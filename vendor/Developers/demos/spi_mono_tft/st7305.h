/**
 * Copyright (c) EndyTsang 2025. All rights reserved. \n
 *
 * Description: ST7305 Driver. \n
 * 
 */
#ifndef _ST7305_H
#define _ST7305_H

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include "spi.h"
#include "pinctrl.h"
#include "spi.h"
#include "soc_osal.h"
#include "app_init.h"

#include "gpio.h"
#include "ulp_gpio.h"
#include "cmsis_os2.h"

#define TFT_CELL_ROW 2       // TFT每个byte2行
#define TFT_CELL_COLUMN 4    // TFT每个byte4列
#define TFT_MAX_OFFSET_BIT 3 // 最高3次方
// 初始化
void st7305_init(void);
// 刷新函数
void st7305_refresh(void);
// 清屏
void st7305_clean(void);
// 画边框
void st7305_drawFrame(void);
// 格子里画数字
void st7305_drawNumberInCell(uint16_t cell, uint8_t num);

#endif
