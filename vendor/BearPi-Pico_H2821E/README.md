# BearPi-Pico H2821E 开发板示例

## 介绍

### 功能介绍

BearPi-Pico H2821E 开发板示例集合了丰富的外设演示案例，涵盖 GPIO、ADC、PWM、定时器、UART、SPI、I2C、I2S、PDM、DMA、CAN、SFC 等多种外设接口。

| 示例 | 功能描述 |
|------|---------|
| Blinky | GPIO 输出控制 LED 循环闪烁 |
| Button | GPIO 按键中断检测 |
| ADC | ADC 模数转换采样 |
| PWM | PWM 脉宽调制输出 |
| RTC | RTC 实时时钟定时 |
| Timer | 硬件定时器多通道定时 |
| I2C | I2C 主从机通信 |
| SPI | SPI 主从机通信 |
| DMA | DMA 直接内存访问传输 |
| CAN | CAN FD 总线通信 |
| QDEC | 正交编码器解码 |
| KeyScan | 键盘矩阵扫描 |
| SFC | 串行闪存读写操作 |
| I2S | I2S 音频数据传输 |
| PDM | PDM 数字麦克风采集 |
| PDM AMIC | PDM 模拟麦克风采集 |
| I2S DMA | I2S DMA 音频传输 |
| I2S DMA LLI | I2S DMA 链表传输 |
| Systick | 系统滴答定时器延时 |
| TCXO | 温补晶振延时 |
| Clocks | 时钟校准 |
| Tasks | 基础任务创建 |
| UART | UART 串口通信 |
| UART DMA LLI | UART DMA 链表传输 |
| Watchdog | 看门狗定时器 |

### 软件概述

- **Blinky 示例**：通过 GPIO 引脚输出高低电平，控制 LED 灯循环亮灭
- **Button 示例**：通过 GPIO 双向边沿中断检测按键按下
- **ADC 示例**：通过 ADC 采样获取外部模拟信号数值
- **PWM 示例**：通过 PWM 输出实现指定频率和占空比的脉冲信号
- **RTC 示例**：RTC 实时时钟定时功能
- **Timer 示例**：硬件定时器多通道定时功能
- **I2C 示例**：I2C 主从机之间的数据收发通信
- **SPI 示例**：SPI 主从机之间的数据收发通信
- **DMA 示例**：DMA 直接内存访问传输，支持单次和链表模式
- **CAN 示例**：CAN FD 总线数据收发
- **QDEC 示例**：正交编码器解码计数
- **KeyScan 示例**：键盘矩阵扫描检测按键
- **SFC 示例**：串行闪存的读写操作
- **I2S 示例**：I2S 音频接口数据传输
- **PDM 示例**：PDM 数字麦克风数据采集
- **PDM AMIC 示例**：PDM 模拟麦克风数据采集
- **I2S DMA 示例**：I2S 通过 DMA 进行音频数据传输
- **I2S DMA LLI 示例**：I2S 通过 DMA 链表进行音频数据传输
- **Systick 示例**：系统滴答定时器延时功能
- **TCXO 示例**：温补晶振延时功能
- **Clocks 示例**：时钟校准功能
- **Tasks 示例**：基础任务创建和调度
- **UART 示例**：UART 串口数据收发，支持轮询和中断模式
- **UART DMA LLI 示例**：UART 通过 DMA 链表进行数据传输
- **Watchdog 示例**：看门狗定时器喂狗

### 硬件概述

BearPi-Pico H2821E 开发板基于海思 Hi2821E 芯片，详情请参考：
- [BearPi-Pico H2821E 原理图](../../doc/hardware/BearPi-Pico_H2821E_原理图_V01.pdf)
- [BearPi-Pico H2821E 产品介绍](../../doc/README.md)

## 约束与限制

### 支持应用运行的芯片和开发板

本示例支持开发板：**BearPi-Pico H2821E**

### 支持 API 版本、SDK 版本

本示例支持版本号：**1.10.101 及以上**

### 支持 IDE 插件版本

本示例支持 IDE 插件版本号：**1.0.1 及以上**

## 目录结构

```
BearPi-Pico_H2821E/
├── peripheral/                    # 外设示例目录
│   ├── adc/                       # ADC 示例
│   │   ├── adc_demo.c
│   │   ├── CMakeLists.txt
│   │   └── Kconfig
│   ├── blinky/                    # LED 闪烁示例
│   │   ├── blinky_cmsis.c
│   │   ├── CMakeLists.txt
│   │   └── Kconfig
│   ├── button/                    # 按键中断示例
│   │   ├── button.c
│   │   ├── CMakeLists.txt
│   │   └── Kconfig
│   ├── can/                       # CAN 总线示例
│   │   ├── can_demo.c
│   │   ├── CMakeLists.txt
│   │   └── Kconfig
│   ├── clocks/                   # 时钟校准示例
│   │   ├── clocks_demo.c
│   │   ├── CMakeLists.txt
│   │   └── Kconfig
│   ├── dma/                      # DMA 示例
│   │   ├── dma_demo.c
│   │   ├── CMakeLists.txt
│   │   └── Kconfig
│   ├── i2c/                      # I2C 示例
│   │   ├── i2c_master_demo.c
│   │   ├── i2c_slave_demo.c
│   │   ├── CMakeLists.txt
│   │   └── Kconfig
│   ├── i2s/                      # I2S 示例
│   │   ├── i2s_master_demo.c
│   │   ├── i2s_slave_demo.c
│   │   ├── CMakeLists.txt
│   │   └── Kconfig
│   ├── i2s_dma/                  # I2S DMA 示例
│   │   ├── i2s_dma_master_demo.c
│   │   ├── i2s_dma_slave_demo.c
│   │   ├── CMakeLists.txt
│   │   └── Kconfig
│   ├── i2s_dma_lli/              # I2S DMA LLI 示例
│   │   ├── i2s_dma_lli_master_demo.c
│   │   ├── i2s_dma_lli_slave_demo.c
│   │   ├── CMakeLists.txt
│   │   └── Kconfig
│   ├── keyscan/                  # 键盘扫描示例
│   │   ├── keyscan_demo.c
│   │   ├── CMakeLists.txt
│   │   └── Kconfig
│   ├── pdm/                      # PDM 数字麦克风示例
│   │   ├── pdm_demo.c
│   │   ├── CMakeLists.txt
│   │   └── Kconfig
│   ├── pdm_amic/                 # PDM 模拟麦克风示例
│   │   ├── pdm_amic_demo.c
│   │   ├── CMakeLists.txt
│   │   └── Kconfig
│   ├── pinctrl/                  # 引脚控制示例
│   │   ├── pinctrl_demo.c
│   │   ├── CMakeLists.txt
│   │   └── Kconfig
│   ├── pwm/                      # PWM 示例
│   │   ├── pwm_demo.c
│   │   ├── CMakeLists.txt
│   │   └── Kconfig
│   ├── qdec/                     # 正交解码器示例
│   │   ├── qdec_demo.c
│   │   ├── CMakeLists.txt
│   │   └── Kconfig
│   ├── rtc/                      # RTC 实时时钟示例
│   │   ├── rtc_demo.c
│   │   ├── CMakeLists.txt
│   │   └── Kconfig
│   ├── sfc/                      # 串行闪存示例
│   │   ├── sfc_demo.c
│   │   ├── CMakeLists.txt
│   │   └── Kconfig
│   ├── spi/                      # SPI 示例
│   │   ├── spi_master_demo.c
│   │   ├── spi_slave_demo.c
│   │   ├── CMakeLists.txt
│   │   └── Kconfig
│   ├── systick/                  # 系统滴答定时器示例
│   │   ├── systick_demo.c
│   │   ├── CMakeLists.txt
│   │   └── Kconfig
│   ├── tasks/                    # 基础任务示例
│   │   ├── tasks.c
│   │   ├── CMakeLists.txt
│   │   └── Kconfig
│   ├── tcxo/                     # TCXO 温补晶振示例
│   │   ├── tcxo_demo.c
│   │   ├── CMakeLists.txt
│   │   └── Kconfig
│   ├── timer/                    # 硬件定时器示例
│   │   ├── timer_demo.c
│   │   ├── CMakeLists.txt
│   │   └── Kconfig
│   ├── uart/                     # UART 示例
│   │   ├── CMakeLists.txt
│   │   └── Kconfig
│   ├── uart_dma_lli/             # UART DMA LLI 示例
│   │   ├── CMakeLists.txt
│   │   └── Kconfig
│   ├── watchdog/                # 看门狗示例
│   │   ├── CMakeLists.txt
│   │   └── Kconfig
│   ├── CMakeLists.txt
│   └── Kconfig
├── doc/
│   ├── README.md                 # 产品介绍文档
│   ├── hardware/                 # 硬件文档
│   │   └── BearPi-Pico_H2821E_原理图_V01.pdf
│   └── media/                    # 媒体资源
│       └── BearPi-Pico_H2821E/
│           ├── image.png
│           └── pico-1.png
├── build_config.json             # 构建配置
└── README.md                     # 本文档
```

## 效果预览

| 示例 | 效果 |
|------|------|
| Blinky | 开发板上的 LED 灯以 500ms 间隔循环闪烁 |
| Button | 按下按键后串口输出 "Button pressed." |
| ADC | 串口输出 ADC 采样电压值（单位：mV） |
| PWM | PWM 引脚输出指定频率和占空比的脉冲信号 |
| RTC | 串口输出多通道 RTC 定时时间统计 |
| Timer | 串口输出多通道定时器时间统计 |
| I2C | I2C 主机发送数据后接收从机返回数据 |
| SPI | SPI 主机发送数据后接收从机返回数据 |
| DMA | DMA 内存到内存数据传输完成提示 |
| CAN | CAN 总线发送和接收数据，串口打印 ID 和数据 |
| QDEC | 旋转编码器转动时串口输出当前计数值 |
| KeyScan | 按下键盘矩阵按键时串口输出按键值 |
| SFC | 串口输出 Flash 读写测试结果 |
| I2S | I2S 音频数据发送和接收 |
| PDM | PDM 数字麦克风数据采集存储 |
| PDM AMIC | PDM 模拟麦克风（AMIC）数据采集存储 |
| I2S DMA | I2S 通过 DMA 方式发送音频数据 |
| I2S DMA LLI | I2S 通过 DMA 链表方式发送音频数据 |
| Systick | 串口输出 systick 延时和计数值 |
| TCXO | 串口输出 TCXO 延时和计数值 |
| Clocks | 时钟校准完成，打印校准值 |
| Tasks | 串口输出 "Hello BS25, Now you can develop SLE Product!" |
| UART | 串口数据收发 |
| UART DMA LLI | UART 通过 DMA 链表方式收发数据 |
| Watchdog | 看门狗定时器喂狗 |

## 接口介绍

### GPIO 接口

#### uapi_gpio_set_dir()

| **定义** | errcode_t uapi_gpio_set_dir(pin_t pin, gpio_direction_t dir); |
|---------|-------------------------------------------------------------|
| **功能** | 设置 GPIO 的输入输出方向 |
| **参数** | pin：IO 引脚号<br/>dir：输入输出方向（GPIO_DIRECTION_INPUT / GPIO_DIRECTION_OUTPUT） |
| **返回值** | ERRCODE_SUCC：成功 Other：失败 |
| **依赖** | driver/gpio.h |

#### uapi_gpio_set_val()

| **定义** | errcode_t uapi_gpio_set_val(pin_t pin, gpio_level_t level); |
|---------|----------------------------------------------------------- |
| **功能** | 设置 GPIO 的输出电平 |
| **参数** | pin：IO 引脚号<br/>level：输出电平（GPIO_LEVEL_HIGH / GPIO_LEVEL_LOW） |
| **返回值** | ERRCODE_SUCC：成功 Other：失败 |
| **依赖** | driver/gpio.h |

#### uapi_gpio_toggle()

| **定义** | errcode_t uapi_gpio_toggle(pin_t pin); |
|---------|-------------------------------------- |
| **功能** | 翻转 GPIO 输出电平状态 |
| **参数** | pin：IO 引脚号 |
| **返回值** | ERRCODE_SUCC：成功 Other：失败 |
| **依赖** | driver/gpio.h |

#### uapi_gpio_register_isr_func()

| **定义** | errcode_t uapi_gpio_register_isr_func(pin_t pin, gpio_interrupt_mode_t mode, gpio_callback_t func); |
|---------|------------------------------------------------------------------------------------------------------|
| **功能** | 注册 GPIO 中断回调函数 |
| **参数** | pin：IO 引脚号<br/>mode：中断触发模式<br/>func：中断回调函数 |
| **返回值** | ERRCODE_SUCC：成功 Other：失败 |
| **依赖** | driver/gpio.h |

#### uapi_gpio_enable_interrupt()

| **定义** | errcode_t uapi_gpio_enable_interrupt(pin_t pin); |
|---------|--------------------------------------------------|
| **功能** | 使能 GPIO 中断 |
| **参数** | pin：IO 引脚号 |
| **返回值** | ERRCODE_SUCC：成功 Other：失败 |
| **依赖** | driver/gpio.h |

### ADC 接口

#### uapi_adc_init()

| **定义** | errcode_t uapi_adc_init(uint8_t clock); |
|---------|----------------------------------------|
| **功能** | 初始化 ADC 模块 |
| **参数** | clock：ADC 时钟配置 |
| **返回值** | ERRCODE_SUCC：成功 Other：失败 |
| **依赖** | driver/adc.h |

#### uapi_adc_auto_sample()

| **定义** | int32_t uapi_adc_auto_sample(uint8_t channel); |
|---------|------------------------------------------------|
| **功能** | 自动采样指定通道的 ADC 值 |
| **参数** | channel：ADC 通道号 |
| **返回值** | ADC 采样值 |
| **依赖** | driver/adc.h |

### PWM 接口

#### uapi_pwm_init()

| **定义** | errcode_t uapi_pwm_init(void); |
|---------|-------------------------------|
| **功能** | 初始化 PWM 模块 |
| **返回值** | ERRCODE_SUCC：成功 Other：失败 |
| **依赖** | driver/pwm.h |

#### uapi_pwm_open()

| **定义** | errcode_t uapi_pwm_open(uint8_t channel, const pwm_config_t *config); |
|---------|----------------------------------------------------------------------|
| **功能** | 打开 PWM 通道并配置 |
| **参数** | channel：PWM 通道号<br/>config：PWM 配置参数 |
| **返回值** | ERRCODE_SUCC：成功 Other：失败 |
| **依赖** | driver/pwm.h |

#### uapi_pwm_set_group()

| **定义** | errcode_t uapi_pwm_set_group(uint8_t group_id, const uint8_t *channels, uint8_t channel_count); |
|---------|-----------------------------------------------------------------------------------------------|
| **功能** | 设置 PWM 组通道 |
| **参数** | group_id：组 ID<br/>channels：通道列表<br/>channel_count：通道数量 |
| **返回值** | ERRCODE_SUCC：成功 Other：失败 |
| **依赖** | driver/pwm.h |

#### uapi_pwm_start_group()

| **定义** | errcode_t uapi_pwm_start_group(uint8_t group_id); |
|---------|---------------------------------------------------|
| **功能** | 启动 PWM 组输出 |
| **参数** | group_id：组 ID |
| **返回值** | ERRCODE_SUCC：成功 Other：失败 |
| **依赖** | driver/pwm.h |

### PINCTRL 接口

#### uapi_pin_set_mode()

| **定义** | errcode_t uapi_pin_set_mode(pin_t pin, pin_mode_t mode); |
|---------|---------------------------------------------------------|
| **功能** | 设置引脚模式 |
| **参数** | pin：引脚号<br/>mode：模式 |
| **返回值** | ERRCODE_SUCC：成功 Other：失败 |
| **依赖** | driver/pinctrl.h |

#### uapi_pin_set_pull()

| **定义** | errcode_t uapi_pin_set_pull(pin_t pin, pin_pull_t pull); |
|---------|----------------------------------------------------------|
| **功能** | 设置引脚上下拉 |
| **参数** | pin：引脚号<br/>pull：上下拉配置 |
| **返回值** | ERRCODE_SUCC：成功 Other：失败 |
| **依赖** | driver/pinctrl.h |

### UART 接口

#### uapi_uart_init()

| **定义** | errcode_t uapi_uart_init(uint8_t id, const uart_pin_config_t *pin_config, const uart_attr_t *attr, ...); |
|---------|-----------------------------------------------------------------------------------------------|
| **功能** | 初始化 UART |
| **参数** | id：UART ID<br/>pin_config：引脚配置<br/>attr：串口属性 |
| **返回值** | ERRCODE_SUCC：成功 Other：失败 |
| **依赖** | driver/uart.h |

#### uapi_uart_write()

| **定义** | errcode_t uapi_uart_write(uint8_t id, const uint8_t *data, uint16_t length, uint16_t timeout); |
|---------|-----------------------------------------------------------------------------------------------|
| **功能** | UART 发送数据 |
| **参数** | id：UART ID<br/>data：数据缓冲区<br/>length：数据长度<br/>timeout：超时时间 |
| **返回值** | ERRCODE_SUCC：成功 Other：失败 |
| **依赖** | driver/uart.h |

### I2C 接口

#### uapi_i2c_master_init()

| **定义** | errcode_t uapi_i2c_master_init(uint8_t bus, uint32_t baudrate, uint8_t hscode); |
|---------|----------------------------------------------------------------------------------|
| **功能** | 初始化 I2C 主机 |
| **参数** | bus：I2C 总线号<br/>baudrate：波特率<br/>hscode：高速码 |
| **返回值** | ERRCODE_SUCC：成功 Other：失败 |
| **依赖** | driver/i2c.h |

#### uapi_i2c_master_write()

| **定义** | errcode_t uapi_i2c_master_write(uint8_t bus, uint16_t dev_addr, i2c_data_t *data); |
|---------|----------------------------------------------------------------------------------------|
| **功能** | I2C 主机发送数据 |
| **参数** | bus：I2C 总线号<br/>dev_addr：设备地址<br/>data：数据配置 |
| **返回值** | ERRCODE_SUCC：成功 Other：失败 |
| **依赖** | driver/i2c.h |

#### uapi_i2c_master_read()

| **定义** | errcode_t uapi_i2c_master_read(uint8_t bus, uint16_t dev_addr, i2c_data_t *data); |
|---------|----------------------------------------------------------------------------------------|
| **功能** | I2C 主机接收数据 |
| **参数** | bus：I2C 总线号<br/>dev_addr：设备地址<br/>data：数据配置 |
| **返回值** | ERRCODE_SUCC：成功 Other：失败 |
| **依赖** | driver/i2c.h |

### SPI 接口

#### uapi_spi_init()

| **定义** | errcode_t uapi_spi_init(uint8_t bus, const spi_attr_t *config, const spi_extra_attr_t *ext_config); |
|---------|-------------------------------------------------------------------------------------------------------|
| **功能** | 初始化 SPI |
| **参数** | bus：SPI 总线号<br/>config：SPI 配置<br/>ext_config：扩展配置 |
| **返回值** | ERRCODE_SUCC：成功 Other：失败 |
| **依赖** | driver/spi.h |

#### uapi_spi_master_write()

| **定义** | errcode_t uapi_spi_master_write(uint8_t bus, spi_xfer_data_t *data, uint32_t timeout); |
|---------|-------------------------------------------------------------------------------------------|
| **功能** | SPI 主机发送数据 |
| **参数** | bus：SPI 总线号<br/>data：传输数据配置<br/>timeout：超时时间 |
| **返回值** | ERRCODE_SUCC：成功 Other：失败 |
| **依赖** | driver/spi.h |

#### uapi_spi_master_read()

| **定义** | errcode_t uapi_spi_master_read(uint8_t bus, spi_xfer_data_t *data, uint32_t timeout); |
|---------|------------------------------------------------------------------------------------------|
| **功能** | SPI 主机接收数据 |
| **参数** | bus：SPI 总线号<br/>data：传输数据配置<br/>timeout：超时时间 |
| **返回值** | ERRCODE_SUCC：成功 Other：失败 |
| **依赖** | driver/spi.h |

### DMA 接口

#### uapi_dma_init()

| **定义** | errcode_t uapi_dma_init(void); |
|---------|-------------------------------|
| **功能** | 初始化 DMA 模块 |
| **返回值** | ERRCODE_SUCC：成功 Other：失败 |
| **依赖** | driver/dma.h |

#### uapi_dma_transfer_memory_single()

| **定义** | errcode_t uapi_dma_transfer_memory_single(dma_ch_user_memory_config_t *config, dma_transfer_cb_t callback, uintptr_t arg); |
|---------|----------------------------------------------------------------------------------------------------------------------------|
| **功能** | DMA 单次内存传输 |
| **参数** | config：传输配置<br/>callback：传输完成回调<br/>arg：回调参数 |
| **返回值** | ERRCODE_SUCC：成功 Other：失败 |
| **依赖** | driver/dma.h |

#### uapi_dma_transfer_memory_lli()

| **定义** | errcode_t uapi_dma_transfer_memory_lli(dma_channel_t channel, dma_ch_user_memory_config_t *config, dma_transfer_cb_t callback); |
|---------|----------------------------------------------------------------------------------------------------------------------------|
| **功能** | DMA 链表内存传输 |
| **参数** | channel：DMA 通道号<br/>config：传输配置<br/>callback：传输完成回调 |
| **返回值** | ERRCODE_SUCC：成功 Other：失败 |
| **依赖** | driver/dma.h |

### Timer 接口

#### uapi_timer_init()

| **定义** | errcode_t uapi_timer_init(void); |
|---------|---------------------------------|
| **功能** | 初始化定时器模块 |
| **返回值** | ERRCODE_SUCC：成功 Other：失败 |
| **依赖** | driver/timer.h |

#### uapi_timer_create()

| **定义** | errcode_t uapi_timer_create(uint8_t timer_idx, timer_handle_t *handle); |
|---------|-----------------------------------------------------------------------|
| **功能** | 创建定时器实例 |
| **参数** | timer_idx：定时器索引<br/>handle：定时器句柄 |
| **返回值** | ERRCODE_SUCC：成功 Other：失败 |
| **依赖** | driver/timer.h |

#### uapi_timer_start()

| **定义** | errcode_t uapi_timer_start(timer_handle_t handle, uint32_t timeout, timer_callback_t callback, uintptr_t data); |
|---------|----------------------------------------------------------------------------------------------------------------|
| **功能** | 启动定时器 |
| **参数** | handle：定时器句柄<br/>timeout：超时时间（us）<br/>callback：回调函数<br/>data：回调参数 |
| **返回值** | ERRCODE_SUCC：成功 Other：失败 |
| **依赖** | driver/timer.h |

### RTC 接口

#### uapi_rtc_init()

| **定义** | errcode_t uapi_rtc_init(void); |
|---------|-------------------------------|
| **功能** | 初始化 RTC 模块 |
| **返回值** | ERRCODE_SUCC：成功 Other：失败 |
| **依赖** | driver/rtc.h |

#### uapi_rtc_create()

| **定义** | errcode_t uapi_rtc_create(uint8_t rtc_idx, rtc_handle_t *handle); |
|---------|--------------------------------------------------------------------|
| **功能** | 创建 RTC 实例 |
| **参数** | rtc_idx：RTC 索引<br/>handle：RTC 句柄 |
| **返回值** | ERRCODE_SUCC：成功 Other：失败 |
| **依赖** | driver/rtc.h |

#### uapi_rtc_start()

| **定义** | errcode_t uapi_rtc_start(rtc_handle_t handle, uint32_t timeout, rtc_callback_t callback, uintptr_t data); |
|---------|------------------------------------------------------------------------------------------------------------|
| **功能** | 启动 RTC 定时 |
| **参数** | handle：RTC 句柄<br/>timeout：超时时间（ms）<br/>callback：回调函数<br/>data：回调参数 |
| **返回值** | ERRCODE_SUCC：成功 Other：失败 |
| **依赖** | driver/rtc.h |

### CAN 接口

#### uapi_can_init()

| **定义** | errcode_t uapi_can_init(uint8_t bus, const can_global_config_t *global_config, const can_filter_list_t *std_list, ...); |
|---------|------------------------------------------------------------------------------------------------------------------------|
| **功能** | 初始化 CAN 模块 |
| **参数** | bus：CAN 总线号<br/>global_config：全局配置<br/>std_list：标准帧过滤列表 |
| **返回值** | ERRCODE_SUCC：成功 Other：失败 |
| **依赖** | driver/can.h |

#### uapi_can_send_msg()

| **定义** | errcode_t uapi_can_send_msg(uint8_t bus, can_msg_attr_t *msg, uint8_t *data, uint8_t length); |
|---------|------------------------------------------------------------------------------------------------|
| **功能** | CAN 发送数据 |
| **参数** | bus：CAN 总线号<br/>msg：报文属性<br/>data：数据缓冲区<br/>length：数据长度 |
| **返回值** | ERRCODE_SUCC：成功 Other：失败 |
| **依赖** | driver/can.h |

#### uapi_can_callback_register()

| **定义** | errcode_t uapi_can_callback_register(uint8_t bus, can_callback_t callback); |
|---------|------------------------------------------------------------------------------|
| **功能** | 注册 CAN 回调函数 |
| **参数** | bus：CAN 总线号<br/>callback：回调函数 |
| **返回值** | ERRCODE_SUCC：成功 Other：失败 |
| **依赖** | driver/can.h |

### SFC 接口

#### uapi_sfc_reg_read()

| **定义** | errcode_t uapi_sfc_reg_read(uint32_t addr, uint8_t *data, uint32_t len); |
|---------|----------------------------------------------------------------------------|
| **功能** | 读取 SFC 闪存数据 |
| **参数** | addr：闪存地址<br/>data：数据缓冲区<br/>len：数据长度 |
| **返回值** | ERRCODE_SUCC：成功 Other：失败 |
| **依赖** | driver/sfc.h |

#### uapi_sfc_reg_write()

| **定义** | errcode_t uapi_sfc_reg_write(uint32_t addr, uint8_t *data, uint32_t len); |
|---------|-----------------------------------------------------------------------------|
| **功能** | 写入 SFC 闪存数据 |
| **参数** | addr：闪存地址<br/>data：数据缓冲区<br/>len：数据长度 |
| **返回值** | ERRCODE_SUCC：成功 Other：失败 |
| **依赖** | driver/sfc.h |

#### uapi_sfc_reg_erase()

| **定义** | errcode_t uapi_sfc_reg_erase(uint32_t addr, uint32_t len); |
|---------|-----------------------------------------------------------|
| **功能** | 擦除 SFC 闪存数据 |
| **参数** | addr：闪存地址<br/>len：擦除长度 |
| **返回值** | ERRCODE_SUCC：成功 Other：失败 |
| **依赖** | driver/sfc.h |

### PDM 接口

#### uapi_pdm_init()

| **定义** | errcode_t uapi_pdm_init(void); |
|---------|-------------------------------|
| **功能** | 初始化 PDM 模块 |
| **返回值** | ERRCODE_SUCC：成功 Other：失败 |
| **依赖** | driver/pdm.h |

#### uapi_pdm_set_attr()

| **定义** | errcode_t uapi_pdm_set_attr(hal_pdm_mic_t mic, const pdm_config_t *config); |
|---------|------------------------------------------------------------------------------|
| **功能** | 配置 PDM 参数 |
| **参数** | mic：麦克风类型<br/>config：PDM 配置 |
| **返回值** | ERRCODE_SUCC：成功 Other：失败 |
| **依赖** | driver/pdm.h |

#### uapi_pdm_start()

| **定义** | errcode_t uapi_pdm_start(void); |
|---------|--------------------------------|
| **功能** | 启动 PDM 采集 |
| **返回值** | ERRCODE_SUCC：成功 Other：失败 |
| **依赖** | driver/pdm.h |

### I2S 接口

#### uapi_i2s_init()

| **定义** | errcode_t uapi_i2s_init(uint8_t bus, i2s_rx_callback_t callback); |
|---------|---------------------------------------------------------------|
| **功能** | 初始化 I2S 模块 |
| **参数** | bus：I2S 总线号<br/>callback：接收回调函数 |
| **返回值** | ERRCODE_SUCC：成功 Other：失败 |
| **依赖** | driver/i2s.h |

#### uapi_i2s_set_config()

| **定义** | errcode_t uapi_i2s_set_config(uint8_t bus, const i2s_config_t *config); |
|---------|-----------------------------------------------------------------------|
| **功能** | 配置 I2S 参数 |
| **参数** | bus：I2S 总线号<br/>config：I2S 配置 |
| **返回值** | ERRCODE_SUCC：成功 Other：失败 |
| **依赖** | driver/i2s.h |

#### uapi_i2s_write_data()

| **定义** | errcode_t uapi_i2s_write_data(uint8_t bus, const i2s_tx_data_t *data); |
|---------|-----------------------------------------------------------------------|
| **功能** | I2S 发送数据 |
| **参数** | bus：I2S 总线号<br/>data：发送数据配置 |
| **返回值** | ERRCODE_SUCC：成功 Other：失败 |
| **依赖** | driver/i2s.h |

### QDEC 接口

#### uapi_qdec_init()

| **定义** | errcode_t uapi_qdec_init(const qdec_config_t *config); |
|---------|------------------------------------------------------|
| **功能** | 初始化 QDEC 模块 |
| **参数** | config：QDEC 配置 |
| **返回值** | ERRCODE_SUCC：成功 Other：失败 |
| **依赖** | driver/qdec.h |

#### uapi_qdec_enable()

| **定义** | errcode_t uapi_qdec_enable(void); |
|---------|----------------------------------|
| **功能** | 使能 QDEC 解码 |
| **返回值** | ERRCODE_SUCC：成功 Other：失败 |
| **依赖** | driver/qdec.h |

### KeyScan 接口

#### uapi_keyscan_init()

| **定义** | errcode_t uapi_keyscan_init(uint8_t pulse_time, uint8_t mode, uint8_t int_type); |
|---------|-------------------------------------------------------------------------------|
| **功能** | 初始化键盘扫描模块 |
| **参数** | pulse_time：脉冲时间<br/>mode：模式<br/>int_type：中断类型 |
| **返回值** | ERRCODE_SUCC：成功 Other：失败 |
| **依赖** | driver/keyscan.h |

#### uapi_keyscan_enable()

| **定义** | errcode_t uapi_keyscan_enable(void); |
|---------|-------------------------------------|
| **功能** | 使能键盘扫描 |
| **返回值** | ERRCODE_SUCC：成功 Other：失败 |
| **依赖** | driver/keyscan.h |

### Systick 接口

#### uapi_systick_init()

| **定义** | void uapi_systick_init(void); |
|---------|-------------------------------|
| **功能** | 初始化系统滴答定时器 |
| **参数** | 无 |
| **返回值** | 无 |
| **依赖** | driver/systick.h |

#### uapi_systick_delay_ms()

| **定义** | void uapi_systick_delay_ms(uint32_t ms); |
|---------|------------------------------------------|
| **功能** | 系统滴答延时（毫秒） |
| **参数** | ms：延时毫秒数 |
| **返回值** | 无 |
| **依赖** | driver/systick.h |

#### uapi_systick_delay_us()

| **定义** | void uapi_systick_delay_us(uint32_t us); |
|---------|------------------------------------------|
| **功能** | 系统滴答延时（微秒） |
| **参数** | us：延时微秒数 |
| **返回值** | 无 |
| **依赖** | driver/systick.h |

### TCXO 接口

#### uapi_tcxo_init()

| **定义** | void uapi_tcxo_init(void); |
|---------|----------------------------|
| **功能** | 初始化 TCXO 模块 |
| **参数** | 无 |
| **返回值** | 无 |
| **依赖** | driver/tcxo.h |

#### uapi_tcxo_delay_ms()

| **定义** | void uapi_tcxo_delay_ms(uint32_t ms); |
|---------|---------------------------------------|
| **功能** | TCXO 延时（毫秒） |
| **参数** | ms：延时毫秒数 |
| **返回值** | 无 |
| **依赖** | driver/tcxo.h |

#### uapi_tcxo_delay_us()

| **定义** | void uapi_tcxo_delay_us(uint32_t us); |
|---------|---------------------------------------|
| **功能** | TCXO 延时（微秒） |
| **参数** | us：延时微秒数 |
| **返回值** | 无 |
| **依赖** | driver/tcxo.h |

## Blinky 示例实现

### 具体实现

步骤一：设置 GPIO 引脚为输出模式

步骤二：设置 GPIO 初始电平为低

步骤三：循环翻转 GPIO 电平状态，实现 LED 闪烁

### 核心代码

```c
// 配置 LED 引脚为输出模式
uapi_pin_set_mode(CONFIG_BLINKY_PIN, HAL_PIO_FUNC_GPIO);
uapi_gpio_set_dir(CONFIG_BLINKY_PIN, GPIO_DIRECTION_OUTPUT);
uapi_gpio_set_val(CONFIG_BLINKY_PIN, GPIO_LEVEL_LOW);

// 主循环
while (1) {
    osDelay(CONFIG_BLINKY_DURATION_MS);
    uapi_gpio_toggle(CONFIG_BLINKY_PIN);
}
```

## Button 示例实现

### 具体实现

步骤一：设置 GPIO 引脚为输入模式

步骤二：设置引脚上拉

步骤三：注册 GPIO 双向边沿中断回调函数

步骤四：使能 GPIO 中断

### 核心代码

```c
// 配置按键引脚
uapi_pin_set_mode(CONFIG_BUTTON_PIN, HAL_PIO_FUNC_GPIO);
uapi_pin_set_pull(CONFIG_BUTTON_PIN, PIN_PULL_UP);
uapi_gpio_set_dir(CONFIG_BUTTON_PIN, GPIO_DIRECTION_INPUT);

// 注册中断回调（双向边沿触发）
uapi_gpio_register_isr_func(CONFIG_BUTTON_PIN, GPIO_INTERRUPT_DEDGE, gpio_callback_func);

// 中断回调函数
static void gpio_callback_func(pin_t pin, uintptr_t param)
{
    UNUSED(pin);
    UNUSED(param);
    osal_printk("Button pressed.\r\n");
}
```

## ADC 示例实现

### 具体实现

步骤一：初始化 PMU 和 ADC 模块

步骤二：配置 ADC 引脚

步骤三：打开 ADC 通道并进行校准

步骤四：循环读取 ADC 采样值并转换为电压输出

### 核心代码

```c
// 初始化 ADC
uapi_pmu_control(PMU_CONTROL_MICLDO_POWER, PMU_CONTROL_POWER_ON);
uapi_pmu_ldo_set_voltage(PMU_LDO_ID_MICLDO, PMU_MICLDO_VSET_1V5);
uapi_adc_init(ADC_CLOCK_NONE);
adc_set_io(GADC_CHANNEL_0);
uapi_adc_open_channel(GADC_CHANNEL_0);
uapi_adc_power_en(AFE_GADC_MODE, true);
adc_calibration(AFE_GADC_MODE, true, true, true);

// 读取 ADC 值并转换为电压
while (1) {
    int gadc_value = uapi_adc_auto_sample(GADC_CHANNEL_0);
    osal_printk("gadc: %dmv\n", (gadc_value * ADC_TICK2VOL_REF_VOLTAGE_MV) >> GAFE_SAMPLE_VALUE_SIGN_BIT);
    osDelay(1000);
}
```

## PWM 示例实现

### 具体实现

步骤一：设置 GPIO 引脚为 PWM 模式

步骤二：初始化 PWM 模块

步骤三：配置 PWM 参数并打开通道

步骤四：启动 PWM 输出

### 核心代码

```c
// PWM 配置
pwm_config_t cfg_no_repeat = {
    200,  // high_time
    50,   // low_time
    0,    // offset_time
    0,    // cycles
    true  // repeat
};

uapi_pin_set_mode(CONFIG_PWM_PIN, HAL_PIO_PWM0);
uapi_pwm_init();

uint8_t channel = PWM_CHANNEL;
uapi_pwm_open(PWM_CHANNEL, &cfg_no_repeat);
uapi_pwm_set_group(PWM_GROUP_ID, &channel, 1);
uapi_pwm_start_group(PWM_GROUP_ID);
uapi_pwm_start(PWM_CHANNEL);
```

## I2C 示例实现

### 具体实现

步骤一：配置 I2C 引脚

步骤二：初始化 I2C 主机

步骤三：循环发送数据并接收从机响应

### 核心代码

```c
// I2C 初始化
app_i2c_init_pin();
uapi_i2c_master_init(CONFIG_I2C_MASTER_BUS_ID, baudrate, hscode);

// 发送和接收数据
uint8_t tx_buff[CONFIG_I2C_TRANSFER_LEN] = { 0 };
uint8_t rx_buff[CONFIG_I2C_TRANSFER_LEN] = { 0 };
i2c_data_t data = {
    .send_buf = tx_buff,
    .send_len = CONFIG_I2C_TRANSFER_LEN,
    .receive_buf = rx_buff,
    .receive_len = CONFIG_I2C_TRANSFER_LEN,
};

while (1) {
    uapi_i2c_master_write(CONFIG_I2C_MASTER_BUS_ID, dev_addr, &data);
    uapi_i2c_master_read(CONFIG_I2C_MASTER_BUS_ID, dev_addr, &data);
}
```

## SPI 示例实现

### 具体实现

步骤一：配置 SPI 引脚

步骤二：初始化 SPI 主机

步骤三：循环发送数据并接收从机响应

### 核心代码

```c
// SPI 初始化配置
spi_attr_t config = {
    .is_slave = false,
    .slave_num = SPI_SLAVE_NUM,
    .bus_clk = SPI_CLK_FREQ,
    .freq_mhz = SPI_FREQUENCY,
    .clk_polarity = SPI_CLK_POLARITY,
    .clk_phase = SPI_CLK_PHASE,
    .frame_format = SPI_FRAME_FORMAT,
    .frame_size = SPI_FRAME_SIZE_8,
    .tmod = SPI_TMOD,
};
uapi_spi_init(CONFIG_SPI_MASTER_BUS_ID, &config, &ext_config);

// 发送和接收数据
spi_xfer_data_t data = {
    .tx_buff = tx_data,
    .tx_bytes = CONFIG_SPI_TRANSFER_LEN,
    .rx_buff = rx_data,
    .rx_bytes = CONFIG_SPI_TRANSFER_LEN,
};

uapi_spi_master_write(CONFIG_SPI_MASTER_BUS_ID, &data, 0xFFFFFFFF);
uapi_spi_master_read(CONFIG_SPI_MASTER_BUS_ID, &data, 0xFFFFFFFF);
```

## DMA 示例实现

### 具体实现

步骤一：初始化 DMA 模块

步骤二：配置内存到内存传输参数

步骤三：执行单次传输或链表传输

步骤四：等待传输完成并验证数据

### 核心代码

```c
// DMA 初始化
dma_port_clock_enable();
uapi_dma_init();
uapi_dma_open();

// 配置传输参数
dma_ch_user_memory_config_t transfer_config = {
    .src = (uint32_t)(uintptr_t)g_app_dma_src_data,
    .dest = (uint32_t)(uintptr_t)g_app_dma_desc_data,
    .transfer_num = DMA_TRANSFER_WORD_NUM,
    .priority = DMA_TRANSFER_PRIORITY,
    .width = DMA_TRANSFER_WIDTH,
};

// 单次传输模式
uapi_dma_transfer_memory_single(&transfer_config, app_dma_trans_done_callback, (uintptr_t)NULL);

// 链表传输模式
uapi_dma_transfer_memory_lli(dma_channel, &transfer_config, app_dma_trans_done_callback);
uapi_dma_enable_lli(dma_channel, app_dma_trans_done_callback, (uintptr_t)NULL);
```

## 实验流程

- **步骤一**：在 `application/samples/peripheral` 文件夹下创建示例文件夹，名称为 `blinky`（以 Blinky 示例为例）

- **步骤二**：将 `vendor/BearPi-Pico_H2821E/peripheral/blinky` 文件夹内容拷贝到创建的示例文件夹中

- **步骤三**：在 `application/samples/peripheral/CMakeLists.txt` 中在最后 set(....) 的上一行加新增编译配置

  ```c
  if(DEFINED CONFIG_SAMPLE_SUPPORT_BLINKY)
    add_subdirectory_if_exist(blinky)
  endif()
  ```

- **步骤四**：在 `application/samples/peripheral/Kconfig` 中新增 Kconfig 配置

  ```
  config SAMPLE_SUPPORT_BLINKY
      bool
      prompt "Support BLINKY Sample."
      default n
      depends on ENABLE_PERIPHERAL_SAMPLE
      help
          This option means support BLINKY Sample.

  if SAMPLE_SUPPORT_BLINKY
  menu "BLINKY Sample Configuration"
      osource "application/samples/peripheral/blinky/Kconfig"
  endmenu
  endif()
  ```

- **步骤五**：点击系统配置图标，选择 KConfig，找到路径 `Application/Enable the Sample of peripheral`，在弹出框中选择对应示例（如 `support BLINKY Sample`），点击 Save 保存后关闭

- **步骤六**：点击 `build` 或 `rebuild` 编译

- **步骤七**：编译完成后，点击"端口设置传输方式选择 `serial`，端口选择 `comxxx`，点击 "程序加载" 按钮烧录

- **步骤八**：烧录出现 "Connecting, please reset device..." 字样时，复位开发板

- **步骤九**：观察实验现象

  - Blinky 示例：LED 灯循环闪烁
  - Button 示例：按下按键串口输出按键信息
  - ADC 示例：串口输出 ADC 采样电压值
  - PWM 示例：PWM 引脚输出脉冲信号
  - I2C 示例：I2C 主机与从机收发数据
  - SPI 示例：SPI 主机与从机收发数据
  - DMA 示例：DMA 内存传输完成提示
  - 其他示例对应各自功能输出

## 注意事项

- 不同示例使用的引脚不同，请参考 `Kconfig` 文件中的默认引脚配置
- I2C 和 SPI 示例需要配合对应的从机设备才能正常通信
- CAN 示例需要两台开发板通过 CAN 总线连接才能测试
- PDM 和 I2S 示例用于音频数据采集和传输
- 进行 DMA 链表传输时需要确保内存地址对齐
- 某些示例可能需要根据实际硬件配置修改引脚映射