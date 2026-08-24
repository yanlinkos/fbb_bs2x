# Preface<a name="ZH-CN_TOPIC_0000002219311933"></a>

**Overview<a name="section4537382116410"></a>**

This document describes the usage guide for the SP31 air mouse sample, including the sample-based compilation version, sample usage steps, and the SLE and SLP working flows in the sample.

Sample code path: application/samples/products/air\_mouse

**Reader Audience<a name="section12772732414"></a>**

This document mainly applies to the following engineers:

-   Technical Support Engineer
-   Software Development Engineer


# Open Source Version<a name="ZH-CN_TOPIC_0000002479298980"></a>

The open source version supports the SLP basic functions. The sample code contains implementations of SLP ranging, SLP angle measurement, SLP CIR reporting, USB, and other functions, which can be used as a reference for developers. The following uses the ecosystem three-antenna board pointing to the single board as a reference example.

-   **[Compilation Steps](#ZH-CN_TOPIC_0000002511180011)**  

-   **[Usage Method](#ZH-CN_TOPIC_0000002511271327)**  

-   **[Startup Flow](#ZH-CN_TOPIC_0000002183826164)**  

-   **[Available Functions](#ZH-CN_TOPIC_0000002479311386)**  

## Compilation Steps<a name="ZH-CN_TOPIC_0000002511180011"></a>

Both the RCU and Dongle versions need to be compiled. The three-antenna board is used as the default board type. The SDK is compiled together with the SLP firmware. The SDK is provided by BS2X. The following sections mainly describe the modification of configuration items.

-   **[Initiator Compilation](#ZH-CN_TOPIC_0000002511178895)**  

-   **[Responder Compilation](#ZH-CN_TOPIC_0000002511258921)**  

### Initiator Compilation<a name="ZH-CN_TOPIC_0000002511178895"></a>

>![](public_sys-resources/icon-note.gif) **Description:** 
>The SDK already contains the supporting SLP firmware, located in the middleware\\services\\srv\_tiot\_host\\tiot\_driver\\product\_porting\\air\_mouse\\firmware directory. Unless there is a version upgrade, no update is required. Step "[1](#li9714185916249)" below is the firmware update procedure and can be skipped.

1.  <a name="li9714185916249"></a>Update the SLP firmware (The SDK comes with a bundled version. If there is no update, this step can be skipped.). In the interim\_binary\\bs21e\\bin directory of the SDK, create a new slp\\firmware directory, and place the "file\_array" and "file\_array\_ota" files from the SP31 version folder into the "interim\_binary\\bs21e\\bin\\slp\\firmware" directory.

    **Figure 1**  SLP firmware storage location<a name="fig177383091517"></a>  
    ![](figures/SLP固件存放位置-1.png "SLP firmware storage location-1")

2.  Open the Visual Studio Code tool and import the SDK project according to the BS2X version document.
3.  Open KConfig and enable the LDO mode, as shown in [Figure 2](#fig1016819411818).

    **Figure 2**  Initiator enabling LDO mode<a name="fig1016819411818"></a>  
    ![](figures/Initiator开启LDO模式.png "Initiator enabling LDO mode")

4.  Set AIR MOUSE type to Enable AIR MOUSE sample, as shown in [Figure 3](#fig16824040135012).

    **Figure 3**  Initiator configuring Enable AIR MOUSE sample mode<a name="fig16824040135012"></a>  
    ![](figures/Initiator配置Enable-AIR-MOUSE-sample模式.png "Initiator configuring Enable AIR MOUSE sample mode")

5.  Set Select AIR MOUSE board to Open Source Board, as shown in [Figure 4](#fig193145223319).

    **Figure 4**  Initiator configuring Open Source Board type<a name="fig193145223319"></a>  
    ![](figures/Initiator配置Open-Source-Board类型.png "Initiator configuring Open Source Board type")

6.  If you need to print CIR, you can enable the Open Cir print mode, as shown in [Figure 5](#fig19740161964118). Note: Enabling it may cause insufficient serial port resources and cause a system hang. It is recommended to enable it as needed.

    **Figure 5**  Initiator enabling Open Cir print mode<a name="fig19740161964118"></a>  
    ![](figures/Initiator开启Open-Cir-print模式.png "Initiator enabling Open Cir print mode")

7.  Modify the sample Usage and set it to ranging aox mode, as shown in [Figure 6](#fig354184517193).

    **Figure 6**  Initiator setting ranging aox mode<a name="fig354184517193"></a>  
    ![](figures/Initiator设置ranging-aox模式.png "Initiator setting ranging aox mode")

8.  Modify the antenna arrangement selection and set it to three ant mode\(L\) type, as shown in [Figure 7](#fig158661417182211).

    **Figure 7**  Initiator setting the antenna to three ant mode\(L\) mode<a name="fig158661417182211"></a>  
    ![](figures/Initiator设置天线为three-ant-mode(L)模式.png "Initiator setting the antenna to three ant mode(L) mode")

9.  Modify the UART pin configuration: H0TX=26, H0RX=27, H0CTS=28, H0RTS=29, as shown in [Figure 8](#fig2423046749).

    **Figure 8**  Initiator modifying UART pin configuration<a name="fig2423046749"></a>  
    ![](figures/Initiator修改UART管脚配置.png "Initiator modifying UART pin configuration")

10. Modify the SLE protocol configuration and select "sle measure peripheral", as shown in [Figure 9](#fig51862553222).

    **Figure 9**  Initiator modifying the SLE protocol<a name="fig51862553222"></a>  
    ![](figures/Initiator修改SLE-protocol-2.png "Initiator modifying the SLE protocol-2")

11. Click Rebuild to compile the version. After a successful compilation, the version path is: tools\\pkg\\fwpkg\\bs21e, and the version file name is: bs21e\_all.fwpkg.

### Responder Compilation<a name="ZH-CN_TOPIC_0000002511258921"></a>

1.  Update the SLP firmware (The SDK comes with a bundled version. If there is no update, this step can be skipped.). In the interim\_binary\\bs21e\\bin directory of the SDK, create a new SLP\\firmware directory, and place the "file\_array" and "file\_array\_ota" files from the SP31 version folder into the "interim\_binary\\bs21e\\bin\\slp\\firmware" directory.

    **Figure 1**  SLP firmware storage location<a name="fig177383091517"></a>  
    ![](figures/SLP固件存放位置-3.png "SLP firmware storage location-3")

2.  Open the Visual Studio Code tool and import the SDK project according to the BS2X version document.
3.  Open KConfig and enable the LDO mode, as shown in [Figure 2](#fig1016819411818).

    **Figure 2**  Responder enabling LDO mode<a name="fig1016819411818"></a>  
    ![](figures/Responder开启LDO模式.png "Responder enabling LDO mode")

4.  Open KConfig and change the AIR MOUSE type to Enable AIR MOUSE Dongle sample, as shown in [Figure 3](#fig16301151185520).

    **Figure 3**  Responder configuring Enable AIR MOUSE Dongle sample mode<a name="fig16301151185520"></a>  
    ![](figures/Responder配置Enable-AIR-MOUSE-Dongle-sample模式.png "Responder configuring Enable AIR MOUSE Dongle sample mode")

5.  Set Select AIR MOUSE board to Open Source Board, as shown in [Figure 4](#fig193145223319).

    **Figure 4**  Responder configuring Open Source Board type<a name="fig193145223319"></a>  
    ![](figures/Responder配置Open-Source-Board类型.png "Responder configuring Open Source Board type")

6.  If you need to print CIR, you can enable the Open Cir print mode, as shown in [Figure 5](#fig19740161964118).

    **Figure 5**  Responder enabling Open Cir print mode<a name="fig19740161964118"></a>  
    ![](figures/Responder开启Open-Cir-print模式.png "Responder enabling Open Cir print mode")

7.  Modify the sample Usage and set it to ranging aox mode, as shown in [Figure 6](#fig89364313162)

    **Figure 6**  Responder setting ranging aox mode<a name="fig89364313162"></a>  
    ![](figures/Respnder设置ranging-aox模式.png "Responder setting ranging aox mode")

8.  Modify the antenna arrangement selection and set it to three ant mode\(L\) type, as shown in [Figure 7](#fig13802161819127)

    **Figure 7**  Responder setting the antenna to three ant mode\(L\) mode<a name="fig13802161819127"></a>  
    ![](figures/Respender设置天线为three-ant-mode(L)模式.png "Responder setting the antenna to three ant mode(L) mode")

9.  Modify the UART pin configuration: H0TX=26, H0RX=27, H0CTS=28, H0RTS=29, as shown in [Figure 8](#fig2423046749).

    **Figure 8**  Responder modifying UART pin configuration<a name="fig2423046749"></a>  
    ![](figures/Responder修改UART管脚配置.png "Responder modifying UART pin configuration")

10. Modify the SLE protocol configuration and select "sle measure central", as shown in [Figure 9](#fig551558172315).

    **Figure 9**  Responder modifying the SLE protocol<a name="fig551558172315"></a>  
    ![](figures/Responder修改SLE-protocol-4.png "Responder modifying the SLE protocol-4")

11. Click Rebuild to compile the version. After a successful compilation, the version path is: tools\\pkg\\fwpkg\\bs21e, and the version file name is: bs21e\_all.fwpkg.

## Usage Method<a name="ZH-CN_TOPIC_0000002511271327"></a>

1.  Burn the corresponding versions on the Initiator side and Responder side respectively.
2.  Power cycle the Initiator side and Responder side. After the Initiator side is powered on, the SLE starts broadcasting. The Responder side is connected to the host device through USB. After power-on, the SLE starts scanning, USB initialization, and device enumeration operations. The host device will recognize the HID device.
3.  Wait for the SLE link establishment.
4.  After the SLE connection pairing succeeds, both sides will automatically load the SLP firmware. After the loading succeeds, the SLP version information will be reported (you can check whether the version is correct). Then the SLP service will start automatically. If the service flow is normal, ranging, angle measurement, and other reported information will be printed periodically in the serial port log on the Responder side, and the cursor will be displayed on the host screen. The logs of both sides are shown in the following figure. For the startup flow, refer to "[Startup Flow](#ZH-CN_TOPIC_0000002511270377)".

    **Figure 1**  Serial port logs of the pointing remote control RCU and Dongle<a name="fig12411235387"></a>  
    ![](figures/指向遥控器RCU-Dongle串口日志-5.png "Serial port logs of the pointing remote control RCU and Dongle-5")

5.  If the CIR function is enabled, CIR data will be printed in the USB serial port.

    **Figure 2**  CIR log reporting in the USB serial port<a name="fig143371658155917"></a>  
    ![](figures/USB串口中CIR日志上报.png "CIR log reporting in the USB serial port")

## Startup Flow<a name="ZH-CN_TOPIC_0000002183826164"></a>

**Figure 1**  Simplified flow of the CIR reporting service<a name="fig533792210357"></a>  
![https://cloudmodeling.tools.huawei.com/draw?id=e89b02a904e44b51b20adcc048ee618a](figures/CIR上报业务简易流程.png "Simplified flow of the CIR reporting service")

## Available Functions<a name="ZH-CN_TOPIC_0000002479311386"></a>

-   **[Virtual Serial Port](#ZH-CN_TOPIC_0000002479153320)**  

-   **[CIR Reporting Function](#ZH-CN_TOPIC_0000002479313296)**  

### Virtual Serial Port<a name="ZH-CN_TOPIC_0000002479153320"></a>

The USB type is set to DEV\_SER\_HID (HID and virtual serial port device) by default. After the board is connected to the host through the USB cable, the host will recognize a serial port device and a HID device (see the figure below). The HID device is used to display the cursor, and the serial port device can send and receive data, such as sending CIR data or receiving production test commands.

**Figure 1**  USB devices displayed on the host<a name="fig438414167129"></a>  
![](figures/主机USB设备显示-6.png "USB devices displayed on the host-6")

### CIR Reporting Function<a name="ZH-CN_TOPIC_0000002479313296"></a>

>![](public_sys-resources/icon-notice.gif) **Notice:** 
>This function occupies many resources and is supported only in some versions.

The Sample code in the sample has implemented the CIR reporting function. You can configure it by referring to the [Compilation Steps](#ZH-CN_TOPIC_0000002511180011) section. After the device link is established, CIR data will be printed in the USB serial port. The relevant functions in the sample code are shown in the following table.

<a name="table2792mcpsimp"></a>
<table><thead align="left"><tr id="row2797mcpsimp"><th class="cellrowborder" valign="top" width="20.32%" id="mcps1.1.4.1.1"><p id="p2799mcpsimp"><a name="p2799mcpsimp"></a><a name="p2799mcpsimp"></a>Function Name</p>
</th>
<th class="cellrowborder" valign="top" width="53.16000000000001%" id="mcps1.1.4.1.2"><p id="p2801mcpsimp"><a name="p2801mcpsimp"></a><a name="p2801mcpsimp"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="26.520000000000003%" id="mcps1.1.4.1.3"><p id="p118512252075"><a name="p118512252075"></a><a name="p118512252075"></a>File</p>
</th>
</tr>
</thead>
<tbody><tr id="row58808436812"><td class="cellrowborder" valign="top" width="20.32%" headers="mcps1.1.4.1.1 "><p id="p15838133414273"><a name="p15838133414273"></a><a name="p15838133414273"></a>set_slp_start_ranging_param</p>
</td>
<td class="cellrowborder" valign="top" width="53.16000000000001%" headers="mcps1.1.4.1.2 "><p id="p388064316812"><a name="p388064316812"></a><a name="p388064316812"></a>Start the ranging and angle measurement service. When CIR is enabled, the default frequency is set to 15 Hz</p>
</td>
<td class="cellrowborder" valign="top" width="26.520000000000003%" headers="mcps1.1.4.1.3 "><p id="p68562510719"><a name="p68562510719"></a><a name="p68562510719"></a>sle_air_mouse_server.c</p>
</td>
</tr>
<tr id="row7575449135816"><td class="cellrowborder" valign="top" width="20.32%" headers="mcps1.1.4.1.1 "><p id="p145751249105815"><a name="p145751249105815"></a><a name="p145751249105815"></a>rpt_cir_cbk</p>
</td>
<td class="cellrowborder" valign="top" width="53.16000000000001%" headers="mcps1.1.4.1.2 "><p id="p11747145314585"><a name="p11747145314585"></a><a name="p11747145314585"></a>CIR reporting callback function mounted on the Initiator side</p>
</td>
<td class="cellrowborder" valign="top" width="26.520000000000003%" headers="mcps1.1.4.1.3 "><p id="p11840586581"><a name="p11840586581"></a><a name="p11840586581"></a>sle_air_mouse_server.c</p>
</td>
</tr>
<tr id="row1461511578714"><td class="cellrowborder" valign="top" width="20.32%" headers="mcps1.1.4.1.1 "><p id="p146157578718"><a name="p146157578718"></a><a name="p146157578718"></a>rpt_cir_cbk</p>
</td>
<td class="cellrowborder" valign="top" width="53.16000000000001%" headers="mcps1.1.4.1.2 "><p id="p1861585718719"><a name="p1861585718719"></a><a name="p1861585718719"></a>CIR reporting callback function mounted on the Responder side</p>
</td>
<td class="cellrowborder" valign="top" width="26.520000000000003%" headers="mcps1.1.4.1.3 "><p id="p7615105715711"><a name="p7615105715711"></a><a name="p7615105715711"></a>sle_air_mouse_client.c</p>
</td>
</tr>
<tr id="row1555614172115"><td class="cellrowborder" valign="top" width="20.32%" headers="mcps1.1.4.1.1 "><p id="p0447106227"><a name="p0447106227"></a><a name="p0447106227"></a>air_mouse_print</p>
</td>
<td class="cellrowborder" valign="top" width="53.16000000000001%" headers="mcps1.1.4.1.2 "><p id="p145568416211"><a name="p145568416211"></a><a name="p145568416211"></a>Customized print function. CIR data is preferentially output from the USB serial port. If the USB device is not enumerated, it is printed from the burn serial port.</p>
</td>
<td class="cellrowborder" valign="top" width="26.520000000000003%" headers="mcps1.1.4.1.3 "><p id="p1755694162120"><a name="p1755694162120"></a><a name="p1755694162120"></a>air_mouse_common.c</p>
</td>
</tr>
</tbody>
</table>

# AT Commands<a name="ZH-CN_TOPIC_0000002219311925"></a>

The following table summarizes the SLP AT commands.

<a name="table224mcpsimp"></a>
<table><thead align="left"><tr id="row93083484514"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.1.9.1.1"><p id="p195741730603"><a name="p195741730603"></a><a name="p195741730603"></a>No.</p>
</th>
<th class="cellrowborder" rowspan="2" valign="top" id="mcps1.1.9.1.2"><p id="p231mcpsimp"><a name="p231mcpsimp"></a><a name="p231mcpsimp"></a>Command</p>
</th>
<th class="cellrowborder" rowspan="2" valign="top" id="mcps1.1.9.1.3"><p id="p233mcpsimp"><a name="p233mcpsimp"></a><a name="p233mcpsimp"></a>Description</p>
</th>
<th class="cellrowborder" colspan="5" valign="top" id="mcps1.1.9.1.4"><p id="p4908101635211"><a name="p4908101635211"></a><a name="p4908101635211"></a>Whether the command can be called in each state</p>
</th>
</tr>
<tr id="row229mcpsimp"><th class="cellrowborder" valign="top" id="mcps1.1.9.2.1"><p id="p1451415308454"><a name="p1451415308454"></a><a name="p1451415308454"></a>Power-off</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.9.2.2"><p id="p1169095012459"><a name="p1169095012459"></a><a name="p1169095012459"></a>Powered on without ranging</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.9.2.3"><p id="p9362440465"><a name="p9362440465"></a><a name="p9362440465"></a>Ranging in progress</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.9.2.4"><p id="p1384214296466"><a name="p1384214296466"></a><a name="p1384214296466"></a>Ranging paused</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.9.2.5"><p id="p8682543184617"><a name="p8682543184617"></a><a name="p8682543184617"></a>Sleep</p>
</th>
</tr>
</thead>
<tbody><tr id="row235mcpsimp"><td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.9.1.1 mcps1.1.9.2.1 "><p id="p154313456016"><a name="p154313456016"></a><a name="p154313456016"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="28.83%" headers="mcps1.1.9.1.2 mcps1.1.9.2.2 "><p id="p237mcpsimp"><a name="p237mcpsimp"></a><a name="p237mcpsimp"></a>AT+SLPPOWERON</p>
</td>
<td class="cellrowborder" valign="top" width="22.040000000000003%" headers="mcps1.1.9.1.3 mcps1.1.9.2.3 "><p id="p239mcpsimp"><a name="p239mcpsimp"></a><a name="p239mcpsimp"></a>Power on SLP to complete SLP loading</p>
</td>
<td class="cellrowborder" valign="top" width="6.3100000000000005%" headers="mcps1.1.9.1.4 mcps1.1.9.2.4 "><p id="p1651423020454"><a name="p1651423020454"></a><a name="p1651423020454"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="10.34%" headers="mcps1.1.9.1.4 mcps1.1.9.2.5 "><p id="p11288201901512"><a name="p11288201901512"></a><a name="p11288201901512"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.309999999999999%" headers="mcps1.1.9.1.4 "><p id="p32927196159"><a name="p32927196159"></a><a name="p32927196159"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.33%" headers="mcps1.1.9.1.4 "><p id="p122951019141511"><a name="p122951019141511"></a><a name="p122951019141511"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.32%" headers="mcps1.1.9.1.4 "><p id="p1729701917150"><a name="p1729701917150"></a><a name="p1729701917150"></a>-</p>
</td>
</tr>
<tr id="row240mcpsimp"><td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.9.1.1 mcps1.1.9.2.1 "><p id="p1143114457012"><a name="p1143114457012"></a><a name="p1143114457012"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="28.83%" headers="mcps1.1.9.1.2 mcps1.1.9.2.2 "><p id="p242mcpsimp"><a name="p242mcpsimp"></a><a name="p242mcpsimp"></a>AT+SLPSTARTRANGING=&lt;parameters&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="22.040000000000003%" headers="mcps1.1.9.1.3 mcps1.1.9.2.3 "><p id="p244mcpsimp"><a name="p244mcpsimp"></a><a name="p244mcpsimp"></a>Start SLP ranging</p>
</td>
<td class="cellrowborder" valign="top" width="6.3100000000000005%" headers="mcps1.1.9.1.4 mcps1.1.9.2.4 "><p id="p9515430174517"><a name="p9515430174517"></a><a name="p9515430174517"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="10.34%" headers="mcps1.1.9.1.4 mcps1.1.9.2.5 "><p id="p116901750194511"><a name="p116901750194511"></a><a name="p116901750194511"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.309999999999999%" headers="mcps1.1.9.1.4 "><p id="p153624417465"><a name="p153624417465"></a><a name="p153624417465"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.33%" headers="mcps1.1.9.1.4 "><p id="p784210295461"><a name="p784210295461"></a><a name="p784210295461"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.32%" headers="mcps1.1.9.1.4 "><p id="p868204394617"><a name="p868204394617"></a><a name="p868204394617"></a>√</p>
</td>
</tr>
<tr id="row245mcpsimp"><td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.9.1.1 mcps1.1.9.2.1 "><p id="p124311045504"><a name="p124311045504"></a><a name="p124311045504"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="28.83%" headers="mcps1.1.9.1.2 mcps1.1.9.2.2 "><p id="p13799734759"><a name="p13799734759"></a><a name="p13799734759"></a>AT+SLPPOWEROFF</p>
</td>
<td class="cellrowborder" valign="top" width="22.040000000000003%" headers="mcps1.1.9.1.3 mcps1.1.9.2.3 "><p id="p249mcpsimp"><a name="p249mcpsimp"></a><a name="p249mcpsimp"></a>Power off SLP</p>
</td>
<td class="cellrowborder" valign="top" width="6.3100000000000005%" headers="mcps1.1.9.1.4 mcps1.1.9.2.4 "><p id="p951515300454"><a name="p951515300454"></a><a name="p951515300454"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="10.34%" headers="mcps1.1.9.1.4 mcps1.1.9.2.5 "><p id="p13690165034513"><a name="p13690165034513"></a><a name="p13690165034513"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.309999999999999%" headers="mcps1.1.9.1.4 "><p id="p43621745468"><a name="p43621745468"></a><a name="p43621745468"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.33%" headers="mcps1.1.9.1.4 "><p id="p584212904611"><a name="p584212904611"></a><a name="p584212904611"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.32%" headers="mcps1.1.9.1.4 "><p id="p9682104324618"><a name="p9682104324618"></a><a name="p9682104324618"></a>√</p>
</td>
</tr>
<tr id="row1127728442"><td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.9.1.1 mcps1.1.9.2.1 "><p id="p64309454019"><a name="p64309454019"></a><a name="p64309454019"></a>4</p>
</td>
<td class="cellrowborder" valign="top" width="28.83%" headers="mcps1.1.9.1.2 mcps1.1.9.2.2 "><p id="p1527868841"><a name="p1527868841"></a><a name="p1527868841"></a>AT+SLPSLEEP</p>
</td>
<td class="cellrowborder" valign="top" width="22.040000000000003%" headers="mcps1.1.9.1.3 mcps1.1.9.2.3 "><p id="p83828102612"><a name="p83828102612"></a><a name="p83828102612"></a>Put SLP to sleep</p>
</td>
<td class="cellrowborder" valign="top" width="6.3100000000000005%" headers="mcps1.1.9.1.4 mcps1.1.9.2.4 "><p id="p45151730184517"><a name="p45151730184517"></a><a name="p45151730184517"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="10.34%" headers="mcps1.1.9.1.4 mcps1.1.9.2.5 "><p id="p1269055044510"><a name="p1269055044510"></a><a name="p1269055044510"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.309999999999999%" headers="mcps1.1.9.1.4 "><p id="p183625418464"><a name="p183625418464"></a><a name="p183625418464"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.33%" headers="mcps1.1.9.1.4 "><p id="p684210290464"><a name="p684210290464"></a><a name="p684210290464"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.32%" headers="mcps1.1.9.1.4 "><p id="p12682194354615"><a name="p12682194354615"></a><a name="p12682194354615"></a>√</p>
</td>
</tr>
<tr id="row101421612104212"><td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.9.1.1 mcps1.1.9.2.1 "><p id="p34301945904"><a name="p34301945904"></a><a name="p34301945904"></a>5</p>
</td>
<td class="cellrowborder" valign="top" width="28.83%" headers="mcps1.1.9.1.2 mcps1.1.9.2.2 "><p id="p1014216128424"><a name="p1014216128424"></a><a name="p1014216128424"></a>AT+SLPSTOPRANGING</p>
</td>
<td class="cellrowborder" valign="top" width="22.040000000000003%" headers="mcps1.1.9.1.3 mcps1.1.9.2.3 "><p id="p111431712204217"><a name="p111431712204217"></a><a name="p111431712204217"></a>Stop the SLP ranging and angle measurement services</p>
</td>
<td class="cellrowborder" valign="top" width="6.3100000000000005%" headers="mcps1.1.9.1.4 mcps1.1.9.2.4 "><p id="p9515123084514"><a name="p9515123084514"></a><a name="p9515123084514"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="10.34%" headers="mcps1.1.9.1.4 mcps1.1.9.2.5 "><p id="p156905506456"><a name="p156905506456"></a><a name="p156905506456"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.309999999999999%" headers="mcps1.1.9.1.4 "><p id="p1362448465"><a name="p1362448465"></a><a name="p1362448465"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.33%" headers="mcps1.1.9.1.4 "><p id="p5842202964616"><a name="p5842202964616"></a><a name="p5842202964616"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.32%" headers="mcps1.1.9.1.4 "><p id="p19682134314610"><a name="p19682134314610"></a><a name="p19682134314610"></a>-</p>
</td>
</tr>
<tr id="row99021216319"><td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.9.1.1 mcps1.1.9.2.1 "><p id="p164297451002"><a name="p164297451002"></a><a name="p164297451002"></a>6</p>
</td>
<td class="cellrowborder" valign="top" width="28.83%" headers="mcps1.1.9.1.2 mcps1.1.9.2.2 "><p id="p891141211313"><a name="p891141211313"></a><a name="p891141211313"></a>AT+SLPPAUSERANGING</p>
</td>
<td class="cellrowborder" valign="top" width="22.040000000000003%" headers="mcps1.1.9.1.3 mcps1.1.9.2.3 "><p id="p0911912203112"><a name="p0911912203112"></a><a name="p0911912203112"></a>Pause the SLP ranging and angle measurement services</p>
</td>
<td class="cellrowborder" valign="top" width="6.3100000000000005%" headers="mcps1.1.9.1.4 mcps1.1.9.2.4 "><p id="p14515143064512"><a name="p14515143064512"></a><a name="p14515143064512"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="10.34%" headers="mcps1.1.9.1.4 mcps1.1.9.2.5 "><p id="p11690150144515"><a name="p11690150144515"></a><a name="p11690150144515"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.309999999999999%" headers="mcps1.1.9.1.4 "><p id="p1936224104619"><a name="p1936224104619"></a><a name="p1936224104619"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.33%" headers="mcps1.1.9.1.4 "><p id="p1684242954612"><a name="p1684242954612"></a><a name="p1684242954612"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.32%" headers="mcps1.1.9.1.4 "><p id="p1968211437465"><a name="p1968211437465"></a><a name="p1968211437465"></a>-</p>
</td>
</tr>
<tr id="row4127171615312"><td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.9.1.1 mcps1.1.9.2.1 "><p id="p24291451507"><a name="p24291451507"></a><a name="p24291451507"></a>7</p>
</td>
<td class="cellrowborder" valign="top" width="28.83%" headers="mcps1.1.9.1.2 mcps1.1.9.2.2 "><p id="p4127416133118"><a name="p4127416133118"></a><a name="p4127416133118"></a>AT+SLPCONTINUERANGING</p>
</td>
<td class="cellrowborder" valign="top" width="22.040000000000003%" headers="mcps1.1.9.1.3 mcps1.1.9.2.3 "><p id="p51278164319"><a name="p51278164319"></a><a name="p51278164319"></a>Continue the SLP ranging and angle measurement services</p>
</td>
<td class="cellrowborder" valign="top" width="6.3100000000000005%" headers="mcps1.1.9.1.4 mcps1.1.9.2.4 "><p id="p85151830174512"><a name="p85151830174512"></a><a name="p85151830174512"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="10.34%" headers="mcps1.1.9.1.4 mcps1.1.9.2.5 "><p id="p469015064510"><a name="p469015064510"></a><a name="p469015064510"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.309999999999999%" headers="mcps1.1.9.1.4 "><p id="p93621542461"><a name="p93621542461"></a><a name="p93621542461"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.33%" headers="mcps1.1.9.1.4 "><p id="p1784232974613"><a name="p1784232974613"></a><a name="p1784232974613"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.32%" headers="mcps1.1.9.1.4 "><p id="p12682134374614"><a name="p12682134374614"></a><a name="p12682134374614"></a>-</p>
</td>
</tr>
<tr id="row165221259123210"><td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.9.1.1 mcps1.1.9.2.1 "><p id="p142913451705"><a name="p142913451705"></a><a name="p142913451705"></a>8</p>
</td>
<td class="cellrowborder" valign="top" width="28.83%" headers="mcps1.1.9.1.2 mcps1.1.9.2.2 "><p id="p1752215912323"><a name="p1752215912323"></a><a name="p1752215912323"></a>AT+SLPWRITEAOXCALIPARA=&lt;parameters&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="22.040000000000003%" headers="mcps1.1.9.1.3 mcps1.1.9.2.3 "><p id="p165225591326"><a name="p165225591326"></a><a name="p165225591326"></a>Write the SLP angle measurement calibration value</p>
</td>
<td class="cellrowborder" valign="top" width="6.3100000000000005%" headers="mcps1.1.9.1.4 mcps1.1.9.2.4 "><p id="p751573020456"><a name="p751573020456"></a><a name="p751573020456"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="10.34%" headers="mcps1.1.9.1.4 mcps1.1.9.2.5 "><p id="p116901350124510"><a name="p116901350124510"></a><a name="p116901350124510"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.309999999999999%" headers="mcps1.1.9.1.4 "><p id="p1436218415460"><a name="p1436218415460"></a><a name="p1436218415460"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.33%" headers="mcps1.1.9.1.4 "><p id="p2842629184611"><a name="p2842629184611"></a><a name="p2842629184611"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.32%" headers="mcps1.1.9.1.4 "><p id="p1968224317463"><a name="p1968224317463"></a><a name="p1968224317463"></a>√</p>
</td>
</tr>
<tr id="row814165153319"><td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.9.1.1 mcps1.1.9.2.1 "><p id="p184285453013"><a name="p184285453013"></a><a name="p184285453013"></a>9</p>
</td>
<td class="cellrowborder" valign="top" width="28.83%" headers="mcps1.1.9.1.2 mcps1.1.9.2.2 "><p id="p214358331"><a name="p214358331"></a><a name="p214358331"></a>AT+SLPREADAOXCALIPARA</p>
</td>
<td class="cellrowborder" valign="top" width="22.040000000000003%" headers="mcps1.1.9.1.3 mcps1.1.9.2.3 "><p id="p51419553318"><a name="p51419553318"></a><a name="p51419553318"></a>Read the SLP angle measurement calibration value</p>
</td>
<td class="cellrowborder" valign="top" width="6.3100000000000005%" headers="mcps1.1.9.1.4 mcps1.1.9.2.4 "><p id="p1751513044511"><a name="p1751513044511"></a><a name="p1751513044511"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="10.34%" headers="mcps1.1.9.1.4 mcps1.1.9.2.5 "><p id="p1869015017459"><a name="p1869015017459"></a><a name="p1869015017459"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.309999999999999%" headers="mcps1.1.9.1.4 "><p id="p193621548464"><a name="p193621548464"></a><a name="p193621548464"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.33%" headers="mcps1.1.9.1.4 "><p id="p11842122919468"><a name="p11842122919468"></a><a name="p11842122919468"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.32%" headers="mcps1.1.9.1.4 "><p id="p1268294384616"><a name="p1268294384616"></a><a name="p1268294384616"></a>√</p>
</td>
</tr>
<tr id="row129333803318"><td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.9.1.1 mcps1.1.9.2.1 "><p id="p442874520010"><a name="p442874520010"></a><a name="p442874520010"></a>10</p>
</td>
<td class="cellrowborder" valign="top" width="28.83%" headers="mcps1.1.9.1.2 mcps1.1.9.2.2 "><p id="p89342883320"><a name="p89342883320"></a><a name="p89342883320"></a>AT+SLPWRITETXPOWER=&lt;parameters&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="22.040000000000003%" headers="mcps1.1.9.1.3 mcps1.1.9.2.3 "><p id="p189341585336"><a name="p189341585336"></a><a name="p189341585336"></a>Write the SLP power value</p>
</td>
<td class="cellrowborder" valign="top" width="6.3100000000000005%" headers="mcps1.1.9.1.4 mcps1.1.9.2.4 "><p id="p20515203084518"><a name="p20515203084518"></a><a name="p20515203084518"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="10.34%" headers="mcps1.1.9.1.4 mcps1.1.9.2.5 "><p id="p11691950134515"><a name="p11691950134515"></a><a name="p11691950134515"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.309999999999999%" headers="mcps1.1.9.1.4 "><p id="p1036213411462"><a name="p1036213411462"></a><a name="p1036213411462"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.33%" headers="mcps1.1.9.1.4 "><p id="p1184216298468"><a name="p1184216298468"></a><a name="p1184216298468"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.32%" headers="mcps1.1.9.1.4 "><p id="p1268214324614"><a name="p1268214324614"></a><a name="p1268214324614"></a>√</p>
</td>
</tr>
<tr id="row83201312163311"><td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.9.1.1 mcps1.1.9.2.1 "><p id="p1942713451002"><a name="p1942713451002"></a><a name="p1942713451002"></a>11</p>
</td>
<td class="cellrowborder" valign="top" width="28.83%" headers="mcps1.1.9.1.2 mcps1.1.9.2.2 "><p id="p032071210333"><a name="p032071210333"></a><a name="p032071210333"></a>AT+SLPREADTXPOWER</p>
</td>
<td class="cellrowborder" valign="top" width="22.040000000000003%" headers="mcps1.1.9.1.3 mcps1.1.9.2.3 "><p id="p1632041215330"><a name="p1632041215330"></a><a name="p1632041215330"></a>Read the SLP power value</p>
</td>
<td class="cellrowborder" valign="top" width="6.3100000000000005%" headers="mcps1.1.9.1.4 mcps1.1.9.2.4 "><p id="p1751519303454"><a name="p1751519303454"></a><a name="p1751519303454"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="10.34%" headers="mcps1.1.9.1.4 mcps1.1.9.2.5 "><p id="p5691185013451"><a name="p5691185013451"></a><a name="p5691185013451"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.309999999999999%" headers="mcps1.1.9.1.4 "><p id="p73622049464"><a name="p73622049464"></a><a name="p73622049464"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.33%" headers="mcps1.1.9.1.4 "><p id="p684282944614"><a name="p684282944614"></a><a name="p684282944614"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.32%" headers="mcps1.1.9.1.4 "><p id="p106826439465"><a name="p106826439465"></a><a name="p106826439465"></a>√</p>
</td>
</tr>
<tr id="row31356222333"><td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.9.1.1 mcps1.1.9.2.1 "><p id="p164271445207"><a name="p164271445207"></a><a name="p164271445207"></a>12</p>
</td>
<td class="cellrowborder" valign="top" width="28.83%" headers="mcps1.1.9.1.2 mcps1.1.9.2.2 "><p id="p201351822133314"><a name="p201351822133314"></a><a name="p201351822133314"></a>AT+SLPWRITETRXDELAY=&lt;parameters&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="22.040000000000003%" headers="mcps1.1.9.1.3 mcps1.1.9.2.3 "><p id="p17135822133314"><a name="p17135822133314"></a><a name="p17135822133314"></a>Write the SLP board-level and antenna delay calibration</p>
</td>
<td class="cellrowborder" valign="top" width="6.3100000000000005%" headers="mcps1.1.9.1.4 mcps1.1.9.2.4 "><p id="p19515830204515"><a name="p19515830204515"></a><a name="p19515830204515"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="10.34%" headers="mcps1.1.9.1.4 mcps1.1.9.2.5 "><p id="p11691165011451"><a name="p11691165011451"></a><a name="p11691165011451"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.309999999999999%" headers="mcps1.1.9.1.4 "><p id="p10362104194613"><a name="p10362104194613"></a><a name="p10362104194613"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.33%" headers="mcps1.1.9.1.4 "><p id="p784212944619"><a name="p784212944619"></a><a name="p784212944619"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.32%" headers="mcps1.1.9.1.4 "><p id="p12682134344614"><a name="p12682134344614"></a><a name="p12682134344614"></a>√</p>
</td>
</tr>
<tr id="row121211825133318"><td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.9.1.1 mcps1.1.9.2.1 "><p id="p19113457805"><a name="p19113457805"></a><a name="p19113457805"></a>13</p>
</td>
<td class="cellrowborder" valign="top" width="28.83%" headers="mcps1.1.9.1.2 mcps1.1.9.2.2 "><p id="p91211025103311"><a name="p91211025103311"></a><a name="p91211025103311"></a>AT+SLPREADTRXDELAY</p>
</td>
<td class="cellrowborder" valign="top" width="22.040000000000003%" headers="mcps1.1.9.1.3 mcps1.1.9.2.3 "><p id="p212162516337"><a name="p212162516337"></a><a name="p212162516337"></a>Read the SLP board-level and antenna delay calibration</p>
</td>
<td class="cellrowborder" valign="top" width="6.3100000000000005%" headers="mcps1.1.9.1.4 mcps1.1.9.2.4 "><p id="p14515163044511"><a name="p14515163044511"></a><a name="p14515163044511"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="10.34%" headers="mcps1.1.9.1.4 mcps1.1.9.2.5 "><p id="p4691165014459"><a name="p4691165014459"></a><a name="p4691165014459"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.309999999999999%" headers="mcps1.1.9.1.4 "><p id="p9362164114616"><a name="p9362164114616"></a><a name="p9362164114616"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.33%" headers="mcps1.1.9.1.4 "><p id="p1684262911466"><a name="p1684262911466"></a><a name="p1684262911466"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.32%" headers="mcps1.1.9.1.4 "><p id="p568213437469"><a name="p568213437469"></a><a name="p568213437469"></a>√</p>
</td>
</tr>
<tr id="row52471857122"><td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.9.1.1 mcps1.1.9.2.1 "><p id="p18304151519019"><a name="p18304151519019"></a><a name="p18304151519019"></a>14</p>
</td>
<td class="cellrowborder" valign="top" width="28.83%" headers="mcps1.1.9.1.2 mcps1.1.9.2.2 "><p id="p924711521217"><a name="p924711521217"></a><a name="p924711521217"></a>AT+SLPENABLEIMUDETECTION</p>
</td>
<td class="cellrowborder" valign="top" width="22.040000000000003%" headers="mcps1.1.9.1.3 mcps1.1.9.2.3 "><p id="p8247105151219"><a name="p8247105151219"></a><a name="p8247105151219"></a>Enable SLP IMU detection</p>
</td>
<td class="cellrowborder" valign="top" width="6.3100000000000005%" headers="mcps1.1.9.1.4 mcps1.1.9.2.4 "><p id="p524775181211"><a name="p524775181211"></a><a name="p524775181211"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="10.34%" headers="mcps1.1.9.1.4 mcps1.1.9.2.5 "><p id="p152471520128"><a name="p152471520128"></a><a name="p152471520128"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.309999999999999%" headers="mcps1.1.9.1.4 "><p id="p061011611616"><a name="p061011611616"></a><a name="p061011611616"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.33%" headers="mcps1.1.9.1.4 "><p id="p9613716171613"><a name="p9613716171613"></a><a name="p9613716171613"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.32%" headers="mcps1.1.9.1.4 "><p id="p13615141611615"><a name="p13615141611615"></a><a name="p13615141611615"></a>-</p>
</td>
</tr>
<tr id="row363415771120"><td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.9.1.1 mcps1.1.9.2.1 "><p id="p113042154018"><a name="p113042154018"></a><a name="p113042154018"></a>15</p>
</td>
<td class="cellrowborder" valign="top" width="28.83%" headers="mcps1.1.9.1.2 mcps1.1.9.2.2 "><p id="p13634185711114"><a name="p13634185711114"></a><a name="p13634185711114"></a>AT+SLPREADGYROZEROOFFSET</p>
</td>
<td class="cellrowborder" valign="top" width="22.040000000000003%" headers="mcps1.1.9.1.3 mcps1.1.9.2.3 "><p id="p163455781110"><a name="p163455781110"></a><a name="p163455781110"></a>Read the SLP GYRO zero offset value</p>
</td>
<td class="cellrowborder" valign="top" width="6.3100000000000005%" headers="mcps1.1.9.1.4 mcps1.1.9.2.4 "><p id="p195802651614"><a name="p195802651614"></a><a name="p195802651614"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="10.34%" headers="mcps1.1.9.1.4 mcps1.1.9.2.5 "><p id="p13961132613164"><a name="p13961132613164"></a><a name="p13961132613164"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.309999999999999%" headers="mcps1.1.9.1.4 "><p id="p1296352618169"><a name="p1296352618169"></a><a name="p1296352618169"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.33%" headers="mcps1.1.9.1.4 "><p id="p9965192615164"><a name="p9965192615164"></a><a name="p9965192615164"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.32%" headers="mcps1.1.9.1.4 "><p id="p17967132620163"><a name="p17967132620163"></a><a name="p17967132620163"></a>√</p>
</td>
</tr>
<tr id="row1389518019123"><td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.9.1.1 mcps1.1.9.2.1 "><p id="p4304141516012"><a name="p4304141516012"></a><a name="p4304141516012"></a>16</p>
</td>
<td class="cellrowborder" valign="top" width="28.83%" headers="mcps1.1.9.1.2 mcps1.1.9.2.2 "><p id="p989513071210"><a name="p989513071210"></a><a name="p989513071210"></a>AT+SLPSETRFSWPARAM=&lt;parameters&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="22.040000000000003%" headers="mcps1.1.9.1.3 mcps1.1.9.2.3 "><p id="p289512041213"><a name="p289512041213"></a><a name="p289512041213"></a>Set the SLP RF front-end configuration parameters</p>
</td>
<td class="cellrowborder" valign="top" width="6.3100000000000005%" headers="mcps1.1.9.1.4 mcps1.1.9.2.4 "><p id="p1571115345162"><a name="p1571115345162"></a><a name="p1571115345162"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="10.34%" headers="mcps1.1.9.1.4 mcps1.1.9.2.5 "><p id="p1714183415162"><a name="p1714183415162"></a><a name="p1714183415162"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.309999999999999%" headers="mcps1.1.9.1.4 "><p id="p371712343169"><a name="p371712343169"></a><a name="p371712343169"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.33%" headers="mcps1.1.9.1.4 "><p id="p1772073415166"><a name="p1772073415166"></a><a name="p1772073415166"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.32%" headers="mcps1.1.9.1.4 "><p id="p57221234111613"><a name="p57221234111613"></a><a name="p57221234111613"></a>√</p>
</td>
</tr>
<tr id="row15695131814131"><td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.9.1.1 mcps1.1.9.2.1 "><p id="p163041915605"><a name="p163041915605"></a><a name="p163041915605"></a>17</p>
</td>
<td class="cellrowborder" valign="top" width="28.83%" headers="mcps1.1.9.1.2 mcps1.1.9.2.2 "><p id="p20696141815133"><a name="p20696141815133"></a><a name="p20696141815133"></a>AT+SLPSETCURSORSPEED=&lt;parameters&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="22.040000000000003%" headers="mcps1.1.9.1.3 mcps1.1.9.2.3 "><p id="p1696121831310"><a name="p1696121831310"></a><a name="p1696121831310"></a>Set the SLP cursor sensitivity</p>
</td>
<td class="cellrowborder" valign="top" width="6.3100000000000005%" headers="mcps1.1.9.1.4 mcps1.1.9.2.4 "><p id="p1294323816164"><a name="p1294323816164"></a><a name="p1294323816164"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="10.34%" headers="mcps1.1.9.1.4 mcps1.1.9.2.5 "><p id="p1694517388168"><a name="p1694517388168"></a><a name="p1694517388168"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.309999999999999%" headers="mcps1.1.9.1.4 "><p id="p109471338201614"><a name="p109471338201614"></a><a name="p109471338201614"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.33%" headers="mcps1.1.9.1.4 "><p id="p4949163851619"><a name="p4949163851619"></a><a name="p4949163851619"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.32%" headers="mcps1.1.9.1.4 "><p id="p129511385162"><a name="p129511385162"></a><a name="p129511385162"></a>√</p>
</td>
</tr>
<tr id="row13551192218139"><td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.9.1.1 mcps1.1.9.2.1 "><p id="p6304415306"><a name="p6304415306"></a><a name="p6304415306"></a>18</p>
</td>
<td class="cellrowborder" valign="top" width="28.83%" headers="mcps1.1.9.1.2 mcps1.1.9.2.2 "><p id="p125516223131"><a name="p125516223131"></a><a name="p125516223131"></a>AT+SLPSETFTMODE=&lt;parameters&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="22.040000000000003%" headers="mcps1.1.9.1.3 mcps1.1.9.2.3 "><p id="p1755192271319"><a name="p1755192271319"></a><a name="p1755192271319"></a>Set the SLP production test mode</p>
</td>
<td class="cellrowborder" valign="top" width="6.3100000000000005%" headers="mcps1.1.9.1.4 mcps1.1.9.2.4 "><p id="p560764131612"><a name="p560764131612"></a><a name="p560764131612"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="10.34%" headers="mcps1.1.9.1.4 mcps1.1.9.2.5 "><p id="p13610341161616"><a name="p13610341161616"></a><a name="p13610341161616"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.309999999999999%" headers="mcps1.1.9.1.4 "><p id="p2061334131613"><a name="p2061334131613"></a><a name="p2061334131613"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.33%" headers="mcps1.1.9.1.4 "><p id="p18615164151611"><a name="p18615164151611"></a><a name="p18615164151611"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.32%" headers="mcps1.1.9.1.4 "><p id="p661744161615"><a name="p661744161615"></a><a name="p661744161615"></a>√</p>
</td>
</tr>
<tr id="row117930983318"><td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.9.1.1 mcps1.1.9.2.1 "><p id="p183045157012"><a name="p183045157012"></a><a name="p183045157012"></a>19</p>
</td>
<td class="cellrowborder" valign="top" width="28.83%" headers="mcps1.1.9.1.2 mcps1.1.9.2.2 "><p id="p1579329143311"><a name="p1579329143311"></a><a name="p1579329143311"></a>AT+SLPREADVERSION</p>
</td>
<td class="cellrowborder" valign="top" width="22.040000000000003%" headers="mcps1.1.9.1.3 mcps1.1.9.2.3 "><p id="p167931593335"><a name="p167931593335"></a><a name="p167931593335"></a>Read the SLP version information</p>
</td>
<td class="cellrowborder" valign="top" width="6.3100000000000005%" headers="mcps1.1.9.1.4 mcps1.1.9.2.4 "><p id="p12454329153414"><a name="p12454329153414"></a><a name="p12454329153414"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="10.34%" headers="mcps1.1.9.1.4 mcps1.1.9.2.5 "><p id="p945412911342"><a name="p945412911342"></a><a name="p945412911342"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.309999999999999%" headers="mcps1.1.9.1.4 "><p id="p16454142919347"><a name="p16454142919347"></a><a name="p16454142919347"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.33%" headers="mcps1.1.9.1.4 "><p id="p1445416297344"><a name="p1445416297344"></a><a name="p1445416297344"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.32%" headers="mcps1.1.9.1.4 "><p id="p745462917347"><a name="p745462917347"></a><a name="p745462917347"></a>√</p>
</td>
</tr>
<tr id="row27907160334"><td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.9.1.1 mcps1.1.9.2.1 "><p id="p630411519013"><a name="p630411519013"></a><a name="p630411519013"></a>20</p>
</td>
<td class="cellrowborder" valign="top" width="28.83%" headers="mcps1.1.9.1.2 mcps1.1.9.2.2 "><p id="p5790916153310"><a name="p5790916153310"></a><a name="p5790916153310"></a>AT+SLPSETTRANSFORM</p>
</td>
<td class="cellrowborder" valign="top" width="22.040000000000003%" headers="mcps1.1.9.1.3 mcps1.1.9.2.3 "><p id="p37901516193312"><a name="p37901516193312"></a><a name="p37901516193312"></a>Set the SLP coordinate transformation parameters</p>
</td>
<td class="cellrowborder" valign="top" width="6.3100000000000005%" headers="mcps1.1.9.1.4 mcps1.1.9.2.4 "><p id="p2079081653315"><a name="p2079081653315"></a><a name="p2079081653315"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="10.34%" headers="mcps1.1.9.1.4 mcps1.1.9.2.5 "><p id="p57907164333"><a name="p57907164333"></a><a name="p57907164333"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.309999999999999%" headers="mcps1.1.9.1.4 "><p id="p207907169333"><a name="p207907169333"></a><a name="p207907169333"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.33%" headers="mcps1.1.9.1.4 "><p id="p15790171653310"><a name="p15790171653310"></a><a name="p15790171653310"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.32%" headers="mcps1.1.9.1.4 "><p id="p67907167334"><a name="p67907167334"></a><a name="p67907167334"></a>-</p>
</td>
</tr>
<tr id="row127416204337"><td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.9.1.1 mcps1.1.9.2.1 "><p id="p83055152011"><a name="p83055152011"></a><a name="p83055152011"></a>21</p>
</td>
<td class="cellrowborder" valign="top" width="28.83%" headers="mcps1.1.9.1.2 mcps1.1.9.2.2 "><p id="p17742152011338"><a name="p17742152011338"></a><a name="p17742152011338"></a>AT+SLPSETINSTPARA</p>
</td>
<td class="cellrowborder" valign="top" width="22.040000000000003%" headers="mcps1.1.9.1.3 mcps1.1.9.2.3 "><p id="p574232083319"><a name="p574232083319"></a><a name="p574232083319"></a>Set the SLP installation parameters</p>
</td>
<td class="cellrowborder" valign="top" width="6.3100000000000005%" headers="mcps1.1.9.1.4 mcps1.1.9.2.4 "><p id="p174272015331"><a name="p174272015331"></a><a name="p174272015331"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="10.34%" headers="mcps1.1.9.1.4 mcps1.1.9.2.5 "><p id="p174212010337"><a name="p174212010337"></a><a name="p174212010337"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.309999999999999%" headers="mcps1.1.9.1.4 "><p id="p374292012337"><a name="p374292012337"></a><a name="p374292012337"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.33%" headers="mcps1.1.9.1.4 "><p id="p87424203335"><a name="p87424203335"></a><a name="p87424203335"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.32%" headers="mcps1.1.9.1.4 "><p id="p1074262017332"><a name="p1074262017332"></a><a name="p1074262017332"></a>-</p>
</td>
</tr>
<tr id="row887075019559"><td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.9.1.1 mcps1.1.9.2.1 "><p id="p830521513012"><a name="p830521513012"></a><a name="p830521513012"></a>22</p>
</td>
<td class="cellrowborder" valign="top" width="28.83%" headers="mcps1.1.9.1.2 mcps1.1.9.2.2 "><p id="p1787075055518"><a name="p1787075055518"></a><a name="p1787075055518"></a>AT+SLPSETCLICK</p>
</td>
<td class="cellrowborder" valign="top" width="22.040000000000003%" headers="mcps1.1.9.1.3 mcps1.1.9.2.3 "><p id="p5870165011557"><a name="p5870165011557"></a><a name="p5870165011557"></a>Set the SLP key state</p>
</td>
<td class="cellrowborder" valign="top" width="6.3100000000000005%" headers="mcps1.1.9.1.4 mcps1.1.9.2.4 "><p id="p181431517155614"><a name="p181431517155614"></a><a name="p181431517155614"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="10.34%" headers="mcps1.1.9.1.4 mcps1.1.9.2.5 "><p id="p13143131795612"><a name="p13143131795612"></a><a name="p13143131795612"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.309999999999999%" headers="mcps1.1.9.1.4 "><p id="p1958811795617"><a name="p1958811795617"></a><a name="p1958811795617"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.33%" headers="mcps1.1.9.1.4 "><p id="p498462155616"><a name="p498462155616"></a><a name="p498462155616"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.32%" headers="mcps1.1.9.1.4 "><p id="p18984102185612"><a name="p18984102185612"></a><a name="p18984102185612"></a>√</p>
</td>
</tr>
<tr id="row6302171813115"><td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.9.1.1 mcps1.1.9.2.1 "><p id="p230318181117"><a name="p230318181117"></a><a name="p230318181117"></a>23</p>
</td>
<td class="cellrowborder" valign="top" width="28.83%" headers="mcps1.1.9.1.2 mcps1.1.9.2.2 "><p id="p630321812113"><a name="p630321812113"></a><a name="p630321812113"></a>AT+SLPREADTSENSOR</p>
</td>
<td class="cellrowborder" valign="top" width="22.040000000000003%" headers="mcps1.1.9.1.3 mcps1.1.9.2.3 "><p id="p129941187212"><a name="p129941187212"></a><a name="p129941187212"></a>Read the SLP temperature</p>
</td>
<td class="cellrowborder" valign="top" width="6.3100000000000005%" headers="mcps1.1.9.1.4 mcps1.1.9.2.4 "><p id="p1630310181914"><a name="p1630310181914"></a><a name="p1630310181914"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="10.34%" headers="mcps1.1.9.1.4 mcps1.1.9.2.5 "><p id="p123035184115"><a name="p123035184115"></a><a name="p123035184115"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.309999999999999%" headers="mcps1.1.9.1.4 "><p id="p33034181111"><a name="p33034181111"></a><a name="p33034181111"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.33%" headers="mcps1.1.9.1.4 "><p id="p1430371814117"><a name="p1430371814117"></a><a name="p1430371814117"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.32%" headers="mcps1.1.9.1.4 "><p id="p1130316181914"><a name="p1130316181914"></a><a name="p1130316181914"></a>√</p>
</td>
</tr>
<tr id="row1348513211015"><td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.9.1.1 mcps1.1.9.2.1 "><p id="p648512113114"><a name="p648512113114"></a><a name="p648512113114"></a>24</p>
</td>
<td class="cellrowborder" valign="top" width="28.83%" headers="mcps1.1.9.1.2 mcps1.1.9.2.2 "><p id="p1848552119114"><a name="p1848552119114"></a><a name="p1848552119114"></a>AT+SLPSETLOGLEVEL</p>
</td>
<td class="cellrowborder" valign="top" width="22.040000000000003%" headers="mcps1.1.9.1.3 mcps1.1.9.2.3 "><p id="p44851211115"><a name="p44851211115"></a><a name="p44851211115"></a>Set the SLP log print level</p>
</td>
<td class="cellrowborder" valign="top" width="6.3100000000000005%" headers="mcps1.1.9.1.4 mcps1.1.9.2.4 "><p id="p3485221511"><a name="p3485221511"></a><a name="p3485221511"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="10.34%" headers="mcps1.1.9.1.4 mcps1.1.9.2.5 "><p id="p9485112112119"><a name="p9485112112119"></a><a name="p9485112112119"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.309999999999999%" headers="mcps1.1.9.1.4 "><p id="p74851221612"><a name="p74851221612"></a><a name="p74851221612"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.33%" headers="mcps1.1.9.1.4 "><p id="p44851021517"><a name="p44851021517"></a><a name="p44851021517"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.32%" headers="mcps1.1.9.1.4 "><p id="p948582117111"><a name="p948582117111"></a><a name="p948582117111"></a>√</p>
</td>
</tr>
<tr id="row206401459110"><td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.9.1.1 mcps1.1.9.2.1 "><p id="p16640204510110"><a name="p16640204510110"></a><a name="p16640204510110"></a>25</p>
</td>
<td class="cellrowborder" valign="top" width="28.83%" headers="mcps1.1.9.1.2 mcps1.1.9.2.2 "><p id="p1064014454113"><a name="p1064014454113"></a><a name="p1064014454113"></a>AT+SLPDISABLEIMUDETECTION</p>
</td>
<td class="cellrowborder" valign="top" width="22.040000000000003%" headers="mcps1.1.9.1.3 mcps1.1.9.2.3 "><p id="p1064015451615"><a name="p1064015451615"></a><a name="p1064015451615"></a>Disable SLP IMU detection</p>
</td>
<td class="cellrowborder" valign="top" width="6.3100000000000005%" headers="mcps1.1.9.1.4 mcps1.1.9.2.4 "><p id="p1764014517120"><a name="p1764014517120"></a><a name="p1764014517120"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="10.34%" headers="mcps1.1.9.1.4 mcps1.1.9.2.5 "><p id="p16408451615"><a name="p16408451615"></a><a name="p16408451615"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.309999999999999%" headers="mcps1.1.9.1.4 "><p id="p564010456113"><a name="p564010456113"></a><a name="p564010456113"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.33%" headers="mcps1.1.9.1.4 "><p id="p3640745919"><a name="p3640745919"></a><a name="p3640745919"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.32%" headers="mcps1.1.9.1.4 "><p id="p2640745214"><a name="p2640745214"></a><a name="p2640745214"></a>-</p>
</td>
</tr>
<tr id="row1765685142318"><td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.9.1.1 mcps1.1.9.2.1 "><p id="p7548241194618"><a name="p7548241194618"></a><a name="p7548241194618"></a>26</p>
</td>
<td class="cellrowborder" valign="top" width="28.83%" headers="mcps1.1.9.1.2 mcps1.1.9.2.2 "><p id="p1412715017473"><a name="p1412715017473"></a><a name="p1412715017473"></a>AT+SLPSETIMURPTFREQ</p>
</td>
<td class="cellrowborder" valign="top" width="22.040000000000003%" headers="mcps1.1.9.1.3 mcps1.1.9.2.3 "><p id="p171273094711"><a name="p171273094711"></a><a name="p171273094711"></a>Set the SLP IMU raw data reporting frequency</p>
</td>
<td class="cellrowborder" valign="top" width="6.3100000000000005%" headers="mcps1.1.9.1.4 mcps1.1.9.2.4 "><p id="p1612712094718"><a name="p1612712094718"></a><a name="p1612712094718"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="10.34%" headers="mcps1.1.9.1.4 mcps1.1.9.2.5 "><p id="p01272017476"><a name="p01272017476"></a><a name="p01272017476"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.309999999999999%" headers="mcps1.1.9.1.4 "><p id="p161276011475"><a name="p161276011475"></a><a name="p161276011475"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.33%" headers="mcps1.1.9.1.4 "><p id="p201273044710"><a name="p201273044710"></a><a name="p201273044710"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.32%" headers="mcps1.1.9.1.4 "><p id="p1712710094715"><a name="p1712710094715"></a><a name="p1712710094715"></a>√</p>
</td>
</tr>
<tr id="row3121997239"><td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.9.1.1 mcps1.1.9.2.1 "><p id="p1033312974715"><a name="p1033312974715"></a><a name="p1033312974715"></a>27</p>
</td>
<td class="cellrowborder" valign="top" width="28.83%" headers="mcps1.1.9.1.2 mcps1.1.9.2.2 "><p id="p73331297473"><a name="p73331297473"></a><a name="p73331297473"></a>AT+SLPSETCORRECTMODE</p>
</td>
<td class="cellrowborder" valign="top" width="22.040000000000003%" headers="mcps1.1.9.1.3 mcps1.1.9.2.3 "><p id="p143336293476"><a name="p143336293476"></a><a name="p143336293476"></a>Set the SLP cursor correction mode</p>
</td>
<td class="cellrowborder" valign="top" width="6.3100000000000005%" headers="mcps1.1.9.1.4 mcps1.1.9.2.4 "><p id="p123334295470"><a name="p123334295470"></a><a name="p123334295470"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="10.34%" headers="mcps1.1.9.1.4 mcps1.1.9.2.5 "><p id="p103332293478"><a name="p103332293478"></a><a name="p103332293478"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.309999999999999%" headers="mcps1.1.9.1.4 "><p id="p13333529174711"><a name="p13333529174711"></a><a name="p13333529174711"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.33%" headers="mcps1.1.9.1.4 "><p id="p19333229194711"><a name="p19333229194711"></a><a name="p19333229194711"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.32%" headers="mcps1.1.9.1.4 "><p id="p183335296474"><a name="p183335296474"></a><a name="p183335296474"></a>√</p>
</td>
</tr>
<tr id="row14745161113418"><td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.9.1.1 mcps1.1.9.2.1 "><p id="p197501725133319"><a name="p197501725133319"></a><a name="p197501725133319"></a>28</p>
</td>
<td class="cellrowborder" valign="top" width="28.83%" headers="mcps1.1.9.1.2 mcps1.1.9.2.2 "><p id="p4750925113318"><a name="p4750925113318"></a><a name="p4750925113318"></a>AT+SLPREADDIEID</p>
</td>
<td class="cellrowborder" valign="top" width="22.040000000000003%" headers="mcps1.1.9.1.3 mcps1.1.9.2.3 "><p id="p9750525123318"><a name="p9750525123318"></a><a name="p9750525123318"></a>Read the SLP chip DIE ID</p>
</td>
<td class="cellrowborder" valign="top" width="6.3100000000000005%" headers="mcps1.1.9.1.4 mcps1.1.9.2.4 "><p id="p1275012553315"><a name="p1275012553315"></a><a name="p1275012553315"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="10.34%" headers="mcps1.1.9.1.4 mcps1.1.9.2.5 "><p id="p1175092518332"><a name="p1175092518332"></a><a name="p1175092518332"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.309999999999999%" headers="mcps1.1.9.1.4 "><p id="p117501725113317"><a name="p117501725113317"></a><a name="p117501725113317"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.33%" headers="mcps1.1.9.1.4 "><p id="p1275082514339"><a name="p1275082514339"></a><a name="p1275082514339"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.32%" headers="mcps1.1.9.1.4 "><p id="p18751202513338"><a name="p18751202513338"></a><a name="p18751202513338"></a>√</p>
</td>
</tr>
<tr id="row3870035103612"><td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.9.1.1 mcps1.1.9.2.1 "><p id="p112256842317"><a name="p112256842317"></a><a name="p112256842317"></a>29</p>
</td>
<td class="cellrowborder" valign="top" width="28.83%" headers="mcps1.1.9.1.2 mcps1.1.9.2.2 "><p id="p9681105317348"><a name="p9681105317348"></a><a name="p9681105317348"></a>AT+SLPRCUSLEEP</p>
</td>
<td class="cellrowborder" valign="top" width="22.040000000000003%" headers="mcps1.1.9.1.3 mcps1.1.9.2.3 "><p id="p82259802315"><a name="p82259802315"></a><a name="p82259802315"></a>Put the RCU side into system sleep</p>
</td>
<td class="cellrowborder" valign="top" width="6.3100000000000005%" headers="mcps1.1.9.1.4 mcps1.1.9.2.4 "><p id="p822688162311"><a name="p822688162311"></a><a name="p822688162311"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="10.34%" headers="mcps1.1.9.1.4 mcps1.1.9.2.5 "><p id="p92261689237"><a name="p92261689237"></a><a name="p92261689237"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.309999999999999%" headers="mcps1.1.9.1.4 "><p id="p922668142314"><a name="p922668142314"></a><a name="p922668142314"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.33%" headers="mcps1.1.9.1.4 "><p id="p1522614816236"><a name="p1522614816236"></a><a name="p1522614816236"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.32%" headers="mcps1.1.9.1.4 "><p id="p12226684235"><a name="p12226684235"></a><a name="p12226684235"></a>-</p>
</td>
</tr>
<tr id="row13691639153611"><td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.9.1.1 mcps1.1.9.2.1 "><p id="p8117712162313"><a name="p8117712162313"></a><a name="p8117712162313"></a>30</p>
</td>
<td class="cellrowborder" valign="top" width="28.83%" headers="mcps1.1.9.1.2 mcps1.1.9.2.2 "><p id="p875022318263"><a name="p875022318263"></a><a name="p875022318263"></a>AT+SLPAMDISCONNECT</p>
</td>
<td class="cellrowborder" valign="top" width="22.040000000000003%" headers="mcps1.1.9.1.3 mcps1.1.9.2.3 "><p id="p8117121217234"><a name="p8117121217234"></a><a name="p8117121217234"></a>On the RCU side, the SLE actively disconnects and disables broadcasting without clearing the pairing records</p>
</td>
<td class="cellrowborder" valign="top" width="6.3100000000000005%" headers="mcps1.1.9.1.4 mcps1.1.9.2.4 "><p id="p1811712127231"><a name="p1811712127231"></a><a name="p1811712127231"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="10.34%" headers="mcps1.1.9.1.4 mcps1.1.9.2.5 "><p id="p711741218237"><a name="p711741218237"></a><a name="p711741218237"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.309999999999999%" headers="mcps1.1.9.1.4 "><p id="p16117212142314"><a name="p16117212142314"></a><a name="p16117212142314"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.33%" headers="mcps1.1.9.1.4 "><p id="p2117101252312"><a name="p2117101252312"></a><a name="p2117101252312"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.32%" headers="mcps1.1.9.1.4 "><p id="p1111791214231"><a name="p1111791214231"></a><a name="p1111791214231"></a>√</p>
</td>
</tr>
<tr id="row6877204263616"><td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.9.1.1 mcps1.1.9.2.1 "><p id="p10714214122312"><a name="p10714214122312"></a><a name="p10714214122312"></a>31</p>
</td>
<td class="cellrowborder" valign="top" width="28.83%" headers="mcps1.1.9.1.2 mcps1.1.9.2.2 "><p id="p7321646142614"><a name="p7321646142614"></a><a name="p7321646142614"></a>AT+SLPAMSTARTANNOUNCE</p>
</td>
<td class="cellrowborder" valign="top" width="22.040000000000003%" headers="mcps1.1.9.1.3 mcps1.1.9.2.3 "><p id="p1671517146231"><a name="p1671517146231"></a><a name="p1671517146231"></a>Enable broadcasting on the RCU side</p>
</td>
<td class="cellrowborder" valign="top" width="6.3100000000000005%" headers="mcps1.1.9.1.4 mcps1.1.9.2.4 "><p id="p871511418237"><a name="p871511418237"></a><a name="p871511418237"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="10.34%" headers="mcps1.1.9.1.4 mcps1.1.9.2.5 "><p id="p571519141236"><a name="p571519141236"></a><a name="p571519141236"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.309999999999999%" headers="mcps1.1.9.1.4 "><p id="p2715314172315"><a name="p2715314172315"></a><a name="p2715314172315"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.33%" headers="mcps1.1.9.1.4 "><p id="p187151142235"><a name="p187151142235"></a><a name="p187151142235"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.32%" headers="mcps1.1.9.1.4 "><p id="p1715121472318"><a name="p1715121472318"></a><a name="p1715121472318"></a>√</p>
</td>
</tr>
<tr id="row1977814563614"><td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.9.1.1 mcps1.1.9.2.1 "><p id="p1579541814235"><a name="p1579541814235"></a><a name="p1579541814235"></a>32</p>
</td>
<td class="cellrowborder" valign="top" width="28.83%" headers="mcps1.1.9.1.2 mcps1.1.9.2.2 "><p id="p1937888102717"><a name="p1937888102717"></a><a name="p1937888102717"></a>AT+AMSETCURSORSPEED=&lt;mode&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="22.040000000000003%" headers="mcps1.1.9.1.3 mcps1.1.9.2.3 "><p id="p279571842313"><a name="p279571842313"></a><a name="p279571842313"></a>On the Dongle side, switch the pointing cursor speed and update the log print flag</p>
</td>
<td class="cellrowborder" valign="top" width="6.3100000000000005%" headers="mcps1.1.9.1.4 mcps1.1.9.2.4 "><p id="p14174123883112"><a name="p14174123883112"></a><a name="p14174123883112"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="10.34%" headers="mcps1.1.9.1.4 mcps1.1.9.2.5 "><p id="p1617423853119"><a name="p1617423853119"></a><a name="p1617423853119"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.309999999999999%" headers="mcps1.1.9.1.4 "><p id="p13174438203117"><a name="p13174438203117"></a><a name="p13174438203117"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.33%" headers="mcps1.1.9.1.4 "><p id="p191756385318"><a name="p191756385318"></a><a name="p191756385318"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.32%" headers="mcps1.1.9.1.4 "><p id="p41751386315"><a name="p41751386315"></a><a name="p41751386315"></a>√</p>
</td>
</tr>
<tr id="row8513164914239"><td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.9.1.1 mcps1.1.9.2.1 "><p id="p1148354712920"><a name="p1148354712920"></a><a name="p1148354712920"></a>33</p>
</td>
<td class="cellrowborder" valign="top" width="28.83%" headers="mcps1.1.9.1.2 mcps1.1.9.2.2 "><p id="p18483174720917"><a name="p18483174720917"></a><a name="p18483174720917"></a>AT+SLPREADTRIANTCALIPARA</p>
</td>
<td class="cellrowborder" valign="top" width="22.040000000000003%" headers="mcps1.1.9.1.3 mcps1.1.9.2.3 "><p id="p8483747293"><a name="p8483747293"></a><a name="p8483747293"></a>Read the SLP three-antenna calibration parameters</p>
</td>
<td class="cellrowborder" valign="top" width="6.3100000000000005%" headers="mcps1.1.9.1.4 mcps1.1.9.2.4 "><p id="p1448318478918"><a name="p1448318478918"></a><a name="p1448318478918"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="10.34%" headers="mcps1.1.9.1.4 mcps1.1.9.2.5 "><p id="p348317472913"><a name="p348317472913"></a><a name="p348317472913"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.309999999999999%" headers="mcps1.1.9.1.4 "><p id="p6483184711910"><a name="p6483184711910"></a><a name="p6483184711910"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.33%" headers="mcps1.1.9.1.4 "><p id="p144831847598"><a name="p144831847598"></a><a name="p144831847598"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.32%" headers="mcps1.1.9.1.4 "><p id="p948324712918"><a name="p948324712918"></a><a name="p948324712918"></a>√</p>
</td>
</tr>
<tr id="row119281052112320"><td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.9.1.1 mcps1.1.9.2.1 "><p id="p142608512916"><a name="p142608512916"></a><a name="p142608512916"></a>34</p>
</td>
<td class="cellrowborder" valign="top" width="28.83%" headers="mcps1.1.9.1.2 mcps1.1.9.2.2 "><p id="p152609511794"><a name="p152609511794"></a><a name="p152609511794"></a>AT+SLPWRITETRIANTCALIPARA=&lt;parameters&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="22.040000000000003%" headers="mcps1.1.9.1.3 mcps1.1.9.2.3 "><p id="p526055115917"><a name="p526055115917"></a><a name="p526055115917"></a>Write the SLP three-antenna calibration parameters</p>
</td>
<td class="cellrowborder" valign="top" width="6.3100000000000005%" headers="mcps1.1.9.1.4 mcps1.1.9.2.4 "><p id="p11260115113918"><a name="p11260115113918"></a><a name="p11260115113918"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="10.34%" headers="mcps1.1.9.1.4 mcps1.1.9.2.5 "><p id="p626018511917"><a name="p626018511917"></a><a name="p626018511917"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.309999999999999%" headers="mcps1.1.9.1.4 "><p id="p22604516913"><a name="p22604516913"></a><a name="p22604516913"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.33%" headers="mcps1.1.9.1.4 "><p id="p526045113912"><a name="p526045113912"></a><a name="p526045113912"></a>√</p>
</td>
<td class="cellrowborder" valign="top" width="8.32%" headers="mcps1.1.9.1.4 "><p id="p1226016512910"><a name="p1226016512910"></a><a name="p1226016512910"></a>√</p>
</td>
</tr>
</tbody>
</table>

-   **[SLP Power-on Loading](#ZH-CN_TOPIC_0000002219226389)**  

-   **[SLP Power-off](#ZH-CN_TOPIC_0000002219226385)**  

-   **[SLP Sleep](#ZH-CN_TOPIC_0000002219311953)**  

-   **[SLP Start Ranging](#ZH-CN_TOPIC_0000002183826184)**  

-   **[SLP Stop Ranging](#ZH-CN_TOPIC_0000002183985848)**  

-   **[SLP Pause Ranging](#ZH-CN_TOPIC_0000002219311949)**  

-   **[SLP Continue Ranging](#ZH-CN_TOPIC_0000002183826180)**  

-   **[SLP Write Angle Measurement Calibration Value](#ZH-CN_TOPIC_0000002219311929)**  

-   **[SLP Read Angle Measurement Calibration Value](#ZH-CN_TOPIC_0000002183985832)**  

-   **[SLP Write TX Transmit Power Codeword](#ZH-CN_TOPIC_0000002183985824)**  

-   **[SLP Read TX Transmit Power Codeword](#ZH-CN_TOPIC_0000002183985840)**  

-   **[SLP Write Board-Level and Antenna Delay Calibration Value](#ZH-CN_TOPIC_0000002183826196)**  

-   **[SLP Read Board-Level and Antenna Delay Calibration Value](#ZH-CN_TOPIC_0000002219311941)**  

-   **[SLP Enable IMU Detection](#ZH-CN_TOPIC_0000002371423284)**  

-   **[SLP Read GYRO Zero Offset Value](#ZH-CN_TOPIC_0000002405262773)**  

-   **[SLP Set RF Front-End Configuration Parameters](#ZH-CN_TOPIC_0000002405142921)**  

-   **[SLP Set Cursor Sensitivity](#ZH-CN_TOPIC_0000002371585692)**  

-   **[SLP Set Production Test Mode](#ZH-CN_TOPIC_0000002405265461)**  

-   **[SLP Read Version Information](#ZH-CN_TOPIC_0000002371586072)**  

-   **[SLP Set Coordinate Transformation Parameters](#ZH-CN_TOPIC_0000002481431717)**  

-   **[SLP Set Installation Parameters](#ZH-CN_TOPIC_0000002481631685)**  

-   **[SLP Set Key State](#ZH-CN_TOPIC_0000002453803022)**  

-   **[SLP Read Temperature Value](#ZH-CN_TOPIC_0000002513368031)**  

-   **[SLP Set Log Print Level](#ZH-CN_TOPIC_0000002513488003)**  

-   **[SLP Disable IMU Detection](#ZH-CN_TOPIC_0000002481568130)**  

-   **[SLP Set IMU Raw Data Reporting Frequency](#ZH-CN_TOPIC_0000002509642402)**  

-   **[SLP Set Cursor Correction Mode](#ZH-CN_TOPIC_0000002509682422)**  

-   **[SLP Read Chip DIE ID](#ZH-CN_TOPIC_0000002551238893)**  

-   **[RCU Side System Sleep](#ZH-CN_TOPIC_0000002543745535)**  

-   **[RCU Side SLE Active Disconnection with Broadcast Disabled but Pairing Records Not Cleared](#ZH-CN_TOPIC_0000002543825541)**  

-   **[RCU Side Enable Broadcasting](#ZH-CN_TOPIC_0000002543745533)**  

-   **[Dongle Side Switch Pointing Cursor Speed and Update Log Print Flag](#ZH-CN_TOPIC_0000002543825539)**  

-   **[SLP Read Three-Antenna Calibration Parameters](#ZH-CN_TOPIC_0000002522946218)**  

-   **[SLP Write Three-Antenna Calibration Parameters](#ZH-CN_TOPIC_0000002522786214)**  

-   **[Dongle Side Read Screen Size Parameters](#ZH-CN_TOPIC_0000002531808984)**  

-   **[Dongle Side Set Preset Screen Size Parameters](#ZH-CN_TOPIC_0000002531649448)**  

-   **[Dongle Side Set Custom Screen Size Parameters](#ZH-CN_TOPIC_0000002562729317)**  

-   **[Dongle Side Read Coordinate Reporting Rate](#ZH-CN_TOPIC_0000002531809378)**  

-   **[Dongle Side Set Coordinate Reporting Rate](#ZH-CN_TOPIC_0000002562569353)**  

-   **[AT Command Usage Description](#ZH-CN_TOPIC_0000002183826172)**  

## SLP Power-on Loading<a name="ZH-CN_TOPIC_0000002219226389"></a>

<a name="table102mcpsimp"></a>
<table><tbody><tr id="row107mcpsimp"><th class="firstcol" valign="top" width="13.819999999999999%" id="mcps1.1.3.1.1"><p id="p109mcpsimp"><a name="p109mcpsimp"></a><a name="p109mcpsimp"></a>Format</p>
</th>
<td class="cellrowborder" valign="top" width="86.18%" headers="mcps1.1.3.1.1 "><p id="p111mcpsimp"><a name="p111mcpsimp"></a><a name="p111mcpsimp"></a>AT+SLPPOWERON</p>
</td>
</tr>
<tr id="row112mcpsimp"><th class="firstcol" valign="top" width="13.819999999999999%" id="mcps1.1.3.2.1"><p id="p114mcpsimp"><a name="p114mcpsimp"></a><a name="p114mcpsimp"></a>Response</p>
</th>
<td class="cellrowborder" valign="top" width="86.18%" headers="mcps1.1.3.2.1 "><p id="p116mcpsimp"><a name="p116mcpsimp"></a><a name="p116mcpsimp"></a>On success: OK;</p>
<p id="p118mcpsimp"><a name="p118mcpsimp"></a><a name="p118mcpsimp"></a>On failure: ERROR.</p>
</td>
</tr>
<tr id="row119mcpsimp"><th class="firstcol" valign="top" width="13.819999999999999%" id="mcps1.1.3.3.1"><p id="p121mcpsimp"><a name="p121mcpsimp"></a><a name="p121mcpsimp"></a>Parameter Description</p>
</th>
<td class="cellrowborder" valign="top" width="86.18%" headers="mcps1.1.3.3.1 "><p id="p123mcpsimp"><a name="p123mcpsimp"></a><a name="p123mcpsimp"></a>-</p>
</td>
</tr>
<tr id="row124mcpsimp"><th class="firstcol" valign="top" width="13.819999999999999%" id="mcps1.1.3.4.1"><p id="p126mcpsimp"><a name="p126mcpsimp"></a><a name="p126mcpsimp"></a>Example</p>
</th>
<td class="cellrowborder" valign="top" width="86.18%" headers="mcps1.1.3.4.1 "><p id="p128mcpsimp"><a name="p128mcpsimp"></a><a name="p128mcpsimp"></a>AT+SLPPOWERON</p>
</td>
</tr>
<tr id="row129mcpsimp"><th class="firstcol" valign="top" width="13.819999999999999%" id="mcps1.1.3.5.1"><p id="p131mcpsimp"><a name="p131mcpsimp"></a><a name="p131mcpsimp"></a>Note</p>
</th>
<td class="cellrowborder" valign="top" width="86.18%" headers="mcps1.1.3.5.1 "><p id="p133mcpsimp"><a name="p133mcpsimp"></a><a name="p133mcpsimp"></a>-</p>
</td>
</tr>
</tbody>
</table>

## SLP Power-off<a name="ZH-CN_TOPIC_0000002219226385"></a>

<a name="table135mcpsimp"></a>
<table><tbody><tr id="row140mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.1.1"><p id="p142mcpsimp"><a name="p142mcpsimp"></a><a name="p142mcpsimp"></a>Format</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.1.1 "><p id="p144mcpsimp"><a name="p144mcpsimp"></a><a name="p144mcpsimp"></a>AT+SLPPOWEROFF</p>
</td>
</tr>
<tr id="row145mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.2.1"><p id="p147mcpsimp"><a name="p147mcpsimp"></a><a name="p147mcpsimp"></a>Response</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.2.1 "><p id="p116mcpsimp"><a name="p116mcpsimp"></a><a name="p116mcpsimp"></a>On success: OK;</p>
<p id="p118mcpsimp"><a name="p118mcpsimp"></a><a name="p118mcpsimp"></a>On failure: ERROR.</p>
</td>
</tr>
<tr id="row152mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.3.1"><p id="p154mcpsimp"><a name="p154mcpsimp"></a><a name="p154mcpsimp"></a>Parameter Description</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.3.1 "><p id="p344311333535"><a name="p344311333535"></a><a name="p344311333535"></a>-</p>
</td>
</tr>
<tr id="row157mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.4.1"><p id="p159mcpsimp"><a name="p159mcpsimp"></a><a name="p159mcpsimp"></a>Example</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.4.1 "><p id="p161mcpsimp"><a name="p161mcpsimp"></a><a name="p161mcpsimp"></a>AT+SLPPOWEROFF</p>
</td>
</tr>
<tr id="row162mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.5.1"><p id="p164mcpsimp"><a name="p164mcpsimp"></a><a name="p164mcpsimp"></a>Note</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.5.1 "><p id="p166mcpsimp"><a name="p166mcpsimp"></a><a name="p166mcpsimp"></a>-</p>
</td>
</tr>
</tbody>
</table>

## SLP Sleep<a name="ZH-CN_TOPIC_0000002219311953"></a>

<a name="table135mcpsimp"></a>
<table><tbody><tr id="row140mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.1.1"><p id="p142mcpsimp"><a name="p142mcpsimp"></a><a name="p142mcpsimp"></a>Format</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.1.1 "><p id="p144mcpsimp"><a name="p144mcpsimp"></a><a name="p144mcpsimp"></a>AT+SLPSLEEP</p>
</td>
</tr>
<tr id="row145mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.2.1"><p id="p147mcpsimp"><a name="p147mcpsimp"></a><a name="p147mcpsimp"></a>Response</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.2.1 "><p id="p116mcpsimp"><a name="p116mcpsimp"></a><a name="p116mcpsimp"></a>On success: OK;</p>
<p id="p118mcpsimp"><a name="p118mcpsimp"></a><a name="p118mcpsimp"></a>On failure: ERROR.</p>
</td>
</tr>
<tr id="row152mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.3.1"><p id="p154mcpsimp"><a name="p154mcpsimp"></a><a name="p154mcpsimp"></a>Parameter Description</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.3.1 "><p id="p344311333535"><a name="p344311333535"></a><a name="p344311333535"></a>-</p>
</td>
</tr>
<tr id="row157mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.4.1"><p id="p159mcpsimp"><a name="p159mcpsimp"></a><a name="p159mcpsimp"></a>Example</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.4.1 "><p id="p161mcpsimp"><a name="p161mcpsimp"></a><a name="p161mcpsimp"></a>AT+SLPSLEEP</p>
</td>
</tr>
<tr id="row162mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.5.1"><p id="p164mcpsimp"><a name="p164mcpsimp"></a><a name="p164mcpsimp"></a>Note</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.5.1 "><p id="p166mcpsimp"><a name="p166mcpsimp"></a><a name="p166mcpsimp"></a>-</p>
</td>
</tr>
</tbody>
</table>

## SLP Start Ranging<a name="ZH-CN_TOPIC_0000002183826184"></a>

<a name="table171mcpsimp"></a>
<table><tbody><tr id="row176mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.1.1"><p id="p178mcpsimp"><a name="p178mcpsimp"></a><a name="p178mcpsimp"></a>Format</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.1.1 "><p id="p180mcpsimp"><a name="p180mcpsimp"></a><a name="p180mcpsimp"></a>AT+SLPSTARTRANGING=&lt;usageMode,rangingMode,aoxDirection,mrSource,roundNum,rangingFreq,txMode,txPowerHigh,txPowerLow&gt;</p>
</td>
</tr>
<tr id="row181mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.2.1"><p id="p183mcpsimp"><a name="p183mcpsimp"></a><a name="p183mcpsimp"></a>Response</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.2.1 "><p id="p116mcpsimp"><a name="p116mcpsimp"></a><a name="p116mcpsimp"></a>On success: OK;</p>
<p id="p118mcpsimp"><a name="p118mcpsimp"></a><a name="p118mcpsimp"></a>On failure: ERROR.</p>
</td>
</tr>
<tr id="row188mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.3.1"><p id="p190mcpsimp"><a name="p190mcpsimp"></a><a name="p190mcpsimp"></a>Parameter Description</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.3.1 "><a name="ul193881124125412"></a><a name="ul193881124125412"></a><ul id="ul193881124125412"><li>&lt;usageMode&gt;: Usage mode.<p id="p1442021585520"><a name="p1442021585520"></a><a name="p1442021585520"></a>0: Ranging and angle measurement mode;</p>
<p id="p9460191375518"><a name="p9460191375518"></a><a name="p9460191375518"></a>1: Air mouse mode.</p>
<p id="p76911629455"><a name="p76911629455"></a><a name="p76911629455"></a>2: Vehicle air mouse mode;</p>
</li><li>&lt;rangingMode&gt;: Ranging mode.<p id="p167692615510"><a name="p167692615510"></a><a name="p167692615510"></a>0: Ranging only;</p>
<p id="p331916818551"><a name="p331916818551"></a><a name="p331916818551"></a>1: Ranging and AOA angle measurement;</p>
<p id="p1310119418557"><a name="p1310119418557"></a><a name="p1310119418557"></a>2: Ranging and AOD angle measurement.</p>
</li><li>&lt;aoxDirection&gt;: Angle measurement direction.<p id="p5190957205420"><a name="p5190957205420"></a><a name="p5190957205420"></a>0: The initiator side sends the angle measurement frame;</p>
<p id="p12429559145413"><a name="p12429559145413"></a><a name="p12429559145413"></a>1: The responder side sends the angle measurement frame;</p>
<p id="p10661554175412"><a name="p10661554175412"></a><a name="p10661554175412"></a>2: Two-sided angle measurement.</p>
</li><li>&lt;mrSource&gt;: Measurement value request source.<p id="p21001715105412"><a name="p21001715105412"></a><a name="p21001715105412"></a>0: Measurement value receiver;</p>
<p id="p195mcpsimp"><a name="p195mcpsimp"></a><a name="p195mcpsimp"></a>1: Measurement value sender.</p>
</li><li>&lt;roundNum&gt;: Number of ranging rounds, value range: 0 to 255; 0 indicates unlimited rounds.</li><li>&lt;rangingFreq&gt;: Ranging frequency, value range: 1 to 20, unit: Hz.</li><li>&lt;txMode&gt;: TX transmission mode.<p id="p14703054125815"><a name="p14703054125815"></a><a name="p14703054125815"></a>0: Normal service mode;</p>
<p id="p94691211185919"><a name="p94691211185919"></a><a name="p94691211185919"></a>1: TX always-on mode;</p>
</li><li>&lt;txPowerHigh&gt;: High 16 bits of the TX transmit power. (Valid only in the production line TX power calibration test. Configure it to 0 outside production.)</li><li>&lt;txPowerLow&gt;: Low 16 bits of the TX transmit power. (Valid only in the production line TX power calibration test. Configure it to 0 outside production.)</li></ul>
</td>
</tr>
<tr id="row198mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.4.1"><p id="p200mcpsimp"><a name="p200mcpsimp"></a><a name="p200mcpsimp"></a>Example</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.4.1 "><p id="p202mcpsimp"><a name="p202mcpsimp"></a><a name="p202mcpsimp"></a>AT+SLPSTARTRANGING=2,1,1,0,0,18,0,0xA54A,0x254A</p>
</td>
</tr>
<tr id="row203mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.5.1"><p id="p205mcpsimp"><a name="p205mcpsimp"></a><a name="p205mcpsimp"></a>Note</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.5.1 "><p id="p207mcpsimp"><a name="p207mcpsimp"></a><a name="p207mcpsimp"></a>-</p>
</td>
</tr>
</tbody>
</table>

## SLP Stop Ranging<a name="ZH-CN_TOPIC_0000002183985848"></a>

<a name="table135mcpsimp"></a>
<table><tbody><tr id="row140mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.1.1"><p id="p142mcpsimp"><a name="p142mcpsimp"></a><a name="p142mcpsimp"></a>Format</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.1.1 "><p id="p144mcpsimp"><a name="p144mcpsimp"></a><a name="p144mcpsimp"></a>AT+SLPSTOPRANGING</p>
</td>
</tr>
<tr id="row145mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.2.1"><p id="p147mcpsimp"><a name="p147mcpsimp"></a><a name="p147mcpsimp"></a>Response</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.2.1 "><p id="p116mcpsimp"><a name="p116mcpsimp"></a><a name="p116mcpsimp"></a>On success: OK;</p>
<p id="p118mcpsimp"><a name="p118mcpsimp"></a><a name="p118mcpsimp"></a>On failure: ERROR.</p>
</td>
</tr>
<tr id="row152mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.3.1"><p id="p154mcpsimp"><a name="p154mcpsimp"></a><a name="p154mcpsimp"></a>Parameter Description</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.3.1 "><p id="p344311333535"><a name="p344311333535"></a><a name="p344311333535"></a>-</p>
</td>
</tr>
<tr id="row157mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.4.1"><p id="p159mcpsimp"><a name="p159mcpsimp"></a><a name="p159mcpsimp"></a>Example</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.4.1 "><p id="p161mcpsimp"><a name="p161mcpsimp"></a><a name="p161mcpsimp"></a>AT+SLPSTOPRANGING</p>
</td>
</tr>
<tr id="row162mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.5.1"><p id="p164mcpsimp"><a name="p164mcpsimp"></a><a name="p164mcpsimp"></a>Note</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.5.1 "><p id="p166mcpsimp"><a name="p166mcpsimp"></a><a name="p166mcpsimp"></a>-</p>
</td>
</tr>
</tbody>
</table>

## SLP Pause Ranging<a name="ZH-CN_TOPIC_0000002219311949"></a>

<a name="table135mcpsimp"></a>
<table><tbody><tr id="row140mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.1.1"><p id="p142mcpsimp"><a name="p142mcpsimp"></a><a name="p142mcpsimp"></a>Format</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.1.1 "><p id="p144mcpsimp"><a name="p144mcpsimp"></a><a name="p144mcpsimp"></a>AT+SLPPAUSERANGING</p>
</td>
</tr>
<tr id="row145mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.2.1"><p id="p147mcpsimp"><a name="p147mcpsimp"></a><a name="p147mcpsimp"></a>Response</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.2.1 "><p id="p116mcpsimp"><a name="p116mcpsimp"></a><a name="p116mcpsimp"></a>On success: OK;</p>
<p id="p118mcpsimp"><a name="p118mcpsimp"></a><a name="p118mcpsimp"></a>On failure: ERROR.</p>
</td>
</tr>
<tr id="row152mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.3.1"><p id="p154mcpsimp"><a name="p154mcpsimp"></a><a name="p154mcpsimp"></a>Parameter Description</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.3.1 "><p id="p344311333535"><a name="p344311333535"></a><a name="p344311333535"></a>-</p>
</td>
</tr>
<tr id="row157mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.4.1"><p id="p159mcpsimp"><a name="p159mcpsimp"></a><a name="p159mcpsimp"></a>Example</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.4.1 "><p id="p161mcpsimp"><a name="p161mcpsimp"></a><a name="p161mcpsimp"></a>AT+SLPPAUSERANGING</p>
</td>
</tr>
<tr id="row162mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.5.1"><p id="p164mcpsimp"><a name="p164mcpsimp"></a><a name="p164mcpsimp"></a>Note</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.5.1 "><p id="p166mcpsimp"><a name="p166mcpsimp"></a><a name="p166mcpsimp"></a>-</p>
</td>
</tr>
</tbody>
</table>

## SLP Continue Ranging<a name="ZH-CN_TOPIC_0000002183826180"></a>

<a name="table135mcpsimp"></a>
<table><tbody><tr id="row140mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.1.1"><p id="p142mcpsimp"><a name="p142mcpsimp"></a><a name="p142mcpsimp"></a>Format</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.1.1 "><p id="p144mcpsimp"><a name="p144mcpsimp"></a><a name="p144mcpsimp"></a>AT+SLPCONTINUERANGING</p>
</td>
</tr>
<tr id="row145mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.2.1"><p id="p147mcpsimp"><a name="p147mcpsimp"></a><a name="p147mcpsimp"></a>Response</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.2.1 "><p id="p116mcpsimp"><a name="p116mcpsimp"></a><a name="p116mcpsimp"></a>On success: OK;</p>
<p id="p118mcpsimp"><a name="p118mcpsimp"></a><a name="p118mcpsimp"></a>On failure: ERROR.</p>
</td>
</tr>
<tr id="row152mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.3.1"><p id="p154mcpsimp"><a name="p154mcpsimp"></a><a name="p154mcpsimp"></a>Parameter Description</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.3.1 "><p id="p344311333535"><a name="p344311333535"></a><a name="p344311333535"></a>-</p>
</td>
</tr>
<tr id="row157mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.4.1"><p id="p159mcpsimp"><a name="p159mcpsimp"></a><a name="p159mcpsimp"></a>Example</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.4.1 "><p id="p161mcpsimp"><a name="p161mcpsimp"></a><a name="p161mcpsimp"></a>AT+SLPCONTINUERANGING</p>
</td>
</tr>
<tr id="row162mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.5.1"><p id="p164mcpsimp"><a name="p164mcpsimp"></a><a name="p164mcpsimp"></a>Note</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.5.1 "><p id="p166mcpsimp"><a name="p166mcpsimp"></a><a name="p166mcpsimp"></a>-</p>
</td>
</tr>
</tbody>
</table>

## SLP Write Angle Measurement Calibration Value<a name="ZH-CN_TOPIC_0000002219311929"></a>

<a name="table135mcpsimp"></a>
<table><tbody><tr id="row140mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.1.1"><p id="p142mcpsimp"><a name="p142mcpsimp"></a><a name="p142mcpsimp"></a>Format</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.1.1 "><p id="p15412201410"><a name="p15412201410"></a><a name="p15412201410"></a>AT+SLPWRITEAOXCALIPARA=&lt;d0,d1,d2,d3,d4,d5,d6,d7&gt;</p>
</td>
</tr>
<tr id="row145mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.2.1"><p id="p147mcpsimp"><a name="p147mcpsimp"></a><a name="p147mcpsimp"></a>Response</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.2.1 "><p id="p116mcpsimp"><a name="p116mcpsimp"></a><a name="p116mcpsimp"></a>On success: OK;</p>
<p id="p118mcpsimp"><a name="p118mcpsimp"></a><a name="p118mcpsimp"></a>On failure: ERROR.</p>
</td>
</tr>
<tr id="row152mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.3.1"><p id="p154mcpsimp"><a name="p154mcpsimp"></a><a name="p154mcpsimp"></a>Parameter Description</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.3.1 "><a name="ul193881124125412"></a><a name="ul193881124125412"></a><ul id="ul193881124125412"><li>&lt;d0&gt;: Angle measurement calibration result d0, value range: -2147483648 to +2147483647</li><li>&lt;d1&gt;: Angle measurement calibration result d1, value range: -2147483648 to +2147483647</li><li>&lt;d2&gt;: Angle measurement calibration result d2, value range: -2147483648 to +2147483647</li><li>&lt;d3&gt;: Angle measurement calibration result d3, value range: -2147483648 to +2147483647</li><li>&lt;d4&gt;: Angle measurement calibration result d4, value range: -2147483648 to +2147483647</li><li>&lt;d5&gt;: Angle measurement calibration result d5, value range: -2147483648 to +2147483647</li><li>&lt;d6&gt;: Angle measurement calibration result d6, value range: -2147483648 to +2147483647</li></ul>
<a name="ul2797173417163"></a><a name="ul2797173417163"></a><ul id="ul2797173417163"><li>&lt;d7&gt;: Angle measurement calibration result d7, value range: -2147483648 to +2147483647</li></ul>
</td>
</tr>
<tr id="row157mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.4.1"><p id="p159mcpsimp"><a name="p159mcpsimp"></a><a name="p159mcpsimp"></a>Example</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.4.1 "><p id="p161mcpsimp"><a name="p161mcpsimp"></a><a name="p161mcpsimp"></a>AT+SLPWRITEAOXCALIPARA=9194023, 388905, 2489162, -1720910, -1638230, 791743, 5058826, -3502109</p>
</td>
</tr>
<tr id="row162mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.5.1"><p id="p164mcpsimp"><a name="p164mcpsimp"></a><a name="p164mcpsimp"></a>Note</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.5.1 "><p id="p166mcpsimp"><a name="p166mcpsimp"></a><a name="p166mcpsimp"></a></p>
</td>
</tr>
</tbody>
</table>

## SLP Read Angle Measurement Calibration Value<a name="ZH-CN_TOPIC_0000002183985832"></a>

<a name="table135mcpsimp"></a>
<table><tbody><tr id="row140mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.1.1"><p id="p142mcpsimp"><a name="p142mcpsimp"></a><a name="p142mcpsimp"></a>Format</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.1.1 "><p id="p144mcpsimp"><a name="p144mcpsimp"></a><a name="p144mcpsimp"></a>AT+SLPREADAOXCALIPARA</p>
</td>
</tr>
<tr id="row145mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.2.1"><p id="p147mcpsimp"><a name="p147mcpsimp"></a><a name="p147mcpsimp"></a>Response</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.2.1 "><p id="p116mcpsimp"><a name="p116mcpsimp"></a><a name="p116mcpsimp"></a>On success: angle measurement calibration result.</p>
<p id="p118mcpsimp"><a name="p118mcpsimp"></a><a name="p118mcpsimp"></a>On failure: ERROR.</p>
</td>
</tr>
<tr id="row152mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.3.1"><p id="p154mcpsimp"><a name="p154mcpsimp"></a><a name="p154mcpsimp"></a>Parameter Description</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.3.1 "><p id="p344311333535"><a name="p344311333535"></a><a name="p344311333535"></a>-</p>
</td>
</tr>
<tr id="row157mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.4.1"><p id="p159mcpsimp"><a name="p159mcpsimp"></a><a name="p159mcpsimp"></a>Example</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.4.1 "><p id="p161mcpsimp"><a name="p161mcpsimp"></a><a name="p161mcpsimp"></a>AT+SLPREADAOXCALIPARA</p>
</td>
</tr>
<tr id="row162mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.5.1"><p id="p164mcpsimp"><a name="p164mcpsimp"></a><a name="p164mcpsimp"></a>Note</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.5.1 "><p id="p166mcpsimp"><a name="p166mcpsimp"></a><a name="p166mcpsimp"></a>-</p>
</td>
</tr>
</tbody>
</table>

## SLP Write TX Transmit Power Codeword<a name="ZH-CN_TOPIC_0000002183985824"></a>

<a name="table135mcpsimp"></a>
<table><tbody><tr id="row140mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.1.1"><p id="p142mcpsimp"><a name="p142mcpsimp"></a><a name="p142mcpsimp"></a>Format</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.1.1 "><p id="p144mcpsimp"><a name="p144mcpsimp"></a><a name="p144mcpsimp"></a>AT+SLPWRITETXPOWER=&lt;txPowerHigh,txPowerLow&gt;</p>
</td>
</tr>
<tr id="row145mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.2.1"><p id="p147mcpsimp"><a name="p147mcpsimp"></a><a name="p147mcpsimp"></a>Response</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.2.1 "><p id="p116mcpsimp"><a name="p116mcpsimp"></a><a name="p116mcpsimp"></a>On success: OK;</p>
<p id="p118mcpsimp"><a name="p118mcpsimp"></a><a name="p118mcpsimp"></a>On failure: ERROR.</p>
</td>
</tr>
<tr id="row152mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.3.1"><p id="p154mcpsimp"><a name="p154mcpsimp"></a><a name="p154mcpsimp"></a>Parameter Description</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.3.1 "><a name="ul193568184239"></a><a name="ul193568184239"></a><ul id="ul193568184239"><li>&lt;txPowerHigh&gt;: High 16 bits of the TX transmit power codeword.</li><li>&lt;txPowerLow&gt;: Low 16 bits of the TX transmit power codeword.</li></ul>
</td>
</tr>
<tr id="row157mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.4.1"><p id="p159mcpsimp"><a name="p159mcpsimp"></a><a name="p159mcpsimp"></a>Example</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.4.1 "><p id="p161mcpsimp"><a name="p161mcpsimp"></a><a name="p161mcpsimp"></a>AT+SLPWRITETXPOWER=0xA54A, 0x254A</p>
</td>
</tr>
<tr id="row162mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.5.1"><p id="p164mcpsimp"><a name="p164mcpsimp"></a><a name="p164mcpsimp"></a>Note</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.5.1 "><p id="p166mcpsimp"><a name="p166mcpsimp"></a><a name="p166mcpsimp"></a>-</p>
</td>
</tr>
</tbody>
</table>

## SLP Read TX Transmit Power Codeword<a name="ZH-CN_TOPIC_0000002183985840"></a>

<a name="table135mcpsimp"></a>
<table><tbody><tr id="row140mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.1.1"><p id="p142mcpsimp"><a name="p142mcpsimp"></a><a name="p142mcpsimp"></a>Format</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.1.1 "><p id="p144mcpsimp"><a name="p144mcpsimp"></a><a name="p144mcpsimp"></a>AT+SLPREADTXPOWER</p>
</td>
</tr>
<tr id="row145mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.2.1"><p id="p147mcpsimp"><a name="p147mcpsimp"></a><a name="p147mcpsimp"></a>Response</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.2.1 "><p id="p116mcpsimp"><a name="p116mcpsimp"></a><a name="p116mcpsimp"></a>On success: TX transmit power codeword;</p>
<p id="p118mcpsimp"><a name="p118mcpsimp"></a><a name="p118mcpsimp"></a>On failure: ERROR.</p>
</td>
</tr>
<tr id="row152mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.3.1"><p id="p154mcpsimp"><a name="p154mcpsimp"></a><a name="p154mcpsimp"></a>Parameter Description</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.3.1 "><p id="p344311333535"><a name="p344311333535"></a><a name="p344311333535"></a>-</p>
</td>
</tr>
<tr id="row157mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.4.1"><p id="p159mcpsimp"><a name="p159mcpsimp"></a><a name="p159mcpsimp"></a>Example</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.4.1 "><p id="p161mcpsimp"><a name="p161mcpsimp"></a><a name="p161mcpsimp"></a>AT+SLPREADTXPOWER</p>
</td>
</tr>
<tr id="row162mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.5.1"><p id="p164mcpsimp"><a name="p164mcpsimp"></a><a name="p164mcpsimp"></a>Note</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.5.1 "><p id="p166mcpsimp"><a name="p166mcpsimp"></a><a name="p166mcpsimp"></a>-</p>
</td>
</tr>
</tbody>
</table>

## SLP Write Board-Level and Antenna Delay Calibration Value<a name="ZH-CN_TOPIC_0000002183826196"></a>

<a name="table135mcpsimp"></a>
<table><tbody><tr id="row140mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.1.1"><p id="p142mcpsimp"><a name="p142mcpsimp"></a><a name="p142mcpsimp"></a>Format</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.1.1 "><p id="p144mcpsimp"><a name="p144mcpsimp"></a><a name="p144mcpsimp"></a>AT+SLPWRITETRXDELAY=&lt;timeDelay&gt;</p>
</td>
</tr>
<tr id="row145mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.2.1"><p id="p147mcpsimp"><a name="p147mcpsimp"></a><a name="p147mcpsimp"></a>Response</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.2.1 "><p id="p116mcpsimp"><a name="p116mcpsimp"></a><a name="p116mcpsimp"></a>On success: OK;</p>
<p id="p118mcpsimp"><a name="p118mcpsimp"></a><a name="p118mcpsimp"></a>On failure: ERROR.</p>
</td>
</tr>
<tr id="row152mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.3.1"><p id="p154mcpsimp"><a name="p154mcpsimp"></a><a name="p154mcpsimp"></a>Parameter Description</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.3.1 "><p id="p319543510297"><a name="p319543510297"></a><a name="p319543510297"></a>&lt;timeDelay&gt;: Total TRX delay calibration value of the board and antenna, value range: 0 to 4294967295, unit: 1e-5 ns.</p>
</td>
</tr>
<tr id="row157mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.4.1"><p id="p159mcpsimp"><a name="p159mcpsimp"></a><a name="p159mcpsimp"></a>Example</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.4.1 "><p id="p161mcpsimp"><a name="p161mcpsimp"></a><a name="p161mcpsimp"></a>AT+SLPWRITETRXDELAY=271617</p>
</td>
</tr>
</tbody>
</table>

## SLP Read Board-Level and Antenna Delay Calibration Value<a name="ZH-CN_TOPIC_0000002219311941"></a>

<a name="table135mcpsimp"></a>
<table><tbody><tr id="row140mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.1.1"><p id="p142mcpsimp"><a name="p142mcpsimp"></a><a name="p142mcpsimp"></a>Format</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.1.1 "><p id="p144mcpsimp"><a name="p144mcpsimp"></a><a name="p144mcpsimp"></a>AT+SLPREADTRXDELAY</p>
</td>
</tr>
<tr id="row145mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.2.1"><p id="p147mcpsimp"><a name="p147mcpsimp"></a><a name="p147mcpsimp"></a>Response</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.2.1 "><p id="p116mcpsimp"><a name="p116mcpsimp"></a><a name="p116mcpsimp"></a>On success: Total TRX delay calibration value of the board and antenna;</p>
<p id="p118mcpsimp"><a name="p118mcpsimp"></a><a name="p118mcpsimp"></a>On failure: ERROR.</p>
</td>
</tr>
<tr id="row152mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.3.1"><p id="p154mcpsimp"><a name="p154mcpsimp"></a><a name="p154mcpsimp"></a>Parameter Description</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.3.1 "><p id="p344311333535"><a name="p344311333535"></a><a name="p344311333535"></a>-</p>
</td>
</tr>
<tr id="row157mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.4.1"><p id="p159mcpsimp"><a name="p159mcpsimp"></a><a name="p159mcpsimp"></a>Example</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.4.1 "><p id="p161mcpsimp"><a name="p161mcpsimp"></a><a name="p161mcpsimp"></a>AT+SLPREADTRXDELAY</p>
</td>
</tr>
<tr id="row162mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.5.1"><p id="p164mcpsimp"><a name="p164mcpsimp"></a><a name="p164mcpsimp"></a>Note</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.5.1 "><p id="p166mcpsimp"><a name="p166mcpsimp"></a><a name="p166mcpsimp"></a>-</p>
</td>
</tr>
</tbody>
</table>

## SLP Enable IMU Detection<a name="ZH-CN_TOPIC_0000002371423284"></a>

<a name="table135mcpsimp"></a>
<table><tbody><tr id="row140mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.1.1"><p id="p142mcpsimp"><a name="p142mcpsimp"></a><a name="p142mcpsimp"></a>Format</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.1.1 "><p id="p144mcpsimp"><a name="p144mcpsimp"></a><a name="p144mcpsimp"></a>AT+SLPENABLEIMUDETECTION</p>
</td>
</tr>
<tr id="row145mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.2.1"><p id="p147mcpsimp"><a name="p147mcpsimp"></a><a name="p147mcpsimp"></a>Response</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.2.1 "><p id="p116mcpsimp"><a name="p116mcpsimp"></a><a name="p116mcpsimp"></a>On success: OK;</p>
<p id="p118mcpsimp"><a name="p118mcpsimp"></a><a name="p118mcpsimp"></a>On failure: ERROR.</p>
</td>
</tr>
<tr id="row152mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.3.1"><p id="p154mcpsimp"><a name="p154mcpsimp"></a><a name="p154mcpsimp"></a>Parameter Description</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.3.1 "><a name="ul19718948132416"></a><a name="ul19718948132416"></a><ul id="ul19718948132416"><li>&lt;updateNV&gt;: Whether to update NV.<p id="p2272166105017"><a name="p2272166105017"></a><a name="p2272166105017"></a>0: Do not update;</p>
<p id="p9376857508"><a name="p9376857508"></a><a name="p9376857508"></a>1: Update.</p>
</li></ul>
</td>
</tr>
<tr id="row157mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.4.1"><p id="p159mcpsimp"><a name="p159mcpsimp"></a><a name="p159mcpsimp"></a>Example</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.4.1 "><p id="p161mcpsimp"><a name="p161mcpsimp"></a><a name="p161mcpsimp"></a>AT+SLPENABLEIMUDETECTION=1</p>
</td>
</tr>
<tr id="row162mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.5.1"><p id="p164mcpsimp"><a name="p164mcpsimp"></a><a name="p164mcpsimp"></a>Note</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.5.1 "><p id="p166mcpsimp"><a name="p166mcpsimp"></a><a name="p166mcpsimp"></a>Can only be called when SLP is powered off. After the call, SLP automatically powers on, loads, and starts the IMU detection process. To disable it, send the power-off command.</p>
</td>
</tr>
</tbody>
</table>

## SLP Read GYRO Zero Offset Value<a name="ZH-CN_TOPIC_0000002405262773"></a>

<a name="table135mcpsimp"></a>
<table><tbody><tr id="row140mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.1.1"><p id="p142mcpsimp"><a name="p142mcpsimp"></a><a name="p142mcpsimp"></a>Format</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.1.1 "><p id="p275845614266"><a name="p275845614266"></a><a name="p275845614266"></a>AT+SLPREADGYROZEROOFFSET</p>
</td>
</tr>
<tr id="row145mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.2.1"><p id="p147mcpsimp"><a name="p147mcpsimp"></a><a name="p147mcpsimp"></a>Response</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.2.1 "><p id="p116mcpsimp"><a name="p116mcpsimp"></a><a name="p116mcpsimp"></a>On success: GYRO zero offset value.</p>
<p id="p118mcpsimp"><a name="p118mcpsimp"></a><a name="p118mcpsimp"></a>On failure: ERROR.</p>
</td>
</tr>
<tr id="row152mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.3.1"><p id="p154mcpsimp"><a name="p154mcpsimp"></a><a name="p154mcpsimp"></a>Parameter Description</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.3.1 "><p id="p344311333535"><a name="p344311333535"></a><a name="p344311333535"></a>-</p>
</td>
</tr>
<tr id="row157mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.4.1"><p id="p159mcpsimp"><a name="p159mcpsimp"></a><a name="p159mcpsimp"></a>Example</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.4.1 "><p id="p161mcpsimp"><a name="p161mcpsimp"></a><a name="p161mcpsimp"></a>AT+SLPREADGYROZEROOFFSET</p>
</td>
</tr>
<tr id="row162mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.5.1"><p id="p164mcpsimp"><a name="p164mcpsimp"></a><a name="p164mcpsimp"></a>Note</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.5.1 "><p id="p166mcpsimp"><a name="p166mcpsimp"></a><a name="p166mcpsimp"></a>-</p>
</td>
</tr>
</tbody>
</table>

## SLP Set RF Front-End Configuration Parameters<a name="ZH-CN_TOPIC_0000002405142921"></a>

<a name="table135mcpsimp"></a>
<table><tbody><tr id="row140mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.1.1"><p id="p142mcpsimp"><a name="p142mcpsimp"></a><a name="p142mcpsimp"></a>Format</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.1.1 "><p id="p1640116435299"><a name="p1640116435299"></a><a name="p1640116435299"></a>AT+SLPSETRFSWPARAM=&lt;pwrCtrl,antSwCtrlEn,ant0CodeTx,ant0CodeRx,ant1CodeTx,ant1CodeRx,ant2CodeTx,ant2CodeRx&gt;</p>
</td>
</tr>
<tr id="row145mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.2.1"><p id="p147mcpsimp"><a name="p147mcpsimp"></a><a name="p147mcpsimp"></a>Response</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.2.1 "><p id="p116mcpsimp"><a name="p116mcpsimp"></a><a name="p116mcpsimp"></a>On success: RF front-end configuration parameters.</p>
<p id="p118mcpsimp"><a name="p118mcpsimp"></a><a name="p118mcpsimp"></a>On failure: ERROR.</p>
</td>
</tr>
<tr id="row152mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.3.1"><p id="p154mcpsimp"><a name="p154mcpsimp"></a><a name="p154mcpsimp"></a>Parameter Description</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.3.1 "><a name="ul193881124125412"></a><a name="ul193881124125412"></a><ul id="ul193881124125412"><li>&lt;pwrCtrl&gt;: Whether the power supply of the RF switch is independently controlled.<p id="p10431351334"><a name="p10431351334"></a><a name="p10431351334"></a>0: No;</p>
<p id="p2097420546319"><a name="p2097420546319"></a><a name="p2097420546319"></a>1: Yes.</p>
</li><li>&lt;antSwCtrlEn&gt;: Enable the RF switch control pin, value range: 0x0 to 0xFF.</li><li>&lt;ant0CodeTx&gt;: Switching codeword of antenna 0 TX, value range: 0x0 to 0xFF.</li><li>&lt;ant0CodeRx&gt;: Switching codeword of antenna 0 RX, value range: 0x0 to 0xFF.</li><li>&lt;ant1CodeTx&gt;: Switching codeword of antenna 1 TX, value range: 0x0 to 0xFF.</li><li>&lt;ant1CodeRx&gt;: Switching codeword of antenna 1 RX, value range: 0x0 to 0xFF.</li><li>&lt;ant2CodeTx&gt;: Switching codeword of antenna 2 TX, value range: 0x0 to 0xFF.</li><li>&lt;ant2CodeRx&gt;: Switching codeword of antenna 2 RX, value range: 0x0 to 0xFF.</li></ul>
</td>
</tr>
<tr id="row157mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.4.1"><p id="p159mcpsimp"><a name="p159mcpsimp"></a><a name="p159mcpsimp"></a>Example</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.4.1 "><p id="p161mcpsimp"><a name="p161mcpsimp"></a><a name="p161mcpsimp"></a>AT+SLPSETRFSWPARAM=0,3,2,0,0,0,0,0</p>
</td>
</tr>
<tr id="row162mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.5.1"><p id="p164mcpsimp"><a name="p164mcpsimp"></a><a name="p164mcpsimp"></a>Note</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.5.1 "><p id="p166mcpsimp"><a name="p166mcpsimp"></a><a name="p166mcpsimp"></a>The configuration parameters must be consistent with the RF front-end design of the board. The configuration takes effect only when it is done before starting ranging.</p>
<p id="p164091951164613"><a name="p164091951164613"></a><a name="p164091951164613"></a>The TX always-on command is sent from ant0 by default, so only the TX of ant0 needs to be configured.</p>
</td>
</tr>
</tbody>
</table>

## SLP Set Cursor Sensitivity<a name="ZH-CN_TOPIC_0000002371585692"></a>

<a name="table135mcpsimp"></a>
<table><tbody><tr id="row140mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.1.1"><p id="p142mcpsimp"><a name="p142mcpsimp"></a><a name="p142mcpsimp"></a>Format</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.1.1 "><p id="p275845614266"><a name="p275845614266"></a><a name="p275845614266"></a>AT+SLPSETCURSORSPEED=&lt;speedMode&gt;</p>
</td>
</tr>
<tr id="row145mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.2.1"><p id="p147mcpsimp"><a name="p147mcpsimp"></a><a name="p147mcpsimp"></a>Response</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.2.1 "><p id="p116mcpsimp"><a name="p116mcpsimp"></a><a name="p116mcpsimp"></a>On success: cursor sensitivity.</p>
<p id="p118mcpsimp"><a name="p118mcpsimp"></a><a name="p118mcpsimp"></a>On failure: ERROR.</p>
</td>
</tr>
<tr id="row152mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.3.1"><p id="p154mcpsimp"><a name="p154mcpsimp"></a><a name="p154mcpsimp"></a>Parameter Description</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.3.1 "><a name="ul1382173655619"></a><a name="ul1382173655619"></a><ul id="ul1382173655619"><li>&lt;speedMode&gt;: Sensitivity level.<p id="p15263811558"><a name="p15263811558"></a><a name="p15263811558"></a>0: Low;</p>
<p id="p1598713859"><a name="p1598713859"></a><a name="p1598713859"></a>1: Medium;</p>
<p id="p26786147517"><a name="p26786147517"></a><a name="p26786147517"></a>2: High.</p>
</li></ul>
</td>
</tr>
<tr id="row157mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.4.1"><p id="p159mcpsimp"><a name="p159mcpsimp"></a><a name="p159mcpsimp"></a>Example</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.4.1 "><p id="p161mcpsimp"><a name="p161mcpsimp"></a><a name="p161mcpsimp"></a>AT+SLPSETCURSORSPEED=1</p>
</td>
</tr>
<tr id="row162mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.5.1"><p id="p164mcpsimp"><a name="p164mcpsimp"></a><a name="p164mcpsimp"></a>Note</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.5.1 "><p id="p166mcpsimp"><a name="p166mcpsimp"></a><a name="p166mcpsimp"></a>-</p>
</td>
</tr>
</tbody>
</table>

## SLP Set Production Test Mode<a name="ZH-CN_TOPIC_0000002405265461"></a>

<a name="table135mcpsimp"></a>
<table><tbody><tr id="row140mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.1.1"><p id="p142mcpsimp"><a name="p142mcpsimp"></a><a name="p142mcpsimp"></a>Format</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.1.1 "><p id="p275845614266"><a name="p275845614266"></a><a name="p275845614266"></a>AT+SLPSETFTMODE=&lt;facMode&gt;</p>
</td>
</tr>
<tr id="row145mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.2.1"><p id="p147mcpsimp"><a name="p147mcpsimp"></a><a name="p147mcpsimp"></a>Response</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.2.1 "><p id="p116mcpsimp"><a name="p116mcpsimp"></a><a name="p116mcpsimp"></a>On success: production test mode.</p>
<p id="p118mcpsimp"><a name="p118mcpsimp"></a><a name="p118mcpsimp"></a>On failure: ERROR.</p>
</td>
</tr>
<tr id="row152mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.3.1"><p id="p154mcpsimp"><a name="p154mcpsimp"></a><a name="p154mcpsimp"></a>Parameter Description</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.3.1 "><a name="ul64024418562"></a><a name="ul64024418562"></a><ul id="ul64024418562"><li>&lt;facMode&gt;: Production test mode.<p id="p188781338155"><a name="p188781338155"></a><a name="p188781338155"></a>0: Normal service;</p>
<p id="p115901640852"><a name="p115901640852"></a><a name="p115901640852"></a>1: RCU production test;</p>
<p id="p1426210411558"><a name="p1426210411558"></a><a name="p1426210411558"></a>2: IMU detection.</p>
</li></ul>
</td>
</tr>
<tr id="row157mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.4.1"><p id="p159mcpsimp"><a name="p159mcpsimp"></a><a name="p159mcpsimp"></a>Example</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.4.1 "><p id="p161mcpsimp"><a name="p161mcpsimp"></a><a name="p161mcpsimp"></a>AT+SLPSETFTMODE=1</p>
</td>
</tr>
<tr id="row162mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.5.1"><p id="p164mcpsimp"><a name="p164mcpsimp"></a><a name="p164mcpsimp"></a>Note</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.5.1 "><p id="p166mcpsimp"><a name="p166mcpsimp"></a><a name="p166mcpsimp"></a>-</p>
</td>
</tr>
</tbody>
</table>

## SLP Read Version Information<a name="ZH-CN_TOPIC_0000002371586072"></a>

<a name="table135mcpsimp"></a>
<table><tbody><tr id="row140mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.1.1"><p id="p142mcpsimp"><a name="p142mcpsimp"></a><a name="p142mcpsimp"></a>Format</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.1.1 "><p id="p275845614266"><a name="p275845614266"></a><a name="p275845614266"></a>AT+SLPREADVERSION</p>
</td>
</tr>
<tr id="row145mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.2.1"><p id="p147mcpsimp"><a name="p147mcpsimp"></a><a name="p147mcpsimp"></a>Response</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.2.1 "><p id="p116mcpsimp"><a name="p116mcpsimp"></a><a name="p116mcpsimp"></a>On success: OK.</p>
<p id="p118mcpsimp"><a name="p118mcpsimp"></a><a name="p118mcpsimp"></a>On failure: ERROR.</p>
</td>
</tr>
<tr id="row152mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.3.1"><p id="p154mcpsimp"><a name="p154mcpsimp"></a><a name="p154mcpsimp"></a>Parameter Description</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.3.1 "><p id="p344311333535"><a name="p344311333535"></a><a name="p344311333535"></a>-</p>
</td>
</tr>
<tr id="row157mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.4.1"><p id="p159mcpsimp"><a name="p159mcpsimp"></a><a name="p159mcpsimp"></a>Example</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.4.1 "><p id="p161mcpsimp"><a name="p161mcpsimp"></a><a name="p161mcpsimp"></a>AT+SLPREADVERSION</p>
</td>
</tr>
<tr id="row162mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.5.1"><p id="p164mcpsimp"><a name="p164mcpsimp"></a><a name="p164mcpsimp"></a>Note</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.5.1 "><p id="p166mcpsimp"><a name="p166mcpsimp"></a><a name="p166mcpsimp"></a>Can be called after power-on loading succeeds. After the call succeeds, version-related parameters will be reported in the SlpReportVersionCallback callback.</p>
</td>
</tr>
</tbody>
</table>

## SLP Set Coordinate Transformation Parameters<a name="ZH-CN_TOPIC_0000002481431717"></a>

<a name="table135mcpsimp"></a>
<table><tbody><tr id="row140mcpsimp"><th class="firstcol" valign="top" width="12.85%" id="mcps1.1.3.1.1"><p id="p142mcpsimp"><a name="p142mcpsimp"></a><a name="p142mcpsimp"></a>Format</p>
</th>
<td class="cellrowborder" valign="top" width="87.15%" headers="mcps1.1.3.1.1 "><p id="p1470891312329"><a name="p1470891312329"></a><a name="p1470891312329"></a>AT+SLPSETTRANSFORM=&lt;frontAxisIdx,frontDirection,rightAxisIdx,rightDirection,downAxisIdx,downDirection&gt;</p>
</td>
</tr>
<tr id="row145mcpsimp"><th class="firstcol" valign="top" width="12.85%" id="mcps1.1.3.2.1"><p id="p147mcpsimp"><a name="p147mcpsimp"></a><a name="p147mcpsimp"></a>Response</p>
</th>
<td class="cellrowborder" valign="top" width="87.15%" headers="mcps1.1.3.2.1 "><p id="p116mcpsimp"><a name="p116mcpsimp"></a><a name="p116mcpsimp"></a>On success: OK.</p>
<p id="p118mcpsimp"><a name="p118mcpsimp"></a><a name="p118mcpsimp"></a>On failure: ERROR.</p>
</td>
</tr>
<tr id="row152mcpsimp"><th class="firstcol" valign="top" width="12.85%" id="mcps1.1.3.3.1"><p id="p154mcpsimp"><a name="p154mcpsimp"></a><a name="p154mcpsimp"></a>Parameter Description</p>
</th>
<td class="cellrowborder" valign="top" width="87.15%" headers="mcps1.1.3.3.1 "><a name="ul193881124125412"></a><a name="ul193881124125412"></a><ul id="ul193881124125412"><li>&lt;frontAxisIdx&gt;: IMU coordinate axis index corresponding to the front direction.<p id="p14814813448"><a name="p14814813448"></a><a name="p14814813448"></a>0: X axis defined by the IMU</p>
<p id="p1848649174417"><a name="p1848649174417"></a><a name="p1848649174417"></a>1: Y axis defined by the IMU</p>
<p id="p18625910164413"><a name="p18625910164413"></a><a name="p18625910164413"></a>2: Z axis defined by the IMU</p>
</li><li>&lt;frontDirection&gt;: IMU coordinate axis direction corresponding to the front direction.<p id="p1497801113412"><a name="p1497801113412"></a><a name="p1497801113412"></a>1: Same direction</p>
<p id="p696971413412"><a name="p696971413412"></a><a name="p696971413412"></a>-1: Opposite direction</p>
</li><li>&lt;rightAxisIdx&gt;: IMU coordinate axis index corresponding to the right direction.<p id="p112091152124415"><a name="p112091152124415"></a><a name="p112091152124415"></a>0: X axis defined by the IMU</p>
<p id="p620914528445"><a name="p620914528445"></a><a name="p620914528445"></a>1: Y axis defined by the IMU</p>
<p id="p172093529441"><a name="p172093529441"></a><a name="p172093529441"></a>2: Z axis defined by the IMU</p>
</li><li>&lt;rightDirection&gt;: IMU coordinate axis direction corresponding to the right direction.<p id="p3446154844219"><a name="p3446154844219"></a><a name="p3446154844219"></a>1: Same direction</p>
<p id="p1144624812423"><a name="p1144624812423"></a><a name="p1144624812423"></a>-1: Opposite direction</p>
</li><li>&lt;downAxisIdx&gt;: IMU coordinate axis index corresponding to the down direction.<p id="p1539013580445"><a name="p1539013580445"></a><a name="p1539013580445"></a>0: X axis defined by the IMU</p>
<p id="p7390175884412"><a name="p7390175884412"></a><a name="p7390175884412"></a>1: Y axis defined by the IMU</p>
<p id="p1739045810447"><a name="p1739045810447"></a><a name="p1739045810447"></a>2: Z axis defined by the IMU</p>
</li><li>&lt;downDirection&gt;: IMU coordinate axis direction corresponding to the down direction.<p id="p3510165316429"><a name="p3510165316429"></a><a name="p3510165316429"></a>1: Same direction</p>
<p id="p251014530428"><a name="p251014530428"></a><a name="p251014530428"></a>-1: Opposite direction</p>
</li></ul>
</td>
</tr>
<tr id="row157mcpsimp"><th class="firstcol" valign="top" width="12.85%" id="mcps1.1.3.4.1"><p id="p159mcpsimp"><a name="p159mcpsimp"></a><a name="p159mcpsimp"></a>Example</p>
</th>
<td class="cellrowborder" valign="top" width="87.15%" headers="mcps1.1.3.4.1 "><p id="p161mcpsimp"><a name="p161mcpsimp"></a><a name="p161mcpsimp"></a>AT+SLPSETTRANSFORM=2,-1,0,-1,1,1</p>
</td>
</tr>
<tr id="row162mcpsimp"><th class="firstcol" valign="top" width="12.85%" id="mcps1.1.3.5.1"><p id="p164mcpsimp"><a name="p164mcpsimp"></a><a name="p164mcpsimp"></a>Note</p>
</th>
<td class="cellrowborder" valign="top" width="87.15%" headers="mcps1.1.3.5.1 "><p id="p166mcpsimp"><a name="p166mcpsimp"></a><a name="p166mcpsimp"></a>Can be called before the ranging service starts. All three coordinate axes need to be configured.</p>
</td>
</tr>
</tbody>
</table>

## SLP Set Installation Parameters<a name="ZH-CN_TOPIC_0000002481631685"></a>

<a name="table135mcpsimp"></a>
<table><tbody><tr id="row140mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.1.1"><p id="p142mcpsimp"><a name="p142mcpsimp"></a><a name="p142mcpsimp"></a>Format</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.1.1 "><p id="p9643681492"><a name="p9643681492"></a><a name="p9643681492"></a>AT+SLPSETINSTPARA=&lt;downtilt,verDisToCarSeat,verDisToSreenTop,horDisToSreen&gt;</p>
</td>
</tr>
<tr id="row145mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.2.1"><p id="p147mcpsimp"><a name="p147mcpsimp"></a><a name="p147mcpsimp"></a>Response</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.2.1 "><p id="p116mcpsimp"><a name="p116mcpsimp"></a><a name="p116mcpsimp"></a>On success: OK.</p>
<p id="p118mcpsimp"><a name="p118mcpsimp"></a><a name="p118mcpsimp"></a>On failure: ERROR.</p>
</td>
</tr>
<tr id="row152mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.3.1"><p id="p154mcpsimp"><a name="p154mcpsimp"></a><a name="p154mcpsimp"></a>Parameter Description</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.3.1 "><a name="ul193881124125412"></a><a name="ul193881124125412"></a><ul id="ul193881124125412"><li>&lt;downtilt&gt;: Downtilt angle of the Dongle tail, unit: degree, value range: [-45, 45].</li><li>&lt;verDisToCarSeat&gt;: Vertical distance from the Dongle to the car seat. Positive when the car seat is below, unit: millimeter.</li><li>&lt;verDisToSreenTop&gt;: Vertical distance from the Dongle to the top of the screen. Positive when the top of the screen is below, unit: millimeter.</li><li>&lt;horDisToSreen&gt;: Horizontal distance from the Dongle to the screen. Positive when the screen is in front, unit: millimeter.</li></ul>
</td>
</tr>
<tr id="row157mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.4.1"><p id="p159mcpsimp"><a name="p159mcpsimp"></a><a name="p159mcpsimp"></a>Example</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.4.1 "><p id="p161mcpsimp"><a name="p161mcpsimp"></a><a name="p161mcpsimp"></a>AT+SLPSETINSTPARA=45,500,-100,-600</p>
</td>
</tr>
<tr id="row162mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.5.1"><p id="p164mcpsimp"><a name="p164mcpsimp"></a><a name="p164mcpsimp"></a>Note</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.5.1 "><p id="p166mcpsimp"><a name="p166mcpsimp"></a><a name="p166mcpsimp"></a>Can be called before the ranging service starts.</p>
</td>
</tr>
</tbody>
</table>

**Figure 1**  Dongle installation parameter diagram<a name="fig5815183514553"></a>  
![](figures/Dongle安装参数示意图.png "Dongle installation parameter diagram")

## SLP Set Key State<a name="ZH-CN_TOPIC_0000002453803022"></a>

<a name="table135mcpsimp"></a>
<table><tbody><tr id="row140mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.1.1"><p id="p142mcpsimp"><a name="p142mcpsimp"></a><a name="p142mcpsimp"></a>Format</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.1.1 "><p id="p251713125118"><a name="p251713125118"></a><a name="p251713125118"></a>AT+SLPSETCLICK=&lt;state&gt;</p>
</td>
</tr>
<tr id="row145mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.2.1"><p id="p147mcpsimp"><a name="p147mcpsimp"></a><a name="p147mcpsimp"></a>Response</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.2.1 "><p id="p116mcpsimp"><a name="p116mcpsimp"></a><a name="p116mcpsimp"></a>On success: OK.</p>
<p id="p118mcpsimp"><a name="p118mcpsimp"></a><a name="p118mcpsimp"></a>On failure: ERROR.</p>
</td>
</tr>
<tr id="row152mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.3.1"><p id="p154mcpsimp"><a name="p154mcpsimp"></a><a name="p154mcpsimp"></a>Parameter Description</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.3.1 "><a name="ul193881124125412"></a><a name="ul193881124125412"></a><ul id="ul193881124125412"><li>&lt;state&gt;: Key state.<p id="p3510165316429"><a name="p3510165316429"></a><a name="p3510165316429"></a>0: Released</p>
<p id="p251014530428"><a name="p251014530428"></a><a name="p251014530428"></a>1: Pressed</p>
</li></ul>
</td>
</tr>
<tr id="row157mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.4.1"><p id="p159mcpsimp"><a name="p159mcpsimp"></a><a name="p159mcpsimp"></a>Example</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.4.1 "><p id="p161mcpsimp"><a name="p161mcpsimp"></a><a name="p161mcpsimp"></a>AT+SLPSETCLICK=1</p>
</td>
</tr>
<tr id="row162mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.5.1"><p id="p164mcpsimp"><a name="p164mcpsimp"></a><a name="p164mcpsimp"></a>Note</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.5.1 "><p id="p166mcpsimp"><a name="p166mcpsimp"></a><a name="p166mcpsimp"></a>Can be called after the pointing service starts.</p>
</td>
</tr>
</tbody>
</table>

## SLP Read Temperature Value<a name="ZH-CN_TOPIC_0000002513368031"></a>

<a name="table135mcpsimp"></a>
<table><tbody><tr id="row140mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.1.1"><p id="p142mcpsimp"><a name="p142mcpsimp"></a><a name="p142mcpsimp"></a>Format</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.1.1 "><p id="p5874165417513"><a name="p5874165417513"></a><a name="p5874165417513"></a>AT+SLPREADTSENSOR</p>
</td>
</tr>
<tr id="row145mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.2.1"><p id="p147mcpsimp"><a name="p147mcpsimp"></a><a name="p147mcpsimp"></a>Response</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.2.1 "><p id="p116mcpsimp"><a name="p116mcpsimp"></a><a name="p116mcpsimp"></a>On success: OK.</p>
<p id="p118mcpsimp"><a name="p118mcpsimp"></a><a name="p118mcpsimp"></a>On failure: ERROR.</p>
</td>
</tr>
<tr id="row152mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.3.1"><p id="p154mcpsimp"><a name="p154mcpsimp"></a><a name="p154mcpsimp"></a>Parameter Description</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.3.1 "><p id="p1482118385349"><a name="p1482118385349"></a><a name="p1482118385349"></a>-</p>
</td>
</tr>
<tr id="row157mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.4.1"><p id="p159mcpsimp"><a name="p159mcpsimp"></a><a name="p159mcpsimp"></a>Example</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.4.1 "><p id="p161mcpsimp"><a name="p161mcpsimp"></a><a name="p161mcpsimp"></a>AT+SLPREADTSENSOR</p>
</td>
</tr>
<tr id="row162mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.5.1"><p id="p164mcpsimp"><a name="p164mcpsimp"></a><a name="p164mcpsimp"></a>Note</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.5.1 "><p id="p166mcpsimp"><a name="p166mcpsimp"></a><a name="p166mcpsimp"></a>Can be called after power-on.</p>
</td>
</tr>
</tbody>
</table>

## SLP Set Log Print Level<a name="ZH-CN_TOPIC_0000002513488003"></a>

<a name="table135mcpsimp"></a>
<table><tbody><tr id="row140mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.1.1"><p id="p142mcpsimp"><a name="p142mcpsimp"></a><a name="p142mcpsimp"></a>Format</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.1.1 "><p id="p1740614364353"><a name="p1740614364353"></a><a name="p1740614364353"></a>AT+SLPSETLOGLEVEL=&lt;nbLogLevel,wbLogLevel&gt;</p>
</td>
</tr>
<tr id="row145mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.2.1"><p id="p147mcpsimp"><a name="p147mcpsimp"></a><a name="p147mcpsimp"></a>Response</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.2.1 "><p id="p116mcpsimp"><a name="p116mcpsimp"></a><a name="p116mcpsimp"></a>On success: OK.</p>
<p id="p118mcpsimp"><a name="p118mcpsimp"></a><a name="p118mcpsimp"></a>On failure: ERROR.</p>
</td>
</tr>
<tr id="row152mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.3.1"><p id="p154mcpsimp"><a name="p154mcpsimp"></a><a name="p154mcpsimp"></a>Parameter Description</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.3.1 "><a name="ul193881124125412"></a><a name="ul193881124125412"></a><ul id="ul193881124125412"><li>&lt;nbLogLevel&gt;: Narrowband log print level;</li><li>&lt;wbLogLevel&gt;: Wideband log print level.</li></ul>
<p id="p1958091893816"><a name="p1958091893816"></a><a name="p1958091893816"></a>Value range:</p>
<a name="ul3904133013387"></a><a name="ul3904133013387"></a><ul id="ul3904133013387"><li>0：NONE；</li><li>1：ERR；</li><li>2：WAR；</li><li>3：INFO；</li><li>4：DBG</li></ul>
</td>
</tr>
<tr id="row157mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.4.1"><p id="p159mcpsimp"><a name="p159mcpsimp"></a><a name="p159mcpsimp"></a>Example</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.4.1 "><p id="p161mcpsimp"><a name="p161mcpsimp"></a><a name="p161mcpsimp"></a>AT+SLPSETLOGLEVEL=3,3</p>
</td>
</tr>
<tr id="row162mcpsimp"><th class="firstcol" valign="top" width="14.000000000000002%" id="mcps1.1.3.5.1"><p id="p164mcpsimp"><a name="p164mcpsimp"></a><a name="p164mcpsimp"></a>Note</p>
</th>
<td class="cellrowborder" valign="top" width="86%" headers="mcps1.1.3.5.1 "><p id="p166mcpsimp"><a name="p166mcpsimp"></a><a name="p166mcpsimp"></a>-</p>
</td>
</tr>
</tbody>
</table>

## SLP Disable IMU Detection<a name="ZH-CN_TOPIC_0000002481568130"></a>

<a name="table135mcpsimp"></a>
<table><tbody><tr id="row140mcpsimp"><th class="firstcol" valign="top" width="13.889999999999999%" id="mcps1.1.3.1.1"><p id="p142mcpsimp"><a name="p142mcpsimp"></a><a name="p142mcpsimp"></a>Format</p>
</th>
<td class="cellrowborder" valign="top" width="86.11%" headers="mcps1.1.3.1.1 "><p id="p251713125118"><a name="p251713125118"></a><a name="p251713125118"></a>AT+SLPDISABLEIMUDETECTION</p>
</td>
</tr>
<tr id="row145mcpsimp"><th class="firstcol" valign="top" width="13.889999999999999%" id="mcps1.1.3.2.1"><p id="p147mcpsimp"><a name="p147mcpsimp"></a><a name="p147mcpsimp"></a>Response</p>
</th>
<td class="cellrowborder" valign="top" width="86.11%" headers="mcps1.1.3.2.1 "><p id="p116mcpsimp"><a name="p116mcpsimp"></a><a name="p116mcpsimp"></a>On success: OK.</p>
<p id="p118mcpsimp"><a name="p118mcpsimp"></a><a name="p118mcpsimp"></a>On failure: ERROR.</p>
</td>
</tr>
<tr id="row152mcpsimp"><th class="firstcol" valign="top" width="13.889999999999999%" id="mcps1.1.3.3.1"><p id="p154mcpsimp"><a name="p154mcpsimp"></a><a name="p154mcpsimp"></a>Parameter Description</p>
</th>
<td class="cellrowborder" valign="top" width="86.11%" headers="mcps1.1.3.3.1 "><p id="p14091318787"><a name="p14091318787"></a><a name="p14091318787"></a>-</p>
</td>
</tr>
<tr id="row157mcpsimp"><th class="firstcol" valign="top" width="13.889999999999999%" id="mcps1.1.3.4.1"><p id="p159mcpsimp"><a name="p159mcpsimp"></a><a name="p159mcpsimp"></a>Example</p>
</th>
<td class="cellrowborder" valign="top" width="86.11%" headers="mcps1.1.3.4.1 "><p id="p161mcpsimp"><a name="p161mcpsimp"></a><a name="p161mcpsimp"></a>AT+SLPDISABLEIMUDETECTION</p>
</td>
</tr>
<tr id="row162mcpsimp"><th class="firstcol" valign="top" width="13.889999999999999%" id="mcps1.1.3.5.1"><p id="p164mcpsimp"><a name="p164mcpsimp"></a><a name="p164mcpsimp"></a>Note</p>
</th>
<td class="cellrowborder" valign="top" width="86.11%" headers="mcps1.1.3.5.1 "><p id="p166mcpsimp"><a name="p166mcpsimp"></a><a name="p166mcpsimp"></a>-</p>
</td>
</tr>
</tbody>
</table>

## SLP Set IMU Raw Data Reporting Frequency<a name="ZH-CN_TOPIC_0000002509642402"></a>

<a name="table67881850104917"></a>
<table><tbody><tr id="row128141850134912"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.1.1"><p id="p98142503492"><a name="p98142503492"></a><a name="p98142503492"></a>Format</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.1.1 "><p id="p14814205084915"><a name="p14814205084915"></a><a name="p14814205084915"></a>AT+SLPSETIMURPTFREQ=&lt;freq&gt;</p>
</td>
</tr>
<tr id="row7814850164915"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.2.1"><p id="p188141950174910"><a name="p188141950174910"></a><a name="p188141950174910"></a>Response</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.2.1 "><p id="p981465015491"><a name="p981465015491"></a><a name="p981465015491"></a>On success: OK.</p>
<p id="p1581410501497"><a name="p1581410501497"></a><a name="p1581410501497"></a>On failure: ERROR.</p>
</td>
</tr>
<tr id="row8814175018497"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.3.1"><p id="p48141501498"><a name="p48141501498"></a><a name="p48141501498"></a>Parameter Description</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.3.1 "><p id="p14814185018492"><a name="p14814185018492"></a><a name="p14814185018492"></a>l &lt;freq&gt;: IMU raw data reporting frequency, unit: Hz, value range: 1,2,3,4,5,6,8,10,12,15,16,20,24,30,40,48,60,80,120</p>
</td>
</tr>
<tr id="row6814155017496"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.4.1"><p id="p18814195094916"><a name="p18814195094916"></a><a name="p18814195094916"></a>Example</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.4.1 "><p id="p118141750134910"><a name="p118141750134910"></a><a name="p118141750134910"></a>AT+SLPSETIMURPTFREQ=1</p>
</td>
</tr>
<tr id="row1681419505497"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.5.1"><p id="p48141650194915"><a name="p48141650194915"></a><a name="p48141650194915"></a>Note</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.5.1 "><p id="p1081414505492"><a name="p1081414505492"></a><a name="p1081414505492"></a>-</p>
</td>
</tr>
</tbody>
</table>

## SLP Set Cursor Correction Mode<a name="ZH-CN_TOPIC_0000002509682422"></a>

<a name="table139648318500"></a>
<table><tbody><tr id="row697520375013"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.1.1"><p id="p5975113115017"><a name="p5975113115017"></a><a name="p5975113115017"></a>Format</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.1.1 "><p id="p2097511318506"><a name="p2097511318506"></a><a name="p2097511318506"></a>AT+SLPSETCORRECTMODE=&lt;mode&gt;</p>
</td>
</tr>
<tr id="row119755313507"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.2.1"><p id="p397510315509"><a name="p397510315509"></a><a name="p397510315509"></a>Response</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.2.1 "><p id="p1097583145010"><a name="p1097583145010"></a><a name="p1097583145010"></a>On success: OK.</p>
<p id="p119751234503"><a name="p119751234503"></a><a name="p119751234503"></a>On failure: ERROR.</p>
</td>
</tr>
<tr id="row1397512312503"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.3.1"><p id="p159751733503"><a name="p159751733503"></a><a name="p159751733503"></a>Parameter Description</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.3.1 "><p id="p15975333503"><a name="p15975333503"></a><a name="p15975333503"></a>&lt;mode&gt;: Cursor correction mode.</p>
<p id="p1097523125013"><a name="p1097523125013"></a><a name="p1097523125013"></a>0: Automatic switching mode</p>
<p id="p1697515312502"><a name="p1697515312502"></a><a name="p1697515312502"></a>1: Pointing mode</p>
<p id="p149751385019"><a name="p149751385019"></a><a name="p149751385019"></a>2: Air mouse mode</p>
</td>
</tr>
<tr id="row19756311505"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.4.1"><p id="p9975103135017"><a name="p9975103135017"></a><a name="p9975103135017"></a>Example</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.4.1 "><p id="p697516305018"><a name="p697516305018"></a><a name="p697516305018"></a>AT+SLPSETCORRECTMODE=0</p>
</td>
</tr>
<tr id="row69750315010"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.5.1"><p id="p159751318501"><a name="p159751318501"></a><a name="p159751318501"></a>Note</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.5.1 "><p id="p49751734505"><a name="p49751734505"></a><a name="p49751734505"></a>-</p>
</td>
</tr>
</tbody>
</table>

## SLP Read Chip DIE ID<a name="ZH-CN_TOPIC_0000002551238893"></a>

<a name="table18392202844019"></a>
<table><tbody><tr id="row13418182844013"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.1.1"><p id="p741842854016"><a name="p741842854016"></a><a name="p741842854016"></a>Format</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.1.1 "><p id="p341819285405"><a name="p341819285405"></a><a name="p341819285405"></a>AT+SLPREADDIEID</p>
</td>
</tr>
<tr id="row1141813284407"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.2.1"><p id="p541892814400"><a name="p541892814400"></a><a name="p541892814400"></a>Response</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.2.1 "><p id="p7418328184020"><a name="p7418328184020"></a><a name="p7418328184020"></a>On success: OK.</p>
<p id="p13418162824019"><a name="p13418162824019"></a><a name="p13418162824019"></a>On failure: ERROR.</p>
</td>
</tr>
<tr id="row154187280403"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.3.1"><p id="p1941819289401"><a name="p1941819289401"></a><a name="p1941819289401"></a>Parameter Description</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.3.1 "><p id="p94180289406"><a name="p94180289406"></a><a name="p94180289406"></a>-</p>
</td>
</tr>
<tr id="row941812816409"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.4.1"><p id="p541882810403"><a name="p541882810403"></a><a name="p541882810403"></a>Example</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.4.1 "><p id="p1741816282407"><a name="p1741816282407"></a><a name="p1741816282407"></a>AT+SLPREADDIEID</p>
</td>
</tr>
<tr id="row1141842815404"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.5.1"><p id="p2041842816401"><a name="p2041842816401"></a><a name="p2041842816401"></a>Note</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.5.1 "><a name="ol201431920121918"></a><a name="ol201431920121918"></a><ol id="ol201431920121918"><li>Can be called only after power-on.</li><li>The result is reported in the rptDieIdCbk callback.</li></ol>
</td>
</tr>
</tbody>
</table>

## RCU Side System Sleep<a name="ZH-CN_TOPIC_0000002543745535"></a>

<a name="table12670105319340"></a>
<table><tbody><tr id="row268118536341"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.1.1"><p id="p66811853183410"><a name="p66811853183410"></a><a name="p66811853183410"></a>Format</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.1.1 "><p id="p9681105317348"><a name="p9681105317348"></a><a name="p9681105317348"></a>AT+SLPRCUSLEEP</p>
</td>
</tr>
<tr id="row1168117533348"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.2.1"><p id="p126811353163417"><a name="p126811353163417"></a><a name="p126811353163417"></a>Response</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.2.1 "><p id="p768135393411"><a name="p768135393411"></a><a name="p768135393411"></a>On success: OK.</p>
<p id="p1568135333416"><a name="p1568135333416"></a><a name="p1568135333416"></a>On failure: ERROR.</p>
</td>
</tr>
<tr id="row20681953153413"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.3.1"><p id="p2068112538340"><a name="p2068112538340"></a><a name="p2068112538340"></a>Parameter Description</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.3.1 "><p id="p3681115319343"><a name="p3681115319343"></a><a name="p3681115319343"></a>-</p>
</td>
</tr>
<tr id="row1668110530342"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.4.1"><p id="p1968155353410"><a name="p1968155353410"></a><a name="p1968155353410"></a>Example</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.4.1 "><p id="p468175313419"><a name="p468175313419"></a><a name="p468175313419"></a>AT+SLPRCUSLEEP</p>
</td>
</tr>
<tr id="row1568175314344"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.5.1"><p id="p156811553193410"><a name="p156811553193410"></a><a name="p156811553193410"></a>Note</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.5.1 "><p id="p368175323418"><a name="p368175323418"></a><a name="p368175323418"></a>Can be called only on the RCU side. It is defined in air_mouse_rcu_at.c and is used only for maintenance testing.</p>
</td>
</tr>
</tbody>
</table>

## RCU Side SLE Active Disconnection with Broadcast Disabled but Pairing Records Not Cleared<a name="ZH-CN_TOPIC_0000002543825541"></a>

<a name="table1088353173514"></a>
<table><tbody><tr id="row8894203183510"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.1.1"><p id="p5894133113519"><a name="p5894133113519"></a><a name="p5894133113519"></a>Format</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.1.1 "><p id="p58942373510"><a name="p58942373510"></a><a name="p58942373510"></a>AT+SLPAMDISCONNECT</p>
</td>
</tr>
<tr id="row2089433203514"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.2.1"><p id="p1089412313514"><a name="p1089412313514"></a><a name="p1089412313514"></a>Response</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.2.1 "><p id="p7894339352"><a name="p7894339352"></a><a name="p7894339352"></a>On success: OK.</p>
<p id="p208941632356"><a name="p208941632356"></a><a name="p208941632356"></a>On failure: ERROR.</p>
</td>
</tr>
<tr id="row7894103163513"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.3.1"><p id="p989415363510"><a name="p989415363510"></a><a name="p989415363510"></a>Parameter Description</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.3.1 "><p id="p28948314352"><a name="p28948314352"></a><a name="p28948314352"></a>-</p>
</td>
</tr>
<tr id="row68946314351"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.4.1"><p id="p2089419393519"><a name="p2089419393519"></a><a name="p2089419393519"></a>Example</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.4.1 "><p id="p589412310350"><a name="p589412310350"></a><a name="p589412310350"></a>AT+ SLPAMDISCONNECT</p>
</td>
</tr>
<tr id="row14894193103517"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.5.1"><p id="p889420317354"><a name="p889420317354"></a><a name="p889420317354"></a>Note</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.5.1 "><p id="p118941731358"><a name="p118941731358"></a><a name="p118941731358"></a>Can be called only on the RCU side. It is defined in air_mouse_rcu_at.c and is used only for maintenance testing.</p>
</td>
</tr>
</tbody>
</table>

## RCU Side Enable Broadcasting<a name="ZH-CN_TOPIC_0000002543745533"></a>

<a name="table49653214012"></a>
<table><tbody><tr id="row71091632164015"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.1.1"><p id="p131091323409"><a name="p131091323409"></a><a name="p131091323409"></a>Format</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.1.1 "><p id="p410983214017"><a name="p410983214017"></a><a name="p410983214017"></a>AT+SLPAMSTARTANNOUNCE</p>
</td>
</tr>
<tr id="row9109632134011"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.2.1"><p id="p18109153244016"><a name="p18109153244016"></a><a name="p18109153244016"></a>Response</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.2.1 "><p id="p17109532124015"><a name="p17109532124015"></a><a name="p17109532124015"></a>On success: OK.</p>
<p id="p13109123215400"><a name="p13109123215400"></a><a name="p13109123215400"></a>On failure: ERROR.</p>
</td>
</tr>
<tr id="row171098324408"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.3.1"><p id="p101107327409"><a name="p101107327409"></a><a name="p101107327409"></a>Parameter Description</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.3.1 "><p id="p17110113217401"><a name="p17110113217401"></a><a name="p17110113217401"></a>-</p>
</td>
</tr>
<tr id="row141101232194018"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.4.1"><p id="p101107326401"><a name="p101107326401"></a><a name="p101107326401"></a>Example</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.4.1 "><p id="p19110123214014"><a name="p19110123214014"></a><a name="p19110123214014"></a>AT+SLPAMSTARTANNOUNCE</p>
</td>
</tr>
<tr id="row181102032134012"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.5.1"><p id="p11101332204016"><a name="p11101332204016"></a><a name="p11101332204016"></a>Note</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.5.1 "><p id="p1811017325408"><a name="p1811017325408"></a><a name="p1811017325408"></a>Can be called only on the RCU side. It is defined in air_mouse_rcu_at.c and is used only for maintenance testing.</p>
</td>
</tr>
</tbody>
</table>

## Dongle Side Switch Pointing Cursor Speed and Update Log Print Flag<a name="ZH-CN_TOPIC_0000002543825539"></a>

<a name="table2071774016408"></a>
<table><tbody><tr id="row2730104074011"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.1.1"><p id="p19730140104012"><a name="p19730140104012"></a><a name="p19730140104012"></a>Format</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.1.1 "><p id="p1273013402405"><a name="p1273013402405"></a><a name="p1273013402405"></a>AT+AMSETCURSORSPEED=&lt;mode&gt;</p>
</td>
</tr>
<tr id="row273064034015"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.2.1"><p id="p18730124020401"><a name="p18730124020401"></a><a name="p18730124020401"></a>Response</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.2.1 "><p id="p1573013402404"><a name="p1573013402404"></a><a name="p1573013402404"></a>On success: OK.</p>
<p id="p137301040124015"><a name="p137301040124015"></a><a name="p137301040124015"></a>On failure: ERROR.</p>
</td>
</tr>
<tr id="row207301940114020"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.3.1"><p id="p1173024011403"><a name="p1173024011403"></a><a name="p1173024011403"></a>Parameter Description</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.3.1 "><p id="p77301340144018"><a name="p77301340144018"></a><a name="p77301340144018"></a>-&lt;mode&gt;: Cursor movement speed.</p>
<p id="p77305404400"><a name="p77305404400"></a><a name="p77305404400"></a>0: Low speed</p>
<p id="p573064011408"><a name="p573064011408"></a><a name="p573064011408"></a>1: Medium speed</p>
<p id="p6730124018407"><a name="p6730124018407"></a><a name="p6730124018407"></a>2: High speed</p>
<p id="p1673074017406"><a name="p1673074017406"></a><a name="p1673074017406"></a>3: Medium-low speed</p>
<p id="p6730240184010"><a name="p6730240184010"></a><a name="p6730240184010"></a>4: Medium-high speed</p>
</td>
</tr>
<tr id="row1730540184015"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.4.1"><p id="p473014014011"><a name="p473014014011"></a><a name="p473014014011"></a>Example</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.4.1 "><p id="p07301740124020"><a name="p07301740124020"></a><a name="p07301740124020"></a>AT+AMSETCURSORSPEED=1</p>
</td>
</tr>
<tr id="row1473014034011"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.5.1"><p id="p573004004011"><a name="p573004004011"></a><a name="p573004004011"></a>Note</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.5.1 "><p id="p1273014404403"><a name="p1273014404403"></a><a name="p1273014404403"></a>Can be called only on the Dongle side. It is defined in air_mouse_dongle_at.c and is used only for maintenance testing.</p>
</td>
</tr>
</tbody>
</table>

## SLP Read Three-Antenna Calibration Parameters<a name="ZH-CN_TOPIC_0000002522946218"></a>

<a name="table9651133516351"></a>
<table><tbody><tr id="row166853519351"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.1.1"><p id="p156681435133512"><a name="p156681435133512"></a><a name="p156681435133512"></a>Format</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.1.1 "><p id="p14668835153514"><a name="p14668835153514"></a><a name="p14668835153514"></a>AT+SLPREADTRIANTCALIPARA</p>
</td>
</tr>
<tr id="row12668163593511"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.2.1"><p id="p156681835143512"><a name="p156681835143512"></a><a name="p156681835143512"></a>Response</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.2.1 "><p id="p1966853533510"><a name="p1966853533510"></a><a name="p1966853533510"></a>On success: three-antenna calibration parameters.</p>
<p id="p15668035123511"><a name="p15668035123511"></a><a name="p15668035123511"></a>On failure: ERROR.</p>
</td>
</tr>
<tr id="row666893533520"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.3.1"><p id="p1066814352358"><a name="p1066814352358"></a><a name="p1066814352358"></a>Parameter Description</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.3.1 "><p id="p1466833518350"><a name="p1466833518350"></a><a name="p1466833518350"></a>-</p>
</td>
</tr>
<tr id="row10668335193510"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.4.1"><p id="p196681535153517"><a name="p196681535153517"></a><a name="p196681535153517"></a>Example</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.4.1 "><p id="p186684351354"><a name="p186684351354"></a><a name="p186684351354"></a>AT+SLPREADTRIANTCALIPARA</p>
</td>
</tr>
<tr id="row196681335173520"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.5.1"><p id="p966883512352"><a name="p966883512352"></a><a name="p966883512352"></a>Note</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.5.1 "><p id="p1666873593510"><a name="p1666873593510"></a><a name="p1666873593510"></a>-</p>
</td>
</tr>
</tbody>
</table>

## SLP Write Three-Antenna Calibration Parameters<a name="ZH-CN_TOPIC_0000002522786214"></a>

<a name="table12585174611491"></a>
<table><tbody><tr id="row3585246134911"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.1.1"><p id="p658512469494"><a name="p658512469494"></a><a name="p658512469494"></a>Format</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.1.1 "><p id="p458534617495"><a name="p458534617495"></a><a name="p458534617495"></a>AT+SLPWRITETRIANTCALIPARA=&lt;d0,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13,d14,d15,d16,d17&gt;</p>
</td>
</tr>
<tr id="row1858534664912"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.2.1"><p id="p6585346114916"><a name="p6585346114916"></a><a name="p6585346114916"></a>Response</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.2.1 "><p id="p10585184615493"><a name="p10585184615493"></a><a name="p10585184615493"></a>On success: OK.</p>
<p id="p25853464492"><a name="p25853464492"></a><a name="p25853464492"></a>On failure: ERROR.</p>
</td>
</tr>
<tr id="row1358584624910"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.3.1"><p id="p19585144615499"><a name="p19585144615499"></a><a name="p19585144615499"></a>Parameter Description</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.3.1 "><a name="ul65855463496"></a><a name="ul65855463496"></a><ul id="ul65855463496"><li>&lt;d0&gt;: Angle measurement calibration result d0, value range: 0 to +2147483647</li><li>&lt;d1&gt;: Angle measurement calibration result d1, value range: 0 to +2147483647</li><li>&lt;d2&gt;: Angle measurement calibration result d2, value range: -2147483648 to +2147483647</li><li>&lt;d3&gt;: Angle measurement calibration result d3, value range: -2147483648 to +2147483647</li><li>&lt;d4&gt;: Angle measurement calibration result d4, value range: -2147483648 to +2147483647</li><li>&lt;d5&gt;: Angle measurement calibration result d5, value range: -2147483648 to +2147483647</li><li>&lt;d6&gt;: Angle measurement calibration result d6, value range: -2147483648 to +2147483647</li></ul>
<a name="ul8585114694915"></a><a name="ul8585114694915"></a><ul id="ul8585114694915"><li>&lt;d7&gt;: Angle measurement calibration result d7, value range: -2147483648 to +2147483647</li></ul>
<a name="ul658511461497"></a><a name="ul658511461497"></a><ul id="ul658511461497"><li>&lt;d8&gt;: Angle measurement calibration result d8, value range: -2147483648 to +2147483647</li><li>&lt;d9&gt;: Angle measurement calibration result d9, value range: -2147483648 to +2147483647</li><li>&lt;d10&gt;: Angle measurement calibration result d10, value range: -2147483648 to +2147483647</li><li>&lt;d11&gt;: Angle measurement calibration result d11, value range: -2147483648 to +2147483647</li><li>&lt;d12&gt;: Angle measurement calibration result d12, value range: -2147483648 to +2147483647</li><li>&lt;d13&gt;: Angle measurement calibration result d13, value range: -2147483648 to +2147483647</li><li>&lt;d14&gt;: Angle measurement calibration result d14, value range: -2147483648 to +2147483647</li></ul>
<a name="ul20586846124910"></a><a name="ul20586846124910"></a><ul id="ul20586846124910"><li>&lt;d15&gt;: Angle measurement calibration result d15, value range: -2147483648 to +2147483647</li></ul>
<a name="ul65861146164916"></a><a name="ul65861146164916"></a><ul id="ul65861146164916"><li>&lt;d16&gt;: Angle measurement calibration result d16, value range: -2147483648 to +2147483647</li><li>&lt;d17&gt;: Angle measurement calibration result d17, value range: -2147483648 to +2147483647</li></ul>
</td>
</tr>
<tr id="row358616464495"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.4.1"><p id="p9586134610498"><a name="p9586134610498"></a><a name="p9586134610498"></a>Example</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.4.1 "><p id="p8586184613495"><a name="p8586184613495"></a><a name="p8586184613495"></a>AT+SLPWRITETRIANTCALIPARA=16319,19754,-1570034,-183423,920318,800092,2163947,-2404308,6413900,-2743629,-496770,292733,14186,-1283284,132692,-509492,-5410657,-3064726</p>
</td>
</tr>
<tr id="row5586134618492"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.5.1"><p id="p35866464491"><a name="p35866464491"></a><a name="p35866464491"></a>Note</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.5.1 "><p id="p12586546194917"><a name="p12586546194917"></a><a name="p12586546194917"></a>Calibration parameters d0 and d1 must not be negative. Writing a negative value causes the write to fail.</p>
</td>
</tr>
</tbody>
</table>

## Dongle Side Read Screen Size Parameters<a name="ZH-CN_TOPIC_0000002531808984"></a>

<a name="table15806101920313"></a>
<table><tbody><tr id="row159246197317"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.1.1"><p id="p139244199313"><a name="p139244199313"></a><a name="p139244199313"></a>Response</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.1.1 "><p id="p39241719033"><a name="p39241719033"></a><a name="p39241719033"></a>On success: OK.</p>
<p id="p99242019334"><a name="p99242019334"></a><a name="p99242019334"></a>On failure: ERROR.</p>
</td>
</tr>
<tr id="row10924319837"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.2.1"><p id="p199245191431"><a name="p199245191431"></a><a name="p199245191431"></a>Parameter Description</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.2.1 "><p id="p99245193317"><a name="p99245193317"></a><a name="p99245193317"></a>-</p>
</td>
</tr>
<tr id="row199247199311"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.3.1"><p id="p8924151911311"><a name="p8924151911311"></a><a name="p8924151911311"></a>Example</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.3.1 "><p id="p10924019438"><a name="p10924019438"></a><a name="p10924019438"></a>AT+AMREADSCREENSIZE</p>
</td>
</tr>
<tr id="row199241619236"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.4.1"><p id="p292418197310"><a name="p292418197310"></a><a name="p292418197310"></a>Log Output</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.4.1 "><p id="p129248198315"><a name="p129248198315"></a><a name="p129248198315"></a>[AM][AT] screen size:1887x1092</p>
</td>
</tr>
<tr id="row149248191537"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.5.1"><p id="p189248191232"><a name="p189248191232"></a><a name="p189248191232"></a>Note</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.5.1 "><p id="p392415195317"><a name="p392415195317"></a><a name="p392415195317"></a>Can be called only on the Dongle side. It is defined in air_mouse_dongle_at.c and is used only for maintenance testing.</p>
</td>
</tr>
</tbody>
</table>

## Dongle Side Set Preset Screen Size Parameters<a name="ZH-CN_TOPIC_0000002531649448"></a>

<a name="table781316192311"></a>
<table><tbody><tr id="row1292413195319"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.1.1"><p id="p29241819036"><a name="p29241819036"></a><a name="p29241819036"></a>Response</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.1.1 "><p id="p69246191438"><a name="p69246191438"></a><a name="p69246191438"></a>On success: OK.</p>
<p id="p209249195310"><a name="p209249195310"></a><a name="p209249195310"></a>On failure: ERROR.</p>
</td>
</tr>
<tr id="row10924181917311"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.2.1"><p id="p1392518191318"><a name="p1392518191318"></a><a name="p1392518191318"></a>Parameter Description</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.2.1 "><p id="p159311206217"><a name="p159311206217"></a><a name="p159311206217"></a>0: 16:9, 98 inches, 2162*1217;</p>
<p id="p692514191834"><a name="p692514191834"></a><a name="p692514191834"></a>1: 16:9, 85 inches, 1887*1092;</p>
<p id="p199255193318"><a name="p199255193318"></a><a name="p199255193318"></a>2: 16:9, 32 inches, 670*340;</p>
<p id="p69251319334"><a name="p69251319334"></a><a name="p69251319334"></a>3: 16:9, 17.3 inches, 382*215</p>
<p id="p149258191738"><a name="p149258191738"></a><a name="p149258191738"></a>4: 16:9, 15.6 inches, 345*194;</p>
<p id="p192511912310"><a name="p192511912310"></a><a name="p192511912310"></a>5: 16:9, 13.2 inches, 292*164;</p>
</td>
</tr>
<tr id="row79251819735"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.3.1"><p id="p2925101915315"><a name="p2925101915315"></a><a name="p2925101915315"></a>Example</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.3.1 "><p id="p492520191135"><a name="p492520191135"></a><a name="p492520191135"></a>AT+AMSETSCREENSIZE=2</p>
</td>
</tr>
<tr id="row1692514191936"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.4.1"><p id="p189257195313"><a name="p189257195313"></a><a name="p189257195313"></a>Note</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.4.1 "><p id="p1392513191038"><a name="p1392513191038"></a><a name="p1392513191038"></a>Can be called only on the Dongle side. It is defined in air_mouse_dongle_at.c and is used only for maintenance testing.</p>
</td>
</tr>
</tbody>
</table>

## Dongle Side Set Custom Screen Size Parameters<a name="ZH-CN_TOPIC_0000002562729317"></a>

<a name="table98229191435"></a>
<table><tbody><tr id="row139251019830"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.1.1"><p id="p19251919832"><a name="p19251919832"></a><a name="p19251919832"></a>Response</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.1.1 "><p id="p15925141915315"><a name="p15925141915315"></a><a name="p15925141915315"></a>On success: OK.</p>
<p id="p14925141912314"><a name="p14925141912314"></a><a name="p14925141912314"></a>On failure: ERROR.</p>
</td>
</tr>
<tr id="row2925101920312"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.2.1"><p id="p109255190311"><a name="p109255190311"></a><a name="p109255190311"></a>Parameter Description</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.2.1 "><p id="p2925151919320"><a name="p2925151919320"></a><a name="p2925151919320"></a>-</p>
</td>
</tr>
<tr id="row892581919320"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.3.1"><p id="p692511196317"><a name="p692511196317"></a><a name="p692511196317"></a>Example</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.3.1 "><p id="p2925131915313"><a name="p2925131915313"></a><a name="p2925131915313"></a>AT+AMSETCUSTOMSCREENSIZE=1887,1092</p>
</td>
</tr>
<tr id="row5925519135"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.4.1"><p id="p1992541917313"><a name="p1992541917313"></a><a name="p1992541917313"></a>Log Output</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.4.1 "><p id="p29257199314"><a name="p29257199314"></a><a name="p29257199314"></a>set screen size, mode:5, size:1887x1092</p>
</td>
</tr>
<tr id="row199257191430"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.5.1"><p id="p992581918310"><a name="p992581918310"></a><a name="p992581918310"></a>Note</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.5.1 "><p id="p1492517191318"><a name="p1492517191318"></a><a name="p1492517191318"></a>Can be called only on the Dongle side. It is defined in air_mouse_dongle_at.c and is used only for maintenance testing.</p>
</td>
</tr>
<tr id="row89251719237"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.6.1"><p id="p392513192313"><a name="p392513192313"></a><a name="p392513192313"></a>Remark</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.6.1 "><p id="p292521918317"><a name="p292521918317"></a><a name="p292521918317"></a>-</p>
</td>
</tr>
</tbody>
</table>

## Dongle Side Read Coordinate Reporting Rate<a name="ZH-CN_TOPIC_0000002531809378"></a>

<a name="table168251019433"></a>
<table><tbody><tr id="row3925171920310"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.1.1"><p id="p1092513192317"><a name="p1092513192317"></a><a name="p1092513192317"></a>Response</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.1.1 "><p id="p39253191333"><a name="p39253191333"></a><a name="p39253191333"></a>On success: OK.</p>
<p id="p1792691920320"><a name="p1792691920320"></a><a name="p1792691920320"></a>On failure: ERROR.</p>
</td>
</tr>
<tr id="row99261191317"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.2.1"><p id="p13926131911320"><a name="p13926131911320"></a><a name="p13926131911320"></a>Parameter Description</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.2.1 "><p id="p4926181916313"><a name="p4926181916313"></a><a name="p4926181916313"></a>-</p>
</td>
</tr>
<tr id="row119267191038"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.3.1"><p id="p89261019637"><a name="p89261019637"></a><a name="p89261019637"></a>Example</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.3.1 "><p id="p1192611197313"><a name="p1192611197313"></a><a name="p1192611197313"></a>AT+AMREADCURSORRPTRATE</p>
</td>
</tr>
<tr id="row3926519339"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.4.1"><p id="p129261919334"><a name="p129261919334"></a><a name="p129261919334"></a>Log Output</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.4.1 "><p id="p10926319232"><a name="p10926319232"></a><a name="p10926319232"></a>[AM][AT] cursor rpt rate:0</p>
</td>
</tr>
<tr id="row1692621911312"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.5.1"><p id="p292618198317"><a name="p292618198317"></a><a name="p292618198317"></a>Note</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.5.1 "><p id="p209261191537"><a name="p209261191537"></a><a name="p209261191537"></a>Can be called only on the Dongle side. It is defined in air_mouse_dongle_at.c and is used only for maintenance testing.</p>
</td>
</tr>
</tbody>
</table>

## Dongle Side Set Coordinate Reporting Rate<a name="ZH-CN_TOPIC_0000002562569353"></a>

<a name="table18291219439"></a>
<table><tbody><tr id="row792671912319"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.1.1"><p id="p992619194310"><a name="p992619194310"></a><a name="p992619194310"></a>Response</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.1.1 "><p id="p10926151919316"><a name="p10926151919316"></a><a name="p10926151919316"></a>On success: OK.</p>
<p id="p1592611917318"><a name="p1592611917318"></a><a name="p1592611917318"></a>On failure: ERROR.</p>
</td>
</tr>
<tr id="row39263198316"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.2.1"><p id="p392691919316"><a name="p392691919316"></a><a name="p392691919316"></a>Parameter Description</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.2.1 "><p id="p1292614197311"><a name="p1292614197311"></a><a name="p1292614197311"></a>-</p>
</td>
</tr>
<tr id="row16926101918313"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.3.1"><p id="p109261196311"><a name="p109261196311"></a><a name="p109261196311"></a>Example</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.3.1 "><p id="p1392671910318"><a name="p1392671910318"></a><a name="p1392671910318"></a>AT+AMSETCURSORRPTRATE=0</p>
</td>
</tr>
<tr id="row29262191534"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.4.1"><p id="p1792661914313"><a name="p1792661914313"></a><a name="p1792661914313"></a>Log Output</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.4.1 "><p id="p1090412567540"><a name="p1090412567540"></a><a name="p1090412567540"></a>AT set_cursor_rpt_rate:0</p>
</td>
</tr>
<tr id="row1592711198310"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.5.1"><p id="p8927819938"><a name="p8927819938"></a><a name="p8927819938"></a>Note</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.5.1 "><p id="p1492710196314"><a name="p1492710196314"></a><a name="p1492710196314"></a>Can be called only on the Dongle side. It is defined in air_mouse_dongle_at.c and is used only for maintenance testing.</p>
</td>
</tr>
<tr id="row292714198317"><th class="firstcol" valign="top" width="13.83%" id="mcps1.1.3.6.1"><p id="p6927161917317"><a name="p6927161917317"></a><a name="p6927161917317"></a>Remark</p>
</th>
<td class="cellrowborder" valign="top" width="86.17%" headers="mcps1.1.3.6.1 "><p id="p139279191631"><a name="p139279191631"></a><a name="p139279191631"></a>This function is not implemented yet.</p>
</td>
</tr>
</tbody>
</table>

## AT Command Usage Description<a name="ZH-CN_TOPIC_0000002183826172"></a>

-   **[RCU](#ZH-CN_TOPIC_0000002219226377)**  

-   **[Dongle](#ZH-CN_TOPIC_0000002219226405)**  

### RCU<a name="ZH-CN_TOPIC_0000002219226377"></a>

If you modify the sample code so that the sample does not automatically load the SLP (comment out the SLP power-on interface SlpPowerOnCommand and the start ranging interface SlpStartRangingCommand called in sle\_air\_mouse\_server.c in the sample), you can also control it through AT commands:

1.  To load the SLP, send the AT command: AT+SLPPOWERON.
2.  After the RCU and Dongle connect successfully, send the AT command: AT+SLPSTARTRANGING=1,1,1,0,0,20,0,0xA54A,0x254A.
3.  To put the SLP to sleep, send the AT command: AT+SLPSLEEP. To wake it up, resend the command: AT+SLPSTARTRANGING=1,1,1,0,0,20,0,0xA54A,0x254A.
4.  To power off the SLP, send the AT command: AT+SLPPOWEROFF.
5.  To stop ranging, send the AT command: AT+SLPSTOPRANGING. Ranging is stopped on the Dongle side simultaneously.
6.  To pause ranging, send the AT command: AT+SLPPAUSERANGING. Ranging is paused on the Dongle side simultaneously.
7.  To continue ranging, send the AT command: AT+SLPCONTINUERANGING. Ranging is continued on the Dongle side simultaneously.

### Dongle<a name="ZH-CN_TOPIC_0000002219226405"></a>

If you modify the sample code so that the sample does not automatically load the SLP (comment out the SLP power-on interface SlpPowerOnCommand called in sle\_air\_mouse\_client.c in the sample), you can also control it through AT commands:

1.  To load the SLP, send the AT command: AT+SLPPOWERON.
2.  To put the SLP to sleep, send the AT command: AT+SLPSLEEP. Wake-up is controlled by the RCU side.
3.  To power off the SLP, send the AT command: AT+SLPPOWEROFF.

# Abbreviations<a name="ZH-CN_TOPIC_0000002183985828"></a>

<a name="table166871040183216"></a>
<table><tbody><tr id="row12655112220491"><td class="cellrowborder" style="border:none" valign="top" width="19.15191519151915%"><p id="p465582204919"><a name="p465582204919"></a><a name="p465582204919"></a><strong id="b1479453812516"><a name="b1479453812516"></a><a name="b1479453812516"></a>A</strong></p>
</td>
<td class="cellrowborder" style="border:none" valign="top" width="47.51475147514751%">&nbsp;&nbsp;</td>
<td class="cellrowborder" style="border:none" valign="top" width="33.33333333333333%">&nbsp;&nbsp;</td>
</tr>
<tr id="row7115411154914"><td class="nocellnorowborder" style="border:none" valign="top" width="19.15191519151915%"><p id="p1111521174916"><a name="p1111521174916"></a><a name="p1111521174916"></a><strong id="b1380663811519"><a name="b1380663811519"></a><a name="b1380663811519"></a>AOX</strong></p>
</td>
<td class="nocellnorowborder" style="border:none" valign="top" width="47.51475147514751%"><p id="p14115911114918"><a name="p14115911114918"></a><a name="p14115911114918"></a>AOA（angle of arrival）/AOD（angle of departure）</p>
</td>
<td class="cell-norowborder" style="border:none" valign="top" width="33.33333333333333%"><p id="p12115911164919"><a name="p12115911164919"></a><a name="p12115911164919"></a>General term for angle of arrival/departure</p>
</td>
</tr>
<tr id="row771967114312"><td class="cellrowborder" style="border:none" valign="top" width="19.15191519151915%">&nbsp;&nbsp;</td>
<td class="cellrowborder" style="border:none" valign="top" width="47.51475147514751%">&nbsp;&nbsp;</td>
<td class="cellrowborder" style="border:none" valign="top" width="33.33333333333333%">&nbsp;&nbsp;</td>
</tr>
<tr id="row59593433"><td class="cellrowborder" style="border:none" valign="top" width="19.15191519151915%"><p id="p18574102395210"><a name="p18574102395210"></a><a name="p18574102395210"></a><strong id="b168196381858"><a name="b168196381858"></a><a name="b168196381858"></a>F</strong></p>
</td>
<td class="cellrowborder" style="border:none" valign="top" width="47.51475147514751%">&nbsp;&nbsp;</td>
<td class="cellrowborder" style="border:none" valign="top" width="33.33333333333333%">&nbsp;&nbsp;</td>
</tr>
<tr id="row1991894431"><td class="nocellnorowborder" style="border:none" valign="top" width="19.15191519151915%"><p id="p146683817486"><a name="p146683817486"></a><a name="p146683817486"></a><strong id="b118204381258"><a name="b118204381258"></a><a name="b118204381258"></a>FREQ</strong></p>
</td>
<td class="nocellnorowborder" style="border:none" valign="top" width="47.51475147514751%"><p id="p344120541481"><a name="p344120541481"></a><a name="p344120541481"></a>Frequency</p>
</td>
<td class="cell-norowborder" style="border:none" valign="top" width="33.33333333333333%"><p id="p56619387489"><a name="p56619387489"></a><a name="p56619387489"></a>Frequency</p>
</td>
</tr>
<tr id="row74552894413"><td class="cellrowborder" style="border:none" valign="top" width="19.15191519151915%">&nbsp;&nbsp;</td>
<td class="cellrowborder" style="border:none" valign="top" width="47.51475147514751%">&nbsp;&nbsp;</td>
<td class="cellrowborder" style="border:none" valign="top" width="33.33333333333333%">&nbsp;&nbsp;</td>
</tr>
<tr id="row1248016964410"><td class="cellrowborder" style="border:none" valign="top" width="19.15191519151915%"><p id="p131772162521"><a name="p131772162521"></a><a name="p131772162521"></a><strong id="b38213381055"><a name="b38213381055"></a><a name="b38213381055"></a>M</strong></p>
</td>
<td class="cellrowborder" style="border:none" valign="top" width="47.51475147514751%">&nbsp;&nbsp;</td>
<td class="cellrowborder" style="border:none" valign="top" width="33.33333333333333%">&nbsp;&nbsp;</td>
</tr>
<tr id="row12480391448"><td class="row-nocellborder" style="border:none" valign="top" width="19.15191519151915%"><p id="p1452831324819"><a name="p1452831324819"></a><a name="p1452831324819"></a><strong id="b982114381254"><a name="b982114381254"></a><a name="b982114381254"></a>MRSOURCE</strong></p>
</td>
<td class="row-nocellborder" style="border:none" valign="top" width="47.51475147514751%"><p id="p1551037019"><a name="p1551037019"></a><a name="p1551037019"></a>Measurement Request  Source</p>
</td>
<td class="cellrowborder" style="border:none" valign="top" width="33.33333333333333%"><p id="p17528181315481"><a name="p17528181315481"></a><a name="p17528181315481"></a>SLP measurement value request source</p>
</td>
</tr>
</tbody>
</table>

