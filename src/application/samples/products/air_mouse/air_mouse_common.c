/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * Description: Air Mouse Common Source File. \n
 *
 * History: \n
 * 2025-05-15, Create file. \n
 */
#include "osal_debug.h"
#include "securec.h"
#include "slp.h"
#include "usb/air_mouse_usb.h"
#include "common_def.h"

#define SLP_IMU_TYPE_NUM (SLP_IMU_TYPE_ASM330 + 1)

#if CONFIG_AIR_MOUSE_HR_BOARD || CONFIG_AIR_MOUSE_HX_BOARD
#if CONFIG_SAMPLE_SUPPORT_AIR_MOUSE
// 参考设计板RCU
SlpTransformParam g_slpTransformParamArr[SLP_IMU_TYPE_NUM] = {
    {{SLP_IMU_AXIS_Y, +1}, {SLP_IMU_AXIS_X, +1}, {SLP_IMU_AXIS_Z, -1}}, // SLP_IMU_TYPE_BMI270
    {{SLP_IMU_AXIS_X, -1}, {SLP_IMU_AXIS_Y, +1}, {SLP_IMU_AXIS_Z, -1}}, // SLP_IMU_TYPE_LSM6DSOX
    {{SLP_IMU_AXIS_X, -1}, {SLP_IMU_AXIS_Y, +1}, {SLP_IMU_AXIS_Z, -1}}, // SLP_IMU_TYPE_ICM46288
    {{SLP_IMU_AXIS_X, -1}, {SLP_IMU_AXIS_Y, +1}, {SLP_IMU_AXIS_Z, -1}}, // SLP_IMU_TYPE_ICM42670
    {{SLP_IMU_AXIS_Y, +1}, {SLP_IMU_AXIS_X, +1}, {SLP_IMU_AXIS_Z, -1}}, // SLP_IMU_TYPE_BMI325
    {{SLP_IMU_AXIS_Z, +1}, {SLP_IMU_AXIS_X, -1}, {SLP_IMU_AXIS_Y, -1}}, // SLP_IMU_TYPE_SMI230
    {{SLP_IMU_AXIS_X, -1}, {SLP_IMU_AXIS_Y, +1}, {SLP_IMU_AXIS_Z, -1}}, // SLP_IMU_TYPE_ASM330
};
#elif CONFIG_SAMPLE_SUPPORT_AIR_MOUSE_DONGLE
// 参考设计板Dongle(天线朝向RCU, USB朝下)
SlpTransformParam g_slpTransformParamArr[SLP_IMU_TYPE_NUM] = {
    {{SLP_IMU_AXIS_Z, -1}, {SLP_IMU_AXIS_Y, +1}, {SLP_IMU_AXIS_X, +1}}, // SLP_IMU_TYPE_BMI270
    {{SLP_IMU_AXIS_Z, -1}, {SLP_IMU_AXIS_X, -1}, {SLP_IMU_AXIS_Y, +1}}, // SLP_IMU_TYPE_LSM6DSOX
    {{SLP_IMU_AXIS_Z, -1}, {SLP_IMU_AXIS_X, -1}, {SLP_IMU_AXIS_Y, +1}}, // SLP_IMU_TYPE_ICM46288
    {{SLP_IMU_AXIS_Z, -1}, {SLP_IMU_AXIS_X, -1}, {SLP_IMU_AXIS_Y, +1}}, // SLP_IMU_TYPE_ICM42670
    {{SLP_IMU_AXIS_Z, -1}, {SLP_IMU_AXIS_Y, +1}, {SLP_IMU_AXIS_X, +1}}, // SLP_IMU_TYPE_BMI325
    {{SLP_IMU_AXIS_Y, -1}, {SLP_IMU_AXIS_Z, +1}, {SLP_IMU_AXIS_X, -1}}, // SLP_IMU_TYPE_SMI230
    {{SLP_IMU_AXIS_Z, -1}, {SLP_IMU_AXIS_X, -1}, {SLP_IMU_AXIS_Y, +1}}, // SLP_IMU_TYPE_ASM330
};
#endif
#elif CONFIG_AIR_MOUSE_EVB4_BOARD
#if CONFIG_SAMPLE_SUPPORT_AIR_MOUSE
// EVB4板RCU
SlpTransformParam g_slpTransformParamArr[SLP_IMU_TYPE_NUM] = {
    {{SLP_IMU_AXIS_Y, +1}, {SLP_IMU_AXIS_X, +1}, {SLP_IMU_AXIS_Z, -1}}, // SLP_IMU_TYPE_BMI270
    {},                                                                 // SLP_IMU_TYPE_LSM6DSOX
    {},                                                                 // SLP_IMU_TYPE_ICM46288
    {},                                                                 // SLP_IMU_TYPE_ICM42670
    {},                                                                 // SLP_IMU_TYPE_BMI325
    {},                                                                 // SLP_IMU_TYPE_SMI230
    {},                                                                 // SLP_IMU_TYPE_ASM330
};
#elif CONFIG_SAMPLE_SUPPORT_AIR_MOUSE_DONGLE
// EVB4板Dongle
SlpTransformParam g_slpTransformParamArr[SLP_IMU_TYPE_NUM] = {
    {{SLP_IMU_AXIS_Y, -1}, {SLP_IMU_AXIS_X, -1}, {SLP_IMU_AXIS_Z, -1}}, // SLP_IMU_TYPE_BMI270
    {},                                                                 // SLP_IMU_TYPE_LSM6DSOX
    {},                                                                 // SLP_IMU_TYPE_ICM46288
    {},                                                                 // SLP_IMU_TYPE_ICM42670
    {},                                                                 // SLP_IMU_TYPE_BMI325
    {},                                                                 // SLP_IMU_TYPE_SMI230
    {},                                                                 // SLP_IMU_TYPE_ASM330
};
#endif
/* 雷达2T4R Dongle板 */
#elif CONFIG_AIR_MOUSE_RADAR_2T4R_BOARD
#if CONFIG_SAMPLE_SUPPORT_AIR_MOUSE
SlpTransformParam g_slpTransformParamArr[SLP_IMU_TYPE_NUM] = {0};
#elif CONFIG_SAMPLE_SUPPORT_AIR_MOUSE_DONGLE
SlpTransformParam g_slpTransformParamArr[SLP_IMU_TYPE_NUM] = {
    {},                                                                 // SLP_IMU_TYPE_BMI270
    {},                                                                 // SLP_IMU_TYPE_LSM6DSOX
    {},                                                                 // SLP_IMU_TYPE_ICM46288
    {},                                                                 // SLP_IMU_TYPE_ICM42670
    {},                                                                 // SLP_IMU_TYPE_BMI325
    {},                                                                 // SLP_IMU_TYPE_SMI230
    {{SLP_IMU_AXIS_Z, +1}, {SLP_IMU_AXIS_X, -1}, {SLP_IMU_AXIS_Y, -1}}, // SLP_IMU_TYPE_ASM330
};
#endif
/* 开源生态三天线板 */
#elif CONFIG_AIR_MOUSE_OPEN_SOURCE_BOARD
#if CONFIG_SAMPLE_SUPPORT_AIR_MOUSE
SlpTransformParam g_slpTransformParamArr[SLP_IMU_TYPE_NUM] = {0};
#elif CONFIG_SAMPLE_SUPPORT_AIR_MOUSE_DONGLE
SlpTransformParam g_slpTransformParamArr[SLP_IMU_TYPE_NUM] = {0};
#endif
#endif

#if CONFIG_AIR_MOUSE_HX_BOARD // CONFIG_AIR_MOUSE_HX_BOARD

#if CONFIG_SAMPLE_SUPPORT_AIR_MOUSE
static const uint8_t g_ant_sw_param[] = {true, 0b000011, 0b000010, 0b000001, 0x0, 0b000000, 0x0, 0x0}; // RCU
#elif CONFIG_SAMPLE_SUPPORT_AIR_MOUSE_DONGLE
static const uint8_t g_ant_sw_param[] = {true, 0b000001, 0b000000, 0b000001, 0x0,      0x0, 0x0, 0x0}; // DONGLE
#endif

#elif CONFIG_AIR_MOUSE_EVB4_BOARD /* Evb4 */
static const uint8_t g_ant_sw_param[] = {false, 0b000111, 0b000011, 0b000100, 0x0, 0b000101, 0x0, 0x0}; // RCU & Dongle

#elif CONFIG_AIR_MOUSE_RADAR_2T4R_BOARD /* Radar 2T4R */
static const uint8_t g_ant_sw_param[] = {false, 0b000111, 0b000110, 0b000110, 0x0, 0b000101, 0x0, 0x0}; // Dongle

#elif CONFIG_AIR_MOUSE_HR_BOARD /* TVRCREF */ /* HR */
#if CONFIG_SAMPLE_SUPPORT_AIR_MOUSE
// haier板子rcu和dongle第一个参数为false，需要编haier版本，需要手动改一下；
// 自研板rcu已默认对齐最新硬件设计，需独立控制rfsw，第一个参数为true；dongle上需要看对否上件，库上配置默认未上件
static const uint8_t g_ant_sw_param[] = {true, 0b000011, 0b000010, 0b000001, 0x0, 0b000000, 0x0, 0x0}; // RCU
#elif CONFIG_SAMPLE_SUPPORT_AIR_MOUSE_DONGLE
static const uint8_t g_ant_sw_param[] = {true, 0b000001, 0b000000, 0b000001, 0x0,      0x0, 0x0, 0x0}; // DONGLE
#endif

#elif CONFIG_AIR_MOUSE_OPEN_SOURCE_BOARD /* OPEN_SOURCE */
#if CONFIG_SAMPLE_SUPPORT_AIR_MOUSE
static const uint8_t g_ant_sw_param[] = {true, 0b111, 0b010, 0b101, 0, 0b000, 0, 0}; // tx0、rx0:TRX1_RXV, rx1:RXH
#elif CONFIG_SAMPLE_SUPPORT_AIR_MOUSE_DONGLE
static const uint8_t g_ant_sw_param[] = {true, 0b111, 0b010, 0b101, 0,     0, 0, 0}; // D tx0:TRX1_RXV, rx0:TRX1_RXV
#endif

#else
#endif

SlpCursorSpeed g_slp_cursor_speed = SLP_CURSOR_SPEED_MEDIUM;  // slp光标速度

void set_slp_uart_buffer(void)
{
    /* RCU */
#if CONFIG_SAMPLE_SUPPORT_AIR_MOUSE
#if CONFIG_SAMPLE_SUPPORT_AIR_MOUSE_CIR_PRINT
    static uint8_t buffer[SLP_UART_BUF_LEN_CIR_RPT]; // rcu + cir上报
#else
    static uint8_t buffer[SLP_UART_BUF_LEN_BASE];  // rcu + airmouse
#endif // CONFIG_SAMPLE_SUPPORT_AIR_MOUSE_CIR_PRINT

    /* Dongle */
#elif CONFIG_SAMPLE_SUPPORT_AIR_MOUSE_DONGLE
#if CONFIG_SAMPLE_SUPPORT_AIR_MOUSE_CIR_PRINT
    static uint8_t buffer[SLP_UART_BUF_LEN_CIR_RPT]; // dongle + cir上报
#else
    static uint8_t buffer[SLP_UART_BUF_LEN_RADAR]; // dongle + airmouse + radar
#endif // CONFIG_SAMPLE_SUPPORT_AIR_MOUSE_CIR_PRINT
#else
#endif

    osal_printk("set_slp_uart_buffer, %u\r\n", sizeof(buffer));
    const SlpUartBufferInfo info = {buffer, sizeof(buffer)};
    SlpSetUartBuffer(&info);
}

void set_ant_sw_param(SlpRfSwParam *param)
{
    if (sizeof(SlpRfSwParam) != sizeof(g_ant_sw_param)) {
        osal_printk("[ERR]set_ant_sw_param is not equal, %u, %u\r\n", sizeof(SlpRfSwParam), sizeof(g_ant_sw_param));
    }
    memcpy_s(param, sizeof(SlpRfSwParam), g_ant_sw_param, sizeof(g_ant_sw_param));
    osal_printk("set_ant_sw_param, pwr_ctrl:%u, ctrl_en:0x%02x, code:0x%02x,0x%02x,0x%02x,0x%02x,0x%02x,0x%02x,\r\n",
        param->pwrCtrl, param->antSwCtrlEn, param->ant0Code.tx.u8, param->ant0Code.rx.u8, param->ant1Code.tx.u8,
        param->ant1Code.rx.u8, param->ant2Code.tx.u8, param->ant2Code.rx.u8);
}

void set_transform_param(SlpImuType type)
{
    if (type >= SLP_IMU_TYPE_NUM) {
        osal_printk("[ERR] set slp transform, imu type:%u\r\n", type);
        return;
    }
    ErrcodeSlpClient ret = SlpSetTransformParam(&g_slpTransformParamArr[type]);
    osal_printk("set slp transform, ret:0x%x, imu:%u\r\n", ret, type);
}

void print_slp_version(SlpVersionRpt *versionRpt)
{
    // 打印SLP版本信息
    osal_printk("[slp ver] Narrow Band: %u.%u.%u, Wide Band: %u.%u.%u\r\n",
        versionRpt->narrowBand.major, versionRpt->narrowBand.minor, versionRpt->narrowBand.patch,
        versionRpt->wideBand.major, versionRpt->wideBand.minor, versionRpt->wideBand.patch);
    osal_printk("[slp cap] ranging:%u, aox:%u, HS:%u, radar:%u, imuDriver:%u, algAirMouse:%u, algRadar:%u\r\n",
        versionRpt->capability.ranging, versionRpt->capability.aox, versionRpt->capability.highSecurity,
        versionRpt->capability.radar, versionRpt->capability.imuDriver, versionRpt->capability.algAirMouse,
        versionRpt->capability.algRadar);
    osal_printk("[slp ver] chipId: 0x%02X, imuType: 0x%02X\r\n", versionRpt->chipId, versionRpt->imuType);
}

void air_mouse_print(const char *buffer, bool both)
{
#if CONFIG_AIR_MOUSE_CI_REPLAY_TEST
    unused(both);
    osal_printk(buffer);
#else
    if (get_usb_init_success_flag()) {
        usb_send_serial_data(buffer, strlen(buffer)); // usb虚拟串口输出
        if (both) {
            osal_printk(buffer);
        }
    } else {
        osal_printk(buffer);
    }
#endif
}

SlpCursorSpeed get_slp_cursor_speed(void)
{
    return g_slp_cursor_speed;
}

void set_slp_cursor_speed(SlpCursorSpeed mode)
{
    g_slp_cursor_speed = mode;
}
