/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * Description: APP COMMON SOURCE. \n
 *
 * History: \n
 * 2024-05-28, Create file. \n
 */
#include "common_def.h"
#include "hal_reboot.h"
#include "app_common.h"

void encode2byte_little(uint8_t *_ptr, uint16_t data)
{
    *(uint8_t *)((_ptr) + 1) = (uint8_t)((data) >> 0x8);
    *(uint8_t *)(_ptr) = (uint8_t)(data);
}

void app_mode_reset(void)
{
    hal_reboot_chip();
}
