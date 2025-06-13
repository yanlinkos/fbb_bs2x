/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2023-2023. All rights reserved.
 *
 * Description: USB Mouse Sample Source. \n
 *
 * History: \n
 * 2023-07-07, Create file. \n
 */
#include "soc_osal.h"
#include "common_def.h"
#include "app_init.h"
#if defined(CONFIG_SAMPLE_SUPPORT_SLE_MEASURE_DIS_SERVER)
#include "sle_measure_dis_server.h"
#elif defined(CONFIG_SAMPLE_SUPPORT_SLE_MEASURE_DIS_CLIENT)
#include "sle_measure_dis_client.h"
#endif
#include "pinctrl.h"
#include "i2c.h"
#include "ssd1306_fonts.h"
#include "ssd1306.h"

#define TASK_PRIORITY_HADM          27
#define STACK_SIZE_BASELINE 0x200
#ifdef CONFIG_SAMPLE_SUPPORT_SLE_MEASURE_DIS_SERVER
#define BTH_HADM_SERVICE_STACK_SIZE (STACK_SIZE_BASELINE * 4 + 0x1000)
#else
#define BTH_HADM_SERVICE_STACK_SIZE (STACK_SIZE_BASELINE * 4 + 0x200)
#endif

#define CONFIG_I2C_MASTER_SCL_PIN_MODE 26
#define CONFIG_I2C_MASTER_SDA_PIN_MODE 27
#define CONFIG_I2C_SCL_MASTER_PIN 0
#define CONFIG_I2C_SDA_MASTER_PIN 1
#define I2C_MASTER_ADDR 0x0
#define I2C_SLAVE1_ADDR 0x38
#define I2C_SET_BANDRATE 400000

void app_i2c_init_pin(void)
{
    uapi_pin_set_mode(CONFIG_I2C_SCL_MASTER_PIN, CONFIG_I2C_MASTER_SCL_PIN_MODE);
    uapi_pin_set_mode(CONFIG_I2C_SDA_MASTER_PIN, CONFIG_I2C_MASTER_SDA_PIN_MODE);
}

void OledTask(void)
{
    uint32_t baudrate = I2C_SET_BANDRATE;
    uint8_t hscode = I2C_MASTER_ADDR;
    app_i2c_init_pin();
    errcode_t ret = uapi_i2c_master_init(0, baudrate, hscode);
    if (ret != 0) {
        printf("i2c init failed, ret = %0x\r\n", ret);
    }
    ssd1306_Init();
    ssd1306_Fill(Black);
}


#if defined(CONFIG_SAMPLE_SUPPORT_SLE_MEASURE_DIS_SERVER)
void sle_measure_dis_server_task(void)
{
    uint32_t ret;
    printf("60606060606060\r\n");
    OledTask();
    ret = measure_dis_server_init();
    check_rc_return_rc(ret, "con sle_measure_dis_server_init");
    while (1) {
        ret = osal_event_read(
            &measure_dis_evt, MEASURE_DIS_MSG_EVENT,
            OSAL_WAIT_FOREVER, OSAL_WAITMODE_OR | OSAL_WAITMODE_CLR);

        sle_measure_dis_msg_proc();
    }
}
#elif defined(CONFIG_SAMPLE_SUPPORT_SLE_MEASURE_DIS_CLIENT)
void sle_measure_dis_client_task(void)
{
    uint32_t ret;
    ret = measure_dis_client_init();
    check_rc_return_rc(ret, "con sle_measure_dis_client_init");
}
#endif

static void measure_dis_entry(void)
{
    osal_printk("CARKEY VERSION 2024.3.21 8:00.\r\n");
    osal_task *task_handle = NULL;
    osal_kthread_lock();
#if defined(CONFIG_SAMPLE_SUPPORT_SLE_MEASURE_DIS_SERVER)
    task_handle = osal_kthread_create((osal_kthread_handler)sle_measure_dis_server_task,
                                      0, "SLEMeasureDisServer", BTH_HADM_SERVICE_STACK_SIZE);
#elif defined(CONFIG_SAMPLE_SUPPORT_SLE_MEASURE_DIS_CLIENT)
    task_handle = osal_kthread_create((osal_kthread_handler)sle_measure_dis_client_task,
                                      0, "SLEMeasureDisClient", BTH_HADM_SERVICE_STACK_SIZE);
#endif
    if (task_handle != NULL) {
        osal_kthread_set_priority(task_handle, TASK_PRIORITY_HADM);
        osal_kfree(task_handle);
    }
    osal_kthread_unlock();
}

/* Run the sle_measure_dis_entry. */
app_run(measure_dis_entry);