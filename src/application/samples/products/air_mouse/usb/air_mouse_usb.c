/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2022-2025. All rights reserved.
 *
 * Description: Air Mouse USB Source. \n
 *
 * History: \n
 * 2025-09-15, Create file. \n
 */
#include "air_mouse_usb.h"
#include <math.h>
#include <stdbool.h>
#include "common_def.h"
#include "console.h"
#include "gadget/f_hid.h"
#include "gadget/usbd_acm.h"
#include "implementation/usb_init.h"
#include "gadget/f_uac.h"
#include "osal_debug.h"
#include "securec.h"
#include "slp_factory.h"
#include "soc_osal.h"
#include "tcxo.h"
#include "sle_device_discovery.h"
#include "sle_connection_manager.h"
#if CONFIG_SAMPLE_SUPPORT_AIR_MOUSE_DONGLE
#include "../dongle/radar/air_mouse_radar.h"
#include "../dongle/sle_air_mouse_client/sle_air_mouse_client.h"
#endif

#define USB_MANUFACTURER           { 'H', 0, 'H', 0, 'H', 0, 'H', 0, 'l', 0, 'i', 0, 'c', 0, 'o', 0, 'n', 0 }
#define USB_MANUFACTURER_LEN       20
#define USB_PRODUCT                { 'S', 0, 'L', 0, 'P', 0, ' ', 0, 'T', 0, 'V', 0, ' ', 0, 'U', 0, 'S', 0, 'B', 0 }
#define USB_PRODUCT_LEN            22
#define USB_SERIAL                 { '2', 0, '0', 0, '2', 0, '0', 0, '0', 0, '6', 0, '2', 0, '4', 0 }
#define USB_SERIAL_LEN             16

#define USB_RECV_DATA_MAX_LEN      512 // USB_HIGH_SPEED:512字节一包, USB_FULL_SPEED:64字节一包, 超过会分包传
#define USB_RECV_DATA_FAIL_DELAY   50
#define USB_SERIAL_RECV_TASK_STACK_SIZE   (0x800)
#define USB_RECV_TASK_PRIO         (26)
#define USB_RECV_BREAK_LEN         5

#define UAC_BUFFER_COUNT           4
#define UAC_BUFFER_LEN             512

/* HID */
#define input(size)                (0x80 | (size))
#define output(size)               (0x90 | (size))
#define feature(size)              (0xb0 | (size))
#define collection(size)           (0xa0 | (size))
#define end_collection(size)       (0xc0 | (size))
#define usage_page(size)           (0x04 | (size))
#define logical_minimum(size)      (0x14 | (size))
#define logical_maximum(size)      (0x24 | (size))
#define physical_minimum(size)     (0x34 | (size))
#define physical_maximum(size)     (0x44 | (size))
#define uint_exponent(size)        (0x54 | (size))
#define uint(size)                 (0x64 | (size))
#define report_size(size)          (0x74 | (size))
#define report_id(size)            (0x84 | (size))
#define report_count(size)         (0x94 | (size))
#define push(size)                 (0xa4 | (size))
#define pop(size)                  (0xb4 | (size))
#define usage(size)                (0x08 | (size))
#define usage_minimum(size)        (0x18 | (size))
#define usage_maximum(size)        (0x28 | (size))
#define designator_index(size)     (0x38 | (size))
#define designator_minimum(size)   (0x48 | (size))
#define designator_maximum(size)   (0x58 | (size))
#define string_index(size)         (0x78 | (size))
#define string_minimum(size)       (0x88 | (size))
#define string_maximum(size)       (0x98 | (size))
#define delimiter(size)            (0xa8 | (size))

/* HID 报文数据限制 */
#define MIN_X 0
#define MAX_X 21240
#define MIN_Y 0
#define MAX_Y 15980

static const uint8_t g_report_desc_hid[ ] = {
    // Integrated Windows Pen TLC
    usage_page(1), 0x0d,               // USAGE_PAGE (Digitizers)
    usage(1), 0x03,                    // USAGE (Light Pen)
    collection(1), 0x01,               // COLLECTION (Application)
    report_id(1), HID_PEN_KIND,        //   REPORT_ID (Pen)
    usage(1), 0x20,                    //   USAGE (Stylus)
    collection(1), 0x00,               //   COLLECTION (Physical)
    usage(1), 0x42,                    //     USAGE (Tip Switch)
    usage(1), 0x44,                    //     USAGE (Barrel Switch)
    usage(1), 0x3c,                    //     USAGE (Invert)
    usage(1), 0x45,                    //     USAGE (Eraser Switch)
    logical_minimum(1), 0x00,          //     LOGICAL_MINIMUM (0)
    logical_maximum(1), 0x01,          //     LOGICAL_MAXIMUM (1)
    report_size(1), 0x01,              //     REPORT_SIZE (1)
    report_count(1), 0x04,             //     REPORT_COUNT (4)
    input(1), 0x02,                    //     INPUT (Data,Var,Abs)
    report_count(1), 0x01,             //     REPORT_COUNT (1)
    input(1), 0x03,                    //     INPUT (Cnst,Var,Abs)
    usage(1), 0x32,                    //     USAGE (In Range)
    input(1), 0x02,                    //     INPUT (Data,Var,Abs)
    report_count(1), 0x02,             //     REPORT_COUNT (2)
    input(1), 0x03,                    //     INPUT (Cnst,Var,Abs)
    usage_page(1), 0x01,               //     USAGE_PAGE (Generic Desktop)
    usage(1), 0x30,                    //     USAGE (X)
    report_size(1), 0x10,              //     REPORT_SIZE (16)
    report_count(1), 0x01,             //     REPORT_COUNT (1)
    push(0),                           //     PUSH
    uint_exponent(1), 0x0d,            //     UNIT_EXPONENT (-3)
    uint(1), 0x13,                     //     UNIT (Inch,EngLinear)
    physical_minimum(2), (uint8_t)MIN_X, (uint8_t)(MIN_X >> 8),  //  PHYSICAL_MINIMUM (0)
    physical_maximum(2), (uint8_t)MAX_X, (uint8_t)(MAX_X >> 8),  //  PHYSICAL_MAXIMUM (21240)
    logical_minimum(2), (uint8_t)MIN_X, (uint8_t)(MIN_X >> 8),   //  LOGICAL_MINIMUM (0)
    logical_maximum(2), (uint8_t)MAX_X, (uint8_t)(MAX_X >> 8),   //  LOGICAL_MAXIMUM (21240)
    input(1), 0x02,                    //     INPUT (Data,Var,Abs)
    usage(1), 0x31,                    //     USAGE (Y)
    physical_minimum(2), (uint8_t)MIN_Y, (uint8_t)(MIN_Y >> 8),  //  PHYSICAL_MINIMUM (0)
    physical_maximum(2), (uint8_t)MAX_Y, (uint8_t)(MAX_Y >> 8),  //  PHYSICAL_MAXIMUM (15980)
    logical_minimum(2), (uint8_t)MIN_Y, (uint8_t)(MIN_Y >> 8),   //  LOGICAL_MINIMUM (0)
    logical_maximum(2), (uint8_t)MAX_Y, (uint8_t)(MAX_Y >> 8),   //  LOGICAL_MAXIMUM (15980)
    input(1), 0x02,                    //     INPUT (Data,Var,Abs)
    pop(0),                            //     POP
    usage_page(1), 0x0d,               //     USAGE_PAGE (Digitizers)
    usage(1), 0x30,                    //     USAGE (Tip Pressure)
    logical_maximum(2), 0xff, 0x00,    //     LOGICAL_MAXIMUM (255)
    input(1), 0x02,                    //     INPUT (Data,Var,Abs)
    report_size(1), 0x08,              //     REPORT_SIZE (8)
    usage(1), 0x3d,                    //     USAGE (X Tilt)
    logical_minimum(1), 0x81,          //     LOGICAL_MINIMUM (-127)
    logical_maximum(1), 0x7f,          //     LOGICAL_MAXIMUM (127)
    input(1), 0x02,                    //     INPUT (Data,Var,Abs)
    usage(1), 0x3e,                    //     USAGE (Y Tilt)
    logical_minimum(1), 0x81,          //     LOGICAL_MINIMUM (-127)
    logical_maximum(1), 0x7f,          //     LOGICAL_MAXIMUM (127)
    input(1), 0x02,                    //     INPUT (Data,Var,Abs)
    end_collection(0),                 //   END_COLLECTION
    end_collection(0),                 // END_COLLECTION
    /* 键盘输入 */
    usage_page(1),      0x01,
    usage(1),           0x06,
    collection(1),      0x01,
    report_id(1),       HID_KEYBOARD_KIND,
    usage_page(1),      0x07,
    usage_minimum(1),   0xE0,
    usage_maximum(1),   0xE7,
    logical_minimum(1), 0x00,
    logical_maximum(1), 0x01,
    report_size(1),     0x01,
    report_count(1),    0x08,
    input(1),           0x02,
    report_count(1),    0x01,
    report_size(1),     0x08,
    input(1),           0x01,
    report_count(1),    0x05,
    report_size(1),     0x01,
    usage_page(1),      0x08,
    usage_minimum(1),   0x01,
    usage_maximum(1),   0x05,
    output(1),          0x02,
    report_count(1),    0x01,
    report_size(1),     0x03,
    output(1),          0x01,
    report_count(1),    0x06,
    report_size(1),     0x08,
    logical_minimum(1), 0x00,
    logical_maximum(1), 0x65,
    usage_page(1),      0x07,
    usage_minimum(1),   0x00,
    usage_maximum(1),   0x65,
    input(1),           0x00,
    end_collection(0),
    // Consumer
    usage_page(1),      0x0C,
    usage(1),           0x01,
    collection(1),      0x01,
    report_id(1),       HID_CONSUMER_KIND,
    logical_minimum(1), 0x00,
    logical_maximum(2), 0xff, 0x1f,
    usage_minimum(1),   0x00,
    usage_maximum(2),   0xff, 0x1f,
    report_size(1),     0x10,
    report_count(1),    0x01,
    input(1),           0x00,
    end_collection(0),
};

typedef enum {
    SERIAL_CMD_WRITE_CALIPARA_2_ONB = 0, // 向对端写入校准值
    SERIAL_CMD_READ_CALIPARA_FROM_ONB,   // 从对端读取校准值
    SERIAL_CMD_WRITE_TRX_DELAY_FROM_ONB, // 向对端写入板级和天线的时延校准值
    SERIAL_CMD_READ_TRX_DELAY_FROM_ONB,  // 从对端读取板级和天线的时延校准值
    SERIAL_CMD_RESTART,                  // 重启测距，切换至产测模式
} serial_cmd_type;

#pragma pack(1)
typedef struct {
    uint8_t cmd_type; // serial_cmd_type
    SlpAoxCaliPara cali_para;
    uint32_t trxDelay;
} serial_cmd_msg_t;
#pragma pack()

static bool g_usb_inited = false;
static char g_usb_recv_data[USB_RECV_DATA_MAX_LEN];
static int32_t g_usb_index = 0;
int16_t g_cursor_coordinate_x = 0; // 光标x轴坐标，单位：像素
int16_t g_cursor_coordinate_y = 0; // 光标y轴坐标，单位：像素
uint16_t g_screen_width;           // 屏幕宽度, 单位: mm
uint16_t g_screen_height;          // 屏幕高度, 单位: mm
bool g_usb_init_success_flag = false;

bool get_usb_init_status(void)
{
    return g_usb_inited;
}

static void usb_init_success_flag_cbk(void)
{
    osal_printk("usb init success cbk\r\n");
    g_usb_init_success_flag = true;
}

bool get_usb_init_success_flag(void)
{
    return g_usb_init_success_flag;
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

bool get_usb_status(void)
{
    return g_usb_inited;
}

int32_t get_usb_index(void)
{
    return g_usb_index;
}

// 判断是否在屏幕外
static bool check_cursor_out_of_screen(SlpCursorRslt *cursor_report)
{
    return cursor_report->x < 0 || cursor_report->x > (g_screen_width * MM_TO_UM) || // x出边框判断
           cursor_report->y < 0 || cursor_report->y > (g_screen_height * MM_TO_UM);  // y出边框判断
}

// 线性映射[m,n]->[lower, upper]
int32_t linear_map(int32_t input, int32_t m, int32_t n, int32_t lower, int32_t upper)
{
    // 除零保护
    if (m == n) {
        return lower; // 如果输出范围相同, 返回lower (或upper, 因为lower == upper)
    }
    // 归一化处理
    float normalized_value = (float)(input - m) / (n - m);
    // 线性映射到目标范围
    float mapped_value = lower + normalized_value * (upper - lower);
    // 四舍五入到最近的整数
    int32_t rounded_value = (int32_t)round(mapped_value);
    // 确保结果在[lower, upper]范围内
    int32_t clamped_value = (int32_t)fmax(lower, fmin(rounded_value, upper));
    return clamped_value;
}

// 更新屏幕光标
void usb_send_cursor_report(SlpCursorRslt *cursor_report)
{
    static usb_hid_pen_t hid_pen_report = {0}; // 触控笔报文数组
    hid_pen_report.kind = HID_PEN_KIND;
    hid_pen_report.tipPressure = 255; // 255：触控笔按压力度

    if (check_cursor_out_of_screen(cursor_report)) { // 屏幕外不显示光标
        hid_pen_report.control.bits.in_range = 0;    // 该参数对部分设备无效
        hid_pen_report.control.bits.tip = 0;
        hid_pen_report.x = INT16_MAX;
        hid_pen_report.y = INT16_MAX;
    } else { // 屏幕内
        hid_pen_report.control.bits.in_range = 1;
        hid_pen_report.control.bits.tip = cursor_report->key; // 是否点击
        // 物理坐标映射至HID logical坐标
        // [0, g_screen_width] -> [MIN_X, MAX_X]
        // [0, g_screen_height] -> [MIN_Y, MAX_Y]
        hid_pen_report.x = linear_map(cursor_report->x, 0, g_screen_width * MM_TO_UM, MIN_X, MAX_X);
        hid_pen_report.y = linear_map(cursor_report->y, 0, g_screen_height * MM_TO_UM, MIN_Y, MAX_Y);
    }

    static uint8_t count = 0;
    size_t ret = fhid_send_data(g_usb_index, (char *)(&hid_pen_report), sizeof(usb_hid_pen_t));
    if (ret != sizeof(usb_hid_pen_t)) {
        if (++count == 120) { // 120:减少打印次数
            osal_printk("[ERR] cursor send fail, size:%u, ret:%d\r\n", sizeof(usb_hid_pen_t), ret);
            count = 0;
        }
    }
}

void usb_send_keyboard_report(usb_hid_keyboard_report_t *report)
{
    report->kind = HID_KEYBOARD_KIND;
    size_t ret = fhid_send_data(g_usb_index, (char *)(report), sizeof(usb_hid_keyboard_report_t));
    if (ret != sizeof(usb_hid_keyboard_report_t)) {
        osal_printk("send keyboard fail, 0x%x\r\n", ret);
    }
    osal_printk("usb send keyboard, key:%u\r\n", report->key[0]);
}

void usb_send_consumer_report(usb_hid_consumer_report_t *report)
{
    report->kind = HID_CONSUMER_KIND;
    size_t ret = fhid_send_data(g_usb_index, (char *)(report), sizeof(usb_hid_consumer_report_t));
    if (ret != sizeof(usb_hid_consumer_report_t)) {
        osal_printk("send consumer fail, 0x%x\r\n", ret);
    }
    osal_printk("usb send consumer, key:%u, %u\r\n", report->comsumer_key0, report->comsumer_key1);
}

void usb_send_serial_data(const char *buffer, uint16_t len)
{
    ssize_t ret = usb_serial_write(g_usb_index, buffer, len);
    if (ret != len) {
        osal_printk("send serial data fail:%s, ret:%d, len:%u\n", buffer, ret, len);
    }
}

void serial_cmd_proc(serial_cmd_msg_t *serial_cmd_msg)
{
    switch (serial_cmd_msg->cmd_type) {
        case SERIAL_CMD_WRITE_CALIPARA_2_ONB:
            SlpWriteAoxCaliPara2Onb(&serial_cmd_msg->cali_para);
            break;
        case SERIAL_CMD_READ_CALIPARA_FROM_ONB:
            SlpReadAoxCaliParaFromOnb();
            break;
        case SERIAL_CMD_WRITE_TRX_DELAY_FROM_ONB:
            SlpWriteTrxDelay2Onb(serial_cmd_msg->trxDelay);
            break;
        case SERIAL_CMD_READ_TRX_DELAY_FROM_ONB:
            SlpReadTrxDelayFromOnb();
            break;
        case SERIAL_CMD_RESTART:
#if CONFIG_SAMPLE_SUPPORT_AIR_MOUSE_DONGLE
            air_mouse_radar_stop(); // 校准时不开启雷达功能
            SlpSetFactoryTestMode(SLP_FACTORY_TEST_AOX_CALI);
            air_mouse_radar_stop();
            sle_air_mouse_client_send_cmd(AM_CMD_RANGING_RESTART);
#else
            osal_printk("cmd restart not support\r\n");
#endif
            break;
        default:
            osal_printk("undefined cmd: %u\r\n", serial_cmd_msg->cmd_type);
            break;
    }
}

static int usb_serial_recv_data(void *data)
{
    unused(data);
    usb_serial_ioctl(0, CONSOLE_CMD_RD_BLOCK_SERIAL, 1);
    for (;;) {
        ssize_t recv_len = usb_serial_read(0, g_usb_recv_data, USB_RECV_DATA_MAX_LEN);
        if (recv_len <= 0) {
            osal_msleep(USB_RECV_DATA_FAIL_DELAY);
            osal_printk("serial recv fail, %d\r\n", recv_len);
            continue;
        }
#if CONFIG_AIR_MOUSE_CI_REPLAY_TEST
        ErrcodeSlpClient ret = SendCiTestData((uint8_t *)g_usb_recv_data, recv_len);
        if (ret != ERRCODE_SLPC_SUCCESS) {
            osal_printk("send test data fail, ret:0x%x\r\n", ret);
        }
#else
        if (recv_len == sizeof(serial_cmd_msg_t)) { // 校准命令
            serial_cmd_msg_t serial_cmd_msg;
            (void)memcpy_s(&serial_cmd_msg, sizeof(serial_cmd_msg_t), &g_usb_recv_data, recv_len);
            serial_cmd_proc(&serial_cmd_msg);
            osal_printk("recv cmd, len, %u, cmd, %u\r\n", recv_len, serial_cmd_msg.cmd_type);
        } else {
            osal_printk("recv len: %u\r\n", recv_len);
        }
        usb_serial_write(0, g_usb_recv_data, recv_len);

        if (memcmp(g_usb_recv_data, "break", USB_RECV_BREAK_LEN) == 0) { // 退出线程
            break;
        }
#endif
    }
    return -1;
}

static int air_mouse_usb_set_device_info(device_type dtype)
{
    // 制造商
    const char manufacturer[USB_MANUFACTURER_LEN] = USB_MANUFACTURER;
    struct device_string str_manufacturer = {
        .str = manufacturer,
        .len = USB_MANUFACTURER_LEN,
    };

    // 产品
    const char product[USB_PRODUCT_LEN] = USB_PRODUCT;
    struct device_string str_product = {
        .str = product,
        .len = USB_PRODUCT_LEN,
    };

    // 版本号
    const char serial[USB_SERIAL_LEN] = USB_SERIAL;
    struct device_string str_serial_number = {
        .str = serial,
        .len = USB_SERIAL_LEN,
    };

    // 设备版本
    struct device_id dev_id = {
        .vendor_id = 0x109B,
        .product_id = 0x3837,
        .release_num = 0x0800,
    };

    // 设置版本设备id
    if (usbd_set_device_info(dtype, &str_manufacturer, &str_product, &str_serial_number, dev_id) != 0) {
        return -1;
    }
    return 0;
}

static int slp_usb_init(device_type dtype)
{
    int32_t usb_index = -1;
    if (g_usb_inited == true) {
        return -1;
    }

    // 设置描述符
    if (dtype == DEV_SER_HID || dtype == DEV_HID) {
        usb_index = hid_add_report_descriptor(g_report_desc_hid, sizeof(g_report_desc_hid), 0);
    }

    // 设置版本设备id
    if (air_mouse_usb_set_device_info(dtype) != 0) {
        return -1;
    }

    // 切换usb为全速模式
    if (usb_device_set_speed(USB_HIGH_SPEED) != 0) {
        return -1;
    }

    if (usb_init(DEVICE, dtype) != 0) {
        return -1;
    }

#if CONFIG_AIR_MOUSE_UAC
    if (uac_wait_host(UAC_WAIT_HOST_FOREVER) != 0) {
        osal_printk("uac host can`t connect\r\n");
        return -1;
    }
#endif

    g_usb_inited = true;
    return usb_index;
}

#if CONFIG_AIR_MOUSE_UAC
static void uac_buf_init(void)
{
    int32_t ret = fuac_reqbuf_init(UAC_BUFFER_COUNT, UAC_BUFFER_LEN);
    if (ret != UAC_OK) {
        osal_printk("fuac eqbuf init fail! ret = %d\r\n", ret);
    }
}
#endif

int32_t vdt_usb_uac_send_data(const uint8_t *data1, int len1, const uint8_t *data2, int len2)
{
    uint32_t uac_buf_index;
    uint8_t *uac_buf = fuac_reqbuf_get(&uac_buf_index);
    if (uac_buf == NULL) {
        osal_printk("fuac reqbuf get failed.\r\n");
        return -1;
    }
    if (memcpy_s(uac_buf, UAC_BUFFER_LEN, data1, len1) != EOK) {
        osal_printk("uac memcpy first part data fail.\r\n");
    }
    if (memcpy_s(uac_buf + len1, UAC_BUFFER_LEN - len1, data2, len2) != EOK) {
        osal_printk("uac memcpy second part data fail.\r\n");
    }

    return fuac_send_message((void *)(uintptr_t)uac_buf, len1 + len2, uac_buf_index);
}

/* USB设备初始化 */
void air_mouse_usb_init(void)
{
    usb_init_success_flag_register_callbacks(usb_init_success_flag_cbk);
    g_usb_index = slp_usb_init(DEV_SER_HID); // 设置描述符、设备ID、版本号等，返回usb设备HID
    // uac_buf_init();
    osal_printk("usb init, %d\n", g_usb_index);
    if (g_usb_index < 0) {
        osal_printk("usb init fail\n");
    }

    /* 创建USB数据接收线程 */
    osal_task *task_handle = NULL;
    osal_kthread_lock(); // 创建任务前锁中断
    task_handle = osal_kthread_create(
        (osal_kthread_handler)usb_serial_recv_data, 0, "SlpUsbSerialRecvTask", USB_SERIAL_RECV_TASK_STACK_SIZE);
    if (task_handle != NULL) {
        osal_kthread_set_priority(task_handle, USB_RECV_TASK_PRIO); // 设置任务优先级
    }
    osal_kthread_unlock();
}

void air_mouse_usb_deinit(void)
{
    osal_printk("usb deinit\n");
    if (g_usb_inited == false) {
        return;
    }
    uint32_t ret = usb_deinit();
    if (ret != 0) {
        osal_printk("usb deinit fail, 0x%x", ret);
    }
    g_usb_inited = false;
}
