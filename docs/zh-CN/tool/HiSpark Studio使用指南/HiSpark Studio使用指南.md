# 前言<a name="ZH-CN_TOPIC_0000002222115730"></a>

**概述<a name="section4537382116410"></a>**

本文档主要描述IDE工具的安装及使用，IDE工具使用的是HiSpark Studio，该工具主要是用于代码的编辑、编译、镜像烧写。

**读者对象<a name="section4378592816410"></a>**

本文档主要适用于以下工程师：

-   技术支持工程师
-   硬件开发工程师

**符号约定<a name="section133020216410"></a>**

在本文中可能出现下列标志，它们所代表的含义如下。

<a name="table2622507016410"></a>
<table><thead align="left"><tr id="row1530720816410"><th class="cellrowborder" valign="top" width="20.580000000000002%" id="mcps1.1.3.1.1"><p id="p6450074116410"><a name="p6450074116410"></a><a name="p6450074116410"></a><strong id="b2136615816410"><a name="b2136615816410"></a><a name="b2136615816410"></a>符号</strong></p>
</th>
<th class="cellrowborder" valign="top" width="79.42%" id="mcps1.1.3.1.2"><p id="p5435366816410"><a name="p5435366816410"></a><a name="p5435366816410"></a><strong id="b5941558116410"><a name="b5941558116410"></a><a name="b5941558116410"></a>说明</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row1372280416410"><td class="cellrowborder" valign="top" width="20.580000000000002%" headers="mcps1.1.3.1.1 "><p id="p3734547016410"><a name="p3734547016410"></a><a name="p3734547016410"></a><a name="image2670064316410"></a><a name="image2670064316410"></a><span><img class="" id="image2670064316410" height="25.270000000000003" width="67.83" src="figures/zh-cn_image_0000002257115921.png"></span></p>
</td>
<td class="cellrowborder" valign="top" width="79.42%" headers="mcps1.1.3.1.2 "><p id="p1757432116410"><a name="p1757432116410"></a><a name="p1757432116410"></a>表示如不避免则将会导致死亡或严重伤害的具有高等级风险的危害。</p>
</td>
</tr>
<tr id="row466863216410"><td class="cellrowborder" valign="top" width="20.580000000000002%" headers="mcps1.1.3.1.1 "><p id="p1432579516410"><a name="p1432579516410"></a><a name="p1432579516410"></a><a name="image4895582316410"></a><a name="image4895582316410"></a><span><img class="" id="image4895582316410" height="25.270000000000003" width="67.83" src="figures/zh-cn_image_0000002221956330.png"></span></p>
</td>
<td class="cellrowborder" valign="top" width="79.42%" headers="mcps1.1.3.1.2 "><p id="p959197916410"><a name="p959197916410"></a><a name="p959197916410"></a>表示如不避免则可能导致死亡或严重伤害的具有中等级风险的危害。</p>
</td>
</tr>
<tr id="row123863216410"><td class="cellrowborder" valign="top" width="20.580000000000002%" headers="mcps1.1.3.1.1 "><p id="p1232579516410"><a name="p1232579516410"></a><a name="p1232579516410"></a><a name="image1235582316410"></a><a name="image1235582316410"></a><span><img class="" id="image1235582316410" height="25.270000000000003" width="67.83" src="figures/zh-cn_image_0000002222116082.png"></span></p>
</td>
<td class="cellrowborder" valign="top" width="79.42%" headers="mcps1.1.3.1.2 "><p id="p123197916410"><a name="p123197916410"></a><a name="p123197916410"></a>表示如不避免则可能导致轻微或中度伤害的具有低等级风险的危害。</p>
</td>
</tr>
<tr id="row5786682116410"><td class="cellrowborder" valign="top" width="20.580000000000002%" headers="mcps1.1.3.1.1 "><p id="p2204984716410"><a name="p2204984716410"></a><a name="p2204984716410"></a><a name="image4504446716410"></a><a name="image4504446716410"></a><span><img class="" id="image4504446716410" height="25.270000000000003" width="67.83" src="figures/zh-cn_image_0000002257035801.png"></span></p>
</td>
<td class="cellrowborder" valign="top" width="79.42%" headers="mcps1.1.3.1.2 "><p id="p4388861916410"><a name="p4388861916410"></a><a name="p4388861916410"></a>用于传递设备或环境安全警示信息。如不避免则可能会导致设备损坏、数据丢失、设备性能降低或其它不可预知的结果。</p>
<p id="p1238861916410"><a name="p1238861916410"></a><a name="p1238861916410"></a>“须知”不涉及人身伤害。</p>
</td>
</tr>
<tr id="row2856923116410"><td class="cellrowborder" valign="top" width="20.580000000000002%" headers="mcps1.1.3.1.1 "><p id="p5555360116410"><a name="p5555360116410"></a><a name="p5555360116410"></a><a name="image799324016410"></a><a name="image799324016410"></a><span><img class="" id="image799324016410" height="25.270000000000003" width="67.83" src="figures/zh-cn_image_0000002257115917.png"></span></p>
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
<tbody><tr id="row143517419579"><td class="cellrowborder" valign="top" width="20.72%" headers="mcps1.1.4.1.1 "><p id="p1643610417576"><a name="p1643610417576"></a><a name="p1643610417576"></a>04</p>
</td>
<td class="cellrowborder" valign="top" width="26.119999999999997%" headers="mcps1.1.4.1.2 "><p id="p843614111576"><a name="p843614111576"></a><a name="p843614111576"></a>2025-12-01</p>
</td>
<td class="cellrowborder" valign="top" width="53.16%" headers="mcps1.1.4.1.3 "><p id="p112227533586"><a name="p112227533586"></a><a name="p112227533586"></a>更新“<a href="工具链toolchain配置.md">工具链toolchain配置</a>”章节内容。</p>
</td>
</tr>
<tr id="row8125121616245"><td class="cellrowborder" valign="top" width="20.72%" headers="mcps1.1.4.1.1 "><p id="p1812512163241"><a name="p1812512163241"></a><a name="p1812512163241"></a>03</p>
</td>
<td class="cellrowborder" valign="top" width="26.119999999999997%" headers="mcps1.1.4.1.2 "><p id="p3125141613244"><a name="p3125141613244"></a><a name="p3125141613244"></a>2025-11-07</p>
</td>
<td class="cellrowborder" valign="top" width="53.16%" headers="mcps1.1.4.1.3 "><a name="ul1488017437263"></a><a name="ul1488017437263"></a><ul id="ul1488017437263"><li>更新“<a href="工具链toolchain配置.md">工具链toolchain配置</a>”章节内容。</li><li>更新“<a href="配置工程的烧录选项.md">配置工程的烧录选项</a>”章节内容。</li><li>更新“<a href="启动调试.md">启动调试</a>”章节内容。</li><li>更新“<a href="扩展工具使用.md">扩展工具使用</a>”章节内容。</li></ul>
</td>
</tr>
<tr id="row121221241101914"><td class="cellrowborder" valign="top" width="20.72%" headers="mcps1.1.4.1.1 "><p id="p171231841111915"><a name="p171231841111915"></a><a name="p171231841111915"></a>02</p>
</td>
<td class="cellrowborder" valign="top" width="26.119999999999997%" headers="mcps1.1.4.1.2 "><p id="p151231941101920"><a name="p151231941101920"></a><a name="p151231941101920"></a>2025-08-07</p>
</td>
<td class="cellrowborder" valign="top" width="53.16%" headers="mcps1.1.4.1.3 "><p id="p3123104121911"><a name="p3123104121911"></a><a name="p3123104121911"></a>更新“<a href="工具简介.md">工具简介</a>”章节内容。</p>
</td>
</tr>
<tr id="row5281780716410"><td class="cellrowborder" valign="top" width="20.72%" headers="mcps1.1.4.1.1 "><p id="p559mcpsimp"><a name="p559mcpsimp"></a><a name="p559mcpsimp"></a>01</p>
</td>
<td class="cellrowborder" valign="top" width="26.119999999999997%" headers="mcps1.1.4.1.2 "><p id="p561mcpsimp"><a name="p561mcpsimp"></a><a name="p561mcpsimp"></a>2025-04-24</p>
</td>
<td class="cellrowborder" valign="top" width="53.16%" headers="mcps1.1.4.1.3 "><p id="p563mcpsimp"><a name="p563mcpsimp"></a><a name="p563mcpsimp"></a>第一次正式版本发布。</p>
</td>
</tr>
</tbody>
</table>

# 工具简介<a name="ZH-CN_TOPIC_0000002378877440"></a>

HiSpark Studio for VS Code插件面向智能设备开发者提供一站式集成开发环境。它提供给开发者代码编辑、编译、烧录和调试等功能，并支持C/C++语言，和64位Windows10或Windows11操作系统，该插件具有以下特点：

-   支持代码查找、代码高亮、代码自动补齐、代码输入提示、代码检查等，开发者可以轻松、高效编码。
-   支持单步调试和查看内存、变量、调用栈等调试信息。
-   支持自动检测各芯片/开发板依赖的工具链是否完备，并提供一键下载和安装缺失工具链。

HiSpark Studio for VS Code插件主要分为以下6个功能区域，如[图1](#zh-cn_topic_0000002293219986_fig19904573445)所示。

① WELCOME：提供欢迎页、使用指南、创建导入项目等选项。

② PROJECT EXPLORER：工程区文件展示区

③ COMMANDS：提供新建工程、打开工程、清除、编译、烧录等功能按钮及控制状态栏中的按钮显隐

④ 代码编辑区：提供代码的查看、编写、跳转、高亮等功能。

⑤ 输出控制台：提供操作日志的打印、调试命令的输入及命令行工具等功能。

⑥状态栏：提供常用功能按钮，包括新建工程、导入工程、工程配置、清除、编译、烧录等功能并显示当前文件的编码格式、行数、列数等信息。

**图 1**  功能分区图<a name="zh-cn_topic_0000002293219986_fig19904573445"></a>  
![](figures/功能分区图.png "功能分区图")

HiSpark Studio for VS Code插件当前支持的芯片和对应特性如[表1](#zh-cn_topic_0000002293219986_table82241939151116)所示。

**表 1**  HiSpark Studio for VS Code插件支持的芯片及其特性

<a name="zh-cn_topic_0000002293219986_table82241939151116"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002293219986_row1022415396111"><th class="cellrowborder" align="center" valign="top" width="14.190000000000003%" id="mcps1.2.8.1.1"><p id="zh-cn_topic_0000002293219986_p922433961112"><a name="zh-cn_topic_0000002293219986_p922433961112"></a><a name="zh-cn_topic_0000002293219986_p922433961112"></a>芯片系列</p>
</th>
<th class="cellrowborder" align="center" valign="top" width="13.040000000000001%" id="mcps1.2.8.1.2"><p id="zh-cn_topic_0000002293219986_p222453971118"><a name="zh-cn_topic_0000002293219986_p222453971118"></a><a name="zh-cn_topic_0000002293219986_p222453971118"></a>芯片名称</p>
</th>
<th class="cellrowborder" align="center" valign="top" width="13.200000000000003%" id="mcps1.2.8.1.3"><p id="zh-cn_topic_0000002293219986_p1822423917119"><a name="zh-cn_topic_0000002293219986_p1822423917119"></a><a name="zh-cn_topic_0000002293219986_p1822423917119"></a>工程管理</p>
</th>
<th class="cellrowborder" align="center" valign="top" width="13.250000000000004%" id="mcps1.2.8.1.4"><p id="zh-cn_topic_0000002293219986_p1628513136102"><a name="zh-cn_topic_0000002293219986_p1628513136102"></a><a name="zh-cn_topic_0000002293219986_p1628513136102"></a>编译运行</p>
</th>
<th class="cellrowborder" align="center" valign="top" width="13.040000000000001%" id="mcps1.2.8.1.5"><p id="zh-cn_topic_0000002293219986_p1791011019106"><a name="zh-cn_topic_0000002293219986_p1791011019106"></a><a name="zh-cn_topic_0000002293219986_p1791011019106"></a>一键烧录</p>
</th>
<th class="cellrowborder" align="center" valign="top" width="15.050000000000002%" id="mcps1.2.8.1.6"><p id="zh-cn_topic_0000002293219986_p681611181416"><a name="zh-cn_topic_0000002293219986_p681611181416"></a><a name="zh-cn_topic_0000002293219986_p681611181416"></a>烧录配置</p>
</th>
<th class="cellrowborder" align="center" valign="top" width="18.23%" id="mcps1.2.8.1.7"><p id="zh-cn_topic_0000002293219986_p178217711010"><a name="zh-cn_topic_0000002293219986_p178217711010"></a><a name="zh-cn_topic_0000002293219986_p178217711010"></a>栈分析和镜像分析</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002293219986_row8752133319518"><td class="cellrowborder" rowspan="11" align="center" valign="top" width="14.190000000000003%" headers="mcps1.2.8.1.1 "><p id="zh-cn_topic_0000002293219986_p3752153355114"><a name="zh-cn_topic_0000002293219986_p3752153355114"></a><a name="zh-cn_topic_0000002293219986_p3752153355114"></a>短距物联</p>
</td>
<td class="cellrowborder" align="center" valign="top" width="13.040000000000001%" headers="mcps1.2.8.1.2 "><p id="zh-cn_topic_0000002293219986_p1575233325112"><a name="zh-cn_topic_0000002293219986_p1575233325112"></a><a name="zh-cn_topic_0000002293219986_p1575233325112"></a>BS20</p>
</td>
<td class="cellrowborder" align="center" valign="top" width="13.200000000000003%" headers="mcps1.2.8.1.3 "><p id="zh-cn_topic_0000002293219986_p77527337518"><a name="zh-cn_topic_0000002293219986_p77527337518"></a><a name="zh-cn_topic_0000002293219986_p77527337518"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" width="13.250000000000004%" headers="mcps1.2.8.1.4 "><p id="zh-cn_topic_0000002293219986_p137521133115114"><a name="zh-cn_topic_0000002293219986_p137521133115114"></a><a name="zh-cn_topic_0000002293219986_p137521133115114"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" width="13.040000000000001%" headers="mcps1.2.8.1.5 "><p id="zh-cn_topic_0000002293219986_p1475293315119"><a name="zh-cn_topic_0000002293219986_p1475293315119"></a><a name="zh-cn_topic_0000002293219986_p1475293315119"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" width="15.050000000000002%" headers="mcps1.2.8.1.6 "><p id="zh-cn_topic_0000002293219986_p0752633185112"><a name="zh-cn_topic_0000002293219986_p0752633185112"></a><a name="zh-cn_topic_0000002293219986_p0752633185112"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" width="18.23%" headers="mcps1.2.8.1.7 "><p id="zh-cn_topic_0000002293219986_p375313334512"><a name="zh-cn_topic_0000002293219986_p375313334512"></a><a name="zh-cn_topic_0000002293219986_p375313334512"></a>√</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002293219986_row856371715552"><td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.1 "><p id="zh-cn_topic_0000002293219986_p3564191720552"><a name="zh-cn_topic_0000002293219986_p3564191720552"></a><a name="zh-cn_topic_0000002293219986_p3564191720552"></a>BS20C</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.2 "><p id="zh-cn_topic_0000002293219986_p12564181712557"><a name="zh-cn_topic_0000002293219986_p12564181712557"></a><a name="zh-cn_topic_0000002293219986_p12564181712557"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.3 "><p id="zh-cn_topic_0000002293219986_p7564141755514"><a name="zh-cn_topic_0000002293219986_p7564141755514"></a><a name="zh-cn_topic_0000002293219986_p7564141755514"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.4 "><p id="zh-cn_topic_0000002293219986_p135641417175520"><a name="zh-cn_topic_0000002293219986_p135641417175520"></a><a name="zh-cn_topic_0000002293219986_p135641417175520"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.5 "><p id="zh-cn_topic_0000002293219986_p1156412171554"><a name="zh-cn_topic_0000002293219986_p1156412171554"></a><a name="zh-cn_topic_0000002293219986_p1156412171554"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.6 "><p id="zh-cn_topic_0000002293219986_p195641117105513"><a name="zh-cn_topic_0000002293219986_p195641117105513"></a><a name="zh-cn_topic_0000002293219986_p195641117105513"></a>√</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002293219986_row222433913117"><td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.1 "><p id="zh-cn_topic_0000002293219986_p3224133916116"><a name="zh-cn_topic_0000002293219986_p3224133916116"></a><a name="zh-cn_topic_0000002293219986_p3224133916116"></a>BS21</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.2 "><p id="zh-cn_topic_0000002293219986_p165292113250"><a name="zh-cn_topic_0000002293219986_p165292113250"></a><a name="zh-cn_topic_0000002293219986_p165292113250"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.3 "><p id="zh-cn_topic_0000002293219986_p91102414261"><a name="zh-cn_topic_0000002293219986_p91102414261"></a><a name="zh-cn_topic_0000002293219986_p91102414261"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.4 "><p id="zh-cn_topic_0000002293219986_p733410487269"><a name="zh-cn_topic_0000002293219986_p733410487269"></a><a name="zh-cn_topic_0000002293219986_p733410487269"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.5 "><p id="zh-cn_topic_0000002293219986_p42591226173614"><a name="zh-cn_topic_0000002293219986_p42591226173614"></a><a name="zh-cn_topic_0000002293219986_p42591226173614"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.6 "><p id="zh-cn_topic_0000002293219986_p14948201272712"><a name="zh-cn_topic_0000002293219986_p14948201272712"></a><a name="zh-cn_topic_0000002293219986_p14948201272712"></a>√</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002293219986_row1151735116505"><td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.1 "><p id="zh-cn_topic_0000002293219986_p1851755155020"><a name="zh-cn_topic_0000002293219986_p1851755155020"></a><a name="zh-cn_topic_0000002293219986_p1851755155020"></a>BS21E</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.2 "><p id="zh-cn_topic_0000002293219986_p10517951165020"><a name="zh-cn_topic_0000002293219986_p10517951165020"></a><a name="zh-cn_topic_0000002293219986_p10517951165020"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.3 "><p id="zh-cn_topic_0000002293219986_p151719518507"><a name="zh-cn_topic_0000002293219986_p151719518507"></a><a name="zh-cn_topic_0000002293219986_p151719518507"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.4 "><p id="zh-cn_topic_0000002293219986_p551819510501"><a name="zh-cn_topic_0000002293219986_p551819510501"></a><a name="zh-cn_topic_0000002293219986_p551819510501"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.5 "><p id="zh-cn_topic_0000002293219986_p13518155155017"><a name="zh-cn_topic_0000002293219986_p13518155155017"></a><a name="zh-cn_topic_0000002293219986_p13518155155017"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.6 "><p id="zh-cn_topic_0000002293219986_p115181051165013"><a name="zh-cn_topic_0000002293219986_p115181051165013"></a><a name="zh-cn_topic_0000002293219986_p115181051165013"></a>√</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002293219986_row113809589516"><td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.1 "><p id="zh-cn_topic_0000002293219986_p1438014581514"><a name="zh-cn_topic_0000002293219986_p1438014581514"></a><a name="zh-cn_topic_0000002293219986_p1438014581514"></a>BS22</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.2 "><p id="zh-cn_topic_0000002293219986_p11380105875115"><a name="zh-cn_topic_0000002293219986_p11380105875115"></a><a name="zh-cn_topic_0000002293219986_p11380105875115"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.3 "><p id="zh-cn_topic_0000002293219986_p1380145835113"><a name="zh-cn_topic_0000002293219986_p1380145835113"></a><a name="zh-cn_topic_0000002293219986_p1380145835113"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.4 "><p id="zh-cn_topic_0000002293219986_p1238055865117"><a name="zh-cn_topic_0000002293219986_p1238055865117"></a><a name="zh-cn_topic_0000002293219986_p1238055865117"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.5 "><p id="zh-cn_topic_0000002293219986_p4380558165110"><a name="zh-cn_topic_0000002293219986_p4380558165110"></a><a name="zh-cn_topic_0000002293219986_p4380558165110"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.6 "><p id="zh-cn_topic_0000002293219986_p16380175814513"><a name="zh-cn_topic_0000002293219986_p16380175814513"></a><a name="zh-cn_topic_0000002293219986_p16380175814513"></a>√</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002293219986_row1099920117520"><td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.1 "><p id="zh-cn_topic_0000002293219986_p2999911165217"><a name="zh-cn_topic_0000002293219986_p2999911165217"></a><a name="zh-cn_topic_0000002293219986_p2999911165217"></a>BS26</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.2 "><p id="zh-cn_topic_0000002293219986_p89991411175217"><a name="zh-cn_topic_0000002293219986_p89991411175217"></a><a name="zh-cn_topic_0000002293219986_p89991411175217"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.3 "><p id="zh-cn_topic_0000002293219986_p1699941117521"><a name="zh-cn_topic_0000002293219986_p1699941117521"></a><a name="zh-cn_topic_0000002293219986_p1699941117521"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.4 "><p id="zh-cn_topic_0000002293219986_p69990117528"><a name="zh-cn_topic_0000002293219986_p69990117528"></a><a name="zh-cn_topic_0000002293219986_p69990117528"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.5 "><p id="zh-cn_topic_0000002293219986_p2999191195219"><a name="zh-cn_topic_0000002293219986_p2999191195219"></a><a name="zh-cn_topic_0000002293219986_p2999191195219"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.6 "><p id="zh-cn_topic_0000002293219986_p12999121125217"><a name="zh-cn_topic_0000002293219986_p12999121125217"></a><a name="zh-cn_topic_0000002293219986_p12999121125217"></a>√</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002293219986_row432645295215"><td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.1 "><p id="zh-cn_topic_0000002293219986_p18326115216527"><a name="zh-cn_topic_0000002293219986_p18326115216527"></a><a name="zh-cn_topic_0000002293219986_p18326115216527"></a>BS21A</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.2 "><p id="zh-cn_topic_0000002293219986_p83261529520"><a name="zh-cn_topic_0000002293219986_p83261529520"></a><a name="zh-cn_topic_0000002293219986_p83261529520"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.3 "><p id="zh-cn_topic_0000002293219986_p17326125216521"><a name="zh-cn_topic_0000002293219986_p17326125216521"></a><a name="zh-cn_topic_0000002293219986_p17326125216521"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.4 "><p id="zh-cn_topic_0000002293219986_p3326185275211"><a name="zh-cn_topic_0000002293219986_p3326185275211"></a><a name="zh-cn_topic_0000002293219986_p3326185275211"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.5 "><p id="zh-cn_topic_0000002293219986_p1632675295211"><a name="zh-cn_topic_0000002293219986_p1632675295211"></a><a name="zh-cn_topic_0000002293219986_p1632675295211"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.6 "><p id="zh-cn_topic_0000002293219986_p1132695218524"><a name="zh-cn_topic_0000002293219986_p1132695218524"></a><a name="zh-cn_topic_0000002293219986_p1132695218524"></a>√</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002293219986_row13345165719131"><td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.1 "><p id="zh-cn_topic_0000002293219986_p10345175731316"><a name="zh-cn_topic_0000002293219986_p10345175731316"></a><a name="zh-cn_topic_0000002293219986_p10345175731316"></a>BS25</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.2 "><p id="zh-cn_topic_0000002293219986_p992218259"><a name="zh-cn_topic_0000002293219986_p992218259"></a><a name="zh-cn_topic_0000002293219986_p992218259"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.3 "><p id="zh-cn_topic_0000002293219986_p7602154114264"><a name="zh-cn_topic_0000002293219986_p7602154114264"></a><a name="zh-cn_topic_0000002293219986_p7602154114264"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.4 "><p id="zh-cn_topic_0000002293219986_p1075134812263"><a name="zh-cn_topic_0000002293219986_p1075134812263"></a><a name="zh-cn_topic_0000002293219986_p1075134812263"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.5 "><p id="zh-cn_topic_0000002293219986_p151964296373"><a name="zh-cn_topic_0000002293219986_p151964296373"></a><a name="zh-cn_topic_0000002293219986_p151964296373"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.6 "><p id="zh-cn_topic_0000002293219986_p1432713122713"><a name="zh-cn_topic_0000002293219986_p1432713122713"></a><a name="zh-cn_topic_0000002293219986_p1432713122713"></a>√</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002293219986_row8258515586"><td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.1 "><p id="zh-cn_topic_0000002293219986_p7251957588"><a name="zh-cn_topic_0000002293219986_p7251957588"></a><a name="zh-cn_topic_0000002293219986_p7251957588"></a><span id="zh-cn_topic_0000002293219986_ph495858135813"><a name="zh-cn_topic_0000002293219986_ph495858135813"></a><a name="zh-cn_topic_0000002293219986_ph495858135813"></a>BS27A</span></p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.2 "><p id="zh-cn_topic_0000002293219986_p182520535814"><a name="zh-cn_topic_0000002293219986_p182520535814"></a><a name="zh-cn_topic_0000002293219986_p182520535814"></a><span id="zh-cn_topic_0000002293219986_ph1066516232218"><a name="zh-cn_topic_0000002293219986_ph1066516232218"></a><a name="zh-cn_topic_0000002293219986_ph1066516232218"></a>√</span></p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.3 "><p id="zh-cn_topic_0000002293219986_p6251258589"><a name="zh-cn_topic_0000002293219986_p6251258589"></a><a name="zh-cn_topic_0000002293219986_p6251258589"></a><span id="zh-cn_topic_0000002293219986_ph11867142492118"><a name="zh-cn_topic_0000002293219986_ph11867142492118"></a><a name="zh-cn_topic_0000002293219986_ph11867142492118"></a>√</span></p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.4 "><p id="zh-cn_topic_0000002293219986_p4251351580"><a name="zh-cn_topic_0000002293219986_p4251351580"></a><a name="zh-cn_topic_0000002293219986_p4251351580"></a><span id="zh-cn_topic_0000002293219986_ph20361128102120"><a name="zh-cn_topic_0000002293219986_ph20361128102120"></a><a name="zh-cn_topic_0000002293219986_ph20361128102120"></a>√</span></p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.5 "><p id="zh-cn_topic_0000002293219986_p825553584"><a name="zh-cn_topic_0000002293219986_p825553584"></a><a name="zh-cn_topic_0000002293219986_p825553584"></a><span id="zh-cn_topic_0000002293219986_ph88833257217"><a name="zh-cn_topic_0000002293219986_ph88833257217"></a><a name="zh-cn_topic_0000002293219986_ph88833257217"></a>√</span></p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.6 "><p id="zh-cn_topic_0000002293219986_p925165125819"><a name="zh-cn_topic_0000002293219986_p925165125819"></a><a name="zh-cn_topic_0000002293219986_p925165125819"></a><span id="zh-cn_topic_0000002293219986_ph11520122692111"><a name="zh-cn_topic_0000002293219986_ph11520122692111"></a><a name="zh-cn_topic_0000002293219986_ph11520122692111"></a>√</span></p>
</td>
</tr>
<tr id="zh-cn_topic_0000002293219986_row579411241563"><td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.1 "><p id="zh-cn_topic_0000002293219986_p167946241168"><a name="zh-cn_topic_0000002293219986_p167946241168"></a><a name="zh-cn_topic_0000002293219986_p167946241168"></a>WS53</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.2 "><p id="zh-cn_topic_0000002293219986_p379442412619"><a name="zh-cn_topic_0000002293219986_p379442412619"></a><a name="zh-cn_topic_0000002293219986_p379442412619"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.3 "><p id="zh-cn_topic_0000002293219986_p1979442414619"><a name="zh-cn_topic_0000002293219986_p1979442414619"></a><a name="zh-cn_topic_0000002293219986_p1979442414619"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.4 "><p id="zh-cn_topic_0000002293219986_p15794202411618"><a name="zh-cn_topic_0000002293219986_p15794202411618"></a><a name="zh-cn_topic_0000002293219986_p15794202411618"></a>×</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.5 "><p id="zh-cn_topic_0000002293219986_p167941224762"><a name="zh-cn_topic_0000002293219986_p167941224762"></a><a name="zh-cn_topic_0000002293219986_p167941224762"></a>×</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.6 "><p id="zh-cn_topic_0000002293219986_p7794182412617"><a name="zh-cn_topic_0000002293219986_p7794182412617"></a><a name="zh-cn_topic_0000002293219986_p7794182412617"></a>×</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002293219986_row176314319149"><td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.1 "><p id="zh-cn_topic_0000002293219986_p126310321414"><a name="zh-cn_topic_0000002293219986_p126310321414"></a><a name="zh-cn_topic_0000002293219986_p126310321414"></a>WS63</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.2 "><p id="zh-cn_topic_0000002293219986_p1550712232518"><a name="zh-cn_topic_0000002293219986_p1550712232518"></a><a name="zh-cn_topic_0000002293219986_p1550712232518"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.3 "><p id="zh-cn_topic_0000002293219986_p593142112617"><a name="zh-cn_topic_0000002293219986_p593142112617"></a><a name="zh-cn_topic_0000002293219986_p593142112617"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.4 "><p id="zh-cn_topic_0000002293219986_p19192124920269"><a name="zh-cn_topic_0000002293219986_p19192124920269"></a><a name="zh-cn_topic_0000002293219986_p19192124920269"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.5 "><p id="zh-cn_topic_0000002293219986_p564492953710"><a name="zh-cn_topic_0000002293219986_p564492953710"></a><a name="zh-cn_topic_0000002293219986_p564492953710"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.6 "><p id="zh-cn_topic_0000002293219986_p178569132279"><a name="zh-cn_topic_0000002293219986_p178569132279"></a><a name="zh-cn_topic_0000002293219986_p178569132279"></a>√</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002293219986_row1613915128"><td class="cellrowborder" rowspan="4" align="center" valign="top" width="14.190000000000003%" headers="mcps1.2.8.1.1 "><p id="zh-cn_topic_0000002293219986_p96123991212"><a name="zh-cn_topic_0000002293219986_p96123991212"></a><a name="zh-cn_topic_0000002293219986_p96123991212"></a>手机穿戴</p>
</td>
<td class="cellrowborder" align="center" valign="top" width="13.040000000000001%" headers="mcps1.2.8.1.2 "><p id="zh-cn_topic_0000002293219986_p16616394125"><a name="zh-cn_topic_0000002293219986_p16616394125"></a><a name="zh-cn_topic_0000002293219986_p16616394125"></a>BRANDY</p>
</td>
<td class="cellrowborder" align="center" valign="top" width="13.200000000000003%" headers="mcps1.2.8.1.3 "><p id="zh-cn_topic_0000002293219986_p142053192513"><a name="zh-cn_topic_0000002293219986_p142053192513"></a><a name="zh-cn_topic_0000002293219986_p142053192513"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" width="13.250000000000004%" headers="mcps1.2.8.1.4 "><p id="zh-cn_topic_0000002293219986_p563714262617"><a name="zh-cn_topic_0000002293219986_p563714262617"></a><a name="zh-cn_topic_0000002293219986_p563714262617"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" width="13.040000000000001%" headers="mcps1.2.8.1.5 "><p id="zh-cn_topic_0000002293219986_p7666164910261"><a name="zh-cn_topic_0000002293219986_p7666164910261"></a><a name="zh-cn_topic_0000002293219986_p7666164910261"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" width="15.050000000000002%" headers="mcps1.2.8.1.6 "><p id="zh-cn_topic_0000002293219986_p1614093013378"><a name="zh-cn_topic_0000002293219986_p1614093013378"></a><a name="zh-cn_topic_0000002293219986_p1614093013378"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" width="18.23%" headers="mcps1.2.8.1.7 "><p id="zh-cn_topic_0000002293219986_p826461492716"><a name="zh-cn_topic_0000002293219986_p826461492716"></a><a name="zh-cn_topic_0000002293219986_p826461492716"></a>√</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002293219986_row1514014131196"><td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.1 "><p id="zh-cn_topic_0000002293219986_p41409138198"><a name="zh-cn_topic_0000002293219986_p41409138198"></a><a name="zh-cn_topic_0000002293219986_p41409138198"></a>SOCMN2</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.2 "><p id="zh-cn_topic_0000002293219986_p2140313121920"><a name="zh-cn_topic_0000002293219986_p2140313121920"></a><a name="zh-cn_topic_0000002293219986_p2140313121920"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.3 "><p id="zh-cn_topic_0000002293219986_p13141171317194"><a name="zh-cn_topic_0000002293219986_p13141171317194"></a><a name="zh-cn_topic_0000002293219986_p13141171317194"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.4 "><p id="zh-cn_topic_0000002293219986_p1414151321913"><a name="zh-cn_topic_0000002293219986_p1414151321913"></a><a name="zh-cn_topic_0000002293219986_p1414151321913"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.5 "><p id="zh-cn_topic_0000002293219986_p20141413131919"><a name="zh-cn_topic_0000002293219986_p20141413131919"></a><a name="zh-cn_topic_0000002293219986_p20141413131919"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.6 "><p id="zh-cn_topic_0000002293219986_p20141313131920"><a name="zh-cn_topic_0000002293219986_p20141313131920"></a><a name="zh-cn_topic_0000002293219986_p20141313131920"></a>√</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002293219986_row8385122535814"><td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.1 "><p id="zh-cn_topic_0000002293219986_p113851625125815"><a name="zh-cn_topic_0000002293219986_p113851625125815"></a><a name="zh-cn_topic_0000002293219986_p113851625125815"></a><span id="zh-cn_topic_0000002293219986_ph1237103135810"><a name="zh-cn_topic_0000002293219986_ph1237103135810"></a><a name="zh-cn_topic_0000002293219986_ph1237103135810"></a>SW21</span></p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.2 "><p id="zh-cn_topic_0000002293219986_p4385162515813"><a name="zh-cn_topic_0000002293219986_p4385162515813"></a><a name="zh-cn_topic_0000002293219986_p4385162515813"></a><span id="zh-cn_topic_0000002293219986_ph1846752210218"><a name="zh-cn_topic_0000002293219986_ph1846752210218"></a><a name="zh-cn_topic_0000002293219986_ph1846752210218"></a>√</span></p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.3 "><p id="zh-cn_topic_0000002293219986_p143851125205818"><a name="zh-cn_topic_0000002293219986_p143851125205818"></a><a name="zh-cn_topic_0000002293219986_p143851125205818"></a><span id="zh-cn_topic_0000002293219986_ph9671222122117"><a name="zh-cn_topic_0000002293219986_ph9671222122117"></a><a name="zh-cn_topic_0000002293219986_ph9671222122117"></a>√</span></p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.4 "><p id="zh-cn_topic_0000002293219986_p8385025125819"><a name="zh-cn_topic_0000002293219986_p8385025125819"></a><a name="zh-cn_topic_0000002293219986_p8385025125819"></a><span id="zh-cn_topic_0000002293219986_ph35691021152111"><a name="zh-cn_topic_0000002293219986_ph35691021152111"></a><a name="zh-cn_topic_0000002293219986_ph35691021152111"></a>√</span></p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.5 "><p id="zh-cn_topic_0000002293219986_p1638512258582"><a name="zh-cn_topic_0000002293219986_p1638512258582"></a><a name="zh-cn_topic_0000002293219986_p1638512258582"></a><span id="zh-cn_topic_0000002293219986_ph4101192192111"><a name="zh-cn_topic_0000002293219986_ph4101192192111"></a><a name="zh-cn_topic_0000002293219986_ph4101192192111"></a>√</span></p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.6 "><p id="zh-cn_topic_0000002293219986_p13385225155818"><a name="zh-cn_topic_0000002293219986_p13385225155818"></a><a name="zh-cn_topic_0000002293219986_p13385225155818"></a><span id="zh-cn_topic_0000002293219986_ph263632020211"><a name="zh-cn_topic_0000002293219986_ph263632020211"></a><a name="zh-cn_topic_0000002293219986_ph263632020211"></a>√</span></p>
</td>
</tr>
<tr id="zh-cn_topic_0000002293219986_row034352451918"><td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.1 "><p id="zh-cn_topic_0000002293219986_p1934302419196"><a name="zh-cn_topic_0000002293219986_p1934302419196"></a><a name="zh-cn_topic_0000002293219986_p1934302419196"></a>3322</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.2 "><p id="zh-cn_topic_0000002293219986_p14343102441910"><a name="zh-cn_topic_0000002293219986_p14343102441910"></a><a name="zh-cn_topic_0000002293219986_p14343102441910"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.3 "><p id="zh-cn_topic_0000002293219986_p33431824191918"><a name="zh-cn_topic_0000002293219986_p33431824191918"></a><a name="zh-cn_topic_0000002293219986_p33431824191918"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.4 "><p id="zh-cn_topic_0000002293219986_p123431224121915"><a name="zh-cn_topic_0000002293219986_p123431224121915"></a><a name="zh-cn_topic_0000002293219986_p123431224121915"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.5 "><p id="zh-cn_topic_0000002293219986_p834442416196"><a name="zh-cn_topic_0000002293219986_p834442416196"></a><a name="zh-cn_topic_0000002293219986_p834442416196"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.6 "><p id="zh-cn_topic_0000002293219986_p934417242193"><a name="zh-cn_topic_0000002293219986_p934417242193"></a><a name="zh-cn_topic_0000002293219986_p934417242193"></a>√</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002293219986_row67644412126"><td class="cellrowborder" rowspan="6" align="center" valign="top" width="14.190000000000003%" headers="mcps1.2.8.1.1 "><p id="zh-cn_topic_0000002293219986_p180416585556"><a name="zh-cn_topic_0000002293219986_p180416585556"></a><a name="zh-cn_topic_0000002293219986_p180416585556"></a>广域物联</p>
</td>
<td class="cellrowborder" align="center" valign="top" width="13.040000000000001%" headers="mcps1.2.8.1.2 "><p id="zh-cn_topic_0000002293219986_p19764114115121"><a name="zh-cn_topic_0000002293219986_p19764114115121"></a><a name="zh-cn_topic_0000002293219986_p19764114115121"></a>NB17</p>
</td>
<td class="cellrowborder" align="center" valign="top" width="13.200000000000003%" headers="mcps1.2.8.1.3 "><p id="zh-cn_topic_0000002293219986_p854012302516"><a name="zh-cn_topic_0000002293219986_p854012302516"></a><a name="zh-cn_topic_0000002293219986_p854012302516"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" width="13.250000000000004%" headers="mcps1.2.8.1.4 "><p id="zh-cn_topic_0000002293219986_p10125174312611"><a name="zh-cn_topic_0000002293219986_p10125174312611"></a><a name="zh-cn_topic_0000002293219986_p10125174312611"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" width="13.040000000000001%" headers="mcps1.2.8.1.5 "><p id="zh-cn_topic_0000002293219986_p29616507262"><a name="zh-cn_topic_0000002293219986_p29616507262"></a><a name="zh-cn_topic_0000002293219986_p29616507262"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" width="15.050000000000002%" headers="mcps1.2.8.1.6 "><p id="zh-cn_topic_0000002293219986_p10614153017372"><a name="zh-cn_topic_0000002293219986_p10614153017372"></a><a name="zh-cn_topic_0000002293219986_p10614153017372"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" width="18.23%" headers="mcps1.2.8.1.7 "><p id="zh-cn_topic_0000002293219986_p468915140272"><a name="zh-cn_topic_0000002293219986_p468915140272"></a><a name="zh-cn_topic_0000002293219986_p468915140272"></a>√</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002293219986_row2177728131414"><td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.1 "><p id="zh-cn_topic_0000002293219986_p617772817147"><a name="zh-cn_topic_0000002293219986_p617772817147"></a><a name="zh-cn_topic_0000002293219986_p617772817147"></a>NB17E</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.2 "><p id="zh-cn_topic_0000002293219986_p918064132516"><a name="zh-cn_topic_0000002293219986_p918064132516"></a><a name="zh-cn_topic_0000002293219986_p918064132516"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.3 "><p id="zh-cn_topic_0000002293219986_p13615843162613"><a name="zh-cn_topic_0000002293219986_p13615843162613"></a><a name="zh-cn_topic_0000002293219986_p13615843162613"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.4 "><p id="zh-cn_topic_0000002293219986_p8559125018268"><a name="zh-cn_topic_0000002293219986_p8559125018268"></a><a name="zh-cn_topic_0000002293219986_p8559125018268"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.5 "><p id="zh-cn_topic_0000002293219986_p39123110372"><a name="zh-cn_topic_0000002293219986_p39123110372"></a><a name="zh-cn_topic_0000002293219986_p39123110372"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.6 "><p id="zh-cn_topic_0000002293219986_p1624131817275"><a name="zh-cn_topic_0000002293219986_p1624131817275"></a><a name="zh-cn_topic_0000002293219986_p1624131817275"></a>√</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002293219986_row175351302145"><td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.1 "><p id="zh-cn_topic_0000002293219986_p1053513304143"><a name="zh-cn_topic_0000002293219986_p1053513304143"></a><a name="zh-cn_topic_0000002293219986_p1053513304143"></a>NB18</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.2 "><p id="zh-cn_topic_0000002293219986_p127882452512"><a name="zh-cn_topic_0000002293219986_p127882452512"></a><a name="zh-cn_topic_0000002293219986_p127882452512"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.3 "><p id="zh-cn_topic_0000002293219986_p109334432614"><a name="zh-cn_topic_0000002293219986_p109334432614"></a><a name="zh-cn_topic_0000002293219986_p109334432614"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.4 "><p id="zh-cn_topic_0000002293219986_p812810510265"><a name="zh-cn_topic_0000002293219986_p812810510265"></a><a name="zh-cn_topic_0000002293219986_p812810510265"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.5 "><p id="zh-cn_topic_0000002293219986_p3500431143718"><a name="zh-cn_topic_0000002293219986_p3500431143718"></a><a name="zh-cn_topic_0000002293219986_p3500431143718"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.6 "><p id="zh-cn_topic_0000002293219986_p146971118102718"><a name="zh-cn_topic_0000002293219986_p146971118102718"></a><a name="zh-cn_topic_0000002293219986_p146971118102718"></a>√</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002293219986_row437904310588"><td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.1 "><p id="zh-cn_topic_0000002293219986_p12379124310581"><a name="zh-cn_topic_0000002293219986_p12379124310581"></a><a name="zh-cn_topic_0000002293219986_p12379124310581"></a><span id="zh-cn_topic_0000002293219986_ph492484719589"><a name="zh-cn_topic_0000002293219986_ph492484719589"></a><a name="zh-cn_topic_0000002293219986_ph492484719589"></a>Hi2113</span></p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.2 "><p id="zh-cn_topic_0000002293219986_p1937916431586"><a name="zh-cn_topic_0000002293219986_p1937916431586"></a><a name="zh-cn_topic_0000002293219986_p1937916431586"></a><span id="zh-cn_topic_0000002293219986_ph01604177216"><a name="zh-cn_topic_0000002293219986_ph01604177216"></a><a name="zh-cn_topic_0000002293219986_ph01604177216"></a>√</span></p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.3 "><p id="zh-cn_topic_0000002293219986_p937964335818"><a name="zh-cn_topic_0000002293219986_p937964335818"></a><a name="zh-cn_topic_0000002293219986_p937964335818"></a><span id="zh-cn_topic_0000002293219986_ph1656761717212"><a name="zh-cn_topic_0000002293219986_ph1656761717212"></a><a name="zh-cn_topic_0000002293219986_ph1656761717212"></a>√</span></p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.4 "><p id="zh-cn_topic_0000002293219986_p837913433581"><a name="zh-cn_topic_0000002293219986_p837913433581"></a><a name="zh-cn_topic_0000002293219986_p837913433581"></a><span id="zh-cn_topic_0000002293219986_ph12115518122115"><a name="zh-cn_topic_0000002293219986_ph12115518122115"></a><a name="zh-cn_topic_0000002293219986_ph12115518122115"></a>√</span></p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.5 "><p id="zh-cn_topic_0000002293219986_p11379184345816"><a name="zh-cn_topic_0000002293219986_p11379184345816"></a><a name="zh-cn_topic_0000002293219986_p11379184345816"></a><span id="zh-cn_topic_0000002293219986_ph1287212182213"><a name="zh-cn_topic_0000002293219986_ph1287212182213"></a><a name="zh-cn_topic_0000002293219986_ph1287212182213"></a>√</span></p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.6 "><p id="zh-cn_topic_0000002293219986_p4379143175818"><a name="zh-cn_topic_0000002293219986_p4379143175818"></a><a name="zh-cn_topic_0000002293219986_p4379143175818"></a><span id="zh-cn_topic_0000002293219986_ph5297619192117"><a name="zh-cn_topic_0000002293219986_ph5297619192117"></a><a name="zh-cn_topic_0000002293219986_ph5297619192117"></a>√</span></p>
</td>
</tr>
<tr id="zh-cn_topic_0000002293219986_row1942754735817"><td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.1 "><p id="zh-cn_topic_0000002293219986_p1542784735818"><a name="zh-cn_topic_0000002293219986_p1542784735818"></a><a name="zh-cn_topic_0000002293219986_p1542784735818"></a>Hi2131</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.2 "><p id="zh-cn_topic_0000002293219986_p204271747175813"><a name="zh-cn_topic_0000002293219986_p204271747175813"></a><a name="zh-cn_topic_0000002293219986_p204271747175813"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.3 "><p id="zh-cn_topic_0000002293219986_p154282475587"><a name="zh-cn_topic_0000002293219986_p154282475587"></a><a name="zh-cn_topic_0000002293219986_p154282475587"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.4 "><p id="zh-cn_topic_0000002293219986_p10428194775820"><a name="zh-cn_topic_0000002293219986_p10428194775820"></a><a name="zh-cn_topic_0000002293219986_p10428194775820"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.5 "><p id="zh-cn_topic_0000002293219986_p13428194711582"><a name="zh-cn_topic_0000002293219986_p13428194711582"></a><a name="zh-cn_topic_0000002293219986_p13428194711582"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.6 "><p id="zh-cn_topic_0000002293219986_p542854735815"><a name="zh-cn_topic_0000002293219986_p542854735815"></a><a name="zh-cn_topic_0000002293219986_p542854735815"></a>√</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002293219986_row22191153205817"><td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.1 "><p id="zh-cn_topic_0000002293219986_p92191653185816"><a name="zh-cn_topic_0000002293219986_p92191653185816"></a><a name="zh-cn_topic_0000002293219986_p92191653185816"></a>Hi2131C</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.2 "><p id="zh-cn_topic_0000002293219986_p18219253135817"><a name="zh-cn_topic_0000002293219986_p18219253135817"></a><a name="zh-cn_topic_0000002293219986_p18219253135817"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.3 "><p id="zh-cn_topic_0000002293219986_p182191653185811"><a name="zh-cn_topic_0000002293219986_p182191653185811"></a><a name="zh-cn_topic_0000002293219986_p182191653185811"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.4 "><p id="zh-cn_topic_0000002293219986_p621935375813"><a name="zh-cn_topic_0000002293219986_p621935375813"></a><a name="zh-cn_topic_0000002293219986_p621935375813"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.5 "><p id="zh-cn_topic_0000002293219986_p021985315814"><a name="zh-cn_topic_0000002293219986_p021985315814"></a><a name="zh-cn_topic_0000002293219986_p021985315814"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.2.8.1.6 "><p id="zh-cn_topic_0000002293219986_p221935314588"><a name="zh-cn_topic_0000002293219986_p221935314588"></a><a name="zh-cn_topic_0000002293219986_p221935314588"></a>√</p>
</td>
</tr>
</tbody>
</table>

<a name="zh-cn_topic_0000002293219986_table96567201482"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002293219986_row2657720174815"><th class="cellrowborder" align="center" valign="top" width="16.13%" id="mcps1.1.7.1.1"><p id="zh-cn_topic_0000002293219986_p865715205483"><a name="zh-cn_topic_0000002293219986_p865715205483"></a><a name="zh-cn_topic_0000002293219986_p865715205483"></a>芯片系列</p>
</th>
<th class="cellrowborder" align="center" valign="top" width="16.79%" id="mcps1.1.7.1.2"><p id="zh-cn_topic_0000002293219986_p765712064811"><a name="zh-cn_topic_0000002293219986_p765712064811"></a><a name="zh-cn_topic_0000002293219986_p765712064811"></a>芯片名称</p>
</th>
<th class="cellrowborder" align="center" valign="top" width="14.82%" id="mcps1.1.7.1.3"><p id="zh-cn_topic_0000002293219986_p17657820164818"><a name="zh-cn_topic_0000002293219986_p17657820164818"></a><a name="zh-cn_topic_0000002293219986_p17657820164818"></a>工程调试</p>
</th>
<th class="cellrowborder" align="center" valign="top" width="17.560000000000002%" id="mcps1.1.7.1.4"><p id="zh-cn_topic_0000002293219986_p1065792019487"><a name="zh-cn_topic_0000002293219986_p1065792019487"></a><a name="zh-cn_topic_0000002293219986_p1065792019487"></a>串口控制台</p>
</th>
<th class="cellrowborder" align="center" valign="top" width="18.33%" id="mcps1.1.7.1.5"><p id="zh-cn_topic_0000002293219986_p66572209480"><a name="zh-cn_topic_0000002293219986_p66572209480"></a><a name="zh-cn_topic_0000002293219986_p66572209480"></a>Kconfig</p>
</th>
<th class="cellrowborder" align="center" valign="top" width="16.37%" id="mcps1.1.7.1.6"><p id="zh-cn_topic_0000002293219986_p16164541155117"><a name="zh-cn_topic_0000002293219986_p16164541155117"></a><a name="zh-cn_topic_0000002293219986_p16164541155117"></a>CodeSize</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002293219986_row1275813324531"><td class="cellrowborder" rowspan="11" align="center" valign="top" width="16.13%" headers="mcps1.1.7.1.1 "><p id="zh-cn_topic_0000002293219986_p27588321539"><a name="zh-cn_topic_0000002293219986_p27588321539"></a><a name="zh-cn_topic_0000002293219986_p27588321539"></a>短距物联</p>
</td>
<td class="cellrowborder" align="center" valign="top" width="16.79%" headers="mcps1.1.7.1.2 "><p id="zh-cn_topic_0000002293219986_p6758183235313"><a name="zh-cn_topic_0000002293219986_p6758183235313"></a><a name="zh-cn_topic_0000002293219986_p6758183235313"></a>BS20</p>
</td>
<td class="cellrowborder" align="center" valign="top" width="14.82%" headers="mcps1.1.7.1.3 "><p id="zh-cn_topic_0000002293219986_p2075893216533"><a name="zh-cn_topic_0000002293219986_p2075893216533"></a><a name="zh-cn_topic_0000002293219986_p2075893216533"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" width="17.560000000000002%" headers="mcps1.1.7.1.4 "><p id="zh-cn_topic_0000002293219986_p975813255319"><a name="zh-cn_topic_0000002293219986_p975813255319"></a><a name="zh-cn_topic_0000002293219986_p975813255319"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" width="18.33%" headers="mcps1.1.7.1.5 "><p id="zh-cn_topic_0000002293219986_p37586329531"><a name="zh-cn_topic_0000002293219986_p37586329531"></a><a name="zh-cn_topic_0000002293219986_p37586329531"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" width="16.37%" headers="mcps1.1.7.1.6 "><p id="zh-cn_topic_0000002293219986_p7758163215312"><a name="zh-cn_topic_0000002293219986_p7758163215312"></a><a name="zh-cn_topic_0000002293219986_p7758163215312"></a>√</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002293219986_row156021450145517"><td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.1 "><p id="zh-cn_topic_0000002293219986_p14602050185512"><a name="zh-cn_topic_0000002293219986_p14602050185512"></a><a name="zh-cn_topic_0000002293219986_p14602050185512"></a>BS20C</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.2 "><p id="zh-cn_topic_0000002293219986_p0602155035519"><a name="zh-cn_topic_0000002293219986_p0602155035519"></a><a name="zh-cn_topic_0000002293219986_p0602155035519"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.3 "><p id="zh-cn_topic_0000002293219986_p12602250185511"><a name="zh-cn_topic_0000002293219986_p12602250185511"></a><a name="zh-cn_topic_0000002293219986_p12602250185511"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.4 "><p id="zh-cn_topic_0000002293219986_p20602135015559"><a name="zh-cn_topic_0000002293219986_p20602135015559"></a><a name="zh-cn_topic_0000002293219986_p20602135015559"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.5 "><p id="zh-cn_topic_0000002293219986_p8602350135518"><a name="zh-cn_topic_0000002293219986_p8602350135518"></a><a name="zh-cn_topic_0000002293219986_p8602350135518"></a>√</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002293219986_row166617208485"><td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.1 "><p id="zh-cn_topic_0000002293219986_p966192034812"><a name="zh-cn_topic_0000002293219986_p966192034812"></a><a name="zh-cn_topic_0000002293219986_p966192034812"></a>BS21</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.2 "><p id="zh-cn_topic_0000002293219986_p6661120144815"><a name="zh-cn_topic_0000002293219986_p6661120144815"></a><a name="zh-cn_topic_0000002293219986_p6661120144815"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.3 "><p id="zh-cn_topic_0000002293219986_p1766152020481"><a name="zh-cn_topic_0000002293219986_p1766152020481"></a><a name="zh-cn_topic_0000002293219986_p1766152020481"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.4 "><p id="zh-cn_topic_0000002293219986_p366113202489"><a name="zh-cn_topic_0000002293219986_p366113202489"></a><a name="zh-cn_topic_0000002293219986_p366113202489"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.5 "><p id="zh-cn_topic_0000002293219986_p10628143205115"><a name="zh-cn_topic_0000002293219986_p10628143205115"></a><a name="zh-cn_topic_0000002293219986_p10628143205115"></a>√</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002293219986_row208491395553"><td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.1 "><p id="zh-cn_topic_0000002293219986_p7850173965510"><a name="zh-cn_topic_0000002293219986_p7850173965510"></a><a name="zh-cn_topic_0000002293219986_p7850173965510"></a>BS21E</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.2 "><p id="zh-cn_topic_0000002293219986_p16850193920551"><a name="zh-cn_topic_0000002293219986_p16850193920551"></a><a name="zh-cn_topic_0000002293219986_p16850193920551"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.3 "><p id="zh-cn_topic_0000002293219986_p14850173919554"><a name="zh-cn_topic_0000002293219986_p14850173919554"></a><a name="zh-cn_topic_0000002293219986_p14850173919554"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.4 "><p id="zh-cn_topic_0000002293219986_p58501439105515"><a name="zh-cn_topic_0000002293219986_p58501439105515"></a><a name="zh-cn_topic_0000002293219986_p58501439105515"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.5 "><p id="zh-cn_topic_0000002293219986_p8850339135516"><a name="zh-cn_topic_0000002293219986_p8850339135516"></a><a name="zh-cn_topic_0000002293219986_p8850339135516"></a>√</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002293219986_row102766536552"><td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.1 "><p id="zh-cn_topic_0000002293219986_p1276135313554"><a name="zh-cn_topic_0000002293219986_p1276135313554"></a><a name="zh-cn_topic_0000002293219986_p1276135313554"></a>BS22</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.2 "><p id="zh-cn_topic_0000002293219986_p142771953155520"><a name="zh-cn_topic_0000002293219986_p142771953155520"></a><a name="zh-cn_topic_0000002293219986_p142771953155520"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.3 "><p id="zh-cn_topic_0000002293219986_p162771853185520"><a name="zh-cn_topic_0000002293219986_p162771853185520"></a><a name="zh-cn_topic_0000002293219986_p162771853185520"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.4 "><p id="zh-cn_topic_0000002293219986_p13277853155520"><a name="zh-cn_topic_0000002293219986_p13277853155520"></a><a name="zh-cn_topic_0000002293219986_p13277853155520"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.5 "><p id="zh-cn_topic_0000002293219986_p192771153205514"><a name="zh-cn_topic_0000002293219986_p192771153205514"></a><a name="zh-cn_topic_0000002293219986_p192771153205514"></a>√</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002293219986_row1327712530556"><td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.1 "><p id="zh-cn_topic_0000002293219986_p4277135310557"><a name="zh-cn_topic_0000002293219986_p4277135310557"></a><a name="zh-cn_topic_0000002293219986_p4277135310557"></a>BS26</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.2 "><p id="zh-cn_topic_0000002293219986_p1227725318554"><a name="zh-cn_topic_0000002293219986_p1227725318554"></a><a name="zh-cn_topic_0000002293219986_p1227725318554"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.3 "><p id="zh-cn_topic_0000002293219986_p1827705317556"><a name="zh-cn_topic_0000002293219986_p1827705317556"></a><a name="zh-cn_topic_0000002293219986_p1827705317556"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.4 "><p id="zh-cn_topic_0000002293219986_p112771953125518"><a name="zh-cn_topic_0000002293219986_p112771953125518"></a><a name="zh-cn_topic_0000002293219986_p112771953125518"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.5 "><p id="zh-cn_topic_0000002293219986_p1927712539551"><a name="zh-cn_topic_0000002293219986_p1927712539551"></a><a name="zh-cn_topic_0000002293219986_p1927712539551"></a>√</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002293219986_row156985158569"><td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.1 "><p id="zh-cn_topic_0000002293219986_p12698171525617"><a name="zh-cn_topic_0000002293219986_p12698171525617"></a><a name="zh-cn_topic_0000002293219986_p12698171525617"></a>BS21A</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.2 "><p id="zh-cn_topic_0000002293219986_p569812158565"><a name="zh-cn_topic_0000002293219986_p569812158565"></a><a name="zh-cn_topic_0000002293219986_p569812158565"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.3 "><p id="zh-cn_topic_0000002293219986_p146981615185619"><a name="zh-cn_topic_0000002293219986_p146981615185619"></a><a name="zh-cn_topic_0000002293219986_p146981615185619"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.4 "><p id="zh-cn_topic_0000002293219986_p18698121516562"><a name="zh-cn_topic_0000002293219986_p18698121516562"></a><a name="zh-cn_topic_0000002293219986_p18698121516562"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.5 "><p id="zh-cn_topic_0000002293219986_p1669831515567"><a name="zh-cn_topic_0000002293219986_p1669831515567"></a><a name="zh-cn_topic_0000002293219986_p1669831515567"></a>√</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002293219986_row17661182054815"><td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.1 "><p id="zh-cn_topic_0000002293219986_p136611520154812"><a name="zh-cn_topic_0000002293219986_p136611520154812"></a><a name="zh-cn_topic_0000002293219986_p136611520154812"></a>BS25</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.2 "><p id="zh-cn_topic_0000002293219986_p7662152074813"><a name="zh-cn_topic_0000002293219986_p7662152074813"></a><a name="zh-cn_topic_0000002293219986_p7662152074813"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.3 "><p id="zh-cn_topic_0000002293219986_p766292011482"><a name="zh-cn_topic_0000002293219986_p766292011482"></a><a name="zh-cn_topic_0000002293219986_p766292011482"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.4 "><p id="zh-cn_topic_0000002293219986_p116621320194811"><a name="zh-cn_topic_0000002293219986_p116621320194811"></a><a name="zh-cn_topic_0000002293219986_p116621320194811"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.5 "><p id="zh-cn_topic_0000002293219986_p662823213516"><a name="zh-cn_topic_0000002293219986_p662823213516"></a><a name="zh-cn_topic_0000002293219986_p662823213516"></a>√</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002293219986_row179291357165814"><td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.1 "><p id="zh-cn_topic_0000002293219986_p892918575589"><a name="zh-cn_topic_0000002293219986_p892918575589"></a><a name="zh-cn_topic_0000002293219986_p892918575589"></a><span id="zh-cn_topic_0000002293219986_ph179041018590"><a name="zh-cn_topic_0000002293219986_ph179041018590"></a><a name="zh-cn_topic_0000002293219986_ph179041018590"></a>BS27a</span></p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.2 "><p id="zh-cn_topic_0000002293219986_p18929115716587"><a name="zh-cn_topic_0000002293219986_p18929115716587"></a><a name="zh-cn_topic_0000002293219986_p18929115716587"></a><span id="zh-cn_topic_0000002293219986_ph152181515122111"><a name="zh-cn_topic_0000002293219986_ph152181515122111"></a><a name="zh-cn_topic_0000002293219986_ph152181515122111"></a>√</span></p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.3 "><p id="zh-cn_topic_0000002293219986_p49291857115818"><a name="zh-cn_topic_0000002293219986_p49291857115818"></a><a name="zh-cn_topic_0000002293219986_p49291857115818"></a><span id="zh-cn_topic_0000002293219986_ph46291141215"><a name="zh-cn_topic_0000002293219986_ph46291141215"></a><a name="zh-cn_topic_0000002293219986_ph46291141215"></a>√</span></p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.4 "><p id="zh-cn_topic_0000002293219986_p792975775810"><a name="zh-cn_topic_0000002293219986_p792975775810"></a><a name="zh-cn_topic_0000002293219986_p792975775810"></a><span id="zh-cn_topic_0000002293219986_ph89194419218"><a name="zh-cn_topic_0000002293219986_ph89194419218"></a><a name="zh-cn_topic_0000002293219986_ph89194419218"></a>×</span></p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.5 "><p id="zh-cn_topic_0000002293219986_p39291457135810"><a name="zh-cn_topic_0000002293219986_p39291457135810"></a><a name="zh-cn_topic_0000002293219986_p39291457135810"></a><span id="zh-cn_topic_0000002293219986_ph959514511214"><a name="zh-cn_topic_0000002293219986_ph959514511214"></a><a name="zh-cn_topic_0000002293219986_ph959514511214"></a>×</span></p>
</td>
</tr>
<tr id="zh-cn_topic_0000002293219986_row3662152014814"><td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.1 "><p id="zh-cn_topic_0000002293219986_p566242064819"><a name="zh-cn_topic_0000002293219986_p566242064819"></a><a name="zh-cn_topic_0000002293219986_p566242064819"></a>WS53</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.2 "><p id="zh-cn_topic_0000002293219986_p1366292044815"><a name="zh-cn_topic_0000002293219986_p1366292044815"></a><a name="zh-cn_topic_0000002293219986_p1366292044815"></a>×</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.3 "><p id="zh-cn_topic_0000002293219986_p1866232015485"><a name="zh-cn_topic_0000002293219986_p1866232015485"></a><a name="zh-cn_topic_0000002293219986_p1866232015485"></a>×</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.4 "><p id="zh-cn_topic_0000002293219986_p156621120124816"><a name="zh-cn_topic_0000002293219986_p156621120124816"></a><a name="zh-cn_topic_0000002293219986_p156621120124816"></a>×</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.5 "><p id="zh-cn_topic_0000002293219986_p262833265116"><a name="zh-cn_topic_0000002293219986_p262833265116"></a><a name="zh-cn_topic_0000002293219986_p262833265116"></a>√</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002293219986_row15662020134810"><td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.1 "><p id="zh-cn_topic_0000002293219986_p16629207481"><a name="zh-cn_topic_0000002293219986_p16629207481"></a><a name="zh-cn_topic_0000002293219986_p16629207481"></a>WS63</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.2 "><p id="zh-cn_topic_0000002293219986_p1266317207489"><a name="zh-cn_topic_0000002293219986_p1266317207489"></a><a name="zh-cn_topic_0000002293219986_p1266317207489"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.3 "><p id="zh-cn_topic_0000002293219986_p7663172054810"><a name="zh-cn_topic_0000002293219986_p7663172054810"></a><a name="zh-cn_topic_0000002293219986_p7663172054810"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.4 "><p id="zh-cn_topic_0000002293219986_p1766311204489"><a name="zh-cn_topic_0000002293219986_p1766311204489"></a><a name="zh-cn_topic_0000002293219986_p1766311204489"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.5 "><p id="zh-cn_topic_0000002293219986_p1628123265117"><a name="zh-cn_topic_0000002293219986_p1628123265117"></a><a name="zh-cn_topic_0000002293219986_p1628123265117"></a>√</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002293219986_row066322014487"><td class="cellrowborder" rowspan="4" align="center" valign="top" width="16.13%" headers="mcps1.1.7.1.1 "><p id="zh-cn_topic_0000002293219986_p10663820184817"><a name="zh-cn_topic_0000002293219986_p10663820184817"></a><a name="zh-cn_topic_0000002293219986_p10663820184817"></a>手机穿戴</p>
</td>
<td class="cellrowborder" align="center" valign="top" width="16.79%" headers="mcps1.1.7.1.2 "><p id="zh-cn_topic_0000002293219986_p18663420134812"><a name="zh-cn_topic_0000002293219986_p18663420134812"></a><a name="zh-cn_topic_0000002293219986_p18663420134812"></a>BRANDY</p>
</td>
<td class="cellrowborder" align="center" valign="top" width="14.82%" headers="mcps1.1.7.1.3 "><p id="zh-cn_topic_0000002293219986_p146631120144818"><a name="zh-cn_topic_0000002293219986_p146631120144818"></a><a name="zh-cn_topic_0000002293219986_p146631120144818"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" width="17.560000000000002%" headers="mcps1.1.7.1.4 "><p id="zh-cn_topic_0000002293219986_p17663320174810"><a name="zh-cn_topic_0000002293219986_p17663320174810"></a><a name="zh-cn_topic_0000002293219986_p17663320174810"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" width="18.33%" headers="mcps1.1.7.1.5 "><p id="zh-cn_topic_0000002293219986_p466312064817"><a name="zh-cn_topic_0000002293219986_p466312064817"></a><a name="zh-cn_topic_0000002293219986_p466312064817"></a>×</p>
</td>
<td class="cellrowborder" align="center" valign="top" width="16.37%" headers="mcps1.1.7.1.6 "><p id="zh-cn_topic_0000002293219986_p2062919321517"><a name="zh-cn_topic_0000002293219986_p2062919321517"></a><a name="zh-cn_topic_0000002293219986_p2062919321517"></a>√</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002293219986_row258119818219"><td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.1 "><p id="zh-cn_topic_0000002293219986_p5581118142119"><a name="zh-cn_topic_0000002293219986_p5581118142119"></a><a name="zh-cn_topic_0000002293219986_p5581118142119"></a>SOCMN2</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.2 "><p id="zh-cn_topic_0000002293219986_p105810872118"><a name="zh-cn_topic_0000002293219986_p105810872118"></a><a name="zh-cn_topic_0000002293219986_p105810872118"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.3 "><p id="zh-cn_topic_0000002293219986_p19581198132117"><a name="zh-cn_topic_0000002293219986_p19581198132117"></a><a name="zh-cn_topic_0000002293219986_p19581198132117"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.4 "><p id="zh-cn_topic_0000002293219986_p658212882112"><a name="zh-cn_topic_0000002293219986_p658212882112"></a><a name="zh-cn_topic_0000002293219986_p658212882112"></a>×</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.5 "><p id="zh-cn_topic_0000002293219986_p175829814215"><a name="zh-cn_topic_0000002293219986_p175829814215"></a><a name="zh-cn_topic_0000002293219986_p175829814215"></a>√</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002293219986_row457619918597"><td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.1 "><p id="zh-cn_topic_0000002293219986_p557710917597"><a name="zh-cn_topic_0000002293219986_p557710917597"></a><a name="zh-cn_topic_0000002293219986_p557710917597"></a><span id="zh-cn_topic_0000002293219986_ph628019113593"><a name="zh-cn_topic_0000002293219986_ph628019113593"></a><a name="zh-cn_topic_0000002293219986_ph628019113593"></a>SW21</span></p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.2 "><p id="zh-cn_topic_0000002293219986_p195774965916"><a name="zh-cn_topic_0000002293219986_p195774965916"></a><a name="zh-cn_topic_0000002293219986_p195774965916"></a><span id="zh-cn_topic_0000002293219986_ph1819215319264"><a name="zh-cn_topic_0000002293219986_ph1819215319264"></a><a name="zh-cn_topic_0000002293219986_ph1819215319264"></a>√</span></p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.3 "><p id="zh-cn_topic_0000002293219986_p95772911596"><a name="zh-cn_topic_0000002293219986_p95772911596"></a><a name="zh-cn_topic_0000002293219986_p95772911596"></a><span id="zh-cn_topic_0000002293219986_ph1181375311264"><a name="zh-cn_topic_0000002293219986_ph1181375311264"></a><a name="zh-cn_topic_0000002293219986_ph1181375311264"></a>√</span></p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.4 "><p id="zh-cn_topic_0000002293219986_p1057712955913"><a name="zh-cn_topic_0000002293219986_p1057712955913"></a><a name="zh-cn_topic_0000002293219986_p1057712955913"></a><span id="zh-cn_topic_0000002293219986_ph765181182112"><a name="zh-cn_topic_0000002293219986_ph765181182112"></a><a name="zh-cn_topic_0000002293219986_ph765181182112"></a>×</span></p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.5 "><p id="zh-cn_topic_0000002293219986_p145773915920"><a name="zh-cn_topic_0000002293219986_p145773915920"></a><a name="zh-cn_topic_0000002293219986_p145773915920"></a><span id="zh-cn_topic_0000002293219986_ph178894120218"><a name="zh-cn_topic_0000002293219986_ph178894120218"></a><a name="zh-cn_topic_0000002293219986_ph178894120218"></a>×</span></p>
</td>
</tr>
<tr id="zh-cn_topic_0000002293219986_row09611137214"><td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.1 "><p id="zh-cn_topic_0000002293219986_p189671302115"><a name="zh-cn_topic_0000002293219986_p189671302115"></a><a name="zh-cn_topic_0000002293219986_p189671302115"></a>3322</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.2 "><p id="zh-cn_topic_0000002293219986_p1961613152111"><a name="zh-cn_topic_0000002293219986_p1961613152111"></a><a name="zh-cn_topic_0000002293219986_p1961613152111"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.3 "><p id="zh-cn_topic_0000002293219986_p396201315213"><a name="zh-cn_topic_0000002293219986_p396201315213"></a><a name="zh-cn_topic_0000002293219986_p396201315213"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.4 "><p id="zh-cn_topic_0000002293219986_p996101332113"><a name="zh-cn_topic_0000002293219986_p996101332113"></a><a name="zh-cn_topic_0000002293219986_p996101332113"></a>×</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.5 "><p id="zh-cn_topic_0000002293219986_p18971013102116"><a name="zh-cn_topic_0000002293219986_p18971013102116"></a><a name="zh-cn_topic_0000002293219986_p18971013102116"></a>×</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002293219986_row136637202484"><td class="cellrowborder" rowspan="6" align="center" valign="top" width="16.13%" headers="mcps1.1.7.1.1 "><p id="zh-cn_topic_0000002293219986_p76631120184812"><a name="zh-cn_topic_0000002293219986_p76631120184812"></a><a name="zh-cn_topic_0000002293219986_p76631120184812"></a>广域物联</p>
</td>
<td class="cellrowborder" align="center" valign="top" width="16.79%" headers="mcps1.1.7.1.2 "><p id="zh-cn_topic_0000002293219986_p15663620104818"><a name="zh-cn_topic_0000002293219986_p15663620104818"></a><a name="zh-cn_topic_0000002293219986_p15663620104818"></a>NB17</p>
</td>
<td class="cellrowborder" align="center" valign="top" width="14.82%" headers="mcps1.1.7.1.3 "><p id="zh-cn_topic_0000002293219986_p146641920164814"><a name="zh-cn_topic_0000002293219986_p146641920164814"></a><a name="zh-cn_topic_0000002293219986_p146641920164814"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" width="17.560000000000002%" headers="mcps1.1.7.1.4 "><p id="zh-cn_topic_0000002293219986_p966420206489"><a name="zh-cn_topic_0000002293219986_p966420206489"></a><a name="zh-cn_topic_0000002293219986_p966420206489"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" width="18.33%" headers="mcps1.1.7.1.5 "><p id="zh-cn_topic_0000002293219986_p06641420124814"><a name="zh-cn_topic_0000002293219986_p06641420124814"></a><a name="zh-cn_topic_0000002293219986_p06641420124814"></a>×</p>
</td>
<td class="cellrowborder" align="center" valign="top" width="16.37%" headers="mcps1.1.7.1.6 "><p id="zh-cn_topic_0000002293219986_p1162912326519"><a name="zh-cn_topic_0000002293219986_p1162912326519"></a><a name="zh-cn_topic_0000002293219986_p1162912326519"></a>×</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002293219986_row1266442019481"><td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.1 "><p id="zh-cn_topic_0000002293219986_p2664620144816"><a name="zh-cn_topic_0000002293219986_p2664620144816"></a><a name="zh-cn_topic_0000002293219986_p2664620144816"></a>NB17E</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.2 "><p id="zh-cn_topic_0000002293219986_p16664122013486"><a name="zh-cn_topic_0000002293219986_p16664122013486"></a><a name="zh-cn_topic_0000002293219986_p16664122013486"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.3 "><p id="zh-cn_topic_0000002293219986_p19664182084811"><a name="zh-cn_topic_0000002293219986_p19664182084811"></a><a name="zh-cn_topic_0000002293219986_p19664182084811"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.4 "><p id="zh-cn_topic_0000002293219986_p16640206489"><a name="zh-cn_topic_0000002293219986_p16640206489"></a><a name="zh-cn_topic_0000002293219986_p16640206489"></a>×</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.5 "><p id="zh-cn_topic_0000002293219986_p462913215518"><a name="zh-cn_topic_0000002293219986_p462913215518"></a><a name="zh-cn_topic_0000002293219986_p462913215518"></a>×</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002293219986_row116641220134820"><td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.1 "><p id="zh-cn_topic_0000002293219986_p16664120184816"><a name="zh-cn_topic_0000002293219986_p16664120184816"></a><a name="zh-cn_topic_0000002293219986_p16664120184816"></a>NB18</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.2 "><p id="zh-cn_topic_0000002293219986_p1966512205489"><a name="zh-cn_topic_0000002293219986_p1966512205489"></a><a name="zh-cn_topic_0000002293219986_p1966512205489"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.3 "><p id="zh-cn_topic_0000002293219986_p16665192034819"><a name="zh-cn_topic_0000002293219986_p16665192034819"></a><a name="zh-cn_topic_0000002293219986_p16665192034819"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.4 "><p id="zh-cn_topic_0000002293219986_p15665152017489"><a name="zh-cn_topic_0000002293219986_p15665152017489"></a><a name="zh-cn_topic_0000002293219986_p15665152017489"></a>×</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.5 "><p id="zh-cn_topic_0000002293219986_p156291932115113"><a name="zh-cn_topic_0000002293219986_p156291932115113"></a><a name="zh-cn_topic_0000002293219986_p156291932115113"></a>×</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002293219986_row5612131955914"><td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.1 "><p id="zh-cn_topic_0000002293219986_p15612419145910"><a name="zh-cn_topic_0000002293219986_p15612419145910"></a><a name="zh-cn_topic_0000002293219986_p15612419145910"></a><span id="zh-cn_topic_0000002293219986_ph7129922175918"><a name="zh-cn_topic_0000002293219986_ph7129922175918"></a><a name="zh-cn_topic_0000002293219986_ph7129922175918"></a>Hi2113</span></p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.2 "><p id="zh-cn_topic_0000002293219986_p186122197597"><a name="zh-cn_topic_0000002293219986_p186122197597"></a><a name="zh-cn_topic_0000002293219986_p186122197597"></a><span id="zh-cn_topic_0000002293219986_ph17935612182111"><a name="zh-cn_topic_0000002293219986_ph17935612182111"></a><a name="zh-cn_topic_0000002293219986_ph17935612182111"></a>√</span></p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.3 "><p id="zh-cn_topic_0000002293219986_p156124196593"><a name="zh-cn_topic_0000002293219986_p156124196593"></a><a name="zh-cn_topic_0000002293219986_p156124196593"></a><span id="zh-cn_topic_0000002293219986_ph1744521322113"><a name="zh-cn_topic_0000002293219986_ph1744521322113"></a><a name="zh-cn_topic_0000002293219986_ph1744521322113"></a>√</span></p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.4 "><p id="zh-cn_topic_0000002293219986_p46121219125913"><a name="zh-cn_topic_0000002293219986_p46121219125913"></a><a name="zh-cn_topic_0000002293219986_p46121219125913"></a><span id="zh-cn_topic_0000002293219986_ph10235676211"><a name="zh-cn_topic_0000002293219986_ph10235676211"></a><a name="zh-cn_topic_0000002293219986_ph10235676211"></a>×</span></p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.5 "><p id="zh-cn_topic_0000002293219986_p1861217190592"><a name="zh-cn_topic_0000002293219986_p1861217190592"></a><a name="zh-cn_topic_0000002293219986_p1861217190592"></a><span id="zh-cn_topic_0000002293219986_ph18737157162114"><a name="zh-cn_topic_0000002293219986_ph18737157162114"></a><a name="zh-cn_topic_0000002293219986_ph18737157162114"></a>×</span></p>
</td>
</tr>
<tr id="zh-cn_topic_0000002293219986_row254113313534"><td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.1 "><p id="zh-cn_topic_0000002293219986_p20541183115315"><a name="zh-cn_topic_0000002293219986_p20541183115315"></a><a name="zh-cn_topic_0000002293219986_p20541183115315"></a>Hi2131</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.2 "><p id="zh-cn_topic_0000002293219986_p1554112385319"><a name="zh-cn_topic_0000002293219986_p1554112385319"></a><a name="zh-cn_topic_0000002293219986_p1554112385319"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.3 "><p id="zh-cn_topic_0000002293219986_p145418355316"><a name="zh-cn_topic_0000002293219986_p145418355316"></a><a name="zh-cn_topic_0000002293219986_p145418355316"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.4 "><p id="zh-cn_topic_0000002293219986_p1254118325310"><a name="zh-cn_topic_0000002293219986_p1254118325310"></a><a name="zh-cn_topic_0000002293219986_p1254118325310"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.5 "><p id="zh-cn_topic_0000002293219986_p10541173165316"><a name="zh-cn_topic_0000002293219986_p10541173165316"></a><a name="zh-cn_topic_0000002293219986_p10541173165316"></a>√</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002293219986_row3715149145317"><td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.1 "><p id="zh-cn_topic_0000002293219986_p16716129165311"><a name="zh-cn_topic_0000002293219986_p16716129165311"></a><a name="zh-cn_topic_0000002293219986_p16716129165311"></a>Hi2131C</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.2 "><p id="zh-cn_topic_0000002293219986_p15716593532"><a name="zh-cn_topic_0000002293219986_p15716593532"></a><a name="zh-cn_topic_0000002293219986_p15716593532"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.3 "><p id="zh-cn_topic_0000002293219986_p1871610914538"><a name="zh-cn_topic_0000002293219986_p1871610914538"></a><a name="zh-cn_topic_0000002293219986_p1871610914538"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.4 "><p id="zh-cn_topic_0000002293219986_p5716119145311"><a name="zh-cn_topic_0000002293219986_p5716119145311"></a><a name="zh-cn_topic_0000002293219986_p5716119145311"></a>√</p>
</td>
<td class="cellrowborder" align="center" valign="top" headers="mcps1.1.7.1.5 "><p id="zh-cn_topic_0000002293219986_p971615925314"><a name="zh-cn_topic_0000002293219986_p971615925314"></a><a name="zh-cn_topic_0000002293219986_p971615925314"></a>√</p>
</td>
</tr>
</tbody>
</table>

>![](public_sys-resources/icon-note.gif) **说明：** 
>芯片系列中，“短距物联”、“手机穿戴”、“广域物联”统一属于FBB系列，文档中FBB系列芯片指代这三个芯片系列。

# 开发环境搭建<a name="ZH-CN_TOPIC_0000002412436853"></a>







## 概述<a name="ZH-CN_TOPIC_0000002378717588"></a>

当前版本仅支持Windows10和Windows11系统，本章节主要介绍Windows10和Windows11系统上的开发环境搭建。

## 安装要求<a name="ZH-CN_TOPIC_0000002412317005"></a>

-   操作系统要求：支持64位Windows10或64位Windows11。
-   VS Code版本要求：1.80.2-1.103.2。
-   硬盘要求：至少有900MB的硬盘空间来安装HiSpark Studio for VS Code插件。
-   内存要求：HiSpark Studio for VS Code插件最低要求为1GB RAM，建议至少有4GB RAM来安装运行HiSpark Studio for VS Code插件。
-   CPU：HiSpark Studio for VS Code插件最低要求为1.6GHz或者更高的处理器。
-   C盘空间要求：建议至少有1GB的C盘剩余空间。

## 安装HiSpark Studio for VS Code插件<a name="ZH-CN_TOPIC_0000002378877444"></a>

>![](public_sys-resources/icon-note.gif) **说明：** 
>若之前已经安装过DevEco相关的插件，请手动禁用或者卸载所有与DevEco相关的插件，否则会与HiSpark Studio for VS Code插件功能冲突。

1.  打开VS Code插件市场在搜索框中搜索HiSpark Studio。

    **图 1**  VS Code插件市场搜索框<a name="zh-cn_topic_0000002293219990_fig155444514303"></a>  
    ![](figures/VS-Code插件市场搜索框.png "VS-Code插件市场搜索框")

2.  搜索结果中选择HiSpark Studio for VS Code，点击安装即可。

## 工具链toolchain配置<a name="ZH-CN_TOPIC_0000002412436857"></a>

HiSpark Studio for VS Code插件在对工程进行编译等操作需要依赖工具链、python以及pip.pyz依赖的环境。可以使用插件中的Download Toolchain功能进行工具链等的自动下载和安装。

**图 1**  Download Toolchain功能<a name="zh-cn_topic_0000002337256433_fig4608724245"></a>  
![](figures/Download-Toolchain功能.png "Download-Toolchain功能")

点击Download Toolchain功能后，会依次下载python3.11.4、pip.pyz、pip.pyz的依赖（wheel、setuptools、cmake、kconfiglib、pycparser、pillow、numpy、opencv\_python、windows\_curses以及tkinter-embed）以及编译所需的tools工具。下载过程VS Code右下角通知栏会有对应的工具下载提示以及进度展示。compiler由于文件比较大，下载时间较长，请耐心等待。

**图 2**  Toolchain下载进度展示（部分）<a name="zh-cn_topic_0000002337256433_fig13993195610574"></a>  
![](figures/Toolchain下载进度展示（部分）.png "Toolchain下载进度展示（部分）")

下载结束后，具体的下载内容位于用户目录下的“..\\.vscode\\extensions\\hispark.hisparkstudio-X.X.X\\downloads”目录下。

**图 3**  Toolchain下载目录<a name="zh-cn_topic_0000002337256433_fig1964666125817"></a>  
![](figures/Toolchain下载目录.png "Toolchain下载目录")

python3.11.4安装好后，会对pip.pyz的依赖进行安装，以及编译工具链的解压，右下角会有对应的通知弹框提示，全部安装完成会提示环境准备完成。

**图 4**  python3.11.4安装完成后的pip.pyz依赖及工具链的解压提示<a name="zh-cn_topic_0000002337256433_fig7778922205811"></a>  
![](figures/python3-11-4安装完成后的pip-pyz依赖及工具链的解压提示.png "python3-11-4安装完成后的pip-pyz依赖及工具链的解压提示")

在环境准备中，会将下载在用户目录下“....\\.vscode\\extensions\\hispark.hisparkstudio-X.X.X\\downloads\\HiSparkStudioToolchain.zip”的这个zip压缩包解压到用户目录下的“..\\.vscode\\extensions\\hispark.hisparkstudio-X.X.X\\tools”中。

**图 5**  编译工具链解压结果<a name="zh-cn_topic_0000002337256433_fig136041725175413"></a>  
![](figures/编译工具链解压结果.png "编译工具链解压结果")

python环境可以通过在用户目录下的“..\\.vscode\\extensions\\hispark.hisparkstudio-X.X.X\\tools\\python”路径下打开cmd（命令提示符）窗口中进行验证。执行“.\\python.exe --version”输出结果为‘Python 3.11.4’，以及执行“.\\python.exe C:\\用户\\.vscode\\extensions\\hispark.hisparkstudio-X.X.X\\downloads\\pip.pyz list”命令输出结果显示有wheel、setuptools、cmake、kconfiglib、pycparser、pillow、numpy、opencv\_python、windows\_curses以及tkinter-embed这些pip.pyz的依赖及其对应版本，则验证python环境已没有问题。

**图 6**  python环境验证<a name="zh-cn_topic_0000002337256433_fig1757924515812"></a>  
![](figures/python环境验证.png "python环境验证")

>![](public_sys-resources/icon-note.gif) **说明：** 
>如果由于环境或其他原因导致自动配置toolchain环境失败，用户也可以手动进行配置：
>-   python手动下载链接：[https://mirrors.huaweicloud.com/python/3.11.4/python-3.11.4-embed-amd64.zip](https://mirrors.huaweicloud.com/python/3.11.4/python-3.11.4-embed-amd64.zip)，将该文件解压到“..\\.vscode\\extensions\\hispark.hisparkstudio-X.X.X\\tools”目录下（tools目录需手动创建），并将解压后文件命名为python。
>    ![](figures/python安装3.png)
>-   下载“pip.pyz”文件至“..\\.vscode\\extensions\\hispark.hisparkstudio-X.X.X\\tools\\python”目录下，并将下载后的“pip.pyz”文件复制到“..\\.vscode\\extensions\\hispark.hisparkstudio-X.X.X\\downloads”目录下，如果没有downloads文件夹目录，则需要手动创建一个downloads文件夹。
>    pip.pyz：[https://bootstrap.pypa.io/pip/pip.pyz](https://bootstrap.pypa.io/pip/pip.pyz)
>-   修改“..\\.vscode\\extensions\\hispark.hisparkstudio-X.X.X\\tools\\python\\python311.\_pth”文件，删除“\#import site”前的\#号。
>    ![](figures/python安装4.png)
>-   pip.pyz依赖准备需要下载对应依赖的whl文件至“..\\.vscode\\extensions\\hispark.hisparkstudio-X.X.X\\tools\\python”目录下，并在该目录下打开cmd执行“.\\python.exe pip.pyz install xx.whl”命令，如下载cmake的whl文件为“cmake-3.20.5-py2.py3-none-win\_amd64.whl”，则在下载文件目录下打开cmd执行“.\\python.exe pip.pyz install cmake-3.20.5-py2.py3-none-win\_amd64.whl”即可。各依赖的whl文件下载链接如下：
>    wheel：
>    [https://mirrors.cloud.tencent.com/pypi/packages/0b/2c/87f3254fd8ffd29e4c02732eee68a83a1d3c346ae39bc6822dcbcb697f2b/wheel-0.45.1-py3-none-any.whl](https://mirrors.cloud.tencent.com/pypi/packages/0b/2c/87f3254fd8ffd29e4c02732eee68a83a1d3c346ae39bc6822dcbcb697f2b/wheel-0.45.1-py3-none-any.whl)
>    setuptools：
>    [https://mirrors.cloud.tencent.com/pypi/packages/a3/dc/17031897dae0efacfea57dfd3a82fdd2a2aeb58e0ff71b77b87e44edc772/setuptools-80.9.0-py3-none-any.whl](https://mirrors.cloud.tencent.com/pypi/packages/a3/dc/17031897dae0efacfea57dfd3a82fdd2a2aeb58e0ff71b77b87e44edc772/setuptools-80.9.0-py3-none-any.whl)
>    cmake：
>    [https://mirrors.cloud.tencent.com/pypi/packages/65/7f/80cf681cd376834b442af8af48e6f17b4197d20b7255aa2f76d8d93a9e44/cmake-3.20.5-py2.py3-none-win\_amd64.whl](https://mirrors.cloud.tencent.com/pypi/packages/65/7f/80cf681cd376834b442af8af48e6f17b4197d20b7255aa2f76d8d93a9e44/cmake-3.20.5-py2.py3-none-win_amd64.whl)
>    kconfiglib：
>    [https://mirrors.cloud.tencent.com/pypi/packages/8a/f1/d98a89231e779b079b977590efcc31249d959c8f1d4b5858cad69695ff9c/kconfiglib-14.1.0-py2.py3-none-any.whl](https://mirrors.cloud.tencent.com/pypi/packages/8a/f1/d98a89231e779b079b977590efcc31249d959c8f1d4b5858cad69695ff9c/kconfiglib-14.1.0-py2.py3-none-any.whl)
>    pycparser：
>    [https://mirrors.cloud.tencent.com/pypi/packages/62/d5/5f610ebe421e85889f2e55e33b7f9a6795bd982198517d912eb1c76e1a53/pycparser-2.21-py2.py3-none-any.whl](https://mirrors.cloud.tencent.com/pypi/packages/62/d5/5f610ebe421e85889f2e55e33b7f9a6795bd982198517d912eb1c76e1a53/pycparser-2.21-py2.py3-none-any.whl)
>    pillow：
>    [https://mirrors.cloud.tencent.com/pypi/packages/c1/d0/5866318eec2b801cdb8c82abf190c8343d8a1cd8bf5a0c17444a6f268291/pillow-10.4.0-cp311-cp311-win\_amd64.whl](https://mirrors.cloud.tencent.com/pypi/packages/c1/d0/5866318eec2b801cdb8c82abf190c8343d8a1cd8bf5a0c17444a6f268291/pillow-10.4.0-cp311-cp311-win_amd64.whl)
>    numpy：
>    [https://mirrors.cloud.tencent.com/pypi/packages/9b/0f/022ca4783b6e6239a53b988a4d315d67f9ae7126227fb2255054a558bd72/numpy-2.0.0-cp311-cp311-win\_amd64.whl](https://mirrors.cloud.tencent.com/pypi/packages/9b/0f/022ca4783b6e6239a53b988a4d315d67f9ae7126227fb2255054a558bd72/numpy-2.0.0-cp311-cp311-win_amd64.whl)
>    opencv\_python：
>    [https://mirrors.cloud.tencent.com/pypi/packages/fa/80/eb88edc2e2b11cd2dd2e56f1c80b5784d11d6e6b7f04a1145df64df40065/opencv\_python-4.12.0.88-cp37-abi3-win\_amd64.whl](https://mirrors.cloud.tencent.com/pypi/packages/fa/80/eb88edc2e2b11cd2dd2e56f1c80b5784d11d6e6b7f04a1145df64df40065/opencv_python-4.12.0.88-cp37-abi3-win_amd64.whl)
>    windows\_curses：
>    [https://mirrors.cloud.tencent.com/pypi/packages/18/1b/e06eb41dad1c74f0d3124218084f258f73a5e76c67112da0ba174162670f/windows\_curses-2.3.3-cp311-cp311-win\_amd64.whl](https://mirrors.cloud.tencent.com/pypi/packages/18/1b/e06eb41dad1c74f0d3124218084f258f73a5e76c67112da0ba174162670f/windows_curses-2.3.3-cp311-cp311-win_amd64.whl)
>-   下载tkinter压缩包至“..\\.vscode\\extensions\\hispark.hisparkstudio-X.X.X\\tools\\python”目录下，并在该目录下打开cmd执行“.\\python.exe pip.pyz install --target .\\ tkinter\_embed-3.11.0.tar.gz”命令
>    tkinter压缩包：
>    [https://mirrors.cloud.tencent.com/pypi/packages/a2/b5/01fa4f6b1b78b01c1602d8e6e28879dcbef2d399d934f28d3324c1114552/tkinter\_embed-3.11.0.tar.gz](https://mirrors.cloud.tencent.com/pypi/packages/a2/b5/01fa4f6b1b78b01c1602d8e6e28879dcbef2d399d934f28d3324c1114552/tkinter_embed-3.11.0.tar.gz)
>-   添加“toolChain.json”至“..\\.vscode\\extensions\\hispark.hisparkstudio-X.X.X\\tools”目录下，并添加python路径内容至“toolChain.json”中。
>    ```
>    {
>        "pythonDir": "..\\.vscode\\extensions\\hispark.hisparkstudio-X.X.X\\tools\\python"
>    }
>    ```
>    ![](figures/python安装5.png)
>-   工具链可以手动通过[https://hispark-obs.obs.cn-east-3.myhuaweicloud.com/HiSparkStudioToolchain.zip](https://hispark-obs.obs.cn-east-3.myhuaweicloud.com/HiSparkStudioToolchain.zip)链接下载，然后解压至“..\\.vscode\\extensions\\hispark.hisparkstudio-X.X.X\\tools”目录下。
>-   工具链的环境和python环境的验证可以参考[图5](#zh-cn_topic_0000002337256433_fig136041725175413)和[图6](#zh-cn_topic_0000002337256433_fig1757924515812)。

## SDK下载<a name="ZH-CN_TOPIC_0000002378717596"></a>

HiSpark Studio for VS Code插件中创建工程需要依赖SDK软件包，插件当前提供WS63和BS2X系列的SDK下载。

**图 1**  Download SDK from HiSpark功能<a name="zh-cn_topic_0000002303416852_fig16959181457"></a>  
![](figures/Download-SDK-from-HiSpark功能.png "Download-SDK-from-HiSpark功能")

点击“Download SDK from HiSpark”后，弹出SDK下载列表。

**图 2**  SDK下载列表<a name="zh-cn_topic_0000002303416852_fig862702418516"></a>  
![](figures/SDK下载列表.png "SDK下载列表")

选中任意SDK，会弹出“选择SDK保存位置”选项。

**图 3**  SDK保存位置选择<a name="zh-cn_topic_0000002303416852_fig109016331355"></a>  
![](figures/SDK保存位置选择.png "SDK保存位置选择")

选中保存文件夹后，右下角弹窗提示，当前正在下载SDK，如果等待时间过长，可能由于环境原因或者当前没有下载gitee的权限，需要用户手动下载Git并添加到环境变量中，关闭VS Code窗口再打开以保证环境变量添加成功，再进行下载操作。

Git下载链接：[https://github.com/git-for-windows/git/releases/download/v2.48.1.windows.1/Git-2.48.1-64-bit.exe](https://github.com/git-for-windows/git/releases/download/v2.48.1.windows.1/Git-2.48.1-64-bit.exe)

**图 4**  下载SDK提示框<a name="zh-cn_topic_0000002303416852_fig1437317573111"></a>  
![](figures/下载SDK提示框.png "下载SDK提示框")

SDK下载完成后，用户可根据SDK来进行工程创建。

>![](public_sys-resources/icon-notice.gif) **须知：** 
>-   为避免SDK下载后与其他文件夹相互影响，建议选择SDK保存位置时选择一个空文件夹。
>-   WS63 SDK在线下载是从通过git clone  [https://gitee.com/HiSpark/fbb\_ws63.git](https://gitee.com/HiSpark/fbb_ws63.git)下载，如果没有下载gitee代码的权限，会导致下载时间过长最终失败。
>-   BS2X SDK在线下载是从通过git clone  [https://gitee.com/HiSpark/fbb\_bs2x.git](https://gitee.com/HiSpark/fbb_bs2x.git)下载，如果没有下载gitee代码的权限，会导致下载时间过长最终失败。

## bash环境准备<a name="ZH-CN_TOPIC_0000002412317009"></a>

该小节仅针对于需要依赖bash环境才可以编译的Hi2131、Hi2131C、3322工程。

如果需要编译Hi2131、Hi2131C、3322的工程，用户需手动下载Git并将bash路径添加到环境变量中。

下载链接：[https://github.com/git-for-windows/git/releases/download/v2.48.1.windows.1/Git-2.48.1-64-bit.exe](https://github.com/git-for-windows/git/releases/download/v2.48.1.windows.1/Git-2.48.1-64-bit.exe)

如果Windows系统System32下默认有“bash.exe”，需要删除其系统下的“bash.exe”，使用安装的git下内置的“bash.exe”。

完成后，重启VS Code使新环境变量生效，即可正常编译工程。

**图 1**  删除Windows系统库的bash<a name="zh-cn_topic_0000002304004976_fig9843191112367"></a>  
![](figures/删除Windows系统库的bash.png "删除Windows系统库的bash")

>![](public_sys-resources/icon-note.gif) **说明：** 
>若删除Windows系统库下的bash时提示没权限，可以在需要删除的bash.exe上右键点击，选择“属性”，在弹出的窗口中依次点击“安全”标签页→“高级”→点击“所有者”标签页下的“更改”按钮。选择一个新的所有者（例如当前用户），点击“应用”和“确定”。返回“安全”标签页，点击“编辑”。为当前添加的用户或组分配适当的权限（如完全控制、读取等）。点“应用”和“确定”后即可删掉选择的bash.exe文件。

**图 2**  配置bash.exe的删除权限<a name="zh-cn_topic_0000002304004976_fig31821532142019"></a>  
![](figures/配置bash-exe的删除权限.png "配置bash-exe的删除权限")

![](figures/zh-cn_image_0000002478125622.png)

**图 3**  Git下的bash路径<a name="zh-cn_topic_0000002304004976_fig664202311363"></a>  
![](figures/Git下的bash路径.png "Git下的bash路径")

**图 4**  添加到环境变量中<a name="zh-cn_topic_0000002304004976_fig1687216294365"></a>  
![](figures/添加到环境变量中.png "添加到环境变量中")

**图 5**  保证Git下的bash被调用<a name="zh-cn_topic_0000002304004976_fig14591538123614"></a>  
![](figures/保证Git下的bash被调用.png "保证Git下的bash被调用")

# 工程管理<a name="ZH-CN_TOPIC_0000002378877448"></a>



## 新建工程<a name="ZH-CN_TOPIC_0000002412436861"></a>

1.  打开HiSpark Studio for VS Code插件，进入欢迎页面，单击“新建工程”，进入新建工程页面。

    **图 1**  HiSpark Studio for VS Code插件欢迎页面<a name="zh-cn_topic_0000002327179609_fig6514428113718"></a>  
    ![](figures/HiSpark-Studio-for-VS-Code插件欢迎页面.png "HiSpark-Studio-for-VS-Code插件欢迎页面")

2.  在[图2](#zh-cn_topic_0000002327179609_fig2784311111318)界面配置工程参数，单击“完成”。

    **图 2**  新建工程窗口<a name="zh-cn_topic_0000002327179609_fig2784311111318"></a>  
    ![](figures/新建工程窗口.png "新建工程窗口")

    -   芯片：选择工程使用的芯片名称。
    -   开发板：选择工程使用的开发板名称。当用户不需要自定义开发板时，默认芯片名作为开发板名。
    -   工程类型：选择创建的工程类型。普通工程和sample工程，sample工程当前只支持WS63芯片。
    -   工程名：输入工程名称。
    -   工程路径：选择用于存放工程文件的目录。
    -   软件包：选择工程使用的软件开发驱动包（SDK）文件夹根目录。

    当芯片选择WS63，且工程类型选择“sample工程后”，工程界面会新增“sample”路径和“sample选择”选项，如[图3](#zh-cn_topic_0000002327179609_fig16606922141519)所示。

    **图 3**  sample工程创建页面<a name="zh-cn_topic_0000002327179609_fig16606922141519"></a>  
    ![](figures/sample工程创建页面.png "sample工程创建页面")

    sample路径可以从本地导入（路径目录下应该包含“build\_config.json文件”），或者直接选择一个空文件夹目录，单击下载的图标按钮，会自动将sample文件下载到选择的空文件夹目录中，然后单击sample选择，弹出如[图4](#zh-cn_topic_0000002327179609_fig111743454160)所示界面。

    **图 4**  sample选择页面<a name="zh-cn_topic_0000002327179609_fig111743454160"></a>  
    ![](figures/sample选择页面.png "sample选择页面")

    选择需要的sample后，关闭sample选择页面，选择的sample选项名会填充到新建工程页面中的“sample选择”中，如[图5](#zh-cn_topic_0000002327179609_fig9923152471712)所示。

    >![](public_sys-resources/icon-caution.gif) **注意：** 
    >sample在线下载是从通过git clone  [https://gitee.com/HiSpark/fbb\_ws63.git](https://gitee.com/HiSpark/fbb_ws63.git)下载，如果没有下载gitee代码的权限，会导致下载时间过长最终失败。

    **图 5**  sample选择完成后页面<a name="zh-cn_topic_0000002327179609_fig9923152471712"></a>  
    ![](figures/sample选择完成后页面.png "sample选择完成后页面")

    后续选择合适的工程名、工程路径和WS63的软件包，单击“完成”即可创建工程。

3.  查看工程创建结果。

    HiSpark Studio for VS Code插件会自动打开新创建的工程，并在欢迎界面工程列表中显示创建的工程，如[图6](#zh-cn_topic_0000002327179609_fig551738161718)所示。

    **图 6**  工程创建结果页面<a name="zh-cn_topic_0000002327179609_fig551738161718"></a>  
    ![](figures/工程创建结果页面.png "工程创建结果页面")

## 导入工程<a name="ZH-CN_TOPIC_0000002378717600"></a>

1.  打开HiSpark Studio for VS Code插件，进入到欢迎页面，单击“导入工程”，进入导入工程页面。

    **图 1**  HiSpark Studio for VS Code插件导入工程页面<a name="zh-cn_topic_0000002293379666_fig19540125184016"></a>  
    ![](figures/HiSpark-Studio-for-VS-Code插件导入工程页面.png "HiSpark-Studio-for-VS-Code插件导入工程页面")

2.  选择导入的路径，即可查找该路径下所有的工程，勾选需要导入的工程，单击“完成”。

    **图 2**  导入工程配置页面<a name="zh-cn_topic_0000002293379666_fig3640203910157"></a>  
    ![](figures/导入工程配置页面.png "导入工程配置页面")

3.  导入工程完成后，会在工程区展示出工程的文件夹，并在欢迎界面的工程列表中展示已导入的工程。

    **图 3**  导入工程完成<a name="zh-cn_topic_0000002293379666_fig1617152231818"></a>  
    ![](figures/导入工程完成.png "导入工程完成")

# 工程配置<a name="ZH-CN_TOPIC_0000002412317013"></a>

工程配置主要用于配置工程的基本信息、编译、调试、烧录等工程配置项，单击“![](figures/config.png)”按钮可以打开工程配置界面，如[图1](#zh-cn_topic_0000002327179613_fig672755464817)所示。

**图 1**  单击工程配置按钮<a name="zh-cn_topic_0000002327179613_fig672755464817"></a>  
![](figures/单击工程配置按钮.png "单击工程配置按钮")





## 基本信息配置<a name="ZH-CN_TOPIC_0000002378877452"></a>

单击工程配置界面左侧“基本信息”页签进入基本信息配置界面，如[图1](#zh-cn_topic_0000002293379670_fig18947542448)所示。该界面包含工程芯片系列、开发板型号、软件包路径，可以修改工程所对应的软件包路径。

**图 1**  基本信息配置界面<a name="zh-cn_topic_0000002293379670_fig18947542448"></a>  
![](figures/基本信息配置界面.png "基本信息配置界面")

-   基本系列配置界面里，Target选择框以及关联的Target管理功能仅在部分FBB芯片中可生效：

    BS20、BS20C、BS21、BS21E、BS21A、BS22、BS26既支持Target选择也支持Target管理，其余含有Target的工程仅支持Target选择。

-   以下指南仅针对上述涉及到Target功能的芯片：
    1.  如[图2](#zh-cn_topic_0000002293379670_fig1942333014511)所示，通过选取不同的Target，可配合编译生成不同的编译产物。

        **图 2**  Target选择界面<a name="zh-cn_topic_0000002293379670_fig1942333014511"></a>  
        ![](figures/Target选择界面.png "Target选择界面")

    2.  单击Target选项框下方的 "Target 管理"，可进入Target管理界面，如[图3](#zh-cn_topic_0000002293379670_fig1648301431310)所示。

        **图 3**  Target管理界面<a name="zh-cn_topic_0000002293379670_fig1648301431310"></a>  
        ![](figures/Target管理界面.png "Target管理界面")

        ① 不支持编辑和删除的SDK默认Target。

        ② 支持编译和删除的Target。

    3.  单击Target管理界面的“添加”，可进入添加Target界面，如[图4](#zh-cn_topic_0000002293379670_fig13409104010130)所示。

        **图 4**  添加Target界面<a name="zh-cn_topic_0000002293379670_fig13409104010130"></a>  
        ![](figures/添加Target界面.png "添加Target界面")

    4.  当用户添加或者删除时，切换回工程配置界面的Target选项中，也会同步生效。以添加Target为例，当新增一个demo的Target后，如[图5](#zh-cn_topic_0000002293379670_fig899411161410)，工程配置界面Target下拉框也会同步更新DEMO选项，如[图6](#zh-cn_topic_0000002293379670_fig38170493913)。

        **图 5**  添加名称为demo的Target<a name="zh-cn_topic_0000002293379670_fig899411161410"></a>  
        ![](figures/添加名称为demo的Target.png "添加名称为demo的Target")

        **图 6**  Target下拉框同步更新DEMO<a name="zh-cn_topic_0000002293379670_fig38170493913"></a>  
        ![](figures/Target下拉框同步更新DEMO.png "Target下拉框同步更新DEMO")

        如[图7](#zh-cn_topic_0000002293379670_fig8566412205415)所示，配置之后的Target参数宏信息会生成在如图target\_config目录下的“.config”文件中。

        **图 7**  Target配置文件<a name="zh-cn_topic_0000002293379670_fig8566412205415"></a>  
        ![](figures/Target配置文件.png "Target配置文件")

        Target支持选择和自定义，单击Target选项框可以从Target列表中选择需要的Target，也可以自定义Target和编译的指令。

        **图 8**  Target自定义<a name="zh-cn_topic_0000002293379670_fig94764713276"></a>  
        ![](figures/Target自定义.png "Target自定义")

        >![](public_sys-resources/icon-notice.gif) **须知：** 
        >-   Target支持选择和自定义，每次自定义时均需要手动输入完整的自定义Target及命令，不支持在选择或自定义的Target基础上二次编辑，也就是每次自定义Target时均从第一个字符开始输入编辑；
        >-   Target自定义时，如果输入的Target为列表中已有的Target，在此基础上新增其他编译命令，如果编译能正常通过，调试和烧录均能正常执行
        >-   Target自定义时，如果输入的Target为列表中没有的Target，在此基础上进行编译，如果编译能正常通过，由于没有绑定elf和map文件，调试和栈分析镜像分析功能会受到影响，并且，自定义列表中没有的Target后重新打开工程配置，会提示launch.json缺失影响调试功能，此为正常现象。

## 编译器配置<a name="ZH-CN_TOPIC_0000002412436865"></a>

单击工程配置界面左侧“编译器”页签进入编译器配置界面，如[图1](#zh-cn_topic_0000002327219389_fig177671416389)、[图2](#zh-cn_topic_0000002327219389_fig892832183814)、[图3](#zh-cn_topic_0000002327219389_fig1020319297387)、[图4](#zh-cn_topic_0000002327219389_fig1514082619416)所示，该界面可配置工程使用的编译工具链、编译类型、编译选项、编译指令、编译结果文件路径以及静态库等配置。

**图 1**  编译器配置界面-1<a name="zh-cn_topic_0000002327219389_fig177671416389"></a>  

![](figures/zh-cn_image_0000002373319477.png)

**图 2**  编译器配置界面-2<a name="zh-cn_topic_0000002327219389_fig892832183814"></a>  

![](figures/zh-cn_image_0000002339286536.png)

**图 3**  编译器配置界面-3<a name="zh-cn_topic_0000002327219389_fig1020319297387"></a>  

![](figures/zh-cn_image_0000002339284964.png)

**图 4**  编译器配置界面-4<a name="zh-cn_topic_0000002327219389_fig1514082619416"></a>  

![](figures/zh-cn_image_0000002339129804.png)

![](figures/编译器配置界面-4.png "编译器配置界面-4")

-   编译链：编译所使用的工具链。
-   指定链接器使用工具链中的C库：指定链接器使用工具链中的C库。
-   指定编译器使用工具链中的C库：指定编译器使用工具链中的C库。
-   编译类型：分debug和release。
    -   debug会生成调试符号表打包到镜像中，方便调试。
    -   release不会生成调试符号表，减少镜像大小，用于生产。

-   浮点常数类型：分float和double。
    -   float可以提高程序的运行速度，但是可能会导致精度损失，因为单精度浮点数只能表示有限的数字范围和精度。
    -   double可以提升浮点运算的计算精度，但是会占用更大的内存空间，也会增加耗时。

-   生成CRC：用于控制编译时是否会在“target.bin”和“target.hex”末尾插入CRC算法计算的结果。
-   生成校验和（使用CRC32算法）：在可执行文件中不插入CRC算法计算结果，但是将结果保存在同级目录下的“checksum\_list.txt”中，并在编译过程中打印出来。
-   生成符号表文件（target.symbol）：可在编译后通过“out/bin”目录下的“target.elf”文件生成“target.symbol”符号表文件，文件位于“out/bin”目录下。
-   生成target.hex：用于控制编译时是否会生成“target.hex”。
-   为Live Watch解析elf文件：用于控制编译时是否会解析elf中的全局变量，解析的结果会在调试功能的Live Watch中使用。
-   为工程分析生成analyzerJson：用于控制编译时是否会静态的分析工程，分析的结果会用于栈分析和镜像分析。
-   镜像填充。
    -   no：无填充。
    -   0：多余空间填0。
    -   1：多余空间填1。

-   编译优化等级：编译优化选项。
    -   O0：不做优化，源码与二进制代码对应性最好，适合调试场景。
    -   Os：优化空间占用，适合Flash空间小的生产发布场景。
    -   O1\~3：优化运行性能，O1、O2、O3优化等级依次增强，适合需提升运行性能的生产发布场景。

-   开启栈保护功能（会增加内存、闪存的占用）。
-   告警当错误处理。
-   显示告警信息。
    -   对未使用的函数不告警：忽略声明但未使用的静态函数发出的警告。
    -   对未使用的标签不告警：忽略给声明但未使用的标签发出的警告。
    -   对未使用的参数不告警：忽略给声明但未使用的参数发出的警告。
    -   对未使用的变量不告警：忽略给声明但未使用的变量发出的警告。
    -   对函数缺少原型声明不告警：忽略在使用函数前没有声明而发出的警告。

-   是否生成静态库：若选中，选中的文件编译生成静态库文件；若不选中，则不会在编译时生成静态库文件。
    -   静态库名

        输入静态库的名字，如“demo”，编译之后会生成在“out\\libs”目录下生成“libdemo.a”。

    -   静态库源文件

        选择想要编译成静态库的文件或者文件夹。

    -   静态库依赖头文件

        选择编译静态库需要依赖的头文件，支持文件和文件夹。

-   外部静态库路径。

    配置不在本工程目录下面的静态库文件参与编译。

-   外部静态库依赖。

    配置不在本工程目录下面的静态库依赖头参与编译。

-   全局宏定义。

    配置在整个工程中都有效的宏定义。

-   编译前执行。

    自定义1～2条指令，被勾选的指令将在编译前执行。命令中可以使用内置变量：$P（当前工程路径）。

-   编译后执行。

    自定义1～2条指令，被勾选的指令将在编译后执行。命令中可以使用内置变量：$P（当前工程路径）。

    >![](public_sys-resources/icon-note.gif) **说明：** 
    >修改配置之后会自动保存并生效。文本输入框中的修改会在失焦时自动保存并生效。

## 烧录器配置<a name="ZH-CN_TOPIC_0000002378717604"></a>

单击工程配置界面左侧“程序加载”页签进入程序加载配置界面，如[图1](#zh-cn_topic_0000002327179617_fig1851473982716)所示，该界面支持配置烧录传输方式以及传输方式对应的参数。

**图 1**  程序加载配置界面<a name="zh-cn_topic_0000002327179617_fig1851473982716"></a>  
![](figures/程序加载配置界面.png "程序加载配置界面")

-   传输方式：选择数据传输方式。选择不同的传输方式会出现不同的参数配置项。
    -   serial：选择通过串口传输。如[图2](#zh-cn_topic_0000002327179617_fig58771855184310)所示。

        -   端口
        -   波特率

        **图 2**  选择serial配置界面<a name="zh-cn_topic_0000002327179617_fig58771855184310"></a>  
        
        ![](figures/zh-cn_image_0000002339310954.png)

    -   usb：选择通过USB设备完成烧写升级。如[图3](#zh-cn_topic_0000002327179617_fig10468263017)所示。（当前usb模式支持BS20、BS20C、BS21、BS21A、BS21E、BS22、BS25、BS26系列芯片。）
        -   usb设备列表

            **图 3**  选择usb配置界面<a name="zh-cn_topic_0000002327179617_fig10468263017"></a>  
            
            ![](figures/zh-cn_image_0000002373349237.png)

        -   如图所示，切换usb模式时，会修改默认Bin文件，且仅支持程序加载，不支持烧录配置。

            **图 4**  传输方式改为usb模式<a name="zh-cn_topic_0000002327179617_fig21511259311"></a>  
            ![](figures/传输方式改为usb模式.png "传输方式改为usb模式")

-   Bin文件：指定需要烧录的文件。
-   烧录后复位：烧录完成后，会进行单板软复位。
-   烧录后校验：烧录后，会将烧录文件进行回读对比，校验文件的完整性。

>![](public_sys-resources/icon-note.gif) **说明：** 
>-   修改配置之后会自动保存并生效。

## 调试器配置<a name="ZH-CN_TOPIC_0000002412317017"></a>

单击工程配置界面左侧“调试器”页签，在JlinkGDBServerCL路径里面选择Jlink的执行软件，如[图1](#zh-cn_topic_0000002340080528_fig205561635163111)所示。

**图 1**  工程配置界面中JlinkGDBServerCL路径选择<a name="zh-cn_topic_0000002340080528_fig205561635163111"></a>  
![](figures/工程配置界面中JlinkGDBServerCL路径选择.png "工程配置界面中JlinkGDBServerCL路径选择")

# 编译运行<a name="ZH-CN_TOPIC_0000002378877456"></a>





## 编译按钮介绍<a name="ZH-CN_TOPIC_0000002412436869"></a>

**图 1**  编译按钮<a name="zh-cn_topic_0000002293383670_fig7871826336"></a>  
![](figures/编译按钮.png "编译按钮")

[图1](#zh-cn_topic_0000002293383670_fig7871826336)按钮依次是：清除、编译、重编译和停止编译按钮。

-   ![](figures/zh-cn_image_0000002339324210.png)：单击触发工程清理，删除编译中间生成的文件。
-   ![](figures/zh-cn_image_0000002339323986.png)：单击触发工程编译。
-   ![](figures/zh-cn_image_0000002373241301.png)：单击触发先清理target再编译。
-   ![](figures/zh-cn_image_0000002373362865.png)：单击触发停止编译。

>![](public_sys-resources/icon-note.gif) **说明：** 
>-   重编译功能会先清除output目录下当前target的内容，如acore目录和fwpkg目录下的名为target的文件夹，如果存在该文件夹则会删除，如果没有，则不会清除任何文件或文件夹，清除完毕后会再执行编译功能。
>-   如果想删除output文件夹，执行“清除”功能即可。

## 编译结果<a name="ZH-CN_TOPIC_0000002378717608"></a>

单击“![](figures/zh-cn_image_0000002373367797.png)”按钮开始编译，编译成功后终端窗口输出如[图1](#zh-cn_topic_0000002293224006_fig9925105200)所示，且工程目录中生成output目录如[图2](#zh-cn_topic_0000002293224006_fig114873277206)所示。

**图 1**  编译成功<a name="zh-cn_topic_0000002293224006_fig9925105200"></a>  
![](figures/编译成功.png "编译成功")

**图 2**  编译生成output目录<a name="zh-cn_topic_0000002293224006_fig114873277206"></a>  

![](figures/zh-cn_image_0000002339329450.png)

单击![](figures/zh-cn_image_0000002339329878.png)按钮开始清除编程生成的文件，成功后终端窗口输出如[图3](#zh-cn_topic_0000002293224006_fig1710335292011)所示。工程清理会清除工程目录下的output文件夹。

**图 3**  清除工程编译成功<a name="zh-cn_topic_0000002293224006_fig1710335292011"></a>  

![](figures/zh-cn_image_0000002327183953.png)

## 编译生成静态库<a name="ZH-CN_TOPIC_0000002412317021"></a>

适用场景：希望将工程中的部分原文件打包生成静态库文件。

1.  进入工程配置页面，到“是否生成静态库”的配置项。

    **图 1**  静态库配置<a name="zh-cn_topic_0000002327223373_fig18878132542220"></a>  
    ![](figures/静态库配置.png "静态库配置")

    使能是否生成静态库。如果不想生成静态库，可以通过这个选项再次关闭。

2.  输入希望生成的静态库名，例如输入“demo”，最后生成静态库时会添加“lib”头和“.a”尾，生成“libdemo.a”。

    **图 2**  输入静态库名字<a name="zh-cn_topic_0000002327223373_fig484053232210"></a>  
    ![](figures/输入静态库名字.png "输入静态库名字")

3.  从当前工程文件中选择静态库的源文件所在的文件夹或文件，支持多选，工具会自动筛选出.c文件，选择完毕后单击完成。

    **图 3**  选择要生成静态库的源文件<a name="zh-cn_topic_0000002327223373_fig296914348228"></a>  
    ![](figures/选择要生成静态库的源文件.png "选择要生成静态库的源文件")

4.  从当前工程文件中选择编译静态依赖所需的头文件路径。支持选择文件夹或者文件， 支持多选，工具会自动筛选出.h文件，选择完毕后单击完成。

    **图 4**  选择要生成静态库的头文件路径<a name="zh-cn_topic_0000002327223373_fig875163710220"></a>  
    ![](figures/选择要生成静态库的头文件路径.png "选择要生成静态库的头文件路径")

5.  点击编译“![](figures/zh-cn_image_0000002439200448.png)”，编译成功之后在 “out\\libs”中生成静态库文件。

    **图 5**  静态库的生成路径<a name="zh-cn_topic_0000002327223373_fig2079334113225"></a>  
    ![](figures/静态库的生成路径.png "静态库的生成路径")

## 使用静态库参与编译<a name="ZH-CN_TOPIC_0000002378877460"></a>

**使用工程中的静态库文件<a name="zh-cn_topic_0000002327183621_section18863661645"></a>**

1.  将“out\\libs”路径下生成的自定义静态库对应的.a文件移至“thirdparty\\sysroot\\lib”路径下。

    >![](public_sys-resources/icon-note.gif) **说明：** 
    >不要在“out\\libs”目录下面放入.a ，否则会在clean的时候被清除。

2.  将静态库对应的.h文件移至“thirdparty\\sysroot\\include”路径下。
3.  在工程中包含对应的头文件，即可调用自定义静态库中的接口。

**使用工程之外的静态库文件<a name="zh-cn_topic_0000002327183621_section1866313180420"></a>**

1.  在外部静态库路径处选择所引用的外部静态库.a文件的路径，在外部静态库依赖处选择对应静态库所依赖头文件的目录。

    **图 1**  外部静态库配置项<a name="zh-cn_topic_0000002327183621_fig57631244152214"></a>  
    ![](figures/外部静态库配置项.png "外部静态库配置项")

2.  选择完毕后单击编译Rebuild，并在工程中包含所引用的静态库所依赖的头文件即可。

# 软件包烧录<a name="ZH-CN_TOPIC_0000002412436873"></a>

烧录功能只支持串口烧录。




## 连接烧录串口线<a name="ZH-CN_TOPIC_0000002378717612"></a>

软件镜像烧录，使用串口通信协议，需要将运行HiSpark Studio for VS Code插件的电脑和目标板用串口线连接，常见的串口线有标准的串口线和USB转串口线两种。如果使用USB转串口线，需提前安装USB转串口驱动。

**图 1**  烧录串口连接示意图<a name="zh-cn_topic_0000002327223389_fig8881486226"></a>  
![](figures/烧录串口连接示意图.png "烧录串口连接示意图")

## 配置工程的烧录选项<a name="ZH-CN_TOPIC_0000002412317029"></a>

1.  配置好硬件环境。

    请用串口线连接好电脑和待烧录开发板。

2.  <a name="zh-cn_topic_0000002327183641_li207851059104511"></a>确定所连接的串口号。

    打开电脑的设备管理器，查看并记录串口线对应的串口号。

    **图 1**  串口选择<a name="zh-cn_topic_0000002327183641_fig55913473219"></a>  
    ![](figures/串口选择.png "串口选择")

    >![](public_sys-resources/icon-notice.gif) **须知：** 
    >如果使用USB转串口方式烧录，请安装USB转串口的驱动程序。

3.  进入工程配置界面。

    打开要烧录的工程后，单击工程配置的“![](figures/config-0.png)”按钮，进入工程配置界面。

    **图 2**  工程配置入口<a name="zh-cn_topic_0000002327183641_fig337113913219"></a>  
    ![](figures/工程配置入口.png "工程配置入口")

4.  单击“程序加载”中的“传输方式”，默认选择“serial”串口传输，“Bin 文件”中，会默认选择烧录的Bin文件，按[步骤2](#zh-cn_topic_0000002327183641_li207851059104511)选择端口号，波特率默认115200。

    **图 3**  串口烧录配置<a name="zh-cn_topic_0000002327183641_fig99981772213"></a>  
    ![](figures/串口烧录配置.png "串口烧录配置")

    >![](public_sys-resources/icon-notice.gif) **须知：** 
    >FBB系列芯片选择“serial”烧写模式时，由于是USB转串口的方式，硬件设备的差异可能会对芯片支持的烧写波特率有限制，如果想支持更高的波特率，需要改板。其中，BRANDY系列芯片烧写波特率默认限制为不超过500000，BS2X系列芯片的烧写波特率默认限制为不超过2000000，3322的烧写波特率默认限制为不超过750000。

5.  单击工具栏中的烧录按钮  ![](figures/shaolu.png)，开始执行烧写。

    **图 4**  烧录按钮入口<a name="zh-cn_topic_0000002327183641_fig1518855418224"></a>  
    ![](figures/烧录按钮入口.png "烧录按钮入口")

6.  按提示复位设备，烧录成功后终端窗口输出如[图5](#zh-cn_topic_0000002327183641_fig9672125742319)所示。

    **图 5**  烧录成功<a name="zh-cn_topic_0000002327183641_fig9672125742319"></a>  
    ![](figures/烧录成功.png "烧录成功")

## 烧录配置<a name="ZH-CN_TOPIC_0000002378877464"></a>

本章节主要介绍支持选择性烧录bin文件的方法。使用此功能前如果编译成功则直接从本章节[1](#zh-cn_topic_0000002293383702_p913mcpsimp)开始，如果未编译，请参见“[编译结果](编译结果.md#ZH-CN_TOPIC_0000002378717608)”章节进行编译，然后再根据本章节步骤进行操作。

1.  <a name="zh-cn_topic_0000002293383702_p913mcpsimp"></a>单击工具栏中的“烧录配置”  ![](figures/sp.png)  按钮，进入烧录配置界面。

    **图 1**  烧录配置按钮及界面<a name="zh-cn_topic_0000002293383702_fig18205858181719"></a>  
    
    ![](figures/zh-cn_image_0000002340660566.png)

2.  FBB分区文件默认为打包好的.fwpkg文件，或者单击“浏览”按钮从本地文件中选择打包好的.fwpkg文件。选择完成后，烧录工具会自动的将.fwpkg文件中包含的bin内容列出。

    **图 2**  FBB烧录配置分区文件路径<a name="zh-cn_topic_0000002293383702_fig7273738121914"></a>  
    
    ![](figures/zh-cn_image_0000002374785221.png)

3.  勾选需要烧录的.bin文件。默认会勾选全部.bin文件，且不支持修改表格中包含loader.bin或ssb.bin的分区名属性所在行的编辑状态。而其它.bin文件可以根据烧写的需求勾选或者取消勾选。
4.  烧录之前需要配置传输方式及其他参数信息，具体操作请参见“[烧录器配置](烧录器配置.md#ZH-CN_TOPIC_0000002378717604)”章节。
5.  单击“烧录”按钮，根据提示重启开发板，即可开始烧录。

    **图 3**  烧录<a name="zh-cn_topic_0000002293383702_fig7508701238"></a>  
    
    ![](figures/zh-cn_image_0000002374672533.png)

6.  开始烧录后，在分区文件下方会显示出烧录进度条，方便查看烧录进度。烧录开始后会在终端打印相关指令信息，最后烧录成功后会在界面显示“successfully”字样。

    **图 4**  烧录进度<a name="zh-cn_topic_0000002293383702_fig19626111222410"></a>  
    
    ![](figures/zh-cn_image_0000002374674917.png)

    **图 5**  烧写开始打印<a name="zh-cn_topic_0000002293383702_fig377133292415"></a>  
    
    ![](figures/zh-cn_image_0000002374810285.png)

    **图 6**  烧写开始打印<a name="zh-cn_topic_0000002293383702_fig17310339133719"></a>  
    ![](figures/烧写开始打印.png "烧写开始打印")

# 栈分析和镜像分析<a name="ZH-CN_TOPIC_0000002412436881"></a>

HiSpark Studio for VS Code插件集成了Stack Analysis栈分析工具和Image Analysis镜像分析工具，用于分析开发过程中的内存不足、内存溢出等问题，帮助开发者更加精准的分析定位问题。

-   Stack Analysis栈分析工具是基于静态二进制分析手段，提供任务栈开销估算值和函数调用关系图示，为栈内存使用、分析、优化、问题定位等开发场景提供较为准确的静态内存分析数据参考。
-   Image Analysis镜像分析工具对工程构建出的.elf文件进行内存占用分析，支持开发者快速评估内存段、符号表使用情况。



## 栈分析<a name="ZH-CN_TOPIC_0000002378717620"></a>

**功能介绍<a name="zh-cn_topic_0000002293224062_section148321529151417"></a>**

栈分析工具基于静态二进制分析手段，提供任务栈开销估算值和函数调用关系图示，为栈内存使用、分析、优化和问题定位等开发场景提供较为准确的静态内存分析数据参考。

**功能入口<a name="zh-cn_topic_0000002293224062_section17325123961615"></a>**

创建工程并成功编译后，单击工具栏中“![](figures/zh-cn_image_0000002293384078.png)”按钮进行栈分析。

**栈分析功能页面<a name="zh-cn_topic_0000002293224062_section125419179175"></a>**

栈分析结果按照函数列表和调用关系进行展示。如[图1](#zh-cn_topic_0000002293224062_fig4596122219257)所示，功能列表页面展示每个函数的名称、内部栈开销和位置信息，其中内部栈开销单位为Byte，支持关键字搜索和排序功能。

**图 1**  功能列表页面<a name="zh-cn_topic_0000002293224062_fig4596122219257"></a>  
![](figures/功能列表页面.png "功能列表页面")

调用关系界面如[图2](#zh-cn_topic_0000002293224062_fig1384164712519)所示，显示每个函数的调用关系，包括函数名称、调用深度、函数最大栈开销和内部栈开销，支持关键字搜索和排序功能。

**图 2**  调用图页面<a name="zh-cn_topic_0000002293224062_fig1384164712519"></a>  
![](figures/调用图页面.png "调用图页面")

**统计项说明<a name="zh-cn_topic_0000002293224062_section618mcpsimp"></a>**

-   最大开销：为当前函数所有子函数中最大的栈开销与循环调用的次数的乘积再加上自身的开销。

    计算公式： max（子函数1的自身栈开销， 子函数2的自身栈开销，子函数3的自身栈开销，…） × 循环次数＋函数的自身栈开销

-   本地开销：当前函数的自身栈开销。
-   深度：当前函数每增加一层子函数，深度增加一层。

## 镜像分析<a name="ZH-CN_TOPIC_0000002412317033"></a>

**功能介绍<a name="zh-cn_topic_0000002327223425_section538803119292"></a>**

镜像分析工具通过分析.elf文件，图形化展示RAM和ROM的使用情况。

**功能入口<a name="zh-cn_topic_0000002327223425_section1582295611297"></a>**

创建工程并成功编译后，单击工具栏中的“![](figures/jing.png)”按钮。

**功能界面<a name="zh-cn_topic_0000002327223425_section1533673619307"></a>**

内存区域页面（如[图1](#zh-cn_topic_0000002327223425_fig1787391122717)所示）评估分析工程对内存的细分使用情况。例如WS63，显示的内存区域region包含RAM、SRAM、ITCM等，展示的信息包含每个内存区域的名称、起始内存地址、结束内存地址、总大小、空闲大小、已用大小以及使用比例，支持关键字搜索和排序功能，如[图1](#zh-cn_topic_0000002327223425_fig1787391122717)所示。

**图 1**  内存区域页面<a name="zh-cn_topic_0000002327223425_fig1787391122717"></a>  
![](figures/内存区域页面.png "内存区域页面")

内存详细信息页面（如[图2](#zh-cn_topic_0000002327223425_fig15591937172713)所示）展示每个内存区域包含的内存段section和内存段包含的symbol的详细信息。比如FLASH下面包含.text、.entry、.data等内存段，内存段又包含分配在该段的程序符号，支持关键字搜索和排序功能。

每一行展示的信息包含运行地址VMA（Virtual Memory Address，表示程序装载的内存地址）、装载地址LMA（Load Memory Address，表示程序运行时的内存地址）、内存段/符号的大小。

**图 2**  内存详细信息页面<a name="zh-cn_topic_0000002327223425_fig15591937172713"></a>  
![](figures/内存详细信息页面.png "内存详细信息页面")

文件大小页面（如[图3](#zh-cn_topic_0000002327223425_fig9261641289)所示）展示每个链接进来的.o文件占用了哪块内存的空间以及占用空间的大小，支持关键字搜索和排序功能。

**图 3**  文件大小页面<a name="zh-cn_topic_0000002327223425_fig9261641289"></a>  
![](figures/文件大小页面.png "文件大小页面")

模块大小页面（如[图4](#zh-cn_topic_0000002327223425_fig1367222122813)所示）展示了模块和组件的层级关系以及不同模块的内存占用，支持关键字搜索和排序功能。

**图 4**  模块大小页面<a name="zh-cn_topic_0000002327223425_fig1367222122813"></a>  
![](figures/模块大小页面.png "模块大小页面")

文件夹大小页面（如[图5](#zh-cn_topic_0000002327223425_fig1075993892817)所示）展示了不同文件夹下面模块的内存占用，支持关键字搜索和排序功能，支持导出excel。

**图 5**  文件夹大小<a name="zh-cn_topic_0000002327223425_fig1075993892817"></a>  
![](figures/文件夹大小.png "文件夹大小")

# 工程调试<a name="ZH-CN_TOPIC_0000002378877472"></a>




## 调试配置选项<a name="ZH-CN_TOPIC_0000002412436885"></a>

>![](public_sys-resources/icon-note.gif) **说明：** 
>调试配置选项中的JlinkGDBServerCL驱动需要在jlink官网下载，官网地址为：[https://www.segger.com/products/debug-probes/j-link/models/j-link-base/](https://www.segger.com/products/debug-probes/j-link/models/j-link-base/)

1.  选择要调试的工程：在HiSpark Studio for VS Code插件主界面中，选择要调试的工程，打开“工程配置”。
2.  修改调试选项，选择对应的调试器。

    **图 1**  调试选项修改<a name="zh-cn_topic_0000002293383734_fig4891141904416"></a>  
    ![](figures/调试选项修改.png "调试选项修改")

## 启动调试<a name="ZH-CN_TOPIC_0000002378717632"></a>

1.  单击IDE工具栏调试按钮“![](figures/34.png)”顶部弹框中选择需要的调试模式。

    **图 1**  调试模式选择<a name="zh-cn_topic_0000002293224078_fig0277550163411"></a>  
    ![](figures/调试模式选择.png "调试模式选择")

    -   GDB Launch（Acore）：A核重启，暂停CPU，设置PC指针从头开始运行程序（A核开头设置了一个虚拟断点）。
    -   GDB Attach（Acore）：A核正在运行中，暂停CPU，程序直接停在CPU Halt处。
    -   GDB Launch（Pcore）：P核重启，暂停CPU，设置PC指针从头开始运行程序（P核开头设置了一个虚拟断点）。
    -   GDB Attach（Pcore）：P核正在运行中，暂停CPU，程序直接停在CPU Halt处。

2.  启动调试成功。调试成功示例如下图，若出现下面提示信息与工具栏调试图标，则说明已经成功启动调试。

    **图 2**  调试成功后提示信息、调试图标及调试界面<a name="zh-cn_topic_0000002293224078_fig1214081317358"></a>  
    ![](figures/调试成功后提示信息-调试图标及调试界面.png "调试成功后提示信息-调试图标及调试界面")

    ![](figures/3534.png)

    ![](figures/777.png)

## 常用调试功能<a name="ZH-CN_TOPIC_0000002412317037"></a>


### 调试页面<a name="ZH-CN_TOPIC_0000002378877476"></a>

调试工作界面如[图1](#zh-cn_topic_0000002327183693_fig132922116210)所示，主要由以下3个部分组成：

① 调试侧边栏

② 调试功能区

③ 调试控制台

**图 1**  调试工作界面<a name="zh-cn_topic_0000002327183693_fig132922116210"></a>  
![](figures/调试工作界面.png "调试工作界面")




#### 调试侧边栏<a name="ZH-CN_TOPIC_0000002412436889"></a>

调试侧边栏集合了调试常用功能，包括变量、监视、调用堆栈、断点等。

#### 调试功能区<a name="ZH-CN_TOPIC_0000002378717640"></a>

启动调试功能后，当代码执行到设置的断点时，程序会暂停，可以根据调试功能区的按钮进行代码的调试。

**图 1**  调试图标<a name="zh-cn_topic_0000002293224090_fig1952516244357"></a>  
![](figures/调试图标.png "调试图标")

-   ![](figures/zh-cn_image_0000002327223797.png)：继续运行（“F5”），当程序执行到断点时停止执行，单击此按钮程序继续执行。
-   ![](figures/zh-cn_image_0000002293384106.png)：单步跳过（“F10”），在单步调试时，直接前进到下一行（如果在函数中存在子函数时，不会进入子函数内单步执行，而是将整个子函数当作一步执行）。
-   ![](figures/zh-cn_image_0000002293224438.png)：单步执行（“F11”），在单步调试时，遇到子函数后，进入子函数并继续单步执行。
-   ![](figures/zh-cn_image_0000002327223801.png)：单步跳出（“Shift+F11”），在单步调试执行到子函数内时，单击单步跳出会执行完子函数剩余部分，并跳出返回到上一层函数。
-   ![](figures/zh-cn_image_0000002327184057.png)：重启调试（“Ctrl+Shift+F5”），重新启动调试。
-   ![](figures/tt7.png)：停止调试（“Shift+F5”），停止调试任务，断开连接。

#### 调试控制台<a name="ZH-CN_TOPIC_0000002412317041"></a>

调试控制台用来输出调试时的打印信息，也可以输入命令与调试器交互。

-   变量查看

    当运行到断点处暂停时，可以在变量界面查看变量的当前值。

    **图 1**  查看变量当前值<a name="zh-cn_topic_0000002327223477_fig122981731183513"></a>  
    ![](figures/查看变量当前值.png "查看变量当前值")

    支持如下4种变量类型：

    -   局部变量
    -   全局变量（可能会被编译器优化，可以使用关键字volatile来规避这个问题 。）
    -   静态变量（可能会被编译器优化，可以使用关键字volatile来规避这个问题。 ）
    -   寄存器

-   监视功能

    在调试过程中，可以通过“监视”查看变量（包括局部变量、全局变量以及静态变量）和特定地址的取值来判断程序的运行结果是否有误。

    **图 2**  监视功能<a name="zh-cn_topic_0000002327223477_fig154504387355"></a>  
    ![](figures/监视功能.png "监视功能")

-   查看调用栈

    在调试过程中，可以通过查看调用栈来分析主程序调用的各子程序的调用关系，如下图所示。

    **图 3**  调用堆栈功能<a name="zh-cn_topic_0000002327223477_fig102391744183516"></a>  
    ![](figures/调用堆栈功能.png "调用堆栈功能")

    **----结束**

# 串口控制台工具<a name="ZH-CN_TOPIC_0000002378877480"></a>

本章节主要介绍HiSpark Studio for VS Code插件中关于串口操作的工具监视器（Monitor）。主要功能包括显示串口列表、连接串口、断开串口连接、接收串口消息、给串口发送消息、清空串口输出区、开启\\关闭屏幕自动滚动等。

>![](public_sys-resources/icon-note.gif) **说明：** 
>串口工具以“\\r\\n“作为每行的分隔符，所以要求被打印的每行字符串都要以“\\r\\n“结尾，否则可能会出现程序结尾打印丢失的情况。







## 打开监视器<a name="ZH-CN_TOPIC_0000002412436893"></a>

运行HiSpark Studio for VS Code插件后打开VS Code终端，找到终端区域、切换到“监视器”选项卡，如[图1](#zh-cn_topic_0000002293224166_fig17771812125220)所示。

**图 1**  切换到“监视器”选项卡<a name="zh-cn_topic_0000002293224166_fig17771812125220"></a>  
![](figures/切换到-监视器-选项卡.png "切换到-监视器-选项卡")

**图 2**  监视器界面介绍<a name="zh-cn_topic_0000002293224166_fig14318546512"></a>  

![](figures/terminal.png)

-   ①：串口配置区

    端口：显示当前电脑所连接的串口设备，单击“![](figures/zh-cn_image_0000002327184165.png)”按钮刷新串口列表。

    波特率：选择串口波特率，范围：300～250000。

    行尾：当给串口发送消息时，工具会根据此选项自动添加字符。

    -   CRLF代表“\\r\\n”。
    -   CR代表“\\r”。
    -   LF代表“\\n”。

-   ②：功能按钮区

    ![](figures/zh-cn_image_0000002293384214.png)：连接串口按钮。当连接串口后，按钮状态会变成![](figures/zh-cn_image_0000002293224546.png)，单击此按钮会断开串口连接。

    ![](figures/zh-cn_image_0000002327223909.png)：时间戳按钮。开启时会在每行输出前加上时间戳显示，如果按钮处于关闭状态则不显示时间戳，如[图3](#zh-cn_topic_0000002293224166_fig1040102615572)所示。

    **图 3**  时间戳设置效果示例<a name="zh-cn_topic_0000002293224166_fig1040102615572"></a>  
    ![](figures/时间戳设置效果示例.png "时间戳设置效果示例")

    ![](figures/zh-cn_image_0000002293384218.png)：隐藏输入框，隐藏/显示输入框界面如[图4](#zh-cn_topic_0000002293224166_fig209583373583)、[图5](#zh-cn_topic_0000002293224166_fig17214483580)所示。

    **图 4**  显示输入框<a name="zh-cn_topic_0000002293224166_fig209583373583"></a>  
    ![](figures/显示输入框.png "显示输入框")

    **图 5**  隐藏输入框<a name="zh-cn_topic_0000002293224166_fig17214483580"></a>  
    ![](figures/隐藏输入框.png "隐藏输入框")

    ![](figures/zh-cn_image_0000002327184173.png)：开启/关闭屏幕自动滚动。

    ![](figures/zh-cn_image_0000002293384226.png)：清空输出区。

    ![](figures/zh-cn_image_0000002293224562.png)：最大化面板。

    ![](figures/zh-cn_image_0000002327223921.png)：关闭面板

-   ③：输出区。
-   ④：输入区。
-   ⑤：发送消息按钮，单击按钮或者敲击回车发送输入区信息给串口，默认编码为UTF-8。

## 连接串口<a name="ZH-CN_TOPIC_0000002378717648"></a>

单击“![](figures/zh-cn_image_0000002327184177.png)”即可连接串口。连接串口前，输入区默认处于未激活状态（不可输入、不可点击）；连接串口后，输入区变为激活状态，串口配置区的监视模式选项变为未激活状态。

**图 1**  开始监视功能<a name="zh-cn_topic_0000002327223529_fig58721954163517"></a>  
![](figures/开始监视功能.png "开始监视功能")

## 查看消息<a name="ZH-CN_TOPIC_0000002412317045"></a>

在输出区可以查看串口发送的消息。

**图 1**  查看串口消息<a name="zh-cn_topic_0000002327183793_fig15659205953510"></a>  
![](figures/查看串口消息.png "查看串口消息")

## 发送消息<a name="ZH-CN_TOPIC_0000002378877488"></a>

在下方输入区输入消息后单击发送按钮或者单击键盘回车按钮发送消息。

**图 1**  发送消息<a name="zh-cn_topic_0000002293383846_fig1571552215364"></a>  
![](figures/发送消息.png "发送消息")

## 断开连接<a name="ZH-CN_TOPIC_0000002412436897"></a>

单击“![](figures/zh-cn_image_0000002327184181.png)”按钮断开串口连接。

**图 1**  停止监视<a name="zh-cn_topic_0000002293224182_fig4728173953619"></a>  
![](figures/停止监视.png "停止监视")

## 扩展工具使用<a name="ZH-CN_TOPIC_0000002378717652"></a>

扩展工具主要用于添加一些用户常用的命令，添加后可以做到点击名称发送命令。扩展工具在出厂时添加了一些常用命令，如果用户用不到这些命令，可以选择清空表格，然后手动添加所需命令，或通过excel表格导入方式进行添加。除此之外，扩展工具还有循环发送功能，在后面章节中会详细介绍。

-   打开扩展工具。单击扩展按钮，会在右侧展开扩展页面。

    **图 1**  扩展工具<a name="zh-cn_topic_0000002327223541_fig1786951684210"></a>  
    ![](figures/扩展工具.png "扩展工具")

    单击此按钮可最大化面板。

    **图 2**  监视器面板最大化按钮<a name="zh-cn_topic_0000002327223541_fig11226132364210"></a>  
    ![](figures/监视器面板最大化按钮.png "监视器面板最大化按钮")

-   单击清空列表按钮可清空列表。

    **图 3**  清空列表功能<a name="zh-cn_topic_0000002327223541_fig6150152913426"></a>  
    ![](figures/清空列表功能.png "清空列表功能")

    如果清空出厂表格后需要恢复，可导入安装目录下“C:\\Users\\用户xxx\\.vscode\\extensions\\hispark.hisparkstudio-x.x.x\\dist\\resources\\terminal\\resources\\excelFile“下的“rawData.xlsx”表格。

-   手动新增命令行。单击“增加一行”按钮。

    **图 4**  新增一行功能<a name="zh-cn_topic_0000002327223541_fig1455312345424"></a>  
    ![](figures/新增一行功能.png "新增一行功能")

    添加数据规则：

    数据格式：下拉框模式，下拉选项有utf8、bin、hex。

    命令：发送给串口的命令字符串。

    名称：识别命令功能的字符串。单击此按钮可立即发送命令给串口（前提是工具处于监听状态）。

    顺序：在使用循环发送功能时，顺序大于0，才会进行循环发送。如果有多个命令的顺序大于0，并且数值一样，则按照由上到下的顺序发送。

    延时发送：先发送一次，再进行延时，单位：ms。

    操作：有编辑和删除两个选项，单击编辑可对命令行进行修改，单击删除可删除命令行。

-   批量添加命令。
    1.  下载导入模板。导入模板会自动保存到“C:\\Users\\用户xxx\\.vscode\\extensions\\hispark.hisparkstudio-x.x.x\\resources\\terminal\\resources\\excelFile\\template.xlsx”。

        **图 5**  下载导入模板功能<a name="zh-cn_topic_0000002327223541_fig131081446114215"></a>  
        ![](figures/下载导入模板功能.png "下载导入模板功能")

        导入模板中会显示需要导入的列，以及每个列的规则。

        **图 6**  导入模板<a name="zh-cn_topic_0000002327223541_fig4205125119425"></a>  
        ![](figures/导入模板.png "导入模板")

    2.  填写导入模板。

        **图 7**  导入模板数据填写<a name="zh-cn_topic_0000002327223541_fig249315718422"></a>  
        ![](figures/导入模板数据填写.png "导入模板数据填写")

    3.  导入“导入模板“文件。

        **图 8**  导入模板数据<a name="zh-cn_topic_0000002327223541_fig11424622434"></a>  
        ![](figures/导入模板数据.png "导入模板数据")

        ![](figures/Snipaste_2025-05-26_19-25-41.png)

    4.  查看导入数据。

        **图 9**  查看导入数据<a name="zh-cn_topic_0000002327223541_fig18481158134314"></a>  
        ![](figures/查看导入数据.png "查看导入数据")

        ![](figures/zh-cn_image_0000002327184197.png)

    5.  查看导入结果表格。导入结果列会显示导入不成功的原因。

        **图 10**  查看导入结果<a name="zh-cn_topic_0000002327223541_fig1017011484311"></a>  
        ![](figures/查看导入结果.png "查看导入结果")

-   循环发送。
    1.  设置顺序和延时。

        **图 11**  设置顺序和延时功能<a name="zh-cn_topic_0000002327223541_fig6466102611434"></a>  
        ![](figures/设置顺序和延时功能.png "设置顺序和延时功能")

        上图表格执行命令的顺序：

        首先，发送“起蓝牙“命令，延时1000ms；然后，发送“键盘模式“命令，延时1000ms；最后，发送“鼠标模式“命令，延时1000ms；结束。这是一个循环发送的周期，循环发送会不断的循环这个周期。

        “修改蓝牙地址”命令并不会发送，因为它的顺序不大于0。

    2.  打开串口监听。

        **图 12**  串口监听功能<a name="zh-cn_topic_0000002327223541_fig5219203116435"></a>  
        ![](figures/串口监听功能.png "串口监听功能")

    3.  打开循环发送开关（发送的命令自带“回车换行”）。打开后，会在左侧输出栏看到发送的命令。

        **图 13**  循环发送功能<a name="zh-cn_topic_0000002327223541_fig734614365431"></a>  
        ![](figures/循环发送功能.png "循环发送功能")

        红色字体表明正在发送此条命令或者正在延时

# Kconfig配置<a name="ZH-CN_TOPIC_0000002412317049"></a>

本功能主要用于控制工程的编译构建， 支持通过图形化界面管理编译配置。

打开工程后，单击工具栏中的系统配置“![](figures/zh-cn_image_0000002327291945.png)”按钮，如[图1](#zh-cn_topic_0000002327183797_fig1334674314438)所示。

**图 1**  系统配置入口<a name="zh-cn_topic_0000002327183797_fig1334674314438"></a>  
![](figures/系统配置入口.png "系统配置入口")

系统配置界面如[图2](#zh-cn_topic_0000002327183797_fig11641828725)所示。

**图 2**  系统配置界面<a name="zh-cn_topic_0000002327183797_fig11641828725"></a>  
![](figures/系统配置界面.png "系统配置界面")


## 按钮功能介绍<a name="ZH-CN_TOPIC_0000002378877492"></a>

系统配置界面按钮功能如下：

① save：配置文件默认保存至\`$\{menu\_config\_build\_target\}\`下。

② save as：自定义保存路径，默认配置文件名 \`$\{menu\_config\_build\_target\}\`.config。

③ save\(minimal\)：自定义保存路径和配置文件名称，且只保存修改过的配置项。

④ open：自定义加载配置文件。

⑤ jump to：配置项搜索。

⑥ show name：显示列名（Option-Name）。

⑦ show all：显示隐藏配置项。

⑧ Single-menu mode：单个菜单模式。

# GUI工程创建与使用<a name="ZH-CN_TOPIC_0000002412436901"></a>

HiSpark Studio支持创建GUI工程和GUI模拟器的使用。按照“[3.1新建工程](新建工程.md#ZH-CN_TOPIC_0000002412436861)”指导新建Brandy工程后，单击工具栏菜单下的“创建GUI应用”图标可在Brandy的工程中创建GUI工程。

**图 1**  创建GUI工程<a name="zh-cn_topic_0000002399739733_fig1874373411538"></a>  
![](figures/创建GUI工程.png "创建GUI工程")

-   像素值：默认454×454对应生成的画布大小，在形状为circle（圆形）时，分辨率为直径×直径，在形状为reatangle（方形）时，分辨率为长×宽。像素值可以自定义，取值范围为1～600。
-   形状：分为circle（圆形）和reatangle（方形），如果不主动选择，默认为圆形。





## GUI界面介绍<a name="ZH-CN_TOPIC_0000002378717656"></a>



### GUI拖拽界面介绍<a name="ZH-CN_TOPIC_0000002412317053"></a>

GUI工程创建后，会在工程目录的“application/wearable/nativeapp/nativeui/应用名”这一目录下创建一个以工程名命名的GUI文件，打开后会呈现表盘形状，可自定义表盘内容。

当前支持的组件包括Button、Image、Progress、List、Label、ToggleButton、CheckBox、RadioButton、LabelButton、ScrollView、CircleProgress、ArcLabel、SwipeView、TextureMapper、Slider、Picker、TimePicker、Chart、EditText、ImageAnimator、DigitalClock、Qrcode、AnalogClock、SweepClock、Coverflow、Barcode、CardPage、CrossView、MapView、RollerView、HexagonsList、IcosahedronView、CanvasExt、TransformList、SlipflowView、TransformGroup、Coverflow2、ParticleView组件和Root组件。

**图 1**  GUI拖拽界面<a name="zh-cn_topic_0000002399619865_fig1973444016553"></a>  

![](figures/gui8.png)

-   FileTree：页面树，可以选择添加、删除页面、修改页面标题、设置主页面。
-   UI Control：UI组件栏，可以将相应的组件选中并拖动到画布（Canvas）中，实现组件的添加。
-   Component Tree：组件树，在低代码开发界面中，开发者可以直观地看到组件的层级结构和摘要信息。开发者可以通过选中组件树中的组件（画布中对应的组件被同步选中），实现画布内组件的快速定位；单击组件后的“![](figures/Y.png)”，可以隐藏/显示相应的组件。
-   Panel：功能面板，包括CrossView、Coverflow2组件用到的子组件切换，以及常用的画布缩小放大、组件左对齐、垂直居中对齐、右对齐、顶对齐、水平居中对齐、底对齐、图层切换、撤销、显示/隐藏组件虚拟边框、一键生成C++代码等。
-   Canvas：画布，开发者可在此区域对组件进行拖拽、拉伸等可视化操作，构建UI界面布局效果。
-   Attributes & Styles：属性样式栏，选中画布中的相应组件后，在右侧属性样式栏可以对该组件的属性样式进行配置。
    -   General：对应图标![](figures/zh-cn_image_0000002366100070.png)，用于设置Width、Height、Background、Position、Display等常规样式。
    -   Feature：对应图标![](figures/zh-cn_image_0000002399619989.png)，用于设置组件的特有样式，如描述Text组件文字大小的FontSize样式等。
    -   Events：对应图标![](figures/zh-cn_image_0000002365940174.png)，为组件绑定相关事件，并设置绑定事件的回调函数。

### 组件介绍<a name="ZH-CN_TOPIC_0000002378877496"></a>













































#### 组件的复制粘贴删除<a name="ZH-CN_TOPIC_0000002412436905"></a>

以Button组件为例，在画布内已经拖入Button组件的前提下进行操作：

-   组件删除

    组件可以通过两种方式删除：

    -   右键点击画布中的Button组件显示操作栏，在弹出的操作栏点击Delete。
    -   选中Button组件，通过键盘Del键删除。

    **图 1**  组件删除<a name="zh-cn_topic_0000002399739737_fig1276601114010"></a>  
    ![](figures/组件删除.png "组件删除")

-   组件复制

    组件可以通过两种方式复制：

    -   右键点击画布中的Button组件显示操作栏，在弹出的操作栏点击Copy再次右键后点选Paste实现复制粘贴。
    -   选中Button组件，通过键盘Ctrl+C和Ctrl+V实现复制粘贴。

    **图 2**  组件复制<a name="zh-cn_topic_0000002399739737_fig1175415591409"></a>  
    ![](figures/组件复制.png "组件复制")

    **图 3**  组件粘贴<a name="zh-cn_topic_0000002399739737_fig14301013164114"></a>  
    ![](figures/组件粘贴.png "组件粘贴")

#### 组件的共有属性<a name="ZH-CN_TOPIC_0000002378717660"></a>

以Button组件为例，选中组件栏中的Button组件，将其拖拽至中央画布区域，松开鼠标，实现一个Button组件的添加。（组件会生成在画布上坐标（100，100）的位置）。

**图 1**  拖拽组件<a name="zh-cn_topic_0000002366099954_fig10331115148"></a>  
![](figures/拖拽组件.png "拖拽组件")

以下操作需在画布内已经拖入Button组件的前提下进行操作。

-   选中画布内的Button组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002399739865.png)样式图标（General），在展开的General栏中修改Button组件的ID。ID并非生成代码时的变量名，因此多个组件可以设置同一个ID。

    **图 2**  通用属性配置：Id<a name="zh-cn_topic_0000002366099954_fig1333343519513"></a>  
    ![](figures/通用属性配置-Id.png "通用属性配置-Id")

-   选中画布内的Button组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002399620009.png)样式图标（General），在展开的General栏中修改Button组件的宽高、位置；另外还可以通过拖拽的方式放大缩小Button组件以及改变组件的位置。

    **图 3**  通用属性的配置<a name="zh-cn_topic_0000002366099954_fig9966191695113"></a>  
    ![](figures/通用属性的配置.png "通用属性的配置")

-   选中Button组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399739869.png)样式图标（General），在展开的General栏中修改Button组件的BackgroundColor属性改变背景颜色。

    **图 4**  修改背景颜色<a name="zh-cn_topic_0000002366099954_fig759121615415"></a>  
    ![](figures/修改背景颜色.png "修改背景颜色")

-   选中画布内的Button组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002399620013.png)样式图标（General），在展开的General栏中修改Button组件GaussOption框中的FullScreenState、GaussianBlur属性改组件的高斯模糊。在同时拖拽两个组件的前提下进行。FullScreenState为false高斯模糊设置不生效，FullScreenState为true高斯模糊设置生效。GaussianBlur属性控制高斯模糊的模糊程度。详情请参见“[高斯模糊属性](高斯模糊属性.md#ZH-CN_TOPIC_0000002378877540)”。

    **图 5**  高斯模糊<a name="zh-cn_topic_0000002366099954_fig48601252103118"></a>  
    ![](figures/高斯模糊.png "高斯模糊")

-   选中画布内的Button组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002399739877.png)样式图标（General），在展开的General栏中修改Button组件Border框中的Width、Color、Radius属性改变边框的样式。

    **图 6**  修改组件边框样式<a name="zh-cn_topic_0000002366099954_fig421010341275"></a>  
    ![](figures/修改组件边框样式.png "修改组件边框样式")

-   选中Button组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399620017.png)样式图标（General），在展开的General栏中修改Button组件Margin框中的MarginTop和MarginLeft属性调整组件相对表盘的位置。

    **图 7**  修改组件相对窗口位置<a name="zh-cn_topic_0000002366099954_fig19389527155313"></a>  
    ![](figures/修改组件相对窗口位置.png "修改组件相对窗口位置")

-   选中Button组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399739897.png)样式图标（General），在展开的General栏中修改Padding改变组件padding部分四个方向的宽度。

    **图 8**  组件相对边框位置<a name="zh-cn_topic_0000002366099954_fig88161839549"></a>  
    ![](figures/组件相对边框位置.png "组件相对边框位置")

#### Button组件<a name="ZH-CN_TOPIC_0000002412317057"></a>

共有属性使用方法请参见“[组件的共有属性](组件的共有属性.md#ZH-CN_TOPIC_0000002378717660)”章节内容。

-   选中画布内的Button组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002399620053.png)样式图标（Feature），在展开的Feature栏中修改Button组件的DefaultImgSrc属性加载图片。

    **图 1**  DefaultImgSrc属性配置<a name="zh-cn_topic_0000002399619869_fig1930105513132"></a>  
    ![](figures/DefaultImgSrc属性配置.png "DefaultImgSrc属性配置")

-   选中画布内的Button组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002399739953.png)样式图标（Feature），在展开的Feature栏中修改Button组件的ImageX和ImageY属性调整图片位置（修改前需要设置DefaultImgSrc属性）。

    **图 2**  ImageX/ImageY属性配置<a name="zh-cn_topic_0000002399619869_fig11684412161613"></a>  
    ![](figures/ImageX-ImageY属性配置.png "ImageX-ImageY属性配置")

-   选中画布内的Button组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002399620097.png)样式图标（Feature），在展开的Feature栏中修改Button组件的ImageOpacity属性调整图片透明度（需要设置DefaultImgSrc）。

    **图 3**  ImageOpacity属性配置<a name="zh-cn_topic_0000002399619869_fig11511623928"></a>  
    ![](figures/ImageOpacity属性配置.png "ImageOpacity属性配置")

-   选中画布内的Button组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002399739961.png)样式图标（Events），在展开的Events栏中配置回调事件。

    Button组件支持的事件有：OnClick、OnLongPress、OnPress、OnCancel和OnRelease。

    **图 4**  回调事件配置<a name="zh-cn_topic_0000002399619869_fig141561846154620"></a>  
    ![](figures/回调事件配置.png "回调事件配置")

>![](public_sys-resources/icon-note.gif) **说明：** 
>-   General页面下的MarginBottom属性和MarginRight属性无界面渲染效果。
>-   Feature页面下的TriggeredImgSrc属性、TriggeredBackgroundColor属性、TriggeredBorderColor属性无界面渲染效果，可以在模拟器上查看渲染效果。
>-   DefaultImgSrc和TriggeredImgSrc不支持中文路径。

#### Image组件<a name="ZH-CN_TOPIC_0000002378877500"></a>

共有属性使用方法请参见“[组件的共有属性](组件的共有属性.md#ZH-CN_TOPIC_0000002378717660)”章节内容。

-   选中画布内的Image组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002399620105.png)样式图标（Feature），在展开的Feature栏中修改Image组件的ImagePath属性加载图片。

    在已有选中图片情况下再次选择相同图片，或者在浏览文件时关闭窗口或点击取消时，界面渲染效果将不会改变。需要清空图片可以删除输入框中的文本。

    **图 1**  特有属性配置：ImagePath<a name="zh-cn_topic_0000002365940058_fig1383616220353"></a>  
    ![](figures/特有属性配置-ImagePath.png "特有属性配置-ImagePath")

    >![](public_sys-resources/icon-note.gif) **说明：** 
    >ImagePath不支持中文路径。
    >导入的Bin文件必须是图片转的Bin，否则模拟器会异常。

-   选中画布内的Image组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002399739965.png)样式图标（Feature），在展开的Feature栏中修改Image组件的ImageOpacity属性调整图片透明度。

    **图 2**  特有属性配置：ImageOpacity<a name="zh-cn_topic_0000002365940058_fig19953128113813"></a>  
    ![](figures/特有属性配置-ImageOpacity.png "特有属性配置-ImageOpacity")

-   选中画布内的Image组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002399620109.png)样式图标（Feature），在展开的Feature栏中修改Image组件的AutoEnable属性。

    -   AutoEnable属性设置为true时，组件会被限制为图片本身的大小，无法通过拖拽组件或直接修改Width/Height值来修改组件的显示效果。
    -   AutoEnable属性设置为false时，会按照组件大小展示图片，设置不同的ImageResizeMode属性值可以呈现不同的显示效果。

    **图 3**  特有属性配置：AutoEnable<a name="zh-cn_topic_0000002365940058_fig32031181480"></a>  
    ![](figures/特有属性配置-AutoEnable.png "特有属性配置-AutoEnable")

-   选中画布内的Image组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002399739969.png)样式图标（Feature），在展开的Feature栏中修改Image组件的ImageResizeMode属性。

    -   AutoEnable属性设置为true时，ImageResizeMode属性不生效。
    -   AutoEnable属性设置为false时，ImageResizeMode生效，对应不同的显示效果。

    当前共有6种模式对应的效果示例如下（图片原始尺寸为80×80）：

    -   ImageResizeMode - None

        **图 4**  图片平铺（图中组件大小为200×200）<a name="zh-cn_topic_0000002365940058_fig137143716018"></a>  
        ![](figures/图片平铺（图中组件大小为200-200）.png "图片平铺（图中组件大小为200-200）")

    -   ImageResizeMode - Cover

        **图 5**  图片覆盖组件1（图中组件大小为100×200）<a name="zh-cn_topic_0000002365940058_fig203183291602"></a>  
        ![](figures/图片覆盖组件1（图中组件大小为100-200）.png "图片覆盖组件1（图中组件大小为100-200）")

        **图 6**  图片覆盖组件2（图中组件大小为200×100）<a name="zh-cn_topic_0000002365940058_fig119815431203"></a>  
        ![](figures/图片覆盖组件2（图中组件大小为200-100）.png "图片覆盖组件2（图中组件大小为200-100）")

    -   ImageResizeMode - Contain

        **图 7**  图片被组件包含在内（图中组件大小为100×200）<a name="zh-cn_topic_0000002365940058_fig9776119513"></a>  
        ![](figures/图片被组件包含在内（图中组件大小为100-200）.png "图片被组件包含在内（图中组件大小为100-200）")

        **图 8**  图片被组件包含在内（图中组件大小为200×100）<a name="zh-cn_topic_0000002365940058_fig1741815478118"></a>  
        ![](figures/图片被组件包含在内（图中组件大小为200-100）.png "图片被组件包含在内（图中组件大小为200-100）")

    -   ImageResizeMode - Fill

        **图 9**  图片填满组件（图中组件大小为200×100）<a name="zh-cn_topic_0000002365940058_fig143226171166"></a>  
        ![](figures/图片填满组件（图中组件大小为200-100）.png "图片填满组件（图中组件大小为200-100）")

    -   ImageResizeMode - Center

        **图 10**  图片处在组件中心（图中组件大小为100×100）<a name="zh-cn_topic_0000002365940058_fig78523241168"></a>  
        ![](figures/图片处在组件中心（图中组件大小为100-100）.png "图片处在组件中心（图中组件大小为100-100）")

        >![](public_sys-resources/icon-note.gif) **说明：** 
        >组件宽高任一为0时，图片隐藏。

    -   ImageResizeMode - Scale Down

        **图 11**  组件宽高较大时，图片按原有尺寸显示<a name="zh-cn_topic_0000002365940058_fig1319195718418"></a>  
        ![](figures/组件宽高较大时-图片按原有尺寸显示.png "组件宽高较大时-图片按原有尺寸显示")

        **图 12**  组件宽高较小时，图片会缩小并被组件包含在内<a name="zh-cn_topic_0000002365940058_fig89661415359"></a>  
        ![](figures/组件宽高较小时-图片会缩小并被组件包含在内.png "组件宽高较小时-图片会缩小并被组件包含在内")

>![](public_sys-resources/icon-note.gif) **说明：** 
>-   组件的特有属性ImagePath未设置时，模拟器中不会显示组件。
>-   General页面下的MarginBottom属性和MarginRight属性没有任何界面渲染效果，可在模拟器上查看效果。
>-   Feature页面下的BlurLevel属性和Algorithm属性没有任何界面渲染效果，可在模拟器上查看效果。
>-   Image组件不支持配置回调事件。

#### Progress组件<a name="ZH-CN_TOPIC_0000002412436909"></a>

共有属性使用方法请参见“[组件的共有属性](组件的共有属性.md#ZH-CN_TOPIC_0000002378717660)”章节内容。

-   选中Progress组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399620153.png)样式图标（Feature），在展开的Feature栏中ForegroundStyle窗口中修改Progress组件的前景色。

    **图 1**  修改前景色<a name="zh-cn_topic_0000002399739741_fig117331435123510"></a>  
    ![](figures/修改前景色.png "修改前景色")

-   选中Progress组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399740017.png)样式图标（Feature），在展开的Feature栏中BackgroundStyle窗口中修改Progress组件的背景色。

    **图 2**  修改背景色<a name="zh-cn_topic_0000002399739741_fig879142417363"></a>  
    ![](figures/修改背景色.png "修改背景色")

-   选中Progress组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399620157.png)样式图标（Feature），在展开的Feature栏中修改Progress组件的ProgressWidth和ProgressHeight属性改变组件的宽度和高度。

    **图 3**  修改组件宽高<a name="zh-cn_topic_0000002399739741_fig119251539922"></a>  
    ![](figures/修改组件宽高.png "修改组件宽高")

-   选中Progress组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399740029.png)样式图标（Feature），在展开的Feature栏中修改Progress组件的Direction属性修改进度条方向。

    **图 4**  修改进度条方向<a name="zh-cn_topic_0000002399739741_fig4795118183012"></a>  
    ![](figures/修改进度条方向.png "修改进度条方向")

-   选中Progress组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399620269.png)样式图标（Feature），在展开的Feature栏中修改Progress组件的Value属性修改进度。

    **图 5**  修改进度<a name="zh-cn_topic_0000002399739741_fig18362191916365"></a>  
    ![](figures/修改进度.png "修改进度")

-   选中Progress组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399740281.png)样式图标（Feature），在展开的Feature栏中修改Progress组件的ForeImage属性添加已走过进度的图片和BackImage属性添加进度条整体的图片。路径不能为空，不支持中文路径。

    **图 6**  添加图片<a name="zh-cn_topic_0000002399739741_fig9386125012810"></a>  
    ![](figures/添加图片.png "添加图片")

>![](public_sys-resources/icon-note.gif) **说明：** 
>-   General页面下的BackgroungColor属性，MarginBottom属性和MarginRight属性暂无渲染效果。
>-   Feature页面下的ForegroundStyle和BackgroundStyle的子属性BorderWidth、BorderColor、BorderRadius、LineWidth、LineHeight、LineColor、ImageOpacity属性暂无渲染效果。
>-   Progress组件不支持配置回调事件。

#### List组件<a name="ZH-CN_TOPIC_0000002378717664"></a>

共有属性使用方法请参见“[组件的共有属性](组件的共有属性.md#ZH-CN_TOPIC_0000002378717660)”章节内容。

-   选中List组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399620549.png)样式图标（Feature），在展开的Feature栏中修改itemHeight属性设置所有子项的高度；修改itemWidth属性设置所有子项的宽度；修改imageWidth属性设置所有子项图片的宽度；修改imageHeight属性设置所有子项图片的高度；修改FontSize属性设置所有子项的字体大小；点击Item栏右侧的加号添加子项，修改子项中的Text属性和ImagePath属性添加文本和图片。

    **图 1**  添加子项<a name="zh-cn_topic_0000002366099958_fig28061923305"></a>  
    ![](figures/添加子项.png "添加子项")

-   选中List组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399740433.png)样式图标（Feature），在展开的Feature栏中修改List组件的OffsetX属性设置所有子项的横向偏移，修改OffsetY属性设置所有子项的纵向偏移。

    **图 2**  修改子项的偏移<a name="zh-cn_topic_0000002366099958_fig1020210122313"></a>  
    ![](figures/修改子项的偏移.png "修改子项的偏移")

-   选中List组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399620589.png)样式图标（Feature），在展开的Feature栏中修改List组件的Direction属性设置列表的排列方向。

    **图 3**  修改列表的排列方向<a name="zh-cn_topic_0000002366099958_fig56791215114412"></a>  
    ![](figures/修改列表的排列方向.png "修改列表的排列方向")

-   选中画布内的List组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002399740481.png)样式图标（Events），在展开的Events栏中配置回调事件。

    List组件支持的事件有：OnClick、OnLongPress、OnDrag、OnDragStart、OnDragEnd、OnPress、OnCancel、OnRelease、OnFocus和OnBlur。

    **图 4**  回调事件配置<a name="zh-cn_topic_0000002366099958_fig186332171075"></a>  
    ![](figures/回调事件配置-1.png "回调事件配置-1")

>![](public_sys-resources/icon-note.gif) **说明：** 
>-   General页面下的MarginBottom属性和MarginRight属性无渲染效果。
>-   Feature页面下的Isloop属性、Autoalign属性、Aligntime属性、Startindex属性均没有界面渲染效果，在添加子元素后可在模拟器查看效果。
>-   目前删除子项的最后一个元素会出现无法删除的问题，如需删除，可以在关闭界面的状态下在index.visual中将属性listItemText和listItemPath删除。

#### Label组件<a name="ZH-CN_TOPIC_0000002412317061"></a>

共有属性使用方法请参见“[组件的共有属性](组件的共有属性.md#ZH-CN_TOPIC_0000002378717660)”章节内容。

-   选中画布内的Label组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002399620633.png)样式图标（Feature），在展开的Feature栏中修改Label组件的Text属性来编辑文本内容（新添加组件默认文本内容为“default”）。

    **图 1**  特有属性配置：Text文本内容<a name="zh-cn_topic_0000002399619873_fig455274919252"></a>  
    ![](figures/特有属性配置-Text文本内容.png "特有属性配置-Text文本内容")

-   选中画布内的Label组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002399740537.png)样式图标（Feature），在展开的Feature栏中设置Label组件的Font属性：

    -   Color：字体颜色
    -   Size：字体大小
    -   LetterSpace：字母间距
    -   LineSpace：行间距
    -   LineHeight：行高（行高小于字体大小时将以字体大小为准，最终行高＝行高＋行间距）
    -   TextDirection：文本方向

    **图 2**  通用属性配置：文本相关属性<a name="zh-cn_topic_0000002399619873_fig15826115915219"></a>  
    ![](figures/通用属性配置-文本相关属性.png "通用属性配置-文本相关属性")

-   选中画布内的Label组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002399620677.png)样式图标（Feature），在展开的Feature栏中修改Label组件的TextAlign属性改变文字的横向与纵向排布。

    **图 3**  改变文字排布<a name="zh-cn_topic_0000002399619873_fig195425918268"></a>  
    ![](figures/改变文字排布.png "改变文字排布")

-   选中画布内的Label组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002399740593.png)样式图标（Feature），在展开的Feature栏中修改Label组件的LineBreakMode属性。LineBreakMode对应6种换行模式，详细介绍如下：
    -   Adapt：组件大小自适应文本，且不会对文本做自动换行。

        >![](public_sys-resources/icon-note.gif) **说明：** 
        >组件宽高不受通用属性Width/Height值影响，因此不可通过拖拽组件或直接修改Width/Height值的方式改变组件宽高。

        **图 4**  LineBreakMode - Adapt<a name="zh-cn_topic_0000002399619873_fig1679161320461"></a>  
        ![](figures/LineBreakMode---Adapt.png "LineBreakMode---Adapt")

    -   Stretch：组件高度按照设置的Height值显示，宽度由文本中最长的行决定，文本不会自动换行。

        >![](public_sys-resources/icon-note.gif) **说明：** 
        >组件宽度不受通用属性Width值影响，因此不可通过拖拽组件或直接修改Width值的方式改变组件宽度。

        **图 5**  LineBreakMode - Stretch<a name="zh-cn_topic_0000002399619873_fig8791181319462"></a>  
        ![](figures/LineBreakMode---Stretch.png "LineBreakMode---Stretch")

    -   Wrap：组件宽度按照设置的Width值显示，文本自动换行，组件高度由文本行数决定。

        >![](public_sys-resources/icon-note.gif) **说明：** 
        >组件高度不受通用属性Height值影响，因此不可通过拖拽组件或直接修改Height值的方式改变组件高度。

        **图 6**  LineBreakMode - Wrap<a name="zh-cn_topic_0000002399619873_fig177911513124619"></a>  
        ![](figures/LineBreakMode---Wrap.png "LineBreakMode---Wrap")

    -   Ellipsis：组件大小按照设置的Height和Width值显示，文本自动换行，超出组件的文本将在末尾以省略号的形式显示。

        **图 7**  LineBreakMode - Ellipsis<a name="zh-cn_topic_0000002399619873_fig1179181314462"></a>  
        ![](figures/LineBreakMode---Ellipsis.png "LineBreakMode---Ellipsis")

    -   Clip：组件大小按照设置的Height和Width值显示，文本自动换行，超出组件的文本将在末尾自动隐藏。

        **图 8**  LineBreakMode - Clip<a name="zh-cn_topic_0000002399619873_fig14791191324610"></a>  
        ![](figures/LineBreakMode---Clip.png "LineBreakMode---Clip")

    -   Marquee：组件大小按照设置的Height和Width值显示，文本不自动换行，超出组件的文本将自动隐藏。

        >![](public_sys-resources/icon-note.gif) **说明：** 
        >此模式下如果单行文本长度不超出组件时，文本按照设置的TextAlign进行对齐。
        >文本长度超出组件时，文本会自动向左循环滚动播放。

        **图 9**  LineBreakMode - Marquee<a name="zh-cn_topic_0000002399619873_fig530611174710"></a>  
        ![](figures/LineBreakMode---Marquee.png "LineBreakMode---Marquee")

-   选中画布内的Label组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002365941030.png)样式图标（Feature），在展开的Feature栏中修改Label组件的RollAnimation属性。

    RollAnimation属性只在LineBreakMode为Marquee且文本长度超出时生效。RollAnimation包含滚动速度（Speed）和滚动起始位置（Pos）。

    **图 10**  特有属性配置：RollAnimation<a name="zh-cn_topic_0000002399619873_fig19196141194615"></a>  
    ![](figures/特有属性配置-RollAnimation.png "特有属性配置-RollAnimation")

>![](public_sys-resources/icon-note.gif) **说明：** 
>-   General页面下的MarginBottom属性和MarginRight属性没有任何界面渲染效果，可在模拟器上查看效果。
>-   Label组件不支持配置回调事件。

#### ToggleButton组件<a name="ZH-CN_TOPIC_0000002378877504"></a>

共有属性使用方法请参见“[组件的共有属性](组件的共有属性.md#ZH-CN_TOPIC_0000002378717660)”章节内容。

-   选中画布内的ToggleButton组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002366100938.png)样式图标（Feature），在展开的Feature栏中修改ToggleButton组件的ImageOpacity属性修改图片透明度。

    **图 1**  修改图片透明度<a name="zh-cn_topic_0000002365940062_fig18996545134711"></a>  
    ![](figures/修改图片透明度.png "修改图片透明度")

-   选中ToggleButton组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002365941090.png)样式图标（Feature），在展开的Feature栏中修改ToggleButton组件的State属性改变组件的状态，当属性值为true时为选中状态，反之为未选中状态。

    **图 2**  修改组件状态<a name="zh-cn_topic_0000002365940062_fig28061923305"></a>  
    ![](figures/修改组件状态.png "修改组件状态")

-   选中ToggleButton组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002366100998.png)样式图标（Feature），在展开的Feature栏中修改ToggleButton组件的UnSelectedImg属性添加未选中时的图片和SelectedImg属性添加选中时的图片，两张图片必须同时存在时才会产生渲染效果，通过将属性UnSelectedImg和SelectedImg恢复成空（手动删除），可以实现图片的删除。

    >![](public_sys-resources/icon-note.gif) **说明：** 
    >图片路径不支持中文路径并且路径不能输入空格。

    **图 3**  添加图片<a name="zh-cn_topic_0000002365940062_fig1150615503413"></a>  
    ![](figures/添加图片-2.png "添加图片-2")

-   选中画布内的ToggleButton组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002365941142.png)样式图标（Events），在展开的Events栏中配置回调事件。

    ToggleButton组件支持的事件有OnClick、OnLongPress、OnPress、OnCancel、OnRelease和OnChange。

    **图 4**  回调事件配置<a name="zh-cn_topic_0000002365940062_fig560310204504"></a>  
    ![](figures/回调事件配置-3.png "回调事件配置-3")

>![](public_sys-resources/icon-note.gif) **说明：** 
>General页面下的，MarginBottom属性、MarginRight属性暂无渲染效果。

#### CheckBox组件<a name="ZH-CN_TOPIC_0000002412436913"></a>

共有属性使用方法请参见“[组件的共有属性](组件的共有属性.md#ZH-CN_TOPIC_0000002378717660)”章节内容。

-   选中画布内的CheckBox组件，在已经添加图片的前提下，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002366101018.png)样式图标（Feature），在展开的Feature栏中修改CheckBox组件的ImageOpacity属性修改图片透明度。

    **图 1**  修改图片透明度<a name="zh-cn_topic_0000002399739745_fig2853208115915"></a>  
    ![](figures/修改图片透明度-4.png "修改图片透明度-4")

-   选中CheckBox组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002365941146.png)样式图标（Feature），在展开的Feature栏中修改CheckBox组件的State属性改变组件的状态，当属性值为Selected时为选中状态，反之为未选中状态。

    **图 2**  修改组件状态<a name="zh-cn_topic_0000002399739745_fig3771124145810"></a>  
    ![](figures/修改组件状态-5.png "修改组件状态-5")

-   选中CheckBox组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002366101022.png)样式图标（Feature），在展开的Feature栏中修改CheckBox组件的UnSelectedImg属性添加未选中时的图片和SelectedImg属性添加选中时的图片，两张图片必选同时存在才会产生渲染效果，通过将属性UnSelectedImg和SelectedImg恢复成空（手动删除），可以实现图片的删除。。

    >![](public_sys-resources/icon-note.gif) **说明：** 
    >图片路径不支持中文路径并且路径不能输入空格。

    **图 3**  添加图片<a name="zh-cn_topic_0000002399739745_fig1581184025416"></a>  
    ![](figures/添加图片-6.png "添加图片-6")

-   选中画布内的CheckBox组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002365941150.png)样式图标（Events），在展开的Events栏中配置回调事件。

    CheckBox组件支持的事件有OnClick、OnLongPress、OnPress、OnCancel、OnRelease和OnChange。

    **图 4**  回调事件配置<a name="zh-cn_topic_0000002399739745_fig15393131421110"></a>  
    ![](figures/回调事件配置-7.png "回调事件配置-7")

>![](public_sys-resources/icon-note.gif) **说明：** 
>General页面下的，MarginTop属性、MarginRight属性无渲染效果。

#### RadioButton组件<a name="ZH-CN_TOPIC_0000002378717668"></a>

共有属性使用方法详见[组件的共有属性](组件的共有属性.md#ZH-CN_TOPIC_0000002378717660)。

-   选中画布内的RadioButton组件，在已经添加图片的前提下，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002366101026.png)样式图标（Feature），在展开的Feature栏中修改RadioButton组件的ImageOpacity属性修改图片透明度。

    **图 1**  修改图片透明度<a name="zh-cn_topic_0000002366099962_fig2853208115915"></a>  
    ![](figures/修改图片透明度-8.png "修改图片透明度-8")

-   选中RadioButton组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002365941158.png)样式图标（Feature），在展开的Feature栏中修改RadioButton组件的State改变组件的状态，当属性值为Selected时为选中状态，反之为未选中状态。

    **图 2**  修改组件状态<a name="zh-cn_topic_0000002366099962_fig82077222339"></a>  
    ![](figures/修改组件状态-9.png "修改组件状态-9")

-   选中RadioButton组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002366101034.png)样式图标（Feature），在展开的Feature栏中修改RadioButton组件的SelectedImg属性添加选中时的图片和UnSelectedImg属性添加未选中时的图片，两张图片必须同时存在才会产生渲染效果，通过将SelectedImg和UnSelectedImg属性恢复成空（手动删除），可以实现图片的删除。

    **图 3**  添加图片效果展示<a name="zh-cn_topic_0000002366099962_fig02076225333"></a>  
    ![](figures/添加图片效果展示.png "添加图片效果展示")

    >![](public_sys-resources/icon-note.gif) **说明：** 
    >SelectedImg属性和UnSelectedImg属性不支持中文路径。

-   选中画布内的RadioButton组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002365941162.png)样式图标（Events），在展开的Events栏中配置回调事件。

    RadioButton组件支持的事件有OnClick、OnLongPress、OnPress、OnCancel、OnRelease和OnChange。

    **图 4**  回调事件配置<a name="zh-cn_topic_0000002366099962_fig14875143917147"></a>  
    ![](figures/回调事件配置-10.png "回调事件配置-10")

>![](public_sys-resources/icon-note.gif) **说明：** 
>-   General页面下的MarginBottom属性和MarginRight属性无渲染效果。
>-   Feature页面下的Name属性没有任何界面渲染效果。当界面上有2个组件，并且Name属性一样时，模拟器才可以实现状态的切换。

#### LabelButton组件<a name="ZH-CN_TOPIC_0000002412317065"></a>

共有属性使用方法请参见“[组件的共有属性](组件的共有属性.md#ZH-CN_TOPIC_0000002378717660)”章节内容。

-   选中LabelButton组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002366101038.png)样式图标（Feature），在展开的Feature栏中修改LabelButton组件的ImageOpacity属性可以修改图片的透明度。

    **图 1**  修改图片透明度<a name="zh-cn_topic_0000002399619877_fig59341711182514"></a>  
    ![](figures/修改图片透明度-11.png "修改图片透明度-11")

-   选中LabelButton组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002365941166.png)样式图标（Feature），在展开的Feature栏中修改LabelButton组件的ImageX属性和ImageY属性可以对图片的位置进行调整。

    **图 2**  修改ImageX属性和ImageY属性的效果<a name="zh-cn_topic_0000002399619877_fig1747911404612"></a>  
    ![](figures/修改ImageX属性和ImageY属性的效果.png "修改ImageX属性和ImageY属性的效果")

-   选中LabelButton组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002366101042.png)样式图标（Feature），在展开的Feature栏中修改LabelButton组件的Text属性添加文本。

    **图 3**  添加文本<a name="zh-cn_topic_0000002399619877_fig115151856956"></a>  
    ![](figures/添加文本.png "添加文本")

-   选中LabelButton组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002365941170.png)样式图标（Feature），在展开的Feature栏中设置LabelButton组件的Font属性：

    -   Color：字体颜色
    -   FontSize：字体大小
    -   TextDirection：文本方向

    **图 4**  文本相关属性<a name="zh-cn_topic_0000002399619877_fig11349122424720"></a>  
    ![](figures/文本相关属性.png "文本相关属性")

-   选中LabelButton组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002366101046.png)样式图标（Feature），在展开的Feature栏中修改LabelButton组件的Text Xoffset属性和Text Yoffset属性对文字的位置进行调整。

    **图 5**  对文字位置进行调整<a name="zh-cn_topic_0000002399619877_fig335933815438"></a>  
    ![](figures/对文字位置进行调整.png "对文字位置进行调整")

-   选中LabelButton组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002365941186.png)样式图标（Feature），在展开的Feature栏中修改LabelButton组件的TextAlign属性对文字的水平的对齐方式进行调整。

    **图 6**  修改文字的对齐方式<a name="zh-cn_topic_0000002399619877_fig0812161817195"></a>  
    ![](figures/修改文字的对齐方式.png "修改文字的对齐方式")

-   选中LabelButton组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002366101066.png)样式图标（Feature），在展开的Feature栏中修改LabelButton组件的DefaultImgSrc属性可以添加图片，通过将属性DefaultImgSrc恢复成空（手动删除），可以实现图片的删除。

    **图 7**  添加图片<a name="zh-cn_topic_0000002399619877_fig245413171610"></a>  
    ![](figures/添加图片-12.png "添加图片-12")

    >![](public_sys-resources/icon-note.gif) **说明：** 
    >DefaultImgSrc属性不支持中文路径。

-   选中画布内的LabelButton组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002365941198.png)样式图标（Events），在展开的Events栏中配置回调事件。

    LabelButton组件支持的事件有OnClick、OnLongPress、OnPress、OnCancel和OnRelease。

    **图 8**  回调事件配置<a name="zh-cn_topic_0000002399619877_fig1068120358476"></a>  
    ![](figures/回调事件配置-13.png "回调事件配置-13")

>![](public_sys-resources/icon-note.gif) **说明：** 
>-   General页面下的MarginBottom属性和MarginRight属性没有任何的渲染效果。
>-   Feature页面下的TriggeredImgSrc属性、TriggeredBackgroundColor属性、TriggeredborderColor属性没有任何界面渲染效果，可在模拟器上查看效果。

#### ScrollView组件<a name="ZH-CN_TOPIC_0000002378877508"></a>

共有属性使用方法请参见“[组件的共有属性](组件的共有属性.md#ZH-CN_TOPIC_0000002378717660)”章节内容。

-   选中组件栏中的其他组件，可以将其拖入ScrollView组件中，并且对其他组件进行样式调整。子组件的位置是相对于父容器的左上角，当组件已经存在于界面上时，点击组件中心位置可以将组件拖入容器中。

    **图 1**  将其他组件拖入ScrollView组件中<a name="zh-cn_topic_0000002365940066_fig192648563920"></a>  
    ![](figures/将其他组件拖入ScrollView组件中.png "将其他组件拖入ScrollView组件中")

-   选中ScrollView组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399621001.png)样式图标（Feature），在展开的Feature栏中修改ScrollView组件的Direction属性可以控制组件哪个方向可以滚动。

    **图 2**  修改组件状态<a name="zh-cn_topic_0000002365940066_fig1335145711333"></a>  
    ![](figures/修改组件状态-14.png "修改组件状态-14")

-   选中画布内的ScrollView组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002399740877.png)样式图标（Events），在展开的Events栏中配置回调事件。

    ScrollView组件支持的事件有OnDrag、OnDragStart、OnDragEnd、OnFocus、OnBlur和OnScroll。

    **图 3**  回调事件配置<a name="zh-cn_topic_0000002365940066_fig159041157202714"></a>  
    ![](figures/回调事件配置-15.png "回调事件配置-15")

>![](public_sys-resources/icon-note.gif) **说明：** 
>-   当其他组件不是直接从左侧UI Control栏拖入时可能会发生其他组件出现在ScrollView组件外面且无法看到的情况，并且当多次从左侧UI Control栏拖入组件时，他们会重复出现在组件（100，100）位置。
>-   General页面下的MarginBottom属性和MarginRight属性没有任何的渲染效果。
>-   Feature页面下的除Direction属性外其他属性均没有界面渲染效果，可在模拟器上查看效果。
>-   ScrollView的滚动条一直处于隐藏状态仍保持正常的拖拽方式。

#### CircleProgress组件<a name="ZH-CN_TOPIC_0000002412436917"></a>

共有属性使用方法请参见“[组件的共有属性](组件的共有属性.md#ZH-CN_TOPIC_0000002378717660)”章节内容。

-   选中画布内的CircleProgress组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002399621005.png)样式图标（Feature），在展开的Feature栏中修改CircleProgress组件的ForegroundStyle和BackgroundStyle窗口中LineWidth属性改变进度条宽度；修改LineColor属性改变进度条颜色。

    **图 1**  修改进度条宽度<a name="zh-cn_topic_0000002399739749_fig815243422317"></a>  
    ![](figures/修改进度条宽度.png "修改进度条宽度")

    **图 2**  修改进度条颜色<a name="zh-cn_topic_0000002399739749_fig969345712413"></a>  
    ![](figures/修改进度条颜色.png "修改进度条颜色")

-   选中画布内的CircleProgress组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002366101078.png)样式图标（Feature），在展开的Feature栏中修改CircleProgress组件的RangeMax和RangeMin用来限制进度条的value，修改value来改变进度值。

    **图 3**  修改进度值<a name="zh-cn_topic_0000002399739749_fig762919369274"></a>  
    ![](figures/修改进度值.png "修改进度值")

-   选中画布内的CircleProgress组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002365941210.png)样式图标（Feature），在展开的Feature栏中修改CircleProgress组件的Radius和CenterX属性和CenterY用来限定圆环。

    **图 4**  修改圆环大小<a name="zh-cn_topic_0000002399739749_fig1581711211515"></a>  
    ![](figures/修改圆环大小.png "修改圆环大小")

-   选中画布内的CircleProgress组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002366101082.png)样式图标（Feature），在展开的Feature栏中修改CircleProgress组件的StartAngel和EndAngel属性用来限制绘制角度。

    **图 5**  修改角度<a name="zh-cn_topic_0000002399739749_fig1267654717373"></a>  
    ![](figures/修改角度.png "修改角度")

-   选中画布内的CircleProgress组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002365941214.png)样式图标（Feature），在展开的Feature栏中修改CircleProgress组件的ForeImage或者BackImage的子属性来添加前景或者背景图片并且修改图片位置。

    >![](public_sys-resources/icon-note.gif) **说明：** 
    >图片路径不支持中文路径并且路径不能输入空格。

    **图 6**  添加图片<a name="zh-cn_topic_0000002399739749_fig836417515157"></a>  
    ![](figures/添加图片-16.png "添加图片-16")

>![](public_sys-resources/icon-note.gif) **说明：** 
>-   General页面下的MarginBottom属性、MarginRight属性无渲染效果。
>-   Feature页面下的ForegroundStyle和BackgroundStyle的子属性BackgroundColor、BorderWidth、BorderColor、BorderRadius、LineHeight、ImageOpacity无渲染效果。
>-   CircleProgress组件不支持回调事件配置。

#### ArcLabel组件<a name="ZH-CN_TOPIC_0000002378717672"></a>

本组件的共有属性不包含Position属性与Size属性，其他共有属性使用方法请参见“[组件的共有属性](组件的共有属性.md#ZH-CN_TOPIC_0000002378717660)”章节内容。

-   选中画布内的ArcLabel组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002366101086.png)样式图标（Feature），在展开的Feature栏中修改ArcLabel组件的LetterSpace属性来修改文本之间的间隔。

    **图 1**  修改文字颜色<a name="zh-cn_topic_0000002366099966_fig19959125910167"></a>  
    ![](figures/修改文字颜色.png "修改文字颜色")

-   选中画布内的ArcLabel组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002365941218.png)样式图标（Feature），在展开的Feature栏中修改ArcLabel组件的TextAlign属性改变文本在圆环上的对齐方式。

    **图 2**  文本对齐方式修改<a name="zh-cn_topic_0000002366099966_fig6210165422115"></a>  
    ![](figures/文本对齐方式修改.png "文本对齐方式修改")

-   选中画布内的ArcLabel组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002366101094.png)样式图标（Feature），在展开的Feature栏中修改ArcLabel组件的Text属性来改变显示的文本。

    **图 3**  显示文本的修改<a name="zh-cn_topic_0000002366099966_fig10896149152219"></a>  
    ![](figures/显示文本的修改.png "显示文本的修改")

-   选中画布内的ArcLabel组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002365941222.png)样式图标（Feature），在展开的Feature栏中修改ArcLabel组件的TextColor属性来修改文字的颜色。

    **图 4**  修改文字颜色<a name="zh-cn_topic_0000002366099966_fig181046357190"></a>  
    ![](figures/修改文字颜色-17.png "修改文字颜色-17")

-   选中画布内的ArcLabel组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002366101098.png)样式图标（Feature），在展开的Feature栏中修改ArcLabel组件的TextSize改变文本中文字的大小。

    **图 5**  文本中文字大小修改<a name="zh-cn_topic_0000002366099966_fig13754615153218"></a>  
    ![](figures/文本中文字大小修改.png "文本中文字大小修改")

-   选中画布内的ArcLabel组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002365941230.png)样式图标（Feature），在展开的Feature栏中修改ArcLabel组件的CenterX、CenterY属性改变文字所在圆的圆心位置。

    **图 6**  文本所在圆圆心修改<a name="zh-cn_topic_0000002366099966_fig16333532113418"></a>  
    ![](figures/文本所在圆圆心修改.png "文本所在圆圆心修改")

-   选中画布内的ArcLabel组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002366101102.png)样式图标（Feature），在展开的Feature栏中修改ArcLabel组件的TextRadius改变文字所在圆的半径。

    **图 7**  文本所在圆半径修改<a name="zh-cn_topic_0000002366099966_fig13296111602013"></a>  
    ![](figures/文本所在圆半径修改.png "文本所在圆半径修改")

-   选中画布内的ArcLabel组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002365941234.png)样式图标（Feature），在展开的Feature栏中修改ArcLabel组件的StartAngle、EndAngle属性改变文本在圆中出现的范围。

    **图 8**  文本出现在圆上的范围修改<a name="zh-cn_topic_0000002366099966_fig1867192510273"></a>  
    ![](figures/文本出现在圆上的范围修改.png "文本出现在圆上的范围修改")

-   选中画布内的ArcLabel组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002366101106.png)样式图标（Feature），在展开的Feature栏中修改ArcLabel组件的TextOrientation改变文本的朝向。

    **图 9**  文本朝向修改<a name="zh-cn_topic_0000002366099966_fig035742622712"></a>  
    ![](figures/文本朝向修改.png "文本朝向修改")

>![](public_sys-resources/icon-note.gif) **说明：** 
>-   General页面下的MarginBottom属性和MarginRight属性无任何渲染效果。
>-   ArcLabel组件不支持回调事件配置。

#### SwipeView组件<a name="ZH-CN_TOPIC_0000002412317069"></a>

本组件的共有属性不包含Border属性、Margin属性与Padding属性，其他共有属性使用方法请参见“[组件的共有属性](组件的共有属性.md#ZH-CN_TOPIC_0000002378717660)”章节内容。

-   选中SwipeView组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002365941238.png)样式图标（Feature），在展开的Feature栏中修改SwipeView组件的Direction属性改变组件的滚动方向。子组件的位置是相对于父容器的左上角，当组件已经存在于界面上时，点击组件中心位置可以将组件拖入容器中。

    **图 1**  修改滚动条位置<a name="zh-cn_topic_0000002399619881_fig85221029131212"></a>  
    ![](figures/修改滚动条位置.png "修改滚动条位置")

    ![](figures/1.png)

    >![](public_sys-resources/icon-note.gif) **说明：** 
    >滚动条已被隐藏，当空间内的子组件超出范围时可拖动，HORIZONTAL是水平滚动，VERTICAL是垂直滚动。

-   选中画布内的SwipeView组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002399621041.png)样式图标（Events），在展开的Events栏中配置回调事件。

    SwipeView组件支持的事件有：OnDrag、OnDragStart、OnDragEnd、OnSwipe。

    **图 2**  回调事件配置<a name="zh-cn_topic_0000002399619881_fig968711173355"></a>  
    ![](figures/回调事件配置-18.png "回调事件配置-18")

>![](public_sys-resources/icon-note.gif) **说明：** 
>-   Feature页面下的Isloop属性、AlignMode属性、TickTime属性暂无渲染效果。
>-   在水平模式下上方工具栏的顶部对齐![](figures/zh-cn_image_0000002399740917.png)、底部对齐![](figures/zh-cn_image_0000002366101114.png)、上下居中对齐![](figures/zh-cn_image_0000002399621045.png)不可用。
>-   在垂直模式下上方工具栏的左对齐![](figures/zh-cn_image_0000002365941246.png)、右对齐![](figures/zh-cn_image_0000002399740925.png)、左右居中对齐![](figures/zh-cn_image_0000002366101122.png)不可用。
>-   SwipeView的滚动条一直处于隐藏状态仍保持正常的拖拽方式。

#### TextureMapper组件<a name="ZH-CN_TOPIC_0000002378877512"></a>

共有属性使用方法请参见“[组件的共有属性](组件的共有属性.md#ZH-CN_TOPIC_0000002378717660)”章节内容。

-   选中TextureMapper组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399621069.png)样式图标（Feature），在展开的Feature栏通过修改TextureMapper组件的ImagePath属性添加图片，通过将ImagePath属性恢复成空（手动删除），可以实现图片的删除。

    **图 1**  添加图片<a name="zh-cn_topic_0000002365940070_fig15600147102714"></a>  
    ![](figures/添加图片-19.png "添加图片-19")

    >![](public_sys-resources/icon-note.gif) **说明：** 
    >ImagePath属性不支持中文路径。

-   选中TextureMapper组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002366101150.png)样式图标（Feature），在展开的Feature栏通过修改TextureMapper组件的ImageOpacity属性修改图片的透明度。

    **图 2**  修改图片透明度<a name="zh-cn_topic_0000002365940070_fig1859224515129"></a>  
    ![](figures/修改图片透明度-20.png "修改图片透明度-20")

-   选中画布内的TextureMapper组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002399740985.png)样式图标（Events），在展开的Events栏中配置回调事件。

    TextureMapper组件支持的事件有OnMapper。

    **图 3**  回调事件配置<a name="zh-cn_topic_0000002365940070_fig833815411471"></a>  
    ![](figures/回调事件配置-21.png "回调事件配置-21")

>![](public_sys-resources/icon-note.gif) **说明：** 
>-   General页面下的MarginBottom属性和MarginRight属性均无渲染效果。
>-   Feature页面下除ImagePath属性外其他属性均没有界面渲染效果，可在模拟器上查看效果。请在展示动画效果前先添加图片并且Feature页面的IsStart属性为true。
>-   组件的大小在添加图片后固定为图片的大小，且修改组件宽高不生效。

#### Slider组件<a name="ZH-CN_TOPIC_0000002412436921"></a>

共有属性使用方法请参见“[组件的共有属性](组件的共有属性.md#ZH-CN_TOPIC_0000002378717660)”章节内容。

-   选中Slider组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399621121.png)样式图标（Feature），在展开的Feature栏中修改Slider组件的SliderValue属性改变滑块的位置。

    **图 1**  修改滑块位置<a name="zh-cn_topic_0000002399739753_fig520210134916"></a>  
    ![](figures/修改滑块位置.png "修改滑块位置")

-   选中Slider组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399741001.png)样式图标（Feature），在展开的Feature栏中修改Slider组件的SliderWidth属性改变滑槽的宽度。

    **图 2**  修改滑槽宽度<a name="zh-cn_topic_0000002399739753_fig19400118164911"></a>  
    ![](figures/修改滑槽宽度.png "修改滑槽宽度")

-   选中Slider组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399621137.png)样式图标（Feature），在展开的Feature栏中修改Slider组件的SliderHeight属性改变滑槽的高度。SliderHeight不能超出边框的高度。

    **图 3**  修改滑槽高度<a name="zh-cn_topic_0000002399739753_fig54931822183517"></a>  
    ![](figures/修改滑槽高度.png "修改滑槽高度")

-   选中Slider组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399741017.png)样式图标（Feature），在展开的Feature栏中修改Slider组件的Direction属性改变滑槽的方向。

    **图 4**  修改滑方向<a name="zh-cn_topic_0000002399739753_fig1164616545365"></a>  
    ![](figures/修改滑方向.png "修改滑方向")

-   选中Slider组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399621145.png)样式图标（Feature），在展开的Feature栏中修改Slider组件的KnobWidth属性改变滑块的宽度。

    **图 5**  修改滑块大小<a name="zh-cn_topic_0000002399739753_fig2041221915013"></a>  
    ![](figures/修改滑块大小.png "修改滑块大小")

-   选中Slider组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399741033.png)样式图标（Feature），在展开的Feature栏中修改Slider组件的BackGroundImage属性改变滑槽的背景图片；修改Slider组件的BackGroundColor属性改变滑槽的背景色。

    >![](public_sys-resources/icon-note.gif) **说明：** 
    >图片路径不支持中文路径并且路径不能输入空格。

    **图 6**  添加图片<a name="zh-cn_topic_0000002399739753_fig20840845145018"></a>  
    ![](figures/添加图片-22.png "添加图片-22")

    **图 7**  设置颜色<a name="zh-cn_topic_0000002399739753_fig1623652355120"></a>  
    ![](figures/设置颜色.png "设置颜色")

-   选中Slider组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002365941362.png)样式图标（Feature），在展开的Feature栏的ForeStyle窗口中修改Slider组件的ForeImg属性改变滑槽的前景图片；修改ForeGroundColor改变滑槽的前景颜色。

    >![](public_sys-resources/icon-note.gif) **说明：** 
    >图片路径不支持中文路径并且路径不能输入空格。

    **图 8**  添加图片<a name="zh-cn_topic_0000002399739753_fig71361938195220"></a>  
    ![](figures/添加图片-23.png "添加图片-23")

    **图 9**  修改背景颜色<a name="zh-cn_topic_0000002399739753_fig53181218398"></a>  
    ![](figures/修改背景颜色-24.png "修改背景颜色-24")

-   选中Slider组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399621173.png)样式图标（Feature），在展开的Feature栏KnobStyle窗口中修改Slider组件的KnobImage属性添加图片；修改KnobBackGroundColor属性改变滑块的颜色；修改KnobRadius属性改变滑块的边框弧度。

    **图 10**  添加图片<a name="zh-cn_topic_0000002399739753_fig4198162695412"></a>  
    ![](figures/添加图片-25.png "添加图片-25")

    >![](public_sys-resources/icon-note.gif) **说明：** 
    >图片路径不支持中文路径并且路径不能输入空格。

    **图 11**  修改背景颜色<a name="zh-cn_topic_0000002399739753_fig561313503547"></a>  
    ![](figures/修改背景颜色-26.png "修改背景颜色-26")

    **图 12**  修改弧度<a name="zh-cn_topic_0000002399739753_fig620717512485"></a>  
    ![](figures/修改弧度.png "修改弧度")

-   选中画布内的Slider组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002365941390.png)样式图标（Events），在展开的Events栏中配置回调事件。

    Slider组件支持的事件有OnClick、OnLongPress、OnDrag、OnDragStart、OnDragEnd、OnPress、OnCancel、OnRelease、OnFocus、OnBlur。

    **图 13**  回调事件配置<a name="zh-cn_topic_0000002399739753_fig325561020"></a>  
    ![](figures/回调事件配置-27.png "回调事件配置-27")

>![](public_sys-resources/icon-note.gif) **说明：** 
>-   General页面下的GaussianBlur属性、MarginBottom属性和MarginRight属性均无渲染效果。
>-   组件的大小在添加图片后固定为图片的大小，且修改组件宽高不生效。

#### Picker组件<a name="ZH-CN_TOPIC_0000002378717676"></a>

共有属性使用方法请参见“[组件的共有属性](组件的共有属性.md#ZH-CN_TOPIC_0000002378717660)”章节内容。

-   选中Picker组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002366101302.png)样式图标（Feature），在展开的Feature栏中修改Picker组件的Normal属性改变组件未选中字体颜色。

    **图 1**  修改未选中字体颜色<a name="zh-cn_topic_0000002366099970_fig19778846182613"></a>  
    ![](figures/修改未选中字体颜色.png "修改未选中字体颜色")

-   选中Picker组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002365941414.png)样式图标（Feature），在展开的Feature栏中修改Picker组件的HighLight属性改变组件选中字体颜色。

    **图 2**  修改选中字体颜色<a name="zh-cn_topic_0000002366099970_fig13923214192715"></a>  
    ![](figures/修改选中字体颜色.png "修改选中字体颜色")

-   选中Picker组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002366101314.png)样式图标（Feature），在展开的Feature栏中修改Picker组件的ItemHeight属性改变组件条目高度。

    **图 3**  修改条目高度<a name="zh-cn_topic_0000002366099970_fig1048834002714"></a>  
    ![](figures/修改条目高度.png "修改条目高度")

-   选中Picker组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002365941430.png)样式图标（Feature），在展开的Feature栏中修改Picker组件的LoopState属性使组件内容循环。

    **图 4**  设置循环<a name="zh-cn_topic_0000002366099970_fig5493192817"></a>  
    ![](figures/设置循环.png "设置循环")

-   选中Picker组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002366101326.png)样式图标（Feature），在展开的Feature栏中修改Picker组件的Values属性改变组件显示文本，数据格式为："x1", "x2", "x3"...（必须带""）

    **图 5**  修改文本<a name="zh-cn_topic_0000002366099970_fig1959462262820"></a>  
    ![](figures/修改文本.png "修改文本")

-   选中Picker组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002365941446.png)样式图标（Feature），在展开的Feature栏中同步Count属性值（必须与输入数组子元素个数相等）。

    **图 6**  添加元素个数值<a name="zh-cn_topic_0000002366099970_fig9995037194619"></a>  
    ![](figures/添加元素个数值.png "添加元素个数值")

-   选中Picker组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002366101334.png)样式图标（Feature），在展开的Feature栏中修改Picker组件的TextDirection属性值改变文本的书写方向。LTR表示文字方向为从左至右，RTL为从右至左。如[图7](#zh-cn_topic_0000002366099970_fig0726183665610)所示，第一个值为“12345”，通过设置TextDirection属性值为RTL后，画布中显示的文字为“54321”。

    **图 7**  修改文本方向<a name="zh-cn_topic_0000002366099970_fig0726183665610"></a>  
    ![](figures/修改文本方向.png "修改文本方向")

-   选中画布内的Picker组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002365941450.png)样式图标（Events），在展开的Events栏中配置回调事件。

    Picker组件支持的事件有OnFocus和OnBlur。

    **图 8**  回调事件配置<a name="zh-cn_topic_0000002366099970_fig325561020"></a>  
    ![](figures/回调事件配置-28.png "回调事件配置-28")

>![](public_sys-resources/icon-note.gif) **说明：** 
>-   General页面下的、MarginBottom属性和MarginRight属性均无渲染效果 。
>-   Count属性值与数组元素个数保持一致。

#### TimePicker组件<a name="ZH-CN_TOPIC_0000002412317073"></a>

共有属性使用方法请参见“[组件的共有属性](组件的共有属性.md#ZH-CN_TOPIC_0000002378717660)”章节内容。

-   选中TimePicker组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002366101338.png)样式图标（Feature），在展开的Feature栏中修改TimePicker组件的ItemHeight属性改变组件条目高度。

    **图 1**  修改条目高度<a name="zh-cn_topic_0000002399619885_fig13492156123017"></a>  
    ![](figures/修改条目高度-29.png "修改条目高度-29")

-   选中TimePicker组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002365941454.png)样式图标（Feature），在展开的Feature栏中修改TimePicker组件的Values属性改变组件显示文本。

    **图 2**  修改文本<a name="zh-cn_topic_0000002399619885_fig1536141613118"></a>  
    ![](figures/修改文本-30.png "修改文本-30")

-   选中TimePicker组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002366101342.png)样式图标（Feature），在展开的Feature栏中修改TimePicker组件的HourLoop属性改变组件小时窗口是否循环。

    **图 3**  设置循环<a name="zh-cn_topic_0000002399619885_fig172573812312"></a>  
    ![](figures/设置循环-31.png "设置循环-31")

-   选中TimePicker组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002365941458.png)样式图标（Feature），在展开的Feature栏中修改TimePicker组件的MinLoop属性改变组件分钟窗口是否循环。

    **图 4**  设置循环<a name="zh-cn_topic_0000002399619885_fig1741193616326"></a>  
    ![](figures/设置循环-32.png "设置循环-32")

-   选中TimePicker组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002366101350.png)样式图标（Feature），在展开的Feature栏中修改TimePicker组件的SecLoop属性改变组件秒窗口是否循环。（在SecShows属性为true情况下）

    **图 5**  设置循环<a name="zh-cn_topic_0000002399619885_fig1031192215331"></a>  
    ![](figures/设置循环-33.png "设置循环-33")

-   选中TimePicker组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002365941462.png)样式图标（Feature），在展开的Feature栏中修改TimePicker组件的NormalColor属性改变组件未选中字体颜色。

    **图 6**  修改字体颜色<a name="zh-cn_topic_0000002399619885_fig689444916334"></a>  
    ![](figures/修改字体颜色.png "修改字体颜色")

-   选中TimePicker组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002366101354.png)样式图标（Feature），在展开的Feature栏中修改TimePicker组件的HighLightColor属性改变组件选中字体颜色。

    **图 7**  修改字体颜色<a name="zh-cn_topic_0000002399619885_fig1820476173413"></a>  
    ![](figures/修改字体颜色-34.png "修改字体颜色-34")

-   选中TimePicker组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002365941466.png)样式图标（Feature），在展开的Feature栏中修改TimePicker组件的SecShow属性设置秒窗口是否显示。

    **图 8**  设置秒窗口显示<a name="zh-cn_topic_0000002399619885_fig732614223349"></a>  
    ![](figures/设置秒窗口显示.png "设置秒窗口显示")

-   选中TimePicker组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002366101358.png)样式图标（Feature），在展开的Feature栏中修改TimePicker组件的BackgroundFontsize属性改变组件未选中字体大小。

    **图 9**  设置字体大小<a name="zh-cn_topic_0000002399619885_fig7257450143415"></a>  
    ![](figures/设置字体大小.png "设置字体大小")

-   选中TimePicker组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002365941470.png)样式图标（Feature），在展开的Feature栏中修改TimePicker组件的HighlightFontsize属性改变组件选中字体大小。

    **图 10**  设置字体大小<a name="zh-cn_topic_0000002399619885_fig1568281294514"></a>  
    ![](figures/设置字体大小-35.png "设置字体大小-35")

-   选中画布内的TimePicker组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002366101362.png)样式图标（Events），在展开的Events栏中配置回调事件。

    TimePicker组件支持的事件有OnFocus和OnBlur。

    **图 11**  回调事件配置<a name="zh-cn_topic_0000002399619885_fig325561020"></a>  
    ![](figures/回调事件配置-36.png "回调事件配置-36")

>![](public_sys-resources/icon-note.gif) **说明：** 
>General页面下的 MarginBottom属性和MarginRight属性均无渲染效果。

#### Chart组件<a name="ZH-CN_TOPIC_0000002378877516"></a>

共有属性使用方法请参见“[组件的共有属性](组件的共有属性.md#ZH-CN_TOPIC_0000002378717660)”章节内容。

-   选中Chart组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002365941478.png)样式图标（Feature），在展开的Feature栏中修改XAxis栏中的属性改变横坐标的样式。

    -   MarkNum属性：改变坐标轴上点的数量
    -   RangMin和RangMax：改变坐标轴的取值范围
    -   Color：改变坐标轴的颜色
    -   Visible：控制坐标轴的可见与否

    **图 1**  修改横坐标属性<a name="zh-cn_topic_0000002365940078_fig8661439164210"></a>  
    ![](figures/修改横坐标属性.png "修改横坐标属性")

-   选中Chart组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399621289.png)样式图标（Feature），在展开的Feature栏中修改YAxis栏中的属性改变纵坐标样式，具体的与横坐标相同，请参考[图2](#zh-cn_topic_0000002365940078_fig16661839194210)。

    **图 2**  修改纵坐标样式<a name="zh-cn_topic_0000002365940078_fig16661839194210"></a>  
    ![](figures/修改纵坐标样式.png "修改纵坐标样式")

-   选中Chart组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399741189.png)样式图标（Feature），在展开的Feature栏中点击DataSerial属性右侧的加号添加数据，可以添加多组数据。

    **图 3**  添加数据<a name="zh-cn_topic_0000002365940078_fig10661113994214"></a>  
    ![](figures/添加数据.png "添加数据")

-   选中Chart组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399621297.png)样式图标（Feature），在展开的Feature栏中添加数据然后改变数据的样式，其中Data属性是要填入的数据，DataCount属性是数据的个数，FillColor是填充渐变色的颜色，LineColor是线的颜色，EnableGradient属性控制是否填充渐变色。

    **图 4**  添加数据效果展示<a name="zh-cn_topic_0000002365940078_fig96611939204217"></a>  
    ![](figures/添加数据效果展示.png "添加数据效果展示")

-   选中Chart组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399741197.png)样式图标（Feature），在展开的Feature栏中ColorGradient窗口中MinOpa和MaxOpa属性改变渐变色的范围，MaxOpa控制上面的渐变色透明度，MinOpa控制下面的渐变色透明度。

    **图 5**  修改透明度渐变色<a name="zh-cn_topic_0000002365940078_fig46611739184215"></a>  
    ![](figures/修改透明度渐变色.png "修改透明度渐变色")

-   选中Chart组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399621305.png)样式图标（Feature），在展开的Feature栏中修改Chart组件的Type属性改变图的类型。

    **图 6**  修改图的类型<a name="zh-cn_topic_0000002365940078_fig19661139164218"></a>  
    ![](figures/修改图的类型.png "修改图的类型")

>![](public_sys-resources/icon-note.gif) **说明：** 
>-   General页面下的MarginBottom属性和MarginRight属性均无渲染效果。
>-   添加数据时的数据的格式为： \{x1,y1\},\{x2,y2\};
>    数据中不能有空格，横坐标应该为从0开始的依次递增的。并且DataCount属性中的数字不能比数据个数小。并且当DataCount属性中的数字比数据个数大时，会自动回连\{0,0\}，柱状图时横坐标的MarkNum也不能比数据个数小。
>-   ColorGradient属性只有在折线图时有用。
>-   目前Chart会有第一次修改DataSerial属性里的属性界面无法发生变化的问题，通过再次修改DataSerial属性中的其他属性的方式可以使界面发生变化。
>-   Chart组件不支持回调事件的配置。

#### EditText组件<a name="ZH-CN_TOPIC_0000002412436925"></a>

共有属性使用方法请参见“[组件的共有属性](组件的共有属性.md#ZH-CN_TOPIC_0000002378717660)”章节内容。

-   选中EditText组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399741209.png)样式图标（Feature），在展开的Feature栏中修改EditText组件的Placeholder属性修改背景提示文字。

    **图 1**  修改背景提示文字<a name="zh-cn_topic_0000002399739757_fig688611508216"></a>  
    ![](figures/修改背景提示文字.png "修改背景提示文字")

-   选中EditText组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399621313.png)样式图标（Feature），在展开的Feature栏中修改EditText组件的Text属性修改前景文字的内容，并且当前景文字存在时无法显示背景文字。

    **图 2**  修改前景文字<a name="zh-cn_topic_0000002399739757_fig18400183213561"></a>  
    ![](figures/修改前景文字.png "修改前景文字")

-   选中EditText组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399741217.png)样式图标（Feature），在展开的Feature栏中修改EditText组件的EditTextColor属性修改前景文字的颜色。

    **图 3**  修改前景文字颜色<a name="zh-cn_topic_0000002399739757_fig581421214573"></a>  
    ![](figures/修改前景文字颜色.png "修改前景文字颜色")

-   选中EditText组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399621333.png)样式图标（Feature），在展开的Feature栏中修改EditText组件的MaxLength属性来限制前景文字输入长度。

    **图 4**  限制前景文字长度<a name="zh-cn_topic_0000002399739757_fig8651102555710"></a>  
    ![](figures/限制前景文字长度.png "限制前景文字长度")

-   选中EditText组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399741233.png)样式图标（Feature），在展开的Feature栏中修改EditText组件的InputType属性来改变输入模式。

    -   text模式：输入的文本正常显示
    -   password模式：输入的文本以密码模式显示（被“·”代替）

    **图 5**  改变输入模式<a name="zh-cn_topic_0000002399739757_fig13869958175715"></a>  
    ![](figures/改变输入模式.png "改变输入模式")

-   选中EditText组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399621357.png)样式图标（Feature），在展开的Feature栏中修改EditText组件的PlaceholderColor属性修改背景提示文字的颜色。

    **图 6**  修改背景提示文字颜色<a name="zh-cn_topic_0000002399739757_fig1530813191564"></a>  
    ![](figures/修改背景提示文字颜色.png "修改背景提示文字颜色")

-   选中EditText组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399741261.png)样式图标（Feature），在展开的Feature栏中修改EditText组件的CursorColor属性来光标的颜色。

    **图 7**  光标颜色<a name="zh-cn_topic_0000002399739757_fig14857161318582"></a>  
    ![](figures/光标颜色.png "光标颜色")

-   选中画布内的EditText组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002399621385.png)样式图标（Events），在展开的Events栏中配置回调事件。

    EditText组件支持的事件有OnClick、OnLongPress、OnPress、OnCancel、OnRelease。

    **图 8**  回调事件配置<a name="zh-cn_topic_0000002399739757_fig325561020"></a>  
    ![](figures/回调事件配置-37.png "回调事件配置-37")

>![](public_sys-resources/icon-note.gif) **说明：** 
>-   General页面下的MarginBottom属性和MarginRight属性均无渲染效果。
>-   文字修改只能通过右侧的特有属性进行，在界面上通过键盘删除文字时会出现将组件删除的问题，修改前景文本请通过右侧的Text文本进行。

#### DigitalClock组件<a name="ZH-CN_TOPIC_0000002378717680"></a>

共有属性使用方法请参见“[组件的共有属性](组件的共有属性.md#ZH-CN_TOPIC_0000002378717660)”章节内容。

-   选中DigitalClock组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399741285.png)样式图标（Feature），在展开的Feature栏中修改DigitalClock组件的Color属性改变字体颜色。

    **图 1**  修改字体颜色<a name="zh-cn_topic_0000002366099978_fig28061923305"></a>  
    ![](figures/修改字体颜色-38.png "修改字体颜色-38")

-   选中DigitalClock组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399621393.png)样式图标（Feature），在展开的Feature栏中修改DigitalClock组件的DisplayMode属性改变组件显示状态。

    **图 2**  组件显示状态<a name="zh-cn_topic_0000002366099978_fig13710344441"></a>  
    ![](figures/组件显示状态.png "组件显示状态")

-   选中DigitalClock组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399741297.png)样式图标（Feature），在展开的Feature栏中修改DigitalClock组件的DisplayLeadigZero属性设置是否在小时前面加0。

    **图 3**  是否添加0<a name="zh-cn_topic_0000002366099978_fig9371123494418"></a>  
    ![](figures/是否添加0.png "是否添加0")

-   选中DigitalClock组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399621397.png)样式图标（Feature），在展开的Feature栏中修改DigitalClock组件的Hour属性设置小时。

    **图 4**  设置小时<a name="zh-cn_topic_0000002366099978_fig67661353475"></a>  
    ![](figures/设置小时.png "设置小时")

-   选中DigitalClock组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399741301.png)样式图标（Feature），在展开的Feature栏中修改DigitalClock组件的Minute属性设置分钟。

    **图 5**  设置分钟<a name="zh-cn_topic_0000002366099978_fig711219924715"></a>  
    ![](figures/设置分钟.png "设置分钟")

-   选中DigitalClock组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399621401.png)样式图标（Feature），在展开的Feature栏中修改DigitalClock组件的Second属性设置秒。

    **图 6**  设置秒<a name="zh-cn_topic_0000002366099978_fig177318106475"></a>  
    ![](figures/设置秒.png "设置秒")

>![](public_sys-resources/icon-note.gif) **说明：** 
>-   General页面下的MarginBottom属性和MarginRight属性均无渲染效果。
>-   DigitalClock不支持回调事件的配置。

#### ImageAnimator组件<a name="ZH-CN_TOPIC_0000002412317077"></a>

共有属性使用方法请参见“[组件的共有属性](组件的共有属性.md#ZH-CN_TOPIC_0000002378717660)”章节内容。

-   选中ImageAnimator组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399741305.png)样式图标（Feature），在展开的Feature栏中添加图片路径。

    **图 1**  图片路径<a name="zh-cn_topic_0000002399619889_fig28061923305"></a>  
    ![](figures/图片路径.png "图片路径")

-   选中ImageAnimator组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399621409.png)样式图标（Feature），在展开的Feature栏中修改ImageAnimator组件的ImageNum属性保证显示图片的个数与输入图片路径的个数相等。

    **图 2**  图片的个数<a name="zh-cn_topic_0000002399619889_fig13710344441"></a>  
    ![](figures/图片的个数.png "图片的个数")

-   选中ImageAnimator组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399741313.png)样式图标（Feature），在展开的Feature栏中修改ImageAnimator组件的Times属性控制循环次数。该属性只有在Repeat为false情况下生效。

    **图 3**  循环次数<a name="zh-cn_topic_0000002399619889_fig9371123494418"></a>  
    ![](figures/循环次数.png "循环次数")

-   选中ImageAnimator组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399621413.png)样式图标（Feature），在展开的Feature栏中修改ImageAnimator组件的Fixed属性用来适应图片大小。

    **图 4**  是否适应图片大小<a name="zh-cn_topic_0000002399619889_fig67661353475"></a>  
    ![](figures/是否适应图片大小.png "是否适应图片大小")

-   选中ImageAnimator组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399741317.png)样式图标（Feature），在展开的Feature栏中修改ImageAnimator组件的Repeat属性控制图片是否循环。

    **图 5**  设置图片是否循环<a name="zh-cn_topic_0000002399619889_fig711219924715"></a>  
    ![](figures/设置图片是否循环.png "设置图片是否循环")

-   选中ImageAnimator组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399621417.png)样式图标（Feature），在展开的Feature栏中修改ImageAnimator组件的Reverse属性设置图片循环方向。

    **图 6**  设置图片循环方向<a name="zh-cn_topic_0000002399619889_fig137012812132"></a>  
    ![](figures/设置图片循环方向.png "设置图片循环方向")

-   选中ImageAnimator组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399741321.png)样式图标（Feature），在展开的Feature栏中修改ImageAnimator组件的FillMode属性设置动画最后一帧显示的图片，true为当前循环模式下动画的第一张图片，false为最后一张。其中，Reverse属性值影响循环动画的图片先后顺序。

    **图 7**  设置最后一帧<a name="zh-cn_topic_0000002399619889_fig142541859122517"></a>  
    ![](figures/设置最后一帧.png "设置最后一帧")

>![](public_sys-resources/icon-note.gif) **说明：** 
>-   General页面下的MarginBottom属性和MarginRight属性均无渲染效果。
>-   Feature页面下的TimeOfUpdate属性和TimeOfPause属性无渲染效果。
>-   ImageAnimator组件不支持回调事件的配置。

#### Qrcode组件<a name="ZH-CN_TOPIC_0000002378877520"></a>

共有属性使用方法请参见“[组件的共有属性](组件的共有属性.md#ZH-CN_TOPIC_0000002378717660)”章节内容。

-   选中画布内的Qrcode组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399621421.png)样式图标（Feature），在展开的Feature栏中修改Qrcode组件的ImageOpacity属性来修改二维码的透明度。

    **图 1**  修改二维码透明度<a name="zh-cn_topic_0000002365940082_fig19959125910167"></a>  
    ![](figures/修改二维码透明度.png "修改二维码透明度")

-   选中画布内的Qrcode组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002399741325.png)样式图标（Feature），在展开的Feature栏中修改Qrcode组件的BackColor属性修改二维码的背景颜色。

    **图 2**  修改背景色<a name="zh-cn_topic_0000002365940082_fig6210165422115"></a>  
    ![](figures/修改背景色-39.png "修改背景色-39")

-   选中画布内的Qrcode组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002399621425.png)样式图标（Feature），在展开的Feature栏中修改Qrcode组件的QrcodeColor属性修改二维码的颜色。

    **图 3**  修改二维码颜色<a name="zh-cn_topic_0000002365940082_fig10896149152219"></a>  
    ![](figures/修改二维码颜色.png "修改二维码颜色")

>![](public_sys-resources/icon-note.gif) **说明：** 
>-   General页面下的BackgroungColor属性、MarginBottom属性和MarginRight属性均无渲染效果。
>-   Feature页面下的Text属性无界面渲染效果，具体效果可在模拟器查看。
>-   Qrcode组件不支持回调事件的配置。

#### AnalogClock组件<a name="ZH-CN_TOPIC_0000002412436929"></a>

共有属性使用方法请参见“[组件的共有属性](组件的共有属性.md#ZH-CN_TOPIC_0000002378717660)”章节内容。

-   选中AnalogClock组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399741329.png)样式图标（Feature），在展开的Feature栏中修改Hour窗口中的PositionX属性和PositionY属性来修改时针的位置，同时对于Minute窗口和Second窗口中的PositionX属性和PositionY属性是可以分别修改分针和秒针的位置。

    **图 1**  修改指针的位置<a name="zh-cn_topic_0000002399739761_fig678011363619"></a>  
    ![](figures/修改指针的位置.png "修改指针的位置")

-   选中AnalogClock组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399621429.png)样式图标（Feature），在展开的Feature栏中修改Hour窗口中的CenterX属性和CenterY属性来修改时针的旋转中心（这个坐标是以PositionX和PositionY所在点为原点的坐标系下的坐标），这个坐标是相对于表针的位置而非组件的左上角，同时对于Minute窗口和Second窗口中的CenterX属性和CenterY属性是可以分别修改分针和秒针的的旋转中心。

    **图 2**  修改指针的旋转中心<a name="zh-cn_topic_0000002399739761_fig821320214408"></a>  
    ![](figures/修改指针的旋转中心.png "修改指针的旋转中心")

-   选中AnalogClock组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399741333.png)样式图标（Feature），在展开的Feature栏中修改Hour窗口中的Color属性来修改时针的颜色，同时对于Minute窗口和Second窗口中的Color属性是可以分别修改分针和秒针的颜色。

    **图 3**  修改指针的颜色<a name="zh-cn_topic_0000002399739761_fig16383193311422"></a>  
    ![](figures/修改指针的颜色.png "修改指针的颜色")

-   选中AnalogClock组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399621433.png)样式图标（Feature），在展开的Feature栏中修改Hour窗口中的Width属性来修改时针的宽度，同时对于Minute窗口和Second窗口中的Width属性是可以分别修改分针和秒针的宽度。

    **图 4**  修改指针的宽度<a name="zh-cn_topic_0000002399739761_fig133511819144416"></a>  
    ![](figures/修改指针的宽度.png "修改指针的宽度")

-   选中AnalogClock组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399741337.png)样式图标（Feature），在展开的Feature栏中修改Hour窗口中的Length属性来修改时针的长度，同时对于Minute窗口和Second窗口中的Length属性是可以分别修改分针和秒针的的长度。

    **图 5**  修改指针的长度<a name="zh-cn_topic_0000002399739761_fig189181575451"></a>  
    ![](figures/修改指针的长度.png "修改指针的长度")

-   选中AnalogClock组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399621437.png)样式图标（Feature），在展开的Feature栏中修改Hour窗口中的Opacity属性来修改时针的颜色透明度，同时对于Minute窗口和Second窗口中的Opacity属性是可以分别修改分针和秒针的的颜色透明度。

    **图 6**  修改指针的颜色透明度<a name="zh-cn_topic_0000002399739761_fig1717814924613"></a>  
    ![](figures/修改指针的颜色透明度.png "修改指针的颜色透明度")

-   选中AnalogClock组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399741341.png)样式图标（Feature），在展开的Feature栏中修改Hour窗口中的LineImage属性来为时针添加图片，同时对于Minute窗口和Second窗口中的LineImage属性是可以分别为分针和秒针添加图片。

    **图 7**  为指针添加图片<a name="zh-cn_topic_0000002399739761_fig194842357484"></a>  
    ![](figures/为指针添加图片.png "为指针添加图片")

    >![](public_sys-resources/icon-note.gif) **说明：** 
    >LineImage属性不支持中文路径。

-   选中AnalogClock组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399621445.png)样式图标（Feature），在展开的Feature栏中修改AnalogClock组件的NewMode属性来控制秒针的显示。

    **图 8**  控制秒针的显示<a name="zh-cn_topic_0000002399739761_fig7341154611512"></a>  
    ![](figures/控制秒针的显示.png "控制秒针的显示")

-   选中画布内的AnalogClock组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002399741345.png)样式图标（Events），在展开的Events栏中配置回调事件。

    AnalogClock组件支持的事件有OnClick、OnLongPress、OnPress、OnCancel和OnRelease。

    **图 9**  回调事件配置<a name="zh-cn_topic_0000002399739761_fig052871717486"></a>  
    ![](figures/回调事件配置-40.png "回调事件配置-40")

-   选中组件栏中的其他组件，可以将其拖入AnalogClock组件中，并且对其他组件进行样式调整。子组件的位置是相对于父容器的左上角，当组件已经存在于界面上时，点击组件中心位置可以将组件拖入容器中。

    **图 10**  将其他组件拖入AnalogClock组件中<a name="zh-cn_topic_0000002399739761_fig192648563920"></a>  
    ![](figures/将其他组件拖入AnalogClock组件中.png "将其他组件拖入AnalogClock组件中")

>![](public_sys-resources/icon-note.gif) **说明：** 
>-   General页面下的MarginBottom属性和MarginRight属性均无渲染效果。
>-   Feature页面下的Am属性无界面渲染效果。

#### SweepClock组件<a name="ZH-CN_TOPIC_0000002378717684"></a>

本组件包含了AnalogClock组件的所有属性，与其类似；因此相同的属性就不在此介绍，请参见“[AnalogClock组件](AnalogClock组件.md#ZH-CN_TOPIC_0000002412436929)”描述。

-   选中SweepClock组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002365941658.png)样式图标（Feature），在展开的Feature栏中修改Hour窗口中的CenterImage属性，为时针中心点添加图片，同时对于Minute窗口和Second窗口中的CenterImage属性是可以分别修改分针和秒针的中心点添加图片。

    **图 1**  为中心圆圈添加图片<a name="zh-cn_topic_0000002366099982_fig194842357484"></a>  
    ![](figures/为中心圆圈添加图片.png "为中心圆圈添加图片")

    >![](public_sys-resources/icon-note.gif) **说明：** 
    >CenterImage属性不支持中文路径。

-   选中SweepClock组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002366101542.png)样式图标（Feature），在展开的Feature栏中修改Hour窗口中的CenterImageX属性和CenterImageY属性，修改时针中心图片的位置，同时对于Minute窗口和Second窗口中的CenterImage属性是可以分别修改分针和秒针的中心图片的位置。

    **图 2**  控制秒针的显示<a name="zh-cn_topic_0000002366099982_fig7341154611512"></a>  
    ![](figures/控制秒针的显示-41.png "控制秒针的显示-41")

-   选中组件栏中的其他组件，可以将其拖入SweepClock组件中，并且对其他组件进行样式调整。子组件的位置是相对于父容器的左上角，当组件已经存在于界面上时，点击组件中心位置可以将组件拖入容器中。

    **图 3**  将其他组件拖入SweepClock组件中<a name="zh-cn_topic_0000002366099982_fig192648563920"></a>  
    ![](figures/将其他组件拖入SweepClock组件中.png "将其他组件拖入SweepClock组件中")

>![](public_sys-resources/icon-note.gif) **说明：** 
>-   General页面下的MarginBottom属性和MarginRight属性均无渲染效果。
>-   Feature页面下的Am属性无界面渲染效果。
>-   SweepClock不支持不支持回调事件的配置。

#### Coverflow组件<a name="ZH-CN_TOPIC_0000002412317081"></a>

本组件的共有属性不包含Border属性、Margin属性与Padding属性，其他共有属性使用方法请参见“[组件的共有属性](组件的共有属性.md#ZH-CN_TOPIC_0000002378717660)”章节内容。

-   选中Coverflow组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399741357.png)样式图标（Feature），在展开的Feature栏导入一张或者多张图片（可以调整画布大小，使图片显示效果更好），第一张图片默认位于画布正中间。

    **图 1**  特有属性配置：ImagePath<a name="zh-cn_topic_0000002399619893_fig144651235202314"></a>  
    ![](figures/特有属性配置-ImagePath-42.png "特有属性配置-ImagePath-42")

    >![](public_sys-resources/icon-note.gif) **说明：** 
    >ImagePath不支持中文路径。
    >导入的Bin文件必须是图片转的Bin，否则模拟器会异常。

-   选中画布内的Coverflow组件，通过右侧属性样式中的![](figures/zh-cn_image_0000002399621461.png)样式图标（Feature），在展开的Feature栏中修改Coverflow组件中的ImgWidth和ImgHeight可以调整图片宽高。

    更改图片宽高后，所有导入Coverflow组件的图片宽高随之改变，且第一张图片始终位于组件的正中间。

    **图 2**  特有属性配置：ImgWidth和ImgHeight<a name="zh-cn_topic_0000002399619893_fig1549113615248"></a>  
    ![](figures/特有属性配置-ImgWidth和ImgHeight.png "特有属性配置-ImgWidth和ImgHeight")

-   选中画布内的Coverflow组件，通过右侧属性样式中的![](figures/zh-cn_image_0000002399741361.png)样式图标（Feature），在展开的Feature栏中修改Coverflow组件中的RotateAngle调整旋转角度。

    **图 3**  特有属性配置：RotateAngle<a name="zh-cn_topic_0000002399619893_fig1917017159243"></a>  
    ![](figures/特有属性配置-RotateAngle.png "特有属性配置-RotateAngle")

-   选中画布内的Coverflow组件，通过右侧属性样式中的![](figures/zh-cn_image_0000002399621465.png)样式图标（Feature），在展开的Feature栏中修改Coverflow组件中的Padding调整图片之间的间距。

    **图 4**  特有属性配置：Padding<a name="zh-cn_topic_0000002399619893_fig2142192232415"></a>  
    ![](figures/特有属性配置-Padding.png "特有属性配置-Padding")

-   选中画布内的Coverflow组件，通过右侧属性样式中的![](figures/zh-cn_image_0000002399741365.png)样式图标（Feature），在展开的Feature栏中修改Coverflow组件中的IsShowMirrorImg设置是否显示图片镜像。

    **图 5**  特有属性配置：IsShowMirrorImg<a name="zh-cn_topic_0000002399619893_fig25262913248"></a>  
    ![](figures/特有属性配置-IsShowMirrorImg.png "特有属性配置-IsShowMirrorImg")

-   选中画布内的Coverflow组件，通过右侧属性样式中的![](figures/zh-cn_image_0000002399621473.png)样式图标（Feature），在展开的Feature栏中修改Coverflow组件中的MirrorOpa设置图片镜像的透明度。

    **图 6**  特有属性配置：MirrorOpa<a name="zh-cn_topic_0000002399619893_fig96581036102413"></a>  
    ![](figures/特有属性配置-MirrorOpa.png "特有属性配置-MirrorOpa")

-   选中画布内的Coverflow组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002399741373.png)样式图标（Events），在展开的Events栏中配置回调事件。

    Coverflow组件支持的事件有：OnDrag、OnDragStart、OnDragEnd、和OnCoverflow。

    **图 7**  回调事件配置<a name="zh-cn_topic_0000002399619893_fig4163730162310"></a>  
    ![](figures/回调事件配置-43.png "回调事件配置-43")

>![](public_sys-resources/icon-note.gif) **说明：** 
>-   Feature页面下的RotateAngle、IsShowMirrorImg和MirrorOpa暂无渲染效果，具体效果可以在模拟器查看。
>-   Coverflow的回调事件在生成的XXXPresenter.cpp文件中的回调函数名称为“OnScroll（）”。

#### Barcode组件<a name="ZH-CN_TOPIC_0000002378877524"></a>

共有属性使用方法请参见“[11.1.2.2 组件的共有属性](组件的共有属性.md#ZH-CN_TOPIC_0000002378717660)”章节内容。

选中画布内的Barcode组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002365941686.png)样式图标（Feature），在展开的Feature栏中有一个BarcodeInfo属性，提供Barcode的信息，且不能设置为空，如果设置为空，生成代码后，在模拟器中会显示条形码失败。

**图 1**  特有属性配置：BarcodeInfo<a name="zh-cn_topic_0000002365940086_fig191081212257"></a>  
![](figures/特有属性配置-BarcodeInfo.png "特有属性配置-BarcodeInfo")

>![](public_sys-resources/icon-note.gif) **说明：** 
>-   Feature页面下的BarcodeInfo属性无页面渲染效果。
>-   Barcode组件不支持回调事件的配置。
>-   BarcodeInfo不能设置为空，且不支持中文，如果设置为空或者为中文，模拟器中显示条形码失败。
>-   BarcodeInfo设置完成后请点击其他位置后，再生成代码。

#### CardPage组件<a name="ZH-CN_TOPIC_0000002412436933"></a>

本组件的General属性请参见“[11.1.2.2 组件的共有属性](组件的共有属性.md#ZH-CN_TOPIC_0000002378717660)”描述。

-   选中画布内的CardPage组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399621509.png)  样式图标（Feature），在展开的Feature栏中有一个IsCoverable属性，默认为false，它的作用是在如果拖动其它CardPage组件展示时是否会覆盖上一个。

    **图 1**  特有属性配置：IsCoverable<a name="zh-cn_topic_0000002399739765_fig195722386343"></a>  
    ![](figures/特有属性配置-IsCoverable.png "特有属性配置-IsCoverable")

-   选中画布内的CardPage组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002366101610.png)样式图标（Events），在展开的Events栏中配置回调事件。

    CardPage组件支持的事件类型有：OnClick、OnLongPress、OnDrag、OnDragStart、OnDragEnd、OnPress、OnCancel、OnRelease、OnFocus、OnBlur、OnRotate、OnRotateStart、OnRotateEnd。

    **图 2**  回调事件配置<a name="zh-cn_topic_0000002399739765_fig1790072115352"></a>  
    ![](figures/回调事件配置-44.png "回调事件配置-44")

>![](public_sys-resources/icon-note.gif) **说明：** 
>-   Feature页面下的属性无界面渲染效果。
>-   CardPage是个容器组件，主要作为CrossView的子组件使用。

#### CrossView组件<a name="ZH-CN_TOPIC_0000002378717688"></a>

本组件的General属性请参见“[11.1.2.2 组件的共有属性](组件的共有属性.md#ZH-CN_TOPIC_0000002378717660)”描述。

-   选中CrossView组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399741433.png)样式图标（Feature），在展开的Feature栏中可以看到EnableScreenCap属性，会弹出一个设定bool变量值的下拉框，它决定设置切换卡片时，是否使能截图模式。

    **图 1**  特有属性配置：EnableScreenCap<a name="zh-cn_topic_0000002366099986_fig1358134319354"></a>  
    
    ![](figures/zh-cn_image_0000002366101638.png)

-   选中CrossView组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002365941766.png)样式图标（Feature），在展开的Feature栏中可以看到SetAnimatorTime属性，它决定模拟器中松手动画时间，其单位为毫秒（ms）。

    **图 2**  特有属性配置：SetAnimatorTime<a name="zh-cn_topic_0000002366099986_fig2959881495"></a>  
    
    ![](figures/zh-cn_image_0000002366101662.png)

-   选中CrossView组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399621581.png)样式图标（Feature），在展开的Feature栏中可以看到DragDirection属性，它决定子组件拖拽来的方向。

    **图 3**  特有属性配置：DragDirection<a name="zh-cn_topic_0000002366099986_fig1772818954716"></a>  
    
    ![](figures/zh-cn_image_0000002365941782.png)

    当拖拽来的组件不是CardPage类型时，右下角会有“Only supports cardpage component”或“仅支持拖拽CardPage组件”提示，并且拖入的子组件不会在画布上展示。

    **图 4**  特有属性配置：DragDirection（仅支持拖拽CardPage类型的子组件）<a name="zh-cn_topic_0000002366099986_fig634965194814"></a>  
    ![](figures/特有属性配置-DragDirection（仅支持拖拽CardPage类型的子组件）.png "特有属性配置-DragDirection（仅支持拖拽CardPage类型的子组件）")

    CrossView组件前端渲染界面仅会展示其某一个CardPage子组件：

    -   当新增CardPage组件时，默认会展示最新拖拽进来的CardPage组件，隐藏掉之前的；
    -   当删除CardPage组件时，默认会展示上个被拖入的CardPage组件，并隐藏掉其它的。

    如果想实现切换，可以点击“[GUI拖拽界面介绍](GUI拖拽界面介绍.md#ZH-CN_TOPIC_0000002412317053)”中所介绍的Panel面板的![](figures/zh-cn_image_0000002366101686.png)按钮，该按钮使用说明如下：

    1.  左右切换会分别显示拖拽来的上一个和下一个CardPage子组件。
    2.  是否支持组件间的循环切换和模拟器的设定规则保持一致，可以在Feature栏的Isloop中选择True&False。当置为False时，第一个组件点击左按钮和最后一个组件点击右按钮时不会有切换效果；当置为True时，第一个组件点击左按钮和最后一个组件点击右按钮时会实现彼此切换。
    3.  切换按钮仅在选中父组件为CrossView的CardPage子组件时生效，选中的操作可以通过点击左侧的组件树中的CardPage或者在渲染界面的CardPage后，点击左右按钮，从而展示被选中组件的前一个和后一个，如[图5](#zh-cn_topic_0000002366099986_fig10608162418201)所示。
    4.  切换按钮如果选的不是父组件为CrossView的CardPage子组件时，会弹窗提示，如[图6](#zh-cn_topic_0000002366099986_fig560918241207)所示。

    **图 5**  特有属性配置：DragDirection（CardPage切换展示逻辑）<a name="zh-cn_topic_0000002366099986_fig10608162418201"></a>  
    ![](figures/特有属性配置-DragDirection（CardPage切换展示逻辑）.png "特有属性配置-DragDirection（CardPage切换展示逻辑）")

    **图 6**  特有属性配置：DragDirection（非CrossView子组件切换的弹窗提醒）<a name="zh-cn_topic_0000002366099986_fig560918241207"></a>  
    ![](figures/特有属性配置-DragDirection（非CrossView子组件切换的弹窗提醒）.png "特有属性配置-DragDirection（非CrossView子组件切换的弹窗提醒）")

    当选择DragDirection为Horizontal方向时，拖拽CardPage组件，CardPage个数不做限制，每次拖拽入新的都会隐藏掉其它的CardPage子组件。

    **图 7**  特有属性配置：DragDirection（水平方向拖拽来的CardPage类型子组件）<a name="zh-cn_topic_0000002366099986_fig12609112419209"></a>  
    ![](figures/特有属性配置-DragDirection（水平方向拖拽来的CardPage类型子组件）.png "特有属性配置-DragDirection（水平方向拖拽来的CardPage类型子组件）")

    当选择DragDirection为Vertical-Up方向时，拖拽CardPage组件，拖拽新的组件时也会隐藏掉其它的CardPage子组件，但是仅支持拖拽的个数为一个，当再次拖拽该方向的CardPage子组件时右下角会有“UpPage direction only supports one component”或“竖直上方向的CardPage组件仅支持拖拽一个”提示。

    **图 8**  特有属性配置：DragDirectio（竖直上方向仅支持拖拽一个子组件）<a name="zh-cn_topic_0000002366099986_fig1260952419208"></a>  
    ![](figures/特有属性配置-DragDirectio（竖直上方向仅支持拖拽一个子组件）.png "特有属性配置-DragDirectio（竖直上方向仅支持拖拽一个子组件）")

    当选择DragDirection为Vertical-Down方向时，拖拽CardPage组件，拖拽新的组件时也会隐藏掉其它的CardPage子组件，且仅支持拖拽的个数为一个，当再次拖拽该方向的CardPage子组件时右下角会有“DownPage direction only supports one component”或“竖直下方向的CardPage组件仅支持拖拽一个”提示。

    **图 9**  特有属性配置：DragDirection（竖直下方向仅支持拖拽一个子组件）<a name="zh-cn_topic_0000002366099986_fig16609142412208"></a>  
    ![](figures/特有属性配置-DragDirection（竖直下方向仅支持拖拽一个子组件）.png "特有属性配置-DragDirection（竖直下方向仅支持拖拽一个子组件）")

-   选中CrossView组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002365941822.png)样式图标（Feature），在展开的Feature栏中点击Isloop属性，会弹出一个设定bool变量值的下拉框，它决定水平卡片循环模式。

    **图 10**  特有属性配置：Isloop<a name="zh-cn_topic_0000002366099986_fig18540511191815"></a>  
    
    ![](figures/zh-cn_image_0000002399741541.png)

-   选中CrossView组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002366101718.png)样式图标（Events），在展开的Events栏中配置回调事件。

    CrossView组件支持的事件有：OnClick、OnLongPress、OnDrag、OnDragStart、OnDragEnd、OnPress、OnCancel、OnRelease、OnFocus、OnBlur、OnRotate、OnRotateStart、OnRotateEnd，OnSwipe。其中OnSwipe默认为True。

    **图 11**  回调事件配置<a name="zh-cn_topic_0000002366099986_fig5540511151817"></a>  
    
    ![](figures/zh-cn_image_0000002399621633.png)

>![](public_sys-resources/icon-note.gif) **说明：** 
>-   Feature界面除DragDirection的特性和Isloop与GUI界面前端渲染关联外，其它属性无界面渲染效果，可在模拟器中查看。
>-   CrossView组件仅支持CardPage类型的子组件拖拽。
>-   CrossView组件的所有弹窗均支持中英文适配。

#### MapView组件<a name="ZH-CN_TOPIC_0000002412317085"></a>

本组件的General属性请参见“[11.1.2.2 组件的共有属性](组件的共有属性.md#ZH-CN_TOPIC_0000002378717660)”描述。

-   选中MapView组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002365941846.png)样式图标（Feature），在展开的Feature栏中点击SvgPath右侧的图标，会弹出一个选择Svg文件的界面，解压地图对应的Svg文件到任意目录，点击选择后，再次打开该目录，刷新，可以看到会生成一个与Svg文件同名的bin文件，该文件用于被模拟器读取并展示。同时该地图文件会完成绘制在画布中。

    **图 1**  特有属性配置：SvgPath-选择Svg文件<a name="zh-cn_topic_0000002399619897_fig1556381810504"></a>  
    ![](figures/特有属性配置-SvgPath-选择Svg文件.png "特有属性配置-SvgPath-选择Svg文件")

    **图 2**  特有属性配置：SvgPath-绘制Svg图片<a name="zh-cn_topic_0000002399619897_fig761210910508"></a>  
    ![](figures/特有属性配置-SvgPath-绘制Svg图片.png "特有属性配置-SvgPath-绘制Svg图片")

-   选中MapView组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002399621645.png)样式图标（Events），在展开的Events栏中配置回调事件。

    MapView组件支持的事件有：OnClick、OnLongPress、OnDrag、OnDragStart、OnDragEnd、OnPress、OnCancel、OnRelease、OnFocus、OnBlur、OnRotate、OnRotateStart、OnRotateEnd和OnPOIClick。

    **图 3**  回调事件配置<a name="zh-cn_topic_0000002399619897_fig982152854217"></a>  
    ![](figures/回调事件配置-45.png "回调事件配置-45")

>![](public_sys-resources/icon-note.gif) **说明：** 
>-   MapView是地图组件，应将地图文件展示到画布中和模拟器中。
>-   MapView的General属性仅包含ID、Position两个选项可供用户设置，工具和模拟器会默认展示该Svg图片的原始大小，用户可以根据模拟器实际效果调整Position参数。

#### RollerView组件<a name="ZH-CN_TOPIC_0000002378877528"></a>

本组件的共有属性不包含Border属性、Margin属性与Padding属性，其他共有属性使用方法请参见“[组件的共有属性](组件的共有属性.md#ZH-CN_TOPIC_0000002378717660)”章节内容。

-   选中RollerView组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399741561.png)样式图标（Feature），在展开的Feature栏导入一张或者多张图片（可以调整画布大小，使图片显示效果更好），第一张图片默认位于画布正中间。

    **图 1**  特有属性配置：ImagePath<a name="zh-cn_topic_0000002365940090_fig144651235202314"></a>  
    ![](figures/特有属性配置-ImagePath-46.png "特有属性配置-ImagePath-46")

    >![](public_sys-resources/icon-note.gif) **说明：** 
    >ImagePath不支持中文路径。
    >导入的Bin文件必须是图片转的Bin，否则模拟器会异常。

-   选中画布内的RollerView组件，通过右侧属性样式中的![](figures/zh-cn_image_0000002399621649.png)样式图标（Feature），在展开的Feature栏中修改RollerView组件中的ImageWidth和ImageHeight可以调整图片宽高。

    更改图片宽高后，所有导入RollerView组件的图片宽高随之改变，且第一张图片始终位于组件的正中间。

    **图 2**  特有属性配置：ImageWidth和ImageHeight<a name="zh-cn_topic_0000002365940090_fig1549113615248"></a>  
    ![](figures/特有属性配置-ImageWidth和ImageHeight.png "特有属性配置-ImageWidth和ImageHeight")

-   选中画布内的RollerView组件，通过右侧属性样式中的![](figures/zh-cn_image_0000002474130925.png)样式图标（Feature），在展开的Feature栏中修改RollerView组件中的MirrorOpacity调整滚筒元素镜像图的透明度。

    **图 3**  特有属性配置：MirrorOpacity<a name="zh-cn_topic_0000002365940090_fig514874910116"></a>  
    ![](figures/特有属性配置-MirrorOpacity.png "特有属性配置-MirrorOpacity")

-   选中画布内的RollerView组件，通过右侧属性样式中的![](figures/zh-cn_image_0000002440730820.png)样式图标（Feature），在展开的Feature栏中修改RollerView组件中的SensitivityFactor调整滚筒灵敏度。

    **图 4**  特有属性配置：SensitivityFactor<a name="zh-cn_topic_0000002365940090_fig2991158101319"></a>  
    ![](figures/特有属性配置-SensitivityFactor.png "特有属性配置-SensitivityFactor")

-   选中画布内的RollerView组件，通过右侧属性样式中的![](figures/zh-cn_image_0000002399741565.png)样式图标（Feature），在展开的Feature栏中修改RollerView组件中的Padding调整图片之间的间距。

    **图 5**  特有属性配置：Padding<a name="zh-cn_topic_0000002365940090_fig2142192232415"></a>  
    ![](figures/特有属性配置-Padding-47.png "特有属性配置-Padding-47")

-   选中画布内的RollerView组件，通过右侧属性样式中的![](figures/zh-cn_image_0000002399621653.png)样式图标（Feature），在展开的Feature栏中修改RollerView组件中的CameraDistance设置模拟器中相机的距离。

    **图 6**  特有属性配置：CameraDistance<a name="zh-cn_topic_0000002365940090_fig25262913248"></a>  
    ![](figures/特有属性配置-CameraDistance.png "特有属性配置-CameraDistance")

-   选中画布内的RollerView组件，通过右侧属性样式中的![](figures/zh-cn_image_0000002399741569.png)样式图标（Feature），在展开的Feature栏中修改RollerView组件中的CamY设置模拟器中相机的Y坐标。

    **图 7**  特有属性配置：CamY<a name="zh-cn_topic_0000002365940090_fig96581036102413"></a>  
    ![](figures/特有属性配置-CamY.png "特有属性配置-CamY")

-   选中画布内的RollerView组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002399621657.png)样式图标（Events），在展开的Events栏中配置回调事件。

    RollerView组件支持的事件有：OnClick、OnLongPress、OnDrag、OnDragStart、OnDragEnd、OnPress、OnCancel、OnRelease、OnFocus、OnBlur、OnScroll、OnModeChange。

    **图 8**  回调事件配置<a name="zh-cn_topic_0000002365940090_fig17698142911119"></a>  
    ![](figures/回调事件配置-48.png "回调事件配置-48")

>![](public_sys-resources/icon-note.gif) **说明：** 
>Feature页面下的CameraDistance和CamY暂无渲染效果，具体效果可以在模拟器查看。
>RollerView组件在模拟器中可以实现水平方向上将图片按照滚筒的形式排布并支持滚动交互。

#### HexagonsList组件<a name="ZH-CN_TOPIC_0000002412436937"></a>

本组件的共有属性不包含Border属性、Margin属性与Padding属性，其他共有属性使用方法请参见“[组件的共有属性](组件的共有属性.md#ZH-CN_TOPIC_0000002378717660)”章节内容。

-   选中HexagonsList组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399741573.png)样式图标（Feature），在展开的Feature栏导入一张或者多张图片（可以调整画布大小，使图片显示效果更好），第一张图片默认位于画布正中间。

    **图 1**  特有属性配置：ImagePath<a name="zh-cn_topic_0000002399739769_fig144651235202314"></a>  
    ![](figures/特有属性配置-ImagePath-49.png "特有属性配置-ImagePath-49")

    >![](public_sys-resources/icon-note.gif) **说明：** 
    >ImagePath不支持中文路径。
    >导入的Bin文件必须是图片转的Bin，否则模拟器会异常。

-   选中画布内的HexagonsList组件，通过右侧属性样式中的![](figures/zh-cn_image_0000002399621661.png)样式图标（Feature），在展开的Feature栏中修改HexagonsList组件中的ImageWidth和ImageHeight可以调整图片宽高。

    更改图片宽高后，所有导入HexagonsList组件的图片宽高随之改变，且第一张图片始终位于组件的正中间。

    **图 2**  特有属性配置：ImageWidth和ImageHeight<a name="zh-cn_topic_0000002399739769_fig1549113615248"></a>  
    ![](figures/特有属性配置-ImageWidth和ImageHeight-50.png "特有属性配置-ImageWidth和ImageHeight-50")

-   选中画布内的HexagonsList组件，通过右侧属性样式中的![](figures/zh-cn_image_0000002399741577.png)样式图标（Feature），在展开的Feature栏中修改HexagonsList组件中的Padding调整图片之间的间距。

    **图 3**  特有属性配置：Padding<a name="zh-cn_topic_0000002399739769_fig2142192232415"></a>  
    ![](figures/特有属性配置-Padding-51.png "特有属性配置-Padding-51")

-   选中画布内的HexagonsList组件，通过右侧属性样式中的![](figures/zh-cn_image_0000002399621673.png)样式图标（Feature），在展开的Feature栏中修改HexagonsList组件中的OriImgDistance属性来设置模拟器中两个相邻图像中心之间的原始图像距离。

    **图 4**  特有属性配置：OriImgDistance<a name="zh-cn_topic_0000002399739769_fig25262913248"></a>  
    ![](figures/特有属性配置-OriImgDistance.png "特有属性配置-OriImgDistance")

-   选中画布内的HexagonsList组件，通过右侧属性样式中的![](figures/zh-cn_image_0000002399741585.png)样式图标（Feature），在展开的Feature栏中修改HexagonsList组件中的ImgSizeInCenter属性来设置模拟器中图像位于中心位置的大小。

    **图 5**  特有属性配置：ImgSizeInCenter<a name="zh-cn_topic_0000002399739769_fig9701121017913"></a>  
    ![](figures/特有属性配置-ImgSizeInCenter.png "特有属性配置-ImgSizeInCenter")

-   选中画布内的HexagonsList组件，通过右侧属性样式中的![](figures/zh-cn_image_0000002399621681.png)样式图标（Feature），在展开的Feature栏中修改HexagonsList组件中的ReboundedSize属性来设置回弹大小，即拖拽到列表边缘之外再释放后回弹至列表边缘移动的距离。

    **图 6**  特有属性配置：ReboundedSize<a name="zh-cn_topic_0000002399739769_fig17864205617814"></a>  
    ![](figures/特有属性配置-ReboundedSize.png "特有属性配置-ReboundedSize")

-   选中画布内的HexagonsList组件，通过右侧属性样式中的![](figures/zh-cn_image_0000002399741589.png)样式图标（Feature），在展开的Feature栏中修改HexagonsList组件中的ScrollBlankSize属性来设置模拟器中组件滚动视图时的空白大小。

    **图 7**  特有属性配置：ScrollBlankSizec<a name="zh-cn_topic_0000002399739769_fig1256315491283"></a>  
    ![](figures/特有属性配置-ScrollBlankSizec.png "特有属性配置-ScrollBlankSizec")

-   选中画布内的HexagonsList组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002399621689.png)样式图标（Events），在展开的Events栏中配置回调事件。

    HexagonsList组件支持的事件有：OnClick、OnLongPress、OnDrag、OnDragStart、OnDragEnd、OnPress、OnCancel、OnRelease、OnFocus、OnBlur、OnRotate、OnRotateStart、OnRotateEnd。

    **图 8**  回调事件配置<a name="zh-cn_topic_0000002399739769_fig17698142911119"></a>  
    ![](figures/回调事件配置-52.png "回调事件配置-52")

>![](public_sys-resources/icon-note.gif) **说明：** 
>Feature页面下的OriImgDistance、ImgSizeInCenter、ReboundedSize和ScrollBlankSize暂无渲染效果，具体效果可以在模拟器查看。
>ImageWidth、Padding，ImageHeight可以用于用户在界面展示多个组件时设置图片大小。
>Rebounded和ScrollBlankSize的初始值为227，是默认组件的Position为\(0, 0, 454, 454\)，即整个表盘。具体的取值大小可以根据实际模拟器展示效果进行调整，通常这个取值为组件宽度的一半。
>OriImgDistance和ImgSizeInCenter属性与组件宽度的乘积，决定了模拟器中图片的摆放位置关系。

#### IcosahedronView组件<a name="ZH-CN_TOPIC_0000002378717692"></a>

本组件的共有属性不包含Position属性、Border属性、Margin属性与Padding属性，其他共有属性使用方法请参见“[组件的共有属性](组件的共有属性.md#ZH-CN_TOPIC_0000002378717660)”章节内容。

-   选中IcosahedronView组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399741597.png)样式图标（Feature），在展开的Feature栏导入一张图片（可以调整画布大小，使图片显示效果更好），图片会默认填满整个画布。

    **图 1**  特有属性配置：DefaultSrc<a name="zh-cn_topic_0000002366099990_fig1411916381693"></a>  
    ![](figures/特有属性配置-DefaultSrc.png "特有属性配置-DefaultSrc")

-   选中IcosahedronView组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399621693.png)样式图标（Feature），在展开的Feature栏中修改IcosahedronView组件中的LuminanceFactor属性来设置模拟器中亮度补偿因子，调整亮度。

    **图 2**  特有属性配置：LuminanceFactor<a name="zh-cn_topic_0000002366099990_fig51391045174012"></a>  
    ![](figures/特有属性配置-LuminanceFactor.png "特有属性配置-LuminanceFactor")

-   IcosahedronView组件仅支持Image组件导入。IcosahedronView组件的DefaultSrc属性设置了默认图片，如果导入的Image组件的图片个数少于20张，则使用该默认图片填充，达到类似足球样式的模拟器效果图。

    **图 3**  仅支持导入Image组件<a name="zh-cn_topic_0000002366099990_fig14703195575718"></a>  
    ![](figures/仅支持导入Image组件.png "仅支持导入Image组件")

-   选中画布内的IcosahedronView组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002366101774.png)样式图标（Events），在展开的Events栏中配置回调事件。

    RollerView组件支持的事件有：OnClick、OnLongPress、OnDrag、OnDragStart、OnDragEnd、OnPress、OnCancel、OnRelease、OnFocus、OnBlur、OnRotate、OnRotateStart、OnRotateEnd。

    **图 4**  回调事件配置<a name="zh-cn_topic_0000002366099990_fig1859035515919"></a>  
    ![](figures/回调事件配置-53.png "回调事件配置-53")

>![](public_sys-resources/icon-note.gif) **说明：** 
>IcosahedronView组件仅支持width和height调节，其坐标位置固定。

#### CanvasExt组件<a name="ZH-CN_TOPIC_0000002412317089"></a>

共有属性使用方法请参见“[组件的共有属性](组件的共有属性.md#ZH-CN_TOPIC_0000002378717660)”章节内容。

-   选中画布内的CanvasExt组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002365941902.png)样式图标（Events），在展开的Events栏中配置回调事件。CanvasExt组件支持的事件有：OnClick、OnLongPress、OnPress、OnCancel和OnRelease。

    **图 1**  回调事件配置<a name="zh-cn_topic_0000002399619901_fig863319505301"></a>  
    ![](figures/回调事件配置-54.png "回调事件配置-54")

#### TransformList组件<a name="ZH-CN_TOPIC_0000002378877532"></a>

共有属性使用方法请参见“[组件的共有属性](组件的共有属性.md#ZH-CN_TOPIC_0000002378717660)”章节内容。

-   选中TransformList组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002366101786.png)样式图标（Feature），在展开的Feature栏中修改itemHeight属性设置所有子项的高度；修改itemWidth属性设置所有子项的宽度；修改itemSpace属性设置子项之间的间隙；修改imageHeight属性设置所有子项图片的高度；修改FontSize属性设置所有子项的字体大小；点击Item栏右侧的加号添加子项，修改子项中的Text属性和ImagePath属性添加文本和图片。

    **图 1**  添加子项<a name="zh-cn_topic_0000002365940094_fig1424214304315"></a>  
    ![](figures/添加子项-55.png "添加子项-55")

-   选中TransformList组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002365941910.png)样式图标（Feature），在展开的Feature栏中修改List组件的OffsetX属性设置所有子项的横向偏移，修改OffsetY属性设置所有子项的纵向偏移。

    **图 2**  修改子项的偏移<a name="zh-cn_topic_0000002365940094_fig8644443123216"></a>  
    ![](figures/修改子项的偏移-56.png "修改子项的偏移-56")

-   选中TransformList组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002366101790.png)样式图标（Feature），在展开的Feature栏中修改TransformList组件的Direction属性设置列表的排列方向。

    **图 3**  修改列表的排列方向<a name="zh-cn_topic_0000002365940094_fig640685910323"></a>  
    ![](figures/修改列表的排列方向-57.png "修改列表的排列方向-57")

-   选中画布内的TransformList组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002365941914.png)样式图标（Events），在展开的Events栏中配置回调事件。

    List组件支持的事件有：OnClick、OnLongPress、OnDrag、OnDragStart、OnDragEnd、OnPress、OnCancel、OnRelease、OnFocus和OnBlur。

    **图 4**  回调事件配置<a name="zh-cn_topic_0000002365940094_fig186332171075"></a>  
    ![](figures/回调事件配置-58.png "回调事件配置-58")

#### SlipflowView组件<a name="ZH-CN_TOPIC_0000002412436941"></a>

本组件的共有属性不包含Position属性、Size属性、GaussOption属性、Border属性、Margin属性与Padding属性，其他共有属性使用方法请参见“[11.1.2.2 组件的共有属性](组件的共有属性.md#ZH-CN_TOPIC_0000002378717660)”描述。

-   选中画布内的SlipflowView组件，通过右侧属性样式中的![](figures/zh-cn_image_0000002366101794.png)样式图标（Feature），在展开的Feature栏中修改SlipflowView组件中的ImgWidth和ImgHeight可以调整图片宽高。

    更改图片宽高后，所有导入SlipflowView组件的图片宽高随之改变，且第一张图片始终位于组件的正中间。

    **图 1**  特有属性配置：ImgWidth和ImgHeight<a name="zh-cn_topic_0000002399739773_fig186308234339"></a>  
    ![](figures/特有属性配置-ImgWidth和ImgHeight-59.png "特有属性配置-ImgWidth和ImgHeight-59")

-   选中画布内的SlipflowView组件，通过右侧属性样式中的![](figures/zh-cn_image_0000002399741625.png)样式图标（Feature），在展开的Feature栏中修改SlipflowView组件中的isEnableBackImage可以控制是否使能背景图片。

    **图 2**  特有属性配置：isEnableBackImage<a name="zh-cn_topic_0000002399739773_fig951023617338"></a>  
    ![](figures/特有属性配置-isEnableBackImage.png "特有属性配置-isEnableBackImage")

-   选中SlipflowView组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399621717.png)样式图标（Feature），在展开的Feature栏中修改SlipflowView组件中的backImagePath可以设置背景图片资源路径。

    **图 3**  特有属性配置：backImagePath<a name="zh-cn_topic_0000002399739773_fig1650517572334"></a>  
    ![](figures/特有属性配置-backImagePath.png "特有属性配置-backImagePath")

-   选中SlipflowView组件，单击右侧属性样式栏中的![](figures/zh-cn_image_0000002399741629.png)样式图标（Feature），在展开的Feature栏导入一张或者多张图片（可以调整画布大小，使图片显示效果更好），第一张图片默认位于画布正中间。

    **图 4**  特有属性配置：ImagePath<a name="zh-cn_topic_0000002399739773_fig144651235202314"></a>  
    
    ![](figures/zh-cn_image_0000002366101802.png)

    >![](public_sys-resources/icon-note.gif) **说明：** 
    >ImagePath不支持中文路径。
    >导入的Bin文件必须是图片转的Bin，否则模拟器会异常.

-   选中画布内的SlipflowView组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002399621721.png)样式图标（Events），在展开的Events栏中配置回调事件。

    SlipflowView组件支持的事件有：OnClick、OnLongPress、OnPress、OnCancel、OnRelease、OnScroll、OnScrollUpStart、OnScrollUpEnd、OnRemove和OnRefreshPageOpaScale。

    **图 5**  回调事件配置<a name="zh-cn_topic_0000002399739773_fig4163730162310"></a>  
    ![](figures/回调事件配置-60.png "回调事件配置-60")

>![](public_sys-resources/icon-note.gif) **说明：** 
>-   SlipflowView组件其坐标位置固定，大小固定。
>-   Feature页面下的isEnableBackImage和backImagePath暂无渲染效果，具体效果可以在模拟器查看。

#### TransformGroup组件<a name="ZH-CN_TOPIC_0000002378717696"></a>

共有属性使用方法请参见“[组件的共有属性](组件的共有属性.md#ZH-CN_TOPIC_0000002378717660)”章节内容。

-   选中画布内的TransformGroup组件，通过右侧属性样式栏中的![](figures/zh-cn_image_0000002399741665.png)样式图标（Events），在展开的Events栏中配置回调事件。

    TransformGroup组件支持的事件类型有：OnClick、OnLongPress、OnPress、OnCancel、OnRelease。

    **图 1**  回调事件配置<a name="zh-cn_topic_0000002366099994_fig1790072115352"></a>  
    ![](figures/回调事件配置-61.png "回调事件配置-61")

>![](public_sys-resources/icon-note.gif) **说明：** 
>TransformGroup是个容器组件，主要作为Coverflow2的子组件使用。

#### Coverflow2组件<a name="ZH-CN_TOPIC_0000002412317093"></a>

共有属性使用方法请参见“[组件的共有属性](组件的共有属性.md#ZH-CN_TOPIC_0000002378717660)”章节内容。

-   选中画布内的Coverflow2组件，通过右侧属性样式中的![](figures/zh-cn_image_0000002399621761.png)样式图标（Feature），在展开的Feature栏中修改Coverflow2组件中的RotateAngle调整旋转角度。

    **图 1**  特有属性配置：RotateAngle<a name="zh-cn_topic_0000002399619905_fig1917017159243"></a>  
    
    ![](figures/zh-cn_image_0000002365941966.png)

-   选中画布内的Coverflow2组件，通过右侧属性样式中的![](figures/zh-cn_image_0000002399741673.png)样式图标（Feature），在展开的Feature栏中修改Coverflow2组件中的Padding调整图片之间的间距。

    **图 2**  特有属性配置：Padding<a name="zh-cn_topic_0000002399619905_fig2142192232415"></a>  
    
    ![](figures/zh-cn_image_0000002366101846.png)

-   选中画布内的Coverflow2组件，通过右侧属性样式中的![](figures/zh-cn_image_0000002399621765.png)样式图标（Feature），在展开的Feature栏中修改Coverflow2组件中的IsShowMirrorImg设置是否显示图片镜像。

    **图 3**  特有属性配置：IsShowMirrorImg<a name="zh-cn_topic_0000002399619905_fig25262913248"></a>  
    
    ![](figures/zh-cn_image_0000002365941970.png)

-   选中画布内的Coverflow2组件，通过右侧属性样式中的![](figures/zh-cn_image_0000002399741677.png)样式图标（Feature），在展开的Feature栏中修改Coverflow2组件中的MirrorOpa设置图片镜像的透明度。

    **图 4**  特有属性配置：MirrorOpa<a name="zh-cn_topic_0000002399619905_fig96581036102413"></a>  
    
    ![](figures/zh-cn_image_0000002366101850.png)

    当拖拽来的组件不是TransformGroup类型时，右下角会有“Only supports transformgroup component”或“仅支持拖拽TransformGroup组件”提示，并且拖入的子组件不会在画布上展示。

    **图 5**  组件拖入Coverflow2组件中<a name="zh-cn_topic_0000002399619905_fig1535915143218"></a>  
    ![](figures/组件拖入Coverflow2组件中.png "组件拖入Coverflow2组件中")

Coverflow2组件前端渲染界面仅会展示其某一个TransformGroup子组件：

-   当新增TransformGroup组件时，默认会展示最新拖拽进来的TransformGroup组件，隐藏掉之前的；
-   当删除TransformGroup组件时，默认会展示上个被拖入的TransformGroup组件，并隐藏掉其它的。

如果想实现切换，可以点击“[GUI拖拽界面介绍](GUI拖拽界面介绍.md#ZH-CN_TOPIC_0000002412317053)”中所介绍的Panel面板的![](figures/zh-cn_image_0000002365941974.png)按钮，该按钮使用说明如下：

1.  左右切换会分别显示拖拽来的上一个和下一个TransformGroup子组件。
2.  切换按钮在选中父组件为Coverflow2的TransformGroup子组件时生效，选中的操作可以通过点击左侧的组件树中的TransformGroup或者在渲染界面的TransformGroup后，点击左右按钮，从而展示被选中组件的前一个和后一个，如[图6](#zh-cn_topic_0000002399619905_fig14330923143518)所示。
3.  切换按钮如果选的不是父组件为Coverflow2的TransformGroup子组件时，会弹窗提示，如[图7](#zh-cn_topic_0000002399619905_fig1459413716407)所示。

**图 6**  TransformGroup切换展示逻辑<a name="zh-cn_topic_0000002399619905_fig14330923143518"></a>  
![](figures/TransformGroup切换展示逻辑.png "TransformGroup切换展示逻辑")

**图 7**  非Coverflow2子组件切换的弹窗提醒<a name="zh-cn_topic_0000002399619905_fig1459413716407"></a>  
![](figures/非Coverflow2子组件切换的弹窗提醒.png "非Coverflow2子组件切换的弹窗提醒")

#### Root组件<a name="ZH-CN_TOPIC_0000002378877536"></a>

本组件为中央区域的背景画布。

**图 1**  Root组件<a name="zh-cn_topic_0000002365940098_fig1548711534020"></a>  
![](figures/Root组件.png "Root组件")

选中Root组件，在右侧展开的General栏中修改BackgroundColor属性，可以修改Root组件的颜色。

**图 2**  修改背景色<a name="zh-cn_topic_0000002365940098_fig1728445112456"></a>  
![](figures/修改背景色-62.png "修改背景色-62")

>![](public_sys-resources/icon-note.gif) **说明：** 
>-   Root组件是所有组件的父组件。
>-   Root组件是唯一的，自动创建的，不可进行除改变颜色外的其他操作的。

#### 用户代码编辑<a name="ZH-CN_TOPIC_0000002412436945"></a>

用户点击画布右上角“Convert to C++ files”，会在工程文件生成界面样式对应的代码。

**图 1**  生成代码按钮<a name="zh-cn_topic_0000002399739777_fig36701735185010"></a>  
![](figures/生成代码按钮.png "生成代码按钮")

以工程名为aaaa的aaaa.gui工程和Button组件为例，生成的代码目录位于工程目录下“application/wearable/nativeapp/gui工程名”，具体结构如[图2](#zh-cn_topic_0000002399739777_fig084021814113)所示。用户可自行在xxxPresenter.cpp文件中按照模板添加自己的回调事件，模板代码如[图3](#zh-cn_topic_0000002399739777_fig113311395104)所示，其余部分都是自动生成的，每次点击生成代码按钮都会刷新。

**图 2**  生成代码目录结构<a name="zh-cn_topic_0000002399739777_fig084021814113"></a>  
![](figures/生成代码目录结构.png "生成代码目录结构")

>![](public_sys-resources/icon-note.gif) **说明：** 
>-   从其他组件切成CrossView组件，或者从CrossView组件切成其它组件，而后去生成代码时，由于CrossView组件添加子组件的特殊性，需要先手动删除当前已有的“/src/$\{AppName\}View.cpp”后，再点击转换生成代码。
>-   其余“ui\_xxView.h”格式的文件不可修改，GUI每次点击生成代码都会覆盖生成。

**图 3**  回调事件模板代码<a name="zh-cn_topic_0000002399739777_fig113311395104"></a>  
![](figures/回调事件模板代码.png "回调事件模板代码")

以click的回调事件为例，如果当前画布中只有一个组件的的click回调被置为true，用户可直接在OnClick的回调函数中添加回调事件，如果当前画布中有多个组件的click回调被置为true，则用户需要按照提示来区分组件实现各自的回调，如[图4](#zh-cn_topic_0000002399739777_fig171118207109)所示。

**图 4**  多个组件同一回调事件代码实现<a name="zh-cn_topic_0000002399739777_fig171118207109"></a>  
![](figures/多个组件同一回调事件代码实现.png "多个组件同一回调事件代码实现")

#### 组件对齐<a name="ZH-CN_TOPIC_0000002378717700"></a>

组件对齐通过选中组件再点击界面上方工具栏中的对齐按钮![](figures/zh-cn_image_0000002399741701.png)实现。

对齐效果分别为左对齐![](figures/zh-cn_image_0000002366101870.png)，左右居中对齐![](figures/zh-cn_image_0000002399621797.png)，右对齐![](figures/zh-cn_image_0000002365942006.png)，顶部对齐![](figures/zh-cn_image_0000002399741709.png)，上下居中对齐![](figures/zh-cn_image_0000002366101906.png)和底部对齐![](figures/zh-cn_image_0000002399621837.png)六种。

根据选中的组件个数不同，对齐操作分为两种：

-   选中一个组件

    只选中一个组件时，会将被选中的组件作为需要对齐的组件，以其父组件作为参照物进行对齐。可以通过组件树（Component Tree）查看组件的父子关系。

    >![](public_sys-resources/icon-note.gif) **说明：** 
    >只选中Root组件时无效。

-   选中多个组件（通过按住Ctrl键点击多个组件）

    当被选中的组件不止一个时，将会以最后一个被选中的组件作为参照物，其他被选中的组件作为需要对齐的组件进行对齐。

    >![](public_sys-resources/icon-note.gif) **说明：** 
    >被选中的组件只能为Root组件或其直接子组件。

#### 组件层级移动<a name="ZH-CN_TOPIC_0000002412317097"></a>

组件层级移动通过选中组件再点击界面上方工具栏中的层级移动按钮实现。

**图 1**  组件层级移动<a name="zh-cn_topic_0000002399619909_fig84841225105411"></a>  
![](figures/组件层级移动.png "组件层级移动")

![](figures/zh-cn_image_0000002366101930.png)为前进一层，![](figures/zh-cn_image_0000002399621861.png)为后退一层

>![](public_sys-resources/icon-note.gif) **说明：** 
>-   每次点击操作只能使组件向前/向后一层。
>-   同时选中多个组件时层级移动操作只对最后一个选中的组件生效。
>-   层级移动无法调整当前组件的父组件（如当前组件是ScrollView/SwipeView的子组件，层级移动操作无法使组件跳出）。
>-   组件树中越靠近顶端的组件层级越低，越靠近底部的组件层级越高。

#### 高斯模糊属性<a name="ZH-CN_TOPIC_0000002378877540"></a>

组件的高斯模糊属性通过单击右侧属性样式栏中的![](figures/zh-cn_image_0000002365942066.png)样式图标（General），在展开的General栏中修改组件的GaussianBlur属性设置高斯模糊。如[图1](#zh-cn_topic_0000002365940102_fig12812852164217)所示。

**图 1**  高斯模糊<a name="zh-cn_topic_0000002365940102_fig12812852164217"></a>  
![](figures/高斯模糊-63.png "高斯模糊-63")

组件设置高斯模糊之后，会将层级低于该组件的其他组件模糊处理。如[图2](#zh-cn_topic_0000002365940102_fig17715201710478)所示。

**图 2**  高斯模糊效果范例<a name="zh-cn_topic_0000002365940102_fig17715201710478"></a>  
![](figures/高斯模糊效果范例.png "高斯模糊效果范例")

>![](public_sys-resources/icon-note.gif) **说明：** 
>-   只有同时满足FullScreenState为true且GaussianBlur不为0时，高斯模糊才会生效。
>-   因渲染方式差异，GUI界面中组件渲染效果会与模拟器中实际效果有一定差异。
>-   多个组件均设置高斯模糊效果时，仅最下层组件的高斯模糊生效。
>-   组件层级可通过组件树查看，层级移动方式和详细说明参考“[组件层级移动](组件层级移动.md#ZH-CN_TOPIC_0000002412317097)”。
>-   GaussianBlur属性决定不同程度的高斯模糊效果，合理的范围是\[0, 32\]。
>-   事件添加：当前版本在控件的Events属性中使能事件不会生成事件代码，需用户手动添加事件代码，具体添加方法是在应用代码（以应用名未gui6为例，在sdk根目录/application/wearable/nativeapp/nativeui/gui6/include/ui\_gui6View.h）的setupUi方法中，对指定控件添加预期添加的事件，如需要给id名称为“button1”的控件添加OnLongPress事件，则在setupUi方法末尾增加“button1-\>SetOnLongPressListener\(gui6presenter\_\);”，其中“button1\_”为控件在代码中的变量名，“gui6presenter\_”为与应用名关联的在代码中自动生成的指针。

## 模拟器效果展示方法<a name="ZH-CN_TOPIC_0000002412436949"></a>





### Demo运行<a name="ZH-CN_TOPIC_0000002378717704"></a>

点击图示中的“App Debug”，会起编译调试并展示模拟器，运行默认的demo效果如[图2](#zh-cn_topic_0000002366100002_fig771416101317)所示。

运行过程中的日志信息记录在当前打开的工程根目录下的“simulator\_build/error.txt”文件中。

**图 1**  App Debug按钮<a name="zh-cn_topic_0000002366100002_fig599934320100"></a>  
![](figures/App-Debug按钮.png "App-Debug按钮")

**图 2**  模拟器效果展示<a name="zh-cn_topic_0000002366100002_fig771416101317"></a>  
![](figures/模拟器效果展示.png "模拟器效果展示")

### 调试运行<a name="ZH-CN_TOPIC_0000002412317101"></a>

点击“App Debug”按钮后，会自动起编译和调试功能，用户可自行添加断点并进行调试。调试功能请参见“[8 工程调试](工程调试.md#ZH-CN_TOPIC_0000002378877472)”章节。

**图 1**  调试功能展示<a name="zh-cn_topic_0000002399619913_fig28521758191013"></a>  
![](figures/调试功能展示.png "调试功能展示")

### 经过GUI界面拖拽生成代码运行<a name="ZH-CN_TOPIC_0000002378877544"></a>

用户在画布中添加组件、更改属性或者回调使能后，并且启动模拟器后，可按照[图1](#zh-cn_topic_0000002365940106_fig18197143416124)操作看到画布中添加的功能列表。

**图 1**  从模拟器查看添加的组件功能<a name="zh-cn_topic_0000002365940106_fig18197143416124"></a>  
![](figures/从模拟器查看添加的组件功能.png "从模拟器查看添加的组件功能")

>![](public_sys-resources/icon-note.gif) **说明：** 
>当模拟器显示主界面时，点击右上角按钮，会自动跳到功能列表页面，列表最先面即为添加组件列表；当模拟器显示非主界面时，点击右上角按钮，会自动跳到主界面。

从图中可以看出，当前添加的功能名称默认为创建的GUI工程名称，图标默认为“示例”图标。如果想要修改模拟器中GUI工程的图标和名称，可以在对应GUI工程的生成代码目录下的“Register.cpp”文件中进行修改。

**图 2**  修改默认GUI工程名称和列表前的图标<a name="zh-cn_topic_0000002365940106_fig21411933131311"></a>  
![](figures/修改默认GUI工程名称和列表前的图标.png "修改默认GUI工程名称和列表前的图标")

在对应的cpp文件中，修改这四个参数可以修改模拟器中对应组件的图标或者名称。

①：桌面中选择图标模式（默认模式）对应的图标显示，格式为.bin的格式文件。

②：桌面中选择蜂窝模式对应的图标显示，格式为.bin的格式文件。

③：桌面中对应足球模式对应的图标显示，格式为.bin的格式文件。

④：组件对应的名称。

对于默认选择的图标模式，只需要更改①和④中的参数，即可修改模拟器中组件对应的图标和组件名。

### 模拟器尺寸与形状设置<a name="ZH-CN_TOPIC_0000002412436953"></a>

用户创建GUI工程后，又想重新改变画布或者模拟器的尺寸与形状，可以在工程中搜索“graphic\_config.h”文件，位于工程目录下的“application/brandy/simulator/libui”目录下，更改HORIZONTAL\_RESOLUTION、VERTICAL\_RESOLUTION以及DEVICE\_SHAPE这三个参数，分别对应模拟器的直径（长宽）以及模拟器的形状。

**图 1**  更改模拟器的尺寸与形状<a name="zh-cn_topic_0000002399739785_fig5357185214137"></a>  
![](figures/更改模拟器的尺寸与形状.png "更改模拟器的尺寸与形状")

## 图形工具介绍<a name="ZH-CN_TOPIC_0000002378717708"></a>

点击插件页面或者状态栏中的“Graphics Tools”图标。

**图 1**  插件页面或者状态栏中的“Graphics Tools”图标<a name="zh-cn_topic_0000002366100006_fig135900300384"></a>  

![](figures/zh-cn_image_0000002404301777.png)

弹出功能页签，当前包含“图片解压缩”和“视频首帧提取”两个功能。

**图 2**  “GUI图形工具”页签<a name="zh-cn_topic_0000002366100006_fig5647114212381"></a>  

![](figures/zh-cn_image_0000002488087200.png)






### 环境配置<a name="ZH-CN_TOPIC_0000002412317105"></a>

在使用“Graphics Tools”图形工具功能之前，需要配置python环境，请参考“[工具链toolchain配置](工具链toolchain配置.md#ZH-CN_TOPIC_0000002412436857)”。

python安装成功后需要安装pip的依赖模块。

-   opencv模块
-   numpy模块
-   Pillow模块
-   matplotlib模块

安装完成后可以在VS Code的安装目录下的“tools/python/Scripts”目录下打开cmd中执行“pip.exe list”，查看各依赖是否安装成功。

**图 1**  pip依赖安装校验<a name="zh-cn_topic_0000002399619917_fig138293814396"></a>  

![](figures/zh-cn_image_0000002415229650.png)

### 图片解压缩工具<a name="ZH-CN_TOPIC_0000002378877548"></a>

图片解压缩工具的功能：依据xml文件配置的压缩算法以及像素格式信息，将指定目录下的每一个子目录都打包成一个资源文件并且生成资源索引文件“ImageResources.cpp”；或者将指定目录下的每一个图片文件都打包成一个资源文件。解压模式下会将.bin文件的图片解压为.png格式的图片；压缩模式下会将.png、.jpg或者.bmp文件格式的图片压缩为.bin文件格式。

**图 1**  图片解压缩界面<a name="zh-cn_topic_0000002365940110_fig2012249183513"></a>  
![](figures/图片解压缩界面.png "图片解压缩界面")

-   脚本路径：需选择“images\_convert.py”脚本所在的文件夹路径，一般为“tools\\DebugKits\\graphic\_tools\\image\_converter\_tool”。
-   解/压缩模式：指定解压、压缩模式，默认选择压缩模式。
-   打包方式：分为文件打包方式和文件夹打包方式，默认选择文件打包方式
    -   文件打包方式：以每个图片为单位进行打包。
    -   文件夹打包方式：将图片进行打包后，再以子文件夹为单位将其包含的已打包过的图片在一起打包。

-   压缩模式：默认为手动压缩模式。
-   alpha压缩模式：0：非压缩；1：压缩。默认为1：压缩模式。
-   rgb压缩模式。0：非压缩；1：压缩。默认为1：压缩模式。
-   压缩单元宽度。4--4x4；6--6x4；8--8x4；16--16x4，也叫压缩倍率在ARGB8888格式时分别对应4倍压缩，6倍压缩，8倍压缩，16倍压缩；在RGB888时分别对应3倍压缩，4.5倍压缩，6倍压缩，12倍压缩；在RGB565时分别对应2倍压缩，3倍压缩，4倍压缩，8倍压缩。默认为6倍压缩。
-   图片输入路径：指定待处理图片的根目录，图片目录下的图片可以为“.jpg、.png、.bmp”等格式。
-   图片输出路径：指定输出的文件夹。

>![](public_sys-resources/icon-notice.gif) **须知：** 
>-   图片压缩仅支持.png、.bmp、.jpg（文件后缀不能为大写）文件的压缩，且图片分辨率大小不能超过1280\*800（宽\*高）。
>-   子文件夹名以及文件名必须为数字以及字母的组合。
>-   解/压缩模式选择为解压模式时，压缩模式、alpha压缩模式、rgb压缩模式和压缩单元宽度选项隐藏。
>-   alpha和rgb同时为0是非压缩模式请注意适配。
>-   压缩倍率是与裸数据大小进行对比，而非与源文件大小对比，例如466×466的RGBA图片，无压缩大小为848KB，6倍压缩时为142KB，16倍压缩时大约为54KB。
>-   压缩操作为有损压缩，压缩倍率越大，图损越大。

**压缩模式样例<a name="zh-cn_topic_0000002365940110_section19664105194515"></a>**

**图 2**  图片压缩具体选择样例<a name="zh-cn_topic_0000002365940110_fig611581334117"></a>  
![](figures/图片压缩具体选择样例.png "图片压缩具体选择样例")

各选项均选择后，点击完成，执行压缩功能，终端界面输显示内容如下：

**图 3**  图片压缩执行时终端界面输出<a name="zh-cn_topic_0000002365940110_fig753304214242"></a>  
![](figures/图片压缩执行时终端界面输出.png "图片压缩执行时终端界面输出")

“Conversion Success!”说明压缩成功。图片所在文件夹前后对比如下，成功将两张png格式图片转换成bin文件格式：

**图 4**  图片压缩前后效果展示<a name="zh-cn_topic_0000002365940110_fig954913529412"></a>  
![](figures/图片压缩前后效果展示.png "图片压缩前后效果展示")

![](figures/zh-cn_image_0000002366102030.png)

**解压模式样例<a name="zh-cn_topic_0000002365940110_section15836552114418"></a>**

将解/压缩模式选择为解压模式，压缩模式、alpha压缩模式、rgb压缩模式和压缩单元宽度选项隐藏。

**图 5**  图片解压具体选择样例<a name="zh-cn_topic_0000002365940110_fig7235124264318"></a>  
![](figures/图片解压具体选择样例.png "图片解压具体选择样例")

各选项均选择后，点击完成，执行解压功能，终端界面输显示内容如下：

**图 6**  图片解压执行时终端界面输出<a name="zh-cn_topic_0000002365940110_fig188091156104319"></a>  
![](figures/图片解压执行时终端界面输出.png "图片解压执行时终端界面输出")

“Decmpress Success”说明解压成功。图片所在文件夹前后对比如下，成功将两张bin格式图片解压为png文件格式：

**图 7**  图片解压前后对比<a name="zh-cn_topic_0000002365940110_fig5433744191910"></a>  
![](figures/图片解压前后对比.png "图片解压前后对比")

![](figures/zh-cn_image_0000002366102034.png)

### 视频首帧提取工具<a name="ZH-CN_TOPIC_0000002412436957"></a>

视频在未加载前，首帧为黑帧，需要用户手动设置一张起始预览图，该功能提供提取视频首帧并将其转换为BMP格式图片的能力。

**图 1**  视频首帧提取工具页面<a name="zh-cn_topic_0000002399739789_fig111561422134515"></a>  
![](figures/视频首帧提取工具页面.png "视频首帧提取工具页面")

-   脚本路径：需选择“convert\_2\_bmp.py”脚本所在的文件夹路径，一般为“tools\\DebugKits\\graphic\_tools\\convert\_2\_bmp”。
-   视频路径：需要提取的视频文件路径。
-   视频帧宽/视频帧高：指定视频帧的宽高，需要与视频资源一致，且需要用户手动输入。
-   图片生成路径：图片生成路径。

>![](public_sys-resources/icon-caution.gif) **注意：** 
>-   视频格式当前仅支持YUV444和YUV420这两种
>-   视频仅支持MJPEG编码及.mp4封装，调整视频格式及大小可借助ffmpeg工具， 例："ffmpeg -i video.mp4 -vf crop=454:454 -b:v 4228k -vcodec mjpeg out.mp4"。
>-   视频帧宽/高可以在视频的属性--\>详细信息中查看。如果视频帧宽高与实际不一致，生成的图片会产生花屏。

视频首帧提取样例：

**图 2**  视频首帧提取具体选项样例<a name="zh-cn_topic_0000002399739789_fig28171353184518"></a>  
![](figures/视频首帧提取具体选项样例.png "视频首帧提取具体选项样例")

各选项均选择后，点击完成，执行视频首帧提取功能，终端界面输显示内容如下：

**图 3**  视频首帧提取执行时终端界面输出<a name="zh-cn_topic_0000002399739789_fig1474664164615"></a>  
![](figures/视频首帧提取执行时终端界面输出.png "视频首帧提取执行时终端界面输出")

“success”说明提取成功。视频所在文件夹前后对比如下，成功将mp4格式的适配的首帧提取出来并且保存为bmp格式的图片：

**图 4**  适配转换前后对比<a name="zh-cn_topic_0000002399739789_fig7243352114711"></a>  
![](figures/适配转换前后对比.png "适配转换前后对比")

![](figures/zh-cn_image_0000002399621957.png)

### 3D建模工具<a name="ZH-CN_TOPIC_0000002378717712"></a>



#### 使用方法<a name="ZH-CN_TOPIC_0000002412317109"></a>

**运行<a name="zh-cn_topic_0000002399619921_section1992610916599"></a>**

点击COMMANDS里面的Modeling Tools，在上方选择“3D Modeling Tool”。

![](figures/zh-cn_image_0000002456945685.png)

**界面介绍<a name="zh-cn_topic_0000002399619921_section114256515596"></a>**

-   **工具启动主界面**

    启动后工具主界面如图所示：

    **图 1**  3D建模工具启动主界面<a name="zh-cn_topic_0000002399619921_fig14212923556"></a>  
    ![](figures/3D建模工具启动主界面.png "3D建模工具启动主界面")

    按钮功能介绍如下：

    -   模型类型：选择当前要使用的模型（球面：sphere；网格：mesh；平面：cylinder），会自动加载默认参数并运行。
    -   纹理导入：选择纹理素材文件。
    -   模型导入：选择模型文件。
    -   模型创建：打开子界面，进行模型参数配置并生成模型。
    -   模型导出：将工具中对应模式下生成的模型文件导出到本地。
    -   运行：运行对应模式下的用例并显示运行效果。
    -   默认参数：一键恢复所有参数到其默认值。
    -   参数导出：根据当前界面配置的模式，调整参数，获得理想效果后，可将该模式下的该组参数保存到一个文件中。
    -   显示日志/隐藏日志：打开/关闭下方的日志框。

-   **模型创建界面**

    ①mesh界面：模型选择选中网格后点击模型创建后弹出如图所示界面：

    **图 2**  mesh界面<a name="zh-cn_topic_0000002399619921_fig179479235556"></a>  
    ![](figures/mesh界面.png "mesh界面")

    ②cylinder界面，模型选择选中平面后点击模型创建后弹出如图所示界面：

    **图 3**  cylinder界面<a name="zh-cn_topic_0000002399619921_fig1460543113556"></a>  
    ![](figures/cylinder界面.png "cylinder界面")

    ③sphere界面，模型选择选中球面后点击模型创建后弹出如图所示界面：

    **图 4**  sphere界面<a name="zh-cn_topic_0000002399619921_fig18331542125514"></a>  
    ![](figures/sphere界面.png "sphere界面")

    点击保存按钮保存配置值，当点击完保存后，子窗体自动关闭。

**操作步骤<a name="zh-cn_topic_0000002399619921_section1371818221405"></a>**

-   **mesh模式：**

    mesh分为7种子模式，其中type0和type6属于强交互模式，模型在线生成，无需离线生成和载入；type1～type5属于弱交互模式，运行用例之前需要离线生成模型或者载入模型，二者选一即可。

    1.  点击主界面网格单选按钮，选中网格模式。
    2.  点击主界面模型创建按钮，进行模型参数设置。
    3.  点击type输入框进行子模式选择，并进行相关参数配置：

        type0：thr建议配置为1.0，len建议配置为5，cx、cy建议配置在非中心点位置，其它参数建议保持默认值

        type1：len建议配置为0.0，cx、cy只支持配置在中心点，其他参数建议保持默认值

        type2：len建议配置为4.52，cx、cy只支持配置在中心点，其他参数建议保持默认值

        type3：len建议配置为1，cx、cy只支持配置在中心点，其他参数建议保持默认值

        type4：len建议配置为3，cx、cy只支持配置在中心点，其他参数建议保持默认值

        type5：len建议配置为9.33，cx、cy只支持配置在中心点，其他参数建议保持默认值

        type6：thr建议配置为0.1，其他参数建议保持默认值

    4.  点击保存按钮保存，并返回主界面。
    5.  点击主界面纹理导入按钮选择纹理素材。
    6.  点击运行按钮。
    7.  拖动右侧mesh\_ctrl滑块，观察效果。

-   **cylinder模式：**
    1.  点击主界面平面单选按钮，选中cylinder模式。
    2.  点击主界面模型创建按钮，进行模型参数设置，建议使用默认值。
    3.  点击保存按钮保存，并返回主界面。
    4.  点击纹理导入按钮选择纹理素材。
    5.  点击运行按钮。
    6.  拖动右侧cylinder\_ctrl滑块（主要滑动的是cylinder\_ctl），观察效果。

-   **sphere模式：**
    1.  点击主界面球面单选按钮，选中sphere模式
    2.  点击主界面模型创建按钮，进行模型参数设置，建议使用默认值
    3.  点击保存按钮保存，并返回主界面
    4.  点击纹理导入按钮选择纹理素材
    5.  点击运行按钮
    6.  拖动右侧angel\_x、angel\_y、angel\_z三个滑块，观察效果。

**素材默认路径<a name="zh-cn_topic_0000002399619921_section88057444012"></a>**

>![](public_sys-resources/icon-notice.gif) **须知：** 
>以下路径不能删除，否则会导致程序运行错误。

-   默认纹理素材路径：C:/Users/$\{用户名\}/.vscode/extensions/hispark.hisparkstudio-$\{版本号\}/dist/source\_file/texture/

-   默认模型素材路径：C:/Users/$\{用户名\}/.vscode/extensions/hispark.hisparkstudio-$\{版本号\}/dist/source\_file/model/，即模型创建完成之后的默认保存路径
-   默认蒙版素材路径：C:/Users/$\{用户名\}/.vscode/extensions/hispark.hisparkstudio-$\{版本号\}/dist/source\_file/mask/，此路径仅供sphere模式使用，目的是使纹理与模型叠加时在连接处能够保持平滑过渡；生成的球蒙版宽高要和dst\_width/dst\_height 一致，且球蒙版为ARGB8888。
-   其中$\{用户名\}为当前Windows登录账号用户名，$\{版本号\}为本插件版本号。

#### 参数表<a name="ZH-CN_TOPIC_0000002378877552"></a>

**滚筒日历<a name="zh-cn_topic_0000002365940114_section19555544673"></a>**

**表 1**  滚筒日历模型参数

<a name="zh-cn_topic_0000002365940114_table9440155420336"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002365940114_row2587354183315"><th class="cellrowborder" valign="top" width="12.98%" id="mcps1.2.5.1.1"><p id="zh-cn_topic_0000002365940114_p165871154173319"><a name="zh-cn_topic_0000002365940114_p165871154173319"></a><a name="zh-cn_topic_0000002365940114_p165871154173319"></a>序号</p>
</th>
<th class="cellrowborder" valign="top" width="24.2%" id="mcps1.2.5.1.2"><p id="zh-cn_topic_0000002365940114_p18587205433319"><a name="zh-cn_topic_0000002365940114_p18587205433319"></a><a name="zh-cn_topic_0000002365940114_p18587205433319"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="26.3%" id="mcps1.2.5.1.3"><p id="zh-cn_topic_0000002365940114_p558755412337"><a name="zh-cn_topic_0000002365940114_p558755412337"></a><a name="zh-cn_topic_0000002365940114_p558755412337"></a>参数含义</p>
</th>
<th class="cellrowborder" valign="top" width="36.52%" id="mcps1.2.5.1.4"><p id="zh-cn_topic_0000002365940114_p6587155473316"><a name="zh-cn_topic_0000002365940114_p6587155473316"></a><a name="zh-cn_topic_0000002365940114_p6587155473316"></a>范围&amp;demo参数</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002365940114_row12587205417331"><td class="cellrowborder" valign="top" width="12.98%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000002365940114_p135878543337"><a name="zh-cn_topic_0000002365940114_p135878543337"></a><a name="zh-cn_topic_0000002365940114_p135878543337"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="24.2%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000002365940114_p15587654143310"><a name="zh-cn_topic_0000002365940114_p15587654143310"></a><a name="zh-cn_topic_0000002365940114_p15587654143310"></a>dst_width</p>
</td>
<td class="cellrowborder" valign="top" width="26.3%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000002365940114_p4587145443312"><a name="zh-cn_topic_0000002365940114_p4587145443312"></a><a name="zh-cn_topic_0000002365940114_p4587145443312"></a>屏幕的宽</p>
</td>
<td class="cellrowborder" valign="top" width="36.52%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000002365940114_p11587195473319"><a name="zh-cn_topic_0000002365940114_p11587195473319"></a><a name="zh-cn_topic_0000002365940114_p11587195473319"></a>-</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002365940114_row1758785413339"><td class="cellrowborder" valign="top" width="12.98%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000002365940114_p1558714540336"><a name="zh-cn_topic_0000002365940114_p1558714540336"></a><a name="zh-cn_topic_0000002365940114_p1558714540336"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="24.2%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000002365940114_p2587185415330"><a name="zh-cn_topic_0000002365940114_p2587185415330"></a><a name="zh-cn_topic_0000002365940114_p2587185415330"></a>dst_height</p>
</td>
<td class="cellrowborder" valign="top" width="26.3%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000002365940114_p18587125412333"><a name="zh-cn_topic_0000002365940114_p18587125412333"></a><a name="zh-cn_topic_0000002365940114_p18587125412333"></a>屏幕的高</p>
</td>
<td class="cellrowborder" valign="top" width="36.52%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000002365940114_p55871054173311"><a name="zh-cn_topic_0000002365940114_p55871054173311"></a><a name="zh-cn_topic_0000002365940114_p55871054173311"></a>-</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002365940114_row3587105412330"><td class="cellrowborder" valign="top" width="12.98%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000002365940114_p1058712545336"><a name="zh-cn_topic_0000002365940114_p1058712545336"></a><a name="zh-cn_topic_0000002365940114_p1058712545336"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="24.2%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000002365940114_p1587115423310"><a name="zh-cn_topic_0000002365940114_p1587115423310"></a><a name="zh-cn_topic_0000002365940114_p1587115423310"></a>cylinder_radius</p>
</td>
<td class="cellrowborder" valign="top" width="26.3%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000002365940114_p758725417337"><a name="zh-cn_topic_0000002365940114_p758725417337"></a><a name="zh-cn_topic_0000002365940114_p758725417337"></a>圆柱体半径</p>
</td>
<td class="cellrowborder" valign="top" width="36.52%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000002365940114_p1588195410337"><a name="zh-cn_topic_0000002365940114_p1588195410337"></a><a name="zh-cn_topic_0000002365940114_p1588195410337"></a>(0,cylinder_dst_width]; 230</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002365940114_row1858865413338"><td class="cellrowborder" valign="top" width="12.98%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000002365940114_p25882544336"><a name="zh-cn_topic_0000002365940114_p25882544336"></a><a name="zh-cn_topic_0000002365940114_p25882544336"></a>4</p>
</td>
<td class="cellrowborder" valign="top" width="24.2%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000002365940114_p155881854133320"><a name="zh-cn_topic_0000002365940114_p155881854133320"></a><a name="zh-cn_topic_0000002365940114_p155881854133320"></a>cylinder_width</p>
</td>
<td class="cellrowborder" valign="top" width="26.3%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000002365940114_p658815544331"><a name="zh-cn_topic_0000002365940114_p658815544331"></a><a name="zh-cn_topic_0000002365940114_p658815544331"></a>圆柱体宽</p>
</td>
<td class="cellrowborder" valign="top" width="36.52%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000002365940114_p1588145410335"><a name="zh-cn_topic_0000002365940114_p1588145410335"></a><a name="zh-cn_topic_0000002365940114_p1588145410335"></a>(0,cylinder_dst_height]; 230</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002365940114_row8588654143319"><td class="cellrowborder" valign="top" width="12.98%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000002365940114_p16588754123314"><a name="zh-cn_topic_0000002365940114_p16588754123314"></a><a name="zh-cn_topic_0000002365940114_p16588754123314"></a>5</p>
</td>
<td class="cellrowborder" valign="top" width="24.2%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000002365940114_p1958819542339"><a name="zh-cn_topic_0000002365940114_p1958819542339"></a><a name="zh-cn_topic_0000002365940114_p1958819542339"></a>cylinder_height</p>
</td>
<td class="cellrowborder" valign="top" width="26.3%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000002365940114_p1458845493318"><a name="zh-cn_topic_0000002365940114_p1458845493318"></a><a name="zh-cn_topic_0000002365940114_p1458845493318"></a>圆柱体高</p>
</td>
<td class="cellrowborder" valign="top" width="36.52%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000002365940114_p1558855403315"><a name="zh-cn_topic_0000002365940114_p1558855403315"></a><a name="zh-cn_topic_0000002365940114_p1558855403315"></a>(0,cylinder_dst_height]; 230</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002365940114_row65881054173318"><td class="cellrowborder" valign="top" width="12.98%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000002365940114_p458895415338"><a name="zh-cn_topic_0000002365940114_p458895415338"></a><a name="zh-cn_topic_0000002365940114_p458895415338"></a>6</p>
</td>
<td class="cellrowborder" valign="top" width="24.2%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000002365940114_p1258865418336"><a name="zh-cn_topic_0000002365940114_p1258865418336"></a><a name="zh-cn_topic_0000002365940114_p1258865418336"></a>cylinder_x_step</p>
</td>
<td class="cellrowborder" valign="top" width="26.3%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000002365940114_p105881954173311"><a name="zh-cn_topic_0000002365940114_p105881954173311"></a><a name="zh-cn_topic_0000002365940114_p105881954173311"></a>模型x方向采样步长</p>
</td>
<td class="cellrowborder" valign="top" width="36.52%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000002365940114_p058818544336"><a name="zh-cn_topic_0000002365940114_p058818544336"></a><a name="zh-cn_topic_0000002365940114_p058818544336"></a>[4 ,8];4</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002365940114_row8588135415332"><td class="cellrowborder" valign="top" width="12.98%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000002365940114_p3588754193314"><a name="zh-cn_topic_0000002365940114_p3588754193314"></a><a name="zh-cn_topic_0000002365940114_p3588754193314"></a>7</p>
</td>
<td class="cellrowborder" valign="top" width="24.2%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000002365940114_p158845483312"><a name="zh-cn_topic_0000002365940114_p158845483312"></a><a name="zh-cn_topic_0000002365940114_p158845483312"></a>cylinder_y_step</p>
</td>
<td class="cellrowborder" valign="top" width="26.3%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000002365940114_p958814542335"><a name="zh-cn_topic_0000002365940114_p958814542335"></a><a name="zh-cn_topic_0000002365940114_p958814542335"></a>模型y方向采样步长</p>
</td>
<td class="cellrowborder" valign="top" width="36.52%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000002365940114_p6588254103318"><a name="zh-cn_topic_0000002365940114_p6588254103318"></a><a name="zh-cn_topic_0000002365940114_p6588254103318"></a>[4 , 8];4</p>
</td>
</tr>
</tbody>
</table>

>![](public_sys-resources/icon-note.gif) **说明：** 
>-   cylinder\_x\_step：逻辑约束cylinder\_dst\_width / cylinder\_x\_step
>-   cylinder\_y\_step：逻辑约束cylinder\_dst\_height /cylinder\_y\_step
>注意：对于cylinder模式的素材，建议宽为屏幕的1/2，高至少为2048。

**表 2**  滚筒日历demo参数

<a name="zh-cn_topic_0000002365940114_table13448145419338"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002365940114_row185881054183311"><th class="cellrowborder" valign="top" width="14.41%" id="mcps1.2.5.1.1"><p id="zh-cn_topic_0000002365940114_p35881654133318"><a name="zh-cn_topic_0000002365940114_p35881654133318"></a><a name="zh-cn_topic_0000002365940114_p35881654133318"></a>序号</p>
</th>
<th class="cellrowborder" valign="top" width="23.16%" id="mcps1.2.5.1.2"><p id="zh-cn_topic_0000002365940114_p18588115433315"><a name="zh-cn_topic_0000002365940114_p18588115433315"></a><a name="zh-cn_topic_0000002365940114_p18588115433315"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="26.040000000000003%" id="mcps1.2.5.1.3"><p id="zh-cn_topic_0000002365940114_p135881654163320"><a name="zh-cn_topic_0000002365940114_p135881654163320"></a><a name="zh-cn_topic_0000002365940114_p135881654163320"></a>参数含义</p>
</th>
<th class="cellrowborder" valign="top" width="36.39%" id="mcps1.2.5.1.4"><p id="zh-cn_topic_0000002365940114_p175881154133315"><a name="zh-cn_topic_0000002365940114_p175881154133315"></a><a name="zh-cn_topic_0000002365940114_p175881154133315"></a>范围&amp;demo参数</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002365940114_row16588205417333"><td class="cellrowborder" valign="top" width="14.41%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000002365940114_p1158825411336"><a name="zh-cn_topic_0000002365940114_p1158825411336"></a><a name="zh-cn_topic_0000002365940114_p1158825411336"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="23.16%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000002365940114_p15588175415335"><a name="zh-cn_topic_0000002365940114_p15588175415335"></a><a name="zh-cn_topic_0000002365940114_p15588175415335"></a>angle</p>
</td>
<td class="cellrowborder" valign="top" width="26.040000000000003%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000002365940114_p13588175415334"><a name="zh-cn_topic_0000002365940114_p13588175415334"></a><a name="zh-cn_topic_0000002365940114_p13588175415334"></a>旋转角度</p>
</td>
<td class="cellrowborder" valign="top" width="36.39%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000002365940114_p1658865413318"><a name="zh-cn_topic_0000002365940114_p1658865413318"></a><a name="zh-cn_topic_0000002365940114_p1658865413318"></a>[0,360]； 0</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002365940114_row8588654173319"><td class="cellrowborder" valign="top" width="14.41%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000002365940114_p3588105415334"><a name="zh-cn_topic_0000002365940114_p3588105415334"></a><a name="zh-cn_topic_0000002365940114_p3588105415334"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="23.16%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000002365940114_p758811546331"><a name="zh-cn_topic_0000002365940114_p758811546331"></a><a name="zh-cn_topic_0000002365940114_p758811546331"></a>v_fov</p>
</td>
<td class="cellrowborder" valign="top" width="26.040000000000003%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000002365940114_p115881554113315"><a name="zh-cn_topic_0000002365940114_p115881554113315"></a><a name="zh-cn_topic_0000002365940114_p115881554113315"></a>视口</p>
</td>
<td class="cellrowborder" valign="top" width="36.39%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000002365940114_p10588454163311"><a name="zh-cn_topic_0000002365940114_p10588454163311"></a><a name="zh-cn_topic_0000002365940114_p10588454163311"></a>[0,180]； 0</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002365940114_row15588125419334"><td class="cellrowborder" valign="top" width="14.41%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000002365940114_p195891054143319"><a name="zh-cn_topic_0000002365940114_p195891054143319"></a><a name="zh-cn_topic_0000002365940114_p195891054143319"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="23.16%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000002365940114_p758985453318"><a name="zh-cn_topic_0000002365940114_p758985453318"></a><a name="zh-cn_topic_0000002365940114_p758985453318"></a>aspect_ratio</p>
</td>
<td class="cellrowborder" valign="top" width="26.040000000000003%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000002365940114_p1958925453315"><a name="zh-cn_topic_0000002365940114_p1958925453315"></a><a name="zh-cn_topic_0000002365940114_p1958925453315"></a>屏幕长宽比</p>
</td>
<td class="cellrowborder" valign="top" width="36.39%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000002365940114_p1758915548334"><a name="zh-cn_topic_0000002365940114_p1758915548334"></a><a name="zh-cn_topic_0000002365940114_p1758915548334"></a>aspect_ratio (0,1]； 1</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002365940114_row12589854183313"><td class="cellrowborder" valign="top" width="14.41%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000002365940114_p185890543339"><a name="zh-cn_topic_0000002365940114_p185890543339"></a><a name="zh-cn_topic_0000002365940114_p185890543339"></a>4</p>
</td>
<td class="cellrowborder" valign="top" width="23.16%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000002365940114_p1058920549333"><a name="zh-cn_topic_0000002365940114_p1058920549333"></a><a name="zh-cn_topic_0000002365940114_p1058920549333"></a>z_near</p>
</td>
<td class="cellrowborder" valign="top" width="26.040000000000003%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000002365940114_p16589195414334"><a name="zh-cn_topic_0000002365940114_p16589195414334"></a><a name="zh-cn_topic_0000002365940114_p16589195414334"></a>近平面</p>
</td>
<td class="cellrowborder" valign="top" width="36.39%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000002365940114_p8589175433317"><a name="zh-cn_topic_0000002365940114_p8589175433317"></a><a name="zh-cn_topic_0000002365940114_p8589175433317"></a>z_near [0,10]； 0</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002365940114_row75891854203313"><td class="cellrowborder" valign="top" width="14.41%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000002365940114_p1758914549336"><a name="zh-cn_topic_0000002365940114_p1758914549336"></a><a name="zh-cn_topic_0000002365940114_p1758914549336"></a>5</p>
</td>
<td class="cellrowborder" valign="top" width="23.16%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000002365940114_p10589155423314"><a name="zh-cn_topic_0000002365940114_p10589155423314"></a><a name="zh-cn_topic_0000002365940114_p10589155423314"></a>z_far</p>
</td>
<td class="cellrowborder" valign="top" width="26.040000000000003%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000002365940114_p1858925411336"><a name="zh-cn_topic_0000002365940114_p1858925411336"></a><a name="zh-cn_topic_0000002365940114_p1858925411336"></a>远平面</p>
</td>
<td class="cellrowborder" valign="top" width="36.39%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000002365940114_p16589754193318"><a name="zh-cn_topic_0000002365940114_p16589754193318"></a><a name="zh-cn_topic_0000002365940114_p16589754193318"></a>z_far [0,10]； 0</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002365940114_row14589205453312"><td class="cellrowborder" valign="top" width="14.41%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000002365940114_p75891054113312"><a name="zh-cn_topic_0000002365940114_p75891054113312"></a><a name="zh-cn_topic_0000002365940114_p75891054113312"></a>6</p>
</td>
<td class="cellrowborder" valign="top" width="23.16%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000002365940114_p7589135403316"><a name="zh-cn_topic_0000002365940114_p7589135403316"></a><a name="zh-cn_topic_0000002365940114_p7589135403316"></a>axis_x</p>
</td>
<td class="cellrowborder" valign="top" width="26.040000000000003%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000002365940114_p5589155423311"><a name="zh-cn_topic_0000002365940114_p5589155423311"></a><a name="zh-cn_topic_0000002365940114_p5589155423311"></a>三维空间的旋转轴x</p>
</td>
<td class="cellrowborder" valign="top" width="36.39%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000002365940114_p115891754113319"><a name="zh-cn_topic_0000002365940114_p115891754113319"></a><a name="zh-cn_topic_0000002365940114_p115891754113319"></a>[-180,180]； 0</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002365940114_row2589135433312"><td class="cellrowborder" valign="top" width="14.41%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000002365940114_p35895542331"><a name="zh-cn_topic_0000002365940114_p35895542331"></a><a name="zh-cn_topic_0000002365940114_p35895542331"></a>7</p>
</td>
<td class="cellrowborder" valign="top" width="23.16%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000002365940114_p1058985414334"><a name="zh-cn_topic_0000002365940114_p1058985414334"></a><a name="zh-cn_topic_0000002365940114_p1058985414334"></a>axis_y</p>
</td>
<td class="cellrowborder" valign="top" width="26.040000000000003%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000002365940114_p4589175418339"><a name="zh-cn_topic_0000002365940114_p4589175418339"></a><a name="zh-cn_topic_0000002365940114_p4589175418339"></a>三维空间的旋转轴y</p>
</td>
<td class="cellrowborder" valign="top" width="36.39%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000002365940114_p19589854203319"><a name="zh-cn_topic_0000002365940114_p19589854203319"></a><a name="zh-cn_topic_0000002365940114_p19589854203319"></a>[-180,180]； 0</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002365940114_row1158985493315"><td class="cellrowborder" valign="top" width="14.41%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000002365940114_p11589115493317"><a name="zh-cn_topic_0000002365940114_p11589115493317"></a><a name="zh-cn_topic_0000002365940114_p11589115493317"></a>8</p>
</td>
<td class="cellrowborder" valign="top" width="23.16%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000002365940114_p1458917549335"><a name="zh-cn_topic_0000002365940114_p1458917549335"></a><a name="zh-cn_topic_0000002365940114_p1458917549335"></a>axis_z</p>
</td>
<td class="cellrowborder" valign="top" width="26.040000000000003%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000002365940114_p13589125413331"><a name="zh-cn_topic_0000002365940114_p13589125413331"></a><a name="zh-cn_topic_0000002365940114_p13589125413331"></a>三维空间的旋转轴z</p>
</td>
<td class="cellrowborder" valign="top" width="36.39%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000002365940114_p658910548333"><a name="zh-cn_topic_0000002365940114_p658910548333"></a><a name="zh-cn_topic_0000002365940114_p658910548333"></a>[-180,180]； 0</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002365940114_row165892544337"><td class="cellrowborder" valign="top" width="14.41%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000002365940114_p1458985414333"><a name="zh-cn_topic_0000002365940114_p1458985414333"></a><a name="zh-cn_topic_0000002365940114_p1458985414333"></a>9</p>
</td>
<td class="cellrowborder" valign="top" width="23.16%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000002365940114_p125892545332"><a name="zh-cn_topic_0000002365940114_p125892545332"></a><a name="zh-cn_topic_0000002365940114_p125892545332"></a>scale_x</p>
</td>
<td class="cellrowborder" valign="top" width="26.040000000000003%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000002365940114_p18589155411334"><a name="zh-cn_topic_0000002365940114_p18589155411334"></a><a name="zh-cn_topic_0000002365940114_p18589155411334"></a>沿x轴缩放系数</p>
</td>
<td class="cellrowborder" valign="top" width="36.39%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000002365940114_p155891754193314"><a name="zh-cn_topic_0000002365940114_p155891754193314"></a><a name="zh-cn_topic_0000002365940114_p155891754193314"></a>(0,10]；1</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002365940114_row1358917549338"><td class="cellrowborder" valign="top" width="14.41%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000002365940114_p13589125493313"><a name="zh-cn_topic_0000002365940114_p13589125493313"></a><a name="zh-cn_topic_0000002365940114_p13589125493313"></a>10</p>
</td>
<td class="cellrowborder" valign="top" width="23.16%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000002365940114_p1558913549335"><a name="zh-cn_topic_0000002365940114_p1558913549335"></a><a name="zh-cn_topic_0000002365940114_p1558913549335"></a>scale_y</p>
</td>
<td class="cellrowborder" valign="top" width="26.040000000000003%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000002365940114_p8589654153310"><a name="zh-cn_topic_0000002365940114_p8589654153310"></a><a name="zh-cn_topic_0000002365940114_p8589654153310"></a>沿y轴缩放系数</p>
</td>
<td class="cellrowborder" valign="top" width="36.39%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000002365940114_p958965423314"><a name="zh-cn_topic_0000002365940114_p958965423314"></a><a name="zh-cn_topic_0000002365940114_p958965423314"></a>(0,10]；1</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002365940114_row558995412336"><td class="cellrowborder" valign="top" width="14.41%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000002365940114_p8589105423315"><a name="zh-cn_topic_0000002365940114_p8589105423315"></a><a name="zh-cn_topic_0000002365940114_p8589105423315"></a>11</p>
</td>
<td class="cellrowborder" valign="top" width="23.16%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000002365940114_p1758925412330"><a name="zh-cn_topic_0000002365940114_p1758925412330"></a><a name="zh-cn_topic_0000002365940114_p1758925412330"></a>scale_z</p>
</td>
<td class="cellrowborder" valign="top" width="26.040000000000003%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000002365940114_p155901654143315"><a name="zh-cn_topic_0000002365940114_p155901654143315"></a><a name="zh-cn_topic_0000002365940114_p155901654143315"></a>沿z轴缩放系数</p>
</td>
<td class="cellrowborder" valign="top" width="36.39%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000002365940114_p19590145463313"><a name="zh-cn_topic_0000002365940114_p19590145463313"></a><a name="zh-cn_topic_0000002365940114_p19590145463313"></a>(0,10]；1</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002365940114_row0590054193316"><td class="cellrowborder" valign="top" width="14.41%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000002365940114_p85901854113310"><a name="zh-cn_topic_0000002365940114_p85901854113310"></a><a name="zh-cn_topic_0000002365940114_p85901854113310"></a>12</p>
</td>
<td class="cellrowborder" valign="top" width="23.16%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000002365940114_p175901542333"><a name="zh-cn_topic_0000002365940114_p175901542333"></a><a name="zh-cn_topic_0000002365940114_p175901542333"></a>translation_x</p>
</td>
<td class="cellrowborder" valign="top" width="26.040000000000003%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000002365940114_p9590454133312"><a name="zh-cn_topic_0000002365940114_p9590454133312"></a><a name="zh-cn_topic_0000002365940114_p9590454133312"></a>沿x轴平移系数</p>
</td>
<td class="cellrowborder" valign="top" width="36.39%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000002365940114_p459035415339"><a name="zh-cn_topic_0000002365940114_p459035415339"></a><a name="zh-cn_topic_0000002365940114_p459035415339"></a>[-cylinder_width, cylinder_width ];-230</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002365940114_row19590115412339"><td class="cellrowborder" valign="top" width="14.41%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000002365940114_p1559016549337"><a name="zh-cn_topic_0000002365940114_p1559016549337"></a><a name="zh-cn_topic_0000002365940114_p1559016549337"></a>13</p>
</td>
<td class="cellrowborder" valign="top" width="23.16%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000002365940114_p2590135473316"><a name="zh-cn_topic_0000002365940114_p2590135473316"></a><a name="zh-cn_topic_0000002365940114_p2590135473316"></a>translation_y</p>
</td>
<td class="cellrowborder" valign="top" width="26.040000000000003%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000002365940114_p12590155418336"><a name="zh-cn_topic_0000002365940114_p12590155418336"></a><a name="zh-cn_topic_0000002365940114_p12590155418336"></a>沿y轴平移系数</p>
</td>
<td class="cellrowborder" valign="top" width="36.39%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000002365940114_p1159085413333"><a name="zh-cn_topic_0000002365940114_p1159085413333"></a><a name="zh-cn_topic_0000002365940114_p1159085413333"></a>[-cylinder_width, cylinder_width ];230</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002365940114_row0590135493314"><td class="cellrowborder" valign="top" width="14.41%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000002365940114_p1759005417330"><a name="zh-cn_topic_0000002365940114_p1759005417330"></a><a name="zh-cn_topic_0000002365940114_p1759005417330"></a>14</p>
</td>
<td class="cellrowborder" valign="top" width="23.16%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000002365940114_p1059095483312"><a name="zh-cn_topic_0000002365940114_p1059095483312"></a><a name="zh-cn_topic_0000002365940114_p1059095483312"></a>translation_z</p>
</td>
<td class="cellrowborder" valign="top" width="26.040000000000003%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000002365940114_p17590854103310"><a name="zh-cn_topic_0000002365940114_p17590854103310"></a><a name="zh-cn_topic_0000002365940114_p17590854103310"></a>沿z轴平移系数</p>
</td>
<td class="cellrowborder" valign="top" width="36.39%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000002365940114_p35901954173320"><a name="zh-cn_topic_0000002365940114_p35901954173320"></a><a name="zh-cn_topic_0000002365940114_p35901954173320"></a>[-cylinder_radius,cylinder_radius]，500</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002365940114_row20590185463311"><td class="cellrowborder" valign="top" width="14.41%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000002365940114_p6590115416332"><a name="zh-cn_topic_0000002365940114_p6590115416332"></a><a name="zh-cn_topic_0000002365940114_p6590115416332"></a>15</p>
</td>
<td class="cellrowborder" valign="top" width="23.16%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000002365940114_p959020544338"><a name="zh-cn_topic_0000002365940114_p959020544338"></a><a name="zh-cn_topic_0000002365940114_p959020544338"></a>look_from_x</p>
</td>
<td class="cellrowborder" valign="top" width="26.040000000000003%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000002365940114_p459095418332"><a name="zh-cn_topic_0000002365940114_p459095418332"></a><a name="zh-cn_topic_0000002365940114_p459095418332"></a>camera位置x轴的坐标</p>
</td>
<td class="cellrowborder" valign="top" width="36.39%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000002365940114_p8590145416339"><a name="zh-cn_topic_0000002365940114_p8590145416339"></a><a name="zh-cn_topic_0000002365940114_p8590145416339"></a>[-cylinder_radius, cylinder_radius]，-500</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002365940114_row12590115473311"><td class="cellrowborder" valign="top" width="14.41%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000002365940114_p7590205413334"><a name="zh-cn_topic_0000002365940114_p7590205413334"></a><a name="zh-cn_topic_0000002365940114_p7590205413334"></a>16</p>
</td>
<td class="cellrowborder" valign="top" width="23.16%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000002365940114_p1359045443317"><a name="zh-cn_topic_0000002365940114_p1359045443317"></a><a name="zh-cn_topic_0000002365940114_p1359045443317"></a>look_from_y</p>
</td>
<td class="cellrowborder" valign="top" width="26.040000000000003%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000002365940114_p11590554133312"><a name="zh-cn_topic_0000002365940114_p11590554133312"></a><a name="zh-cn_topic_0000002365940114_p11590554133312"></a>camera位置y轴的坐标</p>
</td>
<td class="cellrowborder" valign="top" width="36.39%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000002365940114_p15590125463312"><a name="zh-cn_topic_0000002365940114_p15590125463312"></a><a name="zh-cn_topic_0000002365940114_p15590125463312"></a>(-1000,1000)，-400</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002365940114_row115901954113311"><td class="cellrowborder" valign="top" width="14.41%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000002365940114_p959055414331"><a name="zh-cn_topic_0000002365940114_p959055414331"></a><a name="zh-cn_topic_0000002365940114_p959055414331"></a>17</p>
</td>
<td class="cellrowborder" valign="top" width="23.16%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000002365940114_p10590454163312"><a name="zh-cn_topic_0000002365940114_p10590454163312"></a><a name="zh-cn_topic_0000002365940114_p10590454163312"></a>look_from_z</p>
</td>
<td class="cellrowborder" valign="top" width="26.040000000000003%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000002365940114_p1159016541335"><a name="zh-cn_topic_0000002365940114_p1159016541335"></a><a name="zh-cn_topic_0000002365940114_p1159016541335"></a>camera位置z轴坐标</p>
</td>
<td class="cellrowborder" valign="top" width="36.39%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000002365940114_p185903542332"><a name="zh-cn_topic_0000002365940114_p185903542332"></a><a name="zh-cn_topic_0000002365940114_p185903542332"></a>(-1000, 1000)，200</p>
</td>
</tr>
</tbody>
</table>

**月相星球表盘<a name="zh-cn_topic_0000002365940114_section1102111018816"></a>**

**表 3**  月相星球表盘模型参数

<a name="zh-cn_topic_0000002365940114_table20462115423315"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002365940114_row115901354193313"><th class="cellrowborder" valign="top" width="14.149999999999999%" id="mcps1.2.5.1.1"><p id="zh-cn_topic_0000002365940114_p145901544335"><a name="zh-cn_topic_0000002365940114_p145901544335"></a><a name="zh-cn_topic_0000002365940114_p145901544335"></a>序号</p>
</th>
<th class="cellrowborder" valign="top" width="22.64%" id="mcps1.2.5.1.2"><p id="zh-cn_topic_0000002365940114_p1759045415333"><a name="zh-cn_topic_0000002365940114_p1759045415333"></a><a name="zh-cn_topic_0000002365940114_p1759045415333"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="26.56%" id="mcps1.2.5.1.3"><p id="zh-cn_topic_0000002365940114_p195901354133313"><a name="zh-cn_topic_0000002365940114_p195901354133313"></a><a name="zh-cn_topic_0000002365940114_p195901354133313"></a>参数含义</p>
</th>
<th class="cellrowborder" valign="top" width="36.65%" id="mcps1.2.5.1.4"><p id="zh-cn_topic_0000002365940114_p5590185473317"><a name="zh-cn_topic_0000002365940114_p5590185473317"></a><a name="zh-cn_topic_0000002365940114_p5590185473317"></a>范围&amp; demo参数</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002365940114_row559015413316"><td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000002365940114_p135901354143316"><a name="zh-cn_topic_0000002365940114_p135901354143316"></a><a name="zh-cn_topic_0000002365940114_p135901354143316"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="22.64%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000002365940114_p1590135415333"><a name="zh-cn_topic_0000002365940114_p1590135415333"></a><a name="zh-cn_topic_0000002365940114_p1590135415333"></a>dst_width</p>
</td>
<td class="cellrowborder" valign="top" width="26.56%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000002365940114_p7591185418339"><a name="zh-cn_topic_0000002365940114_p7591185418339"></a><a name="zh-cn_topic_0000002365940114_p7591185418339"></a>屏幕的宽</p>
</td>
<td class="cellrowborder" valign="top" width="36.65%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000002365940114_p2059135473315"><a name="zh-cn_topic_0000002365940114_p2059135473315"></a><a name="zh-cn_topic_0000002365940114_p2059135473315"></a>-</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002365940114_row1759114541331"><td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000002365940114_p45911054103312"><a name="zh-cn_topic_0000002365940114_p45911054103312"></a><a name="zh-cn_topic_0000002365940114_p45911054103312"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="22.64%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000002365940114_p105916548338"><a name="zh-cn_topic_0000002365940114_p105916548338"></a><a name="zh-cn_topic_0000002365940114_p105916548338"></a>dst_height</p>
</td>
<td class="cellrowborder" valign="top" width="26.56%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000002365940114_p2591254113316"><a name="zh-cn_topic_0000002365940114_p2591254113316"></a><a name="zh-cn_topic_0000002365940114_p2591254113316"></a>屏幕的高</p>
</td>
<td class="cellrowborder" valign="top" width="36.65%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000002365940114_p8591175420334"><a name="zh-cn_topic_0000002365940114_p8591175420334"></a><a name="zh-cn_topic_0000002365940114_p8591175420334"></a>-</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002365940114_row759115413320"><td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000002365940114_p5591205420334"><a name="zh-cn_topic_0000002365940114_p5591205420334"></a><a name="zh-cn_topic_0000002365940114_p5591205420334"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="22.64%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000002365940114_p18591175415335"><a name="zh-cn_topic_0000002365940114_p18591175415335"></a><a name="zh-cn_topic_0000002365940114_p18591175415335"></a>sphere_radius</p>
</td>
<td class="cellrowborder" valign="top" width="26.56%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000002365940114_p125914547331"><a name="zh-cn_topic_0000002365940114_p125914547331"></a><a name="zh-cn_topic_0000002365940114_p125914547331"></a>球半径</p>
</td>
<td class="cellrowborder" valign="top" width="36.65%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000002365940114_p1259118541334"><a name="zh-cn_topic_0000002365940114_p1259118541334"></a><a name="zh-cn_topic_0000002365940114_p1259118541334"></a>(0, +∞) ；150</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002365940114_row1591254163317"><td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000002365940114_p2059185413332"><a name="zh-cn_topic_0000002365940114_p2059185413332"></a><a name="zh-cn_topic_0000002365940114_p2059185413332"></a>4</p>
</td>
<td class="cellrowborder" valign="top" width="22.64%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000002365940114_p1159155493310"><a name="zh-cn_topic_0000002365940114_p1159155493310"></a><a name="zh-cn_topic_0000002365940114_p1159155493310"></a>sphere_cx</p>
</td>
<td class="cellrowborder" valign="top" width="26.56%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000002365940114_p15591205483317"><a name="zh-cn_topic_0000002365940114_p15591205483317"></a><a name="zh-cn_topic_0000002365940114_p15591205483317"></a>球心x坐标</p>
</td>
<td class="cellrowborder" valign="top" width="36.65%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000002365940114_p105911754133319"><a name="zh-cn_topic_0000002365940114_p105911754133319"></a><a name="zh-cn_topic_0000002365940114_p105911754133319"></a>(0, +∞) ；dst_surface中心</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002365940114_row155914542335"><td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000002365940114_p1359115413338"><a name="zh-cn_topic_0000002365940114_p1359115413338"></a><a name="zh-cn_topic_0000002365940114_p1359115413338"></a>5</p>
</td>
<td class="cellrowborder" valign="top" width="22.64%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000002365940114_p959105453310"><a name="zh-cn_topic_0000002365940114_p959105453310"></a><a name="zh-cn_topic_0000002365940114_p959105453310"></a>sphere_cy</p>
</td>
<td class="cellrowborder" valign="top" width="26.56%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000002365940114_p85911754123316"><a name="zh-cn_topic_0000002365940114_p85911754123316"></a><a name="zh-cn_topic_0000002365940114_p85911754123316"></a>球心y坐标</p>
</td>
<td class="cellrowborder" valign="top" width="36.65%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000002365940114_p1591185443315"><a name="zh-cn_topic_0000002365940114_p1591185443315"></a><a name="zh-cn_topic_0000002365940114_p1591185443315"></a>(0, +∞) ；dst_surface中心</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002365940114_row1259113549337"><td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000002365940114_p195914548331"><a name="zh-cn_topic_0000002365940114_p195914548331"></a><a name="zh-cn_topic_0000002365940114_p195914548331"></a>6</p>
</td>
<td class="cellrowborder" valign="top" width="22.64%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000002365940114_p1459120548337"><a name="zh-cn_topic_0000002365940114_p1459120548337"></a><a name="zh-cn_topic_0000002365940114_p1459120548337"></a>sphere_step_x</p>
</td>
<td class="cellrowborder" valign="top" width="26.56%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000002365940114_p8591115416339"><a name="zh-cn_topic_0000002365940114_p8591115416339"></a><a name="zh-cn_topic_0000002365940114_p8591115416339"></a>模型x方向采样步长</p>
</td>
<td class="cellrowborder" valign="top" width="36.65%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000002365940114_p1591175411337"><a name="zh-cn_topic_0000002365940114_p1591175411337"></a><a name="zh-cn_topic_0000002365940114_p1591175411337"></a>[4, 8];4；</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002365940114_row19591354173315"><td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000002365940114_p1591195410337"><a name="zh-cn_topic_0000002365940114_p1591195410337"></a><a name="zh-cn_topic_0000002365940114_p1591195410337"></a>7</p>
</td>
<td class="cellrowborder" valign="top" width="22.64%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000002365940114_p7591054193314"><a name="zh-cn_topic_0000002365940114_p7591054193314"></a><a name="zh-cn_topic_0000002365940114_p7591054193314"></a>sphrere_step_y</p>
</td>
<td class="cellrowborder" valign="top" width="26.56%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000002365940114_p1659116547335"><a name="zh-cn_topic_0000002365940114_p1659116547335"></a><a name="zh-cn_topic_0000002365940114_p1659116547335"></a>模型y方向采样步长</p>
</td>
<td class="cellrowborder" valign="top" width="36.65%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000002365940114_p4591175423311"><a name="zh-cn_topic_0000002365940114_p4591175423311"></a><a name="zh-cn_topic_0000002365940114_p4591175423311"></a>[4, 8];4；</p>
</td>
</tr>
</tbody>
</table>

>![](public_sys-resources/icon-note.gif) **说明：** 
>-   sphere\_step\_x：逻辑约束dst\_height / sphere\_step\_x< 128
>-   sphere\_step\_y：逻辑约束dst\_width / sphere\_step\_y < 128

**表 4**  月相星球表盘demo参数

<a name="zh-cn_topic_0000002365940114_table4468175418337"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002365940114_row4591454193316"><th class="cellrowborder" valign="top" width="14.799999999999999%" id="mcps1.2.5.1.1"><p id="zh-cn_topic_0000002365940114_p19591115473310"><a name="zh-cn_topic_0000002365940114_p19591115473310"></a><a name="zh-cn_topic_0000002365940114_p19591115473310"></a>序号</p>
</th>
<th class="cellrowborder" valign="top" width="24.34%" id="mcps1.2.5.1.2"><p id="zh-cn_topic_0000002365940114_p4591105413316"><a name="zh-cn_topic_0000002365940114_p4591105413316"></a><a name="zh-cn_topic_0000002365940114_p4591105413316"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="26.169999999999998%" id="mcps1.2.5.1.3"><p id="zh-cn_topic_0000002365940114_p9591115433319"><a name="zh-cn_topic_0000002365940114_p9591115433319"></a><a name="zh-cn_topic_0000002365940114_p9591115433319"></a>参数含义</p>
</th>
<th class="cellrowborder" valign="top" width="34.69%" id="mcps1.2.5.1.4"><p id="zh-cn_topic_0000002365940114_p259111541331"><a name="zh-cn_topic_0000002365940114_p259111541331"></a><a name="zh-cn_topic_0000002365940114_p259111541331"></a>范围&amp;demo值</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002365940114_row11591554153319"><td class="cellrowborder" valign="top" width="14.799999999999999%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000002365940114_p1959113544330"><a name="zh-cn_topic_0000002365940114_p1959113544330"></a><a name="zh-cn_topic_0000002365940114_p1959113544330"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="24.34%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000002365940114_p175924548336"><a name="zh-cn_topic_0000002365940114_p175924548336"></a><a name="zh-cn_topic_0000002365940114_p175924548336"></a>sphere_angle_x</p>
</td>
<td class="cellrowborder" valign="top" width="26.169999999999998%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000002365940114_p8592175433314"><a name="zh-cn_topic_0000002365940114_p8592175433314"></a><a name="zh-cn_topic_0000002365940114_p8592175433314"></a>沿x旋转角度</p>
</td>
<td class="cellrowborder" valign="top" width="34.69%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000002365940114_p4592145423319"><a name="zh-cn_topic_0000002365940114_p4592145423319"></a><a name="zh-cn_topic_0000002365940114_p4592145423319"></a>[0,360];0</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002365940114_row15592854163311"><td class="cellrowborder" valign="top" width="14.799999999999999%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000002365940114_p3592165418335"><a name="zh-cn_topic_0000002365940114_p3592165418335"></a><a name="zh-cn_topic_0000002365940114_p3592165418335"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="24.34%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000002365940114_p14592185473314"><a name="zh-cn_topic_0000002365940114_p14592185473314"></a><a name="zh-cn_topic_0000002365940114_p14592185473314"></a>sphere_angle_y</p>
</td>
<td class="cellrowborder" valign="top" width="26.169999999999998%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000002365940114_p659265433312"><a name="zh-cn_topic_0000002365940114_p659265433312"></a><a name="zh-cn_topic_0000002365940114_p659265433312"></a>沿y轴旋转角度</p>
</td>
<td class="cellrowborder" valign="top" width="34.69%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000002365940114_p1959214546339"><a name="zh-cn_topic_0000002365940114_p1959214546339"></a><a name="zh-cn_topic_0000002365940114_p1959214546339"></a>[0,360];0</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002365940114_row1659245411332"><td class="cellrowborder" valign="top" width="14.799999999999999%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000002365940114_p205921454103319"><a name="zh-cn_topic_0000002365940114_p205921454103319"></a><a name="zh-cn_topic_0000002365940114_p205921454103319"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="24.34%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000002365940114_p1959210549334"><a name="zh-cn_topic_0000002365940114_p1959210549334"></a><a name="zh-cn_topic_0000002365940114_p1959210549334"></a>sphere_angle_z</p>
</td>
<td class="cellrowborder" valign="top" width="26.169999999999998%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000002365940114_p759235493317"><a name="zh-cn_topic_0000002365940114_p759235493317"></a><a name="zh-cn_topic_0000002365940114_p759235493317"></a>沿z轴旋转角度</p>
</td>
<td class="cellrowborder" valign="top" width="34.69%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000002365940114_p115923542337"><a name="zh-cn_topic_0000002365940114_p115923542337"></a><a name="zh-cn_topic_0000002365940114_p115923542337"></a>[0,360];0</p>
</td>
</tr>
</tbody>
</table>

**MESH表盘互动<a name="zh-cn_topic_0000002365940114_section178548341816"></a>**

**表 5**  MESH表盘互动模型参数

<a name="zh-cn_topic_0000002365940114_table14471185473311"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002365940114_row105922547330"><th class="cellrowborder" valign="top" width="15.45%" id="mcps1.2.5.1.1"><p id="zh-cn_topic_0000002365940114_p14592125413316"><a name="zh-cn_topic_0000002365940114_p14592125413316"></a><a name="zh-cn_topic_0000002365940114_p14592125413316"></a>序号</p>
</th>
<th class="cellrowborder" valign="top" width="24.6%" id="mcps1.2.5.1.2"><p id="zh-cn_topic_0000002365940114_p65921549331"><a name="zh-cn_topic_0000002365940114_p65921549331"></a><a name="zh-cn_topic_0000002365940114_p65921549331"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="25.650000000000002%" id="mcps1.2.5.1.3"><p id="zh-cn_topic_0000002365940114_p13592155453318"><a name="zh-cn_topic_0000002365940114_p13592155453318"></a><a name="zh-cn_topic_0000002365940114_p13592155453318"></a>参数含义</p>
</th>
<th class="cellrowborder" valign="top" width="34.300000000000004%" id="mcps1.2.5.1.4"><p id="zh-cn_topic_0000002365940114_p4592105473314"><a name="zh-cn_topic_0000002365940114_p4592105473314"></a><a name="zh-cn_topic_0000002365940114_p4592105473314"></a>范围&amp;demo值</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002365940114_row1459285463317"><td class="cellrowborder" valign="top" width="15.45%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000002365940114_p659255410338"><a name="zh-cn_topic_0000002365940114_p659255410338"></a><a name="zh-cn_topic_0000002365940114_p659255410338"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="24.6%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000002365940114_p8592054113314"><a name="zh-cn_topic_0000002365940114_p8592054113314"></a><a name="zh-cn_topic_0000002365940114_p8592054113314"></a>src_width</p>
</td>
<td class="cellrowborder" valign="top" width="25.650000000000002%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000002365940114_p17592254163317"><a name="zh-cn_topic_0000002365940114_p17592254163317"></a><a name="zh-cn_topic_0000002365940114_p17592254163317"></a>素材的宽</p>
</td>
<td class="cellrowborder" valign="top" width="34.300000000000004%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000002365940114_p19592175493313"><a name="zh-cn_topic_0000002365940114_p19592175493313"></a><a name="zh-cn_topic_0000002365940114_p19592175493313"></a>建议与屏幕的宽保持一致</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002365940114_row95923541336"><td class="cellrowborder" valign="top" width="15.45%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000002365940114_p155921454133314"><a name="zh-cn_topic_0000002365940114_p155921454133314"></a><a name="zh-cn_topic_0000002365940114_p155921454133314"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="24.6%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000002365940114_p959215443320"><a name="zh-cn_topic_0000002365940114_p959215443320"></a><a name="zh-cn_topic_0000002365940114_p959215443320"></a>src_height</p>
</td>
<td class="cellrowborder" valign="top" width="25.650000000000002%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000002365940114_p85921545334"><a name="zh-cn_topic_0000002365940114_p85921545334"></a><a name="zh-cn_topic_0000002365940114_p85921545334"></a>素材的高</p>
</td>
<td class="cellrowborder" valign="top" width="34.300000000000004%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000002365940114_p259285413311"><a name="zh-cn_topic_0000002365940114_p259285413311"></a><a name="zh-cn_topic_0000002365940114_p259285413311"></a>建议与屏幕的高保持一致</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002365940114_row16592115411335"><td class="cellrowborder" valign="top" width="15.45%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000002365940114_p45929540334"><a name="zh-cn_topic_0000002365940114_p45929540334"></a><a name="zh-cn_topic_0000002365940114_p45929540334"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="24.6%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000002365940114_p1459225413331"><a name="zh-cn_topic_0000002365940114_p1459225413331"></a><a name="zh-cn_topic_0000002365940114_p1459225413331"></a>dst_width</p>
</td>
<td class="cellrowborder" valign="top" width="25.650000000000002%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000002365940114_p3592145418335"><a name="zh-cn_topic_0000002365940114_p3592145418335"></a><a name="zh-cn_topic_0000002365940114_p3592145418335"></a>屏幕的宽</p>
</td>
<td class="cellrowborder" valign="top" width="34.300000000000004%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000002365940114_p1259255463313"><a name="zh-cn_topic_0000002365940114_p1259255463313"></a><a name="zh-cn_topic_0000002365940114_p1259255463313"></a>-</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002365940114_row6593954203313"><td class="cellrowborder" valign="top" width="15.45%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000002365940114_p75931254143316"><a name="zh-cn_topic_0000002365940114_p75931254143316"></a><a name="zh-cn_topic_0000002365940114_p75931254143316"></a>4</p>
</td>
<td class="cellrowborder" valign="top" width="24.6%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000002365940114_p16593154113316"><a name="zh-cn_topic_0000002365940114_p16593154113316"></a><a name="zh-cn_topic_0000002365940114_p16593154113316"></a>dst_heigth</p>
</td>
<td class="cellrowborder" valign="top" width="25.650000000000002%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000002365940114_p45931542336"><a name="zh-cn_topic_0000002365940114_p45931542336"></a><a name="zh-cn_topic_0000002365940114_p45931542336"></a>屏幕的高</p>
</td>
<td class="cellrowborder" valign="top" width="34.300000000000004%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000002365940114_p17593145423318"><a name="zh-cn_topic_0000002365940114_p17593145423318"></a><a name="zh-cn_topic_0000002365940114_p17593145423318"></a>-</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002365940114_row159355410334"><td class="cellrowborder" valign="top" width="15.45%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000002365940114_p6593115413315"><a name="zh-cn_topic_0000002365940114_p6593115413315"></a><a name="zh-cn_topic_0000002365940114_p6593115413315"></a>5</p>
</td>
<td class="cellrowborder" valign="top" width="24.6%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000002365940114_p1959395416337"><a name="zh-cn_topic_0000002365940114_p1959395416337"></a><a name="zh-cn_topic_0000002365940114_p1959395416337"></a>mesh_x_block_num</p>
</td>
<td class="cellrowborder" valign="top" width="25.650000000000002%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000002365940114_p195931054123319"><a name="zh-cn_topic_0000002365940114_p195931054123319"></a><a name="zh-cn_topic_0000002365940114_p195931054123319"></a>水平方向划分块数量</p>
</td>
<td class="cellrowborder" valign="top" width="34.300000000000004%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000002365940114_p20593105414335"><a name="zh-cn_topic_0000002365940114_p20593105414335"></a><a name="zh-cn_topic_0000002365940114_p20593105414335"></a>(0,32];32</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002365940114_row19593115453312"><td class="cellrowborder" valign="top" width="15.45%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000002365940114_p95931454123317"><a name="zh-cn_topic_0000002365940114_p95931454123317"></a><a name="zh-cn_topic_0000002365940114_p95931454123317"></a>6</p>
</td>
<td class="cellrowborder" valign="top" width="24.6%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000002365940114_p185931954153319"><a name="zh-cn_topic_0000002365940114_p185931954153319"></a><a name="zh-cn_topic_0000002365940114_p185931954153319"></a>mesh_y_block_num</p>
</td>
<td class="cellrowborder" valign="top" width="25.650000000000002%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000002365940114_p13593185418335"><a name="zh-cn_topic_0000002365940114_p13593185418335"></a><a name="zh-cn_topic_0000002365940114_p13593185418335"></a>垂直方向划分块数量</p>
</td>
<td class="cellrowborder" valign="top" width="34.300000000000004%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000002365940114_p45931545332"><a name="zh-cn_topic_0000002365940114_p45931545332"></a><a name="zh-cn_topic_0000002365940114_p45931545332"></a>(0,32];32</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002365940114_row1259314540335"><td class="cellrowborder" valign="top" width="15.45%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000002365940114_p195931154143312"><a name="zh-cn_topic_0000002365940114_p195931154143312"></a><a name="zh-cn_topic_0000002365940114_p195931154143312"></a>7</p>
</td>
<td class="cellrowborder" valign="top" width="24.6%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000002365940114_p1359345419339"><a name="zh-cn_topic_0000002365940114_p1359345419339"></a><a name="zh-cn_topic_0000002365940114_p1359345419339"></a>mesh_cx</p>
</td>
<td class="cellrowborder" valign="top" width="25.650000000000002%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000002365940114_p559315413337"><a name="zh-cn_topic_0000002365940114_p559315413337"></a><a name="zh-cn_topic_0000002365940114_p559315413337"></a>形变中心点x坐标</p>
</td>
<td class="cellrowborder" valign="top" width="34.300000000000004%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000002365940114_p3207730201312"><a name="zh-cn_topic_0000002365940114_p3207730201312"></a><a name="zh-cn_topic_0000002365940114_p3207730201312"></a>弱互动：mesh_dst_width / 2</p>
<p id="zh-cn_topic_0000002365940114_p115931454113310"><a name="zh-cn_topic_0000002365940114_p115931454113310"></a><a name="zh-cn_topic_0000002365940114_p115931454113310"></a>强互动建议在[0,mesh_dst_width)</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002365940114_row1259335414335"><td class="cellrowborder" valign="top" width="15.45%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000002365940114_p15593554133315"><a name="zh-cn_topic_0000002365940114_p15593554133315"></a><a name="zh-cn_topic_0000002365940114_p15593554133315"></a>8</p>
</td>
<td class="cellrowborder" valign="top" width="24.6%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000002365940114_p359395418333"><a name="zh-cn_topic_0000002365940114_p359395418333"></a><a name="zh-cn_topic_0000002365940114_p359395418333"></a>mesh_cy</p>
</td>
<td class="cellrowborder" valign="top" width="25.650000000000002%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000002365940114_p1593754173320"><a name="zh-cn_topic_0000002365940114_p1593754173320"></a><a name="zh-cn_topic_0000002365940114_p1593754173320"></a>形变中心点y坐标</p>
</td>
<td class="cellrowborder" valign="top" width="34.300000000000004%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000002365940114_p986613280132"><a name="zh-cn_topic_0000002365940114_p986613280132"></a><a name="zh-cn_topic_0000002365940114_p986613280132"></a>弱互动：mesh_dst_height / 2</p>
<p id="zh-cn_topic_0000002365940114_p125931854203313"><a name="zh-cn_topic_0000002365940114_p125931854203313"></a><a name="zh-cn_topic_0000002365940114_p125931854203313"></a>强互动建议在[0,mesh_dst_height)</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002365940114_row15593454133310"><td class="cellrowborder" valign="top" width="15.45%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000002365940114_p175931954143320"><a name="zh-cn_topic_0000002365940114_p175931954143320"></a><a name="zh-cn_topic_0000002365940114_p175931954143320"></a>9</p>
</td>
<td class="cellrowborder" valign="top" width="24.6%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000002365940114_p3593115416333"><a name="zh-cn_topic_0000002365940114_p3593115416333"></a><a name="zh-cn_topic_0000002365940114_p3593115416333"></a>mesh_len</p>
</td>
<td class="cellrowborder" valign="top" width="25.650000000000002%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000002365940114_p1759316549330"><a name="zh-cn_topic_0000002365940114_p1759316549330"></a><a name="zh-cn_topic_0000002365940114_p1759316549330"></a>形变程度</p>
</td>
<td class="cellrowborder" valign="top" width="34.300000000000004%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000002365940114_p759365443318"><a name="zh-cn_topic_0000002365940114_p759365443318"></a><a name="zh-cn_topic_0000002365940114_p759365443318"></a>[0,10]；</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002365940114_row359315547335"><td class="cellrowborder" valign="top" width="15.45%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000002365940114_p13593254183312"><a name="zh-cn_topic_0000002365940114_p13593254183312"></a><a name="zh-cn_topic_0000002365940114_p13593254183312"></a>10</p>
</td>
<td class="cellrowborder" valign="top" width="24.6%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000002365940114_p559325417331"><a name="zh-cn_topic_0000002365940114_p559325417331"></a><a name="zh-cn_topic_0000002365940114_p559325417331"></a>mesh_thr</p>
</td>
<td class="cellrowborder" valign="top" width="25.650000000000002%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000002365940114_p15593155463319"><a name="zh-cn_topic_0000002365940114_p15593155463319"></a><a name="zh-cn_topic_0000002365940114_p15593155463319"></a>形变阈值</p>
</td>
<td class="cellrowborder" valign="top" width="34.300000000000004%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000002365940114_p75937548334"><a name="zh-cn_topic_0000002365940114_p75937548334"></a><a name="zh-cn_topic_0000002365940114_p75937548334"></a>[0,10]；</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002365940114_row12593175413336"><td class="cellrowborder" valign="top" width="15.45%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000002365940114_p2593125453317"><a name="zh-cn_topic_0000002365940114_p2593125453317"></a><a name="zh-cn_topic_0000002365940114_p2593125453317"></a>11</p>
</td>
<td class="cellrowborder" valign="top" width="24.6%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000002365940114_p959413544336"><a name="zh-cn_topic_0000002365940114_p959413544336"></a><a name="zh-cn_topic_0000002365940114_p959413544336"></a>mesh_type</p>
</td>
<td class="cellrowborder" valign="top" width="25.650000000000002%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000002365940114_p85942054163319"><a name="zh-cn_topic_0000002365940114_p85942054163319"></a><a name="zh-cn_topic_0000002365940114_p85942054163319"></a>mesh模型类别</p>
</td>
<td class="cellrowborder" valign="top" width="34.300000000000004%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000002365940114_p1459417542333"><a name="zh-cn_topic_0000002365940114_p1459417542333"></a><a name="zh-cn_topic_0000002365940114_p1459417542333"></a>支持[0,6]共7种模型，其中type=0/6为强互动模型</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002365940114_row2594165413312"><td class="cellrowborder" valign="top" width="15.45%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000002365940114_p1159415548334"><a name="zh-cn_topic_0000002365940114_p1159415548334"></a><a name="zh-cn_topic_0000002365940114_p1159415548334"></a>12</p>
</td>
<td class="cellrowborder" valign="top" width="24.6%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000002365940114_p259417540332"><a name="zh-cn_topic_0000002365940114_p259417540332"></a><a name="zh-cn_topic_0000002365940114_p259417540332"></a>region_w</p>
</td>
<td class="cellrowborder" valign="top" width="25.650000000000002%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000002365940114_p15941254143320"><a name="zh-cn_topic_0000002365940114_p15941254143320"></a><a name="zh-cn_topic_0000002365940114_p15941254143320"></a>动画显示区域宽度</p>
</td>
<td class="cellrowborder" valign="top" width="34.300000000000004%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000002365940114_p15594854143312"><a name="zh-cn_topic_0000002365940114_p15594854143312"></a><a name="zh-cn_topic_0000002365940114_p15594854143312"></a>[0,32]</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002365940114_row9594105453317"><td class="cellrowborder" valign="top" width="15.45%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000002365940114_p15594105483315"><a name="zh-cn_topic_0000002365940114_p15594105483315"></a><a name="zh-cn_topic_0000002365940114_p15594105483315"></a>13</p>
</td>
<td class="cellrowborder" valign="top" width="24.6%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000002365940114_p359465417338"><a name="zh-cn_topic_0000002365940114_p359465417338"></a><a name="zh-cn_topic_0000002365940114_p359465417338"></a>region_h</p>
</td>
<td class="cellrowborder" valign="top" width="25.650000000000002%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000002365940114_p1459495415334"><a name="zh-cn_topic_0000002365940114_p1459495415334"></a><a name="zh-cn_topic_0000002365940114_p1459495415334"></a>动画显示区域高度</p>
</td>
<td class="cellrowborder" valign="top" width="34.300000000000004%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000002365940114_p25941054123312"><a name="zh-cn_topic_0000002365940114_p25941054123312"></a><a name="zh-cn_topic_0000002365940114_p25941054123312"></a>[0,32]</p>
</td>
</tr>
</tbody>
</table>

>![](public_sys-resources/icon-note.gif) **说明：** 
>-   mesh\_x\_block\_num：逻辑约束mesh\_dst\_width / x\_step < 128， 软算法性能约束不超过32。
>-   mesh\_y\_block\_num：逻辑约束mesh\_dst\_height / y\_step < 128， 软算法性能约束不超过32。
>弱互动：只转动表冠；需要载入模型。
>强互动：支持触屏；不需要载入模型。

**表 6**  MESH表盘互动demo参数

<a name="zh-cn_topic_0000002365940114_table1148016549337"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002365940114_row659465413334"><th class="cellrowborder" valign="top" width="18.45%" id="mcps1.2.5.1.1"><p id="zh-cn_topic_0000002365940114_p1559495412335"><a name="zh-cn_topic_0000002365940114_p1559495412335"></a><a name="zh-cn_topic_0000002365940114_p1559495412335"></a>序号</p>
</th>
<th class="cellrowborder" valign="top" width="25.119999999999997%" id="mcps1.2.5.1.2"><p id="zh-cn_topic_0000002365940114_p7594654103317"><a name="zh-cn_topic_0000002365940114_p7594654103317"></a><a name="zh-cn_topic_0000002365940114_p7594654103317"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="31.430000000000003%" id="mcps1.2.5.1.3"><p id="zh-cn_topic_0000002365940114_p185945548335"><a name="zh-cn_topic_0000002365940114_p185945548335"></a><a name="zh-cn_topic_0000002365940114_p185945548335"></a>解释</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.4"><p id="zh-cn_topic_0000002365940114_p85941754143315"><a name="zh-cn_topic_0000002365940114_p85941754143315"></a><a name="zh-cn_topic_0000002365940114_p85941754143315"></a>范围&amp;demo值</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002365940114_row759412543330"><td class="cellrowborder" valign="top" width="18.45%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000002365940114_p059455410332"><a name="zh-cn_topic_0000002365940114_p059455410332"></a><a name="zh-cn_topic_0000002365940114_p059455410332"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="25.119999999999997%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000002365940114_p959414548337"><a name="zh-cn_topic_0000002365940114_p959414548337"></a><a name="zh-cn_topic_0000002365940114_p959414548337"></a>mesh_ctl</p>
</td>
<td class="cellrowborder" valign="top" width="31.430000000000003%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000002365940114_p1659414543335"><a name="zh-cn_topic_0000002365940114_p1659414543335"></a><a name="zh-cn_topic_0000002365940114_p1659414543335"></a>连续帧控制</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000002365940114_p3594154113313"><a name="zh-cn_topic_0000002365940114_p3594154113313"></a><a name="zh-cn_topic_0000002365940114_p3594154113313"></a>[0,10];</p>
</td>
</tr>
</tbody>
</table>

### 蒙版工具<a name="ZH-CN_TOPIC_0000002412436961"></a>

蒙版制作工具支持展示/生成圆形、高斯模糊、HSV三种蒙版文件。




#### 使用方法<a name="ZH-CN_TOPIC_0000002378717716"></a>

**运行<a name="zh-cn_topic_0000002366100014_section17318245565"></a>**

点击COMMANDS里面的Modeling Tools，在上方选择“Mask Tool”。

![](figures/zh-cn_image_0000002423227462.png)

**界面介绍<a name="zh-cn_topic_0000002366100014_section1021463835619"></a>**

启动后工具主界面如图所示：

**图 1**  蒙版工具启动界面<a name="zh-cn_topic_0000002366100014_fig39911508561"></a>  
![](figures/蒙版工具启动界面.png "蒙版工具启动界面")

其中按钮功能介绍如下：

-   模型类型：选择当前要使用的模型（高斯蒙版、圆形截图蒙版、HSV蒙版）
-   生成蒙版：在界面左侧区域生成蒙版图片
-   保存蒙版：保存蒙版文件。
-   显示日志/隐藏日志：打开/关闭下方的日志框

**操作步骤<a name="zh-cn_topic_0000002366100014_section17766850105615"></a>**

1.  选择模型类型
2.  修改右侧控制参数（可选）
3.  点击“生成蒙版” 查看效果
4.  点击“保存蒙版”保存蒙版文件

**素材默认路径<a name="zh-cn_topic_0000002366100014_section1982618594564"></a>**

HSV蒙版生成需要依赖素材文件。工具已提供默认素材文件，用户可自行替换。素材文件路径和文件名如下：

C:/Users/$\{用户名\}/.vscode/extensions/hispark.hisparkstudio-$\{版本号\}/dist/resources/mask/mask\_test/res/input/hsv\_img\_w454\_h454.data

其中$\{用户名\}为当前Windows登录账号用户名，$\{版本号\}为本插件版本号。

>![](public_sys-resources/icon-notice.gif) **须知：** 
>**注意：该文件不能删除或修改文件名，否则会导致程序运行错误**。

**高斯蒙版路径参数生成方法<a name="zh-cn_topic_0000002366100014_section710141005719"></a>**

1.  打开网址：[https://www.jyshare.com/more/svgeditor/](https://www.jyshare.com/more/svgeditor/)
2.  绘制图形：目前只支持以path开头的图形。
3.  注意：绘制图形时，需要在未选中图形的时候，在最右侧设置分辨率。
4.  点击菜单栏-\>视图-\>源代码。
5.  复制path中的“d=”之后的字符串到路径。

#### 控制参数<a name="ZH-CN_TOPIC_0000002412317113"></a>

路径：字符串（仅高斯蒙版模式需要）

宽度：素材width（最大640）

高度：素材height（最大600）

通道：素材channel（只支持3：RGB， 4：ARGB）

#### 注意事项<a name="ZH-CN_TOPIC_0000002378877556"></a>

-   只有高斯蒙版需要路径，其他两个模式下路径默认为空。
-   圆形截图蒙版只支持正圆。
-   HSV蒙版工具目前不支持RGB格式。

## GUI工程使用常见问题<a name="ZH-CN_TOPIC_0000002412436965"></a>


### 起模拟器日志记录位置<a name="ZH-CN_TOPIC_0000002378717720"></a>

在起模拟器运行过程中的日志信息记录在当前打开的工程根目录下的“simulator\_build/error.txt”文件中。可参考“[11.2.1章节](Demo运行.md#ZH-CN_TOPIC_0000002378717704)”。

# 高阶分析功能使用<a name="ZH-CN_TOPIC_0000002412317117"></a>



## 功能<a name="ZH-CN_TOPIC_0000002378877560"></a>

FBB系列工程支持高阶分析功能，具体如下：

-   支持内存统计功能，可显示每个目录每个文件的具体内存信息，且支持按内存区域以及符号类型筛选。
-   支持将当前内存统计保存为基线版本，支持将当前内存统计与基线版本做比较。
-   支持将内存统计导出为JSON/HTML文件，可在设置里配置“导出格式”以及“导出路径”。
-   支持解析cpu trace日志。
-   支持解析cpu trace 二进制文件。
-   支持解析malloc trace日志（支持BS20、BS20C、BS21、BS21A、BS21E、BS22、BS25和BS26系列芯片）。
-   支持解析irq trace日志。

## 功能演示<a name="ZH-CN_TOPIC_0000002412436969"></a>






### 内存统计功能<a name="ZH-CN_TOPIC_0000002378717724"></a>

FBB系列工程经过编译生成output目录后，单击右下角Analysis按钮，在弹出的菜单栏中选择内存统计（有时此窗口弹出较慢，请耐心等待），如[内存统计功能](内存统计功能.md#ZH-CN_TOPIC_0000002378717724)所示。

**图 1**  打开内存统计功能<a name="zh-cn_topic_0000002293383866_fig10508109124015"></a>  
![](figures/打开内存统计功能.png "打开内存统计功能")

选择对应的target即可统计内存，内存统计界面如[图2](#zh-cn_topic_0000002293383866_fig642651812595)所示。

**图 2**  内存统计功能展示<a name="zh-cn_topic_0000002293383866_fig642651812595"></a>  
![](figures/内存统计功能展示.png "内存统计功能展示")

### 基线对比功能<a name="ZH-CN_TOPIC_0000002412317121"></a>

可快速对比更改代码前后的内存占用情况：

1.  单击保存为基线按钮，将当前内存保存为基线。
2.  修改代码或者切换target。
3.  刷新统计。
4.  单击对比按钮，如[图1](#zh-cn_topic_0000002293224194_fig948185817020)所示，对比结果示例如[图2](#zh-cn_topic_0000002293224194_fig68321937318)所示。

    **图 1**  保存基线版本和与基线版本对比按钮<a name="zh-cn_topic_0000002293224194_fig948185817020"></a>  
    ![](figures/保存基线版本和与基线版本对比按钮.png "保存基线版本和与基线版本对比按钮")

    **图 2**  与基线版本对比结果示例<a name="zh-cn_topic_0000002293224194_fig68321937318"></a>  
    ![](figures/与基线版本对比结果示例.png "与基线版本对比结果示例")

### CPU Trace 日志解析功能<a name="ZH-CN_TOPIC_0000002378877564"></a>

芯片死机时通常会通过串口打印出死机日志，其中包含cpu\_trace信息（即死机前一段时间的函数调用链）。

按照“[内存统计功能](内存统计功能.md#ZH-CN_TOPIC_0000002378717724)”步骤，单击右下角cfbb按钮，在弹出的菜单栏中选择Cpu Trace，选择对应的target，将死机时打印的cpu\_trace日志复制到文本框，再点击Trace按钮即可，如[图1](#zh-cn_topic_0000002327223553_fig2078817371822)所示。

**图 1**  Cpu Trace功能<a name="zh-cn_topic_0000002327223553_fig2078817371822"></a>  
![](figures/Cpu-Trace功能.png "Cpu-Trace功能")

### 堆内存占用情况统计（BS2X和BS25系列芯片适用）<a name="ZH-CN_TOPIC_0000002412436973"></a>

此功能可以解析堆内存维测日志，快速分析出堆内存的占用情况。

1.  单击右下角Analysis按钮。
2.  在弹出的菜单栏中选择Malloc Trace，选择对应的target，要打开堆内存维测，只需点击图示中的按钮即可，需要rebuild，使能后串口发送AT指令 AT+TASKMALLOC= \(指令后跟的参数是taskid\)或者调用print\_os\_all\_sys\_task\_heap即可打印出堆内存维测日志。

    **图 1**  Malloc Trace功能<a name="zh-cn_topic_0000002327183813_fig02211941443"></a>  
    ![](figures/Malloc-Trace功能.png "Malloc-Trace功能")

3.  将堆内存维测日志复制到文本框中。
4.  单击Trace按钮即可显示出统计图，如[图2](#zh-cn_topic_0000002327183813_fig1836521310443)所示。

    **图 2**  与基线版本对比结果示例<a name="zh-cn_topic_0000002327183813_fig1836521310443"></a>  
    ![](figures/与基线版本对比结果示例-64.png "与基线版本对比结果示例-64")

### 锁中断时间统计以及中断函数执行时间统计维测<a name="ZH-CN_TOPIC_0000002378717728"></a>

**打开锁中断维测<a name="zh-cn_topic_0000002293383870_section6996192714500"></a>**

要打开锁中断维测，需要在sdk根目录的“kernel/osal\_adapter/CMakeLists.txt”文件的图示位置添加“set\(PUBLIC\_DEFINESOSAL\_IRQ\_RECORD\_INTTER OSAL\_IRQ\_RECORD\_DEBUG\) ”， 注意：需要rebuild。

**图 1**  CMakeLists.txt修改<a name="zh-cn_topic_0000002293383870_fig1883953718473"></a>  
![](figures/CMakeLists-txt修改.png "CMakeLists-txt修改")

**使用锁中断维测<a name="zh-cn_topic_0000002293383870_section470364455017"></a>**

-   调用“osal\_irq\_record\_flag\_set\(\)”接口即可使能/失能锁中断维测，其参数为0～3，参数说明如下：

    0：失能中断维测；

    1：使能锁中断时间统计维测；

    2：使能中断函数执行时间统计维测；

    3：使能锁中断和中断函数执行时间统计维测。

-   调用“osal\_print\_irq\_record\(\)”接口即可打印出记录的维测信息，其参数为空。

**解析维测信息<a name="zh-cn_topic_0000002293383870_section6885916125218"></a>**

1.  单击右下角cfbb按钮。
2.  在弹出的菜单栏中选择Irq Trace。
3.  选择对应的target。
4.  将维测日志复制到文本框，单击“Trace”按钮即可。

**图 2**  Irq Trace功能<a name="zh-cn_topic_0000002293383870_fig15230162419526"></a>  
![](figures/Irq-Trace功能.png "Irq-Trace功能")

# 常见错误<a name="ZH-CN_TOPIC_0000002412317125"></a>







## SDK根目录路径过长<a name="ZH-CN_TOPIC_0000002378877568"></a>

SDK根目录路径过长：

Windows10和Windows11下路径有260Byte的长度限制，过长的路径会导致编译时相关文件无法找到或者编译的时候一直循环某些打印信息，而不执行具体的编译内容,建议SDK代码放到盘符的根目录或缩短SDK存放路径。

**图 1**  SDK根目录路径过长<a name="zh-cn_topic_0000002293383942_fig13895175443715"></a>  
![](figures/SDK根目录路径过长.png "SDK根目录路径过长")

## 路径失效<a name="ZH-CN_TOPIC_0000002412436977"></a>

导入工程路径问题导致的调试、栈分析、镜像分析等默认路径失效。

-   调试：修改默认的debug\_elf路径。

    **图 1**  修改默认debug\_elf路径<a name="zh-cn_topic_0000002293224282_fig1326371603814"></a>  
    ![](figures/修改默认debug_elf路径.png "修改默认debug_elf路径")

## 编译或者执行系统配置功能过程中提示python或者其他依赖出错<a name="ZH-CN_TOPIC_0000002378717732"></a>

编译或者执行系统配置功能过程中提示python环境出错：

**图 1**  python环境出错弹窗<a name="zh-cn_topic_0000002327183901_fig155352138378"></a>  
![](figures/python环境出错弹窗.png "python环境出错弹窗")

或者提示内容为“本地没有安装python”或者“本地安装的python不可用”这种错误，原因为本地没有安装python或者安装的python版本不为3.11.4，为不影响编译或者系统配置功能的正常使用，建议参考2.4章中的配置python环境下载python3.11.4的安装包并手动安装，安装过程中勾选“pip”和“tcl/tk选项”。

编译或者执行系统配置功能过程中提示XX组件下载失败：

**图 2**  pip组件下载失败弹窗<a name="zh-cn_topic_0000002327183901_fig2582192913375"></a>  
![](figures/pip组件下载失败弹窗.png "pip组件下载失败弹窗")

或者cmake、pycparser、kconfiglib或者pillow下载失败。原因为执行编译或者系统配置功能时需要通过安装的python的pip组件进行下载所需依赖失败，可能是本地环境原因导致pip install失败或者当前没有网络连接导致下载失败。

解决方法：根据对应提示的组件下载失败，下载对应组件的whl文件，组件与下载链接对应关系如下：

cmake：[https://files.pythonhosted.org/packages/65/7f/80cf681cd376834b442af8af48e6f17b4197d20b7255aa2f76d8d93a9e44/cmake-3.20.5-py2.py3-none-win\_amd64.whl](https://files.pythonhosted.org/packages/65/7f/80cf681cd376834b442af8af48e6f17b4197d20b7255aa2f76d8d93a9e44/cmake-3.20.5-py2.py3-none-win_amd64.whl)

pycparser：[https://files.pythonhosted.org/packages/62/d5/5f610ebe421e85889f2e55e33b7f9a6795bd982198517d912eb1c76e1a53/pycparser-2.21-py2.py3-none-any.whl](https://files.pythonhosted.org/packages/62/d5/5f610ebe421e85889f2e55e33b7f9a6795bd982198517d912eb1c76e1a53/pycparser-2.21-py2.py3-none-any.whl)

kconfiglib：[https://files.pythonhosted.org/packages/8a/f1/d98a89231e779b079b977590efcc31249d959c8f1d4b5858cad69695ff9c/kconfiglib-14.1.0-py2.py3-none-any.whl](https://files.pythonhosted.org/packages/8a/f1/d98a89231e779b079b977590efcc31249d959c8f1d4b5858cad69695ff9c/kconfiglib-14.1.0-py2.py3-none-any.whl)

windows\_curses：[https://files.pythonhosted.org/packages/18/1b/e06eb41dad1c74f0d3124218084f258f73a5e76c67112da0ba174162670f/windows\_curses-2.3.3-cp311-cp311-win\_amd64.whl](https://files.pythonhosted.org/packages/18/1b/e06eb41dad1c74f0d3124218084f258f73a5e76c67112da0ba174162670f/windows_curses-2.3.3-cp311-cp311-win_amd64.whl)

pillow：

[https://files.pythonhosted.org/packages/c1/d0/5866318eec2b801cdb8c82abf190c8343d8a1cd8bf5a0c17444a6f268291/pillow-10.4.0-cp311-cp311-win\_amd64.whl](https://files.pythonhosted.org/packages/c1/d0/5866318eec2b801cdb8c82abf190c8343d8a1cd8bf5a0c17444a6f268291/pillow-10.4.0-cp311-cp311-win_amd64.whl)

下载完成后，在文件所在目录（建议存放在python3.11.4的安装目录）打开命令提示符（cmd），执行命令“pip install  对应的whl文件”，以cmake和windows\_curses举例：

**图 3**  下载whl文件举例<a name="zh-cn_topic_0000002327183901_fig8902128123817"></a>  
![](figures/下载whl文件举例.png "下载whl文件举例")

执行的命令：

**图 4**  执行pip install命令<a name="zh-cn_topic_0000002327183901_fig1058514345386"></a>  
![](figures/执行pip-install命令.png "执行pip-install命令")

检验是否执行成功，cmake可以打开命令提示符，执行“cmake --version”，如果有对应版本号出现，则说明cmake下载成功，其余组件可以通过执行“pip show 组件名”，如果有对应组件的信息出现，则说明各依赖下载成功：

**图 5**  依赖下载成功检测<a name="zh-cn_topic_0000002327183901_fig15897171463910"></a>  
![](figures/依赖下载成功检测.png "依赖下载成功检测")

如果环境均配置成功但是编译失败，并且提示“is the command line too long”的错误，则说明cmake版本与所需版本不符合，需要在python3.11.4的安装目录下下载cmake-3.20.5-py2.py3-none-win\_amd64.whl并在该目录下执行“pip install  下载的cmake的whl文件”即可。

下载链接：

[https://files.pythonhosted.org/packages/65/7f/80cf681cd376834b442af8af48e6f17b4197d20b7255aa2f76d8d93a9e44/cmake-3.20.5-py2.py3-none-win\_amd64.whl](https://files.pythonhosted.org/packages/65/7f/80cf681cd376834b442af8af48e6f17b4197d20b7255aa2f76d8d93a9e44/cmake-3.20.5-py2.py3-none-win_amd64.whl)

**图 6**  提示is the command line too long<a name="zh-cn_topic_0000002327183901_fig57321230113917"></a>  
![](figures/提示is-the-command-line-too-long.png "提示is-the-command-line-too-long")

如果Python环境正常，但是执行pip install 组件的时候失败：

**图 7**  执行pip install失败<a name="zh-cn_topic_0000002327183901_fig10490436153913"></a>  
![](figures/执行pip-install失败.png "执行pip-install失败")

原因为pip的版本与Python版本不一致，即Python 3.11.4或者其他合规版本的python环境变量添加至环境变量，对应的Python安装目录下的Python311\\Scripts的环境变量没有添加。可手动将Python\\Scripts的环境变量也添加到环境变量头部，下载pip的依赖成功后，再关闭所有VS Code窗口再打开。

**图 8**  添加python311的环境变量<a name="zh-cn_topic_0000002327183901_fig227546143910"></a>  
![](figures/添加python311的环境变量.png "添加python311的环境变量")

## Kconfig Jump to弹框中搜索报错"NameError: name 're' is not defined"<a name="ZH-CN_TOPIC_0000002412317129"></a>

1.  打开Kconfig后，单击“Jump to...”按钮，在弹框中搜索相关内容。

    **图 1**  从Jump to打开搜索框<a name="zh-cn_topic_0000002293383962_fig252132311619"></a>  
    ![](figures/从Jump-to打开搜索框.png "从Jump-to打开搜索框")

2.  若出现如下异常打印：

    **图 2**  Kconfig异常打印<a name="zh-cn_topic_0000002293383962_fig17981081134"></a>  
    ![](figures/Kconfig异常打印.png "Kconfig异常打印")

    需要修改“guiconfig.py”文件：在调用re模块前，添加import re，如[图3](#zh-cn_topic_0000002293383962_fig23065516141)所示。

    **图 3**  添加import re<a name="zh-cn_topic_0000002293383962_fig23065516141"></a>  
    ![](figures/添加import-re.png "添加import-re")

3.  添加代码之后可正常搜索，如[图4](#zh-cn_topic_0000002293383962_fig1265846121315)所示。

    **图 4**  正常搜索示意图<a name="zh-cn_topic_0000002293383962_fig1265846121315"></a>  
    ![](figures/正常搜索示意图.png "正常搜索示意图")

## 编译报错“Invalid argument”<a name="ZH-CN_TOPIC_0000002378877572"></a>

编译过程中如果报错“Invalid argument”。

**图 1**  ws63编译报错“Invalid argument”<a name="zh-cn_topic_0000002304197682_fig1489361241813"></a>  
![](figures/ws63编译报错-Invalid-argument.png "ws63编译报错-Invalid-argument")

报错原因：解析elf时由于没有管理员权限；解决方法：用管理员权限打开VS Code再次进行编译。

## Python环境检查报错<a name="ZH-CN_TOPIC_0000002412436981"></a>

**图 1**  Python环境检查报错<a name="zh-cn_topic_0000002339901405_fig1449715297549"></a>  
![](figures/Python环境检查报错.jpg "Python环境检查报错")

如果在安装Python的时候报错，如上图所示，可以在cmd中执行“Python --version”以及查看环境变量，查看Python是否被正确安装，如果问题还是没解决，可以查看VS Code中是否安装其余插件与之冲突，可以将其余插件禁用排查。

