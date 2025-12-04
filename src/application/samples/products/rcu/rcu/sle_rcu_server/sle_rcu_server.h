/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * Description: SLE SERVER HEADER FILE. \n
 *
 * History: \n
 * 2024-05-25, Create file. \n
 */
#ifndef SLE_RCU_SERVER_H
#define SLE_RCU_SERVER_H

#include <stdint.h>
#include "errcode.h"
#include "osal_debug.h"
#include "sle_ssap_server.h"
#include "sle_service_hids.h"
#include "sle_connection_manager.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

#define LOW_LATENCY_DATA_MAX 136
#define SLE_RCU_SERVER_LOG     "[sle rcu server]"
#define SLE_RCU_SSAP_RPT_HANDLE    2

#if defined(CONFIG_SLE_UPG_ENABLE)
typedef enum {
    SLE_RCU_OTA_RUNNING = 0x01,
    SLE_RCU_OTA_STOP = 0x02
} sle_rcu_ota_stage_e;
#endif

errcode_t sle_low_latency_register_callbacks(sle_low_latency_callbacks_t *cbks);
errcode_t sle_low_latency_set_em_data(uint16_t co_handle, uint8_t enable);
errcode_t sle_rcu_server_init(ssaps_read_request_callback ssaps_read_callback,
                              ssaps_write_request_callback ssaps_write_callback);
uint16_t sle_rcu_client_is_connected(void);
bool get_g_ssaps_ready(void);
int get_g_conn_update(void);
uint16_t get_g_sle_conn_hdl(uint32_t index);
uint16_t get_g_sle_conn_num(void);

void sle_rcu_work_to_standby(void);
void sle_rcu_standby_to_work(void);
void sle_rcu_standby_to_sleep(void);
void sle_rcu_sleep_to_work(void);

void sle_low_latency_cbk_reg(void);
uint8_t rcu_get_server_id(void);
uint16_t get_g_connid(void);

#if defined(CONFIG_SLE_UPG_ENABLE)
void sle_rcu_set_ota_stage(uint8_t ota_stage);
uint8_t sle_rcu_get_ota_stage(void);
#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif