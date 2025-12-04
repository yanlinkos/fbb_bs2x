/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2023-2023. All rights reserved. \n
 *
 * Description: SLE RCU Server Source. \n
 * Author:  \n
 * History: \n
 * 2023-9-10, Create file. \n
 */
#include <pthread.h>
#include "securec.h"
#include "stdbool.h"
#include "soc_osal.h"
#include "common_def.h"
#include "rcu.h"
#include "app_timer.h"
#include "vdt_codec.h"
#include "app_status.h"
#include "app_keyscan.h"
#include "sle_low_latency.h"
#include "sle_device_manager.h"
#include "sle_device_discovery.h"
#include "sle_rcu_server_adv.h"
#include "sle_service_hids.h"
#include "sle_rcu_server.h"
#include "sle_rcu_server_control.h"

static bool g_low_power_state = false;
static bool g_is_sle_connect_callback = false;
sle_callback_entry_t g_sle_callbacks[NONE_DEVICE];

static void sle_callback_to_adv(uint8_t sle_index, sle_addr_t *addr)
{
    sle_set_current_control_obj(sle_index);
    sle_rcu_server_directed_adv_init(addr);
}

static void sle_add_callback(sle_callback_function func, uint8_t sle_index, const sle_addr_t *addr)
{
    g_sle_callbacks[sle_index].func = func;
    memcpy_s(&g_sle_callbacks[sle_index].addr, sizeof(sle_addr_t), addr, sizeof(sle_addr_t));
}

void sle_control_callbacks(uint8_t sle_index)
{
    int num = 0;
    while (1) {
        if (g_sle_callbacks[sle_index].func != NULL) {
            g_sle_callbacks[sle_index].func(sle_index, &g_sle_callbacks[sle_index].addr); // 调用回调函数，传递数据
        } else {
            break;
        }
        if (sle_index == get_current_control_obj()) {
            osal_msleep(APP_CONTROL_MAX_TIME);
        } else {
            osal_msleep(APP_DEFAULT_MAX_TIME);
        }
        num++;
        if (num == APP_SLE_DEFAULT_MAX_COUNT) {
            break;
        }
        sle_stop_announce(SLE_ADV_HANDLE_DEFAULT);
    }
}

static uint8_t sle_control_con_index(const sle_addr_t *addr)
{
    connect_device_info_t info = get_connect_device_info();
    for (int i = TV; i < NONE_DEVICE; i++) {
        if (memcmp(&info.sle_addr[i], addr, sizeof(sle_addr_t)) == 0) {
            return i;
        }
    }
    return NONE_DEVICE;
}

void sle_control_notify_connect(uint16_t conn_id, const sle_addr_t *addr, sle_acb_state_t conn_state,
                                sle_pair_state_t pair_state, sle_disc_reason_t disc_reason)
{
    unused(pair_state);
    unused(disc_reason);
    uint8_t sle_index = sle_control_con_index(addr);
    osal_printk("sle_notify_connect conn_id:%d, con_state:%d; sle_index:%d\r\n", conn_id, conn_state, sle_index);
    if (conn_state == SLE_ACB_STATE_CONNECTED) {
        set_app_sle_conn_status(conn_id, APP_CONNECT_STATUS_CONNECTED);
        if (sle_index == NONE_DEVICE) {
            sle_index = get_current_control_obj();
            osal_printk("sle_control_discon_index sle_index:%d\r\n", sle_index);
        }
#if defined(CONFIG_RCU_MASS_PRODUCTION_TEST)
        sle_stop_announce(SLE_ADV_HANDLE_DEFAULT);
#endif
        if (!g_is_sle_connect_callback) {
            stop_all_adv();
        } else {
            sle_stop_announce(SLE_ADV_HANDLE_DEFAULT);
        }
        set_rcu_mode(RCU_MODE_ADV_SEND);
        memset_s(&g_sle_callbacks[sle_index], sizeof(sle_callback_entry_t), 0, sizeof(sle_callback_entry_t));
    } else if (conn_state == SLE_ACB_STATE_DISCONNECTED) {
        set_app_sle_conn_status(conn_id, APP_CONNECT_STATUS_DISCONNECT);
        sle_add_callback(sle_callback_to_adv, sle_index, addr);
#if !defined(CONFIG_RCU_MASS_PRODUCTION_TEST)
        if (!g_low_power_state) {
            if (sle_index == TV) {
                app_timer_process_start(TIME_CMD_SLE_TV_CALL, APP_SLE_CALL_TIME);
            } else if (sle_index == OTT) {
                app_timer_process_start(TIME_CMD_SLE_OTT_CALL, APP_SLE_CALL_TIME);
            }
        }
#endif
    }
    set_app_sle_conn_device_info(sle_index, conn_id, addr);
}

void sle_control_connect_param_update(sle_connection_param_update_t *g_worktostandby)
{
    connect_device_info_t info = get_connect_device_info();
    for (int i = TV; i < NONE_DEVICE; i++) {
        if (info.connect_type[i] == CONNECT_SLE) {
            g_worktostandby->conn_id = info.con_id[i];
            sle_update_connect_param(g_worktostandby);
        }
    }
}

void sle_control_remote_device(void)
{
    uint32_t device_type = get_current_control_obj();
    sle_pair_remote_device(sle_control_get_sle_addr(device_type));
}

void sle_control_set_power_state(bool power_state)
{
    g_low_power_state = power_state;
}

void sle_control_set_is_connect_callback(bool is_sle_connect_callback)
{
    g_is_sle_connect_callback = is_sle_connect_callback;
}

#ifdef CONFIG_RCU_IS_SLEEP_DISCONNECT
void sle_control_connect_all_remote_device(void)
{
    connect_device_info_t info = get_connect_device_info();
    for (uint8_t i = TV; i < NONE_DEVICE; i++) {
        if (info.connect_type[i] == CONNECT_SLE) {
            sle_control_callbacks(i);
        }
    }
}
#endif

void sle_control_connect_remote_device(uint8_t device_target)
{
    if ((app_control_get_con_type() == CONNECT_SLE) && (sle_control_get_con_state() == APP_CONNECT_STATUS_DISCONNECT)) {
        sle_set_current_control_obj(device_target);
        sle_rcu_server_directed_adv_init(sle_control_get_sle_addr(device_target));
    }
}

void sle_control_clean_all_remote_device(void)
{
    for (uint8_t i = TV; i < NONE_DEVICE; i++) {
        uint16_t con_state = sle_control_get_specific_con_state(i);
        if ((con_state == APP_CONNECT_STATUS_CONNECTED) || (con_state = APP_CONNECT_STATUS_PAIRED)) {
            sle_remove_paired_remote_device(sle_control_get_sle_addr(i));
        }
        remove_connect_device_info(i);
    }
}

void sle_control_disconnect_all_remote_device(void)
{
    for (uint8_t i = TV; i < NONE_DEVICE; i++) {
        if (app_control_get_specific_con_type(i) == CONNECT_SLE) {
            uint16_t con_state = sle_control_get_specific_con_state(i);
            if ((con_state == APP_CONNECT_STATUS_CONNECTED) || (con_state = APP_CONNECT_STATUS_PAIRED)) {
                sle_disconnect_remote_device(sle_control_get_sle_addr(i));
            }
        }
    }
}

void sle_control_disconnect_remote_device(uint8_t device_target)
{
    if (app_control_get_specific_con_type(device_target) == CONNECT_SLE) {
        uint16_t con_state = sle_control_get_specific_con_state(device_target);
        if ((con_state == APP_CONNECT_STATUS_CONNECTED) || (con_state = APP_CONNECT_STATUS_PAIRED)) {
            sle_disconnect_remote_device(sle_control_get_sle_addr(device_target));
        }
    }
}

void sle_control_update_local_latency(uint8_t type)
{
    for (int i = TV; i < NONE_DEVICE; i++) {
        if (app_control_get_specific_con_type(i) == CONNECT_SLE) {
            uint16_t con_state = sle_control_get_specific_con_state(i);
            if ((con_state == APP_CONNECT_STATUS_CONNECTED) || (con_state = APP_CONNECT_STATUS_PAIRED)) {
                sle_update_local_latency(sle_control_get_specific_con_id(i), type, LATENCY_ORIGINAL_VALUE);
            }
        }
    }
}

void sle_control_send_report_by_handle(const uint8_t *data, uint8_t len, uint16_t conn_id)
{
    app_globle_status_t app_globle_status = get_app_globle_status();
    uint16_t con_state = app_globle_status.app_sle_conn_status[conn_id];
    if ((con_state == APP_CONNECT_STATUS_CONNECTED) || (con_state = APP_CONNECT_STATUS_PAIRED)) {
        sle_rcu_server_send_report_by_handle(data, len, conn_id);
    }
}