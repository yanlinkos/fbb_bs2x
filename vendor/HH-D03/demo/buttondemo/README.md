# button

## 1.1 Introduction

**Function Description:** The buttons on the main board control the LED on/off.

**Software Overview:** GPIO pins can be controlled by software, enabling the CPU to read or write the level values of GPIO pins. The GPIO interrupt controller can detect signals from external devices by monitoring the GPIO pin status. These signals can trigger interrupt requests, so that the CPU can quickly respond to events from external devices.

**Hardware Overview:** Because the BS21E development board IO pins support function multiplexing (full routing, any IO pin can multiplex all functions), the core board and traffic light board are used. From the silkscreen on the traffic light board, it can be seen that Switch is connected to MOSI on the baseboard. Insert the core board IO 14 into the MOSI socket using a Dupont wire. The hardware setup requirements are shown in the figure:

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

Press the RESET button on the development board to reset it. The buttons on the main board can control the LED on/off

## 1.4 Interface Description

#### 1.4.1 uapi_gpio_set_dir()


| **Definition:** | errcode_t uapi_gpio_set_dir(pin_t pin, gpio_direction_t dir); |
| ------------ | ------------------------------------------------------------- |
| **Function:** | Sets the input/output direction of the GPIO |
| **Parameters:** | pin: io pin<br/>dir: input/output direction |
| **Return Value:** | ERROCODE_SUCC: success Other: failure |
| **Dependency:** | include\driver\gpio.h |

#### 1.4.2 uapi_gpio_set_isr_mode()


| Definition: | errcode_t uapi_gpio_set_isr_mode(pin_t pin, uint32_t trigger); |
| ------------ | -------------------------------------------------------------------------------------------------------------------- |
| **Function:** | HAL-layer GPIO sets interrupt mode |
| **Parameters:** | pin: io pin<br/>trigger: GPIO interrupt type: 1: rising edge interrupt; 2: falling edge interrupt; 3: both-edge interrupt; 4: low-level interrupt; 8: high-level interrupt |
| **Return Value:** | ERROCODE_SUCC: success Other: failure |
| **Dependency:** | include\driver\gpio.h |

#### 1.4.3 uapi_gpio_register_isr_func()


| **Definition:** | errcode_t uapi_gpio_register_isr_func(pin_t pin, uint32_t trigger, gpio_callback_t callback); |
| ------------ | ---------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Function:** | Registers the GPIO interrupt |
| **Parameters:** | pin: io pin<br/>trigger: GPIO interrupt type: 1: rising edge interrupt; 2: falling edge interrupt; 3: both-edge interrupt; 4: low-level interrupt; 8: high-level interrupt <br/>callback: pointer to the callback |
| **Return Value:** | ERROCODE_SUCC: success Other: failure |
| **Dependency:** | include\driver\gpio.h |

#### 1.4.4 uapi_gpio_enable_interrupt()


| **Definition:** | errcode_t uapi_gpio_enable_interrupt(pin_t pin); |
| ------------ | ------------------------------------------------ |
| **Function:** | Enables the interrupt of the specified GPIO port |
| **Parameters:** | pin: io pin |
| **Return Value:** | ERROCODE_SUCC: success Other: failure |
| **Dependency:** | include\driver\gpio.h |

## 1.5 Concrete Implementation

Step 1: Set the GPIO to input mode;

Step 2: Register the interrupt type, interrupt function, etc.;

Step 3: Depending on the interrupt type, determine whether the IO level has changed, to implement the button function

## 1.6 Experiment Flow

- Step 1: Create a new sample folder in the xxx\src\application\samples\peripheral folder. Right-click on peripheral, select ZeroScript-Sample, and create a Sample folder, for example named "buttondemo".

  ![image-20240205104416249](../../doc/media/beep/image-20240801170551992.png)
- Step 2: Copy the contents of the xxx\vendor\HH-D03\buttondemo directory into the "buttondemo" Sample folder created in Step 1.

  ![image-20240808155814777](../../doc/media/button/image-20240808155814777.png)
- Step 3: Add a new compilation case in the xxx\src\application\samples\peripheral\CMakeLists.txt file, as shown in the figure below (if you do not know where to add it, you can add it on the line above the "set(SOURCES "${SOURCES}" PARENT_SCOPE)" line).

  ![image-20240808155959504](../../doc/media/button/image-20240808155959504.png)
- Step 4: Add a new compilation case in the xxx\src\application\samples\peripheral\Kconfig file, as shown in the figure below (if you do not know where to add it, you can add it on the last line).

  ![image-20240808155947041](../../doc/media/button/image-20240808155947041.png)
- Step 5: Click the following icon, select KConfig, select the path "Application/Enable the Sample of peripheral", select "support BUTTON Sample" in the pop-up dialog, click Save, and close the dialog.

  <img src="../../doc/media/beep/image-20240801171406113.png" alt="image-20240801171406113" style="zoom: 67%;" /><img src="../../doc/media/beep/image-20240205105234692-17119401758316.png" alt="image-20240205105234692" style="zoom: 50%;" /><img src="../../doc/media/button/image-20240808160042906.png" alt="image-20240808160042906" style="zoom:67%;" />
- Step 6: Click "build" or "rebuild" to compile

  ![image-20250716163653427](../../doc/media/readme/image-20250716163653427.png)
- Step 7: The compilation is complete as shown in the figure below.

  ![image-20250307164622717](../../doc/media/button/image-20250307164622717.png)
- Step 8: In the HiSpark Studio tool, click the "Project Configuration" button, select "Program Loading", set the transfer mode to "serial", and select the port "comxxx". The com port is viewed in the device manager (if you cannot find the com port, refer to the Windows environment setup).

  ![image-20250716164922699](../../doc/media/readme/image-20250716164922699.png)
- Step 9: After configuration, click the tool's "Program Loading" button to burn/flash.

  ![image-20250716170835615](../../doc/media/readme/image-20250716170835615.png)
- Step 10: When the message "Connecting, please reset device..." appears, reset the development board and wait for the flashing to finish.

  ![image-20250317173240745](../../doc/media/tools/image-20240801174230202.png)
- Step 11: After the software is successfully flashed, press the RESET button on the development board to reset it. The buttons on the main board can control the LED on/off.
