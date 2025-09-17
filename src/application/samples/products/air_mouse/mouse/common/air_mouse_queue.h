/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * Description: Air Mouse Msg Queue Header File. \n
 *
 * History: \n
 * 2024-09-27, Create file. \n
 */
#ifndef AIR_MOUSE_QUEUE_H
#define AIR_MOUSE_QUEUE_H

#include <stdint.h>
#include "securec.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

#define MSG_BUFFER_LEN 5

typedef enum {
    MSG_TYPE_KEY_EVENT = 0,        // keyscan event
    MSG_TYPE_KEY_HOLD_LONG_EVENT,  // combine key event
    MSG_TYPE_CMD_NUM,
} msg_data_type_e;

typedef struct {
    uint8_t type;  // msg_data_type_e
    uint8_t buffer[MSG_BUFFER_LEN];
} msg_data_t;

void msg_queue_create(void);
void msg_queue_write(msg_data_t *msg);
int32_t msg_queue_receive(uint8_t *buf, uint32_t *len);

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif
