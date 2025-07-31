#include "spi_master.h"

uint8_t sudokuNumberList[SUDOKU_LEN] = {0};
bool sudokuReady = false;

static void app_spi_master_init(void)
{
    uapi_pin_set_mode(CONFIG_SPI_MASTER_CLK_PIN, HAL_PIO_SPI0_SCLK);
    uapi_pin_set_mode(CONFIG_SPI_MASTER_CS_PIN, HAL_PIO_SPI0_CS0);
    uapi_pin_set_mode(CONFIG_SPI_MASTER_DI_PIN, HAL_PIO_SPI0_RXD);
    uapi_pin_set_mode(CONFIG_SPI_MASTER_DO_PIN, HAL_PIO_SPI0_TXD);

    uapi_pin_set_mode(CONFIG_SPI_MASTER_RST_PIN, HAL_PIO_FUNC_GPIO);
    uapi_gpio_set_dir(CONFIG_SPI_MASTER_RST_PIN, GPIO_DIRECTION_OUTPUT);
    uapi_pin_set_mode(CONFIG_SPI_MASTER_DC_PIN, HAL_PIO_FUNC_GPIO);
    uapi_gpio_set_dir(CONFIG_SPI_MASTER_DC_PIN, GPIO_DIRECTION_OUTPUT);

    spi_attr_t config = {0};
    spi_extra_attr_t ext_config = {0};

    config.is_slave = false;
    config.slave_num = SPI_SLAVE_NUM;
    config.bus_clk = SPI_CLK_FREQ;
    config.freq_mhz = SPI_FREQUENCY;
    config.clk_polarity = SPI_CLK_POLARITY;
    config.clk_phase = SPI_CLK_PHASE;
    config.frame_format = SPI_CFG_FRAME_FORMAT_MOTOROLA_SPI;
    config.spi_frame_format = HAL_SPI_FRAME_FORMAT_STANDARD;
    config.frame_size = HAL_SPI_FRAME_SIZE_8;
    config.tmod = HAL_SPI_TRANS_MODE_TX;
    config.sste = SPI_CFG_SSTE_DISABLE;

    ext_config.qspi_param.wait_cycles = SPI_WAIT_CYCLES;
    uapi_spi_init(CONFIG_SPI_MASTER_BUS_ID, &config, &ext_config);
    uapi_dma_init();
    uapi_dma_open();
}

static void *spi_master_task(const char *arg)
{
    unused(arg);

    app_spi_master_init();

    st7305_init();

    st7305_drawFrame();
    st7305_drawNumberInCell(0, 1);
    st7305_drawNumberInCell(1, 2);
    st7305_drawNumberInCell(2, 3);
    st7305_refresh();

    while (1) {
        osal_msleep(500);
    }

    return NULL;
}

static void spi_master_entry(void)
{
    osal_task *task_handle = NULL;
    osal_kthread_lock();
    task_handle = osal_kthread_create((osal_kthread_handler)spi_master_task, 0, "SpiMasterTask", SPI_TASK_STACK_SIZE);
    if (task_handle != NULL) {
        osal_kthread_set_priority(task_handle, SPI_TASK_PRIO);
    }
    osal_kthread_unlock();
}

app_run(spi_master_entry);