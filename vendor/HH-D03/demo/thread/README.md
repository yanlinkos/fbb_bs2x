# thread/Thread

## 1.1 Introduction

**Function Description:** This experiment implements the creation of two task processes (tasks). Task 1 prints "This is Thread1---" once every 1 second, and task 2 prints "This is Thread2---" once every 500ms.

**Software Overview:** A task is the smallest running unit competing for system resources. A task can use or wait for system resources such as CPU and memory space, and runs independently of other tasks. The task module can provide users with multiple tasks, implement switching and communication between tasks, and help users manage business program flows.

- Supports multiple tasks; one task represents one thread.
- Tasks use a preemptive scheduling mechanism and also support round-robin scheduling.
- A high-priority task can preempt a low-priority task, and a low-priority task can only be scheduled after the high-priority task is blocked or finishes.
- There are 32 priorities [0, 31]. The highest priority is 0 and the lowest priority is 31. It is recommended that users use the priority range [10, 30]

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

Task 1 prints "This is Thread1----" once every 1 second, and task 2 prints "This is Thread2----" once every 500ms.

![image-20240418110736915](../../doc/media/thread/image-20240418110736915.png)

## 1.4 Interface Description

### 1.4.1 osal_kthread_lock()


| **Definition:** | void osal_kthread_lock(void); |
| ------------ | ---------------------------------------- |
| **Function:** | Disables system task scheduling |
| **Parameters:** | void type |
| **Return Value:** | none |
| **Dependency:** | kernel\osal\include\schedule\osal_task.h |

### 1.4.2 osal_kthread_create()


| Definition: | osal_task *osal_kthread_create(osal_kthread_handler handler, void *data, const char *name, unsigned int stack_size); |
| ------------ | -------------------------------------------------------------------------------------------------------------------- |
| **Function:** | Creates a task |
| **Parameters:** | handler: the function to be handled by the thread<br/>data: function handler data<br/>name: the displayed thread name<br/>stack_size: the size of the thread stack space |
| **Return Value:** | ERRCODE_SUCC: success Other: failure |
| **Dependency:** | kernel\osal\include\schedule\osal_task.h |

### 1.4.3 osal_kthread_set_priority()


| **Definition:** | int osal_kthread_set_priority(osal_task *task, unsigned int priority); |
| ------------ | ---------------------------------------------------------------------- |
| **Function:** | Sets the task priority |
| **Parameters:** | task: the thread whose priority is to be set<br/>priority: the priority to be set |
| **Return Value:** | OSAL_SUCCESS: success OSAL_FAILURE: failure |
| **Dependency:** | kernel\osal\include\schedule\osal_task.h |

### 1.4.4 osal_kthread_unlock()


| **Definition:** | void osal_kthread_unlock(void); |
| ------------ | ---------------------------------------- |
| **Function:** | Enables system task scheduling |
| **Parameters:** | void |
| **Return Value:** | none |
| **Dependency:** | kernel\osal\include\schedule\osal_task.h |

## 1.5 Concrete Implementation

Step 1: In xxx\src\kernel\liteos\liteos_v208.5.0\Huawei_LiteOS\.config, configure the number of tasks (default is 20). Configure LOSCFG_BASE_CORE_TSK_LIMIT, the maximum number of tasks supported by the system, according to user requirements;

Step 2: Lock the task with osal_kthread_lock to prevent high-priority task scheduling;

Step 3: Create the task with osThreadNew;

Step 4: Run the task app_run(), the overall entry point of the code;

Step 5: Unlock the task with osal_kthread_unlock to allow tasks to be scheduled according to priority;

## 1.6 Case Implementation

- Step 1: Create a new sample folder in the xxx\src\application\samples\peripheral folder. Right-click on peripheral, select "New Folder", and create a Sample folder, for example named "thread".

  ![image-70551992](../../doc/media/thread/image-20240801170551992.png)
- Step 2: Copy the "CMakeList.txt" and "thread_example.c" files from the xxx\vendor\HH-D03\thread directory into the "thread" Sample folder created in Step 1.

![image-20240229141239873](../../doc/media/thread/image-20240229141239873.png)

- Step 3: Add a new compilation case in the xxx\src\application\samples\peripheral\CMakeLists.txt file, as shown in the figure below (if you do not know where to add it, you can add it on the line above the "set(SOURCES "${SOURCES}" PARENT_SCOPE)" line).

![image-20240805105204337](../../doc/media/thread/image-20240805105204337.png)

- Step 4: Add a new compilation case in the xxx\src\application\samples\peripheral\Kconfig file, as shown in the figure below (if you do not know where to add it, you can add it on the last line).

  ![image-20240805105229940](../../doc/media/thread/image-20250311161913270.png)
- Step 5: Click the following icon, select KConfig, select the path "Application/Enable the Sample of peripheral", select "support THREAD Sample" in the pop-up dialog, click Save, and close the dialog.

  <img src="../../doc/media/beep/image-20240801171406113.png" alt="image-20240801171406113" style="zoom: 50%;" /><img src="../../doc/media/thread/image-20240205105234692-17119401758316.png" alt="image-20240205105234692" style="zoom: 50%;" /><img src="../../doc/media/thread/image-20240229141207010.png" alt="image-20240205105234692-17119401758316" style="zoom: 50%;" />
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
- Step 11: After the software is successfully flashed, press the RESET button on the development board to reset it. After the flashing is complete, task 1 prints "This is Thread1----" once every 1 second, and task 2 prints "This is Thread2" once every 500ms. The serial port prints the following information.

  ![image-20240418110732610](../../doc/media/thread/image-20240418110732610.png)
