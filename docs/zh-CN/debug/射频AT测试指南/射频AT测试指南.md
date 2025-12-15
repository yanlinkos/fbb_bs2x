# 前言<a name="ZH-CN_TOPIC_0000001696430170"></a>

**概述<a name="section4537382116410"></a>**

本文档主要介绍BS2XV100的射频非信令相关的测试指令和指令的组包示例，测试前务必阅读注意事项。

**产品版本<a name="section15282156125413"></a>**

与本文档相对应的产品版本如下。

<a name="table32398201"></a>
<table><thead align="left"><tr id="row8991374"><th class="cellrowborder" valign="top" width="31.31%" id="mcps1.1.3.1.1"><p id="p57212719"><a name="p57212719"></a><a name="p57212719"></a><strong id="b6322135815819"><a name="b6322135815819"></a><a name="b6322135815819"></a>产品名称</strong></p>
</th>
<th class="cellrowborder" valign="top" width="68.69%" id="mcps1.1.3.1.2"><p id="p3718701"><a name="p3718701"></a><a name="p3718701"></a><strong id="b19345175815810"><a name="b19345175815810"></a><a name="b19345175815810"></a>产品版本</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row32779375"><td class="cellrowborder" valign="top" width="31.31%" headers="mcps1.1.3.1.1 "><p id="p7894125012586"><a name="p7894125012586"></a><a name="p7894125012586"></a>BS2X</p>
</td>
<td class="cellrowborder" valign="top" width="68.69%" headers="mcps1.1.3.1.2 "><p id="review1024950"><a name="review1024950"></a><a name="review1024950"></a>V100</p>
</td>
</tr>
</tbody>
</table>

**读者对象<a name="section4378592816410"></a>**

本文档主要适用于以下工程师：

-   技术支持工程师。
-   软件开发工程师。

**符号约定<a name="section133020216410"></a>**

在本文中可能出现下列标志,它们所代表的含义如下。

<a name="table2622507016410"></a>
<table><thead align="left"><tr id="row1530720816410"><th class="cellrowborder" valign="top" width="20.580000000000002%" id="mcps1.1.3.1.1"><p id="p6450074116410"><a name="p6450074116410"></a><a name="p6450074116410"></a><strong id="b2136615816410"><a name="b2136615816410"></a><a name="b2136615816410"></a>符号</strong></p>
</th>
<th class="cellrowborder" valign="top" width="79.42%" id="mcps1.1.3.1.2"><p id="p5435366816410"><a name="p5435366816410"></a><a name="p5435366816410"></a><strong id="b5941558116410"><a name="b5941558116410"></a><a name="b5941558116410"></a>说明</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row1372280416410"><td class="cellrowborder" valign="top" width="20.580000000000002%" headers="mcps1.1.3.1.1 "><p id="p3734547016410"><a name="p3734547016410"></a><a name="p3734547016410"></a><a name="image2670064316410"></a><a name="image2670064316410"></a><span><img class="" id="image2670064316410" height="25.270000000000003" width="67.83" src="figures/zh-cn_image_0000001696270718.png"></span></p>
</td>
<td class="cellrowborder" valign="top" width="79.42%" headers="mcps1.1.3.1.2 "><p id="p1757432116410"><a name="p1757432116410"></a><a name="p1757432116410"></a>表示如不避免则将会导致死亡或严重伤害的具有高等级风险的危害。</p>
</td>
</tr>
<tr id="row466863216410"><td class="cellrowborder" valign="top" width="20.580000000000002%" headers="mcps1.1.3.1.1 "><p id="p1432579516410"><a name="p1432579516410"></a><a name="p1432579516410"></a><a name="image4895582316410"></a><a name="image4895582316410"></a><span><img class="" id="image4895582316410" height="25.270000000000003" width="67.83" src="figures/zh-cn_image_0000001744110217.png"></span></p>
</td>
<td class="cellrowborder" valign="top" width="79.42%" headers="mcps1.1.3.1.2 "><p id="p959197916410"><a name="p959197916410"></a><a name="p959197916410"></a>表示如不避免则可能导致死亡或严重伤害的具有中等级风险的危害。</p>
</td>
</tr>
<tr id="row123863216410"><td class="cellrowborder" valign="top" width="20.580000000000002%" headers="mcps1.1.3.1.1 "><p id="p1232579516410"><a name="p1232579516410"></a><a name="p1232579516410"></a><a name="image1235582316410"></a><a name="image1235582316410"></a><span><img class="" id="image1235582316410" height="25.270000000000003" width="67.83" src="figures/zh-cn_image_0000001744150357.png"></span></p>
</td>
<td class="cellrowborder" valign="top" width="79.42%" headers="mcps1.1.3.1.2 "><p id="p123197916410"><a name="p123197916410"></a><a name="p123197916410"></a>表示如不避免则可能导致轻微或中度伤害的具有低等级风险的危害。</p>
</td>
</tr>
<tr id="row5786682116410"><td class="cellrowborder" valign="top" width="20.580000000000002%" headers="mcps1.1.3.1.1 "><p id="p2204984716410"><a name="p2204984716410"></a><a name="p2204984716410"></a><a name="image4504446716410"></a><a name="image4504446716410"></a><span><img class="" id="image4504446716410" height="25.270000000000003" width="67.83" src="figures/zh-cn_image_0000001696430190.png"></span></p>
</td>
<td class="cellrowborder" valign="top" width="79.42%" headers="mcps1.1.3.1.2 "><p id="p4388861916410"><a name="p4388861916410"></a><a name="p4388861916410"></a>用于传递设备或环境安全警示信息。如不避免则可能会导致设备损坏、数据丢失、设备性能降低或其它不可预知的结果。</p>
<p id="p1238861916410"><a name="p1238861916410"></a><a name="p1238861916410"></a>“须知”不涉及人身伤害。</p>
</td>
</tr>
<tr id="row2856923116410"><td class="cellrowborder" valign="top" width="20.580000000000002%" headers="mcps1.1.3.1.1 "><p id="p5555360116410"><a name="p5555360116410"></a><a name="p5555360116410"></a><a name="image799324016410"></a><a name="image799324016410"></a><span><img class="" id="image799324016410" height="25.270000000000003" width="67.83" src="figures/zh-cn_image_0000001744150361.png"></span></p>
</td>
<td class="cellrowborder" valign="top" width="79.42%" headers="mcps1.1.3.1.2 "><p id="p4612588116410"><a name="p4612588116410"></a><a name="p4612588116410"></a>对正文中重点信息的补充说明。</p>
<p id="p1232588116410"><a name="p1232588116410"></a><a name="p1232588116410"></a>“说明”不是安全警示信息,不涉及人身、设备及环境伤害信息。</p>
</td>
</tr>
</tbody>
</table>

**修改记录<a name="section2467512116410"></a>**

<a name="table1557726816410"></a>
<table><thead align="left"><tr id="row2942532716410"><th class="cellrowborder" valign="top" width="18.22%" id="mcps1.1.4.1.1"><p id="p3778275416410"><a name="p3778275416410"></a><a name="p3778275416410"></a><strong id="b5687322716410"><a name="b5687322716410"></a><a name="b5687322716410"></a>文档版本</strong></p>
</th>
<th class="cellrowborder" valign="top" width="24.58%" id="mcps1.1.4.1.2"><p id="p5627845516410"><a name="p5627845516410"></a><a name="p5627845516410"></a><strong id="b5800814916410"><a name="b5800814916410"></a><a name="b5800814916410"></a>发布日期</strong></p>
</th>
<th class="cellrowborder" valign="top" width="57.199999999999996%" id="mcps1.1.4.1.3"><p id="p2382284816410"><a name="p2382284816410"></a><a name="p2382284816410"></a><strong id="b3316380216410"><a name="b3316380216410"></a><a name="b3316380216410"></a>修改说明</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row2018655514115"><td class="cellrowborder" valign="top" width="18.22%" headers="mcps1.1.4.1.1 "><p id="p17186135571120"><a name="p17186135571120"></a><a name="p17186135571120"></a>04</p>
</td>
<td class="cellrowborder" valign="top" width="24.58%" headers="mcps1.1.4.1.2 "><p id="p5186195512119"><a name="p5186195512119"></a><a name="p5186195512119"></a>2025-05-30</p>
</td>
<td class="cellrowborder" valign="top" width="57.199999999999996%" headers="mcps1.1.4.1.3 "><a name="ul0312173511218"></a><a name="ul0312173511218"></a><ul id="ul0312173511218"><li>更新“<a href="常发指令.md">常发指令</a>”小节内容。</li><li>更新“<a href="常收指令.md">常收指令</a>”小节内容。</li><li>更新“<a href="常发指令-0.md">常发指令</a>”小节内容。</li><li>更新“<a href="常收指令-1.md">常收指令</a>”小节内容。</li><li>更新“<a href="常发常收停止指令-2.md">常发常收停止指令</a>”小节内容。</li></ul>
</td>
</tr>
<tr id="row117388126717"><td class="cellrowborder" valign="top" width="18.22%" headers="mcps1.1.4.1.1 "><p id="p973915129712"><a name="p973915129712"></a><a name="p973915129712"></a>03</p>
</td>
<td class="cellrowborder" valign="top" width="24.58%" headers="mcps1.1.4.1.2 "><p id="p1739912571"><a name="p1739912571"></a><a name="p1739912571"></a>2025-01-14</p>
</td>
<td class="cellrowborder" valign="top" width="57.199999999999996%" headers="mcps1.1.4.1.3 "><p id="p12051721978"><a name="p12051721978"></a><a name="p12051721978"></a>更新“<a href="常发指令-0.md">常发指令</a>”小节内容。</p>
</td>
</tr>
<tr id="row19990216115416"><td class="cellrowborder" valign="top" width="18.22%" headers="mcps1.1.4.1.1 "><p id="p7990716175415"><a name="p7990716175415"></a><a name="p7990716175415"></a>02</p>
</td>
<td class="cellrowborder" valign="top" width="24.58%" headers="mcps1.1.4.1.2 "><p id="p69901161541"><a name="p69901161541"></a><a name="p69901161541"></a>2024-08-29</p>
</td>
<td class="cellrowborder" valign="top" width="57.199999999999996%" headers="mcps1.1.4.1.3 "><a name="ul0587122420549"></a><a name="ul0587122420549"></a><ul id="ul0587122420549"><li>更新“<a href="射频测试相关AT指令一览表.md">射频测试相关AT指令一览表</a>”、“<a href="射频单音.md">射频单音</a>”、“<a href="CTRIM校准值写入EFUSE-FLASH指令.md">CTRIM校准值写入EFUSE / FLASH指令</a>”、“<a href="CFO动态校准上报（可选）.md">CFO动态校准上报（可选）</a>”小节内容。</li><li>更新“<a href="AT指令组包示例.md">AT指令组包示例</a>”小节内容。</li><li>更新“<a href="部分指令返回值为十六进制.md">部分指令返回值为十六进制</a>”、“<a href="串口回复说明.md">串口回复说明</a>”、“<a href="星闪协议频点表.md">星闪协议频点表</a>”小节内容。</li></ul>
</td>
</tr>
<tr id="row1847819476327"><td class="cellrowborder" valign="top" width="18.22%" headers="mcps1.1.4.1.1 "><p id="p23680516295"><a name="p23680516295"></a><a name="p23680516295"></a>01</p>
</td>
<td class="cellrowborder" valign="top" width="24.58%" headers="mcps1.1.4.1.2 "><p id="p83681951102912"><a name="p83681951102912"></a><a name="p83681951102912"></a>2024-05-24</p>
</td>
<td class="cellrowborder" valign="top" width="57.199999999999996%" headers="mcps1.1.4.1.3 "><p id="p169114261115"><a name="p169114261115"></a><a name="p169114261115"></a>第一次正式版本发布。</p>
<a name="ul116718118206"></a><a name="ul116718118206"></a><ul id="ul116718118206"><li>更新“<a href="射频测试相关AT指令一览表.md">射频测试相关AT指令一览表</a>”小节内容。</li><li>新增“<a href="RT201-FEM使能（可选）.md">RT201 FEM使能（可选）</a>”小节内容。</li></ul>
</td>
</tr>
<tr id="row18799647121615"><td class="cellrowborder" valign="top" width="18.22%" headers="mcps1.1.4.1.1 "><p id="p1179918476166"><a name="p1179918476166"></a><a name="p1179918476166"></a>00B05</p>
</td>
<td class="cellrowborder" valign="top" width="24.58%" headers="mcps1.1.4.1.2 "><p id="p121721454141610"><a name="p121721454141610"></a><a name="p121721454141610"></a>2024-03-29</p>
</td>
<td class="cellrowborder" valign="top" width="57.199999999999996%" headers="mcps1.1.4.1.3 "><p id="p137991147151613"><a name="p137991147151613"></a><a name="p137991147151613"></a>更新“<a href="BLE业务使能.md">BLE业务使能</a>”小节内容。</p>
</td>
</tr>
<tr id="row6559125613117"><td class="cellrowborder" valign="top" width="18.22%" headers="mcps1.1.4.1.1 "><p id="p1955965620317"><a name="p1955965620317"></a><a name="p1955965620317"></a>00B04</p>
</td>
<td class="cellrowborder" valign="top" width="24.58%" headers="mcps1.1.4.1.2 "><p id="p12559165603115"><a name="p12559165603115"></a><a name="p12559165603115"></a>2024-03-15</p>
</td>
<td class="cellrowborder" valign="top" width="57.199999999999996%" headers="mcps1.1.4.1.3 "><a name="ul6572422143319"></a><a name="ul6572422143319"></a><ul id="ul6572422143319"><li>更新“<a href="射频测试相关AT指令一览表.md">射频测试相关AT指令一览表</a>”小节内容。</li><li>更新“<a href="BLE射频测试相关AT指令描述.md">BLE射频测试相关AT指令描述</a>”小节内容。</li><li>更新“<a href="SLE射频测试相关AT指令描述.md">SLE射频测试相关AT指令描述</a>”小节内容。</li></ul>
</td>
</tr>
<tr id="row84652012919"><td class="cellrowborder" valign="top" width="18.22%" headers="mcps1.1.4.1.1 "><p id="p16465131796"><a name="p16465131796"></a><a name="p16465131796"></a>00B03</p>
</td>
<td class="cellrowborder" valign="top" width="24.58%" headers="mcps1.1.4.1.2 "><p id="p11465918919"><a name="p11465918919"></a><a name="p11465918919"></a>2024-01-18</p>
</td>
<td class="cellrowborder" valign="top" width="57.199999999999996%" headers="mcps1.1.4.1.3 "><p id="p1146514110913"><a name="p1146514110913"></a><a name="p1146514110913"></a>更新“<a href="AT指令组包示例.md">AT指令组包示例</a>”章节内容。</p>
</td>
</tr>
<tr id="row12410423145215"><td class="cellrowborder" valign="top" width="18.22%" headers="mcps1.1.4.1.1 "><p id="p4410323105215"><a name="p4410323105215"></a><a name="p4410323105215"></a>00B02</p>
</td>
<td class="cellrowborder" valign="top" width="24.58%" headers="mcps1.1.4.1.2 "><p id="p3410192317524"><a name="p3410192317524"></a><a name="p3410192317524"></a>2023-12-28</p>
</td>
<td class="cellrowborder" valign="top" width="57.199999999999996%" headers="mcps1.1.4.1.3 "><p id="p136242298531"><a name="p136242298531"></a><a name="p136242298531"></a>更新“<a href="常发指令-0.md">常发指令</a>”小节内容。</p>
</td>
</tr>
<tr id="row5947359616410"><td class="cellrowborder" valign="top" width="18.22%" headers="mcps1.1.4.1.1 "><p id="p2149706016410"><a name="p2149706016410"></a><a name="p2149706016410"></a>00B01</p>
</td>
<td class="cellrowborder" valign="top" width="24.58%" headers="mcps1.1.4.1.2 "><p id="p648803616410"><a name="p648803616410"></a><a name="p648803616410"></a>2023-11-01</p>
</td>
<td class="cellrowborder" valign="top" width="57.199999999999996%" headers="mcps1.1.4.1.3 "><p id="p1946537916410"><a name="p1946537916410"></a><a name="p1946537916410"></a>第一次临时版本发布。</p>
</td>
</tr>
</tbody>
</table>

# 射频测试AT指令<a name="ZH-CN_TOPIC_0000001744110193"></a>









## 射频测试相关AT指令一览表<a name="ZH-CN_TOPIC_0000001744110201"></a>

<a name="table924mcpsimp"></a>
<table><thead align="left"><tr id="row929mcpsimp"><th class="cellrowborder" valign="top" width="30.659999999999997%" id="mcps1.1.3.1.1"><p id="p931mcpsimp"><a name="p931mcpsimp"></a><a name="p931mcpsimp"></a>指令</p>
</th>
<th class="cellrowborder" valign="top" width="69.34%" id="mcps1.1.3.1.2"><p id="p933mcpsimp"><a name="p933mcpsimp"></a><a name="p933mcpsimp"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row8488114014377"><td class="cellrowborder" valign="top" width="30.659999999999997%" headers="mcps1.1.3.1.1 "><p id="p171961046133712"><a name="p171961046133712"></a><a name="p171961046133712"></a>a testsuite_sw_at</p>
</td>
<td class="cellrowborder" valign="top" width="69.34%" headers="mcps1.1.3.1.2 "><p id="p7196114616374"><a name="p7196114616374"></a><a name="p7196114616374"></a>从testsuite进入AT模式（最新版本删除）。</p>
</td>
</tr>
<tr id="row1667763273710"><td class="cellrowborder" valign="top" width="30.659999999999997%" headers="mcps1.1.3.1.1 "><p id="p181961546103711"><a name="p181961546103711"></a><a name="p181961546103711"></a>AT+TESTSUITE</p>
</td>
<td class="cellrowborder" valign="top" width="69.34%" headers="mcps1.1.3.1.2 "><p id="p919610462375"><a name="p919610462375"></a><a name="p919610462375"></a>退出AT模式。（最新版本删除）</p>
</td>
</tr>
<tr id="row62124430577"><td class="cellrowborder" valign="top" width="30.659999999999997%" headers="mcps1.1.3.1.1 "><p id="p4213243155715"><a name="p4213243155715"></a><a name="p4213243155715"></a>AT+BLEENABLE</p>
</td>
<td class="cellrowborder" valign="top" width="69.34%" headers="mcps1.1.3.1.2 "><p id="p321364385713"><a name="p321364385713"></a><a name="p321364385713"></a>BLE业务使能</p>
</td>
</tr>
<tr id="row1150616561211"><td class="cellrowborder" valign="top" width="30.659999999999997%" headers="mcps1.1.3.1.1 "><p id="p195061856029"><a name="p195061856029"></a><a name="p195061856029"></a>AT+BLEFACCALLBACK</p>
</td>
<td class="cellrowborder" valign="top" width="69.34%" headers="mcps1.1.3.1.2 "><p id="p14506195619210"><a name="p14506195619210"></a><a name="p14506195619210"></a>注册BLE命令上报回调（没有相应退出操作）。</p>
</td>
</tr>
<tr id="row934mcpsimp"><td class="cellrowborder" valign="top" width="30.659999999999997%" headers="mcps1.1.3.1.1 "><p id="p936mcpsimp"><a name="p936mcpsimp"></a><a name="p936mcpsimp"></a>AT+BLETX</p>
</td>
<td class="cellrowborder" valign="top" width="69.34%" headers="mcps1.1.3.1.2 "><p id="p939mcpsimp"><a name="p939mcpsimp"></a><a name="p939mcpsimp"></a>BLE常发指令。</p>
</td>
</tr>
<tr id="row940mcpsimp"><td class="cellrowborder" valign="top" width="30.659999999999997%" headers="mcps1.1.3.1.1 "><p id="p942mcpsimp"><a name="p942mcpsimp"></a><a name="p942mcpsimp"></a>AT+BLERX</p>
</td>
<td class="cellrowborder" valign="top" width="69.34%" headers="mcps1.1.3.1.2 "><p id="p945mcpsimp"><a name="p945mcpsimp"></a><a name="p945mcpsimp"></a>BLE常收指令。</p>
</td>
</tr>
<tr id="row946mcpsimp"><td class="cellrowborder" valign="top" width="30.659999999999997%" headers="mcps1.1.3.1.1 "><p id="p948mcpsimp"><a name="p948mcpsimp"></a><a name="p948mcpsimp"></a>AT+BLETRXEND</p>
</td>
<td class="cellrowborder" valign="top" width="69.34%" headers="mcps1.1.3.1.2 "><p id="p951mcpsimp"><a name="p951mcpsimp"></a><a name="p951mcpsimp"></a>BLE常发、常收停止指令。</p>
</td>
</tr>
<tr id="row952mcpsimp"><td class="cellrowborder" valign="top" width="30.659999999999997%" headers="mcps1.1.3.1.1 "><p id="p954mcpsimp"><a name="p954mcpsimp"></a><a name="p954mcpsimp"></a>AT+BLERST</p>
</td>
<td class="cellrowborder" valign="top" width="69.34%" headers="mcps1.1.3.1.2 "><p id="p957mcpsimp"><a name="p957mcpsimp"></a><a name="p957mcpsimp"></a>BLE软件复位指令。</p>
</td>
</tr>
<tr id="row106370376445"><td class="cellrowborder" valign="top" width="30.659999999999997%" headers="mcps1.1.3.1.1 "><p id="p648144317444"><a name="p648144317444"></a><a name="p648144317444"></a>AT+SLEENABLE</p>
</td>
<td class="cellrowborder" valign="top" width="69.34%" headers="mcps1.1.3.1.2 "><p id="p4637153717449"><a name="p4637153717449"></a><a name="p4637153717449"></a>SLE使能指令（没有相应退出操作）。</p>
</td>
</tr>
<tr id="row148978381669"><td class="cellrowborder" valign="top" width="30.659999999999997%" headers="mcps1.1.3.1.1 "><p id="p38982431364"><a name="p38982431364"></a><a name="p38982431364"></a>AT+SLEFACCALLBACK</p>
</td>
<td class="cellrowborder" valign="top" width="69.34%" headers="mcps1.1.3.1.2 "><p id="p163352047560"><a name="p163352047560"></a><a name="p163352047560"></a>注册SLE命令上报回调（没有相应退出操作）。</p>
</td>
</tr>
<tr id="row958mcpsimp"><td class="cellrowborder" valign="top" width="30.659999999999997%" headers="mcps1.1.3.1.1 "><p id="p960mcpsimp"><a name="p960mcpsimp"></a><a name="p960mcpsimp"></a>AT+SLETX</p>
</td>
<td class="cellrowborder" valign="top" width="69.34%" headers="mcps1.1.3.1.2 "><p id="p963mcpsimp"><a name="p963mcpsimp"></a><a name="p963mcpsimp"></a>SLE常发指令。</p>
</td>
</tr>
<tr id="row964mcpsimp"><td class="cellrowborder" valign="top" width="30.659999999999997%" headers="mcps1.1.3.1.1 "><p id="p966mcpsimp"><a name="p966mcpsimp"></a><a name="p966mcpsimp"></a>AT+SLERX</p>
</td>
<td class="cellrowborder" valign="top" width="69.34%" headers="mcps1.1.3.1.2 "><p id="p969mcpsimp"><a name="p969mcpsimp"></a><a name="p969mcpsimp"></a>SLE常收指令。</p>
</td>
</tr>
<tr id="row970mcpsimp"><td class="cellrowborder" valign="top" width="30.659999999999997%" headers="mcps1.1.3.1.1 "><p id="p972mcpsimp"><a name="p972mcpsimp"></a><a name="p972mcpsimp"></a>AT+SLETRXEND</p>
</td>
<td class="cellrowborder" valign="top" width="69.34%" headers="mcps1.1.3.1.2 "><p id="p975mcpsimp"><a name="p975mcpsimp"></a><a name="p975mcpsimp"></a>SLE常发、常收停止指令。</p>
</td>
</tr>
<tr id="row976mcpsimp"><td class="cellrowborder" valign="top" width="30.659999999999997%" headers="mcps1.1.3.1.1 "><p id="p978mcpsimp"><a name="p978mcpsimp"></a><a name="p978mcpsimp"></a>AT+SLERST</p>
</td>
<td class="cellrowborder" valign="top" width="69.34%" headers="mcps1.1.3.1.2 "><p id="p981mcpsimp"><a name="p981mcpsimp"></a><a name="p981mcpsimp"></a>SLE软件复位指令。</p>
</td>
</tr>
<tr id="row982mcpsimp"><td class="cellrowborder" valign="top" width="30.659999999999997%" headers="mcps1.1.3.1.1 "><p id="p984mcpsimp"><a name="p984mcpsimp"></a><a name="p984mcpsimp"></a>AT+BTRFCALI</p>
</td>
<td class="cellrowborder" valign="top" width="69.34%" headers="mcps1.1.3.1.2 "><p id="p987mcpsimp"><a name="p987mcpsimp"></a><a name="p987mcpsimp"></a>射频自校准指令。</p>
</td>
</tr>
<tr id="row988mcpsimp"><td class="cellrowborder" valign="top" width="30.659999999999997%" headers="mcps1.1.3.1.1 "><p id="p990mcpsimp"><a name="p990mcpsimp"></a><a name="p990mcpsimp"></a>AT+BTTXLO</p>
</td>
<td class="cellrowborder" valign="top" width="69.34%" headers="mcps1.1.3.1.2 "><p id="p993mcpsimp"><a name="p993mcpsimp"></a><a name="p993mcpsimp"></a>射频单音指令。</p>
</td>
</tr>
<tr id="row1771253713110"><td class="cellrowborder" valign="top" width="30.659999999999997%" headers="mcps1.1.3.1.1 "><p id="p6216174111115"><a name="p6216174111115"></a><a name="p6216174111115"></a>AT+XOREGVAL</p>
</td>
<td class="cellrowborder" valign="top" width="69.34%" headers="mcps1.1.3.1.2 "><p id="p5712237141117"><a name="p5712237141117"></a><a name="p5712237141117"></a>读取当前校准寄存器配置指令。</p>
</td>
</tr>
<tr id="row1000mcpsimp"><td class="cellrowborder" valign="top" width="30.659999999999997%" headers="mcps1.1.3.1.1 "><p id="p1002mcpsimp"><a name="p1002mcpsimp"></a><a name="p1002mcpsimp"></a>AT+XOCALI</p>
</td>
<td class="cellrowborder" valign="top" width="69.34%" headers="mcps1.1.3.1.2 "><p id="p1006mcpsimp"><a name="p1006mcpsimp"></a><a name="p1006mcpsimp"></a>晶体频偏校准指令。</p>
</td>
</tr>
<tr id="row1007mcpsimp"><td class="cellrowborder" valign="top" width="30.659999999999997%" headers="mcps1.1.3.1.1 "><p id="p1009mcpsimp"><a name="p1009mcpsimp"></a><a name="p1009mcpsimp"></a>AT+XOSETEFUSE</p>
</td>
<td class="cellrowborder" valign="top" width="69.34%" headers="mcps1.1.3.1.2 "><p id="p1012mcpsimp"><a name="p1012mcpsimp"></a><a name="p1012mcpsimp"></a>频偏校准值写EFUSE指令。</p>
</td>
</tr>
<tr id="row46311553212"><td class="cellrowborder" valign="top" width="30.659999999999997%" headers="mcps1.1.3.1.1 "><p id="p7752179223"><a name="p7752179223"></a><a name="p7752179223"></a>AT+XOSETFLASH</p>
</td>
<td class="cellrowborder" valign="top" width="69.34%" headers="mcps1.1.3.1.2 "><p id="p46311051427"><a name="p46311051427"></a><a name="p46311051427"></a>频偏校准值写FLASH指令。</p>
</td>
</tr>
<tr id="row1756819437321"><td class="cellrowborder" valign="top" width="30.659999999999997%" headers="mcps1.1.3.1.1 "><p id="p115681343123215"><a name="p115681343123215"></a><a name="p115681343123215"></a>AT+FEMENABLE</p>
</td>
<td class="cellrowborder" valign="top" width="69.34%" headers="mcps1.1.3.1.2 "><p id="p19568643103216"><a name="p19568643103216"></a><a name="p19568643103216"></a>RT201 FEM配置使能（重启生效）。</p>
</td>
</tr>
<tr id="row1762713484211"><td class="cellrowborder" valign="top" width="30.659999999999997%" headers="mcps1.1.3.1.1 "><p id="p96275488211"><a name="p96275488211"></a><a name="p96275488211"></a>AT+SLECFORPT</p>
</td>
<td class="cellrowborder" valign="top" width="69.34%" headers="mcps1.1.3.1.2 "><p id="p562715481023"><a name="p562715481023"></a><a name="p562715481023"></a>SLE测试模式对通场景cfo上报指令。</p>
</td>
</tr>
<tr id="row1254120334380"><td class="cellrowborder" valign="top" width="30.659999999999997%" headers="mcps1.1.3.1.1 "><p id="p12542163323818"><a name="p12542163323818"></a><a name="p12542163323818"></a>AT+SLECFORSSI</p>
</td>
<td class="cellrowborder" valign="top" width="69.34%" headers="mcps1.1.3.1.2 "><p id="p1542183383818"><a name="p1542183383818"></a><a name="p1542183383818"></a>设置SLE测试模式对通场景cfo上报的rssi门限。</p>
</td>
</tr>
</tbody>
</table>

## 通用AT指令<a name="ZH-CN_TOPIC_0000001744110197"></a>

>![](public_sys-resources/icon-note.gif) **说明：** 
>若当前软件版本同时支持testsuite模式和AT模式，则两种模式串口复用，需要通过以下两条指令相互切换，如果当前版本只支持其中一种模式，则忽略本章节。



### 进入AT模式<a name="ZH-CN_TOPIC_0000001696270698"></a>

<a name="table710mcpsimp"></a>
<table><tbody><tr id="row715mcpsimp"><th class="firstcol" valign="top" width="18%" id="mcps1.1.3.1.1"><p id="p717mcpsimp"><a name="p717mcpsimp"></a><a name="p717mcpsimp"></a>格式</p>
</th>
<td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.3.1.1 "><p id="p171961046133712"><a name="p171961046133712"></a><a name="p171961046133712"></a>a testsuite_sw_at</p>
</td>
</tr>
<tr id="row721mcpsimp"><th class="firstcol" valign="top" width="18%" id="mcps1.1.3.2.1"><p id="p723mcpsimp"><a name="p723mcpsimp"></a><a name="p723mcpsimp"></a>响应</p>
</th>
<td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.3.2.1 "><p id="p725mcpsimp"><a name="p725mcpsimp"></a><a name="p725mcpsimp"></a>[TEST_PASSED!]</p>
<a name="ul15946141215233"></a><a name="ul15946141215233"></a><ul id="ul15946141215233"><li>成功：OK</li><li>失败：[TEST_FAILED : ERROR CODE]</li></ul>
</td>
</tr>
<tr id="row754mcpsimp"><th class="firstcol" valign="top" width="18%" id="mcps1.1.3.3.1"><p id="p756mcpsimp"><a name="p756mcpsimp"></a><a name="p756mcpsimp"></a>示例</p>
</th>
<td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.3.3.1 "><p id="p1447911363465"><a name="p1447911363465"></a><a name="p1447911363465"></a>a testsuite_sw_at</p>
</td>
</tr>
<tr id="row760mcpsimp"><th class="firstcol" valign="top" width="18%" id="mcps1.1.3.4.1"><p id="p762mcpsimp"><a name="p762mcpsimp"></a><a name="p762mcpsimp"></a>注意</p>
</th>
<td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.3.4.1 "><p id="p764mcpsimp"><a name="p764mcpsimp"></a><a name="p764mcpsimp"></a>上电时如果默认为testsuite模式，需要由testsuite模式切换到AT模式，测试AT指令的前置条件。</p>
</td>
</tr>
</tbody>
</table>

### 退出AT模式<a name="ZH-CN_TOPIC_0000001744150341"></a>

<a name="table710mcpsimp"></a>
<table><tbody><tr id="row715mcpsimp"><th class="firstcol" valign="top" width="17.87%" id="mcps1.1.3.1.1"><p id="p717mcpsimp"><a name="p717mcpsimp"></a><a name="p717mcpsimp"></a>格式</p>
</th>
<td class="cellrowborder" valign="top" width="82.13000000000001%" headers="mcps1.1.3.1.1 "><p id="p181961546103711"><a name="p181961546103711"></a><a name="p181961546103711"></a>AT+TESTSUITE</p>
</td>
</tr>
<tr id="row721mcpsimp"><th class="firstcol" valign="top" width="17.87%" id="mcps1.1.3.2.1"><p id="p723mcpsimp"><a name="p723mcpsimp"></a><a name="p723mcpsimp"></a>响应</p>
</th>
<td class="cellrowborder" valign="top" width="82.13000000000001%" headers="mcps1.1.3.2.1 "><a name="ul13125247182319"></a><a name="ul13125247182319"></a><ul id="ul13125247182319"><li>成功：OK</li><li>失败：ERROR</li></ul>
</td>
</tr>
<tr id="row754mcpsimp"><th class="firstcol" valign="top" width="17.87%" id="mcps1.1.3.3.1"><p id="p756mcpsimp"><a name="p756mcpsimp"></a><a name="p756mcpsimp"></a>示例</p>
</th>
<td class="cellrowborder" valign="top" width="82.13000000000001%" headers="mcps1.1.3.3.1 "><p id="p19286225185016"><a name="p19286225185016"></a><a name="p19286225185016"></a>AT+TESTSUITE</p>
</td>
</tr>
<tr id="row760mcpsimp"><th class="firstcol" valign="top" width="17.87%" id="mcps1.1.3.4.1"><p id="p762mcpsimp"><a name="p762mcpsimp"></a><a name="p762mcpsimp"></a>注意</p>
</th>
<td class="cellrowborder" valign="top" width="82.13000000000001%" headers="mcps1.1.3.4.1 "><p id="p13160036165017"><a name="p13160036165017"></a><a name="p13160036165017"></a>由AT模式切到testsuite模式。</p>
</td>
</tr>
</tbody>
</table>

## BLE射频测试相关AT指令描述<a name="ZH-CN_TOPIC_0000001744110189"></a>








### BLE测试建议流程<a name="ZH-CN_TOPIC_0000001696430158"></a>

**图 1**  BLE产测AT测试流程<a name="fig21519485327"></a>  
![](figures/BLE产测AT测试流程.png "BLE产测AT测试流程")

### BLE业务使能<a name="ZH-CN_TOPIC_0000001823127780"></a>

<a name="table170mcpsimp"></a>
<table><tbody><tr id="row175mcpsimp"><th class="firstcol" valign="top" width="18.43%" id="mcps1.1.3.1.1"><p id="p177mcpsimp"><a name="p177mcpsimp"></a><a name="p177mcpsimp"></a>格式</p>
</th>
<td class="cellrowborder" valign="top" width="81.57%" headers="mcps1.1.3.1.1 "><p id="p9326226125914"><a name="p9326226125914"></a><a name="p9326226125914"></a>AT+BLEENABLE</p>
</td>
</tr>
<tr id="row181mcpsimp"><th class="firstcol" valign="top" width="18.43%" id="mcps1.1.3.2.1"><p id="p183mcpsimp"><a name="p183mcpsimp"></a><a name="p183mcpsimp"></a>响应</p>
</th>
<td class="cellrowborder" valign="top" width="81.57%" headers="mcps1.1.3.2.1 "><p id="p347642313241"><a name="p347642313241"></a><a name="p347642313241"></a>[ACore] ble enable cbk in, result:0</p>
<p id="p117841028506"><a name="p117841028506"></a><a name="p117841028506"></a>ble enable</p>
<a name="ul1315815292311"></a><a name="ul1315815292311"></a><ul id="ul1315815292311"><li>成功：OK</li><li>失败：ERROR</li></ul>
</td>
</tr>
<tr id="row188mcpsimp"><th class="firstcol" valign="top" width="18.43%" id="mcps1.1.3.3.1"><p id="p190mcpsimp"><a name="p190mcpsimp"></a><a name="p190mcpsimp"></a>示例</p>
</th>
<td class="cellrowborder" valign="top" width="81.57%" headers="mcps1.1.3.3.1 "><p id="p532632611596"><a name="p532632611596"></a><a name="p532632611596"></a>AT+BLEENABLE</p>
<p id="p108631214219"><a name="p108631214219"></a><a name="p108631214219"></a>回复：</p>
<p id="p13536525123"><a name="p13536525123"></a><a name="p13536525123"></a>OK</p>
</td>
</tr>
<tr id="row194mcpsimp"><th class="firstcol" valign="top" width="18.43%" id="mcps1.1.3.4.1"><p id="p196mcpsimp"><a name="p196mcpsimp"></a><a name="p196mcpsimp"></a>注意</p>
</th>
<td class="cellrowborder" valign="top" width="81.57%" headers="mcps1.1.3.4.1 "><p id="p932618269598"><a name="p932618269598"></a><a name="p932618269598"></a>在进行BLE所有指令前，必须先执行BLE使能指令，使能BLE相关业务接口。</p>
<p id="p764mcpsimp"><a name="p764mcpsimp"></a><a name="p764mcpsimp"></a>本使能指令没有相应退出操作，测试BLE指令的前置条件之一。</p>
<p id="p1344886123718"><a name="p1344886123718"></a><a name="p1344886123718"></a>上电后发一次即可，重复发易出现问题。</p>
</td>
</tr>
</tbody>
</table>

### BLE注册回调<a name="ZH-CN_TOPIC_0000001744150337"></a>

<a name="table710mcpsimp"></a>
<table><tbody><tr id="row715mcpsimp"><th class="firstcol" valign="top" width="18.05%" id="mcps1.1.3.1.1"><p id="p717mcpsimp"><a name="p717mcpsimp"></a><a name="p717mcpsimp"></a>格式</p>
</th>
<td class="cellrowborder" valign="top" width="81.95%" headers="mcps1.1.3.1.1 "><p id="p719mcpsimp"><a name="p719mcpsimp"></a><a name="p719mcpsimp"></a>AT+BLEFACCALLBACK</p>
</td>
</tr>
<tr id="row721mcpsimp"><th class="firstcol" valign="top" width="18.05%" id="mcps1.1.3.2.1"><p id="p723mcpsimp"><a name="p723mcpsimp"></a><a name="p723mcpsimp"></a>响应</p>
</th>
<td class="cellrowborder" valign="top" width="81.95%" headers="mcps1.1.3.2.1 "><a name="ul1971665714232"></a><a name="ul1971665714232"></a><ul id="ul1971665714232"><li>成功：OK</li><li>失败：ERROR</li></ul>
</td>
</tr>
<tr id="row754mcpsimp"><th class="firstcol" valign="top" width="18.05%" id="mcps1.1.3.3.1"><p id="p756mcpsimp"><a name="p756mcpsimp"></a><a name="p756mcpsimp"></a>示例</p>
</th>
<td class="cellrowborder" valign="top" width="81.95%" headers="mcps1.1.3.3.1 "><p id="p1342815521314"><a name="p1342815521314"></a><a name="p1342815521314"></a>AT+BLEFACCALLBACK</p>
</td>
</tr>
<tr id="row760mcpsimp"><th class="firstcol" valign="top" width="18.05%" id="mcps1.1.3.4.1"><p id="p762mcpsimp"><a name="p762mcpsimp"></a><a name="p762mcpsimp"></a>注意</p>
</th>
<td class="cellrowborder" valign="top" width="81.95%" headers="mcps1.1.3.4.1 "><p id="p764mcpsimp"><a name="p764mcpsimp"></a><a name="p764mcpsimp"></a>BLE测试前先注册上报回调，否则业务指令没有上报状态打印。没有相应退出操作，测试BLE指令的前置条件，上电后发一次即可，重复发易出现问题。</p>
</td>
</tr>
</tbody>
</table>

### 常发指令<a name="ZH-CN_TOPIC_0000001744150333"></a>

<a name="table710mcpsimp"></a>
<table><tbody><tr id="row715mcpsimp"><th class="firstcol" valign="top" width="24%" id="mcps1.1.3.1.1"><p id="p717mcpsimp"><a name="p717mcpsimp"></a><a name="p717mcpsimp"></a>格式</p>
</th>
<td class="cellrowborder" valign="top" width="76%" headers="mcps1.1.3.1.1 "><p id="p719mcpsimp"><a name="p719mcpsimp"></a><a name="p719mcpsimp"></a>AT+BLETX=&lt;freq&gt;,&lt;payload_len&gt;,&lt;payload_type&gt;,&lt;phy&gt;</p>
</td>
</tr>
<tr id="row721mcpsimp"><th class="firstcol" valign="top" width="24%" id="mcps1.1.3.2.1"><p id="p723mcpsimp"><a name="p723mcpsimp"></a><a name="p723mcpsimp"></a>响应</p>
</th>
<td class="cellrowborder" valign="top" width="76%" headers="mcps1.1.3.2.1 "><a name="ul0492142418"></a><a name="ul0492142418"></a><ul id="ul0492142418"><li>成功：OK<p id="p7269135910550"><a name="p7269135910550"></a><a name="p7269135910550"></a>status：0x0</p>
<p id="p1326811151872"><a name="p1326811151872"></a><a name="p1326811151872"></a>注意：status为非0值表示该指令执行出错。</p>
</li><li>失败：ERROR<p id="p478792610912"><a name="p478792610912"></a><a name="p478792610912"></a>ERROR原因：指令不支持或格式错误。</p>
</li></ul>
</td>
</tr>
<tr id="row728mcpsimp"><th class="firstcol" valign="top" width="24%" id="mcps1.1.3.3.1"><p id="p730mcpsimp"><a name="p730mcpsimp"></a><a name="p730mcpsimp"></a>参数说明</p>
</th>
<td class="cellrowborder" valign="top" width="76%" headers="mcps1.1.3.3.1 "><a name="ul43281136162820"></a><a name="ul43281136162820"></a><ul id="ul43281136162820"><li>&lt;freq&gt;：发送频点<p id="p13339165516457"><a name="p13339165516457"></a><a name="p13339165516457"></a>发送频率范围是（2N+2402）MHz，其中N即freq，范围0～39，频率有效范围为2402MHz～2480MHz。</p>
</li><li>&lt;payload_len&gt;：包长度<p id="p737mcpsimp"><a name="p737mcpsimp"></a><a name="p737mcpsimp"></a>37～255 Byte，蓝牙Core_v5.3协议定义，如<a href="#fig1312932419464">图1</a>所示。</p>
</li><li>&lt;payload_type&gt;：发包模式<p id="p1514317493432"><a name="p1514317493432"></a><a name="p1514317493432"></a>0：PRBS9</p>
<p id="p1714344914312"><a name="p1714344914312"></a><a name="p1714344914312"></a>1：11110000</p>
<p id="p5143134913437"><a name="p5143134913437"></a><a name="p5143134913437"></a>2：10101010</p>
<p id="p191441749104314"><a name="p191441749104314"></a><a name="p191441749104314"></a>3：PRBS15</p>
<p id="p1214454934316"><a name="p1214454934316"></a><a name="p1214454934316"></a>4：11111111</p>
<p id="p614412499435"><a name="p614412499435"></a><a name="p614412499435"></a>5：00000000</p>
<p id="p19144349124316"><a name="p19144349124316"></a><a name="p19144349124316"></a>6：00001111</p>
<p id="p2144549164310"><a name="p2144549164310"></a><a name="p2144549164310"></a>7：01010101</p>
</li><li>&lt;phy&gt;：PHY类型<p id="p750mcpsimp"><a name="p750mcpsimp"></a><a name="p750mcpsimp"></a>1：1M PHY</p>
<p id="p751mcpsimp"><a name="p751mcpsimp"></a><a name="p751mcpsimp"></a>2：2M PHY</p>
<p id="p752mcpsimp"><a name="p752mcpsimp"></a><a name="p752mcpsimp"></a>3：Coded PHY with S=8 data coding</p>
<p id="p753mcpsimp"><a name="p753mcpsimp"></a><a name="p753mcpsimp"></a>4：Coded PHY with S=2 data coding</p>
</li></ul>
</td>
</tr>
<tr id="row754mcpsimp"><th class="firstcol" valign="top" width="24%" id="mcps1.1.3.4.1"><p id="p756mcpsimp"><a name="p756mcpsimp"></a><a name="p756mcpsimp"></a>示例</p>
</th>
<td class="cellrowborder" valign="top" width="76%" headers="mcps1.1.3.4.1 "><p id="p758mcpsimp"><a name="p758mcpsimp"></a><a name="p758mcpsimp"></a>AT+BLETX=0,255,0,1</p>
</td>
</tr>
<tr id="row760mcpsimp"><th class="firstcol" valign="top" width="24%" id="mcps1.1.3.5.1"><p id="p762mcpsimp"><a name="p762mcpsimp"></a><a name="p762mcpsimp"></a>注意</p>
</th>
<td class="cellrowborder" valign="top" width="76%" headers="mcps1.1.3.5.1 "><p id="p764mcpsimp"><a name="p764mcpsimp"></a><a name="p764mcpsimp"></a>参数为十进制,中间“,”不可省略。</p>
</td>
</tr>
</tbody>
</table>

**图 1**  BLE 非编码测试包结构<a name="fig1312932419464"></a>  
![](figures/BLE-非编码测试包结构.png "BLE-非编码测试包结构")

### 常收指令<a name="ZH-CN_TOPIC_0000001744110205"></a>

<a name="table300mcpsimp"></a>
<table><tbody><tr id="row305mcpsimp"><th class="firstcol" valign="top" width="21.55%" id="mcps1.1.3.1.1"><p id="p307mcpsimp"><a name="p307mcpsimp"></a><a name="p307mcpsimp"></a>格式</p>
</th>
<td class="cellrowborder" valign="top" width="78.45%" headers="mcps1.1.3.1.1 "><p id="p309mcpsimp"><a name="p309mcpsimp"></a><a name="p309mcpsimp"></a>AT+BLERX=&lt;freq&gt;,&lt;phy&gt;,&lt;modulation_index&gt;</p>
</td>
</tr>
<tr id="row311mcpsimp"><th class="firstcol" valign="top" width="21.55%" id="mcps1.1.3.2.1"><p id="p313mcpsimp"><a name="p313mcpsimp"></a><a name="p313mcpsimp"></a>响应</p>
</th>
<td class="cellrowborder" valign="top" width="78.45%" headers="mcps1.1.3.2.1 "><a name="ul0492142418"></a><a name="ul0492142418"></a><ul id="ul0492142418"><li>成功：OK<p id="p7269135910550"><a name="p7269135910550"></a><a name="p7269135910550"></a>status：0x0</p>
<p id="p6259744077"><a name="p6259744077"></a><a name="p6259744077"></a>注意：status为非0值表示该指令执行出错。</p>
</li><li>失败：ERROR<p id="p478792610912"><a name="p478792610912"></a><a name="p478792610912"></a>ERROR原因：指令不支持或格式错误。</p>
</li></ul>
</td>
</tr>
<tr id="row318mcpsimp"><th class="firstcol" valign="top" width="21.55%" id="mcps1.1.3.3.1"><p id="p320mcpsimp"><a name="p320mcpsimp"></a><a name="p320mcpsimp"></a>参数说明</p>
</th>
<td class="cellrowborder" valign="top" width="78.45%" headers="mcps1.1.3.3.1 "><a name="ul89431242152913"></a><a name="ul89431242152913"></a><ul id="ul89431242152913"><li>&lt;freq&gt;：发送频点<p id="p324mcpsimp"><a name="p324mcpsimp"></a><a name="p324mcpsimp"></a>发送频率范围是（2N+2402）MHz，其中N即freq，范围0～39，频率有效范围2402MHz～2480MHz。</p>
</li></ul>
<a name="ul1699614419296"></a><a name="ul1699614419296"></a><ul id="ul1699614419296"><li>&lt;phy&gt;：PHY类型<p id="p327mcpsimp"><a name="p327mcpsimp"></a><a name="p327mcpsimp"></a>1:1M PHY</p>
<p id="p328mcpsimp"><a name="p328mcpsimp"></a><a name="p328mcpsimp"></a>2:2M PHY</p>
<p id="p329mcpsimp"><a name="p329mcpsimp"></a><a name="p329mcpsimp"></a>3:Coded PHY with S=8 data coding</p>
<p id="p330mcpsimp"><a name="p330mcpsimp"></a><a name="p330mcpsimp"></a>4:Coded PHY with S=2 data coding</p>
</li></ul>
<a name="ul118264142918"></a><a name="ul118264142918"></a><ul id="ul118264142918"><li>&lt; modulation_index &gt;：调制指数<p id="p333mcpsimp"><a name="p333mcpsimp"></a><a name="p333mcpsimp"></a>0:Assume transmitter will have a standard modulation index</p>
<p id="p334mcpsimp"><a name="p334mcpsimp"></a><a name="p334mcpsimp"></a>1:Assume transmitter will have a stable modulation index</p>
<p id="p335mcpsimp"><a name="p335mcpsimp"></a><a name="p335mcpsimp"></a>2～256:Reserved</p>
</li></ul>
</td>
</tr>
<tr id="row336mcpsimp"><th class="firstcol" valign="top" width="21.55%" id="mcps1.1.3.4.1"><p id="p338mcpsimp"><a name="p338mcpsimp"></a><a name="p338mcpsimp"></a>示例</p>
</th>
<td class="cellrowborder" valign="top" width="78.45%" headers="mcps1.1.3.4.1 "><p id="p340mcpsimp"><a name="p340mcpsimp"></a><a name="p340mcpsimp"></a>AT+BLERX=0,1,0</p>
</td>
</tr>
<tr id="row342mcpsimp"><th class="firstcol" valign="top" width="21.55%" id="mcps1.1.3.5.1"><p id="p344mcpsimp"><a name="p344mcpsimp"></a><a name="p344mcpsimp"></a>注意</p>
</th>
<td class="cellrowborder" valign="top" width="78.45%" headers="mcps1.1.3.5.1 "><p id="p346mcpsimp"><a name="p346mcpsimp"></a><a name="p346mcpsimp"></a>参数为十进制,中间“,”不可省略。</p>
</td>
</tr>
</tbody>
</table>

### 常发常收停止指令<a name="ZH-CN_TOPIC_0000001744150329"></a>

<a name="table766mcpsimp"></a>
<table><tbody><tr id="row771mcpsimp"><th class="firstcol" valign="top" width="18%" id="mcps1.1.3.1.1"><p id="p773mcpsimp"><a name="p773mcpsimp"></a><a name="p773mcpsimp"></a>格式</p>
</th>
<td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.3.1.1 "><p id="p775mcpsimp"><a name="p775mcpsimp"></a><a name="p775mcpsimp"></a>AT+BLETRXEND</p>
</td>
</tr>
<tr id="row777mcpsimp"><th class="firstcol" valign="top" width="18%" id="mcps1.1.3.2.1"><p id="p779mcpsimp"><a name="p779mcpsimp"></a><a name="p779mcpsimp"></a>响应</p>
</th>
<td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.3.2.1 "><a name="ul0492142418"></a><a name="ul0492142418"></a><ul id="ul0492142418"><li>成功：OK<p id="p7269135910550"><a name="p7269135910550"></a><a name="p7269135910550"></a>status：0x0, num_packets:0x3e8</p>
</li><li>失败：ERROR</li></ul>
</td>
</tr>
<tr id="row784mcpsimp"><th class="firstcol" valign="top" width="18%" id="mcps1.1.3.3.1"><p id="p786mcpsimp"><a name="p786mcpsimp"></a><a name="p786mcpsimp"></a>示例</p>
</th>
<td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.3.3.1 "><p id="p788mcpsimp"><a name="p788mcpsimp"></a><a name="p788mcpsimp"></a>AT+BLETRXEND</p>
<p id="p19282152019551"><a name="p19282152019551"></a><a name="p19282152019551"></a>回复：</p>
<p id="p738851413553"><a name="p738851413553"></a><a name="p738851413553"></a>OK</p>
<p id="p193881147559"><a name="p193881147559"></a><a name="p193881147559"></a>status:0x0, num_packets:0x3e8</p>
<p id="p20977240165510"><a name="p20977240165510"></a><a name="p20977240165510"></a>说明：在RX结束后发送收包指令得到回复num_packets:0x3e8说明收到1000包。</p>
</td>
</tr>
<tr id="row790mcpsimp"><th class="firstcol" valign="top" width="18%" id="mcps1.1.3.4.1"><p id="p792mcpsimp"><a name="p792mcpsimp"></a><a name="p792mcpsimp"></a>注意</p>
</th>
<td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.3.4.1 "><p id="p1869013267417"><a name="p1869013267417"></a><a name="p1869013267417"></a>停止RX时保证在仪表发完包后执行。</p>
<p id="p794mcpsimp"><a name="p794mcpsimp"></a><a name="p794mcpsimp"></a>num_packet在RX结束后关注， num_packet：收包数。</p>
<p id="p834mcpsimp"><a name="p834mcpsimp"></a><a name="p834mcpsimp"></a>为避免丢包，停止RX时要保证在仪表完成发包后执行。</p>
</td>
</tr>
</tbody>
</table>

### BLE 复位指令<a name="ZH-CN_TOPIC_0000001696270702"></a>

<a name="table170mcpsimp"></a>
<table><tbody><tr id="row175mcpsimp"><th class="firstcol" valign="top" width="17.65%" id="mcps1.1.3.1.1"><p id="p177mcpsimp"><a name="p177mcpsimp"></a><a name="p177mcpsimp"></a>格式</p>
</th>
<td class="cellrowborder" valign="top" width="82.35%" headers="mcps1.1.3.1.1 "><p id="p179mcpsimp"><a name="p179mcpsimp"></a><a name="p179mcpsimp"></a>AT+BLERST</p>
</td>
</tr>
<tr id="row181mcpsimp"><th class="firstcol" valign="top" width="17.65%" id="mcps1.1.3.2.1"><p id="p183mcpsimp"><a name="p183mcpsimp"></a><a name="p183mcpsimp"></a>响应</p>
</th>
<td class="cellrowborder" valign="top" width="82.35%" headers="mcps1.1.3.2.1 "><a name="ul0492142418"></a><a name="ul0492142418"></a><ul id="ul0492142418"><li>成功：OK<p id="p7269135910550"><a name="p7269135910550"></a><a name="p7269135910550"></a>status：0x0</p>
</li><li>失败：ERROR</li></ul>
</td>
</tr>
<tr id="row188mcpsimp"><th class="firstcol" valign="top" width="17.65%" id="mcps1.1.3.3.1"><p id="p190mcpsimp"><a name="p190mcpsimp"></a><a name="p190mcpsimp"></a>示例</p>
</th>
<td class="cellrowborder" valign="top" width="82.35%" headers="mcps1.1.3.3.1 "><p id="p192mcpsimp"><a name="p192mcpsimp"></a><a name="p192mcpsimp"></a>AT+BLERST</p>
</td>
</tr>
<tr id="row194mcpsimp"><th class="firstcol" valign="top" width="17.65%" id="mcps1.1.3.4.1"><p id="p196mcpsimp"><a name="p196mcpsimp"></a><a name="p196mcpsimp"></a>注意</p>
</th>
<td class="cellrowborder" valign="top" width="82.35%" headers="mcps1.1.3.4.1 "><p id="p189327169570"><a name="p189327169570"></a><a name="p189327169570"></a>BLE软件复位指令，在进行BLE RF测试前先发BLE复位指令恢复软件状态。</p>
</td>
</tr>
</tbody>
</table>

## SLE射频测试相关AT指令描述<a name="ZH-CN_TOPIC_0000001696270694"></a>








### SLE测试建议流程<a name="ZH-CN_TOPIC_0000001696270690"></a>

**图 1**  SLE产测AT测试流程<a name="fig141263475017"></a>  
![](figures/SLE产测AT测试流程.png "SLE产测AT测试流程")

### SLE使能指令<a name="ZH-CN_TOPIC_0000001696430162"></a>

<a name="table170mcpsimp"></a>
<table><tbody><tr id="row175mcpsimp"><th class="firstcol" valign="top" width="18%" id="mcps1.1.3.1.1"><p id="p177mcpsimp"><a name="p177mcpsimp"></a><a name="p177mcpsimp"></a>格式</p>
</th>
<td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.3.1.1 "><p id="p9326226125914"><a name="p9326226125914"></a><a name="p9326226125914"></a>AT+SLEENABLE</p>
</td>
</tr>
<tr id="row181mcpsimp"><th class="firstcol" valign="top" width="18%" id="mcps1.1.3.2.1"><p id="p183mcpsimp"><a name="p183mcpsimp"></a><a name="p183mcpsimp"></a>响应</p>
</th>
<td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.3.2.1 "><p id="p347642313241"><a name="p347642313241"></a><a name="p347642313241"></a>[ACore] sle enable cbk in, result:0</p>
<p id="p17476202322416"><a name="p17476202322416"></a><a name="p17476202322416"></a>[ACore] sle device discovery in, action:0</p>
<p id="p117841028506"><a name="p117841028506"></a><a name="p117841028506"></a>sle enable</p>
<a name="ul122864642510"></a><a name="ul122864642510"></a><ul id="ul122864642510"><li>成功：OK</li><li>失败：ERROR</li></ul>
</td>
</tr>
<tr id="row188mcpsimp"><th class="firstcol" valign="top" width="18%" id="mcps1.1.3.3.1"><p id="p190mcpsimp"><a name="p190mcpsimp"></a><a name="p190mcpsimp"></a>示例</p>
</th>
<td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.3.3.1 "><p id="p532632611596"><a name="p532632611596"></a><a name="p532632611596"></a>AT+SLEENABLE</p>
<p id="p108631214219"><a name="p108631214219"></a><a name="p108631214219"></a>回复：</p>
<p id="p13536525123"><a name="p13536525123"></a><a name="p13536525123"></a>OK</p>
</td>
</tr>
<tr id="row194mcpsimp"><th class="firstcol" valign="top" width="18%" id="mcps1.1.3.4.1"><p id="p196mcpsimp"><a name="p196mcpsimp"></a><a name="p196mcpsimp"></a>注意</p>
</th>
<td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.3.4.1 "><p id="p932618269598"><a name="p932618269598"></a><a name="p932618269598"></a>在进行SLE所有指令前，必须先执行SLE使能指令。</p>
<p id="p764mcpsimp"><a name="p764mcpsimp"></a><a name="p764mcpsimp"></a>本使能指令没有相应退出操作，测试SLE指令的前置条件之一。</p>
<p id="p1344886123718"><a name="p1344886123718"></a><a name="p1344886123718"></a>上电后发一次即可，重复发易出现问题。</p>
</td>
</tr>
</tbody>
</table>

### SLE注册回调<a name="ZH-CN_TOPIC_0000001696430166"></a>

<a name="table710mcpsimp"></a>
<table><tbody><tr id="row715mcpsimp"><th class="firstcol" valign="top" width="18%" id="mcps1.1.3.1.1"><p id="p717mcpsimp"><a name="p717mcpsimp"></a><a name="p717mcpsimp"></a>格式</p>
</th>
<td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.3.1.1 "><p id="p719mcpsimp"><a name="p719mcpsimp"></a><a name="p719mcpsimp"></a>AT+SLEFACCALLBACK</p>
</td>
</tr>
<tr id="row721mcpsimp"><th class="firstcol" valign="top" width="18%" id="mcps1.1.3.2.1"><p id="p723mcpsimp"><a name="p723mcpsimp"></a><a name="p723mcpsimp"></a>响应</p>
</th>
<td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.3.2.1 "><p id="p329918431903"><a name="p329918431903"></a><a name="p329918431903"></a>[AT] sle factory register cbks.</p>
<a name="ul1814913916254"></a><a name="ul1814913916254"></a><ul id="ul1814913916254"><li>成功：OK</li><li>失败：ERROR</li></ul>
</td>
</tr>
<tr id="row754mcpsimp"><th class="firstcol" valign="top" width="18%" id="mcps1.1.3.3.1"><p id="p756mcpsimp"><a name="p756mcpsimp"></a><a name="p756mcpsimp"></a>示例</p>
</th>
<td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.3.3.1 "><p id="p1342815521314"><a name="p1342815521314"></a><a name="p1342815521314"></a>AT+SLEFACCALLBACK</p>
</td>
</tr>
<tr id="row760mcpsimp"><th class="firstcol" valign="top" width="18%" id="mcps1.1.3.4.1"><p id="p762mcpsimp"><a name="p762mcpsimp"></a><a name="p762mcpsimp"></a>注意</p>
</th>
<td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.3.4.1 "><p id="p764mcpsimp"><a name="p764mcpsimp"></a><a name="p764mcpsimp"></a>SLE测试前先注册回调，没有相应退出操作，测试SLE指令的前置条件之一。</p>
<p id="p434041243710"><a name="p434041243710"></a><a name="p434041243710"></a>上电后发一次即可，重复发易出现问题。</p>
</td>
</tr>
</tbody>
</table>

### 常发指令<a name="ZH-CN_TOPIC_0000001744150345"></a>

<a name="table836mcpsimp"></a>
<table><tbody><tr id="row841mcpsimp"><th class="firstcol" valign="top" width="18%" id="mcps1.1.3.1.1"><p id="p843mcpsimp"><a name="p843mcpsimp"></a><a name="p843mcpsimp"></a>格式</p>
</th>
<td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.3.1.1 "><p id="p845mcpsimp"><a name="p845mcpsimp"></a><a name="p845mcpsimp"></a>AT+SLETX=&lt;freq&gt;,&lt;pwr&gt;,&lt;payload_len&gt;,&lt;payload_type&gt;,&lt;phy&gt;,&lt;format&gt;,&lt;TX_rate&gt;,&lt;pilot&gt;,&lt;polar&gt;,&lt;interval&gt;</p>
</td>
</tr>
<tr id="row847mcpsimp"><th class="firstcol" valign="top" width="18%" id="mcps1.1.3.2.1"><p id="p849mcpsimp"><a name="p849mcpsimp"></a><a name="p849mcpsimp"></a>响应</p>
</th>
<td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.3.2.1 "><a name="ul557114134252"></a><a name="ul557114134252"></a><ul id="ul557114134252"><li>成功：OK<p id="p5804161818250"><a name="p5804161818250"></a><a name="p5804161818250"></a>general event report opcode[04]</p>
<p id="p380481862514"><a name="p380481862514"></a><a name="p380481862514"></a>status：0</p>
<p id="p621816151389"><a name="p621816151389"></a><a name="p621816151389"></a>注意：status为非0值表示该指令执行出错。</p>
<p id="p1156641719819"><a name="p1156641719819"></a><a name="p1156641719819"></a>常见场景，重复发送（不生效）status：b</p>
</li><li>失败：ERROR</li></ul>
<p id="p478792610912"><a name="p478792610912"></a><a name="p478792610912"></a>ERROR原因：指令不支持或格式错误。</p>
</td>
</tr>
<tr id="row854mcpsimp"><th class="firstcol" valign="top" width="18%" id="mcps1.1.3.3.1"><p id="p856mcpsimp"><a name="p856mcpsimp"></a><a name="p856mcpsimp"></a>参数说明</p>
</th>
<td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.3.3.1 "><a name="ul5234101317310"></a><a name="ul5234101317310"></a><ul id="ul5234101317310"><li>&lt;freq&gt;：发送频点<p id="p14713165513359"><a name="p14713165513359"></a><a name="p14713165513359"></a>0～78：射频信道号依次对应对应2402MHz～2480MHz，详见<a href="星闪协议频点表.md#fig12728841183211">图1</a>和<a href="星闪协议频点表.md#fig3784926143510">图2</a>。</p>
</li><li>&lt;pwr&gt;: 发送功率<a name="ul11870527173711"></a><a name="ul11870527173711"></a><ul id="ul11870527173711"><li>GFSK：<p id="p19621558016"><a name="p19621558016"></a><a name="p19621558016"></a>0：-4dBm</p>
<p id="p864mcpsimp"><a name="p864mcpsimp"></a><a name="p864mcpsimp"></a>1：-2dBm</p>
<p id="p865mcpsimp"><a name="p865mcpsimp"></a><a name="p865mcpsimp"></a>2：0dBm</p>
<p id="p866mcpsimp"><a name="p866mcpsimp"></a><a name="p866mcpsimp"></a>3：2dBm</p>
<p id="p867mcpsimp"><a name="p867mcpsimp"></a><a name="p867mcpsimp"></a>4：4dBm</p>
<p id="p868mcpsimp"><a name="p868mcpsimp"></a><a name="p868mcpsimp"></a>5：6dBm</p>
</li><li>QPSK/8PSK：<p id="p167149351203"><a name="p167149351203"></a><a name="p167149351203"></a>0：-8dBm</p>
<p id="p57141335802"><a name="p57141335802"></a><a name="p57141335802"></a>1：-6dBm</p>
<p id="p271453515017"><a name="p271453515017"></a><a name="p271453515017"></a>2：-4dBm</p>
<p id="p1871413511018"><a name="p1871413511018"></a><a name="p1871413511018"></a>3：-2dBm</p>
<p id="p17714103518016"><a name="p17714103518016"></a><a name="p17714103518016"></a>4：0dBm</p>
<p id="p67141135401"><a name="p67141135401"></a><a name="p67141135401"></a>5：2dBm</p>
</li></ul>
</li><li>&lt;payload_len&gt;：包长度<p id="p871mcpsimp"><a name="p871mcpsimp"></a><a name="p871mcpsimp"></a>根据星闪协议，包长范围是0～255Byte</p>
</li><li>&lt;payload_type&gt;：发包模式<p id="p874mcpsimp"><a name="p874mcpsimp"></a><a name="p874mcpsimp"></a>0：PRBS9</p>
<p id="p875mcpsimp"><a name="p875mcpsimp"></a><a name="p875mcpsimp"></a>1：11110000</p>
<p id="p876mcpsimp"><a name="p876mcpsimp"></a><a name="p876mcpsimp"></a>2：10101010</p>
<p id="p877mcpsimp"><a name="p877mcpsimp"></a><a name="p877mcpsimp"></a>3：PRBS15</p>
<p id="p878mcpsimp"><a name="p878mcpsimp"></a><a name="p878mcpsimp"></a>4：11111111</p>
<p id="p879mcpsimp"><a name="p879mcpsimp"></a><a name="p879mcpsimp"></a>5：00000000</p>
<p id="p880mcpsimp"><a name="p880mcpsimp"></a><a name="p880mcpsimp"></a>6：00001111</p>
<p id="p881mcpsimp"><a name="p881mcpsimp"></a><a name="p881mcpsimp"></a>7：01010101</p>
</li><li>&lt;phy&gt;：PHY类型<p id="p884mcpsimp"><a name="p884mcpsimp"></a><a name="p884mcpsimp"></a>0: 1M</p>
<p id="p885mcpsimp"><a name="p885mcpsimp"></a><a name="p885mcpsimp"></a>1: 2M</p>
<p id="p886mcpsimp"><a name="p886mcpsimp"></a><a name="p886mcpsimp"></a>4: 4M</p>
</li><li>&lt;format&gt;：帧类型<p id="p311455218217"><a name="p311455218217"></a><a name="p311455218217"></a>0：无线帧类型1</p>
<p id="p131147524210"><a name="p131147524210"></a><a name="p131147524210"></a>2：无线帧类型2</p>
<p id="p32267235513"><a name="p32267235513"></a><a name="p32267235513"></a>说明：无线帧类型1对应GFSK速率，无线帧类型2对应PSK速率</p>
</li><li>&lt;TX_rate&gt;：速率<p id="p894mcpsimp"><a name="p894mcpsimp"></a><a name="p894mcpsimp"></a>0：GFSK</p>
<p id="p895mcpsimp"><a name="p895mcpsimp"></a><a name="p895mcpsimp"></a>2：QPSK</p>
<p id="p896mcpsimp"><a name="p896mcpsimp"></a><a name="p896mcpsimp"></a>3：8PSK</p>
</li><li>&lt;pilot&gt;：导频<p id="p899mcpsimp"><a name="p899mcpsimp"></a><a name="p899mcpsimp"></a>0：无导频</p>
<p id="p900mcpsimp"><a name="p900mcpsimp"></a><a name="p900mcpsimp"></a>1：8:1</p>
<p id="p901mcpsimp"><a name="p901mcpsimp"></a><a name="p901mcpsimp"></a>2：4:1</p>
<p id="p902mcpsimp"><a name="p902mcpsimp"></a><a name="p902mcpsimp"></a>3：16:1</p>
</li><li>&lt;polar&gt;: 编码<p id="p905mcpsimp"><a name="p905mcpsimp"></a><a name="p905mcpsimp"></a>0：无编码</p>
<p id="p907mcpsimp"><a name="p907mcpsimp"></a><a name="p907mcpsimp"></a>2：3/4</p>
</li><li>&lt;interval&gt;: 间隔<p id="p911mcpsimp"><a name="p911mcpsimp"></a><a name="p911mcpsimp"></a>经验证间隔需要[6,255] （单位125μs）, payload length为255Byte时，建议interval设置为50。</p>
</li></ul>
</td>
</tr>
<tr id="row912mcpsimp"><th class="firstcol" valign="top" width="18%" id="mcps1.1.3.4.1"><p id="p914mcpsimp"><a name="p914mcpsimp"></a><a name="p914mcpsimp"></a>示例</p>
</th>
<td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.3.4.1 "><p id="p916mcpsimp"><a name="p916mcpsimp"></a><a name="p916mcpsimp"></a>AT+SLETX=0,5,255,0,1,2,2,0,0,50</p>
</td>
</tr>
<tr id="row918mcpsimp"><th class="firstcol" valign="top" width="18%" id="mcps1.1.3.5.1"><p id="p920mcpsimp"><a name="p920mcpsimp"></a><a name="p920mcpsimp"></a>注意</p>
</th>
<td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.3.5.1 "><p id="p922mcpsimp"><a name="p922mcpsimp"></a><a name="p922mcpsimp"></a>参数均为十进制,中间“,”不可省略。</p>
</td>
</tr>
</tbody>
</table>

### 常收指令<a name="ZH-CN_TOPIC_0000001696430154"></a>

<a name="table608mcpsimp"></a>
<table><tbody><tr id="row613mcpsimp"><th class="firstcol" valign="top" width="18%" id="mcps1.1.3.1.1"><p id="p615mcpsimp"><a name="p615mcpsimp"></a><a name="p615mcpsimp"></a>格式</p>
</th>
<td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.3.1.1 "><p id="p617mcpsimp"><a name="p617mcpsimp"></a><a name="p617mcpsimp"></a>AT+SLERX=&lt;freq&gt;,&lt;phy&gt;,&lt;format&gt;,&lt;pilot&gt;,&lt;interval&gt;</p>
</td>
</tr>
<tr id="row619mcpsimp"><th class="firstcol" valign="top" width="18%" id="mcps1.1.3.2.1"><p id="p621mcpsimp"><a name="p621mcpsimp"></a><a name="p621mcpsimp"></a>响应</p>
</th>
<td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.3.2.1 "><a name="ul169551831172513"></a><a name="ul169551831172513"></a><ul id="ul169551831172513"><li>成功：OK<p id="p10384437142516"><a name="p10384437142516"></a><a name="p10384437142516"></a>status：0</p>
<p id="p621816151389"><a name="p621816151389"></a><a name="p621816151389"></a>注意：status为非0值表示该指令执行出错。</p>
<p id="p1156641719819"><a name="p1156641719819"></a><a name="p1156641719819"></a>常见场景，重复发送（不生效）status：b</p>
</li><li>失败：ERROR</li></ul>
</td>
</tr>
<tr id="row626mcpsimp"><th class="firstcol" valign="top" width="18%" id="mcps1.1.3.3.1"><p id="p628mcpsimp"><a name="p628mcpsimp"></a><a name="p628mcpsimp"></a>参数说明</p>
</th>
<td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.3.3.1 "><a name="ul2073045574113"></a><a name="ul2073045574113"></a><ul id="ul2073045574113"><li>&lt;freq&gt;：发送频点<p id="p1801043154110"><a name="p1801043154110"></a><a name="p1801043154110"></a>0～78：射频信道号依次对应对应2402～2480 MHz，详见<a href="星闪协议频点表.md#fig12728841183211">图1</a>和<a href="星闪协议频点表.md#fig3784926143510">图2</a></p>
</li><li>&lt;phy&gt;：PHY类型<p id="p635mcpsimp"><a name="p635mcpsimp"></a><a name="p635mcpsimp"></a>0: 1M</p>
<p id="p636mcpsimp"><a name="p636mcpsimp"></a><a name="p636mcpsimp"></a>1: 2M</p>
<p id="p637mcpsimp"><a name="p637mcpsimp"></a><a name="p637mcpsimp"></a>4: 4M</p>
</li><li>&lt;format&gt;：帧类型<p id="p95001325958"><a name="p95001325958"></a><a name="p95001325958"></a>0：无线帧类型1</p>
<p id="p55006251251"><a name="p55006251251"></a><a name="p55006251251"></a>2：无线帧类型2</p>
<p id="p32267235513"><a name="p32267235513"></a><a name="p32267235513"></a>说明：无线帧类型1对应GFSK速率，无线帧类型2对应PSK速率</p>
</li><li>&lt;pilot&gt;：导频<p id="p645mcpsimp"><a name="p645mcpsimp"></a><a name="p645mcpsimp"></a>0：无导频</p>
<p id="p646mcpsimp"><a name="p646mcpsimp"></a><a name="p646mcpsimp"></a>1：1:1</p>
<p id="p647mcpsimp"><a name="p647mcpsimp"></a><a name="p647mcpsimp"></a>2：4:1</p>
<p id="p648mcpsimp"><a name="p648mcpsimp"></a><a name="p648mcpsimp"></a>3：16:1</p>
</li><li>&lt;interval&gt;：间隔<p id="p911mcpsimp"><a name="p911mcpsimp"></a><a name="p911mcpsimp"></a>经验证间隔需要[6,255] （单位125μs）, payload length为255Byte时，建议interval设置为50。</p>
</li></ul>
</td>
</tr>
<tr id="row652mcpsimp"><th class="firstcol" valign="top" width="18%" id="mcps1.1.3.4.1"><p id="p654mcpsimp"><a name="p654mcpsimp"></a><a name="p654mcpsimp"></a>示例</p>
</th>
<td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.3.4.1 "><p id="p656mcpsimp"><a name="p656mcpsimp"></a><a name="p656mcpsimp"></a>AT+SLERX=0,0,0,0,50</p>
</td>
</tr>
<tr id="row658mcpsimp"><th class="firstcol" valign="top" width="18%" id="mcps1.1.3.5.1"><p id="p660mcpsimp"><a name="p660mcpsimp"></a><a name="p660mcpsimp"></a>注意</p>
</th>
<td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.3.5.1 "><p id="p662mcpsimp"><a name="p662mcpsimp"></a><a name="p662mcpsimp"></a>参数为十进制,中间“,”不可省略。</p>
</td>
</tr>
</tbody>
</table>

### 常发常收停止指令<a name="ZH-CN_TOPIC_0000001744110173"></a>

<a name="table796mcpsimp"></a>
<table><tbody><tr id="row801mcpsimp"><th class="firstcol" valign="top" width="18.029999999999998%" id="mcps1.1.3.1.1"><p id="p803mcpsimp"><a name="p803mcpsimp"></a><a name="p803mcpsimp"></a>格式</p>
</th>
<td class="cellrowborder" valign="top" width="81.97%" headers="mcps1.1.3.1.1 "><p id="p805mcpsimp"><a name="p805mcpsimp"></a><a name="p805mcpsimp"></a>AT+SLETRXEND</p>
</td>
</tr>
<tr id="row807mcpsimp"><th class="firstcol" valign="top" width="18.029999999999998%" id="mcps1.1.3.2.1"><p id="p809mcpsimp"><a name="p809mcpsimp"></a><a name="p809mcpsimp"></a>响应</p>
</th>
<td class="cellrowborder" valign="top" width="81.97%" headers="mcps1.1.3.2.1 "><a name="ul243013532612"></a><a name="ul243013532612"></a><ul id="ul243013532612"><li>成功：OK<p id="p18493010102618"><a name="p18493010102618"></a><a name="p18493010102618"></a>general event report opcode[06]</p>
<p id="p64931110102619"><a name="p64931110102619"></a><a name="p64931110102619"></a>status：0,num_packet:3e8,rssi:81</p>
<p id="p621816151389"><a name="p621816151389"></a><a name="p621816151389"></a>注意：status为非0值表示该指令执行出错。</p>
<p id="p1156641719819"><a name="p1156641719819"></a><a name="p1156641719819"></a>常见场景，重复发送（不生效）status：b</p>
</li><li>失败：ERROR</li></ul>
</td>
</tr>
<tr id="row824mcpsimp"><th class="firstcol" valign="top" width="18.029999999999998%" id="mcps1.1.3.3.1"><p id="p826mcpsimp"><a name="p826mcpsimp"></a><a name="p826mcpsimp"></a>示例</p>
</th>
<td class="cellrowborder" valign="top" width="81.97%" headers="mcps1.1.3.3.1 "><p id="p941392314720"><a name="p941392314720"></a><a name="p941392314720"></a>AT+SLETRXEND</p>
<p id="p541311235715"><a name="p541311235715"></a><a name="p541311235715"></a>回复：</p>
<p id="p941317231572"><a name="p941317231572"></a><a name="p941317231572"></a>OK</p>
<p id="p641319231272"><a name="p641319231272"></a><a name="p641319231272"></a>sle radio frequency tx|rx end status:0x0,num_packet:0x3e8,rssi:0x81</p>
<p id="p2413323272"><a name="p2413323272"></a><a name="p2413323272"></a>说明：如仪表发1000包后发结束指令，测试RX的收报数为1000包（0x3e8），测试RX的接收能量rssi为-127dbm（0x81）</p>
<p id="p1524191765310"><a name="p1524191765310"></a><a name="p1524191765310"></a>如果发TX后执行结束指令，则收报数为0， rssi为0。</p>
</td>
</tr>
<tr id="row830mcpsimp"><th class="firstcol" valign="top" width="18.029999999999998%" id="mcps1.1.3.4.1"><p id="p832mcpsimp"><a name="p832mcpsimp"></a><a name="p832mcpsimp"></a>注意</p>
</th>
<td class="cellrowborder" valign="top" width="81.97%" headers="mcps1.1.3.4.1 "><p id="p1595516720517"><a name="p1595516720517"></a><a name="p1595516720517"></a>此指令在执行SLE RF TX、RX后需要停止时执行。</p>
<p id="p4981119519"><a name="p4981119519"></a><a name="p4981119519"></a>rssi和num_packet在RX结束后关注。</p>
<a name="ul19293817552"></a><a name="ul19293817552"></a><ul id="ul19293817552"><li>rssi：接收能量值；</li><li>num_packet：收包数。</li></ul>
<p id="p834mcpsimp"><a name="p834mcpsimp"></a><a name="p834mcpsimp"></a>为避免丢包，停止RX指令发送前要保证仪表已经完成发包</p>
</td>
</tr>
</tbody>
</table>

### SLE 复位指令<a name="ZH-CN_TOPIC_0000001696270674"></a>

<a name="table137mcpsimp"></a>
<table><tbody><tr id="row142mcpsimp"><th class="firstcol" valign="top" width="16.17%" id="mcps1.1.3.1.1"><p id="p144mcpsimp"><a name="p144mcpsimp"></a><a name="p144mcpsimp"></a>格式</p>
</th>
<td class="cellrowborder" valign="top" width="83.83%" headers="mcps1.1.3.1.1 "><p id="p146mcpsimp"><a name="p146mcpsimp"></a><a name="p146mcpsimp"></a>AT+SLERST</p>
</td>
</tr>
<tr id="row148mcpsimp"><th class="firstcol" valign="top" width="16.17%" id="mcps1.1.3.2.1"><p id="p150mcpsimp"><a name="p150mcpsimp"></a><a name="p150mcpsimp"></a>响应</p>
</th>
<td class="cellrowborder" valign="top" width="83.83%" headers="mcps1.1.3.2.1 "><a name="ul104486224265"></a><a name="ul104486224265"></a><ul id="ul104486224265"><li>成功：OK<p id="p633314274266"><a name="p633314274266"></a><a name="p633314274266"></a>general event report opcode[07]</p>
<p id="p12333627162612"><a name="p12333627162612"></a><a name="p12333627162612"></a>status:0</p>
</li><li>失败：ERROR</li></ul>
</td>
</tr>
<tr id="row155mcpsimp"><th class="firstcol" valign="top" width="16.17%" id="mcps1.1.3.3.1"><p id="p157mcpsimp"><a name="p157mcpsimp"></a><a name="p157mcpsimp"></a>示例</p>
</th>
<td class="cellrowborder" valign="top" width="83.83%" headers="mcps1.1.3.3.1 "><p id="p159mcpsimp"><a name="p159mcpsimp"></a><a name="p159mcpsimp"></a>AT+SLERST</p>
</td>
</tr>
<tr id="row161mcpsimp"><th class="firstcol" valign="top" width="16.17%" id="mcps1.1.3.4.1"><p id="p163mcpsimp"><a name="p163mcpsimp"></a><a name="p163mcpsimp"></a>注意</p>
</th>
<td class="cellrowborder" valign="top" width="83.83%" headers="mcps1.1.3.4.1 "><p id="p165mcpsimp"><a name="p165mcpsimp"></a><a name="p165mcpsimp"></a>软件复位指令。</p>
</td>
</tr>
</tbody>
</table>

## 射频单音<a name="ZH-CN_TOPIC_0000001744150313"></a>

<a name="table200mcpsimp"></a>
<table><tbody><tr id="row205mcpsimp"><th class="firstcol" valign="top" width="16.439999999999998%" id="mcps1.1.3.1.1"><p id="p207mcpsimp"><a name="p207mcpsimp"></a><a name="p207mcpsimp"></a>格式</p>
</th>
<td class="cellrowborder" valign="top" width="83.56%" headers="mcps1.1.3.1.1 "><p id="p209mcpsimp"><a name="p209mcpsimp"></a><a name="p209mcpsimp"></a>AT+BTTXLO=&lt;freq&gt;,&lt;mode&gt;</p>
</td>
</tr>
<tr id="row211mcpsimp"><th class="firstcol" valign="top" width="16.439999999999998%" id="mcps1.1.3.2.1"><p id="p213mcpsimp"><a name="p213mcpsimp"></a><a name="p213mcpsimp"></a>响应</p>
</th>
<td class="cellrowborder" valign="top" width="83.56%" headers="mcps1.1.3.2.1 "><a name="ul1626613812261"></a><a name="ul1626613812261"></a><ul id="ul1626613812261"><li>成功：OK</li><li>失败：ERROR</li></ul>
</td>
</tr>
<tr id="row218mcpsimp"><th class="firstcol" valign="top" width="16.439999999999998%" id="mcps1.1.3.3.1"><p id="p443mcpsimp"><a name="p443mcpsimp"></a><a name="p443mcpsimp"></a>参数说明</p>
</th>
<td class="cellrowborder" valign="top" width="83.56%" headers="mcps1.1.3.3.1 "><a name="ul14483426194314"></a><a name="ul14483426194314"></a><ul id="ul14483426194314"><li>&lt;freq&gt;: 频点<p id="p17931122015448"><a name="p17931122015448"></a><a name="p17931122015448"></a>0～78：射频信道号依次对应对应2402～2480 MHz，详见<a href="星闪协议频点表.md#fig12728841183211">图1</a>和<a href="星闪协议频点表.md#fig3784926143510">图2</a></p>
</li><li>&lt;mode&gt;：开关<p id="p10662015151410"><a name="p10662015151410"></a><a name="p10662015151410"></a>0：发单音；</p>
<p id="p6662415181416"><a name="p6662415181416"></a><a name="p6662415181416"></a>255：停止单音；</p>
<p id="p196621715131418"><a name="p196621715131418"></a><a name="p196621715131418"></a>其他值无效。</p>
</li></ul>
</td>
</tr>
<tr id="row230mcpsimp"><th class="firstcol" valign="top" width="16.439999999999998%" id="mcps1.1.3.4.1"><p id="p232mcpsimp"><a name="p232mcpsimp"></a><a name="p232mcpsimp"></a>示例</p>
</th>
<td class="cellrowborder" valign="top" width="83.56%" headers="mcps1.1.3.4.1 "><a name="ul528816452518"></a><a name="ul528816452518"></a><ul id="ul528816452518"><li>AT+BTTXLO=4,0<p id="p21441650156"><a name="p21441650156"></a><a name="p21441650156"></a>说明：在（2402+4）MHz发单音。</p>
</li><li>AT+BTTXLO=4,255<p id="p7144105151516"><a name="p7144105151516"></a><a name="p7144105151516"></a>说明：在（2402+4）MHz停止单音。</p>
</li></ul>
</td>
</tr>
<tr id="row236mcpsimp"><th class="firstcol" valign="top" width="16.439999999999998%" id="mcps1.1.3.5.1"><p id="p238mcpsimp"><a name="p238mcpsimp"></a><a name="p238mcpsimp"></a>注意</p>
</th>
<td class="cellrowborder" valign="top" width="83.56%" headers="mcps1.1.3.5.1 "><p id="p240mcpsimp"><a name="p240mcpsimp"></a><a name="p240mcpsimp"></a>1. 发单音后不会自动停止，测试TRX性能前需要发指令AT+BTTXLO=0,255停止单音，避免影响。</p>
<p id="p20689112121814"><a name="p20689112121814"></a><a name="p20689112121814"></a>2. 最新版本单音不再打印status：0，且不再依赖BLE使能，不与BLE业务耦合，单SLE版本也可以使用发单音和停止单音指令。</p>
</td>
</tr>
</tbody>
</table>

## XO 32M校准（可选）<a name="ZH-CN_TOPIC_0000001696270682"></a>




### 执行CTRIM校准指令<a name="ZH-CN_TOPIC_0000001744150317"></a>

<a name="table422mcpsimp"></a>
<table><tbody><tr id="row427mcpsimp"><th class="firstcol" valign="top" width="17.549999999999997%" id="mcps1.1.3.1.1"><p id="p429mcpsimp"><a name="p429mcpsimp"></a><a name="p429mcpsimp"></a>格式</p>
</th>
<td class="cellrowborder" valign="top" width="82.45%" headers="mcps1.1.3.1.1 "><p id="p431mcpsimp"><a name="p431mcpsimp"></a><a name="p431mcpsimp"></a>AT+ XOCALI=&lt;increase&gt;,&lt;step_num&gt;</p>
</td>
</tr>
<tr id="row434mcpsimp"><th class="firstcol" valign="top" width="17.549999999999997%" id="mcps1.1.3.2.1"><p id="p436mcpsimp"><a name="p436mcpsimp"></a><a name="p436mcpsimp"></a>响应</p>
</th>
<td class="cellrowborder" valign="top" width="82.45%" headers="mcps1.1.3.2.1 "><p id="p1142159124411"><a name="p1142159124411"></a><a name="p1142159124411"></a>xo_ctrim_reg_val:0x0</p>
<a name="ul185881851172219"></a><a name="ul185881851172219"></a><ul id="ul185881851172219"><li>成功：OK</li><li>失败：ERROR</li></ul>
</td>
</tr>
<tr id="row441mcpsimp"><th class="firstcol" valign="top" width="17.549999999999997%" id="mcps1.1.3.3.1"><p id="p443mcpsimp"><a name="p443mcpsimp"></a><a name="p443mcpsimp"></a>参数说明</p>
</th>
<td class="cellrowborder" valign="top" width="82.45%" headers="mcps1.1.3.3.1 "><a name="ul1226823164815"></a><a name="ul1226823164815"></a><ul id="ul1226823164815"><li>&lt; increase &gt;: 增加或减小电容值<p id="p448mcpsimp"><a name="p448mcpsimp"></a><a name="p448mcpsimp"></a>1：增加</p>
<p id="p449mcpsimp"><a name="p449mcpsimp"></a><a name="p449mcpsimp"></a>0：减小</p>
</li><li>&lt; step_num &gt;:<strong id="b255221810489"><a name="b255221810489"></a><a name="b255221810489"></a> </strong>电容值调整步进<p id="p5440154214818"><a name="p5440154214818"></a><a name="p5440154214818"></a>取值范围[0,255]，默认0（十进制）</p>
</li></ul>
</td>
</tr>
<tr id="row460mcpsimp"><th class="firstcol" valign="top" width="17.549999999999997%" id="mcps1.1.3.4.1"><p id="p462mcpsimp"><a name="p462mcpsimp"></a><a name="p462mcpsimp"></a>示例</p>
</th>
<td class="cellrowborder" valign="top" width="82.45%" headers="mcps1.1.3.4.1 "><a name="ul623313239496"></a><a name="ul623313239496"></a><ul id="ul623313239496"><li>AT+ XOCALI=1,10<p id="p97780206223"><a name="p97780206223"></a><a name="p97780206223"></a></p>
<p id="p1037845365211"><a name="p1037845365211"></a><a name="p1037845365211"></a>返回值：</p>
<p id="p118315136467"><a name="p118315136467"></a><a name="p118315136467"></a>xo_ctrim_reg_val:0x10</p>
<p id="p13419132316346"><a name="p13419132316346"></a><a name="p13419132316346"></a>OK</p>
<p id="p4236322446"><a name="p4236322446"></a><a name="p4236322446"></a>说明：给电容增加10steps，具体效果通过发送单音或调制信号观测</p>
</li><li>AT+ XOCALI=0,20<p id="p187781520172215"><a name="p187781520172215"></a><a name="p187781520172215"></a>返回值：</p>
<p id="p748744554618"><a name="p748744554618"></a><a name="p748744554618"></a>xo_ctrim_reg_val:0x0</p>
<p id="p996052617340"><a name="p996052617340"></a><a name="p996052617340"></a>OK</p>
<p id="p577916207225"><a name="p577916207225"></a><a name="p577916207225"></a>说明：电容在第一步增加10后减少20，超出范围，默认减为最小值0。</p>
</li></ul>
</td>
</tr>
<tr id="row476mcpsimp"><th class="firstcol" valign="top" width="17.549999999999997%" id="mcps1.1.3.5.1"><p id="p478mcpsimp"><a name="p478mcpsimp"></a><a name="p478mcpsimp"></a>注意</p>
</th>
<td class="cellrowborder" valign="top" width="82.45%" headers="mcps1.1.3.5.1 "><p id="p480mcpsimp"><a name="p480mcpsimp"></a><a name="p480mcpsimp"></a>超出[0,255]的步进无效，默认按照最大/最小配置寄存器，校准时无特殊环境约束。</p>
<p id="p1640463554719"><a name="p1640463554719"></a><a name="p1640463554719"></a>步进和电容变化非严格线性变化，需要上位机程序使用二分法调整步进，通常常温频偏门限为&plusmn;24kHz。</p>
</td>
</tr>
</tbody>
</table>

### CTRIM校准值写入EFUSE / FLASH指令<a name="ZH-CN_TOPIC_0000001744150321"></a>

<a name="table103mcpsimp"></a>
<table><tbody><tr id="row108mcpsimp"><th class="firstcol" valign="top" width="18%" id="mcps1.1.3.1.1"><p id="p110mcpsimp"><a name="p110mcpsimp"></a><a name="p110mcpsimp"></a>格式</p>
</th>
<td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.3.1.1 "><p id="p112mcpsimp"><a name="p112mcpsimp"></a><a name="p112mcpsimp"></a>AT+ XOSETEFUSE</p>
</td>
</tr>
<tr id="row115mcpsimp"><th class="firstcol" valign="top" width="18%" id="mcps1.1.3.2.1"><p id="p117mcpsimp"><a name="p117mcpsimp"></a><a name="p117mcpsimp"></a>响应</p>
</th>
<td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.3.2.1 "><p id="p1319017119230"><a name="p1319017119230"></a><a name="p1319017119230"></a>efuse_val: 0x0</p>
<a name="ul1134104815221"></a><a name="ul1134104815221"></a><ul id="ul1134104815221"><li>成功：OK</li><li>失败：ERROR</li></ul>
</td>
</tr>
<tr id="row125mcpsimp"><th class="firstcol" valign="top" width="18%" id="mcps1.1.3.3.1"><p id="p127mcpsimp"><a name="p127mcpsimp"></a><a name="p127mcpsimp"></a>示例</p>
</th>
<td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.3.3.1 "><p id="p129mcpsimp"><a name="p129mcpsimp"></a><a name="p129mcpsimp"></a>AT+ XOSETEFUSE</p>
<p id="p1157104182719"><a name="p1157104182719"></a><a name="p1157104182719"></a>返回值：</p>
<p id="p018092252714"><a name="p018092252714"></a><a name="p018092252714"></a>efuse_val: 0x2</p>
<p id="p67961958192711"><a name="p67961958192711"></a><a name="p67961958192711"></a>说明：当前寄存器配置的电容步进为2，写入EFUSE成功后回读EFUSE值为0x2。</p>
</td>
</tr>
<tr id="row131mcpsimp"><th class="firstcol" valign="top" width="18%" id="mcps1.1.3.4.1"><p id="p133mcpsimp"><a name="p133mcpsimp"></a><a name="p133mcpsimp"></a>注意</p>
</th>
<td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.3.4.1 "><p id="p135mcpsimp"><a name="p135mcpsimp"></a><a name="p135mcpsimp"></a>由于EFUSE只能写入一次,根据回报值“efuse_val: 0x2“判断是否写入成功。</p>
</td>
</tr>
</tbody>
</table>

<a name="table9474144171219"></a>
<table><tbody><tr id="row114745451213"><th class="firstcol" valign="top" width="18%" id="mcps1.1.3.1.1"><p id="p1547484181213"><a name="p1547484181213"></a><a name="p1547484181213"></a>格式</p>
</th>
<td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.3.1.1 "><p id="p17474142122"><a name="p17474142122"></a><a name="p17474142122"></a>AT+ XOSETFLASH</p>
</td>
</tr>
<tr id="row44746441217"><th class="firstcol" valign="top" width="18%" id="mcps1.1.3.2.1"><p id="p84741649120"><a name="p84741649120"></a><a name="p84741649120"></a>响应</p>
</th>
<td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.3.2.1 "><p id="p447474171220"><a name="p447474171220"></a><a name="p447474171220"></a>flash_val: 0x2</p>
<a name="ul4474443128"></a><a name="ul4474443128"></a><ul id="ul4474443128"><li>成功：OK</li><li>失败：ERROR</li></ul>
</td>
</tr>
<tr id="row847417461214"><th class="firstcol" valign="top" width="18%" id="mcps1.1.3.3.1"><p id="p1947424171218"><a name="p1947424171218"></a><a name="p1947424171218"></a>示例</p>
</th>
<td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.3.3.1 "><p id="p124741044126"><a name="p124741044126"></a><a name="p124741044126"></a>AT+ XOSETFLASH</p>
<p id="p19474144181211"><a name="p19474144181211"></a><a name="p19474144181211"></a>返回值：</p>
<p id="p17474149127"><a name="p17474149127"></a><a name="p17474149127"></a>flash_val: 0x2</p>
<p id="p1247419401218"><a name="p1247419401218"></a><a name="p1247419401218"></a>说明：当前寄存器配置的电容步进为2，写入FLASH成功后回读FLASH值为0x2。</p>
</td>
</tr>
<tr id="row947484131219"><th class="firstcol" valign="top" width="18%" id="mcps1.1.3.4.1"><p id="p1747417401211"><a name="p1747417401211"></a><a name="p1747417401211"></a>注意</p>
</th>
<td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.3.4.1 "><p id="p34744414128"><a name="p34744414128"></a><a name="p34744414128"></a>根据回报值“flash_val: 0x2“判断是否写入成功。</p>
</td>
</tr>
</tbody>
</table>

### 读取当前CTRIM寄存器配置<a name="ZH-CN_TOPIC_0000001744110185"></a>

<a name="table103mcpsimp"></a>
<table><tbody><tr id="row108mcpsimp"><th class="firstcol" valign="top" width="18%" id="mcps1.1.3.1.1"><p id="p110mcpsimp"><a name="p110mcpsimp"></a><a name="p110mcpsimp"></a>格式</p>
</th>
<td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.3.1.1 "><p id="p162735348268"><a name="p162735348268"></a><a name="p162735348268"></a>AT+ XOREGVAL</p>
</td>
</tr>
<tr id="row115mcpsimp"><th class="firstcol" valign="top" width="18%" id="mcps1.1.3.2.1"><p id="p117mcpsimp"><a name="p117mcpsimp"></a><a name="p117mcpsimp"></a>响应</p>
</th>
<td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.3.2.1 "><p id="p1227303482617"><a name="p1227303482617"></a><a name="p1227303482617"></a>reg_val: 0x0</p>
<a name="ul1719017449227"></a><a name="ul1719017449227"></a><ul id="ul1719017449227"><li>成功：OK</li><li>失败：ERROR</li></ul>
</td>
</tr>
<tr id="row125mcpsimp"><th class="firstcol" valign="top" width="18%" id="mcps1.1.3.3.1"><p id="p127mcpsimp"><a name="p127mcpsimp"></a><a name="p127mcpsimp"></a>示例</p>
</th>
<td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.3.3.1 "><p id="p9273163410265"><a name="p9273163410265"></a><a name="p9273163410265"></a>AT+ XOREGVAL</p>
<p id="p992715102919"><a name="p992715102919"></a><a name="p992715102919"></a>返回值：</p>
<p id="p15211181052917"><a name="p15211181052917"></a><a name="p15211181052917"></a>reg_val: 0x0</p>
<p id="p34158733410"><a name="p34158733410"></a><a name="p34158733410"></a>OK</p>
<p id="p178951911172912"><a name="p178951911172912"></a><a name="p178951911172912"></a>说明：当前XO_CORE_CTRIM寄存器值为0x0。</p>
</td>
</tr>
<tr id="row131mcpsimp"><th class="firstcol" valign="top" width="18%" id="mcps1.1.3.4.1"><p id="p133mcpsimp"><a name="p133mcpsimp"></a><a name="p133mcpsimp"></a>注意</p>
</th>
<td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.3.4.1 "><p id="p42731834142610"><a name="p42731834142610"></a><a name="p42731834142610"></a>上电后默认从EFUSE中读出校准值应用到寄存器，若EFUSE为空，寄存器默认值为0x0。</p>
</td>
</tr>
</tbody>
</table>

## CFO动态校准上报（可选）<a name="ZH-CN_TOPIC_0000001976179977"></a>

>![](public_sys-resources/icon-note.gif) **说明：** 
>“[XO 32M校准（可选）](XO-32M校准（可选）.md)”中ctrim校准时需要用蓝牙综测仪或频谱仪观测定频信号的频谱，通过调整ctrim电容值来改变XO 32M频偏；如果没有仪表，则可以考虑本小节中CF0动态上报的校准方式，通过将DUT与一块golden板对通实现，具体流程见《BS2XV100 产测指导书》。

<a name="table422mcpsimp"></a>
<table><tbody><tr id="row427mcpsimp"><th class="firstcol" valign="top" width="18%" id="mcps1.1.3.1.1"><p id="p429mcpsimp"><a name="p429mcpsimp"></a><a name="p429mcpsimp"></a>格式</p>
</th>
<td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.3.1.1 "><p id="p1237125314810"><a name="p1237125314810"></a><a name="p1237125314810"></a>AT+SLECFORPT</p>
</td>
</tr>
<tr id="row434mcpsimp"><th class="firstcol" valign="top" width="18%" id="mcps1.1.3.2.1"><p id="p436mcpsimp"><a name="p436mcpsimp"></a><a name="p436mcpsimp"></a>响应</p>
</th>
<td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.3.2.1 "><p id="p1142159124411"><a name="p1142159124411"></a><a name="p1142159124411"></a>[AT]sle CFO report:6</p>
<a name="ul185881851172219"></a><a name="ul185881851172219"></a><ul id="ul185881851172219"><li>成功：OK</li><li>失败：ERROR</li></ul>
</td>
</tr>
<tr id="row460mcpsimp"><th class="firstcol" valign="top" width="18%" id="mcps1.1.3.3.1"><p id="p462mcpsimp"><a name="p462mcpsimp"></a><a name="p462mcpsimp"></a>示例</p>
</th>
<td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.3.3.1 "><p id="p56265301387"><a name="p56265301387"></a><a name="p56265301387"></a>AT+SLECFORPT</p>
<p id="p1969851913815"><a name="p1969851913815"></a><a name="p1969851913815"></a>[AT]sle CFO report:6</p>
<p id="p571011211281"><a name="p571011211281"></a><a name="p571011211281"></a>OK</p>
<p id="p6104111131213"><a name="p6104111131213"></a><a name="p6104111131213"></a>注意："6"为十进制数，代表当前DUT比golden板频偏相差6*3.9kHz = 23.4kHz</p>
</td>
</tr>
<tr id="row476mcpsimp"><th class="firstcol" valign="top" width="18%" id="mcps1.1.3.4.1"><p id="p478mcpsimp"><a name="p478mcpsimp"></a><a name="p478mcpsimp"></a>注意</p>
</th>
<td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.3.4.1 "><p id="p4528132512312"><a name="p4528132512312"></a><a name="p4528132512312"></a>1. AT+SLEENABLE</p>
<p id="p1652820251315"><a name="p1652820251315"></a><a name="p1652820251315"></a>2. AT+SLEFACCALLBACK</p>
<p id="p1652862510312"><a name="p1652862510312"></a><a name="p1652862510312"></a>3. AT+SLERX=0,0,0,0,50  (2402MHz 1M GFSK)</p>
<p id="p1924210417910"><a name="p1924210417910"></a><a name="p1924210417910"></a>测试前先通过以上3条指令使得DUT处于RX常收状态，然后通过CFO上报指令查看当前CFO值，上报值为十进制有符号数，校准门限为CFO∈[-6,6], 即&plusmn;24kHz。</p>
</td>
</tr>
</tbody>
</table>

指令串口示例：

![](figures/zh-cn_image_0000001976302233.png)

<a name="table103422123410"></a>
<table><tbody><tr id="row1534211121848"><th class="firstcol" valign="top" width="18%" id="mcps1.1.3.1.1"><p id="p1434214121041"><a name="p1434214121041"></a><a name="p1434214121041"></a>格式</p>
</th>
<td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.3.1.1 "><p id="p88216371452"><a name="p88216371452"></a><a name="p88216371452"></a>AT+SLECFORSSI=&lt;rssi&gt;</p>
</td>
</tr>
<tr id="row634261211416"><th class="firstcol" valign="top" width="18%" id="mcps1.1.3.2.1"><p id="p1134214121747"><a name="p1134214121747"></a><a name="p1134214121747"></a>响应</p>
</th>
<td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.3.2.1 "><p id="p113421112449"><a name="p113421112449"></a><a name="p113421112449"></a>[AT]sle CFO rssi limit:-60</p>
<a name="ul93425126413"></a><a name="ul93425126413"></a><ul id="ul93425126413"><li>成功：OK</li><li>失败：ERROR</li></ul>
</td>
</tr>
<tr id="row183421712041"><th class="firstcol" valign="top" width="18%" id="mcps1.1.3.3.1"><p id="p1534210126415"><a name="p1534210126415"></a><a name="p1534210126415"></a>示例</p>
</th>
<td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.3.3.1 "><p id="p234211219418"><a name="p234211219418"></a><a name="p234211219418"></a>AT+SLECFORSSI=-60</p>
<p id="p1724214252610"><a name="p1724214252610"></a><a name="p1724214252610"></a>[AT]sle CFO rssi limit:-60</p>
<p id="p934201211415"><a name="p934201211415"></a><a name="p934201211415"></a>OK</p>
<p id="p73425122413"><a name="p73425122413"></a><a name="p73425122413"></a>注意："-60"为十进制有符号数，代表当前DUT接收能量大于-60的信号作为cfo上报的依据，小于-60dBm的信号将被视为干扰信号。</p>
</td>
</tr>
<tr id="row73426121414"><th class="firstcol" valign="top" width="18%" id="mcps1.1.3.4.1"><p id="p1342131216413"><a name="p1342131216413"></a><a name="p1342131216413"></a>注意</p>
</th>
<td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.3.4.1 "><p id="p1934211211414"><a name="p1934211211414"></a><a name="p1934211211414"></a>1. AT+SLEENABLE</p>
<p id="p834251218416"><a name="p834251218416"></a><a name="p834251218416"></a>2. AT+SLEFACCALLBACK</p>
<p id="p1534214121419"><a name="p1534214121419"></a><a name="p1534214121419"></a>3. AT+SLERX=0,0,0,0,50  (2402MHz 1M GFSK)</p>
<p id="p83428127412"><a name="p83428127412"></a><a name="p83428127412"></a>测试前先通过以上3条指令使得DUT处于RX常收状态，然后通过CFO rssi 门限设置指令配置信号过滤门限，防止干扰信号影响上报结果。</p>
</td>
</tr>
</tbody>
</table>

指令串口示例：

![](figures/zh-cn_image_0000002028543857.png)

## RT201 FEM使能（可选）<a name="ZH-CN_TOPIC_0000001928238387"></a>

>![](public_sys-resources/icon-note.gif) **说明：** 
>本章仅供前端使用RT201型号的FEM模组的产品参考。

<a name="table103mcpsimp"></a>
<table><tbody><tr id="row108mcpsimp"><th class="firstcol" valign="top" width="18%" id="mcps1.1.3.1.1"><p id="p110mcpsimp"><a name="p110mcpsimp"></a><a name="p110mcpsimp"></a>格式</p>
</th>
<td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.3.1.1 "><p id="p162735348268"><a name="p162735348268"></a><a name="p162735348268"></a>AT+ FEMENABLE=&lt;fem_switch&gt;</p>
</td>
</tr>
<tr id="row115mcpsimp"><th class="firstcol" valign="top" width="18%" id="mcps1.1.3.2.1"><p id="p117mcpsimp"><a name="p117mcpsimp"></a><a name="p117mcpsimp"></a>响应</p>
</th>
<td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.3.2.1 "><a name="ul1719017449227"></a><a name="ul1719017449227"></a><ul id="ul1719017449227"><li>成功：OK</li><li>失败：ERROR</li></ul>
</td>
</tr>
<tr id="row4508152863814"><th class="firstcol" valign="top" width="18%" id="mcps1.1.3.3.1"><p id="p856mcpsimp"><a name="p856mcpsimp"></a><a name="p856mcpsimp"></a>参数说明</p>
</th>
<td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.3.3.1 "><p id="p6233850202012"><a name="p6233850202012"></a><a name="p6233850202012"></a>&lt;fem_switch&gt;：发送频点</p>
<p id="p67093513387"><a name="p67093513387"></a><a name="p67093513387"></a>0：关闭fem配置；</p>
<p id="p14713165513359"><a name="p14713165513359"></a><a name="p14713165513359"></a>1：使能fem配置。</p>
</td>
</tr>
<tr id="row125mcpsimp"><th class="firstcol" valign="top" width="18%" id="mcps1.1.3.4.1"><p id="p127mcpsimp"><a name="p127mcpsimp"></a><a name="p127mcpsimp"></a>示例</p>
</th>
<td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.3.4.1 "><p id="p9273163410265"><a name="p9273163410265"></a><a name="p9273163410265"></a>AT+ FEMENABLE=1</p>
<p id="p992715102919"><a name="p992715102919"></a><a name="p992715102919"></a>返回值：</p>
<p id="p34158733410"><a name="p34158733410"></a><a name="p34158733410"></a>OK</p>
<p id="p114517473521"><a name="p114517473521"></a><a name="p114517473521"></a>AT+ FEMENABLE=0</p>
<p id="p17451447195212"><a name="p17451447195212"></a><a name="p17451447195212"></a>返回值：</p>
<p id="p18451104775217"><a name="p18451104775217"></a><a name="p18451104775217"></a>OK</p>
<p id="p1992153317391"><a name="p1992153317391"></a><a name="p1992153317391"></a>说明：入参写1使能fem配置，写0去使能，重启上下电后生效。</p>
</td>
</tr>
<tr id="row131mcpsimp"><th class="firstcol" valign="top" width="18%" id="mcps1.1.3.5.1"><p id="p133mcpsimp"><a name="p133mcpsimp"></a><a name="p133mcpsimp"></a>注意</p>
</th>
<td class="cellrowborder" valign="top" width="82%" headers="mcps1.1.3.5.1 "><p id="p42731834142610"><a name="p42731834142610"></a><a name="p42731834142610"></a>使能fem的版本，由于fem器件限制输入功率，不能通过NV过指令自定义修改最大功率。</p>
</td>
</tr>
</tbody>
</table>

# AT指令组包示例<a name="ZH-CN_TOPIC_0000001778497610"></a>

以下为AT常发常收指令的组包示例

**表 1**  SLE TX 组包

<a name="table112961750155810"></a>
<table><thead align="left"><tr id="row1259615103143"><th class="cellrowborder" valign="top" width="24.822482248224823%" id="mcps1.2.4.1.1"><p id="p9597151010147"><a name="p9597151010147"></a><a name="p9597151010147"></a>调制速率</p>
</th>
<th class="cellrowborder" valign="top" width="22.182218221822183%" id="mcps1.2.4.1.2"><p id="p1659714109148"><a name="p1659714109148"></a><a name="p1659714109148"></a>信道</p>
</th>
<th class="cellrowborder" valign="top" width="52.995299529953%" id="mcps1.2.4.1.3"><p id="p16597131051411"><a name="p16597131051411"></a><a name="p16597131051411"></a>指令组包</p>
</th>
</tr>
</thead>
<tbody><tr id="row43371150145820"><td class="cellrowborder" rowspan="3" valign="top" width="24.822482248224823%" headers="mcps1.2.4.1.1 "><p id="p23371850175814"><a name="p23371850175814"></a><a name="p23371850175814"></a>1M GFSK</p>
</td>
<td class="cellrowborder" valign="top" width="22.182218221822183%" headers="mcps1.2.4.1.2 "><p id="p1771814105279"><a name="p1771814105279"></a><a name="p1771814105279"></a>2402</p>
</td>
<td class="cellrowborder" valign="top" width="52.995299529953%" headers="mcps1.2.4.1.3 "><p id="p1337155005814"><a name="p1337155005814"></a><a name="p1337155005814"></a>AT+SLETX=0,5,255,0,0,0,0,0,0,50</p>
</td>
</tr>
<tr id="row113370500581"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p671815108271"><a name="p671815108271"></a><a name="p671815108271"></a>2440</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p33371150205811"><a name="p33371150205811"></a><a name="p33371150205811"></a>AT+SLETX=38,5,255,0,0,0,0,0,0,50</p>
</td>
</tr>
<tr id="row1133725045811"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p77181810172719"><a name="p77181810172719"></a><a name="p77181810172719"></a>2480</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p13337135035819"><a name="p13337135035819"></a><a name="p13337135035819"></a>AT+SLETX=78,5,255,0,0,0,0,0,0,50</p>
</td>
</tr>
<tr id="row533765015582"><td class="cellrowborder" rowspan="3" valign="top" width="24.822482248224823%" headers="mcps1.2.4.1.1 "><p id="p633735045813"><a name="p633735045813"></a><a name="p633735045813"></a>2M GFSK</p>
</td>
<td class="cellrowborder" valign="top" width="22.182218221822183%" headers="mcps1.2.4.1.2 "><p id="p1719141015274"><a name="p1719141015274"></a><a name="p1719141015274"></a>2404</p>
</td>
<td class="cellrowborder" valign="top" width="52.995299529953%" headers="mcps1.2.4.1.3 "><p id="p16337115018589"><a name="p16337115018589"></a><a name="p16337115018589"></a>AT+SLETX=2,5,255,0,1,0,0,0,0,50</p>
</td>
</tr>
<tr id="row1533716501581"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1271911012716"><a name="p1271911012716"></a><a name="p1271911012716"></a>2440</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p5337195016583"><a name="p5337195016583"></a><a name="p5337195016583"></a>AT+SLETX=38,5,255,0,1,0,0,0,0,50</p>
</td>
</tr>
<tr id="row93376502585"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1971915100273"><a name="p1971915100273"></a><a name="p1971915100273"></a>2478</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p13379504588"><a name="p13379504588"></a><a name="p13379504588"></a>AT+SLETX=76,5,255,0,1,0,0,0,0,50</p>
</td>
</tr>
<tr id="row3337195019589"><td class="cellrowborder" rowspan="3" valign="top" width="24.822482248224823%" headers="mcps1.2.4.1.1 "><p id="p18337050165818"><a name="p18337050165818"></a><a name="p18337050165818"></a>4M GFSK</p>
</td>
<td class="cellrowborder" valign="top" width="22.182218221822183%" headers="mcps1.2.4.1.2 "><p id="p18719121015271"><a name="p18719121015271"></a><a name="p18719121015271"></a>2405</p>
</td>
<td class="cellrowborder" valign="top" width="52.995299529953%" headers="mcps1.2.4.1.3 "><p id="p19337165010587"><a name="p19337165010587"></a><a name="p19337165010587"></a>AT+SLETX=3,5,255,0,4,0,0,0,0,50</p>
</td>
</tr>
<tr id="row333716500585"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p97191104271"><a name="p97191104271"></a><a name="p97191104271"></a>2441</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p103371350105810"><a name="p103371350105810"></a><a name="p103371350105810"></a>AT+SLETX=39,5,255,0,4,0,0,0,0,50</p>
</td>
</tr>
<tr id="row16337195015585"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p4719310192711"><a name="p4719310192711"></a><a name="p4719310192711"></a>2477</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p433713509585"><a name="p433713509585"></a><a name="p433713509585"></a>AT+SLETX=75,5,255,0,4,0,0,0,0,50</p>
</td>
</tr>
<tr id="row18337155013582"><td class="cellrowborder" rowspan="3" valign="top" width="24.822482248224823%" headers="mcps1.2.4.1.1 "><p id="p1833795011582"><a name="p1833795011582"></a><a name="p1833795011582"></a>1M QPSK</p>
</td>
<td class="cellrowborder" valign="top" width="22.182218221822183%" headers="mcps1.2.4.1.2 "><p id="p158991116202711"><a name="p158991116202711"></a><a name="p158991116202711"></a>2402</p>
</td>
<td class="cellrowborder" valign="top" width="52.995299529953%" headers="mcps1.2.4.1.3 "><p id="p193371550135820"><a name="p193371550135820"></a><a name="p193371550135820"></a>AT+SLETX=0,5,255,0,0,2,2,3,2,50</p>
</td>
</tr>
<tr id="row1433725025811"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p28991416142715"><a name="p28991416142715"></a><a name="p28991416142715"></a>2440</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1133716502589"><a name="p1133716502589"></a><a name="p1133716502589"></a>AT+SLETX=38,5,255,0,0,2,2,3,2,50</p>
</td>
</tr>
<tr id="row533735095816"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1489981610277"><a name="p1489981610277"></a><a name="p1489981610277"></a>2480</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1533755015581"><a name="p1533755015581"></a><a name="p1533755015581"></a>AT+SLETX=78,5,255,0,0,2,2,3,2,50</p>
</td>
</tr>
<tr id="row23377509588"><td class="cellrowborder" rowspan="3" valign="top" width="24.822482248224823%" headers="mcps1.2.4.1.1 "><p id="p333712501589"><a name="p333712501589"></a><a name="p333712501589"></a>2M QPSK</p>
</td>
<td class="cellrowborder" valign="top" width="22.182218221822183%" headers="mcps1.2.4.1.2 "><p id="p128994167278"><a name="p128994167278"></a><a name="p128994167278"></a>2404</p>
</td>
<td class="cellrowborder" valign="top" width="52.995299529953%" headers="mcps1.2.4.1.3 "><p id="p163377507588"><a name="p163377507588"></a><a name="p163377507588"></a>AT+SLETX=2,5,255,0,1,2,2,3,2,50</p>
</td>
</tr>
<tr id="row5337135020583"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p98994169272"><a name="p98994169272"></a><a name="p98994169272"></a>2440</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p19337850105811"><a name="p19337850105811"></a><a name="p19337850105811"></a>AT+SLETX=38,5,255,0,1,2,2,3,2,50</p>
</td>
</tr>
<tr id="row93371450105817"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p889941619279"><a name="p889941619279"></a><a name="p889941619279"></a>2478</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p3337450205819"><a name="p3337450205819"></a><a name="p3337450205819"></a>AT+SLETX=76,5,255,0,1,2,2,3,2,50</p>
</td>
</tr>
<tr id="row103378505588"><td class="cellrowborder" rowspan="3" valign="top" width="24.822482248224823%" headers="mcps1.2.4.1.1 "><p id="p1337165011585"><a name="p1337165011585"></a><a name="p1337165011585"></a>4M QPSK</p>
</td>
<td class="cellrowborder" valign="top" width="22.182218221822183%" headers="mcps1.2.4.1.2 "><p id="p10899141662718"><a name="p10899141662718"></a><a name="p10899141662718"></a>2405</p>
</td>
<td class="cellrowborder" valign="top" width="52.995299529953%" headers="mcps1.2.4.1.3 "><p id="p1833705016580"><a name="p1833705016580"></a><a name="p1833705016580"></a>AT+SLETX=3,5,255,0,4,2,2,3,2,50</p>
</td>
</tr>
<tr id="row23375506588"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p2089931692713"><a name="p2089931692713"></a><a name="p2089931692713"></a>2441</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p6338350105815"><a name="p6338350105815"></a><a name="p6338350105815"></a>AT+SLETX=38,5,255,0,4,2,2,3,2,50</p>
</td>
</tr>
<tr id="row15338250195812"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p208997165279"><a name="p208997165279"></a><a name="p208997165279"></a>2477</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p8338450115810"><a name="p8338450115810"></a><a name="p8338450115810"></a>AT+SLETX=75,5,255,0,4,2,2,3,2,50</p>
</td>
</tr>
<tr id="row5338650175811"><td class="cellrowborder" rowspan="3" valign="top" width="24.822482248224823%" headers="mcps1.2.4.1.1 "><p id="p15338195010584"><a name="p15338195010584"></a><a name="p15338195010584"></a>1M 8PSK</p>
</td>
<td class="cellrowborder" valign="top" width="22.182218221822183%" headers="mcps1.2.4.1.2 "><p id="p575631902714"><a name="p575631902714"></a><a name="p575631902714"></a>2402</p>
</td>
<td class="cellrowborder" valign="top" width="52.995299529953%" headers="mcps1.2.4.1.3 "><p id="p173388505584"><a name="p173388505584"></a><a name="p173388505584"></a>AT+SLETX=0,5,255,0,0,2,3,3,2,50</p>
</td>
</tr>
<tr id="row153381350195818"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p6756111912712"><a name="p6756111912712"></a><a name="p6756111912712"></a>2440</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p43382050165810"><a name="p43382050165810"></a><a name="p43382050165810"></a>AT+SLETX=38,5,255,0,0,2,3,3,2,50</p>
</td>
</tr>
<tr id="row2338350195815"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p975661920277"><a name="p975661920277"></a><a name="p975661920277"></a>2480</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p3338650145813"><a name="p3338650145813"></a><a name="p3338650145813"></a>AT+SLETX=78,5,255,0,0,2,3,3,2,50</p>
</td>
</tr>
<tr id="row163385502585"><td class="cellrowborder" rowspan="3" valign="top" width="24.822482248224823%" headers="mcps1.2.4.1.1 "><p id="p93381150135818"><a name="p93381150135818"></a><a name="p93381150135818"></a>2M 8PSK</p>
</td>
<td class="cellrowborder" valign="top" width="22.182218221822183%" headers="mcps1.2.4.1.2 "><p id="p1675618197271"><a name="p1675618197271"></a><a name="p1675618197271"></a>2404</p>
</td>
<td class="cellrowborder" valign="top" width="52.995299529953%" headers="mcps1.2.4.1.3 "><p id="p1133815502587"><a name="p1133815502587"></a><a name="p1133815502587"></a>AT+SLETX=2,5,255,0,1,2,3,3,2,50</p>
</td>
</tr>
<tr id="row533819503584"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p117561019112713"><a name="p117561019112713"></a><a name="p117561019112713"></a>2440</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p9338135011589"><a name="p9338135011589"></a><a name="p9338135011589"></a>AT+SLETX=38,5,255,0,1,2,3,3,2,50</p>
</td>
</tr>
<tr id="row83384503581"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p15756171918276"><a name="p15756171918276"></a><a name="p15756171918276"></a>2478</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p2338550145812"><a name="p2338550145812"></a><a name="p2338550145812"></a>AT+SLETX=76,5,255,0,1,2,3,3,2,50</p>
</td>
</tr>
<tr id="row123381750105811"><td class="cellrowborder" rowspan="3" valign="top" width="24.822482248224823%" headers="mcps1.2.4.1.1 "><p id="p18338105016583"><a name="p18338105016583"></a><a name="p18338105016583"></a>4M 8PSK</p>
</td>
<td class="cellrowborder" valign="top" width="22.182218221822183%" headers="mcps1.2.4.1.2 "><p id="p875651982715"><a name="p875651982715"></a><a name="p875651982715"></a>2405</p>
</td>
<td class="cellrowborder" valign="top" width="52.995299529953%" headers="mcps1.2.4.1.3 "><p id="p73391950205817"><a name="p73391950205817"></a><a name="p73391950205817"></a>AT+SLETX=3,5,255,0,4,2,3,3,2,50</p>
</td>
</tr>
<tr id="row8339105018584"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p12756111902710"><a name="p12756111902710"></a><a name="p12756111902710"></a>2441</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p733985065815"><a name="p733985065815"></a><a name="p733985065815"></a>AT+SLETX=39,5,255,0,4,2,3,3,2,50</p>
</td>
</tr>
<tr id="row23391050145813"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1975615197277"><a name="p1975615197277"></a><a name="p1975615197277"></a>2477</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p203399502589"><a name="p203399502589"></a><a name="p203399502589"></a>AT+SLETX=75,5,255,0,4,2,3,3,2,50</p>
</td>
</tr>
</tbody>
</table>

**表 2**  SLE RX 组包

<a name="table594854518"></a>
<table><thead align="left"><tr id="row1110821314352"><th class="cellrowborder" valign="top" width="24.832483248324834%" id="mcps1.2.4.1.1"><p id="p022613167353"><a name="p022613167353"></a><a name="p022613167353"></a>调制速率</p>
</th>
<th class="cellrowborder" valign="top" width="22.922292229222922%" id="mcps1.2.4.1.2"><p id="p192262163352"><a name="p192262163352"></a><a name="p192262163352"></a>信道</p>
</th>
<th class="cellrowborder" valign="top" width="52.24522452245224%" id="mcps1.2.4.1.3"><p id="p6226121643518"><a name="p6226121643518"></a><a name="p6226121643518"></a>指令组包</p>
</th>
</tr>
</thead>
<tbody><tr id="row177419817451"><td class="cellrowborder" rowspan="3" valign="top" width="24.832483248324834%" headers="mcps1.2.4.1.1 "><p id="p1274198114519"><a name="p1274198114519"></a><a name="p1274198114519"></a>1M GFSK</p>
</td>
<td class="cellrowborder" valign="top" width="22.922292229222922%" headers="mcps1.2.4.1.2 "><p id="p8746816452"><a name="p8746816452"></a><a name="p8746816452"></a>2402</p>
</td>
<td class="cellrowborder" valign="top" width="52.24522452245224%" headers="mcps1.2.4.1.3 "><p id="p17741810456"><a name="p17741810456"></a><a name="p17741810456"></a>AT+SLERX=0,0,0,0,19</p>
</td>
</tr>
<tr id="row1974888452"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p47520815459"><a name="p47520815459"></a><a name="p47520815459"></a>2440</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p177516820457"><a name="p177516820457"></a><a name="p177516820457"></a>AT+SLERX=38,0,0,0,19</p>
</td>
</tr>
<tr id="row375118154510"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p15752816459"><a name="p15752816459"></a><a name="p15752816459"></a>2480</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p37511874516"><a name="p37511874516"></a><a name="p37511874516"></a>AT+SLERX=78,0,0,0,19</p>
</td>
</tr>
<tr id="row3750814512"><td class="cellrowborder" rowspan="3" valign="top" width="24.832483248324834%" headers="mcps1.2.4.1.1 "><p id="p1275178174510"><a name="p1275178174510"></a><a name="p1275178174510"></a>2M GFSK</p>
</td>
<td class="cellrowborder" valign="top" width="22.922292229222922%" headers="mcps1.2.4.1.2 "><p id="p137511874515"><a name="p137511874515"></a><a name="p137511874515"></a>2404</p>
</td>
<td class="cellrowborder" valign="top" width="52.24522452245224%" headers="mcps1.2.4.1.3 "><p id="p1375108144512"><a name="p1375108144512"></a><a name="p1375108144512"></a>AT+SLERX=2,1,0,0,10</p>
</td>
</tr>
<tr id="row117508124512"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p27518844512"><a name="p27518844512"></a><a name="p27518844512"></a>2440</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p6752815458"><a name="p6752815458"></a><a name="p6752815458"></a>AT+SLERX=38,0,0,0,10</p>
</td>
</tr>
<tr id="row187528144517"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p07538134511"><a name="p07538134511"></a><a name="p07538134511"></a>2478</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p57598154516"><a name="p57598154516"></a><a name="p57598154516"></a>AT+SLERX=76,1,0,0,10</p>
</td>
</tr>
<tr id="row197519812458"><td class="cellrowborder" rowspan="3" valign="top" width="24.832483248324834%" headers="mcps1.2.4.1.1 "><p id="p9751584451"><a name="p9751584451"></a><a name="p9751584451"></a>4M GFSK</p>
</td>
<td class="cellrowborder" valign="top" width="22.922292229222922%" headers="mcps1.2.4.1.2 "><p id="p1275208134512"><a name="p1275208134512"></a><a name="p1275208134512"></a>2405</p>
</td>
<td class="cellrowborder" valign="top" width="52.24522452245224%" headers="mcps1.2.4.1.3 "><p id="p167514819451"><a name="p167514819451"></a><a name="p167514819451"></a>AT+SLERX=3,4,0,0,6</p>
</td>
</tr>
<tr id="row6752819456"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p127568154514"><a name="p127568154514"></a><a name="p127568154514"></a>2441</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1375118174511"><a name="p1375118174511"></a><a name="p1375118174511"></a>AT+SLERX=39,4,0,0,6</p>
</td>
</tr>
<tr id="row157538164511"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p87558164515"><a name="p87558164515"></a><a name="p87558164515"></a>2477</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p375887455"><a name="p375887455"></a><a name="p375887455"></a>AT+SLERX=75,4,0,0,6</p>
</td>
</tr>
<tr id="row47519812453"><td class="cellrowborder" rowspan="3" valign="top" width="24.832483248324834%" headers="mcps1.2.4.1.1 "><p id="p187514854519"><a name="p187514854519"></a><a name="p187514854519"></a>1M QPSK</p>
</td>
<td class="cellrowborder" valign="top" width="22.922292229222922%" headers="mcps1.2.4.1.2 "><p id="p7759818455"><a name="p7759818455"></a><a name="p7759818455"></a>2402</p>
</td>
<td class="cellrowborder" valign="top" width="52.24522452245224%" headers="mcps1.2.4.1.3 "><p id="p17751384459"><a name="p17751384459"></a><a name="p17751384459"></a>AT+SLERX=0,0,2,3,14</p>
</td>
</tr>
<tr id="row17516814515"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p27588134512"><a name="p27588134512"></a><a name="p27588134512"></a>2440</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p127518894510"><a name="p127518894510"></a><a name="p127518894510"></a>AT+SLERX=38,0,2,3,14</p>
</td>
</tr>
<tr id="row17510854515"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p177538174516"><a name="p177538174516"></a><a name="p177538174516"></a>2480</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p275289454"><a name="p275289454"></a><a name="p275289454"></a>AT+SLERX=78,0,2,3,14</p>
</td>
</tr>
<tr id="row57558194511"><td class="cellrowborder" rowspan="3" valign="top" width="24.832483248324834%" headers="mcps1.2.4.1.1 "><p id="p5751085455"><a name="p5751085455"></a><a name="p5751085455"></a>2M QPSK</p>
</td>
<td class="cellrowborder" valign="top" width="22.922292229222922%" headers="mcps1.2.4.1.2 "><p id="p177518813456"><a name="p177518813456"></a><a name="p177518813456"></a>2404</p>
</td>
<td class="cellrowborder" valign="top" width="52.24522452245224%" headers="mcps1.2.4.1.3 "><p id="p14752814455"><a name="p14752814455"></a><a name="p14752814455"></a>AT+SLERX=2,1,2,3,8</p>
</td>
</tr>
<tr id="row4751811459"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p675138204517"><a name="p675138204517"></a><a name="p675138204517"></a>2440</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p975138104513"><a name="p975138104513"></a><a name="p975138104513"></a>AT+SLERX=38,1,2,3,8</p>
</td>
</tr>
<tr id="row1075281451"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p207519820455"><a name="p207519820455"></a><a name="p207519820455"></a>2478</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p197515834518"><a name="p197515834518"></a><a name="p197515834518"></a>AT+SLERX=76,1,2,3,8</p>
</td>
</tr>
<tr id="row97519844514"><td class="cellrowborder" rowspan="3" valign="top" width="24.832483248324834%" headers="mcps1.2.4.1.1 "><p id="p575589457"><a name="p575589457"></a><a name="p575589457"></a>4M QPSK</p>
</td>
<td class="cellrowborder" valign="top" width="22.922292229222922%" headers="mcps1.2.4.1.2 "><p id="p57513894515"><a name="p57513894515"></a><a name="p57513894515"></a>2405</p>
</td>
<td class="cellrowborder" valign="top" width="52.24522452245224%" headers="mcps1.2.4.1.3 "><p id="p16755874517"><a name="p16755874517"></a><a name="p16755874517"></a>AT+SLERX=3,4,2,3,6</p>
</td>
</tr>
<tr id="row1675788455"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1075187453"><a name="p1075187453"></a><a name="p1075187453"></a>2441</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1675198114518"><a name="p1675198114518"></a><a name="p1675198114518"></a>AT+SLERX=39,4,2,3,6</p>
</td>
</tr>
<tr id="row187512820451"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p57513824516"><a name="p57513824516"></a><a name="p57513824516"></a>2477</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p8752864514"><a name="p8752864514"></a><a name="p8752864514"></a>AT+SLERX=75,4,2,3,6</p>
</td>
</tr>
<tr id="row1075886457"><td class="cellrowborder" rowspan="3" valign="top" width="24.832483248324834%" headers="mcps1.2.4.1.1 "><p id="p1751389451"><a name="p1751389451"></a><a name="p1751389451"></a>1M 8PSK</p>
</td>
<td class="cellrowborder" valign="top" width="22.922292229222922%" headers="mcps1.2.4.1.2 "><p id="p127598174513"><a name="p127598174513"></a><a name="p127598174513"></a>2402</p>
</td>
<td class="cellrowborder" valign="top" width="52.24522452245224%" headers="mcps1.2.4.1.3 "><p id="p6755818458"><a name="p6755818458"></a><a name="p6755818458"></a>AT+SLERX=0,0,2,3,10</p>
</td>
</tr>
<tr id="row975986457"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p127515844512"><a name="p127515844512"></a><a name="p127515844512"></a>2440</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1762081456"><a name="p1762081456"></a><a name="p1762081456"></a>AT+SLERX=38,0,2,3,10</p>
</td>
</tr>
<tr id="row176188134516"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1176989459"><a name="p1176989459"></a><a name="p1176989459"></a>2480</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p576158154516"><a name="p576158154516"></a><a name="p576158154516"></a>AT+SLERX=78,0,2,3,10</p>
</td>
</tr>
<tr id="row137618884514"><td class="cellrowborder" rowspan="3" valign="top" width="24.832483248324834%" headers="mcps1.2.4.1.1 "><p id="p876188144517"><a name="p876188144517"></a><a name="p876188144517"></a>2M 8PSK</p>
</td>
<td class="cellrowborder" valign="top" width="22.922292229222922%" headers="mcps1.2.4.1.2 "><p id="p27614834519"><a name="p27614834519"></a><a name="p27614834519"></a>2404</p>
</td>
<td class="cellrowborder" valign="top" width="52.24522452245224%" headers="mcps1.2.4.1.3 "><p id="p167616815457"><a name="p167616815457"></a><a name="p167616815457"></a>AT+SLERX=2,1,2,3,6</p>
</td>
</tr>
<tr id="row187617884510"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p876148174514"><a name="p876148174514"></a><a name="p876148174514"></a>2440</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p14766815456"><a name="p14766815456"></a><a name="p14766815456"></a>AT+SLERX=38,1,2,3,6</p>
</td>
</tr>
<tr id="row11765814511"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p117613817450"><a name="p117613817450"></a><a name="p117613817450"></a>2478</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p4761384456"><a name="p4761384456"></a><a name="p4761384456"></a>AT+SLERX=76,1,2,3,6</p>
</td>
</tr>
<tr id="row137613854519"><td class="cellrowborder" rowspan="3" valign="top" width="24.832483248324834%" headers="mcps1.2.4.1.1 "><p id="p6764864511"><a name="p6764864511"></a><a name="p6764864511"></a>4M 8PSK</p>
</td>
<td class="cellrowborder" valign="top" width="22.922292229222922%" headers="mcps1.2.4.1.2 "><p id="p137615834517"><a name="p137615834517"></a><a name="p137615834517"></a>2405</p>
</td>
<td class="cellrowborder" valign="top" width="52.24522452245224%" headers="mcps1.2.4.1.3 "><p id="p11760814510"><a name="p11760814510"></a><a name="p11760814510"></a>AT+SLERX=3,4,2,3,6</p>
</td>
</tr>
<tr id="row117612816452"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p12763819457"><a name="p12763819457"></a><a name="p12763819457"></a>2441</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p2767818454"><a name="p2767818454"></a><a name="p2767818454"></a>AT+SLERX=39,4,2,3,6</p>
</td>
</tr>
<tr id="row3761782453"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p6765810457"><a name="p6765810457"></a><a name="p6765810457"></a>2477</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p4762854519"><a name="p4762854519"></a><a name="p4762854519"></a>AT+SLERX=75,4,2,3,6</p>
</td>
</tr>
</tbody>
</table>

# 注意事项<a name="ZH-CN_TOPIC_0000001696430150"></a>






## 所有指令的参数输入格式必须为十进制<a name="ZH-CN_TOPIC_0000001744110177"></a>

例如当包长0xFF需输入255时：

-   正确示例： AT+SLETX=0,5,255,0,1,2,2,0,0,50
-   错误示例： AT+SLETX=0,5,FF,0,1,2,2,0,0,50

>![](public_sys-resources/icon-note.gif) **说明：** 
>参数必须是十进制。

## 部分指令返回值为十六进制<a name="ZH-CN_TOPIC_0000001696430146"></a>

发送：

AT+SLETRXEND

回复：

OK

status:0x0, num\_packet:0x3e8, rssi:0x81

>![](public_sys-resources/icon-note.gif) **说明：** 
>测试RX的收报数为1000包（0x3e8\)，RX的当前接收rssi为0x81，即-127dbm。

## 所有参数的间隔符逗号为英文字符","<a name="ZH-CN_TOPIC_0000001696270670"></a>

示例如下：

-   正确示例：AT+SLETX=0,5,255,0,1,2,2,0,0,50
-   错误示例：AT+SLETX=0，5，55,0,1,2,2,0,0,50

    >![](public_sys-resources/icon-note.gif) **说明：** 
    >不识别中文字符逗号。

## 串口回复说明<a name="ZH-CN_TOPIC_0000001744200625"></a>

**图 1**  串口回复示例1<a name="fig153920382285"></a>  
![](figures/串口回复示例1.png "串口回复示例1")

**图 2**  串口回复示例2<a name="fig4745230132910"></a>  
![](figures/串口回复示例2.png "串口回复示例2")

>![](public_sys-resources/icon-note.gif) **说明：** 
>-   TRX射频指令测试时，串口回复重点关注“status:0“、“num\_packets:3e8“、“rssi:81“等字样。
>-   由于指令执行时序异步，“OK“和其他业务上报打印的先后顺序不是固定的，且涉及BLE/SLE TRX业务的指令，回复”OK”不代表指令正常执行。

## 星闪协议频点表<a name="ZH-CN_TOPIC_0000001696270678"></a>

星闪协议拼点如[图1](#fig12728841183211)和[图2](#fig3784926143510)所示。

**图 1**  2400MHz频段不同带宽信道对应的射频信道中心频率和射频信道号1<a name="fig12728841183211"></a>  
![](figures/2400MHz频段不同带宽信道对应的射频信道中心频率和射频信道号1.png "2400MHz频段不同带宽信道对应的射频信道中心频率和射频信道号1")

**图 2**  2400MHz频段不同带宽信道对应的射频信道中心频率和射频信道号2<a name="fig3784926143510"></a>  
![](figures/2400MHz频段不同带宽信道对应的射频信道中心频率和射频信道号2.png "2400MHz频段不同带宽信道对应的射频信道中心频率和射频信道号2")

>![](public_sys-resources/icon-note.gif) **说明：** 
>注意不同带宽的射频测试项需要测的频点不同，例如SLE 4M GFSK指令，测试低频的频点为2405MHz，而不是2402MHz。

