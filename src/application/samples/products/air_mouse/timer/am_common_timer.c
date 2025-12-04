/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: Air Mouse Common Timer. \n
 *
 * History: \n
 * 2025-09-15, Create file. \n
 */
#include "am_common_timer.h"
#include "../air_mouse_common.h"
#include "common_def.h"
#include "osal_timer.h"
#include "securec.h"
#include "sle_connection_manager.h"
#include "soc_osal.h"

print_info_t g_print_info = {0};

void rst_print_info(void)
{
    memset_s(&g_print_info, sizeof(g_print_info), 0, sizeof(g_print_info));
}

void update_am_print_info_cursor(SlpCursorRslt *cursor)
{
    g_print_info.cursor = *cursor;
    g_print_info.flags.cursor = 1;
}

void update_am_print_info_ranging(SlpRangingRpt *ranging)
{
    g_print_info.ranging = *ranging;
    g_print_info.flags.ranging = 1;
}

void update_am_print_info_rssi(int8_t rssi)
{
    g_print_info.rssi = rssi;
    g_print_info.flags.rssi = 1;
}

// 测量值打印定时器回调
void air_mouse_info_print_timer_cbk(unsigned long arg)
{
    unused(arg);
    if (g_print_info.flags.cursor) {
        g_print_info.flags.cursor = 0;
        osal_printk("[rpt] x:%4d,px, y:%4d,px, rx:%8d,mm, ry:%8d,mm, ",
            linear_map(g_print_info.cursor.x, 0, get_screen_width() * MM_TO_UM, 0, 3840), // 3840:4K分辨率横向像素数
            linear_map(g_print_info.cursor.y, 0, get_screen_height() * MM_TO_UM, 0, 2160), // 2160:4K分辨率纵向像素数
            g_print_info.cursor.x, g_print_info.cursor.y);
    } else {
        osal_printk("[rpt] x:----,px, y:----,px, rx:--------,mm, ry:--------,mm, ");
    }

    if (g_print_info.flags.ranging) {
        g_print_info.flags.ranging = 0;
        osal_printk("dis:%8d mm, azi:%3d.%02d deg, fom:%3u, ", g_print_info.ranging.distance,
            g_print_info.ranging.aoxAzi / 100, abs(g_print_info.ranging.aoxAzi % 100), // 100:放大系数
            g_print_info.ranging.aoxAziFom);
    } else {
        osal_printk("dis:-------- mm, azi:------ deg, fom:---, ");
    }

    if (g_print_info.flags.rssi) {
        g_print_info.flags.rssi = 0;
        osal_printk("rssi:%3d\r\n", g_print_info.flags.rssi);
    } else {
        osal_printk("rssi:---\r\n");
    }
    air_mouse_timer_start(AM_TIMER_TYPE_PRINT);
}

static void air_mouse_read_rssi_timer_cbk(unsigned long arg)
{
    unused(arg);
    sle_read_remote_device_rssi(SLE_AIR_MOUSE_DEFAULT_CONNECT_ID); // 读取RSSI
    air_mouse_timer_start(AM_TIMER_TYPE_RSSI);
}

static osal_timer g_timer_arr[AM_TIMER_TYPE_NUM] = {
    {NULL, air_mouse_info_print_timer_cbk, 0, 1000}, // AM_TIMER_TYPE_PRINT
    {NULL, air_mouse_read_rssi_timer_cbk,  0, 2000}, // AM_TIMER_TYPE_RSSI
};

// 启动定时器
void air_mouse_timer_start(air_mouse_timer_type_e type)
{
    osal_timer *timer = &g_timer_arr[type];
    int ret = osal_timer_mod(timer, timer->interval);
    if (ret != OSAL_SUCCESS) {
        osal_printk("[timer] start fail, type:%u, ret:0x%x, \r\n", type, ret);
    }
}

// 停止定时器
void air_mouse_timer_stop(air_mouse_timer_type_e type)
{
    osal_timer *timer = &g_timer_arr[type];
    int ret = osal_timer_stop(timer);
    if (ret == OSAL_SUCCESS || ret == 1) { // OSAL_SUCCESS:已经停止, 1:停止成功
        osal_printk("[timer] stop, type:%u\r\n", type);
    } else {
        osal_printk("[timer] stop fail, type:%u, ret:0x%x, \r\n", type, ret);
    }
}

// 停止所有定时器
void air_mouse_timer_stop_all(void)
{
    for (uint8_t i = 0; i < AM_TIMER_TYPE_NUM; i++) {
        air_mouse_timer_stop(i);
    }
}

// 定时器初始化
void air_mouse_timer_init(void)
{
    rst_print_info();
    osal_printk("[timer] init\r\n");
    for (uint8_t i = 0; i < AM_TIMER_TYPE_NUM; i++) {
        int ret = osal_timer_init(&g_timer_arr[i]);
        if (ret != OSAL_SUCCESS) {
            osal_printk("[timer] init fail, type:%u, ret:0x%x, \r\n", i, ret);
        }
    }
}
