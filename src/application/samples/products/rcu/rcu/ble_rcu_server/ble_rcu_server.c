/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2023-2023. All rights reserved.
 *
 * Description: BLE RCU Server Source. \n
 *
 * History: \n
 * 2023-9-10, Create file. \n
 */
#include "securec.h"
#include "stdbool.h"
#include "soc_osal.h"
#include "common_def.h"
#include "rcu.h"
#include "vdt_codec.h"
#include "amic_voice.h"
#include "bts_low_latency.h"
#include "bts_device_manager.h"
#include "ble_rcu_server_adv.h"
#include "ble_hid_rcu_server.h"
#include "ble_rcu_server_control.h"
#include "ble_rcu_server.h"

#define BLE_RCU_SERVICE_NUM 		3
#define BLE_RCU_TASK_DELAY_MS 		200
#define UART16_LEN 					2

static uint16_t g_ble_enable = false;
/* 低功耗连接参数信息 */
static gap_conn_param_update_t g_worktostandby = { 0, 20, 20, 16, 3000 };
static gap_conn_param_update_t g_standbytowork = { 0, 9, 9, 1, 1000 };

uint8_t g_ble_out_low_latency_data[LOW_LATENCY_DATA_MAX] = { 0 };

static void ble_rcu_adv_enable_cbk(uint8_t adv_id, adv_status_t status)
{
    osal_printk("adv enable cbk adv_id:%d status:%d\n", adv_id, status);
}

static void ble_rcu_adv_disable_cbk(uint8_t adv_id, adv_status_t status)
{
    osal_printk("adv disable adv_id: %d, status:%d\n", adv_id, status);
}

uint8_t *ble_low_latency_get_data_cbk(uint8_t *length, uint16_t *att_handle, uint16_t conn_handle)
{
    unused(conn_handle);
    get_amic_encode_data(length, g_ble_out_low_latency_data);
    *att_handle = ble_rcu_get_amic_handle();
    return g_ble_out_low_latency_data;
}

void ble_set_em_data_cbk(uint16_t co_handle, uint8_t status)
{
    unused(status);
    unused(co_handle);

    osal_printk("pair ble_set_em_data_cbk\r\n");
}

void ble_low_latency_cbk_reg(void)
{
    ble_low_latency_callbacks_t cbks = {0};
    cbks.hid_data_cb = ble_low_latency_get_data_cbk;
    cbks.ble_set_em_data_cb = ble_set_em_data_cbk;
    ble_low_latency_register_callbacks(&cbks);
}

static void ble_enable_cbk(uint8_t status)
{
    osal_printk("enable status:%d\r\n", status);
    g_ble_enable = true;
}

static void bt_core_enable_cb_register(void)
{
    bts_dev_manager_callbacks_t dev_cb = { 0 };
    gap_ble_callbacks_t gap_cb = { 0 };
    dev_cb.ble_enable_cb = ble_enable_cbk;
    gap_cb.start_adv_cb = ble_rcu_adv_enable_cbk;
    gap_cb.stop_adv_cb = ble_rcu_adv_disable_cbk;
    gap_cb.conn_state_change_cb = ble_control_notify_connect;
    if ((gap_ble_register_callbacks(&gap_cb) != ERRCODE_BT_SUCCESS) ||
        (bts_dev_manager_register_callbacks(&dev_cb) != ERRCODE_BT_SUCCESS)) {
        osal_printk("register ble_enable_cbk failed\r\n");
    }
}

void ble_rcu_work_to_standby(void)
{
    ble_control_connect_param_update(&g_worktostandby);
}

void ble_rcu_standby_to_work(void)
{
    ble_control_set_power_state(false);
    ble_control_connect_param_update(&g_standbytowork);
    ble_control_update_local_latency(1);
}

void ble_rcu_standby_to_sleep(void)
{
#ifdef CONFIG_RCU_IS_SLEEP_DISCONNECT
    ble_control_set_power_state(true);
    ble_control_set_is_connect_callback(true);
#endif
    ble_control_update_local_latency(0);
#ifdef CONFIG_RCU_IS_SLEEP_DISCONNECT
    ble_control_disconnect_all_remote_device();
#endif
}

void ble_rcu_sleep_to_work(void)
{
    ble_control_set_is_connect_callback(false);
    ble_control_set_power_state(false);
#ifdef CONFIG_RCU_IS_SLEEP_DISCONNECT
    ble_control_connect_all_remote_device();
#endif
}

void ble_rcu_server_init(void)
{
    bt_core_enable_cb_register();
    enable_ble();
    while (g_ble_enable == false) {
        osal_msleep(BLE_RCU_TASK_DELAY_MS);
    }
    ble_hid_rcu_server_init();
    osal_printk("init ok\r\n");
}
