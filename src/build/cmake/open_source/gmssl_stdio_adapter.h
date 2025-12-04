/*
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2022-2022. All rights reserved.
 *
 * Description: adaptation header for compiling gmssl
 *
 * Author: BGTP
 *
 * Create: 2024-01-05
 */

#ifndef GMSSL_STDIO_ADAPTER_H
#define GMSSL_STDIO_ADAPTER_H

/*
 * GMSSL引用了stdio.h里的stderr和fprintf等定义, 芯片环境下下无法编译,
 * 但GMSSL开源软件不允许直接修改, 因此通过强制定义头文件保护宏然后通过编译选项插入本文件方式, 强制替换函数宏定义
 */

#define error_print() \
    do {  } while (0)

#define error_print_msg(...) \
    do {  } while (0)

#define error_puts(...) \
    do {  } while (0)

#endif // GMSSL_STDIO_ADAPTER_H