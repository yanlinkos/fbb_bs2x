/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * Description: SLE RCU sample of client. \n
 *
 * History: \n
 * 2025-09-02, Create file. \n
 */
#ifndef SLE_OTA_CMD_H
#define SLE_OTA_CMD_H

#include "sle_ssap_client.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

errcode_t sle_ota_recv_handler(uint8_t *data, uint16_t length);
void sle_ota_fhid_send_data_one(uint8_t service_id, uint8_t command_id, uint16_t body_len, uint8_t *body);
void sle_ota_fhid_send_data_more(uint8_t service_id, uint8_t command_id, uint16_t body_len, uint8_t *body);
void sle_ota_data_handle(ssapc_handle_value_t *data);

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif