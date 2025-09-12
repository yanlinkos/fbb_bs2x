/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * Description: Air Mouse Timer Source File. \n
 *
 * History: \n
 * 2024-09-27, Create file. \n
 */
#include "air_mouse_timer.h"
#include "common_def.h"
#include "errcode.h"
#include "osal_debug.h"
#include "osal_timer.h"
#include "soc_osal.h"
#include "sle_common.h"
#include "sle_connection_manager.h"
#include "sle_device_discovery.h"
#include "air_mouse_queue.h"
#include "../keyscan/air_mouse_keyscan.h"
#include "../led/air_mouse_led.h"
#include "../sle_air_mouse_server/sle_air_mouse_server_adv.h"
#include "../sle_air_mouse_server/sle_air_mouse_server.h"

#define TIME_HOLD_LONG  3000
#define TIME_PAIR       10000
#define TIME_UNPAIR     10000

typedef struct {
    app_timer_cmd_e cmd;
    void (*start_func)(unsigned long);  // 启动处理，启动定时器等
    void (*stop_func)(void);            // 中途停止操作
    void (*handler)(unsigned long);     // 定时器回调函数
    unsigned int interval;              // timer timing duration, unit: ms
} timer_table_t;

static osal_timer g_timer_arr[TIME_CMD_NUM];

void send_key_hold_msg(combine_key_e combine_key)
{
    msg_data_t msg = {MSG_TYPE_KEY_HOLD_LONG_EVENT, {0}};
    if (memcpy_s(&msg.buffer, MSG_BUFFER_LEN, &combine_key, sizeof(combine_key_e)) != EOK) {
        osal_printk("send key hold msg failed\r\n");
        return;
    }
    msg_queue_write(&msg);
}

static void key_hold_start_func(unsigned long combine_key)
{
    osal_printk("[timer] start, key hold\r\n");
    osal_timer *timer = &g_timer_arr[TIME_CMD_KEY_HOLD_LONG];
    timer->data = combine_key;
    osal_timer_stop(timer);
    osal_timer_mod(timer, timer->interval);
}

static void key_hold_stop_func(void)
{
    osal_printk("[timer] stop, key hold\r\n");
    osal_timer_stop(&g_timer_arr[TIME_CMD_KEY_HOLD_LONG]);
}

static void key_hold_timer_callback(unsigned long combine_key)
{
    osal_printk("[timer] callback, key hold\r\n");
    send_key_hold_msg(combine_key);
}

static void pair_start_func(unsigned long data)
{
    unused(data);
    osal_printk("[timer] start, pair\r\n");
    osal_timer_start(&g_timer_arr[TIME_CMD_PAIR]);
    set_led_status(LED_STATUS_PAIRING);
    sle_remove_all_pairs();
    set_announce_keyscan_flag();
    sle_start_announce(SLE_ADV_HANDLE_DEFAULT);
}

static void pair_stop_func(void)
{
    osal_printk("[timer] stop, pair\r\n");
    set_led_status(LED_STATUS_IDLE);
    sle_stop_announce(SLE_ADV_HANDLE_DEFAULT);
    osal_timer_stop(&g_timer_arr[TIME_CMD_PAIR]);
}

static void pair_timer_callback(unsigned long para)
{
    unused(para);
    osal_printk("[timer] callback, pair\r\n");
    pair_stop_func();
}

static void unpair_start_func(unsigned long data)
{
    unused(data);
    osal_printk("[timer] start, unpair\r\n");
    set_led_status(LED_STATUS_UNPAIRING);
    osal_msleep(2000);  // 2000:解配对执行速度较快，让指示灯闪烁一段时间
    osal_timer_start(&g_timer_arr[TIME_CMD_UNPAIR]);
    set_announce_keyscan_flag();
    sle_stop_announce(SLE_ADV_HANDLE_DEFAULT);
    sle_remove_all_pairs();
    app_timer_process_stop(TIME_CMD_UNPAIR);
}

static void unpair_stop_func(void)
{
    osal_printk("[timer] stop, unpair\r\n");
    osal_timer_stop(&g_timer_arr[TIME_CMD_UNPAIR]);
    set_led_status(LED_STATUS_IDLE);
}

static void unpair_timer_callback(unsigned long para)
{
    unused(para);
    osal_printk("[timer] callback, unpair%x\r\n");
    set_led_status(LED_STATUS_IDLE);
    unpair_stop_func();
}

static const timer_table_t g_timer_table[TIME_CMD_NUM] = {
    {TIME_CMD_KEY_HOLD_LONG, key_hold_start_func, key_hold_stop_func, key_hold_timer_callback, TIME_HOLD_LONG},
    {TIME_CMD_PAIR, pair_start_func, pair_stop_func, pair_timer_callback, TIME_PAIR},
    {TIME_CMD_UNPAIR, unpair_start_func, unpair_stop_func, unpair_timer_callback, TIME_UNPAIR},
};

void app_timer_process_start(app_timer_cmd_e cmd, unsigned long data)
{
    g_timer_table[cmd].start_func(data);
}

void app_timer_process_stop(app_timer_cmd_e cmd)
{
    g_timer_table[cmd].stop_func();
}

/* 注册定时器 */
void app_timer_init(void)
{
    osal_printk("app_timer_init!\r\n");
    for (int i = 0; i < TIME_CMD_NUM; i++) {
        g_timer_arr[i].timer = NULL;
        g_timer_arr[i].data = 0;
        g_timer_arr[i].handler = g_timer_table[i].handler;
        g_timer_arr[i].interval = g_timer_table[i].interval;
        int ret = osal_timer_init(&g_timer_arr[i]);
        if (ret != OSAL_SUCCESS) {
            osal_printk("osal timer init fail, i:%u ret:0x%08x\r\n", i, ret);
            return;
        }
    }
}
