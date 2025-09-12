/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2023-2023. All rights reserved.
 *
 * Description: sle adv config for sle rcu server. \n
 *
 * History: \n
 * 2023-09-21, Create file. \n
 */
#include "securec.h"
#include "osal_addr.h"
#include "osal_task.h"
#include "common_def.h"
#include "sle_device_manager.h"
#include "sle_device_discovery.h"
#include "sle_errcode.h"
#include "sle_rcu_server.h"
#include "timer.h"
#include "rcu.h"
#include "chip_core_irq.h"
#include "app_common.h"
#include "app_status.h"
#include "app_keyscan.h"
#include "sle_rcu_server_control.h"
#include "sle_rcu_server_adv.h"

/* 初始按键序号 */
static uint8_t keynumber = 0x01;

uint8_t g_sle_current_control_obj = NONE_DEVICE;
uint8_t g_sle_local_name1[] = {'s', 'l', 'e', '_', 'r', 'c', 'u', '1'};
uint8_t g_sle_local_name2[] = {'s', 'l', 'e', '_', 'r', 'c', 'u', '2'};

void sle_set_current_control_obj(uint8_t control_obj)
{
    g_sle_current_control_obj = control_obj;
}

static uint16_t sle_set_adv_local_name(uint8_t *adv_data, uint16_t max_len)
{
    uint8_t index = 0;
    uint8_t *local_name = (uint8_t *)CONFIG_SLE_MULTICON_SERVER_NAME;
    uint8_t local_name_len = (uint8_t)strlen((char *)CONFIG_SLE_MULTICON_SERVER_NAME);
    adv_data[index++] = SLE_ADV_DATA_TYPE_COMPLETE_LOCAL_NAME;
    adv_data[index++] = local_name_len + 1;
    if (memcpy_s(&adv_data[index], max_len - index, local_name, local_name_len) != EOK) {
        return 0;
    }
    return (uint16_t)index + local_name_len + 1;
}

static uint16_t sle_set_adv_data(uint8_t *adv_data, uint16_t length)
{
    size_t len = 0;
    uint16_t idx = 0;

    len = sizeof(struct sle_adv_common_value);
    struct sle_adv_common_value adv_disc_level = {
        .length = len - 1,
        .type = SLE_ADV_DATA_TYPE_DISCOVERY_LEVEL,
        .value = SLE_ANNOUNCE_LEVEL_NORMAL,
    };
    if (memcpy_s(&adv_data[idx], length - idx, &adv_disc_level, len) != EOK) {
        return 0;
    }
    idx += len;

    len = sizeof(struct sle_adv_common_value);
    struct sle_adv_common_value adv_access_mode = {
        .length = len - 1,
        .type = SLE_ADV_DATA_TYPE_ACCESS_MODE,
        .value = 0,
    };
    if (memcpy_s(&adv_data[idx], length - idx, &adv_access_mode, len) != EOK) {
        return 0;
    }
    idx += len;

    uint8_t *sle_adv_dev_name = NULL;
    if (g_sle_current_control_obj == TV) {
        sle_adv_dev_name = g_sle_local_name1;
    } else if (g_sle_current_control_obj == OTT) {
        sle_adv_dev_name = g_sle_local_name2;
    }

    len = sizeof(g_sle_local_name1);
    if (memcpy_s(&adv_data[idx], length - idx, sle_adv_dev_name, len) != EOK) {
        return 0;
    }
    idx += len;
    return idx;
}

static uint16_t sle_set_scan_response_data(uint8_t *scan_rsp_data, uint16_t length)
{
    uint16_t idx = 0;
    size_t scan_rsp_data_len = sizeof(struct sle_adv_common_value);

    struct sle_adv_common_value tx_power_level = {
        .length = sizeof(tx_power_level.value),
        .type = SLE_ADV_DATA_TYPE_TX_POWER_LEVEL,
        .value = SLE_ADV_TX_POWER,
    };
    if (memcpy_s(scan_rsp_data, length, &tx_power_level, scan_rsp_data_len) != EOK) {
        return 0;
    }
    idx += scan_rsp_data_len;

    /* set local name */
    idx += sle_set_adv_local_name(&scan_rsp_data[idx], length - idx);
    return idx;
}

static int sle_set_default_announce_param(void)
{
    sle_announce_param_t param = { 0 };
    uint8_t local_addr[SLE_ADDR_LEN] = { CONFIG_SLE_MULTICON_SERVER_ADDR0, CONFIG_SLE_MULTICON_SERVER_ADDR1,
                                         CONFIG_SLE_MULTICON_SERVER_ADDR2, CONFIG_SLE_MULTICON_SERVER_ADDR3,
                                         CONFIG_SLE_MULTICON_SERVER_ADDR4, CONFIG_SLE_MULTICON_SERVER_ADDR5 };
    param.announce_mode = SLE_ANNOUNCE_MODE_CONNECTABLE_SCANABLE;
    param.announce_handle = SLE_ADV_HANDLE_DEFAULT;
    param.announce_level = SLE_ANNOUNCE_LEVEL_NORMAL;
    param.announce_gt_role = SLE_ANNOUNCE_ROLE_T_CAN_NEGO;
    param.announce_channel_map = SLE_ADV_CHANNEL_MAP_DEFAULT;
    param.announce_interval_min = SLE_ADV_INTERVAL_MIN_DEFAULT;
    param.announce_interval_max = SLE_ADV_INTERVAL_MAX_DEFAULT;
    param.conn_interval_min = SLE_CONN_INTV_MIN_DEFAULT;
    param.conn_interval_max = SLE_CONN_INTV_MAX_DEFAULT;
    param.conn_max_latency = SLE_CONN_MAX_LATENCY;
    param.conn_supervision_timeout = SLE_CONN_SUPERVISION_TIMEOUT_DEFAULT;
    param.own_addr.type = 0;
    if (memcpy_s(param.own_addr.addr, SLE_ADDR_LEN, local_addr, SLE_ADDR_LEN) != EOK) {
        return 0;
    }
    sle_addr_t local_address;
    local_address.type = 0;
    (void)memcpy_s(local_address.addr, SLE_ADDR_LEN, local_addr, SLE_ADDR_LEN);
    sle_set_local_addr(&local_address);
    return sle_set_announce_param(param.announce_handle, &param);
}

static int sle_set_default_announce_data(void)
{
    errcode_t ret;
    uint8_t announce_data_len = 0;
    uint8_t seek_data_len = 0;
    sle_announce_data_t data = { 0 };
    uint8_t adv_handle = SLE_ADV_HANDLE_DEFAULT;
    uint8_t announce_data[SLE_ADV_DATA_LEN_MAX] = { 0 };
    uint8_t seek_rsp_data[SLE_ADV_DATA_LEN_MAX] = { 0 };

    announce_data_len = sle_set_adv_data(announce_data, SLE_ADV_DATA_LEN_MAX);
    data.announce_data = announce_data;
    data.announce_data_len = announce_data_len;

    seek_data_len = sle_set_scan_response_data(seek_rsp_data, SLE_ADV_DATA_LEN_MAX);
    data.seek_rsp_data = seek_rsp_data;
    data.seek_rsp_data_len = seek_data_len;

    ret = sle_set_announce_data(adv_handle, &data);
    if (ret == ERRCODE_SLE_SUCCESS) {
        osal_printk("%s set announce data success.\r\n", SLE_RCU_SERVER_LOG);
    } else {
        osal_printk("%s set adv param fail.\r\n", SLE_RCU_SERVER_LOG);
    }
    return ERRCODE_SLE_SUCCESS;
}

static int sle_set_directed_announce_param(const sle_addr_t *addr)
{
    sle_announce_param_t param = { 0 };
    uint8_t local_addr[SLE_ADDR_LEN] = { CONFIG_SLE_MULTICON_SERVER_ADDR0, CONFIG_SLE_MULTICON_SERVER_ADDR1,
                                         CONFIG_SLE_MULTICON_SERVER_ADDR2, CONFIG_SLE_MULTICON_SERVER_ADDR3,
                                         CONFIG_SLE_MULTICON_SERVER_ADDR4, CONFIG_SLE_MULTICON_SERVER_ADDR5 };
    param.announce_mode = SLE_ANNOUNCE_MODE_CONNECTABLE_DIRECTED;
    param.announce_handle = SLE_ADV_HANDLE_DIRECTED;
    param.announce_gt_role = SLE_ANNOUNCE_ROLE_T_CAN_NEGO;
    param.announce_level = SLE_ANNOUNCE_LEVEL_NORMAL;
    param.announce_channel_map = SLE_ADV_CHANNEL_MAP_DEFAULT;
    param.announce_interval_min = SLE_ADV_INTERVAL_MIN_DEFAULT;
    param.announce_interval_max = SLE_ADV_INTERVAL_MAX_DEFAULT;
    param.conn_interval_min = SLE_CONN_INTV_MIN_DEFAULT;
    param.conn_interval_max = SLE_CONN_INTV_MAX_DEFAULT;
    param.conn_max_latency = SLE_CONN_MAX_LATENCY;
    param.conn_supervision_timeout = SLE_CONN_SUPERVISION_TIMEOUT_DEFAULT;
    param.own_addr.type = 0;
    if (memcpy_s(param.own_addr.addr, SLE_ADDR_LEN, local_addr, SLE_ADDR_LEN) != EOK) {
        return 0;
    }
    param.peer_addr.type = 0;
    if (memcpy_s(param.peer_addr.addr, SLE_ADDR_LEN, addr->addr, SLE_ADDR_LEN) != EOK) {
        return 0;
    }
    sle_addr_t local_address;
    local_address.type = 0;
    (void)memcpy_s(local_address.addr, SLE_ADDR_LEN, local_addr, SLE_ADDR_LEN);
    sle_set_local_addr(&local_address);
    return sle_set_announce_param(param.announce_handle, &param);
}

static int sle_set_wakeup_announce_param(const sle_addr_t *addr)
{
    sle_announce_param_t param = { 0 };
    uint8_t local_addr[SLE_ADDR_LEN] = { CONFIG_SLE_MULTICON_SERVER_ADDR0, CONFIG_SLE_MULTICON_SERVER_ADDR1,
                                         CONFIG_SLE_MULTICON_SERVER_ADDR2, CONFIG_SLE_MULTICON_SERVER_ADDR3,
                                         CONFIG_SLE_MULTICON_SERVER_ADDR4, CONFIG_SLE_MULTICON_SERVER_ADDR5 };
    param.announce_mode = SLE_ANNOUNCE_MODE_CONNECTABLE_DIRECTED;
    param.announce_handle = SLE_ADV_HANDLE_WAKEUP;
    param.announce_gt_role = SLE_ANNOUNCE_ROLE_T_CAN_NEGO;
    param.announce_level = SLE_ANNOUNCE_LEVEL_NORMAL;
    param.announce_channel_map = SLE_ADV_CHANNEL_MAP_DEFAULT;
    param.announce_interval_min = SLE_CONN_WAKEUP_INTV_MIN_DEFAULT;
    param.announce_interval_max = SLE_CONN_WAKEUP_INTV_MAX_DEFAULT;
    param.conn_interval_min = SLE_CONN_INTV_MIN_DEFAULT;
    param.conn_interval_max = SLE_CONN_INTV_MAX_DEFAULT;
    param.conn_max_latency = SLE_CONN_MAX_LATENCY;
    param.conn_supervision_timeout = SLE_CONN_SUPERVISION_TIMEOUT_DEFAULT;
    param.own_addr.type = 0;
    if (memcpy_s(param.own_addr.addr, SLE_ADDR_LEN, local_addr, SLE_ADDR_LEN) != EOK) {
        return 0;
    }
    param.peer_addr.type = 0;
    if (memcpy_s(param.peer_addr.addr, SLE_ADDR_LEN, addr->addr, SLE_ADDR_LEN) != EOK) {
        return 0;
    }
    sle_addr_t local_address;
    local_address.type = 0;
    (void)memcpy_s(local_address.addr, SLE_ADDR_LEN, local_addr, SLE_ADDR_LEN);
    sle_set_local_addr(&local_address);
    return sle_set_announce_param(param.announce_handle, &param);
}

static void sle_set_wakeup_announce_data(void)
{
    keynumber++;
    errcode_t ret;
    uint8_t seek_data_len = 0;
    sle_announce_data_t data = { 0 };
    uint8_t adv_handle = SLE_ADV_HANDLE_WAKEUP;
    uint8_t announce_data[SLE_ADV_DATA_LEN_MAX] = { 0 };
    uint8_t seek_rsp_data[SLE_ADV_DATA_LEN_MAX] = { 0 };

    announce_data[0] = 0xFF;
    announce_data[1] = 0x12;
    announce_data[2] = 0x00;
    announce_data[3] = 0x00;
    announce_data[4] = 0x0C;
    announce_data[5] = 0x7A;
    announce_data[6] = 0x00;
    announce_data[7] = 0x6C;
    announce_data[8] = keynumber;

    data.announce_data = announce_data;
    data.announce_data_len = 20;

    seek_data_len = sle_set_scan_response_data(seek_rsp_data, SLE_ADV_DATA_LEN_MAX);
    data.seek_rsp_data = seek_rsp_data;
    data.seek_rsp_data_len = seek_data_len;

    ret = sle_set_announce_data(adv_handle, &data);
    if (ret != ERRCODE_SLE_SUCCESS) {
        osal_printk("%s set adv param fail.\r\n", SLE_RCU_SERVER_LOG);
    }
}

static void sle_announce_enable_cbk(uint32_t announce_id, errcode_t status)
{
    unused(announce_id);
    unused(status);
    app_print("%s sle announce enable callback id:0x%02x, state:0x%x\r\n", SLE_RCU_SERVER_LOG, announce_id,
              status);
}

static void sle_announce_disable_cbk(uint32_t announce_id, errcode_t status)
{
    unused(announce_id);
    unused(status);
    app_print("%s sle announce disable callback id:0x%02x, state:0x%x\r\n", SLE_RCU_SERVER_LOG, announce_id,
              status);
}

static void sle_announce_terminal_cbk(uint32_t announce_id)
{
    unused(announce_id);
    app_print("%s sle announce terminal callback id:0x%02x\r\n", SLE_RCU_SERVER_LOG, announce_id);
}

errcode_t sle_rcu_announce_register_cbks(void)
{
    sle_announce_seek_callbacks_t seek_cbks = { 0 };
    seek_cbks.announce_enable_cb = sle_announce_enable_cbk;
    seek_cbks.announce_disable_cb = sle_announce_disable_cbk;
    seek_cbks.announce_terminal_cb = sle_announce_terminal_cbk;
    errcode_t ret = sle_announce_seek_register_callbacks(&seek_cbks);
    if (ret != ERRCODE_SLE_SUCCESS) {
        app_print("%s sle_rcu_announce_register_cbks fail:%x\r\n", SLE_RCU_SERVER_LOG, ret);
        return ret;
    }
    return ERRCODE_SLE_SUCCESS;
}

errcode_t sle_rcu_server_adv_init(void)
{
    errcode_t ret;

    uint8_t conn_id;
    sle_set_default_announce_param();
    sle_set_default_announce_data();
    conn_id = sle_control_get_specific_con_id(g_sle_current_control_obj);
    set_app_sle_conn_status(conn_id, APP_CONNECT_STATUS_ADVING);
    set_app_sle_adv_status(conn_id, SLE_ADV_TYPE_DEFAULT);
    ret = sle_start_announce(SLE_ADV_HANDLE_DEFAULT);
    if (ret != ERRCODE_SLE_SUCCESS) {
        sle_stop_announce(SLE_ADV_HANDLE_DEFAULT);
        osal_printk("%s sle_rcu_server_adv_init,sle_start_announce fail :%x\r\n", SLE_RCU_SERVER_LOG, ret);
        return ret;
    }
    return ERRCODE_SLE_SUCCESS;
}

#if defined(CONFIG_RCU_MASS_PRODUCTION_TEST)
static int sle_set_test_announce_data(void)
{
    errcode_t ret;
    uint8_t announce_data_len = 0;
    uint8_t seek_data_len = 0;
    sle_announce_data_t data = { 0 };
    uint8_t adv_handle = SLE_ADV_HANDLE_DEFAULT;
    uint8_t announce_data[SLE_ADV_DATA_LEN_MAX] = { 0 };
    uint8_t seek_rsp_data[SLE_ADV_DATA_LEN_MAX] = { 0 };

    announce_data_len = sle_set_adv_data(announce_data, SLE_ADV_DATA_LEN_MAX);
    data.announce_data = announce_data;
    data.announce_data_len = announce_data_len;

    seek_data_len = sle_set_scan_response_data(seek_rsp_data, SLE_ADV_DATA_LEN_MAX);
    data.seek_rsp_data = seek_rsp_data;
    data.seek_rsp_data_len = seek_data_len;

    ret = sle_set_announce_data(adv_handle, &data);
    if (ret == ERRCODE_SLE_SUCCESS) {
        osal_printk("%s set announce data success.\r\n", SLE_RCU_SERVER_LOG);
    } else {
        osal_printk("%s set adv param fail.\r\n", SLE_RCU_SERVER_LOG);
    }
    return ERRCODE_SLE_SUCCESS;
}

static int rcu_mp_test_set_test_announce_param(sle_addr_t *local_addr, sle_addr_t *peer_addr)
{
    sle_announce_param_t param = { 0 };
    param.announce_mode = SLE_ANNOUNCE_MODE_CONNECTABLE_DIRECTED;
    param.announce_handle = SLE_ADV_HANDLE_DEFAULT;
    param.announce_gt_role = SLE_ANNOUNCE_ROLE_T_CAN_NEGO;
    param.announce_level = SLE_ANNOUNCE_LEVEL_NORMAL;
    param.announce_channel_map = SLE_ADV_CHANNEL_MAP_DEFAULT;
    param.announce_interval_min = SLE_ADV_INTERVAL_MIN_DEFAULT;
    param.announce_interval_max = SLE_ADV_INTERVAL_MAX_DEFAULT;
    param.conn_interval_min = SLE_CONN_INTV_MIN_DEFAULT;
    param.conn_interval_max = SLE_CONN_INTV_MAX_DEFAULT;
    param.conn_max_latency = SLE_CONN_MAX_LATENCY;
    param.conn_supervision_timeout = SLE_CONN_SUPERVISION_TIMEOUT_DEFAULT;
    param.own_addr.type = 0;
    if (memcpy_s(param.own_addr.addr, SLE_ADDR_LEN, local_addr->addr, SLE_ADDR_LEN) != EOK) {
        return 0;
    }
    param.peer_addr.type = 0;
    if (memcpy_s(param.peer_addr.addr, SLE_ADDR_LEN, peer_addr->addr, SLE_ADDR_LEN) != EOK) {
        return 0;
    }
    sle_addr_t local_address;
    local_address.type = 0;
    (void)memcpy_s(local_address.addr, SLE_ADDR_LEN, local_addr->addr, SLE_ADDR_LEN);
    sle_set_local_addr(&local_address);
    return sle_set_announce_param(param.announce_handle, &param);
}
 
errcode_t rcu_mp_test_server_adv_init(const sle_addr_t *local_addr, const sle_addr_t *peer_addr)
{
    errcode_t ret;
    rcu_mp_test_set_test_announce_param(local_addr, peer_addr);
    sle_set_test_announce_data();
    ret = sle_start_announce(SLE_ADV_HANDLE_DIRECTED);
    if (ret != ERRCODE_SLE_SUCCESS) {
        osal_printk("%s sle_rcu_server_adv_init,sle_start_announce fail :%x\r\n", SLE_RCU_SERVER_LOG, ret);
        return ret;
    }
    return ERRCODE_SLE_SUCCESS;
}
#endif

errcode_t sle_rcu_server_directed_adv_init(const sle_addr_t *addr)
{
    errcode_t ret;
    sle_set_directed_announce_param(addr);
    sle_set_default_announce_data();
    uint16_t conn_id = sle_control_get_specific_con_id(g_sle_current_control_obj);
    set_app_sle_conn_status(conn_id, APP_CONNECT_STATUS_ADVING);
    set_app_sle_adv_status(conn_id, SLE_ADV_TYPE_DIRECTED);
    ret = sle_start_announce(SLE_ADV_HANDLE_DIRECTED);
    if (ret != ERRCODE_SLE_SUCCESS) {
        osal_printk("%s sle_rcu_server_adv_init,sle_start_announce fail :%x\r\n", SLE_RCU_SERVER_LOG, ret);
        return ret;
    }
    return ERRCODE_SLE_SUCCESS;
}

errcode_t sle_rcu_server_adv_deinit(void)
{
    osal_printk("stop pair adv\r\n");
    app_globle_status_t status = get_app_globle_status();
    uint16_t conn_id = sle_control_get_con_id();
    if (status.app_sle_conn_status[conn_id] == APP_CONNECT_STATUS_ADVING) {
        set_app_sle_conn_status(conn_id, APP_CONNECT_STATUS_IDLE);
    }
    set_app_sle_adv_status(conn_id, SLE_ADV_TYPE_IDLE);
    if (status.app_sle_conn_status[conn_id] == APP_CONNECT_STATUS_PAIRED) {
        osal_printk("connect and pair completed not should stop adv\r\n");
        return ERRCODE_SLE_SUCCESS;
    } else {
        int ret = sle_stop_announce(SLE_ADV_HANDLE_DEFAULT);
        if (ret != ERRCODE_SLE_SUCCESS) {
            return ret;
        }
    }
    return ERRCODE_SLE_SUCCESS;
}

void sle_rcu_timer_callback(timer_index_t index)
{
    unused(index);
    sle_stop_announce(SLE_ADV_HANDLE_WAKEUP);
}

errcode_t sle_rcu_server_wakeup_adv_init(const sle_addr_t *addr)
{
    if (keynumber != 1) {
        sle_stop_announce(SLE_ADV_HANDLE_WAKEUP);               /* 关闭广播 */
        uapi_timer_stop_high_precision(TIMER_INDEX_1);          /* 关闭timer */
    }
    errcode_t ret;
    sle_set_wakeup_announce_param(addr);
    sle_set_wakeup_announce_data();
    uint16_t conn_id = sle_control_get_con_id();
    set_app_sle_conn_status(conn_id, APP_CONNECT_STATUS_ADVING);
    set_app_sle_adv_status(conn_id, SLE_ADV_TYPE_WAKEUP);
    ret = sle_start_announce(SLE_ADV_HANDLE_WAKEUP);
    if (ret != ERRCODE_SLE_SUCCESS) {
        osal_printk("%s sle_rcu_server_adv_init,sle_start_announce fail :%x\r\n", SLE_RCU_SERVER_LOG, ret);
        return ret;
    }

    timer_irq_info_t irq_info;
    irq_info.irq = TIMER_1_IRQN;
    irq_info.priority = 0;

    uapi_timer_start_high_precision(TIMER_INDEX_1, 0, 500000, &irq_info, sle_rcu_timer_callback);

    return ERRCODE_SLE_SUCCESS;
}
