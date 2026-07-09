# HiSpark Studio Development Environment Setup

**Note: Only supported for LiteOS system version, OpenHarmony system version does not support Windows environment setup**

## Install HiSpark Studio Plugin Version

1. Download and install [vscode](https://code.visualstudio.com/Download), follow the recommendations step by step.

![](../vendor/HH-D03/doc/media/readme/image-20250716160500019.png)

2. Search for "HiSpark Studio" in the Vscode extensions, then click to install.

![image-20250716161307500](../vendor/HH-D03/doc/media/readme/image-20250716161307500.png)

3. After installation, the "HiSpark Studio" icon appears in the sidebar.

![image-20250716162432995](../vendor/HH-D03/doc/media/readme/image-20250716162432995.png)

4. Click "Download Toolchain" to install the tools and plugins. A Python installation dialog box will pop up; click "Install".

![image-20250716162652139](../vendor/HH-D03/doc/media/readme/image-20250716162652139.png)

5. When the text "Environment preparation complete" appears, it indicates that the environment installation is finished.

![image-20250716162816180](../vendor/HH-D03/doc/media/readme/image-20250716162816180.png)

6. Download the corresponding SDK package as needed and select the desired directory for download. Here, take "fbb_bs2x SDK, with the download save path as drive G" as an example.

![image-20250911153633257](../vendor/HH-D03/doc/media/readme/image-20250911153633257.png)

7. Click "New Project", fill in the corresponding information as prompted, and click "Finish". Refer to the image below.

![image-20250911153812800](../vendor/HH-D03/doc/media/readme/image-20250911153812800.png)

8. After successful creation, click "build" to compile.

![image-20250716163653427](../vendor/HH-D03/doc/media/readme/image-20250716163653427.png)

9. The compilation is completed as shown in the figure below.

![image-20250307164622717](../vendor/HH-D03/doc/media/readme/image-20250307164622717.png)

## Image Flashing

1. Hardware Setup: Connect the board to the PC using a Type-C cable.

![image-20250911154349522](../vendor/HH-D03/doc/media/readme/image-20250911154349522.png)

2. Install the driver "CH341SER Driver" ([CH341SER Driver Download Link](https://www.wch.cn/downloads/CH341SER_EXE.html), **If the link is invalid or cannot be downloaded, users can search and download it from Baidu**). Install the CH341SER driver. Before installation, the single-board computer needs to be connected to the PC. Click "Install" to proceed. A message showing **Driver installed successfully indicates success**. If **Driver pre-installed successfully appears, it means the installation failed**.

![image-20240801173439645](../vendor/HH-D03/doc/media/readme/image-20240801173439645-17575744742952.png)

![image-20240801173618611](../vendor/HH-D03/doc/media/readme/image-20240801173618611.png)

3. After successful installation, click the "Project Configuration" button in the HiSpark Studio tool, select "Program Loading", choose "serial" as the transfer method, select "comxxx" as the port, and check the com port in the device manager.

![image-20250716164922699](../vendor/HH-D03/doc/media/readme/image-20250716164922699.png)

4. After configuration is complete, click the tool's "Program Load" button to start burning. When the message "Connecting, please reset device..." appears, reset the development board and wait for the burning to finish.

![image-20250716170835615](../vendor/HH-D03/doc/media/readme/image-20250716170835615.png)

5. At the bottom of HiSpark Studio, select "Monitor", choose the port (**the development board needs to be connected to the computer via Type-C**). If no port is displayed, refresh it. Click "Start Monitor", reset the development board, and the appearance of the word "version" indicates a successful compilation and flashing.

![image-20250911154446376](../vendor/HH-D03/doc/media/readme/image-20250911154446376.png)