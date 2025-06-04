# 前言<a name="ZH-CN_TOPIC_0000001762634336"></a>

**概述<a name="section4537382116410"></a>**

BS2XV100通过API（Application Programming Interface）向开发者提供NFC TAG的相关接口，包括初始化、参数设置、NDEF消息组装、NDEF消息配置、侦听模式开启、关闭等接口

**产品版本<a name="section673mcpsimp"></a>**

与本文档对应的产品版本如下。

<a name="table676mcpsimp"></a>
<table><thead align="left"><tr id="row681mcpsimp"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p683mcpsimp"><a name="p683mcpsimp"></a><a name="p683mcpsimp"></a><strong id="b684mcpsimp"><a name="b684mcpsimp"></a><a name="b684mcpsimp"></a>产品名称</strong></p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p686mcpsimp"><a name="p686mcpsimp"></a><a name="p686mcpsimp"></a><strong id="b687mcpsimp"><a name="b687mcpsimp"></a><a name="b687mcpsimp"></a>产品版本</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row689mcpsimp"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p691mcpsimp"><a name="p691mcpsimp"></a><a name="p691mcpsimp"></a>BS2X</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p693mcpsimp"><a name="p693mcpsimp"></a><a name="p693mcpsimp"></a>V100</p>
</td>
</tr>
</tbody>
</table>

**读者对象<a name="section4378592816410"></a>**

本文档主要适用以下工程师：

-   技术支持工程
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
<tbody><tr id="row1372280416410"><td class="cellrowborder" valign="top" width="20.580000000000002%" headers="mcps1.1.3.1.1 "><p id="p3734547016410"><a name="p3734547016410"></a><a name="p3734547016410"></a><a name="image2670064316410"></a><a name="image2670064316410"></a><span><img class="" id="image2670064316410" height="25.270000000000003" width="67.83" src="figures/zh-cn_image_0000001809712741.png"></span></p>
</td>
<td class="cellrowborder" valign="top" width="79.42%" headers="mcps1.1.3.1.2 "><p id="p1757432116410"><a name="p1757432116410"></a><a name="p1757432116410"></a>表示如不避免则将会导致死亡或严重伤害的具有高等级风险的危害。</p>
</td>
</tr>
<tr id="row466863216410"><td class="cellrowborder" valign="top" width="20.580000000000002%" headers="mcps1.1.3.1.1 "><p id="p1432579516410"><a name="p1432579516410"></a><a name="p1432579516410"></a><a name="image4895582316410"></a><a name="image4895582316410"></a><span><img class="" id="image4895582316410" height="25.270000000000003" width="67.83" src="figures/zh-cn_image_0000001762793288.png"></span></p>
</td>
<td class="cellrowborder" valign="top" width="79.42%" headers="mcps1.1.3.1.2 "><p id="p959197916410"><a name="p959197916410"></a><a name="p959197916410"></a>表示如不避免则可能导致死亡或严重伤害的具有中等级风险的危害。</p>
</td>
</tr>
<tr id="row123863216410"><td class="cellrowborder" valign="top" width="20.580000000000002%" headers="mcps1.1.3.1.1 "><p id="p1232579516410"><a name="p1232579516410"></a><a name="p1232579516410"></a><a name="image1235582316410"></a><a name="image1235582316410"></a><span><img class="" id="image1235582316410" height="25.270000000000003" width="67.83" src="figures/zh-cn_image_0000001809793697.png"></span></p>
</td>
<td class="cellrowborder" valign="top" width="79.42%" headers="mcps1.1.3.1.2 "><p id="p123197916410"><a name="p123197916410"></a><a name="p123197916410"></a>表示如不避免则可能导致轻微或中度伤害的具有低等级风险的危害。</p>
</td>
</tr>
<tr id="row5786682116410"><td class="cellrowborder" valign="top" width="20.580000000000002%" headers="mcps1.1.3.1.1 "><p id="p2204984716410"><a name="p2204984716410"></a><a name="p2204984716410"></a><a name="image4504446716410"></a><a name="image4504446716410"></a><span><img class="" id="image4504446716410" height="25.270000000000003" width="67.83" src="figures/zh-cn_image_0000001762634340.png"></span></p>
</td>
<td class="cellrowborder" valign="top" width="79.42%" headers="mcps1.1.3.1.2 "><p id="p4388861916410"><a name="p4388861916410"></a><a name="p4388861916410"></a>用于传递设备或环境安全警示信息。如不避免则可能会导致设备损坏、数据丢失、设备性能降低或其它不可预知的结果。</p>
<p id="p1238861916410"><a name="p1238861916410"></a><a name="p1238861916410"></a>“须知”不涉及人身伤害。</p>
</td>
</tr>
<tr id="row2856923116410"><td class="cellrowborder" valign="top" width="20.580000000000002%" headers="mcps1.1.3.1.1 "><p id="p5555360116410"><a name="p5555360116410"></a><a name="p5555360116410"></a><a name="image799324016410"></a><a name="image799324016410"></a><span><img class="" id="image799324016410" height="25.270000000000003" width="67.83" src="figures/zh-cn_image_0000001809712745.png"></span></p>
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
<tbody><tr id="row4495154085914"><td class="cellrowborder" valign="top" width="20.72%" headers="mcps1.1.4.1.1 "><p id="p0413131712"><a name="p0413131712"></a><a name="p0413131712"></a>01</p>
</td>
<td class="cellrowborder" valign="top" width="26.119999999999997%" headers="mcps1.1.4.1.2 "><p id="p184131311111"><a name="p184131311111"></a><a name="p184131311111"></a>2024-05-15</p>
</td>
<td class="cellrowborder" valign="top" width="53.16%" headers="mcps1.1.4.1.3 "><p id="p169114261115"><a name="p169114261115"></a><a name="p169114261115"></a>第一次正式版本发布。</p>
</td>
</tr>
<tr id="row5947359616410"><td class="cellrowborder" valign="top" width="20.72%" headers="mcps1.1.4.1.1 "><p id="p2149706016410"><a name="p2149706016410"></a><a name="p2149706016410"></a>00B01</p>
</td>
<td class="cellrowborder" valign="top" width="26.119999999999997%" headers="mcps1.1.4.1.2 "><p id="p648803616410"><a name="p648803616410"></a><a name="p648803616410"></a>2024-01-08</p>
</td>
<td class="cellrowborder" valign="top" width="53.16%" headers="mcps1.1.4.1.3 "><p id="p1946537916410"><a name="p1946537916410"></a><a name="p1946537916410"></a>第一次临时版本发布</p>
</td>
</tr>
</tbody>
</table>

# 概述<a name="ZH-CN_TOPIC_0000001809711061"></a>

BS2XV100通过API（Application Programming Interface）向开发者提供NFC TAG的相关接口，其接口功能说明如下：

TAG芯片接口：提供TAG芯片的参数配置、行为控制等功能。

>![](public_sys-resources/icon-note.gif) **说明：** 
>该文档描述各个模块功能的基本流程和API接口描述。

# 开发指导<a name="ZH-CN_TOPIC_0000001809945117"></a>




## 错误码<a name="ZH-CN_TOPIC_0000001762906302"></a>

NFC TAG使错误码指示用户当前任务执行结果，错误码说明如下：

**表 1**  错误码

<a name="table9501182016504"></a>
<table><thead align="left"><tr id="row950292085010"><th class="cellrowborder" valign="top" width="9%" id="mcps1.2.5.1.1"><p id="p25029205503"><a name="p25029205503"></a><a name="p25029205503"></a>序号</p>
</th>
<th class="cellrowborder" valign="top" width="40.38%" id="mcps1.2.5.1.2"><p id="p1350272085016"><a name="p1350272085016"></a><a name="p1350272085016"></a>定义</p>
</th>
<th class="cellrowborder" valign="top" width="14.180000000000001%" id="mcps1.2.5.1.3"><p id="p19502152005012"><a name="p19502152005012"></a><a name="p19502152005012"></a>实际数值</p>
</th>
<th class="cellrowborder" valign="top" width="36.44%" id="mcps1.2.5.1.4"><p id="p950262016502"><a name="p950262016502"></a><a name="p950262016502"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row10502132020509"><td class="cellrowborder" valign="top" width="9%" headers="mcps1.2.5.1.1 "><p id="p750232017508"><a name="p750232017508"></a><a name="p750232017508"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="40.38%" headers="mcps1.2.5.1.2 "><p id="p1740423423117"><a name="p1740423423117"></a><a name="p1740423423117"></a>NFC_OK</p>
</td>
<td class="cellrowborder" valign="top" width="14.180000000000001%" headers="mcps1.2.5.1.3 "><p id="p1350242035012"><a name="p1350242035012"></a><a name="p1350242035012"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.5.1.4 "><p id="p2478152273213"><a name="p2478152273213"></a><a name="p2478152273213"></a>执行成功错误码。</p>
</td>
</tr>
<tr id="row950211209505"><td class="cellrowborder" valign="top" width="9%" headers="mcps1.2.5.1.1 "><p id="p75021320195017"><a name="p75021320195017"></a><a name="p75021320195017"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="40.38%" headers="mcps1.2.5.1.2 "><p id="p153165211412"><a name="p153165211412"></a><a name="p153165211412"></a>NFC_ERR_PTR_NULL</p>
</td>
<td class="cellrowborder" valign="top" width="14.180000000000001%" headers="mcps1.2.5.1.3 "><p id="p206202225145"><a name="p206202225145"></a><a name="p206202225145"></a>0x80005F00</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.5.1.4 "><p id="p2580741135211"><a name="p2580741135211"></a><a name="p2580741135211"></a>输入参数中有空指针。</p>
</td>
</tr>
<tr id="row647004635216"><td class="cellrowborder" valign="top" width="9%" headers="mcps1.2.5.1.1 "><p id="p9470164695211"><a name="p9470164695211"></a><a name="p9470164695211"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="40.38%" headers="mcps1.2.5.1.2 "><p id="p15376202954111"><a name="p15376202954111"></a><a name="p15376202954111"></a>NFC_ERR_INVALID_LENGTH</p>
</td>
<td class="cellrowborder" valign="top" width="14.180000000000001%" headers="mcps1.2.5.1.3 "><p id="p1247054675220"><a name="p1247054675220"></a><a name="p1247054675220"></a>0x80005F01</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.5.1.4 "><p id="p181987012358"><a name="p181987012358"></a><a name="p181987012358"></a>输入参数长度非法。</p>
</td>
</tr>
<tr id="row208504495415"><td class="cellrowborder" valign="top" width="9%" headers="mcps1.2.5.1.1 "><p id="p485544155412"><a name="p485544155412"></a><a name="p485544155412"></a>5</p>
</td>
<td class="cellrowborder" valign="top" width="40.38%" headers="mcps1.2.5.1.2 "><p id="p91211439114117"><a name="p91211439114117"></a><a name="p91211439114117"></a>NFC_ERR_INVALID_PARAM</p>
</td>
<td class="cellrowborder" valign="top" width="14.180000000000001%" headers="mcps1.2.5.1.3 "><p id="p202639558212"><a name="p202639558212"></a><a name="p202639558212"></a>0x80005F02</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.5.1.4 "><p id="p17800115619340"><a name="p17800115619340"></a><a name="p17800115619340"></a>输入参数中有非法参数。</p>
</td>
</tr>
<tr id="row2914115711542"><td class="cellrowborder" valign="top" width="9%" headers="mcps1.2.5.1.1 "><p id="p15914145716545"><a name="p15914145716545"></a><a name="p15914145716545"></a>6</p>
</td>
<td class="cellrowborder" valign="top" width="40.38%" headers="mcps1.2.5.1.2 "><p id="p17939154313416"><a name="p17939154313416"></a><a name="p17939154313416"></a>NFC_ERR_INVALID_STATE</p>
</td>
<td class="cellrowborder" valign="top" width="14.180000000000001%" headers="mcps1.2.5.1.3 "><p id="p061233385012"><a name="p061233385012"></a><a name="p061233385012"></a>0x80005F03</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.5.1.4 "><p id="p925873013511"><a name="p925873013511"></a><a name="p925873013511"></a>TAG状态异常。</p>
</td>
</tr>
<tr id="row13726122553"><td class="cellrowborder" valign="top" width="9%" headers="mcps1.2.5.1.1 "><p id="p187261621559"><a name="p187261621559"></a><a name="p187261621559"></a>7</p>
</td>
<td class="cellrowborder" valign="top" width="40.38%" headers="mcps1.2.5.1.2 "><p id="p20928749124111"><a name="p20928749124111"></a><a name="p20928749124111"></a>NFC_ERR_MEMCPY_FAIL</p>
</td>
<td class="cellrowborder" valign="top" width="14.180000000000001%" headers="mcps1.2.5.1.3 "><p id="p1991455717548"><a name="p1991455717548"></a><a name="p1991455717548"></a>0x80005F04</p>
</td>
<td class="cellrowborder" valign="top" width="36.44%" headers="mcps1.2.5.1.4 "><p id="p1650784303513"><a name="p1650784303513"></a><a name="p1650784303513"></a>内存拷贝异常。</p>
</td>
</tr>
</tbody>
</table>

## 接口说明<a name="ZH-CN_TOPIC_0000001762902426"></a>

**表 1**  TAG芯片接口描述

<a name="_table213321716161"></a>
<table><thead align="left"><tr id="row788mcpsimp"><th class="cellrowborder" valign="top" width="22.63%" id="mcps1.2.5.1.1"><p id="p790mcpsimp"><a name="p790mcpsimp"></a><a name="p790mcpsimp"></a>接口名称</p>
</th>
<th class="cellrowborder" valign="top" width="17.43%" id="mcps1.2.5.1.2"><p id="p792mcpsimp"><a name="p792mcpsimp"></a><a name="p792mcpsimp"></a>描述</p>
</th>
<th class="cellrowborder" valign="top" width="19.24%" id="mcps1.2.5.1.3"><p id="p142843230222"><a name="p142843230222"></a><a name="p142843230222"></a>参数说明</p>
</th>
<th class="cellrowborder" valign="top" width="40.699999999999996%" id="mcps1.2.5.1.4"><p id="p79178221244"><a name="p79178221244"></a><a name="p79178221244"></a>返回信息说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row109671129123514"><td class="cellrowborder" valign="top" width="22.63%" headers="mcps1.2.5.1.1 "><p id="p1911158105010"><a name="p1911158105010"></a><a name="p1911158105010"></a>NFC_T2T_Init</p>
</td>
<td class="cellrowborder" valign="top" width="17.43%" headers="mcps1.2.5.1.2 "><p id="p189672029143520"><a name="p189672029143520"></a><a name="p189672029143520"></a>初始化T2T模块</p>
</td>
<td class="cellrowborder" valign="top" width="19.24%" headers="mcps1.2.5.1.3 "><p id="p9354163513"><a name="p9354163513"></a><a name="p9354163513"></a>handle：注册的回调函数</p>
</td>
<td class="cellrowborder" valign="top" width="40.699999999999996%" headers="mcps1.2.5.1.4 "><p id="p11967152913520"><a name="p11967152913520"></a><a name="p11967152913520"></a>void</p>
</td>
</tr>
<tr id="row93910277358"><td class="cellrowborder" valign="top" width="22.63%" headers="mcps1.2.5.1.1 "><p id="p8538213155117"><a name="p8538213155117"></a><a name="p8538213155117"></a>NFC_T2T_SetConfig</p>
</td>
<td class="cellrowborder" valign="top" width="17.43%" headers="mcps1.2.5.1.2 "><p id="p4391727103520"><a name="p4391727103520"></a><a name="p4391727103520"></a>配置T2T参数</p>
</td>
<td class="cellrowborder" valign="top" width="19.24%" headers="mcps1.2.5.1.3 "><p id="p94052026115115"><a name="p94052026115115"></a><a name="p94052026115115"></a>id：参数ID</p>
<p id="p12761102710511"><a name="p12761102710511"></a><a name="p12761102710511"></a>data：参数数据</p>
<p id="p147617362518"><a name="p147617362518"></a><a name="p147617362518"></a>len：参数长度</p>
</td>
<td class="cellrowborder" valign="top" width="40.699999999999996%" headers="mcps1.2.5.1.4 "><p id="p5802134813719"><a name="p5802134813719"></a><a name="p5802134813719"></a>接口返回值：错误码。</p>
</td>
</tr>
<tr id="row14862523143519"><td class="cellrowborder" valign="top" width="22.63%" headers="mcps1.2.5.1.1 "><p id="p123561642135116"><a name="p123561642135116"></a><a name="p123561642135116"></a>NFC_T2T_StartEmulation</p>
</td>
<td class="cellrowborder" valign="top" width="17.43%" headers="mcps1.2.5.1.2 "><p id="p138623239351"><a name="p138623239351"></a><a name="p138623239351"></a>开启RF侦听</p>
</td>
<td class="cellrowborder" valign="top" width="19.24%" headers="mcps1.2.5.1.3 "><p id="p5862172311355"><a name="p5862172311355"></a><a name="p5862172311355"></a>void</p>
</td>
<td class="cellrowborder" valign="top" width="40.699999999999996%" headers="mcps1.2.5.1.4 "><p id="p1066892735414"><a name="p1066892735414"></a><a name="p1066892735414"></a>接口返回值：错误码。</p>
</td>
</tr>
<tr id="row18901646113418"><td class="cellrowborder" valign="top" width="22.63%" headers="mcps1.2.5.1.1 "><p id="p107471646205117"><a name="p107471646205117"></a><a name="p107471646205117"></a>NFC_T2T_StopEmulation</p>
</td>
<td class="cellrowborder" valign="top" width="17.43%" headers="mcps1.2.5.1.2 "><p id="p1589004673414"><a name="p1589004673414"></a><a name="p1589004673414"></a>停止RF侦听</p>
</td>
<td class="cellrowborder" valign="top" width="19.24%" headers="mcps1.2.5.1.3 "><p id="p67681345193617"><a name="p67681345193617"></a><a name="p67681345193617"></a>void</p>
</td>
<td class="cellrowborder" valign="top" width="40.699999999999996%" headers="mcps1.2.5.1.4 "><p id="p1949512448387"><a name="p1949512448387"></a><a name="p1949512448387"></a>接口返回值：错误码。</p>
</td>
</tr>
<tr id="row154823161515"><td class="cellrowborder" valign="top" width="22.63%" headers="mcps1.2.5.1.1 "><p id="p7785185105118"><a name="p7785185105118"></a><a name="p7785185105118"></a>NFC_T2T_SetNdef</p>
</td>
<td class="cellrowborder" valign="top" width="17.43%" headers="mcps1.2.5.1.2 "><p id="p15485312159"><a name="p15485312159"></a><a name="p15485312159"></a>设置NDEF消息</p>
</td>
<td class="cellrowborder" valign="top" width="19.24%" headers="mcps1.2.5.1.3 "><p id="p1441324085417"><a name="p1441324085417"></a><a name="p1441324085417"></a>data：ndef数据</p>
<p id="p3288544145414"><a name="p3288544145414"></a><a name="p3288544145414"></a>len：ndef长度</p>
</td>
<td class="cellrowborder" valign="top" width="40.699999999999996%" headers="mcps1.2.5.1.4 "><p id="p998181701718"><a name="p998181701718"></a><a name="p998181701718"></a>接口返回值：错误码。</p>
</td>
</tr>
<tr id="row43102035171512"><td class="cellrowborder" valign="top" width="22.63%" headers="mcps1.2.5.1.1 "><p id="p32025119523"><a name="p32025119523"></a><a name="p32025119523"></a>NFC_T2T_SetTagArea</p>
</td>
<td class="cellrowborder" valign="top" width="17.43%" headers="mcps1.2.5.1.2 "><p id="p183118354157"><a name="p183118354157"></a><a name="p183118354157"></a>设置用户区payload</p>
</td>
<td class="cellrowborder" valign="top" width="19.24%" headers="mcps1.2.5.1.3 "><p id="p0284723122215"><a name="p0284723122215"></a><a name="p0284723122215"></a>buff：用户空间指针</p>
<p id="p1351212353554"><a name="p1351212353554"></a><a name="p1351212353554"></a>len：用户空间长度</p>
</td>
<td class="cellrowborder" valign="top" width="40.699999999999996%" headers="mcps1.2.5.1.4 "><p id="p134171515151711"><a name="p134171515151711"></a><a name="p134171515151711"></a>接口返回值：错误码。</p>
</td>
</tr>
</tbody>
</table>

## 开发流程<a name="ZH-CN_TOPIC_0000001809944693"></a>

1.  调用NFC\_T2T\_Init初始化一个T2T环境。
2.  使用NFC\_T2T\_SetConfig配置感兴趣的参数，可选。
3.  组装NDEF消息，之后使用NFC\_T2T\_SetNdef接口配置到Tag模块。
4.  开启侦听NFC\_T2T\_StartEmulation。

