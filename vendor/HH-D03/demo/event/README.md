## event/Event

## 1.1 Introduction

**Function Description:** This experiment implements synchronization between tasks. In a multi-task environment, tasks often need synchronized operations. A wait is a synchronization, and events can provide one-to-many and many-to-many synchronization operations.

**Software Overview:** When writing events, write the specified event type to the specified event; multiple event types can be written at once. When reading events, the read mode can be selected. For "all" events, all event types in the read mask must have occurred for the read to succeed. For "any" events, the read succeeds if any of the event types in the read mask has occurred.

**Hardware Overview:** [Core board schematic](../../doc/hardware/HH-D03_原理图_V01.pdf). The hardware setup requirements are shown in the figure:

<img src="../../doc/media/tools/image-20250422184625049.png" alt="image-20240226173007100" style="zoom: 67%;" />

## 1.2 Constraints and Limitations

### 1.2.1 Chips and Development Boards Supporting Application Operation

  Development board supported by this example: HH-D03

### 1.2.2 Supported API Version, SDK Version

  Version number supported by this example: 1.0.15 and above

### Supported IDE Plugin Version

  IDE plugin version supported by this example: 1.0.1 and above;

## 1.3 Effect Preview

![image-20240227100118269](../../doc/media/event/image-20240227100118269.png)

## 1.4 Interface Description

### 1.4.1 osal_event_init()


| **Definition:** | int osal_event_init(osal_event *event_obj); |
| ------------ | ------------------------------------------- |
| **Function:** | Initializes an event control module |
| **Parameters:** | event_obj: event |
| **Return Value:** | OSAL_SUCCESS: success Other: OSAL_FAILURE |
| **Dependency:** | kernel\osal\include\event\osal_event.h |

### 1.4.2 osal_event_read()


| Definition: | int osal_event_read(osal_event *event_obj, unsigned int mask, unsigned int timeout_ms, unsigned int mode); |
| ------------ | ---------------------------------------------------------------------------------------------------------- |
| **Function:** | Blocking read of the specified event type; the waiting timeout is a relative time, unit: ms |
| **Parameters:** | event_obj: event<br/>mask: event mask <br/>timeout_ms: timeout period<br/>mode: event type |
| **Return Value:** | OSAL_SUCCESS: success Other: OSAL_FAILURE |
| **Dependency:** | kernel\osal\include\event\osal_event.h |

### 1.4.3 osal_event_write()


| **Definition:** | int osal_event_write(osal_event *event_obj, unsigned int mask); |
| ------------ | --------------------------------------------------------------- |
| **Function:** | Writes the specified event type |
| **Parameters:** | event_obj: event<br/>mask: event mask |
| **Return Value:** | OSAL_SUCCESS: success Other: OSAL_FAILURE |
| **Dependency:** | kernel\osal\include\event\osal_event.h |

### 1.4.4 osal_event_clear()


| **Definition:** | int osal_event_clear(osal_event *event_obj, unsigned int mask); |
| ------------ | --------------------------------------------------------------- |
| **Function:** | Clears the specified event type |
| **Parameters:** | event_obj: event<br/>mask: event mask |
| **Return Value:** | OSAL_SUCCESS: success Other: OSAL_FAILURE |
| **Dependency:** | kernel\osal\include\event\osal_event.h |

### 1.4.5 osal_event_destroy()


| **Definition:** | errcode_t uapi_timer_deinit(void); |
| ------------ | ----------------------------------------- |
| **Function:** | Destroys the specified event control block |
| **Parameters:** | void type |
| **Return Value:** | OSAL_SUCCESS: success Other: OSAL_FAILURE |
| **Dependency:** | kernel\osal\include\event\osal_event.h |

## 1.5 Concrete Implementation

Step 1: Call the event initialization interface osal_event_init to initialize the event waiting queue.

Step 2: Write the event with osal_event_write and configure the event mask type.

Step 3: Read the event with osal_event_read and select the read mode.

Step 4: Clear the event with osal_event_clear to clear the specified event type

## 1.6 Experiment Flow

- Step 1: Create a new sample folder in the xxx\src\application\samples\peripheral folder. Right-click on peripheral, select "New Folder", and create a Sample folder, for example named "event".

  ![image-70551992](../../doc/media/event/image-20240801170551992.png)
- Step 2: Copy the contents of the xxx\vendor\HH-D03\event directory into the "event" Sample folder created in Step 1.

  ![image-20240401150957191](../../doc/media/event/image-20240401150957191.png)
- Step 3: Add a new compilation case in the xxx\src\application\samples\peripheral\CMakeLists.txt file, as shown in the figure below (if you do not know where to add it, you can add it on the line above the "set(SOURCES "${SOURCES}" PARENT_SCOPE)" line).

  ![image-20240802173325308](../../doc/media/event/image-20240802173325308.png)
- Step 4: Add a new compilation case in the xxx\src\application\samples\peripheral\Kconfig file, as shown in the figure below (if you do not know where to add it, you can add it on the last line).

  ![image-20240802173352589](../../doc/media/event/image-20240802173352589.png)
- Step 5: Click the following icon, select KConfig, select the path "Application/Enable the Sample of peripheral", select "support EVENT Sample" in the pop-up dialog, click Save, and close the dialog.

  <img src="../../doc/media/beep/image-20240801171406113.png" alt="image-20240801171406113" style="zoom: 50%;" /><img src="../../doc/media/beep/image-20240205105234692-17119401758316.png" alt="image-20240205105234692" style="zoom: 50%;" /><img src="../../doc/media/event/image-20240401150805884.png" alt="image-20240401150805884" style="zoom:50%;" />
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
- Step 11: After the software is successfully flashed, press the RESET button on the development board to reset it. After the flashing is complete, the serial port prints the following information.

  ![image-20240227100118269](../../doc/media/event/image-20240227100118269.png)
