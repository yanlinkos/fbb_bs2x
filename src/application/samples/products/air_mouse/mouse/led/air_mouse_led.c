/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * Description: Air Mouse LED. \n
 *
 * History: \n
 * 2024-09-25, Create file. \n
 */
#include "air_mouse_led.h"
#include "gpio.h"
#include "osal_timer.h"
#include "pinctrl.h"
#include "soc_osal.h"

#define GPIO_LED_RED 0    // LED_R gpio管脚号
#define GPIO_LED_GREEN 1  // LED_G gpio管脚号

#define LED_OPEN_GPIO_LEVEL 0
#define LED_CLOSE_GPIO_LEVEL 1

#define LED_TIMER_INIT_INTERVAL 100  // unit: ms

typedef struct {
    volatile bool status;      // LED状态，true: 开启; false: 关闭
    uint8_t gpio_pin;          // 管脚号
    osal_timer timer_blink;    // blink定时器
    osal_timer timer_timeout;  // 超时关闭定时器
} led_ctrl_t;                  // LED控制结构体

static led_ctrl_t g_led_ctrl_arr[LED_NUM];  // LED控制数组
static led_status_e g_led_status = LED_STATUS_IDLE;

static void led_timer_blink_callback(unsigned long arg)  // blink定时器回调函数
{
    led_color_e color = (led_color_e)arg;
    if (g_led_ctrl_arr[color].status) {
        osal_timer_start(&g_led_ctrl_arr[color].timer_blink);
        uapi_gpio_set_val(g_led_ctrl_arr[color].gpio_pin, !uapi_gpio_get_val(g_led_ctrl_arr[color].gpio_pin));
    }
}

static void led_timer_timeout_callback(unsigned long arg)  // timeout定时器回调函数
{
    led_stop_timer((led_color_e)arg);
}

void led_start_timer(led_color_e color, uint32_t blink_period, uint32_t led_timer_timeout)
{
    g_led_ctrl_arr[color].status = true;
    osal_timer_stop(&g_led_ctrl_arr[color].timer_blink);
    if (blink_period != 0) {
        osal_timer_mod(&g_led_ctrl_arr[color].timer_blink, blink_period);  // 修改定时器，执行后定时器会重启。
    }

    osal_timer_stop(&g_led_ctrl_arr[color].timer_timeout);
    if (led_timer_timeout != 0) {  // 0: 常亮，unit: ms
        osal_timer_mod(&g_led_ctrl_arr[color].timer_timeout, led_timer_timeout);
    }

    uapi_gpio_set_val(g_led_ctrl_arr[color].gpio_pin, LED_OPEN_GPIO_LEVEL);
}

void led_stop_timer(led_color_e color)
{
    g_led_ctrl_arr[color].status = false;
    osal_timer_stop(&g_led_ctrl_arr[color].timer_timeout);  // 0:alerady success; 1:success
    osal_timer_stop(&g_led_ctrl_arr[color].timer_blink);
    uapi_gpio_set_val(g_led_ctrl_arr[color].gpio_pin, LED_CLOSE_GPIO_LEVEL);
}

void set_led_status(led_status_e status)
{
    osal_printk("[LED] set status:%u\r\n", status);

    g_led_status = status;
    led_stop_timer(LED_RED);
    switch (status) {
        case LED_STATUS_IDLE:
            break;
        case LED_STATUS_ONE_KEY_DOWN:
            led_start_timer(LED_RED, 0, 0);
            break;
        case LED_STATUS_PAIRING:
            led_start_timer(LED_RED, LED_BLINK_PERIOD, 0);
            break;
        case LED_STATUS_UNPAIRING:
            led_start_timer(LED_RED, LED_BLINK_PERIOD, 0);
            break;
        case LED_STATUS_SPEED_MODE_LOW:
            led_start_timer(LED_GREEN, LED_BLINK_PERIOD, LED_BLINK_PERIOD * 1);  // 1:闪烁1次
            break;
        case LED_STATUS_SPEED_MODE_MEDIUM:
            led_start_timer(LED_GREEN, LED_BLINK_PERIOD, LED_BLINK_PERIOD * 3);  // 3:闪烁2次
            break;
        case LED_STATUS_SPEED_MODE_HIGH:
            led_start_timer(LED_GREEN, LED_BLINK_PERIOD, LED_BLINK_PERIOD * 5);  // 5:闪烁3次
            break;
        default:
            osal_printk("invalid LED status: %u\r\n", status);
            break;
    }
}

led_status_e get_led_status(void)
{
    return g_led_status;
}

void air_mouse_led_init(void)  // 初始化LED相关配置
{
    g_led_ctrl_arr[LED_RED].gpio_pin = GPIO_LED_RED;
    g_led_ctrl_arr[LED_GREEN].gpio_pin = GPIO_LED_GREEN;

    int32_t ret;
    for (uint8_t i = 0; i < LED_NUM; i++) {
        uapi_pin_set_mode(g_led_ctrl_arr[i].gpio_pin, HAL_PIO_FUNC_GPIO);      // 设置指定IO复用为GPIO模式
        uapi_gpio_set_dir(g_led_ctrl_arr[i].gpio_pin, GPIO_DIRECTION_OUTPUT);  // 设置指定GPIO为输出模式

        g_led_ctrl_arr[i].timer_blink.timer = NULL;
        g_led_ctrl_arr[i].timer_blink.data = i;  // 入参为LED编号
        g_led_ctrl_arr[i].timer_blink.handler = led_timer_blink_callback;
        g_led_ctrl_arr[i].timer_blink.interval = LED_TIMER_INIT_INTERVAL;
        ret = osal_timer_init(&g_led_ctrl_arr[i].timer_blink);
        if (ret != OSAL_SUCCESS) {
            osal_printk("LED blink timer create failed! ret:0x%X, color:%u\r\n", ret, i);
        }

        g_led_ctrl_arr[i].timer_timeout.timer = NULL;
        g_led_ctrl_arr[i].timer_timeout.data = i;
        g_led_ctrl_arr[i].timer_timeout.handler = led_timer_timeout_callback;
        g_led_ctrl_arr[i].timer_timeout.interval = LED_TIMER_INIT_INTERVAL;
        ret = osal_timer_init(&g_led_ctrl_arr[i].timer_timeout);
        if (ret != OSAL_SUCCESS) {
            osal_printk("LED timeout timer create failed! ret:0x%X, color:%u\r\n", ret, i);
        }

        led_stop_timer(i);
    }
}
