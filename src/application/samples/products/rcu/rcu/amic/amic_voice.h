/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * Description: APP Voice Header File. \n
 *
 * History: \n
 * 2024-05-28, Create file. \n
 */
#ifndef AMIC_VOICE_H
#define AMIC_VOICE_H

#include <stdbool.h>

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

#define LOW_LATENCY_DATA_MAX 136
#if defined (CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER) || defined (CONFIG_SAMPLE_SUPPORT_BLE_RCU_SERVER) || \
    defined (CONFIG_SAMPLE_SUPPORT_AIR_MOUSE)
void amic_init(void);
void amic_deinit(void);
void get_amic_encode_data(uint8_t *length, uint8_t *out_encode_data);
#else
bool recive_amic_encode_data(uint8_t *data, uint16_t data_len);
void get_amic_decode_data(uint8_t **out_data1, uint32_t *len1, uint8_t **out_data2, uint32_t *len2);
#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */
 
#endif