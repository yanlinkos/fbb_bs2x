# beep

## 1.1 Introduction

**Function Description:** Use PWM to control the buzzer sound.

**Software Overview:** PWM is the abbreviation for Pulse Width Modulation. By adjusting the change in the duty cycle, changes in the signal, energy, etc., are regulated. The duty cycle refers to the percentage of time within one cycle during which the signal is at a high level, relative to the entire signal cycle.

**Hardware Overview:** Because the BS21E development board IO pins support function multiplexing (full routing, any IO pin can multiplex all functions). From the board silkscreen, it can be seen that the BEEP buzzer of the traffic light board is connected to A9 on the baseboard. Insert the core board IO 9 into the A9 socket using a Dupont wire. The hardware setup requirements are shown in the figure:

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

  The buzzer sounds

## 1.4 Interface Description

#### 1.4.1 uapi_pwm_open()

| **Definition:** | errcode_t uapi_pwm_open(uint8_t channel, const pwm_config_t *cfg); |
| ------------ | ------------------------------------------------------------ |
| **Function:** | Opens a PWM device with the specified configuration |
| **Parameters:** | channel: the pwm device to use<br/>cfg: the configuration information of the PWM device |
| **Return Value:** | ERROCODE_SUCC: success Other: failure |
| **Dependency:** | include\driver\pwm.h |

#### 1.4.2 uapi_pwm_close()

| Definition: | errcode_t uapi_pwm_close(uint8_t channel); |
| ------------ | ------------------------------------------ |
| **Function:** | Closes the specified PWM. |
| **Parameters:** | channel: the pwm device to use |
| **Return Value:** | ERROCODE_SUCC: success Other: failure |
| **Dependency:** | include\driver\pwm.h |

#### 1.4.3 uapi_pwm_register_interrupt()

| **Definition:** | errcode_t uapi_pwm_register_interrupt(uint8_t channel, pwm_callback_t callback); |
| ------------ | ------------------------------------------------------------ |
| **Function:** | Registers an interrupt callback for the PWM |
| **Parameters:** | channel: the pwm device to use <br/>callback: callback function |
| **Return Value:** | ERROCODE_SUCC: success Other: failure |
| **Dependency:** | include\driver\pwm.h |

#### 1.4.4 uapi_pwm_start()

| **Definition:** | errcode_t uapi_pwm_start(uint8_t channel); |
| ------------ | ------------------------------------------ |
| **Function:** | Starts the PWM |
| **Parameters:** | channel: the pwm device to use |
| **Return Value:** | ERROCODE_SUCC: success Other: failure |
| **Dependency:** | include\driver\pwm.h |

#### 1.4.5 uapi_pwm_set_group()

| **Definition:** | errcode_t uapi_pwm_set_group(uint8_t group, uint16_t channel_id); |
| ------------ | ------------------------------------------------------------ |
| **Function:** | Groups PWM channels |
| **Parameters:** | group: PWM group<br/>channel_id: the IDs of all channels assigned to the same group; each bit in channel_id corresponds to one channel |
| **Return Value:** | ERROCODE_SUCC: success Other: failure |
| **Dependency:** | include\driver\pwm.h |

## 1.5 Concrete Implementation

  Step 1: Initialize the PWM and configure the PWM parameters;

  Step 2: Open the specified PWM device

## 1.6 Experiment Flow

- Step 1: Create a new sample folder in the xxx\src\application\samples\peripheral folder. Right-click on peripheral, select "New Folder", and create a Sample folder, for example named "beep".

  ![image-70551992](../../doc/media/beep/image-20240801170551992.png)

- Step 2: Copy the contents of the xxx\vendor\HiHope_NearLink_DK_WS63E_V03\beep directory into the "beep" Sample folder created in Step 1.

  ![image-20240415150723600](../../doc/media/beep/image-20240415150723600.png)

* Step 3: Add a new compilation case in the xxx\src\application\samples\peripheral\CMakeLists.txt file, as shown in the figure below (if you do not know where to add it, you can add it on the line above the "set(SOURCES "${SOURCES}" PARENT_SCOPE)" line).

  ![image-20240801171056148](../../doc/media/beep/image-20240801171056148.png)
  
* Step 4: Add a new compilation case in the xxx\src\application\samples\peripheral\Kconfig file, as shown in the figure below (if you do not know where to add it, you can add it on the last line).

  ![image-20240801180202806](../../doc/media/beep/image-20240801180202806.png)


- Step 5: Click the following icon, select "System Configuration", select the path "Application/Enable the Sample of peripheral", select "support BEEP Sample" in the pop-up dialog, click Save, and close the dialog.

  <img src="../../doc/media/beep/image-20240801171406113.png" alt="image-20240801171406113" style="zoom: 67%;" /><img src="../../doc/media/beep/image-20240205105234692-17119401758316.png" alt="image-20240205105234692" style="zoom: 50%;" /><img src="../../doc/media/beep/image-20240415150847116.png" alt="image-20240415150847116" style="zoom: 50%;" />

- Step 6: Click "build" or "rebuild" to compile

  ![image-20250716163653427](../../doc/media/readme/image-20250716163653427.png)

- Step 7: The compilation is complete as shown in the figure below.

  ![image-20250307164622717](../../doc/media/tools/image-20250307164622717.png)

- Step 8: In the HiSpark Studio tool, click the "Project Configuration" button, select "Program Loading", set the transfer mode to "serial", and select the port "comxxx". The com port is viewed in the device manager (if you cannot find the com port, refer to the Windows environment setup).

  ![image-20250716164922699](../../doc/media/readme/image-20250716164922699.png)
  
- Step 9: After configuration, click the tool's "Program Loading" button to burn/flash.

  ![image-20250716170835615](../../doc/media/readme/image-20250716170835615.png)

- Step 10: When the message "Connecting, please reset device..." appears, reset the development board and wait for the flashing to finish.

  ![image-20240801174230202](../../doc/media/tools/image-20240801174230202.png)

* Step 11: After flashing is complete, the buzzer on the traffic light board sounds.
