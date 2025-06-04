# 前言<a name="ZH-CN_TOPIC_0000001790966320"></a>

**概述<a name="section4537382116410"></a>**

本文档主要针对BS2X芯片中NV存储模块的使用进行介绍。用于指导工程人员能够快速使用NV模块进行二次开发。

**产品版本<a name="section27775771"></a>**

<a name="table52250146"></a>
<table><thead align="left"><tr id="row55967882"><th class="cellrowborder" valign="top" width="39.39%" id="mcps1.1.3.1.1"><p id="p37104584"><a name="p37104584"></a><a name="p37104584"></a><strong id="b48174912328"><a name="b48174912328"></a><a name="b48174912328"></a>产品名称</strong></p>
</th>
<th class="cellrowborder" valign="top" width="60.61%" id="mcps1.1.3.1.2"><p id="p52681331"><a name="p52681331"></a><a name="p52681331"></a><strong id="b682239163211"><a name="b682239163211"></a><a name="b682239163211"></a>产品版本</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row39329394"><td class="cellrowborder" valign="top" width="39.39%" headers="mcps1.1.3.1.1 "><p id="p31080012"><a name="p31080012"></a><a name="p31080012"></a>BS2X</p>
</td>
<td class="cellrowborder" valign="top" width="60.61%" headers="mcps1.1.3.1.2 "><p id="p34453054"><a name="p34453054"></a><a name="p34453054"></a>V100</p>
</td>
</tr>
</tbody>
</table>

**读者对象<a name="section4378592816410"></a>**

本文档主要适用于以下工程师：

-   技术支持工程师
-   软件工程师

**符号约定<a name="section133020216410"></a>**

在本文中可能出现下列标志，它们所代表的含义如下。

<a name="table2622507016410"></a>
<table><thead align="left"><tr id="row1530720816410"><th class="cellrowborder" valign="top" width="20.580000000000002%" id="mcps1.1.3.1.1"><p id="p6450074116410"><a name="p6450074116410"></a><a name="p6450074116410"></a><strong id="b2136615816410"><a name="b2136615816410"></a><a name="b2136615816410"></a>符号</strong></p>
</th>
<th class="cellrowborder" valign="top" width="79.42%" id="mcps1.1.3.1.2"><p id="p5435366816410"><a name="p5435366816410"></a><a name="p5435366816410"></a><strong id="b5941558116410"><a name="b5941558116410"></a><a name="b5941558116410"></a>说明</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row1372280416410"><td class="cellrowborder" valign="top" width="20.580000000000002%" headers="mcps1.1.3.1.1 "><p id="p3734547016410"><a name="p3734547016410"></a><a name="p3734547016410"></a><a name="image2670064316410"></a><a name="image2670064316410"></a><span><img class="" id="image2670064316410" src="figures/zh-cn_image_0000001790966504.png" width="55.9265" height="25.270000000000003"></span></p>
</td>
<td class="cellrowborder" valign="top" width="79.42%" headers="mcps1.1.3.1.2 "><p id="p1757432116410"><a name="p1757432116410"></a><a name="p1757432116410"></a>表示如不避免则将会导致死亡或严重伤害的具有高等级风险的危害。</p>
</td>
</tr>
<tr id="row466863216410"><td class="cellrowborder" valign="top" width="20.580000000000002%" headers="mcps1.1.3.1.1 "><p id="p1432579516410"><a name="p1432579516410"></a><a name="p1432579516410"></a><a name="image4895582316410"></a><a name="image4895582316410"></a><span><img class="" id="image4895582316410" src="figures/zh-cn_image_0000001837765957.png" width="55.9265" height="25.270000000000003"></span></p>
</td>
<td class="cellrowborder" valign="top" width="79.42%" headers="mcps1.1.3.1.2 "><p id="p959197916410"><a name="p959197916410"></a><a name="p959197916410"></a>表示如不避免则可能导致死亡或严重伤害的具有中等级风险的危害。</p>
</td>
</tr>
<tr id="row123863216410"><td class="cellrowborder" valign="top" width="20.580000000000002%" headers="mcps1.1.3.1.1 "><p id="p1232579516410"><a name="p1232579516410"></a><a name="p1232579516410"></a><a name="image1235582316410"></a><a name="image1235582316410"></a><span><img class="" id="image1235582316410" src="figures/zh-cn_image_0000001837645989.png" width="55.9265" height="25.270000000000003"></span></p>
</td>
<td class="cellrowborder" valign="top" width="79.42%" headers="mcps1.1.3.1.2 "><p id="p123197916410"><a name="p123197916410"></a><a name="p123197916410"></a>表示如不避免则可能导致轻微或中度伤害的具有低等级风险的危害。</p>
</td>
</tr>
<tr id="row5786682116410"><td class="cellrowborder" valign="top" width="20.580000000000002%" headers="mcps1.1.3.1.1 "><p id="p2204984716410"><a name="p2204984716410"></a><a name="p2204984716410"></a><a name="image4504446716410"></a><a name="image4504446716410"></a><span><img class="" id="image4504446716410" src="figures/zh-cn_image_0000001790806840.png" width="55.9265" height="25.270000000000003"></span></p>
</td>
<td class="cellrowborder" valign="top" width="79.42%" headers="mcps1.1.3.1.2 "><p id="p4388861916410"><a name="p4388861916410"></a><a name="p4388861916410"></a>用于传递设备或环境安全警示信息。如不避免则可能会导致设备损坏、数据丢失、设备性能降低或其它不可预知的结果。</p>
<p id="p1238861916410"><a name="p1238861916410"></a><a name="p1238861916410"></a>“须知”不涉及人身伤害。</p>
</td>
</tr>
<tr id="row2856923116410"><td class="cellrowborder" valign="top" width="20.580000000000002%" headers="mcps1.1.3.1.1 "><p id="p5555360116410"><a name="p5555360116410"></a><a name="p5555360116410"></a><a name="image799324016410"></a><a name="image799324016410"></a><span><img class="" id="image799324016410" src="figures/zh-cn_image_0000001837765969.png" width="47.88" height="15.96"></span></p>
</td>
<td class="cellrowborder" valign="top" width="79.42%" headers="mcps1.1.3.1.2 "><p id="p4612588116410"><a name="p4612588116410"></a><a name="p4612588116410"></a>对正文中重点信息的补充说明。</p>
<p id="p1232588116410"><a name="p1232588116410"></a><a name="p1232588116410"></a>“说明”不是安全警示信息，不涉及人身、设备及环境伤害信息。</p>
</td>
</tr>
</tbody>
</table>

**修改记录<a name="section2467512116410"></a>**

<a name="table1557726816410"></a>
<table><thead align="left"><tr id="row2942532716410"><th class="cellrowborder" valign="top" width="20.05%" id="mcps1.1.4.1.1"><p id="p3778275416410"><a name="p3778275416410"></a><a name="p3778275416410"></a><strong id="b5687322716410"><a name="b5687322716410"></a><a name="b5687322716410"></a>文档版本</strong></p>
</th>
<th class="cellrowborder" valign="top" width="22.91%" id="mcps1.1.4.1.2"><p id="p5627845516410"><a name="p5627845516410"></a><a name="p5627845516410"></a><strong id="b5800814916410"><a name="b5800814916410"></a><a name="b5800814916410"></a>发布日期</strong></p>
</th>
<th class="cellrowborder" valign="top" width="57.04%" id="mcps1.1.4.1.3"><p id="p2382284816410"><a name="p2382284816410"></a><a name="p2382284816410"></a><strong id="b3316380216410"><a name="b3316380216410"></a><a name="b3316380216410"></a>修改说明</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row1078055125815"><td class="cellrowborder" valign="top" width="20.05%" headers="mcps1.1.4.1.1 "><p id="p1378185125816"><a name="p1378185125816"></a><a name="p1378185125816"></a><span id="ph1452091915581"><a name="ph1452091915581"></a><a name="ph1452091915581"></a>02</span></p>
</td>
<td class="cellrowborder" valign="top" width="22.91%" headers="mcps1.1.4.1.2 "><p id="p1589341615811"><a name="p1589341615811"></a><a name="p1589341615811"></a><span id="ph31301821135811"><a name="ph31301821135811"></a><a name="ph31301821135811"></a>2025-03-26</span></p>
</td>
<td class="cellrowborder" valign="top" width="57.04%" headers="mcps1.1.4.1.3 "><p id="p578135145818"><a name="p578135145818"></a><a name="p578135145818"></a>更新“<a href="新增NV项.md">新增NV项</a>”小节内容。</p>
</td>
</tr>
<tr id="row1065912148574"><td class="cellrowborder" valign="top" width="20.05%" headers="mcps1.1.4.1.1 "><p id="p0413131712"><a name="p0413131712"></a><a name="p0413131712"></a>01</p>
</td>
<td class="cellrowborder" valign="top" width="22.91%" headers="mcps1.1.4.1.2 "><p id="p184131311111"><a name="p184131311111"></a><a name="p184131311111"></a>2024-05-15</p>
</td>
<td class="cellrowborder" valign="top" width="57.04%" headers="mcps1.1.4.1.3 "><p id="p169114261115"><a name="p169114261115"></a><a name="p169114261115"></a>第一次正式版本发布。</p>
</td>
</tr>
<tr id="row736072814421"><td class="cellrowborder" valign="top" width="20.05%" headers="mcps1.1.4.1.1 "><p id="p1336012816420"><a name="p1336012816420"></a><a name="p1336012816420"></a>00B02</p>
</td>
<td class="cellrowborder" valign="top" width="22.91%" headers="mcps1.1.4.1.2 "><p id="p1536052844214"><a name="p1536052844214"></a><a name="p1536052844214"></a>2024-02-29</p>
</td>
<td class="cellrowborder" valign="top" width="57.04%" headers="mcps1.1.4.1.3 "><a name="ul1761623912427"></a><a name="ul1761623912427"></a><ul id="ul1761623912427"><li>更新“<a href="新增NV项.md">新增NV项</a>”小节内容。</li><li>更新“<a href="编译生成NV镜像.md">编译生成NV镜像</a>”小节内容。</li></ul>
</td>
</tr>
<tr id="row5947359616410"><td class="cellrowborder" valign="top" width="20.05%" headers="mcps1.1.4.1.1 "><p id="p2149706016410"><a name="p2149706016410"></a><a name="p2149706016410"></a>00B01</p>
</td>
<td class="cellrowborder" valign="top" width="22.91%" headers="mcps1.1.4.1.2 "><p id="p648803616410"><a name="p648803616410"></a><a name="p648803616410"></a>2024-02-05</p>
</td>
<td class="cellrowborder" valign="top" width="57.04%" headers="mcps1.1.4.1.3 "><p id="p1946537916410"><a name="p1946537916410"></a><a name="p1946537916410"></a>第一次临时版本发布。</p>
</td>
</tr>
</tbody>
</table>

# NV简介<a name="ZH-CN_TOPIC_0000001837765725"></a>

NV模块用于在本地存储器中存储非易失性数据。NV中的每项数据以类似key-value的方式进行定义，数据项中包含唯一的索引key和自定义数据类型的value。

NV项可通过两种方式进行存储：编译预置和API写入。

-   编译预置是指开发者可在代码编译阶段，通过修改NV头文件和NV配置文件的方式生成客制化的NV镜像，在镜像烧录的过程中统一烧录到存储介质中。预置的NV在代码运行阶段可通过API接口进行读取和更新。具体使用方法请参见“[NV编译预置](NV编译预置.md)”章节。
-   API写入是指用户可直接在代码中调用API接口写入新的NV项，具体使用方法请参见“[NV API指南](NV-API指南.md)”章节。

以Flash为例，NV项存储在Flash中时，以Flash器件的sector为单位进行管理，NV的每个页为一个sector大小（4096Byte），NV页的数量默认配置为2页。除去管理结构，单个非加密NV项的有效数据最大不应超过4060Byte。

# NV编译预置<a name="ZH-CN_TOPIC_0000001790966304"></a>




## 新增NV项<a name="ZH-CN_TOPIC_0000001837645765"></a>



### 新增NV项流程<a name="ZH-CN_TOPIC_0000001837765733"></a>

1.  在头文件中新增kvalue的数据类型定义（非必须，如果是通用类型数据可忽略此步骤）。
2.  在json文件中新增NV描述项。

**新增kvalue数据类型<a name="section206861047121115"></a>**

-   通用数据类型：

    unit8\_t、unit16\_t、unit32\_t、bool。

-   自定义数据类型：

    支持自定义枚举（enum）类型和结构体（struct）类型。

-   自定义数据类型存放路径：

    以bs21为例：middleware\\chips\\bs21\\nv\\nv\_config\\bs21\_nv\_default\\include\\common.h，其中bs21\_nv\_default和“build\\config\\target\_config\\bs21\\config.py"中的'nv\_cfg': 'bs21\_nv\_default'对应，模式配置为bs21\_nv\_default。

-   当用户使用通用或已定义的数据类型时，不涉及本小节的修改；当用户要新增枚举或结构体类型时，需在上述文件中定义。

**新增NV描述项<a name="section13134513141310"></a>**

-   NV描述项文件路径：以bs21为例，middleware\\chips\\bs21\\nv\\nv\_config\\bs21\_nv\_default\\cfg\\acore\\app.json，其中bs21\_nv\_default和“build\\config\\target\_config\\bs21\\config.py"中的'nv\_cfg': 'bs21\_nv\_default'对应，模式配置为bs21\_nv\_default。
-   定义说明如[表1](#table8802115017551)所示。

    **表 1**  NV配置选项说明

    <a name="table8802115017551"></a>
    <table><thead align="left"><tr id="row3802550105510"><th class="cellrowborder" valign="top" width="49.93%" id="mcps1.2.3.1.1"><p id="p680265010550"><a name="p680265010550"></a><a name="p680265010550"></a>NV配置选项</p>
    </th>
    <th class="cellrowborder" valign="top" width="50.07%" id="mcps1.2.3.1.2"><p id="p7802115012558"><a name="p7802115012558"></a><a name="p7802115012558"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1780215504558"><td class="cellrowborder" valign="top" width="49.93%" headers="mcps1.2.3.1.1 "><p id="p188021550125516"><a name="p188021550125516"></a><a name="p188021550125516"></a>key_id</p>
    </td>
    <td class="cellrowborder" valign="top" width="50.07%" headers="mcps1.2.3.1.2 "><p id="p198021950105511"><a name="p198021950105511"></a><a name="p198021950105511"></a>NV项的ID。</p>
    </td>
    </tr>
    <tr id="row198025507556"><td class="cellrowborder" valign="top" width="49.93%" headers="mcps1.2.3.1.1 "><p id="p14802115012556"><a name="p14802115012556"></a><a name="p14802115012556"></a>key_status</p>
    </td>
    <td class="cellrowborder" valign="top" width="50.07%" headers="mcps1.2.3.1.2 "><p id="p1780235085512"><a name="p1780235085512"></a><a name="p1780235085512"></a>NV项的状态。</p>
    </td>
    </tr>
    <tr id="row480295035518"><td class="cellrowborder" valign="top" width="49.93%" headers="mcps1.2.3.1.1 "><p id="p18021450165513"><a name="p18021450165513"></a><a name="p18021450165513"></a>structure_type</p>
    </td>
    <td class="cellrowborder" valign="top" width="50.07%" headers="mcps1.2.3.1.2 "><p id="p198021450155516"><a name="p198021450155516"></a><a name="p198021450155516"></a>NV项的数据结构类型。</p>
    </td>
    </tr>
    <tr id="row1580225015551"><td class="cellrowborder" valign="top" width="49.93%" headers="mcps1.2.3.1.1 "><p id="p880245035512"><a name="p880245035512"></a><a name="p880245035512"></a>attributions</p>
    </td>
    <td class="cellrowborder" valign="top" width="50.07%" headers="mcps1.2.3.1.2 "><p id="p1280225015519"><a name="p1280225015519"></a><a name="p1280225015519"></a>NV项的属性值。</p>
    </td>
    </tr>
    <tr id="row10802125014557"><td class="cellrowborder" valign="top" width="49.93%" headers="mcps1.2.3.1.1 "><p id="p20802450155516"><a name="p20802450155516"></a><a name="p20802450155516"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="50.07%" headers="mcps1.2.3.1.2 "><p id="p08025503552"><a name="p08025503552"></a><a name="p08025503552"></a>NV项的数据。</p>
    </td>
    </tr>
    </tbody>
    </table>

    **图 1**  NV配置文件示例<a name="fig1347521414456"></a>  
    
    ```
    {
        "common":{
            "module_id": "0x0",
            "host_config": {
                "key_id": "0x1",
                "key_status": "alive",
                "structure_type": "uint8_t",
                "attributions": 1,
                "value": 15
            },
            "sample1": {
                "key_id": "0x2",
                "key_status": "alive",
                "structure_type": "sample_type_t",
                "attributions": 1,
                "value": [1,2,3,4,5]    
            }
        }
    }
    ```

    在NV的配置中，每个字段的详细描述如下:

    -   key\_id：

        以十六进制形式给出的NV项ID。key\_id必须唯一，不能重复，因此建议用户对key\_id的取值进行管理，如：key\_id由16bit组成，可规定高8bit为所在模块内的module\_id，低8bit在模块内取值，避免不同模块使用NV互相影响。

    -   key\_status：

        用于标记是否将该项的NV值编到生成的bin文件中。该字段为“alive”，表示NV项生效，当前固件版本正在使用此key；若为其他的字段或空，则不生效。

    -   structure\_type：

        NV项的数据类型。具体说明请参见“[新增kvalue数据类型](#section206861047121115)”中详细描述。

    -   attributions：NV项属性值。

        1 、2、4为互斥关系，三选一。

        1：Normal NV（普通NV）。

        2：Permanent NV（不可修改）。

        4：Un-upgrade NV（不随版本升级而修改，未使用到）。

    -   value：如果value不是上述通用数据类型，任何结构都必须以列表的形式书写。

        value赋值有如下两种情况：

        1.  列表所有成员全部赋值。
        2.  只对列表前面若干个成员赋值。（末尾未赋值的成员默认赋值为0）。

        注：赋值只支持十进制格式。

### 新增NV项示例<a name="ZH-CN_TOPIC_0000001790966292"></a>

-   以BS21为例，在middleware\\chips\\bs21\\nv\\nv\_config\\bs21\_nv\_default\\include\\common.h文件中，新增自定义结构体。新增自定义数据类型示例如下。
    -   新增结构体类型且结构体内都为基础类型：

        ```
        typedef struct {
            int8_t param1;
            int8_t param2;
            int8_t param3;
            int8_t param4;
            int8_t param5;
            uint32_t param6;
            uint32_t param7;
            int32_t param8;
            uint32_t param9;
            uint32_t param10;
            uint32_t param11;
            uint32_t param12;
            uint32_t param13;
            uint32_t param14;
            uint32_t param15;
            uint32_t param16;
            uint32_t param17;
        } sample_type_t;
        ```

    -   新增结构体类型且结构体内有数组类型：

        ```
        typedef struct {
            uint16_t param1; 
            uint16_t param2; 
            uint16_t param3;
            uint16_t param4[2];
        } sample_two;
        ```

    -   新增枚举类型：

        ```
        typedef enum {
            PARAM1,
            PARAM2,
            PARAM3,
            PARAM4
        } sample_three;
        ```

-   以bs21为例，在middleware\\chips\\bs21\\nv\\nv\_config\\bs21\_nv\_default\\cfg\\acore\\app.json文件中，添加新的NV项。
    -   当kvalue预置值类型是基础类型时，添加kvalue预置值如[图1](#fig1025212135315)所示，可在app.json配置文件直接添加，无需在头文件中新增。

        **图 1**  添加kvalue预置值为基础类型<a name="fig1025212135315"></a>  
        
        ```
        "sample1": {
            "key_id": "0x1",
            "key_status": "alive",
            "structure_type": "uint8_t",
            "attributions": 1,
            "value": 0    
        }
        ```

    -   当kvalue预置值类型是结构体类型时，添加kvalue预置值如[图2](#fig655920623220)所示，该kvalue值要对应头文件中已有的结构体，如果没有需手动添加自定义结构体。

        **图 2**  添加kvalue预置值为结构体类型<a name="fig655920623220"></a>  
        
        ```
        "sample2": {
            "key_id": "0x2",
            "key_status": "alive",
            "structure_type": "sample_type_t",
            "attributions": 1,
            "value": [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17]    
        }
        ```

## NV位置调整<a name="ZH-CN_TOPIC_0000001837765745"></a>



### 功能描述<a name="ZH-CN_TOPIC_0000001837765757"></a>

NV位于Flash上的存储区域，其位置及大小支持自定义调整，相关配置文件如下（以BS21为例）：

-   位置及大小相关宏配置文件：

    middleware\\chips\\bs21\\nv\\include\\nv\_config.h

-   bin生成相关配置文件：

    middleware\\chips\\bs21\\nv\\nv\_config\\nv\_target.json

-   打包相关文件：

    tools\\pkg\\chip\_packet\\bs21\\packet.py

### 配置修改<a name="ZH-CN_TOPIC_0000001790806580"></a>

1.  修改nv\_config.h宏定义：

    ```
    #define KV_STORE_DATA_SIZE            NV_LENGTH
    #define KV_STORE_START_ADDR           (NV_STATR_ADDR)
    #define KV_STORE_PAGES_ACPU           1
    ```

    -   KV\_STORE\_DATA\_SIZE修改成目标NV的大小，SIZE大小为扇区（0x1000）的整数倍，最小SIZE为2×FLASH\_PAGE\_SIZE。
    -   KV\_STORE\_START\_ADDR修改为目标位置映射的内存空间。

    -   KV\_STORE\_PAGES\_ACPU修改A核扇区的数量，目前BS2X NV操作在A核进行，只适配ACPU即可。

1.  修改nv\_target.json生成信息：

    修改flash\_size为KV\_STORE\_DATA\_SIZE大小，同时修改page\_nums，使其与 KV\_STORE\_PAGES\_ACPU对应。

    ```
    {
        "size":{
            "flash_size" : "0x2000",
            "page_size" : "0x1000"
        },
        "cores" :{
            "app" : {
                "page_nums" : 4,
                "page_id_start" : "0x254D"
            }
        },
        "acore_test_nv":{
            "TYPE" :  "nv",
            "CHIP" :  "bs21",
            "CORE" :  "app",
            "KERNEL_BIN" : "acore",
            "COMPONENT" : ["app"]
        }
    }
    ```

1.  修改packet.py打包脚本：

    修改打包脚本中的NV bin打包地址。

    ```
        nv = os.path.join(SDK_DIR, "interim_binary", "bs21", "bin", "bs21_all_nv.bin")
        nv_bx = nv + "|0x8c5fc000|0x4000|100"
    ```

    NV bin代码打包格式为nv\_bx = nv + "|地址|大小|下载类型"，用户完成NV地址和大小的修改后，需要将代码中的地址、大小和nv\_config.h里面的地址大小对应，下载类型保持不变。

## 编译生成NV镜像<a name="ZH-CN_TOPIC_0000001790806608"></a>

目前SDK NV bin会随APP的编译一起更新，修改完NV的参数以及地址信息后，重新编译APP，NV bin会自动更新到（以bs21为例）interim\_binary\\bs21\\bin\\bs21\_all\_nv.bin路径下，并且打包到tools\\pkg\\fwpkg\\bs21\\bs21\_all.fwpkg路径下，用户使用Burntool下载即可。

# NV API指南<a name="ZH-CN_TOPIC_0000001790966312"></a>





## 功能描述<a name="ZH-CN_TOPIC_0000001837645757"></a>

NV API主要提供以下几种功能：

-   NV项写入：

    保存需要存储的格式化数据，同时可以定义写入数据的三种属性，分别为是否永久存储、是否加密存储和是否不可升级。

-   NV项读取：

    从本地存储器读取NV数据。

-   NV信息查询：
    -   查询NV是否已存储于本地存储器中。
    -   查询NV空间的使用状态。

NV项的写入接口可设置NV项的属性，对于通过API动态添加的NV项，可在其写入的接口中传入其所拥有的特殊属性。

## 接口说明<a name="ZH-CN_TOPIC_0000001790806596"></a>

NV模块主要提供以下API：

<a name="table4144181117554"></a>
<table><tbody><tr id="row314491195512"><th class="firstcol" valign="top" width="23.150000000000002%" id="mcps1.1.3.1.1"><p id="p141442113557"><a name="p141442113557"></a><a name="p141442113557"></a>uapi_nv_init</p>
</th>
<td class="cellrowborder" valign="top" width="76.85%" headers="mcps1.1.3.1.1 "><p id="p964116279517"><a name="p964116279517"></a><a name="p964116279517"></a>初始化<span>NV</span>模块，包括nv区域map，必须在使用nv函数之前调用。</p>
</td>
</tr>
<tr id="row61441111185511"><th class="firstcol" valign="top" width="23.150000000000002%" id="mcps1.1.3.2.1"><p id="p16369311305"><a name="p16369311305"></a><a name="p16369311305"></a>NULL</p>
</th>
<td class="cellrowborder" valign="top" width="76.85%" headers="mcps1.1.3.2.1 "><p id="p156413316915"><a name="p156413316915"></a><a name="p156413316915"></a>NULL</p>
</td>
</tr>
</tbody>
</table>

<a name="table6707155564719"></a>
<table><tbody><tr id="row4707135514715"><th class="firstcol" valign="top" width="23.150000000000002%" id="mcps1.1.3.1.1"><p id="p770717558479"><a name="p770717558479"></a><a name="p770717558479"></a>uapi_nv_write</p>
</th>
<td class="cellrowborder" valign="top" width="76.85%" headers="mcps1.1.3.1.1 "><p id="p11707755204711"><a name="p11707755204711"></a><a name="p11707755204711"></a>写入NV数据项，默认属性Normal，无回调函数。</p>
</td>
</tr>
<tr id="row67071055184710"><th class="firstcol" valign="top" width="23.150000000000002%" id="mcps1.1.3.2.1"><p id="p10707115514471"><a name="p10707115514471"></a><a name="p10707115514471"></a>key</p>
</th>
<td class="cellrowborder" valign="top" width="76.85%" headers="mcps1.1.3.2.1 "><p id="p27071855154716"><a name="p27071855154716"></a><a name="p27071855154716"></a>要写入的NV项的key ID，用于索引。</p>
</td>
</tr>
<tr id="row1707165554718"><th class="firstcol" valign="top" width="23.150000000000002%" id="mcps1.1.3.3.1"><p id="p13707185512478"><a name="p13707185512478"></a><a name="p13707185512478"></a>*kvalue</p>
</th>
<td class="cellrowborder" valign="top" width="76.85%" headers="mcps1.1.3.3.1 "><p id="p137072555474"><a name="p137072555474"></a><a name="p137072555474"></a>指向要写入的NV项的值的指针。</p>
</td>
</tr>
<tr id="row1370775524718"><th class="firstcol" valign="top" width="23.150000000000002%" id="mcps1.1.3.4.1"><p id="p1870725518470"><a name="p1870725518470"></a><a name="p1870725518470"></a>kvalue_length</p>
</th>
<td class="cellrowborder" valign="top" width="76.85%" headers="mcps1.1.3.4.1 "><p id="p370714556478"><a name="p370714556478"></a><a name="p370714556478"></a>写入数据的长度，单位：Byte。</p>
</td>
</tr>
</tbody>
</table>

<a name="table7346114574915"></a>
<table><tbody><tr id="row23461045114920"><th class="firstcol" valign="top" width="23.39%" id="mcps1.1.3.1.1"><p id="p1634612458495"><a name="p1634612458495"></a><a name="p1634612458495"></a>uapi_nv_write_with_attr</p>
</th>
<td class="cellrowborder" valign="top" width="76.61%" headers="mcps1.1.3.1.1 "><p id="p5346114514496"><a name="p5346114514496"></a><a name="p5346114514496"></a>写入NV数据项，并根据业务需求配置属性及回调函数。</p>
</td>
</tr>
<tr id="row234634518498"><th class="firstcol" valign="top" width="23.39%" id="mcps1.1.3.2.1"><p id="p1734644517499"><a name="p1734644517499"></a><a name="p1734644517499"></a>key</p>
</th>
<td class="cellrowborder" valign="top" width="76.61%" headers="mcps1.1.3.2.1 "><p id="p10346174515497"><a name="p10346174515497"></a><a name="p10346174515497"></a>要写入的NV项的key ID，用于索引。</p>
</td>
</tr>
<tr id="row13346154584913"><th class="firstcol" valign="top" width="23.39%" id="mcps1.1.3.3.1"><p id="p3346114524910"><a name="p3346114524910"></a><a name="p3346114524910"></a>*kvalue</p>
</th>
<td class="cellrowborder" valign="top" width="76.61%" headers="mcps1.1.3.3.1 "><p id="p434694554919"><a name="p434694554919"></a><a name="p434694554919"></a>指向要写入的NV项的值的指针。</p>
</td>
</tr>
<tr id="row134615453495"><th class="firstcol" valign="top" width="23.39%" id="mcps1.1.3.4.1"><p id="p5346645194914"><a name="p5346645194914"></a><a name="p5346645194914"></a>kvalue_length</p>
</th>
<td class="cellrowborder" valign="top" width="76.61%" headers="mcps1.1.3.4.1 "><p id="p134604511495"><a name="p134604511495"></a><a name="p134604511495"></a>写入数据的长度，单位：Byte。</p>
</td>
</tr>
<tr id="row027852165114"><th class="firstcol" valign="top" width="23.39%" id="mcps1.1.3.5.1"><p id="p162835235120"><a name="p162835235120"></a><a name="p162835235120"></a>*attr</p>
</th>
<td class="cellrowborder" valign="top" width="76.61%" headers="mcps1.1.3.5.1 "><p id="p4281152165118"><a name="p4281152165118"></a><a name="p4281152165118"></a>要配置的NV项的属性。</p>
</td>
</tr>
<tr id="row446465925112"><th class="firstcol" valign="top" width="23.39%" id="mcps1.1.3.6.1"><p id="p44641659175110"><a name="p44641659175110"></a><a name="p44641659175110"></a>func</p>
</th>
<td class="cellrowborder" valign="top" width="76.61%" headers="mcps1.1.3.6.1 "><p id="p1446413592510"><a name="p1446413592510"></a><a name="p1446413592510"></a>kvalue写入Flash后调用的回调函数。</p>
</td>
</tr>
</tbody>
</table>

<a name="table525394610498"></a>
<table><tbody><tr id="row72539466499"><th class="firstcol" valign="top" width="23.62%" id="mcps1.1.3.1.1"><p id="p11253164654919"><a name="p11253164654919"></a><a name="p11253164654919"></a>uapi_nv_read</p>
</th>
<td class="cellrowborder" valign="top" width="76.38000000000001%" headers="mcps1.1.3.1.1 "><p id="p125318465490"><a name="p125318465490"></a><a name="p125318465490"></a>读取指定NV数据项的值，默认不获取key的属性值。</p>
</td>
</tr>
<tr id="row4253194634912"><th class="firstcol" valign="top" width="23.62%" id="mcps1.1.3.2.1"><p id="p4253114612499"><a name="p4253114612499"></a><a name="p4253114612499"></a>key</p>
</th>
<td class="cellrowborder" valign="top" width="76.38000000000001%" headers="mcps1.1.3.2.1 "><p id="p12531346194919"><a name="p12531346194919"></a><a name="p12531346194919"></a>要读取的NV项的key ID，用于索引。</p>
</td>
</tr>
<tr id="row925324664918"><th class="firstcol" valign="top" width="23.62%" id="mcps1.1.3.3.1"><p id="p164554315543"><a name="p164554315543"></a><a name="p164554315543"></a>kvalue_max_length</p>
</th>
<td class="cellrowborder" valign="top" width="76.38000000000001%" headers="mcps1.1.3.3.1 "><p id="p9253134611495"><a name="p9253134611495"></a><a name="p9253134611495"></a>允许存储数据的最大长度，单位：Byte。</p>
</td>
</tr>
<tr id="row11253164644913"><th class="firstcol" valign="top" width="23.62%" id="mcps1.1.3.4.1"><p id="p20253246104919"><a name="p20253246104919"></a><a name="p20253246104919"></a>*kvalue_length</p>
</th>
<td class="cellrowborder" valign="top" width="76.38000000000001%" headers="mcps1.1.3.4.1 "><p id="p225317462493"><a name="p225317462493"></a><a name="p225317462493"></a>实际读取到的数据长度（读取以四字节对齐）。</p>
</td>
</tr>
<tr id="row6895182265417"><th class="firstcol" valign="top" width="23.62%" id="mcps1.1.3.5.1"><p id="p15895102285417"><a name="p15895102285417"></a><a name="p15895102285417"></a>*kvalue</p>
</th>
<td class="cellrowborder" valign="top" width="76.38000000000001%" headers="mcps1.1.3.5.1 "><p id="p989519221544"><a name="p989519221544"></a><a name="p989519221544"></a>指向保存读取数据的buffer的指针。</p>
</td>
</tr>
</tbody>
</table>

<a name="table71638477494"></a>
<table><tbody><tr id="row15163147174917"><th class="firstcol" valign="top" width="23.82%" id="mcps1.1.3.1.1"><p id="p516344754914"><a name="p516344754914"></a><a name="p516344754914"></a>uapi_nv_read_with_attr</p>
</th>
<td class="cellrowborder" valign="top" width="76.18%" headers="mcps1.1.3.1.1 "><p id="p8163047174919"><a name="p8163047174919"></a><a name="p8163047174919"></a>读取指定NV数据项的值，同时获取key的属性值</p>
</td>
</tr>
<tr id="row1716310471498"><th class="firstcol" valign="top" width="23.82%" id="mcps1.1.3.2.1"><p id="p7163174724914"><a name="p7163174724914"></a><a name="p7163174724914"></a>key</p>
</th>
<td class="cellrowborder" valign="top" width="76.18%" headers="mcps1.1.3.2.1 "><p id="p516384784917"><a name="p516384784917"></a><a name="p516384784917"></a>要读取的NV项的key ID，用于索引。</p>
</td>
</tr>
<tr id="row9163184712499"><th class="firstcol" valign="top" width="23.82%" id="mcps1.1.3.3.1"><p id="p1093420275819"><a name="p1093420275819"></a><a name="p1093420275819"></a>kvalue_max_length</p>
</th>
<td class="cellrowborder" valign="top" width="76.18%" headers="mcps1.1.3.3.1 "><p id="p1579439155819"><a name="p1579439155819"></a><a name="p1579439155819"></a>允许存储数据的最大长度，单位：Byte。</p>
</td>
</tr>
<tr id="row11163204714915"><th class="firstcol" valign="top" width="23.82%" id="mcps1.1.3.4.1"><p id="p21631947194917"><a name="p21631947194917"></a><a name="p21631947194917"></a>*kvalue_length</p>
</th>
<td class="cellrowborder" valign="top" width="76.18%" headers="mcps1.1.3.4.1 "><p id="p167953925815"><a name="p167953925815"></a><a name="p167953925815"></a>实际读取到的数据长度（读取以四字节对齐）。</p>
</td>
</tr>
<tr id="row8993789585"><th class="firstcol" valign="top" width="23.82%" id="mcps1.1.3.5.1"><p id="p5993168125819"><a name="p5993168125819"></a><a name="p5993168125819"></a>*kvalue</p>
</th>
<td class="cellrowborder" valign="top" width="76.18%" headers="mcps1.1.3.5.1 "><p id="p779639155813"><a name="p779639155813"></a><a name="p779639155813"></a>指向保存读取数据的buffer的指针。</p>
</td>
</tr>
<tr id="row137151455813"><th class="firstcol" valign="top" width="23.82%" id="mcps1.1.3.6.1"><p id="p17371111455810"><a name="p17371111455810"></a><a name="p17371111455810"></a>*attr</p>
</th>
<td class="cellrowborder" valign="top" width="76.18%" headers="mcps1.1.3.6.1 "><p id="p337171485810"><a name="p337171485810"></a><a name="p337171485810"></a>获取到的NV项的属性。</p>
</td>
</tr>
</tbody>
</table>

<a name="table11171155012496"></a>
<table><tbody><tr id="row81717509491"><th class="firstcol" valign="top" width="23.97%" id="mcps1.1.3.1.1"><p id="p1717116503494"><a name="p1717116503494"></a><a name="p1717116503494"></a>uapi_nv_get_store_status</p>
</th>
<td class="cellrowborder" valign="top" width="76.03%" headers="mcps1.1.3.1.1 "><p id="p1517115509496"><a name="p1517115509496"></a><a name="p1517115509496"></a>获取NV存储空间使用情况。</p>
</td>
</tr>
<tr id="row01711950114911"><th class="firstcol" valign="top" width="23.97%" id="mcps1.1.3.2.1"><p id="p1543219281924"><a name="p1543219281924"></a><a name="p1543219281924"></a>*status</p>
</th>
<td class="cellrowborder" valign="top" width="76.03%" headers="mcps1.1.3.2.1 "><p id="p1417135074915"><a name="p1417135074915"></a><a name="p1417135074915"></a>指向保存NV状态数据的指针。</p>
</td>
</tr>
</tbody>
</table>

## 开发指引<a name="ZH-CN_TOPIC_0000001790806588"></a>

以下步骤为NV读写操作步骤指引：

1.  写入默认Normal类型NV。

    ```
    uint8_t *test_nv_value; /* 要写入的NV value保存在test_nv_value中 */
    uint32_t test_len = 15; /* 长度为test_len ，例中为15*/
    
    uint16_t key = TEST_KEY; /* TEST_KEY 为该Key的ID*/
    uint16_t key_len= test_len;
    uint8_t *write_value = uapi_malloc(key_len);
    (void)memcpy_s(write_value, key_len, test_nv_value, key_len);
    errcode_t nv_ret_value = uapi_nv_write(key, write_value, key_len);
    if (nv_ret_value != ERRCODE_SUCC) {
        /* ERROR PROCESS */
        uapi_free(wrt_value);
        return ERRCODE_FAIL;
    }
    /* APP PROCESS */
    uapi_free(wrt_value);
    return ERRCODE_SUCC;
    ```

2.  写入带属性NV（配置加密属性，其他略）。

    ```
    uint8_t *test_nv_value; /* 要写入的NV value保存在test_nv_value中 */
    uint32_t test_len = 15; /* 长度为test_len，例中为15 */
    
    uint16_t key = TEST_KEY;
    uint16_t key_len= test_len;
    
    nv_key_attr_t attr = {0};
    attr.permanent = false;
    attr.encrypted = true; /* 加密属性设为true */
    attr.non_upgrade = false
    uint8_t *write_value= uapi_malloc(key_len);
    (void)memcpy_s(write_value, key_len, test_nv_value, key_len);
    errcode_t nv_ret_value = uapi_nv_write_with_attr(key, write_value, key_len, &attr, NULL);
    if (nv_ret_value != ERRCODE_SUCC) {
        /* ERROR PROCESS */
        uapi_free(write_value);
        return ERRCODE_FAIL;
    }
    /* APP PROCESS */
    uapi_free(write_value);
    return ERRCODE_SUCC;
    ```

3.  读取NV。

    ```
    uint16_t key = TEST_KEY;
    uint16_t key_len= test_len;
    uint16_t real_len= 0;
    uint8_t *read_value = uapi_malloc(key_len);
    if (uapi_nv_read(key, key_len, &real_len, read_value) != ERRCODE_SUCC) {
        /* ERROR PROCESS */
        uapi_free(read_value);
        return ERRCODE_FAIL;
    }
    /* APP PROCESS */
    uapi_free(read_value);
    return ERRCODE_SUCC;
    ```

4.  读取NV及属性。

    ```
    uint16_t key = TEST_KEY;
    uint16_t key_len = test_len;
    uint16_t real_len = 0;
    uint8_t *read_value = uapi_malloc(key_len);
    nv_key_attr_t attr = {false, false, false, 0};
    ext_errno nv_ret = uapi_nv_read_with_attr(key, key_len, &real_len, read_value, &attr);
    if (nv_ret != ERRCODE_SUCC ) {
        /* ERROR PROCESS */
        uapi_free(read_value);
        return ERRCODE_FAIL;
    } 
    /* APP PROCESS */
    uapi_free(read_value);
    return ERRCODE_SUCC;
    ```

5.  查询NV空间状态。

    ```
    nv_store_status status;
    if (uapi_nv_get_store_status(&status) == ERRCODE_SUCC) {
        /* APP PROCESS */
        printf("Total:      %d Bytes\r\n", status.total_space);
        printf("used:       %d Bytes\r\n", status.used_space);
        printf("reclaimable:%d Bytes\r\n", status.reclaimable_space);
        printf("corrupted:  %d Bytes\r\n", status.corrupted_space);
        printf("max_key:    %d Bytes\r\n", status.max_key_space);
    }
    ```

>![](public_sys-resources/icon-note.gif) **说明：** 
>开发指引只是API接口的测试用例，为用户提供简单的sample参考，sample中省略了宏、部分变量、回调函数的定义过程和业务处理过程。

## 注意事项<a name="ZH-CN_TOPIC_0000001837645749"></a>

-   uapi\_nv\_write：默认不对所存储的key添加额外属性（是否永久存储、是否加密存储等）。
-   uapi\_nv\_write\_with\_attr：可同时配置key属性和注册回调函数。目前NV代码中没有使用到回调函数，传NULL忽略即可。
-   NV属性结构体和NV空间状态结构体说明详见nv.h文件。
-   NV write和read接口使用到信号量同步获取，禁止在中断回调中使用。

