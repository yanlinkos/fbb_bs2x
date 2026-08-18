# SLE Traffic Light

## 1.1 Introduction

**Function Description:** Two SparkLink development boards. The SparkLink Server side sends command information to the SparkLink client side to control the red light on the client's traffic light board to turn on/off.

**Hardware Overview:** Core board. The hardware setup requirements are shown in the figure:

  Refer to the [traffic light board schematic](../../doc/hardware/HiSpark_WiFi_IoT_SSL_VER.A.pdf), [baseboard schematic](../../doc/hardware/HiSpark_WiFi_IoT_EXB_VER.A.pdf), and [core board schematic](../../doc/hardware/HH-D03_原理图_V01.pdf)

<img src="../../doc/media/beep/image-20250317171949255-17454042737691.png" alt="image-20250317171949255" style="zoom:50%;" />

## 1.2 Constraints and Limitations

### 1.2.1 Chips and Development Boards Supporting Application Operation

  Development board supported by this example: HH-D03

### 1.2.2 Supported API Version, SDK Version

  Version number supported by this example: 1.0.15 and above

### Supported IDE Plugin Version

  IDE plugin version supported by this example: 1.0.1 and above;

## 1.3 Effect Preview

Client side receives data:

![image](../../doc/media/sle_led/image.png)

Every 500 milliseconds, the Server sends messages through the SparkLink connection to control the on/off status of the 3 LEDs on the client's traffic light board.

## 1.4 Interface Description

#### 1.4.1 enable_sle()


| **Definition:** | errcode_t enable_sle(void); |
| ------------ | ---------------------------------------------------------- |
| **Function:** | Enables the SLE protocol stack |
| **Parameters:** | |
| **Return Value:** | ERROCODE_SUCC: success Other: failure |
| **Dependency:** | include\middleware\services\bts\sle\sle_device_discovery.h |

#### 1.4.2 sle_connect_remote_device()


| Definition: | errcode_t sle_connect_remote_device(const sle_addr_t *addr); |
| ------------ | ------------------------------------------------------------ |
| **Function:** | Sends a connection request |
| **Parameters:** | addr: address |
| **Return Value:** | ERROCODE_SUCC: success Other: failure |
| **Dependency:** | include\middleware\services\bts\sle\sle_connection_manager. |

#### 1.4.3 sle_update_connect_param()


| **Definition:** | errcode_t sle_update_connect_param(sle_connection_param_update_t *params); |
| ------------ | -------------------------------------------------------------------------- |
| **Function:** | Sends a connection parameter update request |
| **Parameters:** | params: connection parameters |
| **Return Value:** | ERROCODE_SUCC: success Other: failure |
| **Dependency:** | include\middleware\services\bts\sle\sle_connection_manager.h |

#### 1.4.4 sle_pair_remote_device()


| **Definition:** | errcode_t sle_pair_remote_device(const sle_addr_t *addr); |
| ------------ | ------------------------------------------------------------ |
| **Function:** | Sends a pairing request |
| **Parameters:** | addr: address |
| **Return Value:** | ERROCODE_SUCC: success Other: failure |
| **Dependency:** | include\middleware\services\bts\sle\sle_connection_manager.h |

## Development Flow

Terminal Node:

Step 1 Call enable_sle to turn on the SLE switch.

Step 2 Call sle_announce_seek_register_callbacks to register the device announce and device discovery callback functions.

Step 3 Call sle_set_local_addr to set the local device address.

Step 4 Call sle_set_local_name to set the local device name.

Step 5 Call sle_set_announce_param to set the device announce parameters.

Step 6 Call sle_set_announce_data to set the device announce data.

Step 7 Call sle_start_announce to start device announcing.

Grant Node: Step 1 Call enable_sle to turn on the SLE switch.

Step 2 Call sle_announce_seek_register_callbacks to register the device announce and device discovery callback functions.

Step 3 Call sle_set_local_addr to set the local device address.

Step 4 Call sle_set_local_name to set the local device name.

Step 5 Call sle_set_seek_param to set the device discovery parameters.

Step 6 Call sle_start_seek to start device discovery, and obtain the information of the device currently announcing in the callback function.

# 1. Usage Introduction

* Step 1: Create a new sample folder in the xxx\src\application\samples\peripheral folder. Right-click on peripheral, select "New Folder", and create a Sample folder, for example named "sle_led".

  ![image-70551992](../../doc/media/beep/image-20240801170551992.png)
* Step 2: Copy the contents of the xxx\vendor\HH-D03\sle_led directory into the "sle_led" Sample folder created in Step 1.

  ![image-20240403100728566](../../doc/media/sle_led/image-20240403100728566.png)
* Step 3: Add a new compilation case in the xxx\src\application\samples\peripheral\CMakeLists.txt file, as shown in the figure below (if you do not know where to add it, you can add it on the line above the "set(SOURCES "${SOURCES}" PARENT_SCOPE)" line).

  ![image_20240808184434](../../doc/media/sle_led/image_20240808184434.png)
* Step 4: Add a new compilation case in the xxx\src\application\samples\peripheral\Kconfig file, as shown in the figure below (if you do not know where to add it, you can add it on the last line).

  ![image_20240808184555](../../doc/media/sle_led/image_20240808184555.png)
* Step 5: Click the following icon, select "System Configuration", select the path "Application/Enable the Sample of peripheral". If you choose to compile the server side, select "support SLE_LED_SERVER Sample"; if you choose to compile the client side, select "support SLE_LED_CLIENT Sample". (You need to prepare two development boards, select different compilation options, and flash different images.)

  ![image_20240808164723](../../doc/media/sle_led/image_20240808164723.png)
  ![image_20240808164731](../../doc/media/sle_led/image_20240808164731.png)

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

* Step 11: Reset the two development boards. After waiting for the connection to be established, the client's traffic signal lights blink continuously.
