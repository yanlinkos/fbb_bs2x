/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2023-2024. All rights reserved. \r\n
 *
 * Description: Sle Air Mouse with dongle Client Source. \r\n
 * \r\n
 * History: \r\n
 * 2023-08-01, Create file. \r\n
 */
#include "sle_air_mouse_client.h"
#include <string.h>
#include "common_def.h"
#include "soc_osal.h"
#include "securec.h"
#include "bts_le_gap.h"
#include "sle_device_manager.h"
#include "sle_device_discovery.h"
#include "sle_connection_manager.h"
#include "sle_errcode.h"
#include "slp.h"
#include "vdt_codec.h"
#include "amic_voice.h"
#include "slp_factory.h"
#include "../../usb/air_mouse_usb.h"
#include "../../timer/am_common_timer.h"
#include "../radar/air_mouse_radar.h"

#define UUID_16BIT_LEN                      2
#define UUID_128BIT_LEN                     16

// 占空比计算公式：SLE_SEEK_WINDOW_DEFAULT/SLE_SEEK_INTERVAL_DEFAULT, 当前占空比为：50/100=50%
#define SLE_SEEK_INTERVAL_DEFAULT           100
#define SLE_SEEK_WINDOW_DEFAULT             50
#define SLE_UART_TASK_DELAY_MS              1000

#define SLE_AIR_MOUSE_DONGLE_CLIENT_LOG     "[sle air mouse dongle client]"

#define SLE_AIR_MOUSE_SSAP_RPT_HANDLE       0x11 // SLP数传HANDLE
#define SLE_AIR_MOUSE_CURSOR_RPT_HANDLE     0x16 // 鼠标坐标上报HANDLE
#define SLE_AIR_MOUSE_CMD_RPT_HANDLE        0x1B // 命令交互HANDLE
#define SLE_AIR_MOUSE_KEYBOARD_RPT_HANDLE   0x20 // 键盘按键上报HANDLE
#define SLE_AIR_MOUSE_AMIC_VOICE            0x29 // 语音数据

#define SLE_AIR_MOUSE_DEFAULT_CLIENT_ID     1

static sle_dev_manager_callbacks_t g_sle_dev_mgr_cbk = { 0 };
static sle_announce_seek_callbacks_t g_sle_air_mouse_client_seek_cbk = { 0 };
static sle_connection_callbacks_t g_sle_air_mouse_client_connect_cbk = { 0 };
ssapc_callbacks_t g_ssapc_cbk = {0};
static sle_addr_t g_sle_air_mouse_server_addr = { 0 };
static uint16_t g_sle_air_mouse_client_conn_id = 0;
static uint8_t g_sle_air_mouse_client_conn_state = SLE_ACB_STATE_NONE;
static bool g_sle_enable = 0;
ssapc_find_service_result_t   g_find_service_result = {0};

static uint32_t g_recv_cursor_sequence_no = 0;  // 光标坐标消息接收序号
static uint32_t g_recv_key_sequence_no = 0;     // 按键消息接收序号
osal_event g_trans_event_id;

// 用于判定是否进睡眠的变量
static int32_t g_last_x = 0;
static int32_t g_last_y = 0;
static uint16_t g_static_count = 0;

sle_addr_t *get_sle_air_mouse_server_addr(void)
{
    return &g_sle_air_mouse_server_addr;
}

static void init_recv_sequence_no(void)
{
    g_recv_cursor_sequence_no = 0;
    g_recv_key_sequence_no = 0;
}

static SlpDeviceAddr g_air_mouse_dongle_addr = {{0x08, 0x02, 0x03, 0x04, 0x05, 0x06}}; // air mouse dongle的本机地址
static char g_serial_send_str[200];
const SlpDeviceAddr *get_slp_air_mouse_dongl_addr(void)
{
    return &g_air_mouse_dongle_addr;
}

#if CONFIG_SAMPLE_SUPPORT_AIR_MOUSE_SLE_ADDR_CHECK
static sle_addr_t g_local_addr = {
    SLE_ADDRESS_TYPE_PUBLIC,
    {
        CONFIG_SLE_DONGLE_SERVER_ADDR0, CONFIG_SLE_DONGLE_SERVER_ADDR1, CONFIG_SLE_DONGLE_SERVER_ADDR2,
        CONFIG_SLE_DONGLE_SERVER_ADDR3, CONFIG_SLE_DONGLE_SERVER_ADDR4, CONFIG_SLE_DONGLE_SERVER_ADDR5}
    };
#endif

uint8_t get_g_sle_air_mouse_client_conn_state(void)
{
    return g_sle_air_mouse_client_conn_state;
}

uint16_t get_g_sle_air_mouse_client_conn_id(void)
{
    return g_sle_air_mouse_client_conn_id;
}

static void sle_air_mouse_client_start_scan(void)
{
    sle_seek_param_t param = { 0 };
    param.own_addr_type = 0;
    param.filter_duplicates = 0;
    param.seek_filter_policy = 0;
    param.seek_phys = 1;
    param.seek_type[0] = 1;
    param.seek_interval[0] = SLE_SEEK_INTERVAL_DEFAULT;
    param.seek_window[0] = SLE_SEEK_WINDOW_DEFAULT;
    sle_set_seek_param(&param);
    sle_start_seek();
}

static void sle_air_mouse_client_sle_enable_cbk(uint8_t status)
{
    if (status != 0) {
        osal_printk("%s sle_air_mouse_client_sle_enable_cbk, status error\r\n", SLE_AIR_MOUSE_DONGLE_CLIENT_LOG);
    } else {
        g_sle_enable = true;
        sle_air_mouse_client_start_scan();
    }
}

static void sle_air_mouse_client_seek_enable_cbk(errcode_t status)
{
    if (status != 0) {
        osal_printk("%s sle_air_mouse_client_seek_enable_cbk, status error\r\n", SLE_AIR_MOUSE_DONGLE_CLIENT_LOG);
    }
}

static void sle_air_mouse_client_seek_result_info_cbk(sle_seek_result_info_t *seek_result)
{
    if (seek_result == NULL || seek_result->data == NULL) {
        osal_printk("%s status error\r\n", SLE_AIR_MOUSE_DONGLE_CLIENT_LOG);
        return;
    }
    uint8_t arr[] = {'s', 'l', 'e', '_', 'a', 'i', 'r', '_', 'm', 'o', 'u', 's', 'e'}; // 根据数据信息判断是否是目标设备
    if (memcmp(seek_result->data + 20, arr, sizeof(arr)) != 0) { // 20：偏移
        return;
    }
#if CONFIG_SAMPLE_SUPPORT_AIR_MOUSE_SLE_ADDR_CHECK
    if (memcmp(&seek_result->addr, &g_local_addr, sizeof(sle_addr_t)) != 0) { // 检查两端地址是否一致
        return;
    }
#endif
    g_sle_air_mouse_server_addr = seek_result->addr; // 保存对端地址
    sle_stop_seek();
}

static void sle_air_mouse_client_seek_disable_cbk(errcode_t status)
{
    if (status != 0) {
        osal_printk("%s sle_air_mouse_client_seek_disable_cbk, status error\r\n", SLE_AIR_MOUSE_DONGLE_CLIENT_LOG);
    } else {
        sle_connect_remote_device(&g_sle_air_mouse_server_addr);
    }
}

static void sle_air_mouse_client_seek_cbk_register(void)
{
    g_sle_dev_mgr_cbk.sle_enable_cb = sle_air_mouse_client_sle_enable_cbk;
    g_sle_air_mouse_client_seek_cbk.seek_enable_cb = sle_air_mouse_client_seek_enable_cbk;
    g_sle_air_mouse_client_seek_cbk.seek_result_cb = sle_air_mouse_client_seek_result_info_cbk;
    g_sle_air_mouse_client_seek_cbk.seek_disable_cb = sle_air_mouse_client_seek_disable_cbk;
    if (sle_announce_seek_register_callbacks(&g_sle_air_mouse_client_seek_cbk) != ERRCODE_BT_SUCCESS ||
        sle_dev_manager_register_callbacks(&g_sle_dev_mgr_cbk) != ERRCODE_BT_SUCCESS) {
        osal_printk("%s register ble_client_enable_cb failed\r\n", SLE_AIR_MOUSE_DONGLE_CLIENT_LOG);
    }
}

static void sle_air_mouse_client_pair_complete_cbk(uint16_t conn_id, const sle_addr_t *addr, errcode_t status)
{
    osal_printk("[uuid client] pair complete conn_id:%02x, status:0x%08x\r\n", conn_id, status);
    unused(addr);
    if (status == ERRCODE_SUCC) {
        init_recv_sequence_no();
        // SLE连接配对成功后，SLP上电，完成SLP加载
        ErrcodeSlpClient ret = SlpPowerOnCommand();
        if (ret != ERRCODE_SLPC_SUCCESS) {
            osal_printk("SlpPowerOnCommand Error 0x%x\r\n", ret);
        }
    } else {
        sle_remove_all_pairs();
        sle_start_seek();
    }
}

static void sle_air_mouse_client_connect_state_changed_cbk(uint16_t conn_id, const sle_addr_t *addr,
    sle_acb_state_t conn_state, sle_pair_state_t pair_state, sle_disc_reason_t disc_reason)
{
    osal_printk("%s conn state changed disc_reason:0x%x\r\n", SLE_AIR_MOUSE_DONGLE_CLIENT_LOG, disc_reason);
    g_sle_air_mouse_client_conn_id = conn_id;
    g_sle_air_mouse_client_conn_state = conn_state;
    if (conn_state == SLE_ACB_STATE_CONNECTED) {
        osal_printk("%s SLE_ACB_STATE_CONNECTED\r\n", SLE_AIR_MOUSE_DONGLE_CLIENT_LOG);
        if (pair_state == SLE_PAIR_NONE) {
            sle_pair_remote_device(addr);
        }
    } else if (conn_state == SLE_ACB_STATE_NONE) {
        osal_printk("%s SLE_ACB_STATE_NONE\r\n", SLE_AIR_MOUSE_DONGLE_CLIENT_LOG);
    } else if (conn_state == SLE_ACB_STATE_DISCONNECTED) {
        osal_printk("%s SLE_ACB_STATE_DISCONNECTED\r\n", SLE_AIR_MOUSE_DONGLE_CLIENT_LOG);
        // SLE断连后，SLP下电
        if (pair_state == SLE_PAIR_PAIRED) {
            sle_remove_all_pairs();
        }
        sle_start_seek();
        ErrcodeSlpClient ret = SlpPowerOffCommand();
        if (ret != ERRCODE_SLPC_SUCCESS) {
            osal_printk("SlpPowerOffCommand Error 0x%x\r\n", ret);
            return;
        }
    } else {
        osal_printk("%s status error\r\n", SLE_AIR_MOUSE_DONGLE_CLIENT_LOG);
    }
}

void read_rssi_callback(uint16_t conn_id, int8_t rssi, errcode_t status)
{
    unused(conn_id);
    unused(status);
    update_am_print_info_rssi(rssi);
}

static void sle_air_mouse_client_connect_cbk_register(void)
{
    g_sle_air_mouse_client_connect_cbk.connect_state_changed_cb = sle_air_mouse_client_connect_state_changed_cbk;
    g_sle_air_mouse_client_connect_cbk.pair_complete_cb = sle_air_mouse_client_pair_complete_cbk;
    g_sle_air_mouse_client_connect_cbk.read_rssi_cb = read_rssi_callback;
    sle_connection_register_callbacks(&g_sle_air_mouse_client_connect_cbk);
}

static void ssapc_exchange_info_cbk(uint8_t client_id, uint16_t conn_id, ssap_exchange_info_t *param,
    errcode_t status)
{
    osal_printk("[ssap client] pair complete client id:%d status:%d\r\n", client_id, status);
    osal_printk("[ssap client] exchange mtu, mtu size: %d, version: %d.\r\n",
        param->mtu_size, param->version);

    ssapc_find_structure_param_t find_param = {0};
    find_param.type = SSAP_FIND_TYPE_PRIMARY_SERVICE;
    find_param.start_hdl = 1;
    find_param.end_hdl = 0xFFFF;
    ssapc_find_structure(0, conn_id, &find_param);
}

static void ssapc_find_structure_cbk(uint8_t client_id, uint16_t conn_id, ssapc_find_service_result_t *service,
    errcode_t status)
{
    osal_printk("[ssap client] find structure cbk client: %d conn_id:%d status: %d \r\n",
        client_id, conn_id, status);
    osal_printk("[ssap client] find structure start_hdl:[0x%02x], end_hdl:[0x%02x], uuid len:%d\r\n",
        service->start_hdl, service->end_hdl, service->uuid.len);
    if (service->uuid.len == UUID_16BIT_LEN) {
        osal_printk("[ssap client] structure uuid:[0x%02x][0x%02x]\r\n",
            service->uuid.uuid[14], service->uuid.uuid[15]); /* 14 15: uuid index */
    } else {
        for (uint8_t idx = 0; idx < UUID_128BIT_LEN; idx++) {
            osal_printk("[ssap client] structure uuid[%d]:[0x%02x]\r\n", idx, service->uuid.uuid[idx]);
        }
    }
    g_find_service_result.start_hdl = service->start_hdl;
    g_find_service_result.end_hdl = service->end_hdl;
    if (memcpy_s(&g_find_service_result.uuid, sizeof(sle_uuid_t), &service->uuid, sizeof(sle_uuid_t)) != EOK) {
        osal_printk("%s sle find service result fail\r\n", SLE_AIR_MOUSE_DONGLE_CLIENT_LOG);
    }
}

static void ssapc_find_structure_cmp_cbk(uint8_t client_id, uint16_t conn_id,
    ssapc_find_structure_result_t *structure_result, errcode_t status)
{
    osal_printk("[ssap client] find structure cmp cbk client id:%d status:%d type:%d uuid len:%d \r\n",
        client_id, status, structure_result->type, structure_result->uuid.len);
    if (structure_result->uuid.len == UUID_16BIT_LEN) {
        osal_printk("[ssap client] find structure cmp cbk structure uuid:[0x%02x][0x%02x]\r\n",
            structure_result->uuid.uuid[14], structure_result->uuid.uuid[15]); /* 14 15: uuid index */
    } else {
        for (uint8_t idx = 0; idx < UUID_128BIT_LEN; idx++) {
            osal_printk("[ssap client] find structure cmp cbk structure uuid[%d]:[0x%02x]\r\n", idx,
                structure_result->uuid.uuid[idx]);
        }
    }
    uint8_t data[] = {0x11, 0x22, 0x33, 0x44};
    uint8_t len = sizeof(data);
    ssapc_write_param_t param = {0};
    param.handle = g_find_service_result.start_hdl;
    param.type = SSAP_PROPERTY_TYPE_VALUE;
    param.data_len = len;
    param.data = data;
    ssapc_write_req(0, conn_id, &param);
}

static void ssapc_find_property_cbk(uint8_t client_id, uint16_t conn_id,
    ssapc_find_property_result_t *property, errcode_t status)
{
    osal_printk("[ssap client] find property cbk, client id: %d, conn id: %d, operate ind: %d, "
        "descriptors count: %d status:%d.\r\n", client_id, conn_id, property->operate_indication,
        property->descriptors_count, status);
    for (uint16_t idx = 0; idx < property->descriptors_count; idx++) {
        osal_printk("[ssap client] find property cbk, descriptors type [%d]: 0x%02x.\r\n",
            idx, property->descriptors_type[idx]);
    }
    if (property->uuid.len == UUID_16BIT_LEN) {
        osal_printk("[ssap client] find property cbk, uuid: %02x %02x.\r\n",
            property->uuid.uuid[14], property->uuid.uuid[15]); /* 14 15: uuid index */
    } else if (property->uuid.len == UUID_128BIT_LEN) {
        for (uint16_t idx = 0; idx < UUID_128BIT_LEN; idx++) {
            osal_printk("[ssap client] find property cbk, uuid [%d]: %02x.\r\n",
                idx, property->uuid.uuid[idx]);
        }
    }
}

static void ssapc_write_cfm_cbk(uint8_t client_id, uint16_t conn_id, ssapc_write_result_t *write_result,
    errcode_t status)
{
    osal_printk("[ssap client] write cfm cbk, client id: %d status:%d.\r\n", client_id, status);
    ssapc_read_req(0, conn_id, write_result->handle, write_result->type);
}

static void ssapc_read_cfm_cbk(uint8_t client_id, uint16_t conn_id, ssapc_handle_value_t *read_data,
    errcode_t status)
{
    osal_printk("[ssap client] read cfm cbk client id: %d conn id: %d status: %d\r\n",
        client_id, conn_id, status);
    osal_printk("[ssap client] read cfm cbk handle: %d, type: %d , len: %d\r\n",
        read_data->handle, read_data->type, read_data->data_len);
}

static void proc_mouse_rpt_data(uint8_t *data, uint16_t data_len)
{
    if (data_len != sizeof(SlpCursorRslt)) {
        osal_printk("[ERR] proc mouse err, %u, %u\r\n", data_len, sizeof(SlpCursorRslt));
        return;
    }
    SlpCursorRslt *cursor_report = (SlpCursorRslt *)data;
    update_am_print_info_cursor(cursor_report);
    usb_send_cursor_report(cursor_report);
}

static void proc_keyboard_rpt_data(uint8_t *data, uint16_t data_len)
{
    if (data_len != sizeof(keyboard_report_t)) {
        osal_printk("[ERR] proc keyboard, %u, %u\r\n", data_len, sizeof(keyboard_report_t));
        return;
    }
    keyboard_report_t *keyboard_report = (keyboard_report_t *)data;
    g_recv_key_sequence_no += 1;
    if (keyboard_report->config.kind == HID_KEYBOARD_KIND) {
        usb_hid_keyboard_report_t report = {.key = {keyboard_report->config.usage_id}};
        usb_send_keyboard_report(&report);
    } else if (keyboard_report->config.kind == HID_CONSUMER_KIND) {
        usb_hid_consumer_report_t report = {.comsumer_key0 = keyboard_report->config.usage_id};
        usb_send_consumer_report(&report);
    } else {
        osal_printk("[ERR] undefined kind:%u\r\n", keyboard_report->config.kind);
    }
}

// 对端零偏值更新
static void proc_am_cmd_gyro_zero_offset(uint8_t *data, uint16_t data_len)
{
    if (data_len != sizeof(air_mouse_cmd_e) + sizeof(SlpGyroZeroOffset)) {
        osal_printk("len is not equal\r\n");
        return;
    }
    if (*(air_mouse_cmd_e *)data != AM_CMD_GYRO_ZERO_OFFSET) {
        osal_printk("cmd is not offset\r\n");
        return;
    }
    SlpGyroZeroOffset *offset = (SlpGyroZeroOffset *)(data + sizeof(air_mouse_cmd_e));
    int ret = sprintf_s(g_serial_send_str, sizeof(g_serial_send_str), "[FT]imu,dongle,offset,%d,%d,%d,END\r\n",
        offset->x, offset->y, offset->z);
    if (ret <= 0) {
        osal_printk("rpt offset fail, %d\r\n", ret);
        return;
    }
    air_mouse_print(g_serial_send_str, true);
}

static void proc_cmd_rpt_data(uint8_t *data, uint16_t data_len)
{
    air_mouse_cmd_e cmd = *(air_mouse_cmd_e *)data;
    usb_hid_keyboard_report_t keyboard_report = {0};
    usb_hid_consumer_report_t consumer_report = {0};
    osal_printk("[slp cmd] proc:%u, sizeof:%u\r\n", cmd, sizeof(air_mouse_cmd_e));
    switch (cmd) {
        case AM_CMD_CURSOR_SPEED_LOW:
        case AM_CMD_CURSOR_SPEED_MEDIUM:
        case AM_CMD_CURSOR_SPEED_HIGH:
            SlpSetCursorSpeedCommand((SlpCursorSpeed)cmd);
            break;
        case AM_CMD_LEFT_KEY_UP:
            SlpClickDebounceCommand(0);
            break;
        case AM_CMD_LEFT_KEY_DOWN:
            SlpClickDebounceCommand(1);
            break;
        case AM_CMD_KEYBOARD_UP:
            usb_send_keyboard_report(&keyboard_report);
            usb_send_consumer_report(&consumer_report);
            break;
        case AM_CMD_SET_FACTORY_TEST_NONE:
            SlpSetFactoryTestMode(SLP_FACTORY_TEST_NONE);
            break;
        case AM_CMD_RANGING_START:
            rst_print_info();
            air_mouse_timer_start(AM_TIMER_TYPE_PRINT);
            air_mouse_timer_start(AM_TIMER_TYPE_RSSI);
            break;
        case AM_CMD_RANGING_STOP:
            air_mouse_timer_stop_all();
            break;
        case AM_CMD_GYRO_ZERO_OFFSET:
            proc_am_cmd_gyro_zero_offset(data, data_len);
            break;
        default:
            osal_printk("[ERR] undefined cmd: %u\r\n", cmd);
            break;
    }
}

static void proc_amic_data(uint8_t *data, uint16_t data_len)
{
    if (recive_amic_encode_data(data, data_len)) {
        uint32_t ret = osal_event_write(&g_trans_event_id, VDT_TRANSFER_EVENT);
        if (ret != OSAL_SUCCESS) {
            osal_printk("(%d)osal event write fail, ret = %x\r\n", __LINE__, ret);
        }
    }
}

void send_amic_data_uac(void)
{
    uint8_t *out_data1 = 0, *out_data2 = 0;
    uint32_t decode_data_len = 0, decode_data_len2 = 0;
    get_amic_decode_data(&out_data1, &decode_data_len, &out_data2, &decode_data_len2);
    if (vdt_usb_uac_send_data(out_data1, decode_data_len, out_data2, decode_data_len2) != 0) {
        osal_printk("Send UAV to USB fail.\r\n");
    }
}

static void ssapc_notification_cbk(uint8_t client_id, uint16_t conn_id, ssapc_handle_value_t *data, errcode_t status)
{
    unused(client_id);
    unused(conn_id);
    unused(status);
    static uint8_t count = 0;
    switch (data->handle) {
        case SLE_AIR_MOUSE_SSAP_RPT_HANDLE: { // Slp 消息
            SlpPayloadInfo info = { data->data, data->data_len };
            SlpRecvPayload(&info);
            break;
        }
        case SLE_AIR_MOUSE_CURSOR_RPT_HANDLE:  // 光标更新
            proc_mouse_rpt_data(data->data, data->data_len);
            break;
        case SLE_AIR_MOUSE_CMD_RPT_HANDLE:  // 命令
            proc_cmd_rpt_data(data->data, data->data_len);
            break;
        case SLE_AIR_MOUSE_KEYBOARD_RPT_HANDLE:
            proc_keyboard_rpt_data(data->data, data->data_len);
            break;
        case SLE_AIR_MOUSE_AMIC_VOICE:
            proc_amic_data(data->data, data->data_len);
            break;
        default:
            if (++count == 100) { // 100:减少打印频率
                count = 0;
                osal_printk("ssapc_notification_cbk undefined handle, %u\r\n", data->handle);
            }
            break;
    }
}

static void sle_air_mouse_ssapc_cbk_register(void)
{
    g_ssapc_cbk.exchange_info_cb = ssapc_exchange_info_cbk;
    g_ssapc_cbk.find_structure_cb = ssapc_find_structure_cbk;
    g_ssapc_cbk.find_structure_cmp_cb = ssapc_find_structure_cmp_cbk;
    g_ssapc_cbk.ssapc_find_property_cbk = ssapc_find_property_cbk;
    g_ssapc_cbk.write_cfm_cb = ssapc_write_cfm_cbk;
    g_ssapc_cbk.read_cfm_cb = ssapc_read_cfm_cbk;
    g_ssapc_cbk.notification_cb = ssapc_notification_cbk;

    ssapc_register_callbacks(&g_ssapc_cbk);
}

/* client向server发数据 */
static errcode_t sle_air_mouse_client_send_slp_payload(uint8_t *payload, uint16_t payload_len)
{
    ssapc_write_param_t param = {0};
    param.handle = SLE_AIR_MOUSE_SSAP_RPT_HANDLE;
    param.type = 0; // 默认配置
    param.data_len = payload_len;
    param.data = payload;
    ssapc_write_cmd(SLE_AIR_MOUSE_DEFAULT_CLIENT_ID, SLE_AIR_MOUSE_DEFAULT_CONNECT_ID, &param);
    return ERRCODE_SLE_SUCCESS;
}

/* client向server发控制命令 */
errcode_t sle_air_mouse_client_send_cmd(air_mouse_cmd_e cmd)
{
    ssapc_write_param_t param = {0};
    param.handle = SLE_AIR_MOUSE_CMD_RPT_HANDLE;
    param.type = 0; // 默认配置
    param.data_len = (uint16_t)sizeof(cmd);
    param.data = &cmd;
    ssapc_write_cmd(SLE_AIR_MOUSE_DEFAULT_CLIENT_ID, SLE_AIR_MOUSE_DEFAULT_CONNECT_ID, &param);
    return ERRCODE_SLE_SUCCESS;
}

static void factory_report_aox_cali_cbk(SlpFactoryRangingAoxDataRpt *factory_rpt)
{
    int ret = sprintf_s(g_serial_send_str, sizeof(g_serial_send_str),
        "[FT]ac,%d,%d,%u,%d,%d,%u,%d,%u,%d,%u,%d,0,END\r\n",
        factory_rpt->aoxCaliData.cirIq0.cirI, factory_rpt->aoxCaliData.cirIq0.cirQ,
        factory_rpt->aoxCaliData.cirIq0.bitWidth, factory_rpt->aoxCaliData.cirIq1.cirI,
        factory_rpt->aoxCaliData.cirIq1.cirQ, factory_rpt->aoxCaliData.cirIq1.bitWidth, factory_rpt->aoxRslt.aoxAzi,
        factory_rpt->aoxRslt.aoxAziFom, factory_rpt->aoxRslt.aoxElev, factory_rpt->aoxRslt.aoxElevFom,
        factory_rpt->tof);
    if (ret <= 0) {
        osal_printk("fac rpt ac fail, %d\r\n", ret);
        return;
    }
    air_mouse_print((const char *)g_serial_send_str, false);
}

static void factory_report_cali_para_cbk(SlpFactoryAoxCaliParaRpt *factory_rpt)
{
    int ret = sprintf_s(g_serial_send_str, sizeof(g_serial_send_str), "[FT]cp,%d,%d,%d,%d,%d,%d,%d,%d,END\r\n",
        factory_rpt->caliPara.para0, factory_rpt->caliPara.para1, factory_rpt->caliPara.para2,
        factory_rpt->caliPara.para3, factory_rpt->caliPara.para4, factory_rpt->caliPara.para5,
        factory_rpt->caliPara.para6, factory_rpt->caliPara.para7);
    if (ret <= 0) {
        osal_printk("fac rpt cp fail, %d\r\n", ret);
        return;
    }
    air_mouse_print((const char *)g_serial_send_str, true);
}

static void factory_report_trx_delay_cbk(uint32_t *timeDelay)
{
    int ret = sprintf_s(g_serial_send_str, sizeof(g_serial_send_str), "[FT]td,%u,END\r\n", *timeDelay);
    if (ret <= 0) {
        osal_printk("fac rpt td fail, %d\r\n", ret);
        return;
    }
    air_mouse_print((const char *)g_serial_send_str, true);
}

static void rpt_fac_imu_data_cbk(SlpFactoryImuDataRpt *rpt)
{
    int ret = sprintf_s(g_serial_send_str, sizeof(g_serial_send_str), "[FT]imu,accNorm,%u,END\r\n", rpt->accNorm);
    if (ret <= 0) {
        osal_printk("fac rpt imu fail, %d\r\n", ret);
        return;
    }
    air_mouse_print((const char *)g_serial_send_str, true);
}

static void slp_report_gyro_zero_offset_cbk(SlpGyroZeroOffset *offset)
{
    int ret = sprintf_s(g_serial_send_str, sizeof(g_serial_send_str), "[FT]imu,offset,%d,%d,%d,END\r\n", offset->x,
        offset->y, offset->z);
    if (ret <= 0) {
        osal_printk("rpt offset fail, %d\r\n", ret);
        return;
    }
    air_mouse_print((const char *)g_serial_send_str, true);
}

void register_slp_factory_test_rpt_callback(void)
{
    SlpFactoryReportCallbacks cbks = {0};
    cbks.rptOriginDataCbk = factory_report_aox_cali_cbk;
    cbks.rptAoxCaliParaCbk = factory_report_cali_para_cbk;
    cbks.rptFactoryTrxDelayCbk = factory_report_trx_delay_cbk;
    cbks.rptImuDataCbk = rpt_fac_imu_data_cbk;
    cbks.rptZeroOffsetCbk = slp_report_gyro_zero_offset_cbk;

    if (SlpRegisterFactoryReportCallbacks(&cbks) != ERRCODE_SLPC_SUCCESS) {
        osal_printk("reg fac rpt cbk failed\r\n");
    }
}

static void client_send_slp_payload_cbk(const SlpPayloadInfo *info)
{
    sle_air_mouse_client_send_slp_payload(info->payload, info->payloadLen);
}

void rpt_version_cbk(SlpVersionRpt *versionRpt)
{
    print_slp_version(versionRpt);
}

static void slp_power_on_cbk(ErrcodeSlpClient errcode)
{
#if CONFIG_SAMPLE_SUPPORT_AIR_MOUSE_CIR_PRINT
    SlpEnCirReportCommand();
#endif
    osal_printk("slp_power_on_cbk errcode: 0x%x\r\n", errcode);
    ErrcodeSlpClient ret = SlpReadVersionCommand();
    osal_printk("SlpReadVersionCommand, ret:0x%x\r\n", ret);

    air_mouse_radar_start();
}

static void slp_power_off_cbk(ErrcodeSlpClient errcode)
{
    if (errcode != ERRCODE_SLPC_SUCCESS) {
        osal_printk("slp_power_off_cbk Error 0x%x\r\n", errcode);
        return;
    }
    air_mouse_timer_stop_all();
}

static void slp_set_local_att_cbk(ErrcodeSlpClient errcode)
{
    osal_printk("slp_set_local_att_cbk errcode: 0x%x\r\n", errcode);
}

static void rpt_errcode_cbk(ErrcodeSlpClient errcode)
{
    int ret;
    switch (errcode) {
        case ERRCODE_SLPC_LOCAL_IMU_READ_DATA:  // DONGLE端IMU异常
            ret = sprintf_s(g_serial_send_str, sizeof(g_serial_send_str), "[FT][ERR]: dongle imu read data failed\r\n");
            if (ret <= 0) {
                osal_printk("fac rpt dongle imu status fail, %d\r\n", ret);
                return;
            }
            air_mouse_print((const char *)g_serial_send_str, true);
            break;
        case ERRCODE_SLPC_PEER_IMU_READ_DATA:  // RCU端IMU异常
            ret = sprintf_s(g_serial_send_str, sizeof(g_serial_send_str), "[FT][ERR]: rcu imu read data failed\r\n");
            if (ret <= 0) {
                osal_printk("fac rpt rcu imu status fail, %d\r\n", ret);
                return;
            }
            air_mouse_print((const char *)g_serial_send_str, true);
            break;
        default:
            osal_printk("slp errcode: 0x%08x\r\n", errcode);
            break;
    }
}

static void rpt_cir_cbk(SlpCirRpt *cirRpt)
{
    if (cirRpt == NULL) {
        sprintf_s(g_serial_send_str, sizeof(g_serial_send_str), "[ERROR][rpt_cir_cbk] cirRpt is null\r\n");
        air_mouse_print(g_serial_send_str, false);
        return;
    }
    uint8_t role = cirRpt->role;
    if (role == 0) {
        sprintf_s(g_serial_send_str, sizeof(g_serial_send_str), "cir,r,poll,bw,%u", cirRpt->bwPollOrResp);
        air_mouse_print(g_serial_send_str, false);

        for (uint16_t i = 0; i < SLP_RANGING_CIR_RECORD_NUM; i = i + 10) { // 10: 10个一组
            sprintf_s(g_serial_send_str, sizeof(g_serial_send_str), ",%u,%u,%u,%u,%u,%u,%u,%u,%u,%u",
                cirRpt->cirPwrPollOrResp[i], cirRpt->cirPwrPollOrResp[i + 1], // 1:索引
                cirRpt->cirPwrPollOrResp[i + 2], cirRpt->cirPwrPollOrResp[i + 3], // 2 3:索引
                cirRpt->cirPwrPollOrResp[i + 4], cirRpt->cirPwrPollOrResp[i + 5], // 4 5:索引
                cirRpt->cirPwrPollOrResp[i + 6], cirRpt->cirPwrPollOrResp[i + 7], // 6 7:索引
                cirRpt->cirPwrPollOrResp[i + 8], cirRpt->cirPwrPollOrResp[i + 9]); // 8 9:索引
            air_mouse_print(g_serial_send_str, false);
        }
        sprintf_s(g_serial_send_str, sizeof(g_serial_send_str), ",final,bw,%u", cirRpt->bwFinal);
        air_mouse_print(g_serial_send_str, false);
        for (uint16_t i = 0; i < SLP_RANGING_CIR_RECORD_NUM; i = i + 10) { // 10: 10个一组
            sprintf_s(g_serial_send_str, sizeof(g_serial_send_str), ",%u,%u,%u,%u,%u,%u,%u,%u,%u,%u",
                cirRpt->cirPwrFinal[i], cirRpt->cirPwrFinal[i + 1], // 1:索引
                cirRpt->cirPwrFinal[i + 2], cirRpt->cirPwrFinal[i + 3], // 2 3:索引
                cirRpt->cirPwrFinal[i + 4], cirRpt->cirPwrFinal[i + 5], // 4 5:索引
                cirRpt->cirPwrFinal[i + 6], cirRpt->cirPwrFinal[i + 7], // 6 7:索引
                cirRpt->cirPwrFinal[i + 8], cirRpt->cirPwrFinal[i + 9]); // 8 9:索引
            air_mouse_print(g_serial_send_str, false);
        }
        sprintf_s(g_serial_send_str, sizeof(g_serial_send_str), ",END\r\n");
        air_mouse_print(g_serial_send_str, false);
    }
}

static void rpt_cfo_cbk(int32_t cfo, uint32_t threshold)
{
    // 打印cfo和阈值
    osal_printk("cfo:%dx0.01ppm, threshold:%ux0.01ppm\r\n", cfo, threshold);
    if ((uint32_t)abs(cfo) > threshold) {
        osal_printk("[ERR] cfo is exceed threshold\r\n");
    }
}

static void rpt_reg_value_cbk(uint32_t addr, uint32_t value)
{
    osal_printk("slp addr:0x%x, value:0x%x\r\n", addr, value);
}

static void check_into_sleep(int32_t x, int32_t y)
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
        // 通知遥控器睡眠
        osal_printk("check sleep, same point %u\r\n", SLEEP_COUNT_THRESHOLD);
        sle_air_mouse_client_send_cmd(AM_CMD_RCU_SLEEP);
        air_mouse_timer_stop_all(); // 关闭光标、测距测角以及rssi打印的定时器，下次唤醒后重新启动
    }
}

void cursor_report_cbk(SlpCursorRslt *cursor_rslt)
{
    update_am_print_info_cursor(cursor_rslt);
    // 如果需要遥控器睡眠，此处调用
    if (CONFIG_LOW_POWER_MODE == 1) {
        check_into_sleep(cursor_rslt->x, cursor_rslt->y);
    }
#if CONFIG_AIR_MOUSE_CI_REPLAY_TEST
    memcpy_s(g_serial_send_str, sizeof(g_serial_send_str), cursor_rslt, sizeof(SlpCursorRslt));
    usb_send_serial_data((const char *)g_serial_send_str, sizeof(SlpCursorRslt));
#else
    usb_send_cursor_report(cursor_rslt);
#endif
}

void ranging_report_cbk(SlpRangingRpt *rangingRpt)
{
    update_am_print_info_ranging(rangingRpt);
}

static void register_slp_report_callback(void)
{
    SlpReportCallbacks cbks = {0};
    cbks.rptCursorCbk = cursor_report_cbk;
    cbks.rptRangingCbk = ranging_report_cbk;
    cbks.rptErrcodeCbk = rpt_errcode_cbk;
    cbks.rptCirCbk = rpt_cir_cbk;
    cbks.rptVersionCbk = rpt_version_cbk;
    cbks.rptCfoCbk = rpt_cfo_cbk;
    cbks.rptRegValueCbk = rpt_reg_value_cbk;
    if (SlpRegisterReportCallbacks(&cbks) != ERRCODE_SLPC_SUCCESS) {
        osal_printk("register slp_report_callback failed\r\n");
    }
}

#if CONFIG_AIR_MOUSE_CI_REPLAY_TEST
void rcu_test_output_report(uint8_t *data, uint32_t len)
{
    usb_send_serial_data((const char *)data, len);
    osal_printk("rcu test ouput, len:%u\r\n", len);
}
#endif

void sle_client_slp_command_register_cbks(void)
{
    register_slp_factory_test_rpt_callback();  // 注册产测结果上报回调函数
#if CONFIG_AIR_MOUSE_CI_REPLAY_TEST
    RegisterRptCiTestOutputCbk(rcu_test_output_report);
#endif
    SlpCommandCallbacks cbks = {0};
    cbks.powerOnCbk = slp_power_on_cbk;
    cbks.powerOffCbk = slp_power_off_cbk;
    cbks.sleepCbk = NULL;
    cbks.setLocalAttCbk = slp_set_local_att_cbk;

    SlpRegisterCommandCallbacks(&cbks);
    SlpRegisterSendPayloadCallback(client_send_slp_payload_cbk); // 注册client端 SLP发送payload函数
    register_slp_report_callback();
}

void sle_air_mouse_client_init(void)
{
    init_recv_sequence_no();
    sle_air_mouse_client_seek_cbk_register();
    while (g_sle_enable == false) {
        osal_msleep(SLE_UART_TASK_DELAY_MS);
        enable_sle();
    }
    sle_air_mouse_client_connect_cbk_register();
    sle_air_mouse_ssapc_cbk_register();
    sle_remove_all_pairs();

#if CONFIG_SAMPLE_SUPPORT_AIR_MOUSE_SLE_ADDR_CHECK
    osal_printk("local addr:");
    for (uint8_t index = 0; index < SLE_ADDR_LEN; index++) {
        osal_printk("0x%02x ", g_local_addr.addr[index]);
    }
    osal_printk("\r\n");
#endif
}
