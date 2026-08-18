## message

## 1.1 Introduction

**Function Description:** This experiment implements the creation of a queue and two tasks. Task 1 calls the sending interface to send messages, and task 2 receives messages through the receiving interface.

**Software Overview:** A queue, also called a message queue, is a data structure commonly used for communication between tasks. It implements receiving messages of variable length from tasks or interrupts, and the receiver reads messages according to the message ID. The system uses the queue data structure to implement asynchronous communication between tasks, with the following characteristics:

- Messages are queued in a first-in-first-out manner and support asynchronous read/write operation.
- Both read and write queues support a timeout mechanism.
- The message types sent are agreed upon by the communicating parties, and messages of different lengths (not exceeding the maximum queue node size) are allowed.
- One task can receive and send messages from any message queue.
- Multiple tasks can receive and send messages from the same message queue.
- When the queue is no longer used, if the memory was dynamically allocated, it needs to be recycled through the memory release function.

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

![image-20240401174326792](../../doc/media/message/image-20240401174326792.png)

## 1.4 Interface Description

### 1.4.1 osal_msg_queue_creat()


| **Definition:** | int osal_msg_queue_create(const char *name, unsigned short queue_len, unsigned long *queue_id, unsigned int flags,unsigned short max_msgsize); |
| ------------ | ------------------------------------------------------------ |
| **Function:** | Creates a message queue |
| **Parameters:** | name: message queue name<br/>queue_len: queue length. Value range is [1,0xffff]<br/>queue_id: the ID of the successfully created queue control structure<br/>flags: queue mode<br/>max_msgsize: node size. Value range is [1,0xffff]. Note that the node should be neither too large nor too small |
| **Return Value:** | OSAL_SUCCESS: success Other: OSAL_FAILURE |
| **Dependency:** | kernel\osal\include\msgqueue\osal_msgqueue.h |

### 1.4.2 osal_msg_queue_delete()


| Definition: | void osal_msg_queue_delete(unsigned long queue_id); |
| ------------ | --------------------------------------------------- |
| **Function:** | Deletes a message queue |
| **Parameters:** | queue_id: the ID of the successfully created queue control structure |
| **Return Value:** | OSAL_SUCCESS: success Other: OSAL_FAILURE |
| **Dependency:** | kernel\osal\include\msgqueue\osal_msgqueue.h |

### 1.4.3 osal_msg_queue_write_copy()


| **Definition:** | int osal_msg_queue_write_copy(unsigned long queue_id, void *buffer_addr, unsigned int buffer_size, unsigned int timeout); |
| ------------ | ------------------------------------------------------------------------------------------------------------------------------------ |
| **Function:** | Sends a message to the tail of the queue |
| **Parameters:** | queue_id: the ID of the successfully created queue control structure<br/>buffer_addr: the starting address storing the data to be written<br/>buffer_size: the length of data to write<br/>timeout: timeout period |
| **Return Value:** | OSAL_SUCCESS: success Other: OSAL_FAILURE |
| **Dependency:** | kernel\osal\include\msgqueue\osal_msgqueue.h |

### 1.4.4 osal_msg_queue_read_copy()


| **Definition:** | int osal_msg_queue_read_copy(unsigned long queue_id, void *buffer_addr, unsigned int *buffer_size,unsigned int timeout); |
| ------------ | ---------------------------------------------------------------------------------------------------------------------------- |
| **Function:** | Blocking reception of messages, unit: ms |
| **Parameters:** | queue_id: the ID of the successfully created queue control structure<br/>buffer_addr: the starting address for reading data<br/>buffer_size: the length of data to read<br/>timeout: timeout period |
| **Return Value:** | OSAL_SUCCESS: success Other: OSAL_FAILURE |
| **Dependency:** | kernel\osal\include\msgqueue\osal_msgqueue.h |

## 1.5 Concrete Implementation

Step 1: Create a queue and two tasks. Task 1 calls the sending interface to send messages, and task 2 receives messages through the receiving window.

Step 2: Create task 1 and task 2 with osal_kthread_creat.

Step 3: Create a message queue with osal_msg_queue_creat.

Step 4: In task 1, call osal_msg_queue_write_copy to send messages.

Step 5: In task 2, call osal_msg_queue_read_copy to receive messages.

## 1.6 Experiment Flow

- Step 1: Create a new sample folder in the xxx\src\application\samples\peripheral folder. Right-click on peripheral, select "New Folder", and create a Sample folder, for example named "message".

  ![image-70551992](../../doc/media/message/image-20240801170551992.png)
- Step 2: Copy the contents of the xxx\vendor\HH-D03\message directory into the "message" Sample folder created in Step 1.

  ![image-20240401184805703](../../doc/media/message/image-20240401184805703.png)
- Step 3: Add a new compilation case in the xxx\src\application\samples\peripheral\CMakeLists.txt file, as shown in the figure below (if you do not know where to add it, you can add it on the line above the "set(SOURCES "${SOURCES}" PARENT_SCOPE)" line).

  ![image-20240805093251683](../../doc/media/message/image-20240805093251683.png)
- Step 4: Add a new compilation case in the xxx\src\application\samples\peripheral\Kconfig file, as shown in the figure below (if you do not know where to add it, you can add it on the last line).

  ![image-20240805093329786](../../doc/media/message/image-20240805093329786.png)
- Step 5: Click the following icon, select KConfig, select the path "Application/Enable the Sample of peripheral", select "support A6_KERNAL_MESSAGE Sample" in the pop-up dialog, click Save, and close the dialog.

  <img src="../../doc/media/beep/image-20240801171406113.png" alt="image-20240801171406113" style="zoom: 50%;" /><img src="../../doc/media/message/image-20240205105234692-17119401758316.png" alt="image-20240205105234692" style="zoom: 50%;" /><img src="../../doc/media/message/image-20240401174241614.png" alt="image-20240401174241614" style="zoom:67%;" />
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

  ![image-20240401174326792](../../doc/media/message/image-20240401174326792.png)
