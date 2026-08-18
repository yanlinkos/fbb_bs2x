## usbdemo

## 1.1 Introduction

USB_HID is a standard device class of USB devices. It belongs to human-machine interaction devices, including mice, keyboards, etc., and is mainly used for interaction between humans and computers. It can also be used to transmit data and control devices. For example, a video display device may use the HID interface for software control of brightness and contrast, while using the traditional video interface to transmit the data to be displayed. A USB amplifier can use real-time transmission to play voice, while using the HID interface to control the volume, etc. HID devices can be used as low-speed, full-speed, and high-speed devices. Because HID devices require timely response to user input, their transmission mode usually uses interrupts.

**Hardware Overview:** Core board, baseboard. Insert the core board main board into the baseboard. Looking at the left side of the baseboard, from the main board silkscreen you can see that the core board's TXD1 corresponds to the baseboard TX. Find the TX hardware interface on the right side of the baseboard, and use a Dupont wire (jumper cap) to connect TX and RX. Looking at the left side of the baseboard, from the main board silkscreen you can see that the core board's RXD1 corresponds to the baseboard RX. Find the RX hardware interface on the right side of the baseboard, and use a Dupont wire (jumper cap) to connect TX and RX. Normally, when two UART devices (A and B) communicate, the hardware wiring is: board A's TX connects to board B's RX, and board A's RX connects to board B's TX. Here, because the hardware quantity is limited, a single board is used for verification; the single board's TX and RX are connected with a Dupont wire or jumper cap. The hardware setup requirements are shown in the figure:

**Hardware Overview:** [Core board schematic](../../doc/hardware/HH-D03_原理图_V01.pdf). The hardware setup requirements are shown in the figure:

![image-20250401173022316](../../doc/media/usbdemo/image-20250401173022316.png)

## 1.2 Constraints and Limitations

### 1.2.1 Chips and Development Boards Supporting Application Operation

  Development board supported by this example: HH-D03

### 1.2.2 Supported API Version, SDK Version

  Version number supported by this example: 1.0.15 and above

### Supported IDE Plugin Version

  IDE plugin version supported by this example: 1.0.1 and above;

## 1.3 Effect Preview



## 1.4 Interface Description

### 1.4.1 usb_init()


| **Definition:** | uint32_t usb_init(controller_type ctype, device_type dtype) |
| ------------ | ----------------------------------------------------------- |
| **Function:** | Initializes the USB |
| **Parameters:** | ctype: controller type<br/>dtype: device type |
| **Return Value:** | ERRCODE_SUCC: success Other: failure |
| **Dependency:** | include\driver\usb\implementation\usb_init.h |

### 1.4.2 usb_deinit()


| **Definition:** | uint32_t usb_deinit(void); |
| ------------ | -------------------------------------------- |
| **Function:** | De-initializes the USB |
| **Parameters:** | |
| **Return Value:** | ERRCODE_SUCC: success Other: failure |
| **Dependency:** | include\driver\usb\implementation\usb_init.h |

### 1.4.3 usbd_set_device_info()


| **Definition:** | uint32_t usbd_set_device_info(device_type dtype,const struct device_string *str_manufacturer,const struct device_string *str_product,const struct device_string *str_serial_number,struct device_id dev_id) |
| ------------ | ------------------------------------------------------------ |
| **Function:** | Sets device VID, PID, and string descriptor information |
| **Parameters:** | dtype: device type<br />str_manufacturer: manufacturer string information<br />str_product: product string information<br />str_serial_number: serial number string information<br />dev_id: VID, PID, and device version number |
| **Return Value:** | ERRCODE_SUCC: success Other: failure |
| **Dependency:** | include\driver\usb\implementation\usb_init.h |

### 1.4.4 fhid_send_data()


| **Definition:** | size_t fhid_send_data(uint8_t report_index, const char *buf, size_t buflen); |
| ------------ | ------------------------------------------------------------ |
| **Function:** | Data sending |
| **Parameters:** | |
| **Return Value:** | ERRCODE_SUCC: success Other: failure |
| **Dependency:** | include\driver\usb\implementation\usb_init.h |

### 1.4.5 fhid_recv_data()


| **Definition:** | int32_t uapi_uart_read(uart_bus_t bus, const uint8_t *buffer, uint32_t length, uint32_t timeout); |
| ------------ | ------------------------------------------------------------ |
| **Function:** | Data receiving |
| **Parameters:** | |
| **Return Value:** | ERRCODE_SUCC: success Other: failure |
| **Dependency:** | include\driver\usb\implementation\usb_init.h |

## 1.5 Concrete Implementation

Step 1: Configure the report descriptor information, and set the report data format and function.

Step 2: First configure the device's VID, PID, device version number, and manufacturer, product, and serial number string information.

Step 3: Initialize the USB. The device type is DEV_HID.

Step 4: Send the mouse data.

## 1.6 Experiment Flow

- Step 1: Create a new sample folder in the xxx\src\application\samples\peripheral folder. Right-click on peripheral, select "New Folder", and create a Sample folder, for example named "uartdemo".

  ![image-70551992](../../doc/media/usbdemo/image-20240801170551992.png)
- Step 2: Copy the contents of the xxx\vendor\HiHope_NearLink_DK_WS63E_V03\usbdemo directory into the "usbdemo" Sample folder created in Step 1.

  ![image-20250401192718838](../../doc/media/usbdemo/image-20250401192718838.png)
- Step 3: Add a new compilation case in the xxx\src\application\samples\peripheral\CMakeLists.txt file, as shown in the figure below (if you do not know where to add it, you can add it on the line above the "set(SOURCES "${SOURCES}" PARENT_SCOPE)" line).

  ![image-20250401192751708](../../doc/media/usbdemo/image-20250401192751708.png)
- Step 4: Add a new compilation case in the xxx\src\application\samples\peripheral\Kconfig file, as shown in the figure below (if you do not know where to add it, you can add it on the last line).

  ![image-20250401192804144](../../doc/media/usbdemo/image-20250401192804144.png)
- Step 5: Click the following icon, select KConfig, select the path "Application/Enable the Sample of peripheral", select "support UARTDEMO Sample" in the pop-up dialog, click Save, and close the dialog.

  <img src="../../doc/media/beep/image-20240801171406113.png" alt="image-20240801171406113" style="zoom: 67%;" /><img src="../../doc/media/beep/image-20240205105234692-17119401758316.png" alt="image-20240205105234692" style="zoom: 50%;" />![image-20250401192821409](../../doc/media/usbdemo/image-20250401192821409.png)
- Step 6: Click "build" or "rebuild" to compile

  ![image-20250716163653427](../../doc/media/readme/image-20250716163653427.png)
- Step 7: The compilation is complete as shown in the figure below.

  ![image-20240801165456569](../../doc/media/tools/image-20250307164622717.png)
- Step 8: In the HiSpark Studio tool, click the "Project Configuration" button, select "Program Loading", set the transfer mode to "serial", and select the port "comxxx". The com port is viewed in the device manager (if you cannot find the com port, refer to the Windows environment setup).

  ![image-20250716164922699](../../doc/media/readme/image-20250716164922699.png)
- Step 9: After configuration, click the tool's "Program Loading" button to burn/flash.

  ![image-20250716170835615](../../doc/media/readme/image-20250716170835615.png)
- Step 10: When the message "Connecting, please reset device..." appears, reset the development board and wait for the flashing to finish.

  ![image-20240801174230202](../../doc/media/tools/image-20240801174230202.png)
- Step 11: After the software is successfully flashed, press the RESET button on the development board to reset it. After the flashing is complete, the development board can be used as a mouse through the buttons on the board.
