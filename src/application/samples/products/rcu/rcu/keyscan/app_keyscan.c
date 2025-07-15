/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * Description: APP Keyscan Source File. \n
 *
 * History: \n
 * 2024-05-16, Create file. \n
 */

#include "securec.h"
#include "soc_osal.h"
#include "app_msg_queue.h"
#include "app_timer.h"
#include "pdm.h"
#include "hal_dma.h"
#include "keyscan.h"
#include "keyscan_porting.h"
#include "osal_mutex.h"
#include "adc.h"
#include "adc_porting.h"
#include "pinctrl.h"
#include "common_def.h"
#include "app_init.h"
#include "watchdog.h"
#include "gpio.h"
#include "pm_clock.h"
#include "hal_adc.h"
#include "ir_study.h"
#if defined(CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER)
#include "sle_rcu_server.h"
#include "sle_rcu_server_adv.h"
#include "sle_common.h"
#include "sle_connection_manager.h"
#include "sle_vdt_pdm.h"
#include "sle_device_discovery.h"
#include "sle_service_hids.h"
#endif
/* CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER */
#if defined(CONFIG_SAMPLE_SUPPORT_BLE_RCU_SERVER)
#include "ble_rcu_server.h"
#include "ble_rcu_server_adv.h"
#include "ble_hid_rcu_server.h"
#endif
/* CONFIG_SAMPLE_SUPPORT_BLE_RCU_SERVER */
#include "bts_le_gap.h"
#if defined(CONFIG_PM_SYS_SUPPORT)
#include "ulp_gpio.h"
#include "gpio.h"
#include "pm_sys.h"
#include "app_ulp.h"
#endif
#include "app_status.h"
#include "app_common.h"
#if defined(CONFIG_SAMPLE_SUPPORT_IR)
#include "ir_nec.h"
#include "ir_porting.h"
#include "chip_core_irq.h"
#endif

#include "hal_reboot.h"
#include "app_keyscan.h"
#if defined(CONFIG_RCU_MASS_PRODUCTION_TEST)
#include "rcu_mp_test.h"
#endif

combine_key_e g_combine_key_flag = COMBINE_KEY_FLAG_NONE;
osal_mutex g_key_process;

#define SLE_ADV_HANDLE_DEFAULT             1

static bool g_keystate_down = 0;
static bool g_check_consumer_send = false;
static connect_device_info_t g_con_info[NONE_DEVICE] = {0};
static uint32_t g_current_control_obj = NONE_DEVICE;

#if defined(CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER) || defined(CONFIG_SAMPLE_SUPPORT_BLE_RCU_SERVER)
static bool g_check_mouse_send = false;
static uint32_t g_keyboard_send_count = 0;
static bool g_check_keyboard_send = false;
#endif
/* CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER */

#if defined(CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER)
#define RING_BUFFER_NUMBER 4
uint8_t g_sle_pdm_buffer[CONFIG_USB_UAC_MAX_RECORD_SIZE] = {0};
uint8_t g_write_buffer_node = 0;
uint8_t g_read_buffer_node = 0;
static uint32_t g_rcu_dma_channel = 0;
static uint32_t g_pdm_dma_data0[CONFIG_USB_PDM_TRANSFER_LEN_BY_DMA] = {0};
static uint32_t g_pdm_dma_data1[CONFIG_USB_PDM_TRANSFER_LEN_BY_DMA] = {0};
static uint32_t g_pdm_dma_data2[CONFIG_USB_PDM_TRANSFER_LEN_BY_DMA] = {0};
static uint32_t g_pdm_dma_data3[CONFIG_USB_PDM_TRANSFER_LEN_BY_DMA] = {0};
uint32_t *g_pdm_dma_data[RING_BUFFER_NUMBER] = {g_pdm_dma_data0, g_pdm_dma_data1, g_pdm_dma_data2, g_pdm_dma_data3};
#endif

#if defined(CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER) || defined(CONFIG_SAMPLE_SUPPORT_BLE_RCU_SERVER)
typedef struct usb_hid_mouse_report {
    mouse_key_t key;
    int8_t x;     /* A negative value indicates that the mouse moves left. */
    int8_t y;     /* A negative value indicates that the mouse moves up. */
    int8_t wheel; /* A negative value indicates that the wheel roll forward. */
} usb_hid_mouse_report_t;

typedef struct usb_hid_keyboard_report {
    uint8_t special_key; /*!< 8bit special key(Lctrl Lshift Lalt Lgui Rctrl Rshift Ralt Rgui) */
    uint8_t reserve;
    uint8_t key[USB_HID_MAX_KEY_LENTH]; /*!< Normal key */
} usb_hid_keyboard_report_t;

typedef struct usb_hid_consumer_report {
    uint8_t comsumer_key0;
    uint8_t comsumer_key1;
} usb_hid_consumer_report_t;
#endif
/* CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER */

#if defined(CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER)
static usb_hid_mouse_report_t g_hid_sle_mouse_report;
static usb_hid_keyboard_report_t g_hid_sle_keyboard_report;
static usb_hid_consumer_report_t g_hid_sle_consumer_report;
#endif
/* CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER */

#if defined(CONFIG_SAMPLE_SUPPORT_BLE_RCU_SERVER)
static usb_hid_mouse_report_t g_hid_ble_mouse_report;
static usb_hid_keyboard_report_t g_hid_ble_keyboard_report;
static usb_hid_consumer_report_t g_hid_ble_consumer_report;
#endif
/* CONFIG_SAMPLE_SUPPORT_BLE_RCU_SERVER */

static const key_config_t g_menu_key_map[RCU_KEY_MAX] = {
    {RCU_KEY_NON,            0x00, RCU_KEYBOARD_KEY, 0x00},
    {RCU_KEY_POWER,          0x66, RCU_KEYBOARD_KEY, 0xDC},
    {RCU_KEY_LIVE_BROADCAST, 0x3D, RCU_KEYBOARD_KEY, 0x3D},
    {RCU_KEY_OTT,            0x4A, RCU_KEYBOARD_KEY, 0x88},
    {RCU_KEY_HOME,           0x4A, RCU_KEYBOARD_KEY, 0x88},
    {RCU_KEY_OK,             0x28, RCU_KEYBOARD_KEY, 0xCE},
    {RCU_KEY_BACK,           0x29, RCU_KEYBOARD_KEY, 0x95},
    {RCU_KEY_MENU,           0x65, RCU_KEYBOARD_KEY, 0x82},
    {RCU_KEY_UP,             0x52, RCU_KEYBOARD_KEY, 0xCA},
    {RCU_KEY_DOWN,           0x51, RCU_KEYBOARD_KEY, 0xD2},
    {RCU_KEY_LEFT,           0x50, RCU_KEYBOARD_KEY, 0x99},
    {RCU_KEY_RIGHT,          0x4F, RCU_KEYBOARD_KEY, 0xC1},
    {RCU_KEY_SOURCE,         0x57, RCU_KEYBOARD_KEY, 0x57},
    {RCU_KEY_VOICE,          0x3E, RCU_KEYBOARD_KEY, 0xE5},
    {RCU_KEY_VOLUME_UP,      0xE9, RCU_CONSUMER_KEY, 0x80},
    {RCU_KEY_VOLUME_DOWN,    0xEA, RCU_CONSUMER_KEY, 0x81},
    {RCU_KEY_MUTE,           0xE2, RCU_CONSUMER_KEY, 0x9C},
    {RCU_KEY_SET_UP,         0xEB, RCU_KEYBOARD_KEY, 0x8D},
    {RCU_KEY_CHANNEL_UP,     0x4B, RCU_KEYBOARD_KEY, 0x85},
    {RCU_KEY_CHANNEL_DOWN,   0x4E, RCU_KEYBOARD_KEY, 0x86},
    {RCU_KEY_LOOK_BACK,      0x91, RCU_KEYBOARD_KEY, 0x37},
    {RCU_KEY_ONE,            0x1E, RCU_KEYBOARD_KEY, 0x92},
    {RCU_KEY_TWO,            0x1F, RCU_KEYBOARD_KEY, 0x93},
    {RCU_KEY_THREE,          0x20, RCU_KEYBOARD_KEY, 0xCC},
    {RCU_KEY_FOUR,           0x21, RCU_KEYBOARD_KEY, 0x8E},
    {RCU_KEY_FIVE,           0x22, RCU_KEYBOARD_KEY, 0x8F},
    {RCU_KEY_SIX,            0x23, RCU_KEYBOARD_KEY, 0xC8},
    {RCU_KEY_SEVEN,          0x24, RCU_KEYBOARD_KEY, 0x8A},
    {RCU_KEY_EIGHT,          0x25, RCU_KEYBOARD_KEY, 0x8B},
    {RCU_KEY_NINE,           0x26, RCU_KEYBOARD_KEY, 0xC4},
    {RCU_KEY_ZERO,           0x27, RCU_KEYBOARD_KEY, 0x87}};

#if defined(CONFIG_KEYSCAN_USE_SIX_KEYS_TYPE)
static const uint8_t g_key_map[CONFIG_KEYSCAN_ENABLE_ROW][CONFIG_KEYSCAN_ENABLE_COL] = {
    {RCU_KEY_HOME, RCU_KEY_BACK},
    {RCU_KEY_MENU, RCU_KEY_VOLUME_UP},
    {RCU_KEY_VOLUME_DOWN, RCU_KEY_OK},
};
#endif /* CONFIG_KEYSCAN_USE_SIX_KEYS_TYPE */

#if defined(CONFIG_KEYSCAN_USER_CONFIG_TYPE)
static const uint8_t g_key_map[CONFIG_KEYSCAN_ENABLE_ROW][CONFIG_KEYSCAN_ENABLE_COL] = {
    {RCU_KEY_POWER, RCU_KEY_BACK, RCU_KEY_VOLUME_UP, RCU_KEY_ONE, RCU_KEY_FOUR, RCU_KEY_SEVEN, RCU_KEY_LEFT},
    {RCU_KEY_POWER, RCU_KEY_HOME, RCU_KEY_VOLUME_DOWN, RCU_KEY_TWO, RCU_KEY_FIVE, RCU_KEY_EIGHT, RCU_KEY_UP},
    {RCU_KEY_MAX, RCU_KEY_MENU, RCU_KEY_VOICE, RCU_KEY_THREE, RCU_KEY_SIX, RCU_KEY_NINE, RCU_KEY_OK},
    {RCU_KEY_LIVE_BROADCAST, RCU_KEY_MAX, RCU_KEY_CHANNEL_UP, RCU_KEY_MAX, RCU_KEY_MAX, RCU_KEY_ZERO, RCU_KEY_RIGHT},
    {RCU_KEY_OTT, RCU_KEY_MAX, RCU_KEY_CHANNEL_DOWN, RCU_KEY_MAX,
        RCU_KEY_LIVE_BROADCAST, RCU_KEY_LOOK_BACK, RCU_KEY_DOWN},
};
#endif /* CONFIG_KEYSCAN_USER_CONFIG_TYPE */

#define COMBINE_KEY_MAX 10
#define COMBINE_KEY_TYPE_INDEX 3

static const uint8_t combine_key[COMBINE_KEY_MAX][4] = {
    // 组合键值
    {RCU_KEY_LIVE_BROADCAST, RCU_KEY_VOLUME_DOWN, 0x0, COMBINE_KEY_FLAG_IR_TV_CONNECT},              // 连电视
    {RCU_KEY_OTT, RCU_KEY_CHANNEL_DOWN, 0x0, COMBINE_KEY_FLAG_IR_LIVE_BROADCAST_CONNECT},            // 连机顶盒
    {RCU_KEY_LEFT, RCU_KEY_RIGHT, 0x0, COMBINE_KEY_FLAG_IR_LEARN},                                   // 红外学习
    {RCU_KEY_LOOK_BACK, RCU_KEY_LIVE_BROADCAST, 0x0, COMBINE_KEY_FLAG_UNPAIR},                       // 取消配对
#if defined(CONFIG_RCU_MASS_PRODUCTION_TEST)
    {RCU_KEY_MENU, RCU_KEY_UP,    0X0, COMBINE_KEY_FLAG_TEST_STATION_01},
    {RCU_KEY_MENU, RCU_KEY_DOWN,  0X0, COMBINE_KEY_FLAG_TEST_STATION_02},
    {RCU_KEY_MENU, RCU_KEY_RIGHT, 0X0, COMBINE_KEY_FLAG_TEST_STATION_03},
    {RCU_KEY_OK,   RCU_KEY_UP, 0X0, COMBINE_KEY_FLAG_TEST_STATION_04},
    {RCU_KEY_OK,   RCU_KEY_DOWN, 0X0, COMBINE_KEY_FLAG_TEST_STATION_05},
    {RCU_KEY_OK,   RCU_KEY_RIGHT, 0X0, COMBINE_KEY_FLAG_TEST_STATION_06},
#endif
};

static uint8_t get_active_con_id(void)
{
    return g_con_info[g_current_control_obj].con_id;
}

static void set_combine_key_flag(combine_key_e flag)
{
    g_combine_key_flag = flag;
}

static combine_key_e get_combine_key_flag(void)
{
    return g_combine_key_flag;
}

static bool is_key_match(uint8_t template_key, uint8_t *key_buffer, uint8_t key_num)
{
    for (int i = 0; i < key_num; i++) {
        if (template_key == key_buffer[i]) {
            return true;
        }
    }

    return false;
}

#if defined(CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER)
static void rcu_vdt_dma_transfer_done_callback(uint8_t intr, uint8_t channel, uintptr_t arg);
static void rcu_amic_init(void);
static void rcu_amic_deinit(void);

static void sle_rcu_consumer_send_report(uint8_t key_value)
{
    if (memset_s(&g_hid_sle_consumer_report, sizeof(g_hid_sle_consumer_report), 0, sizeof(g_hid_sle_consumer_report)) !=
        EOK) {
        return;
    }

    g_hid_sle_consumer_report.comsumer_key0 = g_menu_key_map[key_value].usage_id & 0xFF;
    g_hid_sle_consumer_report.comsumer_key1 = g_menu_key_map[key_value].usage_id >> RCU_CONSUMER_KEY_OFFSET;
    sle_rcu_server_send_report_by_handle(
        (uint8_t *)(uintptr_t)&g_hid_sle_consumer_report, sizeof(usb_hid_consumer_report_t), get_active_con_id());
}

static void sle_rcu_keyboard_send_report(uint8_t key_value, bool send_flag)
{
    if ((key_value != 0) && (g_keyboard_send_count < USB_HID_MAX_KEY_LENTH)) {
        g_hid_sle_keyboard_report.key[g_keyboard_send_count++] = g_menu_key_map[key_value].usage_id;
    }
    if (send_flag) {
        sle_rcu_server_send_report_by_handle(
            (uint8_t *)(uintptr_t)&g_hid_sle_keyboard_report, sizeof(usb_hid_keyboard_report_t), get_active_con_id());

        (void)memset_s(
            &g_hid_sle_keyboard_report, sizeof(g_hid_sle_keyboard_report), 0, sizeof(g_hid_sle_keyboard_report));
        g_keyboard_send_count = 0;
    }
}

static void sle_rcu_mouse_send_report(uint8_t key_value, bool send_flag)
{
    switch (key_value) {
        case RCU_KEY_RIGHT:
            g_hid_sle_mouse_report.x = 0x10;
            break;
        case RCU_KEY_LEFT:
            g_hid_sle_mouse_report.x = 0xF0;
            break;
        case RCU_KEY_DOWN:
            g_hid_sle_mouse_report.y = 0x10;
            break;
        case RCU_KEY_UP:
            g_hid_sle_mouse_report.y = 0xF0;
            break;
        default:
            break;
    }
    if (send_flag) {
        sle_rcu_server_send_report_by_handle(
            (uint8_t *)(uintptr_t)&g_hid_sle_mouse_report, sizeof(usb_hid_mouse_report_t), get_active_con_id());
        if (memset_s(&g_hid_sle_mouse_report, sizeof(g_hid_sle_mouse_report), 0, sizeof(g_hid_sle_mouse_report)) !=
            EOK) {
            return;
        }
    }
}

static void sle_rcu_send_end(void)
{
    if (g_check_consumer_send) {
        if (memset_s(&g_hid_sle_consumer_report, sizeof(g_hid_sle_consumer_report), 0,
            sizeof(g_hid_sle_consumer_report)) != EOK) {
            return;
        }
        sle_rcu_server_send_report_by_handle(
            (uint8_t *)(uintptr_t)&g_hid_sle_consumer_report, sizeof(usb_hid_consumer_report_t), get_active_con_id());
        g_check_consumer_send = false;
    }
    if (g_check_mouse_send) {
        if (memset_s(&g_hid_sle_mouse_report, sizeof(g_hid_sle_mouse_report), 0, sizeof(g_hid_sle_mouse_report)) !=
            EOK) {
            return;
        }
        sle_rcu_server_send_report_by_handle(
            (uint8_t *)(uintptr_t)&g_hid_sle_mouse_report, sizeof(usb_hid_mouse_report_t), get_active_con_id());
        g_check_mouse_send = false;
    }
    if (g_check_keyboard_send) {
        if (memset_s(&g_hid_sle_keyboard_report, sizeof(g_hid_sle_keyboard_report), 0,
            sizeof(g_hid_sle_keyboard_report)) != EOK) {
            return;
        }
        sle_rcu_server_send_report_by_handle(
            (uint8_t *)(uintptr_t)&g_hid_sle_keyboard_report, sizeof(usb_hid_keyboard_report_t), get_active_con_id());
        g_check_keyboard_send = false;
    }
}

static void rcu_amic_deinit(void)
{
    sle_low_latency_set_em_data(get_active_con_id(), 0);
    uapi_dma_end_transfer(g_rcu_dma_channel);
    uapi_dma_close();
    uapi_dma_deinit();
    uapi_adc_power_en(AFE_AMIC_MODE, false);
    uapi_adc_deinit();
    uapi_pdm_stop();
    uapi_pdm_deinit();
}

static void sle_vdt_adc_set_io(pin_t pin)
{
#if defined(CONFIG_PINCTRL_SUPPORT_IE)
    /* ADC管脚无需配置IE使能且管脚默认IE为0，为防止用户修改IE，特在此将IE配置为0 */
    uapi_pin_set_ie(pin, PIN_IE_0);
#endif
    uapi_pin_set_mode(pin, 0);
    uapi_gpio_set_dir(pin, GPIO_DIRECTION_INPUT);
    uapi_pin_set_pull(pin, PIN_PULL_NONE);
}

static void sle_vdt_adc_init(void)
{
    uapi_pin_init();
    uapi_gpio_init();

    sle_vdt_adc_set_io(CONFIG_ADC_USE_PIN1);
    sle_vdt_adc_set_io(CONFIG_ADC_USE_PIN2);
    uapi_adc_init(ADC_CLOCK_NONE);
    uapi_adc_power_en(AFE_AMIC_MODE, true);
    uapi_adc_open_differential_channel(ADC_GADC_CHANNEL7, ADC_GADC_CHANNEL6);
    adc_calibration(AFE_AMIC_MODE, true, true, true);

    return;
}

static void rcu_amic_init(void)
{
    sle_low_latency_set_em_data(get_active_con_id(), 1);

    sle_vdt_adc_init();
    if (sle_vdt_pdm_init() != 0) {
        osal_printk("%s Init the PDM fail.\r\n", SLE_VDT_SERVER_LOG);
    }
    if (uapi_pdm_start() != ERRCODE_SUCC) {
        osal_printk("%s Start the PDM fail.\r\n", SLE_VDT_SERVER_LOG);
    }

    if (rcu_pdm_start_dma_transfer(g_pdm_dma_data[0], rcu_vdt_dma_transfer_done_callback) != 0) {
        osal_printk("rcu_pdm_start_dma_transfer fail!\r\n");
        return;
    }
}

static void rcu_vdt_dma_transfer_restart(void)
{
    g_write_buffer_node = (g_write_buffer_node + 1) % RING_BUFFER_NUMBER;
    if (rcu_pdm_start_dma_transfer(g_pdm_dma_data[g_write_buffer_node],
        rcu_vdt_dma_transfer_done_callback) != 0) {
        return;
    }
}

static void rcu_vdt_dma_transfer_done_callback(uint8_t intr, uint8_t channel, uintptr_t arg)
{
    unused(channel);
    unused(arg);

    switch (intr) {
        case HAL_DMA_INTERRUPT_TFR:
            rcu_vdt_dma_transfer_restart();
            break;
        case HAL_DMA_INTERRUPT_ERR:
            osal_printk("%s DMA transfer error.\r\n", SLE_VDT_SERVER_LOG);
            break;
        default:
            break;
    }
}
#endif
/* CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER */

#if defined(CONFIG_SAMPLE_SUPPORT_BLE_RCU_SERVER)
static void ble_rcu_consumer_send_report(uint8_t key_value)
{
    if (memset_s(&g_hid_ble_consumer_report, sizeof(g_hid_ble_consumer_report), 0, sizeof(g_hid_ble_consumer_report)) !=
        EOK) {
        return;
    }
    g_hid_ble_consumer_report.comsumer_key0 = g_menu_key_map[key_value].usage_id & 0xFF;
    g_hid_ble_consumer_report.comsumer_key1 = g_menu_key_map[key_value].usage_id >> RCU_CONSUMER_KEY_OFFSET;
    ble_hid_rcu_server_send_consumer_input_report_by_uuid(
        (uint8_t *)(uintptr_t)&g_hid_ble_consumer_report, sizeof(usb_hid_consumer_report_t), get_active_con_id());
}

static void ble_rcu_keyboard_send_report(uint8_t key_value, bool send_flag)
{
    if (key_value != 0) {
        g_hid_ble_keyboard_report.key[g_keyboard_send_count++] = g_menu_key_map[key_value].usage_id;
    }
    if (send_flag) {
        ble_hid_rcu_server_send_keyboard_input_report_by_uuid(
            (uint8_t *)(uintptr_t)&g_hid_ble_keyboard_report, sizeof(usb_hid_keyboard_report_t), get_active_con_id());
        if (memset_s(&g_hid_ble_keyboard_report, sizeof(g_hid_ble_keyboard_report), 0,
            sizeof(g_hid_ble_keyboard_report)) != EOK) {
            g_keyboard_send_count = 0;
            return;
        }
        g_keyboard_send_count = 0;
    }
}

static void ble_rcu_mouse_send_report(uint8_t key_value, bool send_flag)
{
    switch (key_value) {
        case RCU_KEY_RIGHT:
            g_hid_ble_mouse_report.x = 0x10;
            break;
        case RCU_KEY_LEFT:
            g_hid_ble_mouse_report.x = 0xF0;
            break;
        case RCU_KEY_DOWN:
            g_hid_ble_mouse_report.y = 0x10;
            break;
        case RCU_KEY_UP:
            g_hid_ble_mouse_report.y = 0xF0;
            break;
        default:
            break;
    }
    if (send_flag) {
        ble_hid_rcu_server_send_mouse_input_report_by_uuid(
            (uint8_t *)(uintptr_t)&g_hid_ble_mouse_report, sizeof(usb_hid_mouse_report_t), get_active_con_id());
        if (memset_s(&g_hid_ble_mouse_report, sizeof(g_hid_ble_mouse_report), 0, sizeof(g_hid_ble_mouse_report)) !=
            EOK) {
            return;
        }
    }
}

static void ble_rcu_send_end(void)
{
    if (g_check_consumer_send) {
        if (memset_s(&g_hid_ble_consumer_report, sizeof(g_hid_ble_consumer_report), 0,
            sizeof(g_hid_ble_consumer_report)) != EOK) {
            return;
        }
        ble_hid_rcu_server_send_consumer_input_report_by_uuid(
            (uint8_t *)(uintptr_t)&g_hid_ble_consumer_report, sizeof(usb_hid_consumer_report_t), get_active_con_id());
        g_check_consumer_send = false;
    }
    if (g_check_mouse_send) {
        if (memset_s(&g_hid_ble_mouse_report, sizeof(g_hid_ble_mouse_report), 0, sizeof(g_hid_ble_mouse_report)) !=
            EOK) {
            return;
        }
        ble_hid_rcu_server_send_mouse_input_report_by_uuid(
            (uint8_t *)(uintptr_t)&g_hid_ble_mouse_report, sizeof(usb_hid_mouse_report_t), get_active_con_id());
        g_check_mouse_send = false;
    }
    if (g_check_keyboard_send) {
        if (memset_s(&g_hid_ble_keyboard_report, sizeof(g_hid_ble_keyboard_report), 0,
            sizeof(g_hid_ble_keyboard_report)) != EOK) {
            return;
        }
        ble_hid_rcu_server_send_keyboard_input_report_by_uuid(
            (uint8_t *)(uintptr_t)&g_hid_ble_keyboard_report, sizeof(usb_hid_keyboard_report_t), get_active_con_id());
        g_check_keyboard_send = false;
    }
}
#endif
/* CONFIG_SAMPLE_SUPPORT_BLE_RCU_SERVER */

#if defined(CONFIG_SAMPLE_SUPPORT_BLE_RCU_SERVER) || defined(CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER)
static void rcu_consumer_send_report(uint8_t key_value)
{
    if (g_current_control_obj == TV) {
#if defined(CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER)
        sle_rcu_consumer_send_report(key_value);
#endif
        /* CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER */
    } else {
#if defined(CONFIG_SAMPLE_SUPPORT_BLE_RCU_SERVER)
        ble_rcu_consumer_send_report(key_value);
#endif
        /* CONFIG_SAMPLE_SUPPORT_BLE_RCU_SERVER */
    }
    g_check_consumer_send = true;
}

static void rcu_mouse_and_keyboard_send_report(uint8_t key_value, bool is_mouse)
{
    if (g_current_control_obj == TV) {
#if defined(CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER)
        if (is_mouse) {
            sle_rcu_mouse_send_report(key_value, false);
            g_check_mouse_send = true;
        } else {
            sle_rcu_keyboard_send_report(key_value, false);
            g_check_keyboard_send = true;
        }
#endif
        /* CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER */
    } else {
#if defined(CONFIG_SAMPLE_SUPPORT_BLE_RCU_SERVER)
        if (is_mouse) {
            ble_rcu_mouse_send_report(key_value, false);
            g_check_mouse_send = true;
        } else {
            ble_rcu_keyboard_send_report(key_value, false);
            g_check_keyboard_send = true;
        }
#endif
        /* CONFIG_SAMPLE_SUPPORT_BLE_RCU_SERVER */
    }
}
#endif

static void rcu_and_ir_send_report(uint8_t key_value)
{
    unused(key_value);
#if defined(CONFIG_SAMPLE_SUPPORT_IR)
    uapi_pin_set_mode(S_MGPIO4, HAL_PIO_FUNC_GPIO);
    uapi_gpio_set_dir(S_MGPIO4, GPIO_DIRECTION_INPUT);
    uapi_pin_set_pull(S_MGPIO4, PIN_PULL_UP);
    uapi_pin_set_mode(S_MGPIO5, HAL_PIO_FUNC_GPIO);
    uapi_gpio_set_dir(S_MGPIO5, GPIO_DIRECTION_OUTPUT);
    uapi_gpio_set_val(S_MGPIO5, GPIO_LEVEL_HIGH);
    ir_nec_send(IR_NEC_USER_CODE, g_menu_key_map[key_value].ir_value);
#endif /* CONFIG_SAMPLE_SUPPORT_IR */
}

static void rcu_mouse_and_keyboard_send_start(void)
{
    if (g_current_control_obj == TV) {
#if defined(CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER)
        if (g_check_mouse_send) {
            sle_rcu_mouse_send_report(0, true);
        }
        if (g_check_keyboard_send) {
            sle_rcu_keyboard_send_report(0, true);
        }
#endif
        /* CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER */
    } else {
#if defined(CONFIG_SAMPLE_SUPPORT_BLE_RCU_SERVER)
        if (g_check_mouse_send) {
            ble_rcu_mouse_send_report(0, true);
        }
        if (g_check_keyboard_send) {
            ble_rcu_keyboard_send_report(0, true);
        }
#endif
        /* CONFIG_SAMPLE_SUPPORT_BLE_RCU_SERVER */
    }
}

static void rcu_send_end(void)
{
#if defined(CONFIG_PM_SYS_SUPPORT)
    uapi_pm_work_state_reset();
#endif
    if (g_current_control_obj == TV) {
#if defined(CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER)
        sle_rcu_send_end();
#endif
        /* CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER */
    } else {
#if defined(CONFIG_SAMPLE_SUPPORT_BLE_RCU_SERVER)
        ble_rcu_send_end();
#endif
        /* CONFIG_SAMPLE_SUPPORT_BLE_RCU_SERVER */
    }
    if (g_keystate_down) {
#if defined(CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER)
        rcu_amic_deinit();
#endif
        g_keystate_down = false;
    }
}

#if defined(CONFIG_SAMPLE_SUPPORT_IR) && defined(CONFIG_SAMPLE_SUPPORT_IR_STUDY)
void app_uapi_ir_study_start(uint8_t key_value)
{
    uapi_pin_set_mode(S_MGPIO6, HAL_PIO_FUNC_GPIO);
    uapi_gpio_set_dir(S_MGPIO6, GPIO_DIRECTION_OUTPUT);
    uapi_gpio_set_val(S_MGPIO6, GPIO_LEVEL_LOW);
    uapi_pin_set_mode(S_MGPIO5, HAL_PIO_FUNC_GPIO);
    uapi_gpio_set_dir(S_MGPIO5, GPIO_DIRECTION_OUTPUT);
    uapi_gpio_set_val(S_MGPIO5, GPIO_LEVEL_LOW);

    uapi_ir_study_start(key_value);
}
#else
void app_uapi_ir_study_start(uint8_t key_value)
{
    unused(key_value);
}
#endif

void app_ir_key_process(uint8_t key_value)
{
    if (get_rcu_mode() == RCU_MODE_IR_STUDY) {
        app_uapi_ir_study_start(g_menu_key_map[key_value].ir_value);
    }
}

static bool active_device_is_connect(void)
{
#if defined(CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER)
    if ((g_current_control_obj == TV) && (g_con_info[TV].state != SLE_ACB_STATE_CONNECTED)) {
        return false;
    }
#endif

#if defined(CONFIG_SAMPLE_SUPPORT_BLE_RCU_SERVER)
    if ((g_current_control_obj == SET_TOP_BOX) && (g_con_info[SET_TOP_BOX].state != GAP_BLE_STATE_CONNECTED)) {
        return false;
    }
#endif
    return true;
}

static void rcu_send_report(uint8_t key_value)
{
    // SLE/BLE发送
    uint8_t usage_page = g_menu_key_map[key_value].usage_page;
    if (usage_page == RCU_KEYBOARD_KEY) {
        rcu_mouse_and_keyboard_send_report(key_value, false);
    } else if (usage_page == RCU_CONSUMER_KEY) {
        rcu_consumer_send_report(key_value);
    }
}

/* 单键操作 */
static void one_key_process(uint8_t key_value)
{
    if (key_value >= RCU_KEY_MAX) {
        osal_printk("key value %d is out of range\r\n", key_value);
        return;
    }

    // 红外学习
    if (get_rcu_mode() == RCU_MODE_IR_STUDY) {
        app_ir_key_process(key_value);
        return;
    }
    // 当前选中的设备没有建立连接走红外发送
    if ((g_current_control_obj == NONE_DEVICE) || (!active_device_is_connect())) {
        rcu_and_ir_send_report(key_value);
        return;
    }

    switch (key_value) {
        case RCU_KEY_LIVE_BROADCAST:
            g_current_control_obj = TV;
            break;
        case RCU_KEY_OTT:
            g_current_control_obj = SET_TOP_BOX;
            break;
        case RCU_KEY_VOICE:
#if defined(CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER)
            rcu_amic_init();
#endif
            g_keystate_down = true;
            break;
        default:
            rcu_send_report(key_value);
            break;
    }
    rcu_mouse_and_keyboard_send_start();
}

static void key_up_process(void)
{
    rcu_send_end();
    app_timer_process_stop(TIME_CMD_KEY_HOLD_LONG);
}

static void key_down_process(key_t key)
{
    if (key.num == PRESS_NONE_KEY) {
        osal_printk("key down process key.num == 0 error!\r\n");
    } else if (key.num == PRESS_ONE_KEY) {
        one_key_process(key.key_value[0]);
    } else if (key.num == PRESS_TWO_KEY) {
        app_timer_process_stop(TIME_CMD_KEY_HOLD_LONG);
        /* 配对组合键 */
        for (int i = 0; i < COMBINE_KEY_MAX; i++) {
            bool tag_one = is_key_match(combine_key[i][0], key.key_value, key.num);
            bool tag_two = is_key_match(combine_key[i][1], key.key_value, key.num);
            if (tag_one && tag_two) {
                set_combine_key_flag(combine_key[i][COMBINE_KEY_TYPE_INDEX]);
                app_timer_process_start(TIME_CMD_KEY_HOLD_LONG, APP_HOLD_LONG_TIME);
                osal_printk("%d\r\n", combine_key[i][COMBINE_KEY_TYPE_INDEX]);
            }
        }
    }
}

#if defined(CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER)
void sle_notify_connect(uint16_t conn_id, uint8_t con_state)
{
    g_con_info[TV].device_type = TV;
    g_con_info[TV].con_id = conn_id;
    g_con_info[TV].state = con_state;
    g_current_control_obj = TV;
}
#endif

#if defined(CONFIG_SAMPLE_SUPPORT_BLE_RCU_SERVER)
void ble_notify_connect(uint16_t conn_id, uint8_t con_state)
{
    g_con_info[SET_TOP_BOX].device_type = SET_TOP_BOX;
    g_con_info[SET_TOP_BOX].con_id = conn_id;
    g_con_info[SET_TOP_BOX].state = con_state;
    g_current_control_obj = SET_TOP_BOX;
}
#endif

/**************************************************
 * 按键长按处理
 *
 **************************************************/

// 配对
static void key_handle_process_repairing_event(void)
{
    osal_printk("key_handle_process_repairing_event start!\r\n");
    app_globle_status_t status = get_app_globle_status();
    set_rcu_mode(RCU_MODE_ADV_SEND);
    if (status.rcu_mode == RCU_MODE_TEST_NO_SLEPP) {
        app_mode_reset();
    }
#if defined(CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER)
    if (g_current_control_obj == TV) {
        uint16_t sle_state = g_con_info[g_current_control_obj].state;
        if (sle_state == SLE_ACB_STATE_CONNECTED) {
            sle_remove_all_pairs();
        } else {
            sle_remove_all_pairs();
            sle_rcu_standby_to_work();
            app_timer_process_start(TIME_CMD_PAIR, APP_PAIR_TIME);
        }
    }
#endif

#if defined(CONFIG_SAMPLE_SUPPORT_BLE_RCU_SERVER)
    if (g_current_control_obj == SET_TOP_BOX) {
        uint16_t ble_state = g_con_info[g_current_control_obj].state;
        if (ble_state == GAP_BLE_STATE_CONNECTED) {
            gap_ble_remove_all_pairs();
        } else {
            gap_ble_remove_all_pairs();
            ble_rcu_standby_to_work();
            app_timer_process_start(TIME_BLE_CMD_PAIR, APP_BLE_PAIR_TIME);
        }
    }
#endif
}

// 解配
static void key_handle_process_unpairing_event(void)
{
    osal_printk("key_handle_process_unpairing_event start\r\n");
    app_globle_status_t status = get_app_globle_status();
    if (status.rcu_mode == RCU_MODE_TEST_NO_SLEPP) {
        app_mode_reset();
    }
#if defined(CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER)
    /* 断开连接 */
    if (g_con_info[TV].state == SLE_ACB_STATE_CONNECTED) {
        sle_rcu_standby_to_sleep();
    }

    /* 关闭广播。 */
    sle_stop_announce(SLE_ADV_HANDLE_DEFAULT);
    /* 删除所有配对信息。 */
    sle_remove_all_pairs();
    g_con_info[TV].state = SLE_ACB_STATE_DISCONNECTED;
#endif

#if defined(CONFIG_SAMPLE_SUPPORT_BLE_RCU_SERVER)
    /* 断开连接 */
    if (g_con_info[SET_TOP_BOX].state == GAP_BLE_STATE_CONNECTED) {
        ble_rcu_standby_to_sleep();
    }

    /* 关闭广播。 */
    gap_ble_stop_adv(BTH_GAP_BLE_ADV_HANDLE_DEFAULT);
    /* 删除所有配对信息。 */
    gap_ble_remove_all_pairs();
    g_con_info[SET_TOP_BOX].state = GAP_BLE_STATE_DISCONNECTED;
#endif
    g_current_control_obj = NONE_DEVICE;
    clear_rcu_mode(RCU_MODE_ADV_SEND);
}

// IR study
static void key_handle_process_ir_study_event(void)
{
    if (get_rcu_mode() != RCU_MODE_IR_STUDY) {
        set_rcu_mode(RCU_MODE_IR_STUDY);
        app_timer_process_start(TIME_CMD_IR_STUDY, APP_IR_STUDY_TIME);
        osal_printk("[ir_study] entry RCU_MODE_IR_STUDY\r\n");
    } else {
        app_timer_process_stop(TIME_CMD_IR_STUDY);
        clear_rcu_mode(RCU_MODE_IR_STUDY);
        osal_printk("[ir_study] exit RCU_MODE_IR_STUDY\r\n");
    }
}

static void key_hold_process(void)
{
    combine_key_e combine_key_flag = get_combine_key_flag();

    switch (combine_key_flag) {
#if defined(CONFIG_RCU_MASS_PRODUCTION_TEST)
        case COMBINE_KEY_FLAG_TEST_STATION_01:
        case COMBINE_KEY_FLAG_TEST_STATION_02:
        case COMBINE_KEY_FLAG_TEST_STATION_03:
        case COMBINE_KEY_FLAG_TEST_STATION_04:
        case COMBINE_KEY_FLAG_TEST_STATION_05:
        case COMBINE_KEY_FLAG_TEST_STATION_06:
            /* 关闭广播。 */
            sle_stop_announce(SLE_ADV_HANDLE_DEFAULT);
            /* 删除所有配对信息。 */
            sle_remove_all_pairs();
            rcu_mp_test_set_work_station(combine_key_flag);
            break;
#endif
        // 连电视
        case COMBINE_KEY_FLAG_IR_TV_CONNECT:
            g_current_control_obj = TV;
            g_con_info[TV].device_type = TV;
            key_handle_process_repairing_event();
            break;

        // 连机顶盒
        case COMBINE_KEY_FLAG_IR_LIVE_BROADCAST_CONNECT:
            g_current_control_obj = SET_TOP_BOX;
            g_con_info[SET_TOP_BOX].device_type = SET_TOP_BOX;
            key_handle_process_repairing_event();
            break;

        // 解配组合键
        case COMBINE_KEY_FLAG_UNPAIR:
            key_handle_process_unpairing_event();
            break;

        // IR study组合键
        case COMBINE_KEY_FLAG_IR_LEARN:
            key_handle_process_ir_study_event();
            break;

        default:
            break;
    }

    set_combine_key_flag(COMBINE_KEY_FLAG_NONE);
}

void keyevent_process(uint8_t *key_value, uint8_t key_num, APP_MSG_DATA_TYPE event)
{
    if (osal_mutex_lock(&g_key_process) == OSAL_SUCCESS) {
#if defined(CONFIG_PM_SYS_SUPPORT)
        uapi_pm_work_state_reset();
#endif
        app_timer_process_start(TIME_CMD_SLEEP_CHECK, APP_SLEEP_CHECK_TIME);
        if (event == KEY_DOWN_EVENT_MSG) {
            key_t temp_key;
            temp_key.num = (key_num < KEY_MAX_NUM ? key_num : KEY_MAX_NUM);
            memcpy_s(temp_key.key_value, KEY_MAX_NUM, key_value, KEY_MAX_NUM);
            key_down_process(temp_key);
        } else if (event == KEY_UP_EVENT_MSG) {
            key_up_process();
        } else if (event == KEY_HOLD_LONG_EVENT_MSG) {
            key_hold_process();
        }
        osal_mutex_unlock(&g_key_process);
    }
}

static int app_keyscan_callback(int key_num, uint8_t key_value[])
{
    app_msg_data_t msg;
    if (key_num == 0) {
        msg.type = KEY_UP_EVENT_MSG;
        memcpy_s(msg.buffer, APP_MSG_BUFFER_LEN, NULL, KEY_MAX_NUM);
        msg.length = 0;
#if defined(CONFIG_PM_SYS_SUPPORT)
        uapi_pm_set_state_trans_duration(DURATION_MS_OF_WORK_TO_STANDBY, DURATION_MS_OF_STANDBY_TO_SLEEP);
#endif
    } else {
#if defined(CONFIG_PM_SYS_SUPPORT)
        uapi_pm_set_state_trans_duration(0xFFFFFFFF, 0xFFFFFFFF);
#endif
        msg.type = KEY_DOWN_EVENT_MSG;
        memcpy_s(msg.buffer, APP_MSG_BUFFER_LEN, key_value, KEY_MAX_NUM);
        msg.length = key_num;
    }
    app_write_msgqueue(msg);
    return 1;
}

void app_keyscan_init(void)
{
    /* keyscan init */
    osal_mutex_init(&g_key_process);
#if defined(CONFIG_KEYSCAN_USER_CONFIG_TYPE)
    uint8_t user_gpio_map[CONFIG_KEYSCAN_ENABLE_ROW + CONFIG_KEYSCAN_ENABLE_COL] = {
        10, 11, 12, 13, 14, 21, 22, 23, 24, 25, 26, 16};
    if (keyscan_porting_set_gpio(user_gpio_map)) {
        return;
    }
#endif
    uapi_set_keyscan_value_map((uint8_t **)g_key_map, CONFIG_KEYSCAN_ENABLE_ROW, CONFIG_KEYSCAN_ENABLE_COL);
    uapi_keyscan_init(EVERY_ROW_PULSE_40_US, HAL_KEYSCAN_MODE_1, KEYSCAN_INT_VALUE_RDY);
    uapi_keyscan_register_callback(app_keyscan_callback);

#if defined(CONFIG_SAMPLE_SUPPORT_BLE_RCU_SERVER)
    ble_rcu_server_register_cb(ble_notify_connect);
#endif

#if defined(CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER)
    sle_rcu_server_register_cb(sle_notify_connect);
#endif
    uapi_keyscan_enable();
}