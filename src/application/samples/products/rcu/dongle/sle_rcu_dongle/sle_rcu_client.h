/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2023-2023. All rights reserved.
 *
 * Description: SLE RCU sample of client. \n
 *
 * History: \n
 * 2023-09-21, Create file. \n
 */
#ifndef SLE_RCU_CLIENT_H
#define SLE_RCU_CLIENT_H

#include "sle_ssap_client.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

typedef enum {
    TYPE_KEYBOARD = 0,
    TYPE_AMIC = 1,
#if defined(CONFIG_SLE_UPG_ENABLE)
    TYPE_OTA = 2,
    TYPE_MAX = 3
#else
    TYPE_MAX = 2
#endif
} data_type_e;

typedef struct property_uuid_handle {
    data_type_e type;
    sle_uuid_t uuid;
    uint8_t handle;
} property_uuid_handle_t;

void sle_rcu_client_init(ssapc_notification_callback notification_cb, ssapc_indication_callback indication_cb);
void sle_rcu_start_scan(void);
uint16_t get_sle_rcu_conn_id(void);
ssapc_write_param_t *get_sle_rcu_send_param(void);
#if defined(CONFIG_SLE_UPG_ENABLE)
uint16_t get_sle_ota_send_handle(void);
#endif
uint8_t get_ssap_find_ready(void);
uint8_t get_sle_rcu_get_connect_state(void);
uint8_t get_ssap_connect_param_update_ready(void);
bool cmp_property_handle(int handle, uint8_t *type);
#if defined (CONFIG_RCU_MASS_PRODUCTION_TEST)
sle_addr_t *sle_rcu_report_client_addr(void);
#endif
#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif