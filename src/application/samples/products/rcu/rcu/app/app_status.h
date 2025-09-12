/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * Description: APP STATUS HEADER FILE. \n
 *
 * History: \n
 * 2024-05-22, Create file. \n
 */
#ifndef APP_STATUS_H
#define APP_STATUS_H

#include "stdbool.h"
#include "bts_def.h"
#include "bts_le_gap.h"
#include "sle_connection_manager.h"
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

#define RCU_TARGET_ADDR_NUM                2
/* 定向广播偏移值 */
#define ADV_HANDLE_DIRECTED_OFFSET            2
#define APP_ADV_INTERVAL                      70
#define APP_DEFAULT_CONNECT_ID                0xFF
#define APP_CONTROL_MAX_TIME                  60
#define APP_DEFAULT_MAX_TIME                  100
#define APP_SLE_DEFAULT_MAX_COUNT             4
#define APP_BLE_DEFAULT_MAX_COUNT             2

typedef enum {
    APP_SYS_WORK,
    APP_SYS_STANDBY,
    APP_SYS_SLEEP,
} app_sys_status_t;

typedef enum {
    APP_CONNECT_STATUS_IDLE = 0,
    APP_CONNECT_STATUS_ADVING,
    APP_CONNECT_STATUS_CONNECTED,
    APP_CONNECT_STATUS_DISCONNECT,
    APP_CONNECT_STATUS_PAIRED,
} app_connect_status_t;

typedef enum {
    SLE_ADV_TYPE_IDLE = 0,
    SLE_ADV_TYPE_DEFAULT,
    SLE_ADV_TYPE_DIRECTED,
    SLE_ADV_TYPE_WAKEUP,
} sle_adv_type_t;

enum {
    RCU_MODE_IDLE = 0,
    RCU_MODE_VOICE_WORK = 0x01,
    RCU_MODE_KEY_OPERATION = 0x02,
    RCU_MODE_IR_SEND = 0x04,
    RCU_MODE_IR_STUDY = 0x08,
    RCU_MODE_ADV_SEND = 0x10,
    RCU_MODE_LED_OPEN = 0x20,
    RCU_MODE_OTA_UPGRADE = 0x40,

    RCU_MODE_TEST_NO_SLEPP = 0x80,
};

enum {
    LATENCY_FEW_INTERACTION = 0,
    LATENCY_ORIGINAL_VALUE = 0xFFFF,
};

typedef enum {
    CONNECT_NONE,
    CONNECT_SLE,
    CONNECT_BLE
} connect_type_e;

typedef enum {
    TV = 0,
    OTT,
    NONE_DEVICE
} device_control_target_e;

typedef struct connect_device_info {
    uint8_t con_id[NONE_DEVICE];
    bd_addr_t ble_addr[NONE_DEVICE];
    sle_addr_t sle_addr[NONE_DEVICE];
    connect_type_e connect_type[NONE_DEVICE];
} connect_device_info_t;

typedef struct app_globle_status {
    app_connect_status_t app_sle_conn_status[CONFIG_RCU_MULTICON_NUM];
    app_connect_status_t app_ble_conn_status[CONFIG_RCU_MULTICON_NUM];
    sle_adv_type_t app_sle_adv_status[CONFIG_RCU_MULTICON_NUM];
    sle_adv_type_t app_ble_adv_status[CONFIG_RCU_MULTICON_NUM];
} app_globle_status_t;

uint8_t get_current_control_obj(void);
void set_current_control_obj(uint8_t control_obj);
app_globle_status_t get_app_globle_status(void);
connect_device_info_t get_connect_device_info(void);
void remove_connect_device_info(uint8_t device_target);
void set_app_sys_status(app_sys_status_t status);

#if defined(CONFIG_SAMPLE_SUPPORT_BLE_RCU_SERVER)
uint16_t ble_control_get_con_id(void);
uint16_t ble_control_get_con_state(void);
bd_addr_t* ble_control_get_ble_addr(uint8_t device_target);
uint16_t ble_control_get_specific_con_id(uint8_t device_target);
uint16_t ble_control_get_specific_con_state(uint8_t device_target);
void set_app_ble_adv_status(uint16_t conn_id, sle_adv_type_t status);
void set_app_ble_conn_status(uint16_t conn_id, app_connect_status_t status);
void set_app_ble_conn_device_info(uint16_t device_target, uint8_t con_id, const bd_addr_t *ble_addr);
#endif
#if defined(CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER)
uint16_t sle_control_get_con_id(void);
uint16_t sle_control_get_con_state(void);
sle_addr_t* sle_control_get_sle_addr(uint8_t device_target);
uint16_t sle_control_get_specific_con_id(uint8_t device_target);
uint16_t sle_control_get_specific_con_state(uint8_t device_target);
void set_app_sle_adv_status(uint16_t conn_id, sle_adv_type_t status);
void set_app_sle_conn_status(uint16_t conn_id, app_connect_status_t status);
void set_app_sle_conn_device_info(uint16_t device_target, uint8_t con_id, const sle_addr_t *sle_addr);
#endif
#if defined(CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER) || defined(CONFIG_SAMPLE_SUPPORT_BLE_RCU_SERVER)
uint8_t get_active_con_id(void);
uint16_t app_control_get_specific_con_type(uint8_t device_target);
#endif
uint16_t app_control_get_con_type(void);
void set_rcu_mode(uint8_t mode);
void clear_rcu_mode(void);
uint8_t get_rcu_mode(void);
void app_conn_info_init(void);

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif