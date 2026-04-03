/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2023-2024. All rights reserved.
 *
* Description: Sle Air Mouse with dongle radar header \n
 *
 * History: \n
 * 2025-10-20, Create file. \n
 */
#ifndef SLE_AIR_MOUSE_RADAR_H
#define SLE_AIR_MOUSE_RADAR_H

#include "uart.h"
#include "gadget/usbd_acm.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

#define AIR_MOUSE_RADAR_GET_VERSION_DELAY_MS 2000

void air_mouse_radar_start(void);
void air_mouse_radar_stop(void);
void air_mouse_radar_get_version(void);

typedef void (*radar_uart_write_cb_t)(uart_bus_t bus, const uint8_t *buffer, uint32_t length, uint32_t timeout);
typedef void (*radar_usb_serial_write_cb_t)(uint32_t index, const char *buffer, size_t buflen);
void slp_radar_set_uart_write_cb(radar_uart_write_cb_t cb);
void slp_radar_set_usb_serial_write_cb(radar_usb_serial_write_cb_t cb);

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif