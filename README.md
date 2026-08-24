# fbb_bs2x Development Guide

## Introduction

  The fbb_bs2x repository is the solution source code repository for SparkLink BS20/BS21E/BS22, based on the LiteOS system. It is mainly used for application scenarios such as mice, keyboards, ranging, and consumer electronics. This SDK package is built from the unified development platform FBB (Family Big Box, unified development framework, unified API). Applications developed on this platform can be easily ported to other SparkLink solutions, effectively lowering the threshold for developers, shortening development cycles, and supporting developers in rapidly developing SparkLink products. Online software documentation link: https://docs.hisilicon.com/repos/fbb_bs2x/zh-CN/master/

## Specifications

| BS2X Series Specifications Comparison | BS20  | BS21E  | BS22   |
| ---------------- | ----- | ------ | ------ |
| CPU Clock        | 64M   | 64M    | 64M    |
| FLASH            | 1M    | 1M     | 1M     |
| RAM              | 128K  | 160K   | 160K   |
| SLE              | 1K    | 2K     | 4K     |
| Air Interface Rate | 4Mbps | 12Mbps | 12Mbps |
| USB              | Supported | Supported | Supported |
| Wired Report Rate | 1K   | 4K     | 8K     |
| Ranging          | Supported | Supported | Supported |

## Release-notes

[BS2X-1.0.17](docs/zh-CN/software/Release notes/BS2X-1.0.17.md)

## Directory Description

| Directory | Description |
| ------ | ----------- |
| docs   | Stores software information manuals, an IO multiplexing relationship table, and user guide manuals to help users quickly understand the BS21E series |
| src    | Development access SDK source code package, based on which users perform secondary development |
| tools  | Development tool and environment setup guides to help users build the development environment |
| vendor | Stores cooperative manufacturers' development board hardware and software materials, including case code, hardware schematics, and case development guide documents |

## Example Tutorials

HH-D03, HH-D121 development board example tutorials

| Primary Category | Subcategory | Application Example | Application Example | Application Example |
| :----------- | --------------- | ----------- | ---------- | --------------------------------------------- |
| **Basic Drivers** | **GPIO** | [LED Light On Example](vendor/HH-D03/demo/led) | [Button Detection](vendor/HH-D03/demo/buttondemo) | [Traffic Light Example](vendor/HH-D03/demo/trafficlight) |
|              | **UART** | [Serial Communication Example](vendor/HH-D03/demo/uartdemo) | | |
|              | **I2C** | [0.96-inch OLED Screen Driver Example](vendor/HH-D03/demo/oled) | [Environment Monitoring](vendor/HH-D03/demo/environment) | |
|              | **PWM** | [Buzzer Sound](vendor/HH-D03/demo/beep) | [RGB Light Example](vendor/HH-D03/demo/pwm_rgb_led) | |
|              | **watchdog** | [Watchdog Example](src/application/samples/peripheral/watchdog) | | |
|              | **i2s** | [I2S Communication Example](src/application/samples/peripheral/i2s) | [I2S+DMA Communication](src/application/samples/peripheral/i2s_dma) | |
|              | **keyscan** | [Keyboard Scan](src/application/samples/peripheral/keyscan) | | |
|              | **spi** | [SPI Communication Example](src/application/samples/peripheral/spi) | | |
|              | **timer** | [Timer Example](src/application/samples/peripheral/timer) | | |
| **Operating System** | **Thread** | [Task Scheduling Use Example](vendor/HH-D03/demo/thread) | | |
|              | **Event** | [Event Use Example](vendor/HH-D03/demo/event) | | |
|              | **Mutex** | [Mutex Use Example](vendor/HH-D03/demo/mutex) | | |
|              | **MessgeQueue** | [Message Queue Use Example](vendor/HH-D03/demo/message) | | |
| **usb**      | **usb** | [usb Communication Example](vendor/HH-D03/demo/usb_demo) | [USB Keyboard](src/application/samples/products/usb_keyboard) | |
| **SparkLink** | **SLE** | [sle_uart Serial Transparent Transmission](src/application/samples/products/sle_uart) | [SLE Ranging](vendor/HH-D03/demo/sle_measure_dis) | |
| **Bluetooth** | **BLE** | [Bluetooth Serial Transparent Transmission](src/application/samples/products/ble_uart) | [Bluetooth Keyboard](src/application/samples/products/ble_keyboard) | |


BearPi-Pico_H2821E development board example tutorials

| Primary Category | Subcategory | Application Example | Application Example | Application Example |
| :----------- | --------------- | ----------- | ---------- | --------------------------------------------- |
| **Basic Drivers** | **GPIO** | [LED Light On Example](https://www.bearpi.cn/core_board/bearpi/pico/h2821E/software/study/1.GPIO%E7%82%B9%E4%BA%AELED%E7%81%AF%E6%B5%8B%E8%AF%95.html) | [Button Detection](https://www.bearpi.cn/core_board/bearpi/pico/h2821E/software/study/2.GPIO%E6%8C%89%E9%94%AE%E4%B8%AD%E6%96%AD%E6%B5%8B%E8%AF%95.html) | |
|              | **UART** | [Serial Communication Example](https://www.bearpi.cn/core_board/bearpi/pico/h2821E/software/study/10.UART%E6%95%B0%E6%8D%AE%E4%BC%A0%E8%BE%93%E8%BE%93%E5%87%BA%E6%B5%8B%E8%AF%95.html) | | |
|              | **I2C** | [I2C Communication Example](https://www.bearpi.cn/core_board/bearpi/pico/h2821E/software/study/5.I2C%E4%B8%BB%E4%BB%8E%E6%95%B0%E6%8D%AE%E4%BC%A0%E8%BE%93%E6%B5%8B%E8%AF%95.html) | | |
|              | **PWM** | [PWM Output Example](https://www.bearpi.cn/core_board/bearpi/pico/h2821E/software/study/9.PWM%E8%BE%93%E5%87%BA%E6%B5%8B%E8%AF%95.html) | | |
|              | **watchdog** | [Watchdog Example](src/application/samples/peripheral/watchdog) | | |
|              | **i2s** | [I2S Communication Example](https://www.bearpi.cn/core_board/bearpi/pico/h2821E/software/study/6.I2S%E4%B8%BB%E4%BB%8E%E6%95%B0%E6%8D%AE%E4%BC%A0%E8%BE%93%E6%B5%8B%E8%AF%95.html) | [I2S+DMA Communication](src/application/samples/peripheral/i2s_dma) | |
|              | **keyscan** | [Keyboard Scan](https://www.bearpi.cn/core_board/bearpi/pico/h2821E/software/study/8.KEYSCAN%E7%9F%A9%E9%98%B5%E9%94%AE%E7%9B%98%E6%89%AB%E6%8F%8F%E6%B5%8B%E8%AF%95.html) | | |
|              | **spi** | [SPI Communication Example](https://www.bearpi.cn/core_board/bearpi/pico/h2821E/software/study/7.SPI%E4%B8%BB%E4%BB%8E%E6%95%B0%E6%8D%AE%E4%BC%A0%E8%BE%93%E6%B5%8B%E8%AF%95.html) | | |
|              | **timer** | [Timer Example](src/application/samples/peripheral/timer) | | |
| **usb**      | **usb** | [USB Keyboard](src/application/samples/products/usb_keyboard) | | |
| **SparkLink** | **SLE** | [sle_uart Serial Transparent Transmission](https://www.bearpi.cn/core_board/bearpi/pico/h2821E/software/SLE%E4%B8%B2%E5%8F%A3%E9%80%8F%E4%BC%A0%E6%B5%8B%E8%AF%95.html) | [SLE Ranging](src/application/samples/products/sle_measure_dis) | |
| **Bluetooth** | **BLE** | [Bluetooth Serial Transparent Transmission](https://www.bearpi.cn/core_board/bearpi/pico/h2821E/software/BLE%E4%B8%B2%E5%8F%A3%E9%80%8F%E4%BC%A0%E6%B5%8B%E8%AF%95.html) | [Bluetooth Keyboard](src/application/samples/products/ble_keyboard) | |

## Contributing

- Refer to [Community Contribution Guide](https://gitcode.com/HiSpark/docs/blob/master/contribute/%E7%A4%BE%E5%8C%BA%E5%8F%82%E4%B8%8E%E8%B4%A1%E7%8C%AE%E6%8C%87%E5%8D%97.md)
