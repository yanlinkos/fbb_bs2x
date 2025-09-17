/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * Description: SLE BAS SERVICE HEADER FILE \n
 *
 * History: \n
 * 2024-5-30, Create file. \n
 */
#ifndef SLE_SERVICE_BAS_H
#define SLE_SERVICE_BAS_H

#include <stdint.h>
#include "errcode.h"
#include "sle_ssap_server.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

void sle_set_battert(int32_t battert_value);
errcode_t sle_add_bas_service(uint8_t server_id);

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif