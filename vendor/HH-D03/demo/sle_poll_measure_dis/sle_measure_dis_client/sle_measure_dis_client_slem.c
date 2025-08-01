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
#include "sle_measure_dis_client.h"
#include "sle_errcode.h"
#include "sle_common.h"
#include "sle_ssap_client.h"
#include "sle_hadm_manager.h"
#include "cmsis_os2.h"
#include "sle_measure_dis_client_slem.h"

measure_dis_stored_iq_data_t g_local_iq_data;/*存储IQ数据*/
uint8_t g_next_idx;/*用于跟踪或索引某种数据结构中的下一个位置*/
uint8_t g_store_local_iq_complete;/*标记本地IQ数据存储是否完成*/

uint8_t g_iq_debug_flag = 0;/*调试标志,非零时启动IO数据的打印功能，修改为1才可打印IQ数据*/

void measure_dis_print_iq_data(uint8_t num, uint8_t role, sle_channel_sounding_iq_trans_t *report)
{
    if (!g_iq_debug_flag) {
        return;
    }
    osal_printk("[iq_data]%d,%d,%d,%d,0x%x,",
                num, role, report->timestamp_sn, report->samp_cnt, report->rssi);
    sle_channel_sounding_qte_trans_t *data = report->data;
    uint16_t i = 0;
    while (i < POSALG_DATA_NUM) {
        osal_printk("[%d]:0x%x,0x%x", i, data[i].i_data, data[i].q_data);
        i++;
        if (i == POSALG_DATA_NUM) {
            osal_printk(".\r\n");
        } else {
            osal_printk(";");
        }
    }
}

/*将接收到的 IQ 数据（来自 sle_channel_sounding_iq_report_t 结构体）存储到本地变量 g_local_iq_data 中。同时，它还会进行一些错误检查和状态更新。*/
errcode_t measure_dis_store_local_iq(sle_channel_sounding_iq_report_t *report)
{
    if (report->report_idx == 0) {
        g_local_iq_data.samp_cnt = 0;
        g_local_iq_data.rssi = report->rssi[0];
        g_local_iq_data.es_sn = report->es_sn;
        g_local_iq_data.timestamp_sn = report->timestamp_sn;
#if (defined(GLE_CS_MODE3_SUPPORT))
        g_local_iq_data.tof_result = report->tof_result;
#endif
        g_next_idx = 0;
    }
    if ((report->report_idx >= MEASURE_DIS_IQ_REPORT_CNT_MAX || report->timestamp_sn != g_local_iq_data.timestamp_sn) ||
        (g_next_idx != report->report_idx)) {
        osal_printk("SLEM STORE LOCAL IQ FAIL. report_idx:%d, timestamp:%d, g_next_idx:%d. \r\n",
                    report->report_idx, report->timestamp_sn, g_next_idx);
        return ERRCODE_INVALID_PARAM;
    }
    g_local_iq_data.samp_cnt += report->samp_cnt;
    uint8_t offset = report->report_idx * SLE_CS_IQ_REPORT_COUNT;
    for (uint8_t i = 0; i < report->samp_cnt; i++) {
        g_local_iq_data.data[offset + i].i_data = report->i_data[i];
        g_local_iq_data.data[offset + i].q_data = report->q_data[i];
    }
    osal_printk("local iq es:%d, time_stamp:%d group:%d, num:%d \r\n",
                report->es_sn, report->timestamp_sn, report->report_idx, 0);
    g_next_idx = report->report_idx + 1;

#if (defined(GLE_CS_MODE3_SUPPORT))
    osal_printk("local tof_result = %d.%03d \r\n", report->tof_result / MEASURE_DIS_NUM_CARRY_1000,
                report->tof_result % MEASURE_DIS_NUM_CARRY_1000);
#endif

    return ERRCODE_SUCC;
}

errcode_t measure_dis_recv_local_iq(uint16_t conn_id, sle_channel_sounding_iq_report_t *report)
{
    osal_printk("enter slem_recv_local_iq conn_id:%d. \r\n", conn_id);
    errcode_t ret = ERRCODE_SUCC;

    ret = measure_dis_store_local_iq(report);
    if (ret != ERRCODE_SUCC) {
        return ERRCODE_INVALID_PARAM;
    }

    if (report->report_idx + 1 == MEASURE_DIS_IQ_REPORT_CNT_MAX) {
        /* 如果是钥匙则发送给从锚点 */
        measure_dis_print_iq_data(0, 0, (sle_channel_sounding_iq_trans_t *)(&g_local_iq_data));
        measure_dis_client_write_server(conn_id,SLEM_PROFILE_MSG_IQ,
                                        (uint8_t *)&g_local_iq_data, sizeof(sle_channel_sounding_iq_trans_t));/*调用measure_dis_client_write_server函数，将IQ数据（通过&g_local_iq_data访问）发送到服务器（从设备或锚点）。*/
    }
    return ret;
}

void measure_dis_read_local_cs_caps_cb(sle_channel_sounding_caps_t *caps, errcode_t status)
{
    UNUSED(caps);
    osal_printk("SLEM READ LOCAL CAPS. status:%d. \r\n", status);
}

void measure_dis_read_remote_cs_caps_cb(uint16_t conn_id, sle_channel_sounding_caps_t *caps, errcode_t status)
{
    UNUSED(caps);
    UNUSED(conn_id);
    osal_printk("SLEM READ REMOTE CAPS. status:%d. \r\n", status);
}

void measure_dis_set_cs_param_cb(uint16_t conn_id, errcode_t status)
{
    UNUSED(conn_id);
    osal_printk("SLEM SET PARAM. status:%d. \r\n", status);
}

void measure_dis_cs_state_changed_cb(uint8_t slem_status, errcode_t status)
{
    unused(slem_status);
    osal_printk("SLEM STATE CHANGED. status:%d. \r\n", status);
}

void measure_dis_cs_iq_report_cb(uint16_t conn_id, sle_channel_sounding_iq_report_t *report)
{
    if (report->report_idx == 0) {
        osal_printk("RECEIVE LOCAL IQ. timestamp_sn:%d \r\n",  report->timestamp_sn);
    }
    measure_dis_recv_local_iq(conn_id, report);
}

errcode_t measure_dis_reg_callbacks(void)
{
    sle_hadm_callbacks_t scd_cbks = {0};

    scd_cbks.read_local_cs_caps_cb = measure_dis_read_local_cs_caps_cb;
    scd_cbks.read_remote_cs_caps_cb = measure_dis_read_remote_cs_caps_cb;
    scd_cbks.cs_state_changed_cb = measure_dis_cs_state_changed_cb;
    scd_cbks.cs_iq_report_cb = measure_dis_cs_iq_report_cb;

    errcode_t ret = sle_hadm_register_callbacks(&scd_cbks);
    osal_printk("SCD SET CALLBACK DONE. ret = %x.\r\n", ret);
    return ret;
}