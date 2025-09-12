/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2023-2023. All rights reserved.
 *
 * Description: SLE ADV Config. \n
 *
 * History: \n
 * 2023-09-21, Create file. \n
 */

#ifndef SLE_SERVER_ADV_H
#define SLE_SERVER_ADV_H

#include "errcode.h"
#include "sle_common.h"

/* 连接调度间隔12.5ms，单位125us */
#define SLE_CONN_INTV_MIN_DEFAULT                 0x64
/* 连接调度间隔12.5ms，单位125us */
#define SLE_CONN_INTV_MAX_DEFAULT                 0x64
/* 连接调度间隔20ms，单位125us */
#define SLE_CONN_WAKEUP_INTV_MIN_DEFAULT          0xA0
/* 连接调度间隔20ms，单位125us */
#define SLE_CONN_WAKEUP_INTV_MAX_DEFAULT          0xA0
/* 连接调度间隔25ms，单位125us */
#define SLE_ADV_INTERVAL_MIN_DEFAULT              (0xC8 * 2)
/* 连接调度间隔25ms，单位125us */
#define SLE_ADV_INTERVAL_MAX_DEFAULT              (0xC8 * 2)
/* 超时时间5000ms，单位10ms */
#define SLE_CONN_SUPERVISION_TIMEOUT_DEFAULT      0x1F4
/* 超时时间4990ms，单位10ms */
#define SLE_CONN_MAX_LATENCY                      0x1F3
/* 广播发送功率 */
#define SLE_ADV_TX_POWER                          6
/* 广播ID */
#define SLE_ADV_HANDLE_DEFAULT                    1
/* 定向广播ID */
#define SLE_ADV_HANDLE_DIRECTED                   1
/* 唤醒广播ID */
#define SLE_ADV_HANDLE_WAKEUP                     1
/* 最大广播数据长度 */
#define SLE_ADV_DATA_LEN_MAX                      31
#define SLE_UART_TASK_DELAY_MS                    1000

/**
 * @if Eng
 * @brief Definitaion of BLE ADV common broadcast struct.
 * @else
 * @brief SLE 广播普通数据结构。
 * @endif
 */
typedef struct sle_adv_common_value {
    uint8_t type;
    uint8_t length;
    uint8_t value;
} sle_adv_common_value_t;

/**
 * @if Eng
 * @brief Definitaion of BLE ADV Channel mapping.
 * @else
 * @brief SLE 广播信道映射。
 * @endif
 */
typedef enum sle_adv_channel_map {
    SLE_ADV_CHANNEL_MAP_77                 = 0x01,
    SLE_ADV_CHANNEL_MAP_78                 = 0x02,
    SLE_ADV_CHANNEL_MAP_79                 = 0x04,
    SLE_ADV_CHANNEL_MAP_DEFAULT            = 0x07
} sle_adv_channel_map_t;

/**
 * @if Eng
 * @brief Definitaion of SLE ADV Data Type.
 * @else
 * @brief SLE 广播数据类型。
 * @endif
 */
typedef enum sle_adv_data {
    SLE_ADV_DATA_TYPE_DISCOVERY_LEVEL                              = 0x01,   /*!< 发现等级 */
    SLE_ADV_DATA_TYPE_ACCESS_MODE                                  = 0x02,   /*!< 接入层能力 */
    SLE_ADV_DATA_TYPE_SERVICE_DATA_16BIT_UUID                      = 0x03,   /*!< 标准服务数据信息 */
    SLE_ADV_DATA_TYPE_SERVICE_DATA_128BIT_UUID                     = 0x04,   /*!< 自定义服务数据信息 */
    SLE_ADV_DATA_TYPE_COMPLETE_LIST_OF_16BIT_SERVICE_UUIDS         = 0x05,   /*!< 完整标准服务标识列表 */
    SLE_ADV_DATA_TYPE_COMPLETE_LIST_OF_128BIT_SERVICE_UUIDS        = 0x06,   /*!< 完整自定义服务标识列表 */
    SLE_ADV_DATA_TYPE_INCOMPLETE_LIST_OF_16BIT_SERVICE_UUIDS       = 0x07,   /*!< 部分标准服务标识列表 */
    SLE_ADV_DATA_TYPE_INCOMPLETE_LIST_OF_128BIT_SERVICE_UUIDS      = 0x08,   /*!< 部分自定义服务标识列表 */
    SLE_ADV_DATA_TYPE_SERVICE_STRUCTURE_HASH_VALUE                 = 0x09,   /*!< 服务结构散列值 */
    SLE_ADV_DATA_TYPE_SHORTENED_LOCAL_NAME                         = 0x0A,   /*!< 设备缩写本地名称 */
    SLE_ADV_DATA_TYPE_COMPLETE_LOCAL_NAME                          = 0x0B,   /*!< 设备完整本地名称 */
    SLE_ADV_DATA_TYPE_TX_POWER_LEVEL                               = 0x0C,   /*!< 广播发送功率 */
    SLE_ADV_DATA_TYPE_SLB_COMMUNICATION_DOMAIN                     = 0x0D,   /*!< SLB通信域域名 */
    SLE_ADV_DATA_TYPE_SLB_MEDIA_ACCESS_LAYER_ID                    = 0x0E,   /*!< SLB媒体接入层标识 */
    SLE_ADV_DATA_TYPE_EXTENDED                                     = 0xFE,   /*!< 数据类型扩展 */
    SLE_ADV_DATA_TYPE_MANUFACTURER_SPECIFIC_DATA                   = 0xFF    /*!< 厂商自定义信息 */
} sle_adv_data_t;

void sle_set_current_control_obj(uint8_t control_obj);
errcode_t sle_rcu_server_adv_init(void);
errcode_t sle_rcu_server_adv_deinit(void);
errcode_t sle_rcu_server_directed_adv_init(const sle_addr_t *addr);
errcode_t sle_rcu_announce_register_cbks(void);
errcode_t sle_rcu_server_wakeup_adv_init(const sle_addr_t *addr);
#if defined(CONFIG_RCU_MASS_PRODUCTION_TEST)
errcode_t rcu_mp_test_server_adv_init(const sle_addr_t *local_addr, const sle_addr_t *peer_addr);
#endif
#endif