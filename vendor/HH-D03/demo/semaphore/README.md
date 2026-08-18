## semaphore/Semaphore

## 1.1 Introduction

**Function Description:** This experiment implements synchronized acquisition of a semaphore between two tasks.

**Software Overview:** A semaphore is a mechanism for implementing communication between tasks, enabling synchronization between tasks or mutually exclusive access to critical resources. It is often used to assist a group of competing tasks in accessing critical resources. In a multi-task system, tasks need synchronization or mutual exclusion to protect critical resources, and the semaphore function can provide this support for users. Generally, the count value of a semaphore is used to represent the effective number of remaining mutually exclusive resources that can be occupied.

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

![image-20240401171259237](../../doc/media/semaphore/image-20240401171259237.png)

## 1.4 Interface Description

### 1.4.1 osal_sem_init()


| **Definition:** | int osal_sem_init(osal_semaphore *sem, int val); |
| ------------ | ------------------------------------------------ |
| **Function:** | Creates a semaphore |
| **Parameters:** | sem: semaphore object<br/>val: initial number of available semaphores |
| **Return Value:** | OSAL_SUCCESS: success Other: OSAL_FAILURE |
| **Dependency:** | kernel\osal\include\semaphore\osal_semaphore.h |

### 1.4.2 osal_sem_binary_sem_init()


| Definition: | int osal_sem_binary_sem_init(osal_semaphore *sem, int val); |
| ------------ | ----------------------------------------------------------- |
| **Function:** | Creates a binary semaphore |
| **Parameters:** | sem: semaphore object<br/>val: initial number of available semaphores, range [0, 1] |
| **Return Value:** | OSAL_SUCCESS: success Other: OSAL_FAILURE |
| **Dependency:** | kernel\osal\include\semaphore\osal_semaphore.h |

### 1.4.3 osal_sem_down_timeout()


| **Definition:** | int osal_sem_down_timeout(osal_semaphore *sem, unsigned int timeout); |
| ------------ | --------------------------------------------------------------------- |
| **Function:** | Blocking acquisition of the specified semaphore, unit: ms |
| **Parameters:** | sem: semaphore object<br/>timeout: timeout period |
| **Return Value:** | OSAL_SUCCESS: success Other: OSAL_FAILURE |
| **Dependency:** | kernel\osal\include\semaphore\osal_semaphore.h |

### 1.4.4 osal_sem_up()


| **Definition:** | void osal_sem_up(osal_semaphore *sem); |
| ------------ | ---------------------------------------------- |
| **Function:** | Releases the specified semaphore |
| **Parameters:** | sem: semaphore object |
| **Return Value:** | OSAL_SUCCESS: success Other: OSAL_FAILURE |
| **Dependency:** | kernel\osal\include\semaphore\osal_semaphore.h |

## 1.5 Concrete Flow

Step 1: Create a semaphore using osal_sem_init or osal_sem_binary_sem_init.

Step 2: Request the semaphore using osal_sem_down_timeout.

There are 3 request modes for a semaphore:

```
Non-blocking mode: A task needs to request a semaphore. If the number of tasks currently holding the semaphore has not reached the upper limit set for the semaphore, the request succeeds. Otherwise, it immediately returns a request failure. The timeout is set to 0.
```


```
Permanent blocking mode: A task needs to request a semaphore. If the number of tasks currently holding the semaphore has not reached the upper limit set for the semaphore, the request succeeds. Otherwise, the task enters the blocked state, and the system switches to the ready task with the highest priority to continue executing. After the task enters the blocked state, it will only resume execution when another task releases the semaphore. The timeout is set to HI_SYS_WAIT_FOREVER.
```


```
Timed blocking mode: A task needs to request a semaphore. If the number of tasks currently holding the semaphore has not reached the upper limit set for the semaphore, the request succeeds. Otherwise, the task enters the blocked state, and the system switches to the ready task with the highest priority to continue executing. After the task enters the blocked state, the blocked task will resume execution only if another task releases the semaphore before the specified timeout, or after the user-specified timeout has elapsed. The timeout is set to a reasonable value.
```


Step 3: Release the semaphore using osal_sem_up. If a task is blocked on the specified semaphore, wake up the first task in the semaphore's blocking queue. This task enters the ready state and is scheduled. If no task is blocked on the specified semaphore, the semaphore is released successfully.

Step 4: Delete the semaphore using osal_sem_destroy.

## 1.6 Experiment Flow

- Step 1: Create a new sample folder in the xxx\src\application\samples\peripheral folder. Right-click on peripheral, select "New Folder", and create a Sample folder, for example named "semaphore".

  ![image-70551992](../../doc/media/oled/image-20240801170551992-17228250453191.png)
- Step 2: Copy the contents of the xxx\vendor\HH-D03\semaphore directory into the "semaphore" Sample folder created in Step 1.

![image-20240401162502575](../../doc/media/semaphore/image-20240401162502575.png)

- Step 3: Add a new compilation case in the xxx\src\application\samples\peripheral\CMakeLists.txt file, as shown in the figure below (if you do not know where to add it, you can add it on the line above the "set(SOURCES "${SOURCES}" PARENT_SCOPE)" line).

  ![image-20240805103314839](../../doc/media/semaphore/image-20240805103314839.png)
- Step 4: Add a new compilation case in the xxx\src\application\samples\peripheral\Kconfig file, as shown in the figure below (if you do not know where to add it, you can add it on the last line).

  ![image-20240805103330471](../../doc/media/semaphore/image-20240805103330471.png)
- Step 5: Click the following icon, select KConfig, select the path "Application/Enable the Sample of peripheral", select "support SEMAPHORE Sample" in the pop-up dialog, click Save, and close the dialog.

  <img src="../../doc/media/beep/image-20240801171406113.png" alt="image-20240801171406113" style="zoom: 50%;" /><img src="../../doc/media/oled/image-20240205105234692-17119401758316-17228251215953.png" alt="image-20240205105234692" style="zoom: 50%;" /><img src="../../doc/media/semaphore/image-20240401162820928.png" alt="image-20240401162820928" style="zoom:67%;" />
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

  ![image-20240401171259237](../../doc/media/semaphore/image-20240401171259237.png)
