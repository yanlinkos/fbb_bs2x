/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2023-2023. All rights reserved.
 *
 * Description: ble rcu sample of client. \n
 *
 * History: \n
 * 2023-09-21, Create file. \n
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "string.h"
#include "securec.h"
#include "osal_debug.h"
#include "lm_ble_scan.h"
#include "ble_rcu_until.h"

bool ble_rcu_bdaddr_compare(uint8_t const *bd_address1, bd_addr_t const *bd_address2)
{
    for (uint8_t idx = 0; idx < BD_ADDR_LEN; idx++) {
        if (bd_address1[idx] != bd_address2->addr[idx]) {
            return false;
        }
    }
    return true;
}

void ble_rcu_scan_remove_adv_list(const uint8_t *adv_addr)
{
    osal_printk("[ble] remove adv list");
    lm_ble_scan_desc_t *scan_desc = lm_ble_scan_get_desc();
    if (scan_desc == NULL) {
        osal_printk("[ble] get desc is NULL\r\n");
        return;
    }

    lm_ble_scan_adv_list_t *list_adv_addr = (lm_ble_scan_adv_list_t *)list_head(&scan_desc->adv_list);

    while (list_adv_addr != NULL) {
        if (ble_rcu_bdaddr_compare(adv_addr, &list_adv_addr->adv_addr)) {
            memset_s(&list_adv_addr->adv_addr, sizeof(bd_addr_t), 0, sizeof(bd_addr_t));
        }

        // 获取下一个 adv
        list_adv_addr = (lm_ble_scan_adv_list_t *)(list_adv_addr->hdr.next);
    }
}