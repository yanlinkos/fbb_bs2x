/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2023-2024. All rights reserved.
 *
* Description: Sle Air Mouse with dongle radar \n
 *
 * History: \n
 * 2025-10-20, Create file. \n
 */
#include "radar_service.h"
#include "osal_debug.h"
#include "uapi_crc.h"
#include "air_mouse_radar.h"

#define RADAR_DEFAULT_CHANNEL_IDX 3

#ifdef CONFIG_SLP_USAGE_AIR_MOUSE_CAR
#define RADAR_DEFAULT_TX_POWER_IDX 34
#define RADAR_DEFAULT_RAW_DATA_START_BIN    0
#define RADAR_DEFAULT_RAW_DATA_END_BIN      (29)
#define RADAR_DEFAULT_SUBFRAME_PERIOD       (1816)
#define RADAR_DEFAULT_ANT_SWITCH_INTERVAL   (158)
#define RADAR_DEFAULT_LNA_CODE              (0xF)
#define RADAR_DEFAULT_VGA_CODE              (0x1D)
#define RADAR_DEFAULT_ANT_CH_NUM            (8)
#define RADAR_DEFAULT_ANT_CODE_TABLE { 1, 0, 3, 2, 5, 4, 7, 6 }
#else
#define RADAR_DEFAULT_TX_POWER_IDX 38
#define RADAR_DEFAULT_RAW_DATA_START_BIN    0
#define RADAR_DEFAULT_RAW_DATA_END_BIN      (44)
#define RADAR_DEFAULT_SUBFRAME_PERIOD       (687)
#define RADAR_DEFAULT_ANT_SWITCH_INTERVAL   (687)
#define RADAR_DEFAULT_LNA_CODE              (0xF)
#define RADAR_DEFAULT_VGA_CODE              (0x01)
#define RADAR_DEFAULT_ANT_CH_NUM            (1)
#define RADAR_DEFAULT_ANT_CODE_TABLE { 0, 0, 0, 0, 0, 0, 0, 0 }
#endif

#define RADAR_DEFAULT_SPREAD_FACTOR     (8)
#define RADAR_DEFAULT_ACC_RSHIFT_BIT    (2)
#define RADAR_DEFAULT_ACC_NUM           (1023)
#define RADAR_DEFAULT_CORR_DIV          (16)
#define RADAR_DEFAULT_TX_WAVE_LEN       (31)
#define RADAR_DEFAULT_31N6_TX_WAVE_BITS {0, 0, 0, 0, 1, 0, -1, 0, 1, 1, \
                                         1, 0, 1, -1, 0, 0, 0, 1, -1, 1, \
                                         1, 1, 0, 0, -1, 1, 0, -1, 0, 0, -1}

#define RADAR_RAW_DATA_CNT_INIT_VALUE 0xFFFF
#define RADAR_RAW_DATA_PRINT_INFO_PERIOD 100
#define RADAR_RAW_DATA_NORMAL_RPT_INTERVAL 1
#define RADAR_DEFAULT_SW_CTRL_EN (7)

static uint16_t g_raw_data_frame_cnt = RADAR_RAW_DATA_CNT_INIT_VALUE;
static uint8_t g_default_ant_code[RADAR_MAX_ANT_CH_NUM] = RADAR_DEFAULT_ANT_CODE_TABLE;

static void InitHardwarePara(radar_hardware_para_t *hwPara)
{
    hwPara->rf_para.ch_idx = RADAR_DEFAULT_CHANNEL_IDX;
    hwPara->rf_para.ant_ch_num = RADAR_DEFAULT_ANT_CH_NUM;
    for (uint8_t i = 0; i < RADAR_MAX_ANT_CH_NUM; i++) {
        hwPara->rf_para.tx_power_idx[i] = RADAR_DEFAULT_TX_POWER_IDX;
        hwPara->rf_para.agc_para.lna_code[i] = RADAR_DEFAULT_LNA_CODE;
        hwPara->rf_para.agc_para.vga_code[i] = RADAR_DEFAULT_VGA_CODE;
        hwPara->rf_para.ant_code[i] = g_default_ant_code[i];
    }
    hwPara->frame_para.subframe_period = RADAR_DEFAULT_SUBFRAME_PERIOD;
    hwPara->frame_para.ant_switch_interval = RADAR_DEFAULT_ANT_SWITCH_INTERVAL;
    hwPara->raw_data_para.start_bin = RADAR_DEFAULT_RAW_DATA_START_BIN;
    hwPara->raw_data_para.end_bin = RADAR_DEFAULT_RAW_DATA_END_BIN;
    hwPara->rf_para.ant_sw_ctrl_en.u8 = RADAR_DEFAULT_SW_CTRL_EN;

    hwPara->wave_para.spread_factor = RADAR_DEFAULT_SPREAD_FACTOR;
    hwPara->wave_para.acc_rshift_bit = RADAR_DEFAULT_ACC_RSHIFT_BIT;
    hwPara->wave_para.acc_num = RADAR_DEFAULT_ACC_NUM;
    hwPara->wave_para.corr_div = RADAR_DEFAULT_CORR_DIV;
    hwPara->wave_para.tx_wave_len = RADAR_DEFAULT_TX_WAVE_LEN;
    int8_t wave_bits[RADAR_DEFAULT_TX_WAVE_LEN] = RADAR_DEFAULT_31N6_TX_WAVE_BITS;
    for (uint8_t i = 0; i < RADAR_DEFAULT_TX_WAVE_LEN; i++) {
        hwPara->wave_para.tx_wave_bits[i] = wave_bits[i];
    }
}

void uapi_radar_raw_data_cb_func(radar_raw_data_msg_t *dataMsg)
{
    // 对雷达原始数据进行CRC校验
    uint16_t crc = uapi_crc16(0, (uint8_t*)(dataMsg->data), dataMsg->data_len);
    if (crc != dataMsg->crc) {
        osal_printk("radar_raw_data_cb:: CRC check failed, %d != %d\r\n", crc, dataMsg->crc);
    }

    // 根据宽带测产生的计数进行序号校验，每上报一次计数器值会加1
    if (g_raw_data_frame_cnt != RADAR_RAW_DATA_CNT_INIT_VALUE) {
        uint16_t counter_diff = dataMsg->counter - g_raw_data_frame_cnt;
        if (counter_diff != RADAR_RAW_DATA_NORMAL_RPT_INTERVAL) {
            osal_printk("radar_raw_data_cb:: frame not continuous, prevCnt:%d, currCnt:%d, diff:%d\r\n",
                g_raw_data_frame_cnt, dataMsg->counter, counter_diff);
        }
    }
    g_raw_data_frame_cnt = dataMsg->counter;

    // 雷达原始数据基本信息打印，以打印数据长度、计数器值和起始&结束Bin的索引为例。每隔100次上报打印一次，防止刷屏。
    if (dataMsg->counter % RADAR_RAW_DATA_PRINT_INFO_PERIOD == 0) {
        osal_printk("recv data len:%u, cnt:%u, bin:[%u,%u]\r\n", dataMsg->data_len, dataMsg->counter,
            dataMsg->data_para.start_bin, dataMsg->data_para.end_bin);
    }
}

void air_mouse_radar_init(void)
{
    errcode_radar_client_t ret;
    radar_hardware_para_t para = {0};
    InitHardwarePara(&para);
    ret = uapi_radar_set_hardware_para(&para);
    if (ret != ERRCODE_RC_SUCCESS) {
        osal_printk("uapi_radar_set_hardware_para Error 0x%x\r\n", ret);
        return;
    }

    ret = uapi_radar_register_raw_data_cb(uapi_radar_raw_data_cb_func);
    if (ret != ERRCODE_RC_SUCCESS) {
        osal_printk("uapi_radar_register_raw_data_cb Error 0x%x\r\n", ret);
        return;
    }
    osal_printk("air_mouse_radar_init succ");
}

void air_mouse_radar_start(void)
{
    errcode_radar_client_t ret = uapi_radar_set_status(RADAR_STATUS_START);
    if (ret != ERRCODE_RC_SUCCESS) {
        osal_printk("air_mouse_radar_start Error 0x%x\r\n", ret);
        return;
    }
    // 在下发雷达开启成功后，对原始数据计数器赋初始值
    g_raw_data_frame_cnt = RADAR_RAW_DATA_CNT_INIT_VALUE;
}

void air_mouse_radar_stop(void)
{
    errcode_radar_client_t ret = uapi_radar_set_status(RADAR_STATUS_STOP);
    if (ret != ERRCODE_RC_SUCCESS) {
        osal_printk("air_mouse_radar_stop Error 0x%x\r\n", ret);
        return;
    }
    // 在下发雷达停止成功后，对原始数据计数器赋初始值
    g_raw_data_frame_cnt = RADAR_RAW_DATA_CNT_INIT_VALUE;
}

void air_mouse_radar_get_version(void)
{
    // 在雷达启动成功后才能获取雷达版本信息
    radar_version_info_t version;
    errcode_radar_client_t ret = uapi_radar_get_version(&version);
    if (ret != ERRCODE_RC_SUCCESS) {
        osal_printk("uapi_radar_get_version Error 0x%x\r\n", ret);
        return;
    }
    osal_printk("radar version: narrow band:%d.%d.%d, wide band:%d.%d.%d\r\n", version.narrow_band.major,
                version.narrow_band.minor, version.narrow_band.patch, version.wide_band.major, version.wide_band.minor,
                version.wide_band.patch);
}