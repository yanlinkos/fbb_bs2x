/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2023-2023. All rights reserved. \n
 *
 * Description: BLE RCU HID Server config. \n
 * Author:  \n
 * History: \n
 * 2023-9-10, Create file. \n
 */

/**
 * @defgroup bluetooth_bts_hid_server HID SERVER API
 * @ingroup  bluetooth
 * @{
 */
#ifndef BLE_RCU_SERVER_CONTROL
#define BLE_RCU_SERVER_CONTROL

#include "bts_def.h"
#include "bts_le_gap.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*ble_callback_function)(uint8_t ble_index, bd_addr_t *addr);

typedef struct {
    ble_callback_function func;
    uint8_t ble_index;
    bd_addr_t addr;
} ble_callback_entry_t;

void ble_control_callbacks(uint8_t sle_index);
uint8_t get_ble_callback_count(void);
void ble_control_device_switch(void);
void ble_control_remote_device(void);
void ble_control_clean_all_remote_device(void);
void ble_control_connect_remote_device(uint8_t device_target);
#ifdef CONFIG_RCU_IS_SLEEP_DISCONNECT
void ble_control_connect_all_remote_device(void);
#endif
void ble_control_disconnect_remote_device(uint8_t device_target);
void ble_control_disconnect_all_remote_device(void);
void ble_control_set_power_state(bool power_state);
void ble_control_set_is_connect_callback(bool is_ble_connect_callback);
void ble_control_connect_param_update(gap_conn_param_update_t *g_worktostandby);
void ble_control_notify_connect(uint16_t conn_id, bd_addr_t *addr, gap_ble_conn_state_t conn_state,
                                gap_ble_pair_state_t pair_state, gap_ble_disc_reason_t disc_reason);
void ble_control_update_local_latency(uint8_t type);
void ble_control_send_report_by_handle(const uint8_t *data, uint8_t len, uint16_t conn_id, uint8_t usage_page);
#ifdef __cplusplus
}
#endif
#endif
