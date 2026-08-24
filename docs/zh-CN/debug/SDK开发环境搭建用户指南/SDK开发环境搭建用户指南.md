# Preface<a name="ZH-CN_TOPIC_0000002050854473"></a>

**Overview<a name="section4537382116410"></a>**

This document describes the SDK development environment for BS2X series chips (including SDK compilation, application development, etc.), helping users quickly understand the development environment and compile executable files for secondary development.

**Product Version<a name="section1423985410207"></a>**

The product version corresponding to this document is as follows.

<a name="table2270181717471"></a>
<table><thead align="left"><tr id="row15364171712479"><th class="cellrowborder" valign="top" width="31.759999999999998%" id="mcps1.1.3.1.1"><p id="p123646174478"><a name="p123646174478"></a><a name="p123646174478"></a><strong id="b12222191212104"><a name="b12222191212104"></a><a name="b12222191212104"></a>Product Name</strong></p>
</th>
<th class="cellrowborder" valign="top" width="68.24%" id="mcps1.1.3.1.2"><p id="p1936401717470"><a name="p1936401717470"></a><a name="p1936401717470"></a><strong id="b1523661211108"><a name="b1523661211108"></a><a name="b1523661211108"></a>Product Version</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row19364317104716"><td class="cellrowborder" valign="top" width="31.759999999999998%" headers="mcps1.1.3.1.1 "><p id="p14623132513473"><a name="p14623132513473"></a><a name="p14623132513473"></a>BS2X</p>
</td>
<td class="cellrowborder" valign="top" width="68.24%" headers="mcps1.1.3.1.2 "><p id="p733963813395"><a name="p733963813395"></a><a name="p733963813395"></a>V100</p>
</td>
</tr>
</tbody>
</table>

**Reader Audience<a name="section4378592816410"></a>**

This document is mainly applicable to the following engineers:

-   Technical support engineer
-   Software development engineer

**Symbol Conventions<a name="section133020216410"></a>**

The following symbols may appear in this document. Their meanings are as follows.

<a name="table2622507016410"></a>
<table><thead align="left"><tr id="row1530720816410"><th class="cellrowborder" valign="top" width="20.580000000000002%" id="mcps1.1.3.1.1"><p id="p6450074116410"><a name="p6450074116410"></a><a name="p6450074116410"></a><strong id="b2136615816410"><a name="b2136615816410"></a><a name="b2136615816410"></a>Symbol</strong></p>
</th>
<th class="cellrowborder" valign="top" width="79.42%" id="mcps1.1.3.1.2"><p id="p5435366816410"><a name="p5435366816410"></a><a name="p5435366816410"></a><strong id="b5941558116410"><a name="b5941558116410"></a><a name="b5941558116410"></a>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row1372280416410"><td class="cellrowborder" valign="top" width="20.580000000000002%" headers="mcps1.1.3.1.1 "><p id="p3734547016410"><a name="p3734547016410"></a><a name="p3734547016410"></a><a name="image2670064316410"></a><a name="image2670064316410"></a><span><img class="" id="image2670064316410" height="25.270000000000003" width="55.9265" src="figures/zh-cn_image_0000002014775060.png"></span></p>
</td>
<td class="cellrowborder" valign="top" width="79.42%" headers="mcps1.1.3.1.2 "><p id="p1757432116410"><a name="p1757432116410"></a><a name="p1757432116410"></a>Indicates a hazard with a high level of risk which, if not avoided, will result in death or serious injury.</p>
</td>
</tr>
<tr id="row466863216410"><td class="cellrowborder" valign="top" width="20.580000000000002%" headers="mcps1.1.3.1.1 "><p id="p1432579516410"><a name="p1432579516410"></a><a name="p1432579516410"></a><a name="image4895582316410"></a><a name="image4895582316410"></a><span><img class="" id="image4895582316410" height="25.270000000000003" width="55.9265" src="figures/zh-cn_image_0000002050895577.png"></span></p>
</td>
<td class="cellrowborder" valign="top" width="79.42%" headers="mcps1.1.3.1.2 "><p id="p959197916410"><a name="p959197916410"></a><a name="p959197916410"></a>Indicates a hazard with a medium level of risk which, if not avoided, could result in death or serious injury.</p>
</td>
</tr>
<tr id="row123863216410"><td class="cellrowborder" valign="top" width="20.580000000000002%" headers="mcps1.1.3.1.1 "><p id="p1232579516410"><a name="p1232579516410"></a><a name="p1232579516410"></a><a name="image1235582316410"></a><a name="image1235582316410"></a><span><img class="" id="image1235582316410" height="25.270000000000003" width="55.9265" src="figures/zh-cn_image_0000002014775064.png"></span></p>
</td>
<td class="cellrowborder" valign="top" width="79.42%" headers="mcps1.1.3.1.2 "><p id="p123197916410"><a name="p123197916410"></a><a name="p123197916410"></a>Indicates a hazard with a low level of risk which, if not avoided, could result in minor or moderate injury.</p>
</td>
</tr>
<tr id="row5786682116410"><td class="cellrowborder" valign="top" width="20.580000000000002%" headers="mcps1.1.3.1.1 "><p id="p2204984716410"><a name="p2204984716410"></a><a name="p2204984716410"></a><a name="image4504446716410"></a><a name="image4504446716410"></a><span><img class="" id="image4504446716410" height="25.270000000000003" width="55.9265" src="figures/zh-cn_image_0000002014616836.png"></span></p>
</td>
<td class="cellrowborder" valign="top" width="79.42%" headers="mcps1.1.3.1.2 "><p id="p4388861916410"><a name="p4388861916410"></a><a name="p4388861916410"></a>Used to convey equipment or environment safety warnings. If not avoided, it may result in equipment damage, data loss, degraded equipment performance, or other unpredictable results.</p>
<p id="p1238861916410"><a name="p1238861916410"></a><a name="p1238861916410"></a>"Notice" does not involve personal injury.</p>
</td>
</tr>
<tr id="row2856923116410"><td class="cellrowborder" valign="top" width="20.580000000000002%" headers="mcps1.1.3.1.1 "><p id="p5555360116410"><a name="p5555360116410"></a><a name="p5555360116410"></a><a name="image799324016410"></a><a name="image799324016410"></a><span><img class="" id="image799324016410" height="15.96" width="47.88" src="figures/zh-cn_image_0000002050854685.png"></span></p>
</td>
<td class="cellrowborder" valign="top" width="79.42%" headers="mcps1.1.3.1.2 "><p id="p4612588116410"><a name="p4612588116410"></a><a name="p4612588116410"></a>Supplementary description of key information in the main text.</p>
<p id="p1232588116410"><a name="p1232588116410"></a><a name="p1232588116410"></a>"Note" is not a safety warning and does not involve personal, equipment, or environmental damage.</p>
</td>
</tr>
</tbody>
</table>

**Modification Record<a name="section2467512116410"></a>**

<a name="table1557726816410"></a>
<table><thead align="left"><tr id="row2942532716410"><th class="cellrowborder" valign="top" width="19.580000000000002%" id="mcps1.1.4.1.1"><p id="p3778275416410"><a name="p3778275416410"></a><a name="p3778275416410"></a><strong id="b5687322716410"><a name="b5687322716410"></a><a name="b5687322716410"></a>Document Version</strong></p>
</th>
<th class="cellrowborder" valign="top" width="19.11%" id="mcps1.1.4.1.2"><p id="p5627845516410"><a name="p5627845516410"></a><a name="p5627845516410"></a><strong id="b5800814916410"><a name="b5800814916410"></a><a name="b5800814916410"></a>Release Date</strong></p>
</th>
<th class="cellrowborder" valign="top" width="61.309999999999995%" id="mcps1.1.4.1.3"><p id="p2382284816410"><a name="p2382284816410"></a><a name="p2382284816410"></a><strong id="b3316380216410"><a name="b3316380216410"></a><a name="b3316380216410"></a>Modification Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row34241947105220"><td class="cellrowborder" valign="top" width="19.580000000000002%" headers="mcps1.1.4.1.1 "><p id="p204251847165213"><a name="p204251847165213"></a><a name="p204251847165213"></a>04</p>
</td>
<td class="cellrowborder" valign="top" width="19.11%" headers="mcps1.1.4.1.2 "><p id="p44252474520"><a name="p44252474520"></a><a name="p44252474520"></a>2025-08-07</p>
</td>
<td class="cellrowborder" valign="top" width="61.309999999999995%" headers="mcps1.1.4.1.3 "><p id="p12529155415211"><a name="p12529155415211"></a><a name="p12529155415211"></a>Updated the content of the "<a href="打包添加其他bin文件.md">Packaging and Adding Other bin Files</a>" subsection.</p>
</td>
</tr>
<tr id="row372895021211"><td class="cellrowborder" valign="top" width="19.580000000000002%" headers="mcps1.1.4.1.1 "><p id="p1872915507128"><a name="p1872915507128"></a><a name="p1872915507128"></a>03</p>
</td>
<td class="cellrowborder" valign="top" width="19.11%" headers="mcps1.1.4.1.2 "><p id="p127294502129"><a name="p127294502129"></a><a name="p127294502129"></a>2025-05-30</p>
</td>
<td class="cellrowborder" valign="top" width="61.309999999999995%" headers="mcps1.1.4.1.3 "><p id="p4856173615221"><a name="p4856173615221"></a><a name="p4856173615221"></a>Updated the content of the "<a href="flash分区表配置.md">Flash Partition Table Configuration</a>" subsection.</p>
</td>
</tr>
<tr id="row31617137538"><td class="cellrowborder" valign="top" width="19.580000000000002%" headers="mcps1.1.4.1.1 "><p id="p8161191335314"><a name="p8161191335314"></a><a name="p8161191335314"></a>02</p>
</td>
<td class="cellrowborder" valign="top" width="19.11%" headers="mcps1.1.4.1.2 "><p id="p716114136532"><a name="p716114136532"></a><a name="p716114136532"></a>2025-01-24</p>
</td>
<td class="cellrowborder" valign="top" width="61.309999999999995%" headers="mcps1.1.4.1.3 "><a name="ul1051218445539"></a><a name="ul1051218445539"></a><ul id="ul1051218445539"><li>Adjusted the document structure.</li><li>Added the content of the "<a href="搭建Windows开发环境.md">Setting Up the Windows Development Environment</a>" subsection.</li><li>Added the content of the "<a href="编译SDK（Cmake）.md">Compiling the SDK (Cmake)</a>" subsection.</li></ul>
</td>
</tr>
<tr id="row58810414523"><td class="cellrowborder" valign="top" width="19.580000000000002%" headers="mcps1.1.4.1.1 "><p id="p0413131712"><a name="p0413131712"></a><a name="p0413131712"></a>01</p>
</td>
<td class="cellrowborder" valign="top" width="19.11%" headers="mcps1.1.4.1.2 "><p id="p184131311111"><a name="p184131311111"></a><a name="p184131311111"></a>2024-05-15</p>
</td>
<td class="cellrowborder" valign="top" width="61.309999999999995%" headers="mcps1.1.4.1.3 "><p id="p169114261115"><a name="p169114261115"></a><a name="p169114261115"></a>First official release.</p>
</td>
</tr>
<tr id="row6236545165217"><td class="cellrowborder" valign="top" width="19.580000000000002%" headers="mcps1.1.4.1.1 "><p id="p795653135515"><a name="p795653135515"></a><a name="p795653135515"></a>00B03</p>
</td>
<td class="cellrowborder" valign="top" width="19.11%" headers="mcps1.1.4.1.2 "><p id="p395613165520"><a name="p395613165520"></a><a name="p395613165520"></a>2024-02-29</p>
</td>
<td class="cellrowborder" valign="top" width="61.309999999999995%" headers="mcps1.1.4.1.3 "><p id="p1295714315557"><a name="p1295714315557"></a><a name="p1295714315557"></a>Updated the content of the "Version Compilation" subsection.</p>
</td>
</tr>
<tr id="row12832184925218"><td class="cellrowborder" valign="top" width="19.580000000000002%" headers="mcps1.1.4.1.1 "><p id="p1169313194333"><a name="p1169313194333"></a><a name="p1169313194333"></a>00B02</p>
<p id="p2149706016410"><a name="p2149706016410"></a><a name="p2149706016410"></a>00B01</p>
</td>
<td class="cellrowborder" valign="top" width="19.11%" headers="mcps1.1.4.1.2 "><p id="p6693181912338"><a name="p6693181912338"></a><a name="p6693181912338"></a>2023-12-04</p>
<p id="p648803616410"><a name="p648803616410"></a><a name="p648803616410"></a>2023-10-27</p>
</td>
<td class="cellrowborder" valign="top" width="61.309999999999995%" headers="mcps1.1.4.1.3 "><p id="p195751335183313"><a name="p195751335183313"></a><a name="p195751335183313"></a>Updated the content of the "Starting Compilation" subsection.</p>
<p id="p1946537916410"><a name="p1946537916410"></a><a name="p1946537916410"></a>First temporary release.</p>
</td>
</tr>
</tbody>
</table>

# Setting Up the Development Environment<a name="ZH-CN_TOPIC_0000002050895357"></a>




## SDK Development Environment Overview<a name="ZH-CN_TOPIC_0000002014616608"></a>

A typical SDK development environment mainly includes:

-   Linux server

    A Linux server is mainly used to set up the cross-compilation environment to compile executable code that can run on the target board.

-   Workstation

    A workstation is mainly used for target board flashing and debugging. It connects to the target board over a serial port, allowing developers to flash target board images and debug programs from the workstation. The workstation usually requires terminal tools for logging in to the Linux server and the target board and viewing the target board's print output. The workstation typically runs Windows or Linux. Common terminal tools on Windows or Linux workstations include SecureCRT, Putty, miniCom, etc., which need to be downloaded from their official websites.

-   Target board

    This document uses the DEMO board as an example of a target board. The DEMO board connects to the workstation via a USB-to-serial adapter. The workstation flashes the cross-compiled DEMO board image to the DEMO board over the serial port, as shown in [Figure 1](#fig1236915206315).

    **Figure 1**  SDK Development Environment<a name="fig1236915206315"></a>  
    
    ![](figures/zh-cn_image_0000002014775020.png)

## Setting Up the Windows Development Environment<a name="ZH-CN_TOPIC_0000002156721308"></a>

The BS2X solution provides IDE development tools for Windows that support one-click version builds. For setting up an IDE-based compilation environment, refer to the "BS2X V100 IDE Tool Usage Guide". This document does not repeat the details.

## Setting Up the Linux Development Environment<a name="ZH-CN_TOPIC_0000002050895361"></a>

Ubuntu 20.04 or later is recommended for the Linux system, with bash as the Shell. The SDK is compiled with Cmake (3.14.1 or later). Compilation tools also include Python (3.8.0 or later), etc.




### Configuring the Shell<a name="ZH-CN_TOPIC_0000002014616616"></a>

Configure bash as the default shell. Open a Linux terminal and run the command "sudo dpkg-reconfigure dash", then select no.

### Installing Cmake<a name="ZH-CN_TOPIC_0000002050854469"></a>

Open a Linux terminal and run the command "sudo apt install cmake" to complete the Cmake installation.

### Installing the Python Environment<a name="ZH-CN_TOPIC_0000002014774836"></a>

1.  Open a Linux terminal, enter the command "python3 -V" to check the Python version. Python 3.8.0 or later is recommended.
2.  If the Python version is too old, run "sudo apt-get update" to update the system to the latest version, or install Python3 with the command "sudo apt-get install python3 -y" (root/sudo privileges are required). After installation, check the Python version again.

    If the version requirement is still not met, download the source package of the corresponding version from "[https://www.python.org/downloads/source/](https://www.python.org/downloads/source/)  ". For download and installation instructions, refer to  [https://wiki.python.org/moin/BeginnersGuide/Download](https://wiki.python.org/moin/BeginnersGuide/Download)  and the README in the source package.

3.  Install the Python package management tools by running the command "sudo apt-get install python3-setuptools python3-pip -y" (root/sudo privileges are required).
4.  Install Kconfiglib 14.1.0+. Use the command "sudo pip3 install kconfiglib" (root/sudo privileges are required), or download the .whl file (for example, kconfiglib-14.1.0-py2.py3-none-any.whl) from "[https://pypi.org/project/kconfiglib](https://pypi.org/project/kconfiglib)" and install it with "pip3 install kconfiglib-xxx.whl" (root/sudo privileges are required). Alternatively, download the source package, extract it locally, and install it with "python setup.py install" (root/sudo privileges are required). The installation completion screen is shown in [Figure 1](#fig743717512220).

    **Figure 1**  Example of Completed Kconfiglib Component Installation<a name="fig743717512220"></a>  
    ![](figures/安装Kconfiglib组件包完成示例.png "Example of Completed Kconfiglib Component Installation")

5.  Install the Python component packages required for upgrade file signing.

    Install pycparser:

    After downloading the .whl file (for example, pycparser-2.21-py2.py3-none-any.whl) from "[https://pypi.org/project/pycparser/](https://pypi.org/project/pycparser/)", install it with "pip3 install pycparser-xxx.whl" (root/sudo privileges are required). Alternatively, download the source package, extract it locally, and install it with "python setup.py install" (root/sudo privileges are required). After the installation is complete, the interface will prompt "Successfully intalled pycparser-2.21".

>![](public_sys-resources/icon-note.gif) **Note:** 
>If the build environment contains multiple python versions, especially multiple python versions of the same version, and the user cannot identify which one is being used, it is recommended to install Python component packages from the component package source code in this case.

# Compiling the SDK<a name="ZH-CN_TOPIC_0000002050895353"></a>



## SDK Directory Structure<a name="ZH-CN_TOPIC_0000002014616612"></a>

The SDK root directory structure is shown in [Table 1](#table13927142512394).

**Table 1**  SDK Root Directory

<a name="table13927142512394"></a>
<table><thead align="left"><tr id="row15927132514396"><th class="cellrowborder" valign="top" width="27.38%" id="mcps1.2.3.1.1"><p id="p11927325113916"><a name="p11927325113916"></a><a name="p11927325113916"></a>Directory</p>
</th>
<th class="cellrowborder" valign="top" width="72.61999999999999%" id="mcps1.2.3.1.2"><p id="p1292722593913"><a name="p1292722593913"></a><a name="p1292722593913"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row292882517399"><td class="cellrowborder" valign="top" width="27.38%" headers="mcps1.2.3.1.1 "><p id="p159281025163910"><a name="p159281025163910"></a><a name="p159281025163910"></a>application</p>
</td>
<td class="cellrowborder" valign="top" width="72.61999999999999%" headers="mcps1.2.3.1.2 "><p id="p417918234"><a name="p417918234"></a><a name="p417918234"></a>Application layer code (including demo programs as reference examples).</p>
</td>
</tr>
<tr id="row12308241122019"><td class="cellrowborder" valign="top" width="27.38%" headers="mcps1.2.3.1.1 "><p id="p1566453261918"><a name="p1566453261918"></a><a name="p1566453261918"></a>build</p>
</td>
<td class="cellrowborder" valign="top" width="72.61999999999999%" headers="mcps1.2.3.1.2 "><p id="p466403211919"><a name="p466403211919"></a><a name="p466403211919"></a>Scripts and configuration files required for SDK builds.</p>
</td>
</tr>
<tr id="row1653555018202"><td class="cellrowborder" valign="top" width="27.38%" headers="mcps1.2.3.1.1 "><p id="p1066416323191"><a name="p1066416323191"></a><a name="p1066416323191"></a>build.py</p>
</td>
<td class="cellrowborder" valign="top" width="72.61999999999999%" headers="mcps1.2.3.1.2 "><p id="p14664123216198"><a name="p14664123216198"></a><a name="p14664123216198"></a>Entry script for compilation.</p>
</td>
</tr>
<tr id="row10787191320215"><td class="cellrowborder" valign="top" width="27.38%" headers="mcps1.2.3.1.1 "><p id="p116642329192"><a name="p116642329192"></a><a name="p116642329192"></a>CMakeLists.txt</p>
</td>
<td class="cellrowborder" valign="top" width="72.61999999999999%" headers="mcps1.2.3.1.2 "><p id="p14664132191912"><a name="p14664132191912"></a><a name="p14664132191912"></a>Top-level "CMakeLists.txt" file of the Cmake project.</p>
</td>
</tr>
<tr id="row109286253399"><td class="cellrowborder" valign="top" width="27.38%" headers="mcps1.2.3.1.1 "><p id="p17664432111917"><a name="p17664432111917"></a><a name="p17664432111917"></a>config.in</p>
</td>
<td class="cellrowborder" valign="top" width="72.61999999999999%" headers="mcps1.2.3.1.2 "><p id="p136644327197"><a name="p136644327197"></a><a name="p136644327197"></a>Kconfig configuration file.</p>
</td>
</tr>
<tr id="row15928132512396"><td class="cellrowborder" valign="top" width="27.38%" headers="mcps1.2.3.1.1 "><p id="p666414326194"><a name="p666414326194"></a><a name="p666414326194"></a>drivers</p>
</td>
<td class="cellrowborder" valign="top" width="72.61999999999999%" headers="mcps1.2.3.1.2 "><p id="p1566483281918"><a name="p1566483281918"></a><a name="p1566483281918"></a>Driver code.</p>
</td>
</tr>
<tr id="row415218166102"><td class="cellrowborder" valign="top" width="27.38%" headers="mcps1.2.3.1.1 "><p id="p19664732181920"><a name="p19664732181920"></a><a name="p19664732181920"></a>include</p>
</td>
<td class="cellrowborder" valign="top" width="72.61999999999999%" headers="mcps1.2.3.1.2 "><p id="p1066453216197"><a name="p1066453216197"></a><a name="p1066453216197"></a>Directory for storing API header files.</p>
</td>
</tr>
<tr id="row75842056117"><td class="cellrowborder" valign="top" width="27.38%" headers="mcps1.2.3.1.1 "><p id="p1166412325191"><a name="p1166412325191"></a><a name="p1166412325191"></a>interim_binary</p>
</td>
<td class="cellrowborder" valign="top" width="72.61999999999999%" headers="mcps1.2.3.1.2 "><p id="p1866403221917"><a name="p1866403221917"></a><a name="p1866403221917"></a>Directory for storing libraries.</p>
</td>
</tr>
<tr id="row152262035269"><td class="cellrowborder" valign="top" width="27.38%" headers="mcps1.2.3.1.1 "><p id="p1566413221912"><a name="p1566413221912"></a><a name="p1566413221912"></a>kernel</p>
</td>
<td class="cellrowborder" valign="top" width="72.61999999999999%" headers="mcps1.2.3.1.2 "><p id="p1066483281910"><a name="p1066483281910"></a><a name="p1066483281910"></a>Kernel code and OS interface adaptation layer code.</p>
</td>
</tr>
<tr id="row26011201747"><td class="cellrowborder" valign="top" width="27.38%" headers="mcps1.2.3.1.1 "><p id="p433325713498"><a name="p433325713498"></a><a name="p433325713498"></a>middleware</p>
</td>
<td class="cellrowborder" valign="top" width="72.61999999999999%" headers="mcps1.2.3.1.2 "><p id="p233335715491"><a name="p233335715491"></a><a name="p233335715491"></a>Middleware code.</p>
</td>
</tr>
<tr id="row17392173512420"><td class="cellrowborder" valign="top" width="27.38%" headers="mcps1.2.3.1.1 "><p id="p14333185794910"><a name="p14333185794910"></a><a name="p14333185794910"></a>open_source</p>
</td>
<td class="cellrowborder" valign="top" width="72.61999999999999%" headers="mcps1.2.3.1.2 "><p id="p14333957164919"><a name="p14333957164919"></a><a name="p14333957164919"></a>Open-source code.</p>
</td>
</tr>
<tr id="row17747172410413"><td class="cellrowborder" valign="top" width="27.38%" headers="mcps1.2.3.1.1 "><p id="p1333312572493"><a name="p1333312572493"></a><a name="p1333312572493"></a>protocol</p>
</td>
<td class="cellrowborder" valign="top" width="72.61999999999999%" headers="mcps1.2.3.1.2 "><p id="p6333157154912"><a name="p6333157154912"></a><a name="p6333157154912"></a>Protocol stacks such as BLE and SLE.</p>
</td>
</tr>
<tr id="row768611001510"><td class="cellrowborder" valign="top" width="27.38%" headers="mcps1.2.3.1.1 "><p id="p03333575492"><a name="p03333575492"></a><a name="p03333575492"></a>test</p>
</td>
<td class="cellrowborder" valign="top" width="72.61999999999999%" headers="mcps1.2.3.1.2 "><p id="p333345713495"><a name="p333345713495"></a><a name="p333345713495"></a>Test suite code.</p>
</td>
</tr>
<tr id="row44171914181911"><td class="cellrowborder" valign="top" width="27.38%" headers="mcps1.2.3.1.1 "><p id="p93331557104916"><a name="p93331557104916"></a><a name="p93331557104916"></a>tools</p>
</td>
<td class="cellrowborder" valign="top" width="72.61999999999999%" headers="mcps1.2.3.1.2 "><p id="p1833415714912"><a name="p1833415714912"></a><a name="p1833415714912"></a>Contains the compilation toolchain (for both Linux and Windows), image packaging scripts, NV creation tools, and signing scripts, etc.</p>
</td>
</tr>
<tr id="row15401556194817"><td class="cellrowborder" valign="top" width="27.38%" headers="mcps1.2.3.1.1 "><p id="p53342570499"><a name="p53342570499"></a><a name="p53342570499"></a>output</p>
</td>
<td class="cellrowborder" valign="top" width="72.61999999999999%" headers="mcps1.2.3.1.2 "><p id="p43341957154917"><a name="p43341957154917"></a><a name="p43341957154917"></a>Object files and intermediate files generated during compilation (including library files, printed logs, generated binary files, etc.).</p>
</td>
</tr>
</tbody>
</table>

Note: The output directory described in the table above is generated after compilation. The root directory after decompressing the SDK is shown in [Figure 1](#fig112752111447).

**Figure 1**  Example of Decompressing the SDK<a name="fig112752111447"></a>  

![](figures/zh-cn_image_0000002156816834.png)

## Compiling the SDK (Cmake)<a name="ZH-CN_TOPIC_0000002014616620"></a>








### Compilation Methods<a name="ZH-CN_TOPIC_0000002014774840"></a>

Run the "python3 build.py" command in the root directory to run the compilation script and compile the corresponding SDK program. The compilation commands are listed in [Table 1](#table1646491114816). standard-bs21-n1100 is used as an example here; compilation targets may differ across BS2X projects.

**Table 1**  build.sh Parameter List

<a name="table1646491114816"></a>
<table><thead align="left"><tr id="row44654114810"><th class="cellrowborder" valign="top" width="12.76%" id="mcps1.2.4.1.1"><p id="p194651412487"><a name="p194651412487"></a><a name="p194651412487"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="40.35%" id="mcps1.2.4.1.2"><p id="p6461872507"><a name="p6461872507"></a><a name="p6461872507"></a>Example</p>
</th>
<th class="cellrowborder" valign="top" width="46.89%" id="mcps1.2.4.1.3"><p id="p1246515144820"><a name="p1246515144820"></a><a name="p1246515144820"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row746513144812"><td class="cellrowborder" valign="top" width="12.76%" headers="mcps1.2.4.1.1 "><p id="p2465219482"><a name="p2465219482"></a><a name="p2465219482"></a>None</p>
</td>
<td class="cellrowborder" valign="top" width="40.35%" headers="mcps1.2.4.1.2 "><p id="p1215022142715"><a name="p1215022142715"></a><a name="p1215022142715"></a>python3 build.py standard-bs21-n1100</p>
</td>
<td class="cellrowborder" valign="top" width="46.89%" headers="mcps1.2.4.1.3 "><p id="p144651117489"><a name="p144651117489"></a><a name="p144651117489"></a>Starts incremental compilation for the standard-bs21-n1100 target.</p>
</td>
</tr>
<tr id="row04651218489"><td class="cellrowborder" valign="top" width="12.76%" headers="mcps1.2.4.1.1 "><p id="p24654119480"><a name="p24654119480"></a><a name="p24654119480"></a>-c</p>
</td>
<td class="cellrowborder" valign="top" width="40.35%" headers="mcps1.2.4.1.2 "><p id="p16463717500"><a name="p16463717500"></a><a name="p16463717500"></a>python3 build.py -c standard-bs21-n1100</p>
</td>
<td class="cellrowborder" valign="top" width="46.89%" headers="mcps1.2.4.1.3 "><p id="p1046516134810"><a name="p1046516134810"></a><a name="p1046516134810"></a>Starts full compilation for the standard-bs21-n1100 target.</p>
</td>
</tr>
<tr id="row11696675533"><td class="cellrowborder" valign="top" width="12.76%" headers="mcps1.2.4.1.1 "><p id="p206971172535"><a name="p206971172535"></a><a name="p206971172535"></a>menuconfig</p>
</td>
<td class="cellrowborder" valign="top" width="40.35%" headers="mcps1.2.4.1.2 "><p id="p1669710713535"><a name="p1669710713535"></a><a name="p1669710713535"></a>python3 build.py standard-bs21-n1100 menuconfig</p>
</td>
<td class="cellrowborder" valign="top" width="46.89%" headers="mcps1.2.4.1.3 "><p id="p18697274534"><a name="p18697274534"></a><a name="p18697274534"></a>Starts the menuconfig graphical configuration interface for the standard-bs21-n1100 target.</p>
</td>
</tr>
</tbody>
</table>

**Table 2**  Compilation Target Introduction

<a name="table16988747155411"></a>
<table><thead align="left"><tr id="row1898820470542"><th class="cellrowborder" valign="top" width="42.96%" id="mcps1.2.3.1.1"><p id="p69881047105420"><a name="p69881047105420"></a><a name="p69881047105420"></a>Compilation Target</p>
</th>
<th class="cellrowborder" valign="top" width="57.04%" id="mcps1.2.3.1.2"><p id="p898824715413"><a name="p898824715413"></a><a name="p898824715413"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row20988114713546"><td class="cellrowborder" valign="top" width="42.96%" headers="mcps1.2.3.1.1 "><p id="p1098804755419"><a name="p1098804755419"></a><a name="p1098804755419"></a>python3 build.py -c standard-bs21-n1100</p>
</td>
<td class="cellrowborder" valign="top" width="57.04%" headers="mcps1.2.3.1.2 "><p id="p7989144715418"><a name="p7989144715418"></a><a name="p7989144715418"></a>Compilation target for the app version (flashboot will be packaged into the compilation output).</p>
</td>
</tr>
<tr id="row14862228125611"><td class="cellrowborder" valign="top" width="42.96%" headers="mcps1.2.3.1.1 "><p id="p757993465615"><a name="p757993465615"></a><a name="p757993465615"></a>python3 build.py -c flashboot-bs21-n1100</p>
</td>
<td class="cellrowborder" valign="top" width="57.04%" headers="mcps1.2.3.1.2 "><p id="p4863132885617"><a name="p4863132885617"></a><a name="p4863132885617"></a>Compilation target for the flashboot image.</p>
</td>
</tr>
</tbody>
</table>

The compiled flash images are located in the "output/bs21/fwpkg/standard-bs21-n1100" directory (see [Table 3](#table5535429403)).

**Table 3**  Flash Images

<a name="table5535429403"></a>
<table><thead align="left"><tr id="row1353722184019"><th class="cellrowborder" valign="top" width="35.449999999999996%" id="mcps1.2.3.1.1"><p id="p97691634164219"><a name="p97691634164219"></a><a name="p97691634164219"></a>File Name</p>
</th>
<th class="cellrowborder" valign="top" width="64.55%" id="mcps1.2.3.1.2"><p id="p253772164019"><a name="p253772164019"></a><a name="p253772164019"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row75376234019"><td class="cellrowborder" valign="top" width="35.449999999999996%" headers="mcps1.2.3.1.1 "><p id="p1740682318402"><a name="p1740682318402"></a><a name="p1740682318402"></a>bs21_all_in_one.fwpkg</p>
</td>
<td class="cellrowborder" valign="top" width="64.55%" headers="mcps1.2.3.1.2 "><p id="p10903201011919"><a name="p10903201011919"></a><a name="p10903201011919"></a>When flashing a blank chip, this file must be flashed. It contains all the content that needs to be flashed, including: loaderboot_sign.bin, flashboot_sign_a.bin, flashboot_sign_b.bin, bs21_all_nv.bin, and application_sign.bin.</p>
<p id="p7548577443"><a name="p7548577443"></a><a name="p7548577443"></a>The files are described as follows:</p>
<p id="p195743193449"><a name="p195743193449"></a><a name="p195743193449"></a>loaderboot_sign.bin: the image file of loaderboot. When an upgrade starts, the romboot hardened in the chip receives this image file, loads it into memory, and runs it. loaderboot is responsible for receiving subsequent image files. Note: This image runs only in RAM during the upgrade phase and is not stored in flash.</p>
<p id="p101101949144511"><a name="p101101949144511"></a><a name="p101101949144511"></a>flashboot_sign_a.bin: the image file of flashboot. After flashing is complete, this is the primary flashboot image to execute. Its integrity is verified at startup.</p>
<p id="p205118146539"><a name="p205118146539"></a><a name="p205118146539"></a>flashboot_sign_b.bin: the backup image file of flashboot. This image is loaded when the primary flashboot image is checked as invalid or corrupted.</p>
<p id="p4313165175313"><a name="p4313165175313"></a><a name="p4313165175313"></a>bs21_all_nv.bin: the image file of the parameter area.</p>
<p id="p123521010192719"><a name="p123521010192719"></a><a name="p123521010192719"></a>application_sign.bin: the image file of the application version.</p>
</td>
</tr>
<tr id="row15537132114020"><td class="cellrowborder" valign="top" width="35.449999999999996%" headers="mcps1.2.3.1.1 "><p id="p20351123274017"><a name="p20351123274017"></a><a name="p20351123274017"></a>bs21_loadapp_only.fwpkg</p>
</td>
<td class="cellrowborder" valign="top" width="64.55%" headers="mcps1.2.3.1.2 "><p id="p109031510191919"><a name="p109031510191919"></a><a name="p109031510191919"></a>Upgrade packaging file, including: loaderboot_sign.bin and application_sign.bin. Does not include flashboot-related content.</p>
<p id="p167261737104910"><a name="p167261737104910"></a><a name="p167261737104910"></a>After the chip has been flashed with the "bs21_all_in_one.fwpkg" image, if subsequent modifications do not involve flashboot or nv changes, this file can be used for upgrading.</p>
</td>
</tr>
<tr id="row14916571496"><td class="cellrowborder" valign="top" width="35.449999999999996%" headers="mcps1.2.3.1.1 "><p id="p6492195724914"><a name="p6492195724914"></a><a name="p6492195724914"></a>bs21_flashboot_only.fwpkg</p>
</td>
<td class="cellrowborder" valign="top" width="64.55%" headers="mcps1.2.3.1.2 "><p id="p15492125744919"><a name="p15492125744919"></a><a name="p15492125744919"></a>Boot upgrade packaging file, including: loaderboot_sign.bin, flashboot_sign_a.bin, and flashboot_sign_b.bin. Does not include application-related content.</p>
<p id="p1595611412517"><a name="p1595611412517"></a><a name="p1595611412517"></a>After the chip has been flashed with the "bs21_all_in_one.fwpkg" image, if there is a need to upgrade flashboot, this file can be used for upgrading.</p>
</td>
</tr>
<tr id="row1972752413919"><td class="cellrowborder" valign="top" width="35.449999999999996%" headers="mcps1.2.3.1.1 "><p id="p12728924153915"><a name="p12728924153915"></a><a name="p12728924153915"></a>bs21_nv_only.fwpkg</p>
</td>
<td class="cellrowborder" valign="top" width="64.55%" headers="mcps1.2.3.1.2 "><p id="p5728132443915"><a name="p5728132443915"></a><a name="p5728132443915"></a>nv upgrade packaging file, including loaderboot_sign.bin and bs21_all_nv.bin. Does not include application or flashboot-related content.</p>
<p id="p192271348204018"><a name="p192271348204018"></a><a name="p192271348204018"></a>After the chip has been flashed with the "bs21_all_in_one.fwpkg" image, if there is a need to upgrade nv parameters, this file can be used for upgrading.</p>
</td>
</tr>
</tbody>
</table>

Note: The intermediate files generated by compilation are located in the "output/bs21/acore/standard-bs21-n1100" directory.

### Compilation Parameters in Detail<a name="ZH-CN_TOPIC_0000002014774828"></a>

The parameters accepted by the compilation command and their explanations are shown in [Table 1](#table36913222319).

**Table 1**  Compilation Parameter Information

<a name="table36913222319"></a>
<table><thead align="left"><tr id="row205261342910"><th class="cellrowborder" valign="top" width="20.65%" id="mcps1.2.3.1.1"><p id="p6526649913"><a name="p6526649913"></a><a name="p6526649913"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="79.35%" id="mcps1.2.3.1.2"><p id="p135275415919"><a name="p135275415919"></a><a name="p135275415919"></a>Parameter Information</p>
</th>
</tr>
</thead>
<tbody><tr id="row1289314403919"><td class="cellrowborder" valign="top" width="20.65%" headers="mcps1.2.3.1.1 "><p id="p1089312404913"><a name="p1089312404913"></a><a name="p1089312404913"></a>-c</p>
</td>
<td class="cellrowborder" valign="top" width="79.35%" headers="mcps1.2.3.1.2 "><p id="p489312401193"><a name="p489312401193"></a><a name="p489312401193"></a>Compiles after clean.</p>
</td>
</tr>
<tr id="row9701422193117"><td class="cellrowborder" valign="top" width="20.65%" headers="mcps1.2.3.1.1 "><p id="p157010226318"><a name="p157010226318"></a><a name="p157010226318"></a>-j</p>
</td>
<td class="cellrowborder" valign="top" width="79.35%" headers="mcps1.2.3.1.2 "><p id="p17092210313"><a name="p17092210313"></a><a name="p17092210313"></a>-j&lt;num&gt;: executes compilation with num threads, for example -j16 or -j8.</p>
<p id="p194801456193213"><a name="p194801456193213"></a><a name="p194801456193213"></a>Uses the maximum number of threads by default.</p>
</td>
</tr>
<tr id="row270622113120"><td class="cellrowborder" valign="top" width="20.65%" headers="mcps1.2.3.1.1 "><p id="p327613157339"><a name="p327613157339"></a><a name="p327613157339"></a>-def=</p>
</td>
<td class="cellrowborder" valign="top" width="79.35%" headers="mcps1.2.3.1.2 "><p id="p570622133113"><a name="p570622133113"></a><a name="p570622133113"></a>-def=XXX,YYY,ZZZ=x,...  Adds the XXX, YYY, and ZZZ=x compilation macros to the current compilation target.</p>
<p id="p687205165210"><a name="p687205165210"></a><a name="p687205165210"></a>Use -def=-:XXX to disable the XXX macro;</p>
<p id="p7751710105219"><a name="p7751710105219"></a><a name="p7751710105219"></a>Use -def=-:ZZZ=x to add or modify the ZZZ macro.</p>
</td>
</tr>
<tr id="row5701722153118"><td class="cellrowborder" valign="top" width="20.65%" headers="mcps1.2.3.1.1 "><p id="p147012225311"><a name="p147012225311"></a><a name="p147012225311"></a>-component=</p>
</td>
<td class="cellrowborder" valign="top" width="79.35%" headers="mcps1.2.3.1.2 "><p id="p170922163112"><a name="p170922163112"></a><a name="p170922163112"></a>-component=XXX,YYY,...  Compiles only the XXX and YYY components.</p>
</td>
</tr>
<tr id="row12380153694910"><td class="cellrowborder" valign="top" width="20.65%" headers="mcps1.2.3.1.1 "><p id="p183801736124914"><a name="p183801736124914"></a><a name="p183801736124914"></a>-ninja</p>
</td>
<td class="cellrowborder" valign="top" width="79.35%" headers="mcps1.2.3.1.2 "><p id="p6744245135819"><a name="p6744245135819"></a><a name="p6744245135819"></a>Uses ninja to generate intermediate files. Unix makefile is used by default.</p>
</td>
</tr>
<tr id="row57010229319"><td class="cellrowborder" valign="top" width="20.65%" headers="mcps1.2.3.1.1 "><p id="p8706227315"><a name="p8706227315"></a><a name="p8706227315"></a>-[release / debug]</p>
</td>
<td class="cellrowborder" valign="top" width="79.35%" headers="mcps1.2.3.1.2 "><p id="p270112211312"><a name="p270112211312"></a><a name="p270112211312"></a>release:  Saves time when generating disassembly files;</p>
<p id="p16649163112211"><a name="p16649163112211"></a><a name="p16649163112211"></a>debug:   Provides more comprehensive information when generating disassembly files but takes longer.</p>
<p id="p18807163914214"><a name="p18807163914214"></a><a name="p18807163914214"></a>debug is used by default.</p>
</td>
</tr>
<tr id="row187072220311"><td class="cellrowborder" valign="top" width="20.65%" headers="mcps1.2.3.1.1 "><p id="p770422133120"><a name="p770422133120"></a><a name="p770422133120"></a>-dump</p>
</td>
<td class="cellrowborder" valign="top" width="79.35%" headers="mcps1.2.3.1.2 "><p id="p4701622143115"><a name="p4701622143115"></a><a name="p4701622143115"></a>Outputs all parameter lists of the target in the terminal during compilation (including compilation macros, components, compilation options, etc.).</p>
</td>
</tr>
<tr id="row1170152283114"><td class="cellrowborder" valign="top" width="20.65%" headers="mcps1.2.3.1.1 "><p id="p5701222103111"><a name="p5701222103111"></a><a name="p5701222103111"></a>-nhso</p>
</td>
<td class="cellrowborder" valign="top" width="79.35%" headers="mcps1.2.3.1.2 "><p id="p117012221318"><a name="p117012221318"></a><a name="p117012221318"></a>Does not update the HSO database.</p>
</td>
</tr>
<tr id="row87082218313"><td class="cellrowborder" valign="top" width="20.65%" headers="mcps1.2.3.1.1 "><p id="p1870102213317"><a name="p1870102213317"></a><a name="p1870102213317"></a>-out_libs</p>
</td>
<td class="cellrowborder" valign="top" width="79.35%" headers="mcps1.2.3.1.2 "><p id="p370192214311"><a name="p370192214311"></a><a name="p370192214311"></a>-out_libs=file_path: instead of linking into an elf, packages all .a files into one large .a file.</p>
</td>
</tr>
<tr id="row57062212312"><td class="cellrowborder" valign="top" width="20.65%" headers="mcps1.2.3.1.1 "><p id="p1270182211310"><a name="p1270182211310"></a><a name="p1270182211310"></a>others</p>
</td>
<td class="cellrowborder" valign="top" width="79.35%" headers="mcps1.2.3.1.2 "><p id="p17019227313"><a name="p17019227313"></a><a name="p17019227313"></a>Used as a keyword for matching compilation target_names.</p>
</td>
</tr>
</tbody>
</table>

### Compilation Options in Detail<a name="ZH-CN_TOPIC_0000002050854453"></a>

bs2x configures compilation options in .py files in different directories, as shown in [Table 1](#table20340122212538).

**Table 1**  BS2X Common Component Compilation Options

<a name="table20340122212538"></a>
<table><thead align="left"><tr id="row5340132295310"><th class="cellrowborder" align="center" valign="top" width="15.85%" id="mcps1.2.5.1.1"><p id="p1934072235311"><a name="p1934072235311"></a><a name="p1934072235311"></a>Compilation Option Type</p>
</th>
<th class="cellrowborder" align="center" valign="top" width="16.68%" id="mcps1.2.5.1.2"><p id="p9340122218538"><a name="p9340122218538"></a><a name="p9340122218538"></a>Description</p>
</th>
<th class="cellrowborder" align="center" valign="top" width="42.47%" id="mcps1.2.5.1.3"><p id="p12340192213533"><a name="p12340192213533"></a><a name="p12340192213533"></a>Content</p>
</th>
<th class="cellrowborder" align="center" valign="top" width="25%" id="mcps1.2.5.1.4"><p id="p183401122125318"><a name="p183401122125318"></a><a name="p183401122125318"></a>Corresponding File Control Path</p>
</th>
</tr>
</thead>
<tbody><tr id="row1234092285320"><td class="cellrowborder" align="left" valign="top" width="15.85%" headers="mcps1.2.5.1.1 "><p id="p2034012205315"><a name="p2034012205315"></a><a name="p2034012205315"></a>common_ccflags</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="16.68%" headers="mcps1.2.5.1.2 "><p id="p6340172295318"><a name="p6340172295318"></a><a name="p6340172295318"></a>Basic compilation option</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="42.47%" headers="mcps1.2.5.1.3 "><p id="p334017226530"><a name="p334017226530"></a><a name="p334017226530"></a>-std=gnu99 -Wall -Werror -Wextra -Winit-self -Wpointer-arith -Wstrict-prototypes -Wno-type-limits -fno-strict-aliasing -Os -fno-unwind-tables</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p33404224537"><a name="p33404224537"></a><a name="p33404224537"></a>\sdk\build\config\target_config\common_config.py</p>
</td>
</tr>
<tr id="row1534012216539"><td class="cellrowborder" align="left" valign="top" width="15.85%" headers="mcps1.2.5.1.1 "><p id="p63407223532"><a name="p63407223532"></a><a name="p63407223532"></a>riscv31</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="16.68%" headers="mcps1.2.5.1.2 "><p id="p12340142265320"><a name="p12340142265320"></a><a name="p12340142265320"></a>Chip type compilation option</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="42.47%" headers="mcps1.2.5.1.3 "><p id="p18340922175319"><a name="p18340922175319"></a><a name="p18340922175319"></a>-ffreestanding -fdata-sections -Wno-implicit-fallthrough -ffunction-sections -nostdlib -pipe -fno-tree-scev-cprop -fno-common -mpush-pop -msmall-data-limit=0 -fno-ipa-ra -Wtrampolines -Wlogical-op -Wjump-misses-init -Wa,-enable-c-lbu-sb -Wa,-enable-c-lhu-sh -fimm-compare -femit-muliadd -fmerge-immshf -femit-uxtb-uxth -femit-lli -femit-clz -fldm-stm-optimize -g</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p17340422185318"><a name="p17340422185318"></a><a name="p17340422185318"></a>\sdk\build\config\target_config\common_config.py</p>
</td>
</tr>
<tr id="row143404224531"><td class="cellrowborder" align="left" valign="top" width="15.85%" headers="mcps1.2.5.1.1 "><p id="p16340152214539"><a name="p16340152214539"></a><a name="p16340152214539"></a>fp_flags</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="16.68%" headers="mcps1.2.5.1.2 "><p id="p12340182275318"><a name="p12340182275318"></a><a name="p12340182275318"></a>Hard floating-point compilation option</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="42.47%" headers="mcps1.2.5.1.3 "><p id="p113401322195311"><a name="p113401322195311"></a><a name="p113401322195311"></a>-march=rv32imfc -mabi=ilp32f</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p1734013223533"><a name="p1734013223533"></a><a name="p1734013223533"></a>\sdk\build\config\target_config\bs21\target_config.py</p>
</td>
</tr>
<tr id="row20340322205313"><td class="cellrowborder" align="left" valign="top" width="15.85%" headers="mcps1.2.5.1.1 "><p id="p334013226531"><a name="p334013226531"></a><a name="p334013226531"></a>codesize_flags</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="16.68%" headers="mcps1.2.5.1.2 "><p id="p434012235317"><a name="p434012235317"></a><a name="p434012235317"></a>codesize optimization option</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="42.47%" headers="mcps1.2.5.1.3 "><p id="p43401422205318"><a name="p43401422205318"></a><a name="p43401422205318"></a>--short-enums -madjust-regorder -madjust-const-cost -freorder-commu-args -fimm-compare-expand -frmv-str-zero -mfp-const-opt -frtl-sequence-abstract -frtl-hoist-sink -fsafe-alias-multipointer -finline-optimize-size -fmuliadd-expand -mlli-expand -Wa,-mcjal-expand -foptimize-reg-alloc -fsplit-multi-zero-assignments -floop-optimize-size -Wa,-mlli-relax -mpattern-abstract -foptimize-pro-and-epilogue</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p16341142215317"><a name="p16341142215317"></a><a name="p16341142215317"></a>\sdk\build\config\target_config\bs21\target_config.py</p>
</td>
</tr>
</tbody>
</table>

The detailed descriptions of the compilation options are shown in [Table 2](#table5190336213).

**Table 2**  Detailed Compilation Option Descriptions

<a name="table5190336213"></a>
<table><thead align="left"><tr id="row1319033617116"><th class="cellrowborder" valign="top" width="23.27%" id="mcps1.2.3.1.1"><p id="p17190636711"><a name="p17190636711"></a><a name="p17190636711"></a>Option</p>
</th>
<th class="cellrowborder" valign="top" width="76.73%" id="mcps1.2.3.1.2"><p id="p11190936911"><a name="p11190936911"></a><a name="p11190936911"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row71905363117"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p519017366118"><a name="p519017366118"></a><a name="p519017366118"></a>-std=gnu99</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p2019017361613"><a name="p2019017361613"></a><a name="p2019017361613"></a>Uses the ISO C99 standard plus GNU extensions.</p>
</td>
</tr>
<tr id="row12190103614112"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p2190236315"><a name="p2190236315"></a><a name="p2190236315"></a>-Wall</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p81901236214"><a name="p81901236214"></a><a name="p81901236214"></a>Displays all warnings after compilation.</p>
</td>
</tr>
<tr id="row101901836410"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p2190143614118"><a name="p2190143614118"></a><a name="p2190143614118"></a>-Werror</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p10190163611115"><a name="p10190163611115"></a><a name="p10190163611115"></a>Upgrades all warnings to errors.</p>
</td>
</tr>
<tr id="row1119017361713"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p019020361111"><a name="p019020361111"></a><a name="p019020361111"></a>-Wextra</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p20190163620117"><a name="p20190163620117"></a><a name="p20190163620117"></a>Enables additional warning information (a supplement to -Wall).</p>
</td>
</tr>
<tr id="row619013367118"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p019015360118"><a name="p019015360118"></a><a name="p019015360118"></a>-Winit-self</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p161900368113"><a name="p161900368113"></a><a name="p161900368113"></a>Warns about uninitialized variables that are initialized with themselves.</p>
</td>
</tr>
<tr id="row719019363117"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p119014366115"><a name="p119014366115"></a><a name="p119014366115"></a>-Wpointer-arith</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p1619043612113"><a name="p1619043612113"></a><a name="p1619043612113"></a>Warns about anything that depends on the size of a function type or of void.</p>
</td>
</tr>
<tr id="row14190153619116"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p111901367112"><a name="p111901367112"></a><a name="p111901367112"></a>-Wstrict-prototypes</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p91904361411"><a name="p91904361411"></a><a name="p91904361411"></a>Warns if a function is declared or defined without specifying argument types.</p>
</td>
</tr>
<tr id="row1291829722"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p109181091128"><a name="p109181091128"></a><a name="p109181091128"></a>-Wno-type-limits</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p09187916216"><a name="p09187916216"></a><a name="p09187916216"></a>Suppresses warnings about comparisons that are always true or always false due to the limited range of data types.</p>
</td>
</tr>
<tr id="row358111191722"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p1658117191624"><a name="p1658117191624"></a><a name="p1658117191624"></a>-fno-strict-aliasing</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p35814192026"><a name="p35814192026"></a><a name="p35814192026"></a>Disables the strict-aliasing optimization rule: pointers of different types never point to the same memory area.</p>
</td>
</tr>
<tr id="row8581919926"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p205811519027"><a name="p205811519027"></a><a name="p205811519027"></a>-Os</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p95813198217"><a name="p95813198217"></a><a name="p95813198217"></a>Optimizes the object file size specifically, performing all -O2 optimization options that do not increase the object file size. In addition, -Os also performs options that further optimize the program.</p>
</td>
</tr>
<tr id="row16125102412213"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p1412517241221"><a name="p1412517241221"></a><a name="p1412517241221"></a>-fno-unwind-tables</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p131259244217"><a name="p131259244217"></a><a name="p131259244217"></a>Deletes the unwind debugging information.</p>
</td>
</tr>
<tr id="row1012518241212"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p1312512243217"><a name="p1312512243217"></a><a name="p1312512243217"></a>-ffreestanding</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p612515241523"><a name="p612515241523"></a><a name="p612515241523"></a>Asserts that compilation occurs in a freestanding environment.</p>
</td>
</tr>
<tr id="row31251624524"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p13125152413211"><a name="p13125152413211"></a><a name="p13125152413211"></a>-fdata-sections</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p1512552417212"><a name="p1512552417212"></a><a name="p1512552417212"></a>Places each data item in its own section (ELF only).</p>
</td>
</tr>
<tr id="row1912517240210"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p1112512417210"><a name="p1112512417210"></a><a name="p1112512417210"></a>-Wno-implicit-fallthrough</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p3125924522"><a name="p3125924522"></a><a name="p3125924522"></a>Ignores errors about missing break statements in switch-case during compilation.</p>
</td>
</tr>
<tr id="row19253297218"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p32522910212"><a name="p32522910212"></a><a name="p32522910212"></a>-ffunction-sections</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p112517292029"><a name="p112517292029"></a><a name="p112517292029"></a>Places each function in its own section (ELF only).</p>
</td>
</tr>
<tr id="row0223859152611"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p12801157122614"><a name="p12801157122614"></a><a name="p12801157122614"></a>-nostdlib</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p580145752611"><a name="p580145752611"></a><a name="p580145752611"></a>Disables the default header file and library file search directories.</p>
</td>
</tr>
<tr id="row82231359192613"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p480114577263"><a name="p480114577263"></a><a name="p480114577263"></a>-pipe</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p08011257132610"><a name="p08011257132610"></a><a name="p08011257132610"></a>Uses pipes during compilation, leveraging GCC's pipe functionality to improve compilation speed.</p>
</td>
</tr>
<tr id="row4223185992617"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p780155782616"><a name="p780155782616"></a><a name="p780155782616"></a>-fno-tree-scev-cprop</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p11801115713269"><a name="p11801115713269"></a><a name="p11801115713269"></a>Disables copy propagation using scalar evolution information, related to code space optimization.</p>
</td>
</tr>
<tr id="row42231559132610"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p38013573266"><a name="p38013573266"></a><a name="p38013573266"></a>-fno-common</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p12801195752613"><a name="p12801195752613"></a><a name="p12801195752613"></a>Can change uninitialized global variables in static libraries from weak symbols to strong symbols. When all static libraries are linked into an executable file, if there are two or more strong symbols with the same name at the same time, the linker will report an error.</p>
</td>
</tr>
<tr id="row222315919261"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p1280155716262"><a name="p1280155716262"></a><a name="p1280155716262"></a>-mpush-pop</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p10801457172618"><a name="p10801457172618"></a><a name="p10801457172618"></a>CodeSize optimization. This compilation option requires the CPU version to support instructions such as push/pop/popret/lwm/swm.</p>
</td>
</tr>
<tr id="row52231259132616"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p38011357172611"><a name="p38011357172611"></a><a name="p38011357172611"></a>-msmall-data-limit=0</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p13801105716267"><a name="p13801105716267"></a><a name="p13801105716267"></a>CodeSize optimization. This compilation option requires the CPU version to support instructions such as push/pop/popret/lwm/swm.</p>
</td>
</tr>
<tr id="row1422318591268"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p7801115712618"><a name="p7801115712618"></a><a name="p7801115712618"></a>-fno-ipa-ra</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p480110573264"><a name="p480110573264"></a><a name="p480110573264"></a>Disables the compiler's optimization for leaf functions (caused by the -fipa-ra parameter when the -O2 optimization option is added to compilation options).</p>
</td>
</tr>
<tr id="row112231859142619"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p2801135712616"><a name="p2801135712616"></a><a name="p2801135712616"></a>-Wtrampolines</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p118011557192613"><a name="p118011557192613"></a><a name="p118011557192613"></a>This option is used to check whether the code contains nested functions. GCC has a special name for nested functions: trampoline.</p>
</td>
</tr>
<tr id="row822315592263"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p58016579269"><a name="p58016579269"></a><a name="p58016579269"></a>-Wlogical-op</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p2801185716269"><a name="p2801185716269"></a><a name="p2801185716269"></a>Gives a warning when the result of a logical operation always appears to be true or false.</p>
</td>
</tr>
<tr id="row3223159172612"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p98011357202616"><a name="p98011357202616"></a><a name="p98011357202616"></a>-Wjump-misses-init</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p4801657112615"><a name="p4801657112615"></a><a name="p4801657112615"></a>Warns about variables declared and initialized after switch or goto statements.</p>
</td>
</tr>
<tr id="row16223205992611"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p2801857142613"><a name="p2801857142613"></a><a name="p2801857142613"></a>-Wa,-enable-c-lbu-sb</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p980145762611"><a name="p980145762611"></a><a name="p980145762611"></a>Assembler optimization, disabled by default. If this optimization is enabled, the assembler will use compressed lbu &amp; sb to replace lbu &amp; sb.</p>
</td>
</tr>
<tr id="row12223145992612"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p68019577260"><a name="p68019577260"></a><a name="p68019577260"></a>-Wa,-enable-c-lhu-sh</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p780116576263"><a name="p780116576263"></a><a name="p780116576263"></a>Assembler optimization, disabled by default. If this optimization is enabled, the assembler will use compressed lhu &amp; sh to replace lhu &amp; sh.</p>
</td>
</tr>
<tr id="row922385932618"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p8801125718262"><a name="p8801125718262"></a><a name="p8801125718262"></a>-fimm-compare</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p1380125712267"><a name="p1380125712267"></a><a name="p1380125712267"></a>Code size optimization. It can merge the two instructions (li, bxx) for non-zero immediate comparisons into one instruction (bxxi).</p>
</td>
</tr>
<tr id="row17223155916263"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p138011557162617"><a name="p138011557162617"></a><a name="p138011557162617"></a>-femit-muliadd</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p780114574266"><a name="p780114574266"></a><a name="p780114574266"></a>CodeSize optimization. It can merge multiple add-tree instructions into one instruction.</p>
</td>
</tr>
<tr id="row14223145912610"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p118019579264"><a name="p118019579264"></a><a name="p118019579264"></a>-fmerge-immshf</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p580113575267"><a name="p580113575267"></a><a name="p580113575267"></a>CodeSize optimization. It can merge immediate shifts into one instruction. The combination takes effect only with options above -O1.</p>
</td>
</tr>
<tr id="row122385912614"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p78011257162613"><a name="p78011257162613"></a><a name="p78011257162613"></a>-femit-uxtb-uxth</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p9802195772618"><a name="p9802195772618"></a><a name="p9802195772618"></a>CodeSize optimization. Optimizes unsigned extended bytes and unsigned extended half-words into uxtb and uxth (16 bytes). The combination is available only with options above -O1.</p>
</td>
</tr>
<tr id="row10223135911262"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p12802175762619"><a name="p12802175762619"></a><a name="p12802175762619"></a>-femit-lli</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p15802135719269"><a name="p15802135719269"></a><a name="p15802135719269"></a>Uses the 48-bit l.li instruction instead of the 64-bit lui + addi instruction for 32-bit long immediate loading. This optimization is used in combination with the insn combination.</p>
</td>
</tr>
<tr id="row522395932614"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p16802155782615"><a name="p16802155782615"></a><a name="p16802155782615"></a>-femit-clz</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p158021557112619"><a name="p158021557112619"></a><a name="p158021557112619"></a>Supports the CLZ instruction. All calls to the __builtin_clz function will be optimized into the CLZ instruction.</p>
</td>
</tr>
<tr id="row152221259102610"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p1180215717269"><a name="p1180215717269"></a><a name="p1180215717269"></a>-fldm-stm-optimize</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p58021057112610"><a name="p58021057112610"></a><a name="p58021057112610"></a>Enables the optimization that replaces consecutive WORD loads/stores with ldmia/stmia, disabled by default.</p>
</td>
</tr>
<tr id="row19222195911264"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p18802205772613"><a name="p18802205772613"></a><a name="p18802205772613"></a>-g</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p1580235712268"><a name="p1580235712268"></a><a name="p1580235712268"></a>Debug compilation option. For executable binary files, the following method can be used to determine whether debugging information is included.</p>
</td>
</tr>
<tr id="row8222125972613"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p13802105710266"><a name="p13802105710266"></a><a name="p13802105710266"></a>-mabi=ilp32f</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p880285711261"><a name="p880285711261"></a><a name="p880285711261"></a>Supports hard floating point (specifies the integer and floating-point calling conventions).</p>
</td>
</tr>
<tr id="row62223599267"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p11802125782610"><a name="p11802125782610"></a><a name="p11802125782610"></a>-march=rv32imfc</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p180225712268"><a name="p180225712268"></a><a name="p180225712268"></a>Supports hard floating point (generates code for the given RISC-V ISA).</p>
</td>
</tr>
<tr id="row022216592268"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p11802115732615"><a name="p11802115732615"></a><a name="p11802115732615"></a>--short-enums</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p1280214577264"><a name="p1280214577264"></a><a name="p1280214577264"></a>CodeSize optimization. enum types equal the smallest integer type large enough.</p>
</td>
</tr>
<tr id="row17222125972619"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p880285772615"><a name="p880285772615"></a><a name="p880285772615"></a>-madjust-regorder</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p4802125762613"><a name="p4802125762613"></a><a name="p4802125762613"></a>Register allocation optimization - adjusts the register allocation order.</p>
</td>
</tr>
<tr id="row42226593261"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p10802657102615"><a name="p10802657102615"></a><a name="p10802657102615"></a>-madjust-const-cost</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p5802957152612"><a name="p5802957152612"></a><a name="p5802957152612"></a>Immediate value repeated-loading optimization.</p>
</td>
</tr>
<tr id="row7222165972619"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p580265710263"><a name="p580265710263"></a><a name="p580265710263"></a>-freorder-commu-args</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p2802105719261"><a name="p2802105719261"></a><a name="p2802105719261"></a>Floating-point operation commutative operand optimization.</p>
</td>
</tr>
<tr id="row1922295942618"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p128021057142619"><a name="p128021057142619"></a><a name="p128021057142619"></a>-fimm-compare-expand</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p13802057142614"><a name="p13802057142614"></a><a name="p13802057142614"></a>Extended instruction constant comparison instruction optimization.</p>
</td>
</tr>
<tr id="row62227599269"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p198027575269"><a name="p198027575269"></a><a name="p198027575269"></a>-frmv-str-zero</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p180218572268"><a name="p180218572268"></a><a name="p180218572268"></a>rodata section constant string alignment optimization.</p>
</td>
</tr>
<tr id="row20222125911269"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p2802125702610"><a name="p2802125702610"></a><a name="p2802125702610"></a>-mfp-const-opt</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p48021057162618"><a name="p48021057162618"></a><a name="p48021057162618"></a>Floating-point constant loading optimization.</p>
</td>
</tr>
<tr id="row322255912263"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p680220574266"><a name="p680220574266"></a><a name="p680220574266"></a>-mswitch-jump-table</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p1080265714268"><a name="p1080265714268"></a><a name="p1080265714268"></a>switch-case jump table optimization.</p>
</td>
</tr>
<tr id="row1422275916266"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p15802165792620"><a name="p15802165792620"></a><a name="p15802165792620"></a>-frtl-sequence-abstract</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p880218573260"><a name="p880218573260"></a><a name="p880218573260"></a>Intra-function procedure optimization.</p>
</td>
</tr>
<tr id="row192221459112614"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p198020573260"><a name="p198020573260"></a><a name="p198020573260"></a>-frtl-hoist-sink</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p980255715269"><a name="p980255715269"></a><a name="p980255715269"></a>Code movement optimization.</p>
</td>
</tr>
<tr id="row22221659202615"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p780210572261"><a name="p780210572261"></a><a name="p780210572261"></a>-fsafe-alias-multipointer</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p14802155772613"><a name="p14802155772613"></a><a name="p14802155772613"></a>Multi-level pointer repeated-loading optimization.</p>
</td>
</tr>
<tr id="row52220590262"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p580275711266"><a name="p580275711266"></a><a name="p580275711266"></a>-finline-optimize-size</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p9802115722617"><a name="p9802115722617"></a><a name="p9802115722617"></a>inline inlining cost model optimization.</p>
</td>
</tr>
<tr id="row422255910268"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p10802165719268"><a name="p10802165719268"></a><a name="p10802165719268"></a>-fmuliadd-expand</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p15802125772620"><a name="p15802125772620"></a><a name="p15802125772620"></a>Extended instruction multiply-add instruction optimization (muliadd optimization).</p>
</td>
</tr>
<tr id="row1022225915261"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p8802185715264"><a name="p8802185715264"></a><a name="p8802185715264"></a>-mlli-expand</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p12802175712265"><a name="p12802175712265"></a><a name="p12802175712265"></a>Extended instruction l.li instruction optimization.</p>
</td>
</tr>
<tr id="row162222059172614"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p2802195718261"><a name="p2802195718261"></a><a name="p2802195718261"></a>-Wa,-mcjal-expand</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p1980295715265"><a name="p1980295715265"></a><a name="p1980295715265"></a>Assembler jal compressed instruction optimization.</p>
</td>
</tr>
<tr id="row9222135920268"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p680211576264"><a name="p680211576264"></a><a name="p680211576264"></a>-foptimize-reg-alloc</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p1980295717268"><a name="p1980295717268"></a><a name="p1980295717268"></a>Register allocation optimization - adjusts the register allocation priority.</p>
</td>
</tr>
<tr id="row102227596265"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p18802175792618"><a name="p18802175792618"></a><a name="p18802175792618"></a>-fsplit-multi-zero-assignments</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p8802125715260"><a name="p8802125715260"></a><a name="p8802125715260"></a>Consecutive zero-value assignment optimization.</p>
</td>
</tr>
<tr id="row18222135932618"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p1280225714264"><a name="p1280225714264"></a><a name="p1280225714264"></a>-floop-optimize-size</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p13802165792611"><a name="p13802165792611"></a><a name="p13802165792611"></a>Loop structure optimization.</p>
</td>
</tr>
<tr id="row622212598262"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p3802957102613"><a name="p3802957102613"></a><a name="p3802957102613"></a>-Wa,-mlli-relax</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p480225719264"><a name="p480225719264"></a><a name="p480225719264"></a>High-frequency immediate value loading optimization (coordinated optimization between the assembler and the linker).</p>
</td>
</tr>
<tr id="row19222459132612"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p6802657122612"><a name="p6802657122612"></a><a name="p6802657122612"></a>-mpattern-abstract</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p1280375711260"><a name="p1280375711260"></a><a name="p1280375711260"></a>Interprocedural abstraction optimization (abstracts and optimizes based on known patterns).</p>
</td>
</tr>
<tr id="row112215590261"><td class="cellrowborder" valign="top" width="23.27%" headers="mcps1.2.3.1.1 "><p id="p38031257182617"><a name="p38031257182617"></a><a name="p38031257182617"></a>-foptimize-pro-and-epilogue</p>
</td>
<td class="cellrowborder" valign="top" width="76.73%" headers="mcps1.2.3.1.2 "><p id="p108038575262"><a name="p108038575262"></a><a name="p108038575262"></a>Function prologue and epilogue optimization.</p>
</td>
</tr>
</tbody>
</table>

### Packaging and Adding Other bin Files<a name="ZH-CN_TOPIC_0000002050895345"></a>

Currently, when bs21 compiles bs21\_all\_in\_one.fwpkg, the bs21\_all\_nv.bin and application\_sign.bin files are compiled by default, and the loaderboot\_sign.bin, flashboot\_sign\_a.bin, and flashboot\_sign\_b.bin files are added during packaging. The files are described in [Table 3](编译方法.md#table5535429403).

To package other bin files, add them as follows:

1.  Open the /tools/pkg/chip\_packet/bs2x/packet.py file in the root path.
2.  Add code in the make\_all\_in\_one\_packet function, as shown in [Figure 1](#fig9503124071916).

    **Figure 1**  File Path and Function to Be Added<a name="fig9503124071916"></a>  
    ![](figures/文件路径和待添加函数.png "File Path and Function to Be Added")

3.  Add the bin file path in the function, using partition.bin as an example.

    Each concatenated string represents one directory level (folder name and file name).

    The actual path of the concatenated partition.bin: sdk\\interim\_binary\\bs21\\bin\\boot\_bin\\loaderboot\_sign.bin.

    **Figure 2**  bin File Path Diagram<a name="fig137811571192"></a>  
    ![](figures/bin文件路径图.png "bin File Path Diagram")

4.  Set the packaging parameters, separating parameters with "|", as shown in [Figure 3](#fig149913416201).

    **Figure 3**  bin File Compilation Parameters<a name="fig149913416201"></a>  
    ![](figures/bin文件编译参数.png "bin File Compilation Parameters")

    1. Flash location. The remaining addresses of the single board can be found in the sdk\\build\\config\\target\_config\\bs2x\\flash\_sector\_config\\bs2x-xxx.json file.

    2. The occupied space size.

    3. The file type.

    -   0: loader.
    -   1: indicates a normal flash file, flashed to flash.
    -   3: eFuse.
    -   4: OTP.

5.  At the end of the function, add the variables with the compilation parameters and paths set to the compilation list, as shown in [Figure 3](#fig149913416201).

    **Figure 4**  Adding the Path to the Compilation List<a name="fig127881192020"></a>  
    ![](figures/添加路径到编译列表.png "Adding the Path to the Compilation List")

6.  The compilation result is shown in [Figure 5](#fig131271820142012).

    **Figure 5**  Compilation Result<a name="fig131271820142012"></a>  
    ![](figures/编译结果.png "Compilation Result")

>![](public_sys-resources/icon-note.gif) **Note:** 
>If the newly added bin files need to be upgraded via OTA, refer to the corresponding content in the "BS2X V100 Upgrade Solution Usage Guide" to adapt OTA upgrade support for the newly added bin files.

### Flash Partition Table Configuration<a name="ZH-CN_TOPIC_0000002014774832"></a>

The path of the partition table configuration file is "sdk\\build\\config\\target\_config\\bs21\\flash\_sector\_config\\xxx.json".

![](figures/zh-cn_image_0000002321022121.png)

**Table 1**  Partition Table Description

<a name="table1956131716324"></a>
<table><thead align="left"><tr id="row1056221715324"><th class="cellrowborder" valign="top" width="10.24%" id="mcps1.2.5.1.1"><p id="p856214175326"><a name="p856214175326"></a><a name="p856214175326"></a>Partition Table Id</p>
</th>
<th class="cellrowborder" valign="top" width="19.3%" id="mcps1.2.5.1.2"><p id="p19562131773219"><a name="p19562131773219"></a><a name="p19562131773219"></a>Start Address</p>
</th>
<th class="cellrowborder" valign="top" width="20.72%" id="mcps1.2.5.1.3"><p id="p256271743218"><a name="p256271743218"></a><a name="p256271743218"></a>Partition Length</p>
</th>
<th class="cellrowborder" valign="top" width="49.74%" id="mcps1.2.5.1.4"><p id="p156251711325"><a name="p156251711325"></a><a name="p156251711325"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row14562917143214"><td class="cellrowborder" valign="top" width="10.24%" headers="mcps1.2.5.1.1 "><p id="p2562141719328"><a name="p2562141719328"></a><a name="p2562141719328"></a>0x00</p>
</td>
<td class="cellrowborder" valign="top" width="19.3%" headers="mcps1.2.5.1.2 "><p id="p835118346381"><a name="p835118346381"></a><a name="p835118346381"></a>0x00001000</p>
</td>
<td class="cellrowborder" valign="top" width="20.72%" headers="mcps1.2.5.1.3 "><p id="p19901114993916"><a name="p19901114993916"></a><a name="p19901114993916"></a>0x0000A000</p>
</td>
<td class="cellrowborder" valign="top" width="49.74%" headers="mcps1.2.5.1.4 "><p id="p172967560396"><a name="p172967560396"></a><a name="p172967560396"></a>flashboot a: secondary boot main area (size is configured based on the actual usage).</p>
</td>
</tr>
<tr id="row2056251723219"><td class="cellrowborder" valign="top" width="10.24%" headers="mcps1.2.5.1.1 "><p id="p1156261711323"><a name="p1156261711323"></a><a name="p1156261711323"></a>0x01</p>
</td>
<td class="cellrowborder" valign="top" width="19.3%" headers="mcps1.2.5.1.2 "><p id="p8351113493813"><a name="p8351113493813"></a><a name="p8351113493813"></a>0x0000B000</p>
</td>
<td class="cellrowborder" valign="top" width="20.72%" headers="mcps1.2.5.1.3 "><p id="p18901149203915"><a name="p18901149203915"></a><a name="p18901149203915"></a>0x00000000</p>
</td>
<td class="cellrowborder" valign="top" width="49.74%" headers="mcps1.2.5.1.4 "><p id="p7115201311403"><a name="p7115201311403"></a><a name="p7115201311403"></a>flashboot b: secondary boot backup area (size is configured based on the actual usage).</p>
</td>
</tr>
<tr id="row956271715322"><td class="cellrowborder" valign="top" width="10.24%" headers="mcps1.2.5.1.1 "><p id="p1956221783217"><a name="p1956221783217"></a><a name="p1956221783217"></a>0x23</p>
</td>
<td class="cellrowborder" valign="top" width="19.3%" headers="mcps1.2.5.1.2 "><p id="p10352173463813"><a name="p10352173463813"></a><a name="p10352173463813"></a>0x0000B000</p>
</td>
<td class="cellrowborder" valign="top" width="20.72%" headers="mcps1.2.5.1.3 "><p id="p109019492394"><a name="p109019492394"></a><a name="p109019492394"></a>0x00073000</p>
</td>
<td class="cellrowborder" valign="top" width="49.74%" headers="mcps1.2.5.1.4 "><p id="p1181510123118"><a name="p1181510123118"></a><a name="p1181510123118"></a>acpu image: application partition.</p>
</td>
</tr>
<tr id="row956213171329"><td class="cellrowborder" valign="top" width="10.24%" headers="mcps1.2.5.1.1 "><p id="p6374133916337"><a name="p6374133916337"></a><a name="p6374133916337"></a>0x25</p>
</td>
<td class="cellrowborder" valign="top" width="19.3%" headers="mcps1.2.5.1.2 "><p id="p16352934183818"><a name="p16352934183818"></a><a name="p16352934183818"></a>0x00000000</p>
</td>
<td class="cellrowborder" valign="top" width="20.72%" headers="mcps1.2.5.1.3 "><p id="p1690115499394"><a name="p1690115499394"></a><a name="p1690115499394"></a>0x00000080</p>
</td>
<td class="cellrowborder" valign="top" width="49.74%" headers="mcps1.2.5.1.4 "><p id="p711461213322"><a name="p711461213322"></a><a name="p711461213322"></a>nv data: nv data area.</p>
</td>
</tr>
<tr id="row165621117193217"><td class="cellrowborder" valign="top" width="10.24%" headers="mcps1.2.5.1.1 "><p id="p75629175320"><a name="p75629175320"></a><a name="p75629175320"></a>0x26</p>
</td>
<td class="cellrowborder" valign="top" width="19.3%" headers="mcps1.2.5.1.2 "><p id="p19352634123820"><a name="p19352634123820"></a><a name="p19352634123820"></a>0x00000080</p>
</td>
<td class="cellrowborder" valign="top" width="20.72%" headers="mcps1.2.5.1.3 "><p id="p690111498399"><a name="p690111498399"></a><a name="p690111498399"></a>0x00000700</p>
</td>
<td class="cellrowborder" valign="top" width="49.74%" headers="mcps1.2.5.1.4 "><p id="p134156118331"><a name="p134156118331"></a><a name="p134156118331"></a>fota dat: fota backup area.</p>
</td>
</tr>
<tr id="row17562121773213"><td class="cellrowborder" valign="top" width="10.24%" headers="mcps1.2.5.1.1 "><p id="p18563191717324"><a name="p18563191717324"></a><a name="p18563191717324"></a>0x27</p>
</td>
<td class="cellrowborder" valign="top" width="19.3%" headers="mcps1.2.5.1.2 "><p id="p18757926203320"><a name="p18757926203320"></a><a name="p18757926203320"></a>0x00000000</p>
</td>
<td class="cellrowborder" valign="top" width="20.72%" headers="mcps1.2.5.1.3 "><p id="p3256554183317"><a name="p3256554183317"></a><a name="p3256554183317"></a>0x00000000</p>
</td>
<td class="cellrowborder" valign="top" width="49.74%" headers="mcps1.2.5.1.4 "><p id="p9825201463417"><a name="p9825201463417"></a><a name="p9825201463417"></a>rsv1: reserved partition 1.</p>
</td>
</tr>
<tr id="row256313170321"><td class="cellrowborder" valign="top" width="10.24%" headers="mcps1.2.5.1.1 "><p id="p14563317173215"><a name="p14563317173215"></a><a name="p14563317173215"></a>0x28</p>
</td>
<td class="cellrowborder" valign="top" width="19.3%" headers="mcps1.2.5.1.2 "><p id="p635263483815"><a name="p635263483815"></a><a name="p635263483815"></a>0x00000000</p>
</td>
<td class="cellrowborder" valign="top" width="20.72%" headers="mcps1.2.5.1.3 "><p id="p143411956123315"><a name="p143411956123315"></a><a name="p143411956123315"></a>0x00000000</p>
</td>
<td class="cellrowborder" valign="top" width="49.74%" headers="mcps1.2.5.1.4 "><p id="p1569019166349"><a name="p1569019166349"></a><a name="p1569019166349"></a>rsv1: reserved partition 2.</p>
</td>
</tr>
<tr id="row13563101716328"><td class="cellrowborder" valign="top" width="10.24%" headers="mcps1.2.5.1.1 "><p id="p156311703215"><a name="p156311703215"></a><a name="p156311703215"></a>0x29</p>
</td>
<td class="cellrowborder" valign="top" width="19.3%" headers="mcps1.2.5.1.2 "><p id="p935217342385"><a name="p935217342385"></a><a name="p935217342385"></a>0x00000000</p>
</td>
<td class="cellrowborder" valign="top" width="20.72%" headers="mcps1.2.5.1.3 "><p id="p133209584339"><a name="p133209584339"></a><a name="p133209584339"></a>0x00000000</p>
</td>
<td class="cellrowborder" valign="top" width="49.74%" headers="mcps1.2.5.1.4 "><p id="p63126289342"><a name="p63126289342"></a><a name="p63126289342"></a>rsv1: reserved partition 3.</p>
</td>
</tr>
<tr id="row35636173326"><td class="cellrowborder" valign="top" width="10.24%" headers="mcps1.2.5.1.1 "><p id="p1256313171324"><a name="p1256313171324"></a><a name="p1256313171324"></a>0x30</p>
</td>
<td class="cellrowborder" valign="top" width="19.3%" headers="mcps1.2.5.1.2 "><p id="p93528349384"><a name="p93528349384"></a><a name="p93528349384"></a>0x00000000</p>
</td>
<td class="cellrowborder" valign="top" width="20.72%" headers="mcps1.2.5.1.3 "><p id="p083920083412"><a name="p083920083412"></a><a name="p083920083412"></a>0x00000000</p>
</td>
<td class="cellrowborder" valign="top" width="49.74%" headers="mcps1.2.5.1.4 "><p id="p1183751873415"><a name="p1183751873415"></a><a name="p1183751873415"></a>rsv1: reserved partition 4.</p>
</td>
</tr>
<tr id="row55638179321"><td class="cellrowborder" valign="top" width="10.24%" headers="mcps1.2.5.1.1 "><p id="p175632176321"><a name="p175632176321"></a><a name="p175632176321"></a>0x31</p>
</td>
<td class="cellrowborder" valign="top" width="19.3%" headers="mcps1.2.5.1.2 "><p id="p6352734113816"><a name="p6352734113816"></a><a name="p6352734113816"></a>0x00000000</p>
</td>
<td class="cellrowborder" valign="top" width="20.72%" headers="mcps1.2.5.1.3 "><p id="p109011649173913"><a name="p109011649173913"></a><a name="p109011649173913"></a>0x00000000</p>
</td>
<td class="cellrowborder" valign="top" width="49.74%" headers="mcps1.2.5.1.4 "><p id="p46395207342"><a name="p46395207342"></a><a name="p46395207342"></a>rsv1: reserved partition 5.</p>
</td>
</tr>
<tr id="row1756314172327"><td class="cellrowborder" valign="top" width="10.24%" headers="mcps1.2.5.1.1 "><p id="p55631217153217"><a name="p55631217153217"></a><a name="p55631217153217"></a>0x32</p>
</td>
<td class="cellrowborder" valign="top" width="19.3%" headers="mcps1.2.5.1.2 "><p id="p13352143412387"><a name="p13352143412387"></a><a name="p13352143412387"></a>0x00000000</p>
</td>
<td class="cellrowborder" valign="top" width="20.72%" headers="mcps1.2.5.1.3 "><p id="p7901124911392"><a name="p7901124911392"></a><a name="p7901124911392"></a>0x00000000</p>
</td>
<td class="cellrowborder" valign="top" width="49.74%" headers="mcps1.2.5.1.4 "><p id="p01718235344"><a name="p01718235344"></a><a name="p01718235344"></a>rsv1: reserved partition 6.</p>
</td>
</tr>
<tr id="row1356361733214"><td class="cellrowborder" valign="top" width="10.24%" headers="mcps1.2.5.1.1 "><p id="p35631317153213"><a name="p35631317153213"></a><a name="p35631317153213"></a>0x33</p>
</td>
<td class="cellrowborder" valign="top" width="19.3%" headers="mcps1.2.5.1.2 "><p id="p183521634153818"><a name="p183521634153818"></a><a name="p183521634153818"></a>0x00000000</p>
</td>
<td class="cellrowborder" valign="top" width="20.72%" headers="mcps1.2.5.1.3 "><p id="p26641889346"><a name="p26641889346"></a><a name="p26641889346"></a>0x00000000</p>
</td>
<td class="cellrowborder" valign="top" width="49.74%" headers="mcps1.2.5.1.4 "><p id="p10464725173419"><a name="p10464725173419"></a><a name="p10464725173419"></a>rsv1: reserved partition 7.</p>
</td>
</tr>
</tbody>
</table>

>![](public_sys-resources/icon-note.gif) **Note:** 
>The partition information with partition table Ids in the range [0x0, 0x26] is used for image loading, startup, and OTA upgrades. Please modify it with caution. Partition table information can be obtained by passing the partition Id to the uapi\_partition\_get\_info interface, which returns the corresponding address and length.
>Partition\_defines passes the partition table macro definitions as parameters. When Use\_defines is enabled, the partition table offset and size of the corresponding ID are passed to the subsequent build stages according to the specified macro definitions, and can be directly referenced in the code.

### Menuconfig Configuration<a name="ZH-CN_TOPIC_0000002050854461"></a>

Running the "python3 build.py -c standard-bs21-n1100 menuconfig" script starts the Menuconfig program, through which users can configure compilation and system functions, as shown in [Figure 1](#fig155343385597).

The SDK integrates default configurations, but users are advised to make appropriate configurations on the first run to reduce problems caused by configuration. Users can run "python3 build.py -c standard-bs21-n1100 menuconfig" at any time to change the configuration.

**Figure 1**  Menuconfig Running Interface<a name="fig155343385597"></a>  
![](figures/Menuconfig运行界面.png "Menuconfig Running Interface")

Note: If the interface differs, the actual version prevails.

The Menuconfig operation instructions are shown in [Table 1](#table364152210248). Shortcut keys can be entered in the Menuconfig interface for configuration.

**Table 1**  Menuconfig Common Operation Commands

<a name="table364152210248"></a>
<table><thead align="left"><tr id="row2642122213247"><th class="cellrowborder" valign="top" width="17%" id="mcps1.2.3.1.1"><p id="p10343125916259"><a name="p10343125916259"></a><a name="p10343125916259"></a>Shortcut Key</p>
</th>
<th class="cellrowborder" valign="top" width="83%" id="mcps1.2.3.1.2"><p id="p0642102212419"><a name="p0642102212419"></a><a name="p0642102212419"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row146421622162417"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.2.3.1.1 "><p id="p66421322192415"><a name="p66421322192415"></a><a name="p66421322192415"></a>Space, Enter</p>
</td>
<td class="cellrowborder" valign="top" width="83%" headers="mcps1.2.3.1.2 "><p id="p464282282416"><a name="p464282282416"></a><a name="p464282282416"></a>Selects or deselects.</p>
</td>
</tr>
<tr id="row0235155732813"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.2.3.1.1 "><p id="p123512571284"><a name="p123512571284"></a><a name="p123512571284"></a>ESC</p>
</td>
<td class="cellrowborder" valign="top" width="83%" headers="mcps1.2.3.1.2 "><p id="p4235125718282"><a name="p4235125718282"></a><a name="p4235125718282"></a>Returns to the previous menu or exits the interface.</p>
</td>
</tr>
<tr id="row1425985152914"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.2.3.1.1 "><p id="p02597515295"><a name="p02597515295"></a><a name="p02597515295"></a>Q</p>
</td>
<td class="cellrowborder" valign="top" width="83%" headers="mcps1.2.3.1.2 "><p id="p1825945119290"><a name="p1825945119290"></a><a name="p1825945119290"></a>Exits the interface.</p>
</td>
</tr>
<tr id="row161871942143019"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.2.3.1.1 "><p id="p718744220300"><a name="p718744220300"></a><a name="p718744220300"></a>S</p>
</td>
<td class="cellrowborder" valign="top" width="83%" headers="mcps1.2.3.1.2 "><p id="p1818734211305"><a name="p1818734211305"></a><a name="p1818734211305"></a>Saves the configuration.</p>
</td>
</tr>
<tr id="row1661115053113"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.2.3.1.1 "><p id="p1861165015311"><a name="p1861165015311"></a><a name="p1861165015311"></a>F</p>
</td>
<td class="cellrowborder" valign="top" width="83%" headers="mcps1.2.3.1.2 "><p id="p17611125012312"><a name="p17611125012312"></a><a name="p17611125012312"></a>Displays the help menu.</p>
</td>
</tr>
</tbody>
</table>

All commands can be viewed in the Menuconfig official help at the bottom of the Menuconfig interface, as shown in [Figure 2](#fig14504171214012).

**Figure 2**  Menuconfig Command Help Bar<a name="fig14504171214012"></a>  
![](figures/Menuconfig命令帮助栏.png "Menuconfig Command Help Bar")

**Table 2**  Menuconfig Menu Item Description

<a name="table111109185019"></a>
<table><thead align="left"><tr id="row31102115020"><th class="cellrowborder" valign="top" width="28.48%" id="mcps1.2.3.1.1"><p id="p1511071155010"><a name="p1511071155010"></a><a name="p1511071155010"></a>Menu</p>
</th>
<th class="cellrowborder" valign="top" width="71.52%" id="mcps1.2.3.1.2"><p id="p1511016155013"><a name="p1511016155013"></a><a name="p1511016155013"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row171109113504"><td class="cellrowborder" valign="top" width="28.48%" headers="mcps1.2.3.1.1 "><p id="p21103135016"><a name="p21103135016"></a><a name="p21103135016"></a>Targets</p>
</td>
<td class="cellrowborder" valign="top" width="71.52%" headers="mcps1.2.3.1.2 "><p id="p171101818501"><a name="p171101818501"></a><a name="p171101818501"></a>Compilation target-related configuration.</p>
</td>
</tr>
<tr id="row211021195018"><td class="cellrowborder" valign="top" width="28.48%" headers="mcps1.2.3.1.1 "><p id="p1311017165013"><a name="p1311017165013"></a><a name="p1311017165013"></a>Application</p>
</td>
<td class="cellrowborder" valign="top" width="71.52%" headers="mcps1.2.3.1.2 "><p id="p31103195010"><a name="p31103195010"></a><a name="p31103195010"></a>Application-related configuration (mainly sample-related).</p>
</td>
</tr>
<tr id="row161103165010"><td class="cellrowborder" valign="top" width="28.48%" headers="mcps1.2.3.1.1 "><p id="p01104117505"><a name="p01104117505"></a><a name="p01104117505"></a>Bootloader</p>
</td>
<td class="cellrowborder" valign="top" width="71.52%" headers="mcps1.2.3.1.2 "><p id="p121105116505"><a name="p121105116505"></a><a name="p121105116505"></a>boot-related configuration.</p>
</td>
</tr>
<tr id="row1211071175013"><td class="cellrowborder" valign="top" width="28.48%" headers="mcps1.2.3.1.1 "><p id="p8110141155011"><a name="p8110141155011"></a><a name="p8110141155011"></a>Drivers</p>
</td>
<td class="cellrowborder" valign="top" width="71.52%" headers="mcps1.2.3.1.2 "><p id="p11692144810534"><a name="p11692144810534"></a><a name="p11692144810534"></a>Peripheral driver-related configuration and board-level configuration.</p>
</td>
</tr>
<tr id="row1511031125010"><td class="cellrowborder" valign="top" width="28.48%" headers="mcps1.2.3.1.1 "><p id="p141101111500"><a name="p141101111500"></a><a name="p141101111500"></a>Kernel</p>
</td>
<td class="cellrowborder" valign="top" width="71.52%" headers="mcps1.2.3.1.2 "><p id="p15798145395311"><a name="p15798145395311"></a><a name="p15798145395311"></a>Kernel-related configuration.</p>
</td>
</tr>
<tr id="row161106115504"><td class="cellrowborder" valign="top" width="28.48%" headers="mcps1.2.3.1.1 "><p id="p91105115502"><a name="p91105115502"></a><a name="p91105115502"></a>Middleware</p>
</td>
<td class="cellrowborder" valign="top" width="71.52%" headers="mcps1.2.3.1.2 "><p id="p199165471300"><a name="p199165471300"></a><a name="p199165471300"></a>Middleware-related configuration (NV, FOTA, AT, DFX, PM, etc.).</p>
</td>
</tr>
<tr id="row94651621525"><td class="cellrowborder" valign="top" width="28.48%" headers="mcps1.2.3.1.1 "><p id="p8671200105210"><a name="p8671200105210"></a><a name="p8671200105210"></a>Protocol</p>
</td>
<td class="cellrowborder" valign="top" width="71.52%" headers="mcps1.2.3.1.2 "><p id="p8251182085411"><a name="p8251182085411"></a><a name="p8251182085411"></a>SparkLink and Bluetooth-related configuration.</p>
</td>
</tr>
<tr id="row1453145185216"><td class="cellrowborder" valign="top" width="28.48%" headers="mcps1.2.3.1.1 "><p id="p1760612418522"><a name="p1760612418522"></a><a name="p1760612418522"></a>Test</p>
</td>
<td class="cellrowborder" valign="top" width="71.52%" headers="mcps1.2.3.1.2 "><p id="p1960613475215"><a name="p1960613475215"></a><a name="p1960613475215"></a>Test suite-related configuration.</p>
</td>
</tr>
</tbody>
</table>

### Precautions<a name="ZH-CN_TOPIC_0000002050854465"></a>

-   If "./build.py" reports a permission error, run "chmod +x build.py" to add the execution permission, or run "python3./build.py".
-   If a package is reported missing during compilation, check whether the corresponding component has been installed for the python in the environment. If the build environment contains multiple python versions, especially multiple python versions of the same version, and the user cannot identify which one is being used, it is recommended to install Python component packages from the component package source code in this case.
-   The system gives priority to the configuration made by the user through Menuconfig. If the user has not configured it, the system will compile with the default configuration.

# Creating a New APP<a name="ZH-CN_TOPIC_0000002050895349"></a>




## Creating a Source Directory<a name="ZH-CN_TOPIC_0000002050854457"></a>

>![](public_sys-resources/icon-note.gif) **Note:** 
>Users can create an app in the directory at the same level as "application/bs21" by referring to the "standard-bs21-n1100" directory. The following uses "my\_demo" as an example.

The steps are as follows:

1.  Create the "application/bs21/my\_demo" directory to store the source files of "my\_demo".
2.  Copy "application/bs21/standard/CMakeLists.txt" to "application/bs21/my\_demo/CmakeLists.txt", and place the source files in the "application/bs21/my\_demo" directory.
3.  Modify the "application/bs21/my\_demo/CmakeLists.txt" file. The meanings of the variables are shown in [Table 1](#table89969106362).

    **Table 1**  Meanings of Variables in the Component's CmakeLists.txt

    <a name="table89969106362"></a>
    <table><thead align="left"><tr id="row69971710143612"><th class="cellrowborder" valign="top" width="27.900000000000002%" id="mcps1.2.3.1.1"><p id="p8997181043611"><a name="p8997181043611"></a><a name="p8997181043611"></a>Variable Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="72.1%" id="mcps1.2.3.1.2"><p id="p1799771019361"><a name="p1799771019361"></a><a name="p1799771019361"></a>Variable Meaning</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row77088920486"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.2.3.1.1 "><p id="p167083915484"><a name="p167083915484"></a><a name="p167083915484"></a>COMPONENT_NAME</p>
    </td>
    <td class="cellrowborder" valign="top" width="72.1%" headers="mcps1.2.3.1.2 "><p id="p570849194814"><a name="p570849194814"></a><a name="p570849194814"></a>Name of the current component, for example "my_demo".</p>
    </td>
    </tr>
    <tr id="row99971710133619"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.2.3.1.1 "><p id="p199976101361"><a name="p199976101361"></a><a name="p199976101361"></a>SOURCES</p>
    </td>
    <td class="cellrowborder" valign="top" width="72.1%" headers="mcps1.2.3.1.2 "><p id="p499751023618"><a name="p499751023618"></a><a name="p499751023618"></a>List of C files of the current component. The CMAKE_CURRENT_SOURCE_DIR variable identifies the path where the current CMakeLists.txt is located.</p>
    </td>
    </tr>
    <tr id="row5997910163618"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.2.3.1.1 "><p id="p129971210143615"><a name="p129971210143615"></a><a name="p129971210143615"></a>PUBLIC_HEADER</p>
    </td>
    <td class="cellrowborder" valign="top" width="72.1%" headers="mcps1.2.3.1.2 "><p id="p69971109360"><a name="p69971109360"></a><a name="p69971109360"></a>Paths of the header files that the current component needs to expose externally.</p>
    </td>
    </tr>
    <tr id="row1199791011363"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.2.3.1.1 "><p id="p1699711105364"><a name="p1699711105364"></a><a name="p1699711105364"></a>PRIVATE_HEADER</p>
    </td>
    <td class="cellrowborder" valign="top" width="72.1%" headers="mcps1.2.3.1.2 "><p id="p1799771033615"><a name="p1799771033615"></a><a name="p1799771033615"></a>Header file search paths internal to the current component.</p>
    </td>
    </tr>
    <tr id="row99971610193616"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.2.3.1.1 "><p id="p169971610133618"><a name="p169971610133618"></a><a name="p169971610133618"></a>PRIVATE_DEFINES</p>
    </td>
    <td class="cellrowborder" valign="top" width="72.1%" headers="mcps1.2.3.1.2 "><p id="p14997610103613"><a name="p14997610103613"></a><a name="p14997610103613"></a>Macro definitions effective within the current component.</p>
    </td>
    </tr>
    <tr id="row12997210203618"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.2.3.1.1 "><p id="p59971910163611"><a name="p59971910163611"></a><a name="p59971910163611"></a>PUBLIC_DEFINES</p>
    </td>
    <td class="cellrowborder" valign="top" width="72.1%" headers="mcps1.2.3.1.2 "><p id="p02671050184018"><a name="p02671050184018"></a><a name="p02671050184018"></a>Macro definitions that the current component needs to expose externally.</p>
    </td>
    </tr>
    <tr id="row12716914103914"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.2.3.1.1 "><p id="p5717214153911"><a name="p5717214153911"></a><a name="p5717214153911"></a>COMPONENT_PUBLIC_CCFLAGS</p>
    </td>
    <td class="cellrowborder" valign="top" width="72.1%" headers="mcps1.2.3.1.2 "><p id="p14717111473912"><a name="p14717111473912"></a><a name="p14717111473912"></a>Compilation options that the current component needs to expose externally.</p>
    </td>
    </tr>
    <tr id="row22992182396"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.2.3.1.1 "><p id="p152993185398"><a name="p152993185398"></a><a name="p152993185398"></a>COMPONENT_CCFLAGS</p>
    </td>
    <td class="cellrowborder" valign="top" width="72.1%" headers="mcps1.2.3.1.2 "><p id="p132991118123913"><a name="p132991118123913"></a><a name="p132991118123913"></a>Compilation options effective within the current component.</p>
    </td>
    </tr>
    </tbody>
    </table>

4.  Modify "application/bs21/CMakeLists.txt" to add the my\_demo directory to compilation.
5.  Modify "build/config/target\_config/bs21/config.py" and add 'my\_demo' to the ram\_component field to register the my\_demo component in the compilation system.

## Developing Code<a name="ZH-CN_TOPIC_0000002014774848"></a>

After the directory structure is created, start developing the code (users can refer to "application/samples" for porting). After the code development is complete, use "python3 build.py -c standard-bs21-n1100" to compile my\_demo for code compilation and debugging.

## Image Flashing<a name="ZH-CN_TOPIC_0000002014616604"></a>

For the image flashing method, refer to the "Operation Guide" section in the "BS2X V100 BurnTool Tool Usage Guide".

