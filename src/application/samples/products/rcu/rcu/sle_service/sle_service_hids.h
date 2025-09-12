/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * Description: SLE SERVICE HIDS HEADER \n
 *
 * History: \n
 * 2024-05-25, Create file. \n
 */
#ifndef SLE_SERVICE_HIDS_H
#define SLE_SERVICE_HIDS_H

#include <stdint.h>
#include "osal_debug.h"
#include "errcode.h"
#include "sle_ota.h"
#include "sle_service_common.h"
#include "sle_ssap_server.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

#define SLE_RCU_SERVER_LOG     "[sle rcu server]"
/* Property UUID */
#define SLE_UUID_SERVER_NTF_REPORT     0x2323
#define SLE_UUID_AMIC_SERVER_NTF_REPORT     0x2325

typedef enum {
    SLE_HID_INDEX_SERVICE, // hid service

    SLE_HID_INDEX_REPORT_MAP, // Report Map
    SLE_HID_INDEX_HID_CONTROL, // Hid Control Point

    // keyboard
    SLE_HID_INDEX_KEYBOARD_INPUT, // input report
    SLE_HID_INDEX_KEYBOARD_CCCD, // CCCD
    SLE_HID_INDEX_KEYBOARD_REF, // Report Reference

    // customer
    SLE_HID_INDEX_CUSTOMER_INPUT, // input report
    SLE_HID_INDEX_CUSTOMER_CCCD, // CCCD
    SLE_HID_INDEX_CUSTOMER_REF, // Report Reference

    SLE_HID_INDEX_MAX,
} sle_hid_index_t;

#define SLE_INPUT_REPORT_LENGTH 4
#define SLE_SRV_ENCODED_REPORT_LEN 8

typedef struct {
    uint8_t  hid_control_point;
    uint8_t* cccd;
    uint16_t cccd_len;
    uint8_t* input_report;
    uint8_t* input_report_descriptor;
    uint8_t* report_map_datas;
    uint16_t map_data_len;
    sle_item_handle_t* item_handle;
} sle_service_hids_t;

typedef enum {
    HID_INDEX_SERVICE,
    HID_INDEX_REPORT,
    HID_INDEX_CCCD,
    HID_INDEX_REF,
    HID_INDEX_MAP,
    HID_INDEX_CONTROL,
    HID_ELEMENT_NUM,
} sle_hid_array_index_t;

errcode_t sle_add_hid_service(uint8_t server_id);
errcode_t sle_rcu_server_send_report_by_handle(const uint8_t *data, uint8_t len, uint16_t conn_id);

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif