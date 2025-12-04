/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2023-2025. All rights reserved.
 * Description: slp at api
 * ROM      : NO
 * STRATEGY : NO
 */

/**
 * @defgroup middleware_service_slp_at_api SLP AT API
 * @ingroup  middleware_service_slp
 * @{
 */

#ifndef SLP_AT_H
#define SLP_AT_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @if Eng
 * @brief  Register SLP AT command.
 * @par Description: Register SLP AT command.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  注册SLP AT指令。
 * @par Description: 注册SLP AT指令。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref errcode_t
 * @endif
 */
uint32_t SlpAtRegister(void);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif
