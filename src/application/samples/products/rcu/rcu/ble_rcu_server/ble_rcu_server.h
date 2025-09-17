/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2023-2023. All rights reserved.
 *
 * Description: BLE RCU Server config. \n
 *
 * History: \n
 * 2023-9-10, Create file. \n
 */

/**
 * @defgroup bluetooth_bts_hid_server HID SERVER API
 * @ingroup  bluetooth
 * @{
 */
#ifndef BLE_UUID_SERVER_H
#define BLE_UUID_SERVER_H

#include "bts_def.h"
#include "bts_le_gap.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

#ifdef CONFIG_APP_LOG_ENABLE
#define app_print(fmt, args...) osal_printk(fmt, ##args)
#else
#define app_print(fmt, args...)
#endif

#define LOW_LATENCY_DATA_MAX 136
/* Service UUID */
#define BLE_UUID_UUID_SERVER_SERVICE                 0xABCD
/* Characteristic UUID */
#define BLE_UUID_UUID_SERVER_REPORT                  0xCDEF
/* Client Characteristic Configuration UUID */
#define BLE_UUID_CLIENT_CHARACTERISTIC_CONFIGURATION 0x2902
/* Server ID */
#define BLE_UUID_SERVER_ID 1

/* Characteristic Property */
#define UUID_SERVER_PROPERTIES   (GATT_CHARACTER_PROPERTY_BIT_READ | GATT_CHARACTER_PROPERTY_BIT_NOTIFY)

/**
 * @if Eng
 * @brief  BLE uuid server inir.
 * @attention  NULL
 * @retval BT_STATUS_SUCCESS    Excute successfully
 * @retval BT_STATUS_FAIL       Execute fail
 * @par Dependency:
 * @li bts_def.h
 * @else
 * @brief  BLE UUID服务器初始化。
 * @attention  NULL
 * @retval BT_STATUS_SUCCESS    执行成功
 * @retval BT_STATUS_FAIL       执行失败
 * @par 依赖:
 * @li bts_def.h
 * @endif
 */
void ble_rcu_server_init(void);
uint16_t get_g_connection_state(void);

void ble_rcu_work_to_standby(void);
void ble_rcu_standby_to_work(void);
void ble_rcu_standby_to_sleep(void);
void ble_rcu_sleep_to_work(void);
void ble_low_latency_cbk_reg(void);
#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif

