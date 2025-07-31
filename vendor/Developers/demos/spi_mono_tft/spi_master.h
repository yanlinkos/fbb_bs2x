#ifndef _SPI_MASTER_H
#define _SPI_MASTER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "pinctrl.h"
#include "spi.h"
#include "dma.h"
#include "soc_osal.h"
#include "app_init.h"

#include "gpio.h"
#include "ulp_gpio.h"

#include "st7305.h"
// #include "mconfig.h"

#define SPI_SLAVE_NUM 1
#define SPI_FREQUENCY 4
#define SPI_CLK_POLARITY 0
#define SPI_CLK_PHASE 0
#define SPI_FRAME_FORMAT 0
#define SPI_FRAME_FORMAT_STANDARD 0
#define SPI_FRAME_SIZE 0x1f
#define SPI_TMOD 0
#define SPI_WAIT_CYCLES 0x10

#define SPI_TASK_PRIO 26
#define SPI_TASK_STACK_SIZE 0x0400

#define SUDOKU_LEN 81
#define SPI_DMA_WIDTH 2

extern uint8_t sudokuNumberList[SUDOKU_LEN];
extern bool sudokuReady;

#ifdef __cplusplus
}
#endif

#endif
