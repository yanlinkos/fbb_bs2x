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
    uint8_t reserved : 5;
} key_press_flag_t;  // 按键是否已经按下

key_press_flag_t g_key_press_flag = {0};

void init_key_press_flag(void)
{
    (void)memset_s(&g_key_press_flag, sizeof(g_key_press_flag), 0, sizeof(g_key_press_flag));
}

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

// 指向功能开/关处理
static void slp_key_proc(void)
{
    uint16_t number;
    sle_get_paired_devices_num(&number);
    if (number == 0) {  // 未匹配到对端设备
        osal_printk("paired devices num:0\r\n");
        return;
    }
    if (SlpPowerOffCommand() == ERRCODE_SLPC_POWERD_OFF) {  // 上下电状态切换
        init_power_on_start_time();
        SlpPowerOnCommand();
    } else {
        sle_air_mouse_server_send_cmd(AM_CMD_RANGING_STOP, NULL, 0);
    }
}

static void switch_to_next_cursor_speed(void)  // 切换至下一个光标速度模式
{
    SlpCursorSpeed next_mode = (get_slp_cursor_speed() + 1) % (SLP_CURSOR_SPEED_HIGH + 1);
    set_slp_cursor_speed(next_mode);
#if CONFIG_SLP_USAGE_AIR_MOUSE
    ErrcodeSlpClient ret = SlpSetCursorSpeedCommand(next_mode); // tv场景在rcu侧调用
    if (ret != ERRCODE_SLPC_SUCCESS) {
        osal_printk("set cursor speed error:0x%08X\r\n", ret);
        return;
    }
#elif CONFIG_SLP_USAGE_AIR_MOUSE_CAR
    sle_air_mouse_server_send_cmd((air_mouse_cmd_e)next_mode, NULL, 0); // car场景在dongle侧调用
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
        default:
            osal_printk("[ERR] other cursor speed:%u", next_mode);
            break;
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
        case RCU_KEY_S9:  // 切换光标速度
            switch_to_next_cursor_speed();
            break;
        case RCU_KEY_S14:  // 模拟语音，按下暂停测距交互, 抬起继续测距交互
            g_key_press_flag.slp_pause = 1;
            ret = SlpPauseRangingCommand();
            osal_printk("S14 pause ranging, 0x%08X\r\n", ret);
            rcu_amic_init();
            break;
        case RCU_KEY_S12:  // 鼠标左键
            g_key_press_flag.left_key = 1;
#if CONFIG_SLP_USAGE_AIR_MOUSE
            SlpClickDebounceCommand(1); // tv场景在rcu侧调用
#elif CONFIG_SLP_USAGE_AIR_MOUSE_CAR
            ret = sle_air_mouse_server_send_cmd(AM_CMD_LEFT_KEY_DOWN, NULL, 0); // car场景在dongle侧调用
#endif
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
        case RCU_KEY_S5:  // 切换光标速度
            switch_to_next_cursor_speed();
            break;
        case RCU_KEY_S19:  // 模拟语音，按下暂停测距交互, 抬起继续测距交互
            g_key_press_flag.slp_pause = 1;
            ret = SlpPauseRangingCommand();
            osal_printk("pause ranging, 0x%X\r\n", ret);
            rcu_amic_init();
            break;
        case RCU_KEY_S9:  // 鼠标左键
            g_key_press_flag.left_key = 1;
#if CONFIG_SLP_USAGE_AIR_MOUSE
            SlpClickDebounceCommand(1); // tv场景在rcu侧调用
#elif CONFIG_SLP_USAGE_AIR_MOUSE_CAR
            ret = sle_air_mouse_server_send_cmd(AM_CMD_LEFT_KEY_DOWN, NULL, 0); // car场景在dongle侧调用
#endif
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
    osal_printk("[proc] key up, press_flag:0x%02x\r\n", g_key_press_flag);
    if (get_led_status() != LED_STATUS_PAIRING && get_led_status() != LED_STATUS_UNPAIRING) {
        set_led_status(LED_STATUS_IDLE);
    }
    if (g_key_press_flag.keyboard == 1) {
        g_key_press_flag.keyboard = 0;
        sle_air_mouse_server_send_cmd(AM_CMD_KEYBOARD_UP, NULL, 0);
    }
    if (g_key_press_flag.left_key == 1) {
        g_key_press_flag.left_key = 0;
#if CONFIG_SLP_USAGE_AIR_MOUSE
        SlpClickDebounceCommand(0); // tv场景在rcu侧调用
#elif CONFIG_SLP_USAGE_AIR_MOUSE_CAR
        sle_air_mouse_server_send_cmd(AM_CMD_LEFT_KEY_UP, NULL, 0); // car场景在dongle侧调用
#else
#endif
    }
    if (g_key_press_flag.slp_pause == 1) { // 抬起按键后继续测距
        g_key_press_flag.slp_pause = 0;
        rcu_amic_deinit();
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
            key_up_process();
            combine_key_process(key);
            break;
        default:
            osal_printk("[ERR] other key num:%u", key->num);
            break;
    }
}
