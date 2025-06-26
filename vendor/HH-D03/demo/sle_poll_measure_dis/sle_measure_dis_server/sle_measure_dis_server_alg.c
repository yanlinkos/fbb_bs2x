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

#include "sle_measure_dis_server.h"
#include "sle_common.h"
#include "smooth.h"
#include "alg_smooth_dis.h"
#include "tcxo.h"
#include "pm_clock.h"
#include "sle_measure_dis_server_alg.h"

#define TOF_DEFAULT 2070
#define DIS_ALG_MODE 4/*表示距离测量算法的工作模式*/
#define DIS_ALG_RSSI_LIMIT (-120)/*表示RSSI的阈值*/
#define DIS_ALG_THRESHOULD_COND2 20/*可能用于算法中的某个条件判断，比如作为阈值或计数器的一部分，具体含义需要根据算法的实现来确定。*/
#define DIS_ALG_R_START 2

uint8_t g_iq_debug_flag = 0;/*修改为1才可打印出IQ数据*/
uint32_t counter = 0;

measure_dis_stored_iq_data_t g_md_local_iq_data;
uint8_t g_md_store_local_iq_complete;
uint8_t g_next_idx;
/*为alg_para结构体设置一些基本的参数，包括校准值（calib_val）、飞行时间校准值（tof_calib）和算法模式标志（flag_inter）*/
void slem_posalg_set_base_para(alg_para_dis *alg_para, uint8_t key_id)
{
    unused(key_id);
    alg_para->calib_val = 0;
    alg_para->tof_calib = TOF_DEFAULT;
    alg_para->flag_inter = DIS_ALG_MODE;
}
/*用于打印距离测量的结果，包括第一次测量的距离（dist_first）、第二次测量的距离（虽然在这个函数中被标记为unused）、概率（prob，同样被标记为unused）和时间戳（time）。*/
void measure_dis_print_cal_dis(float dist_first, float dist_second, float prob, uint64_t time)
{
    unused(dist_second);
    unused(prob);
    osal_printk(
        "SLEM get distance done. dist_first:%d.%03d, time = %d ms. \r\n",
        (int32_t)(dist_first), ((uint32_t)(dist_first * MEASURE_DIS_NUM_CARRY_1000) % MEASURE_DIS_NUM_CARRY_1000),
        (uint32_t)(time));
}
/*函数将dis_result结构体中的距离测量结果复制到measure_dis_profile_msg_dis_t结构体中。这包括第一次测量的距离（dist_first）、第二次测量的距离（dist_second）、双重测量的距离（dist_double）、高位值（high）、概率（prob）、RSSI（rssi）和平滑次数（smooth_num）。这个函数可能是距离测量算法与上层应用或数据报告之间的桥梁，负责将计算得到的结果封装成一种更易于处理或传输的格式。*/
static void measure_dis_posalg_set_distance(dis_result *dis, measure_dis_profile_msg_dis_t *measure_dis_temp)
{
    measure_dis_temp->dist_first = dis->dist_first;
    measure_dis_temp->dist_second = dis->dist_second;
    measure_dis_temp->dist_double = dis->dist_double;
    measure_dis_temp->high = dis->high;
    measure_dis_temp->prob = dis->prob;
    measure_dis_temp->rssi = dis->rssi;
    measure_dis_temp->smooth_num = dis->smooth_num;
}
/*函数接受一个指向alg_para_dis结构体的指针alg_para作为参数，并为其成员变量设置基础或默认的参数值*/
void measure_dis_posalg_set_base_para(alg_para_dis *alg_para)
{
    alg_para->calib_val = 0.8; /* 根据5次测量平均值0.8来校准 */
    alg_para->tof_calib = TOF_DEFAULT;
    alg_para->flag_inter = DIS_ALG_MODE;
}

void measure_dis_posalg_get_distance(measure_dis_profile_msg_dis_t *measure_dis_temp,
                                     sle_channel_sounding_iq_trans_t *remote_iq_data)
{
    alg_para_dis *alg_para = (alg_para_dis *)osal_kmalloc(sizeof(alg_para_dis), 0);/*使用osal_kmalloc为alg_para_dis结构体分配内存*/

    slem_posalg_set_base_para(alg_para, 0);/*分配和初始化参数,调用slem_posalg_set_base_para来设置基础参数*/
    alg_para->rssi_rtd = g_md_local_iq_data.rssi;
    alg_para->rssi_dut = remote_iq_data[0].rssi;
#if (defined(GLE_CS_MODE3_SUPPORT))
    alg_para->tof_rtd = g_md_local_iq_data.tof_result;
    alg_para->tof_dut = remote_iq_data[0].tof_result;
#endif
    alg_para->iq_rtd = (alg_iq *)&(g_md_local_iq_data.data[0]);/*填充特定参数*/
    alg_para->iq_dut = (alg_iq *)&(remote_iq_data[0].data[0]);
    g_md_store_local_iq_complete = false;

    para_pair para_limit = {.rssi_limit = DIS_ALG_RSSI_LIMIT,
                            .threshold_cond2 = DIS_ALG_THRESHOULD_COND2,
                            .r_start = DIS_ALG_R_START};
    alg_para->para_limit = para_limit;
    para_keys_info keys_info = {0, 1};
    alg_para->keys_info = keys_info;
    /* remote iq 是 dut， local iq 是 rtd */
    uapi_clock_control(CLOCK_CONTROL_FREQ_LEVEL_CONFIG, CLOCK_FREQ_LEVEL_HIGH);
    uint64_t time_start = uapi_tcxo_get_ms();/*配置时钟和测量时间*/

    alg_para->cur_count = counter;
    alg_para->cur_time = uapi_tcxo_get_ms();
    dis_result result_dist = slem_alg_calc_smoothed_dis(alg_para);/*调用算法计算距离*/
    counter++;
    uint64_t time_end = uapi_tcxo_get_ms();
    uapi_clock_control(CLOCK_CONTROL_FREQ_LEVEL_CONFIG, CLOCK_FREQ_LEVEL_LOW_POWER);
    measure_dis_print_cal_dis(result_dist.dist_first, result_dist.dist_second,
                              result_dist.prob, time_end - time_start);/*打印结果,打印计算出的距离、概率和所需时间。同时，还打印了DUT和RTD的RSSI值。*/
    osal_printk("dut_rssi = %d, rtd_rssi = %d. \r\n", result_dist.rssi_dut, result_dist.rssi_rtd);

    measure_dis_posalg_set_distance(&result_dist, measure_dis_temp);/*设置距离结果,将计算出的距离结果复制到measure_dis_temp结构体中，以供后续使用。*/
    osal_kfree(alg_para);/*清理资源,释放为alg_para结构体分配的内存，并将系统时钟设置回低功耗模式。*/
}

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

errcode_t measure_dis_store_local_iq(sle_channel_sounding_iq_report_t *report)
{
    if (report->report_idx == 0) {
        g_md_local_iq_data.samp_cnt = 0;
        g_md_local_iq_data.rssi = report->rssi[0];
        g_md_local_iq_data.es_sn = report->es_sn;
        g_md_local_iq_data.timestamp_sn = report->timestamp_sn;
#if (defined(GLE_CS_MODE3_SUPPORT))
        g_md_local_iq_data.tof_result = report->tof_result;
#endif
        g_next_idx = 0;
    }
    if ((report->report_idx >= MEASURE_DIS_IQ_REPORT_CNT_MAX ||
         report->timestamp_sn != g_md_local_iq_data.timestamp_sn) ||
        (g_next_idx != report->report_idx)) {
        osal_printk("MEASURE_DIS STORE LOCAL IQ FAIL. report_idx:%d, timestamp:%d, g_next_idx:%d. \r\n",
                    report->report_idx, report->timestamp_sn, g_next_idx);
        return ERRCODE_INVALID_PARAM;
    }
    g_md_local_iq_data.samp_cnt += report->samp_cnt;
    uint8_t offset = report->report_idx * SLE_CS_IQ_REPORT_COUNT;
    for (uint8_t i = 0; i < report->samp_cnt; i++) {
        g_md_local_iq_data.data[offset + i].i_data = report->i_data[i];
        g_md_local_iq_data.data[offset + i].q_data = report->q_data[i];
    }
    g_next_idx = report->report_idx + 1;

#if (defined(GLE_CS_MODE3_SUPPORT))
    osal_printk("local tof_result = %d.%03d \r\n", report->tof_result / MEASURE_DIS_NUM_CARRY_1000,
                report->tof_result % MEASURE_DIS_NUM_CARRY_1000);
#endif

    return ERRCODE_SUCC;
}

errcode_t measure_dis_proc_local_iq(uint16_t conn_id, sle_channel_sounding_iq_report_t *report)
{
    unused(conn_id);
    if (report->report_idx == 0) {
        osal_printk("RECEIVE LOCAL IQ. timestamp_sn:%d \r\n",  report->timestamp_sn);
    }/*收到的第一个IQ报告，打印出时间戳序列号*/
    errcode_t ret = ERRCODE_SUCC;

    ret = measure_dis_store_local_iq(report);/*存储IQ报告*/
    if (ret != ERRCODE_SUCC) {
        return ERRCODE_INVALID_PARAM;
    }
/*检查IO数据报告是否完整*/
    if (report->report_idx + 1 == MEASURE_DIS_IQ_REPORT_CNT_MAX) {
        g_md_store_local_iq_complete = true;
        osal_printk("store local iq data commplete . \r\n");
        /* 如果是钥匙则发送给从锚点 */
        measure_dis_print_iq_data(0, 0, (sle_channel_sounding_iq_trans_t *)(&g_md_local_iq_data));
    }
    return ret;
}

errcode_t measure_dis_proc_remote_iq(uint16_t conn_id, sle_channel_sounding_iq_trans_t *report)
{
    unused(conn_id);
    uint8_t num = 0; /* SLAVE只有一路MEASURE_DIS业务 */
    measure_dis_print_iq_data(0, 1, report);/*打印IQ数据*/
    if (abs((int32_t)(g_md_local_iq_data.timestamp_sn - report->timestamp_sn)) >= MEASURE_DIS_TIMESTAMP_DIFF_MAX) {
        if (g_md_local_iq_data.timestamp_sn > report->timestamp_sn) {
            osal_printk("current remote es_sn is too early.\r\n");
        } else {
            osal_printk("current remote es_sn is too late.\r\n");
        }
        osal_printk("local:%d, remote:%d. \r\n",
                    g_md_local_iq_data.timestamp_sn, report->timestamp_sn);
        return ERRCODE_INVALID_PARAM;
    }/*时间戳验证,检查本地和远程IQ报告的时间戳序列号（timestamp_sn）差异是否在允许范围内*/

    osal_printk("local ts = %d, remote ts = %d.  num[%d], local commplete status:%d.\r\n",
                g_md_local_iq_data.timestamp_sn, report->timestamp_sn, num, g_md_store_local_iq_complete);

    if (g_md_store_local_iq_complete) {
        g_md_store_local_iq_complete = false;/*被重置为false，以表示本地数据已被处理*/
        measure_dis_profile_msg_dis_t measure_dis_dis_temp = { report->timestamp_sn, 0, 0, 0, 0, 0, 0, 0};
        measure_dis_posalg_get_distance(&measure_dis_dis_temp, (sle_channel_sounding_iq_trans_t *)report);
    }/*本地IQ数据收集已完成（g_md_store_local_iq_complete为true），则调用measure_dis_posalg_get_distance函数来基于本地和远程的IQ数据计算距离。*/

    return ERRCODE_SUCC;
}
/*读取本地（设备自身）的信道探测（Channel Sounding）能力的回调函数*/
void measure_dis_read_local_cs_caps_cb(sle_channel_sounding_caps_t *caps, errcode_t status)
{
    unused(caps);
    osal_printk("SLEM READ LOCAL CAPS. status:%d. \r\n", status);
}
/*读取远程（对端设备）的信道探测能力的回调函数*/
void measure_dis_read_remote_cs_caps_cb(uint16_t conn_id, sle_channel_sounding_caps_t *caps, errcode_t status)
{
    unused(caps);
    unused(conn_id);
    osal_printk("SLEM READ REMOTE CAPS. status:%d. \r\n", status);
}

void measure_dis_set_cs_param_cb(uint16_t conn_id, errcode_t status)
{
    unused(conn_id);
    osal_printk("SLEM SET PARAM. status:%d. \r\n", status);
}

void measure_dis_cs_state_changed_cb(errcode_t status)
{
    osal_printk("SLEM STATE CHANGED. status:%d. \r\n", status);
}

void measure_dis_cs_iq_report_cb(uint16_t conn_id, sle_channel_sounding_iq_report_t *report)
{
    errcode_t ret = ERRCODE_FAIL;

    sle_channel_sounding_iq_report_t *report_local = NULL;
    uint32_t len = sizeof(sle_channel_sounding_iq_report_t);
    report_local = (sle_channel_sounding_iq_report_t *)osal_kmalloc(len, 0);
    if (report_local == NULL) {
        return;
    }
    if (memcpy_s(report_local, sizeof(sle_channel_sounding_iq_report_t), report, len) != EOK) {
        osal_kfree(report_local);
        return;
    }
    measure_dis_msg_node_t msg_node = {conn_id, SLEM_MSG_LOCAL_IQ, 0, report_local};
    ret = sle_measure_dis_msg_add(&msg_node);
    if (ret != ERRCODE_SUCC) {
        osal_kfree(report_local);
    }
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

errcode_t measure_dis_recv_local_iq(measure_dis_msg_node_t *msg_node)
{
    /* key send to anchor */
    errcode_t ret = measure_dis_proc_local_iq(msg_node->conn_id, (sle_channel_sounding_iq_report_t *)(msg_node->data));
    osal_kfree(msg_node->data);
    osal_event_write(&measure_dis_evt, MEASURE_DIS_MSG_EVENT);
    return ret;
}

errcode_t measure_dis_recv_remote_iq(measure_dis_msg_node_t *msg_node)
{
    osal_printk("slem recv remote iq.\n");
    errcode_t ret = measure_dis_proc_remote_iq(msg_node->conn_id, (sle_channel_sounding_iq_trans_t *)(msg_node->data));
    osal_kfree(msg_node->data);
    osal_event_write(&measure_dis_evt, MEASURE_DIS_MSG_EVENT);
    return ret;
}
/*根据消息类型调用相应的处理函数*/
errcode_t measure_dis_match_msg(measure_dis_msg_node_t *msg_node)
{
    errcode_t ret = ERRCODE_FAIL;
    osal_printk("---enter sle_slem_msg_proc, type:%d---\n", msg_node->type);
    switch (msg_node->type) {
        case SLEM_MSG_LOCAL_IQ:
            ret = measure_dis_recv_local_iq(msg_node);
            break;
        case SLEM_MSG_REMOTE_IQ:
            ret = measure_dis_recv_remote_iq(msg_node);
            break;
        default:
            break;
    }
    return ret;
}

errcode_t measure_dis_remote_iq(uint16_t len, uint8_t *value)
{
    UNUSED(len);
    errcode_t ret = ERRCODE_FAIL;
    sle_channel_sounding_iq_trans_t *report = NULL;
    report = (sle_channel_sounding_iq_trans_t *)osal_kmalloc(sizeof(sle_channel_sounding_iq_trans_t), 0);
    if (report == NULL) {
        return ERRCODE_MALLOC;
    }
    if (memcpy_s(report, sizeof(sle_channel_sounding_iq_trans_t), value, len) != EOK) {
        osal_kfree(report);
        return ERRCODE_MEMCPY;
    }
    osal_printk("RECEIVE REMOTE IQ. timestamp_sn:%d \r\n", report->timestamp_sn);
    measure_dis_msg_node_t msg_node = {g_measure_dis_conn_id, SLEM_MSG_REMOTE_IQ, 0, report};
    ret = sle_measure_dis_msg_add(&msg_node);
    if (ret != ERRCODE_SUCC) {
        osal_kfree(report);
    }

    return ret;
}