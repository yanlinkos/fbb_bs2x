/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * Description: SLE SERVICE COMMON FUNCTION HEADER FILE\n
 *
 * History: \n
 * 2024-5-30, Create file. \n
 */
#ifndef SLE_SERVICE_COMMON_H
#define SLE_SERVICE_COMMON_H

#include "errcode.h"
#include "osal_debug.h"
#include "sle_ssap_server.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

#define SLE_RCU_SERVER_LOG     "[sle rcu server]"

typedef struct {
    uint16_t handle_in;
    uint16_t handle_out;
} sle_item_handle_t;

errcode_t sle_set_uuid(uint8_t *uuid, sle_uuid_t *service_uuid);
errcode_t sle_add_property(uint8_t server_id, uint32_t properties, uint8_t *uuid,
    uint16_t len, uint8_t *data, sle_item_handle_t* service_hdl);
errcode_t sle_service_add(uint8_t server_id, uint8_t* device_uuid, sle_item_handle_t* service_hdl,
    uint8_t sle_index_start, uint8_t sle_index_end);

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif