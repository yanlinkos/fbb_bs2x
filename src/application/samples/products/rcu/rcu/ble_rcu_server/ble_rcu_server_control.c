/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2023-2023. All rights reserved. \n
 *
 * Description: BLE RCU Server Source. \n
 * Author:  \n
 * History: \n
 * 2023-9-10, Create file. \n
 */
#include "securec.h"
#include "stdbool.h"
#include "soc_osal.h"
#include "common_def.h"
#include "rcu.h"
#include "app_timer.h"
#include "vdt_codec.h"
#include "app_status.h"
#include "app_keyscan.h"
#include "bts_low_latency.h"
#include "bts_device_manager.h"
#include "ble_rcu_server_adv.h"
#include "ble_hid_rcu_server.h"
#include "ble_rcu_server.h"
#include "ble_rcu_server_control.h"

static bool g_low_power_state = false;
static bool g_is_ble_connect_callback = false;
ble_callback_entry_t g_ble_callbacks[NONE_DEVICE];

static void ble_callback_to_adv(uint8_t ble_index, bd_addr_t *addr)
{
    ble_set_current_control_obj(ble_index);
    ble_rcu_set_adv_data();
    ble_rcu_directed_start_adv(addr);
}

static void ble_add_callback(ble_callback_function func, uint8_t ble_index, bd_addr_t *addr)
{
    g_ble_callbacks[ble_index].func = func;
    memcpy_s(&g_ble_callbacks[ble_index].addr, sizeof(bd_addr_t), addr, sizeof(bd_addr_t));
}

void ble_control_callbacks(uint8_t ble_index)
{
    int num = 0;
    while (1) {
        if (g_ble_callbacks[ble_index].func != NULL) {
            g_ble_callbacks[ble_index].func(ble_index, &g_ble_callbacks[ble_index].addr); // 调用回调函数，传递数据
        } else {
            break;
        }
        osal_msleep(APP_DEFAULT_MAX_TIME);
        num++;
        if (num == APP_BLE_DEFAULT_MAX_COUNT) {
            break;
        }
        gap_ble_stop_adv(ble_index);
    }
}

static uint8_t ble_control_con_index(bd_addr_t *addr)
{
    connect_device_info_t info = get_connect_device_info();
    for (int i = TV; i < NONE_DEVICE; i++) {
        if (memcmp(&info.ble_addr[i], addr, sizeof(bd_addr_t)) == 0) {
            return i;
        }
    }
    return NONE_DEVICE;
}

void ble_control_notify_connect(uint16_t conn_id, bd_addr_t *addr, gap_ble_conn_state_t conn_state,
                                gap_ble_pair_state_t pair_state, gap_ble_disc_reason_t disc_reason)
{
    unused(pair_state);
    unused(disc_reason);
    uint8_t ble_index = ble_control_con_index(addr);
    osal_printk("ble_notify_connect conn_id:%d, con_state:%d; ble_index:%d\r\n", conn_id, conn_state, ble_index);
    if (conn_state == GAP_BLE_STATE_CONNECTED) {
        set_app_ble_conn_status(conn_id, APP_CONNECT_STATUS_CONNECTED);
        if (ble_index == NONE_DEVICE) {
            ble_index = get_current_control_obj();
            osal_printk("ble_control_discon_index ble_index:%d\r\n", ble_index);
        }
        if (!g_is_ble_connect_callback) {
            stop_all_adv();
        } else {
            gap_ble_stop_adv(BTH_GAP_BLE_ADV_HANDLE_DEFAULT);
        }
        set_rcu_mode(RCU_MODE_ADV_SEND);
        memset_s(&g_ble_callbacks[ble_index], sizeof(ble_callback_entry_t), 0, sizeof(ble_callback_entry_t));
    } else if (conn_state == GAP_BLE_STATE_DISCONNECTED) {
        set_app_ble_conn_status(conn_id, APP_CONNECT_STATUS_DISCONNECT);
        ble_add_callback(ble_callback_to_adv, ble_index, addr);
        if (!g_low_power_state) {
            if (ble_index == TV) {
                app_timer_process_start(TIME_CMD_BLE_TV_CALL, APP_BLE_CALL_TIME);
            } else if (ble_index == OTT) {
                app_timer_process_start(TIME_CMD_BLE_OTT_CALL, APP_BLE_CALL_TIME);
            }
        }
    }
    set_app_ble_conn_device_info(ble_index, conn_id, addr);
}

void ble_control_connect_param_update(gap_conn_param_update_t *g_worktostandby)
{
    connect_device_info_t info = get_connect_device_info();
    for (int i = TV; i < NONE_DEVICE; i++) {
        if (info.connect_type[i] == CONNECT_BLE) {
            g_worktostandby->conn_handle = info.con_id[i];
            gap_ble_connect_param_update(g_worktostandby);
        }
    }
}

void ble_control_set_is_connect_callback(bool is_ble_connect_callback)
{
    g_is_ble_connect_callback = is_ble_connect_callback;
}

void ble_control_remote_device(void)
{
    uint32_t device_type = get_current_control_obj();
    gap_ble_remove_pair(ble_control_get_ble_addr(device_type));
}

void ble_control_set_power_state(bool power_state)
{
    g_low_power_state = power_state;
}

void ble_control_clean_all_remote_device(void)
{
    for (int i = TV; i < NONE_DEVICE; i++) {
        uint16_t con_state = ble_control_get_specific_con_state(i);
        if ((con_state == APP_CONNECT_STATUS_CONNECTED) || (con_state = APP_CONNECT_STATUS_PAIRED)) {
            gap_ble_remove_pair(ble_control_get_ble_addr(i));
        }
        remove_connect_device_info(i);
    }
}

#ifdef CONFIG_RCU_IS_SLEEP_DISCONNECT
void ble_control_connect_all_remote_device(void)
{
    connect_device_info_t info = get_connect_device_info();
    for (int i = TV; i < NONE_DEVICE; i++) {
        if (info.connect_type[i] == CONNECT_BLE) {
            ble_control_callbacks(i);
        }
    }
}
#endif

void ble_control_connect_remote_device(uint8_t device_target)
{
    if ((app_control_get_con_type() == CONNECT_BLE) && (ble_control_get_con_state() == APP_CONNECT_STATUS_DISCONNECT)) {
        ble_set_current_control_obj(device_target);
        ble_rcu_set_adv_data();
        ble_rcu_directed_start_adv(ble_control_get_ble_addr(device_target));
    }
}

void ble_control_disconnect_all_remote_device(void)
{
    for (int i = TV; i < NONE_DEVICE; i++) {
        if (app_control_get_specific_con_type(i) == CONNECT_BLE) {
            uint16_t con_state = ble_control_get_specific_con_state(i);
            if ((con_state == APP_CONNECT_STATUS_CONNECTED) || (con_state = APP_CONNECT_STATUS_PAIRED)) {
                gap_ble_disconnect_remote_device(ble_control_get_ble_addr(i));
            }
        }
    }
}

void ble_control_disconnect_remote_device(uint8_t device_target)
{
    if (app_control_get_specific_con_type(device_target) == CONNECT_BLE) {
        uint16_t con_state = ble_control_get_specific_con_state(device_target);
        if ((con_state == APP_CONNECT_STATUS_CONNECTED) || (con_state = APP_CONNECT_STATUS_PAIRED)) {
            gap_ble_disconnect_remote_device(ble_control_get_ble_addr(device_target));
        }
    }
}

void ble_control_update_local_latency(uint8_t type)
{
    for (int i = TV; i < NONE_DEVICE; i++) {
        if (app_control_get_specific_con_type(i) == CONNECT_BLE) {
            uint16_t con_state = ble_control_get_specific_con_state(i);
            if ((con_state == APP_CONNECT_STATUS_CONNECTED) || (con_state = APP_CONNECT_STATUS_PAIRED)) {
                gap_ble_update_local_latency(ble_control_get_specific_con_id(i), type, LATENCY_ORIGINAL_VALUE);
            }
        }
    }
}

void ble_control_send_report_by_handle(const uint8_t *data, uint8_t len, uint16_t conn_id, uint8_t usage_page)
{
    app_globle_status_t app_globle_status = get_app_globle_status();
    uint16_t con_state = app_globle_status.app_ble_conn_status[conn_id];
    if ((con_state == APP_CONNECT_STATUS_CONNECTED) || (con_state == APP_CONNECT_STATUS_PAIRED)) {
        if (usage_page == RCU_MOUSE_KEY) {
            ble_hid_rcu_server_send_mouse_input_report_by_uuid(data, len, conn_id);
        } else if (usage_page == RCU_KEYBOARD_KEY) {
            ble_hid_rcu_server_send_keyboard_input_report_by_uuid(data, len, conn_id);
        } else if (usage_page == RCU_CONSUMER_KEY) {
            ble_hid_rcu_server_send_consumer_input_report_by_uuid(data, len, conn_id);
        }
    }
}