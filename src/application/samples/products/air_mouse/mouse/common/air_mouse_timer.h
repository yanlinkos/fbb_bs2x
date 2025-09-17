/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * Description: Air Mouse Timer Header File. \n
 *
 * History: \n
 * 2024-09-27, Create file. \n
 */
#ifndef AIR_MOUSE_TIMER_H
#define AIR_MOUSE_TIMER_H

#include <stdint.h>

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

typedef enum {
    TIME_CMD_KEY_HOLD_LONG,  // 组合键长按时间
    TIME_CMD_PAIR,
    TIME_CMD_UNPAIR,
    TIME_CMD_NUM,
} app_timer_cmd_e;

void app_timer_process_start(app_timer_cmd_e cmd, unsigned long data);
void app_timer_process_stop(app_timer_cmd_e cmd);
void app_timer_init(void);

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif
