/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * Description: SLE Server SOURCE \n
 *
 * History: \n
 * 2024-5-25, Create file. \n
 */
#include "securec.h"
#include "osal_task.h"
#include "common_def.h"
#include "sle_errcode.h"
#include "sle_device_manager.h"
#include "sle_device_discovery.h"
#include "rcu.h"
#include "sle_rcu_server_adv.h"
#include "sle_ota.h"
#include "vdt_codec.h"
#include "sle_service_hids.h"
#include "sle_service_dis.h"
#include "sle_service_bas.h"
#include "sle_service_ntf.h"
#include "app_common.h"
#include "app_status.h"
#include "amic_voice.h"
#include "sle_rcu_server_control.h"
#include "sle_rcu_server.h"

#define BT_INDEX_4                      4
#define BT_INDEX_0                      0
#define HID_ELEMENT_NUM                 6
#define SLE_RCU_SSAP_MTU_MAX            520
#define SLE_RCU_TASK_DELAY_MS 		200

/* sle pair acb handle */
static uint16_t g_sle_pair_handle;
bool g_ssaps_ready = false;
static int g_conn_update = 0;
/* sle server app uuid */
static uint8_t g_sle_uuid_app_uuid[UUID_LEN_2] = { 0x12, 0x34 };

/* sle connect acb handle */
static uint16_t g_sle_conn_handle[CONFIG_RCU_MULTICON_NUM] = { 0 };
/* sle server handle */
uint8_t g_server_id = 0;
static uint16_t g_sle_enable = false;

/* 低功耗连接参数信息 */
static sle_connection_param_update_t g_work_to_standby = { 0, 100, 100, 80, 3000 };
static sle_connection_param_update_t g_standby_to_work = { 0, 30, 30, 2, 1000 };

uint8_t g_out_low_latency_data[LOW_LATENCY_DATA_MAX] = { 0 };
/* sle gamepad conn state */

#if defined(CONFIG_SLE_UPG_ENABLE)
static uint8_t sle_rcu_ota_stage = SLE_RCU_OTA_STOP;
#endif

bool get_g_ssaps_ready(void)
{
    return g_ssaps_ready;
}

uint8_t rcu_get_server_id(void)
{
    return g_server_id;
}

int get_g_conn_update(void)
{
    return g_conn_update;
}

uint16_t get_g_sle_conn_hdl(uint32_t index)
{
    return g_sle_conn_handle[index];
}

#if defined(CONFIG_SLE_UPG_ENABLE)
void sle_rcu_set_ota_stage(uint8_t ota_stage)
{
    sle_rcu_ota_stage = ota_stage;
}
uint8_t sle_rcu_get_ota_stage()
{
    return sle_rcu_ota_stage;
}
#endif

static void ssaps_mtu_changed_cbk(uint8_t server_id, uint16_t conn_id,  ssap_exchange_info_t *mtu_size,
                                  errcode_t status)
{
    osal_printk("%s ssaps ssaps_mtu_changed_cbk callback server_id:0x%x, conn_id:0x%x, mtu_size:0x%x, status:0x%x\r\n",
                SLE_RCU_SERVER_LOG, server_id, conn_id, mtu_size->mtu_size, status);
    g_ssaps_ready = true;
    if (g_sle_pair_handle == 0) {
        g_sle_pair_handle =  conn_id + 1;
    }
}

static void ssaps_start_service_cbk(uint8_t server_id, uint16_t handle, errcode_t status)
{
    osal_printk("%s start service cbk callback server_id:%d, handle:0x%x, status:0x%x\r\n", SLE_RCU_SERVER_LOG,
                server_id, handle, status);
}

static void ssaps_add_service_cbk(uint8_t server_id, sle_uuid_t *uuid, uint16_t handle, errcode_t status)
{
    unused(uuid);
    osal_printk("%s add service cbk callback server_id:0x%x, handle:0x%x, status:0x%x\r\n", SLE_RCU_SERVER_LOG,
                server_id, handle, status);
}

static void ssaps_add_property_cbk(uint8_t server_id, sle_uuid_t *uuid, uint16_t service_handle,
    uint16_t handle, errcode_t status)
{
    unused(uuid);
    osal_printk("%s add property cbk callback server_id:0x%x, service_handle:0x%x,handle:0x%x, status:0x%x\r\n",
                SLE_RCU_SERVER_LOG, server_id, service_handle, handle, status);
}

static void ssaps_add_descriptor_cbk(uint8_t server_id, sle_uuid_t *uuid, uint16_t service_handle,
                                     uint16_t property_handle, errcode_t status)
{
    unused(uuid);
    osal_printk("%s add descriptor cbk callback server_id:0x%x, service_handle:0x%x, property_handle:0x%x, \
                status:0x%x\r\n", SLE_RCU_SERVER_LOG, server_id, service_handle, property_handle, status);
}

static void ssaps_delete_all_service_cbk(uint8_t server_id, errcode_t status)
{
    osal_printk("%s delete all service callback server_id:0x%x, status:0x%x\r\n", SLE_RCU_SERVER_LOG,
                server_id, status);
}

static errcode_t sle_ssaps_register_cbks(ssaps_read_request_callback ssaps_read_callback,
                                         ssaps_write_request_callback ssaps_write_callback)
{
    errcode_t ret;
    ssaps_callbacks_t ssaps_cbk = { 0 };
    ssaps_cbk.add_service_cb = ssaps_add_service_cbk;
    ssaps_cbk.add_property_cb = ssaps_add_property_cbk;
    ssaps_cbk.add_descriptor_cb = ssaps_add_descriptor_cbk;
    ssaps_cbk.start_service_cb = ssaps_start_service_cbk;
    ssaps_cbk.delete_all_service_cb = ssaps_delete_all_service_cbk;
    ssaps_cbk.mtu_changed_cb = ssaps_mtu_changed_cbk;
    ssaps_cbk.read_request_cb = ssaps_read_callback;
    ssaps_cbk.write_request_cb = ssaps_write_callback;
    ret = ssaps_register_callbacks(&ssaps_cbk);
    if (ret != ERRCODE_SLE_SUCCESS) {
        osal_printk("%s sle_ssaps_register_cbks,ssaps_register_callbacks fail :%x\r\n", SLE_RCU_SERVER_LOG,
                    ret);
        return ret;
    }
    return ERRCODE_SLE_SUCCESS;
}

static errcode_t sle_server_id_register(void)
{
    errcode_t ret;
    sle_uuid_t app_uuid = { 0 };
    app_uuid.len = sizeof(g_sle_uuid_app_uuid);
    if (memcpy_s(app_uuid.uuid, app_uuid.len, g_sle_uuid_app_uuid, sizeof(g_sle_uuid_app_uuid)) != EOK) {
        return ERRCODE_SLE_FAIL;
    }
    ret = ssaps_register_server(&app_uuid, &g_server_id);
    if (ret != ERRCODE_SLE_SUCCESS) {
        osal_printk("%s sle_server_id_register fail: 0x%x\r\n", SLE_RCU_SERVER_LOG, ret);
        return ret;
    }

    return ERRCODE_SLE_SUCCESS;
}

static errcode_t sle_rcu_services_add(void)
{
    errcode_t ret;

    if (sle_server_id_register() != ERRCODE_SLE_SUCCESS) {
        return ERRCODE_SLE_FAIL;
    }
#if defined(CONFIG_SLE_UPG_ENABLE)
    // add ota service
    ret = sle_ota_service_init(g_server_id);
    if (ret != ERRCODE_SLE_SUCCESS) {
        return ret;
    }
#endif
    // add ntf service
    ret = sle_add_ntf_service(g_server_id);
    if (ret != ERRCODE_SLE_SUCCESS) {
        return ret;
    }
    // add hid service
    ret = sle_add_hid_service(g_server_id);
    if (ret != ERRCODE_SLE_SUCCESS) {
        return ret;
    }
    // add bas service
    ret = sle_add_bas_service(g_server_id);
    if (ret != ERRCODE_SLE_SUCCESS) {
        return ret;
    }
    // add dis service
    ret = sle_add_dis_service(g_server_id);
    if (ret != ERRCODE_SLE_SUCCESS) {
        return ret;
    }
    osal_printk("%s sle rcu services add ok\r\n", SLE_RCU_SERVER_LOG);
    return ERRCODE_SLE_SUCCESS;
}

static void sle_is_need_to_reconnect(void)
{
    sle_addr_t addr[RCU_TARGET_ADDR_NUM];
    uint16_t number = 1;

    sle_get_bonded_devices(addr, &number);
    if (number > 0) {
        sle_rcu_server_directed_adv_init(addr);
    }
    return;
}

static void sle_enable_cbk(uint8_t status)
{
    unused(status);
    ssap_exchange_info_t info = {0};
    info.mtu_size = SLE_RCU_SSAP_MTU_MAX;
    if (ssaps_set_info(0, &info) != ERRCODE_SLE_SUCCESS) {
        osal_printk("%s sle_rcu_server_init,ssaps_set_info fail\r\n", SLE_RCU_SERVER_LOG);
        return;
    }

    if (sle_rcu_services_add() != ERRCODE_SLE_SUCCESS) {
        osal_printk("%s sle_rcu_server_init,sle_rcu_services_add fail\r\n", SLE_RCU_SERVER_LOG);
        return;
    }
    sle_is_need_to_reconnect();
    app_print("%s sle enable callback status:0x%x\r\n", SLE_RCU_SERVER_LOG, status);
    g_sle_enable = true;
}

static errcode_t sle_dev_manager_register_cbks(void)
{
    sle_dev_manager_callbacks_t dev_cbks = { 0 };
    dev_cbks.sle_enable_cb = sle_enable_cbk;
    errcode_t ret = sle_dev_manager_register_callbacks(&dev_cbks);
    if (ret != ERRCODE_SLE_SUCCESS) {
        osal_printk("%s sle_dev_manager_register_cbks fail :0x%x\r\n", SLE_RCU_SERVER_LOG, ret);
        return ret;
    }
    return ERRCODE_SLE_SUCCESS;
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

static void sle_pair_complete_cbk(uint16_t conn_id, const sle_addr_t *addr, errcode_t status)
{
    unused(conn_id);
    unused(addr);
    unused(status);
    osal_printk("pair complete\r\n");
    g_sle_pair_handle = conn_id + 1;
    set_app_sle_conn_status(conn_id, APP_CONNECT_STATUS_PAIRED);
}

void sle_connect_param_update_cb(uint16_t conn_id, errcode_t status, const sle_connection_param_update_evt_t *param)
{
    unused(conn_id);
    unused(status);
    unused(param);
    osal_printk("sle_connect_param_update_cb interval_min %d*0.125 ms\r\n", param->interval);
    g_conn_update = 1;
}

static errcode_t sle_conn_register_cbks(void)
{
    errcode_t ret;
    sle_connection_callbacks_t conn_cbks = { 0 };
    conn_cbks.connect_state_changed_cb = sle_control_notify_connect;
    conn_cbks.pair_complete_cb = sle_pair_complete_cbk;
    conn_cbks.connect_param_update_cb = sle_connect_param_update_cb;
    ret = sle_connection_register_callbacks(&conn_cbks);
    if (ret != ERRCODE_SLE_SUCCESS) {
        osal_printk("%s sle_conn_register_cbks,sle_connection_register_callbacks fail :%x\r\n",
                    SLE_RCU_SERVER_LOG, ret);
        return ret;
    }
    return ERRCODE_SLE_SUCCESS;
}

uint16_t sle_rcu_client_is_connected(void)
{
    return g_sle_pair_handle;
}

void sle_rcu_work_to_standby(void)
{
    sle_control_connect_param_update(&g_work_to_standby);
}

void sle_rcu_standby_to_work(void)
{
    sle_control_connect_param_update(&g_standby_to_work);
    sle_control_update_local_latency(1);
}

void sle_rcu_standby_to_sleep(void)
{
#ifdef CONFIG_RCU_IS_SLEEP_DISCONNECT
    sle_control_set_power_state(true);
    sle_control_set_is_connect_callback(true);
#endif
    sle_control_update_local_latency(0);
#ifdef CONFIG_RCU_IS_SLEEP_DISCONNECT
    sle_control_disconnect_all_remote_device();
#endif
}

void sle_rcu_sleep_to_work(void)
{
    sle_control_set_is_connect_callback(false);
    sle_control_set_power_state(false);
#ifdef CONFIG_RCU_IS_SLEEP_DISCONNECT
    sle_control_connect_all_remote_device();
#endif
}

/* 初始化uuid server */
errcode_t sle_rcu_server_init(ssaps_read_request_callback ssaps_read_callback,
                              ssaps_write_request_callback ssaps_write_callback)
{
    errcode_t ret;
    ret = sle_dev_manager_register_cbks();
    if (ret != ERRCODE_SLE_SUCCESS) {
        return ret;
    }
    ret = sle_rcu_announce_register_cbks();
    if (ret != ERRCODE_SLE_SUCCESS) {
        return ret;
    }
    ret = sle_conn_register_cbks();
    if (ret != ERRCODE_SLE_SUCCESS) {
        return ret;
    }
    ret = sle_ssaps_register_cbks(ssaps_read_callback, ssaps_write_callback);
    if (ret != ERRCODE_SLE_SUCCESS) {
        return ret;
    }
    ret = enable_sle();
    if (ret != ERRCODE_SLE_SUCCESS) {
        osal_printk("%s sle_rcu_server_init,enable_sle fail :%x\r\n", SLE_RCU_SERVER_LOG, ret);
        return ret;
    }

    while (g_sle_enable == false) {
        osal_msleep(SLE_RCU_TASK_DELAY_MS);
    }
    osal_printk("%s init ok\r\n", SLE_RCU_SERVER_LOG);
    return ERRCODE_SLE_SUCCESS;
}
