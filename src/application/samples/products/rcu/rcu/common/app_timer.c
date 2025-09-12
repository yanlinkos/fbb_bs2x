/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * Description: APP TIMER. \n
 *
 * History: \n
 * 2024-05-16, Create file. \n
 */

#include "common_def.h"
#include "errcode.h"
#include "soc_osal.h"
#include "osal_timer.h"
#include "osal_debug.h"
#include "app_msg_queue.h"
#include "app_status.h"
#if defined(CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER)
#include "sle_common.h"
#include "sle_device_discovery.h"
#include "sle_connection_manager.h"
#include "sle_errcode.h"
#include "sle_rcu_server_control.h"
#include "sle_rcu_server_adv.h"
#endif
#if defined(CONFIG_SAMPLE_SUPPORT_BLE_RCU_SERVER)
#include "ble_rcu_server_adv.h"
#include "ble_rcu_server_control.h"
#include "bts_le_gap.h"
#endif
#include "app_timer.h"

osal_timer app_timer[TIME_CMD_MAX];

void key_hold_long_start_fun(unsigned int time)
{
    osal_timer_stop(&app_timer[TIME_CMD_KEY_HOLD_LONG]);
    osal_timer_mod(&app_timer[TIME_CMD_KEY_HOLD_LONG], time);
}

void key_hold_long_stop_fun(void)
{
    osal_timer_stop(&app_timer[TIME_CMD_KEY_HOLD_LONG]);
}

void key_hold_long_timer_callback(unsigned long para)
{
    unused(para);
    app_msg_data_t msg;
    msg.type = KEY_HOLD_LONG_EVENT_MSG;
    msg.length = 0;
    app_write_msgqueue(msg);
    osal_timer_stop(&app_timer[TIME_CMD_KEY_HOLD_LONG]);
}

void pair_start_fun(unsigned int time)
{
    unused(time);
#if defined(CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER) || defined(CONFIG_SAMPLE_SUPPORT_BLE_RCU_SERVER)
    app_globle_status_t status = get_app_globle_status();
    uint16_t conn_id = 0;
#endif
#if defined(CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER)
    conn_id = sle_control_get_con_id();
    if (status.app_sle_conn_status[conn_id] == APP_CONNECT_STATUS_ADVING) {
        set_app_sle_conn_status(conn_id, APP_CONNECT_STATUS_IDLE);
        set_app_sle_adv_status(conn_id, SLE_ADV_TYPE_IDLE);
        sle_rcu_server_adv_deinit();
    } else {
        sle_rcu_server_adv_init();
    }
#endif

#if defined(CONFIG_SAMPLE_SUPPORT_BLE_RCU_SERVER)
    conn_id = ble_control_get_con_id();
    if (status.app_ble_conn_status[conn_id] == APP_CONNECT_STATUS_ADVING) {
        set_app_ble_conn_status(conn_id, APP_CONNECT_STATUS_IDLE);
        set_app_ble_adv_status(conn_id, SLE_ADV_TYPE_IDLE);
    } else {
        ble_rcu_set_adv_data();
        ble_rcu_start_adv();
    }
#endif

    osal_timer_start(&app_timer[TIME_CMD_PAIR]);
}

void pair_stop_fun(void)
{
    osal_timer_stop(&app_timer[TIME_CMD_PAIR]);
}

void pair_timer_callback(unsigned long para)
{
    unused(para);
#if defined(CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER)
    sle_rcu_server_adv_deinit();
#endif

#if defined(CONFIG_SAMPLE_SUPPORT_BLE_RCU_SERVER)
    gap_ble_stop_adv(BTH_GAP_BLE_ADV_HANDLE_DEFAULT);
#endif
    pair_stop_fun();
}

void unpair_start_fun(unsigned int time)
{
    unused(time);
}

void unpair_stop_fun(void)
{
}

void unpair_timer_callback(unsigned long para)
{
    unused(para);
    unpair_stop_fun();
}

void sleep_check_start_fun(unsigned int time)
{
    unused(time);
    osal_timer_mod(&app_timer[TIME_CMD_SLEEP_CHECK], APP_SLEEP_CHECK_START_TIME);
}

void sleep_check_stop_fun(void)
{
    osal_timer_stop(&app_timer[TIME_CMD_SLEEP_CHECK]);
}

void sleep_check_timer_callback(unsigned long para)
{
    unused(para);
    app_msg_data_t msg;
    msg.type = SLEPP_CHECK_MSG;
    msg.length = 0;
    app_write_msgqueue(msg);
}

void ir_study_start_fun(unsigned int time)
{
    osal_timer_mod(&app_timer[TIME_CMD_IR_STUDY], time);
}
 
void ir_study_stop_fun(void)
{
    osal_timer_stop(&app_timer[TIME_CMD_IR_STUDY]);
}
 
void ir_study_timer_callback(unsigned long para)
{
    unused(para);
    ir_study_stop_fun();
    clear_rcu_mode();
    osal_printk("exit RCU_MODE_IR_STUDY\r\n");
}

void pair_start_sle_tv_call_fun(unsigned int time)
{
    unused(time);
    osal_printk("pair_start_sle_tv_call_fun\r\n");
#if defined(CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER)
    sle_control_callbacks(TV);
#endif
    osal_timer_start(&app_timer[TIME_CMD_PAIR]);
}

void pair_stop_sle_tv_call_fun(void)
{
    osal_timer_stop(&app_timer[TIME_CMD_PAIR]);
}

void pair_timer_sle_tv_call_callback(unsigned long para)
{
    unused(para);
    pair_stop_sle_tv_call_fun();
}

void pair_start_sle_ott_call_fun(unsigned int time)
{
    unused(time);
    osal_printk("pair_start_sle_ott_call_fun\r\n");
#if defined(CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER)
    sle_control_callbacks(OTT);
#endif
    osal_timer_start(&app_timer[TIME_CMD_PAIR]);
}

void pair_stop_sle_ott_call_fun(void)
{
    osal_timer_stop(&app_timer[TIME_CMD_PAIR]);
}

void pair_timer_sle_ott_call_callback(unsigned long para)
{
    unused(para);
    pair_stop_sle_ott_call_fun();
}

void pair_start_ble_tv_call_fun(unsigned int time)
{
    unused(time);
    osal_printk("pair_start_ble_tv_call_fun\r\n");
#if defined(CONFIG_SAMPLE_SUPPORT_BLE_RCU_SERVER)
    ble_control_callbacks(TV);
#endif
    osal_timer_start(&app_timer[TIME_CMD_PAIR]);
}

void pair_stop_ble_tv_call_fun(void)
{
    osal_timer_stop(&app_timer[TIME_CMD_PAIR]);
}

void pair_timer_ble_tv_call_callback(unsigned long para)
{
    unused(para);
    pair_stop_ble_tv_call_fun();
}

void pair_start_ble_ott_call_fun(unsigned int time)
{
    unused(time);
    osal_printk("pair_start_ble_ott_call_fun\r\n");
#if defined(CONFIG_SAMPLE_SUPPORT_BLE_RCU_SERVER)
    ble_control_callbacks(OTT);
#endif
    osal_timer_start(&app_timer[TIME_CMD_PAIR]);
}

void pair_stop_ble_ott_call_fun(void)
{
    osal_timer_stop(&app_timer[TIME_CMD_PAIR]);
}

void pair_timer_ble_ott_call_callback(unsigned long para)
{
    unused(para);
    pair_stop_ble_ott_call_fun();
}

app_timer_t app_timer_table[] = {
    {TIME_CMD_KEY_HOLD_LONG, key_hold_long_start_fun, key_hold_long_stop_fun,
     key_hold_long_timer_callback, APP_HOLD_LONG_TIME},
    {TIME_CMD_PAIR,          pair_start_fun,          pair_stop_fun,
     pair_timer_callback,          APP_PAIR_TIME},
    {TIME_CMD_SLEEP_CHECK,   sleep_check_start_fun,   sleep_check_stop_fun,
     sleep_check_timer_callback,   APP_SLEEP_CHECK_TIME},
    {TIME_CMD_UNPAIR,         unpair_start_fun,        unpair_stop_fun,
     unpair_timer_callback,        APP_UNPAIR_TIME},
    {TIME_CMD_IR_STUDY,      ir_study_start_fun,       ir_study_stop_fun,
     ir_study_timer_callback,      APP_IR_STUDY_TIME},
    {TIME_CMD_SLE_TV_CALL,      pair_start_sle_tv_call_fun,  pair_stop_sle_tv_call_fun,
     pair_timer_sle_tv_call_callback,      APP_SLE_CALL_TIME},
    {TIME_CMD_SLE_OTT_CALL,      pair_start_sle_ott_call_fun,  pair_stop_sle_ott_call_fun,
     pair_timer_sle_ott_call_callback,      APP_SLE_CALL_TIME},
    {TIME_CMD_BLE_TV_CALL,      pair_start_ble_tv_call_fun,  pair_stop_ble_tv_call_fun,
     pair_timer_ble_tv_call_callback,      APP_BLE_CALL_TIME},
    {TIME_CMD_BLE_OTT_CALL,      pair_start_ble_ott_call_fun,  pair_stop_ble_ott_call_fun,
     pair_timer_ble_ott_call_callback,      APP_BLE_CALL_TIME},
};

void app_timer_process_start(APP_TIMER_CMD cmd, unsigned int time)
{
    app_timer_table[cmd].start_fun(time);
}

void app_timer_process_stop(APP_TIMER_CMD cmd)
{
    app_timer_table[cmd].stop_fun();
}

/* 注册定时器 */
void app_timer_init(void)
{
    for (int i = 0; i < TIME_CMD_MAX; i++) {
        app_timer[i].timer = NULL;
        app_timer[i].data = 0;
        app_timer[i].handler = app_timer_table[i].handler;
        app_timer[i].interval = app_timer_table[i].interval;
        osal_timer_init(&app_timer[i]);
    }
    osal_printk("app_timer_init!\r\n");
}