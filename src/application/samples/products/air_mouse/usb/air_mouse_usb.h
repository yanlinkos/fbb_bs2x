/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2022-2025. All rights reserved.
 *
 * Description: Air Mouse USB Header. \n
 *
 * History: \n
 * 2025-09-15, Create file. \n
 */
#ifndef AIR_MOUSE_USB_H
#define AIR_MOUSE_USB_H

#include "slp.h"
#include "air_mouse_common.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

#define USB_HID_MAX_KEY_LENTH 6

typedef enum {
    HID_PEN_KIND = 0x3F, // 触控笔
    HID_KEYBOARD_KIND,   // 键盘输入
    HID_CONSUMER_KIND,   // Consumer
} hid_kind_mode;

#pragma pack(1)
typedef struct {
    uint8_t kind;
    uint8_t special_key;                /*!< 8bit special key(Lctrl Lshift Lalt Lgui Rctrl Rshift Ralt Rgui) */
    uint8_t reserve;
    uint8_t key[USB_HID_MAX_KEY_LENTH]; /*!< Normal key */
} usb_hid_keyboard_report_t;

typedef struct usb_hid_consumer_report {
    uint8_t kind;
    uint8_t comsumer_key0;
    uint8_t comsumer_key1;
} usb_hid_consumer_report_t;

// 定义按键结构体类型
typedef struct {
    uint8_t key;      // rcu_key_index_e
    uint8_t usage_id; // Usage ID
    uint8_t kind;     // hid_kind_mode
} key_config_t;

typedef struct {
    uint32_t sequence_no;  // 发送的消息号
    key_config_t config;
} keyboard_report_t;  // 用于空口传输键盘

typedef union {
    uint8_t data;
    struct {
        uint8_t tip : 1;       // 接触屏幕
        uint8_t barrel : 1;    // 桶形按钮
        uint8_t invert : 1;    // 倒置
        uint8_t eraser : 1;    // 橡皮擦
        uint8_t reserve1 : 1;
        uint8_t in_range : 1;  // 在范围内
        uint8_t reserve : 2;
    } bits;
} pen_control_union_t;

typedef struct {
    uint8_t kind;
    pen_control_union_t control;
    int16_t x;
    int16_t y;
    uint16_t tipPressure;  // 接触压力
    uint8_t xTilt;         // x轴倾斜度
    uint8_t yTilt;         // y轴倾斜度
} usb_hid_pen_t;

/**
 * @if Eng
 * @brief Definitaion of usb hid rcu report struct.
 * @else
 * @brief 定义USB CONSUMER HID上报的结构体。
 * @endif
 */
typedef struct usb_hid_rcu_consumer_report {
    uint8_t kind;
    uint8_t comsumer_key0;
    uint8_t comsumer_key1;
} usb_hid_rcu_consumer_report_t;
#pragma pack()

void usb_init_success_flag_register_callbacks(void *callback); // f_hid_custom.c中定义
bool get_usb_init_status(void);
bool get_usb_init_success_flag(void);
void air_mouse_usb_init(void);
void air_mouse_usb_deinit(void);
void usb_send_cursor_report(SlpCursorRslt *cursor_report);
void usb_send_keyboard_report(usb_hid_keyboard_report_t *report);
void usb_send_consumer_report(usb_hid_consumer_report_t *report);
void usb_send_serial_data(const char *buffer, uint16_t len);
void set_screen_size(uint16_t width, uint16_t height);
uint16_t get_screen_width(void);
uint16_t get_screen_height(void);
int32_t linear_map(int32_t input, int32_t m, int32_t n, int32_t lower, int32_t upper);
int32_t vdt_usb_uac_send_data(const uint8_t *data1, int len1, const uint8_t *data2, int len2);

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif
