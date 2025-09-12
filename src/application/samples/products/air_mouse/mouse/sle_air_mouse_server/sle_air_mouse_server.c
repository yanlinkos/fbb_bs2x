/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2023-2025. All rights reserved.
 *
 * Description: Sle Air Mouse with dongle server Source. \n
 *
 * History: \n
 * 2023-11-16, Create file. \n
 */
#include "sle_air_mouse_server.h"
#include <stdint.h>
#include "securec.h"
#include "soc_osal.h"
#include "common_def.h"
#include "slp_factory.h"
#include "sle_errcode.h"
#include "slp_errcode.h"
#include "bts_le_gap.h"
#include "sle_connection_manager.h"
#include "sle_device_manager.h"
#include "sle_device_discovery.h"
#include "sle_ssap_server.h"
#include "sle_air_mouse_server_adv.h"
#include "air_mouse_common.h"
#include "gpio.h"
#include "ulp_gpio.h"
#include "pm_veto.h"
#include "pm_clock.h"
#include "keyscan.h"
#include "amic_voice.h"
#include "sle_service_ntf.h"
#ifdef CONFIG_SAMPLE_SUPPORT_AIR_MOUSE_OTA
#include "sle_ota.h"
#endif
#include "../common/air_mouse_timer.h"

#define SLE_ADV_HANDLE_DEFAULT              1
#define USB_MOUSE_TASK_DELAY_MS             2000
#define SLE_AIR_MOUSE_SSAP_RPT_HANDLE       0x11 // SLP数传HANDLE
#define SLE_AIR_MOUSE_CURSOR_RPT_HANDLE     0x16 // 鼠标坐标上报HANDLE
#define SLE_AIR_MOUSE_CMD_RPT_HANDLE        0x1B // 命令交互HANDLE
#define SLE_AIR_MOUSE_KEYBOARD_RPT_HANDLE   0x20 // 键盘按键上报HANDLE

#define SLE_AIR_MOUSE_DEFAULT_SERVER_ID     1
#define SLE_AIR_MOUSE_DEFAULT_CONNECT_ID    0

#define APP_UUID_LEN                        2
#define UUID_LEN_2                          2
#define BT_INDEX_4                          4
#define BT_INDEX_5                          5
#define BT_INDEX_0                          0
#define HANDLE_NUM                          2
#define HID_ELEMENT_NUM                     6
#define SLE_AIR_MOUSE_REPORT_LENGTH         4
#define SLE_SRV_ENCODED_REPORT_LEN          8
#define MOUSE_APPEARANCE_LENGTH             3

#define SEND_DATA_LEN_FOR_TV_CAR            250

// 用于判定是否进睡眠的变量
static int16_t g_last_x = 0;
static int16_t g_last_y = 0;
static uint16_t g_static_count = 0;

static uint8_t g_app_uuid[APP_UUID_LEN] = {0x0, 0x0};
static uint8_t g_server_id = 0;
static uint8_t g_mouse_sle_conn_hdl = 0;
static uint32_t g_mouse_sle_pair_status = 0;
static uint8_t g_sle_input_report[SLE_AIR_MOUSE_REPORT_LENGTH] = {0};
static uint8_t g_sle_hid_control_point = 1;
static sle_item_handle_t g_service_hdl[HID_ELEMENT_NUM] = {0};
static uint8_t g_cccd[2] = {0x01, 0x0};
static uint8_t g_input_report_descriptor[SLE_SRV_ENCODED_REPORT_LEN] = {0};
/* Hid Information characteristic not defined */
static uint8_t g_sle_hid_group_uuid[HID_ELEMENT_NUM][SLE_UUID_LEN] = {
    /* Human Interface Device service UUID. */
    { 0x37, 0xBE, 0xA8, 0x80, 0xFC, 0x70, 0x11, 0xEA,
      0xB7, 0x20, 0x00, 0x00, 0x00, 0x00, 0x06, 0x0B },
    /* Report characteristic UUID. 输入报告信息 */
    { 0x37, 0xBE, 0xA8, 0x80, 0xFC, 0x70, 0x11, 0xEA,
      0xB7, 0x20, 0x00, 0x00, 0x00, 0x00, 0x10, 0x3C },
    /* CCCD */
    { 0xFB, 0x34, 0x9B, 0x5F, 0x80, 0x00, 0x00, 0x80,
      0x00, 0x10, 0x00, 0x00, 0x02, 0x29, 0x00, 0x00 },
    /* Report Reference characteristic UUID. 报告索引信息 */
    { 0x37, 0xBE, 0xA8, 0x80, 0xFC, 0x70, 0x11, 0xEA,
      0xB7, 0x20, 0x00, 0x00, 0x00, 0x00, 0x10, 0x3B },
    /* Report Map characteristic UUID. 类型和格式描述 */
    { 0x37, 0xBE, 0xA8, 0x80, 0xFC, 0x70, 0x11, 0xEA,
      0xB7, 0x20, 0x00, 0x00, 0x00, 0x00, 0x10, 0x39 },
    /* Hid Control Point characteristic UUID.  工作状态指示 */
    { 0x37, 0xBE, 0xA8, 0x80, 0xFC, 0x70, 0x11, 0xEA,
      0xB7, 0x20, 0x00, 0x00, 0x00, 0x00, 0x10, 0x3A },
};

static SlpDeviceAddr g_air_mouse_addr = {{0x01, 0x02, 0x03, 0x04, 0x05, 0x06}}; // air mouse的本机地址
static SlpDeviceAddr g_air_mouse_connect_addr = {{0x08, 0x02, 0x03, 0x04, 0x05, 0x06}}; /* air mouse 连接到的
                                                                                           对端dongle的本机地址 */
static uint8_t g_connect_id = 0;

static uint8_t g_start_ranging_times = 0; // 启动测距的次数, 上电和低功耗时清零
static bool g_sample_sleep = false; // sample中发送睡眠指令的标志，true表示sample发送睡眠指令,用于区分AT命令和sample逻辑

static uint8_t g_ranging_report_cnt = 0; // 测量值上报计数

const SlpDeviceAddr *get_slp_air_mouse_addr(void)
{
    return &g_air_mouse_addr;
}

static uint8_t g_hid_service_property[HID_ELEMENT_NUM] = {
    0,
    SSAP_OPERATE_INDICATION_BIT_READ | SSAP_OPERATE_INDICATION_BIT_NOTIFY,
    SSAP_OPERATE_INDICATION_BIT_READ | SSAP_OPERATE_INDICATION_BIT_WRITE_NO_RSP | SSAP_OPERATE_INDICATION_BIT_WRITE |
        SSAP_OPERATE_INDICATION_BIT_NOTIFY,
    SSAP_OPERATE_INDICATION_BIT_READ | SSAP_OPERATE_INDICATION_BIT_WRITE | SSAP_OPERATE_INDICATION_BIT_NOTIFY,
    SSAP_OPERATE_INDICATION_BIT_READ | SSAP_OPERATE_INDICATION_BIT_NOTIFY,
    SSAP_OPERATE_INDICATION_BIT_WRITE_NO_RSP | SSAP_OPERATE_INDICATION_BIT_NOTIFY,
};

typedef enum {
    SLE_UUID_INDEX0, // hid service
    SLE_UUID_INDEX1, // input report
    SLE_UUID_INDEX2, // CCCD
    SLE_UUID_INDEX3, // Report Reference
    SLE_UUID_INDEX4, // Report Map
    SLE_UUID_INDEX5, // Hid Control Point
} sle_uuid_index_t;

static uint8_t g_sle_report_map_datas[] = {
    0x00,                       /* type indicate */
    0x05, 0x01,                 /* Usage Page (Generic Desktop)             */
    0x09, 0x02,                 /* Usage (Mouse)                            */
    0xA1, 0x01,                 /* Collection (Application)                 */
    0x09, 0x01,                 /*  Usage (Pointer)                         */
    0xA1, 0x00,                 /*  Collection (Physical)                   */
    0x85, 0x01,                 /*   Report ID  */
    0x05, 0x09,                 /*      Usage Page (Buttons)                */
    0x19, 0x01,                 /*      Usage Minimum (01)                  */
    0x29, 0x03,                 /*      Usage Maximum (03)                  */
    0x15, 0x00,                 /*      Logical Minimum (0)                 */
    0x25, 0x01,                 /*      Logical Maximum (1)                 */
    0x95, 0x03,                 /*      Report Count (3)                    */
    0x75, 0x01,                 /*      Report Size (1)                     */
    0x81, 0x02,                 /*      Input (Data, Variable, Absolute)    */
    0x95, 0x01,                 /*      Report Count (1)                    */
    0x75, 0x05,                 /*      Report Size (5)                     */
    0x81, 0x01,                 /*      Input (Constant)    ;5 bit padding  */
    0x05, 0x01,                 /*      Usage Page (Generic Desktop)        */
    0x09, 0x30,                 /*      Usage (X)                           */
    0x09, 0x31,                 /*      Usage (Y)                           */
    0x16, 0x01, 0xF8,           /*      Logical Minimum (-2047)              */
    0x26, 0xFF, 0x07,           /*      Logical Maximum (2047)               */
    0x75, 0x0C,                 /*      Report Size (12)                     */
    0x95, 0x02,                 /*      Report Count (2)                    */
    0x81, 0x06,                 /*      Input (Data, Variable, Relative)    */
    0x05, 0x01,                 /*      Usage Page (Generic Desktop)        */
    0x09, 0x38,                 /*      Usage (Wheel)                       */
    0x15, 0x81,                 /*      Logical Minimum (-127)              */
    0x25, 0x7F,                 /*      Logical Maximum (127)               */
    0x75, 0x08,                 /*      Report Size (8)                     */
    0x95, 0x01,                 /*      Report Count (1)                    */
    0x81, 0x06,                 /*      Input (Data, Variable, Relative)    */
    0xC0,                       /* End Collection,End Collection            */
    0xC0,                       /* End Collection,End Collection            */
};

static bool g_ssap_passage_supprot = false;
static uint8_t g_sle_air_mouse_server_conn_state = SLE_ACB_STATE_NONE;
#define DIS_ELEMENT_NUM 4
static uint8_t g_sle_dis_uuid[DIS_ELEMENT_NUM][SLE_UUID_LEN] = {
    /* DIS service UUID. 设备信息管理 */
    { 0x37, 0xBE, 0xA8, 0x80, 0xFC, 0x70, 0x11, 0xEA,
      0xB7, 0x20, 0x00, 0x00, 0x00, 0x00, 0x06, 0x09 },
    /* Device name characteristic UUID 设备名称 */
    { 0x37, 0xBE, 0xA8, 0x80, 0xFC, 0x70, 0x11, 0xEA,
      0xB7, 0x20, 0x00, 0x00, 0x00, 0x00, 0x10, 0x3F},
    /* Device appearance characteristic 设备外观 */
    { 0x37, 0xBE, 0xA8, 0x80, 0xFC, 0x70, 0x11, 0xEA,
      0xB7, 0x20, 0x00, 0x00, 0x00, 0x00, 0x10, 0x40},
      /* Pnp Id characteristic UUID（设备序列号） */
    { 0x37, 0xBE, 0xA8, 0x80, 0xFC, 0x70, 0x11, 0xEA,
      0xB7, 0x20, 0x00, 0x00, 0x00, 0x00, 0x10, 0x2E },
};

static sle_item_handle_t g_dis_service_hdl[DIS_ELEMENT_NUM] = {0};
static uint8_t g_local_device_name[] = { 's', 'l', 'e', '_', 'm', 'o', 'u', 's', 'e'};
static bool g_sle_enable = false;
#define MANUFACTURE_PNP_ID (uint8_t *)"MAGIC-103F-12D1-0001"
#define MANUFACTURE_PNP_ID_LENGTH 20
typedef enum {
    SLE_DIS_INDEX0, // dis service
    SLE_DIS_INDEX1, // name
    SLE_DIS_INDEX2, // appearance
    SLE_DIS_INDEX3, // pnp id
} sle_dis_index_t;

int32_t g_slp_cursor_report_x = 0;
int32_t g_slp_cursor_report_y = 0;
static usb_hid_mouse_report_t g_mouse_report = { 0 };
static usb_hid_keyboard_report_t g_keyboard_report = { 0 };

// 假设100HZ频率发送, 2^32/100/60/60 ≈ 11930.46 小时
static uint32_t g_send_cursor_sequence_no = 0;  // 光标坐标消息发送序号
static uint32_t g_send_key_sequence_no = 0;     // 按键消息发送序号

SlpCursorSpeed g_slp_cursor_speed = SLP_CURSOR_SPEED_MEDIUM;  // slp光标速度

uint16_t g_screen_width;   // 屏幕宽度, 单位: mm
uint16_t g_screen_height;  // 屏幕高度, 单位: mm

uint8_t g_out_low_latency_data[LOW_LATENCY_DATA_MAX] = { 0 };

SlpCursorSpeed get_slp_cursor_speed(void)
{
    return g_slp_cursor_speed;
}

void set_screen_size(uint16_t width, uint16_t height)
{
    g_screen_width = width;
    g_screen_height = height;
}

uint16_t get_screen_width(void)
{
    return g_screen_width;
}

uint16_t get_screen_height(void)
{
    return g_screen_height;
}

void set_slp_cursor_speed(SlpCursorSpeed mode)
{
    g_slp_cursor_speed = mode;
}

// 记录开始时间
uint64_t g_power_on_start_time = 0; // ms
uint64_t g_start_ranging_start_time = 0; // ms
static bool g_announce_keyscan_flag = false;  // 是否是由keyscan触发的配对/解配对状态

void init_power_on_start_time(void)  // 记录开始时间
{
    g_power_on_start_time = uapi_tcxo_get_ms();
}

void set_announce_keyscan_flag(void)
{
    g_announce_keyscan_flag = true;
}

static void init_hid_report(void)
{
    (void)memset_s(&g_mouse_report, sizeof(usb_hid_mouse_report_t), 0, sizeof(usb_hid_mouse_report_t));
    (void)memset_s(&g_keyboard_report, sizeof(usb_hid_keyboard_report_t), 0, sizeof(usb_hid_keyboard_report_t));
    g_mouse_report.kind = HID_MOUSE_ABS_KIND;
    g_keyboard_report.kind = HID_KEYBOARD_KIND;
    g_send_cursor_sequence_no = 0;
    g_send_key_sequence_no = 0;
}

errcode_t get_g_sle_air_mouse_pair_state(uint32_t *pair_state)
{
    *pair_state = g_mouse_sle_pair_status;
    return ERRCODE_SLE_SUCCESS;
}

errcode_t get_g_sle_air_mouse_server_conn_state(uint8_t *conn_state)
{
    *conn_state = g_sle_air_mouse_server_conn_state;
    return ERRCODE_SLE_SUCCESS;
}

errcode_t get_g_read_ssap_support(bool *param)
{
    *param = g_ssap_passage_supprot;
    return ERRCODE_SLE_SUCCESS;
}

static void ssaps_read_request_cbk(uint8_t server_id, uint16_t conn_id, ssaps_req_read_cb_t *read_cb_para,
    errcode_t status)
{
    osal_printk("[uuid server] ssaps read request cbk server_id:%x, conn_id:%x, handle:%x, status:%x\r\n",
        server_id, conn_id, read_cb_para->handle, status);
}

static void ssaps_write_request_cbk(uint8_t server_id, uint16_t conn_id, ssaps_req_write_cb_t *write_cb_para,
    errcode_t status)
{
    unused(server_id);
    unused(conn_id);
    unused(status);
    g_ssap_passage_supprot = true;

    SlpPayloadInfo info = { write_cb_para->value, write_cb_para->length };
    SlpRecvPayload(&info);
}

static void ssaps_mtu_changed_cbk(uint8_t server_id, uint16_t conn_id,  ssap_exchange_info_t *mtu_size,
    errcode_t status)
{
    osal_printk("[uuid server] ssaps write request cbk server_id:%x, conn_id:%x, mtu_size:%x, status:%x\r\n",
        server_id, conn_id, mtu_size->mtu_size, status);
}

static void ssaps_start_service_cbk(uint8_t server_id, uint16_t handle, errcode_t status)
{
    osal_printk("[uuid server] start service cbk server_id:%x, handle:%x, status:%x\r\n",
        server_id, handle, status);
}

static void sle_connect_param_update_cbk(uint16_t conn_id, errcode_t status,
    const sle_connection_param_update_evt_t *param)
{
    sle_set_data_len(conn_id, SEND_DATA_LEN_FOR_TV_CAR);
    osal_printk("%s connect up back conn_id:0x%02x, interval:0x%x, latency:0x%x, supervision:0x%x\r\n",
        SLE_AIR_MOUSE_DONGLE_SERVER_LOG, conn_id, param->interval, param->latency, param->supervision);
    osal_printk("[uuid server] sle_connect_param_update_cbk:0x%x\r\n", status);
}

void set_slp_start_ranging_param(SlpStartRangingParam *param)
{
    // 1. frameParam
    param->frameParam.codeLen = 0; // 0: 默认值
    param->frameParam.syncCodeIdx = 2; // 2: 默认值
    param->frameParam.syncSymNum = 4; // 4: 默认值
    param->frameParam.ctsSegNum = 4; // 4: 默认值
    param->frameParam.ctsSegSymNum = 1; // 1: 默认值
    param->frameParam.gapBaseSymNum = 0; // 0: 默认值
    param->frameParam.ctsCpLen = 0; // 0: 默认值

    // 2. securityParam
    param->secParam.secMode = SLP_SEC_MODE_LPLS; // 遥控器使用低安全模式
    param->secParam.encryptMode = SLP_ENCRYPT_MODE_AES128;
    param->secParam.sessionKeyMode = SLP_WB_SHARED_KEY;
    param->secParam.sessionKeyIdx = 0;

    // 3. rangingParam
    param->rangingParam.chIdx = SLP_CH_9;
#if CONFIG_SLP_USAGE_RANGING_AOX
    param->rangingParam.usageMode = SLP_USAGE_RANGING_AOX;
#elif CONFIG_SLP_USAGE_AIR_MOUSE
    param->rangingParam.usageMode = SLP_USAGE_AIR_MOUSE;
#elif CONFIG_SLP_USAGE_AIR_MOUSE_CAR
    param->rangingParam.usageMode = SLP_USAGE_AIR_MOUSE_CAR;
#endif
    param->rangingParam.slpRangingMode = SLP_RANGING_AOA;
    param->rangingParam.multiNodeMode = SLP_ONE_TO_ONE;
    param->rangingParam.rangingRoundUsage = SLP_DS_TWR;
    param->rangingParam.mrSource = SLP_MR_RECV;
#if CONFIG_SAMPLE_SUPPORT_AIR_MOUSE_CIR_PRINT
    param->rangingParam.rangingFreq = 2; // 测距频率2Hz
#else
    param->rangingParam.rangingFreq = 20; // 测距频率20Hz
#endif
    param->rangingParam.validRoundNum = 0; // 无限轮
    param->rangingParam.aoxDirection = SLP_RESPONSE_AOX;
    param->rangingParam.firstAoxAntDis = 12507618; // 12507618: CH9的1/3波长，单位：nm
    param->rangingParam.nbSyncMode = SLP_NB_SINGLE_SIDE_SYNC;
    param->rangingParam.deviceNum = 2; // 2: 默认2个设备
    param->rangingParam.txMode = 0; // 0: 非常发模式
    param->rangingParam.sessionId = 0x20240101;
    // air mouse为测距发起者，所以air mouse的地址放在前面
    (void)memcpy_s(&param->rangingParam.deviceAddr[0].addr[0], sizeof(SlpDeviceAddr),
        &g_air_mouse_addr.addr[0], sizeof(SlpDeviceAddr));
    (void)memcpy_s(&param->rangingParam.deviceAddr[1].addr[0], sizeof(SlpDeviceAddr),
        &g_air_mouse_connect_addr.addr[0], sizeof(SlpDeviceAddr));
}

#ifdef weak
weak void slp_sleep_pin_config(void)
{
}

weak void ulp_wakeup_congif(ulp_gpio_irq_cb_t irq_cb)
{
    unused(irq_cb);
}

weak void slp_wakeup_pin_config(void)
{
}
#else
__attribute__((weak)) void slp_sleep_pin_config(void)
{
}

__attribute__((weak)) void ulp_wakeup_congif(ulp_gpio_irq_cb_t irq_cb)
{
    unused(irq_cb);
}

__attribute__((weak)) void slp_wakeup_pin_config(void)
{
}
#endif

static void sle_conn_param_update(uint16_t sle_connection_interval, uint16_t max_latency, uint16_t timeout)
{
    sle_connection_param_update_t params;
    params.conn_id = g_connect_id;
    params.interval_max = sle_connection_interval;
    params.interval_min = sle_connection_interval;
    params.max_latency = max_latency;
    params.supervision_timeout = timeout;
    sle_update_connect_param(&params);
}

// 恢复SLP相关投票、时钟、管脚
static void slp_resume(void)
{
    // 添加SLP睡眠否决票
    uapi_pm_add_sleep_veto(PM_VETO_ID_SLP);

    // 开启SLP时钟
    uapi_clock_control(CLOCK_CONTROL_XO_OUT_ENABLE, CLOCK_XO2DIE);

    // 不下电管脚和下电管脚使能切换
    uint32_t irq_status = osal_irq_lock();
    ulp_gpio_deinit();
    uapi_gpio_init();
    slp_wakeup_pin_config(); // SLP管脚恢复
    (void)uapi_keyscan_resume(0); // 恢复按键
    osal_irq_restore(irq_status);
}

// imu 唤醒中断回调函数
void imu_wakeup_callback(uint8_t ulp_gpio)
{
    unused(ulp_gpio);

    // 更新sle的interval为2.5ms
    sle_conn_param_update(20, 0, 500); // 20: 2.5ms interval, 0: latency, 500: supervision_timeout

    slp_resume();

    // 重启slp测距
    g_start_ranging_times = 0;
    SlpStartRangingParam param = {0};
    set_slp_start_ranging_param(&param);
    ErrcodeSlpClient ret = SlpStartRangingCommand(&param);
    if (ret != ERRCODE_SLPC_SUCCESS) {
        osal_printk("SlpStartRangingCommand Error 0x%x\r\n", ret);
        return;
    }
}

static void sle_connect_state_changed_cbk(uint16_t conn_id, const sle_addr_t *addr,
                                          sle_acb_state_t conn_state, sle_pair_state_t pair_state,
                                          sle_disc_reason_t disc_reason)
{
    osal_printk("%s connect state changed conn_id:0x%02x, conn_state:0x%x, pair_state:0x%x, disc_reason:0x%x\r\n",
                SLE_AIR_MOUSE_DONGLE_SERVER_LOG, conn_id, conn_state, pair_state, disc_reason);
    osal_printk("remote addr:");
    for (uint8_t i = 0; i < SLE_ADDR_LEN; i++) {
        osal_printk("%02x ", addr->addr[i]);
    }
    osal_printk("\r\n");
    g_sle_air_mouse_server_conn_state = conn_state;
    g_mouse_sle_pair_status = pair_state;

    sle_connection_param_update_t con_param = {0};
    con_param.conn_id = conn_id;
    g_connect_id = conn_id;
    con_param.interval_max = 20; // 20:2.5ms, 单位slot, 每个0.125ms
    con_param.interval_min = 20; // 20:2.5ms, 单位slot, 每个0.125ms
    con_param.max_latency = 0;
    con_param.supervision_timeout = 500; // 设置连接延迟500*10ms,需满足timeout > 2 * interval * (latency + 1)
    if (conn_state == SLE_ACB_STATE_CONNECTED) {
        osal_printk("%s SLE_ACB_STATE_CONNECTED\r\n", SLE_AIR_MOUSE_DONGLE_SERVER_LOG);
        sle_update_connect_param(&con_param);
    } else if (conn_state == SLE_ACB_STATE_DISCONNECTED) {
        osal_printk("%s SLE_ACB_STATE_DISCONNECTED\r\n", SLE_AIR_MOUSE_DONGLE_SERVER_LOG);
        // 防止遥控器睡眠过程中，dongle下电再上电导致遥控器启动异常
        slp_resume();
        if (!g_announce_keyscan_flag) {  // 如果不是按键触发的配对动作，则一直开启广播直到连接上为止
            sle_start_announce(SLE_ADV_HANDLE_DEFAULT);
        }
        g_ssap_passage_supprot = false;

        // SLE断连后，SLP下电
        ErrcodeSlpClient ret = SlpPowerOffCommand();
        if (ret != ERRCODE_SLPC_SUCCESS) {
            osal_printk("SlpPowerOffCommand Error 0x%x\r\n", ret);
            return;
        }
    }
    g_mouse_sle_conn_hdl = conn_id;
}

static void sle_pair_complete_cbk(uint16_t conn_id, const sle_addr_t *addr, errcode_t status)
{
    osal_printk("[uuid server] pair complete conn_id:%02x, status:%x\r\n",
        conn_id, status);
    osal_printk("[uuid server] pair complete addr:%02x:**:**:**:%02x:%02x\r\n",
        addr->addr[BT_INDEX_0], addr->addr[BT_INDEX_4], addr->addr[BT_INDEX_5]);
    g_mouse_sle_pair_status = status;
    if (g_mouse_sle_pair_status == 0) {
        init_hid_report();
        // SLE连接配对成功后，SLP上电，完成SLP加载
        init_power_on_start_time();
        ErrcodeSlpClient ret = SlpPowerOnCommand();
        if (ret != ERRCODE_SLPC_SUCCESS) {
            osal_printk("SlpPowerOnCommand Error 0x%x\r\n", ret);
            return;
        }
#ifdef CONFIG_AIR_MOUSE_HR_BOARD
        app_timer_process_stop(TIME_CMD_PAIR);
#endif
    }
}

void read_rssi_callback(uint16_t conn_id, int8_t rssi, errcode_t status)
{
    UNUSED(conn_id);
    osal_printk("[cursor] x:%d, y:%d, rx:%d, ry:%d, rssi:%d, conn_id:%u, status:0x%08X\r\n", g_mouse_report.x,
        g_mouse_report.y, g_slp_cursor_report_x, g_slp_cursor_report_y, rssi, conn_id, status);
}

static void sle_conn_register_cbks(void)
{
    sle_connection_callbacks_t conn_cbks = { 0 };
    conn_cbks.connect_state_changed_cb = sle_connect_state_changed_cbk;
    conn_cbks.pair_complete_cb = sle_pair_complete_cbk;
    conn_cbks.connect_param_update_cb = sle_connect_param_update_cbk;
    conn_cbks.read_rssi_cb = read_rssi_callback;
    sle_connection_register_callbacks(&conn_cbks);
}

static void sle_air_mouse_ssaps_register_cbks(void)
{
    ssaps_callbacks_t ssaps_cbk = {0};
    ssaps_cbk.start_service_cb = ssaps_start_service_cbk;
    ssaps_cbk.mtu_changed_cb = ssaps_mtu_changed_cbk;
    ssaps_cbk.read_request_cb = ssaps_read_request_cbk;
    ssaps_cbk.write_request_cb = ssaps_write_request_cbk;
    ssaps_register_callbacks(&ssaps_cbk);
}

static uint8_t sle_get_server_id(void)
{
    return g_server_id;
}

static errcode_t sle_register_server(void)
{
    // register server
    errcode_t ret;
    sle_uuid_t app_uuid = {0};
    app_uuid.len = sizeof(g_app_uuid);
    if (memcpy_s(app_uuid.uuid, app_uuid.len, g_app_uuid, sizeof(g_app_uuid)) != EOK) {
        return ERRCODE_SLE_MEMCPY_FAIL;
    }
    ret = ssaps_register_server(&app_uuid, &g_server_id);
    if (ret != ERRCODE_SLE_SUCCESS) {
        osal_printk("[uuid server] sle reg server fail, ret:%x\r\n", ret);
        return ERRCODE_SLE_FAIL;
    }
#ifdef CONFIG_SAMPLE_SUPPORT_AIR_MOUSE_OTA
    ret = sle_ota_service_init(g_server_id);
    osal_printk("[uuid server] add ota service:%x\r\n", g_server_id);
    if (ret != ERRCODE_SLE_SUCCESS) {
        osal_printk("[uuid server] add ota service fail, ret:%x\r\n", ret);
        return ERRCODE_SLE_FAIL;
    }
#endif

    return ERRCODE_SLE_SUCCESS;
}

static errcode_t sle_sample_set_uuid(uint8_t *uuid, sle_uuid_t *service_uuid)
{
    if (memcpy_s(service_uuid->uuid, SLE_UUID_LEN, uuid, SLE_UUID_LEN) != EOK) {
        osal_printk("sle air mouse hid set uuid fail\r\n");
        return ERRCODE_SLE_MEMCPY_FAIL;
    }
    service_uuid->len = SLE_UUID_LEN;
    return ERRCODE_SLE_SUCCESS;
}

static errcode_t sle_air_mouse_service_add(void)
{
    errcode_t ret;
    sle_uuid_t service_uuid = {0};
    ret = sle_sample_set_uuid(g_sle_hid_group_uuid[SLE_UUID_INDEX0], &service_uuid);
    if (ret != ERRCODE_SLE_SUCCESS) {
        osal_printk("[uuid server] sle air mouse uuid set fail, ret:%x\r\n", ret);
        return ERRCODE_SLE_FAIL;
    }

    ret = ssaps_add_service_sync(sle_get_server_id(), &service_uuid, true, &g_service_hdl[SLE_UUID_INDEX0].handle_out);
    if (ret != ERRCODE_SLE_SUCCESS) {
        osal_printk("[uuid server] sle air mouse add service fail, ret:%x\r\n", ret);
        return ERRCODE_SLE_FAIL;
    }
    g_service_hdl[SLE_UUID_INDEX1].handle_in = g_service_hdl[SLE_UUID_INDEX0].handle_out;
    g_service_hdl[SLE_UUID_INDEX3].handle_in = g_service_hdl[SLE_UUID_INDEX0].handle_out;
    g_service_hdl[SLE_UUID_INDEX4].handle_in = g_service_hdl[SLE_UUID_INDEX0].handle_out;
    g_service_hdl[SLE_UUID_INDEX5].handle_in = g_service_hdl[SLE_UUID_INDEX0].handle_out;
    return ERRCODE_SLE_SUCCESS;
}

static errcode_t sle_sample_add_descriptor_interface(uint32_t properties, uint16_t service_handle,
    uint16_t property_handle, uint16_t len, uint8_t *data)
{
    if (data == NULL) {
        osal_printk("sle sample add descriptor interface param is NULL\r\n");
        return ERRCODE_SLE_FAIL;
    }
    ssaps_desc_info_t descriptor = {0};
    descriptor.permissions = SSAP_PERMISSION_READ | SSAP_PERMISSION_WRITE;
    descriptor.operate_indication = properties;
    descriptor.type = SSAP_DESCRIPTOR_CLIENT_CONFIGURATION;
    descriptor.value_len = len;
    descriptor.value = data;
    return ssaps_add_descriptor_sync(sle_get_server_id(), service_handle, property_handle, &descriptor);
}

static errcode_t sle_sample_add_property_interface(uint32_t properties, uint8_t *uuid, uint16_t len, uint8_t *data,
    sle_item_handle_t* service_hdl)
{
    if ((data == NULL) || (service_hdl == NULL)) {
        osal_printk("sle sample add property interface param is NULL\r\n");
        return ERRCODE_SLE_FAIL;
    }
    ssaps_property_info_t property = {0};
    errcode_t ret = sle_sample_set_uuid(uuid, &property.uuid);
    if (ret != ERRCODE_SLE_SUCCESS) {
        osal_printk("[uuid server] sle air mouse uuid set fail, ret:%x\r\n", ret);
        return ERRCODE_SLE_FAIL;
    }
    property.permissions = SSAP_PERMISSION_READ | SSAP_PERMISSION_WRITE;
    property.operate_indication = properties;
    property.value_len = len;
    property.value = data;
    return ssaps_add_property_sync(sle_get_server_id(), service_hdl->handle_in, &property, &service_hdl->handle_out);
}

static errcode_t sle_air_mouse_property_and_descriptor_add(void)
{
    errcode_t ret = ERRCODE_SLE_SUCCESS;
    ret = sle_sample_add_property_interface(g_hid_service_property[SLE_UUID_INDEX1],
        g_sle_hid_group_uuid[SLE_UUID_INDEX1], SLE_AIR_MOUSE_REPORT_LENGTH, g_sle_input_report,
        &g_service_hdl[SLE_UUID_INDEX1]);
    if (ret != ERRCODE_SLE_SUCCESS) {
        osal_printk("[uuid server] sle air mouse add report fail, ret:%x, indet:%x\r\n", ret, SLE_UUID_INDEX1);
        return ERRCODE_SLE_FAIL;
    }
    osal_printk("[uuid server] sle air mouse add report, proterty hdl:%x\r\n",
        g_service_hdl[SLE_UUID_INDEX1].handle_out);

    ret = sle_sample_add_descriptor_interface(g_hid_service_property[SLE_UUID_INDEX2],
        g_service_hdl[SLE_UUID_INDEX0].handle_out, g_service_hdl[SLE_UUID_INDEX1].handle_out, sizeof(g_cccd), g_cccd);
    if (ret != ERRCODE_SLE_SUCCESS) {
        osal_printk("[uuid server] sle air mouse add cccd fail, ret:%x, indet:%x\r\n", ret, SLE_UUID_INDEX2);
        return ERRCODE_SLE_FAIL;
    }

    g_input_report_descriptor[0] = 0x1;   // [1] : report id
    g_input_report_descriptor[1] = 0x1;   // [1] : input
    g_input_report_descriptor[2] = g_service_hdl[SLE_UUID_INDEX1].handle_out; // [2] rpt handle low
    g_input_report_descriptor[3] = 0;     // [3] rpt handle high
    ret = sle_sample_add_property_interface(g_hid_service_property[SLE_UUID_INDEX3],
        g_sle_hid_group_uuid[SLE_UUID_INDEX3], SLE_SRV_ENCODED_REPORT_LEN, g_input_report_descriptor,
        &g_service_hdl[SLE_UUID_INDEX3]);
    if (ret != ERRCODE_SLE_SUCCESS) {
        osal_printk("[uuid server] sle air mouse add report ref fail, ret:%x, indet:%x\r\n", ret, SLE_UUID_INDEX3);
        return ERRCODE_SLE_FAIL;
    }

    ret = sle_sample_add_property_interface(g_hid_service_property[SLE_UUID_INDEX4],
        g_sle_hid_group_uuid[SLE_UUID_INDEX4], sizeof(g_sle_report_map_datas), g_sle_report_map_datas,
        &g_service_hdl[SLE_UUID_INDEX4]);
    if (ret != ERRCODE_SLE_SUCCESS) {
        osal_printk("[uuid server] sle air mouse add report map ref fail, ret:%x, indet:%x\r\n", ret,
            SLE_UUID_INDEX4);
        return ERRCODE_SLE_FAIL;
    }

    ret = sle_sample_add_property_interface(g_hid_service_property[SLE_UUID_INDEX5],
        g_sle_hid_group_uuid[SLE_UUID_INDEX5], sizeof(uint8_t), &g_sle_hid_control_point,
        &g_service_hdl[SLE_UUID_INDEX5]);
    if (ret != ERRCODE_SLE_SUCCESS) {
        osal_printk("[uuid server] sle air mouse add hid ctrl point fail, ret:%x, indet:%x\r\n", ret,
            SLE_UUID_INDEX5);
        return ERRCODE_SLE_FAIL;
    }
    return ERRCODE_SLE_SUCCESS;
}

// 注册服务，slp数传，handle：2
static errcode_t sle_air_mouse_server_add(void)
{
    errcode_t ret;
    /* sle_register_server 只需执行一次，若注册多个服务，后续的注册不要调用这个函数 */
    ret = sle_register_server();
    if (ret != ERRCODE_SLE_SUCCESS) {
        osal_printk("[uuid server] sle pen reg server fail, ret:%x\r\n", ret);
        return ERRCODE_SLE_FAIL;
    }

    if (sle_air_mouse_service_add() != ERRCODE_SLE_SUCCESS) {
        ssaps_unregister_server(sle_get_server_id());
        return ERRCODE_SLE_FAIL;
    }

    if (sle_air_mouse_property_and_descriptor_add() != ERRCODE_SLE_SUCCESS) {
        ssaps_unregister_server(sle_get_server_id());
        return ERRCODE_SLE_FAIL;
    }
    osal_printk("[uuid server] sle pen add service, server_id:%x, service_handle:%x\r\n",
        g_server_id, g_service_hdl[SLE_UUID_INDEX0].handle_out);
    ret = ssaps_start_service(g_server_id, g_service_hdl[SLE_UUID_INDEX0].handle_out);
    if (ret != ERRCODE_SLE_SUCCESS) {
        osal_printk("[uuid server] sle pen start service fail, ret:%x\r\n", ret);
        return ERRCODE_SLE_FAIL;
    }
    osal_printk("[uuid server] sle uuid add service out\r\n");
    return ERRCODE_SLE_SUCCESS;
}

// 注册服务，HID鼠标光标，handle：4
static errcode_t sle_air_mouse_cursor_add(void)
{
    errcode_t ret;

    if (sle_air_mouse_service_add() != ERRCODE_SLE_SUCCESS) {
        ssaps_unregister_server(sle_get_server_id());
        return ERRCODE_SLE_FAIL;
    }

    if (sle_air_mouse_property_and_descriptor_add() != ERRCODE_SLE_SUCCESS) {
        ssaps_unregister_server(sle_get_server_id());
        return ERRCODE_SLE_FAIL;
    }
    osal_printk("[uuid server] sle pen add service, server_id:%x, service_handle:%x\r\n",
        g_server_id, g_service_hdl[SLE_UUID_INDEX0].handle_out);
    ret = ssaps_start_service(g_server_id, g_service_hdl[SLE_UUID_INDEX0].handle_out);
    if (ret != ERRCODE_SLE_SUCCESS) {
        osal_printk("[uuid server] sle pen start service fail, ret:%x\r\n", ret);
        return ERRCODE_SLE_FAIL;
    }
    osal_printk("[uuid server] sle uuid add service out\r\n");
    return ERRCODE_SLE_SUCCESS;
}

// 注册服务，命令，handle：6
static errcode_t sle_air_mouse_cmd_add(void)
{
    errcode_t ret;

    if (sle_air_mouse_service_add() != ERRCODE_SLE_SUCCESS) {
        ssaps_unregister_server(sle_get_server_id());
        return ERRCODE_SLE_FAIL;
    }

    if (sle_air_mouse_property_and_descriptor_add() != ERRCODE_SLE_SUCCESS) {
        ssaps_unregister_server(sle_get_server_id());
        return ERRCODE_SLE_FAIL;
    }
    osal_printk("[uuid server] sle cmd add service, server_id:%x, service_handle:%x\r\n",
        g_server_id, g_service_hdl[SLE_UUID_INDEX0].handle_out);
    ret = ssaps_start_service(g_server_id, g_service_hdl[SLE_UUID_INDEX0].handle_out);
    if (ret != ERRCODE_SLE_SUCCESS) {
        osal_printk("[uuid server] sle cmd start service fail, ret:%x\r\n", ret);
        return ERRCODE_SLE_FAIL;
    }
    osal_printk("[uuid server] sle uuid add service out\r\n");
    return ERRCODE_SLE_SUCCESS;
}

// 注册服务，HID鼠标，handle：8
static errcode_t sle_air_mouse_keyboard_add(void)
{
    errcode_t ret;

    if (sle_air_mouse_service_add() != ERRCODE_SLE_SUCCESS) {
        ssaps_unregister_server(sle_get_server_id());
        return ERRCODE_SLE_FAIL;
    }

    if (sle_air_mouse_property_and_descriptor_add() != ERRCODE_SLE_SUCCESS) {
        ssaps_unregister_server(sle_get_server_id());
        return ERRCODE_SLE_FAIL;
    }
    osal_printk("[uuid server] sle pen add service, server_id:%x, service_handle:%x\r\n",
        g_server_id, g_service_hdl[SLE_UUID_INDEX0].handle_out);
    ret = ssaps_start_service(g_server_id, g_service_hdl[SLE_UUID_INDEX0].handle_out);
    if (ret != ERRCODE_SLE_SUCCESS) {
        osal_printk("[uuid server] sle pen start service fail, ret:%x\r\n", ret);
        return ERRCODE_SLE_FAIL;
    }
    osal_printk("[uuid server] sle uuid add service out\r\n");
    return ERRCODE_SLE_SUCCESS;
}

static errcode_t sle_dis_service_add(void)
{
    errcode_t ret;
    sle_uuid_t service_uuid = {0};
    ret = sle_sample_set_uuid(g_sle_dis_uuid[SLE_DIS_INDEX0], &service_uuid);
    if (ret != ERRCODE_SLE_SUCCESS) {
        osal_printk("[uuid server] sle air mouse uuid set fail, ret:%x\r\n", ret);
        return ERRCODE_SLE_FAIL;
    }

    ret = ssaps_add_service_sync(sle_get_server_id(), &service_uuid, 1, &g_dis_service_hdl[SLE_DIS_INDEX0].handle_out);
    if (ret != ERRCODE_SLE_SUCCESS) {
        osal_printk("[uuid server] sle air mouse add service fail, ret:%x\r\n", ret);
        return ERRCODE_SLE_FAIL;
    }
    g_dis_service_hdl[SLE_DIS_INDEX1].handle_in = g_dis_service_hdl[SLE_DIS_INDEX0].handle_out;
    g_dis_service_hdl[SLE_DIS_INDEX2].handle_in = g_dis_service_hdl[SLE_DIS_INDEX0].handle_out;
    g_dis_service_hdl[SLE_DIS_INDEX3].handle_in = g_dis_service_hdl[SLE_DIS_INDEX0].handle_out;
    return ERRCODE_SLE_SUCCESS;
}

static errcode_t sle_dis_property_and_descriptor_add(void)
{
    errcode_t ret = ERRCODE_SLE_SUCCESS;
    uint32_t properties = SSAP_OPERATE_INDICATION_BIT_READ;
    ret = sle_sample_add_property_interface(properties, g_sle_dis_uuid[SLE_DIS_INDEX1], sizeof(g_local_device_name),
        g_local_device_name, &g_dis_service_hdl[SLE_DIS_INDEX1]);
    if (ret != ERRCODE_SLE_SUCCESS) {
        osal_printk("[dis server] sle dis add name fail, ret:%x, indet:%x\r\n", ret, SLE_DIS_INDEX1);
        return ERRCODE_SLE_FAIL;
    }

    uint8_t appearance_value[MOUSE_APPEARANCE_LENGTH] = {0x00, 0x05, 0x02}; // mouse appearance 0x00, 0x05, 0x02

    ret = sle_sample_add_property_interface(properties, g_sle_dis_uuid[SLE_DIS_INDEX2], sizeof(appearance_value),
        appearance_value, &g_dis_service_hdl[SLE_DIS_INDEX2]);
    if (ret != ERRCODE_SLE_SUCCESS) {
        osal_printk("[uuid server] sle dis add appearance fail, ret:%x, indet:%x\r\n", ret, SLE_DIS_INDEX2);
        return ERRCODE_SLE_FAIL;
    }

    uint8_t *facturer_pnp_id = (uint8_t*)MANUFACTURE_PNP_ID;

    ret = sle_sample_add_property_interface(properties, g_sle_dis_uuid[SLE_DIS_INDEX3], MANUFACTURE_PNP_ID_LENGTH,
        facturer_pnp_id, &g_dis_service_hdl[SLE_DIS_INDEX3]);
    if (ret != ERRCODE_SLE_SUCCESS) {
        osal_printk("[uuid server] sle dis add appearance fail, ret:%x, indet:%x\r\n", ret, SLE_DIS_INDEX2);
        return ERRCODE_SLE_FAIL;
    }
    return ERRCODE_SLE_SUCCESS;
}

errcode_t sle_sample_dis_server_add(void)
{
    errcode_t ret = ERRCODE_SLE_SUCCESS;
    ret = sle_set_local_name(g_local_device_name, sizeof(g_local_device_name));
    if (ret != ERRCODE_SLE_SUCCESS) {
        osal_printk("[dis server] set local name fail, ret:%x\r\n", ret);
        return ERRCODE_SLE_FAIL;
    }
    if (sle_dis_service_add() != ERRCODE_SLE_SUCCESS) {
        ssaps_unregister_server(sle_get_server_id());
        return ERRCODE_SLE_FAIL;
    }

    if (sle_dis_property_and_descriptor_add() != ERRCODE_SLE_SUCCESS) {
        ssaps_unregister_server(sle_get_server_id());
        return ERRCODE_SLE_FAIL;
    }
    osal_printk("[dis server] sle dis add service, server_id:%x, service_handle:%x\r\n",
        sle_get_server_id(), g_dis_service_hdl[SLE_DIS_INDEX0].handle_out);
    ret = ssaps_start_service(sle_get_server_id(), g_dis_service_hdl[SLE_DIS_INDEX0].handle_out);
    if (ret != ERRCODE_SLE_SUCCESS) {
        osal_printk("[dis server] sle dis start service fail, ret:%x\r\n", ret);
        return ERRCODE_SLE_FAIL;
    }
    osal_printk("[dis server] sle add dis service out\r\n");
    return ERRCODE_SLE_SUCCESS;
}

/* server向client发数据 */
static errcode_t sle_air_mouse_server_send_slp_payload(uint8_t *payload, uint16_t payload_len)
{
    ssaps_ntf_ind_t param = { 0 };
    param.handle = SLE_AIR_MOUSE_SSAP_RPT_HANDLE;
    param.value_len = payload_len;
    param.value = payload;
    ssaps_notify_indicate(SLE_AIR_MOUSE_DEFAULT_SERVER_ID, SLE_AIR_MOUSE_DEFAULT_CONNECT_ID, &param);
    return ERRCODE_SLE_SUCCESS;
}

// 发送数据：HID键盘光标
errcode_t sle_air_mouse_server_send_cmd(air_mouse_cmd_e cmd)
{
    ssaps_ntf_ind_t param = { 0 };
    param.handle = SLE_AIR_MOUSE_CMD_RPT_HANDLE;
    param.value_len = (uint16_t)sizeof(air_mouse_cmd_e);
    param.value = osal_vmalloc(sizeof(air_mouse_cmd_e));
    if (param.value == NULL) {
        osal_printk("send input report new fail\r\n");
        return ERRCODE_SLE_MALLOC_FAIL;
    }
    *(air_mouse_cmd_e *)param.value = cmd;

    ssaps_notify_indicate(SLE_AIR_MOUSE_DEFAULT_SERVER_ID, SLE_AIR_MOUSE_DEFAULT_CONNECT_ID, &param);
    osal_vfree(param.value);
    return ERRCODE_SLE_SUCCESS;
}

// 发送数据：HID键盘按键
errcode_t sle_hid_mouse_server_send_keyboard_report(uint8_t key, uint8_t value)
{
    ssaps_ntf_ind_t param = { 0 };
    param.handle = SLE_AIR_MOUSE_KEYBOARD_RPT_HANDLE;
    param.value_len = sizeof(keyboard_report_t);
    param.value = osal_vmalloc(sizeof(keyboard_report_t));
    if (param.value == NULL) {
        osal_printk("send input report new fail\r\n");
        return ERRCODE_SLE_MALLOC_FAIL;
    }
    g_send_key_sequence_no += 1;
    g_keyboard_report.key[0] = value;
    osal_printk("key send, no, %u, key, %u, value, %u\r\n", g_send_key_sequence_no, key, value);
    keyboard_report_t keyboard_report;
    keyboard_report.sequence_no = g_send_key_sequence_no;
    keyboard_report.key = key;
    keyboard_report.report = g_keyboard_report;

    if (memcpy_s(param.value, sizeof(keyboard_report_t), &keyboard_report, sizeof(keyboard_report_t)) != EOK) {
        osal_printk("send keyboard sequence_no memcpy fail\r\n");
        osal_vfree(param.value);
        return ERRCODE_SLE_MEMCPY_FAIL;
    }

    ssaps_notify_indicate(SLE_AIR_MOUSE_DEFAULT_SERVER_ID, SLE_AIR_MOUSE_DEFAULT_CONNECT_ID, &param);
    osal_vfree(param.value);
    return ERRCODE_SLE_SUCCESS;
}

static void ble_enable_cbk(uint8_t status)
{
    osal_printk("enable status:%d\r\n", status);
    g_sle_enable = true;
}

static void bt_core_enable_cb_register(void)
{
    sle_dev_manager_callbacks_t dev_cbks = { 0 };
    dev_cbks.sle_enable_cb = ble_enable_cbk;
    if (sle_dev_manager_register_callbacks(&dev_cbks) != ERRCODE_BT_SUCCESS) {
        osal_printk("register sle_enable failed\r\n");
    }
}

static void imu_wakeup_init(void)
{
    osal_msleep(500); // 500:下发slp睡眠消息后，等该500ms后，再操作全系统睡眠

    // 不下电管脚和下电管脚使能切换
    uint32_t irq_status = osal_irq_lock();
    slp_sleep_pin_config(); // 配置SLP管脚
    (void)uapi_keyscan_suspend(0); // 配置按键管脚
    uapi_gpio_deinit();
    ulp_gpio_init();
    // 配置ulp唤醒管脚，绑定唤醒回调
    ulp_wakeup_congif(imu_wakeup_callback);
    osal_irq_restore(irq_status);

    // 关闭SLP时钟
    uapi_clock_control(CLOCK_CONTROL_XO_OUT_DISABLE, CLOCK_XO2DIE);

    // 移除 SLP 睡眠否决票
    uapi_pm_remove_sleep_veto(PM_VETO_ID_SLP);
    // 移除 MCU 睡眠否决票
    uapi_pm_remove_sleep_veto(PM_VETO_ID_MCU);
}

static void check_into_sleep(int16_t x, int16_t y)
{
    if ((g_last_x == x) && (g_last_y == y)) {
        g_static_count++;
    } else {
        g_static_count = 0;
    }

    g_last_x = x;
    g_last_y = y;

    // SLEEP_COUNT_THRESHOLD次相同报点,则进入睡眠
    if (g_static_count >= SLEEP_COUNT_THRESHOLD) {
        g_static_count = 0;
        // 下发slp睡眠消息
        ErrcodeSlpClient ret = SlpSleepCommand();
        if (ret != ERRCODE_SLPC_SUCCESS) {
            osal_printk("SlpSleepCommand Error 0x%x\r\n", ret);
        }
        g_sample_sleep = true;
    }
}

void cursor_report_cbk(int32_t x, int32_t y, uint8_t key_state)
{
    UNUSED(key_state);
    // 如果需要睡眠，此处调用
    if (CONFIG_LOW_POWER_MODE == 1) {
        check_into_sleep(x, y);
    }
}

void ranging_report_cbk(SlpRangingRpt *rangingRpt)
{
    g_ranging_report_cnt++;
    if (g_ranging_report_cnt % 20 != 0) {  // 20: 每20轮打印一次
        return;
    }
    g_ranging_report_cnt = 0;

    osal_printk("[slp rpt] d:%d mm,azi:%dx0.01 deg,f:%u,elev:%dx0.01 deg,f:%u",
        rangingRpt->distance, rangingRpt->aoxAzi, rangingRpt->aoxAziFom, rangingRpt->aoxElev, rangingRpt->aoxElevFom);
    uint8_t *pAddr = rangingRpt->providerAddr.addr;
    osal_printk("|pAddr:%02x:%02x:%02x:%02x:%02x:%02x",
        pAddr[0], pAddr[1], pAddr[2], pAddr[3], pAddr[4], pAddr[5]); // 1:idx,2:idx,3:idx,4:idx,5:idx
    uint8_t *rAddr = rangingRpt->requestorAddr.addr;
    osal_printk("|rAddr:%02x:%02x:%02x:%02x:%02x:%02x\r\n",
        rAddr[0], rAddr[1], rAddr[2], rAddr[3], rAddr[4], rAddr[5]); // 1:idx,2:idx,3:idx,4:idx,5:idx
}

static void rpt_errcode_cbk(ErrcodeSlpClient errcode)
{
    switch (errcode) {
        case ERRCODE_SLPC_LOCAL_IMU_READ_DATA:
            osal_printk("[ERROR]: rcu imu read data failed\r\n");
            break;
        case ERRCODE_SLPC_PEER_IMU_READ_DATA:
            osal_printk("[ERROR]: dongle imu read data failed\r\n");
            break;
        default:
            osal_printk("slp errcode: 0x%08x\r\n", errcode);
            break;
    }
}

static void rpt_cir_cbk(SlpCirRpt *cirRpt)
{
    if (cirRpt == NULL) {
        osal_printk("[ERROR][rpt_cir_cbk] cirRpt is null\r\n");
    }
    uint8_t role = cirRpt->role;
    if (role == 1) {
        osal_printk("Role is INITIATOR\r\n");
        osal_printk("Response Cir Bw:%u\r\n", cirRpt->bwPollOrResp);
        for (uint16_t i = 0; i < SLP_RANGING_CIR_RECORD_NUM; i = i + 10) { // 10: 10个一组
            osal_printk("Pwr: idx %u, %u %u %u %u %u %u %u %u %u %u\r\n", i,
                cirRpt->cirPwrPollOrResp[i], cirRpt->cirPwrPollOrResp[i + 1], // 1:索引
                cirRpt->cirPwrPollOrResp[i + 2], cirRpt->cirPwrPollOrResp[i + 3], // 2 3:索引
                cirRpt->cirPwrPollOrResp[i + 4], cirRpt->cirPwrPollOrResp[i + 5], // 4 5:索引
                cirRpt->cirPwrPollOrResp[i + 6], cirRpt->cirPwrPollOrResp[i + 7], // 6 7:索引
                cirRpt->cirPwrPollOrResp[i + 8], cirRpt->cirPwrPollOrResp[i + 9]); // 8 9:索引
        }
        osal_printk("Horizontal Aox Ant0 Bw:%u, Ant1 Bw:%u\r\n", cirRpt->bwHorizontalAox0, cirRpt->bwHorizontalAox1);
        // 前两百个IQ是ant0的, 后两个IQ是ant1的
        for (uint16_t i = 0; i < SLP_AOX_CIR_RECORD_NUM; i = i + 10) { // 10: 10个一组, 格式为 I Q I Q I Q I Q I Q
            osal_printk("IQ: idx %u, %d %d %d %d %d %d %d %d %d %d\r\n", i / 2, // 2:IQ
                cirRpt->horizontalAoxIq[i], cirRpt->horizontalAoxIq[i + 1], // 1:索引
                cirRpt->horizontalAoxIq[i + 2], cirRpt->horizontalAoxIq[i + 3], // 2 3:索引
                cirRpt->horizontalAoxIq[i + 4], cirRpt->horizontalAoxIq[i + 5], // 4 5:索引
                cirRpt->horizontalAoxIq[i + 6], cirRpt->horizontalAoxIq[i + 7], // 6 7:索引
                cirRpt->horizontalAoxIq[i + 8], cirRpt->horizontalAoxIq[i + 9]); // 8 9:索引
        }
    }
}

static void rpt_version_cbk(
    SlpVersionRpt *narrowVersion, SlpVersionRpt *wideVersion, uint32_t chipId, SlpImuType imuType)
{
    // 打印SLP版本号
    osal_printk("_VERSION_ Narrow Band: %u.%u.%u, Wide Band: %u.%u.%u, chipId: 0x%02X, imuType: 0x%02X\r\n",
        narrowVersion->major, narrowVersion->minor, narrowVersion->patch, wideVersion->major, wideVersion->minor,
        wideVersion->patch, chipId, imuType);
}

static void rpt_cfo_cbk(int32_t cfo, uint32_t threshold)
{
    // 打印cfo和阈值
    osal_printk("cfo:%dx0.01ppm, threshold:%ux0.01ppm\r\n", cfo, threshold);
    if ((uint32_t)abs(cfo) > threshold) {
        osal_printk("[ERR] cfo is exceed threshold\r\n");
    }
}

static void register_slp_report_callback(void)
{
    SlpReportCallbacks cbks = {0};
    cbks.rptRangingCbk = ranging_report_cbk;
    cbks.rptErrcodeCbk = rpt_errcode_cbk;
    cbks.rptCirCbk = rpt_cir_cbk;
    cbks.rptVersionCbk = rpt_version_cbk;
    cbks.rptCfoCbk = rpt_cfo_cbk;
    if (SlpRegisterReportCallbacks(&cbks) != ERRCODE_SLPC_SUCCESS) {
        osal_printk("register slp_report_callback failed\r\n");
    }
}

void server_send_slp_payload_cbk(const SlpPayloadInfo *info)
{
    sle_air_mouse_server_send_slp_payload(info->payload, info->payloadLen);
}

static void slp_power_on_cbk(ErrcodeSlpClient errcode)
{
    osal_printk("slp_power_on_cbk errcode: 0x%x, duration: %u ms\r\n", errcode,
        (uint32_t)(uapi_tcxo_get_ms() - g_power_on_start_time));
    g_start_ranging_times = 0; // 复位

    // 如果SLE已配对, 且上电加载完成，则启动测距
    if (g_mouse_sle_pair_status == 0 && errcode == ERRCODE_SLPC_SUCCESS) {
#if CONFIG_SAMPLE_SUPPORT_AIR_MOUSE_CIR_PRINT
        SlpEnCirReportCommand();
#endif
        // 启动测距
        g_start_ranging_start_time = uapi_tcxo_get_ms();
        SlpStartRangingParam param = {0};
        set_slp_start_ranging_param(&param);
        errcode = SlpStartRangingCommand(&param);
        if (errcode != ERRCODE_SLPC_SUCCESS) {
            osal_printk("SlpStartRangingCommand Error 0x%x\r\n", errcode);
            return;
        }
        g_start_ranging_times++;
    } else {
        osal_printk("slp_power_on_cbk Error 0x%x\r\n", errcode);
    }
}

static void slp_start_ranging_cbk(ErrcodeSlpClient errcode)
{
    osal_printk("slp_start_ranging_cbk errcode: 0x%x\r\n", errcode);

    // 如果上电或低功耗后已启动10次测距，则不再重复启动
    if (g_start_ranging_times >= 10) {
        osal_printk("slp start ranging times: %u\r\n", g_start_ranging_times);
        return;
    }

    // 启动测距出错时(未收到dongle的payload)，如果配对正常，则间隔500ms重新启动测距
    if (g_mouse_sle_pair_status == 0 && errcode == ERRCODE_SLPC_RECV_PAYLOAD_FAILED) {
        osal_msleep(500); // 500:500ms
        // 启动测距
        SlpStartRangingParam param = {0};
        set_slp_start_ranging_param(&param);
        g_start_ranging_times++;
        errcode = SlpStartRangingCommand(&param);
        if (errcode != ERRCODE_SLPC_SUCCESS) {
            osal_printk("SlpStartRangingCommand Error 0x%x\r\n", errcode);
            return;
        }
    }
}

static void slp_stop_ranging_cbk(ErrcodeSlpClient errcode)
{
    osal_printk("slp_stop_ranging_cbk errcode: 0x%x\r\n", errcode);
}

static void slp_power_off_cbk(ErrcodeSlpClient errcode)
{
    osal_printk("slp_power_off_cbk Error 0x%x\r\n", errcode);
    if (errcode != ERRCODE_SLPC_SUCCESS) {
        osal_printk("slp_power_off_cbk Error 0x%x\r\n", errcode);
        return;
    }
}

static void slp_sleep_cbk(ErrcodeSlpClient errcode)
{
    osal_printk("slp_sleep_cbk errcode: 0x%x\r\n", errcode);

    // 如果不是sample逻辑发送的睡眠指令，则不进行后续操作
    if (!g_sample_sleep) {
        return;
    }

    g_sample_sleep = false;
    // 如果SLP睡眠完成，则更新SLE interval
    if (errcode == ERRCODE_SLPC_SUCCESS) {
        imu_wakeup_init();
        // 更新SLE的interval为10ms
        sle_conn_param_update(80, 30, 500); // 80: 10ms interval, 30: latency, 500: supervision_timeout
    } else {
        osal_printk("slp_sleep_cbk Error 0x%x\r\n", errcode);
    }
}

static void slp_set_local_att_cbk(ErrcodeSlpClient errcode)
{
    osal_printk("slp_set_local_att_cbk errcode: 0x%x\r\n", errcode);
}

static void slp_pause_ranging_cbk(ErrcodeSlpClient errcode)
{
    osal_printk("slp_pause_ranging_cbk errcode: 0x%x\r\n", errcode);
}

static void slp_continue_ranging_cbk(ErrcodeSlpClient errcode)
{
    osal_printk("slp_continue_ranging_cbk errcode: 0x%x\r\n", errcode);
}

void sle_server_slp_command_register_cbks(void)
{
    SlpCommandCallbacks cbks = {0};
    cbks.powerOnCbk = slp_power_on_cbk;
    cbks.startRangingCbk = slp_start_ranging_cbk;
    cbks.stopRangingCbk = slp_stop_ranging_cbk;
    cbks.powerOffCbk = slp_power_off_cbk;
    cbks.sleepCbk = slp_sleep_cbk;
    cbks.setLocalAttCbk = slp_set_local_att_cbk;
    cbks.pauseRangingCbk = slp_pause_ranging_cbk;
    cbks.continueRangingCbk = slp_continue_ranging_cbk;

    SlpRegisterCommandCallbacks(&cbks);
}

static void slp_report_gyro_zero_offset_cbk(SlpGyroZeroOffset *offset)
{
    osal_printk("[slp nv] update gyro zero offset, x:%d, y:%d, z:%d\r\n", offset->x, offset->y, offset->z);
}

void register_slp_factory_test_rpt_callback(void)
{
    // 从NV中读取陀螺仪零漂值
    SlpGyroZeroOffset offset;
    errcode_t ret = SlpReadGyroZeroOffset(&offset);
    osal_printk("[slp nv] init gyro zero offset, ret:0x%x, x:%d, y:%d, z:%d\r\n", ret, offset.x, offset.y, offset.z);

    SlpFactoryReportCallbacks cbks = {0};
    cbks.rptZeroOffsetCbk = slp_report_gyro_zero_offset_cbk;

    if (SlpRegisterFactoryReportCallbacks(&cbks) != ERRCODE_SLPC_SUCCESS) {
        osal_printk("[slp nv] reg fac rpt cbk failed\r\n");
    }
}

void sle_set_em_data(uint8_t enable)
{
    sle_low_latency_set_em_data(g_mouse_sle_conn_hdl, enable);
}

uint8_t *sle_low_latency_get_data_cbk(uint8_t *length, uint16_t *ssap_handle, uint8_t *data_type, uint16_t co_handle)
{
    unused(data_type);
    unused(co_handle);
    get_amic_encode_data(length, g_out_low_latency_data);
    *ssap_handle = rcu_get_handle();
    return g_out_low_latency_data;
}

void sle_set_em_data_cbk(uint16_t co_handle, uint8_t status)
{
    unused(status);
    unused(co_handle);
}

void sle_low_latency_cbk_reg(void)
{
    sle_low_latency_callbacks_t cbks = {0};
    cbks.hid_data_cb = sle_low_latency_get_data_cbk;
    cbks.sle_set_em_data_cb = sle_set_em_data_cbk;
    sle_low_latency_register_callbacks(&cbks);
}

errcode_t sle_air_mouse_server_init(void)
{
    g_announce_keyscan_flag = false;
    g_sample_sleep = false;
    g_ranging_report_cnt = 0;
    bt_core_enable_cb_register();
    while (g_sle_enable == false) {
        osal_msleep(USB_MOUSE_TASK_DELAY_MS);
        enable_sle();
    }
    sle_remove_all_pairs();
    sle_conn_register_cbks();
    sle_air_mouse_ssaps_register_cbks();

    /* 注册服务，handle值依次为2、4、6 ... */
    sle_air_mouse_server_add();   // slp数传
    sle_air_mouse_cursor_add();   // 鼠标坐标传输
    sle_air_mouse_cmd_add();      // 命令传输
    sle_air_mouse_keyboard_add(); // 键盘按键传输

    init_hid_report(); // 变量初始化
    register_slp_report_callback(); // 注册坐标上报、imu异常上报回调函数
    SlpRegisterSendPayloadCallback(server_send_slp_payload_cbk); // 注册server端 slp发送payload函数
    register_slp_factory_test_rpt_callback();

    sle_sample_dis_server_add();
    sle_air_mouse_server_adv_init();
    sle_add_ntf_service(g_server_id);
    sle_low_latency_cbk_reg();
    osal_printk("%s init ok\r\n", SLE_AIR_MOUSE_DONGLE_SERVER_LOG);
    return ERRCODE_SLE_SUCCESS;
}
