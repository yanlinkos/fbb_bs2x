/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2023-2023. All rights reserved.
 *
 * Description: RCU Source. \n
 *
 * History: \n
 * 2023-09-21, Create file. \n
 */
#include "securec.h"
#include "soc_osal.h"
#include "common_def.h"
#include "app_init.h"
#include "watchdog.h"
#include "keyscan.h"
#include "gpio.h"
#include "pinctrl.h"
#include "pm_clock.h"
#if defined(CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER) || defined(CONFIG_SAMPLE_SUPPORT_BLE_RCU_SERVER)
#include "vdt_codec.h"
#endif
#if defined(CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER)
#include "sle_errcode.h"
#include "sle_device_discovery.h"
#include "sle_connection_manager.h"
#include "sle_rcu_server.h"
#include "sle_rcu_server_adv.h"
#endif /* CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER */
#if defined(CONFIG_SAMPLE_SUPPORT_BLE_RCU_SERVER)
#include "ble_rcu_server.h"
#include "ble_rcu_server_adv.h"
#include "ble_hid_rcu_server.h"
#endif /* CONFIG_SAMPLE_SUPPORT_BLE_RCU_SERVER */
#include "bts_le_gap.h"
#if defined(CONFIG_SAMPLE_SUPPORT_IR)
#include "ir_nec.h"
#endif
#if defined(CONFIG_PM_SYS_SUPPORT)
#include "ulp_gpio.h"
#include "gpio.h"
#include "pm_sys.h"
#include "app_ulp.h"
#endif
#ifdef CONFIG_ULTRA_DEEP_SLEEP_ENABLE
#include "pm_sleep_porting.h"
#include "watchdog_porting.h"
#endif
#if defined(CONFIG_BT_UPG_ENABLE) || defined(CONFIG_SLE_UPG_ENABLE)
#include "ota_upgrade.h"
#endif
#include "app_status.h"
#include "app_timer.h"
#include "app_common.h"
#include "app_msg_queue.h"
#include "app_keyscan.h"
#include "timer.h"
#if defined(CONFIG_RCU_MASS_PRODUCTION_TEST)
#include "rcu_mp_test.h"
#endif  /* CONFIG_RCU_MASS_PRODUCTION_TEST */
#include "preserve.h"
#include "log_reg_dump.h"
#include "hal_reboot.h"
#include "rcu.h"

#define SLE_RCU_SERVER_TASK_PRIO           24
#define USB_HID_MAX_KEY_LENTH              6
#define KEYSCAN_REPORT_MAX_KEY_NUMS        6
#define CONVERT_DEC_TO_HEX                 16
#define MAX_NUM_OF_DEC                     10
#define LENGTH_OF_KEY_VALUE_STR            5
#define SLE_RCU_PARAM_ARGC_2               2
#define SLE_RCU_PARAM_ARGC_3               3
#define SLE_RCU_PARAM_ARGC_4               4

#define SLE_RCU_STATE_DISCONNECT           0
#define SLE_RCU_STATE_CONNECTED            1

#define RCU_TASK_STACK_SIZE                0xc00
#define RCU_TASK_DURATION_MS               200
#define SLE_RCU_WAIT_SSAPS_READY           500
#define SLE_RCU_SERVER_DELAY_COUNT         3
#define SLE_RCU_SERVER_MSG_QUEUE_MAX_SIZE  32
#define SLE_RCU_SERVER_LOG                 "[sle rcu server]"
#define USB_RCU_TASK_DELAY_MS              10

#define RCU_KEY_STANDBY                    0x66
#define RCU_KEY_HOME                       0x5
#define RCU_KEY_BACK                       0x6
#define RCU_KEY_SEARCH                     0x7
#define RCU_KEY_VOLUP                      0x8
#define RCU_KEY_VOLDOWN                    0x9
#define RCU_KEY_SWITCH_MOUSE_AND_KEY       0xA
#define RCU_KEY_POWER                      0xB
#define RCU_KEY_SWITCH_SLE_AND_BLE         0xC
#define RCU_KEY_SWITCH_CONN_ID             0xD
#define RCU_KEY_MIC                        0xE
#define RCU_KEY_CONNECT_ADV                0xF
#define RCU_KEY_DISCONNECT_DEVICE          0x10
#define RCU_KEY_SWITCH_IR                  0x11
#define RCU_KEY_WAKEUP_ADV                 0x12

#define RCU_KEY_APPLIC                     0x65
#define RCU_KEY_ENTER                      0x28
#define RCU_KEY_BACKOUT                    0x29
#define RCU_KEY_PAGEUP                     0x4B
#define RCU_KEY_PAGEDN                     0x4E
#define RCU_KEY_RIGHT                      0x4F
#define RCU_KEY_LEFT                       0x50
#define RCU_KEY_DOWN                       0x51
#define RCU_KEY_UP                         0x52

#define IR_NEC_USER_CODE                   0x00
#define IR_NEC_KEY_UP                      0xCA
#define IR_NEC_KEY_DOWN                    0xD2
#define IR_NEC_KEY_RIGHT                   0xC1
#define IR_NEC_KEY_LEFT                    0x99
#define IR_NEC_KEY_SELECT                  0xCE
#define IR_NEC_KEY_BACK                    0x90
#define IR_NEC_KEY_MENU                    0x9D
#define IR_NEC_KEY_POWER                   0x9C
#define IR_NEC_KEY_HOME                    0xCB
#define IR_NEC_KEY_VOLUMEUP                0x80
#define IR_NEC_KEY_VOLUMEDOWN              0x81
#define IR_NEC_KEY_MUTE                    0xDD

#define SLE_VDT_SERVER_LOG                 "[sle vdt server]"

#define RCU_CONSUMER_KEY_NUM               6
#define RCU_CONSUMER_KEY_OFFSET            8

osal_task *g_rcu_task_handle = NULL;

#if defined(CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER)
static void ssaps_server_read_request_cbk(uint8_t server_id, uint16_t conn_id, ssaps_req_read_cb_t *read_cb_para,
                                          errcode_t status)
{
    unused(server_id);
    unused(conn_id);
    unused(read_cb_para);
    unused(status);
}
#if defined(CONFIG_RCU_MASS_PRODUCTION_TEST)
static void rcu_private_sle_frame_dispatch(uint8_t *value, uint16_t len)
{
    private_frame_t private_frame = { 0 };
    if (value == NULL || len == 0) {
        return;
    }
 
    (void)memcpy_s(&private_frame, sizeof(private_frame_t), value, sizeof(private_frame_t));
 
    if (private_frame.flag != PRIVATE_FRAME_FLAG) {
        return;
    }
 
    switch (private_frame.service_id) {
        case PRIVATE_FRAME_SERVICE_FACTORY_TEST:
            rcu_mp_test_handler(&private_frame, value + sizeof(private_frame_t), private_frame.body_len);
            break;
 
        default:
            break;
    }
}
#endif

static void ssaps_server_write_request_cbk(uint8_t server_id, uint16_t conn_id, ssaps_req_write_cb_t *write_cb_para,
                                           errcode_t status)
{
    unused(server_id);
    unused(conn_id);
    unused(write_cb_para);
    unused(status);
#if defined(CONFIG_RCU_MASS_PRODUCTION_TEST)
    if ((write_cb_para->length > 0) && write_cb_para->value) {
        rcu_private_sle_frame_dispatch((uint8_t *)write_cb_para->value, write_cb_para->length);
    }
#endif
}
#endif /* CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER */


#if defined(CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER)
static void vdt_set_phy_param(void)
{
    sle_set_phy_t param = { 0 };
    param.tx_format = 1;         /* 无线帧类型2 0 :无线帧类型1(GFSK); 1:无线帧类型2(QPSK) */
    param.rx_format = 1;         /* 无线帧类型2 */
    param.tx_phy = 0;            /* 0 1M 1 2M 2 4M */
    param.rx_phy = 0;
    param.tx_pilot_density = 0;  /* 导频密度4:1 */
    param.rx_pilot_density = 0;  /* 导频密度4:1 */
    param.g_feedback = 0;
    param.t_feedback = 0;
    if (sle_set_phy_param(0, &param) != 0) {
        return;
    }
    app_print("vdt_set_phy_param ok!\r\n");
}
#endif
void rcu_msg_sle_adv_enable(void)
{
    osal_printk("[rcu]sle adv enable.\n");
}

void rcu_msg_sle_adv_disable(void)
{
    osal_printk("[rcu]sle adv disable.\n");
}

void rcu_msg_sle_connected(void)
{
    osal_printk("[rcu]sle connected.\n");
}

void rcu_msg_sle_disconnected(void)
{
    osal_printk("[rcu]sle disconnected.\n");
}

void rcu_msg_sle_conn_param_updataed(void)
{
    osal_printk("[rcu]sle connect param updataed.\n");
}

static void *rcu_task(const char *arg)
{
    unused(arg);
    uint32_t rcu_msg_size = sizeof(app_msg_data_t);
    app_msg_data_t rcu_msg_data;
    while (1) {
        if (app_receive_msgqueue((uint8_t *)&rcu_msg_data, &rcu_msg_size) != OSAL_SUCCESS) {
            continue;
        }
        switch (rcu_msg_data.type) {
            case RCU_MSG_SLE_ADV_ENABLE:
                rcu_msg_sle_adv_enable();
                break;

            case RCU_MSG_SLE_ADV_DISABLE:
                rcu_msg_sle_adv_disable();
                break;

            case RCU_MSG_SLE_CONNECTED:
                rcu_msg_sle_connected();
                break;

            case RCU_MSG_SLE_DISCONNECTED:
                rcu_msg_sle_disconnected();
                break;

            case RCU_MSG_SLE_CONN_PARAM_UPDATAED:
                rcu_msg_sle_conn_param_updataed();
                break;
            case KEY_DOWN_EVENT_MSG:
            case KEY_UP_EVENT_MSG:
            case KEY_HOLD_LONG_EVENT_MSG:
                keyevent_process(rcu_msg_data.buffer, rcu_msg_data.length, rcu_msg_data.type);
                break;

            default:
                break;
        }
    }

    return NULL;
}

#if defined(CONFIG_BT_UPG_ENABLE) || defined(CONFIG_SLE_UPG_ENABLE)
static errcode_t ota_upgrade_state_notify_cb(ota_upgrade_state_t upgrade_state, errcode_t upgrade_errcode)
{
    osal_printk("[OTA]upgrade_state = 0x%x.upgrade_errcode = 0x%x.\r\n", upgrade_state, upgrade_errcode);
    errcode_t ret = ERRCODE_SUCC;
    switch (upgrade_state) {
        case OTA_UPGRADE_STATE_PERMIT:
            /* 电量判断，如果电量低，不升级 返回ERRCODE_UPG_REJECT_LOW_POWER  */
            break;
        case OTA_UPGRADE_STATE_START:
#if defined(CONFIG_PM_SYS_SUPPORT)
            /* 睡眠否决票 uapi_pm_add_sleep_veto */
            ret = uapi_pm_set_state_trans_duration(0xFFFFFFFF, 0xFFFFFFFF);
            uapi_pm_wkup_process(0);
#if defined(CONFIG_SLE_UPG_ENABLE)
            sle_rcu_set_ota_stage(SLE_RCU_OTA_RUNNING);
#endif  /* CONFIG_SLE_UPG_ENABLE */
#endif
            break;
        case OTA_UPGRADE_STATE_END:
#if defined(CONFIG_PM_SYS_SUPPORT)
            /* 移除睡眠否决票uapi_pm_remove_sleep_veto */
            uapi_pm_work_state_reset();
            ret = uapi_pm_set_state_trans_duration(DURATION_MS_OF_WORK_TO_STANDBY, DURATION_MS_OF_STANDBY_TO_SLEEP);
#if defined(CONFIG_SLE_UPG_ENABLE)
            sle_rcu_set_ota_stage(SLE_RCU_OTA_STOP);
#endif  /* CONFIG_SLE_UPG_ENABLE */
#endif
            break;
        default:
            break;
    }
    return ret;
}
#endif

static void rcu_entry(void)
{
    app_timer_init();
    uapi_timer_init();
    if (uapi_clock_control(CLOCK_CLKEN_ID_MCU_CORE, CLOCK_FREQ_LEVEL_HIGH) == ERRCODE_SUCC) {
        osal_printk("Config succ.\r\n");
    }
#if defined(CONFIG_SAMPLE_SUPPORT_BLE_RCU_SERVER)
    ble_rcu_server_init();
#endif /* CONFIG_SAMPLE_SUPPORT_BLE_RCU_SERVER */

#if defined(CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER)
    /* sle server init */
    sle_rcu_server_init(ssaps_server_read_request_cbk, ssaps_server_write_request_cbk);
    vdt_set_phy_param();
#endif

#if defined(CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER) || defined(CONFIG_SAMPLE_SUPPORT_BLE_RCU_SERVER)
    vdt_codec_init();
#endif

/* open low power */
#if defined(CONFIG_PM_SYS_SUPPORT)
    rcu_low_power_init();
#endif
    app_conn_info_init();
    app_create_msgqueue();
    app_keyscan_init();
#if defined(CONFIG_BT_UPG_ENABLE) || defined(CONFIG_SLE_UPG_ENABLE)
    ota_upgrade_callback_register(ota_upgrade_state_notify_cb);
#endif
    osal_kthread_lock();
    g_rcu_task_handle = osal_kthread_create((osal_kthread_handler)rcu_task, 0, "SleRcuSrverTask",
                                            RCU_TASK_STACK_SIZE);
    if (g_rcu_task_handle != NULL) {
        osal_kthread_set_priority(g_rcu_task_handle, SLE_RCU_SERVER_TASK_PRIO);
    }
    osal_kthread_unlock();
}

void app_main(void *unused)
{
    UNUSED(unused);
    hal_reboot_clear_history();
    system_boot_reason_print();
    system_boot_reason_process();
#if (USE_COMPRESS_LOG_INSTEAD_OF_SDT_LOG == NO)
    log_exception_dump_reg_check();
#endif
#if defined(CONFIG_SAMPLE_ENABLE)
    app_tasks_init();
#endif
#ifdef OS_DFX_SUPPORT
    print_os_task_id_and_name();
#endif
}

/* Run the rcu_entry. */
app_run(rcu_entry);