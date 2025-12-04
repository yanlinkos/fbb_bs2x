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
#include "../../mouse/sle_air_mouse_server/sle_air_mouse_server.h"

// 鼠标按键
#define KEYBOARD_NONE              0 // 未配置

// HID键盘扫描码
#define KEYBOARD_HID_CODE_BACK     0x29 // 返回
#define KEYBOARD_HID_CODE_ENTER    0x28 // 回车
#define KEYBOARD_HID_CODE_SPACE    0x2C // 空格
#define KEYBOARD_HID_CODE_PRINTSCR 0x46 // 截屏
#define KEYBOARD_HID_CODE_HOME     0x4A // 首页
#define KEYBOARD_HID_CODE_END      0x4D // 结尾
#define KEYBOARD_HID_CODE_MENU     0x65 // 菜单
#define KEYBOARD_HID_CODE_UP       0x52 // 上
#define KEYBOARD_HID_CODE_DOWN     0x51 // 下
#define KEYBOARD_HID_CODE_LEFT     0x50 // 左
#define KEYBOARD_HID_CODE_RIGHT    0x4F // 右
#define KEYBOARD_HID_CODE_SOURCE   0x57 // 信源
#define CONSUMER_HID_CODE_POWER    0x30 // 电源
#define CONSUMER_HID_VOLUME_UP     0xE9 // 音量+
#define CONSUMER_HID_VOLUME_DOWN   0xEA // 音量-

#if CONFIG_AIR_MOUSE_HR_BOARD
static const key_config_t g_menu_key_map[RCU_KEY_NUM] = {
    {RCU_KEY_S0,  0,                        0                },
    {RCU_KEY_S1,  0,                        0                },
    {RCU_KEY_S2,  0,                        0                },
    {RCU_KEY_S3,  CONSUMER_HID_CODE_POWER,  HID_CONSUMER_KIND},
    {RCU_KEY_S4,  CONSUMER_HID_VOLUME_UP,   HID_CONSUMER_KIND},
    {RCU_KEY_S5,  KEYBOARD_HID_CODE_LEFT,   HID_KEYBOARD_KIND},
    {RCU_KEY_S6,  KEYBOARD_HID_CODE_BACK,   HID_KEYBOARD_KIND},
    {RCU_KEY_S7,  KEYBOARD_HID_CODE_SOURCE, HID_KEYBOARD_KIND},
    {RCU_KEY_S8,  KEYBOARD_HID_CODE_DOWN,   HID_KEYBOARD_KIND},
    {RCU_KEY_S9,  KEYBOARD_HID_CODE_MENU,   HID_KEYBOARD_KIND},
    {RCU_KEY_S10, KEYBOARD_HID_CODE_HOME,   HID_KEYBOARD_KIND},
    {RCU_KEY_S11, KEYBOARD_HID_CODE_UP,     HID_KEYBOARD_KIND},
    {RCU_KEY_S12, 0,                        0                },
    {RCU_KEY_S13, CONSUMER_HID_VOLUME_DOWN, HID_CONSUMER_KIND},
    {RCU_KEY_S14, 0,                        0                },
    {RCU_KEY_S15, KEYBOARD_HID_CODE_RIGHT,  HID_KEYBOARD_KIND},
    {RCU_KEY_S16, 0,                        0                },
    {RCU_KEY_S17, 0,                        0                },
    {RCU_KEY_S18, 0,                        0                },
    {RCU_KEY_S19, 0,                        0                },
    {RCU_KEY_S20, 0,                        0                },
};
#elif CONFIG_AIR_MOUSE_HX_BOARD
static const key_config_t g_menu_key_map[RCU_KEY_NUM] = {
    {RCU_KEY_S0,  0,                        0                },
    {RCU_KEY_S1,  KEYBOARD_HID_CODE_SOURCE, HID_KEYBOARD_KIND},
    {RCU_KEY_S2,  0,                        0                },
    {RCU_KEY_S3,  KEYBOARD_HID_CODE_LEFT,   HID_KEYBOARD_KIND},
    {RCU_KEY_S4,  KEYBOARD_HID_CODE_BACK,   HID_KEYBOARD_KIND},
    {RCU_KEY_S5,  0,                        0                },
    {RCU_KEY_S6,  CONSUMER_HID_CODE_POWER,  HID_CONSUMER_KIND},
    {RCU_KEY_S7,  KEYBOARD_HID_CODE_UP,     HID_KEYBOARD_KIND},
    {RCU_KEY_S8,  0,                        0                },
    {RCU_KEY_S9,  0,                        0                },
    {RCU_KEY_S10, KEYBOARD_HID_CODE_DOWN,   HID_KEYBOARD_KIND},
    {RCU_KEY_S11, 0,                        0                },
    {RCU_KEY_S12, 0,                        0                },
    {RCU_KEY_S13, KEYBOARD_HID_CODE_RIGHT,  HID_KEYBOARD_KIND},
    {RCU_KEY_S14, KEYBOARD_HID_CODE_HOME,   HID_KEYBOARD_KIND},
    {RCU_KEY_S15, KEYBOARD_HID_CODE_MENU,   HID_KEYBOARD_KIND},
    {RCU_KEY_S16, 0,                        0                },
    {RCU_KEY_S17, 0,                        0                },
    {RCU_KEY_S18, CONSUMER_HID_VOLUME_UP,   HID_CONSUMER_KIND},
    {RCU_KEY_S19, 0,                        0                },
    {RCU_KEY_S20, CONSUMER_HID_VOLUME_DOWN, HID_CONSUMER_KIND},
};
#endif

#if CONFIG_AIR_MOUSE_HR_BOARD
#define GPIO_MAP_NUM                8   // keyscan使用的gpio管脚数量
#define GPIO_COL_1                  16  // COL1 gpio管脚号
#define GPIO_COL_2                  21  // COL2 gpio管脚号
#define GPIO_COL_3                  6   // COL3 gpio管脚号
#define GPIO_COL_4                  5   // COL4 gpio管脚号
#define GPIO_ROW_1                  24  // ROW1 gpio管脚号
#define GPIO_ROW_2                  23  // ROW2 gpio管脚号
#define GPIO_ROW_3                  22  // ROW3 gpio管脚号
#define GPIO_ROW_4                  2   // ROW3 gpio管脚号
#elif CONFIG_AIR_MOUSE_HX_BOARD
#define GPIO_MAP_NUM                9   // keyscan使用的gpio管脚数量
#define GPIO_COL_1                  16  // COL1 gpio管脚号
#define GPIO_COL_2                  21  // COL2 gpio管脚号
#define GPIO_COL_3                  18  // COL3 gpio管脚号
#define GPIO_COL_4                  11  // COL4 gpio管脚号
#define GPIO_COL_5                  17  // COL5 gpio管脚号
#define GPIO_ROW_1                  24  // ROW1 gpio管脚号
#define GPIO_ROW_2                  23  // ROW2 gpio管脚号
#define GPIO_ROW_3                  22  // ROW3 gpio管脚号
#define GPIO_ROW_4                  5   // ROW4 gpio管脚号
#endif

#if CONFIG_AIR_MOUSE_HR_BOARD
// Keyscan的gpio矩阵，ROW在前，COL在后
static const uint8_t user_gpio_map[GPIO_MAP_NUM] = {
    GPIO_ROW_1, GPIO_ROW_2, GPIO_ROW_3, GPIO_ROW_4,
    GPIO_COL_1, GPIO_COL_2, GPIO_COL_3, GPIO_COL_4
};

// Keyscan的键值矩阵
static const uint8_t g_key_map[CONFIG_KEYSCAN_ENABLE_ROW][CONFIG_KEYSCAN_ENABLE_COL] = {
    {RCU_KEY_S3,  RCU_KEY_S4,  RCU_KEY_S5,  RCU_KEY_S6 },
    {RCU_KEY_S7,  RCU_KEY_S8,  RCU_KEY_S9,  RCU_KEY_S10},
    {RCU_KEY_S11, RCU_KEY_S12, RCU_KEY_S13, RCU_KEY_S14},
    {RCU_KEY_S15, RCU_KEY_S16, 0,           0          },
};

#elif CONFIG_AIR_MOUSE_HX_BOARD
// Keyscan的gpio矩阵，ROW在前，COL在后
static const uint8_t user_gpio_map[GPIO_MAP_NUM] = {
    GPIO_ROW_1, GPIO_ROW_2, GPIO_ROW_3, GPIO_ROW_4,
    GPIO_COL_1, GPIO_COL_2, GPIO_COL_3, GPIO_COL_4, GPIO_COL_5
};

// Keyscan的键值矩阵
static const uint8_t g_key_map[CONFIG_KEYSCAN_ENABLE_ROW][CONFIG_KEYSCAN_ENABLE_COL] = {
    {RCU_KEY_S1,  RCU_KEY_S2,  RCU_KEY_S3,  RCU_KEY_S4,  RCU_KEY_S5 },
    {RCU_KEY_S6,  RCU_KEY_S7,  RCU_KEY_S8,  RCU_KEY_S9,  RCU_KEY_S10},
    {RCU_KEY_S11, RCU_KEY_S12, RCU_KEY_S13, RCU_KEY_S14, RCU_KEY_S15},
    {RCU_KEY_S16, RCU_KEY_S17, RCU_KEY_S18, RCU_KEY_S19, RCU_KEY_S20},
};
#endif

const key_config_t *get_key_value(rcu_key_index_e key)
{
    return &g_menu_key_map[key];
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
