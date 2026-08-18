## uartdemo

## 1.1 Introduction

**Function Description:** In this experiment, GPIO 15 and GPIO 16 are multiplexed as UART functions. The board's TX and RX are connected with a jumper cap, implementing data sending and receiving in polling mode, and data receiving and sending in interrupt mode.

**Software Overview:** The GPIO pin outputs high and low level states.

**Hardware Overview:** Core board, baseboard. Insert the core board main board into the baseboard. Looking at the left side of the baseboard, from the main board silkscreen you can see that the core board's TXD1 corresponds to the baseboard TX. Find the TX hardware interface on the right side of the baseboard, and use a Dupont wire (jumper cap) to connect TX and RX. Looking at the left side of the baseboard, from the main board silkscreen you can see that the core board's RXD1 corresponds to the baseboard RX. Find the RX hardware interface on the right side of the baseboard, and use a Dupont wire (jumper cap) to connect TX and RX. Normally, when two UART devices (A and B) communicate, the hardware wiring is: board A's TX connects to board B's RX, and board A's RX connects to board B's TX. Here, because the hardware quantity is limited, a single board is used for verification; the single board's TX and RX are connected with a Dupont wire or jumper cap. The hardware setup requirements are shown in the figure:

  Refer to the [core board schematic](../../doc/hardware/HH-D03_原理图_V01.pdf)

<img src="../../doc/media/uartdemo/image-20250401153218775.png" alt="image-20240418162118123" style="zoom:80%;" />

## 1.2 Constraints and Limitations

### 1.2.1 Chips and Development Boards Supporting Application Operation

  Development board supported by this example: HH-D03

### 1.2.2 Supported API Version, SDK Version

  Version number supported by this example: 1.0.15 and above

### Supported IDE Plugin Version

  IDE plugin version supported by this example: 1.0.1 and above;

## 1.3 Effect Preview

The serial port cyclically prints "hello uart1" every 5 seconds.

![image-20240418163011967](../../doc/media/uartdemo/image-20240418163011967.png)

## 1.4 Interface Description

### 1.4.1 uapi_pin_set_mode()


| **Definition:** | errcode_t uapi_pin_set_mode(pin_t pin, pin_mode_t mode); |
| ------------ | -------------------------------------------------------- |
| **Function:** | Sets the pin multiplexing mode |
| **Parameters:** | pin: io<br/>mode: multiplexing mode |
| **Return Value:** | ERRCODE_SUCC: success Other: failure |
| **Dependency:** | include\driver\pinctrl.h |

### 1.4.2 uapi_uart_init()


| **Definition:** | errcode_t uapi_uart_init(uart_bus_t bus, const uart_pin_config_t *pins, const uart_attr_t *attr, const uart_extra_attr_t *extra_attr, uart_buffer_config_t *uart_buffer_config); |
| ------------ | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Function:** | Initializes the specified serial port |
| **Parameters:** | bus: serial port number<br/>pins: the pins used in the UART, including TX, RX, RTS, and CTS<br/>attr: the basic configuration parameters of the UART<br/>extra_attr: the advanced configuration parameters of the UART<br/>uart_buffer_config: specifies the UART receive buffer |
| **Return Value:** | ERRCODE_SUCC: success Other: failure |
| **Dependency:** | include\driver\uart.h |

### 1.4.3 uapi_uart_deinit()


| **Definition:** | errcode_t uapi_uart_deinit(uart_bus_t bus); |
| ------------ | ------------------------------------------- |
| **Function:** | De-initializes the specified serial port |
| **Parameters:** | bus: serial port number |
| **Return Value:** | ERRCODE_SUCC: success Other: failure |
| **Dependency:** | include\driver\uart.h |

### 1.4.4 uapi_uart_write()


| **Definition:** | int32_t uapi_uart_write(uart_bus_t bus, const uint8_t *buffer, uint32_t length, uint32_t timeout); |
| ------------ | -------------------------------------------------------------------------------------------------------- |
| **Function:** | Sends data to the opened UART using direct sending |
| **Parameters:** | bus: serial port number<br/>buffer: the data buffer to be sent <br/>length: the length of the data buffer to be sent <br/>timeout: timeout period |
| **Return Value:** | ERRCODE_SUCC: success Other: failure |
| **Dependency:** | include\driver\uart.h |

### 1.4.5 uapi_uart_write_int()


| **Definition:** | errcode_t uapi_uart_write_int(uart_bus_t bus, const uint8_t *buffer, uint32_t length,void *params, uart_tx_callback_t finished_with_buffer_func); |
| ------------ | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Function:** | Sends data to the opened UART using interrupt mode; the callback function is called when the data transmission is complete |
| **Parameters:** | bus: serial port number<br/>buffer: the data buffer to be sent <br/>length: the length of the data buffer to be sent <br/>params: the parameters passed to the transmit-complete callback function<br/>finished_with_buffer_func: the callback function called when data transmission is complete |
| **Return Value:** | ERRCODE_SUCC: success Other: failure |
| **Dependency:** | include\driver\uart.h |

### 1.4.6 uapi_uart_read()


| **Definition:** | int32_t uapi_uart_read(uart_bus_t bus, const uint8_t *buffer, uint32_t length, uint32_t timeout); |
| ------------ | ---------------------------------------------------------------------------------------------------------- |
| **Function:** | Reads data from the UART |
| **Parameters:** | bus: serial port number<br/>buffer: the buffer storing the received data <br/>length: the length of the buffer storing the received data <br/>timeout: timeout period |
| **Return Value:** | ERRCODE_SUCC: success Other: failure |
| **Dependency:** | include\driver\uart.h |

### 1.4.7 uapi_uart_register_rx_callback()


| **Definition:** | errcode_t uapi_uart_register_rx_callback(uart_bus_t bus, uart_rx_condition_t condition, uint32_t size, uart_rx_callback_t callback); |
| ------------ | ------------------------------------------------------------------------------------------------------------------------------------------------ |
| **Function:** | Registers a receive callback function, which is triggered based on the trigger condition and size. |
| **Parameters:** | bus: serial port number<br/>condition: the condition that triggers the callback <br/>size: if the trigger condition involves data length, this parameter indicates the required data length <br/>callback: the callback function for receiving data |
| **Return Value:** | ERRCODE_SUCC: success Other: failure |
| **Dependency:** | include\driver\uart.h |

## 1.5 Concrete Implementation

Step 1: Set the GPIO to be multiplexed as the uart function.

Step 2: Configure the uart parameters, such as baud rate, data bits, stop bits, parity, etc.

Step 3: Initialize the uart device.

Step 4: Write data through the uapi_uart_write function.

Step 5: Read data through the uapi_uart_read function.

## 1.6 Experiment Flow

- Step 1: Create a new sample folder in the xxx\src\application\samples\peripheral folder. Right-click on peripheral, select "New Folder", and create a Sample folder, for example named "uartdemo".

  ![image-70551992](../../doc/media/uartdemo/image-20240801170551992.png)
- Step 2: Copy the contents of the xxx\vendor\HiHope_NearLink_DK_WS63E_V03\uartdemo directory into the "uartdemo" Sample folder created in Step 1.

  ![image-20240418162506313](../../doc/media/uartdemo/image-20240418162506313.png)
- Step 3: Add a new compilation case in the xxx\src\application\samples\peripheral\CMakeLists.txt file, as shown in the figure below (if you do not know where to add it, you can add it on the line above the "set(SOURCES "${SOURCES}" PARENT_SCOPE)" line).

  ![image-20240805111300643](../../doc/media/uartdemo/image-20250401152631378.png)
- Step 4: Add a new compilation case in the xxx\src\application\samples\peripheral\Kconfig file, as shown in the figure below (if you do not know where to add it, you can add it on the last line).

  ![image-20240805111322155](../../doc/media/uartdemo/image-20250401152813400.png)
- Step 5: Click the following icon, select KConfig, select the path "Application/Enable the Sample of peripheral", select "support UARTDEMO Sample" in the pop-up dialog, click Save, and close the dialog.

  <img src="../../doc/media/beep/image-20240801171406113.png" alt="image-20240801171406113" style="zoom: 50%;" /><img src="../../doc/media/beep/image-20240205105234692-17119401758316.png" alt="image-20240205105234692" style="zoom: 50%;" /><img src="../../doc/media/uartdemo/image-20240418162620764.png" alt="image-20240418162620764" style="zoom:67%;" />
- Step 6: Click "build" or "rebuild" to compile

  ![image-20250716163653427](../../doc/media/readme/image-20250716163653427.png)
- Step 7: The compilation is complete as shown in the figure below.

  ![image-20240801165456569](../../doc/media/tools/image-20250307164622717.png)
- Step 8: In the HiSpark Studio tool, click the "Project Configuration" button, select "Program Loading", set the transfer mode to "serial", and select the port "comxxx". The com port is viewed in the device manager (if you cannot find the com port, refer to the Windows environment setup).

  ![image-20250716164922699](../../doc/media/readme/image-20250716164922699.png)
- Step 9: After configuration, click the tool's "Program Loading" button to burn/flash.

  ![image-20250716170835615](../../doc/media/readme/image-20250716170835615.png)
- Step 10: When the message "Connecting, please reset device..." appears, reset the development board and wait for the flashing to finish.

  ![image-20240801174230202](../../doc/media/beep/image-20240801174230202.png)
- Step 11: After the software is successfully flashed, press the RESET button on the development board to reset it. After the flashing is complete, the serial port cyclically prints "hello uart1" every 5 seconds.

  ![image-20240418163011967](../../doc/media/uartdemo/image-20240418163011967.png)
