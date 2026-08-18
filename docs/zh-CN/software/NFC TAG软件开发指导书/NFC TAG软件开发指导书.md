# Preface<a name="ZH-CN_TOPIC_0000001762634336"></a>

**Overview<a name="section4537382116410"></a>**

BS2XV100 provides developers with NFC TAG-related interfaces through APIs (Application Programming Interfaces), including interfaces for initialization, parameter setting, NDEF message assembly, NDEF message configuration, listening-mode enabling, disabling, etc.

**Product Versions<a name="section673mcpsimp"></a>**

The product versions corresponding to this document are as follows.

| Product Name | Product Version |
| --- | --- |
| BS2X | V100 |

**Reader Audience<a name="section4378592816410"></a>**

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
| 02 | 2025-11-07 | Updated the content of the "[Interface Description](接口说明.md)" chapter. |
| 01 | 2024-05-15 | First official version release. |
| 00B01 | 2024-01-08 | First interim version release. |

# Overview<a name="ZH-CN_TOPIC_0000001809711061"></a>

BS2XV100 provides developers with NFC TAG-related interfaces through APIs (Application Programming Interfaces). The interface functions are described as follows:

TAG chip interfaces: provide functions such as TAG chip parameter configuration and behavior control.

> ![](public_sys-resources/icon-note.gif) **Notes:**
> This document describes the basic flow and API interface descriptions of the functions of each module.

# Development Guidance<a name="ZH-CN_TOPIC_0000001809945117"></a>

## Error Codes<a name="ZH-CN_TOPIC_0000001762906302"></a>

NFC TAG uses error codes to indicate to users the execution result of the current task. The error codes are described as follows:

**Table 1** Error Codes

| No. | Definition | Actual Value | Description |
| --- | --- | --- | --- |
| 1 | NFC_OK | 0 | Successful execution error code. |
| 2 | NFC_ERR_PTR_NULL | 0x80005F00 | A null pointer is present in the input parameters. |
| 3 | NFC_ERR_INVALID_LENGTH | 0x80005F01 | The input parameter length is illegal. |
| 5 | NFC_ERR_INVALID_PARAM | 0x80005F02 | An illegal parameter is present in the input parameters. |
| 6 | NFC_ERR_INVALID_STATE | 0x80005F03 | An abnormal TAG state. |
| 7 | NFC_ERR_MEMCPY_FAIL | 0x80005F04 | A memory copy exception. |

## Interface Description<a name="ZH-CN_TOPIC_0000001762902426"></a>

**Table 1** TAG Chip Interface Description

| Interface Name | Description | Parameter Description | Return Information Description |
| --- | --- | --- | --- |
| NFC_T2T_Init | Initializes the T2T module | handle: registered callback function | void |
| NFC_T2T_SetConfig | Configures T2T parameters | id: parameter ID<br/>data: parameter data<br/>len: parameter length | Interface return value: error code. |
| NFC_T2T_StartEmulation | Enables RF listening | void | Interface return value: error code. |
| NFC_T2T_StopEmulation | Stops RF listening | void | Interface return value: error code. |
| NFC_T2T_SetNdef | Sets the NDEF message | data: ndef data<br/>len: ndef length, maximum 988 bytes | Interface return value: error code. |
| NFC_T2T_SetTagArea | Places the storage location of the NDEF message into a user-defined space | buff: user space pointer<br/>len: user space length | Interface return value: error code. |

## Development Flow<a name="ZH-CN_TOPIC_0000001809944693"></a>

1. Call NFC_T2T_Init to initialize a T2T environment.
2. Use NFC_T2T_SetConfig to configure the parameters of interest, which is optional.
3. Assemble the NDEF message, then use the NFC_T2T_SetNdef interface to configure it to the Tag module.
4. Enable listening with NFC_T2T_StartEmulation.
