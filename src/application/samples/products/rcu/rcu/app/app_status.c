/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * Description: APP STATUS SOURCE \n
 *
 * History: \n
 * 2024-5-21, Create file. \n
 */
#include "securec.h"
#include "common_def.h"
#include "osal_debug.h"
#include "app_common.h"
#include "app_msg_queue.h"
#include "app_keyscan.h"
#include "app_status.h"

static app_globle_status_t g_app_cur_status;
static connect_device_info_t g_device_info;
static app_sys_status_t g_app_sys_status;
static uint8_t g_rcu_mode;
static uint8_t g_current_control_obj = NONE_DEVICE;

uint8_t get_current_control_obj(void)
{
    return g_current_control_obj;
}

void set_current_control_obj(uint8_t control_obj)
{
    g_current_control_obj = control_obj;
}

app_globle_status_t get_app_globle_status(void)
{
    return g_app_cur_status;
}

connect_device_info_t get_connect_device_info(void)
{
    return g_device_info;
}

void remove_connect_device_info(uint8_t device_target)
{
    g_device_info.connect_type[device_target] = CONNECT_NONE;
}

void set_app_sys_status(app_sys_status_t status)
{
    g_app_sys_status = status;
}

#if defined(CONFIG_SAMPLE_SUPPORT_BLE_RCU_SERVER)
void set_app_ble_adv_status(uint16_t conn_id, sle_adv_type_t status)
{
    g_app_cur_status.app_ble_adv_status[conn_id] = status;
}

void set_app_ble_conn_status(uint16_t conn_id, app_connect_status_t status)
{
    g_app_cur_status.app_ble_conn_status[conn_id] = status;
}

void set_app_ble_conn_device_info(uint16_t device_target, uint8_t con_id, const bd_addr_t *ble_addr)
{
    if (ble_addr == NULL) {
        return;
    }
    g_device_info.con_id[device_target] = con_id;
    g_device_info.connect_type[device_target] = CONNECT_BLE;
    memcpy_s(&g_device_info.ble_addr[device_target], sizeof(bd_addr_t), ble_addr, sizeof(bd_addr_t));
}

uint16_t ble_control_get_con_id(void)
{
    return g_device_info.con_id[g_current_control_obj];
}

uint16_t ble_control_get_con_state(void)
{
    uint32_t con_id = ble_control_get_con_id();
    return g_app_cur_status.app_ble_conn_status[con_id];
}

bd_addr_t* ble_control_get_ble_addr(uint8_t device_target)
{
    return &g_device_info.ble_addr[device_target];
}

uint16_t ble_control_get_specific_con_id(uint8_t device_target)
{
    return g_device_info.con_id[device_target];
}

uint16_t ble_control_get_specific_con_state(uint8_t device_target)
{
    uint32_t con_id = ble_control_get_specific_con_id(device_target);
    return g_app_cur_status.app_ble_conn_status[con_id];
}
#endif

#if defined(CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER)
void set_app_sle_adv_status(uint16_t conn_id, sle_adv_type_t status)
{
    if (conn_id >= CONFIG_RCU_MULTICON_NUM) {
        osal_printk("connect id exceeded the maximum value\r\n");
        return;
    }
    g_app_cur_status.app_sle_adv_status[conn_id] = status;
}

void set_app_sle_conn_status(uint16_t conn_id, app_connect_status_t status)
{
    if (conn_id >= CONFIG_RCU_MULTICON_NUM) {
        osal_printk("connect id exceeded the maximum value\r\n");
        return;
    }
    g_app_cur_status.app_sle_conn_status[conn_id] = status;
}

void set_app_sle_conn_device_info(uint16_t device_target, uint8_t con_id, const sle_addr_t *sle_addr)
{
    if (sle_addr == NULL) {
        return;
    }
    g_device_info.con_id[device_target] = con_id;
    g_device_info.connect_type[device_target] = CONNECT_SLE;
    memcpy_s(&g_device_info.sle_addr[device_target], sizeof(sle_addr_t), sle_addr, sizeof(sle_addr_t));
}

uint16_t sle_control_get_con_id(void)
{
    return g_device_info.con_id[g_current_control_obj];
}

uint16_t sle_control_get_con_state(void)
{
    uint32_t con_id = sle_control_get_con_id();
    return g_app_cur_status.app_sle_conn_status[con_id];
}

sle_addr_t* sle_control_get_sle_addr(uint8_t device_target)
{
    return &g_device_info.sle_addr[device_target];
}

uint16_t sle_control_get_specific_con_id(uint8_t device_target)
{
    return g_device_info.con_id[device_target];
}

uint16_t sle_control_get_specific_con_state(uint8_t device_target)
{
    uint32_t con_id = sle_control_get_specific_con_id(device_target);
    return g_app_cur_status.app_sle_conn_status[con_id];
}
#endif

void set_rcu_mode(uint8_t mode)
{
    g_rcu_mode = mode;
    app_print("[SYS]set: 0x%x, now: 0x%x\r\n", mode, g_rcu_mode);
}

void clear_rcu_mode(void)
{
    g_rcu_mode = RCU_MODE_IDLE;
}

uint8_t get_rcu_mode(void)
{
    return g_rcu_mode;
}

#if defined(CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER) || defined(CONFIG_SAMPLE_SUPPORT_BLE_RCU_SERVER)
uint8_t get_active_con_id(void)
{
#if defined(CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER)
    if (g_device_info.connect_type[g_current_control_obj] == CONNECT_SLE) {
        return sle_control_get_con_id();
    }
#endif
#if defined(CONFIG_SAMPLE_SUPPORT_BLE_RCU_SERVER)
    if (g_device_info.connect_type[g_current_control_obj] == CONNECT_BLE) {
        return ble_control_get_con_id();
    }
#endif
    return 0;
}

uint16_t app_control_get_specific_con_type(uint8_t device_target)
{
    return g_device_info.connect_type[device_target];
}
#endif

uint16_t app_control_get_con_type(void)
{
    return g_device_info.connect_type[g_current_control_obj];
}

void app_conn_info_init(void)
{
    memset_s(&g_app_cur_status, sizeof(app_globle_status_t), 0, sizeof(app_globle_status_t));
    memset_s(&g_device_info, sizeof(connect_device_info_t), 0, sizeof(connect_device_info_t));
    g_device_info.con_id[TV] = APP_DEFAULT_CONNECT_ID;
    g_device_info.con_id[OTT] = APP_DEFAULT_CONNECT_ID;
}