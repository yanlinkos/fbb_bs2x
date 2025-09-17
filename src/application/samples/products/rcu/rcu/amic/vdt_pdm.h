/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2023-2023. All rights reserved.
 *
 * Description: SLE RCU AMIC VDT PDM Source \n
 *
 * History: \n
 * 2023-12-26, Create file. \n
 */
#ifndef SLE_VDT_PDM_H
#define SLE_VDT_PDM_H

#include <stdint.h>
#include "dma.h"
#include "dma_porting.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

int32_t vdt_pdm_init(void);
int32_t rcu_pdm_start_dma_transfer(uint32_t *pcm_buffer, dma_transfer_cb_t trans_done);
uint32_t vdt_pdm_get_fifo_deepth(void);

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif