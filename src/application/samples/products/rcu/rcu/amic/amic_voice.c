/**
 * Copyright (c) HiSilicon (Shanghai) Technologies Co., Ltd. 2024-2024. All rights reserved.
 *
 * Description: APP Voice Source File. \n
 *
 * History: \n
 * 2024-05-28, Create file. \n
 */
#if defined (CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER) || defined (CONFIG_SAMPLE_SUPPORT_BLE_RCU_SERVER) || \
    defined (CONFIG_SAMPLE_SUPPORT_AIR_MOUSE)
#include "pinctrl.h"
#include "gpio.h"
#include "vdt_pdm.h"
#include "pdm.h"
#include "dma.h"
#include "dma_porting.h"
#include "adc.h"
#include "adc_porting.h"
#include "hal_dma.h"
#endif
#include "securec.h"
#include "osal_debug.h"
#include "vdt_codec.h"
#include "amic_voice.h"

#define AMIC_VOICE_LOG                 "[amic]"
#define RING_BUFFER_NUMBER                 4

#if defined (CONFIG_SAMPLE_SUPPORT_SLE_RCU_SERVER) || defined (CONFIG_SAMPLE_SUPPORT_BLE_RCU_SERVER) || \
    defined (CONFIG_SAMPLE_SUPPORT_AIR_MOUSE)

#define ADC_GADC_CHANNEL7                  7
#define ADC_GADC_CHANNEL6                  6
#define SLE_VDT_MIC_OFFSET_16              16
#define SLE_VDT_MIC_OFFSET_24              24

static uint8_t g_pdm_buffer[CONFIG_USB_UAC_MAX_RECORD_SIZE] = {0};
static uint8_t g_write_buffer_node = 0;
static uint8_t g_read_buffer_node = 0;
static uint32_t g_pdm_dma_data0[CONFIG_USB_PDM_TRANSFER_LEN_BY_DMA] = {0};
static uint32_t g_pdm_dma_data1[CONFIG_USB_PDM_TRANSFER_LEN_BY_DMA] = {0};
static uint32_t g_pdm_dma_data2[CONFIG_USB_PDM_TRANSFER_LEN_BY_DMA] = {0};
static uint32_t g_pdm_dma_data3[CONFIG_USB_PDM_TRANSFER_LEN_BY_DMA] = {0};
static uint32_t *g_pdm_dma_data[RING_BUFFER_NUMBER] = {g_pdm_dma_data0, g_pdm_dma_data1,
                                                       g_pdm_dma_data2, g_pdm_dma_data3};
static uint32_t g_rcu_dma_channel = 0;

static void rcu_vdt_dma_transfer_restart(void);

static void vdt_adc_set_io(pin_t pin)
{
#if defined(CONFIG_PINCTRL_SUPPORT_IE)
    /* ADC管脚无需配置IE使能且管脚默认IE为0，为防止用户修改IE，特在此将IE配置为0 */
    uapi_pin_set_ie(pin, PIN_IE_0);
#endif
    uapi_pin_set_mode(pin, 0);
    uapi_gpio_set_dir(pin, GPIO_DIRECTION_INPUT);
    uapi_pin_set_pull(pin, PIN_PULL_NONE);
}

static void vdt_adc_init(void)
{
    uapi_pin_init();
    uapi_gpio_init();

    vdt_adc_set_io(CONFIG_ADC_USE_PIN1);
    vdt_adc_set_io(CONFIG_ADC_USE_PIN2);
    uapi_adc_init(ADC_CLOCK_NONE);
    uapi_adc_power_en(AFE_AMIC_MODE, true);
    uapi_adc_open_differential_channel(ADC_GADC_CHANNEL7, ADC_GADC_CHANNEL6);
    adc_calibration(AFE_AMIC_MODE, true, true, true);

    return;
}

static void rcu_vdt_dma_transfer_done_callback(uint8_t intr, uint8_t channel, uintptr_t arg)
{
    unused(channel);
    unused(arg);

    switch (intr) {
        case HAL_DMA_INTERRUPT_TFR:
            rcu_vdt_dma_transfer_restart();
            break;
        case HAL_DMA_INTERRUPT_ERR:
            osal_printk("%s DMA transfer error.\r\n", AMIC_VOICE_LOG);
            break;
        default:
            break;
    }
}

static void rcu_vdt_dma_transfer_restart(void)
{
    g_write_buffer_node = (g_write_buffer_node + 1) % RING_BUFFER_NUMBER;
    if (rcu_pdm_start_dma_transfer(g_pdm_dma_data[g_write_buffer_node],
        rcu_vdt_dma_transfer_done_callback) != 0) {
        return;
    }
}

void amic_init(void)
{
    vdt_adc_init();
    if (vdt_pdm_init() != 0) {
        osal_printk("%s Init the PDM fail.\r\n", AMIC_VOICE_LOG);
        return;
    }

    if (uapi_pdm_start() != ERRCODE_SUCC) {
        osal_printk("%s Start the PDM fail.\r\n", AMIC_VOICE_LOG);
        return;
    }

    if (rcu_pdm_start_dma_transfer(g_pdm_dma_data[0], rcu_vdt_dma_transfer_done_callback) != 0) {
        osal_printk("rcu_pdm_start_dma_transfer fail!\r\n");
        return;
    }
}

void amic_deinit(void)
{
    uapi_dma_end_transfer(g_rcu_dma_channel);
    uapi_dma_close();
    uapi_dma_deinit();
    uapi_adc_power_en(AFE_AMIC_MODE, false);
    uapi_adc_deinit();
    uapi_pdm_stop();
    uapi_pdm_deinit();
}

void get_amic_encode_data(uint8_t *length, uint8_t *out_encode_data)
{
    if (g_read_buffer_node == g_write_buffer_node) {
        *length = 0;
        return;
    }

    uint8_t *out_data1, *out_data2;
    uint32_t buffer_filled_count = 0;
    for (uint32_t i = 0; i < CONFIG_USB_PDM_TRANSFER_LEN_BY_DMA; i++) {
        g_pdm_buffer[buffer_filled_count++] =
            (uint8_t)(g_pdm_dma_data[g_read_buffer_node][i] >> SLE_VDT_MIC_OFFSET_16);
        g_pdm_buffer[buffer_filled_count++] =
            (uint8_t)(g_pdm_dma_data[g_read_buffer_node][i] >> SLE_VDT_MIC_OFFSET_24);
    }
    g_read_buffer_node = (g_read_buffer_node + 1) % RING_BUFFER_NUMBER;

    uint32_t encode_data_len1 = vdt_codec_encode(g_pdm_buffer, &out_data1);
    uint32_t encode_data_len2 = vdt_codec_encode(g_pdm_buffer + CONFIG_USB_PDM_TRANSFER_LEN_BY_DMA, &out_data2);

    if (memcpy_s(out_encode_data, LOW_LATENCY_DATA_MAX, out_data1, encode_data_len1) != EOK) {
        osal_printk("memcpy first part data fail.\r\n");
    }
    if (memcpy_s(out_encode_data + encode_data_len1, LOW_LATENCY_DATA_MAX - encode_data_len1, out_data2,
        encode_data_len2) != EOK) {
        osal_printk("memcpy second part data fail.\r\n");
    }

    *length = encode_data_len1 + encode_data_len2;
}

#else

static uint8_t g_out_decode_data1[LOW_LATENCY_DATA_MAX] = { 0 };
static uint8_t g_out_decode_data2[LOW_LATENCY_DATA_MAX] = { 0 };
static uint8_t g_out_decode_data3[LOW_LATENCY_DATA_MAX] = { 0 };
static uint8_t g_out_decode_data4[LOW_LATENCY_DATA_MAX] = { 0 };
static uint8_t *g_out_decode_data[RING_BUFFER_NUMBER] = {g_out_decode_data1, g_out_decode_data2,
                                                         g_out_decode_data3, g_out_decode_data4};
static uint8_t g_write_index = 0;
static uint8_t g_read_index = 0;

bool recive_amic_encode_data(uint8_t *data, uint16_t data_len)
{
    if (memcpy_s(g_out_decode_data[g_write_index], LOW_LATENCY_DATA_MAX, data, data_len) != EOK) {
        osal_printk("memcpy amic decode data fail.\r\n");
        return false;
    }
    g_write_index = (g_write_index + 1) % RING_BUFFER_NUMBER;
    return g_write_index != g_read_index;
}

void get_amic_decode_data(uint8_t **out_data1, uint32_t *len1, uint8_t **out_data2, uint32_t *len2)
{
    *len1 = vdt_codec_decode(g_out_decode_data[g_read_index], out_data1);
    *len2 = vdt_codec_decode(&g_out_decode_data[g_read_index][DEC_FREAM_16K_SBC_SIZE], out_data2);
    g_read_index = (g_read_index + 1) % RING_BUFFER_NUMBER;
}
#endif