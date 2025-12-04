/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2024. All rights reserved.
 * 2024-03-22， Create file. \n
 */
#ifndef AIR_MOUSE_COMMON_H
#define AIR_MOUSE_COMMON_H

#include "slp.h"
#include "usb/air_mouse_usb.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

#define SLEEP_COUNT_THRESHOLD               1000 // 1000次相同报点进入睡眠
#define MM_TO_UM                            1000 // mm->um
#define SLE_AIR_MOUSE_DEFAULT_CONNECT_ID    0

// 按键序号
typedef enum {
    RCU_KEY_S0 = 0,
    RCU_KEY_S1,
    RCU_KEY_S2,
    RCU_KEY_S3,
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
    RCU_KEY_S17,
    RCU_KEY_S18,
    RCU_KEY_S19,
    RCU_KEY_S20,
    RCU_KEY_NUM,
} rcu_key_index_e;

// 控制命令
typedef enum {
    /* rcu */
    AM_CMD_CURSOR_SPEED_LOW = SLP_CURSOR_SPEED_LOW,        // 低灵敏度
    AM_CMD_CURSOR_SPEED_MEDIUM = SLP_CURSOR_SPEED_MEDIUM,  // 中灵敏度
    AM_CMD_CURSOR_SPEED_HIGH = SLP_CURSOR_SPEED_HIGH,      // 高灵敏度
    AM_CMD_LEFT_KEY_UP,                                    // 左键抬起
    AM_CMD_LEFT_KEY_DOWN,                                  // 左键按下
    AM_CMD_KEYBOARD_UP,                                    // 按键抬起
    AM_CMD_SET_FACTORY_TEST_NONE,                          // 指向业务
    AM_CMD_RANGING_START,                                  // 测距启动
    AM_CMD_RANGING_STOP,                                   // 测距停止
    AM_CMD_GYRO_ZERO_OFFSET,                               // 发送Gyro零偏
    /* dongle */
    AM_CMD_RANGING_RESTART,                                // 重启测距
    AM_CMD_RCU_SLEEP,                                      // 遥控器睡眠
} air_mouse_cmd_e;

typedef enum {
    AM_RESOLUTION_720P = 0,
    AM_RESOLUTION_1080P,
    AM_RESOLUTION_4K,
    AM_RESOLUTION_8K,
} air_mouse_resolution_e;

void set_slp_uart_buffer(void);
void set_transform_param(SlpImuType type);
void set_ant_sw_param(SlpRfSwParam *param);
void print_slp_version(SlpVersionRpt *versionRpt);
void air_mouse_print(const char *str, bool both);

#if CONFIG_AIR_MOUSE_CI_REPLAY_TEST
ErrcodeSlpClient SendCiTestData(uint8_t *data, uint32_t len);
typedef void (*RptCiTestOutputCbk)(uint8_t *data, uint32_t len);
ErrcodeSlpClient RegisterRptCiTestOutputCbk(RptCiTestOutputCbk func);
#endif

void set_slp_cursor_speed(SlpCursorSpeed mode);
SlpCursorSpeed get_slp_cursor_speed(void);

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif
