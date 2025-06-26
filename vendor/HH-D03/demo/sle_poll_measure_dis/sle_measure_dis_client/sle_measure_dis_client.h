/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2023-2023. All rights reserved.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef SLE_MEASURE_DIS_CLIENT_H
#define SLE_MEASURE_DIS_CLIENT_H

#include <stdint.h>
#include <securec.h>
#include "errcode.h"
#include "std_def.h"
#include "soc_osal.h"
#include "common_def.h"
#include "sle_ssap_client.h"
/*表示不同的数量级和连接状态,用于距离测量单位转换*/
#define MEASURE_DIS_NUM_CARRY_10_7     10000000
#define MEASURE_DIS_NUM_CARRY_1000     1000
#define MEASURE_DIS_NUM_CARRY_100      100
#define MEASURE_DIS_NUM_CARRY_10       10
#define MEASURE_DIS_NUM_CARRY_2        2

#define SLEM_CONNET_INVAILD 0xFF

#define MAX_SERVERS 3                                               

typedef enum {
    SLEM_PROFILE_MSG_IQ = 0xFFFFFFEA,
} slem_profile_msg_type_t;

typedef struct {
    uint32_t        type;                             
    uint32_t        len;                             
    uint8_t         data[0];
} measure_ids_msg_t;

typedef struct server_data {
    uint8_t property_uuid[SLE_UUID_LEN];
    uint8_t server_uuid[SLE_UUID_LEN];
    uint8_t service_uuid[SLE_UUID_LEN];
    uint16_t begin_hdl;
    uint16_t end_hdl;
    uint16_t property_handle;
} measure_dis_server_data_t;

static inline void check_rc_return_rc(uint32_t rc, char *err)
{
    do {
        if ((rc) != ERRCODE_SUCC) {
            osal_printk("CARKEY ERROR: %s fail!: call %s return 0x%x!\n", err, __FUNCTION__, rc);
        }
    } while (0);
}

int measure_dis_client_write_server(uint16_t conn_id, uint32_t type, uint8_t *data, uint32_t data_len);
int measure_dis_client_init(void);
int measure_dis_start_scan(void);
void switch_to_next_server(void);

#endif