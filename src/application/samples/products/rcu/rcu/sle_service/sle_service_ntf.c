/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * Description: SLE DIS SERVICE \n
 *
 * History: \n
 * 2024-5-30, Create file. \n
 */
#include "securec.h"
#include "osal_addr.h"
#include "sle_errcode.h"
#include "sle_device_discovery.h"
#include "sle_service_common.h"
#include "app_common.h"
#include "sle_service_ntf.h"

#define UUID_INDEX                      14
#define OCTET_BIT_LEN                   8
/* Service UUID */
#define SLE_UUID_SERVER_SERVICE        0x2222
/* Property UUID */
#define SLE_UUID_SERVER_NTF_REPORT     0x2323
/* Property Property */
#define SLE_UUID_TEST_PERMISSIONS (SSAP_PERMISSION_READ | SSAP_PERMISSION_WRITE)
/* Operation indication */
#define SLE_UUID_TEST_PROPERTY_OPERATIONS (SSAP_OPERATE_INDICATION_BIT_READ | SSAP_OPERATE_INDICATION_BIT_NOTIFY)
/* Descriptor Property */
#define SLE_UUID_TEST_DESCRIPTOR_OPERATIONS \
    (SSAP_OPERATE_INDICATION_BIT_READ | \
     SSAP_OPERATE_INDICATION_BIT_WRITE_NO_RSP | \
     SSAP_OPERATE_INDICATION_BIT_WRITE)

static uint8_t g_sle_rcu_base[] = { 0x37, 0xBE, 0xA8, 0x80, 0xFC, 0x70, 0x11, 0xEA, \
    0xB7, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
/* server notify property uuid */
static uint8_t g_sle_property_value[OCTET_BIT_LEN] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };

static uint8_t g_server_id;
static uint16_t g_service_handle = 0;
static uint16_t g_property_handle = 0;

uint16_t rcu_get_handle(void)
{
    return g_property_handle;
}

static void sle_uuid_set_base(sle_uuid_t *out)
{
    if (memcpy_s(out->uuid, SLE_UUID_LEN, g_sle_rcu_base, SLE_UUID_LEN) != EOK) {
        out->len = 0;
        return ;
    }
    out->len = UUID_LEN_2;
}

static void sle_uuid_setu2(uint16_t u2, sle_uuid_t *out)
{
    sle_uuid_set_base(out);
    out->len = UUID_LEN_2;
    encode2byte_little(&out->uuid[UUID_INDEX], u2);
}

static errcode_t sle_uuid_server_service_add(void)
{
    sle_uuid_t service_uuid = { 0 };
    sle_uuid_setu2(SLE_UUID_SERVER_SERVICE, &service_uuid);
    return ssaps_add_service_sync(g_server_id, &service_uuid, 1, &g_service_handle);
}

static errcode_t sle_uuid_server_property_add(void)
{
    errcode_t ret;
    ssaps_property_info_t property = { 0 };
    ssaps_desc_info_t descriptor = { 0 };
    uint8_t ntf_value[] = { 0x01, 0x00 };

    property.permissions = SLE_UUID_TEST_PERMISSIONS;
    property.operate_indication = SLE_UUID_TEST_PROPERTY_OPERATIONS;
    sle_uuid_setu2(SLE_UUID_SERVER_NTF_REPORT, &property.uuid);
    property.value_len = sizeof(g_sle_property_value);
    property.value = (uint8_t *)osal_vmalloc(sizeof(g_sle_property_value));
    if (property.value == NULL) {
        return ERRCODE_SLE_FAIL;
    }
    if (memcpy_s(property.value, sizeof(g_sle_property_value), g_sle_property_value,
        sizeof(g_sle_property_value)) != EOK) {
        osal_vfree(property.value);
        return ERRCODE_SLE_FAIL;
    }
    ret = ssaps_add_property_sync(g_server_id, g_service_handle, &property,  &g_property_handle);
    if (ret != ERRCODE_SLE_SUCCESS) {
        osal_vfree(property.value);
        return ret;
    }
    descriptor.permissions = SLE_UUID_TEST_PERMISSIONS;
    descriptor.type = SSAP_DESCRIPTOR_CLIENT_CONFIGURATION;
    descriptor.operate_indication = SLE_UUID_TEST_DESCRIPTOR_OPERATIONS;
    descriptor.value_len = sizeof(ntf_value);
    descriptor.value = (uint8_t *)osal_vmalloc(sizeof(ntf_value));
    if (descriptor.value == NULL) {
        osal_vfree(property.value);
        return ERRCODE_SLE_FAIL;
    }
    if (memcpy_s(descriptor.value, sizeof(ntf_value), ntf_value, sizeof(ntf_value)) != EOK) {
        osal_vfree(property.value);
        osal_vfree(descriptor.value);
        return ERRCODE_SLE_FAIL;
    }
    ret = ssaps_add_descriptor_sync(g_server_id, g_service_handle, g_property_handle, &descriptor);
    if (ret != ERRCODE_SLE_SUCCESS) {
        osal_vfree(property.value);
        osal_vfree(descriptor.value);
        return ret;
    }
    osal_vfree(property.value);
    osal_vfree(descriptor.value);
    return ERRCODE_SLE_SUCCESS;
}

errcode_t sle_add_ntf_service(uint8_t server_id)
{
    errcode_t ret;
    g_server_id = server_id;
    ret = sle_uuid_server_service_add();
    if (ret != ERRCODE_SLE_SUCCESS) {
        osal_printk("%s sle_add_ntf_service add service fail, ret:%x\r\n", SLE_RCU_SERVER_LOG, ret);
        return ret;
    }
    ret = sle_uuid_server_property_add();
    if (ret != ERRCODE_SLE_SUCCESS) {
        osal_printk("%s sle_add_ntf_service add property fail, ret:%x\r\n", SLE_RCU_SERVER_LOG, ret);
        return ret;
    }
    ret = ssaps_start_service(g_server_id, g_service_handle);
    if (ret != ERRCODE_SLE_SUCCESS) {
        osal_printk("%s sle_add_ntf_service start fail, ret:%x\r\n", SLE_RCU_SERVER_LOG, ret);
        return ret;
    }
    return ERRCODE_SLE_SUCCESS;
}

/* device通过uuid向host发送数据：report */
errcode_t sle_rcu_server_send_report_by_uuid(const uint8_t *data, uint8_t len, uint16_t conn_id)
{
    osal_printk("enter sle rcu server send report by uuid function! \n");
    errcode_t ret;
    ssaps_ntf_ind_by_uuid_t param = { 0 };
    param.type = SSAP_PROPERTY_TYPE_VALUE;
    param.start_handle = g_service_handle;
    param.end_handle = g_property_handle;
    param.value_len = len;
    param.value = (uint8_t *)osal_vmalloc(len);
    if (param.value == NULL) {
        return ERRCODE_SLE_FAIL;
    }
    if (memcpy_s(param.value, param.value_len, data, len) != EOK) {
        osal_vfree(param.value);
        return ERRCODE_SLE_FAIL;
    }
    sle_uuid_setu2(SLE_UUID_SERVER_NTF_REPORT, &param.uuid);
    ret = ssaps_notify_indicate_by_uuid(g_server_id, conn_id, &param);
    if (ret != ERRCODE_SLE_SUCCESS) {
        osal_printk("%s sle_rcu_server_send_report_by_uuid,ssaps_notify_indicate_by_uuid fail :%x\r\n",
                    SLE_RCU_SERVER_LOG, ret);
        osal_vfree(param.value);
        return ret;
    }
    osal_vfree(param.value);
    return ERRCODE_SLE_SUCCESS;
}