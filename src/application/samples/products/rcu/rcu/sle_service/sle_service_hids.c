/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * Description: SLE SERVICE HIDS \n
 *
 * History: \n
 * 2024-05-25, Create file. \n
 */
#include "securec.h"
#include "sle_errcode.h"
#include "sle_rcu_server.h"
#include "osal_addr.h"
#include "sle_service_common.h"
#include "sle_service_hids.h"

#define HID_DEVICE_TYPE_NUM              1
#define HID_REF_OFFSET                   2
#define HID_SERVICE_STEP                 3

#define SLE_HID_POINT 1
#define RCU_SEND_BUFF_LENGTH       20

static uint8_t g_server_id;
static uint8_t g_cccd[2] = {0x01, 0x0};
static sle_item_handle_t g_hid_service_hdl[SLE_HID_INDEX_MAX] = {0};

#define input(size)             (0x80 | (size))
#define output(size)            (0x90 | (size))
#define feature(size)           (0xb0 | (size))
#define collection(size)        (0xa0 | (size))
#define end_collection(size)    (0xc0 | (size))

/* Global items */
#define usage_page(size)        (0x04 | (size))
#define logical_minimum(size)   (0x14 | (size))
#define logical_maximum(size)   (0x24 | (size))
#define physical_minimum(size)  (0x34 | (size))
#define physical_maximum(size)  (0x44 | (size))
#define uint_exponent(size)     (0x54 | (size))
#define uint(size)              (0x64 | (size))
#define report_size(size)       (0x74 | (size))
#define report_id(size)         (0x84 | (size))
#define report_count(size)      (0x94 | (size))
#define push(size)              (0xa4 | (size))
#define pop(size)               (0xb4 | (size))

/* Local items */
#define usage(size)                 (0x08 | (size))
#define usage_minimum(size)         (0x18 | (size))
#define usage_maximum(size)         (0x28 | (size))
#define designator_index(size)      (0x38 | (size))
#define designator_minimum(size)    (0x48 | (size))
#define designator_maximum(size)    (0x58 | (size))
#define string_index(size)          (0x78 | (size))
#define string_minimum(size)        (0x88 | (size))
#define string_maximum(size)        (0x98 | (size))
#define delimiter(size)             (0xa8 | (size))

static uint8_t g_sle_report_map_datas[] = {
    usage_page(1),      0x01,
    usage(1),           0x06,
    collection(1),      0x01,
    report_id(1),       0x01,
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
    logical_maximum(1), 0xFF,
    usage_page(1),      0x07,
    usage_minimum(1),   0x00,
    usage_maximum(1),   0xFF,
    input(1),           0x00,
    end_collection(0),

    usage_page(1),      0x0C,
    usage(1),           0x01,
    collection(1),      0x01,
    report_id(1),       0x03,
    logical_minimum(1), 0x00,
    logical_maximum(2), 0xff, 0x1f,
    usage_minimum(1),   0x00,
    usage_maximum(2),   0xff, 0x1f,
    report_size(1),     0x10,
    report_count(1),    0x01,
    input(1),           0x00,
    end_collection(0),

    usage_page(1),      0x01,
    usage(1),           0x09,
    collection(1),      0x01,
    report_id(1),       0x02,
    usage(1),           0x81,
    logical_minimum(1), 0x00,
    logical_maximum(2), 0xff, 0x1f,
    usage_minimum(1),   0x00,
    usage_maximum(2),   0xff, 0x1f,
    report_size(1),     0x10,
    report_count(1),    0x01,
    input(1),           0x00,
    end_collection(0),

    usage_page(1),      0x01,
    usage(1),           0x02,
    collection(1),      0x01,
    report_id(1),       0x04,
    usage(1),           0x01,
    collection(1),      0x00,
    report_count(1),    0x03,
    report_size(1),     0x01,
    usage_page(1),      0x09,
    usage_minimum(1),   0x1,
    usage_maximum(1),   0x3,
    logical_minimum(1), 0x00,
    logical_maximum(1), 0x01,
    input(1),           0x02,
    report_count(1),    0x01,
    report_size(1),     0x05,
    input(1),           0x01,
    report_count(1),    0x03,
    report_size(1),     0x08,
    usage_page(1),      0x01,
    usage(1),           0x30,
    usage(1),           0x31,
    usage(1),           0x38,
    logical_minimum(1), 0x81,
    logical_maximum(1), 0x7f,
    input(1),           0x06,
    end_collection(0),
    end_collection(0),
};

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

static uint8_t g_hid_service_property[HID_ELEMENT_NUM] = {
    0,
    SSAP_OPERATE_INDICATION_BIT_READ | SSAP_OPERATE_INDICATION_BIT_NOTIFY,
    SSAP_OPERATE_INDICATION_BIT_READ | SSAP_OPERATE_INDICATION_BIT_WRITE_NO_RSP | SSAP_OPERATE_INDICATION_BIT_WRITE,
    SSAP_OPERATE_INDICATION_BIT_READ | SSAP_OPERATE_INDICATION_BIT_WRITE,
    SSAP_OPERATE_INDICATION_BIT_READ | SSAP_OPERATE_INDICATION_BIT_NOTIFY,
    SSAP_OPERATE_INDICATION_BIT_WRITE_NO_RSP,
};

static errcode_t sle_add_descriptor_interface(uint32_t properties, sle_service_hids_t* hid_service,
    uint16_t device_input)
{
    if (hid_service->cccd == NULL) {
        osal_printk("sle add descriptor interface param is NULL\r\n");
        return ERRCODE_SLE_FAIL;
    }
    ssaps_desc_info_t descriptor = {0};
    descriptor.permissions = SSAP_PERMISSION_READ | SSAP_PERMISSION_WRITE;
    descriptor.operate_indication = properties;
    descriptor.type = SSAP_DESCRIPTOR_CLIENT_CONFIGURATION;
    descriptor.value_len = hid_service->cccd_len;
    descriptor.value = hid_service->cccd;
    return ssaps_add_descriptor_sync(g_server_id,
        hid_service->item_handle[SLE_HID_INDEX_SERVICE].handle_out,
        hid_service->item_handle[device_input].handle_out, &descriptor);
}

static errcode_t sle_add_device_descriptor(sle_service_hids_t* hid_service, uint16_t index_multiple)
{
    errcode_t ret;
    uint16_t device_input = SLE_HID_INDEX_HID_CONTROL + 1 + HID_SERVICE_STEP * index_multiple;

    ret = sle_add_property(g_server_id, g_hid_service_property[HID_INDEX_REPORT],
        g_sle_hid_group_uuid[HID_INDEX_REPORT], SLE_INPUT_REPORT_LENGTH,
        hid_service->input_report, &hid_service->item_handle[device_input]);
    if (ret != ERRCODE_SLE_SUCCESS) {
        osal_printk("[uuid server] sle add report fail, ret:%x, indet:%x\r\n",
                    ret, SLE_HID_INDEX_KEYBOARD_INPUT);
        return ERRCODE_SLE_FAIL;
    }

    ret = sle_add_descriptor_interface(g_hid_service_property[HID_INDEX_CCCD], hid_service, device_input);
    if (ret != ERRCODE_SLE_SUCCESS) {
        osal_printk("[uuid server] sle add cccd fail, ret:%x, indet:%x\r\n",
                    ret, SLE_HID_INDEX_KEYBOARD_CCCD);
        return ERRCODE_SLE_FAIL;
    }

    hid_service->input_report_descriptor[0] = 0x1;   // [1] : report id
    hid_service->input_report_descriptor[1] = 0x1;   // [1] : input
    // [2] rpt handle low
    hid_service->input_report_descriptor[2] = hid_service->item_handle[device_input].handle_out;
    hid_service->input_report_descriptor[3] = 0;     // [3] rpt handle high

    ret = sle_add_property(g_server_id, g_hid_service_property[HID_INDEX_REF], g_sle_hid_group_uuid[HID_INDEX_REF],
        SLE_SRV_ENCODED_REPORT_LEN, hid_service->input_report_descriptor,
        &hid_service->item_handle[device_input + HID_REF_OFFSET]);
    if (ret != ERRCODE_SLE_SUCCESS) {
        osal_printk("[uuid server] sle add report ref fail, ret:%x, indet:%x\r\n",
                    ret, SLE_HID_INDEX_KEYBOARD_REF);
        return ERRCODE_SLE_FAIL;
    }
    return ret;
}

static errcode_t sle_hids_property_and_descriptor_add(sle_service_hids_t* hid_service)
{
    errcode_t ret = ERRCODE_SLE_SUCCESS;
    // report_map_datas
    ret = sle_add_property(g_server_id, g_hid_service_property[HID_INDEX_MAP], g_sle_hid_group_uuid[HID_INDEX_MAP],
        hid_service->map_data_len, hid_service->report_map_datas, &hid_service->item_handle[SLE_HID_INDEX_REPORT_MAP]);
    if (ret != ERRCODE_SLE_SUCCESS) {
        osal_printk("[uuid server] sle add report map ref fail, ret:%x, index:%x\r\n",
                    ret, SLE_HID_INDEX_REPORT_MAP);
        return ret;
    }

    // control_point
    ret = sle_add_property(g_server_id, g_hid_service_property[HID_INDEX_CONTROL],
        g_sle_hid_group_uuid[HID_INDEX_CONTROL], sizeof(hid_service->hid_control_point),
        &hid_service->hid_control_point, &hid_service->item_handle[SLE_HID_INDEX_HID_CONTROL]);
    if (ret != ERRCODE_SLE_SUCCESS) {
        osal_printk("[uuid server] sle add hid ctrl point fail, ret:%x, index:%x\r\n",
                    ret, SLE_HID_INDEX_HID_CONTROL);
        return ret;
    }

    for (uint16_t i = 0; i < HID_DEVICE_TYPE_NUM; i++) {
        ret = sle_add_device_descriptor(hid_service, i);
    }

    return ERRCODE_SLE_SUCCESS;
}

static errcode_t sle_rcu_hid_service_add(sle_service_hids_t* hid_service)
{
    errcode_t ret = ERRCODE_SLE_SUCCESS;
    
    // add HID service
    ret = sle_service_add(g_server_id, g_sle_hid_group_uuid[HID_INDEX_SERVICE],
        hid_service->item_handle, SLE_HID_INDEX_SERVICE, SLE_HID_INDEX_MAX);
    if (ret != ERRCODE_SLE_SUCCESS) {
        return ERRCODE_SLE_FAIL;
    }

    if (sle_hids_property_and_descriptor_add(hid_service) != ERRCODE_SLE_SUCCESS) {
        return ERRCODE_SLE_FAIL;
    }

    ret = ssaps_start_service(g_server_id, hid_service->item_handle[SLE_HID_INDEX_SERVICE].handle_out);
    if (ret != ERRCODE_SLE_SUCCESS) {
        osal_printk("%s sle rcu add HID service fail, ret:%x\r\n", SLE_RCU_SERVER_LOG, ret);
        return ERRCODE_SLE_FAIL;
    }
    return ERRCODE_SLE_SUCCESS;
}

errcode_t sle_add_hid_service(uint8_t server_id)
{
    uint8_t sle_input_report[SLE_INPUT_REPORT_LENGTH] = {0};
    uint8_t input_report_descriptor[SLE_SRV_ENCODED_REPORT_LEN] = {0};
    g_server_id = server_id;
    sle_service_hids_t hid_service = { 0 };
    hid_service.hid_control_point = SLE_HID_POINT;
    hid_service.cccd = g_cccd;
    hid_service.cccd_len = sizeof(g_cccd);
    hid_service.input_report = sle_input_report;
    hid_service.input_report_descriptor = input_report_descriptor;
    hid_service.report_map_datas = g_sle_report_map_datas;
    hid_service.map_data_len = sizeof(g_sle_report_map_datas);
    hid_service.item_handle = g_hid_service_hdl;
    errcode_t ret = sle_rcu_hid_service_add(&hid_service);
    if (ret != ERRCODE_SLE_SUCCESS) {
        osal_printk("%s sle_add_hid_service fail, ret:%x\r\n", SLE_RCU_SERVER_LOG, ret);
        return ret;
    }
    return ERRCODE_SLE_SUCCESS;
}

/* device通过handle向host发送数据：report */
errcode_t sle_rcu_server_send_report_by_handle(const uint8_t *data, uint8_t len, uint16_t conn_id)
{
    ssaps_ntf_ind_t param = { 0 };
    uint8_t receive_buf[RCU_SEND_BUFF_LENGTH] = { 0 }; /* max receive length. */
    param.handle = g_hid_service_hdl[SLE_HID_INDEX_KEYBOARD_INPUT].handle_out;
    param.type = SSAP_PROPERTY_TYPE_VALUE;
    param.value = receive_buf;
    param.value_len = len;
    if (memcpy_s(param.value, param.value_len, data, len) != EOK) {
        return ERRCODE_SLE_FAIL;
    }
    return ssaps_notify_indicate(g_server_id, conn_id, &param);
}