/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2023. All rights reserved.
 *
 * Description: SLE Service Access Protocol data struct defination.
 */

/**
 * @defgroup sle_ssap_stru Service Access Protocol data struct defination.
 * @ingroup  SLE
 * @{
 */

#ifndef SLE_SSAP_STRU_H
#define SLE_SSAP_STRU_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @if Eng
 * @brief  Length of sle UUID.
 * @else
 * @brief  星闪UUID长度。
 * @endif
 */
#define SLE_UUID_LEN 16

/**
 * @if Eng
 * @brief  Enum of write types for ssap clients to write property and descriptor.
 * @else
 * @brief  定义SSAP client写property和descriptor时的写类型。
 * @endif
 */
typedef enum {
    SSAP_WRITE_NO_RSP           = 0x01, /*!< @if Eng type of wirte with no server response
                                             @else 只写，且不需要server回复响应 @endif */
    SSAP_WRITE_DEFAULT_WITH_RSP = 0x02, /*!< @if Eng type of wirte with server response
                                             @else 只写，且需要server回复响应 @endif */
} ssap_write_type_t;

/**
 * @if Eng
 * @brief  SSAP attribute permission.
 * @else
 * @brief  SSAP attribute操作权限。
 * @endif
 */
typedef enum {
    SSAP_PERMISSION_READ                = 0x01, /*!< @if Eng readable
                                                     @else   可读 @endif */
    SSAP_PERMISSION_WRITE               = 0x02, /*!< @if Eng writable
                                                     @else   可写 @endif */
    SSAP_PERMISSION_ENCRYPTION_NEED     = 0x04, /*!< @if Eng need encryption
                                                     @else   需要加密 @endif */
    SSAP_PERMISSION_AUTHENTICATION_NEED = 0x08, /*!< @if Eng need authentication
                                                     @else   需要认证 @endif */
    SSAP_PERMISSION_AUTHORIZATION_NEED  = 0x10, /*!< @if Eng need authorization
                                                     @else   需要授权 @endif */
} ssap_permission_t;

/**
 * @if Eng
 * @brief  SSAP find type.
 * @else
 * @brief  SSAP 查找类型
 * @endif
 */
typedef enum {
    SSAP_FIND_TYPE_SERVICE_STRUCTURE = 0x00, /*!< @if Eng service structure
                                                  @else   服务结构 @endif */
    SSAP_FIND_TYPE_PRIMARY_SERVICE   = 0x01, /*!< @if Eng primary service
                                                  @else   首要服务 @endif */
    SSAP_FIND_TYPE_REFERENCE_SERVICE = 0x02, /*!< @if Eng reference service
                                                  @else   引用服务 @endif */
    SSAP_FIND_TYPE_PROPERTY          = 0x03, /*!< @if Eng property
                                                  @else   属性 @endif */
    SSAP_FIND_TYPE_METHOD            = 0x04, /*!< @if Eng method
                                                  @else   方法 @endif */
    SSAP_FIND_TYPE_EVENT             = 0x05, /*!< @if Eng event
                                                  @else   事件 @endif */
} ssap_find_type_t;

/**
 * @if Eng
 * @brief  SSAP property type.
 * @else
 * @brief  SSAP 特征类型。
 * @endif
 */
typedef enum {
    SSAP_PROPERTY_TYPE_VALUE             = 0x00, /*!< @if Eng property value
                                                      @else   特征值 @endif */
    SSAP_DESCRIPTOR_USER_DESCRIPTION     = 0x01, /*!< @if Eng user description descriptor
                                                      @else   属性说明描述符 @endif */
    SSAP_DESCRIPTOR_CLIENT_CONFIGURATION = 0x02, /*!< @if Eng client configuration descriptor
                                                      @else   客户端配置描述符 @endif */
    SSAP_DESCRIPTOR_SERVER_CONFIGURATION = 0x03, /*!< @if Eng server configuration descriptor
                                                      @else   服务端配置描述符 @endif */
    SSAP_DESCRIPTOR_PRESENTATION_FORMAT  = 0x04, /*!< @if Eng presentation format descriptor
                                                      @else   格式描述符 @endif */
    SSAP_DESCRIPTOR_RFU                  = 0x05, /*!< @if Eng RFU descriptor, 0x05 – 0x1F
                                                      @else   服务管理保留描述符，0x05 – 0x1F @endif */
    SSAP_DESCRIPTOR_CUSTOM               = 0xFF, /*!< @if Eng custom descriptor
                                                      @else   厂商自定义描述符 @endif */
} ssap_property_type_t;

/**
 * @if Eng
 * @brief  SSAP errcode.
 * @else
 * @brief  SSAP 错误码。
 * @endif
 */
typedef enum {
    SSAP_ERRCODE_PDU_INVALID                            = 0x01,    /*!< @if Eng invalid PDU
                                                                        @else   服务端接收的 PDU 无效 @endif */
    SSAP_ERRCODE_PDU_NOT_SUPPORTED                      = 0x02,    /*!< @if Eng PDU not support
                                                                        @else   服务端不支持处理接收的 @endif */
    SSAP_ERRCODE_UNKNOW                                 = 0x03,    /*!< @if Eng PDU unknow
                                                                        @else   服务端执行请求时发生未知错误 @endif */
    SSAP_ERRCODE_INVALID_HANDLE                         = 0x04,    /*!< @if Eng invalid handle
                                                                        @else   请求中的句柄无效 @endif */
    SSAP_ERRCODE_INSUFFICIENT_RESOURCES                 = 0x05,    /*!< @if Eng insufficient resources
                                                                        @else   服务端没有足够资源完成请求 @endif */
    SSAP_ERRCODE_READ_NOT_PERMITTED                     = 0x06,    /*!< @if Eng prohibit reading
                                                                        @else   服务端禁止客户端读取值 @endif */
    SSAP_ERRCODE_WRITE_NOT_PERMITTED                    = 0x07,    /*!< @if Eng prohibit writing
                                                                        @else   服务端禁止客户端写入值 @endif */
    SSAP_ERRCODE_INSUFFICIENT_AUTHENTICATION            = 0x08,    /*!< @if Eng client no authentication
                                                                        @else   客户端未经过认证 @endif */
    SSAP_ERRCODE_INSUFFICIENT_AUTHORIZATION             = 0x09,    /*!< @if Eng client no authorizaion
                                                                        @else   客户端未被授权 @endif */
    SSAP_ERRCODE_INSUFFICIENT_ENCRYPTION                = 0x0A,    /*!< @if Eng bearer not encrypted
                                                                        @else   传输 PDU 的承载未加密 @endif */
    SSAP_ERRCODE_ATTRIBUTE_NOT_FOUND                    = 0x0B,    /*!< @if Eng entries not found
                                                                        @else   服务端未找到对应条目 @endif */
    SSAP_ERRCODE_INVALID_METHOD_CALL                    = 0x0C,    /*!< @if Eng method access error
                                                                        @else   方法访问错误 @endif */
    SSAP_ERRCODE_INVALID_ATTRIBUTE_VALUE_TYPE           = 0x0D,    /*!< @if Eng data type incorrected
                                                                        @else   客户端发送写入数据类型
                                                                                不符的错误 @endif */
    SSAP_ERRCODE_INVALID_ATTRIBUTE_VALUE_LENGTH         = 0x0E,    /*!< @if Eng data value length incorrected
                                                                        @else   客户端发送写入值长度不符的错误 @endif */
    SSAP_ERRCODE_OUT_OF_RANGE                           = 0x0F,    /*!< @if Eng data value incorrected
                                                                        @else   客户端写入的值超出范围 @endif */
    SSAP_ERRCODE_SERVER_SUBCONTRACT_NOT_SUPPORTED       = 0x10,    /*!< @if Eng subcontract not support
                                                                        @else   服务端不支持信令的分包发送 @endif */
    SSAP_ERRCODE_ATTRIBUTE_NUM_OVER_LIMIT               = 0x11,    /*!< @if Eng attribute number over limit
                                                                        @else   请求数量超出服务端的支持能力 @endif */
    SSAP_ERRCODE_SERVER_FRAGMENT_NUMBER_NOT_SUPPORTED   = 0x12,    /*!< @if Eng fragment number not support
                                                                        @else   服务端不支持信令分片序号功能 @endif */
    SSAP_ERRCODE_SERVER_SUBCONTRACT_NOT_FULLY_RECEIVED  = 0x13,    /*!< @if Eng subcontract not fully receive
                                                                        @else   服务端未接收所有分包 @endif */
    SSAP_ERRCODE_SERVER_TRANSACTION_NUM_NOT_SUPPORTED   = 0x14,    /*!< @if Eng transaction number not support
                                                                        @else   服务端不支持消息事务号 @endif */
    SSAP_ERRCODE_SERVER_RELIABLE_MODE_NOT_SUPPORTED     = 0x15,    /*!< @if Eng reliable mode not support
                                                                        @else   服务端不支持可靠模式 @endif */
} ssap_errcode_t;

/**
 * @if Eng
 * @brief  SSAP operation indication.
 * @else
 * @brief  SSAP 操作指示。
 * @endif
 */
typedef enum {
    SSAP_OPERATE_INDICATION_BIT_READ = 0x01,              /*!< @if Eng data values can be read
                                                               @else   数据值可被读取 @endif */
    SSAP_OPERATE_INDICATION_BIT_WRITE_NO_RSP = 0x02,      /*!< @if Eng data values can be written without feedback.
                                                               @else   数据值可被写入，写入后无反馈 @endif */
    SSAP_OPERATE_INDICATION_BIT_WRITE = 0x04,             /*!< @if Eng data values can be written. After being written,
                                                                       a feedback is generated to the client.
                                                               @else   数据值可被写入，写入后产生反馈给客户端 @endif */
    SSAP_OPERATE_INDICATION_BIT_NOTIFY = 0x08,            /*!< @if Eng data value send to client by notification.
                                                               @else   数据值通过通知方式传递给客户端 @endif */
    SSAP_OPERATE_INDICATION_BIT_INDICATE = 0x10,          /*!< @if Eng data value send to client by indication.
                                                               @else   数据值通过指示方式传递给客户端 @endif */
    SSAP_OPERATE_INDICATION_BIT_BROADCAST = 0x20,         /*!< @if Eng data value can be carried in broadcast
                                                               @else   数据值可携带在广播中 @endif */
    SSAP_OPERATE_INDICATION_BIT_DESCRITOR_WRITE = 0x100,  /*!< @if Eng data value description descriptor can be
                                                                       written
                                                               @else   数据值说明描述符可被写入 @endif */
    SSAP_OPERATE_INDICATION_BIT_DESCRIPTOR_CLIENT_CONFIGURATION_WRITE = 0x200,
                                                             /*!< @if Eng client descriptor value can be written
                                                                   @else 客户端描述符可被写入 @endif */
    SSAP_OPERATE_INDICATION_BIT_DESCRIPTOR_SERVER_CONFIGURATION_WRITE = 0x400,
                                                             /*!< @if Eng server descriptor value can be written
                                                                   @else 服务端述符可被写入 @endif */
    SSAP_OPERATE_INDICATION_MAX = 0x7FF,                  /*!< @if Eng maximum of operation indication
                                                               @else   操作指示最大值 @endif */
} ssap_operate_indication_t;

/**
 * @if Eng
 * @brief  UUID.
 * @else
 * @brief  通用唯一识别码。
 * @endif
 */
typedef struct {
    uint8_t len;                /*!< @if Eng uuid len
                                     @else   UUID 长度 @endif */
    uint8_t uuid[SLE_UUID_LEN]; /*!< @if Eng uuid
                                     @else   UUID字段 @endif */
} sle_uuid_t;

/**
 * @if Eng
 * @brief  Struct of ssap info exchange
 * @else
 * @brief  ssap 信息交换结构体。
 * @endif
 */
typedef struct {
    uint32_t mtu_size; /*!< @if Eng mtu size
        ·                   @else   mtu大小 @endif */
    uint16_t version;  /*!< @if Eng version
                            @else   版本 @endif */
} ssap_exchange_info_t;

#ifdef __cplusplus
}
#endif
#endif /* SLE_SSAP_STRU_H */
/**
 * @}
 */
