/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * Description: SLE DIS SERVICE \n
 *
 * History: \n
 * 2024-5-30, Create file. \n
 */
#include "securec.h"
#include "sle_errcode.h"
#include "sle_device_discovery.h"
#include "sle_service_common.h"
#include "sle_service_dis.h"

#define DIS_APPEARANCE_LENGTH    3
#define DIS_ELEMENT_NUM 9

#define HARD_WARE_VERSION         "V1.0\0"
#define FIRM_WARE_VERSION         "SLE AOS-IOT-V1.0\0"
#define SOFT_WARE_VERSION         "$(SOFT_VERSION)\0"

static uint8_t g_server_id;

static uint8_t g_sle_dis_uuid[DIS_ELEMENT_NUM][SLE_UUID_LEN] = {
    /* DIS service UUID. 设备信息管理 */
    { 0x37, 0xBE, 0xA8, 0x80, 0xFC, 0x70, 0x11, 0xEA, 0xB7, 0x20, 0x00, 0x00, 0x00, 0x00, 0x06, 0x09 },
    /* Device name characteristic UUID 设备名称 */
    { 0x37, 0xBE, 0xA8, 0x80, 0xFC, 0x70, 0x11, 0xEA, 0xB7, 0x20, 0x00, 0x00, 0x00, 0x00, 0x10, 0x3F},
    /* Device appearance characteristic 设备外观 */
    { 0x37, 0xBE, 0xA8, 0x80, 0xFC, 0x70, 0x11, 0xEA, 0xB7, 0x20, 0x00, 0x00, 0x00, 0x00, 0x10, 0x41},
    /* Pnp Id characteristic UUID（设备序列号） */
    { 0x37, 0xBE, 0xA8, 0x80, 0xFC, 0x70, 0x11, 0xEA, 0xB7, 0x20, 0x00, 0x00, 0x00, 0x00, 0x10, 0x2E },
    /* 软件版本信息 */
    { 0x37, 0xBE, 0xA8, 0x80, 0xFC, 0x70, 0x11, 0xEA, 0xB7, 0x20, 0x00, 0x00, 0x00, 0x00, 0x10, 0x33 },
    /* 固件版本信息 */
    { 0x37, 0xBE, 0xA8, 0x80, 0xFC, 0x70, 0x11, 0xEA, 0xB7, 0x20, 0x00, 0x00, 0x00, 0x00, 0x10, 0x32 },
    /* 硬件版本信息 */
    { 0x37, 0xBE, 0xA8, 0x80, 0xFC, 0x70, 0x11, 0xEA, 0xB7, 0x20, 0x00, 0x00, 0x00, 0x00, 0x10, 0x31 },
    /* 设备序列号信息 */
    { 0x37, 0xBE, 0xA8, 0x80, 0xFC, 0x70, 0x11, 0xEA, 0xB7, 0x20, 0x00, 0x00, 0x00, 0x00, 0x10, 0x30 },
    /* 设备型号信息 */
    { 0x37, 0xBE, 0xA8, 0x80, 0xFC, 0x70, 0x11, 0xEA, 0xB7, 0x20, 0x00, 0x00, 0x00, 0x00, 0x10, 0x2F },
};

static sle_item_handle_t g_dis_service_hdl[DIS_ELEMENT_NUM] = {0};
static uint8_t g_local_device_name[] = CONFIG_SLE_MULTICON_SERVER_NAME;
#define MANUFACTURE_PNP_ID "HS-2024-3361-0001" // manufacture-PID-VID-VERSION

uint8_t *facturer_pnp_id = (uint8_t*)MANUFACTURE_PNP_ID;
uint8_t dis_description[DIS_ELEMENT_NUM][32] = {
    {CONFIG_SLE_MULTICON_SERVER_NAME},  // local_device_name
    {0x00, 0x05, 0x01},  // appearance_value   keyboard
    {MANUFACTURE_PNP_ID},
    {SOFT_WARE_VERSION},  // sw_str
    {FIRM_WARE_VERSION},  // fw_len
    {HARD_WARE_VERSION},  // hw_str
    {'0', '2', '0', '1', '0', '0'},  // sn
    {'0', '2', '0', '1', '0', '0'}  // cmei
};

typedef enum {
    SLE_DIS_INDEX0, // dis service
    SLE_DIS_INDEX1, // name
    SLE_DIS_INDEX2, // appearance
    SLE_DIS_INDEX3, // pnp id
    SLE_DIS_INDEX4, // sw
    SLE_DIS_INDEX5, // fw
    SLE_DIS_INDEX6, // hw
    SLE_DIS_INDEX7, // sn
    SLE_DIS_INDEX8, // model
    SLE_DIS_INDEX_MAX  // max index
} sle_dis_index_t;

static errcode_t sle_dis_property_and_descriptor_add(void)
{
    errcode_t ret = ERRCODE_SLE_SUCCESS;
    uint32_t properties = SSAP_OPERATE_INDICATION_BIT_READ;
    for (int i = SLE_DIS_INDEX1; i < SLE_DIS_INDEX_MAX; i++) {
        ret = sle_add_property(g_server_id, properties, g_sle_dis_uuid[i], sizeof(dis_description[i - 1]),
            dis_description[i - 1], &g_dis_service_hdl[i]);
        if (ret != ERRCODE_SLE_SUCCESS) {
            return ret;
        }
    }

    return ERRCODE_SLE_SUCCESS;
}

static errcode_t sle_rcu_dis_service_add(void)
{
    errcode_t ret = ERRCODE_SLE_SUCCESS;

    ret = sle_set_local_name(g_local_device_name, sizeof(g_local_device_name));
    if (ret != ERRCODE_SLE_SUCCESS) {
        return ret;
    }
    ret = sle_service_add(g_server_id, g_sle_dis_uuid[SLE_DIS_INDEX0], g_dis_service_hdl,
        SLE_DIS_INDEX0, SLE_DIS_INDEX_MAX);
    if (ret != ERRCODE_SLE_SUCCESS) {
        return ret;
    }
    
    ret = sle_dis_property_and_descriptor_add();
    if (ret != ERRCODE_SLE_SUCCESS) {
        return ret;
    }

    ret = ssaps_start_service(g_server_id, g_dis_service_hdl[SLE_DIS_INDEX0].handle_out);
    if (ret != ERRCODE_SLE_SUCCESS) {
        return ret;
    }

    return ERRCODE_SLE_SUCCESS;
}

errcode_t sle_add_dis_service(uint8_t server_id)
{
    g_server_id = server_id;
    errcode_t ret = sle_rcu_dis_service_add();
    if (ret != ERRCODE_SLE_SUCCESS) {
        osal_printk("%s sle_rcu_server_init,sle_rcu_dis_service_add fail\r\n", SLE_RCU_SERVER_LOG);
        return ret;
    }
    return ERRCODE_SLE_SUCCESS;
}