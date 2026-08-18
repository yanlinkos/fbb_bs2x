# Preface<a name="ZH-CN_TOPIC_0000001926760082"></a>

**Overview<a name="section669mcpsimp"></a>**

Describes the changes in the Bluetooth and NearLink (SLE) SDK interfaces in the BS2X release version.

**Product Versions<a name="section673mcpsimp"></a>**

The product versions corresponding to this document are as follows.

| Product Name | Product Version |
| --- | --- |
| BS2X | V100 |

**Reader Audience<a name="section694mcpsimp"></a>**

This document is mainly applicable to the following engineers:

- Technical support engineers
- Software development engineers

**Symbol Conventions<a name="section133020216410"></a>**

The following symbols may appear in this document, and their meanings are as follows.

| Symbol | Description |
| --- | --- |
| [Image] | Indicates a hazard with a high level of risk that, if not avoided, will result in death or serious injury. |
| [Image] | Indicates a hazard with a medium level of risk that, if not avoided, may result in death or serious injury. |
| [Image] | Indicates a hazard with a low level of risk that, if not avoided, may result in minor or moderate injury. |
| [Image] | Used to deliver device- or environment-safety warning information. If not avoided, it may cause equipment damage, data loss, degraded equipment performance, or other unpredictable results. "Cautions" do not involve personal injury. |
| [Image] | Supplementary explanation of key information in the main text. "Notes" are not safety warning information and do not involve personal, equipment, or environmental injury information. |

**Modification Records<a name="section2467512116410"></a>**

| Doc Version | Release Date | Modification Description |
| --- | --- | --- |
| 01 | 2025-05-30 | Updated [Table 1](BLE-SDK接口变更说明.md#table14411119287) of the "[BLE SDK Interface Change Description](BLE-SDK接口变更说明.md)" chapter. |
| 00B01 | 2024-06-18 | First interim version release. |

# BLE SDK Interface Change Description<a name="ZH-CN_TOPIC_0000001920743641"></a>

**Table 1** BLE Interface Change Description

| SDK Version | Header File | Modification Content |
| --- | --- | --- |
| 1.0.11 | bts_device_manager.h | 1. Added the power_on callback to indicate whether the B core in the dual-core is powered on.<br/>2. Moved the enable/disable ble interface and callback to this file. |
| 1.0.11 | bts_le_gap.h | 1. Added the set extended advertising parameters interface.<br/>2. Added the get bond device interface.<br/>3. Added the set NV interface (not yet released).<br/>4. Added the set rssi interface. |
| 1.0.12 | bts_le_gap.h | Changed the tx_power parameter type of the ble advertising parameter structure gap_ble_adv_params_t from uint32_t to int8_t. |
| 1.0.12 | bts_le_gap.h | 1. Modified the set NV interface (added the index input parameter).<br/>2. Added the errcode_t gap_ble_set_save_smp_keys_mode(uint8_t is_available) interface to set whether user NV setting is supported.<br/>3. Added the gap_ble_save_pair_keys_mode_switch_t enum. |
| 1.0.12 | bts_le_gap.h | 1. Added errcode_t gap_ble_add_white_list(const bd_addr_t *addr), errcode_t gap_ble_remove_white_list(const bd_addr_t *addr), errcode_t gap_ble_get_white_list(void) interfaces.<br/>2. Added the typedef void (*gap_ble_get_white_list_callback)(uint8_t count, bd_addr_t *addr_list) callback. |
| 1.0.12 | bts_le_gap.h | Added the keymissing error code in pair_complete_cb. |
| 1.0.12 | bts_le_gap.h | 1. For the first pairing, first report the authentication complete callback, then report the pairing complete callback.<br/>2. For reconnection, only report the pairing complete callback. |
| 1.0.12 | bts_low_latency.h | Added the set em data method and callback. |
| 1.0.16 | bts_le_gap.h | Added the gap_ble_set_scan_extern_parameters interface. |

**Table 2** SLE Interface Change Description

| SDK Version | Header File | Modification Content |
| --- | --- | --- |
| 1.0.11 | sle_transmition_manager.h | Added the QOS queue. |
| 1.0.11 | sle_ssap_client.h | Changed the type member variable in the ssapc_find_structure_param_t of the ssapc_find_structure method, with the referenced enum changed from ssap_find_type_t to ssap_property_type_t. |
| 1.0.11 | sle_ota.h | Added the sle ota header file. |
| 1.0.11 | sle_low_latency.h | 1. Changed the len parameter of the tx and rx callback functions from uint16_t to uint8_t.<br/>2. Added sle_low_latency_rx_get_data to obtain rx data. |
| 1.0.11 | sle_device_manager.h | 1. Added the power_on callback to indicate whether the B core in the dual-core is powered on.<br/>2. Moved the enable/disable sle interface and callback to this file. |
| 1.0.11 | sle_device_discovery.h | Added the delete advertising interface and callback. |
| 1.0.11 | sle_connection_manager.h | 1. Added the get connection as G/T node interface.<br/>2. Added the get bond device interface.<br/>3. Added the set NV interface (not yet released).<br/>4. Added the whitelist logic.<br/>5. Added the cancel connection interface.<br/>6. Added the set rssi interface.<br/>7. Added the disconnect all connections interface. |
| 1.0.12 | sle_ssap_server.h | Added the interface for receiving the cfm response from the client: indicate_cfm_cb. |
| 1.0.12 | sle_connection_manager.h | Added the set channel map interface. |
| 1.0.12 | sle_connection_manager.h | 1. Modified the set NV interface (added the index input parameter).<br/>2. Added the errcode_t sle_set_save_pair_keys_mode(uint8_t is_available) interface to set whether user NV setting is supported.<br/>3. Added the sle_save_smp_keys_mode_switch_t enum. |
| 1.0.12 | sle_connection_manager.h | Added the keymissing error code in pair_complete_cb. |
| 1.0.12 | sle_low_latency.h | 1. Added the set em data method and callback.<br/>2. Modified the original low latency callback. |
