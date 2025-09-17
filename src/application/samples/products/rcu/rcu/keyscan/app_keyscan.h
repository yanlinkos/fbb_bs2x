/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * Description: APP Keyscan Header File. \n
 *
 * History: \n
 * 2024-05-20, Create file. \n
 */

#ifndef APP_KEYSCAN_H
#define APP_KEYSCAN_H

#include "app_msg_queue.h"
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

#define KEY_MAX_NUM                        3
#define USB_HID_MAX_KEY_LENTH              6

#define PRESS_NONE_KEY                     0
#define PRESS_ONE_KEY                      1
#define PRESS_TWO_KEY                      2
#define PRESS_THREE_KEY                    3

#define IR_NEC_USER_CODE                   0x00

#define SLE_VDT_SERVER_LOG                 "[sle vdt server]"
#define ADC_GADC_CHANNEL7                  7
#define ADC_GADC_CHANNEL6                  6
#define RCU_CONSUMER_KEY_NUM               6
#define RCU_CONSUMER_KEY_OFFSET            8
#define RCU_KEYBOARD_KEY                   0x07
#define RCU_MOUSE_KEY                      0x0a
#define RCU_CONSUMER_KEY                   0x0c

#define DURATION_MS_OF_SLEEP_TO_UDS        30000

typedef union mouse_key {
    struct {
        uint8_t left_key   : 1;
        uint8_t right_key  : 1;
        uint8_t mid_key    : 1;
        uint8_t reserved   : 5;
    } b;
    uint8_t d8;
} mouse_key_t;

typedef enum {
    COMBINE_KEY_FLAG_NONE           = 0,
    COMBINE_KEY_FLAG_TEST_STATION_01,
    COMBINE_KEY_FLAG_TEST_STATION_02,
    COMBINE_KEY_FLAG_TEST_STATION_03,
    COMBINE_KEY_FLAG_TEST_STATION_04,
    COMBINE_KEY_FLAG_TEST_STATION_05,
    COMBINE_KEY_FLAG_TEST_STATION_06,
    COMBINE_KEY_FLAG_PAIR,
    COMBINE_KEY_FLAG_UNPAIR,
    COMBINE_KEY_FLAG_IR_LEARN,
    COMBINE_KEY_FLAG_IR_CHANGE,
    COMBINE_KEY_FLAG_IR_MODE_LOCAL,
    COMBINE_KEY_FLAG_IR_MODE_UPLOAD,
    COMBINE_KEY_FLAG_IR_LEARN_ERASE,
    COMBINE_KEY_FLAG_IR_TV_CONNECT,
    COMBINE_KEY_FLAG_IR_LIVE_BROADCAST_CONNECT,
    COMBINE_KEY_FLAG_SINGLE_TONE_MODE
} combine_key_e;

typedef enum {
    RCU_KEY_NON,
    RCU_KEY_POWER,
    RCU_KEY_LIVE_BROADCAST,
    RCU_KEY_OTT,
    RCU_KEY_HOME,
    RCU_KEY_OK,
    RCU_KEY_BACK,
    RCU_KEY_MENU,
    RCU_KEY_UP,
    RCU_KEY_DOWN,
    RCU_KEY_LEFT,
    RCU_KEY_RIGHT,
    RCU_KEY_SOURCE,
    RCU_KEY_VOICE,
    RCU_KEY_VOLUME_UP,
    RCU_KEY_VOLUME_DOWN,
    RCU_KEY_MUTE,
    RCU_KEY_SET_UP,
    RCU_KEY_CHANNEL_UP,
    RCU_KEY_CHANNEL_DOWN,
    RCU_KEY_LOOK_BACK,
    RCU_KEY_ONE,
    RCU_KEY_TWO,
    RCU_KEY_THREE,
    RCU_KEY_FOUR,
    RCU_KEY_FIVE,
    RCU_KEY_SIX,
    RCU_KEY_SEVEN,
    RCU_KEY_EIGHT,
    RCU_KEY_NINE,
    RCU_KEY_ZERO,
    RCU_KEY_MAX
} key_name_e;

typedef struct {
    key_name_e key_value;                    // key value
    uint8_t usage_id;                        // Usage ID
    uint8_t usage_page;                      // Usage Page
    uint8_t ir_value;                        // ir value
} key_config_t;

typedef struct {
    uint8_t num;
    uint8_t key_value[KEY_MAX_NUM];
} key_t;

void stop_all_adv(void);
void keyevent_process(uint8_t *key_buf, uint8_t keylen, APP_MSG_DATA_TYPE event);
void app_keyscan_init(void);

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif