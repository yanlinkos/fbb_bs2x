/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2025. All rights reserved.
 *
 * Description: Air Mouse LED. \n
 *
 * History: \n
 * 2024-09-25, Create file. \n
 */
#ifndef AIR_MOUSE_LED_H
#define AIR_MOUSE_LED_H

#include <stdint.h>

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

#define LED_BLINK_PERIOD      200  // unit: ms

typedef enum {
    LED_RED,
    LED_GREEN,
    LED_NUM,
} led_color_e;  // LED编号

typedef enum {
    LED_STATUS_IDLE,
    LED_STATUS_ONE_KEY_DOWN,       // 单个按键按下
    LED_STATUS_PAIRING,            // 配对中
    LED_STATUS_UNPAIRING,          // 解配对中
    LED_STATUS_SPEED_MODE_LOW,     // speed mode low
    LED_STATUS_SPEED_MODE_MEDIUM,  // speed mode medium
    LED_STATUS_SPEED_MODE_HIGH,    // speed mode high
} led_status_e;                    // LED状态

/**
 * @brief  开启LED.
 * @param  [in]  color LED编号, see @ref led_color_e.
 * @param  [in]  led_timer_period blink间隔, 单位: ms, 0: 不闪烁.
 * @param  [in]  led_timer_timeout 持续时间, 单位: ms, 0: 常亮.
 */
void led_start_timer(led_color_e color, uint32_t led_timer_period, uint32_t led_timer_timeout);
void led_stop_timer(led_color_e color);  // 关闭LED
void air_mouse_led_init(void);
void set_led_status(led_status_e status);
led_status_e get_led_status(void);

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif
