/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * Description: Air Mouse Msg Queue Source File. \n
 *
 * History: \n
 * 2024-09-27, Create file. \n
 */
#include "air_mouse_queue.h"
#include "osal_debug.h"
#include "osal_msgqueue.h"
#include "soc_osal.h"

#define MAX_QUEUE_LEN 5
#define MSG_WAIT_FOREVER 0xFFFFFFFF

static unsigned long g_msg_queue_id;

// 创建消息队列
void msg_queue_create(void)
{
    osal_printk("msg_queue_create: %u, %u\r\n", MAX_QUEUE_LEN, sizeof(msg_data_t));
    int32_t ret = osal_msg_queue_create("AIR_MOUSE_RCU_MSG", MAX_QUEUE_LEN, &g_msg_queue_id, 0, sizeof(msg_data_t));
    if (ret != OSAL_SUCCESS) {
        osal_printk("queue create fail, ret:0x%08X", ret);
        return;
    }
}

// 写入消息队列
void msg_queue_write(msg_data_t *msg)
{
    int32_t ret = osal_msg_queue_write_copy(g_msg_queue_id, msg, sizeof(msg_data_t), 0);
    if (ret != OSAL_SUCCESS) {
        osal_printk("message write fail, ret:0x%08X\r\n", ret);
        return;
    }
}

// 接收消息
int32_t msg_queue_receive(uint8_t buf[], uint32_t *len)
{
    if (buf == NULL) {
        osal_printk("message receive fail!\r\n");
        return -1;
    }
    int32_t ret = osal_msg_queue_read_copy(g_msg_queue_id, (void *)buf, len, MSG_WAIT_FOREVER);
    if (ret != 0) {
        osal_printk("osal_msg_queue_read_copy failed ret = 0x%08X!\r\n", ret);
    }
    return ret;
}
