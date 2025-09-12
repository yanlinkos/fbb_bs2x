/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2023-2023. All rights reserved.
 *
 * Description: SLE RCU sample of client. \n
 *
 * History: \n
 * 2023-09-21, Create file. \n
 */
#ifndef BLE_RCU_CLIENT_H
#define BLE_RCU_CLIENT_H

#include <stdint.h>
#include <stdbool.h>
#include "bts_gatt_client.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

#define BLE_UUID_LEN 16

#define BLE_HANDLE_TYPE_KEYBOARD            22
#define BLE_HANDLE_TYPE_MOUSE               29
#define BLE_HANDLE_TYPE_CONSUMER            36
#define BLE_HANDLE_TYPE_AMIC                43

typedef struct property_uuid_handle {
    uint8_t index;
    bt_uuid_t uuid;
    uint8_t handle;
} property_uuid_handle_t;

void ble_rcu_client_init(gattc_notification_callback notification_cb, gattc_indication_callback indication_cb);
errcode_t ble_rcu_start_scan(void);
errcode_t ble_rcu_stop_scan(void);
uint16_t get_ble_rcu_conn_id(void);
void ble_rcu_set_scan_parameters(void);
uint8_t get_ble_find_ready(void);
bool is_character_handle(int handle);

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif