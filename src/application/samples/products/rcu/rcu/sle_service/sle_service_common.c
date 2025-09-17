/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * Description: SLE SERVICE COMMON FUNCTION HEADER FILE\n
 *
 * History: \n
 * 2024-5-30, Create file. \n
 */
#include "securec.h"
#include "sle_errcode.h"

#include "sle_service_common.h"

errcode_t sle_set_uuid(uint8_t *uuid, sle_uuid_t *service_uuid)
{
    if (memcpy_s(service_uuid->uuid, SLE_UUID_LEN, uuid, SLE_UUID_LEN) != EOK) {
        return ERRCODE_SLE_MEMCPY_FAIL;
    }
    service_uuid->len = SLE_UUID_LEN;
    return ERRCODE_SLE_SUCCESS;
}

errcode_t sle_add_property(uint8_t server_id, uint32_t properties, uint8_t *uuid, uint16_t len, uint8_t *data,
    sle_item_handle_t* service_hdl)
{
    if ((data == NULL) || (service_hdl == NULL)) {
        return ERRCODE_SLE_FAIL;
    }
    ssaps_property_info_t property = {0};
    errcode_t ret = sle_set_uuid(uuid, &property.uuid);
    if (ret != ERRCODE_SLE_SUCCESS) {
        return ERRCODE_SLE_FAIL;
    }
    property.permissions = SSAP_PERMISSION_READ | SSAP_PERMISSION_WRITE;
    property.operate_indication = properties;
    property.value_len = len;
    property.value = data;
    return ssaps_add_property_sync(server_id, service_hdl->handle_in, &property, &service_hdl->handle_out);
}

errcode_t sle_service_add(uint8_t server_id, uint8_t *device_uuid, sle_item_handle_t *service_hdl,
    uint8_t sle_index_start, uint8_t sle_index_end)
{
    errcode_t ret;
    sle_uuid_t service_uuid = {0};
    ret = sle_set_uuid(device_uuid, &service_uuid);
    if (ret != ERRCODE_SLE_SUCCESS) {
        osal_printk("[dis service] set uuid fail, ret:0x%x\r\n", ret);
        return ERRCODE_SLE_FAIL;
    }

    ret = ssaps_add_service_sync(server_id, &service_uuid, 1, &service_hdl[sle_index_start].handle_out);
    if (ret != ERRCODE_SLE_SUCCESS) {
        return ret;
    }

    for (uint8_t i = 1; i < sle_index_end; i++) {
        service_hdl[sle_index_start + i].handle_in = service_hdl[sle_index_start].handle_out;
    }
    return ERRCODE_SLE_SUCCESS;
}
