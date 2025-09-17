/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2023-2025. All rights reserved.
 *
 * Description: LOW POWER HEADER FILE. \n
 *
 * History: \n
 * 2024-05-21, Create file. \n
 */

#ifndef APP_ULP_H
#define APP_ULP_H

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

#define DURATION_MS_OF_WORK_TO_STANDBY     2000
#define DURATION_MS_OF_STANDBY_TO_SLEEP    30000

void rcu_low_power_init(void);

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif
