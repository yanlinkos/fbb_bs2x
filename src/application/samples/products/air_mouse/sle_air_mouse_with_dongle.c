/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2023-2024. All rights reserved.
 *
 * Description: Sle Air Mouse with dongle Sample Source. \n
 *
 * History: \n
 * 2023-11-16, Create file. \n
 */
#include "app_init.h"
#include "gadget/f_hid.h"
#include "soc_osal.h"
#include "securec.h"
#include "uart.h"
#include "watchdog.h"
#include "sle_errcode.h"
#include "sle_connection_manager.h"
#include "sle_device_discovery.h"
#include "usb/air_mouse_usb.h"
#include "air_mouse_common.h"
#include "timer/am_common_timer.h"
#include "vdt_codec.h"
#if defined(CONFIG_SAMPLE_SUPPORT_AIR_MOUSE)
#include "mouse/rcu_main.h"
#include "mouse/sle_air_mouse_server/sle_air_mouse_server_adv.h"
#include "mouse/sle_air_mouse_server/sle_air_mouse_server.h"
#if CONFIG_AIR_MOUSE_HR_BOARD || CONFIG_AIR_MOUSE_HX_BOARD
#include "mouse/keyscan/air_mouse_keyscan.h"
#include "mouse/led/air_mouse_led.h"
#endif
#elif defined(CONFIG_SAMPLE_SUPPORT_AIR_MOUSE_DONGLE)
#include "dongle/sle_air_mouse_client/sle_air_mouse_client.h"
#include "dongle/radar/air_mouse_radar.h"
#include "tcxo.h"
#endif
#include "slp.h"
#include "slp_factory.h"
#include "pm_veto.h"
#include "usb/air_mouse_usb.h"

#define AIR_MOUSE_TASK_STACK_SIZE       0xa00
#define AIR_MOUSE_TASK_PRIO             20

#if CONFIG_SAMPLE_SUPPORT_AIR_MOUSE_CIR_PRINT
#define SLP_TASK_STACK_SIZE             0x1a00
#else
#define SLP_TASK_STACK_SIZE             0xa00
#endif
#define SLP_TASK_PRIO                   20

static void *slp_task(const char *arg)
{
    osal_printk("input slp_task\r\n");
    unused(arg);

#ifdef CONFIG_AIR_MOUSE_HX_BOARD
    (void)uapi_pin_set_mode((pin_t)CONFIG_AIR_MOUSE_POWER_CTRL_PIN, (pin_mode_t)HAL_PIO_FUNC_GPIO);
    (void)uapi_gpio_set_dir((pin_t)CONFIG_AIR_MOUSE_POWER_CTRL_PIN, GPIO_DIRECTION_INPUT);
    (void)uapi_pin_set_pull((pin_t)CONFIG_AIR_MOUSE_POWER_CTRL_PIN, PIN_PULL_UP);
#endif

    // 启动Slp任务，并阻塞等待消息
    SlpTask(NULL);

    return NULL;
}

#if defined(CONFIG_SAMPLE_SUPPORT_AIR_MOUSE)
static void *sle_air_mouse_task(const char *arg)
{
    osal_printk("input sle_air_mouse_task\r\n");
    unused(arg);
#if CONFIG_AIR_MOUSE_EVB4_BOARD || CONFIG_AIR_MOUSE_RADAR_2T4R_BOARD
    air_mouse_usb_init(); // USB初始化
#endif
#if CONFIG_AIR_MOUSE_HR_BOARD || CONFIG_AIR_MOUSE_HX_BOARD
    /* 按键功能初始化 */
    air_mouse_keyscan_init();
    /* LED控制初始化 */
    air_mouse_led_init();
    led_start_timer(LED_GREEN, LED_BLINK_PERIOD, 0);
#endif

    uapi_pm_add_sleep_veto(PM_VETO_ID_SLP);

    sle_server_slp_command_register_cbks(); // 注册server端 SLP command回调

    set_slp_uart_buffer(); // 设置slp uart buffer
#if CONFIG_AIR_MOUSE_HX_BOARD
    set_transform_param(SLP_IMU_TYPE_BMI325);
#else
    set_transform_param(SLP_IMU_TYPE_BMI270);
#endif
    // 设置Slp本机属性
    SlpLocalAtt att = {0};
    att.screenParam.cursorSpeed = get_slp_cursor_speed();
    att.screenParam.width = get_screen_width();
    att.screenParam.height = get_screen_height();
    set_ant_sw_param(&att.rfSwParam);
    (void)memcpy_s(&att.localAddr, sizeof(SlpDeviceAddr), get_slp_air_mouse_addr(), sizeof(SlpDeviceAddr));
    ErrcodeSlpClient ret = SlpSetLocalAttCommand(&att);
    if (ret != ERRCODE_SLPC_SUCCESS) {
        osal_printk("SlpSetLocalAttCommand Error 0x%x\r\n", ret);
        return NULL;
    }

    // SLE广播
    sle_air_mouse_server_init();

#if CONFIG_AIR_MOUSE_HR_BOARD || CONFIG_AIR_MOUSE_HX_BOARD
    led_stop_timer(LED_GREEN);
    rcu_task(NULL);  // 消息队列
#endif
    return NULL;
}

#elif defined(CONFIG_SAMPLE_SUPPORT_AIR_MOUSE_DONGLE)
static void *sle_air_mouse_dongle_task(const char *arg)
{
    osal_printk("input sle_air_mouse_dongle_task\r\n");
    unused(arg);
    uapi_pm_add_sleep_veto(PM_VETO_ID_SLP);

    air_mouse_usb_init(); // USB初始化
    sle_client_slp_command_register_cbks(); // 注册client端 SLP command回调

    set_slp_uart_buffer(); // 设置slp uart buffer
    // Dongle IMU转换参数设置，需根据当前使用IMU型号配置，没有IMU则无需配置
#if CONFIG_AIR_MOUSE_RADAR_2T4R_BOARD
    set_transform_param(SLP_IMU_TYPE_ASM330);
#else
    set_transform_param(SLP_IMU_TYPE_BMI270);
#endif
    // 设置Slp本机属性
    SlpLocalAtt att = {0};
    // car模式下screenParam在dongle端配置生效
    att.screenParam.cursorSpeed = get_slp_cursor_speed();
    att.screenParam.width = get_screen_width();
    att.screenParam.height = get_screen_height();
    set_ant_sw_param(&att.rfSwParam);
    (void)memcpy_s(&att.localAddr, sizeof(SlpDeviceAddr), get_slp_air_mouse_dongl_addr(), sizeof(SlpDeviceAddr));
    ErrcodeSlpClient ret = SlpSetLocalAttCommand(&att);
    if (ret != ERRCODE_SLPC_SUCCESS) {
        osal_printk("SlpSetLocalAttCommand Error 0x%x\r\n", ret);
        return NULL;
    }

    SlpInstParam param = {
        .downtilt = 40, // dongle下倾角40°
        .verDisToCarSeat = 500, // 座椅高度减dongle高度500mm
        .verDisToSreenTop = 0, // 屏幕顶部高度减dongle高度0mm
        .horDisToSreen = 0, // 屏幕与dongle水平距离0mm
    };
    ret = SlpSetInstParam(&param); // 设置安装参数
    if (ret != ERRCODE_SLPC_SUCCESS) {
        osal_printk("SlpSetInstParam Error 0x%x\r\n", ret);
    }

    air_mouse_radar_init();

#if defined(CONFIG_AIR_MOUSE_CI_REPLAY_TEST)
    SlpPowerOnCommand(); // 上电后不开扫描, slp直接加载
#elif defined(CONFIG_AIR_MOUSE_RADAR_ONLY)
    SlpPowerOnCommand(); // 上电后不开扫描, slp直接加载
    air_mouse_radar_start();
#else

    sle_air_mouse_client_init(); // GLE 扫描连接

#if CONFIG_AIR_MOUSE_UAC
    // 初始化事件队列，用于处理amic语音数据
    if (osal_event_init(&g_trans_event_id) != OSAL_SUCCESS) {
        osal_printk("dongle osal_event_init fail! \r\n");
    }
    vdt_codec_init(); // 初始化音频编解码

    while (1) {
        uapi_watchdog_kick();
        uint8_t ret = osal_event_read(&g_trans_event_id, VDT_TRANSFER_EVENT, OSAL_WAIT_FOREVER,
                                      OSAL_WAITMODE_AND | OSAL_WAITMODE_CLR);
        if (ret & VDT_TRANSFER_EVENT) {
            send_amic_data_uac();
        }
    }
#endif // CONFIG_AIR_MOUSE_UAC

#endif

    return NULL;
}
#endif

static void sle_air_mouse_with_dongle_entry(void)
{
    /*
        16:9长宽比下，长宽分别为（单位mm）:
        85寸    屏宽1887， 屏高1092
        17.3寸  屏宽382，  屏高215
        15.6寸  屏宽345，  屏高194
        13.2寸  屏宽292，  屏高164
     */
    set_screen_size(1887, 1092); // 85寸屏宽1887，屏高1092
    set_slp_cursor_speed(SLP_CURSOR_SPEED_MEDIUM);
    air_mouse_timer_init(); // 定时器初始化
    writew(0x5702c288, 0x3A00); //  slp 32M时钟驱动调制最大
    osal_printk("input sle_air_mouse_with_dongle_entry\r\n");

    // slp sync管脚配置
    uapi_pin_set_mode(CONFIG_AIR_MOUSE_SYNC_PIN, PIN_MODE_61);

    osal_task *task_cb = NULL;
    osal_task *slp_task_cb = NULL;
    osal_kthread_lock();

    slp_task_cb = osal_kthread_create((osal_kthread_handler)slp_task, NULL,
                                      "SLPTask", SLP_TASK_STACK_SIZE);
#if defined(CONFIG_SAMPLE_SUPPORT_AIR_MOUSE_DONGLE)
    task_cb = osal_kthread_create((osal_kthread_handler)sle_air_mouse_dongle_task, NULL,
                                  "SLEAirMouseDongleTask", AIR_MOUSE_TASK_STACK_SIZE);
#endif

#if defined(CONFIG_SAMPLE_SUPPORT_AIR_MOUSE)
    task_cb = osal_kthread_create((osal_kthread_handler)sle_air_mouse_task, NULL,
                                  "SLEAirMouseTask", AIR_MOUSE_TASK_STACK_SIZE);
#endif

    if (slp_task_cb != NULL) {
        osal_kthread_set_priority(slp_task_cb, SLP_TASK_PRIO);
    }
    if (task_cb != NULL) {
        osal_kthread_set_priority(task_cb, AIR_MOUSE_TASK_PRIO);
    }

    osal_kthread_unlock();
}

/* Run the sle_air_mouse_with_dongle_entry. */
app_run(sle_air_mouse_with_dongle_entry);
