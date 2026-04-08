/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2026. All rights reserved.
 * Description: slp factory api
 * ROM      : NO
 * STRATEGY : NO
 */

/**
 * @defgroup middleware_service_slp_factory_api SLP FACTORY API
 * @ingroup  middleware_service_slp
 * @{
 */

#ifndef SLP_FACTORY_H
#define SLP_FACTORY_H

#include <stdint.h>
#include <stdbool.h>
#include "slp_errcode.h"

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack(1)
/**
 * @if Eng
 * @brief Struct of cir data for slp
 * @else
 * @brief slp的cir数据
 * @endif
 */
typedef struct {
    int32_t cirI;                   /*!< @if Eng i of cir data.
                                         @else cir数据的i。 @endif */
    int32_t cirQ;                   /*!< @if Eng q of cir data.
                                         @else cir数据的q。 @endif */
    uint8_t bitWidth;               /*!< @if Eng bit width of cir data.
                                         @else cir数据的位宽。 @endif */
} SlpCirIqForCali;

/**
 * @if Eng
 * @brief Struct of slp aox calibration data
 * @else
 * @brief slp测角校准数据
 * @endif
 */
typedef struct {
    SlpCirIqForCali cirIq0;         /*!< @if Eng aox calibration data of antenna 0.
                                         @else 天线0的测角校准数据。 @endif */
    SlpCirIqForCali cirIq1;         /*!< @if eng aox calibration data of antenna 1.
                                         @else 天线1的测角校准数据。 @endif */
} SlpAoxCaliData;

/**
 * @if Eng
 * @brief Struct of angle measurement result
 * @else
 * @brief slp测角结果
 * @endif
 */
typedef struct {
    int16_t aoxAzi;                 /*!< @if Eng azimuth result, unit: 0.01°.
                                         @else 方向角结果, 单位: 0.01度。 @endif */
    uint8_t aoxAziFom;              /*!< @if Eng FOM (Figure Of Merit) of the azimuth.
                                         @else 方向角置信度。 @endif */
    int16_t aoxElev;                /*!< @if Eng elevation result, unit: 0.01°.
                                         @else 俯仰角结果, 单位: 0.01度。 @endif */
    uint8_t aoxElevFom;             /*!< @if Eng FOM (Figure Of Merit) of the elevation.
                                         @else 俯仰角置信度。 @endif */
    uint32_t round;                 /*!< @if Eng round.
                                         @else 轮数。 @endif */
} SlpAoxRslt;

/**
 * @if Eng
 * @brief Struct of slp aox calibration result
 * @else
 * @brief slp测角校准结果
 * @endif
 */
typedef struct {
    int32_t para0;                  /*!< @if Eng aox cali result para 0.
                                         @else 测角校准参数0 @endif */
    int32_t para1;                  /*!< @if Eng aox cali result para 1.
                                         @else 测角校准参数1 @endif */
    int32_t para2;                  /*!< @if Eng aox cali result para 2.
                                         @else 测角校准参数2 @endif */
    int32_t para3;                  /*!< @if Eng aox cali result para 3.
                                         @else 测角校准参数3 @endif */
    int32_t para4;                  /*!< @if Eng aox cali result para 4.
                                         @else 测角校准参数4 @endif */
    int32_t para5;                  /*!< @if Eng aox cali result para 5.
                                         @else 测角校准参数5 @endif */
    int32_t para6;                  /*!< @if Eng aox cali result para 6.
                                         @else 测角校准参数6 @endif */
    int32_t para7;                  /*!< @if Eng aox cali result para 7.
                                         @else 测角校准参数7 @endif */
} SlpAoxCaliPara;

/**
 * @if Eng
 * @brief Struct of TriAnt slp aox calibration result
 * @else
 * @brief slp三天线测角校准参数
 * @endif
 */
typedef struct {
    uint32_t para0;                  /*!< @if Eng 3ant aox cali result para 0.
                                         @else 三天线测角校准参数0 @endif */
    uint32_t para1;                  /*!< @if Eng 3ant aox cali result para 1.
                                         @else 三天线测角校准参数1 @endif */
    int32_t para2;                  /*!< @if Eng 3ant aox cali result para 2.
                                         @else 三天线测角校准参数2 @endif */
    int32_t para3;                  /*!< @if Eng 3ant aox cali result para 3.
                                         @else 三天线测角校准参数3 @endif */
    int32_t para4;                  /*!< @if Eng 3ant aox cali result para 4.
                                         @else 三天线测角校准参数4 @endif */
    int32_t para5;                  /*!< @if Eng 3ant aox cali result para 5.
                                         @else 三天线测角校准参数5 @endif */
    int32_t para6;                  /*!< @if Eng 3ant aox cali result para 6.
                                         @else 三天线测角校准参数6 @endif */
    int32_t para7;                  /*!< @if Eng 3ant aox cali result para 7.
                                         @else 三天线测角校准参数7 @endif */
    int32_t para8;                  /*!< @if Eng 3ant aox cali result para 8.
                                         @else 三天线测角校准参数8 @endif */
    int32_t para9;                  /*!< @if Eng 3ant aox cali result para 9.
                                         @else 三天线测角校准参数9 @endif */
    int32_t para10;                 /*!< @if Eng 3ant aox cali result para 10.
                                         @else 三天线测角校准参数10 @endif */
    int32_t para11;                 /*!< @if Eng 3ant aox cali result para 11.
                                         @else 三天线测角校准参数11 @endif */
    int32_t para12;                 /*!< @if Eng 3ant aox cali result para 12.
                                         @else 三天线测角校准参数12 @endif */
    int32_t para13;                 /*!< @if Eng 3ant aox cali result para 13.
                                         @else 三天线测角校准参数13 @endif */
    int32_t para14;                 /*!< @if Eng 3ant aox cali result para 14.
                                         @else 三天线测角校准参数14 @endif */
    int32_t para15;                 /*!< @if Eng 3ant aox cali result para 15.
                                         @else 三天线测角校准参数15 @endif */
    int32_t para16;                 /*!< @if Eng 3ant aox cali result para 16.
                                         @else 三天线测角校准参数16 @endif */
    int32_t para17;                 /*!< @if Eng 3ant aox cali result para 17.
                                         @else 三天线测角校准参数17 @endif */
} SlpTriAntAoxCaliPara;

/**
 * @if Eng
 * @brief Struct of gyroscope zero offset value
 * @else
 * @brief 陀螺仪零偏校准值结构体
 * @endif
 */
typedef struct {
    int32_t x;                      /*!< @if Eng i of calibration result d11, unit: 1e-8 rad/s.
                                         @else 陀螺仪x轴零偏校准值，单位：1e-8弧度/秒。 @endif */
    int32_t y;                      /*!< @if Eng q of calibration result d11, unit: 1e-8 rad/s.
                                         @else 陀螺仪y轴零偏校准值，单位：1e-8弧度/秒。 @endif */
    int32_t z;                      /*!< @if Eng i of calibration result d12, unit: 1e-8 rad/s.
                                         @else 陀螺仪y轴零偏校准值，单位：1e-8弧度/秒。 @endif */
} SlpGyroZeroOffset;

/**
 * @if Eng
 * @brief Struct of slp factory aox calibration data report interface
 * @else
 * @brief slp三天线-L型产测测角校准数据上报结构体
 * @endif
 */
typedef struct {
    int32_t tof;                    /*!< @if Eng time of flight, unit: 1/64 ns.
                                         @else 测距结果, 飞行时间, 单位: 1/64纳秒. @endif */
    SlpAoxCaliData aoxElevCaliData;     /*!< @if Eng elev aox calibration data.
                                         @else 垂直测角校准数据. @endif */
    SlpAoxCaliData aoxAziCaliData;      /*!< @if Eng azi aox calibration data.
                                         @else 水平测角校准数据. @endif */
    SlpAoxRslt aoxRslt;             /*!< @if Eng angle measurement result.
                                         @else 测角结果. @endif */
} SlpFactoryTriAntRangingAoxDataRpt;

/**
 * @if Eng
 * @brief Struct of slp factory aox calibration data report interface
 * @else
 * @brief slp产测测角校准数据上报
 * @endif
 */
typedef struct {
    int32_t tof;                    /*!< @if Eng time of flight, unit: 1/64 ns.
                                         @else 测距结果, 飞行时间, 单位: 1/64纳秒. @endif */
    SlpAoxCaliData aoxCaliData;     /*!< @if Eng aox calibration data.
                                         @else 测角校准数据. @endif */
    SlpAoxRslt aoxRslt;             /*!< @if Eng angle measurement result.
                                         @else 测角结果. @endif */
} SlpFactoryRangingAoxDataRpt;

/**
 * @if Eng
 * @brief Struct of slp factory report interface
 * @else
 * @brief slp产测测角校准结果上报
 * @endif
 */
typedef struct {
    SlpAoxCaliPara caliPara;        /*!< @if Eng aox calibration para.
                                         @else 测角校准结果. @endif */
} SlpFactoryAoxCaliParaRpt;
#pragma pack()

/**
 * @if Eng
 * @brief Enum of factory test mode
 * @else
 * @brief 产线测试模式
 * @endif
 */
typedef enum {
    SLP_FACTORY_TEST_NONE = 0,      /*!< @if Eng slp normal service mode
                                         @else slp 正常业务模式 @endif */
    SLP_FACTORY_TEST_AOX_CALI,      /*!< @if Eng slp aox calibration mode
                                         @else slp 测角校准模式 @endif */
    SLP_FACTORY_TEST_IMU_DETECT,    /*!< @if Eng imu detect mode
                                         @else slp IMU检测模式 @endif */
} SlpFactoryTestMode;

/**
 * @if Eng
 * @brief Set factory test mode.
 * @par Description: Set factory test mode.
 * @param  [in]  mode factory test mode，see @ref SlpFactoryTestMode
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref ErrcodeSlpClient
 * @else
 * @brief 设置产测模式。
 * @par Description: 设置产测模式。
 * @param  [in]  mode 产测模式，参考 @ref SlpFactoryTestMode
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref ErrcodeSlpClient
 * @endif
 */
ErrcodeSlpClient SlpSetFactoryTestMode(uint8_t mode);

/**
 * @if Eng
 * @brief Write the calibration value.
 * @par Description: Write the calibration value.
 * @param  [in]  caliPara cali result, see @ref SlpAoxCaliPara
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref ErrcodeSlpClient
 * @else
 * @brief 写入校准值。
 * @par Description: 写入校准值。
 * @param  [in]  caliPara 校准值，参考 @ref SlpAoxCaliPara
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref ErrcodeSlpClient
 * @endif
 */
uint32_t SlpWriteAoxCaliPara(SlpAoxCaliPara *caliPara);

/**
 * @if Eng
 * @brief Read the calibration value.
 * @par Description: Read the calibration value.
 * @param  [in]  caliPara cali para, see @ref SlpAoxCaliPara
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref ErrcodeSlpClient
 * @else
 * @brief 读取校准值。
 * @par Description: 读取校准值。
 * @param  [in]  caliPara 校准值，参考 @ref SlpAoxCaliPara
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref ErrcodeSlpClient
 * @endif
 */
uint32_t SlpReadAoxCaliPara(SlpAoxCaliPara *caliPara);

/**
 * @if Eng
 * @brief Write the calibration value for three_ant_L.
 * @par Description: Write the calibration value for three_ant_L.
 * @param  [in]  caliPara cali result, see @ref SlpTriAntAoxCaliPara
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref ErrcodeSlpClient
 * @else
 * @brief 向本端NV写入三天线校准值。
 * @par Description: 向本端NV写入三天线校准值。
 * @param  [in]  caliPara 校准值，参考 @ref SlpTriAntAoxCaliPara
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref ErrcodeSlpClient
 * @endif
 */
uint32_t SlpWriteTriAntAoxCaliPara(SlpTriAntAoxCaliPara *caliPara);

/**
 * @if Eng
 * @brief Read the calibration value for three_ant_L.
 * @par Description: Read the calibration value for three_ant_L.
 * @param  [in]  caliPara cali result, see @ref SlpTriAntAoxCaliPara
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref ErrcodeSlpClient
 * @else
 * @brief 读取本端NV三天线校准值。
 * @par Description: 读取本端NV三天线校准值。
 * @param  [in]  caliPara 校准值，参考 @ref SlpTriAntAoxCaliPara
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref ErrcodeSlpClient
 * @endif
 */
uint32_t SlpReadTriAntAoxCaliPara(SlpTriAntAoxCaliPara *caliPara);

/**
 * @if Eng
 * @brief Write the calibration value.
 * @par Description: Write the calibration value.
 * @param  [in]  txPower cali result
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief 写入校准值。
 * @par Description: 写入校准值。
 * @param  [in]  txPower 校准值
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref errcode_t
 * @endif
 */
uint32_t SlpWriteTxPower(uint32_t *txPower);

/**
 * @if Eng
 * @brief Read the calibration value.
 * @par Description: Read the calibration value.
 * @param  [in]  txPower tx power
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief 读取校准值。
 * @par Description: 读取校准值。
 * @param  [in]  txPower 校准值
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref errcode_t
 * @endif
 */
uint32_t SlpReadTxPower(uint32_t *txPower);

/**
 * @if Eng
 * @brief Write the board and ant trx time delay calibration value.
 * @par Description: Write the board and ant trx time delay calibration value.
 * @param  [in]  timeDelay trx time delay, unit: 1e-5 ns.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief 写入板级和天线的TRX总时延校准值。
 * @par Description: 写入板级和天线的TRX总时延校准值。
 * @param  [in]  timeDelay 板级和天线的TRX总时延校准值, 单位: 1e-5 纳秒
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref errcode_t
 * @endif
 */
uint32_t SlpWriteBoardAntTrxTimeDelay(uint32_t timeDelay);

/**
 * @if Eng
 * @brief Read the board and ant trx time delay calibration value.
 * @par Description: Read the board and ant trx time delay calibration value.
 * @param  [in]  timeDelay trx time delay, unit: 1e-5 ns.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief 读取板级和天线的TRX总时延校准值。
 * @par Description: 读取板级和天线的TRX总时延校准值。
 * @param  [in]  timeDelay 板级和天线的TRX总时延校准值, 单位: 1e-5 纳秒
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref errcode_t
 * @endif
 */
uint32_t SlpReadBoardAntTrxTimeDelay(uint32_t *timeDelay);

/**
 * @if Eng
 * @brief Write the calibration value to the peer device.
 * @par Description: Write the calibration value to the peer device.
 * @param  [in]  caliPara cali para, see @ref SlpAoxCaliPara
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref ErrcodeSlpClient
 * @else
 * @brief 向对端设备写入校准值。
 * @par Description: 向对端设备写入校准值。
 * @param  [in]  caliPara 校准值，参考 @ref SlpAoxCaliPara
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref ErrcodeSlpClient
 * @endif
 */
ErrcodeSlpClient SlpWriteAoxCaliPara2Onb(SlpAoxCaliPara *caliPara);

/**
 * @if Eng
 * @brief Read the calibration value from the peer device.
 * @par Description: Read the calibration value from the peer device.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref ErrcodeSlpClient
 * @else
 * @brief 读取对端设备校准值。
 * @par Description: 读取对端设备校准值。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref ErrcodeSlpClient
 * @endif
 */
ErrcodeSlpClient SlpReadAoxCaliParaFromOnb(void);

/**
 * @if Eng
 * @brief Write the board and ant trx delay to the peer device.
 * @par Description: Write the board and ant trx delay to the peer device.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref ErrcodeSlpClient
 * @else
 * @brief 向对端设备写入板级和天线的时延校准值。
 * @par Description: 读取对端设备板级和天线的时延校准值。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref ErrcodeSlpClient
 * @endif
 */
ErrcodeSlpClient SlpWriteTrxDelay2Onb(uint32_t trxDelay);

/**
 * @if Eng
 * @brief Read the board and ant trx delay from the peer device.
 * @par Description: Read the board and ant trx delay from the peer device.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref ErrcodeSlpClient
 * @else
 * @brief 读取对端设备板级和天线的时延校准值。
 * @par Description: 读取对端设备板级和天线的时延校准值。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref ErrcodeSlpClient
 * @endif
 */
ErrcodeSlpClient SlpReadTrxDelayFromOnb(void);

/**
 * @if Eng
 * @brief write gyro zero offset to nv.
 * @par write gyro zero offset to nv.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief 向NV中写入陀螺仪零偏值。
 * @par 从NV中读取陀螺仪零偏值。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref errcode_t
 * @endif
 */
uint32_t SlpWriteGyroZeroOffset(SlpGyroZeroOffset *offset);

/**
 * @if Eng
 * @brief Read the gyro zero offset from nv.
 * @par Read the gyro zero offset from nv.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief 从NV中读取陀螺仪零偏值。
 * @par 从NV中读取陀螺仪零偏值。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref errcode_t
 * @endif
 */
uint32_t SlpReadGyroZeroOffset(SlpGyroZeroOffset *offset);

/**
 * @if Eng
 * @brief  SLP enable imu detection.
 * @par Description: SLP enable imu detection.
 * @param  [in]  gyroUpdateFlag whether to update the zero bias value, true: Yes, false: No.
 * @retval ERRCODE_SLPC_SUCCESS Success.
 * @retval Other        Failure. For details, see @ref ErrcodeSlpClient
 * @else
 * @brief  SLP开启IMU检测。
 * @par Description: SLP开启IMU检测。
 * @param  [in]  gyroUpdateFlag 是否更新零偏值，true：是，false：否。
 * @retval ERRCODE_SLPC_SUCCESS 成功。
 * @retval Other        失败。参考 @ref ErrcodeSlpClient
 * @endif
 */
ErrcodeSlpClient SlpEnableImuDetectionCommand(bool gyroUpdateFlag);

/**
 * @if Eng
 * @brief  SLP disable imu detection.
 * @par Description: SLP disable imu detection.
 * @retval ERRCODE_SLPC_SUCCESS Success.
 * @retval Other        Failure. For details, see @ref ErrcodeSlpClient
 * @else
 * @brief  SLP关闭IMU检测。
 * @par Description: SLP关闭IMU检测。
 * @retval ERRCODE_SLPC_SUCCESS 成功。
 * @retval Other        失败。参考 @ref ErrcodeSlpClient
 * @endif
 */
ErrcodeSlpClient SlpDisableImuDetectionCommand(void);

/**
 * @if Eng
 * @brief Callback invoked when report factory test result
 * @par Callback invoked when report factory test result
 * @attention 1.This function is called in SLP context,should not be blocked or do long time waiting.
 * @attention 2.The memories of pointer are requested and freed by the slp automatically.
 * @param  [in]  factoryRpt factory test aox calibration data.
 * @else
 * @brief 产测测角校准数据上报函数。
 * @par 产测测角校准数据上报函数。
 * @attention  1. 该回调函数运行于SLP线程，不能阻塞或长时间等待。
 * @attention  2. 指针由SLP申请内存，也由SLP释放，回调中不应释放。
 * @param  [in]  factoryRpt 产测测角校准数据。
 * @endif
 */
typedef void (*SlpReportOriginDataCallback)(SlpFactoryRangingAoxDataRpt *factoryRpt);

/**
 * @if Eng
 * @brief Callback invoked when report factory test result
 * @par Callback invoked when report factory test result
 * @attention 1.This function is called in SLP context,should not be blocked or do long time waiting.
 * @attention 2.The memories of pointer are requested and freed by the slp automatically.
 * @param  [in]  factoryRpt factory test aox calibration result.
 * @else
 * @brief 测角校准结果上报函数。
 * @par    测角校准结果上报函数。
 * @attention  1. 该回调函数运行于SLP线程，不能阻塞或长时间等待。
 * @attention  2. 指针由SLP申请内存，也由SLP释放，回调中不应释放。
 * @param  [in]  factoryRpt 测角校准结果。
 * @endif
 */
typedef void (*SlpReportAoxCaliParaCallback)(SlpFactoryAoxCaliParaRpt *factoryRpt);

/**
 * @if Eng
 * @brief Callback invoked when report factory test result
 * @par Callback invoked when report factory test result
 * @attention  1.This function is called in SLP context,should not be blocked or do long time waiting.
 * @attention  2.The memories of pointer are requested and freed by the slp automatically.
 * @param  [in]  trxDelay board and ant trx time delay cali result, unit：1e-5 ns.
 * @else
 * @brief  板级+天线时延校准结果上报函数。
 * @par  Description: 板级+天线时延校准结果上报函数。
 * @attention  1. 该回调函数运行于SLP线程，不能阻塞或长时间等待。
 * @attention  2. 指针由SLP申请内存，也由SLP释放，回调中不应释放。
 * @param  [in]  trxDelay 板级+天线时延校准值，单位：1e-5 纳秒。
 * @endif
 */
typedef void (*SlpReportFactoryTrxDelayCallback)(uint32_t *trxDelay);

/**
 * @if Eng
 * @brief Callback invoked when report gyroscope zero offset result
 * @par Callback invoked when report gyroscope zero offset result
 * @attention  1.This function is called in SLP context,should not be blocked or do long time waiting.
 * @attention  2.The memories of pointer are requested and freed by the slp automatically.
 * @param  [in]  offset gyroscope zero offset result, see @ref SlpGyroZeroOffset
 * @param  [in]  updateNv has NV been updated, true: Yes, false: No
 * @else
 * @brief  陀螺仪零偏校准值结果上报回调函数。
 * @par  陀螺仪零偏校准值结果上报回调函数。
 * @attention  1. 该回调函数运行于SLP线程，不能阻塞或长时间等待。
 * @attention  2. 指针由SLP申请内存，也由SLP释放，回调中不应释放。
 * @param  [in]  offset 陀螺仪零偏校准值。参考 @ref SlpGyroZeroOffset
 * @param  [in]  updateNv 是否更新了NV, true: 是, false: 否
 * @endif
 */
typedef void (*SlpReportGyroZeroOffsetCallback)(SlpGyroZeroOffset *offset, bool updateNv);

/**
 * @if Eng
 * @brief Struct of slp factory aox calibration data report interface
 * @else
 * @brief slp产测测角校准数据上报
 * @endif
 */
typedef struct {
    uint32_t accNorm;               /*!< @if Eng IMU acceleration norm, unit: 1e-5m/(s^2).
                                         @else 惯导中加速度的模, 单位: 1e-5m/(s^2). @endif */
} SlpFactoryImuDataRpt;

/**
 * @if Eng
 * @brief Callback invoked when report imu factory data
 * @par Callback invoked when report imu factory data
 * @attention 1.This function is called in SLP context, should not be blocked or do long time waiting.
 * @attention 2.The memories of pointer are requested and freed by the slp automatically.
 * @param  [in]  rpt factory data of imu.
 * @else
 * @brief  IMU产测数据上报的回调函数。
 * @par  IMU产测数据上报的回调函数。
 * @attention  1. 该回调函数运行于SLP线程，不能阻塞或长时间等待。
 * @attention  2. 指针由SLP申请内存，也由SLP释放，回调中不应释放。
 * @param  [in]  rpt imu产测数据。
 * @endif
 */
typedef void (*SlpReportFactoryImuDataCallback)(SlpFactoryImuDataRpt *rpt);

/**
 * @if Eng
 * @brief Callback invoked when report factory test result
 * @par Callback invoked when report factory test result
 * @param  [in]  factoryRpt factory test aox calibration result.
 * @else
 * @brief  测角原始数据上报函数(三天线-L型)
 * @par    测角原始数据上报函数(三天线-L型)
 * @param  [in]  factoryRpt 测角校准结果。
 * @endif
 */
typedef void (*SlpReportTriAntOriginDataCallback)(SlpFactoryTriAntRangingAoxDataRpt *factoryRpt);


/**
 * @if Eng
 * @brief Struct of slp factory result report callbacks
 * @else
 * @brief 产测结果上报回调
 * @endif
 */
typedef struct {
    SlpReportOriginDataCallback rptOriginDataCbk;           /*!< @if Eng report ranging aox calibration data callback.
                                                                 @else 上报测距测角校准原始数据回调函数。 @endif */
    SlpReportAoxCaliParaCallback rptAoxCaliParaCbk;         /*!< @if Eng slp report aox calibration result callback.
                                                                 @else 上报测角校准参数回调函数。 @endif */
    SlpReportFactoryTrxDelayCallback rptFactoryTrxDelayCbk; /*!< @if Eng slp report trx time delay result callback.
                                                                 @else 上报板级+天线时延校准结果回调函数。 @endif */
    SlpReportGyroZeroOffsetCallback rptZeroOffsetCbk;       /*!< @if Eng slp report trx time delay result callback.
                                                                 @else 陀螺仪零偏校准值结果上报回调函数。 @endif */
    SlpReportFactoryImuDataCallback rptImuDataCbk;          /*!< @if Eng slp report IMU factory data callback.
                                                                 @else 上报IMU产测数据回调函数。 @endif */
    SlpReportTriAntOriginDataCallback rptTriAntOriginDataCbk;          /*!< @if Eng slp report TriAnt aox factory data callback.
                                                                 @else 上报三天线产测数据回调函数。 @endif */
} SlpFactoryReportCallbacks;

/**
 * @if Eng
 * @brief Register SLP report callbacks.
 * @par Description: Register SLP report factory test result callbacks.
 * @param  [in]  func Callback function.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref ErrcodeSlpClient
 * @else
 * @brief 注册SLP上报结果回调函数。
 * @par Description: 注册SLP产测上报结果回调函数。
 * @param  [in]  func 回调函数。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref ErrcodeSlpClient
 * @endif
 */
ErrcodeSlpClient SlpRegisterFactoryReportCallbacks(SlpFactoryReportCallbacks *func);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif
