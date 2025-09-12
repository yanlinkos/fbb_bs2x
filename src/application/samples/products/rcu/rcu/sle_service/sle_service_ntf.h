/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * Description: SLE DIS SERVICE HEADER FILE \n
 *
 * History: \n
 * 2024-5-30, Create file. \n
 */
#ifndef SLE_SERVICE_NTF_H
#define SLE_SERVICE_NTF_H

#include <stdint.h>
#include "errcode.h"
#include "sle_ssap_server.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

#define UUID_LEN_2                      2

errcode_t sle_add_ntf_service(uint8_t server_id);
uint16_t rcu_get_handle(void);
errcode_t sle_rcu_server_send_report_by_uuid(const uint8_t *data, uint8_t len, uint16_t conn_id);

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif