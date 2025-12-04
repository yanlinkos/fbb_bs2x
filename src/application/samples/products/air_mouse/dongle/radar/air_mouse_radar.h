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

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

#define AIR_MOUSE_RADAR_GET_VERSION_DELAY_MS 2000

void air_mouse_radar_init(void);
void air_mouse_radar_start(void);
void air_mouse_radar_stop(void);
void air_mouse_radar_get_version(void);

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif