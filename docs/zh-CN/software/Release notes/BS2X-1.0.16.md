# Version 1.0.16 Description File

## 1. Improvements Over the Previous Baseline Version

| No. | Module | Problem Description | Remark |
| --- | ------- | --------------------------------------------------- | --- |
| 01  | BLE | On MacBook computers, under Bluetooth connection, there is a probability of a stuttering/lagging phenomenon | |
| 02  | SLE | Multiple dongles plugged into a USB hub experience disconnection issues | |
| 03  | SLE/BLE | After entering standby low-power mode, upon waking up, SLE is inevitably unable to switch reporting rates, or BLE is unable to update connection parameters | |
| 04  | BTH | The BLE client will hang the thread without returning when the peer BLE server does not exist | |
| 05  | SLE | The mouse may experience a disconnect-then-reconnect issue with a certain probability after being powered back on | |
| 06  | PLT | The IR learning function is not successful | |
| 07  | PLT | Ghost-key triggers occur with a certain probability | |
| 08  | PLT | During stress testing of the voice remote control, local recording noise appears that is not background ambient noise | |
| 09  | BTH | Abnormal event and message ordering | |
| 10  | SLE | In 2.4G mode, after sleep-wake and reconnection, a link-break/reconnect loop occurs. First, 2 link-break causes are 0x07, and the rest are all 0x1c | |
| 11  | PLT | Abnormal hang/deadlock occurs when SLP loads firmware | |
| 12  | PLT | After bs21 enters low power and wakes up, uart data reception becomes slower | |

## 2. Newly Added, Modified, and Deleted Functional Features Compared to the Previous Baseline Version

### 2.1 BS2X 1.0.16 Version Compared to BS2X 1.0.15 Version

This section describes all newly added functional features between the current version and the previous baseline version.

| No. | Brief Description | Detailed Description | Modified Module |
| --- | ---------------- | -------------------- | ---- |
| 01  | Supports ranging DLI standard | Supports the ranging DLI standard, enabling interoperability certification | SLE |
| 02  | New BLE Long Range | Supports the BLE Long Range feature | BLE |
| 03  | New standard broadcast support | Supports standard broadcast, compatible with legacy broadcast | SLE |
| 04  | SPI bus adjustment | Supports adjusting the SPI CS and TSRAD delay | PLT |

## 3. Interface Change Description

### 3.1 BLE SDK Interface Change Description

| Header File | Modified Content | Modified Version |
| ------------ | ---------------------------------------- | ----------- |
| bts_le_gap.h | 1. New interface gap_ble_set_scan_extern_parameters | BS2X 1.0.16 |

### 3.2 SLE SDK Interface Change Description

| Header File | Modified Content | Modified Version |
| ------------------------ | ------------------------------------- | ----------- |
| sle_at_dd.h | 1. Added a broadcast filtering policy field | BS2X 1.0.16 |
| uapi_gle_dev_discovery.h | 1. New interface for setting broadcast extension default parameters | BS2X 1.0.16 |
| sle_device_discovery.h | 1. Added a broadcast filtering policy field | BS2X 1.0.16 |
| gle_hci_ev.h | 1. New ranging status | BS2X 1.0.16 |
| bth_gle_hadm.h | 1. New SparkLink layer setting cs parameters, GTTT networking mode | BS2X 1.0.16 |
| sle_hadm_manager.h | 1. New GTTT-mode channel sounding parameters and configuration method | BS2X 1.0.16 |
