/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: Air Mouse Common Timer Header File. \n
 *
 * History: \n
 * 2025-09-15, Create file. \n
 */
#ifndef AIR_MOUSE_COMMON_TIMER_H
#define AIR_MOUSE_COMMON_TIMER_H

#include <stdint.h>
#include "slp.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

typedef enum {
    AM_TIMER_TYPE_PRINT = 0,
    AM_TIMER_TYPE_RSSI,
    AM_TIMER_TYPE_NUM,
} air_mouse_timer_type_e;

typedef struct {
    SlpCursorRslt cursor;
    SlpRangingRpt ranging;
    int8_t rssi;
    struct {
        uint8_t cursor : 1;
        uint8_t ranging : 1;
        uint8_t rssi : 1;
        uint8_t reserved : 5;
    } flags;    // 标志数据是否打印过
} print_info_t; // 记录上报值用于周期性打印

void rst_print_info(void);
void update_am_print_info_cursor(SlpCursorRslt *cursor);
void update_am_print_info_ranging(SlpRangingRpt *ranging);
void update_am_print_info_rssi(int8_t rssi);
void air_mouse_timer_start(air_mouse_timer_type_e type);
void air_mouse_timer_stop(air_mouse_timer_type_e type);
void air_mouse_timer_stop_all(void);
void air_mouse_timer_init(void);

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif
