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
#if CONFIG_AIR_MOUSE_CPU_USAGE_STATISTIC
#include "los_cpup.h"
#endif

#define PRINT_TIMER 2 // 打印光标定时器间隔，2秒一次，单位：秒
#define RSSI_TIMER  2 // 打印rssi定时器间隔，2秒一次，单位：秒
#define CPU_TIMER   2 // 打印cpu总占用率间隔，2秒一次，单位：秒
print_info_t g_print_info = {0};

void rst_print_info(void)
{
    print_info_t temp_info = g_print_info;
    memset_s(&g_print_info, sizeof(g_print_info), 0, sizeof(g_print_info));
    // 不更新
    g_print_info.air_mouse_mode = temp_info.air_mouse_mode;
    g_print_info.radar_status = temp_info.radar_status;
    g_print_info.cursor_speed = temp_info.cursor_speed;
    g_print_info.flags.air_mouse_mode = temp_info.flags.air_mouse_mode;
    g_print_info.flags.radar_status = temp_info.flags.radar_status;
    g_print_info.flags.cursor_speed = temp_info.flags.cursor_speed;
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

void update_am_print_info_am_mode(bool flag)
{
    g_print_info.air_mouse_mode = flag;
    g_print_info.flags.air_mouse_mode = 1;
    air_mouse_info_print();
}

void update_am_print_info_radar_status(bool flag)
{
    g_print_info.radar_status = flag;
    g_print_info.flags.radar_status = 1;
    air_mouse_info_print();
}

void update_am_print_info_cursor_speed(SlpCursorSpeed cursor_speed)
{
    g_print_info.cursor_speed = cursor_speed;
    g_print_info.flags.cursor_speed = 1;
    air_mouse_info_print();
}

void update_am_print_info_rssi(int8_t rssi)
{
    g_print_info.rssi = rssi;
    g_print_info.flags.rssi = 1;
}

// 测量值打印定时器回调
void air_mouse_info_print(void)
{
    screen_size_t *screen_size = get_screen_size();
    if (g_print_info.flags.cursor) {
        g_print_info.flags.cursor = 0;
        osal_printk("[rpt] pos:(%4d,%4d)px,(%8d,%8d)mm; ",
            linear_map(g_print_info.cursor.x, 0, screen_size->x * MM_TO_UM, 0, 3840), // 3840:4K分辨率横向像素数
            linear_map(g_print_info.cursor.y, 0, screen_size->y * MM_TO_UM, 0, 2160), // 2160:4K分辨率纵向像素数
            g_print_info.cursor.x, g_print_info.cursor.y);
    } else {
        osal_printk("[rpt] pos:(----,----)px,(--------,--------)mm; ");
    }
    osal_printk("freq:%3u Hz; ", GetCursorSendNum() / PRINT_TIMER);
    RstCursorSendNum();
    if (g_print_info.flags.ranging) {
        g_print_info.flags.ranging = 0;
        osal_printk("dis:%8d mm; localazi:%3d.%02d deg,fom:%3u; peerazi:%3d.%02d deg,fom:%3u; ", g_print_info.ranging.distance,
            g_print_info.ranging.localAoxAzi / 100, abs(g_print_info.ranging.localAoxAzi % 100), // 100:放大系数
            g_print_info.ranging.localAoxAziFom,
            g_print_info.ranging.peerAoxAzi / 100, abs(g_print_info.ranging.peerAoxAzi % 100), // 100:放大系数
            g_print_info.ranging.peerAoxAziFom);
    } else {
        osal_printk("dis:-------- mm; localazi:------ deg,fom:---; peerazi:------ deg,fom:---; ");
    }

    if (g_print_info.flags.air_mouse_mode) {
        osal_printk("m:%u; ", g_print_info.air_mouse_mode);
    } else {
        osal_printk("m:-; ");
    }

    if (g_print_info.flags.radar_status) {
        osal_printk("r:%u; ", g_print_info.radar_status);
    } else {
        osal_printk("r:-; ");
    }

    if (g_print_info.flags.cursor_speed) {
        osal_printk("s:%u; ", g_print_info.cursor_speed);
    } else {
        osal_printk("s:-; ");
    }

    if (g_print_info.flags.rssi) {
        g_print_info.flags.rssi = 0;
        osal_printk("rssi:%3d\r\n", g_print_info.rssi);
    } else {
        osal_printk("rssi:---\r\n");
    }
}

// 测量值打印定时器回调
void air_mouse_info_print_timer_cbk(unsigned long arg)
{
    unused(arg);
    air_mouse_info_print();
    air_mouse_timer_start(AM_TIMER_TYPE_PRINT);
}

static void air_mouse_read_rssi_timer_cbk(unsigned long arg)
{
    unused(arg);
    sle_read_remote_device_rssi(SLE_AIR_MOUSE_DEFAULT_CONNECT_ID); // 读取RSSI
    air_mouse_timer_start(AM_TIMER_TYPE_RSSI);
}

static void air_mouse_cpu_usage_print_cbk(unsigned long arg)
{
    unused(arg);
#if CONFIG_AIR_MOUSE_CPU_USAGE_STATISTIC
    uint32_t usage = 1000 - LOS_HistoryTaskCpuUsage(0x2, CPUP_LAST_ONE_RECORD); // 1000:输出范围, 0x2:IdleCore000线程
    osal_printk("cpup 1s:%2u.%u%%\r\n", usage / 10, usage % 10); // 10:放大系数
#else
    osal_printk("cpu usage read fail\r\n");
#endif
    air_mouse_timer_start(AM_TIMER_TYPE_CPU);
}

static osal_timer g_timer_arr[AM_TIMER_TYPE_NUM] = {
    {NULL, air_mouse_info_print_timer_cbk, 0, (PRINT_TIMER * 1000)}, // AM_TIMER_TYPE_PRINT，1000：秒转毫秒
    {NULL, air_mouse_read_rssi_timer_cbk,  0, (RSSI_TIMER * 1000) }, // AM_TIMER_TYPE_RSSI，1000：秒转毫秒
    {NULL, air_mouse_cpu_usage_print_cbk,  0, (CPU_TIMER * 1000)  }, // AM_TIMER_TYPE_CPU，1000：秒转毫秒
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

#if CONFIG_AIR_MOUSE_CPU_USAGE_STATISTIC
    air_mouse_timer_start(AM_TIMER_TYPE_CPU);
#endif
}
