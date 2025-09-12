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
#include "slp_errcode.h"
#include "sle_connection_manager.h"
#include "sle_device_discovery.h"
#include "dongle/air_mouse_usb/usb_init_app.h"
#include "vdt_codec.h"
#if defined(CONFIG_SAMPLE_SUPPORT_AIR_MOUSE)
#include "mouse/rcu_main.h"
#include "mouse/sle_air_mouse_server/sle_air_mouse_server_adv.h"
#include "mouse/sle_air_mouse_server/sle_air_mouse_server.h"
#ifdef CONFIG_AIR_MOUSE_HR_BOARD
#include "mouse/keyscan/air_mouse_keyscan.h"
#include "mouse/led/air_mouse_led.h"
#endif
#elif defined(CONFIG_SAMPLE_SUPPORT_AIR_MOUSE_DONGLE)
#include "dongle/sle_air_mouse_client/sle_air_mouse_client.h"
#include "dongle/air_mouse_usb/usb_init_app.h"
#include "tcxo.h"
#endif
#include "slp.h"
#include "slp_factory.h"
#include "pm_veto.h"
#ifdef CONFIG_AIR_MOUSE_DONGLE_FACTORY_PHASE_CALI
#include "dongle/air_mouse_usb/usb_serial.h"
#include "gadget/usbd_acm.h"
#endif

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

    // 启动Slp任务，并阻塞等待消息
    SlpTask(NULL);

    return NULL;
}

static void set_slp_local_attr(const SlpDeviceAddr *mac)
{
    // 设置Slp本机属性
    set_screen_size(1887, 1092); // 85寸屏宽1887，屏高1092
    set_slp_cursor_speed(SLP_CURSOR_SPEED_MEDIUM);
    SlpLocalAtt att = {0};
    att.screenParam.cursorSpeed = get_slp_cursor_speed();
    att.screenParam.width = get_screen_width();
    att.screenParam.height = get_screen_height();
    (void)memcpy_s(&att.localAddr, sizeof(SlpDeviceAddr), mac, sizeof(SlpDeviceAddr));
    ErrcodeSlpClient ret = SlpSetLocalAttCommand(&att);
    if (ret != ERRCODE_SLPC_SUCCESS) {
        osal_printk("SlpSetLocalAttCommand Error 0x%x\r\n", ret);
    }
}

#if defined(CONFIG_SAMPLE_SUPPORT_AIR_MOUSE)
static void *sle_air_mouse_task(const char *arg)
{
    osal_printk("input sle_air_mouse_task\r\n");
    unused(arg);

#ifdef CONFIG_AIR_MOUSE_HR_BOARD
    /* 按键功能初始化 */
    air_mouse_keyscan_init();
    /* LED控制初始化 */
    air_mouse_led_init();
    led_start_timer(LED_GREEN, LED_BLINK_PERIOD, 0);
#endif

    uapi_pm_add_sleep_veto(PM_VETO_ID_SLP);

    sle_server_slp_command_register_cbks(); // 注册server端 SLP command回调

    set_slp_local_attr(get_slp_air_mouse_addr()); // 设置Slp本机属性

    vdt_codec_init(); // 初始化音频编解码
    // SLE广播
    sle_air_mouse_server_init();

#ifdef CONFIG_AIR_MOUSE_HR_BOARD
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

    // USB 设备初始化
#if defined(CONFIG_AIR_MOUSE_HR_BOARD) || (CONFIG_AIR_MOUSE_EVB4_FOR_1T2R)
#ifdef CONFIG_AIR_MOUSE_DONGLE_FACTORY_PHASE_CALI
    dongle_usb_serial_init();  // USB 串口设备初始化
#else
    dongle_hid_usb_init();  // USB HID设备初始化
#endif
#endif

    sle_client_slp_command_register_cbks(); // 注册client端 SLP command回调

    // 设置HID类型
#if CONFIG_AIR_MOUSE_DONGLE_RELATIVE_COORDINATES
    set_mouse_move_mode(HID_PEN_KIND);
#elif CONFIG_AIR_MOUSE_DONGLE_ABSOLUTE_COORDINATES
    set_mouse_move_mode(HID_PEN_KIND);
#elif CONFIG_AIR_MOUSE_DONGLE_FACTORY_SCREEN_TEST
    set_screen_resolution(SLP_SCREEN_4K);
    set_mouse_move_mode(HID_NEARLINK_KIND);
#else
#endif

    set_slp_local_attr(get_slp_air_mouse_dongl_addr()); // 设置Slp本机属性

    // 初始化事件队列，用于处理amic语音数据
    if (osal_event_init(&g_trans_event_id) != OSAL_SUCCESS) {
        osal_printk("dongle osal_event_init fail! \r\n");
    }
    vdt_codec_init(); // 初始化音频编解码

#ifdef CONFIG_AIR_MOUSE_DONGLE_FACTORY_PHASE_CALI
    SlpSetFactoryTestMode(SLP_FACTORY_TEST_AOX_CALI); // 相位校准模式
#endif

    // GLE 扫描连接
    sle_air_mouse_client_init();

    while (1) {
        uapi_watchdog_kick();
        uint8_t ret = osal_event_read(&g_trans_event_id, VDT_TRANSFER_EVENT, OSAL_WAIT_FOREVER,
                                      OSAL_WAITMODE_AND | OSAL_WAITMODE_CLR);
        if (ret & VDT_TRANSFER_EVENT) {
            send_amic_data_uac();
        }
    }

    return NULL;
}
#endif

static void sle_air_mouse_with_dongle_entry(void)
{
    osal_printk("input sle_air_mouse_with_dongle_entry\r\n");
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