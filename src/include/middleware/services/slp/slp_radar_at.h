/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 * Description: slp radar at api
 * ROM      : NO
 * STRATEGY : NO
 */

/**
 * @defgroup middleware_service_slp_api SLP RADAR AT
 * @ingroup  middleware_service_slp
 * @{
 */
#ifndef SLP_RADAR_AT_H
#define SLP_RADAR_AT_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @if Eng
 * @brief  Register SLP RADAR AT command.
 * @par Description: Register SLP RADAR AT command.
 * @retval void.
 * @else
 * @brief  注册SLP RADAR AT指令。
 * @par Description: 注册SLP RADAR AT指令。
 * @retval 无。
 * @endif
 */
void SlpRadarAtRegister(void);

#ifdef __cplusplus
}
#endif
#endif