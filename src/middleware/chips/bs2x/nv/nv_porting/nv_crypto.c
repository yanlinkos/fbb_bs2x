/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2023-2023. All rights reserved.
 *
 * Description: NV crypto
 *
 * History:
 * 2023-04-27, Create file.
 */

#include "nv_porting.h"

#if (CONFIG_NV_SUPPORT_ENCRYPT == NV_YES)
#include "common_def.h"
#include "efuse.h"
#include "storage_common.h"
#include "trng.h"
#include "hkdf.h"
#include "aes.h"

#define INVALID_HANDLE         (0xFFFFFFFF)
#define NV_HEADER_LENGTH       16
#define NV_KEY_LENGTH          16
#define NV_IV_LENGTH           12
#define NV_TAG_LENGTH          16
#define NV_DIE_ID_LENGTH_BYTES 16
#define NV_DIE_ID_LEN_WORDS    4
#define NV_DIE_ID_HIGH_32      3
#define NV_DIE_ID_LOW_32       0
#define MATERIAL_LEN           16
#define SALT_LEN               32
#define PASSWORD_LEN           16
#define OTP_RANDOM_POS         108
#define DIE_ID_POS             0
#define NV_PRK_LENGTH          32
#define GMSSL_ERRCODE_SUCC 1
#define GMSSL_ERRCODE_FAIL (-1)

STATIC uint8_t ta_uuid[] = {0xCA, 0x2B, 0xF7, 0x6A, 0xFF, 0x79, 0x4E, 0xAC,
                            0xA6, 0x3D, 0x4E, 0x0A, 0xAA, 0xEE, 0x6C, 0x77};

typedef struct {
    uint16_t enc_key;
    uint16_t version;
    uint32_t rnd;
    uint32_t die_id;
} kv_crypto_iv_info_t;

typedef struct {
    uint8_t type;
    uint8_t upgrade;
    uint16_t key_id;
    uint16_t enc_key;
    uint16_t version;
    uint32_t rnd;
    uint32_t die_id;
} kv_crypto_key_info_t;

typedef struct {
    AES_KEY key;
    uint8_t iv[NV_IV_LENGTH];
    uint8_t iv_len;
    uint8_t tag[NV_TAG_LENGTH];
    uint8_t tag_len;
} drv_symc_ctx;

static errcode_t make_section_key(uint8_t *section_key,
                                  const kv_key_header_t *header,
                                  uint32_t die_id_high32)
{
    kv_crypto_key_info_t *kv_crypto_key_info =
        (kv_crypto_key_info_t *)(uintptr_t)section_key;
    kv_crypto_key_info->type = header->type;
    kv_crypto_key_info->upgrade = header->upgrade;
    kv_crypto_key_info->key_id = header->key_id;
    kv_crypto_key_info->enc_key = header->enc_key;
    kv_crypto_key_info->version = header->version;
    kv_crypto_key_info->rnd = header->rnd;
    kv_crypto_key_info->die_id = die_id_high32;

    return ERRCODE_SUCC;
}

static errcode_t make_iv(uint8_t *iv, const kv_key_header_t *header,
                         uint32_t die_id_low32)
{
    kv_crypto_iv_info_t *kv_crypto_iv_info =
        (kv_crypto_iv_info_t *)(uintptr_t)iv;
    kv_crypto_iv_info->enc_key = header->enc_key;
    kv_crypto_iv_info->version = header->version;
    kv_crypto_iv_info->rnd = header->rnd;
    kv_crypto_iv_info->die_id = die_id_low32;
    return ERRCODE_SUCC;
}

// Random OTP(16bytes)
static errcode_t get_material1(uint8_t *material1, uint32_t material1_len)
{
    errcode_t ret = ERRCODE_FAIL;

    ret = uapi_efuse_read_buffer(material1, OTP_RANDOM_POS, material1_len);
    storage_chk_return(ret != ERRCODE_SUCC, ret,
                       "uapi_efuse_read_buffer failed!\n");

    return ret;
}
// salt component: sectionkey || ta_uuid;
// sectionkey component: type || owner || key_id || enc_key || version || rnd ||
// DIE_ID
static errcode_t get_salt(uint8_t *salt, uint32_t salt_len, uint32_t *die_id,
                          const kv_key_header_t *header)
{
    errcode_t ret = ERRCODE_FAIL;
    uint8_t section_key[NV_KEY_LENGTH] = {0};

    ret = make_section_key(section_key, header, die_id[NV_DIE_ID_HIGH_32]);
    storage_chk_goto(ret != ERRCODE_SUCC, err_exit,
                     "make_section_key failed!\n");

    storage_chk_goto(memcpy_s(salt, salt_len, section_key, NV_KEY_LENGTH) !=
                         EOK,
                     err_exit, "memcpy_s failed!\n");

    storage_chk_goto(memcpy_s(salt + NV_KEY_LENGTH, salt_len - NV_KEY_LENGTH,
                              ta_uuid, sizeof(ta_uuid)) != EOK,
                     err_exit, "memcpy_s failed!\n");

err_exit:
    (void)memset_s(section_key, sizeof(section_key), 0, sizeof(section_key));
    return ret;
}

// Using material1(16bytes) and salt(16bytes) to derive rootkey by HKDF
static errcode_t get_password(uint8_t *password, uint32_t password_len,
                              const kv_key_header_t *header, uint32_t *die_id)
{
    uint8_t salt[SALT_LEN] = {0};
    uint8_t material1[MATERIAL_LEN] = {0};
    errcode_t ret = ERRCODE_FAIL;
        
    uint8_t prk[NV_PRK_LENGTH] = { 0 };
    size_t prk_length = NV_PRK_LENGTH;

    ret = get_salt(salt, SALT_LEN, die_id, header);
    storage_chk_goto(ret != ERRCODE_SUCC, err_exit, "get salt failed!\n");

    ret = get_material1(material1, MATERIAL_LEN);
    storage_chk_goto(ret != ERRCODE_SUCC, err_exit, "get material1 failed!\n");

    const DIGEST *digest;
    digest = DIGEST_sm3();
    ret = hkdf_extract(digest, (const uint8_t *)salt, SALT_LEN, (const uint8_t *)material1, MATERIAL_LEN,
        (uint8_t *)prk, &prk_length);
    storage_chk_goto(ret != GMSSL_ERRCODE_SUCC, err_exit, "hkdf_extract failed!\n");

    ret = hkdf_expand(digest, (const uint8_t *)prk, prk_length, NULL, 0, password_len, password);
    storage_chk_goto(ret != GMSSL_ERRCODE_SUCC, err_exit, "hkdf_expand failed!\n");

    ret = ERRCODE_SUCC;
    return ret;
err_exit:
    (void)memset_s(salt, sizeof(salt), 0, sizeof(salt));
    (void)memset_s(material1, sizeof(material1), 0, sizeof(material1));
    (void)memset_s(prk, sizeof(prk), 0, sizeof(prk));
    return ret;
}


/* 创建加解密通道 */
errcode_t nv_crypto_claim_aes(uint32_t *crypto_handle,
                              const kv_key_header_t *header)
{
    uint32_t die_id[NV_DIE_ID_LEN_WORDS] = {0};
    uint8_t password[PASSWORD_LEN] = {0};
    *crypto_handle = INVAILD_CRYPTO_HANDLE;
    drv_symc_ctx *ctx = osal_vzalloc(sizeof(drv_symc_ctx));
    storage_chk_return(ctx == NULL, ERRCODE_FAIL, "create ctx failed!\n");
    *crypto_handle = (uint32_t)(uintptr_t)ctx;
    errcode_t ret = ERRCODE_FAIL;

    // /* 获取Die_id */
    ret = uapi_efuse_get_die_id((uint8_t *)die_id, NV_DIE_ID_LENGTH_BYTES);
    storage_chk_goto(ret != ERRCODE_SUCC, err_exit, "get_die_id failed!\n");

    /* 获取密钥 */
    ret = get_password(password, PASSWORD_LEN, header, die_id);
    storage_chk_goto(ret != ERRCODE_SUCC, err_exit, "get_password failed!\n");

    /* 获取iv */
    ret = make_iv((uint8_t *)ctx->iv, header, die_id[NV_DIE_ID_LOW_32]);
    storage_chk_goto(ret != ERRCODE_SUCC, err_exit, "make_iv failed!\n");
    ctx->iv_len = NV_IV_LENGTH;
    ctx->tag_len = NV_TAG_LENGTH;
    ret = aes_set_encrypt_key(&ctx->key, (const uint8_t *)password, PASSWORD_LEN);
    storage_chk_goto(ret != GMSSL_ERRCODE_SUCC, err_exit, "aes_set_encrypt_key failed!\n");
    return ERRCODE_SUCC;

err_exit:
    (void)memset_s(ctx, sizeof(drv_symc_ctx), 0, sizeof(drv_symc_ctx));
    (void)memset_s(password, sizeof(password), 0, sizeof(password));
    (void)memset_s(die_id, sizeof(die_id), 0, sizeof(die_id));
    osal_vfree(ctx);
    *crypto_handle = INVAILD_CRYPTO_HANDLE;
    return ERRCODE_FAIL;
}

/* 释放加解密通道 */
void nv_crypto_release_aes(uint32_t crypto_handle)
{
    if (crypto_handle ==  INVAILD_CRYPTO_HANDLE) {
        return;
    }

    drv_symc_ctx *ctx = (drv_symc_ctx *)(uintptr_t)crypto_handle;
    if (ctx != NULL) {
        (void)memset_s(ctx, sizeof(drv_symc_ctx), 0, sizeof(drv_symc_ctx));
        osal_vfree(ctx);
    }
}

/* NV数据加密 */
errcode_t nv_crypto_encode(uint32_t crypto_handle, const uintptr_t src,
                           uintptr_t dest, uint32_t length)
{
    errcode_t ret;
    drv_symc_ctx *ctx = (drv_symc_ctx *)(uintptr_t)crypto_handle;
    storage_chk_return(ctx == NULL, ERRCODE_FAIL, "get ctx failed\n");

    ret = aes_gcm_encrypt(&ctx->key, (const uint8_t *)ctx->iv, ctx->iv_len, NULL, 0, (const uint8_t *)src, length,
        (uint8_t *)dest, ctx->tag_len, (uint8_t *)ctx->tag);
    storage_chk_return(ret != GMSSL_ERRCODE_SUCC, ERRCODE_FAIL, "aes_gcm_encrypt failed\n");
    return ERRCODE_SUCC;
}

/* NV数据解密 */
errcode_t nv_crypto_decode(uint32_t crypto_handle, const uintptr_t src,
                           uintptr_t dest, uint32_t length)
{
    errcode_t ret;
    drv_symc_ctx *ctx = (drv_symc_ctx *)(uintptr_t)crypto_handle;
    storage_chk_return(ctx == NULL, ERRCODE_FAIL, "get ctx failed\n");
    
    ret = aes_gcm_decrypt(&ctx->key, (const uint8_t *)ctx->iv, ctx->iv_len, NULL, 0, (const uint8_t *)src, length,
        (uint8_t *)ctx->tag, ctx->tag_len, (uint8_t *)dest);
    storage_chk_return(ret != GMSSL_ERRCODE_SUCC, ERRCODE_FAIL, "aes_gcm_decrypt tag verify failed\n");
    return ERRCODE_SUCC;
}

/* 获取加密Tag */
errcode_t nv_crypto_get_tag(uint32_t crypto_handle, uint8_t *tag,
                            uint32_t *tag_len)
{
    errcode_t ret;
    drv_symc_ctx *ctx = (drv_symc_ctx *)(uintptr_t)crypto_handle;
    storage_chk_return(ctx == NULL, ERRCODE_FAIL, "get ctx failed\n");

    *tag_len = ctx->tag_len;
    ret = memcpy_s(tag, ctx->tag_len, ctx->tag, ctx->tag_len);
    storage_chk_return(ret != EOK, ERRCODE_FAIL, "memcpy_s failed\n");
    return ERRCODE_SUCC;
}

/* 设置当前NV的Tag */
errcode_t nv_crypto_set_tag(uint32_t crypto_handle, uint8_t *tag,
                            uint32_t tag_len)
{
    errcode_t ret;
    drv_symc_ctx *ctx = (drv_symc_ctx *)(uintptr_t)crypto_handle;
    storage_chk_return(ctx == NULL, ERRCODE_FAIL, "get ctx failed\n");

    ret = memcpy_s(ctx->tag, sizeof(ctx->tag), tag, tag_len);
    storage_chk_return(ret != EOK, ERRCODE_FAIL, "memcpy_s failed\n");
    ctx->tag_len = tag_len;
    return ERRCODE_SUCC;
}

/* 校验Tag */
errcode_t nv_crypto_validate_tag(uint32_t crypto_handle)
{
    unused(crypto_handle);
    return ERRCODE_SUCC;
}

/* 获取随机数 */
void nv_crypto_generate_random(uint32_t *rnd)
{
    (void)uapi_drv_cipher_trng_get_random(rnd);
}

/* 以下函数预留，可不实现 */
errcode_t nv_crypto_start_hash(void)
{
    return ERRCODE_SUCC;
}

errcode_t nv_crypto_update_hash(const uint8_t *src, uint32_t length)
{
    unused(src);
    unused(length);
    return ERRCODE_SUCC;
}

errcode_t nv_crypto_complete_hash(uint8_t *hash)
{
    unused(hash);
    return ERRCODE_SUCC;
}

#endif /* #if (CONFIG_NV_SUPPORT_ENCRYPT == NV_YES) */
