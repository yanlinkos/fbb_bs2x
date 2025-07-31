#include "st7305.h"

// 经过实际测试，得出这个数值
#define COLUMN_START 0x12
#define COLUMN_END 0x2A
#define ROW_START 0x00
#define ROW_END 0xC7

#define COLUMN_COUNT 75
#define ROW_COUNT 200
#define MAX_Y (ROW_COUNT * 2)
#define MAX_X (COLUMN_COUNT * 4)

static uint8_t image[COLUMN_COUNT * ROW_COUNT] = {0x00};

void send_cmd(uint8_t cmd)
{
    uint8_t d = cmd;
    spi_xfer_data_t spi_data = {
        .tx_buff = &d,
        .tx_bytes = 1,
    };
    uapi_gpio_set_val(CONFIG_SPI_MASTER_DC_PIN, GPIO_LEVEL_LOW);
    uapi_spi_master_write(CONFIG_SPI_MASTER_BUS_ID, &spi_data, 0xFFFFFFFF);
}

void send_data(uint8_t data)
{

    uint8_t d = data;
    spi_xfer_data_t spi_data = {
        .tx_buff = &d,
        .tx_bytes = 1,
    };
    uapi_gpio_set_val(CONFIG_SPI_MASTER_DC_PIN, GPIO_LEVEL_HIGH);
    uapi_spi_master_write(CONFIG_SPI_MASTER_BUS_ID, &spi_data, 0xFFFFFFFF);
}

void send_data_array(uint8_t *data, uint32_t len)
{
    spi_xfer_data_t spi_data = {
        .tx_buff = data,
        .tx_bytes = len,
    };
    uapi_gpio_set_val(CONFIG_SPI_MASTER_DC_PIN, GPIO_LEVEL_HIGH);
    uapi_spi_master_write(CONFIG_SPI_MASTER_BUS_ID, &spi_data, 0xFFFFFFFF);
}

void st7305_init(void)
{
    // 复位
    uapi_gpio_set_val(CONFIG_SPI_MASTER_RST_PIN, GPIO_LEVEL_LOW);
    osal_msleep(50); // 延时50ms
    uapi_gpio_set_val(CONFIG_SPI_MASTER_RST_PIN, GPIO_LEVEL_HIGH);

    /////////////HSD 4.2” 300x400 Mono High Scan Rate Initial Code (8Hz)/////////////////
    send_cmd(0xD6); // NVM Load Control
    send_data(0X17);
    send_data(0X02);

    send_cmd(0xD1); // Booster Enable
    send_data(0X01);

    send_cmd(0xC0);  // Gate Voltage Setting
    send_data(0X11); // VGH 00:8V  04:10V  08:12V   0E:15V  11:16.5V
    send_data(0X04); // VGL 00:-5V   04:-7V   0A:-10V

    // VLC=3.6V (12/-5)(delta Vp=0.6V)
    send_cmd(0xC1);  // VSHP Setting (4.8V)
    send_data(0X41); // VSHP1  5.0V
    send_data(0X41); // VSHP2  5.0V
    send_data(0X41); // VSHP3  5.0V
    send_data(0X41); // VSHP4	 5.0V

    send_cmd(0xC2);  // VSLP Setting (0.98V)
    send_data(0X19); // VSLP1  0.5V
    send_data(0X19); // VSLP2  0.5V
    send_data(0X19); // VSLP3  0.5V
    send_data(0X19); // VSLP4  0.5V

    send_cmd(0xC4);  // VSHN Setting (-3.6V)
    send_data(0X41); // VSHN1	  3.8V
    send_data(0X41); // VSHN2 	3.8V
    send_data(0X41); // VSHN3 	3.8V
    send_data(0X41); // VSHN4 	3.8V

    send_cmd(0xC5);  // VSLN Setting (0.22V)
    send_data(0X19); // VSLN1 	0.5V
    send_data(0X19); // VSLN2 	0.5V
    send_data(0X19); // VSLN3 	0.5V
    send_data(0X19); // VSLN4   0.5V

    send_cmd(0xD8);  // HPM=32Hz
    send_data(0XA6); //~51Hz
    send_data(0XE9); //~1Hz

    send_cmd(0xB2);  // Frame Rate Control
    send_data(0X05); // 12--HPM=32hz ; LPM=1hz   05--HPM=16hz ; LPM=8hz

    send_cmd(0xB3); // Update Period Gate EQ Control in HPM
    send_data(0XE5);
    send_data(0XF6);
    send_data(0X05); // HPM EQ Control
    send_data(0X46);
    send_data(0X77);
    send_data(0X77);
    send_data(0X77);
    send_data(0X77);
    send_data(0X76);
    send_data(0X45);

    send_cmd(0xB4);  // Update Period Gate EQ Control in LPM
    send_data(0X05); // LPM EQ Control
    send_data(0X46);
    send_data(0X77);
    send_data(0X77);
    send_data(0X77);
    send_data(0X77);
    send_data(0X76);
    send_data(0X45);

    send_cmd(0x62); // Gate Timing Control
    send_data(0X32);
    send_data(0X03);
    send_data(0X1F);

    send_cmd(0xB7); // Source EQ Enable
    send_data(0X13);

    send_cmd(0xB0);  // Gate Line Setting
    send_data(0X64); // 60---384 line    64---400 line

    send_cmd(0x11);   // Sleep out
    osal_msleep(120); // 延时120ms

    send_cmd(0xC9);  // Source Voltage Select
    send_data(0X00); // VSHP1; VSLP1 ; VSHN1 ; VSLN1

    send_cmd(0x36);  // Memory Data Access Control
    send_data(0X00); // MX=1 ; DO=1

    send_cmd(0x3A);  // Data Format Select
    send_data(0X11); // 10:4write for 24bit ; 11: 3write for 24bit

    send_cmd(0xB9);  // Gamma Mode Setting
    send_data(0X20); // 20: Mono 00:4GS

    send_cmd(0xB8);  // Panel Setting
    send_data(0X29); // Panel Setting Frame inversion  09:column 29:dot_1-Frame 25:dot_1-Line

    // WRITE RAM 300*400
    send_cmd(0x2A); // Column Address Setting
    send_data(COLUMN_START);
    send_data(COLUMN_END);

    send_cmd(0x2B); // Row Address Setting
    send_data(ROW_START);
    send_data(ROW_END);

    send_cmd(0x35);  // TE
    send_data(0X00); //

    send_cmd(0xD0);  // Auto power dowb
    send_data(0XFF); //

    send_cmd(0x39); // LPM

    send_cmd(0x29); // DISPLAY ON

    st7305_clean();
}

void st7305_clean(void)
{
    memset(image, 0x00, COLUMN_COUNT * ROW_COUNT);
    st7305_refresh();
}

void st7305_refresh(void)
{
    send_cmd(0x2A);
    send_data(COLUMN_START);
    send_data(COLUMN_END);
    send_cmd(0x2B);
    send_data(ROW_START);
    send_data(ROW_END);
    send_cmd(0x2C);
    send_data_array(image, sizeof(image));
}

uint32_t intPow(uint8_t m, uint8_t n)
{
    uint32_t result = 1;
    while (n--)
        result *= m;
    return result;
}

void drawPoint(uint16_t x, uint16_t y)
{
    if (x > MAX_X || y > MAX_Y) {
        return;
    }
    uint16_t x1, y1, n, y2;

    x1 = x / TFT_CELL_ROW;
    y1 = y / TFT_CELL_COLUMN;

    y2 = y - y1 * TFT_CELL_COLUMN;
    n = intPow(TFT_CELL_COLUMN, (TFT_MAX_OFFSET_BIT - y2));
    if (x - x1 * TFT_CELL_ROW == 0)
        n *= TFT_CELL_ROW;

    image[x1 * COLUMN_COUNT + y1] |= n;
}

void drawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
{
    uint16_t t;
    int xerr = 0, yerr = 0, delta_x, delta_y, distance;
    int incx, incy, uRow, uCol;
    delta_x = x2 - x1; // 计算坐标增量
    delta_y = y2 - y1;
    uRow = x1; // 画线起点坐标
    uCol = y1;
    if (delta_x > 0)
        incx = 1; // 设置单步方向
    else if (delta_x == 0)
        incx = 0; // 垂直线
    else {
        incx = -1;
        delta_x = -delta_x;
    }
    if (delta_y > 0)
        incy = 1;
    else if (delta_y == 0)
        incy = 0; // 水平线
    else {
        incy = -1;
        delta_y = -delta_x;
    }
    if (delta_x > delta_y)
        distance = delta_x; // 选取基本增量坐标轴
    else
        distance = delta_y;
    for (t = 0; t < distance + 1; t++) {
        drawPoint(uRow, uCol); // 画点
        xerr += delta_x;
        yerr += delta_y;
        if (xerr > distance) {
            xerr -= distance;
            uRow += incx;
        }
        if (yerr > distance) {
            yerr -= distance;
            uCol += incy;
        }
    }
}

#define PADDING 15
#define CELL_LEN 30
#define FONT_SIZE 24
#define FONT_BYTES 36
#define FONT_X_OFFSET 7
void st7305_drawFrame(void)
{
    // 绘制10条线段
    for (uint8_t i = 0; i < 10; i++) {
        // 偏移9个padding
        drawLine(PADDING, PADDING + i * CELL_LEN, PADDING + CELL_LEN * 9 + 1, PADDING + i * CELL_LEN);
    }
    // 绘制10条线段
    for (uint8_t i = 0; i < 10; i++) {
        // 偏移9个padding
        drawLine(PADDING + i * CELL_LEN, PADDING, PADDING + i * CELL_LEN, PADDING + CELL_LEN * 9 + 1);
    }
}

/* 24*24  ASCII字符集点阵 */
const uint8_t asc2_2412[10][FONT_BYTES] = {
    {0x00, 0x00, 0x00, 0x00, 0x7F, 0x80, 0x01, 0xFF, 0xE0, 0x03, 0x80, 0x70, 0x06, 0x00, 0x18, 0x04, 0x00, 0x08, 0x04,
     0x00, 0x08, 0x06, 0x00, 0x18, 0x03, 0x80, 0x70, 0x01, 0xFF, 0xE0, 0x00, 0x7F, 0x80, 0x00, 0x00, 0x00}, /* "0",16 */
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x08, 0x01, 0x00, 0x08, 0x01, 0x00, 0x08, 0x03, 0xFF, 0xF8, 0x07,
     0xFF, 0xF8, 0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, /* "1",17 */
    {0x00, 0x00, 0x00, 0x01, 0xC0, 0x38, 0x02, 0xC0, 0x58, 0x04, 0x00, 0x98, 0x04, 0x01, 0x18, 0x04, 0x02, 0x18, 0x04,
     0x04, 0x18, 0x06, 0x1C, 0x18, 0x03, 0xF8, 0x18, 0x01, 0xE0, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, /* "2",18 */
    {0x00, 0x00, 0x00, 0x01, 0xC0, 0xE0, 0x03, 0xC0, 0xF0, 0x04, 0x00, 0x08, 0x04, 0x08, 0x08, 0x04, 0x08, 0x08, 0x06,
     0x18, 0x08, 0x03, 0xF4, 0x18, 0x01, 0xE7, 0xF0, 0x00, 0x01, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, /* "3",19 */
    {0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x0D, 0x00, 0x00, 0x11, 0x00, 0x00, 0x61, 0x00, 0x00, 0x81, 0x08, 0x03,
     0x01, 0x08, 0x07, 0xFF, 0xF8, 0x0F, 0xFF, 0xF8, 0x00, 0x01, 0x08, 0x00, 0x01, 0x08, 0x00, 0x00, 0x00}, /* "4",20 */
    {0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x07, 0xFC, 0xD0, 0x06, 0x08, 0x08, 0x06, 0x10, 0x08, 0x06, 0x10, 0x08, 0x06,
     0x10, 0x08, 0x06, 0x18, 0x38, 0x06, 0x0F, 0xF0, 0x06, 0x07, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, /* "5",21 */
    {0x00, 0x00, 0x00, 0x00, 0x3F, 0x80, 0x01, 0xFF, 0xE0, 0x03, 0x84, 0x30, 0x02, 0x08, 0x18, 0x04, 0x10, 0x08, 0x04,
     0x10, 0x08, 0x04, 0x10, 0x08, 0x07, 0x18, 0x10, 0x03, 0x0F, 0xF0, 0x00, 0x07, 0xC0, 0x00, 0x00, 0x00}, /* "6",22 */
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xC0, 0x00, 0x07, 0x00, 0x00, 0x06, 0x00, 0x00, 0x06, 0x00, 0xF8, 0x06,
     0x07, 0xF8, 0x06, 0x18, 0x00, 0x06, 0xE0, 0x00, 0x07, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00}, /* "7",23 */
    {0x00, 0x00, 0x00, 0x01, 0xE1, 0xE0, 0x03, 0xF7, 0xF0, 0x06, 0x34, 0x10, 0x04, 0x18, 0x08, 0x04, 0x18, 0x08, 0x04,
     0x0C, 0x08, 0x04, 0x0C, 0x08, 0x06, 0x16, 0x18, 0x03, 0xF3, 0xF0, 0x01, 0xC1, 0xE0, 0x00, 0x00, 0x00}, /* "8",24 */
    {0x00, 0x00, 0x00, 0x00, 0xF8, 0x00, 0x03, 0xFC, 0x30, 0x03, 0x06, 0x38, 0x04, 0x02, 0x08, 0x04, 0x02, 0x08, 0x04,
     0x02, 0x08, 0x04, 0x04, 0x10, 0x03, 0x08, 0xF0, 0x01, 0xFF, 0xC0, 0x00, 0x7F, 0x00, 0x00, 0x00, 0x00}, /* "9",25 */
};

void drawChar(uint16_t x, uint16_t y, uint8_t num)
{
    uint8_t temp;
    uint8_t t1;
    uint8_t t;
    uint16_t y0 = y;
    for (t = 0; t < FONT_BYTES; t++) {
        temp = asc2_2412[num][t];
        for (t1 = 0; t1 < 8; t1++) { /* 8: 一个字节比特数 */
            if (temp & 0x80) {
                drawPoint(x, y);
            }
            temp <<= 1;
            y++;
            if ((y - y0) == FONT_SIZE) {
                y = y0;
                x++;
                break;
            }
        }
    }
}

void st7305_drawNumberInCell(uint16_t cell, uint8_t num)
{
    uint8_t x = cell % 9;
    uint8_t y = cell / 9;

    // 有点偏移，字模从WS63拷过来，偏一点好看一些
    uint16_t drawX = x * CELL_LEN + PADDING + CELL_LEN / 2 - FONT_SIZE / 2 + FONT_X_OFFSET;
    uint16_t drawY = y * CELL_LEN + PADDING + CELL_LEN / 2 - FONT_SIZE / 2;

    drawChar(drawX, drawY, num);
}