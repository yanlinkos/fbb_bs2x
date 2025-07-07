/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2024. All rights reserved.
 * 2024-03-22， Create file. \n
 */
#ifndef AIR_MOUSE_COMMON_H
#define AIR_MOUSE_COMMON_H

#include "slp.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

#define SLEEP_COUNT_THRESHOLD               1000 // 1000次相同报点进入睡眠
#define MM_TO_UM                            1000 // mm->um

// 按键序号
typedef enum {
    RCU_KEY_S3 = 3,
    RCU_KEY_S4,
    RCU_KEY_S5,
    RCU_KEY_S6,
    RCU_KEY_S7,
    RCU_KEY_S8,
    RCU_KEY_S9,
    RCU_KEY_S10,
    RCU_KEY_S11,
    RCU_KEY_S12,
    RCU_KEY_S13,
    RCU_KEY_S14,
    RCU_KEY_S15,
    RCU_KEY_S16,
    RCU_KEY_NUM,
} rcu_key_index_e;

// 按键序号
typedef enum {
    AM_CMD_CURSOR_SPEED_LOW = SLP_CURSOR_SPEED_LOW,        // 低灵敏度
    AM_CMD_CURSOR_SPEED_MEDIUM = SLP_CURSOR_SPEED_MEDIUM,  // 中灵敏度
    AM_CMD_CURSOR_SPEED_HIGH = SLP_CURSOR_SPEED_HIGH,      // 高灵敏度
    AM_CMD_LEFT_KEY_UP,                                    // 左键抬起
    AM_CMD_LEFT_KEY_DOWN,                                  // 左键按下
} air_mouse_cmd_e;

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif