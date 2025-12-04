/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2023-2023. All rights reserved.
 *
 * Description: ble rcu sample of client. \n
 *
 * History: \n
 * 2023-09-21, Create file. \n
 */
#include "securec.h"
#include "string.h"
#include "common_def.h"
#include "osal_debug.h"
#include "osal_task.h"
#include "bts_def.h"
#include "bts_le_gap.h"
#include "ble_rcu_until.h"
#include "bts_device_manager.h"
#include "ble_rcu_client.h"

#if defined(CONFIG_RCU_MASS_PRODUCTION_TEST)
#include "rcu_dongle_mp_test.h"
#endif

#define BLE_MICRO_MULTINUM_ONE 1
#define BLE_MICRO_MULTINUM_TWO 2
#define BLE_ADDR_INDEX0 0
#define BLE_ADDR_INDEX1 1
#define BLE_ADDR_INDEX2 2
#define BLE_ADDR_INDEX3 3
#define BLE_ADDR_INDEX4 4
#define BLE_ADDR_INDEX5 5

#define UUID16_LEN 2

#define BLE_MTU_SIZE_DEFAULT CONFIG_BLE_MTU_LENGTH
#define BLE_RCU_DONGLE_LOG "[ble rcu dongle]"
#define BLE_RCU_CLIENT_ERROR "[ble rcu client error]"
#define BLE_DEV_NAME_OFFSET 6
#define BLE_CHARACTER_HANDLE_MAX 50

static uint8_t g_ble_rcu_client_id = 2;
static uint16_t g_ble_rcu_conn_id = 0;
static uint16_t g_ble_rcu_mtu = CONFIG_RCU_MTU_LENGTH;

static uint16_t g_rcu_scan_interval = 0x48;
static uint16_t g_rcu_scan_window = 0x48;
static uint8_t g_rcu_scan_type = 0x00;
static uint8_t g_rcu_scan_phy = 0x01;
static uint8_t g_rcu_scan_filter_policy = 0x00;
static uint8_t g_ble_find_ready = 0;
static uint8_t g_index_type = 0;
static uint8_t g_ble_connect_state = 0;

static bt_uuid_t g_client_app_uuid = {UUID16_LEN, {0}};
static uint8_t g_uuid_server[BT_UUID_MAX_LEN] = {0x18, 0x12};
static uint8_t g_uuid_character[BT_UUID_MAX_LEN] = {0x2A, 0x4D};
static bd_addr_t g_ble_rcu_remote_addr = {0};
static property_uuid_handle_t g_character_handle[BLE_CHARACTER_HANDLE_MAX] = {0};

typedef struct ble_multicon_stru {
    uint8_t current_connect;
    uint8_t connected_num;
    uint8_t is_connected[CONFIG_RCU_MULTICON_NUM];
    uint16_t conn_id[CONFIG_RCU_MULTICON_NUM];
    uint8_t addr[CONFIG_RCU_MULTICON_NUM][BD_ADDR_LEN];
} ble_multicon_stru_t;
static ble_multicon_stru_t g_ble_multicon_param = {0};

static uint8_t ble_rcu_find_unconnect_server_by_addr(uint8_t *server_addr)
{
    uint8_t i;
    for (i = 0; i < CONFIG_RCU_MULTICON_NUM; i++) {
        if (g_ble_multicon_param.is_connected[i] == 1) {
            continue;
        }
#if defined(CONFIG_RCU_MASS_PRODUCTION_TEST)
        bd_addr_t peer_addr = {0x10, 0x00, 0x00, 0x00, 0x00, 0x00};
        if (memcmp(server_addr, &peer_addr.addr[i], BD_ADDR_LEN) == 0) {
            return i;
        }
#else
        if (memcmp(server_addr, g_ble_multicon_param.addr[i], BD_ADDR_LEN) == 0) {
            return i;
        }
#endif
    }
    return i;
}

static uint8_t ble_rcu_find_connected_server_by_addr(const uint8_t *server_addr)
{
    uint8_t i;
    for (i = 0; i < CONFIG_RCU_MULTICON_NUM; i++) {
        if (g_ble_multicon_param.is_connected[i] == 0) {
            continue;
        }

#if defined(CONFIG_RCU_MASS_PRODUCTION_TEST)
        bd_addr_t peer_addr = {0, {0x10, 0x00, 0x00, 0x00, 0x00, 0x00}};
        if (memcmp(server_addr, &peer_addr.addr[i], BD_ADDR_LEN) == 0) {
            return i;
        }
#else
        if (memcmp(server_addr, g_ble_multicon_param.addr[i], BD_ADDR_LEN) == 0) {
            return i;
        }
#endif
    }
    return i;
}

bool is_character_handle(int handle)
{
    for (int i = 0; i < g_index_type; i++) {
        if (handle == g_character_handle[i].handle) {
            return true;
        }
    }
    return false;
}

uint8_t get_ble_find_ready(void)
{
    return g_ble_find_ready;
}

/* ble client discover all service */
errcode_t ble_rcu_client_discover_all_service(uint16_t conn_id)
{
    bt_uuid_t service_uuid = {0};
    return gattc_discovery_service(g_ble_rcu_client_id, conn_id, &service_uuid);
}

uint16_t get_ble_rcu_conn_id(void)
{
    return g_ble_rcu_conn_id;
}

void ble_rcu_set_scan_parameters(void)
{
    osal_printk("ble_rcu_set_scan_parameters\n");
    gap_ble_scan_params_t ble_rcu_scan_params = {0};
    ble_rcu_scan_params.scan_interval = g_rcu_scan_interval;
    ble_rcu_scan_params.scan_window = g_rcu_scan_window;
    ble_rcu_scan_params.scan_type = g_rcu_scan_type;
    ble_rcu_scan_params.scan_phy = g_rcu_scan_phy;
    ble_rcu_scan_params.scan_filter_policy = g_rcu_scan_filter_policy;
    int ret = gap_ble_set_scan_parameters(&ble_rcu_scan_params);
    if (ret != 0) {
        osal_printk("gap_ble_set_scan_parameters error ret:%d\n", ret);
    }
}

errcode_t ble_rcu_start_scan(void)
{
    return gap_ble_start_scan();
}

errcode_t ble_rcu_stop_scan(void)
{
    return gap_ble_stop_scan();
}

static void ble_rcu_client_power_on_cbk(uint8_t status)
{
    unused(status);
    osal_printk("ble_rcu_client_power_on_cbk\n");
    if (enable_ble() != 0) {
        osal_printk("enable_ble error\n");
    }
}

static void ble_rcu_gap_ble_enable_callback(uint8_t status)
{
    if (status != 0) {
        osal_printk("%s ble_rcu_gap_ble_enable_callback ,status error\r\n", BLE_RCU_DONGLE_LOG);
        return;
    }

#ifdef CONFIG_SAMPLE_SUPPORT_CLIENT_TV
    uint8_t local_addr[BD_ADDR_LEN] = { CONFIG_TV_MULTICON_CLIENT_ADDR0, CONFIG_TV_MULTICON_CLIENT_ADDR1,
                                        CONFIG_TV_MULTICON_CLIENT_ADDR2, CONFIG_TV_MULTICON_CLIENT_ADDR3,
                                        CONFIG_TV_MULTICON_CLIENT_ADDR4, CONFIG_TV_MULTICON_CLIENT_ADDR5 };
#endif
#ifdef CONFIG_SAMPLE_SUPPORT_CLIENT_OTT
    uint8_t local_addr[BD_ADDR_LEN] = { CONFIG_OTT_MULTICON_CLIENT_ADDR0, CONFIG_OTT_MULTICON_CLIENT_ADDR1,
                                        CONFIG_OTT_MULTICON_CLIENT_ADDR2, CONFIG_OTT_MULTICON_CLIENT_ADDR3,
                                        CONFIG_OTT_MULTICON_CLIENT_ADDR4, CONFIG_OTT_MULTICON_CLIENT_ADDR5 };
#endif

    char uuid[UUID16_LEN] = {0xEE, 0xFD};
    if (memcpy_s(g_client_app_uuid.uuid, UUID16_LEN, uuid, UUID16_LEN) != EOK) {
        printf("BleGattcRegister memcpy fail");
        return;
    }
    int ret = gattc_register_client(&g_client_app_uuid, &g_ble_rcu_client_id);
    if (ret != 0) {
        osal_printk("gattc_register_client error ret:%d\n", ret);
    }

    bd_addr_t local_address;
    local_address.type = 0;
    (void)memcpy_s(local_address.addr, BD_ADDR_LEN, local_addr, BD_ADDR_LEN);
    if (gap_ble_set_local_addr(&local_address) != ERRCODE_SUCC) {
        osal_printk("%s set local addr error!\r\n", BLE_RCU_DONGLE_LOG);
        return;
    }

    ble_rcu_set_scan_parameters();
}

static void ble_rcu_gap_ble_disable_callback(uint8_t status)
{
    unused(status);
    osal_printk("ble_rcu_gap_ble_disable_callback\n");
}

bts_dev_manager_callbacks_t g_ble_dev_mgr_cbk = {
    .power_on_cb = ble_rcu_client_power_on_cbk,
    .ble_enable_cb = ble_rcu_gap_ble_enable_callback,
    .ble_disable_cb = ble_rcu_gap_ble_disable_callback,
};

static void ble_rcu_gap_ble_set_adv_data_callback(uint8_t adv_id, errcode_t status)
{
    unused(adv_id);
    unused(status);
    osal_printk("ble_rcu_gap_ble_set_adv_data_callback\n");
}

static void ble_rcu_gap_ble_set_adv_param_callback(uint8_t adv_id, errcode_t status)
{
    unused(adv_id);
    unused(status);
    osal_printk("ble_rcu_gap_ble_set_adv_param_callback\n");
}

static void ble_rcu_gap_ble_set_scan_param_callback(errcode_t status)
{
    unused(status);
    osal_printk("ble_rcu_gap_ble_set_scan_param_callback status :%d\n", status);
    gap_ble_remove_all_pairs();
    ble_rcu_start_scan();
}

static void ble_rcu_gap_ble_start_adv_callback(uint8_t adv_id, adv_status_t status)
{
    unused(adv_id);
    unused(status);
    osal_printk("ble_rcu_gap_ble_start_adv_callback\n");
}

static void ble_rcu_gap_ble_stop_adv_callback(uint8_t adv_id, adv_status_t status)
{
    unused(adv_id);
    unused(status);
    osal_printk("ble_rcu_gap_ble_stop_adv_callback\n");
}

static void ble_rcu_gap_ble_scan_result_callback(gap_scan_result_data_t *scan_result_data)
{
    unused(scan_result_data);
#if defined(CONFIG_SAMPLE_SUPPORT_CLIENT_TV)
    uint8_t arr[] = {'b', 'l', 'e', '_', 'r', 'c', 'u', '1'};
#endif
#if defined(CONFIG_SAMPLE_SUPPORT_CLIENT_OTT)
    uint8_t arr[] = {'b', 'l', 'e', '_', 'r', 'c', 'u', '2'};
#endif
    uint8_t find_connect_server = 0;
    if (scan_result_data == NULL || scan_result_data->adv_data == NULL) {
        return;
    }

    find_connect_server = ble_rcu_find_unconnect_server_by_addr(scan_result_data->addr.addr);
    int ret = memcmp(scan_result_data->adv_data + BLE_DEV_NAME_OFFSET + 3, arr, sizeof(arr));
    if (ret != 0) {
        uint8_t local_addr[BD_ADDR_LEN] = {0x05, 0x04, 0x03, 0x02, 0x0a, 0x0b};
        if (scan_result_data->addr.addr[BLE_ADDR_INDEX0] == local_addr[BLE_ADDR_INDEX0] &&
            scan_result_data->addr.addr[BLE_ADDR_INDEX1] == local_addr[BLE_ADDR_INDEX1] &&
            scan_result_data->addr.addr[BLE_ADDR_INDEX2] == local_addr[BLE_ADDR_INDEX2] &&
            scan_result_data->addr.addr[BLE_ADDR_INDEX3] == local_addr[BLE_ADDR_INDEX3] &&
            scan_result_data->addr.addr[BLE_ADDR_INDEX4] == local_addr[BLE_ADDR_INDEX4] &&
            scan_result_data->addr.addr[BLE_ADDR_INDEX5] == local_addr[BLE_ADDR_INDEX5]) {
            ble_rcu_scan_remove_adv_list((uint8_t *)&scan_result_data->addr.addr);
        }
    }
    if ((find_connect_server <= CONFIG_RCU_MULTICON_NUM) && (ret == 0)) {
        osal_printk("%s find server addr:[0x%02x:0x%02x:xx:xx:xx:0x%02x], index = %d\r\n",
            BLE_RCU_DONGLE_LOG,
            scan_result_data->addr.addr[BLE_ADDR_INDEX0],
            scan_result_data->addr.addr[BLE_ADDR_INDEX1],
            scan_result_data->addr.addr[BLE_ADDR_INDEX5],
            find_connect_server);
        g_ble_multicon_param.current_connect = find_connect_server;
        (void)memcpy_s(&g_ble_rcu_remote_addr, sizeof(bd_addr_t), &scan_result_data->addr, sizeof(bd_addr_t));
        if (gap_ble_connect_remote_device(&g_ble_rcu_remote_addr) != 0) {
            osal_printk("gap_ble_connect_remote_device error\r\n");
        }
        ble_rcu_stop_scan();
    }
}

static void ble_rcu_gap_ble_connect_state_changed_callback(uint16_t conn_id, bd_addr_t *addr,
    gap_ble_conn_state_t conn_state, gap_ble_pair_state_t pair_state, gap_ble_disc_reason_t disc_reason)
{
    unused(conn_id);
    unused(addr);
    unused(conn_state);
    unused(pair_state);
    unused(disc_reason);

    bd_addr_t bt_rcu_client_addr = {0};
    bt_rcu_client_addr.type = addr->type;
    g_ble_rcu_conn_id = conn_id;
    if (memcpy_s(bt_rcu_client_addr.addr, BD_ADDR_LEN, addr->addr, BD_ADDR_LEN) != EOK) {
        osal_printk("%s add server app addr memcpy failed\r\n", BLE_RCU_CLIENT_ERROR);
        return;
    }

    if ((conn_state == GAP_BLE_STATE_CONNECTED) && (pair_state == GAP_BLE_PAIR_NONE)) {
        osal_printk("%s connect change cbk conn_id =%d \n", BLE_RCU_DONGLE_LOG, conn_id);
        g_ble_multicon_param.is_connected[g_ble_multicon_param.current_connect] = 1;
        g_ble_multicon_param.connected_num++;
        if (g_ble_multicon_param.connected_num < CONFIG_RCU_MULTICON_NUM) {
            ble_rcu_start_scan();
        }
        osal_printk("%s gattc_exchange_mtu_req \n", BLE_RCU_DONGLE_LOG);
        gattc_exchange_mtu_req(g_ble_rcu_client_id, g_ble_rcu_conn_id, g_ble_rcu_mtu);
    } else if (conn_state == GAP_BLE_STATE_DISCONNECTED) {
        osal_printk("%s connect change cbk conn disconnected \n", BLE_RCU_DONGLE_LOG);
        g_ble_connect_state = 0;
        uint8_t connected_server_id = ble_rcu_find_connected_server_by_addr(addr->addr);
        if (connected_server_id <= CONFIG_RCU_MULTICON_NUM) {
            g_ble_multicon_param.is_connected[connected_server_id] = 0;
            g_ble_multicon_param.connected_num--;
        }

#if !defined(CONFIG_RCU_MASS_PRODUCTION_TEST)
        if (g_ble_multicon_param.connected_num < CONFIG_RCU_MULTICON_NUM) {
            ble_rcu_start_scan();
        }
#endif
        return;
    }
}

static void ble_rcu_gap_ble_paired_complete_callback(uint16_t conn_id, const bd_addr_t *addr, errcode_t status)
{
    unused(conn_id);
    unused(addr);
    unused(status);
    if (status == 0) {
        gattc_exchange_mtu_req(g_ble_rcu_client_id, g_ble_rcu_conn_id, g_ble_rcu_mtu);
    } else if (status == ERRCODE_BT_KEY_MISSING) {
        uint8_t ret = gap_ble_remove_pair(addr);
        osal_printk("gap_ble_remove_all_pairs ret: %d\r\n", ret);
    }
}

static void ble_rcu_gap_ble_read_rssi_callback(uint16_t conn_id, int8_t rssi, errcode_t status)
{
    unused(conn_id);
    unused(rssi);
    unused(status);
}

static void ble_rcu_gap_ble_terminate_adv_callback(uint8_t adv_id, adv_status_t status)
{
    unused(adv_id);
    unused(status);
}

static void ble_rcu_gap_ble_auth_complete_callback(
    uint16_t conn_id, const bd_addr_t *addr, errcode_t status, const ble_auth_info_evt_t *evt)
{
    unused(conn_id);
    unused(addr);
    unused(status);
    unused(evt);
}

static void ble_rcu_gap_ble_connect_param_update_callback(
    uint16_t conn_id, errcode_t status, const gap_ble_conn_param_update_t *param)
{
    unused(conn_id);
    unused(param);
    unused(status);
    osal_printk("ble connect param update callback conn_id:%d, latency:%d", conn_id, param->latency);
}

gap_ble_callbacks_t g_ble_rcu_cbk = {
    .set_adv_data_cb = ble_rcu_gap_ble_set_adv_data_callback,
    .set_adv_param_cb = ble_rcu_gap_ble_set_adv_param_callback,
    .set_scan_param_cb = ble_rcu_gap_ble_set_scan_param_callback,
    .start_adv_cb = ble_rcu_gap_ble_start_adv_callback,
    .stop_adv_cb = ble_rcu_gap_ble_stop_adv_callback,
    .scan_result_cb = ble_rcu_gap_ble_scan_result_callback,
    .conn_state_change_cb = ble_rcu_gap_ble_connect_state_changed_callback,
    .pair_result_cb = ble_rcu_gap_ble_paired_complete_callback,
    .read_rssi_cb = ble_rcu_gap_ble_read_rssi_callback,
    .terminate_adv_cb = ble_rcu_gap_ble_terminate_adv_callback,
    .auth_complete_cb = ble_rcu_gap_ble_auth_complete_callback,
    .conn_param_update_cb = ble_rcu_gap_ble_connect_param_update_callback,
};

static void ble_rcu_client_sample_seek_cbk_register(void)
{
    bts_dev_manager_register_callbacks(&g_ble_dev_mgr_cbk);
    gap_ble_register_callbacks(&g_ble_rcu_cbk);
}

static void ble_rcu_dis_client_discovery_service_cbk(
    uint8_t client_id, uint16_t conn_id, gattc_discovery_service_result_t *service, errcode_t status)
{
    unused(conn_id);
    unused(client_id);
    unused(service);
    unused(status);
    gattc_discovery_character_param_t param = {0};
    if (memcmp(service->uuid.uuid, g_uuid_server, service->uuid.uuid_len) == 0) {
        osal_printk(":%02x:%02x\n", service->uuid.uuid[0], service->uuid.uuid[1]);
        param.service_handle = service->start_hdl;
        param.uuid.uuid_len = service->uuid.uuid_len;
        if (memcpy_s(param.uuid.uuid, param.uuid.uuid_len, service->uuid.uuid, service->uuid.uuid_len) != 0) {
            osal_printk("%s memcpy error\n", BLE_RCU_CLIENT_ERROR);
        }
        gattc_discovery_character(g_ble_rcu_client_id, conn_id, &param);
    }
}

static void ble_rcu_gattc_discovery_service_complete_callback(
    uint8_t client_id, uint16_t conn_id, bt_uuid_t *uuid, errcode_t status)
{
    unused(conn_id);
    unused(client_id);
    unused(uuid);
    unused(status);
    g_ble_find_ready = 1;
}

static void ble_rcu_gattc_discovery_character_callback(
    uint8_t client_id, uint16_t conn_id, gattc_discovery_character_result_t *character, errcode_t status)
{
    unused(conn_id);
    unused(client_id);
    unused(character);
    unused(status);
    if (memcmp(character->uuid.uuid, g_uuid_character, character->uuid.uuid_len) == 0) {
        gattc_discovery_descriptor(g_ble_rcu_client_id, conn_id, character->declare_handle);
        if (!is_character_handle(character->value_handle)) {
            g_character_handle[g_index_type].index = g_index_type;
            g_character_handle[g_index_type].uuid.uuid_len = character->uuid.uuid_len;
            memcpy_s(g_character_handle[g_index_type].uuid.uuid, BLE_UUID_LEN, character->uuid.uuid, BLE_UUID_LEN);
            g_character_handle[g_index_type].handle = character->value_handle;
            g_index_type++;
        }
    }
}

static void ble_rcu_gattc_discovery_character_complete_callback(
    uint8_t client_id, uint16_t conn_id, gattc_discovery_character_param_t *param, errcode_t status)
{
    unused(conn_id);
    unused(client_id);
    unused(param);
    unused(status);
}

static void ble_rcu_gattc_discovery_descriptor_callback(
    uint8_t client_id, uint16_t conn_id, gattc_discovery_descriptor_result_t *descriptor, errcode_t status)
{
    unused(conn_id);
    unused(client_id);
    unused(descriptor);
    unused(status);

    gattc_read_req_by_uuid_param_t paramsss = {0};
    paramsss.uuid = descriptor->uuid;
    paramsss.start_hdl = descriptor->descriptor_hdl;
    paramsss.end_hdl = descriptor->descriptor_hdl;
    gattc_read_req_by_uuid(client_id, conn_id, &paramsss);
}

static void ble_rcu_gattc_discovery_descriptor_complete_callback(
    uint8_t client_id, uint16_t conn_id, uint16_t character_handle, errcode_t status)
{
    unused(conn_id);
    unused(client_id);
    unused(character_handle);
    unused(status);
}

static void ble_rcu_gattc_read_cfm_callback(
    uint8_t client_id, uint16_t conn_id, gattc_handle_value_t *read_result, gatt_status_t status)
{
    unused(conn_id);
    unused(client_id);
    unused(read_result);
    unused(status);
}

static void ble_rcu_gattc_read_by_uuid_complete_callback(
    uint8_t client_id, uint16_t conn_id, gattc_read_req_by_uuid_param_t *param, errcode_t status)
{
    unused(conn_id);
    unused(client_id);
    unused(param);
    unused(status);
}

static void ble_rcu_gattc_write_cfm_callback(uint8_t client_id, uint16_t conn_id, uint16_t handle, gatt_status_t status)
{
    unused(conn_id);
    unused(client_id);
    unused(handle);
    unused(status);
}

static void ble_rcu_gattc_mtu_changed_callback(uint8_t client_id, uint16_t conn_id, uint16_t mtu_size, errcode_t status)
{
    unused(conn_id);
    unused(client_id);
    unused(mtu_size);
    unused(status);
    ble_rcu_client_discover_all_service(conn_id);
}

gattc_callbacks_t g_ble_rcu_register_cbk = {
    .discovery_svc_cb = ble_rcu_dis_client_discovery_service_cbk,
    .discovery_svc_cmp_cb = ble_rcu_gattc_discovery_service_complete_callback,
    .discovery_chara_cb = ble_rcu_gattc_discovery_character_callback,
    .discovery_chara_cmp_cb = ble_rcu_gattc_discovery_character_complete_callback,
    .discovery_desc_cb = ble_rcu_gattc_discovery_descriptor_callback,
    .discovery_desc_cmp_cb = ble_rcu_gattc_discovery_descriptor_complete_callback,
    .read_cb = ble_rcu_gattc_read_cfm_callback,
    .read_cmp_cb = ble_rcu_gattc_read_by_uuid_complete_callback,
    .write_cb = ble_rcu_gattc_write_cfm_callback,
    .mtu_changed_cb = ble_rcu_gattc_mtu_changed_callback,
};

static void ble_rcu_client_sample_ssapc_cbk_register(
    gattc_notification_callback notification_cb, gattc_indication_callback indication_cb)
{
    g_ble_rcu_register_cbk.notification_cb = notification_cb;
    g_ble_rcu_register_cbk.indication_cb = indication_cb;
    gattc_register_callbacks(&g_ble_rcu_register_cbk);
}

static void ble_client_tartget_server_init(void)
{
    switch (CONFIG_RCU_MULTICON_NUM) {
        case BLE_MICRO_MULTINUM_ONE:
            g_ble_multicon_param.addr[0][BLE_ADDR_INDEX0] = CONFIG_BLE_MULTICON_SERVER1_ADDR0;
            g_ble_multicon_param.addr[0][BLE_ADDR_INDEX1] = CONFIG_BLE_MULTICON_SERVER1_ADDR1;
            g_ble_multicon_param.addr[0][BLE_ADDR_INDEX2] = CONFIG_BLE_MULTICON_SERVER1_ADDR2;
            g_ble_multicon_param.addr[0][BLE_ADDR_INDEX3] = CONFIG_BLE_MULTICON_SERVER1_ADDR3;
            g_ble_multicon_param.addr[0][BLE_ADDR_INDEX4] = CONFIG_BLE_MULTICON_SERVER1_ADDR4;
            g_ble_multicon_param.addr[0][BLE_ADDR_INDEX5] = CONFIG_BLE_MULTICON_SERVER1_ADDR5;
            break;
        case BLE_MICRO_MULTINUM_TWO:
            g_ble_multicon_param.addr[0][BLE_ADDR_INDEX0] = CONFIG_BLE_MULTICON_SERVER1_ADDR0;
            g_ble_multicon_param.addr[0][BLE_ADDR_INDEX1] = CONFIG_BLE_MULTICON_SERVER1_ADDR1;
            g_ble_multicon_param.addr[0][BLE_ADDR_INDEX2] = CONFIG_BLE_MULTICON_SERVER1_ADDR2;
            g_ble_multicon_param.addr[0][BLE_ADDR_INDEX3] = CONFIG_BLE_MULTICON_SERVER1_ADDR3;
            g_ble_multicon_param.addr[0][BLE_ADDR_INDEX4] = CONFIG_BLE_MULTICON_SERVER1_ADDR4;
            g_ble_multicon_param.addr[0][BLE_ADDR_INDEX5] = CONFIG_BLE_MULTICON_SERVER1_ADDR5;
#if defined(CONFIG_BLE_EXSIT_TWO_MULTICON_SERVER)
            g_ble_multicon_param.addr[1][BLE_ADDR_INDEX0] = CONFIG_BLE_MULTICON_SERVER2_ADDR0;
            g_ble_multicon_param.addr[1][BLE_ADDR_INDEX1] = CONFIG_BLE_MULTICON_SERVER2_ADDR1;
            g_ble_multicon_param.addr[1][BLE_ADDR_INDEX2] = CONFIG_BLE_MULTICON_SERVER2_ADDR2;
            g_ble_multicon_param.addr[1][BLE_ADDR_INDEX3] = CONFIG_BLE_MULTICON_SERVER2_ADDR3;
            g_ble_multicon_param.addr[1][BLE_ADDR_INDEX4] = CONFIG_BLE_MULTICON_SERVER2_ADDR4;
            g_ble_multicon_param.addr[1][BLE_ADDR_INDEX5] = CONFIG_BLE_MULTICON_SERVER2_ADDR5;
#endif
            break;
        default:
            break;
    }
}

void ble_rcu_client_init(gattc_notification_callback notification_cb, gattc_indication_callback indication_cb)
{
    ble_client_tartget_server_init();
    ble_rcu_client_sample_seek_cbk_register();
    ble_rcu_client_sample_ssapc_cbk_register(notification_cb, indication_cb);
    enable_ble();
}
