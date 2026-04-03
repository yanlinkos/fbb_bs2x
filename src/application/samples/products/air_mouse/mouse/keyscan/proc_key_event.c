/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2024. All rights reserved. \n
 *
 * Description: Air Mouse RCU Key Event Prcess Source File. \n
 *
 * History: \n
 * 2024-09-27, Create file. \n
 */
#include "proc_key_event.h"
#include "osal_debug.h"
#include "soc_osal.h"
#include "tcxo.h"
#include "sle_connection_manager.h"
#include "slp.h"
#include "slp_errcode.h"
#include "air_mouse_keyscan.h"
#include "../common/air_mouse_timer.h"
#include "../led/air_mouse_led.h"
#include "../sle_air_mouse_server/sle_air_mouse_server.h"
#include "../../air_mouse_common.h"
#include "amic_voice.h"

typedef struct {
    uint8_t one_key;
    uint8_t two_key;
    combine_key_e type;
} combine_key_t;

#if CONFIG_AIR_MOUSE_HR_BOARD /* 组合键 */
static const combine_key_t g_combine_key[COMBINE_KEY_NUM] = {
    {RCU_KEY_S10, RCU_KEY_S9, COMBINE_KEY_PAIR  },
    {RCU_KEY_S10, RCU_KEY_S3, COMBINE_KEY_UNPAIR},
};
#elif CONFIG_AIR_MOUSE_HX_BOARD
static const combine_key_t g_combine_key[COMBINE_KEY_NUM] = {
    {RCU_KEY_S5, RCU_KEY_S15, COMBINE_KEY_PAIR  },
    {RCU_KEY_S5, RCU_KEY_S1,  COMBINE_KEY_UNPAIR},
};
#endif /* 组合键 */

typedef struct {
    uint8_t slp_pause : 1;
    uint8_t left_key : 1;
    uint8_t keyboard : 1;
    uint8_t combine_key_first : 1; // 组合键第一个按键
    uint8_t reserved : 4;
} key_press_flag_t;  // 按键是否已经按下

key_press_flag_t g_key_press_flag = {0};

static screen_size_e g_screen_size_idx = SCREEN_SIZE_16X9_85_INCH;

void init_key_press_flag(void)
{
    (void)memset_s(&g_key_press_flag, sizeof(g_key_press_flag), 0, sizeof(g_key_press_flag));
}

#if CONFIG_AIR_MOUSE_UAC
void rcu_amic_init(void)
{
    sle_set_em_data(1);
    amic_init();
}

void rcu_amic_deinit(void)
{
    sle_set_em_data(0);
    amic_deinit();
}
#endif

// 指向功能开/关处理
static void slp_key_proc(void)
{
    uint16_t number;
    sle_get_paired_devices_num(&number);
    if (number == 0) {  // 未配对到对端设备
        osal_printk("paired devices num:0\r\n");
        return;
    }
    if (SlpPowerOffCommand() == ERRCODE_SLPC_POWERD_OFF) {  // 上下电状态切换
        init_power_on_start_time_server();
        SlpPowerOnCommand();
    } else {
        sle_air_mouse_server_send_cmd(AM_CMD_RANGING_STOP, NULL, 0);
    }
}

// 切换slp本端和对端屏幕尺寸配置，重启指向业务后生效
void switch_to_next_screen_size(void)
{
    g_screen_size_idx = (g_screen_size_idx + 1) % (SCREEN_SIZE_ARR_NUM);
    ErrcodeSlpClient ret = SlpStopRangingCommand();
    if (ret != ERRCODE_SLPC_SUCCESS) {
        osal_printk("stop ranging fail, 0x%x\r\n", ret);
    }
    set_screen_size(g_screen_size_idx);
    set_slp_local_att();
    sle_air_mouse_server_send_cmd(AM_CMD_SCRREN_SIZE, (uint8_t *)&g_screen_size_idx, sizeof(screen_size_e));

    set_led_status(g_screen_size_idx + LED_STATUS_SPEED_MODE_LOW);
}

void switch_to_next_cursor_speed(void)  // 切换至下一个光标速度模式
{
    SlpCursorSpeed next_mode = (get_slp_cursor_speed() + 1) % (SLP_CURSOR_SPEED_MEDIUM_HIGH  + 1);
    set_slp_cursor_speed(next_mode);
#if CONFIG_SLP_USAGE_AIR_MOUSE
    ErrcodeSlpClient ret = SlpSetCursorSpeedCommand(next_mode); // tv场景在rcu侧调用
    if (ret != ERRCODE_SLPC_SUCCESS) {
        osal_printk("set cursor speed error:0x%08X\r\n", ret);
        return;
    }
#elif CONFIG_SLP_USAGE_AIR_MOUSE_CAR
    sle_air_mouse_server_send_cmd(AM_CMD_CURSOR_SPEED, &next_mode, sizeof(next_mode)); // car场景在dongle侧调用
#else
#endif
    osal_printk("cursor speed swtich to:%u\r\n", next_mode);

    switch (next_mode) {  // 切换LED状态
        case SLP_CURSOR_SPEED_LOW:
            set_led_status(LED_STATUS_SPEED_MODE_LOW);
            break;
        case SLP_CURSOR_SPEED_MEDIUM:
            set_led_status(LED_STATUS_SPEED_MODE_MEDIUM);
            break;
        case SLP_CURSOR_SPEED_HIGH:
            set_led_status(LED_STATUS_SPEED_MODE_HIGH);
            break;
        case SLP_CURSOR_SPEED_MEDIUM_LOW:
            set_led_status(LED_STATUS_SPEED_MODE_MEDIUM_LOW);
            break;
        case SLP_CURSOR_SPEED_MEDIUM_HIGH:
            set_led_status(LED_STATUS_SPEED_MODE_MEDIUM_HIGH);
            break;
        default:
            osal_printk("[ERR] other cursor speed:%u", next_mode);
            break;
    }
}

// 确认键按下处理, 指向关闭时发送键值, 指向启动时发送控制命令调用防抖接口
static void confirm_key_press(uint8_t key)
{
    if (get_slp_ranging_start_flag()) {
#if CONFIG_SLP_USAGE_AIR_MOUSE
        SlpClickDebounceCommand(1); // tv场景在rcu侧调用
#elif CONFIG_SLP_USAGE_AIR_MOUSE_CAR
        sle_air_mouse_server_send_cmd(AM_CMD_LEFT_KEY_DOWN, NULL, 0); // car场景在dongle侧调用
#endif
    } else {
        sle_hid_mouse_server_send_keyboard_report(get_key_value(key));
    }
}

// 确认键抬起处理, 指向关闭时发送键值, 指向启动时发送控制命令调用防抖接口
static void confirm_key_release(void)
{
    if (get_slp_ranging_start_flag()) {
#if CONFIG_SLP_USAGE_AIR_MOUSE
        SlpClickDebounceCommand(0); // tv场景在rcu侧调用
#elif CONFIG_SLP_USAGE_AIR_MOUSE_CAR
        sle_air_mouse_server_send_cmd(AM_CMD_LEFT_KEY_UP, NULL, 0); // car场景在dongle侧调用
#endif
    } else {
        sle_air_mouse_server_send_cmd(AM_CMD_KEYBOARD_UP, NULL, 0);
    }
}

#if CONFIG_AIR_MOUSE_HR_BOARD /* 单键操作 */
/* 单键操作 */
static void one_key_process(uint8_t key)
{
    // 配对、解配对过程中按其他按键仍保持闪烁
    if (get_led_status() != LED_STATUS_PAIRING && get_led_status() != LED_STATUS_UNPAIRING) {
        set_led_status(LED_STATUS_ONE_KEY_DOWN);
    }
    ErrcodeSlpClient ret;
    switch (key) {
        case RCU_KEY_S10:  // 组合键/Home键
            g_key_press_flag.combine_key_first = 1;
            break;
        case RCU_KEY_S14:  // 模拟语音，按下暂停测距交互, 抬起继续测距交互
            g_key_press_flag.slp_pause = 1;
            ret = SlpPauseRangingCommand();
            osal_printk("S14 pause ranging, 0x%08X\r\n", ret);
#if CONFIG_AIR_MOUSE_UAC
            rcu_amic_init();
#endif
            break;
        case RCU_KEY_S12:  // 鼠标左键
            g_key_press_flag.left_key = 1;
            confirm_key_press(key);
            break;
        case RCU_KEY_S16:  // slp开关
            sle_air_mouse_server_send_cmd(AM_CMD_SET_FACTORY_TEST_NONE, NULL, 0); // 设置为指向业务
            slp_key_proc();
            break;
        default:
            g_key_press_flag.keyboard = 1;
            sle_hid_mouse_server_send_keyboard_report(get_key_value(key));
            break;
    }
}
#elif CONFIG_AIR_MOUSE_HX_BOARD
static void one_key_process(uint8_t key)
{
    // 配对、解配对过程中按其他按键仍保持闪烁
    if (get_led_status() != LED_STATUS_PAIRING && get_led_status() != LED_STATUS_UNPAIRING) {
        set_led_status(LED_STATUS_ONE_KEY_DOWN);
    }
    ErrcodeSlpClient ret;
    switch (key) {
        case RCU_KEY_S19:  // 模拟语音，按下暂停测距交互, 抬起继续测距交互
            g_key_press_flag.slp_pause = 1;
            ret = SlpPauseRangingCommand();
            osal_printk("pause ranging, 0x%X\r\n", ret);
#if CONFIG_AIR_MOUSE_UAC
            rcu_amic_init();
#endif
            break;
        case RCU_KEY_S9:  // 鼠标左键
            g_key_press_flag.left_key = 1;
            confirm_key_press(key);
            break;
        case RCU_KEY_S11:  // slp开关
            sle_air_mouse_server_send_cmd(AM_CMD_SET_FACTORY_TEST_NONE, NULL, 0); // 设置为指向业务
            slp_key_proc();
            break;
        default: // 键盘
            g_key_press_flag.keyboard = 1;
            sle_hid_mouse_server_send_keyboard_report(get_key_value(key));
            break;
    }
}
#endif /* 单键操作 */

// 判断键值是否在组合键中
static bool is_key_match(uint8_t template_key, uint8_t key_array[], uint8_t key_num)
{
    for (int i = 0; i < key_num; i++) {
        if (template_key == key_array[i]) {
            return true;
        }
    }
    return false;
}

/* 组合键判断 */
static void combine_key_process(key_t *key)
{
    for (int i = 0; i < COMBINE_KEY_NUM; i++) {
        bool tag_one = is_key_match(g_combine_key[i].one_key, key->array, key->num);
        bool tag_two = is_key_match(g_combine_key[i].two_key, key->array, key->num);
        if (tag_one && tag_two) {
            app_timer_process_start(TIME_CMD_KEY_HOLD_LONG, i);
            osal_printk("[proc] combine_key: %d\r\n", g_combine_key[i].type);
            return;
        }
    }
    osal_printk("[proc] combine_key unsupport! %u,%u\r\n", key->array[0], key->array[1]);
}

// 按键释放处理
static void key_up_process(void)
{
    osal_printk("[proc] key up, pause:%u, left_key:%u, keyboard:%u, key_first:%u\r\n", g_key_press_flag.slp_pause,
        g_key_press_flag.left_key, g_key_press_flag.keyboard, g_key_press_flag.combine_key_first);
    if (get_led_status() != LED_STATUS_PAIRING && get_led_status() != LED_STATUS_UNPAIRING) {
        set_led_status(LED_STATUS_IDLE);
    }
    if (g_key_press_flag.keyboard == 1) {
        g_key_press_flag.keyboard = 0;
        sle_air_mouse_server_send_cmd(AM_CMD_KEYBOARD_UP, NULL, 0);
    }
    if (g_key_press_flag.combine_key_first == 1) {
        g_key_press_flag.combine_key_first = 0;
#if CONFIG_AIR_MOUSE_HR_BOARD
        sle_hid_mouse_server_send_keyboard_report(get_key_value(RCU_KEY_S10));
        sle_air_mouse_server_send_cmd(AM_CMD_KEYBOARD_UP, NULL, 0);
#elif CONFIG_AIR_MOUSE_HX_BOARD
        switch_to_next_cursor_speed();
#endif
    }
    if (g_key_press_flag.left_key == 1) {
        g_key_press_flag.left_key = 0;
        confirm_key_release();
    }
    if (g_key_press_flag.slp_pause == 1) { // 抬起按键后继续测距
        g_key_press_flag.slp_pause = 0;
#if CONFIG_AIR_MOUSE_UAC
        rcu_amic_deinit();
#endif
        ErrcodeSlpClient ret = SlpContinueRangingCommand();
        osal_printk("ranging continue, 0x%08x\r\n", ret);
    }
    init_key_press_flag();
}

void key_event_process(msg_data_t *msg)
{
    key_t *key = (key_t *)msg->buffer;

    switch (key->num) {
        case 0:
            key_up_process();
            break;
        case 1:
            one_key_process(key->array[0]);
            break;
        case 2:  // 2：组合键数量
            combine_key_process(key);
            break;
        default:
            osal_printk("[ERR] other key num:%u", key->num);
            break;
    }
}
