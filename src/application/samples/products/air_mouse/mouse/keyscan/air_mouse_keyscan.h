/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2023-2024. All rights reserved.
 *
 * Description: Air Mouse RCU keyscan Header. \n
 *
 * History: \n
 * 2024-01-23, Create file. \n
 */

#ifndef AIR_MOUSE_KEYSCAN_H
#define AIR_MOUSE_KEYSCAN_H

#include <stdint.h>
#include "../../air_mouse_common.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

#define KEY_MAX_NUM 2  // 处理的最大组合键数量

typedef enum {
    COMBINE_KEY_PAIR = 0,
    COMBINE_KEY_UNPAIR,
    COMBINE_KEY_NUM,
} combine_key_e;  // 组合键类型

typedef struct {
    uint8_t num;
    uint8_t array[KEY_MAX_NUM];
} key_t;

void air_mouse_keyscan_init(void);
const key_config_t *get_key_value(rcu_key_index_e key);

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif
