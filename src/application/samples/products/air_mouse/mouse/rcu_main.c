/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2024. All rights reserved. \n
 *
 * Description: Air mouse RCU Main Task Source File. \n
 *
 * History: \n
 * 2024-10-14, Create file. \n
 */
#include "rcu_main.h"
#include "common_def.h"
#include "osal_debug.h"
#include "soc_osal.h"
#include "mouse/common/air_mouse_queue.h"
#include "mouse/common/air_mouse_timer.h"
#include "mouse/keyscan/proc_key_event.h"
#include "mouse/keyscan/proc_key_hold.h"

typedef void (*msg_func)(msg_data_t *msg);

static const msg_func g_rcu_msg_func_map[MSG_TYPE_CMD_NUM] = {
    key_event_process,  //  MSG_TYPE_KEY_EVENT
    key_hold_process,   //  MSG_TYPE_KEY_HOLD_LONG_EVENT
};

static void rcu_msg_proc(msg_data_t *msg)
{
    if (msg->type < MSG_TYPE_CMD_NUM && g_rcu_msg_func_map[msg->type] != NULL) {
        g_rcu_msg_func_map[msg->type](msg);
    } else {
        osal_printk("[ERR] wrong msg type: %u\r\n", msg->type);
    }
}

// RCU消息队列
void *rcu_task(const char *arg)
{
    unused(arg);
    app_timer_init();
    init_key_press_flag();
    osal_printk("enter air mouse rcu task!\r\n");
    msg_queue_create();  // 创建消息队列
    msg_data_t msg = {0};
    uint32_t msg_size = (uint32_t)sizeof(msg_data_t);

    while (1) {
        int32_t ret = msg_queue_receive((uint8_t *)&msg, &msg_size);
        if (ret != OSAL_SUCCESS) {
            osal_printk("queue receive err:%d\r\n", ret);
            continue;
        }
        rcu_msg_proc(&msg);
    }

    return NULL;
}
