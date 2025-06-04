# 前言<a name="ZH-CN_TOPIC_0000001926760082"></a>

**概述<a name="section669mcpsimp"></a>**

BS2X发布版本中蓝牙和星闪SDK接口变化说明。

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

**读者对象<a name="section694mcpsimp"></a>**

本文档主要适用以下工程师：

-   技术支持工程师
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
<tbody><tr id="row1372280416410"><td class="cellrowborder" valign="top" width="20.580000000000002%" headers="mcps1.1.3.1.1 "><p id="p3734547016410"><a name="p3734547016410"></a><a name="p3734547016410"></a><a name="image2670064316410"></a><a name="image2670064316410"></a><span><img class="" id="image2670064316410" height="25.270000000000003" width="67.83" src="figures/zh-cn_image_0000001926919442.png"></span></p>
</td>
<td class="cellrowborder" valign="top" width="79.42%" headers="mcps1.1.3.1.2 "><p id="p1757432116410"><a name="p1757432116410"></a><a name="p1757432116410"></a>表示如不避免则将会导致死亡或严重伤害的具有高等级风险的危害。</p>
</td>
</tr>
<tr id="row466863216410"><td class="cellrowborder" valign="top" width="20.580000000000002%" headers="mcps1.1.3.1.1 "><p id="p1432579516410"><a name="p1432579516410"></a><a name="p1432579516410"></a><a name="image4895582316410"></a><a name="image4895582316410"></a><span><img class="" id="image4895582316410" height="25.270000000000003" width="67.83" src="figures/zh-cn_image_0000001953959001.png"></span></p>
</td>
<td class="cellrowborder" valign="top" width="79.42%" headers="mcps1.1.3.1.2 "><p id="p959197916410"><a name="p959197916410"></a><a name="p959197916410"></a>表示如不避免则可能导致死亡或严重伤害的具有中等级风险的危害。</p>
</td>
</tr>
<tr id="row123863216410"><td class="cellrowborder" valign="top" width="20.580000000000002%" headers="mcps1.1.3.1.1 "><p id="p1232579516410"><a name="p1232579516410"></a><a name="p1232579516410"></a><a name="image1235582316410"></a><a name="image1235582316410"></a><span><img class="" id="image1235582316410" height="25.270000000000003" width="67.83" src="figures/zh-cn_image_0000001954078781.png"></span></p>
</td>
<td class="cellrowborder" valign="top" width="79.42%" headers="mcps1.1.3.1.2 "><p id="p123197916410"><a name="p123197916410"></a><a name="p123197916410"></a>表示如不避免则可能导致轻微或中度伤害的具有低等级风险的危害。</p>
</td>
</tr>
<tr id="row5786682116410"><td class="cellrowborder" valign="top" width="20.580000000000002%" headers="mcps1.1.3.1.1 "><p id="p2204984716410"><a name="p2204984716410"></a><a name="p2204984716410"></a><a name="image4504446716410"></a><a name="image4504446716410"></a><span><img class="" id="image4504446716410" height="25.270000000000003" width="67.83" src="figures/zh-cn_image_0000001926760086.png"></span></p>
</td>
<td class="cellrowborder" valign="top" width="79.42%" headers="mcps1.1.3.1.2 "><p id="p4388861916410"><a name="p4388861916410"></a><a name="p4388861916410"></a>用于传递设备或环境安全警示信息。如不避免则可能会导致设备损坏、数据丢失、设备性能降低或其它不可预知的结果。</p>
<p id="p1238861916410"><a name="p1238861916410"></a><a name="p1238861916410"></a>“须知”不涉及人身伤害。</p>
</td>
</tr>
<tr id="row2856923116410"><td class="cellrowborder" valign="top" width="20.580000000000002%" headers="mcps1.1.3.1.1 "><p id="p5555360116410"><a name="p5555360116410"></a><a name="p5555360116410"></a><a name="image799324016410"></a><a name="image799324016410"></a><span><img class="" id="image799324016410" height="25.270000000000003" width="67.83" src="figures/zh-cn_image_0000001926919446.png"></span></p>
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
<tbody><tr id="row5947359616410"><td class="cellrowborder" valign="top" width="20.72%" headers="mcps1.1.4.1.1 "><p id="p2149706016410"><a name="p2149706016410"></a><a name="p2149706016410"></a>00B01</p>
</td>
<td class="cellrowborder" valign="top" width="26.119999999999997%" headers="mcps1.1.4.1.2 "><p id="p648803616410"><a name="p648803616410"></a><a name="p648803616410"></a>2024-06-18</p>
</td>
<td class="cellrowborder" valign="top" width="53.16%" headers="mcps1.1.4.1.3 "><p id="p1946537916410"><a name="p1946537916410"></a><a name="p1946537916410"></a>第一次临时版本发布。</p>
</td>
</tr>
</tbody>
</table>

# BLE SDK接口变更说明<a name="ZH-CN_TOPIC_0000001920743641"></a>

**表 1**  BLE接口变更说明

<a name="table14411119287"></a>
<table><thead align="left"><tr id="row17411112819"><th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.2.4.1.1"><p id="p1785215212112"><a name="p1785215212112"></a><a name="p1785215212112"></a>SDK版本</p>
</th>
<th class="cellrowborder" valign="top" width="27.750000000000004%" id="mcps1.2.4.1.2"><p id="p641181112817"><a name="p641181112817"></a><a name="p641181112817"></a>头文件</p>
</th>
<th class="cellrowborder" valign="top" width="56.910000000000004%" id="mcps1.2.4.1.3"><p id="p10412010284"><a name="p10412010284"></a><a name="p10412010284"></a>修改内容</p>
</th>
</tr>
</thead>
<tbody><tr id="row1441161172816"><td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.2.4.1.1 "><p id="p114161152819"><a name="p114161152819"></a><a name="p114161152819"></a>1.0.11</p>
</td>
<td class="cellrowborder" valign="top" width="27.750000000000004%" headers="mcps1.2.4.1.2 "><p id="p1641171102815"><a name="p1641171102815"></a><a name="p1641171102815"></a>bts_device_manager.h</p>
</td>
<td class="cellrowborder" valign="top" width="56.910000000000004%" headers="mcps1.2.4.1.3 "><a name="ol13389174294614"></a><a name="ol13389174294614"></a><ol id="ol13389174294614"><li>添加power_on回调，表明双核中B核是否上电</li><li>将enable/disable ble接口和回调移动至此文件</li></ol>
</td>
</tr>
<tr id="row94211118283"><td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.2.4.1.1 "><p id="p44211112820"><a name="p44211112820"></a><a name="p44211112820"></a>1.0.11</p>
</td>
<td class="cellrowborder" valign="top" width="27.750000000000004%" headers="mcps1.2.4.1.2 "><p id="p10423118287"><a name="p10423118287"></a><a name="p10423118287"></a>bts_le_gap.h</p>
</td>
<td class="cellrowborder" valign="top" width="56.910000000000004%" headers="mcps1.2.4.1.3 "><a name="ol11839172024715"></a><a name="ol11839172024715"></a><ol id="ol11839172024715"><li>添加设置扩展广播参数接口</li><li>添加获取bond设备接口</li><li>添加设置NV接口（暂未开放）</li><li>添加设置rssi接口</li></ol>
</td>
</tr>
<tr id="row65021347192019"><td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.2.4.1.1 "><p id="p3651432124618"><a name="p3651432124618"></a><a name="p3651432124618"></a>1.0.12</p>
</td>
<td class="cellrowborder" valign="top" width="27.750000000000004%" headers="mcps1.2.4.1.2 "><p id="p5843115919228"><a name="p5843115919228"></a><a name="p5843115919228"></a>bts_le_gap.h</p>
</td>
<td class="cellrowborder" valign="top" width="56.910000000000004%" headers="mcps1.2.4.1.3 "><p id="p175021047112013"><a name="p175021047112013"></a><a name="p175021047112013"></a>将ble广播参数的结构体gap_ble_adv_params_t的tx_power参数类型从uint32_t 变更为int8_t</p>
</td>
</tr>
<tr id="row1632919424202"><td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.2.4.1.1 "><p id="p2013053314464"><a name="p2013053314464"></a><a name="p2013053314464"></a>1.0.12</p>
</td>
<td class="cellrowborder" valign="top" width="27.750000000000004%" headers="mcps1.2.4.1.2 "><p id="p133004262012"><a name="p133004262012"></a><a name="p133004262012"></a>bts_le_gap.h</p>
</td>
<td class="cellrowborder" valign="top" width="56.910000000000004%" headers="mcps1.2.4.1.3 "><a name="ol149513185471"></a><a name="ol149513185471"></a><ol id="ol149513185471"><li>修改设置NV接口（添加index入参）</li><li>添加errcode_t gap_ble_set_save_smp_keys_mode(uint8_t is_available)接口，设置是否支持用户设置NV</li><li>添加gap_ble_save_pair_keys_mode_switch_t枚举</li></ol>
</td>
</tr>
<tr id="row757818722519"><td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.2.4.1.1 "><p id="p1681113318462"><a name="p1681113318462"></a><a name="p1681113318462"></a>1.0.12</p>
</td>
<td class="cellrowborder" valign="top" width="27.750000000000004%" headers="mcps1.2.4.1.2 "><p id="p182688302257"><a name="p182688302257"></a><a name="p182688302257"></a>bts_le_gap.h</p>
</td>
<td class="cellrowborder" valign="top" width="56.910000000000004%" headers="mcps1.2.4.1.3 "><a name="ol6205131119474"></a><a name="ol6205131119474"></a><ol id="ol6205131119474"><li>添加errcode_t gap_ble_add_white_list(const bd_addr_t *addr)<p id="p15991315114720"><a name="p15991315114720"></a><a name="p15991315114720"></a>errcode_t gap_ble_remove_white_list(const bd_addr_t *addr)</p>
<p id="p61008153477"><a name="p61008153477"></a><a name="p61008153477"></a>errcode_t gap_ble_get_white_list(void)接口</p>
</li><li>添加typedef void (*gap_ble_get_white_list_callback)(uint8_t count, bd_addr_t *addr_list)回调</li></ol>
</td>
</tr>
<tr id="row79601115153013"><td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.2.4.1.1 "><p id="p1521143474616"><a name="p1521143474616"></a><a name="p1521143474616"></a>1.0.12</p>
</td>
<td class="cellrowborder" valign="top" width="27.750000000000004%" headers="mcps1.2.4.1.2 "><p id="p143115541327"><a name="p143115541327"></a><a name="p143115541327"></a>bts_le_gap.h</p>
</td>
<td class="cellrowborder" valign="top" width="56.910000000000004%" headers="mcps1.2.4.1.3 "><p id="p89601815153010"><a name="p89601815153010"></a><a name="p89601815153010"></a><span>pair_complete_cb</span>中添加keymissing错误码</p>
</td>
</tr>
<tr id="row4110252174315"><td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.2.4.1.1 "><p id="p1341203584619"><a name="p1341203584619"></a><a name="p1341203584619"></a>1.0.12</p>
</td>
<td class="cellrowborder" valign="top" width="27.750000000000004%" headers="mcps1.2.4.1.2 "><p id="p41105522437"><a name="p41105522437"></a><a name="p41105522437"></a>bts_le_gap.h</p>
</td>
<td class="cellrowborder" valign="top" width="56.910000000000004%" headers="mcps1.2.4.1.3 "><a name="ol8940173475"></a><a name="ol8940173475"></a><ol id="ol8940173475"><li>首次配对先上报认证完成回调，后上报配对完成回调</li><li>回连只上报配对完成回调</li></ol>
</td>
</tr>
<tr id="row6453163631410"><td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.2.4.1.1 "><p id="p1045373681414"><a name="p1045373681414"></a><a name="p1045373681414"></a>1.0.12</p>
</td>
<td class="cellrowborder" valign="top" width="27.750000000000004%" headers="mcps1.2.4.1.2 "><p id="p194531336111412"><a name="p194531336111412"></a><a name="p194531336111412"></a>bts_low_latency.h</p>
</td>
<td class="cellrowborder" valign="top" width="56.910000000000004%" headers="mcps1.2.4.1.3 "><p id="p2453536161419"><a name="p2453536161419"></a><a name="p2453536161419"></a>新增set em data方法和回调</p>
</td>
</tr>
</tbody>
</table>

**表 2**  SLE接口变更说明

<a name="table43133297215"></a>
<table><thead align="left"><tr id="row4314629524"><th class="cellrowborder" valign="top" width="15.409999999999998%" id="mcps1.2.4.1.1"><p id="p123141529227"><a name="p123141529227"></a><a name="p123141529227"></a>SDK版本</p>
</th>
<th class="cellrowborder" valign="top" width="27.66%" id="mcps1.2.4.1.2"><p id="p133141296211"><a name="p133141296211"></a><a name="p133141296211"></a>头文件</p>
</th>
<th class="cellrowborder" valign="top" width="56.93%" id="mcps1.2.4.1.3"><p id="p431416291424"><a name="p431416291424"></a><a name="p431416291424"></a>修改内容</p>
</th>
</tr>
</thead>
<tbody><tr id="row9314929822"><td class="cellrowborder" valign="top" width="15.409999999999998%" headers="mcps1.2.4.1.1 "><p id="p1731414292215"><a name="p1731414292215"></a><a name="p1731414292215"></a>1.0.11</p>
</td>
<td class="cellrowborder" valign="top" width="27.66%" headers="mcps1.2.4.1.2 "><p id="p133141291923"><a name="p133141291923"></a><a name="p133141291923"></a>sle_transmition_manager.h</p>
</td>
<td class="cellrowborder" valign="top" width="56.93%" headers="mcps1.2.4.1.3 "><p id="p9314102918217"><a name="p9314102918217"></a><a name="p9314102918217"></a>添加QOS队列</p>
</td>
</tr>
<tr id="row133149297214"><td class="cellrowborder" valign="top" width="15.409999999999998%" headers="mcps1.2.4.1.1 "><p id="p1693155111114"><a name="p1693155111114"></a><a name="p1693155111114"></a>1.0.11</p>
</td>
<td class="cellrowborder" valign="top" width="27.66%" headers="mcps1.2.4.1.2 "><p id="p23143292218"><a name="p23143292218"></a><a name="p23143292218"></a>sle_ssap_client.h</p>
</td>
<td class="cellrowborder" valign="top" width="56.93%" headers="mcps1.2.4.1.3 "><p id="p119121133899"><a name="p119121133899"></a><a name="p119121133899"></a>ssapc_find_structure方法的ssapc_find_structure_param_t中type成员变量参考枚举从ssap_find_type_t改为ssap_property_type_t</p>
</td>
</tr>
<tr id="row10314029129"><td class="cellrowborder" valign="top" width="15.409999999999998%" headers="mcps1.2.4.1.1 "><p id="p10898105512112"><a name="p10898105512112"></a><a name="p10898105512112"></a>1.0.11</p>
</td>
<td class="cellrowborder" valign="top" width="27.66%" headers="mcps1.2.4.1.2 "><p id="p231482913216"><a name="p231482913216"></a><a name="p231482913216"></a>sle_ota.h</p>
</td>
<td class="cellrowborder" valign="top" width="56.93%" headers="mcps1.2.4.1.3 "><p id="p2031432918210"><a name="p2031432918210"></a><a name="p2031432918210"></a>新增sle ota头文件</p>
</td>
</tr>
<tr id="row1531418291520"><td class="cellrowborder" valign="top" width="15.409999999999998%" headers="mcps1.2.4.1.1 "><p id="p12596135617119"><a name="p12596135617119"></a><a name="p12596135617119"></a>1.0.11</p>
</td>
<td class="cellrowborder" valign="top" width="27.66%" headers="mcps1.2.4.1.2 "><p id="p183145296218"><a name="p183145296218"></a><a name="p183145296218"></a>sle_low_latency.h</p>
</td>
<td class="cellrowborder" valign="top" width="56.93%" headers="mcps1.2.4.1.3 "><a name="ol362712910478"></a><a name="ol362712910478"></a><ol id="ol362712910478"><li>tx和rx回调函数参数len由uint16_t改为uint8_t</li><li>添加sle_low_latency_rx_get_data获取rx数据</li></ol>
</td>
</tr>
<tr id="row99461111444"><td class="cellrowborder" valign="top" width="15.409999999999998%" headers="mcps1.2.4.1.1 "><p id="p43968572113"><a name="p43968572113"></a><a name="p43968572113"></a>1.0.11</p>
</td>
<td class="cellrowborder" valign="top" width="27.66%" headers="mcps1.2.4.1.2 "><p id="p49461012415"><a name="p49461012415"></a><a name="p49461012415"></a>sle_device_manager.h</p>
</td>
<td class="cellrowborder" valign="top" width="56.93%" headers="mcps1.2.4.1.3 "><a name="ol1065133214477"></a><a name="ol1065133214477"></a><ol id="ol1065133214477"><li>添加power_on回调，表明双核中B核是否上电</li><li>将enable/disable sle接口和回调移动至此文件</li></ol>
</td>
</tr>
<tr id="row715815948"><td class="cellrowborder" valign="top" width="15.409999999999998%" headers="mcps1.2.4.1.1 "><p id="p144185811116"><a name="p144185811116"></a><a name="p144185811116"></a>1.0.11</p>
</td>
<td class="cellrowborder" valign="top" width="27.66%" headers="mcps1.2.4.1.2 "><p id="p815810513411"><a name="p815810513411"></a><a name="p815810513411"></a>sle_device_discovery.h</p>
</td>
<td class="cellrowborder" valign="top" width="56.93%" headers="mcps1.2.4.1.3 "><p id="p71581458414"><a name="p71581458414"></a><a name="p71581458414"></a>添加删除广播接口和回调</p>
</td>
</tr>
<tr id="row1413131810419"><td class="cellrowborder" valign="top" width="15.409999999999998%" headers="mcps1.2.4.1.1 "><p id="p75191358181112"><a name="p75191358181112"></a><a name="p75191358181112"></a>1.0.11</p>
</td>
<td class="cellrowborder" valign="top" width="27.66%" headers="mcps1.2.4.1.2 "><p id="p213218845"><a name="p213218845"></a><a name="p213218845"></a>sle_connection_manager.h</p>
</td>
<td class="cellrowborder" valign="top" width="56.93%" headers="mcps1.2.4.1.3 "><a name="ol655711115485"></a><a name="ol655711115485"></a><ol id="ol655711115485"><li>添加获取连接为G/T节点接口</li><li>添加获取bond设备接口</li><li>添加设置NV接口（暂未开放）</li><li>添加白名单逻辑</li><li>添加取消连接接口</li><li>添加设置rssi接口</li><li>添加断开所有连接接口</li></ol>
</td>
</tr>
<tr id="row1711114942518"><td class="cellrowborder" valign="top" width="15.409999999999998%" headers="mcps1.2.4.1.1 "><p id="p1171164914250"><a name="p1171164914250"></a><a name="p1171164914250"></a>1.0.12</p>
</td>
<td class="cellrowborder" valign="top" width="27.66%" headers="mcps1.2.4.1.2 "><p id="p1271184962516"><a name="p1271184962516"></a><a name="p1271184962516"></a>sle_ssap_server.h</p>
</td>
<td class="cellrowborder" valign="top" width="56.93%" headers="mcps1.2.4.1.3 "><p id="p10711134917252"><a name="p10711134917252"></a><a name="p10711134917252"></a>添加收到来自客户端的cfm响应接口：indicate_cfm_cb</p>
</td>
</tr>
<tr id="row1780942562619"><td class="cellrowborder" valign="top" width="15.409999999999998%" headers="mcps1.2.4.1.1 "><p id="p11809162532612"><a name="p11809162532612"></a><a name="p11809162532612"></a>1.0.12</p>
</td>
<td class="cellrowborder" valign="top" width="27.66%" headers="mcps1.2.4.1.2 "><p id="p180942532611"><a name="p180942532611"></a><a name="p180942532611"></a>sle_connection_manager.h</p>
</td>
<td class="cellrowborder" valign="top" width="56.93%" headers="mcps1.2.4.1.3 "><p id="p158091625182614"><a name="p158091625182614"></a><a name="p158091625182614"></a>新增set channel map接口</p>
</td>
</tr>
<tr id="row1750116423267"><td class="cellrowborder" valign="top" width="15.409999999999998%" headers="mcps1.2.4.1.1 "><p id="p550174210269"><a name="p550174210269"></a><a name="p550174210269"></a>1.0.12</p>
</td>
<td class="cellrowborder" valign="top" width="27.66%" headers="mcps1.2.4.1.2 "><p id="p1350194214265"><a name="p1350194214265"></a><a name="p1350194214265"></a>sle_connection_manager.h</p>
</td>
<td class="cellrowborder" valign="top" width="56.93%" headers="mcps1.2.4.1.3 "><a name="ol1194712578472"></a><a name="ol1194712578472"></a><ol id="ol1194712578472"><li>修改设置NV接口（添加index入参）</li><li>添加errcode_t sle_set_save_pair_keys_mode(uint8_t is_available)接口，设置是否支持用户设置NV</li><li>添加sle_save_smp_keys_mode_switch_t枚举</li></ol>
</td>
</tr>
<tr id="row393182013317"><td class="cellrowborder" valign="top" width="15.409999999999998%" headers="mcps1.2.4.1.1 "><p id="p189320208317"><a name="p189320208317"></a><a name="p189320208317"></a>1.0.12</p>
</td>
<td class="cellrowborder" valign="top" width="27.66%" headers="mcps1.2.4.1.2 "><p id="p0931420143118"><a name="p0931420143118"></a><a name="p0931420143118"></a>sle_connection_manager.h</p>
</td>
<td class="cellrowborder" valign="top" width="56.93%" headers="mcps1.2.4.1.3 "><p id="p1094132015312"><a name="p1094132015312"></a><a name="p1094132015312"></a><span>pair_complete_cb</span>中添加keymissing错误码</p>
</td>
</tr>
<tr id="row293711261489"><td class="cellrowborder" valign="top" width="15.409999999999998%" headers="mcps1.2.4.1.1 "><p id="p293714267486"><a name="p293714267486"></a><a name="p293714267486"></a>1.0.12</p>
</td>
<td class="cellrowborder" valign="top" width="27.66%" headers="mcps1.2.4.1.2 "><p id="p109371426154818"><a name="p109371426154818"></a><a name="p109371426154818"></a>sle_low_latency.h</p>
</td>
<td class="cellrowborder" valign="top" width="56.93%" headers="mcps1.2.4.1.3 "><a name="ol5761195584719"></a><a name="ol5761195584719"></a><ol id="ol5761195584719"><li>新增set em data方法和回调</li><li>修改原有low latency回调</li></ol>
</td>
</tr>
</tbody>
</table>

