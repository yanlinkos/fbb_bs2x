# 前言<a name="ZH-CN_TOPIC_0000001876336573"></a>

**概述<a name="section4537382116410"></a>**

本文档介绍应用层相关协议，用于指导客户开发。

**读者对象<a name="section4378592816410"></a>**

本文档主要适用于以下工程师：

-   软件开发工程师

**符号约定<a name="section133020216410"></a>**

在本文中可能出现下列标志，它们所代表的含义如下。

<a name="table2622507016410"></a>
<table><thead align="left"><tr id="row1530720816410"><th class="cellrowborder" valign="top" width="20.580000000000002%" id="mcps1.1.3.1.1"><p id="p6450074116410"><a name="p6450074116410"></a><a name="p6450074116410"></a><strong id="b2136615816410"><a name="b2136615816410"></a><a name="b2136615816410"></a>符号</strong></p>
</th>
<th class="cellrowborder" valign="top" width="79.42%" id="mcps1.1.3.1.2"><p id="p5435366816410"><a name="p5435366816410"></a><a name="p5435366816410"></a><strong id="b5941558116410"><a name="b5941558116410"></a><a name="b5941558116410"></a>说明</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row1372280416410"><td class="cellrowborder" valign="top" width="20.580000000000002%" headers="mcps1.1.3.1.1 "><p id="p3734547016410"><a name="p3734547016410"></a><a name="p3734547016410"></a><a name="image2670064316410"></a><a name="image2670064316410"></a><span><img class="" id="image2670064316410" height="25.270000000000003" width="67.83" src="figures/zh-cn_image_0000001876296353.png"></span></p>
</td>
<td class="cellrowborder" valign="top" width="79.42%" headers="mcps1.1.3.1.2 "><p id="p1757432116410"><a name="p1757432116410"></a><a name="p1757432116410"></a>表示如不避免则将会导致死亡或严重伤害的具有高等级风险的危害。</p>
</td>
</tr>
<tr id="row466863216410"><td class="cellrowborder" valign="top" width="20.580000000000002%" headers="mcps1.1.3.1.1 "><p id="p1432579516410"><a name="p1432579516410"></a><a name="p1432579516410"></a><a name="image4895582316410"></a><a name="image4895582316410"></a><span><img class="" id="image4895582316410" height="25.270000000000003" width="67.83" src="figures/zh-cn_image_0000001829616886.png"></span></p>
</td>
<td class="cellrowborder" valign="top" width="79.42%" headers="mcps1.1.3.1.2 "><p id="p959197916410"><a name="p959197916410"></a><a name="p959197916410"></a>表示如不避免则可能导致死亡或严重伤害的具有中等级风险的危害。</p>
</td>
</tr>
<tr id="row123863216410"><td class="cellrowborder" valign="top" width="20.580000000000002%" headers="mcps1.1.3.1.1 "><p id="p1232579516410"><a name="p1232579516410"></a><a name="p1232579516410"></a><a name="image1235582316410"></a><a name="image1235582316410"></a><span><img class="" id="image1235582316410" height="25.270000000000003" width="67.83" src="figures/zh-cn_image_0000001829457154.png"></span></p>
</td>
<td class="cellrowborder" valign="top" width="79.42%" headers="mcps1.1.3.1.2 "><p id="p123197916410"><a name="p123197916410"></a><a name="p123197916410"></a>表示如不避免则可能导致轻微或中度伤害的具有低等级风险的危害。</p>
</td>
</tr>
<tr id="row5786682116410"><td class="cellrowborder" valign="top" width="20.580000000000002%" headers="mcps1.1.3.1.1 "><p id="p2204984716410"><a name="p2204984716410"></a><a name="p2204984716410"></a><a name="image4504446716410"></a><a name="image4504446716410"></a><span><img class="" id="image4504446716410" height="25.270000000000003" width="67.83" src="figures/zh-cn_image_0000001876336577.png"></span></p>
</td>
<td class="cellrowborder" valign="top" width="79.42%" headers="mcps1.1.3.1.2 "><p id="p4388861916410"><a name="p4388861916410"></a><a name="p4388861916410"></a>用于传递设备或环境安全警示信息。如不避免则可能会导致设备损坏、数据丢失、设备性能降低或其它不可预知的结果。</p>
<p id="p1238861916410"><a name="p1238861916410"></a><a name="p1238861916410"></a>“须知”不涉及人身伤害。</p>
</td>
</tr>
<tr id="row2856923116410"><td class="cellrowborder" valign="top" width="20.580000000000002%" headers="mcps1.1.3.1.1 "><p id="p5555360116410"><a name="p5555360116410"></a><a name="p5555360116410"></a><a name="image799324016410"></a><a name="image799324016410"></a><span><img class="" id="image799324016410" height="25.270000000000003" width="67.83" src="figures/zh-cn_image_0000001876296357.png"></span></p>
</td>
<td class="cellrowborder" valign="top" width="79.42%" headers="mcps1.1.3.1.2 "><p id="p4612588116410"><a name="p4612588116410"></a><a name="p4612588116410"></a>对正文中重点信息的补充说明。</p>
<p id="p1232588116410"><a name="p1232588116410"></a><a name="p1232588116410"></a>“说明”不是安全警示信息，不涉及人身、设备及环境伤害信息。</p>
</td>
</tr>
</tbody>
</table>

**修改记录<a name="section2467512116410"></a>**

<a name="table1557726816410"></a>
<table><thead align="left"><tr id="row2942532716410"><th class="cellrowborder" valign="top" width="20.72%" id="mcps1.1.4.1.1"><p id="p3778275416410"><a name="p3778275416410"></a><a name="p3778275416410"></a><strong id="b5687322716410"><a name="b5687322716410"></a><a name="b5687322716410"></a>文档版本</strong></p>
</th>
<th class="cellrowborder" valign="top" width="26.119999999999997%" id="mcps1.1.4.1.2"><p id="p5627845516410"><a name="p5627845516410"></a><a name="p5627845516410"></a><strong id="b5800814916410"><a name="b5800814916410"></a><a name="b5800814916410"></a>发布日期</strong></p>
</th>
<th class="cellrowborder" valign="top" width="53.16%" id="mcps1.1.4.1.3"><p id="p2382284816410"><a name="p2382284816410"></a><a name="p2382284816410"></a><strong id="b3316380216410"><a name="b3316380216410"></a><a name="b3316380216410"></a>修改说明</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row1674128202419"><td class="cellrowborder" valign="top" width="20.72%" headers="mcps1.1.4.1.1 "><p id="p0413131712"><a name="p0413131712"></a><a name="p0413131712"></a>01</p>
</td>
<td class="cellrowborder" valign="top" width="26.119999999999997%" headers="mcps1.1.4.1.2 "><p id="p184131311111"><a name="p184131311111"></a><a name="p184131311111"></a>2024-07-04</p>
</td>
<td class="cellrowborder" valign="top" width="53.16%" headers="mcps1.1.4.1.3 "><p id="p169114261115"><a name="p169114261115"></a><a name="p169114261115"></a>第一次正式版本发布。</p>
</td>
</tr>
</tbody>
</table>

# 概述<a name="ZH-CN_TOPIC_0000001829430328"></a>



## 背景<a name="ZH-CN_TOPIC_0000001829590088"></a>

星闪协议要求从机与主机侧交互时，从机和主机侧都搭配星闪芯片。多数场景下，主机侧的星闪芯片只作为桥片使用星闪的controller功能，星闪host部署在主SOC上。但在某些应用场景下，主机侧的星闪芯片需要使用芯片自带的星闪Host，不再作为桥片。为了实现主机SOC应用层与星闪芯片内host之间的交互，需要有对应的协议传输指令和数据。

## 需求<a name="ZH-CN_TOPIC_0000001876189753"></a>

为支撑星闪芯片内host与主机SOC应用层之间进行消息交互，需要在应用层定义新的协议，简称SLE-Link协议。

# SLE Frame格式定义<a name="ZH-CN_TOPIC_0000001876269533"></a>

SLE-Link协议定义了新的SLE Frame格式，格式如下：


## SLE Frame格式定义<a name="ZH-CN_TOPIC_0000001829430332"></a>

![](figures/zh-cn_image_0000001829430412.png)

**注意： Service ID和Command ID使用0作为非法值**

<a name="table4479mcpsimp"></a>
<table><thead align="left"><tr id="row4485mcpsimp"><th class="cellrowborder" valign="top" width="16%" id="mcps1.1.4.1.1"><p id="p4487mcpsimp"><a name="p4487mcpsimp"></a><a name="p4487mcpsimp"></a>字段</p>
</th>
<th class="cellrowborder" valign="top" width="16%" id="mcps1.1.4.1.2"><p id="p4490mcpsimp"><a name="p4490mcpsimp"></a><a name="p4490mcpsimp"></a>长度</p>
</th>
<th class="cellrowborder" valign="top" width="68%" id="mcps1.1.4.1.3"><p id="p4493mcpsimp"><a name="p4493mcpsimp"></a><a name="p4493mcpsimp"></a>含义</p>
</th>
</tr>
</thead>
<tbody><tr id="row4495mcpsimp"><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.4.1.1 "><p id="p4497mcpsimp"><a name="p4497mcpsimp"></a><a name="p4497mcpsimp"></a>Flag</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.4.1.2 "><p id="p4499mcpsimp"><a name="p4499mcpsimp"></a><a name="p4499mcpsimp"></a>1Byte</p>
</td>
<td class="cellrowborder" valign="top" width="68%" headers="mcps1.1.4.1.3 "><p id="p4501mcpsimp"><a name="p4501mcpsimp"></a><a name="p4501mcpsimp"></a>Flag为固定值，作为星闪消息数据域的识别符，1字节。</p>
</td>
</tr>
<tr id="row4502mcpsimp"><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.4.1.1 "><p id="p4504mcpsimp"><a name="p4504mcpsimp"></a><a name="p4504mcpsimp"></a>Version</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.4.1.2 "><p id="p4506mcpsimp"><a name="p4506mcpsimp"></a><a name="p4506mcpsimp"></a>1Byte</p>
</td>
<td class="cellrowborder" valign="top" width="68%" headers="mcps1.1.4.1.3 "><p id="p4508mcpsimp"><a name="p4508mcpsimp"></a><a name="p4508mcpsimp"></a>Version表示对应的软件版本信息，根据需要添加，1字节。</p>
</td>
</tr>
<tr id="row4509mcpsimp"><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.4.1.1 "><p id="p4511mcpsimp"><a name="p4511mcpsimp"></a><a name="p4511mcpsimp"></a>Total Frame</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.4.1.2 "><p id="p4513mcpsimp"><a name="p4513mcpsimp"></a><a name="p4513mcpsimp"></a>1Byte</p>
</td>
<td class="cellrowborder" valign="top" width="68%" headers="mcps1.1.4.1.3 "><p id="p4515mcpsimp"><a name="p4515mcpsimp"></a><a name="p4515mcpsimp"></a>表示总包数。</p>
</td>
</tr>
<tr id="row4516mcpsimp"><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.4.1.1 "><p id="p4518mcpsimp"><a name="p4518mcpsimp"></a><a name="p4518mcpsimp"></a>Frame Seq</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.4.1.2 "><p id="p4520mcpsimp"><a name="p4520mcpsimp"></a><a name="p4520mcpsimp"></a>1Byte</p>
</td>
<td class="cellrowborder" valign="top" width="68%" headers="mcps1.1.4.1.3 "><p id="p4522mcpsimp"><a name="p4522mcpsimp"></a><a name="p4522mcpsimp"></a>表示包序号。</p>
</td>
</tr>
<tr id="row4523mcpsimp"><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.4.1.1 "><p id="p4525mcpsimp"><a name="p4525mcpsimp"></a><a name="p4525mcpsimp"></a>Rsv</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.4.1.2 "><p id="p4527mcpsimp"><a name="p4527mcpsimp"></a><a name="p4527mcpsimp"></a>1Byte</p>
</td>
<td class="cellrowborder" valign="top" width="68%" headers="mcps1.1.4.1.3 "><p id="p4529mcpsimp"><a name="p4529mcpsimp"></a><a name="p4529mcpsimp"></a>保留字段，便于拓展。</p>
</td>
</tr>
<tr id="row4530mcpsimp"><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.4.1.1 "><p id="p4532mcpsimp"><a name="p4532mcpsimp"></a><a name="p4532mcpsimp"></a>Service ID</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.4.1.2 "><p id="p4534mcpsimp"><a name="p4534mcpsimp"></a><a name="p4534mcpsimp"></a>1Byte</p>
</td>
<td class="cellrowborder" valign="top" width="68%" headers="mcps1.1.4.1.3 "><p id="p4536mcpsimp"><a name="p4536mcpsimp"></a><a name="p4536mcpsimp"></a>每个报文所属的业务类型，比如：设备发现，连接管理，OTA服务等。</p>
</td>
</tr>
<tr id="row4537mcpsimp"><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.4.1.1 "><p id="p4539mcpsimp"><a name="p4539mcpsimp"></a><a name="p4539mcpsimp"></a>CommandID</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.4.1.2 "><p id="p4541mcpsimp"><a name="p4541mcpsimp"></a><a name="p4541mcpsimp"></a>1Byte</p>
</td>
<td class="cellrowborder" valign="top" width="68%" headers="mcps1.1.4.1.3 "><p id="p4543mcpsimp"><a name="p4543mcpsimp"></a><a name="p4543mcpsimp"></a>每个业务类型下的具体操作，比如：建立连接，断开连接、参数更新。</p>
</td>
</tr>
<tr id="row4544mcpsimp"><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.4.1.1 "><p id="p4546mcpsimp"><a name="p4546mcpsimp"></a><a name="p4546mcpsimp"></a>BodyLen</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.4.1.2 "><p id="p4548mcpsimp"><a name="p4548mcpsimp"></a><a name="p4548mcpsimp"></a>2Byte</p>
</td>
<td class="cellrowborder" valign="top" width="68%" headers="mcps1.1.4.1.3 "><p id="p4550mcpsimp"><a name="p4550mcpsimp"></a><a name="p4550mcpsimp"></a>指示后续body部分的数据长度。</p>
</td>
</tr>
<tr id="row4551mcpsimp"><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.4.1.1 "><p id="p4553mcpsimp"><a name="p4553mcpsimp"></a><a name="p4553mcpsimp"></a>Body</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.4.1.2 "><p id="p4555mcpsimp"><a name="p4555mcpsimp"></a><a name="p4555mcpsimp"></a>Variable Byte</p>
</td>
<td class="cellrowborder" valign="top" width="68%" headers="mcps1.1.4.1.3 "><p id="p4557mcpsimp"><a name="p4557mcpsimp"></a><a name="p4557mcpsimp"></a>实际数据，以TLV格式，可以存放多个TLV。</p>
</td>
</tr>
<tr id="row4558mcpsimp"><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.4.1.1 "><p id="p4560mcpsimp"><a name="p4560mcpsimp"></a><a name="p4560mcpsimp"></a>MIC</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.4.1.2 "><p id="p4562mcpsimp"><a name="p4562mcpsimp"></a><a name="p4562mcpsimp"></a>2Byte</p>
</td>
<td class="cellrowborder" valign="top" width="68%" headers="mcps1.1.4.1.3 "><p id="p4564mcpsimp"><a name="p4564mcpsimp"></a><a name="p4564mcpsimp"></a>Message Integrity Check，消息完整性校验，采用CRC算法。对前面所有数据生成校验结果。</p>
</td>
</tr>
</tbody>
</table>








### Header<a name="ZH-CN_TOPIC_0000001829590092"></a>

Flag固定值：取值为0x1F。

Version：表示对应的软件版本信息。

Total Frame：表示总包数，不分包，该字段为1；如果分包，则该字段≥2。

Frame Seq：如果不分包则置为0，如果需要分包则该字段为帧序号，从1开始依次添加。

### Service ID<a name="ZH-CN_TOPIC_0000001876189757"></a>

Service ID：占1字节，用于标识服务类型。取值0\~255，每个Service ID固定从1开始编号。

Service ID定义如下表。

为了避免各个领域和产品型态的Service ID冲突，将Service ID进行统一划分：

<a name="table4574mcpsimp"></a>
<table><thead align="left"><tr id="row4580mcpsimp"><th class="cellrowborder" valign="top" width="16%" id="mcps1.1.4.1.1"><p id="p4582mcpsimp"><a name="p4582mcpsimp"></a><a name="p4582mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="43%" id="mcps1.1.4.1.2"><p id="p4584mcpsimp"><a name="p4584mcpsimp"></a><a name="p4584mcpsimp"></a>Service Name</p>
</th>
<th class="cellrowborder" valign="top" width="41%" id="mcps1.1.4.1.3"><p id="p4586mcpsimp"><a name="p4586mcpsimp"></a><a name="p4586mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row4587mcpsimp"><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.4.1.1 "><p id="p4589mcpsimp"><a name="p4589mcpsimp"></a><a name="p4589mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="43%" headers="mcps1.1.4.1.2 "><p id="p4591mcpsimp"><a name="p4591mcpsimp"></a><a name="p4591mcpsimp"></a><a href="Device-Discovery-Service.md">Device Discovery Service</a></p>
</td>
<td class="cellrowborder" valign="top" width="41%" headers="mcps1.1.4.1.3 "><p id="p4594mcpsimp"><a name="p4594mcpsimp"></a><a name="p4594mcpsimp"></a>设备发现。</p>
</td>
</tr>
<tr id="row4595mcpsimp"><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.4.1.1 "><p id="p4597mcpsimp"><a name="p4597mcpsimp"></a><a name="p4597mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="43%" headers="mcps1.1.4.1.2 "><p id="p175964513713"><a name="p175964513713"></a><a name="p175964513713"></a><a href="Connection-Management-Service.md">Connection Management Service</a></p>
</td>
<td class="cellrowborder" valign="top" width="41%" headers="mcps1.1.4.1.3 "><p id="p4602mcpsimp"><a name="p4602mcpsimp"></a><a name="p4602mcpsimp"></a>连接管理。</p>
</td>
</tr>
<tr id="row4603mcpsimp"><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.4.1.1 "><p id="p4605mcpsimp"><a name="p4605mcpsimp"></a><a name="p4605mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="43%" headers="mcps1.1.4.1.2 "><p id="p4607mcpsimp"><a name="p4607mcpsimp"></a><a name="p4607mcpsimp"></a><a href="SSAP-Client-Service.md">SSAP Client Service</a></p>
</td>
<td class="cellrowborder" valign="top" width="41%" headers="mcps1.1.4.1.3 "><p id="p4609mcpsimp"><a name="p4609mcpsimp"></a><a name="p4609mcpsimp"></a>SSAP Client服务。</p>
</td>
</tr>
<tr id="row4610mcpsimp"><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.4.1.1 "><p id="p4612mcpsimp"><a name="p4612mcpsimp"></a><a name="p4612mcpsimp"></a>0x04</p>
</td>
<td class="cellrowborder" valign="top" width="43%" headers="mcps1.1.4.1.2 "><p id="p4614mcpsimp"><a name="p4614mcpsimp"></a><a name="p4614mcpsimp"></a><a href="SSAP-Server-Service.md">SSAP Server Service</a></p>
</td>
<td class="cellrowborder" valign="top" width="41%" headers="mcps1.1.4.1.3 "><p id="p4616mcpsimp"><a name="p4616mcpsimp"></a><a name="p4616mcpsimp"></a>SSAP Server服务。</p>
</td>
</tr>
<tr id="row4617mcpsimp"><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.4.1.1 "><p id="p4619mcpsimp"><a name="p4619mcpsimp"></a><a name="p4619mcpsimp"></a>0x05</p>
</td>
<td class="cellrowborder" valign="top" width="43%" headers="mcps1.1.4.1.2 "><p id="p4621mcpsimp"><a name="p4621mcpsimp"></a><a name="p4621mcpsimp"></a><a href="Factory-Test-Service.md">Factory Test Service</a></p>
</td>
<td class="cellrowborder" valign="top" width="41%" headers="mcps1.1.4.1.3 "><p id="p4623mcpsimp"><a name="p4623mcpsimp"></a><a name="p4623mcpsimp"></a>产测模式。</p>
</td>
</tr>
<tr id="row4624mcpsimp"><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.4.1.1 "><p id="p4626mcpsimp"><a name="p4626mcpsimp"></a><a name="p4626mcpsimp"></a>0x06</p>
</td>
<td class="cellrowborder" valign="top" width="43%" headers="mcps1.1.4.1.2 "><p id="p4628mcpsimp"><a name="p4628mcpsimp"></a><a name="p4628mcpsimp"></a><a href="Low-Latency-Service.md">Low Latency Service</a></p>
</td>
<td class="cellrowborder" valign="top" width="41%" headers="mcps1.1.4.1.3 "><p id="p4630mcpsimp"><a name="p4630mcpsimp"></a><a name="p4630mcpsimp"></a>低延时模式。</p>
</td>
</tr>
</tbody>
</table>

### Command ID<a name="ZH-CN_TOPIC_0000001876269537"></a>

Command ID：占1字节，用于标识具体命令类型，每个Service ID对应的Command ID都从1开始，表明真实的逻辑行为，具体的Command ID说明在后续的服务接口定义中详细介绍。

### TLV格式<a name="ZH-CN_TOPIC_0000001829430336"></a>

TLVs封装消息中的具体信息。一个Payload的body下可以对应多个TLV。

![](figures/zh-cn_image_0000001829590172.png)

-   Type：占用1个字节，表示消息类型，取值0\~255。其中0x00，0xFF不使用，0x7F固定用作错误码。
-   Length：占用2个字节，表示后面value的长度，取值范围0\~65535。当Length为0时，表明Value不存在。
-   Value：为具体的数据。

**注：简化处理，不支持Type下再挂子节点。**

### 通用错误码<a name="ZH-CN_TOPIC_0000001829590096"></a>

通用错误码Type值为127，固定为1个字节。格式如下。

![](figures/zh-cn_image_0000001876189837.png)

<a name="table4646mcpsimp"></a>
<table><thead align="left"><tr id="row4652mcpsimp"><th class="cellrowborder" valign="top" width="16%" id="mcps1.1.4.1.1"><p id="p4654mcpsimp"><a name="p4654mcpsimp"></a><a name="p4654mcpsimp"></a><strong id="b4655mcpsimp"><a name="b4655mcpsimp"></a><a name="b4655mcpsimp"></a>Error</strong></p>
</th>
<th class="cellrowborder" valign="top" width="12%" id="mcps1.1.4.1.2"><p id="p4657mcpsimp"><a name="p4657mcpsimp"></a><a name="p4657mcpsimp"></a><strong id="b4658mcpsimp"><a name="b4658mcpsimp"></a><a name="b4658mcpsimp"></a>类别</strong></p>
</th>
<th class="cellrowborder" valign="top" width="72%" id="mcps1.1.4.1.3"><p id="p4660mcpsimp"><a name="p4660mcpsimp"></a><a name="p4660mcpsimp"></a><strong id="b4661mcpsimp"><a name="b4661mcpsimp"></a><a name="b4661mcpsimp"></a>描述</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row4662mcpsimp"><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.4.1.1 "><p id="p4664mcpsimp"><a name="p4664mcpsimp"></a><a name="p4664mcpsimp"></a>0x00</p>
</td>
<td class="cellrowborder" rowspan="9" valign="top" width="12%" headers="mcps1.1.4.1.2 "><p id="p4666mcpsimp"><a name="p4666mcpsimp"></a><a name="p4666mcpsimp"></a>通用错误</p>
</td>
<td class="cellrowborder" valign="top" width="72%" headers="mcps1.1.4.1.3 "><p id="p4668mcpsimp"><a name="p4668mcpsimp"></a><a name="p4668mcpsimp"></a>成功。</p>
</td>
</tr>
<tr id="row4669mcpsimp"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p4671mcpsimp"><a name="p4671mcpsimp"></a><a name="p4671mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p4673mcpsimp"><a name="p4673mcpsimp"></a><a name="p4673mcpsimp"></a>未知error类型。</p>
</td>
</tr>
<tr id="row4674mcpsimp"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p4676mcpsimp"><a name="p4676mcpsimp"></a><a name="p4676mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p4678mcpsimp"><a name="p4678mcpsimp"></a><a name="p4678mcpsimp"></a>不支持该请求。</p>
</td>
</tr>
<tr id="row4679mcpsimp"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p4681mcpsimp"><a name="p4681mcpsimp"></a><a name="p4681mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p4683mcpsimp"><a name="p4683mcpsimp"></a><a name="p4683mcpsimp"></a>无权限。</p>
</td>
</tr>
<tr id="row4684mcpsimp"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p4686mcpsimp"><a name="p4686mcpsimp"></a><a name="p4686mcpsimp"></a>0x04</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p4688mcpsimp"><a name="p4688mcpsimp"></a><a name="p4688mcpsimp"></a>系统忙。</p>
</td>
</tr>
<tr id="row4689mcpsimp"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p4691mcpsimp"><a name="p4691mcpsimp"></a><a name="p4691mcpsimp"></a>0x05</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p4693mcpsimp"><a name="p4693mcpsimp"></a><a name="p4693mcpsimp"></a>请求格式错误。</p>
</td>
</tr>
<tr id="row4694mcpsimp"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p4696mcpsimp"><a name="p4696mcpsimp"></a><a name="p4696mcpsimp"></a>0x06</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p4698mcpsimp"><a name="p4698mcpsimp"></a><a name="p4698mcpsimp"></a>参数错误。</p>
</td>
</tr>
<tr id="row4699mcpsimp"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p4701mcpsimp"><a name="p4701mcpsimp"></a><a name="p4701mcpsimp"></a>0x07</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p4703mcpsimp"><a name="p4703mcpsimp"></a><a name="p4703mcpsimp"></a>申请内存失败。</p>
</td>
</tr>
<tr id="row4704mcpsimp"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p4706mcpsimp"><a name="p4706mcpsimp"></a><a name="p4706mcpsimp"></a>0x08</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p4708mcpsimp"><a name="p4708mcpsimp"></a><a name="p4708mcpsimp"></a>响应超时。</p>
</td>
</tr>
</tbody>
</table>

### MIC校验<a name="ZH-CN_TOPIC_0000001876189761"></a>

发送端和接收端，都采用相同的算法进行校验证，接收到当检测到计算出来的MIC与发送端携带的MIC不同时，认为数据不合法，直接丢弃。

MIC采用CRC-16，算法名称：CRC-16/XMODEM，多项式poly：0x1021

![](figures/zh-cn_image_0000001876269617.png)

### Frame合法性原则<a name="ZH-CN_TOPIC_0000001876269541"></a>



#### 接收Frame Request<a name="ZH-CN_TOPIC_0000001829430340"></a>

Device侧检查DATA内容，Header是0x1F，且对MIC前的所有字段做校验，得到的结果与MIC的2个字节相同，则认为是合法的SLE Frame消息。

#### 接收Frame Response<a name="ZH-CN_TOPIC_0000001829590100"></a>

Host侧检查DATA内容，Header是0x1F, 且对MIC前的所有字段做校验，得到的结果与MIC的2个字节相同，则认为是合法的SLE Frame消息。

# 服务接口定义<a name="ZH-CN_TOPIC_0000001876189765"></a>







## Device Discovery Service<a name="ZH-CN_TOPIC_0000001876269545"></a>















### 使能SLE<a name="ZH-CN_TOPIC_0000001829430344"></a>

<a name="table4723mcpsimp"></a>
<table><thead align="left"><tr id="row4729mcpsimp"><th class="cellrowborder" valign="top" width="21.45%" id="mcps1.1.4.1.1"><p id="p4731mcpsimp"><a name="p4731mcpsimp"></a><a name="p4731mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="22.06%" id="mcps1.1.4.1.2"><p id="p4733mcpsimp"><a name="p4733mcpsimp"></a><a name="p4733mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="56.489999999999995%" id="mcps1.1.4.1.3"><p id="p4735mcpsimp"><a name="p4735mcpsimp"></a><a name="p4735mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row4736mcpsimp"><td class="cellrowborder" valign="top" width="21.45%" headers="mcps1.1.4.1.1 "><p id="p4738mcpsimp"><a name="p4738mcpsimp"></a><a name="p4738mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="22.06%" headers="mcps1.1.4.1.2 "><p id="p4740mcpsimp"><a name="p4740mcpsimp"></a><a name="p4740mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="56.489999999999995%" headers="mcps1.1.4.1.3 "><p id="p4742mcpsimp"><a name="p4742mcpsimp"></a><a name="p4742mcpsimp"></a>使能SLE协议栈</p>
</td>
</tr>
</tbody>
</table>

**TLV参数：**

无

### 去使能SLE<a name="ZH-CN_TOPIC_0000001829590104"></a>

<a name="table4747mcpsimp"></a>
<table><thead align="left"><tr id="row4753mcpsimp"><th class="cellrowborder" valign="top" width="21.33%" id="mcps1.1.4.1.1"><p id="p4755mcpsimp"><a name="p4755mcpsimp"></a><a name="p4755mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="22.42%" id="mcps1.1.4.1.2"><p id="p4757mcpsimp"><a name="p4757mcpsimp"></a><a name="p4757mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="56.25%" id="mcps1.1.4.1.3"><p id="p4759mcpsimp"><a name="p4759mcpsimp"></a><a name="p4759mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row4760mcpsimp"><td class="cellrowborder" valign="top" width="21.33%" headers="mcps1.1.4.1.1 "><p id="p4762mcpsimp"><a name="p4762mcpsimp"></a><a name="p4762mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="22.42%" headers="mcps1.1.4.1.2 "><p id="p4764mcpsimp"><a name="p4764mcpsimp"></a><a name="p4764mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="56.25%" headers="mcps1.1.4.1.3 "><p id="p4766mcpsimp"><a name="p4766mcpsimp"></a><a name="p4766mcpsimp"></a>去使能SLE协议栈</p>
</td>
</tr>
</tbody>
</table>

**TLV参数：**

无

### 设置本地设备地址<a name="ZH-CN_TOPIC_0000001876189769"></a>

<a name="table4771mcpsimp"></a>
<table><thead align="left"><tr id="row4777mcpsimp"><th class="cellrowborder" valign="top" width="21.26%" id="mcps1.1.4.1.1"><p id="p4779mcpsimp"><a name="p4779mcpsimp"></a><a name="p4779mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="22.689999999999998%" id="mcps1.1.4.1.2"><p id="p4781mcpsimp"><a name="p4781mcpsimp"></a><a name="p4781mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="56.05%" id="mcps1.1.4.1.3"><p id="p4783mcpsimp"><a name="p4783mcpsimp"></a><a name="p4783mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row4784mcpsimp"><td class="cellrowborder" valign="top" width="21.26%" headers="mcps1.1.4.1.1 "><p id="p4786mcpsimp"><a name="p4786mcpsimp"></a><a name="p4786mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="22.689999999999998%" headers="mcps1.1.4.1.2 "><p id="p4788mcpsimp"><a name="p4788mcpsimp"></a><a name="p4788mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="56.05%" headers="mcps1.1.4.1.3 "><p id="p4790mcpsimp"><a name="p4790mcpsimp"></a><a name="p4790mcpsimp"></a>去使能SLE协议栈</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

<a name="table4793mcpsimp"></a>
<table><thead align="left"><tr id="row4800mcpsimp"><th class="cellrowborder" valign="top" width="27%" id="mcps1.1.5.1.1"><p id="p4802mcpsimp"><a name="p4802mcpsimp"></a><a name="p4802mcpsimp"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="22%" id="mcps1.1.5.1.2"><p id="p4804mcpsimp"><a name="p4804mcpsimp"></a><a name="p4804mcpsimp"></a>Type(bit0~bit6)</p>
</th>
<th class="cellrowborder" valign="top" width="18%" id="mcps1.1.5.1.3"><p id="p4806mcpsimp"><a name="p4806mcpsimp"></a><a name="p4806mcpsimp"></a>Length</p>
<p id="p4807mcpsimp"><a name="p4807mcpsimp"></a><a name="p4807mcpsimp"></a>Size(Oct)</p>
</th>
<th class="cellrowborder" valign="top" width="33%" id="mcps1.1.5.1.4"><p id="p4809mcpsimp"><a name="p4809mcpsimp"></a><a name="p4809mcpsimp"></a>Value</p>
<p id="p4810mcpsimp"><a name="p4810mcpsimp"></a><a name="p4810mcpsimp"></a>数据类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row4811mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p4813mcpsimp"><a name="p4813mcpsimp"></a><a name="p4813mcpsimp"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p4815mcpsimp"><a name="p4815mcpsimp"></a><a name="p4815mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p4817mcpsimp"><a name="p4817mcpsimp"></a><a name="p4817mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p4819mcpsimp"><a name="p4819mcpsimp"></a><a name="p4819mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row4820mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p4822mcpsimp"><a name="p4822mcpsimp"></a><a name="p4822mcpsimp"></a>addr</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p4824mcpsimp"><a name="p4824mcpsimp"></a><a name="p4824mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p4826mcpsimp"><a name="p4826mcpsimp"></a><a name="p4826mcpsimp"></a>6</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p4828mcpsimp"><a name="p4828mcpsimp"></a><a name="p4828mcpsimp"></a>usigned char</p>
</td>
</tr>
</tbody>
</table>

### 获取本地设备地址<a name="ZH-CN_TOPIC_0000001876269549"></a>

<a name="table4830mcpsimp"></a>
<table><thead align="left"><tr id="row4836mcpsimp"><th class="cellrowborder" valign="top" width="21.3%" id="mcps1.1.4.1.1"><p id="p4838mcpsimp"><a name="p4838mcpsimp"></a><a name="p4838mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="22.88%" id="mcps1.1.4.1.2"><p id="p4840mcpsimp"><a name="p4840mcpsimp"></a><a name="p4840mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="55.82%" id="mcps1.1.4.1.3"><p id="p4842mcpsimp"><a name="p4842mcpsimp"></a><a name="p4842mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row4843mcpsimp"><td class="cellrowborder" valign="top" width="21.3%" headers="mcps1.1.4.1.1 "><p id="p4845mcpsimp"><a name="p4845mcpsimp"></a><a name="p4845mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="22.88%" headers="mcps1.1.4.1.2 "><p id="p4847mcpsimp"><a name="p4847mcpsimp"></a><a name="p4847mcpsimp"></a>0x04</p>
</td>
<td class="cellrowborder" valign="top" width="55.82%" headers="mcps1.1.4.1.3 "><p id="p4849mcpsimp"><a name="p4849mcpsimp"></a><a name="p4849mcpsimp"></a>获取本地设备地址</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

<a name="table4852mcpsimp"></a>
<table><thead align="left"><tr id="row4859mcpsimp"><th class="cellrowborder" valign="top" width="27%" id="mcps1.1.5.1.1"><p id="p4861mcpsimp"><a name="p4861mcpsimp"></a><a name="p4861mcpsimp"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="21.98%" id="mcps1.1.5.1.2"><p id="p4863mcpsimp"><a name="p4863mcpsimp"></a><a name="p4863mcpsimp"></a>Type(bit0~bit6)</p>
</th>
<th class="cellrowborder" valign="top" width="18.02%" id="mcps1.1.5.1.3"><p id="p4865mcpsimp"><a name="p4865mcpsimp"></a><a name="p4865mcpsimp"></a>Length Size(Oct)</p>
</th>
<th class="cellrowborder" valign="top" width="33%" id="mcps1.1.5.1.4"><p id="p4868mcpsimp"><a name="p4868mcpsimp"></a><a name="p4868mcpsimp"></a>Value 数据类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row4870mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p4872mcpsimp"><a name="p4872mcpsimp"></a><a name="p4872mcpsimp"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="21.98%" headers="mcps1.1.5.1.2 "><p id="p4874mcpsimp"><a name="p4874mcpsimp"></a><a name="p4874mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="18.02%" headers="mcps1.1.5.1.3 "><p id="p4876mcpsimp"><a name="p4876mcpsimp"></a><a name="p4876mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p4878mcpsimp"><a name="p4878mcpsimp"></a><a name="p4878mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row4879mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p4881mcpsimp"><a name="p4881mcpsimp"></a><a name="p4881mcpsimp"></a>addr</p>
</td>
<td class="cellrowborder" valign="top" width="21.98%" headers="mcps1.1.5.1.2 "><p id="p4883mcpsimp"><a name="p4883mcpsimp"></a><a name="p4883mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="18.02%" headers="mcps1.1.5.1.3 "><p id="p4885mcpsimp"><a name="p4885mcpsimp"></a><a name="p4885mcpsimp"></a>6</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p4887mcpsimp"><a name="p4887mcpsimp"></a><a name="p4887mcpsimp"></a>usigned char</p>
</td>
</tr>
</tbody>
</table>

### 设置本地设备名称<a name="ZH-CN_TOPIC_0000001829430348"></a>

<a name="table4889mcpsimp"></a>
<table><thead align="left"><tr id="row4895mcpsimp"><th class="cellrowborder" valign="top" width="21.12%" id="mcps1.1.4.1.1"><p id="p4897mcpsimp"><a name="p4897mcpsimp"></a><a name="p4897mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="23.13%" id="mcps1.1.4.1.2"><p id="p4899mcpsimp"><a name="p4899mcpsimp"></a><a name="p4899mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="55.75%" id="mcps1.1.4.1.3"><p id="p4901mcpsimp"><a name="p4901mcpsimp"></a><a name="p4901mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row4902mcpsimp"><td class="cellrowborder" valign="top" width="21.12%" headers="mcps1.1.4.1.1 "><p id="p4904mcpsimp"><a name="p4904mcpsimp"></a><a name="p4904mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="23.13%" headers="mcps1.1.4.1.2 "><p id="p4906mcpsimp"><a name="p4906mcpsimp"></a><a name="p4906mcpsimp"></a>0x05</p>
</td>
<td class="cellrowborder" valign="top" width="55.75%" headers="mcps1.1.4.1.3 "><p id="p4908mcpsimp"><a name="p4908mcpsimp"></a><a name="p4908mcpsimp"></a>设置本地设备名称</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

<a name="table4911mcpsimp"></a>
<table><thead align="left"><tr id="row4918mcpsimp"><th class="cellrowborder" valign="top" width="27%" id="mcps1.1.5.1.1"><p id="p4920mcpsimp"><a name="p4920mcpsimp"></a><a name="p4920mcpsimp"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="22%" id="mcps1.1.5.1.2"><p id="p4922mcpsimp"><a name="p4922mcpsimp"></a><a name="p4922mcpsimp"></a>Type(bit0~bit6)</p>
</th>
<th class="cellrowborder" valign="top" width="18%" id="mcps1.1.5.1.3"><p id="p4924mcpsimp"><a name="p4924mcpsimp"></a><a name="p4924mcpsimp"></a>Length Size(Oct)</p>
</th>
<th class="cellrowborder" valign="top" width="33%" id="mcps1.1.5.1.4"><p id="p4927mcpsimp"><a name="p4927mcpsimp"></a><a name="p4927mcpsimp"></a>Value数据类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row4929mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p4931mcpsimp"><a name="p4931mcpsimp"></a><a name="p4931mcpsimp"></a>name</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p4933mcpsimp"><a name="p4933mcpsimp"></a><a name="p4933mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p4935mcpsimp"><a name="p4935mcpsimp"></a><a name="p4935mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p4937mcpsimp"><a name="p4937mcpsimp"></a><a name="p4937mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row4938mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p4940mcpsimp"><a name="p4940mcpsimp"></a><a name="p4940mcpsimp"></a>len</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p4942mcpsimp"><a name="p4942mcpsimp"></a><a name="p4942mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p4944mcpsimp"><a name="p4944mcpsimp"></a><a name="p4944mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p4946mcpsimp"><a name="p4946mcpsimp"></a><a name="p4946mcpsimp"></a>uint8</p>
</td>
</tr>
</tbody>
</table>

### 获取本地设备名称<a name="ZH-CN_TOPIC_0000001829590108"></a>

<a name="table102mcpsimp"></a>
<table><thead align="left"><tr id="row108mcpsimp"><th class="cellrowborder" valign="top" width="20.94%" id="mcps1.1.4.1.1"><p id="p110mcpsimp"><a name="p110mcpsimp"></a><a name="p110mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="23.49%" id="mcps1.1.4.1.2"><p id="p112mcpsimp"><a name="p112mcpsimp"></a><a name="p112mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="55.57%" id="mcps1.1.4.1.3"><p id="p114mcpsimp"><a name="p114mcpsimp"></a><a name="p114mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row115mcpsimp"><td class="cellrowborder" valign="top" width="20.94%" headers="mcps1.1.4.1.1 "><p id="p117mcpsimp"><a name="p117mcpsimp"></a><a name="p117mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="23.49%" headers="mcps1.1.4.1.2 "><p id="p119mcpsimp"><a name="p119mcpsimp"></a><a name="p119mcpsimp"></a>0x06</p>
</td>
<td class="cellrowborder" valign="top" width="55.57%" headers="mcps1.1.4.1.3 "><p id="p121mcpsimp"><a name="p121mcpsimp"></a><a name="p121mcpsimp"></a>获取本地设备名称</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

<a name="table124mcpsimp"></a>
<table><thead align="left"><tr id="row131mcpsimp"><th class="cellrowborder" valign="top" width="27%" id="mcps1.1.5.1.1"><p id="p133mcpsimp"><a name="p133mcpsimp"></a><a name="p133mcpsimp"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="22%" id="mcps1.1.5.1.2"><p id="p135mcpsimp"><a name="p135mcpsimp"></a><a name="p135mcpsimp"></a>Type(bit0~bit6)</p>
</th>
<th class="cellrowborder" valign="top" width="18%" id="mcps1.1.5.1.3"><p id="p137mcpsimp"><a name="p137mcpsimp"></a><a name="p137mcpsimp"></a>Length Size(Oct)</p>
</th>
<th class="cellrowborder" valign="top" width="33%" id="mcps1.1.5.1.4"><p id="p140mcpsimp"><a name="p140mcpsimp"></a><a name="p140mcpsimp"></a>Value数据类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row142mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p144mcpsimp"><a name="p144mcpsimp"></a><a name="p144mcpsimp"></a>name</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p146mcpsimp"><a name="p146mcpsimp"></a><a name="p146mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p148mcpsimp"><a name="p148mcpsimp"></a><a name="p148mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p150mcpsimp"><a name="p150mcpsimp"></a><a name="p150mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row151mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p153mcpsimp"><a name="p153mcpsimp"></a><a name="p153mcpsimp"></a>len</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p155mcpsimp"><a name="p155mcpsimp"></a><a name="p155mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p157mcpsimp"><a name="p157mcpsimp"></a><a name="p157mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p159mcpsimp"><a name="p159mcpsimp"></a><a name="p159mcpsimp"></a>uint8</p>
</td>
</tr>
</tbody>
</table>

### 设置设备公开数据<a name="ZH-CN_TOPIC_0000001876189773"></a>

<a name="table161mcpsimp"></a>
<table><thead align="left"><tr id="row167mcpsimp"><th class="cellrowborder" valign="top" width="20.94%" id="mcps1.1.4.1.1"><p id="p169mcpsimp"><a name="p169mcpsimp"></a><a name="p169mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="23.62%" id="mcps1.1.4.1.2"><p id="p171mcpsimp"><a name="p171mcpsimp"></a><a name="p171mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="55.44%" id="mcps1.1.4.1.3"><p id="p173mcpsimp"><a name="p173mcpsimp"></a><a name="p173mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row174mcpsimp"><td class="cellrowborder" valign="top" width="20.94%" headers="mcps1.1.4.1.1 "><p id="p176mcpsimp"><a name="p176mcpsimp"></a><a name="p176mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="23.62%" headers="mcps1.1.4.1.2 "><p id="p178mcpsimp"><a name="p178mcpsimp"></a><a name="p178mcpsimp"></a>0x07</p>
</td>
<td class="cellrowborder" valign="top" width="55.44%" headers="mcps1.1.4.1.3 "><p id="p180mcpsimp"><a name="p180mcpsimp"></a><a name="p180mcpsimp"></a>设置设备公开数据</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

<a name="table183mcpsimp"></a>
<table><thead align="left"><tr id="row190mcpsimp"><th class="cellrowborder" valign="top" width="27%" id="mcps1.1.5.1.1"><p id="p192mcpsimp"><a name="p192mcpsimp"></a><a name="p192mcpsimp"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="22%" id="mcps1.1.5.1.2"><p id="p194mcpsimp"><a name="p194mcpsimp"></a><a name="p194mcpsimp"></a>Type(bit0~bit6)</p>
</th>
<th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.5.1.3"><p id="p196mcpsimp"><a name="p196mcpsimp"></a><a name="p196mcpsimp"></a>Length Size(Oct)</p>
</th>
<th class="cellrowborder" valign="top" width="30.009999999999998%" id="mcps1.1.5.1.4"><p id="p199mcpsimp"><a name="p199mcpsimp"></a><a name="p199mcpsimp"></a>Value数据类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row201mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p203mcpsimp"><a name="p203mcpsimp"></a><a name="p203mcpsimp"></a>announce_id</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p205mcpsimp"><a name="p205mcpsimp"></a><a name="p205mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.5.1.3 "><p id="p207mcpsimp"><a name="p207mcpsimp"></a><a name="p207mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="30.009999999999998%" headers="mcps1.1.5.1.4 "><p id="p209mcpsimp"><a name="p209mcpsimp"></a><a name="p209mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row210mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p212mcpsimp"><a name="p212mcpsimp"></a><a name="p212mcpsimp"></a>announce_data_len</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p214mcpsimp"><a name="p214mcpsimp"></a><a name="p214mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.5.1.3 "><p id="p216mcpsimp"><a name="p216mcpsimp"></a><a name="p216mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="30.009999999999998%" headers="mcps1.1.5.1.4 "><p id="p218mcpsimp"><a name="p218mcpsimp"></a><a name="p218mcpsimp"></a>uint16_t</p>
</td>
</tr>
<tr id="row219mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p221mcpsimp"><a name="p221mcpsimp"></a><a name="p221mcpsimp"></a>seek_rsp_data_len</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p223mcpsimp"><a name="p223mcpsimp"></a><a name="p223mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.5.1.3 "><p id="p225mcpsimp"><a name="p225mcpsimp"></a><a name="p225mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="30.009999999999998%" headers="mcps1.1.5.1.4 "><p id="p227mcpsimp"><a name="p227mcpsimp"></a><a name="p227mcpsimp"></a>uint16_t</p>
</td>
</tr>
<tr id="row228mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p230mcpsimp"><a name="p230mcpsimp"></a><a name="p230mcpsimp"></a>announce_data</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p232mcpsimp"><a name="p232mcpsimp"></a><a name="p232mcpsimp"></a>0x04</p>
</td>
<td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.5.1.3 "><p id="p234mcpsimp"><a name="p234mcpsimp"></a><a name="p234mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="30.009999999999998%" headers="mcps1.1.5.1.4 "><p id="p236mcpsimp"><a name="p236mcpsimp"></a><a name="p236mcpsimp"></a>uint8_t</p>
</td>
</tr>
<tr id="row237mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p239mcpsimp"><a name="p239mcpsimp"></a><a name="p239mcpsimp"></a>seek_rsp_data</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p241mcpsimp"><a name="p241mcpsimp"></a><a name="p241mcpsimp"></a>0x05</p>
</td>
<td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.5.1.3 "><p id="p243mcpsimp"><a name="p243mcpsimp"></a><a name="p243mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="30.009999999999998%" headers="mcps1.1.5.1.4 "><p id="p245mcpsimp"><a name="p245mcpsimp"></a><a name="p245mcpsimp"></a>uint8_t</p>
</td>
</tr>
</tbody>
</table>

### 设置设备公开参数<a name="ZH-CN_TOPIC_0000001876269553"></a>

<a name="table247mcpsimp"></a>
<table><thead align="left"><tr id="row253mcpsimp"><th class="cellrowborder" valign="top" width="21%" id="mcps1.1.4.1.1"><p id="p255mcpsimp"><a name="p255mcpsimp"></a><a name="p255mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="23.799999999999997%" id="mcps1.1.4.1.2"><p id="p257mcpsimp"><a name="p257mcpsimp"></a><a name="p257mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="55.2%" id="mcps1.1.4.1.3"><p id="p259mcpsimp"><a name="p259mcpsimp"></a><a name="p259mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row260mcpsimp"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.1.4.1.1 "><p id="p262mcpsimp"><a name="p262mcpsimp"></a><a name="p262mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="23.799999999999997%" headers="mcps1.1.4.1.2 "><p id="p264mcpsimp"><a name="p264mcpsimp"></a><a name="p264mcpsimp"></a>0x08</p>
</td>
<td class="cellrowborder" valign="top" width="55.2%" headers="mcps1.1.4.1.3 "><p id="p266mcpsimp"><a name="p266mcpsimp"></a><a name="p266mcpsimp"></a>设置设备公开参数</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

<a name="table269mcpsimp"></a>
<table><thead align="left"><tr id="row276mcpsimp"><th class="cellrowborder" valign="top" width="34.65346534653465%" id="mcps1.1.5.1.1"><p id="p278mcpsimp"><a name="p278mcpsimp"></a><a name="p278mcpsimp"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="17.82178217821782%" id="mcps1.1.5.1.2"><p id="p280mcpsimp"><a name="p280mcpsimp"></a><a name="p280mcpsimp"></a>Type(bit0~bit6)</p>
</th>
<th class="cellrowborder" valign="top" width="17.82178217821782%" id="mcps1.1.5.1.3"><p id="p282mcpsimp"><a name="p282mcpsimp"></a><a name="p282mcpsimp"></a>Length Size(Oct)</p>
</th>
<th class="cellrowborder" valign="top" width="29.7029702970297%" id="mcps1.1.5.1.4"><p id="p285mcpsimp"><a name="p285mcpsimp"></a><a name="p285mcpsimp"></a>Value数据类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row287mcpsimp"><td class="cellrowborder" valign="top" width="34.65346534653465%" headers="mcps1.1.5.1.1 "><p id="p289mcpsimp"><a name="p289mcpsimp"></a><a name="p289mcpsimp"></a>announce_id</p>
</td>
<td class="cellrowborder" valign="top" width="17.82178217821782%" headers="mcps1.1.5.1.2 "><p id="p291mcpsimp"><a name="p291mcpsimp"></a><a name="p291mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="17.82178217821782%" headers="mcps1.1.5.1.3 "><p id="p293mcpsimp"><a name="p293mcpsimp"></a><a name="p293mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="29.7029702970297%" headers="mcps1.1.5.1.4 "><p id="p295mcpsimp"><a name="p295mcpsimp"></a><a name="p295mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row296mcpsimp"><td class="cellrowborder" valign="top" width="34.65346534653465%" headers="mcps1.1.5.1.1 "><p id="p298mcpsimp"><a name="p298mcpsimp"></a><a name="p298mcpsimp"></a>announce_handle</p>
</td>
<td class="cellrowborder" valign="top" width="17.82178217821782%" headers="mcps1.1.5.1.2 "><p id="p300mcpsimp"><a name="p300mcpsimp"></a><a name="p300mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="17.82178217821782%" headers="mcps1.1.5.1.3 "><p id="p302mcpsimp"><a name="p302mcpsimp"></a><a name="p302mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="29.7029702970297%" headers="mcps1.1.5.1.4 "><p id="p304mcpsimp"><a name="p304mcpsimp"></a><a name="p304mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row305mcpsimp"><td class="cellrowborder" valign="top" width="34.65346534653465%" headers="mcps1.1.5.1.1 "><p id="p307mcpsimp"><a name="p307mcpsimp"></a><a name="p307mcpsimp"></a>announce_mode</p>
</td>
<td class="cellrowborder" valign="top" width="17.82178217821782%" headers="mcps1.1.5.1.2 "><p id="p309mcpsimp"><a name="p309mcpsimp"></a><a name="p309mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="17.82178217821782%" headers="mcps1.1.5.1.3 "><p id="p311mcpsimp"><a name="p311mcpsimp"></a><a name="p311mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="29.7029702970297%" headers="mcps1.1.5.1.4 "><p id="p313mcpsimp"><a name="p313mcpsimp"></a><a name="p313mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row314mcpsimp"><td class="cellrowborder" valign="top" width="34.65346534653465%" headers="mcps1.1.5.1.1 "><p id="p316mcpsimp"><a name="p316mcpsimp"></a><a name="p316mcpsimp"></a>announce_gt_role</p>
</td>
<td class="cellrowborder" valign="top" width="17.82178217821782%" headers="mcps1.1.5.1.2 "><p id="p318mcpsimp"><a name="p318mcpsimp"></a><a name="p318mcpsimp"></a>0x04</p>
</td>
<td class="cellrowborder" valign="top" width="17.82178217821782%" headers="mcps1.1.5.1.3 "><p id="p320mcpsimp"><a name="p320mcpsimp"></a><a name="p320mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="29.7029702970297%" headers="mcps1.1.5.1.4 "><p id="p322mcpsimp"><a name="p322mcpsimp"></a><a name="p322mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row323mcpsimp"><td class="cellrowborder" valign="top" width="34.65346534653465%" headers="mcps1.1.5.1.1 "><p id="p325mcpsimp"><a name="p325mcpsimp"></a><a name="p325mcpsimp"></a>announce_level</p>
</td>
<td class="cellrowborder" valign="top" width="17.82178217821782%" headers="mcps1.1.5.1.2 "><p id="p327mcpsimp"><a name="p327mcpsimp"></a><a name="p327mcpsimp"></a>0x05</p>
</td>
<td class="cellrowborder" valign="top" width="17.82178217821782%" headers="mcps1.1.5.1.3 "><p id="p329mcpsimp"><a name="p329mcpsimp"></a><a name="p329mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="29.7029702970297%" headers="mcps1.1.5.1.4 "><p id="p331mcpsimp"><a name="p331mcpsimp"></a><a name="p331mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row332mcpsimp"><td class="cellrowborder" valign="top" width="34.65346534653465%" headers="mcps1.1.5.1.1 "><p id="p334mcpsimp"><a name="p334mcpsimp"></a><a name="p334mcpsimp"></a>announce_interval_min</p>
</td>
<td class="cellrowborder" valign="top" width="17.82178217821782%" headers="mcps1.1.5.1.2 "><p id="p336mcpsimp"><a name="p336mcpsimp"></a><a name="p336mcpsimp"></a>0x06</p>
</td>
<td class="cellrowborder" valign="top" width="17.82178217821782%" headers="mcps1.1.5.1.3 "><p id="p338mcpsimp"><a name="p338mcpsimp"></a><a name="p338mcpsimp"></a>4</p>
</td>
<td class="cellrowborder" valign="top" width="29.7029702970297%" headers="mcps1.1.5.1.4 "><p id="p340mcpsimp"><a name="p340mcpsimp"></a><a name="p340mcpsimp"></a>uint32</p>
</td>
</tr>
<tr id="row341mcpsimp"><td class="cellrowborder" valign="top" width="34.65346534653465%" headers="mcps1.1.5.1.1 "><p id="p343mcpsimp"><a name="p343mcpsimp"></a><a name="p343mcpsimp"></a>announce_interval_max</p>
</td>
<td class="cellrowborder" valign="top" width="17.82178217821782%" headers="mcps1.1.5.1.2 "><p id="p345mcpsimp"><a name="p345mcpsimp"></a><a name="p345mcpsimp"></a>0x07</p>
</td>
<td class="cellrowborder" valign="top" width="17.82178217821782%" headers="mcps1.1.5.1.3 "><p id="p347mcpsimp"><a name="p347mcpsimp"></a><a name="p347mcpsimp"></a>4</p>
</td>
<td class="cellrowborder" valign="top" width="29.7029702970297%" headers="mcps1.1.5.1.4 "><p id="p349mcpsimp"><a name="p349mcpsimp"></a><a name="p349mcpsimp"></a>uint32</p>
</td>
</tr>
<tr id="row350mcpsimp"><td class="cellrowborder" valign="top" width="34.65346534653465%" headers="mcps1.1.5.1.1 "><p id="p352mcpsimp"><a name="p352mcpsimp"></a><a name="p352mcpsimp"></a>announce_channel_map</p>
</td>
<td class="cellrowborder" valign="top" width="17.82178217821782%" headers="mcps1.1.5.1.2 "><p id="p354mcpsimp"><a name="p354mcpsimp"></a><a name="p354mcpsimp"></a>0x08</p>
</td>
<td class="cellrowborder" valign="top" width="17.82178217821782%" headers="mcps1.1.5.1.3 "><p id="p356mcpsimp"><a name="p356mcpsimp"></a><a name="p356mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="29.7029702970297%" headers="mcps1.1.5.1.4 "><p id="p358mcpsimp"><a name="p358mcpsimp"></a><a name="p358mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row359mcpsimp"><td class="cellrowborder" valign="top" width="34.65346534653465%" headers="mcps1.1.5.1.1 "><p id="p361mcpsimp"><a name="p361mcpsimp"></a><a name="p361mcpsimp"></a>announce_tx_power</p>
</td>
<td class="cellrowborder" valign="top" width="17.82178217821782%" headers="mcps1.1.5.1.2 "><p id="p363mcpsimp"><a name="p363mcpsimp"></a><a name="p363mcpsimp"></a>0x09</p>
</td>
<td class="cellrowborder" valign="top" width="17.82178217821782%" headers="mcps1.1.5.1.3 "><p id="p365mcpsimp"><a name="p365mcpsimp"></a><a name="p365mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="29.7029702970297%" headers="mcps1.1.5.1.4 "><p id="p367mcpsimp"><a name="p367mcpsimp"></a><a name="p367mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row368mcpsimp"><td class="cellrowborder" valign="top" width="34.65346534653465%" headers="mcps1.1.5.1.1 "><p id="p370mcpsimp"><a name="p370mcpsimp"></a><a name="p370mcpsimp"></a>own_addr_type</p>
</td>
<td class="cellrowborder" valign="top" width="17.82178217821782%" headers="mcps1.1.5.1.2 "><p id="p372mcpsimp"><a name="p372mcpsimp"></a><a name="p372mcpsimp"></a>0x0A</p>
</td>
<td class="cellrowborder" valign="top" width="17.82178217821782%" headers="mcps1.1.5.1.3 "><p id="p374mcpsimp"><a name="p374mcpsimp"></a><a name="p374mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="29.7029702970297%" headers="mcps1.1.5.1.4 "><p id="p376mcpsimp"><a name="p376mcpsimp"></a><a name="p376mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row377mcpsimp"><td class="cellrowborder" valign="top" width="34.65346534653465%" headers="mcps1.1.5.1.1 "><p id="p379mcpsimp"><a name="p379mcpsimp"></a><a name="p379mcpsimp"></a>own_addr</p>
</td>
<td class="cellrowborder" valign="top" width="17.82178217821782%" headers="mcps1.1.5.1.2 "><p id="p381mcpsimp"><a name="p381mcpsimp"></a><a name="p381mcpsimp"></a>0x0B</p>
</td>
<td class="cellrowborder" valign="top" width="17.82178217821782%" headers="mcps1.1.5.1.3 "><p id="p383mcpsimp"><a name="p383mcpsimp"></a><a name="p383mcpsimp"></a>6</p>
</td>
<td class="cellrowborder" valign="top" width="29.7029702970297%" headers="mcps1.1.5.1.4 "><p id="p385mcpsimp"><a name="p385mcpsimp"></a><a name="p385mcpsimp"></a>unsigned char</p>
</td>
</tr>
<tr id="row386mcpsimp"><td class="cellrowborder" valign="top" width="34.65346534653465%" headers="mcps1.1.5.1.1 "><p id="p388mcpsimp"><a name="p388mcpsimp"></a><a name="p388mcpsimp"></a>peer_addr_type</p>
</td>
<td class="cellrowborder" valign="top" width="17.82178217821782%" headers="mcps1.1.5.1.2 "><p id="p390mcpsimp"><a name="p390mcpsimp"></a><a name="p390mcpsimp"></a>0x0C</p>
</td>
<td class="cellrowborder" valign="top" width="17.82178217821782%" headers="mcps1.1.5.1.3 "><p id="p392mcpsimp"><a name="p392mcpsimp"></a><a name="p392mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="29.7029702970297%" headers="mcps1.1.5.1.4 "><p id="p394mcpsimp"><a name="p394mcpsimp"></a><a name="p394mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row395mcpsimp"><td class="cellrowborder" valign="top" width="34.65346534653465%" headers="mcps1.1.5.1.1 "><p id="p397mcpsimp"><a name="p397mcpsimp"></a><a name="p397mcpsimp"></a>peer_addr</p>
</td>
<td class="cellrowborder" valign="top" width="17.82178217821782%" headers="mcps1.1.5.1.2 "><p id="p399mcpsimp"><a name="p399mcpsimp"></a><a name="p399mcpsimp"></a>0x0D</p>
</td>
<td class="cellrowborder" valign="top" width="17.82178217821782%" headers="mcps1.1.5.1.3 "><p id="p401mcpsimp"><a name="p401mcpsimp"></a><a name="p401mcpsimp"></a>6</p>
</td>
<td class="cellrowborder" valign="top" width="29.7029702970297%" headers="mcps1.1.5.1.4 "><p id="p403mcpsimp"><a name="p403mcpsimp"></a><a name="p403mcpsimp"></a>unsigned char</p>
</td>
</tr>
<tr id="row404mcpsimp"><td class="cellrowborder" valign="top" width="34.65346534653465%" headers="mcps1.1.5.1.1 "><p id="p406mcpsimp"><a name="p406mcpsimp"></a><a name="p406mcpsimp"></a>conn_interval_min</p>
</td>
<td class="cellrowborder" valign="top" width="17.82178217821782%" headers="mcps1.1.5.1.2 "><p id="p408mcpsimp"><a name="p408mcpsimp"></a><a name="p408mcpsimp"></a>0x0E</p>
</td>
<td class="cellrowborder" valign="top" width="17.82178217821782%" headers="mcps1.1.5.1.3 "><p id="p410mcpsimp"><a name="p410mcpsimp"></a><a name="p410mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="29.7029702970297%" headers="mcps1.1.5.1.4 "><p id="p412mcpsimp"><a name="p412mcpsimp"></a><a name="p412mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row413mcpsimp"><td class="cellrowborder" valign="top" width="34.65346534653465%" headers="mcps1.1.5.1.1 "><p id="p415mcpsimp"><a name="p415mcpsimp"></a><a name="p415mcpsimp"></a>conn_interval_max</p>
</td>
<td class="cellrowborder" valign="top" width="17.82178217821782%" headers="mcps1.1.5.1.2 "><p id="p417mcpsimp"><a name="p417mcpsimp"></a><a name="p417mcpsimp"></a>0x0F</p>
</td>
<td class="cellrowborder" valign="top" width="17.82178217821782%" headers="mcps1.1.5.1.3 "><p id="p419mcpsimp"><a name="p419mcpsimp"></a><a name="p419mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="29.7029702970297%" headers="mcps1.1.5.1.4 "><p id="p421mcpsimp"><a name="p421mcpsimp"></a><a name="p421mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row422mcpsimp"><td class="cellrowborder" valign="top" width="34.65346534653465%" headers="mcps1.1.5.1.1 "><p id="p424mcpsimp"><a name="p424mcpsimp"></a><a name="p424mcpsimp"></a>conn_max_latency</p>
</td>
<td class="cellrowborder" valign="top" width="17.82178217821782%" headers="mcps1.1.5.1.2 "><p id="p426mcpsimp"><a name="p426mcpsimp"></a><a name="p426mcpsimp"></a>0x10</p>
</td>
<td class="cellrowborder" valign="top" width="17.82178217821782%" headers="mcps1.1.5.1.3 "><p id="p428mcpsimp"><a name="p428mcpsimp"></a><a name="p428mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="29.7029702970297%" headers="mcps1.1.5.1.4 "><p id="p430mcpsimp"><a name="p430mcpsimp"></a><a name="p430mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row431mcpsimp"><td class="cellrowborder" valign="top" width="34.65346534653465%" headers="mcps1.1.5.1.1 "><p id="p433mcpsimp"><a name="p433mcpsimp"></a><a name="p433mcpsimp"></a>conn_supervision_timeout</p>
</td>
<td class="cellrowborder" valign="top" width="17.82178217821782%" headers="mcps1.1.5.1.2 "><p id="p435mcpsimp"><a name="p435mcpsimp"></a><a name="p435mcpsimp"></a>0x11</p>
</td>
<td class="cellrowborder" valign="top" width="17.82178217821782%" headers="mcps1.1.5.1.3 "><p id="p437mcpsimp"><a name="p437mcpsimp"></a><a name="p437mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="29.7029702970297%" headers="mcps1.1.5.1.4 "><p id="p439mcpsimp"><a name="p439mcpsimp"></a><a name="p439mcpsimp"></a>uint16</p>
</td>
</tr>
</tbody>
</table>

### 开始设备公开<a name="ZH-CN_TOPIC_0000001829430352"></a>

<a name="table441mcpsimp"></a>
<table><thead align="left"><tr id="row447mcpsimp"><th class="cellrowborder" valign="top" width="20.43%" id="mcps1.1.4.1.1"><p id="p449mcpsimp"><a name="p449mcpsimp"></a><a name="p449mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="24.51%" id="mcps1.1.4.1.2"><p id="p451mcpsimp"><a name="p451mcpsimp"></a><a name="p451mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="55.059999999999995%" id="mcps1.1.4.1.3"><p id="p453mcpsimp"><a name="p453mcpsimp"></a><a name="p453mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row454mcpsimp"><td class="cellrowborder" valign="top" width="20.43%" headers="mcps1.1.4.1.1 "><p id="p456mcpsimp"><a name="p456mcpsimp"></a><a name="p456mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="24.51%" headers="mcps1.1.4.1.2 "><p id="p458mcpsimp"><a name="p458mcpsimp"></a><a name="p458mcpsimp"></a>0x09</p>
</td>
<td class="cellrowborder" valign="top" width="55.059999999999995%" headers="mcps1.1.4.1.3 "><p id="p460mcpsimp"><a name="p460mcpsimp"></a><a name="p460mcpsimp"></a>开始设备公开</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

<a name="table463mcpsimp"></a>
<table><thead align="left"><tr id="row470mcpsimp"><th class="cellrowborder" valign="top" width="28.712871287128717%" id="mcps1.1.5.1.1"><p id="p472mcpsimp"><a name="p472mcpsimp"></a><a name="p472mcpsimp"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="23.762376237623766%" id="mcps1.1.5.1.2"><p id="p474mcpsimp"><a name="p474mcpsimp"></a><a name="p474mcpsimp"></a>Type(bit0~bit6)</p>
</th>
<th class="cellrowborder" valign="top" width="17.82178217821782%" id="mcps1.1.5.1.3"><p id="p476mcpsimp"><a name="p476mcpsimp"></a><a name="p476mcpsimp"></a>Length Size(Oct)</p>
</th>
<th class="cellrowborder" valign="top" width="29.7029702970297%" id="mcps1.1.5.1.4"><p id="p479mcpsimp"><a name="p479mcpsimp"></a><a name="p479mcpsimp"></a>Value数据类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row481mcpsimp"><td class="cellrowborder" valign="top" width="28.712871287128717%" headers="mcps1.1.5.1.1 "><p id="p483mcpsimp"><a name="p483mcpsimp"></a><a name="p483mcpsimp"></a>announce_id</p>
</td>
<td class="cellrowborder" valign="top" width="23.762376237623766%" headers="mcps1.1.5.1.2 "><p id="p485mcpsimp"><a name="p485mcpsimp"></a><a name="p485mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="17.82178217821782%" headers="mcps1.1.5.1.3 "><p id="p487mcpsimp"><a name="p487mcpsimp"></a><a name="p487mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="29.7029702970297%" headers="mcps1.1.5.1.4 "><p id="p489mcpsimp"><a name="p489mcpsimp"></a><a name="p489mcpsimp"></a>uint8</p>
</td>
</tr>
</tbody>
</table>

### 结束设备公开<a name="ZH-CN_TOPIC_0000001829590112"></a>

<a name="table491mcpsimp"></a>
<table><thead align="left"><tr id="row497mcpsimp"><th class="cellrowborder" valign="top" width="20.669999999999998%" id="mcps1.1.4.1.1"><p id="p499mcpsimp"><a name="p499mcpsimp"></a><a name="p499mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="24.58%" id="mcps1.1.4.1.2"><p id="p501mcpsimp"><a name="p501mcpsimp"></a><a name="p501mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="54.75%" id="mcps1.1.4.1.3"><p id="p503mcpsimp"><a name="p503mcpsimp"></a><a name="p503mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row504mcpsimp"><td class="cellrowborder" valign="top" width="20.669999999999998%" headers="mcps1.1.4.1.1 "><p id="p506mcpsimp"><a name="p506mcpsimp"></a><a name="p506mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="24.58%" headers="mcps1.1.4.1.2 "><p id="p508mcpsimp"><a name="p508mcpsimp"></a><a name="p508mcpsimp"></a>0x0A</p>
</td>
<td class="cellrowborder" valign="top" width="54.75%" headers="mcps1.1.4.1.3 "><p id="p510mcpsimp"><a name="p510mcpsimp"></a><a name="p510mcpsimp"></a>结束设备公开</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

<a name="table513mcpsimp"></a>
<table><thead align="left"><tr id="row520mcpsimp"><th class="cellrowborder" valign="top" width="28.712871287128717%" id="mcps1.1.5.1.1"><p id="p522mcpsimp"><a name="p522mcpsimp"></a><a name="p522mcpsimp"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="23.762376237623766%" id="mcps1.1.5.1.2"><p id="p524mcpsimp"><a name="p524mcpsimp"></a><a name="p524mcpsimp"></a>Type(bit0~bit6)</p>
</th>
<th class="cellrowborder" valign="top" width="17.82178217821782%" id="mcps1.1.5.1.3"><p id="p526mcpsimp"><a name="p526mcpsimp"></a><a name="p526mcpsimp"></a>Length Size(Oct)</p>
</th>
<th class="cellrowborder" valign="top" width="29.7029702970297%" id="mcps1.1.5.1.4"><p id="p529mcpsimp"><a name="p529mcpsimp"></a><a name="p529mcpsimp"></a>Value数据类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row531mcpsimp"><td class="cellrowborder" valign="top" width="28.712871287128717%" headers="mcps1.1.5.1.1 "><p id="p533mcpsimp"><a name="p533mcpsimp"></a><a name="p533mcpsimp"></a>announce_id</p>
</td>
<td class="cellrowborder" valign="top" width="23.762376237623766%" headers="mcps1.1.5.1.2 "><p id="p535mcpsimp"><a name="p535mcpsimp"></a><a name="p535mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="17.82178217821782%" headers="mcps1.1.5.1.3 "><p id="p537mcpsimp"><a name="p537mcpsimp"></a><a name="p537mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="29.7029702970297%" headers="mcps1.1.5.1.4 "><p id="p539mcpsimp"><a name="p539mcpsimp"></a><a name="p539mcpsimp"></a>uint8</p>
</td>
</tr>
</tbody>
</table>

### 设置设备扫描参数<a name="ZH-CN_TOPIC_0000001876189777"></a>

<a name="table541mcpsimp"></a>
<table><thead align="left"><tr id="row547mcpsimp"><th class="cellrowborder" valign="top" width="20.61%" id="mcps1.1.4.1.1"><p id="p549mcpsimp"><a name="p549mcpsimp"></a><a name="p549mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="24.63%" id="mcps1.1.4.1.2"><p id="p551mcpsimp"><a name="p551mcpsimp"></a><a name="p551mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="54.76%" id="mcps1.1.4.1.3"><p id="p553mcpsimp"><a name="p553mcpsimp"></a><a name="p553mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row554mcpsimp"><td class="cellrowborder" valign="top" width="20.61%" headers="mcps1.1.4.1.1 "><p id="p556mcpsimp"><a name="p556mcpsimp"></a><a name="p556mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="24.63%" headers="mcps1.1.4.1.2 "><p id="p558mcpsimp"><a name="p558mcpsimp"></a><a name="p558mcpsimp"></a>0x0B</p>
</td>
<td class="cellrowborder" valign="top" width="54.76%" headers="mcps1.1.4.1.3 "><p id="p560mcpsimp"><a name="p560mcpsimp"></a><a name="p560mcpsimp"></a>设置设备扫描参数</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

<a name="table563mcpsimp"></a>
<table><thead align="left"><tr id="row570mcpsimp"><th class="cellrowborder" valign="top" width="32.67326732673268%" id="mcps1.1.5.1.1"><p id="p572mcpsimp"><a name="p572mcpsimp"></a><a name="p572mcpsimp"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="21.782178217821784%" id="mcps1.1.5.1.2"><p id="p574mcpsimp"><a name="p574mcpsimp"></a><a name="p574mcpsimp"></a>Type(bit0~bit6)</p>
</th>
<th class="cellrowborder" valign="top" width="15.841584158415841%" id="mcps1.1.5.1.3"><p id="p576mcpsimp"><a name="p576mcpsimp"></a><a name="p576mcpsimp"></a>Length Size(Oct)</p>
</th>
<th class="cellrowborder" valign="top" width="29.7029702970297%" id="mcps1.1.5.1.4"><p id="p579mcpsimp"><a name="p579mcpsimp"></a><a name="p579mcpsimp"></a>Value数据类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row581mcpsimp"><td class="cellrowborder" valign="top" width="32.67326732673268%" headers="mcps1.1.5.1.1 "><p id="p583mcpsimp"><a name="p583mcpsimp"></a><a name="p583mcpsimp"></a>own_addr_type</p>
</td>
<td class="cellrowborder" valign="top" width="21.782178217821784%" headers="mcps1.1.5.1.2 "><p id="p585mcpsimp"><a name="p585mcpsimp"></a><a name="p585mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.5.1.3 "><p id="p587mcpsimp"><a name="p587mcpsimp"></a><a name="p587mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="29.7029702970297%" headers="mcps1.1.5.1.4 "><p id="p589mcpsimp"><a name="p589mcpsimp"></a><a name="p589mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row590mcpsimp"><td class="cellrowborder" valign="top" width="32.67326732673268%" headers="mcps1.1.5.1.1 "><p id="p592mcpsimp"><a name="p592mcpsimp"></a><a name="p592mcpsimp"></a>filter_duplicates</p>
</td>
<td class="cellrowborder" valign="top" width="21.782178217821784%" headers="mcps1.1.5.1.2 "><p id="p594mcpsimp"><a name="p594mcpsimp"></a><a name="p594mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.5.1.3 "><p id="p596mcpsimp"><a name="p596mcpsimp"></a><a name="p596mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="29.7029702970297%" headers="mcps1.1.5.1.4 "><p id="p598mcpsimp"><a name="p598mcpsimp"></a><a name="p598mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row599mcpsimp"><td class="cellrowborder" valign="top" width="32.67326732673268%" headers="mcps1.1.5.1.1 "><p id="p601mcpsimp"><a name="p601mcpsimp"></a><a name="p601mcpsimp"></a>seek_filter_policy</p>
</td>
<td class="cellrowborder" valign="top" width="21.782178217821784%" headers="mcps1.1.5.1.2 "><p id="p603mcpsimp"><a name="p603mcpsimp"></a><a name="p603mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.5.1.3 "><p id="p605mcpsimp"><a name="p605mcpsimp"></a><a name="p605mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="29.7029702970297%" headers="mcps1.1.5.1.4 "><p id="p607mcpsimp"><a name="p607mcpsimp"></a><a name="p607mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row608mcpsimp"><td class="cellrowborder" valign="top" width="32.67326732673268%" headers="mcps1.1.5.1.1 "><p id="p610mcpsimp"><a name="p610mcpsimp"></a><a name="p610mcpsimp"></a>seek_phys</p>
</td>
<td class="cellrowborder" valign="top" width="21.782178217821784%" headers="mcps1.1.5.1.2 "><p id="p612mcpsimp"><a name="p612mcpsimp"></a><a name="p612mcpsimp"></a>0x04</p>
</td>
<td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.5.1.3 "><p id="p614mcpsimp"><a name="p614mcpsimp"></a><a name="p614mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="29.7029702970297%" headers="mcps1.1.5.1.4 "><p id="p616mcpsimp"><a name="p616mcpsimp"></a><a name="p616mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row617mcpsimp"><td class="cellrowborder" valign="top" width="32.67326732673268%" headers="mcps1.1.5.1.1 "><p id="p619mcpsimp"><a name="p619mcpsimp"></a><a name="p619mcpsimp"></a>seek_type</p>
</td>
<td class="cellrowborder" valign="top" width="21.782178217821784%" headers="mcps1.1.5.1.2 "><p id="p621mcpsimp"><a name="p621mcpsimp"></a><a name="p621mcpsimp"></a>0x05</p>
</td>
<td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.5.1.3 "><p id="p623mcpsimp"><a name="p623mcpsimp"></a><a name="p623mcpsimp"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="29.7029702970297%" headers="mcps1.1.5.1.4 "><p id="p625mcpsimp"><a name="p625mcpsimp"></a><a name="p625mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row626mcpsimp"><td class="cellrowborder" valign="top" width="32.67326732673268%" headers="mcps1.1.5.1.1 "><p id="p628mcpsimp"><a name="p628mcpsimp"></a><a name="p628mcpsimp"></a>seek_interval</p>
</td>
<td class="cellrowborder" valign="top" width="21.782178217821784%" headers="mcps1.1.5.1.2 "><p id="p630mcpsimp"><a name="p630mcpsimp"></a><a name="p630mcpsimp"></a>0x06</p>
</td>
<td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.5.1.3 "><p id="p632mcpsimp"><a name="p632mcpsimp"></a><a name="p632mcpsimp"></a>6</p>
</td>
<td class="cellrowborder" valign="top" width="29.7029702970297%" headers="mcps1.1.5.1.4 "><p id="p634mcpsimp"><a name="p634mcpsimp"></a><a name="p634mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row635mcpsimp"><td class="cellrowborder" valign="top" width="32.67326732673268%" headers="mcps1.1.5.1.1 "><p id="p637mcpsimp"><a name="p637mcpsimp"></a><a name="p637mcpsimp"></a>seek_window</p>
</td>
<td class="cellrowborder" valign="top" width="21.782178217821784%" headers="mcps1.1.5.1.2 "><p id="p639mcpsimp"><a name="p639mcpsimp"></a><a name="p639mcpsimp"></a>0x07</p>
</td>
<td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.5.1.3 "><p id="p641mcpsimp"><a name="p641mcpsimp"></a><a name="p641mcpsimp"></a>6</p>
</td>
<td class="cellrowborder" valign="top" width="29.7029702970297%" headers="mcps1.1.5.1.4 "><p id="p643mcpsimp"><a name="p643mcpsimp"></a><a name="p643mcpsimp"></a>uint16</p>
</td>
</tr>
</tbody>
</table>

### 上报设备扫描结果<a name="ZH-CN_TOPIC_0000001876269557"></a>

<a name="table645mcpsimp"></a>
<table><thead align="left"><tr id="row651mcpsimp"><th class="cellrowborder" valign="top" width="21.060000000000002%" id="mcps1.1.4.1.1"><p id="p653mcpsimp"><a name="p653mcpsimp"></a><a name="p653mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="24.81%" id="mcps1.1.4.1.2"><p id="p655mcpsimp"><a name="p655mcpsimp"></a><a name="p655mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="54.13%" id="mcps1.1.4.1.3"><p id="p657mcpsimp"><a name="p657mcpsimp"></a><a name="p657mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row658mcpsimp"><td class="cellrowborder" valign="top" width="21.060000000000002%" headers="mcps1.1.4.1.1 "><p id="p660mcpsimp"><a name="p660mcpsimp"></a><a name="p660mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="24.81%" headers="mcps1.1.4.1.2 "><p id="p662mcpsimp"><a name="p662mcpsimp"></a><a name="p662mcpsimp"></a>0x0C</p>
</td>
<td class="cellrowborder" valign="top" width="54.13%" headers="mcps1.1.4.1.3 "><p id="p664mcpsimp"><a name="p664mcpsimp"></a><a name="p664mcpsimp"></a>上报设备扫描结果</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

<a name="table667mcpsimp"></a>
<table><thead align="left"><tr id="row674mcpsimp"><th class="cellrowborder" valign="top" width="32.67326732673268%" id="mcps1.1.5.1.1"><p id="p676mcpsimp"><a name="p676mcpsimp"></a><a name="p676mcpsimp"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="21.782178217821784%" id="mcps1.1.5.1.2"><p id="p678mcpsimp"><a name="p678mcpsimp"></a><a name="p678mcpsimp"></a>Type(bit0~bit6)</p>
</th>
<th class="cellrowborder" valign="top" width="15.841584158415841%" id="mcps1.1.5.1.3"><p id="p680mcpsimp"><a name="p680mcpsimp"></a><a name="p680mcpsimp"></a>Length Size(Oct)</p>
</th>
<th class="cellrowborder" valign="top" width="29.7029702970297%" id="mcps1.1.5.1.4"><p id="p683mcpsimp"><a name="p683mcpsimp"></a><a name="p683mcpsimp"></a>Value数据类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row685mcpsimp"><td class="cellrowborder" valign="top" width="32.67326732673268%" headers="mcps1.1.5.1.1 "><p id="p687mcpsimp"><a name="p687mcpsimp"></a><a name="p687mcpsimp"></a>event_type</p>
</td>
<td class="cellrowborder" valign="top" width="21.782178217821784%" headers="mcps1.1.5.1.2 "><p id="p689mcpsimp"><a name="p689mcpsimp"></a><a name="p689mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.5.1.3 "><p id="p691mcpsimp"><a name="p691mcpsimp"></a><a name="p691mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="29.7029702970297%" headers="mcps1.1.5.1.4 "><p id="p693mcpsimp"><a name="p693mcpsimp"></a><a name="p693mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row694mcpsimp"><td class="cellrowborder" valign="top" width="32.67326732673268%" headers="mcps1.1.5.1.1 "><p id="p696mcpsimp"><a name="p696mcpsimp"></a><a name="p696mcpsimp"></a>addr_type</p>
</td>
<td class="cellrowborder" valign="top" width="21.782178217821784%" headers="mcps1.1.5.1.2 "><p id="p698mcpsimp"><a name="p698mcpsimp"></a><a name="p698mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.5.1.3 "><p id="p700mcpsimp"><a name="p700mcpsimp"></a><a name="p700mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="29.7029702970297%" headers="mcps1.1.5.1.4 "><p id="p702mcpsimp"><a name="p702mcpsimp"></a><a name="p702mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row703mcpsimp"><td class="cellrowborder" valign="top" width="32.67326732673268%" headers="mcps1.1.5.1.1 "><p id="p705mcpsimp"><a name="p705mcpsimp"></a><a name="p705mcpsimp"></a>addr</p>
</td>
<td class="cellrowborder" valign="top" width="21.782178217821784%" headers="mcps1.1.5.1.2 "><p id="p707mcpsimp"><a name="p707mcpsimp"></a><a name="p707mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.5.1.3 "><p id="p709mcpsimp"><a name="p709mcpsimp"></a><a name="p709mcpsimp"></a>6</p>
</td>
<td class="cellrowborder" valign="top" width="29.7029702970297%" headers="mcps1.1.5.1.4 "><p id="p711mcpsimp"><a name="p711mcpsimp"></a><a name="p711mcpsimp"></a>unsigned char</p>
</td>
</tr>
<tr id="row712mcpsimp"><td class="cellrowborder" valign="top" width="32.67326732673268%" headers="mcps1.1.5.1.1 "><p id="p714mcpsimp"><a name="p714mcpsimp"></a><a name="p714mcpsimp"></a>direct_addr_type</p>
</td>
<td class="cellrowborder" valign="top" width="21.782178217821784%" headers="mcps1.1.5.1.2 "><p id="p716mcpsimp"><a name="p716mcpsimp"></a><a name="p716mcpsimp"></a>0x04</p>
</td>
<td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.5.1.3 "><p id="p718mcpsimp"><a name="p718mcpsimp"></a><a name="p718mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="29.7029702970297%" headers="mcps1.1.5.1.4 "><p id="p720mcpsimp"><a name="p720mcpsimp"></a><a name="p720mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row721mcpsimp"><td class="cellrowborder" valign="top" width="32.67326732673268%" headers="mcps1.1.5.1.1 "><p id="p723mcpsimp"><a name="p723mcpsimp"></a><a name="p723mcpsimp"></a>direct_addr</p>
</td>
<td class="cellrowborder" valign="top" width="21.782178217821784%" headers="mcps1.1.5.1.2 "><p id="p725mcpsimp"><a name="p725mcpsimp"></a><a name="p725mcpsimp"></a>0x05</p>
</td>
<td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.5.1.3 "><p id="p727mcpsimp"><a name="p727mcpsimp"></a><a name="p727mcpsimp"></a>6</p>
</td>
<td class="cellrowborder" valign="top" width="29.7029702970297%" headers="mcps1.1.5.1.4 "><p id="p729mcpsimp"><a name="p729mcpsimp"></a><a name="p729mcpsimp"></a>unsigned char</p>
</td>
</tr>
<tr id="row730mcpsimp"><td class="cellrowborder" valign="top" width="32.67326732673268%" headers="mcps1.1.5.1.1 "><p id="p732mcpsimp"><a name="p732mcpsimp"></a><a name="p732mcpsimp"></a>rssi</p>
</td>
<td class="cellrowborder" valign="top" width="21.782178217821784%" headers="mcps1.1.5.1.2 "><p id="p734mcpsimp"><a name="p734mcpsimp"></a><a name="p734mcpsimp"></a>0x06</p>
</td>
<td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.5.1.3 "><p id="p736mcpsimp"><a name="p736mcpsimp"></a><a name="p736mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="29.7029702970297%" headers="mcps1.1.5.1.4 "><p id="p738mcpsimp"><a name="p738mcpsimp"></a><a name="p738mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row739mcpsimp"><td class="cellrowborder" valign="top" width="32.67326732673268%" headers="mcps1.1.5.1.1 "><p id="p741mcpsimp"><a name="p741mcpsimp"></a><a name="p741mcpsimp"></a>data_status</p>
</td>
<td class="cellrowborder" valign="top" width="21.782178217821784%" headers="mcps1.1.5.1.2 "><p id="p743mcpsimp"><a name="p743mcpsimp"></a><a name="p743mcpsimp"></a>0x07</p>
</td>
<td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.5.1.3 "><p id="p745mcpsimp"><a name="p745mcpsimp"></a><a name="p745mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="29.7029702970297%" headers="mcps1.1.5.1.4 "><p id="p747mcpsimp"><a name="p747mcpsimp"></a><a name="p747mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row748mcpsimp"><td class="cellrowborder" valign="top" width="32.67326732673268%" headers="mcps1.1.5.1.1 "><p id="p750mcpsimp"><a name="p750mcpsimp"></a><a name="p750mcpsimp"></a>data_lenth</p>
</td>
<td class="cellrowborder" valign="top" width="21.782178217821784%" headers="mcps1.1.5.1.2 "><p id="p752mcpsimp"><a name="p752mcpsimp"></a><a name="p752mcpsimp"></a>0x08</p>
</td>
<td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.5.1.3 "><p id="p754mcpsimp"><a name="p754mcpsimp"></a><a name="p754mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="29.7029702970297%" headers="mcps1.1.5.1.4 "><p id="p756mcpsimp"><a name="p756mcpsimp"></a><a name="p756mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row757mcpsimp"><td class="cellrowborder" valign="top" width="32.67326732673268%" headers="mcps1.1.5.1.1 "><p id="p759mcpsimp"><a name="p759mcpsimp"></a><a name="p759mcpsimp"></a>data</p>
</td>
<td class="cellrowborder" valign="top" width="21.782178217821784%" headers="mcps1.1.5.1.2 "><p id="p761mcpsimp"><a name="p761mcpsimp"></a><a name="p761mcpsimp"></a>0x09</p>
</td>
<td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.5.1.3 "><p id="p763mcpsimp"><a name="p763mcpsimp"></a><a name="p763mcpsimp"></a>n</p>
</td>
<td class="cellrowborder" valign="top" width="29.7029702970297%" headers="mcps1.1.5.1.4 "><p id="p765mcpsimp"><a name="p765mcpsimp"></a><a name="p765mcpsimp"></a>uint8</p>
</td>
</tr>
</tbody>
</table>

### 开始设备扫描<a name="ZH-CN_TOPIC_0000001829430356"></a>

<a name="table767mcpsimp"></a>
<table><thead align="left"><tr id="row773mcpsimp"><th class="cellrowborder" valign="top" width="21.75%" id="mcps1.1.4.1.1"><p id="p775mcpsimp"><a name="p775mcpsimp"></a><a name="p775mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="24.8%" id="mcps1.1.4.1.2"><p id="p777mcpsimp"><a name="p777mcpsimp"></a><a name="p777mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="53.449999999999996%" id="mcps1.1.4.1.3"><p id="p779mcpsimp"><a name="p779mcpsimp"></a><a name="p779mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row780mcpsimp"><td class="cellrowborder" valign="top" width="21.75%" headers="mcps1.1.4.1.1 "><p id="p782mcpsimp"><a name="p782mcpsimp"></a><a name="p782mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="24.8%" headers="mcps1.1.4.1.2 "><p id="p784mcpsimp"><a name="p784mcpsimp"></a><a name="p784mcpsimp"></a>0x0D</p>
</td>
<td class="cellrowborder" valign="top" width="53.449999999999996%" headers="mcps1.1.4.1.3 "><p id="p786mcpsimp"><a name="p786mcpsimp"></a><a name="p786mcpsimp"></a>开始设备扫描</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

无

### 停止设备扫描<a name="ZH-CN_TOPIC_0000001829590116"></a>

<a name="table791mcpsimp"></a>
<table><thead align="left"><tr id="row797mcpsimp"><th class="cellrowborder" valign="top" width="21.73%" id="mcps1.1.4.1.1"><p id="p799mcpsimp"><a name="p799mcpsimp"></a><a name="p799mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="24.8%" id="mcps1.1.4.1.2"><p id="p801mcpsimp"><a name="p801mcpsimp"></a><a name="p801mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="53.47%" id="mcps1.1.4.1.3"><p id="p803mcpsimp"><a name="p803mcpsimp"></a><a name="p803mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row804mcpsimp"><td class="cellrowborder" valign="top" width="21.73%" headers="mcps1.1.4.1.1 "><p id="p806mcpsimp"><a name="p806mcpsimp"></a><a name="p806mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="24.8%" headers="mcps1.1.4.1.2 "><p id="p808mcpsimp"><a name="p808mcpsimp"></a><a name="p808mcpsimp"></a>0x0E</p>
</td>
<td class="cellrowborder" valign="top" width="53.47%" headers="mcps1.1.4.1.3 "><p id="p810mcpsimp"><a name="p810mcpsimp"></a><a name="p810mcpsimp"></a>停止设备扫描</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

无

## Connection Management Service<a name="ZH-CN_TOPIC_0000001876189781"></a>




















### 发送链接请求<a name="ZH-CN_TOPIC_0000001876269561"></a>

<a name="table4306mcpsimp"></a>
<table><thead align="left"><tr id="row4312mcpsimp"><th class="cellrowborder" valign="top" width="22.06%" id="mcps1.1.4.1.1"><p id="p4314mcpsimp"><a name="p4314mcpsimp"></a><a name="p4314mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="24.560000000000002%" id="mcps1.1.4.1.2"><p id="p4316mcpsimp"><a name="p4316mcpsimp"></a><a name="p4316mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="53.38%" id="mcps1.1.4.1.3"><p id="p4318mcpsimp"><a name="p4318mcpsimp"></a><a name="p4318mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row4319mcpsimp"><td class="cellrowborder" valign="top" width="22.06%" headers="mcps1.1.4.1.1 "><p id="p4321mcpsimp"><a name="p4321mcpsimp"></a><a name="p4321mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="24.560000000000002%" headers="mcps1.1.4.1.2 "><p id="p4323mcpsimp"><a name="p4323mcpsimp"></a><a name="p4323mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="53.38%" headers="mcps1.1.4.1.3 "><p id="p4325mcpsimp"><a name="p4325mcpsimp"></a><a name="p4325mcpsimp"></a>发送链接请求</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

<a name="table4328mcpsimp"></a>
<table><thead align="left"><tr id="row4335mcpsimp"><th class="cellrowborder" valign="top" width="27%" id="mcps1.1.5.1.1"><p id="p4337mcpsimp"><a name="p4337mcpsimp"></a><a name="p4337mcpsimp"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="22%" id="mcps1.1.5.1.2"><p id="p4339mcpsimp"><a name="p4339mcpsimp"></a><a name="p4339mcpsimp"></a>Type(bit0~bit6)</p>
</th>
<th class="cellrowborder" valign="top" width="18%" id="mcps1.1.5.1.3"><p id="p4341mcpsimp"><a name="p4341mcpsimp"></a><a name="p4341mcpsimp"></a>Length Size(Oct)</p>
</th>
<th class="cellrowborder" valign="top" width="33%" id="mcps1.1.5.1.4"><p id="p4344mcpsimp"><a name="p4344mcpsimp"></a><a name="p4344mcpsimp"></a>Value数据类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row4346mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p4348mcpsimp"><a name="p4348mcpsimp"></a><a name="p4348mcpsimp"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p4350mcpsimp"><a name="p4350mcpsimp"></a><a name="p4350mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p4352mcpsimp"><a name="p4352mcpsimp"></a><a name="p4352mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p4354mcpsimp"><a name="p4354mcpsimp"></a><a name="p4354mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row4355mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p4357mcpsimp"><a name="p4357mcpsimp"></a><a name="p4357mcpsimp"></a>addr</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p4359mcpsimp"><a name="p4359mcpsimp"></a><a name="p4359mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p4361mcpsimp"><a name="p4361mcpsimp"></a><a name="p4361mcpsimp"></a>6</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p4363mcpsimp"><a name="p4363mcpsimp"></a><a name="p4363mcpsimp"></a>usigned char</p>
</td>
</tr>
</tbody>
</table>

### 断开链接请求<a name="ZH-CN_TOPIC_0000001829430360"></a>

<a name="table818mcpsimp"></a>
<table><thead align="left"><tr id="row824mcpsimp"><th class="cellrowborder" valign="top" width="22.439999999999998%" id="mcps1.1.4.1.1"><p id="p826mcpsimp"><a name="p826mcpsimp"></a><a name="p826mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="24.14%" id="mcps1.1.4.1.2"><p id="p828mcpsimp"><a name="p828mcpsimp"></a><a name="p828mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="53.42%" id="mcps1.1.4.1.3"><p id="p830mcpsimp"><a name="p830mcpsimp"></a><a name="p830mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row831mcpsimp"><td class="cellrowborder" valign="top" width="22.439999999999998%" headers="mcps1.1.4.1.1 "><p id="p833mcpsimp"><a name="p833mcpsimp"></a><a name="p833mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="24.14%" headers="mcps1.1.4.1.2 "><p id="p835mcpsimp"><a name="p835mcpsimp"></a><a name="p835mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="53.42%" headers="mcps1.1.4.1.3 "><p id="p837mcpsimp"><a name="p837mcpsimp"></a><a name="p837mcpsimp"></a>断开链接请求</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

<a name="table840mcpsimp"></a>
<table><thead align="left"><tr id="row847mcpsimp"><th class="cellrowborder" valign="top" width="27%" id="mcps1.1.5.1.1"><p id="p849mcpsimp"><a name="p849mcpsimp"></a><a name="p849mcpsimp"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="22%" id="mcps1.1.5.1.2"><p id="p851mcpsimp"><a name="p851mcpsimp"></a><a name="p851mcpsimp"></a>Type(bit0~bit6)</p>
</th>
<th class="cellrowborder" valign="top" width="18%" id="mcps1.1.5.1.3"><p id="p853mcpsimp"><a name="p853mcpsimp"></a><a name="p853mcpsimp"></a>Length Size(Oct)</p>
</th>
<th class="cellrowborder" valign="top" width="33%" id="mcps1.1.5.1.4"><p id="p856mcpsimp"><a name="p856mcpsimp"></a><a name="p856mcpsimp"></a>Value数据类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row858mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p860mcpsimp"><a name="p860mcpsimp"></a><a name="p860mcpsimp"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p862mcpsimp"><a name="p862mcpsimp"></a><a name="p862mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p864mcpsimp"><a name="p864mcpsimp"></a><a name="p864mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p866mcpsimp"><a name="p866mcpsimp"></a><a name="p866mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row867mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p869mcpsimp"><a name="p869mcpsimp"></a><a name="p869mcpsimp"></a>addr</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p871mcpsimp"><a name="p871mcpsimp"></a><a name="p871mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p873mcpsimp"><a name="p873mcpsimp"></a><a name="p873mcpsimp"></a>6</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p875mcpsimp"><a name="p875mcpsimp"></a><a name="p875mcpsimp"></a>usigned char</p>
</td>
</tr>
</tbody>
</table>

### 更新链接参数请求<a name="ZH-CN_TOPIC_0000001829590120"></a>

<a name="table877mcpsimp"></a>
<table><thead align="left"><tr id="row883mcpsimp"><th class="cellrowborder" valign="top" width="22.81%" id="mcps1.1.4.1.1"><p id="p885mcpsimp"><a name="p885mcpsimp"></a><a name="p885mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="23.919999999999998%" id="mcps1.1.4.1.2"><p id="p887mcpsimp"><a name="p887mcpsimp"></a><a name="p887mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="53.269999999999996%" id="mcps1.1.4.1.3"><p id="p889mcpsimp"><a name="p889mcpsimp"></a><a name="p889mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row890mcpsimp"><td class="cellrowborder" valign="top" width="22.81%" headers="mcps1.1.4.1.1 "><p id="p892mcpsimp"><a name="p892mcpsimp"></a><a name="p892mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="23.919999999999998%" headers="mcps1.1.4.1.2 "><p id="p894mcpsimp"><a name="p894mcpsimp"></a><a name="p894mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="53.269999999999996%" headers="mcps1.1.4.1.3 "><p id="p896mcpsimp"><a name="p896mcpsimp"></a><a name="p896mcpsimp"></a>更新链接参数请求</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

<a name="table899mcpsimp"></a>
<table><thead align="left"><tr id="row906mcpsimp"><th class="cellrowborder" valign="top" width="27%" id="mcps1.1.5.1.1"><p id="p908mcpsimp"><a name="p908mcpsimp"></a><a name="p908mcpsimp"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="22%" id="mcps1.1.5.1.2"><p id="p910mcpsimp"><a name="p910mcpsimp"></a><a name="p910mcpsimp"></a>Type(bit0~bit6)</p>
</th>
<th class="cellrowborder" valign="top" width="18%" id="mcps1.1.5.1.3"><p id="p912mcpsimp"><a name="p912mcpsimp"></a><a name="p912mcpsimp"></a>Length Size(Oct)</p>
</th>
<th class="cellrowborder" valign="top" width="33%" id="mcps1.1.5.1.4"><p id="p915mcpsimp"><a name="p915mcpsimp"></a><a name="p915mcpsimp"></a>Value数据类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row917mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p919mcpsimp"><a name="p919mcpsimp"></a><a name="p919mcpsimp"></a>conn_id</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p921mcpsimp"><a name="p921mcpsimp"></a><a name="p921mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p923mcpsimp"><a name="p923mcpsimp"></a><a name="p923mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p925mcpsimp"><a name="p925mcpsimp"></a><a name="p925mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row926mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p928mcpsimp"><a name="p928mcpsimp"></a><a name="p928mcpsimp"></a>interval_min</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p930mcpsimp"><a name="p930mcpsimp"></a><a name="p930mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p932mcpsimp"><a name="p932mcpsimp"></a><a name="p932mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p934mcpsimp"><a name="p934mcpsimp"></a><a name="p934mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row935mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p937mcpsimp"><a name="p937mcpsimp"></a><a name="p937mcpsimp"></a>interval_max</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p939mcpsimp"><a name="p939mcpsimp"></a><a name="p939mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p941mcpsimp"><a name="p941mcpsimp"></a><a name="p941mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p943mcpsimp"><a name="p943mcpsimp"></a><a name="p943mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row944mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p946mcpsimp"><a name="p946mcpsimp"></a><a name="p946mcpsimp"></a>max_latency</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p948mcpsimp"><a name="p948mcpsimp"></a><a name="p948mcpsimp"></a>0x04</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p950mcpsimp"><a name="p950mcpsimp"></a><a name="p950mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p952mcpsimp"><a name="p952mcpsimp"></a><a name="p952mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row953mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p955mcpsimp"><a name="p955mcpsimp"></a><a name="p955mcpsimp"></a>supervision_timeout</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p957mcpsimp"><a name="p957mcpsimp"></a><a name="p957mcpsimp"></a>0x05</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p959mcpsimp"><a name="p959mcpsimp"></a><a name="p959mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p961mcpsimp"><a name="p961mcpsimp"></a><a name="p961mcpsimp"></a>uint16</p>
</td>
</tr>
</tbody>
</table>

### 发送配对请求<a name="ZH-CN_TOPIC_0000001876189785"></a>

<a name="table963mcpsimp"></a>
<table><thead align="left"><tr id="row969mcpsimp"><th class="cellrowborder" valign="top" width="22.98%" id="mcps1.1.4.1.1"><p id="p971mcpsimp"><a name="p971mcpsimp"></a><a name="p971mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="23.87%" id="mcps1.1.4.1.2"><p id="p973mcpsimp"><a name="p973mcpsimp"></a><a name="p973mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="53.15%" id="mcps1.1.4.1.3"><p id="p975mcpsimp"><a name="p975mcpsimp"></a><a name="p975mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row976mcpsimp"><td class="cellrowborder" valign="top" width="22.98%" headers="mcps1.1.4.1.1 "><p id="p978mcpsimp"><a name="p978mcpsimp"></a><a name="p978mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="23.87%" headers="mcps1.1.4.1.2 "><p id="p980mcpsimp"><a name="p980mcpsimp"></a><a name="p980mcpsimp"></a>0x04</p>
</td>
<td class="cellrowborder" valign="top" width="53.15%" headers="mcps1.1.4.1.3 "><p id="p982mcpsimp"><a name="p982mcpsimp"></a><a name="p982mcpsimp"></a>发送配对请求</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

<a name="table985mcpsimp"></a>
<table><thead align="left"><tr id="row992mcpsimp"><th class="cellrowborder" valign="top" width="27%" id="mcps1.1.5.1.1"><p id="p994mcpsimp"><a name="p994mcpsimp"></a><a name="p994mcpsimp"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="21.98%" id="mcps1.1.5.1.2"><p id="p996mcpsimp"><a name="p996mcpsimp"></a><a name="p996mcpsimp"></a>Type(bit0~bit6)</p>
</th>
<th class="cellrowborder" valign="top" width="18.02%" id="mcps1.1.5.1.3"><p id="p998mcpsimp"><a name="p998mcpsimp"></a><a name="p998mcpsimp"></a>Length Size(Oct)</p>
</th>
<th class="cellrowborder" valign="top" width="33%" id="mcps1.1.5.1.4"><p id="p1001mcpsimp"><a name="p1001mcpsimp"></a><a name="p1001mcpsimp"></a>Value数据类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row1003mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p1005mcpsimp"><a name="p1005mcpsimp"></a><a name="p1005mcpsimp"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="21.98%" headers="mcps1.1.5.1.2 "><p id="p1007mcpsimp"><a name="p1007mcpsimp"></a><a name="p1007mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="18.02%" headers="mcps1.1.5.1.3 "><p id="p1009mcpsimp"><a name="p1009mcpsimp"></a><a name="p1009mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p1011mcpsimp"><a name="p1011mcpsimp"></a><a name="p1011mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row1012mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p1014mcpsimp"><a name="p1014mcpsimp"></a><a name="p1014mcpsimp"></a>addr</p>
</td>
<td class="cellrowborder" valign="top" width="21.98%" headers="mcps1.1.5.1.2 "><p id="p1016mcpsimp"><a name="p1016mcpsimp"></a><a name="p1016mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="18.02%" headers="mcps1.1.5.1.3 "><p id="p1018mcpsimp"><a name="p1018mcpsimp"></a><a name="p1018mcpsimp"></a>6</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p1020mcpsimp"><a name="p1020mcpsimp"></a><a name="p1020mcpsimp"></a>usigned char</p>
</td>
</tr>
</tbody>
</table>

### 删除配对<a name="ZH-CN_TOPIC_0000001876269565"></a>

<a name="table1022mcpsimp"></a>
<table><thead align="left"><tr id="row1028mcpsimp"><th class="cellrowborder" valign="top" width="22.439999999999998%" id="mcps1.1.4.1.1"><p id="p1030mcpsimp"><a name="p1030mcpsimp"></a><a name="p1030mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="24.54%" id="mcps1.1.4.1.2"><p id="p1032mcpsimp"><a name="p1032mcpsimp"></a><a name="p1032mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="53.02%" id="mcps1.1.4.1.3"><p id="p1034mcpsimp"><a name="p1034mcpsimp"></a><a name="p1034mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1035mcpsimp"><td class="cellrowborder" valign="top" width="22.439999999999998%" headers="mcps1.1.4.1.1 "><p id="p1037mcpsimp"><a name="p1037mcpsimp"></a><a name="p1037mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="24.54%" headers="mcps1.1.4.1.2 "><p id="p1039mcpsimp"><a name="p1039mcpsimp"></a><a name="p1039mcpsimp"></a>0x05</p>
</td>
<td class="cellrowborder" valign="top" width="53.02%" headers="mcps1.1.4.1.3 "><p id="p1041mcpsimp"><a name="p1041mcpsimp"></a><a name="p1041mcpsimp"></a>删除配对</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

<a name="table1044mcpsimp"></a>
<table><thead align="left"><tr id="row1051mcpsimp"><th class="cellrowborder" valign="top" width="27%" id="mcps1.1.5.1.1"><p id="p1053mcpsimp"><a name="p1053mcpsimp"></a><a name="p1053mcpsimp"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="22%" id="mcps1.1.5.1.2"><p id="p1055mcpsimp"><a name="p1055mcpsimp"></a><a name="p1055mcpsimp"></a>Type(bit0~bit6)</p>
</th>
<th class="cellrowborder" valign="top" width="18%" id="mcps1.1.5.1.3"><p id="p1057mcpsimp"><a name="p1057mcpsimp"></a><a name="p1057mcpsimp"></a>Length Size(Oct)</p>
</th>
<th class="cellrowborder" valign="top" width="33%" id="mcps1.1.5.1.4"><p id="p1060mcpsimp"><a name="p1060mcpsimp"></a><a name="p1060mcpsimp"></a>Value数据类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row1062mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p1064mcpsimp"><a name="p1064mcpsimp"></a><a name="p1064mcpsimp"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p1066mcpsimp"><a name="p1066mcpsimp"></a><a name="p1066mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p1068mcpsimp"><a name="p1068mcpsimp"></a><a name="p1068mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p1070mcpsimp"><a name="p1070mcpsimp"></a><a name="p1070mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row1071mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p1073mcpsimp"><a name="p1073mcpsimp"></a><a name="p1073mcpsimp"></a>addr</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p1075mcpsimp"><a name="p1075mcpsimp"></a><a name="p1075mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p1077mcpsimp"><a name="p1077mcpsimp"></a><a name="p1077mcpsimp"></a>6</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p1079mcpsimp"><a name="p1079mcpsimp"></a><a name="p1079mcpsimp"></a>usigned char</p>
</td>
</tr>
</tbody>
</table>

### 删除所有配对<a name="ZH-CN_TOPIC_0000001829430364"></a>

<a name="table1081mcpsimp"></a>
<table><thead align="left"><tr id="row1087mcpsimp"><th class="cellrowborder" valign="top" width="22.75%" id="mcps1.1.4.1.1"><p id="p1089mcpsimp"><a name="p1089mcpsimp"></a><a name="p1089mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="24.37%" id="mcps1.1.4.1.2"><p id="p1091mcpsimp"><a name="p1091mcpsimp"></a><a name="p1091mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="52.88%" id="mcps1.1.4.1.3"><p id="p1093mcpsimp"><a name="p1093mcpsimp"></a><a name="p1093mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1094mcpsimp"><td class="cellrowborder" valign="top" width="22.75%" headers="mcps1.1.4.1.1 "><p id="p1096mcpsimp"><a name="p1096mcpsimp"></a><a name="p1096mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="24.37%" headers="mcps1.1.4.1.2 "><p id="p1098mcpsimp"><a name="p1098mcpsimp"></a><a name="p1098mcpsimp"></a>0x06</p>
</td>
<td class="cellrowborder" valign="top" width="52.88%" headers="mcps1.1.4.1.3 "><p id="p1100mcpsimp"><a name="p1100mcpsimp"></a><a name="p1100mcpsimp"></a>删除所有配对</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

无

### 获取配对设备数量<a name="ZH-CN_TOPIC_0000001829590124"></a>

<a name="table1105mcpsimp"></a>
<table><thead align="left"><tr id="row1111mcpsimp"><th class="cellrowborder" valign="top" width="22.75%" id="mcps1.1.4.1.1"><p id="p1113mcpsimp"><a name="p1113mcpsimp"></a><a name="p1113mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="24.16%" id="mcps1.1.4.1.2"><p id="p1115mcpsimp"><a name="p1115mcpsimp"></a><a name="p1115mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="53.09%" id="mcps1.1.4.1.3"><p id="p1117mcpsimp"><a name="p1117mcpsimp"></a><a name="p1117mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1118mcpsimp"><td class="cellrowborder" valign="top" width="22.75%" headers="mcps1.1.4.1.1 "><p id="p1120mcpsimp"><a name="p1120mcpsimp"></a><a name="p1120mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="24.16%" headers="mcps1.1.4.1.2 "><p id="p1122mcpsimp"><a name="p1122mcpsimp"></a><a name="p1122mcpsimp"></a>0x07</p>
</td>
<td class="cellrowborder" valign="top" width="53.09%" headers="mcps1.1.4.1.3 "><p id="p1124mcpsimp"><a name="p1124mcpsimp"></a><a name="p1124mcpsimp"></a>获取配对设备数量</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

<a name="table1127mcpsimp"></a>
<table><thead align="left"><tr id="row1134mcpsimp"><th class="cellrowborder" valign="top" width="27%" id="mcps1.1.5.1.1"><p id="p1136mcpsimp"><a name="p1136mcpsimp"></a><a name="p1136mcpsimp"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="22%" id="mcps1.1.5.1.2"><p id="p1138mcpsimp"><a name="p1138mcpsimp"></a><a name="p1138mcpsimp"></a>Type(bit0~bit6)</p>
</th>
<th class="cellrowborder" valign="top" width="18%" id="mcps1.1.5.1.3"><p id="p1140mcpsimp"><a name="p1140mcpsimp"></a><a name="p1140mcpsimp"></a>Length Size(Oct)</p>
</th>
<th class="cellrowborder" valign="top" width="33%" id="mcps1.1.5.1.4"><p id="p1143mcpsimp"><a name="p1143mcpsimp"></a><a name="p1143mcpsimp"></a>Value数据类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row1145mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p1147mcpsimp"><a name="p1147mcpsimp"></a><a name="p1147mcpsimp"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p1149mcpsimp"><a name="p1149mcpsimp"></a><a name="p1149mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p1151mcpsimp"><a name="p1151mcpsimp"></a><a name="p1151mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p1153mcpsimp"><a name="p1153mcpsimp"></a><a name="p1153mcpsimp"></a>uint16</p>
</td>
</tr>
</tbody>
</table>

### 获取配对设备<a name="ZH-CN_TOPIC_0000001876189789"></a>

<a name="table1155mcpsimp"></a>
<table><thead align="left"><tr id="row1161mcpsimp"><th class="cellrowborder" valign="top" width="23.189999999999998%" id="mcps1.1.4.1.1"><p id="p1163mcpsimp"><a name="p1163mcpsimp"></a><a name="p1163mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="23.73%" id="mcps1.1.4.1.2"><p id="p1165mcpsimp"><a name="p1165mcpsimp"></a><a name="p1165mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="53.080000000000005%" id="mcps1.1.4.1.3"><p id="p1167mcpsimp"><a name="p1167mcpsimp"></a><a name="p1167mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1168mcpsimp"><td class="cellrowborder" valign="top" width="23.189999999999998%" headers="mcps1.1.4.1.1 "><p id="p1170mcpsimp"><a name="p1170mcpsimp"></a><a name="p1170mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="23.73%" headers="mcps1.1.4.1.2 "><p id="p1172mcpsimp"><a name="p1172mcpsimp"></a><a name="p1172mcpsimp"></a>0x08</p>
</td>
<td class="cellrowborder" valign="top" width="53.080000000000005%" headers="mcps1.1.4.1.3 "><p id="p1174mcpsimp"><a name="p1174mcpsimp"></a><a name="p1174mcpsimp"></a>获取配对设备</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

<a name="table1177mcpsimp"></a>
<table><thead align="left"><tr id="row1184mcpsimp"><th class="cellrowborder" valign="top" width="27%" id="mcps1.1.5.1.1"><p id="p1186mcpsimp"><a name="p1186mcpsimp"></a><a name="p1186mcpsimp"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="22%" id="mcps1.1.5.1.2"><p id="p1188mcpsimp"><a name="p1188mcpsimp"></a><a name="p1188mcpsimp"></a>Type(bit0~bit6)</p>
</th>
<th class="cellrowborder" valign="top" width="18%" id="mcps1.1.5.1.3"><p id="p1190mcpsimp"><a name="p1190mcpsimp"></a><a name="p1190mcpsimp"></a>Length Size(Oct)</p>
</th>
<th class="cellrowborder" valign="top" width="33%" id="mcps1.1.5.1.4"><p id="p1193mcpsimp"><a name="p1193mcpsimp"></a><a name="p1193mcpsimp"></a>Value数据类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row1195mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p1197mcpsimp"><a name="p1197mcpsimp"></a><a name="p1197mcpsimp"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p1199mcpsimp"><a name="p1199mcpsimp"></a><a name="p1199mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p1201mcpsimp"><a name="p1201mcpsimp"></a><a name="p1201mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p1203mcpsimp"><a name="p1203mcpsimp"></a><a name="p1203mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row1204mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p1206mcpsimp"><a name="p1206mcpsimp"></a><a name="p1206mcpsimp"></a>addr</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p1208mcpsimp"><a name="p1208mcpsimp"></a><a name="p1208mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p1210mcpsimp"><a name="p1210mcpsimp"></a><a name="p1210mcpsimp"></a>6</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p1212mcpsimp"><a name="p1212mcpsimp"></a><a name="p1212mcpsimp"></a>usigned char</p>
</td>
</tr>
<tr id="row1213mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p1215mcpsimp"><a name="p1215mcpsimp"></a><a name="p1215mcpsimp"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p1217mcpsimp"><a name="p1217mcpsimp"></a><a name="p1217mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p1219mcpsimp"><a name="p1219mcpsimp"></a><a name="p1219mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p1221mcpsimp"><a name="p1221mcpsimp"></a><a name="p1221mcpsimp"></a>uint16</p>
</td>
</tr>
</tbody>
</table>

### 获取配对状态<a name="ZH-CN_TOPIC_0000001876269569"></a>

<a name="table1223mcpsimp"></a>
<table><thead align="left"><tr id="row1229mcpsimp"><th class="cellrowborder" valign="top" width="23.13%" id="mcps1.1.4.1.1"><p id="p1231mcpsimp"><a name="p1231mcpsimp"></a><a name="p1231mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="23.65%" id="mcps1.1.4.1.2"><p id="p1233mcpsimp"><a name="p1233mcpsimp"></a><a name="p1233mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="53.22%" id="mcps1.1.4.1.3"><p id="p1235mcpsimp"><a name="p1235mcpsimp"></a><a name="p1235mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1236mcpsimp"><td class="cellrowborder" valign="top" width="23.13%" headers="mcps1.1.4.1.1 "><p id="p1238mcpsimp"><a name="p1238mcpsimp"></a><a name="p1238mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="23.65%" headers="mcps1.1.4.1.2 "><p id="p1240mcpsimp"><a name="p1240mcpsimp"></a><a name="p1240mcpsimp"></a>0x09</p>
</td>
<td class="cellrowborder" valign="top" width="53.22%" headers="mcps1.1.4.1.3 "><p id="p1242mcpsimp"><a name="p1242mcpsimp"></a><a name="p1242mcpsimp"></a>获取配对状态</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

<a name="table1245mcpsimp"></a>
<table><thead align="left"><tr id="row1252mcpsimp"><th class="cellrowborder" valign="top" width="27%" id="mcps1.1.5.1.1"><p id="p1254mcpsimp"><a name="p1254mcpsimp"></a><a name="p1254mcpsimp"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="22%" id="mcps1.1.5.1.2"><p id="p1256mcpsimp"><a name="p1256mcpsimp"></a><a name="p1256mcpsimp"></a>Type(bit0~bit6)</p>
</th>
<th class="cellrowborder" valign="top" width="18%" id="mcps1.1.5.1.3"><p id="p1258mcpsimp"><a name="p1258mcpsimp"></a><a name="p1258mcpsimp"></a>Length Size(Oct)</p>
</th>
<th class="cellrowborder" valign="top" width="33%" id="mcps1.1.5.1.4"><p id="p1261mcpsimp"><a name="p1261mcpsimp"></a><a name="p1261mcpsimp"></a>Value数据类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row1263mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p1265mcpsimp"><a name="p1265mcpsimp"></a><a name="p1265mcpsimp"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p1267mcpsimp"><a name="p1267mcpsimp"></a><a name="p1267mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p1269mcpsimp"><a name="p1269mcpsimp"></a><a name="p1269mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p1271mcpsimp"><a name="p1271mcpsimp"></a><a name="p1271mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row1272mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p1274mcpsimp"><a name="p1274mcpsimp"></a><a name="p1274mcpsimp"></a>addr</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p1276mcpsimp"><a name="p1276mcpsimp"></a><a name="p1276mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p1278mcpsimp"><a name="p1278mcpsimp"></a><a name="p1278mcpsimp"></a>6</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p1280mcpsimp"><a name="p1280mcpsimp"></a><a name="p1280mcpsimp"></a>usigned char</p>
</td>
</tr>
<tr id="row1281mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p1283mcpsimp"><a name="p1283mcpsimp"></a><a name="p1283mcpsimp"></a>state</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p1285mcpsimp"><a name="p1285mcpsimp"></a><a name="p1285mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p1287mcpsimp"><a name="p1287mcpsimp"></a><a name="p1287mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p1289mcpsimp"><a name="p1289mcpsimp"></a><a name="p1289mcpsimp"></a>uint8</p>
</td>
</tr>
</tbody>
</table>

### 读取对端设备RSSI值<a name="ZH-CN_TOPIC_0000001829430368"></a>

<a name="table1291mcpsimp"></a>
<table><thead align="left"><tr id="row1297mcpsimp"><th class="cellrowborder" valign="top" width="23.189999999999998%" id="mcps1.1.4.1.1"><p id="p1299mcpsimp"><a name="p1299mcpsimp"></a><a name="p1299mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="23.79%" id="mcps1.1.4.1.2"><p id="p1301mcpsimp"><a name="p1301mcpsimp"></a><a name="p1301mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="53.02%" id="mcps1.1.4.1.3"><p id="p1303mcpsimp"><a name="p1303mcpsimp"></a><a name="p1303mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1304mcpsimp"><td class="cellrowborder" valign="top" width="23.189999999999998%" headers="mcps1.1.4.1.1 "><p id="p1306mcpsimp"><a name="p1306mcpsimp"></a><a name="p1306mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="23.79%" headers="mcps1.1.4.1.2 "><p id="p1308mcpsimp"><a name="p1308mcpsimp"></a><a name="p1308mcpsimp"></a>0x0A</p>
</td>
<td class="cellrowborder" valign="top" width="53.02%" headers="mcps1.1.4.1.3 "><p id="p1310mcpsimp"><a name="p1310mcpsimp"></a><a name="p1310mcpsimp"></a>读取对端设备RSSI值</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

<a name="table1313mcpsimp"></a>
<table><thead align="left"><tr id="row1320mcpsimp"><th class="cellrowborder" valign="top" width="27%" id="mcps1.1.5.1.1"><p id="p1322mcpsimp"><a name="p1322mcpsimp"></a><a name="p1322mcpsimp"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="22%" id="mcps1.1.5.1.2"><p id="p1324mcpsimp"><a name="p1324mcpsimp"></a><a name="p1324mcpsimp"></a>Type(bit0~bit6)</p>
</th>
<th class="cellrowborder" valign="top" width="18%" id="mcps1.1.5.1.3"><p id="p1326mcpsimp"><a name="p1326mcpsimp"></a><a name="p1326mcpsimp"></a>Length Size(Oct)</p>
</th>
<th class="cellrowborder" valign="top" width="33%" id="mcps1.1.5.1.4"><p id="p1329mcpsimp"><a name="p1329mcpsimp"></a><a name="p1329mcpsimp"></a>Value数据类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row1331mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p1333mcpsimp"><a name="p1333mcpsimp"></a><a name="p1333mcpsimp"></a>conn_id</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p1335mcpsimp"><a name="p1335mcpsimp"></a><a name="p1335mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p1337mcpsimp"><a name="p1337mcpsimp"></a><a name="p1337mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p1339mcpsimp"><a name="p1339mcpsimp"></a><a name="p1339mcpsimp"></a>uint16</p>
</td>
</tr>
</tbody>
</table>

### 设置ACB链路参数<a name="ZH-CN_TOPIC_0000001829590128"></a>

<a name="table1341mcpsimp"></a>
<table><thead align="left"><tr id="row1347mcpsimp"><th class="cellrowborder" valign="top" width="22.939999999999998%" id="mcps1.1.4.1.1"><p id="p1349mcpsimp"><a name="p1349mcpsimp"></a><a name="p1349mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="23.91%" id="mcps1.1.4.1.2"><p id="p1351mcpsimp"><a name="p1351mcpsimp"></a><a name="p1351mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="53.15%" id="mcps1.1.4.1.3"><p id="p1353mcpsimp"><a name="p1353mcpsimp"></a><a name="p1353mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1354mcpsimp"><td class="cellrowborder" valign="top" width="22.939999999999998%" headers="mcps1.1.4.1.1 "><p id="p1356mcpsimp"><a name="p1356mcpsimp"></a><a name="p1356mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="23.91%" headers="mcps1.1.4.1.2 "><p id="p1358mcpsimp"><a name="p1358mcpsimp"></a><a name="p1358mcpsimp"></a>0x0B</p>
</td>
<td class="cellrowborder" valign="top" width="53.15%" headers="mcps1.1.4.1.3 "><p id="p1360mcpsimp"><a name="p1360mcpsimp"></a><a name="p1360mcpsimp"></a>设置ACB链路参数</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

<a name="table1363mcpsimp"></a>
<table><thead align="left"><tr id="row1370mcpsimp"><th class="cellrowborder" valign="top" width="27%" id="mcps1.1.5.1.1"><p id="p1372mcpsimp"><a name="p1372mcpsimp"></a><a name="p1372mcpsimp"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="22%" id="mcps1.1.5.1.2"><p id="p1374mcpsimp"><a name="p1374mcpsimp"></a><a name="p1374mcpsimp"></a>Type(bit0~bit6)</p>
</th>
<th class="cellrowborder" valign="top" width="18%" id="mcps1.1.5.1.3"><p id="p1376mcpsimp"><a name="p1376mcpsimp"></a><a name="p1376mcpsimp"></a>Length Size(Oct)</p>
</th>
<th class="cellrowborder" valign="top" width="33%" id="mcps1.1.5.1.4"><p id="p1379mcpsimp"><a name="p1379mcpsimp"></a><a name="p1379mcpsimp"></a>Value数据类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row1381mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p1383mcpsimp"><a name="p1383mcpsimp"></a><a name="p1383mcpsimp"></a>conn_id</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p1385mcpsimp"><a name="p1385mcpsimp"></a><a name="p1385mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p1387mcpsimp"><a name="p1387mcpsimp"></a><a name="p1387mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p1389mcpsimp"><a name="p1389mcpsimp"></a><a name="p1389mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row1390mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p1392mcpsimp"><a name="p1392mcpsimp"></a><a name="p1392mcpsimp"></a>evt_int</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p1394mcpsimp"><a name="p1394mcpsimp"></a><a name="p1394mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p1396mcpsimp"><a name="p1396mcpsimp"></a><a name="p1396mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p1398mcpsimp"><a name="p1398mcpsimp"></a><a name="p1398mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row1399mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p1401mcpsimp"><a name="p1401mcpsimp"></a><a name="p1401mcpsimp"></a>evt_num</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p1403mcpsimp"><a name="p1403mcpsimp"></a><a name="p1403mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p1405mcpsimp"><a name="p1405mcpsimp"></a><a name="p1405mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p1407mcpsimp"><a name="p1407mcpsimp"></a><a name="p1407mcpsimp"></a>uint8</p>
</td>
</tr>
</tbody>
</table>

### 设置PHY参数<a name="ZH-CN_TOPIC_0000001876189793"></a>

<a name="table1409mcpsimp"></a>
<table><thead align="left"><tr id="row1415mcpsimp"><th class="cellrowborder" valign="top" width="22.939999999999998%" id="mcps1.1.4.1.1"><p id="p1417mcpsimp"><a name="p1417mcpsimp"></a><a name="p1417mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="23.79%" id="mcps1.1.4.1.2"><p id="p1419mcpsimp"><a name="p1419mcpsimp"></a><a name="p1419mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="53.269999999999996%" id="mcps1.1.4.1.3"><p id="p1421mcpsimp"><a name="p1421mcpsimp"></a><a name="p1421mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1422mcpsimp"><td class="cellrowborder" valign="top" width="22.939999999999998%" headers="mcps1.1.4.1.1 "><p id="p1424mcpsimp"><a name="p1424mcpsimp"></a><a name="p1424mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="23.79%" headers="mcps1.1.4.1.2 "><p id="p1426mcpsimp"><a name="p1426mcpsimp"></a><a name="p1426mcpsimp"></a>0x0C</p>
</td>
<td class="cellrowborder" valign="top" width="53.269999999999996%" headers="mcps1.1.4.1.3 "><p id="p1428mcpsimp"><a name="p1428mcpsimp"></a><a name="p1428mcpsimp"></a>设置PHY参数</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

<a name="table1431mcpsimp"></a>
<table><thead align="left"><tr id="row1438mcpsimp"><th class="cellrowborder" valign="top" width="27%" id="mcps1.1.5.1.1"><p id="p1440mcpsimp"><a name="p1440mcpsimp"></a><a name="p1440mcpsimp"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="22%" id="mcps1.1.5.1.2"><p id="p1442mcpsimp"><a name="p1442mcpsimp"></a><a name="p1442mcpsimp"></a>Type(bit0~bit6)</p>
</th>
<th class="cellrowborder" valign="top" width="18%" id="mcps1.1.5.1.3"><p id="p1444mcpsimp"><a name="p1444mcpsimp"></a><a name="p1444mcpsimp"></a>Length Size(Oct)</p>
</th>
<th class="cellrowborder" valign="top" width="33%" id="mcps1.1.5.1.4"><p id="p1447mcpsimp"><a name="p1447mcpsimp"></a><a name="p1447mcpsimp"></a>Value数据类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row1449mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p1451mcpsimp"><a name="p1451mcpsimp"></a><a name="p1451mcpsimp"></a>conn_hdl</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p1453mcpsimp"><a name="p1453mcpsimp"></a><a name="p1453mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p1455mcpsimp"><a name="p1455mcpsimp"></a><a name="p1455mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p1457mcpsimp"><a name="p1457mcpsimp"></a><a name="p1457mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row1458mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p1460mcpsimp"><a name="p1460mcpsimp"></a><a name="p1460mcpsimp"></a>tx_format</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p1462mcpsimp"><a name="p1462mcpsimp"></a><a name="p1462mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p1464mcpsimp"><a name="p1464mcpsimp"></a><a name="p1464mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p1466mcpsimp"><a name="p1466mcpsimp"></a><a name="p1466mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row1467mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p1469mcpsimp"><a name="p1469mcpsimp"></a><a name="p1469mcpsimp"></a>rx_format</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p1471mcpsimp"><a name="p1471mcpsimp"></a><a name="p1471mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p1473mcpsimp"><a name="p1473mcpsimp"></a><a name="p1473mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p1475mcpsimp"><a name="p1475mcpsimp"></a><a name="p1475mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row1476mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p1478mcpsimp"><a name="p1478mcpsimp"></a><a name="p1478mcpsimp"></a>tx_phy</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p1480mcpsimp"><a name="p1480mcpsimp"></a><a name="p1480mcpsimp"></a>0x04</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p1482mcpsimp"><a name="p1482mcpsimp"></a><a name="p1482mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p1484mcpsimp"><a name="p1484mcpsimp"></a><a name="p1484mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row1485mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p1487mcpsimp"><a name="p1487mcpsimp"></a><a name="p1487mcpsimp"></a>rx_phy</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p1489mcpsimp"><a name="p1489mcpsimp"></a><a name="p1489mcpsimp"></a>0x05</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p1491mcpsimp"><a name="p1491mcpsimp"></a><a name="p1491mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p1493mcpsimp"><a name="p1493mcpsimp"></a><a name="p1493mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row1494mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p1496mcpsimp"><a name="p1496mcpsimp"></a><a name="p1496mcpsimp"></a>tx_pilot_density</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p1498mcpsimp"><a name="p1498mcpsimp"></a><a name="p1498mcpsimp"></a>0x06</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p1500mcpsimp"><a name="p1500mcpsimp"></a><a name="p1500mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p1502mcpsimp"><a name="p1502mcpsimp"></a><a name="p1502mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row1503mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p1505mcpsimp"><a name="p1505mcpsimp"></a><a name="p1505mcpsimp"></a>rx_pilot_density</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p1507mcpsimp"><a name="p1507mcpsimp"></a><a name="p1507mcpsimp"></a>0x07</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p1509mcpsimp"><a name="p1509mcpsimp"></a><a name="p1509mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p1511mcpsimp"><a name="p1511mcpsimp"></a><a name="p1511mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row1512mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p1514mcpsimp"><a name="p1514mcpsimp"></a><a name="p1514mcpsimp"></a>g_feedback</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p1516mcpsimp"><a name="p1516mcpsimp"></a><a name="p1516mcpsimp"></a>0x08</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p1518mcpsimp"><a name="p1518mcpsimp"></a><a name="p1518mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p1520mcpsimp"><a name="p1520mcpsimp"></a><a name="p1520mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row1521mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p1523mcpsimp"><a name="p1523mcpsimp"></a><a name="p1523mcpsimp"></a>t_feedback</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p1525mcpsimp"><a name="p1525mcpsimp"></a><a name="p1525mcpsimp"></a>0x09</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p1527mcpsimp"><a name="p1527mcpsimp"></a><a name="p1527mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p1529mcpsimp"><a name="p1529mcpsimp"></a><a name="p1529mcpsimp"></a>uint8</p>
</td>
</tr>
</tbody>
</table>

### 设置最大功率<a name="ZH-CN_TOPIC_0000001876269573"></a>

<a name="table1531mcpsimp"></a>
<table><thead align="left"><tr id="row1537mcpsimp"><th class="cellrowborder" valign="top" width="23.04%" id="mcps1.1.4.1.1"><p id="p1539mcpsimp"><a name="p1539mcpsimp"></a><a name="p1539mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="23.799999999999997%" id="mcps1.1.4.1.2"><p id="p1541mcpsimp"><a name="p1541mcpsimp"></a><a name="p1541mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="53.16%" id="mcps1.1.4.1.3"><p id="p1543mcpsimp"><a name="p1543mcpsimp"></a><a name="p1543mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1544mcpsimp"><td class="cellrowborder" valign="top" width="23.04%" headers="mcps1.1.4.1.1 "><p id="p1546mcpsimp"><a name="p1546mcpsimp"></a><a name="p1546mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="23.799999999999997%" headers="mcps1.1.4.1.2 "><p id="p1548mcpsimp"><a name="p1548mcpsimp"></a><a name="p1548mcpsimp"></a>0x0D</p>
</td>
<td class="cellrowborder" valign="top" width="53.16%" headers="mcps1.1.4.1.3 "><p id="p1550mcpsimp"><a name="p1550mcpsimp"></a><a name="p1550mcpsimp"></a>设置最大功率</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

<a name="table1553mcpsimp"></a>
<table><thead align="left"><tr id="row1560mcpsimp"><th class="cellrowborder" valign="top" width="27%" id="mcps1.1.5.1.1"><p id="p1562mcpsimp"><a name="p1562mcpsimp"></a><a name="p1562mcpsimp"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="22%" id="mcps1.1.5.1.2"><p id="p1564mcpsimp"><a name="p1564mcpsimp"></a><a name="p1564mcpsimp"></a>Type(bit0~bit6)</p>
</th>
<th class="cellrowborder" valign="top" width="18%" id="mcps1.1.5.1.3"><p id="p1566mcpsimp"><a name="p1566mcpsimp"></a><a name="p1566mcpsimp"></a>Length Size(Oct)</p>
</th>
<th class="cellrowborder" valign="top" width="33%" id="mcps1.1.5.1.4"><p id="p1569mcpsimp"><a name="p1569mcpsimp"></a><a name="p1569mcpsimp"></a>Value数据类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row1571mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p1573mcpsimp"><a name="p1573mcpsimp"></a><a name="p1573mcpsimp"></a>ble_pwr</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p1575mcpsimp"><a name="p1575mcpsimp"></a><a name="p1575mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p1577mcpsimp"><a name="p1577mcpsimp"></a><a name="p1577mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p1579mcpsimp"><a name="p1579mcpsimp"></a><a name="p1579mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row1580mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p1582mcpsimp"><a name="p1582mcpsimp"></a><a name="p1582mcpsimp"></a>sle_pwr</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p1584mcpsimp"><a name="p1584mcpsimp"></a><a name="p1584mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p1586mcpsimp"><a name="p1586mcpsimp"></a><a name="p1586mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p1588mcpsimp"><a name="p1588mcpsimp"></a><a name="p1588mcpsimp"></a>uint8</p>
</td>
</tr>
</tbody>
</table>

### 发送链接管理能力查询请求<a name="ZH-CN_TOPIC_0000001829430372"></a>

<a name="table1590mcpsimp"></a>
<table><thead align="left"><tr id="row1596mcpsimp"><th class="cellrowborder" valign="top" width="23.06%" id="mcps1.1.4.1.1"><p id="p1598mcpsimp"><a name="p1598mcpsimp"></a><a name="p1598mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="23.799999999999997%" id="mcps1.1.4.1.2"><p id="p1600mcpsimp"><a name="p1600mcpsimp"></a><a name="p1600mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="53.14%" id="mcps1.1.4.1.3"><p id="p1602mcpsimp"><a name="p1602mcpsimp"></a><a name="p1602mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1603mcpsimp"><td class="cellrowborder" valign="top" width="23.06%" headers="mcps1.1.4.1.1 "><p id="p1605mcpsimp"><a name="p1605mcpsimp"></a><a name="p1605mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="23.799999999999997%" headers="mcps1.1.4.1.2 "><p id="p1607mcpsimp"><a name="p1607mcpsimp"></a><a name="p1607mcpsimp"></a>0x0E</p>
</td>
<td class="cellrowborder" valign="top" width="53.14%" headers="mcps1.1.4.1.3 "><p id="p1609mcpsimp"><a name="p1609mcpsimp"></a><a name="p1609mcpsimp"></a>发送链接管理能力查询请求</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

<a name="table1612mcpsimp"></a>
<table><thead align="left"><tr id="row1619mcpsimp"><th class="cellrowborder" valign="top" width="32.67326732673268%" id="mcps1.1.5.1.1"><p id="p1621mcpsimp"><a name="p1621mcpsimp"></a><a name="p1621mcpsimp"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="21.782178217821784%" id="mcps1.1.5.1.2"><p id="p1623mcpsimp"><a name="p1623mcpsimp"></a><a name="p1623mcpsimp"></a>Type(bit0~bit6)</p>
</th>
<th class="cellrowborder" valign="top" width="15.841584158415841%" id="mcps1.1.5.1.3"><p id="p1625mcpsimp"><a name="p1625mcpsimp"></a><a name="p1625mcpsimp"></a>Length Size(Oct)</p>
</th>
<th class="cellrowborder" valign="top" width="29.7029702970297%" id="mcps1.1.5.1.4"><p id="p1628mcpsimp"><a name="p1628mcpsimp"></a><a name="p1628mcpsimp"></a>Value数据类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row1630mcpsimp"><td class="cellrowborder" valign="top" width="32.67326732673268%" headers="mcps1.1.5.1.1 "><p id="p1632mcpsimp"><a name="p1632mcpsimp"></a><a name="p1632mcpsimp"></a>conn_id</p>
</td>
<td class="cellrowborder" valign="top" width="21.782178217821784%" headers="mcps1.1.5.1.2 "><p id="p1634mcpsimp"><a name="p1634mcpsimp"></a><a name="p1634mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.5.1.3 "><p id="p1636mcpsimp"><a name="p1636mcpsimp"></a><a name="p1636mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="29.7029702970297%" headers="mcps1.1.5.1.4 "><p id="p1638mcpsimp"><a name="p1638mcpsimp"></a><a name="p1638mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row1639mcpsimp"><td class="cellrowborder" valign="top" width="32.67326732673268%" headers="mcps1.1.5.1.1 "><p id="p1641mcpsimp"><a name="p1641mcpsimp"></a><a name="p1641mcpsimp"></a>relay_capability</p>
</td>
<td class="cellrowborder" valign="top" width="21.782178217821784%" headers="mcps1.1.5.1.2 "><p id="p1643mcpsimp"><a name="p1643mcpsimp"></a><a name="p1643mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.5.1.3 "><p id="p1645mcpsimp"><a name="p1645mcpsimp"></a><a name="p1645mcpsimp"></a>1bit</p>
</td>
<td class="cellrowborder" valign="top" width="29.7029702970297%" headers="mcps1.1.5.1.4 "><p id="p1647mcpsimp"><a name="p1647mcpsimp"></a><a name="p1647mcpsimp"></a>uint32</p>
</td>
</tr>
<tr id="row1648mcpsimp"><td class="cellrowborder" valign="top" width="32.67326732673268%" headers="mcps1.1.5.1.1 "><p id="p1650mcpsimp"><a name="p1650mcpsimp"></a><a name="p1650mcpsimp"></a>trans_mode</p>
</td>
<td class="cellrowborder" valign="top" width="21.782178217821784%" headers="mcps1.1.5.1.2 "><p id="p1652mcpsimp"><a name="p1652mcpsimp"></a><a name="p1652mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.5.1.3 "><p id="p1654mcpsimp"><a name="p1654mcpsimp"></a><a name="p1654mcpsimp"></a>1bit</p>
</td>
<td class="cellrowborder" valign="top" width="29.7029702970297%" headers="mcps1.1.5.1.4 "><p id="p1656mcpsimp"><a name="p1656mcpsimp"></a><a name="p1656mcpsimp"></a>uint32</p>
</td>
</tr>
<tr id="row1657mcpsimp"><td class="cellrowborder" valign="top" width="32.67326732673268%" headers="mcps1.1.5.1.1 "><p id="p1659mcpsimp"><a name="p1659mcpsimp"></a><a name="p1659mcpsimp"></a>measurement_capability</p>
</td>
<td class="cellrowborder" valign="top" width="21.782178217821784%" headers="mcps1.1.5.1.2 "><p id="p1661mcpsimp"><a name="p1661mcpsimp"></a><a name="p1661mcpsimp"></a>0x04</p>
</td>
<td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.5.1.3 "><p id="p1663mcpsimp"><a name="p1663mcpsimp"></a><a name="p1663mcpsimp"></a>1bit</p>
</td>
<td class="cellrowborder" valign="top" width="29.7029702970297%" headers="mcps1.1.5.1.4 "><p id="p1665mcpsimp"><a name="p1665mcpsimp"></a><a name="p1665mcpsimp"></a>uint32</p>
</td>
</tr>
<tr id="row1666mcpsimp"><td class="cellrowborder" valign="top" width="32.67326732673268%" headers="mcps1.1.5.1.1 "><p id="p1668mcpsimp"><a name="p1668mcpsimp"></a><a name="p1668mcpsimp"></a>access_slb</p>
</td>
<td class="cellrowborder" valign="top" width="21.782178217821784%" headers="mcps1.1.5.1.2 "><p id="p1670mcpsimp"><a name="p1670mcpsimp"></a><a name="p1670mcpsimp"></a>0x05</p>
</td>
<td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.5.1.3 "><p id="p1672mcpsimp"><a name="p1672mcpsimp"></a><a name="p1672mcpsimp"></a>1bit</p>
</td>
<td class="cellrowborder" valign="top" width="29.7029702970297%" headers="mcps1.1.5.1.4 "><p id="p1674mcpsimp"><a name="p1674mcpsimp"></a><a name="p1674mcpsimp"></a>uint32</p>
</td>
</tr>
<tr id="row1675mcpsimp"><td class="cellrowborder" valign="top" width="32.67326732673268%" headers="mcps1.1.5.1.1 "><p id="p1677mcpsimp"><a name="p1677mcpsimp"></a><a name="p1677mcpsimp"></a>access_sle</p>
</td>
<td class="cellrowborder" valign="top" width="21.782178217821784%" headers="mcps1.1.5.1.2 "><p id="p1679mcpsimp"><a name="p1679mcpsimp"></a><a name="p1679mcpsimp"></a>0x06</p>
</td>
<td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.5.1.3 "><p id="p1681mcpsimp"><a name="p1681mcpsimp"></a><a name="p1681mcpsimp"></a>1bit</p>
</td>
<td class="cellrowborder" valign="top" width="29.7029702970297%" headers="mcps1.1.5.1.4 "><p id="p1683mcpsimp"><a name="p1683mcpsimp"></a><a name="p1683mcpsimp"></a>uint32</p>
</td>
</tr>
<tr id="row1684mcpsimp"><td class="cellrowborder" valign="top" width="32.67326732673268%" headers="mcps1.1.5.1.1 "><p id="p1686mcpsimp"><a name="p1686mcpsimp"></a><a name="p1686mcpsimp"></a>mtu</p>
</td>
<td class="cellrowborder" valign="top" width="21.782178217821784%" headers="mcps1.1.5.1.2 "><p id="p1688mcpsimp"><a name="p1688mcpsimp"></a><a name="p1688mcpsimp"></a>0x07</p>
</td>
<td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.5.1.3 "><p id="p1690mcpsimp"><a name="p1690mcpsimp"></a><a name="p1690mcpsimp"></a>1bit</p>
</td>
<td class="cellrowborder" valign="top" width="29.7029702970297%" headers="mcps1.1.5.1.4 "><p id="p1692mcpsimp"><a name="p1692mcpsimp"></a><a name="p1692mcpsimp"></a>uint32</p>
</td>
</tr>
<tr id="row1693mcpsimp"><td class="cellrowborder" valign="top" width="32.67326732673268%" headers="mcps1.1.5.1.1 "><p id="p1695mcpsimp"><a name="p1695mcpsimp"></a><a name="p1695mcpsimp"></a>mps</p>
</td>
<td class="cellrowborder" valign="top" width="21.782178217821784%" headers="mcps1.1.5.1.2 "><p id="p1697mcpsimp"><a name="p1697mcpsimp"></a><a name="p1697mcpsimp"></a>0x08</p>
</td>
<td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.5.1.3 "><p id="p1699mcpsimp"><a name="p1699mcpsimp"></a><a name="p1699mcpsimp"></a>1bit</p>
</td>
<td class="cellrowborder" valign="top" width="29.7029702970297%" headers="mcps1.1.5.1.4 "><p id="p1701mcpsimp"><a name="p1701mcpsimp"></a><a name="p1701mcpsimp"></a>uint32</p>
</td>
</tr>
<tr id="row1702mcpsimp"><td class="cellrowborder" valign="top" width="32.67326732673268%" headers="mcps1.1.5.1.1 "><p id="p1704mcpsimp"><a name="p1704mcpsimp"></a><a name="p1704mcpsimp"></a>reserve</p>
</td>
<td class="cellrowborder" valign="top" width="21.782178217821784%" headers="mcps1.1.5.1.2 "><p id="p1706mcpsimp"><a name="p1706mcpsimp"></a><a name="p1706mcpsimp"></a>0x09</p>
</td>
<td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.5.1.3 "><p id="p1708mcpsimp"><a name="p1708mcpsimp"></a><a name="p1708mcpsimp"></a>25bit</p>
</td>
<td class="cellrowborder" valign="top" width="29.7029702970297%" headers="mcps1.1.5.1.4 "><p id="p1710mcpsimp"><a name="p1710mcpsimp"></a><a name="p1710mcpsimp"></a>uint32</p>
</td>
</tr>
</tbody>
</table>

### 断开所有链接<a name="ZH-CN_TOPIC_0000001829590132"></a>

<a name="table1712mcpsimp"></a>
<table><thead align="left"><tr id="row1718mcpsimp"><th class="cellrowborder" valign="top" width="22.939999999999998%" id="mcps1.1.4.1.1"><p id="p1720mcpsimp"><a name="p1720mcpsimp"></a><a name="p1720mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="24.15%" id="mcps1.1.4.1.2"><p id="p1722mcpsimp"><a name="p1722mcpsimp"></a><a name="p1722mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="52.910000000000004%" id="mcps1.1.4.1.3"><p id="p1724mcpsimp"><a name="p1724mcpsimp"></a><a name="p1724mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1725mcpsimp"><td class="cellrowborder" valign="top" width="22.939999999999998%" headers="mcps1.1.4.1.1 "><p id="p1727mcpsimp"><a name="p1727mcpsimp"></a><a name="p1727mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="24.15%" headers="mcps1.1.4.1.2 "><p id="p1729mcpsimp"><a name="p1729mcpsimp"></a><a name="p1729mcpsimp"></a>0x0F</p>
</td>
<td class="cellrowborder" valign="top" width="52.910000000000004%" headers="mcps1.1.4.1.3 "><p id="p1731mcpsimp"><a name="p1731mcpsimp"></a><a name="p1731mcpsimp"></a>断开所有链接</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

空

### 获取绑定设备<a name="ZH-CN_TOPIC_0000001876189797"></a>

<a name="table1736mcpsimp"></a>
<table><thead align="left"><tr id="row1742mcpsimp"><th class="cellrowborder" valign="top" width="23%" id="mcps1.1.4.1.1"><p id="p1744mcpsimp"><a name="p1744mcpsimp"></a><a name="p1744mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="24.22%" id="mcps1.1.4.1.2"><p id="p1746mcpsimp"><a name="p1746mcpsimp"></a><a name="p1746mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="52.78%" id="mcps1.1.4.1.3"><p id="p1748mcpsimp"><a name="p1748mcpsimp"></a><a name="p1748mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1749mcpsimp"><td class="cellrowborder" valign="top" width="23%" headers="mcps1.1.4.1.1 "><p id="p1751mcpsimp"><a name="p1751mcpsimp"></a><a name="p1751mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="24.22%" headers="mcps1.1.4.1.2 "><p id="p1753mcpsimp"><a name="p1753mcpsimp"></a><a name="p1753mcpsimp"></a>0x010</p>
</td>
<td class="cellrowborder" valign="top" width="52.78%" headers="mcps1.1.4.1.3 "><p id="p1755mcpsimp"><a name="p1755mcpsimp"></a><a name="p1755mcpsimp"></a>获取绑定设备</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

<a name="table1758mcpsimp"></a>
<table><thead align="left"><tr id="row1765mcpsimp"><th class="cellrowborder" valign="top" width="27%" id="mcps1.1.5.1.1"><p id="p1767mcpsimp"><a name="p1767mcpsimp"></a><a name="p1767mcpsimp"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="22%" id="mcps1.1.5.1.2"><p id="p1769mcpsimp"><a name="p1769mcpsimp"></a><a name="p1769mcpsimp"></a>Type(bit0~bit6)</p>
</th>
<th class="cellrowborder" valign="top" width="18%" id="mcps1.1.5.1.3"><p id="p1771mcpsimp"><a name="p1771mcpsimp"></a><a name="p1771mcpsimp"></a>Length Size(Oct)</p>
</th>
<th class="cellrowborder" valign="top" width="33%" id="mcps1.1.5.1.4"><p id="p1774mcpsimp"><a name="p1774mcpsimp"></a><a name="p1774mcpsimp"></a>Value数据类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row1776mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p1778mcpsimp"><a name="p1778mcpsimp"></a><a name="p1778mcpsimp"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p1780mcpsimp"><a name="p1780mcpsimp"></a><a name="p1780mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p1782mcpsimp"><a name="p1782mcpsimp"></a><a name="p1782mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p1784mcpsimp"><a name="p1784mcpsimp"></a><a name="p1784mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row1785mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p1787mcpsimp"><a name="p1787mcpsimp"></a><a name="p1787mcpsimp"></a>addr</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p1789mcpsimp"><a name="p1789mcpsimp"></a><a name="p1789mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p1791mcpsimp"><a name="p1791mcpsimp"></a><a name="p1791mcpsimp"></a>6</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p1793mcpsimp"><a name="p1793mcpsimp"></a><a name="p1793mcpsimp"></a>usigned char</p>
</td>
</tr>
<tr id="row1794mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p1796mcpsimp"><a name="p1796mcpsimp"></a><a name="p1796mcpsimp"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p1798mcpsimp"><a name="p1798mcpsimp"></a><a name="p1798mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p1800mcpsimp"><a name="p1800mcpsimp"></a><a name="p1800mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p1802mcpsimp"><a name="p1802mcpsimp"></a><a name="p1802mcpsimp"></a>uint16</p>
</td>
</tr>
</tbody>
</table>

### 设置调制与编码策略<a name="ZH-CN_TOPIC_0000001876269577"></a>

<a name="table1804mcpsimp"></a>
<table><thead align="left"><tr id="row1810mcpsimp"><th class="cellrowborder" valign="top" width="23.189999999999998%" id="mcps1.1.4.1.1"><p id="p1812mcpsimp"><a name="p1812mcpsimp"></a><a name="p1812mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="24.23%" id="mcps1.1.4.1.2"><p id="p1814mcpsimp"><a name="p1814mcpsimp"></a><a name="p1814mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="52.580000000000005%" id="mcps1.1.4.1.3"><p id="p1816mcpsimp"><a name="p1816mcpsimp"></a><a name="p1816mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1817mcpsimp"><td class="cellrowborder" valign="top" width="23.189999999999998%" headers="mcps1.1.4.1.1 "><p id="p1819mcpsimp"><a name="p1819mcpsimp"></a><a name="p1819mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="24.23%" headers="mcps1.1.4.1.2 "><p id="p1821mcpsimp"><a name="p1821mcpsimp"></a><a name="p1821mcpsimp"></a>0x11</p>
</td>
<td class="cellrowborder" valign="top" width="52.580000000000005%" headers="mcps1.1.4.1.3 "><p id="p1823mcpsimp"><a name="p1823mcpsimp"></a><a name="p1823mcpsimp"></a>设置MCS</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

<a name="table1826mcpsimp"></a>
<table><thead align="left"><tr id="row1833mcpsimp"><th class="cellrowborder" valign="top" width="27%" id="mcps1.1.5.1.1"><p id="p1835mcpsimp"><a name="p1835mcpsimp"></a><a name="p1835mcpsimp"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="21.98%" id="mcps1.1.5.1.2"><p id="p1837mcpsimp"><a name="p1837mcpsimp"></a><a name="p1837mcpsimp"></a>Type(bit0~bit6)</p>
</th>
<th class="cellrowborder" valign="top" width="18.02%" id="mcps1.1.5.1.3"><p id="p1839mcpsimp"><a name="p1839mcpsimp"></a><a name="p1839mcpsimp"></a>Length Size(Oct)</p>
</th>
<th class="cellrowborder" valign="top" width="33%" id="mcps1.1.5.1.4"><p id="p1842mcpsimp"><a name="p1842mcpsimp"></a><a name="p1842mcpsimp"></a>Value数据类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row1844mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p1846mcpsimp"><a name="p1846mcpsimp"></a><a name="p1846mcpsimp"></a>conn_id</p>
</td>
<td class="cellrowborder" valign="top" width="21.98%" headers="mcps1.1.5.1.2 "><p id="p1848mcpsimp"><a name="p1848mcpsimp"></a><a name="p1848mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="18.02%" headers="mcps1.1.5.1.3 "><p id="p1850mcpsimp"><a name="p1850mcpsimp"></a><a name="p1850mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p1852mcpsimp"><a name="p1852mcpsimp"></a><a name="p1852mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row1853mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p1855mcpsimp"><a name="p1855mcpsimp"></a><a name="p1855mcpsimp"></a>mcs</p>
</td>
<td class="cellrowborder" valign="top" width="21.98%" headers="mcps1.1.5.1.2 "><p id="p1857mcpsimp"><a name="p1857mcpsimp"></a><a name="p1857mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="18.02%" headers="mcps1.1.5.1.3 "><p id="p1859mcpsimp"><a name="p1859mcpsimp"></a><a name="p1859mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p1861mcpsimp"><a name="p1861mcpsimp"></a><a name="p1861mcpsimp"></a>uint8</p>
</td>
</tr>
</tbody>
</table>

### 设置最大payload字节数<a name="ZH-CN_TOPIC_0000001829430376"></a>

<a name="table1863mcpsimp"></a>
<table><thead align="left"><tr id="row1869mcpsimp"><th class="cellrowborder" valign="top" width="23.380000000000003%" id="mcps1.1.4.1.1"><p id="p1871mcpsimp"><a name="p1871mcpsimp"></a><a name="p1871mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="23.97%" id="mcps1.1.4.1.2"><p id="p1873mcpsimp"><a name="p1873mcpsimp"></a><a name="p1873mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="52.65%" id="mcps1.1.4.1.3"><p id="p1875mcpsimp"><a name="p1875mcpsimp"></a><a name="p1875mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1876mcpsimp"><td class="cellrowborder" valign="top" width="23.380000000000003%" headers="mcps1.1.4.1.1 "><p id="p1878mcpsimp"><a name="p1878mcpsimp"></a><a name="p1878mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="23.97%" headers="mcps1.1.4.1.2 "><p id="p1880mcpsimp"><a name="p1880mcpsimp"></a><a name="p1880mcpsimp"></a>0x12</p>
</td>
<td class="cellrowborder" valign="top" width="52.65%" headers="mcps1.1.4.1.3 "><p id="p1882mcpsimp"><a name="p1882mcpsimp"></a><a name="p1882mcpsimp"></a>设置最大payload</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

<a name="table1885mcpsimp"></a>
<table><thead align="left"><tr id="row1892mcpsimp"><th class="cellrowborder" valign="top" width="27%" id="mcps1.1.5.1.1"><p id="p1894mcpsimp"><a name="p1894mcpsimp"></a><a name="p1894mcpsimp"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="22%" id="mcps1.1.5.1.2"><p id="p1896mcpsimp"><a name="p1896mcpsimp"></a><a name="p1896mcpsimp"></a>Type(bit0~bit6)</p>
</th>
<th class="cellrowborder" valign="top" width="18%" id="mcps1.1.5.1.3"><p id="p1898mcpsimp"><a name="p1898mcpsimp"></a><a name="p1898mcpsimp"></a>Length Size(Oct)</p>
</th>
<th class="cellrowborder" valign="top" width="33%" id="mcps1.1.5.1.4"><p id="p1901mcpsimp"><a name="p1901mcpsimp"></a><a name="p1901mcpsimp"></a>Value数据类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row1903mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p1905mcpsimp"><a name="p1905mcpsimp"></a><a name="p1905mcpsimp"></a>conn_id</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p1907mcpsimp"><a name="p1907mcpsimp"></a><a name="p1907mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p1909mcpsimp"><a name="p1909mcpsimp"></a><a name="p1909mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p1911mcpsimp"><a name="p1911mcpsimp"></a><a name="p1911mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row1912mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p1914mcpsimp"><a name="p1914mcpsimp"></a><a name="p1914mcpsimp"></a>tx_octets</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p1916mcpsimp"><a name="p1916mcpsimp"></a><a name="p1916mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p1918mcpsimp"><a name="p1918mcpsimp"></a><a name="p1918mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p1920mcpsimp"><a name="p1920mcpsimp"></a><a name="p1920mcpsimp"></a>uint16</p>
</td>
</tr>
</tbody>
</table>

### 发送连接状态查询请求<a name="ZH-CN_TOPIC_0000001954647133"></a>

<a name="table147191843154717"></a>
<table><thead align="left"><tr id="row15833124364716"><th class="cellrowborder" valign="top" width="23.517648235176484%" id="mcps1.1.4.1.1"><p id="p5833343174712"><a name="p5833343174712"></a><a name="p5833343174712"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="23.877612238776123%" id="mcps1.1.4.1.2"><p id="p483319432472"><a name="p483319432472"></a><a name="p483319432472"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="52.604739526047396%" id="mcps1.1.4.1.3"><p id="p9833164314715"><a name="p9833164314715"></a><a name="p9833164314715"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row78333437471"><td class="cellrowborder" valign="top" width="23.517648235176484%" headers="mcps1.1.4.1.1 "><p id="p58331543204710"><a name="p58331543204710"></a><a name="p58331543204710"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="23.877612238776123%" headers="mcps1.1.4.1.2 "><p id="p2083304344716"><a name="p2083304344716"></a><a name="p2083304344716"></a>0x13</p>
</td>
<td class="cellrowborder" valign="top" width="52.604739526047396%" headers="mcps1.1.4.1.3 "><p id="p16834243124713"><a name="p16834243124713"></a><a name="p16834243124713"></a>发送连接状态查询请求</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

<a name="table1672594324712"></a>
<table><thead align="left"><tr id="row1983418435477"><th class="cellrowborder" valign="top" width="27.08%" id="mcps1.1.5.1.1"><p id="p7834154319479"><a name="p7834154319479"></a><a name="p7834154319479"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="21.67%" id="mcps1.1.5.1.2"><p id="p8834184317476"><a name="p8834184317476"></a><a name="p8834184317476"></a>Type(bit0~bit6)</p>
</th>
<th class="cellrowborder" valign="top" width="17.71%" id="mcps1.1.5.1.3"><p id="p128341543124710"><a name="p128341543124710"></a><a name="p128341543124710"></a>Length</p>
<p id="p1483416431475"><a name="p1483416431475"></a><a name="p1483416431475"></a>Size(Oct)</p>
</th>
<th class="cellrowborder" valign="top" width="33.54%" id="mcps1.1.5.1.4"><p id="p8834124334719"><a name="p8834124334719"></a><a name="p8834124334719"></a>Value</p>
<p id="p983420435474"><a name="p983420435474"></a><a name="p983420435474"></a>数据类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row1183410437475"><td class="cellrowborder" valign="top" width="27.08%" headers="mcps1.1.5.1.1 "><p id="p78349431471"><a name="p78349431471"></a><a name="p78349431471"></a>conn_status</p>
</td>
<td class="cellrowborder" valign="top" width="21.67%" headers="mcps1.1.5.1.2 "><p id="p108341143134714"><a name="p108341143134714"></a><a name="p108341143134714"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="17.71%" headers="mcps1.1.5.1.3 "><p id="p1483464344713"><a name="p1483464344713"></a><a name="p1483464344713"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33.54%" headers="mcps1.1.5.1.4 "><p id="p6834134311471"><a name="p6834134311471"></a><a name="p6834134311471"></a>uint8</p>
</td>
</tr>
</tbody>
</table>

## SSAP Client Service<a name="ZH-CN_TOPIC_0000001829590136"></a>









### 注册SSAP客户端<a name="ZH-CN_TOPIC_0000001876189801"></a>

<a name="table1923mcpsimp"></a>
<table><thead align="left"><tr id="row1929mcpsimp"><th class="cellrowborder" valign="top" width="23%" id="mcps1.1.4.1.1"><p id="p1931mcpsimp"><a name="p1931mcpsimp"></a><a name="p1931mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="24.529999999999998%" id="mcps1.1.4.1.2"><p id="p1933mcpsimp"><a name="p1933mcpsimp"></a><a name="p1933mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="52.470000000000006%" id="mcps1.1.4.1.3"><p id="p1935mcpsimp"><a name="p1935mcpsimp"></a><a name="p1935mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1936mcpsimp"><td class="cellrowborder" valign="top" width="23%" headers="mcps1.1.4.1.1 "><p id="p1938mcpsimp"><a name="p1938mcpsimp"></a><a name="p1938mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="24.529999999999998%" headers="mcps1.1.4.1.2 "><p id="p1940mcpsimp"><a name="p1940mcpsimp"></a><a name="p1940mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="52.470000000000006%" headers="mcps1.1.4.1.3 "><p id="p1942mcpsimp"><a name="p1942mcpsimp"></a><a name="p1942mcpsimp"></a>注册SSAP客户端</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

<a name="table1945mcpsimp"></a>
<table><thead align="left"><tr id="row1952mcpsimp"><th class="cellrowborder" valign="top" width="27%" id="mcps1.1.5.1.1"><p id="p1954mcpsimp"><a name="p1954mcpsimp"></a><a name="p1954mcpsimp"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="22%" id="mcps1.1.5.1.2"><p id="p1956mcpsimp"><a name="p1956mcpsimp"></a><a name="p1956mcpsimp"></a>Type(bit0~bit6)</p>
</th>
<th class="cellrowborder" valign="top" width="17.98%" id="mcps1.1.5.1.3"><p id="p1958mcpsimp"><a name="p1958mcpsimp"></a><a name="p1958mcpsimp"></a>Length Size(Oct)</p>
</th>
<th class="cellrowborder" valign="top" width="33.019999999999996%" id="mcps1.1.5.1.4"><p id="p1961mcpsimp"><a name="p1961mcpsimp"></a><a name="p1961mcpsimp"></a>Value数据类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row1963mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p1965mcpsimp"><a name="p1965mcpsimp"></a><a name="p1965mcpsimp"></a>len</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p1967mcpsimp"><a name="p1967mcpsimp"></a><a name="p1967mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="p1969mcpsimp"><a name="p1969mcpsimp"></a><a name="p1969mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33.019999999999996%" headers="mcps1.1.5.1.4 "><p id="p1971mcpsimp"><a name="p1971mcpsimp"></a><a name="p1971mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row1972mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p1974mcpsimp"><a name="p1974mcpsimp"></a><a name="p1974mcpsimp"></a>uuid</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p1976mcpsimp"><a name="p1976mcpsimp"></a><a name="p1976mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="p1978mcpsimp"><a name="p1978mcpsimp"></a><a name="p1978mcpsimp"></a>16</p>
</td>
<td class="cellrowborder" valign="top" width="33.019999999999996%" headers="mcps1.1.5.1.4 "><p id="p1980mcpsimp"><a name="p1980mcpsimp"></a><a name="p1980mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row1981mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p1983mcpsimp"><a name="p1983mcpsimp"></a><a name="p1983mcpsimp"></a>client_id</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p1985mcpsimp"><a name="p1985mcpsimp"></a><a name="p1985mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="p1987mcpsimp"><a name="p1987mcpsimp"></a><a name="p1987mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33.019999999999996%" headers="mcps1.1.5.1.4 "><p id="p1989mcpsimp"><a name="p1989mcpsimp"></a><a name="p1989mcpsimp"></a>uint8</p>
</td>
</tr>
</tbody>
</table>

### 注销SSAP客户端<a name="ZH-CN_TOPIC_0000001876269581"></a>

<a name="table1991mcpsimp"></a>
<table><thead align="left"><tr id="row1997mcpsimp"><th class="cellrowborder" valign="top" width="23.25%" id="mcps1.1.4.1.1"><p id="p1999mcpsimp"><a name="p1999mcpsimp"></a><a name="p1999mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="24.15%" id="mcps1.1.4.1.2"><p id="p2001mcpsimp"><a name="p2001mcpsimp"></a><a name="p2001mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="52.6%" id="mcps1.1.4.1.3"><p id="p2003mcpsimp"><a name="p2003mcpsimp"></a><a name="p2003mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2004mcpsimp"><td class="cellrowborder" valign="top" width="23.25%" headers="mcps1.1.4.1.1 "><p id="p2006mcpsimp"><a name="p2006mcpsimp"></a><a name="p2006mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="24.15%" headers="mcps1.1.4.1.2 "><p id="p2008mcpsimp"><a name="p2008mcpsimp"></a><a name="p2008mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="52.6%" headers="mcps1.1.4.1.3 "><p id="p2010mcpsimp"><a name="p2010mcpsimp"></a><a name="p2010mcpsimp"></a>注销SSAP客户端</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

<a name="table2013mcpsimp"></a>
<table><thead align="left"><tr id="row2020mcpsimp"><th class="cellrowborder" valign="top" width="27%" id="mcps1.1.5.1.1"><p id="p2022mcpsimp"><a name="p2022mcpsimp"></a><a name="p2022mcpsimp"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="22%" id="mcps1.1.5.1.2"><p id="p2024mcpsimp"><a name="p2024mcpsimp"></a><a name="p2024mcpsimp"></a>Type(bit0~bit6)</p>
</th>
<th class="cellrowborder" valign="top" width="18%" id="mcps1.1.5.1.3"><p id="p2026mcpsimp"><a name="p2026mcpsimp"></a><a name="p2026mcpsimp"></a>Length Size(Oct)</p>
</th>
<th class="cellrowborder" valign="top" width="33%" id="mcps1.1.5.1.4"><p id="p2029mcpsimp"><a name="p2029mcpsimp"></a><a name="p2029mcpsimp"></a>Value数据类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row2031mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2033mcpsimp"><a name="p2033mcpsimp"></a><a name="p2033mcpsimp"></a>client_id</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p2035mcpsimp"><a name="p2035mcpsimp"></a><a name="p2035mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p2037mcpsimp"><a name="p2037mcpsimp"></a><a name="p2037mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2039mcpsimp"><a name="p2039mcpsimp"></a><a name="p2039mcpsimp"></a>uint8</p>
</td>
</tr>
</tbody>
</table>

### 查找服务、特征、描述符<a name="ZH-CN_TOPIC_0000001829430380"></a>

<a name="table2041mcpsimp"></a>
<table><thead align="left"><tr id="row2047mcpsimp"><th class="cellrowborder" valign="top" width="23.189999999999998%" id="mcps1.1.4.1.1"><p id="p2049mcpsimp"><a name="p2049mcpsimp"></a><a name="p2049mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="24.14%" id="mcps1.1.4.1.2"><p id="p2051mcpsimp"><a name="p2051mcpsimp"></a><a name="p2051mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="52.669999999999995%" id="mcps1.1.4.1.3"><p id="p2053mcpsimp"><a name="p2053mcpsimp"></a><a name="p2053mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2054mcpsimp"><td class="cellrowborder" valign="top" width="23.189999999999998%" headers="mcps1.1.4.1.1 "><p id="p2056mcpsimp"><a name="p2056mcpsimp"></a><a name="p2056mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="24.14%" headers="mcps1.1.4.1.2 "><p id="p2058mcpsimp"><a name="p2058mcpsimp"></a><a name="p2058mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="52.669999999999995%" headers="mcps1.1.4.1.3 "><p id="p2060mcpsimp"><a name="p2060mcpsimp"></a><a name="p2060mcpsimp"></a>查找服务、特征、描述符</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

<a name="table2063mcpsimp"></a>
<table><thead align="left"><tr id="row2070mcpsimp"><th class="cellrowborder" valign="top" width="27%" id="mcps1.1.5.1.1"><p id="p2072mcpsimp"><a name="p2072mcpsimp"></a><a name="p2072mcpsimp"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="22%" id="mcps1.1.5.1.2"><p id="p2074mcpsimp"><a name="p2074mcpsimp"></a><a name="p2074mcpsimp"></a>Type(bit0~bit6)</p>
</th>
<th class="cellrowborder" valign="top" width="18%" id="mcps1.1.5.1.3"><p id="p2076mcpsimp"><a name="p2076mcpsimp"></a><a name="p2076mcpsimp"></a>Length Size(Oct)</p>
</th>
<th class="cellrowborder" valign="top" width="33%" id="mcps1.1.5.1.4"><p id="p2079mcpsimp"><a name="p2079mcpsimp"></a><a name="p2079mcpsimp"></a>Value数据类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row2081mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2083mcpsimp"><a name="p2083mcpsimp"></a><a name="p2083mcpsimp"></a>client_id</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p2085mcpsimp"><a name="p2085mcpsimp"></a><a name="p2085mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p2087mcpsimp"><a name="p2087mcpsimp"></a><a name="p2087mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2089mcpsimp"><a name="p2089mcpsimp"></a><a name="p2089mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row2090mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2092mcpsimp"><a name="p2092mcpsimp"></a><a name="p2092mcpsimp"></a>conn_id</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p2094mcpsimp"><a name="p2094mcpsimp"></a><a name="p2094mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p2096mcpsimp"><a name="p2096mcpsimp"></a><a name="p2096mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2098mcpsimp"><a name="p2098mcpsimp"></a><a name="p2098mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row2099mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2101mcpsimp"><a name="p2101mcpsimp"></a><a name="p2101mcpsimp"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p2103mcpsimp"><a name="p2103mcpsimp"></a><a name="p2103mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p2105mcpsimp"><a name="p2105mcpsimp"></a><a name="p2105mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2107mcpsimp"><a name="p2107mcpsimp"></a><a name="p2107mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row2108mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2110mcpsimp"><a name="p2110mcpsimp"></a><a name="p2110mcpsimp"></a>start_hdl</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p2112mcpsimp"><a name="p2112mcpsimp"></a><a name="p2112mcpsimp"></a>0x04</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p2114mcpsimp"><a name="p2114mcpsimp"></a><a name="p2114mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2116mcpsimp"><a name="p2116mcpsimp"></a><a name="p2116mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row2117mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2119mcpsimp"><a name="p2119mcpsimp"></a><a name="p2119mcpsimp"></a>end_hdl</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p2121mcpsimp"><a name="p2121mcpsimp"></a><a name="p2121mcpsimp"></a>0x05</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p2123mcpsimp"><a name="p2123mcpsimp"></a><a name="p2123mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2125mcpsimp"><a name="p2125mcpsimp"></a><a name="p2125mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row2126mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2128mcpsimp"><a name="p2128mcpsimp"></a><a name="p2128mcpsimp"></a>len</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p2130mcpsimp"><a name="p2130mcpsimp"></a><a name="p2130mcpsimp"></a>0x06</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p2132mcpsimp"><a name="p2132mcpsimp"></a><a name="p2132mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2134mcpsimp"><a name="p2134mcpsimp"></a><a name="p2134mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row2135mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2137mcpsimp"><a name="p2137mcpsimp"></a><a name="p2137mcpsimp"></a>uuid</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p2139mcpsimp"><a name="p2139mcpsimp"></a><a name="p2139mcpsimp"></a>0x07</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p2141mcpsimp"><a name="p2141mcpsimp"></a><a name="p2141mcpsimp"></a>16</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2143mcpsimp"><a name="p2143mcpsimp"></a><a name="p2143mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row2144mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2146mcpsimp"><a name="p2146mcpsimp"></a><a name="p2146mcpsimp"></a>reserve</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p2148mcpsimp"><a name="p2148mcpsimp"></a><a name="p2148mcpsimp"></a>0x08</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p2150mcpsimp"><a name="p2150mcpsimp"></a><a name="p2150mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2152mcpsimp"><a name="p2152mcpsimp"></a><a name="p2152mcpsimp"></a>uint8</p>
</td>
</tr>
</tbody>
</table>

### 发起按照UUID读取请求<a name="ZH-CN_TOPIC_0000001829590140"></a>

<a name="table2154mcpsimp"></a>
<table><thead align="left"><tr id="row2160mcpsimp"><th class="cellrowborder" valign="top" width="23.47%" id="mcps1.1.4.1.1"><p id="p2162mcpsimp"><a name="p2162mcpsimp"></a><a name="p2162mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="24.169999999999998%" id="mcps1.1.4.1.2"><p id="p2164mcpsimp"><a name="p2164mcpsimp"></a><a name="p2164mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="52.35999999999999%" id="mcps1.1.4.1.3"><p id="p2166mcpsimp"><a name="p2166mcpsimp"></a><a name="p2166mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2167mcpsimp"><td class="cellrowborder" valign="top" width="23.47%" headers="mcps1.1.4.1.1 "><p id="p2169mcpsimp"><a name="p2169mcpsimp"></a><a name="p2169mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="24.169999999999998%" headers="mcps1.1.4.1.2 "><p id="p2171mcpsimp"><a name="p2171mcpsimp"></a><a name="p2171mcpsimp"></a>0x04</p>
</td>
<td class="cellrowborder" valign="top" width="52.35999999999999%" headers="mcps1.1.4.1.3 "><p id="p2173mcpsimp"><a name="p2173mcpsimp"></a><a name="p2173mcpsimp"></a>发起按照UUID读取请求</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

<a name="table2176mcpsimp"></a>
<table><thead align="left"><tr id="row2183mcpsimp"><th class="cellrowborder" valign="top" width="27%" id="mcps1.1.5.1.1"><p id="p2185mcpsimp"><a name="p2185mcpsimp"></a><a name="p2185mcpsimp"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="22%" id="mcps1.1.5.1.2"><p id="p2187mcpsimp"><a name="p2187mcpsimp"></a><a name="p2187mcpsimp"></a>Type(bit0~bit6)</p>
</th>
<th class="cellrowborder" valign="top" width="18%" id="mcps1.1.5.1.3"><p id="p2189mcpsimp"><a name="p2189mcpsimp"></a><a name="p2189mcpsimp"></a>Length Size(Oct)</p>
</th>
<th class="cellrowborder" valign="top" width="33%" id="mcps1.1.5.1.4"><p id="p2192mcpsimp"><a name="p2192mcpsimp"></a><a name="p2192mcpsimp"></a>Value数据类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row2194mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2196mcpsimp"><a name="p2196mcpsimp"></a><a name="p2196mcpsimp"></a>client_id</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p2198mcpsimp"><a name="p2198mcpsimp"></a><a name="p2198mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p2200mcpsimp"><a name="p2200mcpsimp"></a><a name="p2200mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2202mcpsimp"><a name="p2202mcpsimp"></a><a name="p2202mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row2203mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2205mcpsimp"><a name="p2205mcpsimp"></a><a name="p2205mcpsimp"></a>conn_id</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p2207mcpsimp"><a name="p2207mcpsimp"></a><a name="p2207mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p2209mcpsimp"><a name="p2209mcpsimp"></a><a name="p2209mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2211mcpsimp"><a name="p2211mcpsimp"></a><a name="p2211mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row2212mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2214mcpsimp"><a name="p2214mcpsimp"></a><a name="p2214mcpsimp"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p2216mcpsimp"><a name="p2216mcpsimp"></a><a name="p2216mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p2218mcpsimp"><a name="p2218mcpsimp"></a><a name="p2218mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2220mcpsimp"><a name="p2220mcpsimp"></a><a name="p2220mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row2221mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2223mcpsimp"><a name="p2223mcpsimp"></a><a name="p2223mcpsimp"></a>start_hdl</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p2225mcpsimp"><a name="p2225mcpsimp"></a><a name="p2225mcpsimp"></a>0x04</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p2227mcpsimp"><a name="p2227mcpsimp"></a><a name="p2227mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2229mcpsimp"><a name="p2229mcpsimp"></a><a name="p2229mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row2230mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2232mcpsimp"><a name="p2232mcpsimp"></a><a name="p2232mcpsimp"></a>end_hdl</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p2234mcpsimp"><a name="p2234mcpsimp"></a><a name="p2234mcpsimp"></a>0x05</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p2236mcpsimp"><a name="p2236mcpsimp"></a><a name="p2236mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2238mcpsimp"><a name="p2238mcpsimp"></a><a name="p2238mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row2239mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2241mcpsimp"><a name="p2241mcpsimp"></a><a name="p2241mcpsimp"></a>len</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p2243mcpsimp"><a name="p2243mcpsimp"></a><a name="p2243mcpsimp"></a>0x06</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p2245mcpsimp"><a name="p2245mcpsimp"></a><a name="p2245mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2247mcpsimp"><a name="p2247mcpsimp"></a><a name="p2247mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row2248mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2250mcpsimp"><a name="p2250mcpsimp"></a><a name="p2250mcpsimp"></a>uuid</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p2252mcpsimp"><a name="p2252mcpsimp"></a><a name="p2252mcpsimp"></a>0x07</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p2254mcpsimp"><a name="p2254mcpsimp"></a><a name="p2254mcpsimp"></a>16</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2256mcpsimp"><a name="p2256mcpsimp"></a><a name="p2256mcpsimp"></a>uint8</p>
</td>
</tr>
</tbody>
</table>

### 发起按照句柄读取请求<a name="ZH-CN_TOPIC_0000001876189805"></a>

<a name="table2258mcpsimp"></a>
<table><thead align="left"><tr id="row2264mcpsimp"><th class="cellrowborder" valign="top" width="23.880000000000003%" id="mcps1.1.4.1.1"><p id="p2266mcpsimp"><a name="p2266mcpsimp"></a><a name="p2266mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="23.84%" id="mcps1.1.4.1.2"><p id="p2268mcpsimp"><a name="p2268mcpsimp"></a><a name="p2268mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="52.28%" id="mcps1.1.4.1.3"><p id="p2270mcpsimp"><a name="p2270mcpsimp"></a><a name="p2270mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2271mcpsimp"><td class="cellrowborder" valign="top" width="23.880000000000003%" headers="mcps1.1.4.1.1 "><p id="p2273mcpsimp"><a name="p2273mcpsimp"></a><a name="p2273mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="23.84%" headers="mcps1.1.4.1.2 "><p id="p2275mcpsimp"><a name="p2275mcpsimp"></a><a name="p2275mcpsimp"></a>0x05</p>
</td>
<td class="cellrowborder" valign="top" width="52.28%" headers="mcps1.1.4.1.3 "><p id="p2277mcpsimp"><a name="p2277mcpsimp"></a><a name="p2277mcpsimp"></a>发起按照句柄读取请求</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

<a name="table2280mcpsimp"></a>
<table><thead align="left"><tr id="row2287mcpsimp"><th class="cellrowborder" valign="top" width="27%" id="mcps1.1.5.1.1"><p id="p2289mcpsimp"><a name="p2289mcpsimp"></a><a name="p2289mcpsimp"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="22%" id="mcps1.1.5.1.2"><p id="p2291mcpsimp"><a name="p2291mcpsimp"></a><a name="p2291mcpsimp"></a>Type(bit0~bit6)</p>
</th>
<th class="cellrowborder" valign="top" width="18%" id="mcps1.1.5.1.3"><p id="p2293mcpsimp"><a name="p2293mcpsimp"></a><a name="p2293mcpsimp"></a>Length Size(Oct)</p>
</th>
<th class="cellrowborder" valign="top" width="33%" id="mcps1.1.5.1.4"><p id="p2296mcpsimp"><a name="p2296mcpsimp"></a><a name="p2296mcpsimp"></a>Value数据类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row2298mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2300mcpsimp"><a name="p2300mcpsimp"></a><a name="p2300mcpsimp"></a>client_id</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p2302mcpsimp"><a name="p2302mcpsimp"></a><a name="p2302mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p2304mcpsimp"><a name="p2304mcpsimp"></a><a name="p2304mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2306mcpsimp"><a name="p2306mcpsimp"></a><a name="p2306mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row2307mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2309mcpsimp"><a name="p2309mcpsimp"></a><a name="p2309mcpsimp"></a>conn_id</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p2311mcpsimp"><a name="p2311mcpsimp"></a><a name="p2311mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p2313mcpsimp"><a name="p2313mcpsimp"></a><a name="p2313mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2315mcpsimp"><a name="p2315mcpsimp"></a><a name="p2315mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row2316mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2318mcpsimp"><a name="p2318mcpsimp"></a><a name="p2318mcpsimp"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p2320mcpsimp"><a name="p2320mcpsimp"></a><a name="p2320mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p2322mcpsimp"><a name="p2322mcpsimp"></a><a name="p2322mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2324mcpsimp"><a name="p2324mcpsimp"></a><a name="p2324mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row2325mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2327mcpsimp"><a name="p2327mcpsimp"></a><a name="p2327mcpsimp"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p2329mcpsimp"><a name="p2329mcpsimp"></a><a name="p2329mcpsimp"></a>0x04</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p2331mcpsimp"><a name="p2331mcpsimp"></a><a name="p2331mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2333mcpsimp"><a name="p2333mcpsimp"></a><a name="p2333mcpsimp"></a>uint8</p>
</td>
</tr>
</tbody>
</table>

### 发起写请求<a name="ZH-CN_TOPIC_0000001876269585"></a>

<a name="table2335mcpsimp"></a>
<table><thead align="left"><tr id="row2341mcpsimp"><th class="cellrowborder" valign="top" width="23.82%" id="mcps1.1.4.1.1"><p id="p2343mcpsimp"><a name="p2343mcpsimp"></a><a name="p2343mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="23.76%" id="mcps1.1.4.1.2"><p id="p2345mcpsimp"><a name="p2345mcpsimp"></a><a name="p2345mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.4.1.3"><p id="p2347mcpsimp"><a name="p2347mcpsimp"></a><a name="p2347mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2348mcpsimp"><td class="cellrowborder" valign="top" width="23.82%" headers="mcps1.1.4.1.1 "><p id="p2350mcpsimp"><a name="p2350mcpsimp"></a><a name="p2350mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="23.76%" headers="mcps1.1.4.1.2 "><p id="p2352mcpsimp"><a name="p2352mcpsimp"></a><a name="p2352mcpsimp"></a>0x06</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.4.1.3 "><p id="p2354mcpsimp"><a name="p2354mcpsimp"></a><a name="p2354mcpsimp"></a>发起写请求</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

<a name="table2357mcpsimp"></a>
<table><thead align="left"><tr id="row2364mcpsimp"><th class="cellrowborder" valign="top" width="27%" id="mcps1.1.5.1.1"><p id="p2366mcpsimp"><a name="p2366mcpsimp"></a><a name="p2366mcpsimp"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="22%" id="mcps1.1.5.1.2"><p id="p2368mcpsimp"><a name="p2368mcpsimp"></a><a name="p2368mcpsimp"></a>Type(bit0~bit6)</p>
</th>
<th class="cellrowborder" valign="top" width="18%" id="mcps1.1.5.1.3"><p id="p2370mcpsimp"><a name="p2370mcpsimp"></a><a name="p2370mcpsimp"></a>Length Size(Oct)</p>
</th>
<th class="cellrowborder" valign="top" width="33%" id="mcps1.1.5.1.4"><p id="p2373mcpsimp"><a name="p2373mcpsimp"></a><a name="p2373mcpsimp"></a>Value数据类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row2375mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2377mcpsimp"><a name="p2377mcpsimp"></a><a name="p2377mcpsimp"></a>client_id</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p2379mcpsimp"><a name="p2379mcpsimp"></a><a name="p2379mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p2381mcpsimp"><a name="p2381mcpsimp"></a><a name="p2381mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2383mcpsimp"><a name="p2383mcpsimp"></a><a name="p2383mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row2384mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2386mcpsimp"><a name="p2386mcpsimp"></a><a name="p2386mcpsimp"></a>conn_id</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p2388mcpsimp"><a name="p2388mcpsimp"></a><a name="p2388mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p2390mcpsimp"><a name="p2390mcpsimp"></a><a name="p2390mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2392mcpsimp"><a name="p2392mcpsimp"></a><a name="p2392mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row2393mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2395mcpsimp"><a name="p2395mcpsimp"></a><a name="p2395mcpsimp"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p2397mcpsimp"><a name="p2397mcpsimp"></a><a name="p2397mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p2399mcpsimp"><a name="p2399mcpsimp"></a><a name="p2399mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2401mcpsimp"><a name="p2401mcpsimp"></a><a name="p2401mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row2402mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2404mcpsimp"><a name="p2404mcpsimp"></a><a name="p2404mcpsimp"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p2406mcpsimp"><a name="p2406mcpsimp"></a><a name="p2406mcpsimp"></a>0x04</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p2408mcpsimp"><a name="p2408mcpsimp"></a><a name="p2408mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2410mcpsimp"><a name="p2410mcpsimp"></a><a name="p2410mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row2411mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2413mcpsimp"><a name="p2413mcpsimp"></a><a name="p2413mcpsimp"></a>data_len</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p2415mcpsimp"><a name="p2415mcpsimp"></a><a name="p2415mcpsimp"></a>0x05</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p2417mcpsimp"><a name="p2417mcpsimp"></a><a name="p2417mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2419mcpsimp"><a name="p2419mcpsimp"></a><a name="p2419mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row2420mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2422mcpsimp"><a name="p2422mcpsimp"></a><a name="p2422mcpsimp"></a>data</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p2424mcpsimp"><a name="p2424mcpsimp"></a><a name="p2424mcpsimp"></a>0x06</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p2426mcpsimp"><a name="p2426mcpsimp"></a><a name="p2426mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2428mcpsimp"><a name="p2428mcpsimp"></a><a name="p2428mcpsimp"></a>uint8</p>
</td>
</tr>
</tbody>
</table>

### 发起写命令<a name="ZH-CN_TOPIC_0000001829430384"></a>

<a name="table2430mcpsimp"></a>
<table><thead align="left"><tr id="row2436mcpsimp"><th class="cellrowborder" valign="top" width="23.94%" id="mcps1.1.4.1.1"><p id="p2438mcpsimp"><a name="p2438mcpsimp"></a><a name="p2438mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="23.630000000000003%" id="mcps1.1.4.1.2"><p id="p2440mcpsimp"><a name="p2440mcpsimp"></a><a name="p2440mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="52.43%" id="mcps1.1.4.1.3"><p id="p2442mcpsimp"><a name="p2442mcpsimp"></a><a name="p2442mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2443mcpsimp"><td class="cellrowborder" valign="top" width="23.94%" headers="mcps1.1.4.1.1 "><p id="p2445mcpsimp"><a name="p2445mcpsimp"></a><a name="p2445mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="23.630000000000003%" headers="mcps1.1.4.1.2 "><p id="p2447mcpsimp"><a name="p2447mcpsimp"></a><a name="p2447mcpsimp"></a>0x07</p>
</td>
<td class="cellrowborder" valign="top" width="52.43%" headers="mcps1.1.4.1.3 "><p id="p2449mcpsimp"><a name="p2449mcpsimp"></a><a name="p2449mcpsimp"></a>发起写命令</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

<a name="table2452mcpsimp"></a>
<table><thead align="left"><tr id="row2459mcpsimp"><th class="cellrowborder" valign="top" width="27%" id="mcps1.1.5.1.1"><p id="p2461mcpsimp"><a name="p2461mcpsimp"></a><a name="p2461mcpsimp"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="22%" id="mcps1.1.5.1.2"><p id="p2463mcpsimp"><a name="p2463mcpsimp"></a><a name="p2463mcpsimp"></a>Type(bit0~bit6)</p>
</th>
<th class="cellrowborder" valign="top" width="18%" id="mcps1.1.5.1.3"><p id="p2465mcpsimp"><a name="p2465mcpsimp"></a><a name="p2465mcpsimp"></a>Length Size(Oct)</p>
</th>
<th class="cellrowborder" valign="top" width="33%" id="mcps1.1.5.1.4"><p id="p2468mcpsimp"><a name="p2468mcpsimp"></a><a name="p2468mcpsimp"></a>Value数据类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row2470mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2472mcpsimp"><a name="p2472mcpsimp"></a><a name="p2472mcpsimp"></a>client_id</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p2474mcpsimp"><a name="p2474mcpsimp"></a><a name="p2474mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p2476mcpsimp"><a name="p2476mcpsimp"></a><a name="p2476mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2478mcpsimp"><a name="p2478mcpsimp"></a><a name="p2478mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row2479mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2481mcpsimp"><a name="p2481mcpsimp"></a><a name="p2481mcpsimp"></a>conn_id</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p2483mcpsimp"><a name="p2483mcpsimp"></a><a name="p2483mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p2485mcpsimp"><a name="p2485mcpsimp"></a><a name="p2485mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2487mcpsimp"><a name="p2487mcpsimp"></a><a name="p2487mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row2488mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2490mcpsimp"><a name="p2490mcpsimp"></a><a name="p2490mcpsimp"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p2492mcpsimp"><a name="p2492mcpsimp"></a><a name="p2492mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p2494mcpsimp"><a name="p2494mcpsimp"></a><a name="p2494mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2496mcpsimp"><a name="p2496mcpsimp"></a><a name="p2496mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row2497mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2499mcpsimp"><a name="p2499mcpsimp"></a><a name="p2499mcpsimp"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p2501mcpsimp"><a name="p2501mcpsimp"></a><a name="p2501mcpsimp"></a>0x04</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p2503mcpsimp"><a name="p2503mcpsimp"></a><a name="p2503mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2505mcpsimp"><a name="p2505mcpsimp"></a><a name="p2505mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row2506mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2508mcpsimp"><a name="p2508mcpsimp"></a><a name="p2508mcpsimp"></a>data_len</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p2510mcpsimp"><a name="p2510mcpsimp"></a><a name="p2510mcpsimp"></a>0x05</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p2512mcpsimp"><a name="p2512mcpsimp"></a><a name="p2512mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2514mcpsimp"><a name="p2514mcpsimp"></a><a name="p2514mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row2515mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2517mcpsimp"><a name="p2517mcpsimp"></a><a name="p2517mcpsimp"></a>data</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p2519mcpsimp"><a name="p2519mcpsimp"></a><a name="p2519mcpsimp"></a>0x06</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p2521mcpsimp"><a name="p2521mcpsimp"></a><a name="p2521mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2523mcpsimp"><a name="p2523mcpsimp"></a><a name="p2523mcpsimp"></a>uint8</p>
</td>
</tr>
</tbody>
</table>

### 发送交换info请求<a name="ZH-CN_TOPIC_0000001829590144"></a>

<a name="table2525mcpsimp"></a>
<table><thead align="left"><tr id="row2531mcpsimp"><th class="cellrowborder" valign="top" width="24.11%" id="mcps1.1.4.1.1"><p id="p2533mcpsimp"><a name="p2533mcpsimp"></a><a name="p2533mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="23.46%" id="mcps1.1.4.1.2"><p id="p2535mcpsimp"><a name="p2535mcpsimp"></a><a name="p2535mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="52.43%" id="mcps1.1.4.1.3"><p id="p2537mcpsimp"><a name="p2537mcpsimp"></a><a name="p2537mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2538mcpsimp"><td class="cellrowborder" valign="top" width="24.11%" headers="mcps1.1.4.1.1 "><p id="p2540mcpsimp"><a name="p2540mcpsimp"></a><a name="p2540mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="23.46%" headers="mcps1.1.4.1.2 "><p id="p2542mcpsimp"><a name="p2542mcpsimp"></a><a name="p2542mcpsimp"></a>0x08</p>
</td>
<td class="cellrowborder" valign="top" width="52.43%" headers="mcps1.1.4.1.3 "><p id="p2544mcpsimp"><a name="p2544mcpsimp"></a><a name="p2544mcpsimp"></a>发送交换info请求</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

<a name="table2547mcpsimp"></a>
<table><thead align="left"><tr id="row2554mcpsimp"><th class="cellrowborder" valign="top" width="27%" id="mcps1.1.5.1.1"><p id="p2556mcpsimp"><a name="p2556mcpsimp"></a><a name="p2556mcpsimp"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="22%" id="mcps1.1.5.1.2"><p id="p2558mcpsimp"><a name="p2558mcpsimp"></a><a name="p2558mcpsimp"></a>Type(bit0~bit6)</p>
</th>
<th class="cellrowborder" valign="top" width="18%" id="mcps1.1.5.1.3"><p id="p2560mcpsimp"><a name="p2560mcpsimp"></a><a name="p2560mcpsimp"></a>Length Size(Oct)</p>
</th>
<th class="cellrowborder" valign="top" width="33%" id="mcps1.1.5.1.4"><p id="p2563mcpsimp"><a name="p2563mcpsimp"></a><a name="p2563mcpsimp"></a>Value数据类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row2565mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2567mcpsimp"><a name="p2567mcpsimp"></a><a name="p2567mcpsimp"></a>client_id</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p2569mcpsimp"><a name="p2569mcpsimp"></a><a name="p2569mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p2571mcpsimp"><a name="p2571mcpsimp"></a><a name="p2571mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2573mcpsimp"><a name="p2573mcpsimp"></a><a name="p2573mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row2574mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2576mcpsimp"><a name="p2576mcpsimp"></a><a name="p2576mcpsimp"></a>conn_id</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p2578mcpsimp"><a name="p2578mcpsimp"></a><a name="p2578mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p2580mcpsimp"><a name="p2580mcpsimp"></a><a name="p2580mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2582mcpsimp"><a name="p2582mcpsimp"></a><a name="p2582mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row2583mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2585mcpsimp"><a name="p2585mcpsimp"></a><a name="p2585mcpsimp"></a>mtu_size</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p2587mcpsimp"><a name="p2587mcpsimp"></a><a name="p2587mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p2589mcpsimp"><a name="p2589mcpsimp"></a><a name="p2589mcpsimp"></a>4</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2591mcpsimp"><a name="p2591mcpsimp"></a><a name="p2591mcpsimp"></a>uint32</p>
</td>
</tr>
<tr id="row2592mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2594mcpsimp"><a name="p2594mcpsimp"></a><a name="p2594mcpsimp"></a>version</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p2596mcpsimp"><a name="p2596mcpsimp"></a><a name="p2596mcpsimp"></a>0x04</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p2598mcpsimp"><a name="p2598mcpsimp"></a><a name="p2598mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2600mcpsimp"><a name="p2600mcpsimp"></a><a name="p2600mcpsimp"></a>uint16</p>
</td>
</tr>
</tbody>
</table>

## SSAP Server Service<a name="ZH-CN_TOPIC_0000001876189809"></a>















### 注册SSAP服务端<a name="ZH-CN_TOPIC_0000001876269589"></a>

<a name="table2603mcpsimp"></a>
<table><thead align="left"><tr id="row2609mcpsimp"><th class="cellrowborder" valign="top" width="23.990000000000002%" id="mcps1.1.4.1.1"><p id="p2611mcpsimp"><a name="p2611mcpsimp"></a><a name="p2611mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="24.11%" id="mcps1.1.4.1.2"><p id="p2613mcpsimp"><a name="p2613mcpsimp"></a><a name="p2613mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="51.9%" id="mcps1.1.4.1.3"><p id="p2615mcpsimp"><a name="p2615mcpsimp"></a><a name="p2615mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2616mcpsimp"><td class="cellrowborder" valign="top" width="23.990000000000002%" headers="mcps1.1.4.1.1 "><p id="p2618mcpsimp"><a name="p2618mcpsimp"></a><a name="p2618mcpsimp"></a>0x04</p>
</td>
<td class="cellrowborder" valign="top" width="24.11%" headers="mcps1.1.4.1.2 "><p id="p2620mcpsimp"><a name="p2620mcpsimp"></a><a name="p2620mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="51.9%" headers="mcps1.1.4.1.3 "><p id="p2622mcpsimp"><a name="p2622mcpsimp"></a><a name="p2622mcpsimp"></a>注册SSAP服务端</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

<a name="table2625mcpsimp"></a>
<table><thead align="left"><tr id="row2632mcpsimp"><th class="cellrowborder" valign="top" width="27%" id="mcps1.1.5.1.1"><p id="p2634mcpsimp"><a name="p2634mcpsimp"></a><a name="p2634mcpsimp"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="22%" id="mcps1.1.5.1.2"><p id="p2636mcpsimp"><a name="p2636mcpsimp"></a><a name="p2636mcpsimp"></a>Type(bit0~bit6)</p>
</th>
<th class="cellrowborder" valign="top" width="18%" id="mcps1.1.5.1.3"><p id="p2638mcpsimp"><a name="p2638mcpsimp"></a><a name="p2638mcpsimp"></a>Length Size(Oct)</p>
</th>
<th class="cellrowborder" valign="top" width="33%" id="mcps1.1.5.1.4"><p id="p2641mcpsimp"><a name="p2641mcpsimp"></a><a name="p2641mcpsimp"></a>Value数据类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row2643mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2645mcpsimp"><a name="p2645mcpsimp"></a><a name="p2645mcpsimp"></a>len</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p2647mcpsimp"><a name="p2647mcpsimp"></a><a name="p2647mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p2649mcpsimp"><a name="p2649mcpsimp"></a><a name="p2649mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2651mcpsimp"><a name="p2651mcpsimp"></a><a name="p2651mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row2652mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2654mcpsimp"><a name="p2654mcpsimp"></a><a name="p2654mcpsimp"></a>uuid</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p2656mcpsimp"><a name="p2656mcpsimp"></a><a name="p2656mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p2658mcpsimp"><a name="p2658mcpsimp"></a><a name="p2658mcpsimp"></a>16</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2660mcpsimp"><a name="p2660mcpsimp"></a><a name="p2660mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row2661mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2663mcpsimp"><a name="p2663mcpsimp"></a><a name="p2663mcpsimp"></a>server_id</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p2665mcpsimp"><a name="p2665mcpsimp"></a><a name="p2665mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p2667mcpsimp"><a name="p2667mcpsimp"></a><a name="p2667mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2669mcpsimp"><a name="p2669mcpsimp"></a><a name="p2669mcpsimp"></a>uint8</p>
</td>
</tr>
</tbody>
</table>

### 注销SSAP服务端<a name="ZH-CN_TOPIC_0000001829430388"></a>

<a name="table2671mcpsimp"></a>
<table><thead align="left"><tr id="row2677mcpsimp"><th class="cellrowborder" valign="top" width="24.12%" id="mcps1.1.4.1.1"><p id="p2679mcpsimp"><a name="p2679mcpsimp"></a><a name="p2679mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="23.79%" id="mcps1.1.4.1.2"><p id="p2681mcpsimp"><a name="p2681mcpsimp"></a><a name="p2681mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="52.09%" id="mcps1.1.4.1.3"><p id="p2683mcpsimp"><a name="p2683mcpsimp"></a><a name="p2683mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2684mcpsimp"><td class="cellrowborder" valign="top" width="24.12%" headers="mcps1.1.4.1.1 "><p id="p2686mcpsimp"><a name="p2686mcpsimp"></a><a name="p2686mcpsimp"></a>0x04</p>
</td>
<td class="cellrowborder" valign="top" width="23.79%" headers="mcps1.1.4.1.2 "><p id="p2688mcpsimp"><a name="p2688mcpsimp"></a><a name="p2688mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="52.09%" headers="mcps1.1.4.1.3 "><p id="p2690mcpsimp"><a name="p2690mcpsimp"></a><a name="p2690mcpsimp"></a>注销SSAP服务端</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

<a name="table2693mcpsimp"></a>
<table><thead align="left"><tr id="row2700mcpsimp"><th class="cellrowborder" valign="top" width="27%" id="mcps1.1.5.1.1"><p id="p2702mcpsimp"><a name="p2702mcpsimp"></a><a name="p2702mcpsimp"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="22%" id="mcps1.1.5.1.2"><p id="p2704mcpsimp"><a name="p2704mcpsimp"></a><a name="p2704mcpsimp"></a>Type(bit0~bit6)</p>
</th>
<th class="cellrowborder" valign="top" width="17.98%" id="mcps1.1.5.1.3"><p id="p2706mcpsimp"><a name="p2706mcpsimp"></a><a name="p2706mcpsimp"></a>Length Size(Oct)</p>
</th>
<th class="cellrowborder" valign="top" width="33.019999999999996%" id="mcps1.1.5.1.4"><p id="p2709mcpsimp"><a name="p2709mcpsimp"></a><a name="p2709mcpsimp"></a>Value数据类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row2711mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2713mcpsimp"><a name="p2713mcpsimp"></a><a name="p2713mcpsimp"></a>server_id</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p2715mcpsimp"><a name="p2715mcpsimp"></a><a name="p2715mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="p2717mcpsimp"><a name="p2717mcpsimp"></a><a name="p2717mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33.019999999999996%" headers="mcps1.1.5.1.4 "><p id="p2719mcpsimp"><a name="p2719mcpsimp"></a><a name="p2719mcpsimp"></a>uint8</p>
</td>
</tr>
</tbody>
</table>

### 异步添加SSAP服务<a name="ZH-CN_TOPIC_0000001829590148"></a>

<a name="table2721mcpsimp"></a>
<table><thead align="left"><tr id="row2727mcpsimp"><th class="cellrowborder" valign="top" width="24.07%" id="mcps1.1.4.1.1"><p id="p2729mcpsimp"><a name="p2729mcpsimp"></a><a name="p2729mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="24.04%" id="mcps1.1.4.1.2"><p id="p2731mcpsimp"><a name="p2731mcpsimp"></a><a name="p2731mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="51.89%" id="mcps1.1.4.1.3"><p id="p2733mcpsimp"><a name="p2733mcpsimp"></a><a name="p2733mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2734mcpsimp"><td class="cellrowborder" valign="top" width="24.07%" headers="mcps1.1.4.1.1 "><p id="p2736mcpsimp"><a name="p2736mcpsimp"></a><a name="p2736mcpsimp"></a>0x04</p>
</td>
<td class="cellrowborder" valign="top" width="24.04%" headers="mcps1.1.4.1.2 "><p id="p2738mcpsimp"><a name="p2738mcpsimp"></a><a name="p2738mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="51.89%" headers="mcps1.1.4.1.3 "><p id="p2740mcpsimp"><a name="p2740mcpsimp"></a><a name="p2740mcpsimp"></a>异步添加SSAP服务</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

<a name="table2743mcpsimp"></a>
<table><thead align="left"><tr id="row2750mcpsimp"><th class="cellrowborder" valign="top" width="27%" id="mcps1.1.5.1.1"><p id="p2752mcpsimp"><a name="p2752mcpsimp"></a><a name="p2752mcpsimp"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="21.98%" id="mcps1.1.5.1.2"><p id="p2754mcpsimp"><a name="p2754mcpsimp"></a><a name="p2754mcpsimp"></a>Type(bit0~bit6)</p>
</th>
<th class="cellrowborder" valign="top" width="18.02%" id="mcps1.1.5.1.3"><p id="p2756mcpsimp"><a name="p2756mcpsimp"></a><a name="p2756mcpsimp"></a>Length Size(Oct)</p>
</th>
<th class="cellrowborder" valign="top" width="33%" id="mcps1.1.5.1.4"><p id="p2759mcpsimp"><a name="p2759mcpsimp"></a><a name="p2759mcpsimp"></a>Value数据类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row2761mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2763mcpsimp"><a name="p2763mcpsimp"></a><a name="p2763mcpsimp"></a>server_id</p>
</td>
<td class="cellrowborder" valign="top" width="21.98%" headers="mcps1.1.5.1.2 "><p id="p2765mcpsimp"><a name="p2765mcpsimp"></a><a name="p2765mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="18.02%" headers="mcps1.1.5.1.3 "><p id="p2767mcpsimp"><a name="p2767mcpsimp"></a><a name="p2767mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2769mcpsimp"><a name="p2769mcpsimp"></a><a name="p2769mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row2770mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2772mcpsimp"><a name="p2772mcpsimp"></a><a name="p2772mcpsimp"></a>len</p>
</td>
<td class="cellrowborder" valign="top" width="21.98%" headers="mcps1.1.5.1.2 "><p id="p2774mcpsimp"><a name="p2774mcpsimp"></a><a name="p2774mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="18.02%" headers="mcps1.1.5.1.3 "><p id="p2776mcpsimp"><a name="p2776mcpsimp"></a><a name="p2776mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2778mcpsimp"><a name="p2778mcpsimp"></a><a name="p2778mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row2779mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2781mcpsimp"><a name="p2781mcpsimp"></a><a name="p2781mcpsimp"></a>uuid</p>
</td>
<td class="cellrowborder" valign="top" width="21.98%" headers="mcps1.1.5.1.2 "><p id="p2783mcpsimp"><a name="p2783mcpsimp"></a><a name="p2783mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="18.02%" headers="mcps1.1.5.1.3 "><p id="p2785mcpsimp"><a name="p2785mcpsimp"></a><a name="p2785mcpsimp"></a>16</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2787mcpsimp"><a name="p2787mcpsimp"></a><a name="p2787mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row2788mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2790mcpsimp"><a name="p2790mcpsimp"></a><a name="p2790mcpsimp"></a>is_primary</p>
</td>
<td class="cellrowborder" valign="top" width="21.98%" headers="mcps1.1.5.1.2 "><p id="p2792mcpsimp"><a name="p2792mcpsimp"></a><a name="p2792mcpsimp"></a>0x04</p>
</td>
<td class="cellrowborder" valign="top" width="18.02%" headers="mcps1.1.5.1.3 "><p id="p2794mcpsimp"><a name="p2794mcpsimp"></a><a name="p2794mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2796mcpsimp"><a name="p2796mcpsimp"></a><a name="p2796mcpsimp"></a>bool</p>
</td>
</tr>
</tbody>
</table>

### 异步添加SSAP属性<a name="ZH-CN_TOPIC_0000001876189813"></a>

<a name="table2798mcpsimp"></a>
<table><thead align="left"><tr id="row2804mcpsimp"><th class="cellrowborder" valign="top" width="23.630000000000003%" id="mcps1.1.4.1.1"><p id="p2806mcpsimp"><a name="p2806mcpsimp"></a><a name="p2806mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="24.14%" id="mcps1.1.4.1.2"><p id="p2808mcpsimp"><a name="p2808mcpsimp"></a><a name="p2808mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="52.23%" id="mcps1.1.4.1.3"><p id="p2810mcpsimp"><a name="p2810mcpsimp"></a><a name="p2810mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2811mcpsimp"><td class="cellrowborder" valign="top" width="23.630000000000003%" headers="mcps1.1.4.1.1 "><p id="p2813mcpsimp"><a name="p2813mcpsimp"></a><a name="p2813mcpsimp"></a>0x04</p>
</td>
<td class="cellrowborder" valign="top" width="24.14%" headers="mcps1.1.4.1.2 "><p id="p2815mcpsimp"><a name="p2815mcpsimp"></a><a name="p2815mcpsimp"></a>0x04</p>
</td>
<td class="cellrowborder" valign="top" width="52.23%" headers="mcps1.1.4.1.3 "><p id="p2817mcpsimp"><a name="p2817mcpsimp"></a><a name="p2817mcpsimp"></a>异步添加SSAP属性</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

<a name="table2820mcpsimp"></a>
<table><thead align="left"><tr id="row2827mcpsimp"><th class="cellrowborder" valign="top" width="27%" id="mcps1.1.5.1.1"><p id="p2829mcpsimp"><a name="p2829mcpsimp"></a><a name="p2829mcpsimp"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="22%" id="mcps1.1.5.1.2"><p id="p2831mcpsimp"><a name="p2831mcpsimp"></a><a name="p2831mcpsimp"></a>Type(bit0~bit6)</p>
</th>
<th class="cellrowborder" valign="top" width="18%" id="mcps1.1.5.1.3"><p id="p2833mcpsimp"><a name="p2833mcpsimp"></a><a name="p2833mcpsimp"></a>Length Size(Oct)</p>
</th>
<th class="cellrowborder" valign="top" width="33%" id="mcps1.1.5.1.4"><p id="p2836mcpsimp"><a name="p2836mcpsimp"></a><a name="p2836mcpsimp"></a>Value数据类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row2838mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2840mcpsimp"><a name="p2840mcpsimp"></a><a name="p2840mcpsimp"></a>server_id</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p2842mcpsimp"><a name="p2842mcpsimp"></a><a name="p2842mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p2844mcpsimp"><a name="p2844mcpsimp"></a><a name="p2844mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2846mcpsimp"><a name="p2846mcpsimp"></a><a name="p2846mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row2847mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2849mcpsimp"><a name="p2849mcpsimp"></a><a name="p2849mcpsimp"></a>service_handle</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p2851mcpsimp"><a name="p2851mcpsimp"></a><a name="p2851mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p2853mcpsimp"><a name="p2853mcpsimp"></a><a name="p2853mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2855mcpsimp"><a name="p2855mcpsimp"></a><a name="p2855mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row2856mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2858mcpsimp"><a name="p2858mcpsimp"></a><a name="p2858mcpsimp"></a>len</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p2860mcpsimp"><a name="p2860mcpsimp"></a><a name="p2860mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p2862mcpsimp"><a name="p2862mcpsimp"></a><a name="p2862mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2864mcpsimp"><a name="p2864mcpsimp"></a><a name="p2864mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row2865mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2867mcpsimp"><a name="p2867mcpsimp"></a><a name="p2867mcpsimp"></a>uuid</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p2869mcpsimp"><a name="p2869mcpsimp"></a><a name="p2869mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p2871mcpsimp"><a name="p2871mcpsimp"></a><a name="p2871mcpsimp"></a>16</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2873mcpsimp"><a name="p2873mcpsimp"></a><a name="p2873mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row2874mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2876mcpsimp"><a name="p2876mcpsimp"></a><a name="p2876mcpsimp"></a>permissions</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p2878mcpsimp"><a name="p2878mcpsimp"></a><a name="p2878mcpsimp"></a>0x04</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p2880mcpsimp"><a name="p2880mcpsimp"></a><a name="p2880mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2882mcpsimp"><a name="p2882mcpsimp"></a><a name="p2882mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row2883mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2885mcpsimp"><a name="p2885mcpsimp"></a><a name="p2885mcpsimp"></a>operate_indication</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p2887mcpsimp"><a name="p2887mcpsimp"></a><a name="p2887mcpsimp"></a>0x05</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p2889mcpsimp"><a name="p2889mcpsimp"></a><a name="p2889mcpsimp"></a>4</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2891mcpsimp"><a name="p2891mcpsimp"></a><a name="p2891mcpsimp"></a>uint32</p>
</td>
</tr>
<tr id="row2892mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2894mcpsimp"><a name="p2894mcpsimp"></a><a name="p2894mcpsimp"></a>value_len</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p2896mcpsimp"><a name="p2896mcpsimp"></a><a name="p2896mcpsimp"></a>0x06</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p2898mcpsimp"><a name="p2898mcpsimp"></a><a name="p2898mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2900mcpsimp"><a name="p2900mcpsimp"></a><a name="p2900mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row2901mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2903mcpsimp"><a name="p2903mcpsimp"></a><a name="p2903mcpsimp"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p2905mcpsimp"><a name="p2905mcpsimp"></a><a name="p2905mcpsimp"></a>0x07</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p2907mcpsimp"><a name="p2907mcpsimp"></a><a name="p2907mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2909mcpsimp"><a name="p2909mcpsimp"></a><a name="p2909mcpsimp"></a>uint8</p>
</td>
</tr>
</tbody>
</table>

### 异步添加SSAP描述<a name="ZH-CN_TOPIC_0000001876269593"></a>

<a name="table2911mcpsimp"></a>
<table><thead align="left"><tr id="row2917mcpsimp"><th class="cellrowborder" valign="top" width="23.200000000000003%" id="mcps1.1.4.1.1"><p id="p2919mcpsimp"><a name="p2919mcpsimp"></a><a name="p2919mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="24.52%" id="mcps1.1.4.1.2"><p id="p2921mcpsimp"><a name="p2921mcpsimp"></a><a name="p2921mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="52.28%" id="mcps1.1.4.1.3"><p id="p2923mcpsimp"><a name="p2923mcpsimp"></a><a name="p2923mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2924mcpsimp"><td class="cellrowborder" valign="top" width="23.200000000000003%" headers="mcps1.1.4.1.1 "><p id="p2926mcpsimp"><a name="p2926mcpsimp"></a><a name="p2926mcpsimp"></a>0x04</p>
</td>
<td class="cellrowborder" valign="top" width="24.52%" headers="mcps1.1.4.1.2 "><p id="p2928mcpsimp"><a name="p2928mcpsimp"></a><a name="p2928mcpsimp"></a>0x05</p>
</td>
<td class="cellrowborder" valign="top" width="52.28%" headers="mcps1.1.4.1.3 "><p id="p2930mcpsimp"><a name="p2930mcpsimp"></a><a name="p2930mcpsimp"></a>异步添加SSAP描述</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

<a name="table2933mcpsimp"></a>
<table><thead align="left"><tr id="row2940mcpsimp"><th class="cellrowborder" valign="top" width="27%" id="mcps1.1.5.1.1"><p id="p2942mcpsimp"><a name="p2942mcpsimp"></a><a name="p2942mcpsimp"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="22%" id="mcps1.1.5.1.2"><p id="p2944mcpsimp"><a name="p2944mcpsimp"></a><a name="p2944mcpsimp"></a>Type(bit0~bit6)</p>
</th>
<th class="cellrowborder" valign="top" width="18%" id="mcps1.1.5.1.3"><p id="p2946mcpsimp"><a name="p2946mcpsimp"></a><a name="p2946mcpsimp"></a>Length Size(Oct)</p>
</th>
<th class="cellrowborder" valign="top" width="33%" id="mcps1.1.5.1.4"><p id="p2949mcpsimp"><a name="p2949mcpsimp"></a><a name="p2949mcpsimp"></a>Value数据类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row2951mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2953mcpsimp"><a name="p2953mcpsimp"></a><a name="p2953mcpsimp"></a>server_id</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p2955mcpsimp"><a name="p2955mcpsimp"></a><a name="p2955mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p2957mcpsimp"><a name="p2957mcpsimp"></a><a name="p2957mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2959mcpsimp"><a name="p2959mcpsimp"></a><a name="p2959mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row2960mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2962mcpsimp"><a name="p2962mcpsimp"></a><a name="p2962mcpsimp"></a>service_handle</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p2964mcpsimp"><a name="p2964mcpsimp"></a><a name="p2964mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p2966mcpsimp"><a name="p2966mcpsimp"></a><a name="p2966mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2968mcpsimp"><a name="p2968mcpsimp"></a><a name="p2968mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row2969mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2971mcpsimp"><a name="p2971mcpsimp"></a><a name="p2971mcpsimp"></a>property_handle</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p2973mcpsimp"><a name="p2973mcpsimp"></a><a name="p2973mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p2975mcpsimp"><a name="p2975mcpsimp"></a><a name="p2975mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2977mcpsimp"><a name="p2977mcpsimp"></a><a name="p2977mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row2978mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2980mcpsimp"><a name="p2980mcpsimp"></a><a name="p2980mcpsimp"></a>len</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p2982mcpsimp"><a name="p2982mcpsimp"></a><a name="p2982mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p2984mcpsimp"><a name="p2984mcpsimp"></a><a name="p2984mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2986mcpsimp"><a name="p2986mcpsimp"></a><a name="p2986mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row2987mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2989mcpsimp"><a name="p2989mcpsimp"></a><a name="p2989mcpsimp"></a>uuid</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p2991mcpsimp"><a name="p2991mcpsimp"></a><a name="p2991mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p2993mcpsimp"><a name="p2993mcpsimp"></a><a name="p2993mcpsimp"></a>16</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p2995mcpsimp"><a name="p2995mcpsimp"></a><a name="p2995mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row2996mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p2998mcpsimp"><a name="p2998mcpsimp"></a><a name="p2998mcpsimp"></a>permissions</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p3000mcpsimp"><a name="p3000mcpsimp"></a><a name="p3000mcpsimp"></a>0x04</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p3002mcpsimp"><a name="p3002mcpsimp"></a><a name="p3002mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3004mcpsimp"><a name="p3004mcpsimp"></a><a name="p3004mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row3005mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3007mcpsimp"><a name="p3007mcpsimp"></a><a name="p3007mcpsimp"></a>operate_indication</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p3009mcpsimp"><a name="p3009mcpsimp"></a><a name="p3009mcpsimp"></a>0x05</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p3011mcpsimp"><a name="p3011mcpsimp"></a><a name="p3011mcpsimp"></a>4</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3013mcpsimp"><a name="p3013mcpsimp"></a><a name="p3013mcpsimp"></a>uint32</p>
</td>
</tr>
<tr id="row3014mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3016mcpsimp"><a name="p3016mcpsimp"></a><a name="p3016mcpsimp"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p3018mcpsimp"><a name="p3018mcpsimp"></a><a name="p3018mcpsimp"></a>0x06</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p3020mcpsimp"><a name="p3020mcpsimp"></a><a name="p3020mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3022mcpsimp"><a name="p3022mcpsimp"></a><a name="p3022mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row3023mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3025mcpsimp"><a name="p3025mcpsimp"></a><a name="p3025mcpsimp"></a>value_len</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p3027mcpsimp"><a name="p3027mcpsimp"></a><a name="p3027mcpsimp"></a>0x07</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p3029mcpsimp"><a name="p3029mcpsimp"></a><a name="p3029mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3031mcpsimp"><a name="p3031mcpsimp"></a><a name="p3031mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row3032mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3034mcpsimp"><a name="p3034mcpsimp"></a><a name="p3034mcpsimp"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p3036mcpsimp"><a name="p3036mcpsimp"></a><a name="p3036mcpsimp"></a>0x08</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p3038mcpsimp"><a name="p3038mcpsimp"></a><a name="p3038mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3040mcpsimp"><a name="p3040mcpsimp"></a><a name="p3040mcpsimp"></a>uint8</p>
</td>
</tr>
</tbody>
</table>

### 同步添加SSAP服务<a name="ZH-CN_TOPIC_0000001829430392"></a>

<a name="table3042mcpsimp"></a>
<table><thead align="left"><tr id="row3048mcpsimp"><th class="cellrowborder" valign="top" width="23.31%" id="mcps1.1.4.1.1"><p id="p3050mcpsimp"><a name="p3050mcpsimp"></a><a name="p3050mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="24.34%" id="mcps1.1.4.1.2"><p id="p3052mcpsimp"><a name="p3052mcpsimp"></a><a name="p3052mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="52.349999999999994%" id="mcps1.1.4.1.3"><p id="p3054mcpsimp"><a name="p3054mcpsimp"></a><a name="p3054mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row3055mcpsimp"><td class="cellrowborder" valign="top" width="23.31%" headers="mcps1.1.4.1.1 "><p id="p3057mcpsimp"><a name="p3057mcpsimp"></a><a name="p3057mcpsimp"></a>0x04</p>
</td>
<td class="cellrowborder" valign="top" width="24.34%" headers="mcps1.1.4.1.2 "><p id="p3059mcpsimp"><a name="p3059mcpsimp"></a><a name="p3059mcpsimp"></a>0x06</p>
</td>
<td class="cellrowborder" valign="top" width="52.349999999999994%" headers="mcps1.1.4.1.3 "><p id="p3061mcpsimp"><a name="p3061mcpsimp"></a><a name="p3061mcpsimp"></a>同步添加SSAP服务</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

<a name="table3064mcpsimp"></a>
<table><thead align="left"><tr id="row3071mcpsimp"><th class="cellrowborder" valign="top" width="27%" id="mcps1.1.5.1.1"><p id="p3073mcpsimp"><a name="p3073mcpsimp"></a><a name="p3073mcpsimp"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="22%" id="mcps1.1.5.1.2"><p id="p3075mcpsimp"><a name="p3075mcpsimp"></a><a name="p3075mcpsimp"></a>Type(bit0~bit6)</p>
</th>
<th class="cellrowborder" valign="top" width="18%" id="mcps1.1.5.1.3"><p id="p3077mcpsimp"><a name="p3077mcpsimp"></a><a name="p3077mcpsimp"></a>Length Size(Oct)</p>
</th>
<th class="cellrowborder" valign="top" width="33%" id="mcps1.1.5.1.4"><p id="p3080mcpsimp"><a name="p3080mcpsimp"></a><a name="p3080mcpsimp"></a>Value数据类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row3082mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3084mcpsimp"><a name="p3084mcpsimp"></a><a name="p3084mcpsimp"></a>server_id</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p3086mcpsimp"><a name="p3086mcpsimp"></a><a name="p3086mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p3088mcpsimp"><a name="p3088mcpsimp"></a><a name="p3088mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3090mcpsimp"><a name="p3090mcpsimp"></a><a name="p3090mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row3091mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3093mcpsimp"><a name="p3093mcpsimp"></a><a name="p3093mcpsimp"></a>len</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p3095mcpsimp"><a name="p3095mcpsimp"></a><a name="p3095mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p3097mcpsimp"><a name="p3097mcpsimp"></a><a name="p3097mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3099mcpsimp"><a name="p3099mcpsimp"></a><a name="p3099mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row3100mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3102mcpsimp"><a name="p3102mcpsimp"></a><a name="p3102mcpsimp"></a>uuid</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p3104mcpsimp"><a name="p3104mcpsimp"></a><a name="p3104mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p3106mcpsimp"><a name="p3106mcpsimp"></a><a name="p3106mcpsimp"></a>16</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3108mcpsimp"><a name="p3108mcpsimp"></a><a name="p3108mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row3109mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3111mcpsimp"><a name="p3111mcpsimp"></a><a name="p3111mcpsimp"></a>is_primary</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p3113mcpsimp"><a name="p3113mcpsimp"></a><a name="p3113mcpsimp"></a>0x04</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p3115mcpsimp"><a name="p3115mcpsimp"></a><a name="p3115mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3117mcpsimp"><a name="p3117mcpsimp"></a><a name="p3117mcpsimp"></a>bool</p>
</td>
</tr>
<tr id="row3118mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3120mcpsimp"><a name="p3120mcpsimp"></a><a name="p3120mcpsimp"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p3122mcpsimp"><a name="p3122mcpsimp"></a><a name="p3122mcpsimp"></a>0x05</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p3124mcpsimp"><a name="p3124mcpsimp"></a><a name="p3124mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3126mcpsimp"><a name="p3126mcpsimp"></a><a name="p3126mcpsimp"></a>uint16</p>
</td>
</tr>
</tbody>
</table>

### 同步添加SSAP属性<a name="ZH-CN_TOPIC_0000001829590152"></a>

<a name="table3128mcpsimp"></a>
<table><thead align="left"><tr id="row3134mcpsimp"><th class="cellrowborder" valign="top" width="23.169999999999998%" id="mcps1.1.4.1.1"><p id="p3136mcpsimp"><a name="p3136mcpsimp"></a><a name="p3136mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="24.18%" id="mcps1.1.4.1.2"><p id="p3138mcpsimp"><a name="p3138mcpsimp"></a><a name="p3138mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="52.65%" id="mcps1.1.4.1.3"><p id="p3140mcpsimp"><a name="p3140mcpsimp"></a><a name="p3140mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row3141mcpsimp"><td class="cellrowborder" valign="top" width="23.169999999999998%" headers="mcps1.1.4.1.1 "><p id="p3143mcpsimp"><a name="p3143mcpsimp"></a><a name="p3143mcpsimp"></a>0x04</p>
</td>
<td class="cellrowborder" valign="top" width="24.18%" headers="mcps1.1.4.1.2 "><p id="p3145mcpsimp"><a name="p3145mcpsimp"></a><a name="p3145mcpsimp"></a>0x07</p>
</td>
<td class="cellrowborder" valign="top" width="52.65%" headers="mcps1.1.4.1.3 "><p id="p3147mcpsimp"><a name="p3147mcpsimp"></a><a name="p3147mcpsimp"></a>同步添加SSAP属性</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

<a name="table3150mcpsimp"></a>
<table><thead align="left"><tr id="row3157mcpsimp"><th class="cellrowborder" valign="top" width="27%" id="mcps1.1.5.1.1"><p id="p3159mcpsimp"><a name="p3159mcpsimp"></a><a name="p3159mcpsimp"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="22%" id="mcps1.1.5.1.2"><p id="p3161mcpsimp"><a name="p3161mcpsimp"></a><a name="p3161mcpsimp"></a>Type(bit0~bit6)</p>
</th>
<th class="cellrowborder" valign="top" width="18%" id="mcps1.1.5.1.3"><p id="p3163mcpsimp"><a name="p3163mcpsimp"></a><a name="p3163mcpsimp"></a>Length Size(Oct)</p>
</th>
<th class="cellrowborder" valign="top" width="33%" id="mcps1.1.5.1.4"><p id="p3166mcpsimp"><a name="p3166mcpsimp"></a><a name="p3166mcpsimp"></a>Value数据类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row3168mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3170mcpsimp"><a name="p3170mcpsimp"></a><a name="p3170mcpsimp"></a>server_id</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p3172mcpsimp"><a name="p3172mcpsimp"></a><a name="p3172mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p3174mcpsimp"><a name="p3174mcpsimp"></a><a name="p3174mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3176mcpsimp"><a name="p3176mcpsimp"></a><a name="p3176mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row3177mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3179mcpsimp"><a name="p3179mcpsimp"></a><a name="p3179mcpsimp"></a>service_handle</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p3181mcpsimp"><a name="p3181mcpsimp"></a><a name="p3181mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p3183mcpsimp"><a name="p3183mcpsimp"></a><a name="p3183mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3185mcpsimp"><a name="p3185mcpsimp"></a><a name="p3185mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row3186mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3188mcpsimp"><a name="p3188mcpsimp"></a><a name="p3188mcpsimp"></a>len</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p3190mcpsimp"><a name="p3190mcpsimp"></a><a name="p3190mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p3192mcpsimp"><a name="p3192mcpsimp"></a><a name="p3192mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3194mcpsimp"><a name="p3194mcpsimp"></a><a name="p3194mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row3195mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3197mcpsimp"><a name="p3197mcpsimp"></a><a name="p3197mcpsimp"></a>uuid</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p3199mcpsimp"><a name="p3199mcpsimp"></a><a name="p3199mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p3201mcpsimp"><a name="p3201mcpsimp"></a><a name="p3201mcpsimp"></a>16</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3203mcpsimp"><a name="p3203mcpsimp"></a><a name="p3203mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row3204mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3206mcpsimp"><a name="p3206mcpsimp"></a><a name="p3206mcpsimp"></a>permissions</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p3208mcpsimp"><a name="p3208mcpsimp"></a><a name="p3208mcpsimp"></a>0x04</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p3210mcpsimp"><a name="p3210mcpsimp"></a><a name="p3210mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3212mcpsimp"><a name="p3212mcpsimp"></a><a name="p3212mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row3213mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3215mcpsimp"><a name="p3215mcpsimp"></a><a name="p3215mcpsimp"></a>operate_indication</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p3217mcpsimp"><a name="p3217mcpsimp"></a><a name="p3217mcpsimp"></a>0x05</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p3219mcpsimp"><a name="p3219mcpsimp"></a><a name="p3219mcpsimp"></a>4</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3221mcpsimp"><a name="p3221mcpsimp"></a><a name="p3221mcpsimp"></a>uint32</p>
</td>
</tr>
<tr id="row3222mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3224mcpsimp"><a name="p3224mcpsimp"></a><a name="p3224mcpsimp"></a>value_len</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p3226mcpsimp"><a name="p3226mcpsimp"></a><a name="p3226mcpsimp"></a>0x06</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p3228mcpsimp"><a name="p3228mcpsimp"></a><a name="p3228mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3230mcpsimp"><a name="p3230mcpsimp"></a><a name="p3230mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row3231mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3233mcpsimp"><a name="p3233mcpsimp"></a><a name="p3233mcpsimp"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p3235mcpsimp"><a name="p3235mcpsimp"></a><a name="p3235mcpsimp"></a>0x07</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p3237mcpsimp"><a name="p3237mcpsimp"></a><a name="p3237mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3239mcpsimp"><a name="p3239mcpsimp"></a><a name="p3239mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row3240mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3242mcpsimp"><a name="p3242mcpsimp"></a><a name="p3242mcpsimp"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p3244mcpsimp"><a name="p3244mcpsimp"></a><a name="p3244mcpsimp"></a>0x05</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p3246mcpsimp"><a name="p3246mcpsimp"></a><a name="p3246mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3248mcpsimp"><a name="p3248mcpsimp"></a><a name="p3248mcpsimp"></a>uint16</p>
</td>
</tr>
</tbody>
</table>

### 同步添加SSAP描述<a name="ZH-CN_TOPIC_0000001876189817"></a>

<a name="table3250mcpsimp"></a>
<table><thead align="left"><tr id="row3256mcpsimp"><th class="cellrowborder" valign="top" width="22.81%" id="mcps1.1.4.1.1"><p id="p3258mcpsimp"><a name="p3258mcpsimp"></a><a name="p3258mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="24.36%" id="mcps1.1.4.1.2"><p id="p3260mcpsimp"><a name="p3260mcpsimp"></a><a name="p3260mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="52.83%" id="mcps1.1.4.1.3"><p id="p3262mcpsimp"><a name="p3262mcpsimp"></a><a name="p3262mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row3263mcpsimp"><td class="cellrowborder" valign="top" width="22.81%" headers="mcps1.1.4.1.1 "><p id="p3265mcpsimp"><a name="p3265mcpsimp"></a><a name="p3265mcpsimp"></a>0x04</p>
</td>
<td class="cellrowborder" valign="top" width="24.36%" headers="mcps1.1.4.1.2 "><p id="p3267mcpsimp"><a name="p3267mcpsimp"></a><a name="p3267mcpsimp"></a>0x08</p>
</td>
<td class="cellrowborder" valign="top" width="52.83%" headers="mcps1.1.4.1.3 "><p id="p3269mcpsimp"><a name="p3269mcpsimp"></a><a name="p3269mcpsimp"></a>同步添加SSAP描述</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

<a name="table3272mcpsimp"></a>
<table><thead align="left"><tr id="row3279mcpsimp"><th class="cellrowborder" valign="top" width="27%" id="mcps1.1.5.1.1"><p id="p3281mcpsimp"><a name="p3281mcpsimp"></a><a name="p3281mcpsimp"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="22%" id="mcps1.1.5.1.2"><p id="p3283mcpsimp"><a name="p3283mcpsimp"></a><a name="p3283mcpsimp"></a>Type(bit0~bit6)</p>
</th>
<th class="cellrowborder" valign="top" width="18%" id="mcps1.1.5.1.3"><p id="p3285mcpsimp"><a name="p3285mcpsimp"></a><a name="p3285mcpsimp"></a>Length Size(Oct)</p>
</th>
<th class="cellrowborder" valign="top" width="33%" id="mcps1.1.5.1.4"><p id="p3288mcpsimp"><a name="p3288mcpsimp"></a><a name="p3288mcpsimp"></a>Value数据类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row3290mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3292mcpsimp"><a name="p3292mcpsimp"></a><a name="p3292mcpsimp"></a>server_id</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p3294mcpsimp"><a name="p3294mcpsimp"></a><a name="p3294mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p3296mcpsimp"><a name="p3296mcpsimp"></a><a name="p3296mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3298mcpsimp"><a name="p3298mcpsimp"></a><a name="p3298mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row3299mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3301mcpsimp"><a name="p3301mcpsimp"></a><a name="p3301mcpsimp"></a>service_handle</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p3303mcpsimp"><a name="p3303mcpsimp"></a><a name="p3303mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p3305mcpsimp"><a name="p3305mcpsimp"></a><a name="p3305mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3307mcpsimp"><a name="p3307mcpsimp"></a><a name="p3307mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row3308mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3310mcpsimp"><a name="p3310mcpsimp"></a><a name="p3310mcpsimp"></a>property_handle</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p3312mcpsimp"><a name="p3312mcpsimp"></a><a name="p3312mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p3314mcpsimp"><a name="p3314mcpsimp"></a><a name="p3314mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3316mcpsimp"><a name="p3316mcpsimp"></a><a name="p3316mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row3317mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3319mcpsimp"><a name="p3319mcpsimp"></a><a name="p3319mcpsimp"></a>len</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p3321mcpsimp"><a name="p3321mcpsimp"></a><a name="p3321mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p3323mcpsimp"><a name="p3323mcpsimp"></a><a name="p3323mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3325mcpsimp"><a name="p3325mcpsimp"></a><a name="p3325mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row3326mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3328mcpsimp"><a name="p3328mcpsimp"></a><a name="p3328mcpsimp"></a>uuid</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p3330mcpsimp"><a name="p3330mcpsimp"></a><a name="p3330mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p3332mcpsimp"><a name="p3332mcpsimp"></a><a name="p3332mcpsimp"></a>16</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3334mcpsimp"><a name="p3334mcpsimp"></a><a name="p3334mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row3335mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3337mcpsimp"><a name="p3337mcpsimp"></a><a name="p3337mcpsimp"></a>permissions</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p3339mcpsimp"><a name="p3339mcpsimp"></a><a name="p3339mcpsimp"></a>0x04</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p3341mcpsimp"><a name="p3341mcpsimp"></a><a name="p3341mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3343mcpsimp"><a name="p3343mcpsimp"></a><a name="p3343mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row3344mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3346mcpsimp"><a name="p3346mcpsimp"></a><a name="p3346mcpsimp"></a>operate_indication</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p3348mcpsimp"><a name="p3348mcpsimp"></a><a name="p3348mcpsimp"></a>0x05</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p3350mcpsimp"><a name="p3350mcpsimp"></a><a name="p3350mcpsimp"></a>4</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3352mcpsimp"><a name="p3352mcpsimp"></a><a name="p3352mcpsimp"></a>uint32</p>
</td>
</tr>
<tr id="row3353mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3355mcpsimp"><a name="p3355mcpsimp"></a><a name="p3355mcpsimp"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p3357mcpsimp"><a name="p3357mcpsimp"></a><a name="p3357mcpsimp"></a>0x06</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p3359mcpsimp"><a name="p3359mcpsimp"></a><a name="p3359mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3361mcpsimp"><a name="p3361mcpsimp"></a><a name="p3361mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row3362mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3364mcpsimp"><a name="p3364mcpsimp"></a><a name="p3364mcpsimp"></a>value_len</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p3366mcpsimp"><a name="p3366mcpsimp"></a><a name="p3366mcpsimp"></a>0x07</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p3368mcpsimp"><a name="p3368mcpsimp"></a><a name="p3368mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3370mcpsimp"><a name="p3370mcpsimp"></a><a name="p3370mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row3371mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3373mcpsimp"><a name="p3373mcpsimp"></a><a name="p3373mcpsimp"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p3375mcpsimp"><a name="p3375mcpsimp"></a><a name="p3375mcpsimp"></a>0x08</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p3377mcpsimp"><a name="p3377mcpsimp"></a><a name="p3377mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3379mcpsimp"><a name="p3379mcpsimp"></a><a name="p3379mcpsimp"></a>uint8</p>
</td>
</tr>
</tbody>
</table>

### 开始SSAP服务<a name="ZH-CN_TOPIC_0000001876269597"></a>

<a name="table3381mcpsimp"></a>
<table><thead align="left"><tr id="row3387mcpsimp"><th class="cellrowborder" valign="top" width="22.82%" id="mcps1.1.4.1.1"><p id="p3389mcpsimp"><a name="p3389mcpsimp"></a><a name="p3389mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="24.6%" id="mcps1.1.4.1.2"><p id="p3391mcpsimp"><a name="p3391mcpsimp"></a><a name="p3391mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="52.580000000000005%" id="mcps1.1.4.1.3"><p id="p3393mcpsimp"><a name="p3393mcpsimp"></a><a name="p3393mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row3394mcpsimp"><td class="cellrowborder" valign="top" width="22.82%" headers="mcps1.1.4.1.1 "><p id="p3396mcpsimp"><a name="p3396mcpsimp"></a><a name="p3396mcpsimp"></a>0x04</p>
</td>
<td class="cellrowborder" valign="top" width="24.6%" headers="mcps1.1.4.1.2 "><p id="p3398mcpsimp"><a name="p3398mcpsimp"></a><a name="p3398mcpsimp"></a>0x09</p>
</td>
<td class="cellrowborder" valign="top" width="52.580000000000005%" headers="mcps1.1.4.1.3 "><p id="p3400mcpsimp"><a name="p3400mcpsimp"></a><a name="p3400mcpsimp"></a>开始SSAP服务</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

<a name="table3403mcpsimp"></a>
<table><thead align="left"><tr id="row3410mcpsimp"><th class="cellrowborder" valign="top" width="27%" id="mcps1.1.5.1.1"><p id="p3412mcpsimp"><a name="p3412mcpsimp"></a><a name="p3412mcpsimp"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="21.98%" id="mcps1.1.5.1.2"><p id="p3414mcpsimp"><a name="p3414mcpsimp"></a><a name="p3414mcpsimp"></a>Type(bit0~bit6)</p>
</th>
<th class="cellrowborder" valign="top" width="18.02%" id="mcps1.1.5.1.3"><p id="p3416mcpsimp"><a name="p3416mcpsimp"></a><a name="p3416mcpsimp"></a>Length Size(Oct)</p>
</th>
<th class="cellrowborder" valign="top" width="33%" id="mcps1.1.5.1.4"><p id="p3419mcpsimp"><a name="p3419mcpsimp"></a><a name="p3419mcpsimp"></a>Value数据类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row3421mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3423mcpsimp"><a name="p3423mcpsimp"></a><a name="p3423mcpsimp"></a>server_id</p>
</td>
<td class="cellrowborder" valign="top" width="21.98%" headers="mcps1.1.5.1.2 "><p id="p3425mcpsimp"><a name="p3425mcpsimp"></a><a name="p3425mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="18.02%" headers="mcps1.1.5.1.3 "><p id="p3427mcpsimp"><a name="p3427mcpsimp"></a><a name="p3427mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3429mcpsimp"><a name="p3429mcpsimp"></a><a name="p3429mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row3430mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3432mcpsimp"><a name="p3432mcpsimp"></a><a name="p3432mcpsimp"></a>service_handle</p>
</td>
<td class="cellrowborder" valign="top" width="21.98%" headers="mcps1.1.5.1.2 "><p id="p3434mcpsimp"><a name="p3434mcpsimp"></a><a name="p3434mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="18.02%" headers="mcps1.1.5.1.3 "><p id="p3436mcpsimp"><a name="p3436mcpsimp"></a><a name="p3436mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3438mcpsimp"><a name="p3438mcpsimp"></a><a name="p3438mcpsimp"></a>uint16</p>
</td>
</tr>
</tbody>
</table>

### 删除所有SSAP服务<a name="ZH-CN_TOPIC_0000001829430396"></a>

<a name="table3440mcpsimp"></a>
<table><thead align="left"><tr id="row3446mcpsimp"><th class="cellrowborder" valign="top" width="22.81%" id="mcps1.1.4.1.1"><p id="p3448mcpsimp"><a name="p3448mcpsimp"></a><a name="p3448mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="24.67%" id="mcps1.1.4.1.2"><p id="p3450mcpsimp"><a name="p3450mcpsimp"></a><a name="p3450mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="52.52%" id="mcps1.1.4.1.3"><p id="p3452mcpsimp"><a name="p3452mcpsimp"></a><a name="p3452mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row3453mcpsimp"><td class="cellrowborder" valign="top" width="22.81%" headers="mcps1.1.4.1.1 "><p id="p3455mcpsimp"><a name="p3455mcpsimp"></a><a name="p3455mcpsimp"></a>0x04</p>
</td>
<td class="cellrowborder" valign="top" width="24.67%" headers="mcps1.1.4.1.2 "><p id="p3457mcpsimp"><a name="p3457mcpsimp"></a><a name="p3457mcpsimp"></a>0x0A</p>
</td>
<td class="cellrowborder" valign="top" width="52.52%" headers="mcps1.1.4.1.3 "><p id="p3459mcpsimp"><a name="p3459mcpsimp"></a><a name="p3459mcpsimp"></a>删除所有SSAP服务</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

<a name="table3462mcpsimp"></a>
<table><thead align="left"><tr id="row3469mcpsimp"><th class="cellrowborder" valign="top" width="27%" id="mcps1.1.5.1.1"><p id="p3471mcpsimp"><a name="p3471mcpsimp"></a><a name="p3471mcpsimp"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="21.98%" id="mcps1.1.5.1.2"><p id="p3473mcpsimp"><a name="p3473mcpsimp"></a><a name="p3473mcpsimp"></a>Type(bit0~bit6)</p>
</th>
<th class="cellrowborder" valign="top" width="18.02%" id="mcps1.1.5.1.3"><p id="p3475mcpsimp"><a name="p3475mcpsimp"></a><a name="p3475mcpsimp"></a>Length Size(Oct)</p>
</th>
<th class="cellrowborder" valign="top" width="33%" id="mcps1.1.5.1.4"><p id="p3478mcpsimp"><a name="p3478mcpsimp"></a><a name="p3478mcpsimp"></a>Value数据类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row3480mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3482mcpsimp"><a name="p3482mcpsimp"></a><a name="p3482mcpsimp"></a>server_id</p>
</td>
<td class="cellrowborder" valign="top" width="21.98%" headers="mcps1.1.5.1.2 "><p id="p3484mcpsimp"><a name="p3484mcpsimp"></a><a name="p3484mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="18.02%" headers="mcps1.1.5.1.3 "><p id="p3486mcpsimp"><a name="p3486mcpsimp"></a><a name="p3486mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3488mcpsimp"><a name="p3488mcpsimp"></a><a name="p3488mcpsimp"></a>uint8</p>
</td>
</tr>
</tbody>
</table>

### 发送SSAP响应<a name="ZH-CN_TOPIC_0000001829590156"></a>

<a name="table3490mcpsimp"></a>
<table><thead align="left"><tr id="row3496mcpsimp"><th class="cellrowborder" valign="top" width="22.91%" id="mcps1.1.4.1.1"><p id="p3498mcpsimp"><a name="p3498mcpsimp"></a><a name="p3498mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="24.41%" id="mcps1.1.4.1.2"><p id="p3500mcpsimp"><a name="p3500mcpsimp"></a><a name="p3500mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="52.68000000000001%" id="mcps1.1.4.1.3"><p id="p3502mcpsimp"><a name="p3502mcpsimp"></a><a name="p3502mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row3503mcpsimp"><td class="cellrowborder" valign="top" width="22.91%" headers="mcps1.1.4.1.1 "><p id="p3505mcpsimp"><a name="p3505mcpsimp"></a><a name="p3505mcpsimp"></a>0x04</p>
</td>
<td class="cellrowborder" valign="top" width="24.41%" headers="mcps1.1.4.1.2 "><p id="p3507mcpsimp"><a name="p3507mcpsimp"></a><a name="p3507mcpsimp"></a>0x0B</p>
</td>
<td class="cellrowborder" valign="top" width="52.68000000000001%" headers="mcps1.1.4.1.3 "><p id="p3509mcpsimp"><a name="p3509mcpsimp"></a><a name="p3509mcpsimp"></a>发送SSAP响应</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

<a name="table3512mcpsimp"></a>
<table><thead align="left"><tr id="row3519mcpsimp"><th class="cellrowborder" valign="top" width="27%" id="mcps1.1.5.1.1"><p id="p3521mcpsimp"><a name="p3521mcpsimp"></a><a name="p3521mcpsimp"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="21.98%" id="mcps1.1.5.1.2"><p id="p3523mcpsimp"><a name="p3523mcpsimp"></a><a name="p3523mcpsimp"></a>Type(bit0~bit6)</p>
</th>
<th class="cellrowborder" valign="top" width="18.02%" id="mcps1.1.5.1.3"><p id="p3525mcpsimp"><a name="p3525mcpsimp"></a><a name="p3525mcpsimp"></a>Length Size(Oct)</p>
</th>
<th class="cellrowborder" valign="top" width="33%" id="mcps1.1.5.1.4"><p id="p3528mcpsimp"><a name="p3528mcpsimp"></a><a name="p3528mcpsimp"></a>Value数据类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row3530mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3532mcpsimp"><a name="p3532mcpsimp"></a><a name="p3532mcpsimp"></a>server_id</p>
</td>
<td class="cellrowborder" valign="top" width="21.98%" headers="mcps1.1.5.1.2 "><p id="p3534mcpsimp"><a name="p3534mcpsimp"></a><a name="p3534mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="18.02%" headers="mcps1.1.5.1.3 "><p id="p3536mcpsimp"><a name="p3536mcpsimp"></a><a name="p3536mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3538mcpsimp"><a name="p3538mcpsimp"></a><a name="p3538mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row3539mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3541mcpsimp"><a name="p3541mcpsimp"></a><a name="p3541mcpsimp"></a>conn_id</p>
</td>
<td class="cellrowborder" valign="top" width="21.98%" headers="mcps1.1.5.1.2 "><p id="p3543mcpsimp"><a name="p3543mcpsimp"></a><a name="p3543mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="18.02%" headers="mcps1.1.5.1.3 "><p id="p3545mcpsimp"><a name="p3545mcpsimp"></a><a name="p3545mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3547mcpsimp"><a name="p3547mcpsimp"></a><a name="p3547mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row3548mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3550mcpsimp"><a name="p3550mcpsimp"></a><a name="p3550mcpsimp"></a>request_id</p>
</td>
<td class="cellrowborder" valign="top" width="21.98%" headers="mcps1.1.5.1.2 "><p id="p3552mcpsimp"><a name="p3552mcpsimp"></a><a name="p3552mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="18.02%" headers="mcps1.1.5.1.3 "><p id="p3554mcpsimp"><a name="p3554mcpsimp"></a><a name="p3554mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3556mcpsimp"><a name="p3556mcpsimp"></a><a name="p3556mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row3557mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3559mcpsimp"><a name="p3559mcpsimp"></a><a name="p3559mcpsimp"></a>status</p>
</td>
<td class="cellrowborder" valign="top" width="21.98%" headers="mcps1.1.5.1.2 "><p id="p3561mcpsimp"><a name="p3561mcpsimp"></a><a name="p3561mcpsimp"></a>0x04</p>
</td>
<td class="cellrowborder" valign="top" width="18.02%" headers="mcps1.1.5.1.3 "><p id="p3563mcpsimp"><a name="p3563mcpsimp"></a><a name="p3563mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3565mcpsimp"><a name="p3565mcpsimp"></a><a name="p3565mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row3566mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3568mcpsimp"><a name="p3568mcpsimp"></a><a name="p3568mcpsimp"></a>value_len</p>
</td>
<td class="cellrowborder" valign="top" width="21.98%" headers="mcps1.1.5.1.2 "><p id="p3570mcpsimp"><a name="p3570mcpsimp"></a><a name="p3570mcpsimp"></a>0x05</p>
</td>
<td class="cellrowborder" valign="top" width="18.02%" headers="mcps1.1.5.1.3 "><p id="p3572mcpsimp"><a name="p3572mcpsimp"></a><a name="p3572mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3574mcpsimp"><a name="p3574mcpsimp"></a><a name="p3574mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row3575mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3577mcpsimp"><a name="p3577mcpsimp"></a><a name="p3577mcpsimp"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="21.98%" headers="mcps1.1.5.1.2 "><p id="p3579mcpsimp"><a name="p3579mcpsimp"></a><a name="p3579mcpsimp"></a>0x06</p>
</td>
<td class="cellrowborder" valign="top" width="18.02%" headers="mcps1.1.5.1.3 "><p id="p3581mcpsimp"><a name="p3581mcpsimp"></a><a name="p3581mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3583mcpsimp"><a name="p3583mcpsimp"></a><a name="p3583mcpsimp"></a>uint8</p>
</td>
</tr>
</tbody>
</table>

### 发送通知或指示<a name="ZH-CN_TOPIC_0000001876189821"></a>

<a name="table3585mcpsimp"></a>
<table><thead align="left"><tr id="row3591mcpsimp"><th class="cellrowborder" valign="top" width="22.900000000000002%" id="mcps1.1.4.1.1"><p id="p3593mcpsimp"><a name="p3593mcpsimp"></a><a name="p3593mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="24.6%" id="mcps1.1.4.1.2"><p id="p3595mcpsimp"><a name="p3595mcpsimp"></a><a name="p3595mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="52.5%" id="mcps1.1.4.1.3"><p id="p3597mcpsimp"><a name="p3597mcpsimp"></a><a name="p3597mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row3598mcpsimp"><td class="cellrowborder" valign="top" width="22.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p3600mcpsimp"><a name="p3600mcpsimp"></a><a name="p3600mcpsimp"></a>0x04</p>
</td>
<td class="cellrowborder" valign="top" width="24.6%" headers="mcps1.1.4.1.2 "><p id="p3602mcpsimp"><a name="p3602mcpsimp"></a><a name="p3602mcpsimp"></a>0x0C</p>
</td>
<td class="cellrowborder" valign="top" width="52.5%" headers="mcps1.1.4.1.3 "><p id="p3604mcpsimp"><a name="p3604mcpsimp"></a><a name="p3604mcpsimp"></a>发送通知或指示</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

<a name="table3607mcpsimp"></a>
<table><thead align="left"><tr id="row3614mcpsimp"><th class="cellrowborder" valign="top" width="27%" id="mcps1.1.5.1.1"><p id="p3616mcpsimp"><a name="p3616mcpsimp"></a><a name="p3616mcpsimp"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="21.98%" id="mcps1.1.5.1.2"><p id="p3618mcpsimp"><a name="p3618mcpsimp"></a><a name="p3618mcpsimp"></a>Type(bit0~bit6)</p>
</th>
<th class="cellrowborder" valign="top" width="18.02%" id="mcps1.1.5.1.3"><p id="p3620mcpsimp"><a name="p3620mcpsimp"></a><a name="p3620mcpsimp"></a>Length Size(Oct)</p>
</th>
<th class="cellrowborder" valign="top" width="33%" id="mcps1.1.5.1.4"><p id="p3623mcpsimp"><a name="p3623mcpsimp"></a><a name="p3623mcpsimp"></a>Value数据类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row3625mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3627mcpsimp"><a name="p3627mcpsimp"></a><a name="p3627mcpsimp"></a>server_id</p>
</td>
<td class="cellrowborder" valign="top" width="21.98%" headers="mcps1.1.5.1.2 "><p id="p3629mcpsimp"><a name="p3629mcpsimp"></a><a name="p3629mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="18.02%" headers="mcps1.1.5.1.3 "><p id="p3631mcpsimp"><a name="p3631mcpsimp"></a><a name="p3631mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3633mcpsimp"><a name="p3633mcpsimp"></a><a name="p3633mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row3634mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3636mcpsimp"><a name="p3636mcpsimp"></a><a name="p3636mcpsimp"></a>conn_id</p>
</td>
<td class="cellrowborder" valign="top" width="21.98%" headers="mcps1.1.5.1.2 "><p id="p3638mcpsimp"><a name="p3638mcpsimp"></a><a name="p3638mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="18.02%" headers="mcps1.1.5.1.3 "><p id="p3640mcpsimp"><a name="p3640mcpsimp"></a><a name="p3640mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3642mcpsimp"><a name="p3642mcpsimp"></a><a name="p3642mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row3643mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3645mcpsimp"><a name="p3645mcpsimp"></a><a name="p3645mcpsimp"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="21.98%" headers="mcps1.1.5.1.2 "><p id="p3647mcpsimp"><a name="p3647mcpsimp"></a><a name="p3647mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="18.02%" headers="mcps1.1.5.1.3 "><p id="p3649mcpsimp"><a name="p3649mcpsimp"></a><a name="p3649mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3651mcpsimp"><a name="p3651mcpsimp"></a><a name="p3651mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row3652mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3654mcpsimp"><a name="p3654mcpsimp"></a><a name="p3654mcpsimp"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="21.98%" headers="mcps1.1.5.1.2 "><p id="p3656mcpsimp"><a name="p3656mcpsimp"></a><a name="p3656mcpsimp"></a>0x04</p>
</td>
<td class="cellrowborder" valign="top" width="18.02%" headers="mcps1.1.5.1.3 "><p id="p3658mcpsimp"><a name="p3658mcpsimp"></a><a name="p3658mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3660mcpsimp"><a name="p3660mcpsimp"></a><a name="p3660mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row3661mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3663mcpsimp"><a name="p3663mcpsimp"></a><a name="p3663mcpsimp"></a>value_len</p>
</td>
<td class="cellrowborder" valign="top" width="21.98%" headers="mcps1.1.5.1.2 "><p id="p3665mcpsimp"><a name="p3665mcpsimp"></a><a name="p3665mcpsimp"></a>0x05</p>
</td>
<td class="cellrowborder" valign="top" width="18.02%" headers="mcps1.1.5.1.3 "><p id="p3667mcpsimp"><a name="p3667mcpsimp"></a><a name="p3667mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3669mcpsimp"><a name="p3669mcpsimp"></a><a name="p3669mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row3670mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3672mcpsimp"><a name="p3672mcpsimp"></a><a name="p3672mcpsimp"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="21.98%" headers="mcps1.1.5.1.2 "><p id="p3674mcpsimp"><a name="p3674mcpsimp"></a><a name="p3674mcpsimp"></a>0x06</p>
</td>
<td class="cellrowborder" valign="top" width="18.02%" headers="mcps1.1.5.1.3 "><p id="p3676mcpsimp"><a name="p3676mcpsimp"></a><a name="p3676mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3678mcpsimp"><a name="p3678mcpsimp"></a><a name="p3678mcpsimp"></a>uint8</p>
</td>
</tr>
</tbody>
</table>

### 通过UUID发送通知或指示<a name="ZH-CN_TOPIC_0000001876269601"></a>

<a name="table3680mcpsimp"></a>
<table><thead align="left"><tr id="row3686mcpsimp"><th class="cellrowborder" valign="top" width="22.55%" id="mcps1.1.4.1.1"><p id="p3688mcpsimp"><a name="p3688mcpsimp"></a><a name="p3688mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="24.88%" id="mcps1.1.4.1.2"><p id="p3690mcpsimp"><a name="p3690mcpsimp"></a><a name="p3690mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="52.56999999999999%" id="mcps1.1.4.1.3"><p id="p3692mcpsimp"><a name="p3692mcpsimp"></a><a name="p3692mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row3693mcpsimp"><td class="cellrowborder" valign="top" width="22.55%" headers="mcps1.1.4.1.1 "><p id="p3695mcpsimp"><a name="p3695mcpsimp"></a><a name="p3695mcpsimp"></a>0x04</p>
</td>
<td class="cellrowborder" valign="top" width="24.88%" headers="mcps1.1.4.1.2 "><p id="p3697mcpsimp"><a name="p3697mcpsimp"></a><a name="p3697mcpsimp"></a>0x0D</p>
</td>
<td class="cellrowborder" valign="top" width="52.56999999999999%" headers="mcps1.1.4.1.3 "><p id="p3699mcpsimp"><a name="p3699mcpsimp"></a><a name="p3699mcpsimp"></a>通过UUID发送通知或指示</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

<a name="table3702mcpsimp"></a>
<table><thead align="left"><tr id="row3709mcpsimp"><th class="cellrowborder" valign="top" width="27%" id="mcps1.1.5.1.1"><p id="p3711mcpsimp"><a name="p3711mcpsimp"></a><a name="p3711mcpsimp"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="22%" id="mcps1.1.5.1.2"><p id="p3713mcpsimp"><a name="p3713mcpsimp"></a><a name="p3713mcpsimp"></a>Type(bit0~bit6)</p>
</th>
<th class="cellrowborder" valign="top" width="18%" id="mcps1.1.5.1.3"><p id="p3715mcpsimp"><a name="p3715mcpsimp"></a><a name="p3715mcpsimp"></a>Length Size(Oct)</p>
</th>
<th class="cellrowborder" valign="top" width="33%" id="mcps1.1.5.1.4"><p id="p3718mcpsimp"><a name="p3718mcpsimp"></a><a name="p3718mcpsimp"></a>Value数据类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row3720mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3722mcpsimp"><a name="p3722mcpsimp"></a><a name="p3722mcpsimp"></a>server_id</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p3724mcpsimp"><a name="p3724mcpsimp"></a><a name="p3724mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p3726mcpsimp"><a name="p3726mcpsimp"></a><a name="p3726mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3728mcpsimp"><a name="p3728mcpsimp"></a><a name="p3728mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row3729mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3731mcpsimp"><a name="p3731mcpsimp"></a><a name="p3731mcpsimp"></a>conn_id</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p3733mcpsimp"><a name="p3733mcpsimp"></a><a name="p3733mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p3735mcpsimp"><a name="p3735mcpsimp"></a><a name="p3735mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3737mcpsimp"><a name="p3737mcpsimp"></a><a name="p3737mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row3738mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3740mcpsimp"><a name="p3740mcpsimp"></a><a name="p3740mcpsimp"></a>len</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p3742mcpsimp"><a name="p3742mcpsimp"></a><a name="p3742mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p3744mcpsimp"><a name="p3744mcpsimp"></a><a name="p3744mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3746mcpsimp"><a name="p3746mcpsimp"></a><a name="p3746mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row3747mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3749mcpsimp"><a name="p3749mcpsimp"></a><a name="p3749mcpsimp"></a>uuid</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p3751mcpsimp"><a name="p3751mcpsimp"></a><a name="p3751mcpsimp"></a>0x04</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p3753mcpsimp"><a name="p3753mcpsimp"></a><a name="p3753mcpsimp"></a>16</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3755mcpsimp"><a name="p3755mcpsimp"></a><a name="p3755mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row3756mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3758mcpsimp"><a name="p3758mcpsimp"></a><a name="p3758mcpsimp"></a>start_handle</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p3760mcpsimp"><a name="p3760mcpsimp"></a><a name="p3760mcpsimp"></a>0x05</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p3762mcpsimp"><a name="p3762mcpsimp"></a><a name="p3762mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3764mcpsimp"><a name="p3764mcpsimp"></a><a name="p3764mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row3765mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3767mcpsimp"><a name="p3767mcpsimp"></a><a name="p3767mcpsimp"></a>end_handle</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p3769mcpsimp"><a name="p3769mcpsimp"></a><a name="p3769mcpsimp"></a>0x06</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p3771mcpsimp"><a name="p3771mcpsimp"></a><a name="p3771mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3773mcpsimp"><a name="p3773mcpsimp"></a><a name="p3773mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row3774mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3776mcpsimp"><a name="p3776mcpsimp"></a><a name="p3776mcpsimp"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p3778mcpsimp"><a name="p3778mcpsimp"></a><a name="p3778mcpsimp"></a>0x07</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p3780mcpsimp"><a name="p3780mcpsimp"></a><a name="p3780mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3782mcpsimp"><a name="p3782mcpsimp"></a><a name="p3782mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row3783mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3785mcpsimp"><a name="p3785mcpsimp"></a><a name="p3785mcpsimp"></a>value_len</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p3787mcpsimp"><a name="p3787mcpsimp"></a><a name="p3787mcpsimp"></a>0x08</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p3789mcpsimp"><a name="p3789mcpsimp"></a><a name="p3789mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3791mcpsimp"><a name="p3791mcpsimp"></a><a name="p3791mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row3792mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3794mcpsimp"><a name="p3794mcpsimp"></a><a name="p3794mcpsimp"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p3796mcpsimp"><a name="p3796mcpsimp"></a><a name="p3796mcpsimp"></a>0x09</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p3798mcpsimp"><a name="p3798mcpsimp"></a><a name="p3798mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3800mcpsimp"><a name="p3800mcpsimp"></a><a name="p3800mcpsimp"></a>uint8</p>
</td>
</tr>
</tbody>
</table>

### 设置服务端info<a name="ZH-CN_TOPIC_0000001829430400"></a>

<a name="table3802mcpsimp"></a>
<table><thead align="left"><tr id="row3808mcpsimp"><th class="cellrowborder" valign="top" width="22.38%" id="mcps1.1.4.1.1"><p id="p3810mcpsimp"><a name="p3810mcpsimp"></a><a name="p3810mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="25.169999999999998%" id="mcps1.1.4.1.2"><p id="p3812mcpsimp"><a name="p3812mcpsimp"></a><a name="p3812mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="52.449999999999996%" id="mcps1.1.4.1.3"><p id="p3814mcpsimp"><a name="p3814mcpsimp"></a><a name="p3814mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row3815mcpsimp"><td class="cellrowborder" valign="top" width="22.38%" headers="mcps1.1.4.1.1 "><p id="p3817mcpsimp"><a name="p3817mcpsimp"></a><a name="p3817mcpsimp"></a>0x04</p>
</td>
<td class="cellrowborder" valign="top" width="25.169999999999998%" headers="mcps1.1.4.1.2 "><p id="p3819mcpsimp"><a name="p3819mcpsimp"></a><a name="p3819mcpsimp"></a>0x0E</p>
</td>
<td class="cellrowborder" valign="top" width="52.449999999999996%" headers="mcps1.1.4.1.3 "><p id="p3821mcpsimp"><a name="p3821mcpsimp"></a><a name="p3821mcpsimp"></a>设置服务端info</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

<a name="table3824mcpsimp"></a>
<table><thead align="left"><tr id="row3831mcpsimp"><th class="cellrowborder" valign="top" width="27%" id="mcps1.1.5.1.1"><p id="p3833mcpsimp"><a name="p3833mcpsimp"></a><a name="p3833mcpsimp"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="22%" id="mcps1.1.5.1.2"><p id="p3835mcpsimp"><a name="p3835mcpsimp"></a><a name="p3835mcpsimp"></a>Type(bit0~bit6)</p>
</th>
<th class="cellrowborder" valign="top" width="18%" id="mcps1.1.5.1.3"><p id="p3837mcpsimp"><a name="p3837mcpsimp"></a><a name="p3837mcpsimp"></a>Length Size(Oct)</p>
</th>
<th class="cellrowborder" valign="top" width="33%" id="mcps1.1.5.1.4"><p id="p3840mcpsimp"><a name="p3840mcpsimp"></a><a name="p3840mcpsimp"></a>Value数据类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row3842mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3844mcpsimp"><a name="p3844mcpsimp"></a><a name="p3844mcpsimp"></a>server_id</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p3846mcpsimp"><a name="p3846mcpsimp"></a><a name="p3846mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p3848mcpsimp"><a name="p3848mcpsimp"></a><a name="p3848mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3850mcpsimp"><a name="p3850mcpsimp"></a><a name="p3850mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row3851mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3853mcpsimp"><a name="p3853mcpsimp"></a><a name="p3853mcpsimp"></a>mtu_size</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p3855mcpsimp"><a name="p3855mcpsimp"></a><a name="p3855mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p3857mcpsimp"><a name="p3857mcpsimp"></a><a name="p3857mcpsimp"></a>4</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3859mcpsimp"><a name="p3859mcpsimp"></a><a name="p3859mcpsimp"></a>uint32</p>
</td>
</tr>
<tr id="row3860mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3862mcpsimp"><a name="p3862mcpsimp"></a><a name="p3862mcpsimp"></a>version</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p3864mcpsimp"><a name="p3864mcpsimp"></a><a name="p3864mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p3866mcpsimp"><a name="p3866mcpsimp"></a><a name="p3866mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3868mcpsimp"><a name="p3868mcpsimp"></a><a name="p3868mcpsimp"></a>uint16</p>
</td>
</tr>
</tbody>
</table>

## Factory Test Service<a name="ZH-CN_TOPIC_0000001829590160"></a>






### 打开射频发送<a name="ZH-CN_TOPIC_0000001876189825"></a>

<a name="table3871mcpsimp"></a>
<table><thead align="left"><tr id="row3877mcpsimp"><th class="cellrowborder" valign="top" width="22.38%" id="mcps1.1.4.1.1"><p id="p3879mcpsimp"><a name="p3879mcpsimp"></a><a name="p3879mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="25.16%" id="mcps1.1.4.1.2"><p id="p3881mcpsimp"><a name="p3881mcpsimp"></a><a name="p3881mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="52.459999999999994%" id="mcps1.1.4.1.3"><p id="p3883mcpsimp"><a name="p3883mcpsimp"></a><a name="p3883mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row3884mcpsimp"><td class="cellrowborder" valign="top" width="22.38%" headers="mcps1.1.4.1.1 "><p id="p3886mcpsimp"><a name="p3886mcpsimp"></a><a name="p3886mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="25.16%" headers="mcps1.1.4.1.2 "><p id="p3888mcpsimp"><a name="p3888mcpsimp"></a><a name="p3888mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="52.459999999999994%" headers="mcps1.1.4.1.3 "><p id="p3890mcpsimp"><a name="p3890mcpsimp"></a><a name="p3890mcpsimp"></a>打开射频发送</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

<a name="table3893mcpsimp"></a>
<table><thead align="left"><tr id="row3900mcpsimp"><th class="cellrowborder" valign="top" width="27%" id="mcps1.1.5.1.1"><p id="p3902mcpsimp"><a name="p3902mcpsimp"></a><a name="p3902mcpsimp"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="22%" id="mcps1.1.5.1.2"><p id="p3904mcpsimp"><a name="p3904mcpsimp"></a><a name="p3904mcpsimp"></a>Type(bit0~bit6)</p>
</th>
<th class="cellrowborder" valign="top" width="18%" id="mcps1.1.5.1.3"><p id="p3906mcpsimp"><a name="p3906mcpsimp"></a><a name="p3906mcpsimp"></a>Length Size(Oct)</p>
</th>
<th class="cellrowborder" valign="top" width="33%" id="mcps1.1.5.1.4"><p id="p3909mcpsimp"><a name="p3909mcpsimp"></a><a name="p3909mcpsimp"></a>Value数据类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row3911mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3913mcpsimp"><a name="p3913mcpsimp"></a><a name="p3913mcpsimp"></a>tx_freq</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p3915mcpsimp"><a name="p3915mcpsimp"></a><a name="p3915mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p3917mcpsimp"><a name="p3917mcpsimp"></a><a name="p3917mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3919mcpsimp"><a name="p3919mcpsimp"></a><a name="p3919mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row3920mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3922mcpsimp"><a name="p3922mcpsimp"></a><a name="p3922mcpsimp"></a>tx_power</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p3924mcpsimp"><a name="p3924mcpsimp"></a><a name="p3924mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p3926mcpsimp"><a name="p3926mcpsimp"></a><a name="p3926mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3928mcpsimp"><a name="p3928mcpsimp"></a><a name="p3928mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row3929mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3931mcpsimp"><a name="p3931mcpsimp"></a><a name="p3931mcpsimp"></a>test_data_len</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p3933mcpsimp"><a name="p3933mcpsimp"></a><a name="p3933mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p3935mcpsimp"><a name="p3935mcpsimp"></a><a name="p3935mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3937mcpsimp"><a name="p3937mcpsimp"></a><a name="p3937mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row3938mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3940mcpsimp"><a name="p3940mcpsimp"></a><a name="p3940mcpsimp"></a>pk_payload_type</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p3942mcpsimp"><a name="p3942mcpsimp"></a><a name="p3942mcpsimp"></a>0x04</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p3944mcpsimp"><a name="p3944mcpsimp"></a><a name="p3944mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3946mcpsimp"><a name="p3946mcpsimp"></a><a name="p3946mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row3947mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3949mcpsimp"><a name="p3949mcpsimp"></a><a name="p3949mcpsimp"></a>tx_phy</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p3951mcpsimp"><a name="p3951mcpsimp"></a><a name="p3951mcpsimp"></a>0x05</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p3953mcpsimp"><a name="p3953mcpsimp"></a><a name="p3953mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3955mcpsimp"><a name="p3955mcpsimp"></a><a name="p3955mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row3956mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3958mcpsimp"><a name="p3958mcpsimp"></a><a name="p3958mcpsimp"></a>tx_format</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p3960mcpsimp"><a name="p3960mcpsimp"></a><a name="p3960mcpsimp"></a>0x06</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p3962mcpsimp"><a name="p3962mcpsimp"></a><a name="p3962mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3964mcpsimp"><a name="p3964mcpsimp"></a><a name="p3964mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row3965mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3967mcpsimp"><a name="p3967mcpsimp"></a><a name="p3967mcpsimp"></a>tx_rate</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p3969mcpsimp"><a name="p3969mcpsimp"></a><a name="p3969mcpsimp"></a>0x07</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p3971mcpsimp"><a name="p3971mcpsimp"></a><a name="p3971mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3973mcpsimp"><a name="p3973mcpsimp"></a><a name="p3973mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row3974mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3976mcpsimp"><a name="p3976mcpsimp"></a><a name="p3976mcpsimp"></a>tx_pilot_ratio</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p3978mcpsimp"><a name="p3978mcpsimp"></a><a name="p3978mcpsimp"></a>0x08</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p3980mcpsimp"><a name="p3980mcpsimp"></a><a name="p3980mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3982mcpsimp"><a name="p3982mcpsimp"></a><a name="p3982mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row3983mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3985mcpsimp"><a name="p3985mcpsimp"></a><a name="p3985mcpsimp"></a>tx_polar_r</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p3987mcpsimp"><a name="p3987mcpsimp"></a><a name="p3987mcpsimp"></a>0x09</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p3989mcpsimp"><a name="p3989mcpsimp"></a><a name="p3989mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p3991mcpsimp"><a name="p3991mcpsimp"></a><a name="p3991mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row3992mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p3994mcpsimp"><a name="p3994mcpsimp"></a><a name="p3994mcpsimp"></a>tx_interval</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p3996mcpsimp"><a name="p3996mcpsimp"></a><a name="p3996mcpsimp"></a>0x0A</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p3998mcpsimp"><a name="p3998mcpsimp"></a><a name="p3998mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p4000mcpsimp"><a name="p4000mcpsimp"></a><a name="p4000mcpsimp"></a>uint16</p>
</td>
</tr>
</tbody>
</table>

### 打开射频接收<a name="ZH-CN_TOPIC_0000001876269605"></a>

<a name="table4002mcpsimp"></a>
<table><thead align="left"><tr id="row4008mcpsimp"><th class="cellrowborder" valign="top" width="21.61%" id="mcps1.1.4.1.1"><p id="p4010mcpsimp"><a name="p4010mcpsimp"></a><a name="p4010mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="25.89%" id="mcps1.1.4.1.2"><p id="p4012mcpsimp"><a name="p4012mcpsimp"></a><a name="p4012mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="52.5%" id="mcps1.1.4.1.3"><p id="p4014mcpsimp"><a name="p4014mcpsimp"></a><a name="p4014mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row4015mcpsimp"><td class="cellrowborder" valign="top" width="21.61%" headers="mcps1.1.4.1.1 "><p id="p4017mcpsimp"><a name="p4017mcpsimp"></a><a name="p4017mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="25.89%" headers="mcps1.1.4.1.2 "><p id="p4019mcpsimp"><a name="p4019mcpsimp"></a><a name="p4019mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="52.5%" headers="mcps1.1.4.1.3 "><p id="p4021mcpsimp"><a name="p4021mcpsimp"></a><a name="p4021mcpsimp"></a>打开射频接收</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

<a name="table4024mcpsimp"></a>
<table><thead align="left"><tr id="row4031mcpsimp"><th class="cellrowborder" valign="top" width="27%" id="mcps1.1.5.1.1"><p id="p4033mcpsimp"><a name="p4033mcpsimp"></a><a name="p4033mcpsimp"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="22%" id="mcps1.1.5.1.2"><p id="p4035mcpsimp"><a name="p4035mcpsimp"></a><a name="p4035mcpsimp"></a>Type(bit0~bit6)</p>
</th>
<th class="cellrowborder" valign="top" width="18%" id="mcps1.1.5.1.3"><p id="p4037mcpsimp"><a name="p4037mcpsimp"></a><a name="p4037mcpsimp"></a>Length Size(Oct)</p>
</th>
<th class="cellrowborder" valign="top" width="33%" id="mcps1.1.5.1.4"><p id="p4040mcpsimp"><a name="p4040mcpsimp"></a><a name="p4040mcpsimp"></a>Value数据类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row4042mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p4044mcpsimp"><a name="p4044mcpsimp"></a><a name="p4044mcpsimp"></a>rx_freq</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p4046mcpsimp"><a name="p4046mcpsimp"></a><a name="p4046mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p4048mcpsimp"><a name="p4048mcpsimp"></a><a name="p4048mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p4050mcpsimp"><a name="p4050mcpsimp"></a><a name="p4050mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row4051mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p4053mcpsimp"><a name="p4053mcpsimp"></a><a name="p4053mcpsimp"></a>rx_phy</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p4055mcpsimp"><a name="p4055mcpsimp"></a><a name="p4055mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p4057mcpsimp"><a name="p4057mcpsimp"></a><a name="p4057mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p4059mcpsimp"><a name="p4059mcpsimp"></a><a name="p4059mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row4060mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p4062mcpsimp"><a name="p4062mcpsimp"></a><a name="p4062mcpsimp"></a>rx_format</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p4064mcpsimp"><a name="p4064mcpsimp"></a><a name="p4064mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p4066mcpsimp"><a name="p4066mcpsimp"></a><a name="p4066mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p4068mcpsimp"><a name="p4068mcpsimp"></a><a name="p4068mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row4069mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p4071mcpsimp"><a name="p4071mcpsimp"></a><a name="p4071mcpsimp"></a>rx_pilot_ratio</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p4073mcpsimp"><a name="p4073mcpsimp"></a><a name="p4073mcpsimp"></a>0x04</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p4075mcpsimp"><a name="p4075mcpsimp"></a><a name="p4075mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p4077mcpsimp"><a name="p4077mcpsimp"></a><a name="p4077mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row4078mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p4080mcpsimp"><a name="p4080mcpsimp"></a><a name="p4080mcpsimp"></a>rx_interval</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p4082mcpsimp"><a name="p4082mcpsimp"></a><a name="p4082mcpsimp"></a>0x05</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p4084mcpsimp"><a name="p4084mcpsimp"></a><a name="p4084mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p4086mcpsimp"><a name="p4086mcpsimp"></a><a name="p4086mcpsimp"></a>uint16</p>
</td>
</tr>
</tbody>
</table>

### 关闭射频收发<a name="ZH-CN_TOPIC_0000001829430404"></a>

<a name="table4088mcpsimp"></a>
<table><thead align="left"><tr id="row4094mcpsimp"><th class="cellrowborder" valign="top" width="21.38%" id="mcps1.1.4.1.1"><p id="p4096mcpsimp"><a name="p4096mcpsimp"></a><a name="p4096mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="26.200000000000003%" id="mcps1.1.4.1.2"><p id="p4098mcpsimp"><a name="p4098mcpsimp"></a><a name="p4098mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.4.1.3"><p id="p4100mcpsimp"><a name="p4100mcpsimp"></a><a name="p4100mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row4101mcpsimp"><td class="cellrowborder" valign="top" width="21.38%" headers="mcps1.1.4.1.1 "><p id="p4103mcpsimp"><a name="p4103mcpsimp"></a><a name="p4103mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="26.200000000000003%" headers="mcps1.1.4.1.2 "><p id="p4105mcpsimp"><a name="p4105mcpsimp"></a><a name="p4105mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.4.1.3 "><p id="p4107mcpsimp"><a name="p4107mcpsimp"></a><a name="p4107mcpsimp"></a>关闭射频收发</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

无

### 重置射频收发<a name="ZH-CN_TOPIC_0000001829590164"></a>

<a name="table4112mcpsimp"></a>
<table><thead align="left"><tr id="row4118mcpsimp"><th class="cellrowborder" valign="top" width="21.44%" id="mcps1.1.4.1.1"><p id="p4120mcpsimp"><a name="p4120mcpsimp"></a><a name="p4120mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="26.52%" id="mcps1.1.4.1.2"><p id="p4122mcpsimp"><a name="p4122mcpsimp"></a><a name="p4122mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="52.04%" id="mcps1.1.4.1.3"><p id="p4124mcpsimp"><a name="p4124mcpsimp"></a><a name="p4124mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row4125mcpsimp"><td class="cellrowborder" valign="top" width="21.44%" headers="mcps1.1.4.1.1 "><p id="p4127mcpsimp"><a name="p4127mcpsimp"></a><a name="p4127mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="26.52%" headers="mcps1.1.4.1.2 "><p id="p4129mcpsimp"><a name="p4129mcpsimp"></a><a name="p4129mcpsimp"></a>0x04</p>
</td>
<td class="cellrowborder" valign="top" width="52.04%" headers="mcps1.1.4.1.3 "><p id="p4131mcpsimp"><a name="p4131mcpsimp"></a><a name="p4131mcpsimp"></a>重置射频收发</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

无

### 设置RSSI阈值<a name="ZH-CN_TOPIC_0000001876189829"></a>

<a name="table4136mcpsimp"></a>
<table><thead align="left"><tr id="row4142mcpsimp"><th class="cellrowborder" valign="top" width="21.37%" id="mcps1.1.4.1.1"><p id="p4144mcpsimp"><a name="p4144mcpsimp"></a><a name="p4144mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="26.56%" id="mcps1.1.4.1.2"><p id="p4146mcpsimp"><a name="p4146mcpsimp"></a><a name="p4146mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="52.07000000000001%" id="mcps1.1.4.1.3"><p id="p4148mcpsimp"><a name="p4148mcpsimp"></a><a name="p4148mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row4149mcpsimp"><td class="cellrowborder" valign="top" width="21.37%" headers="mcps1.1.4.1.1 "><p id="p4151mcpsimp"><a name="p4151mcpsimp"></a><a name="p4151mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="26.56%" headers="mcps1.1.4.1.2 "><p id="p4153mcpsimp"><a name="p4153mcpsimp"></a><a name="p4153mcpsimp"></a>0x05</p>
</td>
<td class="cellrowborder" valign="top" width="52.07000000000001%" headers="mcps1.1.4.1.3 "><p id="p4155mcpsimp"><a name="p4155mcpsimp"></a><a name="p4155mcpsimp"></a>设置RSSI阈值</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

<a name="table4158mcpsimp"></a>
<table><thead align="left"><tr id="row4165mcpsimp"><th class="cellrowborder" valign="top" width="27%" id="mcps1.1.5.1.1"><p id="p4167mcpsimp"><a name="p4167mcpsimp"></a><a name="p4167mcpsimp"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="22%" id="mcps1.1.5.1.2"><p id="p4169mcpsimp"><a name="p4169mcpsimp"></a><a name="p4169mcpsimp"></a>Type(bit0~bit6)</p>
</th>
<th class="cellrowborder" valign="top" width="18%" id="mcps1.1.5.1.3"><p id="p4171mcpsimp"><a name="p4171mcpsimp"></a><a name="p4171mcpsimp"></a>Length Size(Oct)</p>
</th>
<th class="cellrowborder" valign="top" width="33%" id="mcps1.1.5.1.4"><p id="p4174mcpsimp"><a name="p4174mcpsimp"></a><a name="p4174mcpsimp"></a>Value数据类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row4176mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p4178mcpsimp"><a name="p4178mcpsimp"></a><a name="p4178mcpsimp"></a>rssi_sheld</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p4180mcpsimp"><a name="p4180mcpsimp"></a><a name="p4180mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p4182mcpsimp"><a name="p4182mcpsimp"></a><a name="p4182mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p4184mcpsimp"><a name="p4184mcpsimp"></a><a name="p4184mcpsimp"></a>uint8</p>
</td>
</tr>
</tbody>
</table>

## Low Latency Service<a name="ZH-CN_TOPIC_0000001876269609"></a>




### 低延时鼠标侧使能<a name="ZH-CN_TOPIC_0000001829430408"></a>

<a name="table4187mcpsimp"></a>
<table><thead align="left"><tr id="row4193mcpsimp"><th class="cellrowborder" valign="top" width="21.15%" id="mcps1.1.4.1.1"><p id="p4195mcpsimp"><a name="p4195mcpsimp"></a><a name="p4195mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="27.250000000000004%" id="mcps1.1.4.1.2"><p id="p4197mcpsimp"><a name="p4197mcpsimp"></a><a name="p4197mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="51.6%" id="mcps1.1.4.1.3"><p id="p4199mcpsimp"><a name="p4199mcpsimp"></a><a name="p4199mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row4200mcpsimp"><td class="cellrowborder" valign="top" width="21.15%" headers="mcps1.1.4.1.1 "><p id="p4202mcpsimp"><a name="p4202mcpsimp"></a><a name="p4202mcpsimp"></a>0x04</p>
</td>
<td class="cellrowborder" valign="top" width="27.250000000000004%" headers="mcps1.1.4.1.2 "><p id="p4204mcpsimp"><a name="p4204mcpsimp"></a><a name="p4204mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="51.6%" headers="mcps1.1.4.1.3 "><p id="p4206mcpsimp"><a name="p4206mcpsimp"></a><a name="p4206mcpsimp"></a>低延时鼠标侧使能</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

无

### 低延时Dongle侧使能<a name="ZH-CN_TOPIC_0000001829590168"></a>

<a name="table4211mcpsimp"></a>
<table><thead align="left"><tr id="row4217mcpsimp"><th class="cellrowborder" valign="top" width="20.94%" id="mcps1.1.4.1.1"><p id="p4219mcpsimp"><a name="p4219mcpsimp"></a><a name="p4219mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="27.37%" id="mcps1.1.4.1.2"><p id="p4221mcpsimp"><a name="p4221mcpsimp"></a><a name="p4221mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="51.690000000000005%" id="mcps1.1.4.1.3"><p id="p4223mcpsimp"><a name="p4223mcpsimp"></a><a name="p4223mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row4224mcpsimp"><td class="cellrowborder" valign="top" width="20.94%" headers="mcps1.1.4.1.1 "><p id="p4226mcpsimp"><a name="p4226mcpsimp"></a><a name="p4226mcpsimp"></a>0x04</p>
</td>
<td class="cellrowborder" valign="top" width="27.37%" headers="mcps1.1.4.1.2 "><p id="p4228mcpsimp"><a name="p4228mcpsimp"></a><a name="p4228mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="51.690000000000005%" headers="mcps1.1.4.1.3 "><p id="p4230mcpsimp"><a name="p4230mcpsimp"></a><a name="p4230mcpsimp"></a>低延时Dongle侧使能</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

无

### 低延时参数设置<a name="ZH-CN_TOPIC_0000001876189833"></a>

<a name="table4235mcpsimp"></a>
<table><thead align="left"><tr id="row4241mcpsimp"><th class="cellrowborder" valign="top" width="20.87%" id="mcps1.1.4.1.1"><p id="p4243mcpsimp"><a name="p4243mcpsimp"></a><a name="p4243mcpsimp"></a>Service ID</p>
</th>
<th class="cellrowborder" valign="top" width="27.46%" id="mcps1.1.4.1.2"><p id="p4245mcpsimp"><a name="p4245mcpsimp"></a><a name="p4245mcpsimp"></a>Comand ID</p>
</th>
<th class="cellrowborder" valign="top" width="51.67%" id="mcps1.1.4.1.3"><p id="p4247mcpsimp"><a name="p4247mcpsimp"></a><a name="p4247mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row4248mcpsimp"><td class="cellrowborder" valign="top" width="20.87%" headers="mcps1.1.4.1.1 "><p id="p4250mcpsimp"><a name="p4250mcpsimp"></a><a name="p4250mcpsimp"></a>0x04</p>
</td>
<td class="cellrowborder" valign="top" width="27.46%" headers="mcps1.1.4.1.2 "><p id="p4252mcpsimp"><a name="p4252mcpsimp"></a><a name="p4252mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="51.67%" headers="mcps1.1.4.1.3 "><p id="p4254mcpsimp"><a name="p4254mcpsimp"></a><a name="p4254mcpsimp"></a>低延时参数设置</p>
</td>
</tr>
</tbody>
</table>

**TLV 参数：**

<a name="table4257mcpsimp"></a>
<table><thead align="left"><tr id="row4264mcpsimp"><th class="cellrowborder" valign="top" width="27%" id="mcps1.1.5.1.1"><p id="p4266mcpsimp"><a name="p4266mcpsimp"></a><a name="p4266mcpsimp"></a>字段名称</p>
</th>
<th class="cellrowborder" valign="top" width="22%" id="mcps1.1.5.1.2"><p id="p4268mcpsimp"><a name="p4268mcpsimp"></a><a name="p4268mcpsimp"></a>Type(bit0~bit6)</p>
</th>
<th class="cellrowborder" valign="top" width="18%" id="mcps1.1.5.1.3"><p id="p4270mcpsimp"><a name="p4270mcpsimp"></a><a name="p4270mcpsimp"></a>Length Size(Oct)</p>
</th>
<th class="cellrowborder" valign="top" width="33%" id="mcps1.1.5.1.4"><p id="p4273mcpsimp"><a name="p4273mcpsimp"></a><a name="p4273mcpsimp"></a>Value数据类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row4275mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p4277mcpsimp"><a name="p4277mcpsimp"></a><a name="p4277mcpsimp"></a>conn_id</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p4279mcpsimp"><a name="p4279mcpsimp"></a><a name="p4279mcpsimp"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p4281mcpsimp"><a name="p4281mcpsimp"></a><a name="p4281mcpsimp"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p4283mcpsimp"><a name="p4283mcpsimp"></a><a name="p4283mcpsimp"></a>uint16</p>
</td>
</tr>
<tr id="row4284mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p4286mcpsimp"><a name="p4286mcpsimp"></a><a name="p4286mcpsimp"></a>enable</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p4288mcpsimp"><a name="p4288mcpsimp"></a><a name="p4288mcpsimp"></a>0x02</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p4290mcpsimp"><a name="p4290mcpsimp"></a><a name="p4290mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p4292mcpsimp"><a name="p4292mcpsimp"></a><a name="p4292mcpsimp"></a>uint8</p>
</td>
</tr>
<tr id="row4293mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.5.1.1 "><p id="p4295mcpsimp"><a name="p4295mcpsimp"></a><a name="p4295mcpsimp"></a>rate</p>
</td>
<td class="cellrowborder" valign="top" width="22%" headers="mcps1.1.5.1.2 "><p id="p4297mcpsimp"><a name="p4297mcpsimp"></a><a name="p4297mcpsimp"></a>0x03</p>
</td>
<td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.5.1.3 "><p id="p4299mcpsimp"><a name="p4299mcpsimp"></a><a name="p4299mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.5.1.4 "><p id="p4301mcpsimp"><a name="p4301mcpsimp"></a><a name="p4301mcpsimp"></a>uint8</p>
</td>
</tr>
</tbody>
</table>

# 交互流程示例<a name="ZH-CN_TOPIC_0000001876269613"></a>

以SSAP交互流程为例，流程图如[图1](#fig0769195551910)所示。

**图 1**  交互流程图<a name="fig0769195551910"></a>  
![](figures/交互流程图.png "交互流程图")

