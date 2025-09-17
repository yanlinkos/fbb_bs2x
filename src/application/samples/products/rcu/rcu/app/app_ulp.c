/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2023-2025. All rights reserved.
 *
 * Description: RCU LOW POWER SOURCE \n
 *
 * History: \n
 * 2024-5-21, Create file. \n
 */
#if defined(CONFIG_PM_SYS_SUPPORT)
#if defined(CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER)
#include "sle_rcu_server.h"
#endif
#if defined(CONFIG_SAMPLE_SUPPORT_BLE_RCU_SERVER)
#include "ble_rcu_server.h"
#endif
#include "keyscan.h"
#ifdef CONFIG_ULTRA_DEEP_SLEEP_ENABLE
#include "pm_sleep_porting.h"
#endif
#include "ulp_gpio.h"
#include "soc_osal.h"
#include "pm_porting.h"
#include "gpio.h"
#include "pm_sys.h"
#include "app_status.h"
#include "app_ulp.h"

static void ulp_gpio_wkup_handler(uint8_t ulp_gpio)
{
    uapi_pm_wkup_process(0);
    osal_printk("ulp_gpio%d wakeup\n", ulp_gpio);
}

static ulp_gpio_int_wkup_cfg_t g_wk_cfg[] = {
    { 1, 35, true, ULP_GPIO_INTERRUPT_FALLING_EDGE, ulp_gpio_wkup_handler }, /* ulp_gpio1设置为下降沿中断，用于系统唤醒并
                                                                              在系统唤醒后进入回调处理。 */
};

static void rcu_enable_ulpgpio_wkup(void)
{
    uapi_gpio_deinit();
    ulp_gpio_init();
    ulp_gpio_int_wkup_config(g_wk_cfg, sizeof(g_wk_cfg) / sizeof(ulp_gpio_int_wkup_cfg_t));
}

static void rcu_disable_ulpgpio_wkup(void)
{
    ulp_gpio_deinit();
    uapi_gpio_init();
}

static void ulp_gpio_standby_config(void)
{
    uapi_gpio_set_dir(S_MGPIO0, GPIO_DIRECTION_INPUT);
    uapi_gpio_set_dir(S_MGPIO1, GPIO_DIRECTION_INPUT);
    uapi_gpio_set_dir(S_MGPIO2, GPIO_DIRECTION_INPUT);
    uapi_gpio_set_dir(S_MGPIO3, GPIO_DIRECTION_INPUT);
    uapi_gpio_set_dir(S_MGPIO4, GPIO_DIRECTION_INPUT);
    uapi_gpio_set_dir(S_MGPIO5, GPIO_DIRECTION_INPUT);
    uapi_gpio_set_dir(S_MGPIO6, GPIO_DIRECTION_INPUT);
    uapi_gpio_set_dir(S_MGPIO7, GPIO_DIRECTION_INPUT);
    uapi_gpio_set_dir(S_MGPIO8, GPIO_DIRECTION_INPUT);
    uapi_gpio_set_dir(S_MGPIO9, GPIO_DIRECTION_INPUT);
    uapi_gpio_set_dir(S_MGPIO15, GPIO_DIRECTION_INPUT);
    uapi_gpio_set_dir(S_MGPIO17, GPIO_DIRECTION_INPUT);
    uapi_gpio_set_dir(S_MGPIO18, GPIO_DIRECTION_INPUT);
    uapi_gpio_set_dir(S_MGPIO19, GPIO_DIRECTION_INPUT);
    uapi_gpio_set_dir(S_MGPIO20, GPIO_DIRECTION_INPUT);
    uapi_gpio_set_dir(S_MGPIO28, GPIO_DIRECTION_INPUT);
    uapi_gpio_set_dir(S_MGPIO29, GPIO_DIRECTION_INPUT);
    uapi_gpio_set_dir(S_MGPIO30, GPIO_DIRECTION_INPUT);
    uapi_gpio_set_dir(S_MGPIO31, GPIO_DIRECTION_INPUT);
    uapi_pin_set_pull(S_MGPIO0, PIN_PULL_DOWN);
    uapi_pin_set_pull(S_MGPIO1, PIN_PULL_DOWN);
    uapi_pin_set_pull(S_MGPIO2, PIN_PULL_NONE);
    uapi_pin_set_pull(S_MGPIO3, PIN_PULL_NONE);
    uapi_pin_set_pull(S_MGPIO4, PIN_PULL_NONE);
    uapi_pin_set_pull(S_MGPIO5, PIN_PULL_UP);
    uapi_pin_set_pull(S_MGPIO6, PIN_PULL_DOWN);
    uapi_pin_set_pull(S_MGPIO7, PIN_PULL_UP);
    uapi_pin_set_pull(S_MGPIO8, PIN_PULL_UP);
    uapi_pin_set_pull(S_MGPIO9, PIN_PULL_UP);
    uapi_pin_set_pull(S_MGPIO15, PIN_PULL_DOWN);
    uapi_pin_set_pull(S_MGPIO17, PIN_PULL_DOWN);
    uapi_pin_set_pull(S_MGPIO18, PIN_PULL_DOWN);
    uapi_pin_set_pull(S_MGPIO19, PIN_PULL_DOWN);
    uapi_pin_set_pull(S_MGPIO20, PIN_PULL_DOWN);
    uapi_pin_set_pull(S_MGPIO27, PIN_PULL_DOWN);
    uapi_pin_set_pull(S_MGPIO28, PIN_PULL_DOWN);
    uapi_pin_set_pull(S_MGPIO29, PIN_PULL_DOWN);
    uapi_pin_set_pull(S_MGPIO30, PIN_PULL_DOWN);
    uapi_pin_set_pull(S_MGPIO31, PIN_PULL_DOWN);
}

static void ulp_gpio_wakeup_config(void)
{
    uapi_pin_set_pull(S_MGPIO0, PIN_PULL_DOWN);
    uapi_pin_set_pull(S_MGPIO1, PIN_PULL_DOWN);
    uapi_pin_set_pull(S_MGPIO2, PIN_PULL_DOWN);
    uapi_pin_set_pull(S_MGPIO3, PIN_PULL_NONE);
    uapi_pin_set_pull(S_MGPIO4, PIN_PULL_UP);
    uapi_pin_set_pull(S_MGPIO5, PIN_PULL_DOWN);
    uapi_pin_set_pull(S_MGPIO6, PIN_PULL_DOWN);
    uapi_pin_set_pull(S_MGPIO7, PIN_PULL_DOWN);
    uapi_pin_set_pull(S_MGPIO8, PIN_PULL_DOWN);
    uapi_pin_set_pull(S_MGPIO9, PIN_PULL_DOWN);
    uapi_pin_set_pull(S_MGPIO15, PIN_PULL_DOWN);
    uapi_pin_set_pull(S_MGPIO17, PIN_PULL_NONE);
    uapi_pin_set_pull(S_MGPIO18, PIN_PULL_DOWN);
    uapi_pin_set_pull(S_MGPIO19, PIN_PULL_NONE);
    uapi_pin_set_pull(S_MGPIO20, PIN_PULL_DOWN);
    uapi_pin_set_pull(S_MGPIO27, PIN_PULL_DOWN);
    uapi_pin_set_pull(S_MGPIO28, PIN_PULL_DOWN);
    uapi_pin_set_pull(S_MGPIO29, PIN_PULL_DOWN);
    uapi_pin_set_pull(S_MGPIO30, PIN_PULL_DOWN);
    uapi_pin_set_pull(S_MGPIO31, PIN_PULL_DOWN);
}

static int32_t rcu_state_work_to_standby(uintptr_t arg)
{
    osal_printk("rcu_state_work_to_standby\r\n");
    uapi_keyscan_suspend(arg);
    rcu_enable_ulpgpio_wkup();
    set_app_sys_status(APP_SYS_STANDBY);
    ulp_gpio_standby_config();
#if defined(CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER)
    /* 连接态：增大连接间隔；广播态：暂不操作。 */
    sle_rcu_work_to_standby();
#endif
#if defined(CONFIG_SAMPLE_SUPPORT_BLE_RCU_SERVER)
    /* 连接态：增大连接间隔；广播态：暂不操作。 */
    ble_rcu_work_to_standby();
#endif

    return 0;
}

static int32_t rcu_state_standby_to_sleep(uintptr_t arg)
{
    unused(arg);
    osal_printk("rcu_state_standby_to_sleep\r\n");
    set_app_sys_status(APP_SYS_SLEEP);
#if defined(CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER)
    /* 断开连接、关闭广播。 */
    sle_rcu_standby_to_sleep();
#endif
#if defined(CONFIG_SAMPLE_SUPPORT_BLE_RCU_SERVER)
    /* 断开连接、关闭广播。 */
    ble_rcu_standby_to_sleep();
#endif
#ifdef CONFIG_ULTRA_DEEP_SLEEP_ENABLE
    pm_enable_ultra_deep_sleep_mode(true);
#endif
    return 0;
}

static int32_t rcu_state_standby_to_work(uintptr_t arg)
{
    osal_printk("rcu_state_standby_to_work\r\n");
    set_app_sys_status(APP_SYS_WORK);
    rcu_disable_ulpgpio_wkup();
    uapi_keyscan_resume(arg);
    ulp_gpio_wakeup_config();
#if defined(CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER)
    /* 连接态：减小连接间隔；广播态：不操作。 */
    sle_rcu_standby_to_work();
#endif
#if defined(CONFIG_SAMPLE_SUPPORT_BLE_RCU_SERVER)
    /* 连接态：减小连接间隔；广播态：不操作。 */
    ble_rcu_standby_to_work();
#endif
    return 0;
}

static int32_t rcu_state_sleep_to_work(uintptr_t arg)
{
    osal_printk("rcu_state_sleep_to_work\r\n");
    set_app_sys_status(APP_SYS_WORK);
    rcu_disable_ulpgpio_wkup();
    uapi_keyscan_resume(arg);
    ulp_gpio_wakeup_config();
#if defined(CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER)
    /* 连接态：减小连接间隔；广播态：不操作。 */
    sle_rcu_standby_to_work();
    sle_rcu_sleep_to_work();
#endif
#if defined(CONFIG_SAMPLE_SUPPORT_BLE_RCU_SERVER)
    /* 连接态：减小连接间隔；广播态：不操作。 */
    ble_rcu_standby_to_work();
    ble_rcu_sleep_to_work();
#endif
    return 0;
}

void rcu_low_power_init(void)
{
    pm_state_trans_handler_t handler = {
        .work_to_standby = rcu_state_work_to_standby,
        .standby_to_sleep = rcu_state_standby_to_sleep,
        .standby_to_work = rcu_state_standby_to_work,
        .sleep_to_work = rcu_state_sleep_to_work,
    };
    uapi_pm_state_trans_handler_register(&handler);

    uapi_pm_work_state_reset();
    rcu_disable_ulpgpio_wkup();
    uapi_pm_set_state_trans_duration(DURATION_MS_OF_WORK_TO_STANDBY, DURATION_MS_OF_STANDBY_TO_SLEEP);
}
#endif
