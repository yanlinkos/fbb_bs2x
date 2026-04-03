/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: Air Mouse RCU AT Command Source\n
 *
 * History: \n
 * 2025-12-20, Create file. \n
 */
#include "air_mouse_rcu_at.h"
#include "sle_device_discovery.h"
#include "at.h"
#include "../sle_air_mouse_server/sle_air_mouse_server.h"

#define SERVER_AT_MAX_NUM    10

/* --------------------------------------- slp_rcu_sleep_req （遥控器整机睡眠）--------------------------------------- */
static at_ret_t slp_at_rcu_sleep_req(void)
{
    ErrcodeSlpClient ret = ERRCODE_SLPC_SUCCESS;
    set_rcu_sleep_flag(true);
    ret = SlpSleepCommand();
    if (ret != ERRCODE_SLPC_SUCCESS) {
        osal_printk("[SLP][AT] slp send sleep req cmd fail, ret: 0x%X\r\n", ret);
        return AT_RET_SYNTAX_ERROR;
    }

    return AT_RET_OK;
}

// 断链且不清除配对记录
static at_ret_t slp_at_rcu_disconnect_req(void)
{
    set_announce_after_disc_flag(false);
    errcode_t ret = sle_disconnect_all_remote_device();
    osal_printk("[AM][AT] dis conn ret:0x%x\r\n", ret);
    if (ret != ERRCODE_SUCC) {
        return AT_RET_SYNTAX_ERROR;
    }

    return AT_RET_OK;
}

static at_ret_t slp_at_rcu_start_announce_req(void)
{
    errcode_t ret = sle_start_announce(SLE_ADV_HANDLE_DEFAULT);
    osal_printk("[AM][AT] start announce, ret:0x%X\r\n", ret);
    if (ret != ERRCODE_SUCC) {
        return AT_RET_SYNTAX_ERROR;
    }

    return AT_RET_OK;
}

static at_cmd_entry_t g_slp_server_at_table[] = {
    {
        "SLPRCUSLEEP",
        1, // ID
        0, // Attribute
        NULL,
        slp_at_rcu_sleep_req,
        NULL,
        NULL,
        NULL,
    },
    {
        "SLPAMDISCONNECT",
        1, // ID
        0, // Attribute
        NULL,
        slp_at_rcu_disconnect_req,
        NULL,
        NULL,
        NULL,
    },
    {
        "SLPAMSTARTANNOUNCE",
        1, // ID
        0, // Attribute
        NULL,
        slp_at_rcu_start_announce_req,
        NULL,
        NULL,
        NULL,
    },
};

errcode_t air_mouse_rcu_at_register(void)
{
    return uapi_at_cmd_table_register(
        g_slp_server_at_table, (sizeof(g_slp_server_at_table) / sizeof(g_slp_server_at_table[0])), SERVER_AT_MAX_NUM);
}
