/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2023-2023. All rights reserved.
 *
 * Description: BLE RCU Server adv Source. \n
 *
 * History: \n
 * 2023-9-10, Create file. \n
 */

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "osal_addr.h"
#include "soc_osal.h"
#include "securec.h"
#include "errcode.h"
#include "bts_def.h"
#include "bts_le_gap.h"
#include "app_status.h"
#include "app_keyscan.h"
#include "ble_rcu_server_adv.h"

#define  NAME_MAX_LENGTH 15
#define EXT_ADV_OR_SCAN_RSP_DATA_LEN 251
#define u16_low_u8(val)  ((uint8_t)((uint16_t)(val) & 0xff))
#define u16_high_u8(val) ((uint8_t)(((uint16_t)(val) >> 8) & 0xff))

uint8_t g_ble_current_control_obj = NONE_DEVICE;
uint8_t g_ble_local_name1[NAME_MAX_LENGTH] = {'b', 'l', 'e', '_', 'r', 'c', 'u', '1'};
uint8_t g_ble_local_name2[NAME_MAX_LENGTH] = {'b', 'l', 'e', '_', 'r', 'c', 'u', '2'};
uint8_t g_ble_adv_id = 0;

void ble_set_current_control_obj(uint8_t control_obj)
{
    g_ble_current_control_obj = control_obj;
}

static uint8_t ble_set_adv_flag_data(uint8_t *set_adv_data_position, uint8_t max_len)
{
    errno_t n_ret;

    ble_adv_flag adv_flags = {
        .length = BLE_ADV_FLAG_LEN - BLE_GENERAL_BYTE_1,
        .adv_data_type = 1,
        .flags = BLE_ADV_FLAG_DATA,
    };
    n_ret = memcpy_s(set_adv_data_position, max_len, &adv_flags, BLE_ADV_FLAG_LEN);
    if (n_ret != EOK) {
        return 0;
    }
    return BLE_ADV_FLAG_LEN;
}

static uint8_t ble_set_adv_appearance(uint8_t *set_adv_data_position, uint8_t max_len)
{
    errno_t n_ret;
    ble_appearance_t adv_appearance_data = {
        .length = BLE_ADV_APPEARANCE_LENGTH - BLE_GENERAL_BYTE_1,
        .adv_data_type = BLE_SERVICE_DATA_16_UUID,
        .catogory_id = { u16_low_u8(HID_SERVICE), u16_high_u8(HID_SERVICE) },
    };
    n_ret = memcpy_s(set_adv_data_position, max_len, &adv_appearance_data, BLE_ADV_APPEARANCE_LENGTH);
    if (n_ret != EOK) {
        return 0;
    }
    return BLE_ADV_APPEARANCE_LENGTH;
}

static uint8_t ble_set_adv_name(uint8_t *set_adv_data_position, uint8_t max_len)
{
    errno_t n_ret;
    uint8_t len;
    uint8_t size_local_name = sizeof(g_ble_local_name1);

    uint8_t *ble_adv_dev_name = NULL;
    if (g_ble_current_control_obj == TV) {
        ble_adv_dev_name = g_ble_local_name1;
    } else if (g_ble_current_control_obj == OTT) {
        ble_adv_dev_name = g_ble_local_name2;
    }

    ble_local_name_t adv_local_name_data = { 0 };
    adv_local_name_data.length = (uint8_t)(BLE_ADV_PARAM_DATATYPE_LENGTH + size_local_name);
    adv_local_name_data.adv_data_type = BLE_ADV_LOCAL_NAME_DATA_TYPE;
    len = BLE_ADV_PARAM_DATATYPE_LENGTH + BLE_ADV_PARAM_DATATYPE_LENGTH;
    n_ret = memcpy_s(set_adv_data_position, max_len, &adv_local_name_data, len);
    if (n_ret != EOK) {
        return 0;
    }
    n_ret = memcpy_s((set_adv_data_position + len), (size_t)(max_len - len), ble_adv_dev_name, size_local_name);
    if (n_ret != EOK) {
        return 0;
    }
    len = (uint8_t)(len + size_local_name);
    return len;
}

static uint8_t ble_set_adv_appearance_data(uint8_t *set_adv_data_position, uint8_t max_len)
{
    uint8_t idx = 0;
    idx += ble_set_adv_appearance(set_adv_data_position, max_len);
    idx += ble_set_adv_name(set_adv_data_position + idx, (max_len - idx));
    return idx;
}

static uint16_t ble_uuid_server_set_adv_data(uint8_t *set_adv_data, uint8_t adv_data_max_len)
{
    uint8_t idx = 0;

    if ((set_adv_data == NULL) || (adv_data_max_len == 0)) {
        return 0;
    }
    idx += ble_set_adv_flag_data(set_adv_data, adv_data_max_len);
    idx += ble_set_adv_appearance_data(&set_adv_data[idx], adv_data_max_len - idx);
    return idx;
}

static uint16_t ble_set_scan_response_data(uint8_t *scan_rsp_data, uint8_t scan_rsp_data_max_len)
{
    uint8_t idx = 0;
    uint8_t size_local_name = sizeof(g_ble_local_name1);

    if (scan_rsp_data == NULL) {
        return 0;
    }
    if (scan_rsp_data_max_len == 0) {
        return 0;
    }

    /* tx power level */
    ble_tx_power_level_t tx_power_level = {
        .length = BLE_SCAN_RSP_TX_POWER_LEVEL_LEN - BLE_GENERAL_BYTE_1,
        .adv_data_type = BLE_ADV_TX_POWER_LEVEL,
        .tx_power_value = 0,
    };

    errno_t n_ret = memcpy_s(scan_rsp_data, scan_rsp_data_max_len, &tx_power_level, sizeof(ble_tx_power_level_t));
    if (n_ret != EOK) {
        return 0;
    }
    idx += BLE_SCAN_RSP_TX_POWER_LEVEL_LEN;

    uint8_t *ble_adv_dev_name = NULL;
    if (g_ble_current_control_obj == TV) {
        ble_adv_dev_name = g_ble_local_name1;
    } else if (g_ble_current_control_obj == OTT) {
        ble_adv_dev_name = g_ble_local_name2;
    }

    /* set local name */
    scan_rsp_data[idx++] = size_local_name + BLE_GENERAL_BYTE_1;
    scan_rsp_data[idx++] = BLE_ADV_LOCAL_NAME_DATA_TYPE;
    if ((idx + size_local_name) > scan_rsp_data_max_len) {
        return 0;
    }
    n_ret = memcpy_s(&scan_rsp_data[idx], scan_rsp_data_max_len - idx, ble_adv_dev_name, size_local_name);
    if (n_ret != EOK) {
        return 0;
    }
    idx += size_local_name;
    return idx;
}

uint8_t ble_rcu_set_adv_data(void)
{
    uint16_t adv_data_len;
    uint16_t scan_rsp_data_len;
    uint8_t set_adv_data[EXT_ADV_OR_SCAN_RSP_DATA_LEN] = { 0 };
    uint8_t set_scan_rsp_data[EXT_ADV_OR_SCAN_RSP_DATA_LEN] = { 0 };
    gap_ble_config_adv_data_t cfg_adv_data;

    ble_appearance_t adv_appearance_data = {
        .length = BLE_ADV_APPEARANCE_LENGTH - BLE_GENERAL_BYTE_1,
        .adv_data_type = BLE_SERVICE_DATA_16_UUID,
        .catogory_id = { u16_low_u8(HID_SERVICE), u16_high_u8(HID_SERVICE) },
    };

    if (memcpy_s(set_adv_data, sizeof(set_adv_data), &adv_appearance_data, BLE_ADV_APPEARANCE_LENGTH) != EOK) {
        return 1;
    }
    /* set adv data */
    adv_data_len = ble_uuid_server_set_adv_data(set_adv_data, EXT_ADV_OR_SCAN_RSP_DATA_LEN);
    if ((adv_data_len > EXT_ADV_OR_SCAN_RSP_DATA_LEN) || (adv_data_len == 0)) {
        return 0;
    }
    /* set scan response data */
    scan_rsp_data_len = ble_set_scan_response_data(set_scan_rsp_data, EXT_ADV_OR_SCAN_RSP_DATA_LEN);
    if ((scan_rsp_data_len > EXT_ADV_OR_SCAN_RSP_DATA_LEN) || (scan_rsp_data_len == 0)) {
        return 0;
    }
    cfg_adv_data.adv_data = set_adv_data;
    cfg_adv_data.adv_length = adv_data_len;

    cfg_adv_data.scan_rsp_data = set_scan_rsp_data;
    cfg_adv_data.scan_rsp_length = scan_rsp_data_len;
    if (gap_ble_set_adv_data(g_ble_current_control_obj, &cfg_adv_data) != 0) {
        return 0;
    }
    return 0;
}

uint8_t ble_rcu_directed_start_adv(bd_addr_t *addr)
{
    errcode_t n_ret = 0;
    uint8_t local_addr[BD_ADDR_LEN];
    if (g_ble_current_control_obj == TV) {
        local_addr[BLE_ADDRESS_ZERO] = CONFIG_TV_MULTICON_SERVER_ADDR0;
        local_addr[BLE_ADDRESS_ONE] = CONFIG_TV_MULTICON_SERVER_ADDR1;
        local_addr[BLE_ADDRESS_TWO] = CONFIG_TV_MULTICON_SERVER_ADDR2;
        local_addr[BLE_ADDRESS_THREE] = CONFIG_TV_MULTICON_SERVER_ADDR3;
        local_addr[BLE_ADDRESS_FOUR] = CONFIG_TV_MULTICON_SERVER_ADDR4;
        local_addr[BLE_ADDRESS_FIVE] = CONFIG_TV_MULTICON_SERVER_ADDR5;
    } else if (g_ble_current_control_obj == OTT) {
        local_addr[BLE_ADDRESS_ZERO] = CONFIG_OTT_MULTICON_SERVER_ADDR0;
        local_addr[BLE_ADDRESS_ONE] = CONFIG_OTT_MULTICON_SERVER_ADDR1;
        local_addr[BLE_ADDRESS_TWO] = CONFIG_OTT_MULTICON_SERVER_ADDR2;
        local_addr[BLE_ADDRESS_THREE] = CONFIG_OTT_MULTICON_SERVER_ADDR3;
        local_addr[BLE_ADDRESS_FOUR] = CONFIG_OTT_MULTICON_SERVER_ADDR4;
        local_addr[BLE_ADDRESS_FIVE] = CONFIG_OTT_MULTICON_SERVER_ADDR5;
    }
    gap_ble_adv_params_t adv_para = {0};
    uint8_t adv_id = g_ble_current_control_obj;

    adv_para.min_interval = BLE_ADV_MIN_INTERVAL;
    adv_para.max_interval = BLE_ADV_MAX_INTERVAL;
    adv_para.duration = BTH_GAP_BLE_ADV_FOREVER_DURATION;
    adv_para.peer_addr.type = BLE_PUBLIC_DEVICE_ADDRESS;
    /* 广播通道选择bitMap, 可参考BleAdvChannelMap */
    adv_para.channel_map = BLE_ADV_CHANNEL_MAP_CH_DEFAULT;
    adv_para.adv_type = BLE_ADV_TYPE_CONNECTABLE_UNDIRECTED;
    adv_para.adv_filter_policy = BLE_ADV_FILTER_POLICY_SCAN_ANY_CONNECT_ANY;
    adv_para.own_addr.type = 0;
    if (memcpy_s(adv_para.own_addr.addr, BD_ADDR_LEN, local_addr, BD_ADDR_LEN) != EOK) {
        return 0;
    }

    if (addr != NULL) {
        adv_para.peer_addr.type = 0;
        if (memcpy_s(adv_para.peer_addr.addr, BD_ADDR_LEN, addr, BD_ADDR_LEN) != EOK) {
            return 0;
        }
    }

    n_ret = gap_ble_set_adv_param(adv_id, &adv_para);
    if (n_ret != 0) {
        return 0;
    }

    n_ret = gap_ble_start_adv(adv_id);
    if (n_ret != 0) {
        return 0;
    }
    return 0;
}

uint8_t ble_rcu_start_adv(void)
{
    errcode_t n_ret = 0;
    uint8_t local_addr[BD_ADDR_LEN];
    if (g_ble_current_control_obj == TV) {
        local_addr[BLE_ADDRESS_ZERO] = CONFIG_TV_MULTICON_SERVER_ADDR0;
        local_addr[BLE_ADDRESS_ONE] = CONFIG_TV_MULTICON_SERVER_ADDR1;
        local_addr[BLE_ADDRESS_TWO] = CONFIG_TV_MULTICON_SERVER_ADDR2;
        local_addr[BLE_ADDRESS_THREE] = CONFIG_TV_MULTICON_SERVER_ADDR3;
        local_addr[BLE_ADDRESS_FOUR] = CONFIG_TV_MULTICON_SERVER_ADDR4;
        local_addr[BLE_ADDRESS_FIVE] = CONFIG_TV_MULTICON_SERVER_ADDR5;
    } else if (g_ble_current_control_obj == OTT) {
        local_addr[BLE_ADDRESS_ZERO] = CONFIG_OTT_MULTICON_SERVER_ADDR0;
        local_addr[BLE_ADDRESS_ONE] = CONFIG_OTT_MULTICON_SERVER_ADDR1;
        local_addr[BLE_ADDRESS_TWO] = CONFIG_OTT_MULTICON_SERVER_ADDR2;
        local_addr[BLE_ADDRESS_THREE] = CONFIG_OTT_MULTICON_SERVER_ADDR3;
        local_addr[BLE_ADDRESS_FOUR] = CONFIG_OTT_MULTICON_SERVER_ADDR4;
        local_addr[BLE_ADDRESS_FIVE] = CONFIG_OTT_MULTICON_SERVER_ADDR5;
    }
    gap_ble_adv_params_t adv_para = {0};
    uint8_t adv_id = g_ble_current_control_obj;

    adv_para.min_interval = BLE_ADV_MIN_INTERVAL;
    adv_para.max_interval = BLE_ADV_MAX_INTERVAL;
    adv_para.duration = BTH_GAP_BLE_ADV_FOREVER_DURATION;
    adv_para.peer_addr.type = BLE_PUBLIC_DEVICE_ADDRESS;
    /* 广播通道选择bitMap, 可参考BleAdvChannelMap */
    adv_para.channel_map = BLE_ADV_CHANNEL_MAP_CH_DEFAULT;
    adv_para.adv_type = BLE_ADV_TYPE_CONNECTABLE_UNDIRECTED;
    adv_para.adv_filter_policy = BLE_ADV_FILTER_POLICY_SCAN_ANY_CONNECT_ANY;
    adv_para.own_addr.type = 0;
    if (memcpy_s(adv_para.own_addr.addr, BD_ADDR_LEN, local_addr, BD_ADDR_LEN) != EOK) {
        return 0;
    }
    (void)memset_s(&adv_para.peer_addr.addr, BD_ADDR_LEN, 0, BD_ADDR_LEN);

    n_ret = gap_ble_set_adv_param(adv_id, &adv_para);
    if (n_ret != 0) {
        return 0;
    }

    n_ret = gap_ble_start_adv(adv_id);
    if (n_ret != 0) {
        gap_ble_stop_adv(adv_id);
        return 0;
    }
    return 0;
}