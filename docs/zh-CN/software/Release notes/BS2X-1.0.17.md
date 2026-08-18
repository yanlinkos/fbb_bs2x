# Version 1.0.17 Description File

## 1. Improvements Over the Previous Baseline Version

| No. | Module | Problem Description | Remark |
| --- | ------- | --------------------------------------- | --- |
| 01  | PLT | Optimization of the fhid_send_data return value judgment | |
| 02  | SLE | Modified the enum value in the encryption algorithm header file | |
| 03  | SLE/BLE | Modified the clock comparison logic; in BLE, the clock is obtained directly to prevent incorrect conversion between the two after the GLE clock flips | |
| 04  | SLE | The highest bit of ltk_len is used as the peer LL Privacy flag; the returned length removes this high bit | |
| 05  | PLT | In a multi-connection scenario, after first establishing one connection, then connecting to an invalid address and disconnecting, there is no callback for the connection state change | |
| 06  | PLT | On the login screen of some Macs, the mouse cursor can only move up and down, not left and right | |
| 07  | PLT | Open-source software upgrade | |
| 08  | BLE | Improved the randomness of BLE IRK generation | |

## 2. Newly Added, Modified, and Deleted Functional Features Compared to the Previous Baseline Version

### 2.1 New Functional Features

This section describes all newly added functional features between the current version and the previous baseline version.

| No. | Brief Description | Detailed Description | Modified Module |
| --- | ------------------------- | ----------------------------------------------- | ------ |
| 01  | Supports low-latency one-to-two solution | Office keyboard-and-mouse kit supports keyboard-and-mouse one-to-two functionality. Note: one-to-two is a new feature, provided for debugging only, and does not support commercial use. | SLE |
| 02  | AT command extension, improving import efficiency | Supports AT commands to directly write or read the MAC to NV, and read NV key_id, version number, power mode, and temperature commands. | PLT |
| 03  | Supports UART read/write timeout mechanism, enhancing robustness | When the UART read/write interface blocks and times out, an error code is returned to avoid invalid waiting. | PLT |
| 04  | Supports capturing serial port and HSO logs via USB, improving testability and ease of use | Serial port and HSO logs can be captured via the USB port, avoiding complex operations such as disassembly and flying leads. | PLT |
| 05  | RCU Sample feature enhancement | RCU Sample supports three-mode remote control configuration, including dual SLE, dual BLE, and SLE+BLE modes. | Sample |
| 06  | Pointing remote Sample feature enhancement | The pointing remote Sample adds voice collection, voice encoding/decoding, and voice transmission functions. | Sample |

### 2.2 Enhanced Functional Features

| No. | Brief Description | Modification Reason | Modification Impact | Modified Module |
| --- | -------- | ---- | ----------------------------------------- | ---- |
| 01  | Key press latency optimization | Performance optimization | Optimizes air-interface and key-press-triggered interrupt time consumption. | SLE |
| 02  | Broadcast access process optimization | Performance optimization | Optimizes the probability of 0x1C disconnection after sleep-wake. | SLE |
| 03  | Partition logic optimization | Functional optimization | The APP mirror partition size is obtained directly from the partition table, avoiding the problem where the APP mirror might overlap with user-defined partitions. | PLT |

## 3. Interface Change Description

### 3.1 BLE SDK Interface Change Description

Not applicable

### 3.2 SLE SDK Interface Change Description

| Header File | Modified Content | Modified Version |
| ------------------------ | ----------------------------------------------------------------------------------------------------------------------------------------- | ----------- |
| sle_connection_manager.h | Modified the enum value in the encryption algorithm header file. | BS2X 1.0.17 |
| extern use | New interface errcode_t sle_set_low_latency_data(uint16_t conn_id, uint8_t* value, uint8_t len);<br>Interface usage: used to quickly send data to the peer via low latency, reducing latency. Typical usage scenario: sending key-press data. | BS2X 1.0.17 |
