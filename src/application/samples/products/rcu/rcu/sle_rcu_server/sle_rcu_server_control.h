/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2023-2023. All rights reserved. \n
 *
 * Description: SLE RCU HID Server config. \n
 * Author:  \n
 * History: \n
 * 2023-9-10, Create file. \n
 */

/**
 * @defgroup bluetooth_bts_hid_server HID SERVER API
 * @ingroup  bluetooth
 * @{
 */
#ifndef SLE_RCU_SERVER_CONTROL
#define SLE_RCU_SERVER_CONTROL

#include "sle_connection_manager.h"

#ifdef __cplusplus
extern "C" {
#endif
typedef void (*sle_callback_function)(uint8_t sle_index, sle_addr_t *addr);

typedef struct {
    sle_callback_function func;
    sle_addr_t addr;
} sle_callback_entry_t;

void sle_control_callbacks(uint8_t sle_index);
void sle_control_device_switch(void);
void sle_control_remote_device(void);
void sle_control_clean_all_remote_device(void);
void sle_control_connect_remote_device(uint8_t device_target);
#ifdef CONFIG_RCU_IS_SLEEP_DISCONNECT
void sle_control_connect_all_remote_device(void);
#endif
void sle_control_disconnect_remote_device(uint8_t device_target);
void sle_control_disconnect_all_remote_device(void);
void sle_control_set_power_state(bool power_state);
void sle_control_set_is_connect_callback(bool is_sle_connect_callback);
void sle_control_connect_param_update(sle_connection_param_update_t *g_worktostandby);
void sle_control_notify_connect(uint16_t conn_id, const sle_addr_t *addr, sle_acb_state_t conn_state,
                                sle_pair_state_t pair_state, sle_disc_reason_t disc_reason);
void sle_control_update_local_latency(uint8_t type);
void sle_control_send_report_by_handle(const uint8_t *data, uint8_t len, uint16_t conn_id);
#ifdef __cplusplus
}
#endif
#endif
