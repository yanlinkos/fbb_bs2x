## trafficlight

## 1.1 Introduction

**Function Description:** The red, yellow, and green lights on the traffic light board blink, and the buttons can control the buzzer sound.

**Software Overview:** The GPIO pin outputs high and low level states.

**Hardware Overview:** Core board, traffic light board. From the silkscreen on the traffic light board, it can be seen that RED is connected to D10 on the baseboard. D10 on the left side of the baseboard corresponds to GPIO 7 on the core board; GREEN is connected to A11 on the baseboard. A11 on the left side of the baseboard corresponds to GPIO 11 on the core board; YELLOW is connected to A12 on the baseboard. A12 on the left side of the baseboard corresponds to GPIO 12 on the core board; Switch is connected to MOSI on the baseboard. MOSI on the left side of the baseboard corresponds to GPIO14 on the core board; the BEEP buzzer is connected to A9 on the baseboard. A9 on the left side of the baseboard corresponds to GPIO 9 on the core board. The hardware setup requirements are shown in the figure:

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

The red, yellow, and green lights on the traffic light board blink, and the buttons can control the buzzer sound.

<img src="../../doc/media/beep/image-20250317171949255-17454042737691.png" alt="image-20250317171949255" style="zoom:50%;" />

## 1.4 Interface Description

### 1.4.1 uapi_pwm_init()


| **Definition:** | errcode_t uapi_pwm_init (void) |
| ------------ | --------------------------------- |
| **Function:** | Initializes the PWM. |
| **Parameters:** | none |
| **Return Value:** | ERRCODE_SUCC: success Other: failure |
| **Dependency:** | include\driver\pwm.h |

### 1.4.2 uapi_pwm_open()


| Definition: | errcode_t uapi_pwm_open(uint8_t channel, const pwm_config_t *cfg); |
| ------------ | ------------------------------------------------------------------ |
| **Function:** | Opens a PWM device with the specified configuration |
| **Parameters:** | channel: the PWM device to use<br/>cfg: the configuration information of the PWM device |
| **Return Value:** | ERRCODE_SUCC: success Other: failure |
| **Dependency:** | include\driver\pwm.h |

### 1.4.3 uapi_pwm_set_group()


| **Definition:** | errcode_t uapi_pwm_set_group(uint8_t group, uint16_t channel_id); |
| ------------ | ----------------------------------------------------------------------------------------------------- |
| **Function:** | Groups PWM channels |
| **Parameters:** | group: PWM group<br/>channel_id: the IDs of all channels assigned to the same group; each bit in channel_id corresponds to one channel |
| **Return Value:** | ERRCODE_SUCC: success Other: failure |
| **Dependency:** | include\driver\pwm.h |

### 1.4.4 uapi_pwm_start()


| **Definition:** | errcode_t uapi_pwm_start(uint8_t channel); |
| ------------ | ------------------------------------------ |
| **Function:** | Starts the PWM |
| **Parameters:** | channel: the PWM device to use |
| **Return Value:** | ERRCODE_SUCC: success Other: failure |
| **Dependency:** | include\driver\pwm.h |

### 1.4.5 uapi_pwm_close()


| **Definition:** | errcode_t uapi_pwm_close(uint8_t channel); |
| ------------ | ------------------------------------------ |
| **Function:** | Closes the specified PWM. |
| **Parameters:** | channel: the PWM device to use. |
| **Return Value:** | ERRCODE_SUCC: success Other: failure |
| **Dependency:** | include\driver\pwm.h |

### 1.4.6 uapi_pin_set_mode()


| **Definition:** | errcode_t uapi_pin_set_mode(pin_t pin, pin_mode_t mode); |
| ------------ | -------------------------------------------------------- |
| **Function:** | Sets the pin multiplexing mode |
| **Parameters:** | pin: io<br/>mode: multiplexing mode |
| **Return Value:** | ERRCODE_SUCC: success Other: failure |
| **Dependency:** | include\driver\pinctrl.h |

### 1.4.7 uapi_gpio_set_dir()


| **Definition:** | errcode_t uapi_gpio_set_dir(pin_t pin, gpio_direction_t dir); |
| ------------ | ------------------------------------------------------------- |
| **Function:** | Sets the input/output direction of the GPIO |
| **Parameters:** | pin: io<br/>dir: input/output direction |
| **Return Value:** | ERRCODE_SUCC: success Other: failure |
| **Dependency:** | include\driver\gpio.h |

### 1.4.8 uapi_gpio_register_isr_func()


| **Definition:** | errcode_t uapi_gpio_register_isr_func(pin_t pin, uint32_t trigger, gpio_callback_t callback); |
| ------------ | ----------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Function:** | Registers the GPIO interrupt |
| **Parameters:** | pin: io<br/>trigger: GPIO interrupt type: 1: rising edge interrupt; 2: falling edge interrupt; 3: both-edge interrupt; 4: low-level interrupt; 8: high-level interrupt <br/>callback: pointer to the callback |
| **Return Value:** | ERRCODE_SUCC: success Other: failure |
| **Dependency:** | include\driver\gpio.h |

## 1.5 Concrete Implementation

Step 1: Set the GPIO to output mode;

Step 2: Initialize the PWM and configure the PWM parameters;

Step 3: Set the GPIO output to high or low;

Step 4: Open the specified PWM device;

Step 5: Toggle the GPIO output level state

## 1.6 Experiment Flow

- Step 1: Create a new sample folder in the xxx\src\application\samples\peripheral folder. Right-click on peripheral, select "New Folder", and create a Sample folder, for example named "trafficlight".

  ![image-70551992](../../doc/media/beep/image-20240801170551992.png)
- Step 2: Copy the contents of the xxx\vendor\HiHope_NearLink_DK_WS63E_V03\traffic_demo directory into the "trafficlight" Sample folder created in Step 1.

![image-20240418152414639](../../doc/media/trafficlight/image-20240418152414639.png)

- Step 3: Add a new compilation case in the xxx\src\application\samples\peripheral\CMakeLists.txt file, as shown in the figure below (if you do not know where to add it, you can add it on the line above the "set(SOURCES "${SOURCES}" PARENT_SCOPE)" line).

  ![image-20250401144603017](../../doc/media/trafficlight/image-20240805110207997.png)
- Step 4: Add a new compilation case in the xxx\src\application\samples\peripheral\Kconfig file, as shown in the figure below (if you do not know where to add it, you can add it on the last line).

  ![image-20250401144508525](../../doc/media/trafficlight/image-20240805110216395.png)
- Step 5: Click the following icon, select KConfig, select the path "Application/Enable the Sample of peripheral", select "support TRAFFICLIGHT Sample" in the pop-up dialog, click Save, and close the dialog.

  <img src="../../doc/media/beep/image-20240801171406113.png" alt="image-20240801171406113" style="zoom: 67%;" /><img src="../../doc/media/beep/image-20240205105234692-17119401758316.png" alt="image-20240205105234692" style="zoom: 50%;" /><img src="../../doc/media/trafficlight/image-20240418152441142.png" alt="image-20240418152441142" style="zoom:67%;" />
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
- Step 11: After the software is successfully flashed, press the RESET button on the development board to reset it. After the flashing is complete, the lights on the board blink, and the buzzer sound can be controlled by the buttons.

  <img src="../../doc/media/beep/image-20250317171949255-17454042737691.png" alt="image-20250317171949255" style="zoom:50%;" />
