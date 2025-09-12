/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * Description: SLE BAS SERVICE \n
 *
 * History: \n
 * 2024-5-30, Create file. \n
 */
#include "sle_errcode.h"
#include "sle_service_common.h"
#include "adc_porting.h"
#include "sle_service_bas.h"

#define BAT_ELEMENT_NUM 3

static uint8_t g_server_id;

static uint8_t g_sle_bat_uuid[BAT_ELEMENT_NUM][SLE_UUID_LEN] = {
    /* BAT service UUID. 设备信息管理 */
    { 0x37, 0xBE, 0xA8, 0x80, 0xFC, 0x70, 0x11, 0xEA, 0xB7, 0x20, 0x00, 0x00, 0x00, 0x00, 0x06, 0x0A },
    /* 电池剩余容量占比信息 */
    { 0x37, 0xBE, 0xA8, 0x80, 0xFC, 0x70, 0x11, 0xEA, 0xB7, 0x20, 0x00, 0x00, 0x00, 0x00, 0x10, 0x34},
    /* 电池剩余容量信息 */
    { 0x37, 0xBE, 0xA8, 0x80, 0xFC, 0x70, 0x11, 0xEA, 0xB7, 0x20, 0x00, 0x00, 0x00, 0x00, 0x10, 0x35},
};

typedef enum {
    SLE_BAT_INDEX0, // bat service
    SLE_BAT_INDEX1, // bat level
    SLE_BAT_INDEX2, // bat value
    SLE_BAT_INDEX_MAX  // bat max
} sle_bas_index_t;

static sle_item_handle_t g_bas_service_hdl[BAT_ELEMENT_NUM] = {0};

int32_t g_battert_value;

void sle_set_battert(int32_t battert_value)
{
    g_battert_value = battert_value;
}

static errcode_t sle_bas_property_and_descriptor_add(void)
{
    uint32_t properties = SSAP_OPERATE_INDICATION_BIT_READ;

    return sle_add_property(g_server_id, properties, g_sle_bat_uuid[SLE_BAT_INDEX1], sizeof(g_battert_value),
                            (uint8_t *)&g_battert_value, &g_bas_service_hdl[SLE_BAT_INDEX1]);
}

errcode_t sle_rcu_bas_service_add(void)
{
    errcode_t ret = ERRCODE_SLE_SUCCESS;

    ret = sle_service_add(g_server_id, g_sle_bat_uuid[SLE_BAT_INDEX0], g_bas_service_hdl,
    SLE_BAT_INDEX0, SLE_BAT_INDEX_MAX);
    if (ret != ERRCODE_SLE_SUCCESS) {
        return ret;
    }

    ret = sle_bas_property_and_descriptor_add();
    if (ret != ERRCODE_SLE_SUCCESS) {
        return ret;
    }

    ret = ssaps_start_service(g_server_id, g_bas_service_hdl[SLE_BAT_INDEX0].handle_out);
    if (ret != ERRCODE_SLE_SUCCESS) {
        return ret;
    }

    return ERRCODE_SLE_SUCCESS;
}

errcode_t sle_add_bas_service(uint8_t server_id)
{
    uint8_t channel = 1;
    bool self_cali = true;
    g_server_id = server_id;
    adc_port_gadc_entirely_open(channel, self_cali);
    sle_set_battert(adc_port_gadc_entirely_sample(channel));
    errcode_t ret = sle_rcu_bas_service_add();
    if (ret != ERRCODE_SLE_SUCCESS) {
        osal_printk("%s sle_add_bas_service fail, ret:%x\r\n", SLE_RCU_SERVER_LOG, ret);
        return ERRCODE_SLE_FAIL;
    }
    return ERRCODE_SLE_SUCCESS;
}