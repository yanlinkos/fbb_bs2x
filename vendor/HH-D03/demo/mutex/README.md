# mutex/Mutex

## 1.1 Introduction

**Function Description:** This experiment implements a mechanism to prevent two tasks from accessing the same shared resource at the same time.

**Software Overview:** A mutex lock, also called a mutex semaphore, is a special binary semaphore used to implement exclusive processing of shared resources. At any time, a mutex lock has only two states: locked, when a task holds it, that task obtains ownership of the mutex lock; unlocked, when the task releases it, the mutex lock is unlocked and the task loses ownership of the mutex lock. When one task holds the mutex lock, other tasks can no longer unlock or hold the mutex lock. In a multi-task environment, there are often application scenarios where multiple tasks compete for the same shared resource. A mutex lock can be used to protect shared resources and thereby implement exclusive access.

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

![image-20240401153146328](../../doc/media/mutex/image-20240401153146328.png)

## 1.4 Interface Description

### 1.4.1 osal_mutex_init()


| **Definition:** | int osal_mutex_init(osal_mutex *mutex); |
| ------------ | ----------------------------------------- |
| **Function:** | Initializes a mutex lock |
| **Parameters:** | mutex: mutex object |
| **Return Value:** | OSAL_SUCCESS: success Other: OSAL_FAILURE |
| **Dependency:** | kernel\osal\include\mutex\osal_mutex.h |

### 1.4.2 osal_mutex_destroy()


| Definition: | void osal_mutex_destroy(osal_mutex *mutex); |
| ------------ | ------------------------------------------- |
| **Function:** | Deletes the specified mutex lock |
| **Parameters:** | mutex: mutex object |
| **Return Value:** | OSAL_SUCCESS: success Other: OSAL_FAILURE |
| **Dependency:** | kernel\osal\include\mutex\osal_mutex.h |

### 1.4.3 osal_mutex_lock_timeout()


| **Definition:** | int osal_mutex_lock_timeout(osal_mutex *mutex, unsigned int timeout); |
| ------------ | --------------------------------------------------------------------- |
| **Function:** | Blocking acquisition of the mutex lock, unit: ms |
| **Parameters:** | mutex: mutex object<br/>timeout: timeout period |
| **Return Value:** | OSAL_SUCCESS: success Other: OSAL_FAILURE |
| **Dependency:** | kkernel\osal\include\mutex\osal_mutex.h |

### 1.4.4 osal_event_unlock()


| **Definition:** | void osal_mutex_unlock(osal_mutex *mutex); |
| ------------ | ------------------------------------------ |
| **Function:** | Releases the specified mutex lock |
| **Parameters:** | mutex: mutex object |
| **Return Value:** | OSAL_SUCCESS: success Other: OSAL_FAILURE |
| **Dependency:** | kernel\osal\include\mutex\osal_mutex.h |

## 1.5 Concrete Implementation

Step 1: Task example_task_mux creates a mutex lock, locks task scheduling, creates two tasks example_mutex_task1 and example_mutex_task2 (example_mutex_task2 has higher priority than example_mutex_task1), and unlocks task scheduling.

Step 2: example_mutex_task2 is scheduled, permanently requests the mutex lock, then the task sleeps for 100ms, example_mutex_task2 is suspended, and example_mutex_task1 is woken up.

Step 3: example_mutex_task1 requests the mutex lock with a wait time of 10ms. Because the mutex lock is still held by example_mutex_task2, example_mutex_task1 is suspended. After 10ms, if the mutex lock is not obtained, example_mutex_task1 is woken up and tries to request the mutex lock with a permanent wait, then example_mutex_task1 is suspended.

Step 4: After 100ms, example_mutex_task2 wakes up, releases the mutex lock; after example_mutex_task1 is scheduled and runs, it releases the mutex lock.

Step 5: After example_mutex_task1 finishes, the mutex lock is deleted after 300ms.

## 1.6 Experiment Flow

- Step 1: Create a new sample folder in the xxx\src\application\samples\peripheral folder. Right-click on peripheral, select "New Folder", and create a Sample folder, for example named "mutex".

  ![image-70551992](../../doc/media/message/image-20240801170551992-17228219869641.png)
- Step 2: Copy the contents of the xxx\vendor\HH-D03\mutex directory into the "mutex" Sample folder created in Step 1.

  ![image-20240401155957848](../../doc/media/mutex/image-20240401155957848.png)
- Step 3: Add a new compilation case in the xxx\src\application\samples\peripheral\CMakeLists.txt file, as shown in the figure below (if you do not know where to add it, you can add it on the line above the "set(SOURCES "${SOURCES}" PARENT_SCOPE)" line).

  ![image-20240805094616844](../../doc/media/mutex/image-20240805094616844.png)
- Step 4: Add a new compilation case in the xxx\src\application\samples\peripheral\Kconfig file, as shown in the figure below (if you do not know where to add it, you can add it on the last line).

  ![image-20240805094733456](../../doc/media/mutex/image-20240805094733456.png)
- Step 5: Click the following icon, select KConfig, select the path "Application/Enable the Sample of peripheral", select "support MUTEX Sample" in the pop-up dialog, click Save, and close the dialog.

  <img src="../../doc/media/mutex/image-20240801171406113.png" alt="image-20240801171406113" style="zoom: 50%;" /><img src="../../doc/media/beep/image-20240205105234692-17119401758316.png" alt="image-20240205105234692" style="zoom: 50%;" /><img src="../../doc/media/mutex/image-20240401154052776.png" alt="image-20240401154052776" style="zoom:50%;" />
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

  ![image-20240401153146328](../../doc/media/mutex/image-20240401153146328.png)
