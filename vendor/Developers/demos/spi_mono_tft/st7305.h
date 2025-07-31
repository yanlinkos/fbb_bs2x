#ifndef _ST7305_H
#define _ST7305_H

#ifdef __cplusplus
extern "C" {
#endif

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

#ifdef __cplusplus
}
#endif

#endif
