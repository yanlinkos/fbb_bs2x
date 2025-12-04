/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * Description: SLE RCU sample of client. \n
 *
 * History: \n
 * 2025-09-02, Create file. \n
 */

#include <errcode.h>
#include "securec.h"
#include "common_def.h"
#include "osal_debug.h"
#include "gadget/f_hid.h"
#include "sle_device_manager.h"
#include "sle_device_discovery.h"
#include "sle_ssap_client.h"
#include "sle_ota_cmd.h"
#include "sle_rcu_client.h"
#include "rcu_dongle_hid.h"
#include "sle_ota_cmd_handler.h"

#define WRITE_REQ_DATA_LEN_INDEX    33
#define WRITE_REQ_DATA_INDEX        35
#define DEVICE_ADDR_RPT_LEN         24
#define RPT_TYPE_INDEX              12
#define RPT_ADDR_INDEX              16
#define SLE_OTA_CONNECT_DELAY       500
#define DIAG_FRAME_DATA_OFFSET      4
#define FRAME_8_BIT_SHIFT           8
#define CONNECT_TRY_TIME            20

static void sle_ota_send_common_response(uint8_t service_id, uint8_t command_id, errcode_t ret)
{
    uint8_t ret_code = 0;
    if (ret != ERRCODE_SUCC) {
        ret_code = 1;
    }
    sle_ota_response_frame_t response = { 0 };
    response.flag = SLE_LINK_FRAME_HEAD_FLAG;
    response.service_id = service_id;
    response.command_id = command_id;
    response.body_len[0] = 0x04;
    response.body_len[1] = 0x00;
    response.type = 0x7F;
    response.len[0] = 0x01;
    response.len[1] = 0x00;
    response.errorcode = ret_code;
    fhid_send_data(rcu_dongle_get_custom_report_desc_hid(), (char *)&response, sizeof(sle_ota_response_frame_t));
}

errcode_t sle_ota_discover_device_service(uint8_t service_id, uint8_t command_id, uint8_t *buffer, uint16_t length)
{
    unused(service_id);
    unused(command_id);
    unused(buffer);
    unused(length);
    errcode_t ret = ERRCODE_SUCC;
    switch (command_id) {
        case COMMAND_ID_ENABLE_SLE:
            break;
        case COMMAND_ID_DISABLE:
            break;
        case COMMAND_ID_SET_DEVICE_ADDR:
            break;
        case COMMAND_ID_GET_DEVICE_ADDR:
            break;
        case COMMAND_ID_SET_DEVICE_NAME:
            break;
        case COMMAND_ID_GET_DEVICE_NAME:
            break;
        case COMMAND_ID_SET_ANNOUNCE_DATA:
            break;
        case COMMAND_ID_SET_START_ANNOUNCE:
            break;
        case COMMAND_ID_SET_END_ANNOUNCE:
            break;
        case COMMAND_ID_SET_SCAN_PARAM:
            break;
        case COMMAND_ID_UPLOAD_SCAN_RESULT:
            break;
        case COMMAND_ID_START_SCAN:
            break;
        case COMMAND_ID_STOP_SCAN:
            break;
        default:
            break;
    }
    return ret;
}

errcode_t sle_ota_manage_connection_service(uint8_t service_id, uint8_t command_id, uint8_t *buffer, uint16_t length)
{
    unused(service_id);
    unused(command_id);
    unused(buffer);
    unused(length);
    errcode_t ret = ERRCODE_SUCC;
    switch (command_id) {
        case COMMAND_ID_SEND_LINK_REQ:
            break;
        case COMMAND_ID_BREAK_LINK_REQ:
            break;
        case COMMAND_ID_UPG_LINK_PARAM:
            break;
        case COMMAND_ID_SEND_BOUND_REQ:
            break;
        case COMMAND_ID_DELETE_BOUND:
            break;
        case COMMAND_ID_DELETE_ALL_BOUND:
            break;
        case COMMAND_ID_GET_BOUND_DEVICE_NUM:
            break;
        case COMMAND_ID_GET_BOUND_DEVICE:
            break;
        case COMMAND_ID_GET_BOUND_STATUS:
            break;
        case COMMAND_ID_GET_DEVICE_RSSI:
            break;
        case COMMAND_ID_GET_ACB_PARAM:
            break;
        case COMMAND_ID_SET_PHY_PARAM:
            break;
        case COMMAND_ID_SET_POWRER_MAXIMUM:
            break;
        case COMMAND_ID_SEND_LINK_MANAGEMEND_CHECK:
            break;
        case COMMAND_ID_GET_CONN_STATUS:
            break;
        default:
            break;
    }
    return ret;
}

static errcode_t sle_ota_write_cmd(uint8_t service_id, uint8_t command_id, uint8_t *buffer, uint16_t length)
{
    unused(length);
    errcode_t ret = ERRCODE_SUCC;
    uint16_t len = (buffer[WRITE_REQ_DATA_LEN_INDEX]) + (buffer[WRITE_REQ_DATA_LEN_INDEX + 1] << FRAME_8_BIT_SHIFT);
    uint8_t *data = buffer + WRITE_REQ_DATA_INDEX;
    ssapc_write_param_t sle_micro_send_param;
    sle_micro_send_param.handle = get_sle_ota_send_handle();
    sle_micro_send_param.type = SSAP_PROPERTY_TYPE_VALUE;
    sle_micro_send_param.data_len = len;
    sle_micro_send_param.data = data;
    ret = ssapc_write_cmd(0, get_sle_rcu_conn_id(), &sle_micro_send_param);
    sle_ota_send_common_response(service_id, command_id, ret);
    return ret;
}

errcode_t sle_ota_manage_ssap_client(uint8_t service_id, uint8_t command_id, uint8_t *buffer, uint16_t length)
{
    unused(service_id);
    unused(command_id);
    unused(buffer);
    unused(length);
    errcode_t ret = ERRCODE_SUCC;
    switch (command_id) {
        case COMMAND_ID_REGISTER_CLIENT:
            break;
        case COMMAND_ID_UNREGISTER_CLIENT:
            break;
        case COMMAND_ID_SEARCH_SERVER_DESCRIPTION:
            break;
        case COMMAND_ID_UUID_READ_REQ:
            break;
        case COMMAND_ID_HANDLE_READ_REQ:
            break;
        case COMMAND_ID_WRITE_REQ:
            break;
        case COMMAND_ID_WRITE_CMD:
            sle_ota_write_cmd(service_id, command_id, buffer, length);
            break;
        case COMMAND_ID_EXCHANGE_INFO_REQ:
            break;
        default:
            break;
    }
    return ret;
}