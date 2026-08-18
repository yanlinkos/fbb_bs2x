# Version 1.0.18 Description File

## 1. Improvements Over the Previous Baseline Version

| No. | Module | Problem Description | Remark |
| --- | ------- | --------------------------------------- | --- |
| 01  | PLT | With extremely low probability, the chip fails to start normally and hangs in Flashboot, reporting "Flashboot Jump Failed!" | The Flashboot of SDK 1.0.16/17 versions needs to be updated |
| 02  | PLT | A very small number of boards experience a sleep-wake disconnection issue | |
| 03  | SLE | Supports setting the broadcast interval to greater than 20 seconds | |
| 04  | SLE | The tablet interoperability test case "client supports error-type handle handling for responsive writes" fails; HID is not affected | |

## 2. Newly Added, Modified, and Deleted Functional Features Compared to the Previous Baseline Version

### 2.1 New Functional Features

This section describes all newly added functional features between the current version and the previous baseline version.

| No. | Brief Description | Detailed Description | Modified Module |
| --- | ------------------------- | ----------------------------------------------- | ------ |
| 01  | Supports SLE direct connection at 500Hz | Based on the 2821, the reporting rate for devices directly connected via SparkLink (such as tablets) can reach 500Hz. | SLE |
| 02  | Database open | The Database is opened/available with the SDK. | PLT/SLE |
| 03  | Supports frequency-hopping ChannelMAP configuration | New channel list application guidance is added, supporting customized frequency-hopping channels by customers. | SLE |
| 04  | Supports payload length configuration | New payload-length customization application guidance is added, supporting custom transmission data sizes. | SLE |
| 05  | OTA upgrade open | Provides SLE/BLE OTA reference implementations. | OTA |
| 06  | AMIC open | Supports voice collection and transmission capability, providing a Sample. | PLT |
| 07  | Added BLE More Data related measurement | In BLE mode, new measurement information is needed to indicate how many more data packets there are in one connection interval. | BLE |
| 08  | Supports configurable encrypted storage of pairing keys | Supports configurable encrypted storage of SparkLink and Bluetooth pairing keys. | SLE/BLE |

### 2.2 Enhanced Functional Features

| No. | Brief Description | Modification Reason | Modification Impact | Modified Module |
| --- | -------- | ---- | ----------------------------------------- | ---- |
| 01  | Bus automatic CG optimization | Performance optimization | Bus optimization, improving register read/write performance. | PLT |
| 02  | Low-latency one-to-two reconnection time optimization | Performance optimization | The low-latency one-to-two reconnection time is on par with one-to-one. | SLE |
| 03  | Low-latency one-to-two power consumption optimization | Functional optimization | The low-latency one-to-two power consumption is on par with one-to-one. | SLE |

## 3. Interface Change Description

### 3.1 BLE SDK Interface Change Description
| Header File | Modified Content | Modified Version |
| ---------- | -------------------- | ----------- |
| bts_le_gap.h | New interface: <br> errcode_t <br> gap_ble_set_nv_store_smp_keys_mode(uint8_t is_encrypted);<br> Interface usage: NV storage pairing key encryption setting.<br> Typical usage scenario: whether the pairing key is stored encrypted.<br> | BS2X 1.0.18 |

### 3.2 SLE SDK Interface Change Description
Not applicable
