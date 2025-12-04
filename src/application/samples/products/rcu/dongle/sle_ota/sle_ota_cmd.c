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
#include "sle_ota_cmd_handler.h"
#include "osal_debug.h"
#include "rcu_dongle_hid.h"
#include "gadget/f_hid.h"
#include "sle_ota_cmd.h"

#define WRITE_REQ_BUFFER_LEN                    256
#define FRAME_8_BIT_SHIFT                       8
#define SLE_OTA_RESPONSE_LEN                    128
#define SLE_OTA_RPT_DATA_LEN_INDEX              24
#define SLE_OTA_8_BIT_SHIFT                     8
#define SLE_OTA_16_BIT_SHIFT                    16
#define SLE_OTA_24_BIT_SHIFT                    24
#define SLE_OTA_RESPONSE_HEADER_LEN             26
#define SLE_OTA_RPT_SERVICEID                   0X03
#define SLE_OTA_RPT_COMMANDID                   0X07
#define SLE_OTA_LOG                             "[sle ota cmd]"

#define SLE_OTA_NEGOTATION_HEADER_LEN           44
#define SLE_OTA_NEGOTATION_ID_INDEX             44
#define SLE_OTA_NEGOTATION_FOTA_SIZE_INDEX      52
#define SLE_OTA_NEGOTATION_PACKET_SIZE_INDEX    58
#define SLE_OTA_NEGOTATION_LEN                  70

#define SLE_OTA_REQUEST_LEN                     53
#define SLE_OTA_REQUEST_ID_INDEX                35
#define SLE_OTA_REQUEST_FOTA_HEAD_INDEX         43
#define SLE_OTA_REQUEST_PACKET_SIZE_INDEX       47


static uint16_t g_reassembly_len = 0;
static uint16_t g_reassembly_offset = 0;
static uint8_t  g_reassembly_expect_seq = 0;

static uint8_t g_reassembly_buff[WRITE_REQ_BUFFER_LEN] = { 0 };
static uint8_t g_sle_ota_rpt_body[SLE_OTA_RESPONSE_LEN] = { 0x1, 0x1, 0x0, 0x0, 0x2, 0x2, 0x0, 0xa, 0x0, 0x3,
                                                            0x2, 0x0, 0xa, 0x0, 0x4, 0x1, 0x0, 0x0, 0x5, 0x2,
                                                            0x0, 0xd, 0x0, 0x6, 0x0, 0x0};

typedef errcode_t (*sle_ota_pkt_recv_hook)(uint8_t service_id, uint8_t command_id, uint8_t *buffer, uint16_t length);
typedef struct {
    uint8_t service_id;
    sle_ota_pkt_recv_hook handler;
} sle_ota_service_handler_t;

static sle_ota_service_handler_t g_sle_ota_cmd_id_tbl[] = {
    { SERVICE_ID_SERVICE_DISCOVER,                  sle_ota_discover_device_service },
    { SERVICE_ID_SERVICE_CONNECT,                   sle_ota_manage_connection_service },
    { SERVICE_ID_CLIENT_MANAGE,                     sle_ota_manage_ssap_client },
    { SERVICE_ID_SERVICE_MANAGE,                    NULL },
    { SERVICE_ID_FACTORY_TEST_SERVICE,              NULL },
    { SERVICE_ID_LOW_LATENCY_SERVICE_MANAGE,        NULL },
};

static errcode_t sle_ota_cmd_receiver(uint8_t service_id, uint8_t command_id, uint8_t *data, uint16_t len)
{
    uint32_t i;
    for (i = 0; i < sizeof(g_sle_ota_cmd_id_tbl) / sizeof(g_sle_ota_cmd_id_tbl[0]); i++) {
        sle_ota_service_handler_t *item = &g_sle_ota_cmd_id_tbl[i];
        if (item->service_id == service_id && item->handler != NULL) {
            item->handler(service_id, command_id, data, len);
            return ERRCODE_SUCC;
        }
    }
    return ERRCODE_NOT_SUPPORT;
}

errcode_t sle_ota_recv_handler(uint8_t *data, uint16_t length)
{
    sle_ota_frame_header_t *head = (sle_ota_frame_header_t *)((uint8_t *)data);
    if (head->flag != SLE_LINK_FRAME_HEAD_FLAG) {
        return ERRCODE_NOT_SUPPORT;
    }
    if (head->total_frame <= 1) {
        /* 不需要组包 */
        (void)memset_s(g_reassembly_buff, WRITE_REQ_BUFFER_LEN, 0, WRITE_REQ_BUFFER_LEN);
        sle_ota_frame_header_t *req = (sle_ota_frame_header_t *)((uint8_t *)data);
        return sle_ota_cmd_receiver(req->service_id, req->command_id, data, length);
    }
    uint16_t len = 0;
    /* 组包 */
    if ((head->frame_seq == 0) && (g_reassembly_expect_seq == head->frame_seq)) {
        (void)memset_s(g_reassembly_buff, WRITE_REQ_BUFFER_LEN, 0, WRITE_REQ_BUFFER_LEN);
        g_reassembly_offset = 0;
        /* Bodylen长度 */
        uint16_t body_len = data[SLE_LINK_FRAME_BODY_LEN_INDEX] +
                            (data[SLE_LINK_FRAME_BODY_LEN_INDEX + 1] << FRAME_8_BIT_SHIFT);
        g_reassembly_len = SLE_LINK_FRAME_HEAD_LEN + SLE_LINK_FRAME_PAYLOAD_HEAD_LEN + body_len +
                           SLE_LINK_FRAME_MIC_LEN;
        len = length - SLE_LINK_FRAME_MIC_LEN;
        if (memcpy_s(g_reassembly_buff, len, data, len) != EOK) {
            return ERRCODE_FAIL;
        }
        g_reassembly_offset = len;
        g_reassembly_expect_seq += 1;
    } else if ((head->frame_seq == (head->total_frame - 1)) && (g_reassembly_expect_seq == head->frame_seq)) {
        /* 最后一帧 */
        /* 还未接收body长度 */
        len = g_reassembly_len - g_reassembly_offset;
        if (memcpy_s(g_reassembly_buff + g_reassembly_offset, len, data + SLE_LINK_FRAME_HEAD_LEN, len) != EOK) {
            return ERRCODE_FAIL;
        }
        g_reassembly_expect_seq = 0;
        sle_ota_frame_header_t *req = (sle_ota_frame_header_t *)((uint8_t *)g_reassembly_buff);
        return sle_ota_cmd_receiver(req->service_id, req->command_id, g_reassembly_buff, g_reassembly_len);
    } else if (g_reassembly_expect_seq == head->frame_seq) {
        len = length - SLE_LINK_FRAME_HEAD_LEN - SLE_LINK_FRAME_MIC_LEN;
        if (memcpy_s(g_reassembly_buff + g_reassembly_offset, len, data + SLE_LINK_FRAME_HEAD_LEN, len) != EOK) {
            return ERRCODE_FAIL;
        }
        g_reassembly_offset += len;
        g_reassembly_expect_seq += 1;
    } else {
        g_reassembly_expect_seq = 0;
        g_reassembly_offset = 0;
        g_reassembly_len = 0;
    }
    return ERRCODE_SUCC;
}

void sle_ota_fhid_send_data_one(uint8_t service_id, uint8_t command_id, uint16_t body_len, uint8_t *body)
{
    uint8_t send_buff[SLE_LINK_MAX_FRAME_LEN] = {0};
    sle_ota_frame_header_t *head = (sle_ota_frame_header_t *)&send_buff;
    head->flag = SLE_LINK_FRAME_HEAD_FLAG;
    head->version = 0;
    head->total_frame = 1;
    head->frame_seq = 0;
    head->service_id = service_id;
    head->command_id = command_id;
    head->body_len[0] = body_len;
    head->body_len[1]= body_len >> SLE_OTA_8_BIT_SHIFT;

    uint8_t *body_buff = (uint8_t *)((uintptr_t)send_buff + sizeof(sle_ota_frame_header_t));
    if (memcpy_s(body_buff, SLE_LINK_FRAME_BODY_MAX_LEN, body, body_len) != EOK) {
        osal_printk("%s memcpy body fail.\r\n", SLE_OTA_LOG);
        return;
    }
    uint16_t send_len = body_len + SLE_LINK_FRAME_HEAD_LEN + SLE_LINK_FRAME_PAYLOAD_HEAD_LEN + SLE_LINK_FRAME_MIC_LEN;
    int32_t ret = fhid_send_data(rcu_dongle_get_custom_report_desc_hid(), (char *)send_buff, send_len);
    if (ret < 0) {
        osal_printk("%s hid send data falied! ret:%d\n", SLE_OTA_LOG, ret);
        return;
    }
}

void sle_ota_fhid_send_data_more(uint8_t service_id, uint8_t command_id, uint16_t body_len, uint8_t *body)
{
    uint8_t send_buff[SLE_LINK_MAX_FRAME_LEN] = {0};
    sle_ota_frame_header_t *head = (sle_ota_frame_header_t *)&send_buff;
    head->flag = SLE_LINK_FRAME_HEAD_FLAG;
    head->version = 0;
    head->service_id = service_id;
    head->command_id = command_id;
    head->body_len[0] = body_len;
    head->body_len[1]= body_len >> SLE_OTA_8_BIT_SHIFT;
    /* 分帧发送 */
    uint16_t payload_len_send = body_len + SLE_LINK_FRAME_PAYLOAD_HEAD_LEN;
    head->total_frame = ((payload_len_send % SLE_LINK_FRAME_PAYLOAD_MAX_LEN) ? 1 : 0)
                        + (payload_len_send / SLE_LINK_FRAME_PAYLOAD_MAX_LEN);
    /* 第一帧 */
    head->frame_seq = 0;
    uint16_t body_send_len = (body_len > SLE_LINK_FRAME_BODY_MAX_LEN) ?
                                    SLE_LINK_FRAME_BODY_MAX_LEN : body_len;
    uint8_t *body_buff = (uint8_t *)((uintptr_t)send_buff + sizeof(sle_ota_frame_header_t));
    if (memcpy_s(body_buff, SLE_LINK_FRAME_BODY_MAX_LEN, body, body_send_len) != EOK) {
        osal_printk("%s memcpy body fail.\r\n", SLE_OTA_LOG);
        return;
    }
    int32_t ret = fhid_send_data(rcu_dongle_get_custom_report_desc_hid(), (char *)send_buff, SLE_LINK_MAX_FRAME_LEN);
    if (ret < 0) {
        osal_printk("%s hid send data(seq %d) falied! ret:%d\n", SLE_OTA_LOG, head->frame_seq, ret);
        return;
    }
    uint16_t body_offset = SLE_LINK_FRAME_BODY_MAX_LEN;
    uint16_t left_body_len = body_len - SLE_LINK_FRAME_BODY_MAX_LEN;
    /* 剩余帧 */
    for (uint8_t i = 1; i < head->total_frame ; i++) {
        head->frame_seq = i;
        uint8_t *payload_buff = (uint8_t *)((uintptr_t)send_buff + SLE_LINK_FRAME_HEAD_LEN);
        uint8_t *payload_data = (uint8_t *)((uintptr_t)body + body_offset);
        body_send_len = (left_body_len > SLE_LINK_FRAME_BODY_MAX_LEN) ?
                                  SLE_LINK_FRAME_BODY_MAX_LEN : left_body_len;
        (void)memset_s(payload_buff, SLE_LINK_FRAME_PAYLOAD_MAX_LEN, 0, SLE_LINK_FRAME_PAYLOAD_MAX_LEN);
        if (memcpy_s(payload_buff, SLE_LINK_FRAME_PAYLOAD_MAX_LEN, payload_data, body_send_len) != EOK) {
            osal_printk("%s memcpy %d seq of body fail.\r\n", SLE_OTA_LOG, head->frame_seq);
            return;
        }
        uint16_t frame_send_len = body_send_len + SLE_LINK_FRAME_MIC_LEN + SLE_LINK_FRAME_HEAD_LEN;
        ret = fhid_send_data(rcu_dongle_get_custom_report_desc_hid(), (char *)send_buff, frame_send_len);
        if (ret < 0) {
            osal_printk("%s hid send data(seq %d) falied! ret:%d\n", SLE_OTA_LOG, head->frame_seq, ret);
            return;
        }
        body_offset += body_send_len;
        left_body_len -= body_send_len;
    }
}

void sle_ota_data_handle(ssapc_handle_value_t *data)
{
    g_sle_ota_rpt_body[SLE_OTA_RPT_DATA_LEN_INDEX] = data->data_len;
    g_sle_ota_rpt_body[SLE_OTA_RPT_DATA_LEN_INDEX + 1] = data->data_len >> SLE_OTA_8_BIT_SHIFT;
    for (uint32_t i = 0; i < data->data_len && SLE_OTA_RESPONSE_HEADER_LEN + i < SLE_OTA_RESPONSE_LEN; i++) {
        g_sle_ota_rpt_body[SLE_OTA_RESPONSE_HEADER_LEN + i] = data->data[i];
    }
    uint16_t body_len = SLE_OTA_RESPONSE_HEADER_LEN + data->data_len;
    if (body_len <= SLE_LINK_FRAME_BODY_MAX_LEN) {
        sle_ota_fhid_send_data_one(SLE_OTA_RPT_SERVICEID, SLE_OTA_RPT_COMMANDID, body_len, g_sle_ota_rpt_body);
        return;
    }
    sle_ota_fhid_send_data_more(SLE_OTA_RPT_SERVICEID, SLE_OTA_RPT_COMMANDID, body_len, g_sle_ota_rpt_body);
}