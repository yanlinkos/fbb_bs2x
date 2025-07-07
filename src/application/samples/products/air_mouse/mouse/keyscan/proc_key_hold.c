
/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * Description: Air Mouse RCU Keyscan Hold Process Source File. \n
 *
 * History: \n
 * 2024-09-27, Create file. \n
 */
#include "proc_key_hold.h"
#include "osal_debug.h"
#include "../keyscan/air_mouse_keyscan.h"
#include "../common/air_mouse_timer.h"

// 配对
static void key_handle_process_repairing_event(void)
{
    app_timer_process_start(TIME_CMD_PAIR, 0);  // 广播等待配对，超时则关闭
}

// 解配
static void key_handle_process_unpairing_event(void)
{
    app_timer_process_start(TIME_CMD_UNPAIR, 0);
}

// 组合键长按处理
void key_hold_process(msg_data_t *msg)
{
    combine_key_e combine_key = *(combine_key_e *)msg->buffer;
    osal_printk("[proc] key hold, combine_key:%u\r\n", combine_key);

    switch (combine_key) {
        case COMBINE_KEY_PAIR:  // 配对
            key_handle_process_repairing_event();
            break;
        case COMBINE_KEY_UNPAIR:  // 解配
            key_handle_process_unpairing_event();
            break;
        default:
            osal_printk("[proc] key hold, combine_key is not support:%u\r\n", combine_key);
            break;
    }
}
