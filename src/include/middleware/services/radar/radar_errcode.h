/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2025-2025. All rights reserved.
 * Description: header file of radar errcode
 */


/**
 * @defgroup  middleware_service_radar_errcode Radar Errcode
 * @ingroup middleware_service_radar
 * @{
 */

#ifndef RADAR_ERRCODE_H
#define RADAR_ERRCODE_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @if Eng
 * @brief  radar error code base.
 * @else
 * @brief  雷达错误码起始。
 * @endif
 */
#define ERRCODE_RADAR_BASE 0x8000A000

/**
 * @if Eng
 * @brief  radar error code base.
 * @else
 * @brief  雷达错误码结束。
 * @endif
 */
#define ERRCODE_RADAR_END 0x8000A0FF

/**
 * @if Eng
 * @brief  radar client error code base.
 * @else
 * @brief  雷达client错误码起始。
 * @endif
 */
#define ERRCODE_RADAR_CLIENT_BASE 0x8000A100

/**
 * @if Eng
 * @brief  radar Client error code base.
 * @else
 * @brief  雷达client错误码结束。
 * @endif
 */
#define ERRCODE_RADAR_CLIENT_END 0x8000A1FF

/**
 * @if Eng
 * @brief  radar error code.
 * @else
 * @brief  雷达错误码。
 * @endif
 */
typedef enum {
    ERRCODE_RADAR_SUCCESS = 0,            /*!< @if Eng error code of success
                                                                @else   执行成功错误码 @endif */
    ERRCODE_RADAR_MAX = ERRCODE_RADAR_END /*!< @if Eng maximum of error code
                                                                @else   雷达错误码最大值 @endif */
} errcode_radar_t;

/**
 * @if Eng
 * @brief  radar client error code.
 * @else
 * @brief  雷达client错误码。
 * @endif
 */
typedef enum {
    ERRCODE_RC_SUCCESS = 0,                               /*!< @if Eng error code of success
                                                                    @else   执行成功错误码 @endif */
    ERRCODE_RC_MALLOC_FAILED = ERRCODE_RADAR_CLIENT_BASE, /*!< @if Eng error code of malloc failed
                                                                    @else   申请动态内存失败错误码 @endif */
    ERRCODE_RC_QUEUE_WRITE_FAILED,                        /*!< @if Eng error code of message queue write failed
                                                                    @else   消息队列写入失败错误码 @endif */
    ERRCODE_RC_POWER_ON_FAILED,                           /*!< @if Eng error code of power on failed
                                                                    @else   上电加载失败错误码 @endif */
    ERRCODE_RC_POWERED_ON,                                /*!< @if Eng error code of is powerd on
                                                                    @else   已经上电加载错误码 @endif */
    ERRCODE_RC_POWERED_OFF,                               /*!< @if Eng error code of is powerd off
                                                                    @else   已经下电错误码 @endif */
    ERRCODE_RC_RADAR_ENABLED,                             /*!< @if Eng error code of SLP radar enabled
                                                                    @else   雷达已经使能错误码 @endif */
    ERRCODE_RC_RADAR_DISABLED,                            /*!< @if Eng error code of SLP disabled
                                                                    @else   雷达已经关闭错误码 @endif */
    ERRCODE_RC_PTR_NULL,                                  /*!< @if Eng error code of ptr is NULL
                                                                    @else   雷达指针为空 @endif */
    ERRCODE_RC_PARA_INVALID,                              /*!< @if Eng error code of para is invalid
                                                                    @else   雷达参数不合规 @endif */
    ERRCODE_RC_MAX = ERRCODE_RADAR_CLIENT_END             /*!< @if Eng maximum of error code
                                                                    @else   RC错误码最大值 @endif */
} errcode_radar_client_t;

#ifdef __cplusplus
}
#endif
#endif

/**
 * @}
 */