/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2023-2024. All rights reserved. \n
 *
 * Description: Air Mouse RCU Keyscan Source File. \n
 *
 * History: \n
 * 2024-01-23, Create file. \n
 */
#include "air_mouse_keyscan.h"
#include "common_def.h"
#include "keyscan.h"
#include "keyscan_porting.h"
#include "osal_debug.h"
#include "securec.h"
#include "../common/air_mouse_timer.h"
#include "../common/air_mouse_queue.h"
#include "../../dongle/air_mouse_usb/usb_init_app.h"
#include "../../mouse/sle_air_mouse_server/sle_air_mouse_server.h"

// 鼠标按键
#define MOUSE_LEFT_CODE             1 // 鼠标左键

// HID键盘扫描码
#define KEYBOARD_HID_CODE_ESC       0X29  // ESC
#define KEYBOARD_HID_CODE_BACK      0X2A  // 回退
#define KEYBOARD_HID_CODE_ENTER     0X28  // 回车
#define KEYBOARD_HID_CODE_SPACE     0X2C  // 空格
#define KEYBOARD_HID_CODE_PRINTSCR  0X46  // 截屏
#define KEYBOARD_HID_CODE_HOME      0X4a  // 首页
#define KEYBOARD_HID_CODE_END       0X4d  // 结尾
#define KEYBOARD_HID_CODE_UP        0X52  // 上
#define KEYBOARD_HID_CODE_DOWN      0X51  // 下
#define KEYBOARD_HID_CODE_LEFT      0X50  // 左
#define KEYBOARD_HID_CODE_RIGHT     0X4F  // 右

#define PRESS_KEYSCAN               1 // 按键按下
#define RELEASE_KEYSCAN             0 // 按键释放

#define GPIO_MAP_NUM                8   // keyscan使用的gpio管脚数量
#define GPIO_COL_1                  16  // COL1 gpio管脚号
#define GPIO_COL_2                  21  // COL2 gpio管脚号
#define GPIO_COL_3                  6   // COL3 gpio管脚号
#define GPIO_COL_4                  5   // COL4 gpio管脚号
#define GPIO_ROW_1                  24  // ROW1 gpio管脚号
#define GPIO_ROW_2                  23  // ROW2 gpio管脚号
#define GPIO_ROW_3                  22  // ROW3 gpio管脚号
#define GPIO_ROW_4                  2   // ROW3 gpio管脚号

// Keyscan的gpio矩阵，ROW在前，COL在后
static const uint8_t user_gpio_map[GPIO_MAP_NUM] = {
    GPIO_ROW_1, GPIO_ROW_2, GPIO_ROW_3, GPIO_ROW_4,
    GPIO_COL_1, GPIO_COL_2, GPIO_COL_3, GPIO_COL_4
};

// Keyscan的键值矩阵
static const uint8_t g_key_map[CONFIG_KEYSCAN_ENABLE_ROW][CONFIG_KEYSCAN_ENABLE_COL] = {
    {RCU_KEY_S3, RCU_KEY_S4, RCU_KEY_S5, RCU_KEY_S6},
    {RCU_KEY_S7, RCU_KEY_S8, RCU_KEY_S9, RCU_KEY_S10},
    {RCU_KEY_S11, RCU_KEY_S12, RCU_KEY_S13, RCU_KEY_S14},
    {RCU_KEY_S15, RCU_KEY_S16},
};

// 按键序号对应的值
static uint8_t g_value_map[RCU_KEY_NUM] = {
    MOUSE_LEFT_CODE, MOUSE_LEFT_CODE, KEYBOARD_HID_CODE_LEFT, KEYBOARD_HID_CODE_ESC,
    MOUSE_LEFT_CODE, KEYBOARD_HID_CODE_DOWN, MOUSE_LEFT_CODE, KEYBOARD_HID_CODE_HOME,
    KEYBOARD_HID_CODE_UP, MOUSE_LEFT_CODE, MOUSE_LEFT_CODE, KEYBOARD_HID_CODE_HOME,
    KEYBOARD_HID_CODE_RIGHT, MOUSE_LEFT_CODE
};

uint8_t get_key_value(rcu_key_index_e key)
{
    return g_value_map[key - RCU_KEY_S3];
}

static void print_key(int key_num, uint8_t key_array[])
{
    osal_printk("[keyscan], num:%d, value:", key_num);
    for (int i = 0; i < key_num; i++) {
        osal_printk("%u|", key_array[i]);
    }
    osal_printk("\r\n");
}

static int keyscan_callback(int key_num, uint8_t key_array[])
{
    print_key(key_num, key_array);

    app_timer_process_stop(TIME_CMD_KEY_HOLD_LONG); // 关闭长按判断定时器
    if (key_num > KEY_MAX_NUM) {
        osal_printk("key num %u is not support\r\n", key_num);
        return 0;
    }

    key_t key = {key_num, {0}};
    if (memcpy_s(&key.array, KEY_MAX_NUM, key_array, key_num) != EOK) {
        osal_printk("send key msg failed\r\n");
        return 0;
    }
    msg_data_t msg = {MSG_TYPE_KEY_EVENT, {0}};
    if (memcpy_s(&msg.buffer, MSG_BUFFER_LEN, &key, sizeof(key)) != EOK) {
        osal_printk("send key msg failed\r\n");
        return 0;
    }
    msg_queue_write(&msg);

    return 1;
}

void air_mouse_keyscan_init(void)
{
    // 设置Keyscan的gpio矩阵
    keyscan_porting_set_gpio((uint8_t *)user_gpio_map);
    // 设置Keyscan的键值矩阵
    uapi_set_keyscan_value_map((uint8_t **)g_key_map, CONFIG_KEYSCAN_ENABLE_ROW, CONFIG_KEYSCAN_ENABLE_COL);
    // 扫描时长、扫描模式、中断类型
    uapi_keyscan_init(EVERY_ROW_PULSE_40_US, HAL_KEYSCAN_MODE_0, KEYSCAN_INT_VALUE_RDY);
    // 注册keyscan回调函数
    uapi_keyscan_register_callback(keyscan_callback);
    // 使能keyscan扫描
    uapi_keyscan_enable();
}
