/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2024. All rights reserved. \n
 *
 * Description: Air Mouse RCU Key Event Prcess Header File. \n
 *
 * History: \n
 * 2024-09-27, Create file. \n
 */
#ifndef PROC_KEY_EVENT_H
#define PROC_KEY_EVENT_H

#include <stdint.h>
#include "../common/air_mouse_queue.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

void key_event_process(msg_data_t *msg);
void init_key_press_flag(void);

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif
