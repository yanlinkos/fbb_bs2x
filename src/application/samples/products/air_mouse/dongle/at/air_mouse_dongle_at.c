/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: Air Mouse RCU AT Command Source\n
 *
 * History: \n
 * 2025-12-20, Create file. \n
 */
#include "air_mouse_dongle_at.h"
#include "at.h"
#include "slp.h"
#include "../../timer/am_common_timer.h"
#include "../radar/air_mouse_radar.h"
#include "../sle_air_mouse_client/sle_air_mouse_client.h"

#define SERVER_AT_MAX_NUM    10

typedef struct {
    uint32_t paraMap;
    SlpCursorSpeed mode;
} SlpAtCursorSpeedPara;

typedef struct {
    uint32_t paraMap;
    screen_size_e mode;
} SlpAtScreenSize;

typedef struct {
    uint32_t paraMap;
    screen_size_t screen_size;
} SlpAtCustomScreenSize;

typedef struct {
    uint32_t paraMap;
    uint32_t mode; // SlpCursorRptRate
} SlpAtCursorRptRate;

/* ------------------------------------ air_mouse_set_cursor_speed_cmd ------------------------------------------- */
const at_para_parse_syntax_t g_amAtSetCursorSpeedCommandSyntax[] = {
    {
        .type = AT_SYNTAX_TYPE_INT,
        .last = true,
        .attribute = AT_SYNTAX_ATTR_AT_MIN_VALUE | AT_SYNTAX_ATTR_AT_MAX_VALUE,
        .entry.int_range.min_val = INT32_MIN,
        .entry.int_range.max_val = INT32_MAX,
        .offset = offsetof(SlpAtCursorSpeedPara, mode),
    },
};

static at_ret_t air_mosue_at_set_cursor_speed_req(SlpAtCursorSpeedPara *args)
{
    ErrcodeSlpClient ret = ERRCODE_SLPC_SUCCESS;
    ret = SlpSetCursorSpeedCommand(args->mode);
    if (ret != ERRCODE_SLPC_SUCCESS) {
        osal_printk("[AM][AT] slp cursor speed fail, mode:%u, ret:0x%X\r\n", args->mode, ret);
        return AT_RET_SYNTAX_ERROR;
    }
    osal_printk("[AM][AT] cursor speed:%u\r\n", args->mode);
    update_am_print_info_cursor_speed(args->mode);

    return AT_RET_OK;
}

/* ----------------------------------------- air_mouse_radar_off_cmd ----------------------------------------------- */
static at_ret_t air_mosue_at_radar_off_req(void)
{
    set_radar_is_running_flag(false);
    air_mouse_radar_stop();
    return AT_RET_OK;
}

/* ----------------------------------------- air_mouse_radar_on_cmd ------------------------------------------------ */
static at_ret_t air_mosue_at_radar_on_req(void)
{
    set_radar_is_running_flag(true);
    air_mouse_radar_start();
    return AT_RET_OK;
}

/* ------------------------------------ air_mosue_at_read_screen_size_req ------------------------------------------ */
static at_ret_t air_mosue_at_read_screen_size_req(void)
{
    screen_size_t *screen_size = get_screen_size();
    osal_printk("[AM][AT] screen size:%ux%u\r\n", screen_size->x, screen_size->y);
    return AT_RET_OK;
}

/* ------------------------------------- air_mosue_set_screen_size_req --------------------------------------------- */
const at_para_parse_syntax_t g_amAtSetScreenSizeCommandSyntax[] = {
    {
        .type = AT_SYNTAX_TYPE_INT,
        .last = true,
        .attribute = AT_SYNTAX_ATTR_AT_MIN_VALUE | AT_SYNTAX_ATTR_AT_MAX_VALUE,
        .entry.int_range.min_val = 0,
        .entry.int_range.max_val = INT32_MAX,
        .offset = offsetof(SlpAtScreenSize, mode),
    },
};

static at_ret_t air_mosue_at_set_screen_size_req(SlpAtScreenSize *args)
{
    if (args->mode >= SCREEN_SIZE_ARR_NUM) {
        osal_printk("[AM][AT] screen size fail, mode:%u\r\n", args->mode);
        return AT_RET_PARSE_PARA_ERROR;
    }
    set_screen_size(args->mode);
#if CONFIG_SLP_USAGE_AIR_MOUSE // tv场景在rcu侧调用
    sle_air_mouse_client_send_cmd(AM_CMD_DONGLE_SCRREN_SIZE, (uint8_t *)&args->mode, sizeof(screen_size_e));
#elif CONFIG_SLP_USAGE_AIR_MOUSE_CAR // car场景在dongle侧调用
    set_slp_local_att();
#endif
    sle_air_mouse_client_send_cmd(AM_CMD_RANGING_RESTART, NULL, 0); // 设置完成后重启测距
    return AT_RET_OK;
}

/* ---------------------------------- air_mosue_set_custom_screen_size_req ----------------------------------------- */
const at_para_parse_syntax_t g_amAtSetCustomScreenSizeCommandSyntax[] = {
    {
        .type = AT_SYNTAX_TYPE_INT,
        .attribute = AT_SYNTAX_ATTR_AT_MIN_VALUE | AT_SYNTAX_ATTR_AT_MAX_VALUE,
        .entry.int_range.min_val = 0,
        .entry.int_range.max_val = UINT16_MAX,
        .offset = offsetof(SlpAtCustomScreenSize, screen_size.x),
    },
    {
        .type = AT_SYNTAX_TYPE_INT,
        .last = true,
        .attribute = AT_SYNTAX_ATTR_AT_MIN_VALUE | AT_SYNTAX_ATTR_AT_MAX_VALUE,
        .entry.int_range.min_val = 0,
        .entry.int_range.max_val = UINT16_MAX,
        .offset = offsetof(SlpAtCustomScreenSize, screen_size.y),
    },
};

static at_ret_t air_mosue_at_set_custom_screen_size_req(SlpAtCustomScreenSize *args)
{
    set_custom_screen_size(&args->screen_size);
    set_screen_size(SCREEN_SIZE_CUSTOM);
#if CONFIG_SLP_USAGE_AIR_MOUSE // tv场景在rcu侧调用
    uint8_t data[sizeof(uint8_t) + sizeof(screen_size_t)] = {SCREEN_SIZE_CUSTOM};
    *(screen_size_t *)(&data[1]) = args->screen_size;
    sle_air_mouse_client_send_cmd(AM_CMD_DONGLE_SCRREN_SIZE, (uint8_t *)data, sizeof(data));
#elif CONFIG_SLP_USAGE_AIR_MOUSE_CAR // car场景在dongle侧调用
    set_slp_local_att();
#endif
    sle_air_mouse_client_send_cmd(AM_CMD_RANGING_RESTART, NULL, 0); // 设置完成后重启测距
    return AT_RET_OK;
}

/* ----------------------------------- air_mosue_at_cursor_rpt_rate_req -------------------------------------------- */
static at_ret_t air_mosue_at_read_cursor_rpt_rate_req(void)
{
    osal_printk("[AM][AT] cursor rpt rate:%u\r\n", 0);
    return AT_RET_OK;
}

/* ---------------------------------- air_mouse_set_cursor_rpt_speed_req ------------------------------------------- */
const at_para_parse_syntax_t g_amAtSetCursorRptRateCommandSyntax[] = {
    {
        .type = AT_SYNTAX_TYPE_INT,
        .last = true,
        .attribute = AT_SYNTAX_ATTR_AT_MIN_VALUE | AT_SYNTAX_ATTR_AT_MAX_VALUE,
        .entry.int_range.min_val = 0,
        .entry.int_range.max_val = INT32_MAX,
        .offset = offsetof(SlpAtCursorRptRate, mode),
    },
};

static at_ret_t air_mosue_at_set_cursor_rpt_rate_req(SlpAtCursorRptRate *args)
{
    osal_printk("AT set_cursor_rpt_rate:%u\r\n", args->mode);
#if CONFIG_SLP_USAGE_AIR_MOUSE // tv场景在rcu侧调用
    sle_air_mouse_client_send_cmd(AM_CMD_DONGLE_RPT_RATE, (uint8_t *)&args->mode, sizeof(uint32_t));
#elif CONFIG_SLP_USAGE_AIR_MOUSE_CAR // car场景在dongle侧调用
#endif
    sle_air_mouse_client_send_cmd(AM_CMD_RANGING_RESTART, NULL, 0); // 设置完成后重启测距
    return AT_RET_OK;
}

static at_cmd_entry_t g_slp_client_at_table[] = {
    {
        "AMSETCURSORSPEED",
        1, // ID
        0, // Attribute
        g_amAtSetCursorSpeedCommandSyntax,
        NULL,
        (at_set_func_t)air_mosue_at_set_cursor_speed_req,
        NULL,
        NULL,
    },
    {
        "AMRADAROFF",
        2,  // ID
        0,  // Attribute
        NULL,
        (at_read_func_t)air_mosue_at_radar_off_req,
        NULL,
        NULL,
        NULL,
    },
    {
        "AMRADARON",
        3,  // ID
        0,  // Attribute
        NULL,
        (at_read_func_t)air_mosue_at_radar_on_req,
        NULL,
        NULL,
        NULL,
    },
    {
        "AMREADSCREENSIZE", // 读取屏幕尺寸
        4,  // ID
        0,  // Attribute
        NULL,
        (at_read_func_t)air_mosue_at_read_screen_size_req,
        NULL,
        NULL,
        NULL,
    },
    {
        "AMSETSCREENSIZE", // 设置预设屏幕尺寸
        5,  // ID
        0,  // Attribute
        g_amAtSetScreenSizeCommandSyntax,
        NULL,
        (at_set_func_t)air_mosue_at_set_screen_size_req,
        NULL,
        NULL,
    },
    {
        "AMSETCUSTOMSCREENSIZE", // 设置自定义屏幕尺寸
        6,  // ID
        0,  // Attribute
        g_amAtSetCustomScreenSizeCommandSyntax,
        NULL,
        (at_set_func_t)air_mosue_at_set_custom_screen_size_req,
        NULL,
        NULL,
    },
    {
        "AMREADCURSORRPTRATE", // 读取光标上报频率
        7,  // ID
        0,  // Attribute
        NULL,
        (at_read_func_t)air_mosue_at_read_cursor_rpt_rate_req,
        NULL,
        NULL,
        NULL,
    },
    {
        "AMSETCURSORRPTRATE", // 设置光标上报频率切换
        8,  // ID
        0,  // Attribute
        g_amAtSetCursorRptRateCommandSyntax,
        NULL,
        (at_set_func_t)air_mosue_at_set_cursor_rpt_rate_req,
        NULL,
        NULL,
    },
};

errcode_t air_mouse_dongle_at_register(void)
{
    return uapi_at_cmd_table_register(
        g_slp_client_at_table, (sizeof(g_slp_client_at_table) / sizeof(g_slp_client_at_table[0])), SERVER_AT_MAX_NUM);
}
