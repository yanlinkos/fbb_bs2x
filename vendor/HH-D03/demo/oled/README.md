# OLED

## 1.1 Introduction

**Function Description:** Displays "Hello World" on an SSD1306 OLED screen.

**Software Overview:** I2C is a serial communication protocol that allows multiple devices to be connected to a single bus. Each device connected to the bus has a unique address. Any device can act as either a master or a slave, but only one master is allowed at any given time.

**Hardware Overview:** Core board, OLED board. For the OLED datasheet, refer to the liquid crystal display (LCD) PDF in https://gitee.com/HiSpark/hi3861_hdu_iot_application/issues/I6WPSS?from=project-issue. On the BS21E development board, IO0 connects to the baseboard RX and IO1 connects to the baseboard TX. The hardware setup requirements are shown in the figure:

Refer to the [core board schematic](../../doc/hardware/HH-D03_原理图_V01.pdf), [OLED board schematic](../../doc/hardware/HiSpark_WiFi_IoT_OLED_VER.A.pdf), and [baseboard schematic](../../doc/hardware/HiSpark_WiFi_IoT_EXB_VER.A.pdf)

![image-20250424151926307](../../doc/media/oled/image-20250424151926307.png)

## 1.2 Constraints and Limitations

### 1.2.1 Chips and Development Boards Supporting Application Operation

  Development board supported by this example: HH-D03

### 1.2.2 Supported API Version, SDK Version

  Version number supported by this example: 1.0.15 and above

### Supported IDE Plugin Version

  IDE plugin version supported by this example: 1.0.1 and above;

## 1.3 Effect Preview

"Hello World" is displayed on the screen.

![image-20250424151931799](../../doc/media/oled/image-20250424151931799.png)

## 1.4 Interface Description

### 1.4.1 uapi_i2c_master_read()


| **Definition:** | errcode_t uapi_i2c_master_read(i2c_bus_t bus, uint16_t dev_addr, i2c_data_t *data); |
| ------------ | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| **Function:** | The master receives data from the target I2C slave. There are two methods: manual switching mode and automatic switching mode. Both methods are statically configured. The manual switching mode has the following three transfer modes, but they cannot be used simultaneously on the same bus |
| **Parameters:** | bus: I2C bus<br/>dev_addr: target slave address from which the master receives data <br/>data: data pointer for received data |
| **Return Value:** | ERRCODE_SUCC: success Other: failure |
| **Dependency:** | include\driver\i2c.h |

### 1.4.2 uapi_i2c_master_write()


| Definition: | errcode_t uapi_i2c_master_write(i2c_bus_t bus, uint16_t dev_addr, i2c_data_t *data); |
| ------------ | ------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| **Function:** | Writes data from the master to the slave. There are two methods: manual switching mode and automatic switching mode. Both methods are statically configured. The manual switching mode has the following three transfer modes, but they cannot be used simultaneously on the same bus |
| **Parameters:** | bus: I2C bus<br/>dev_addr: target slave address to which the master sends data <br/>data: data pointer for transmitted data |
| **Return Value:** | ERRCODE_SUCC: success Other: failure |
| **Dependency:** | include\driver\i2c.h |

### 1.4.3 uapi_i2c_master_init()


| **Definition:** | errcode_t uapi_i2c_master_init(i2c_bus_t bus, uint32_t baudrate, uint8_t hscode); |
| ------------ | ------------------------------------------------------------------------------------------------------------------------------------------ |
| **Function:** | Initializes this i2c as a master according to the specified parameters |
| **Parameters:** | bus: I2C bus<br/>baudrate: i2c baud rate <br/>hscode: i2c high-speed mode master code. Each master has its own unique master code. The valid range is 0~7, and it only needs to be configured in high-speed mode |
| **Return Value:** | ERRCODE_SUCC: success Other: failure |
| **Dependency:** | include\driver\i2c.h |

### 1.4.4 uapi_pin_set_mode()


| **Definition:** | errcode_t uapi_pin_set_mode(pin_t pin, pin_mode_t mode); |
| ------------ | -------------------------------------------------------- |
| **Function:** | Sets the pin multiplexing mode |
| **Parameters:** | pin: io<br/>mode: multiplexing mode |
| **Return Value:** | ERRCODE_SUCC: success Other: failure |
| **Dependency:** | include\driver\pinctrl.h |

### 1.4.5 ssd1306_SetCursor()


| **Definition:** | void ssd1306_SetCursor(uint8_t x, uint8_t y); |
| ------------ | --------------------------------------------- |
| **Function:** | Sets the string display position |
| **Parameters:** | x: x coordinate<br/>y: y coordinate |
| **Return Value:** | none |
| **Dependency:** | oled\ssd1306.h |

### 1.4.6 ssd1306_DrawString()


| **Definition:** | char ssd1306_DrawString(char *str, FontDef Font, SSD1306_COLOR color); |
| ------------ | ---------------------------------------------------------------------- |
| **Function:** | Sets the string to be output |
| **Parameters:** | str: string to be output<br/>Font: string size <br/>color: color |
| **Return Value:** | ERRCODE_SUCC: success Other: failure |
| **Dependency:** | oled\ssd1306.h |

### 1.4.7 ssd1306_UpdateScreen()


| **Definition:** | void ssd1306_UpdateScreen(void); |
| ------------ | -------------------------------- |
| **Function:** | Displays the string on the screen |
| **Parameters:** | none |
| **Return Value:** | none |
| **Dependency:** | oled\ssd1306.h |

## 1.5 Concrete Implementation

Step 1: Initialize the I2C device;

Step 2: After I2C communication is normal, initialize the OLED;

Step 3: Send data according to the protocol requirements in the datasheet

## 1.6 Experiment Flow

- Step 1: Create a new sample folder in the xxx\src\application\samples\peripheral folder. Right-click on peripheral, select "New Folder", and create a Sample folder, for example named "oled".

  ![image-70551992](../../doc/media/oled/image-20240801170551992-17228250453191.png)
- Step 2: Copy the contents of the xxx\vendor\HH-D03\oled directory into the "oled" Sample folder created in Step 1.

  ![image-20240415171655322](../../doc/media/oled/image-20240415171655322.png)
- Step 3: Add a new compilation case in the xxx\src\application\samples\peripheral\CMakeLists.txt file, as shown in the figure below (if you do not know where to add it, you can add it on the line above the "set(SOURCES "${SOURCES}" PARENT_SCOPE)" line).

  ![image-20240805095756111](../../doc/media/oled/image-20240805095756111.png)
- Step 4: Add a new compilation case in the xxx\src\application\samples\peripheral\Kconfig file, as shown in the figure below (if you do not know where to add it, you can add it on the last line).

  ![image-20240805095816487](../../doc/media/oled/image-20240805095816487.png)
- Step 5: Click the following icon, select KConfig, select the path "Application/Enable the Sample of peripheral", select "support OLED Sample" in the pop-up dialog, click Save, and close the dialog.

  <img src="../../doc/media/beep/image-20240801171406113.png" alt="image-20240801171406113" style="zoom: 67%;" /><img src="../../doc/media/oled/image-20240205105234692-17119401758316.png" alt="image-20240205105234692" style="zoom: 50%;" /><img src="../../doc/media/oled/image-20240415171718967.png" alt="image-20240415171718967" style="zoom:67%;" />
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
- Step 11: After the software is successfully flashed, press the RESET button on the development board to reset it. "Hello World!!!" is displayed on the screen.

  ![image-20250424151937751](../../doc/media/oled/image-20250424151937751.png)
