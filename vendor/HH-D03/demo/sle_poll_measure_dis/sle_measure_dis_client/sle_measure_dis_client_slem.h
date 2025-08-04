/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2023-2023. All rights reserved.
 *
 * Description: SLE MEASURE_DIS sample of client. \n
 *
 * History: \n
 * 2023-04-03, Create file. \n
 */
#ifndef SLE_MEASURE_DIS_CLIENT_SLEM_H
#define SLE_MEASURE_DIS_CLIENT_SLEM_H

#include "sle_measure_dis_client_slem.h"
#include "sle_hadm_manager.h"

#define MEASURE_DIS_IQ_REPORT_CNT_MAX 1
#define POSALG_DATA_NUM 79
#define IQ_DATA_MAX (MEASURE_DIS_IQ_REPORT_CNT_MAX * SLE_CS_IQ_REPORT_COUNT)

typedef struct {
    uint16_t i_data;
    uint16_t q_data;
} measure_dis_stored_qte_trans_t;

typedef struct {
    uint8_t samp_cnt;
    uint8_t rssi;
    uint16_t es_sn;
    uint32_t timestamp_sn;
    measure_dis_stored_qte_trans_t data[IQ_DATA_MAX];
#if (defined(GLE_CS_MODE3_SUPPORT))
    uint32_t tof_result;/*如果定义了GLE_CS_MODE3_SUPPORT宏，则还会包含一个tof_result字段，可能用于存储时间飞行（Time of Flight）的测量结果。*/
#endif
} measure_dis_stored_iq_data_t;/*用于存储与IQ数据相关的多个字段，包括样本计数、RSSI（接收信号强度指示）、序列号、时间戳，以及一个measure_dis_stored_qte_trans_t类型的数组，用于存储实际的IQ数据。*/

typedef struct {
    uint16_t i_data;
    uint16_t q_data;
} sle_channel_sounding_qte_trans_t;/*用于存储CS IQ数据*/

typedef struct {
    uint8_t samp_cnt;
    uint8_t rssi;
    uint16_t es_sn;
    uint32_t timestamp_sn;
    sle_channel_sounding_qte_trans_t data[IQ_DATA_MAX];
    uint32_t tof_result;
} sle_channel_sounding_iq_trans_t;/*用于存储与CS IQ数据样本、样本数量、RSSI值、序列号、时间戳、TOF;*/

errcode_t measure_dis_reg_callbacks(void);/*回调函数注册*/

#endif