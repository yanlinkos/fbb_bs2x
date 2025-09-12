/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * Description: APP TIMER. \n
 *
 * History: \n
 * 2024-05-16, Create file. \n
 */

#ifndef APP_TIMER_H
#define APP_TIMER_H

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

#define APP_HOLD_LONG_TIME                  3000
#define APP_PAIR_TIME                       3000
#define APP_BLE_CALL_TIME                   1000
#define APP_SLE_CALL_TIME                   1000
#define APP_UNPAIR_TIME                     3000
#define APP_IR_STUDY_TIME                   (2 * 60 * 1000)
#define APP_SLEEP_CHECK_TIME                3000
#define APP_SLEEP_CHECK_START_TIME          100

typedef enum {
    TIME_CMD_KEY_HOLD_LONG,
    TIME_CMD_PAIR,
    TIME_CMD_SLEEP_CHECK,
    TIME_CMD_UNPAIR,
    TIME_CMD_IR_STUDY,
    TIME_CMD_SLE_TV_CALL,
    TIME_CMD_SLE_OTT_CALL,
    TIME_CMD_BLE_TV_CALL,
    TIME_CMD_BLE_OTT_CALL,
    TIME_CMD_MAX
}APP_TIMER_CMD;

typedef struct {
    APP_TIMER_CMD cmd;
    void(*start_fun)(unsigned int);
    void(*stop_fun)(void);
    void (*handler)(unsigned long);
    unsigned int interval; // timer timing duration, unit: ms.
}app_timer_t;

void app_timer_process_start(APP_TIMER_CMD cmd, unsigned int time);
void app_timer_process_stop(APP_TIMER_CMD cmd);
void app_timer_init(void);

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif