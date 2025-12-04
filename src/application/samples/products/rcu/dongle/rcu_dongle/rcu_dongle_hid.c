/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2023-2023. All rights reserved.
 *
 * Description: SLE RCU Dongle Hid Source. \n
 *
 * History: \n
 * 2023-09-21, Create file. \n
 */
#include "gadget/f_hid.h"
#include "osal_debug.h"

#define input(size)             (0x80 | (size))
#define output(size)            (0x90 | (size))
#define collection(size)        (0xa0 | (size))
#define end_collection(size)    (0xc0 | (size))

/* Global items */
#define usage_page(size)        (0x04 | (size))
#define logical_minimum(size)   (0x14 | (size))
#define logical_maximum(size)   (0x24 | (size))
#define report_size(size)       (0x74 | (size))
#define report_id(size)         (0x84 | (size))
#define report_count(size)      (0x94 | (size))

/* Local items */
#define usage(size)                 (0x08 | (size))
#define usage_minimum(size)         (0x18 | (size))
#define usage_maximum(size)         (0x28 | (size))

static int32_t g_sle_rcu_dongle_custom_hid_index = 0;

static const uint8_t g_report_desc_hid[ ] = {
    usage_page(1),      0x01,
    usage(1),           0x06,
    collection(1),      0x01,
    report_id(1),       0x01,
    usage_page(1),      0x07,
    usage_minimum(1),   0xE0,
    usage_maximum(1),   0xE7,
    logical_minimum(1), 0x00,
    logical_maximum(1), 0x01,
    report_size(1),     0x01,
    report_count(1),    0x08,
    input(1),           0x02,
    report_count(1),    0x01,
    report_size(1),     0x08,
    input(1),           0x01,
    report_count(1),    0x05,
    report_size(1),     0x01,
    usage_page(1),      0x08,
    usage_minimum(1),   0x01,
    usage_maximum(1),   0x05,
    output(1),          0x02,
    report_count(1),    0x01,
    report_size(1),     0x03,
    output(1),          0x01,
    report_count(1),    0x06,
    report_size(1),     0x08,
    logical_minimum(1), 0x00,
    logical_maximum(1), 0xFF,
    usage_page(1),      0x07,
    usage_minimum(1),   0x00,
    usage_maximum(1),   0xFF,
    input(1),           0x00,
    end_collection(0),

    usage_page(1),      0x0C,
    usage(1),           0x01,
    collection(1),      0x01,
    report_id(1),       0x03,
    logical_minimum(1), 0x00,
    logical_maximum(2), 0xff, 0x1f,
    usage_minimum(1),   0x00,
    usage_maximum(2),   0xff, 0x1f,
    report_size(1),     0x10,
    report_count(1),    0x01,
    input(1),           0x00,
    end_collection(0),

    usage_page(1),      0x01,
    usage(1),           0x09,
    collection(1),      0x01,
    report_id(1),       0x02,
    usage(1),           0x81,
    logical_minimum(1), 0x00,
    logical_maximum(2), 0xff, 0x1f,
    usage_minimum(1),   0x00,
    usage_maximum(2),   0xff, 0x1f,
    report_size(1),     0x10,
    report_count(1),    0x01,
    input(1),           0x00,
    end_collection(0),

    usage_page(1),      0x01,
    usage(1),           0x02,
    collection(1),      0x01,
    report_id(1),       0x04,
    usage(1),           0x01,
    collection(1),      0x00,
    report_count(1),    0x03,
    report_size(1),     0x01,
    usage_page(1),      0x09,
    usage_minimum(1),   0x1,
    usage_maximum(1),   0x3,
    logical_minimum(1), 0x00,
    logical_maximum(1), 0x01,
    input(1),           0x02,
    report_count(1),    0x01,
    report_size(1),     0x05,
    input(1),           0x01,
    report_count(1),    0x03,
    report_size(1),     0x08,
    usage_page(1),      0x01,
    usage(1),           0x30,
    usage(1),           0x31,
    usage(1),           0x38,
    logical_minimum(1), 0x81,
    logical_maximum(1), 0x7f,
    input(1),           0x06,
    end_collection(0),
    end_collection(0),
};

uint8_t g_custom_report_desc[] = {
    usage_page(2), 0xB2, 0xFF,
    usage(1),           0x1,
    collection(1),      0x01,
    report_id(1),       0x1f,
    collection(1),      0x00,
    report_count(1),    0x3f,
    report_size(1),     0x8,
    usage_minimum(1),   0x0,
    usage_maximum(1),   0xFF,
    output(1),          0x2,
    usage(1),           0x2,
    report_count(1),    0x3f,
    report_size(1),     0x8,
    usage_minimum(1),   0x0,
    usage_maximum(1),   0xFF,
    input(1),           0,
    end_collection(0),
    end_collection(0)
};

int32_t rcu_dongle_set_report_desc_hid(void)
{
    int32_t index1 = hid_add_report_descriptor(g_report_desc_hid, sizeof(g_report_desc_hid), 0);
    return index1;
}

int32_t rcu_dongle_set_custom_report_desc_hid(void)
{
    g_sle_rcu_dongle_custom_hid_index =
        hid_add_report_descriptor(g_custom_report_desc, sizeof(g_custom_report_desc), 0);
    if (g_sle_rcu_dongle_custom_hid_index < 0) {
        osal_printk("[rcu dongle hid] set custom report desc hid fail!\r\n");
    }
    return g_sle_rcu_dongle_custom_hid_index;
}

int32_t rcu_dongle_get_custom_report_desc_hid(void)
{
    return g_sle_rcu_dongle_custom_hid_index;
}