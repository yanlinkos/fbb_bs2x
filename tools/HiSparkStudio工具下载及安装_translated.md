# Building HiSpark Studio Development Environment

**Note: Only supported for LiteOS system versions; OpenHarmony system versions do not support Windows environment setup.**

## System Requirements:

| Tool Version                                    | Download Link                                                |
| ----------------------------------------------- | ------------------------------------------------------------ |
| Supported OS: Windows10, Windows11              |                                                              |
| Python: 3.11.4                                  | [python download link](https://www.python.org/ftp/python/3.11.4/python-3.11.4-amd64.exe) |
| cmake-3.20.5-py2.py3-none-win_amd64.whl         | [cmake download link](https://files.pythonhosted.org/packages/65/7f/80cf681cd376834b442af8af48e6f17b4197d20b7255aa2f76d8d93a9e44/cmake-3.20.5-py2.py3-none-win_amd64.whl) |
| kconfiglib-14.1.0-py2.py3-none-any.whl          | [kconfiglib download link](https://files.pythonhosted.org/packages/8a/f1/d98a89231e779b079b977590efcc31249d959c8f1d4b5858cad69695ff9c/kconfiglib-14.1.0-py2.py3-none-any.whl) |
| pycparser-2.21-py2.py3-none-any.whl             | [pycparser download link](https://files.pythonhosted.org/packages/62/d5/5f610ebe421e85889f2e55e33b7f9a6795bd982198517d912eb1c76e1a53/pycparser-2.21-py2.py3-none-any.whl) |
| windows_curses-2.3.3-cp311-cp311-win_amd64.whl  | [windows_curses download link](https://files.pythonhosted.org/packages/18/1b/e06eb41dad1c74f0d3124218084f258f73a5e76c67112da0ba174162670f/windows_curses-2.3.3-cp311-cp311-win_amd64.whl) |

## HiSpark Studio Download

- Log in to the Shanghai HiSilicon developer website to obtain the IDE tool. You need to register an account to download. Download the latest version. The image below is for reference only.

  ![image.png](../vendor/HH-D03/doc/media/tools/1.png)

- If you cannot log in to the developer website to download, you can access this link to download (it is recommended to download from the HiSilicon developer website): [https://hispark-obs.obs.cn-east-3.myhuaweicloud.com/HiSparkStudio.exe](https://gitee.com/link?target=https%3A%2F%2Fhispark-obs.obs.cn-east-3.myhuaweicloud.com%2FHiSparkStudio.exe)

## HiSpark Studio Installation

- After downloading, double-click "HiSparkStudio1.0.0.11.exe" to install. Download the latest version; the image below is for reference only.

  ![image.png](../vendor/HH-D03/doc/media/tools/2.png)

- The installation interface is as follows: select "I agree to the agreement", then click "Next".

  ![image.png](../vendor/HH-D03/doc/media/tools/3.png)

- Select the corresponding disk for installation based on the user's own disk space, and after making the selection, click Next. (**Note: If your username contains Chinese characters, please install it to another directory such as drive D or E.** **Here, drive D is used as an example.**)

  ![image.png](../vendor/HH-D03/doc/media/tools/4.png)

- Check additional tasks according to the user's own needs. All are checked by default. After making the selection, click Next.

  ![image.png](../vendor/HH-D03/doc/media/tools/5.png)

- Click "Install" to install the tool.

  ![image-20250306181441344](../vendor/HH-D03/doc/media/tools/6.png)

- The installation process is as follows, wait for the installation to complete.

  ![image.png](../vendor/HH-D03/doc/media/tools/7.png)

- If a "python 3.11.4" prompt automatically appears during installation, click "Cancel".

  ![image-20250306181829205](../vendor/HH-D03/doc/media/tools/10.png)

- The following interface indicates that the installation is complete. Click Finish to proceed.

  ![image.png](../vendor/HH-D03/doc/media/tools/8.png)

- The main page interface of HiSpark studio is shown below.

  ![image.png](../vendor/HH-D03/doc/media/tools/9.png)

## Adding Environment Variables

- After the tool is installed, add environment variables in the system environment variables of your computer (here, Windows 10 is used as an example; for Windows 11, you can search Baidu for how to add environment variables). Right-click on "This PC" and click "Properties".

  ![image-20250307143252345](../vendor/HH-D03/doc/media/tools/image-20250307143252345.png)

- Pop up the System Properties dialog, click "Environment Variables"

  ![image-20250307143539205](../vendor/HH-D03/doc/media/tools/image-20250307143539205.png)

- In the system environment variables, select "Path" and double-click to enter.

  ![image-20250307143625753](../vendor/HH-D03/doc/media/tools/image-20250307143625753.png)

- Add "xxx\HiSpark Studio\tools\Windows\ninja", "xxx\HiSpark Studio\tools\Windows\gn", and "xxx\HiSpark Studio\tools\Windows\cc_riscv32_musl_fp_win\bin" to the environment variables (xxx represents the HiSpark Studio installation directory). After adding, click "OK".

  ![image-20250307142741299](../vendor/HH-D03/doc/media/tools/image-20250307142741299.png)

  ![image-20250307145245437](../vendor/HH-D03/doc/media/tools/image-20250307145245437.png)

  ![image-20250307145204942](../vendor/HH-D03/doc/media/tools/image-20250307145204942.png)

  ![image-20250307144012214](../vendor/HH-D03/doc/media/tools/image-20250307144012214.png)

- After the environment variable installation is complete, test whether it has been successfully added. In the "command line window", enter "ninja --version", "gn --version", and "riscv32-linux-musl-gcc -v" respectively. If the version numbers appear as shown in the figure below, it indicates success.

  ![image-20250307150120146](../vendor/HH-D03/doc/media/tools/image-20250307150120146.png)

  ## Python Download and Installation

- After successfully configuring the environment variables, download Python (version: 3.11.4), [Python download link: https://www.python.org/ftp/python/3.11.4/python-3.11.4-amd64.exe](https://www.python.org/ftp/python/3.11.4/python-3.11.4-amd64.exe)

  ![image-20250307095229583](../vendor/HH-D03/doc/media/tools/11.png)

- After the download is complete, click Install, check "ADD python.exe to PATH" on the installation interface, and select "Customize installation".

  ![image-20250307095303931](../vendor/HH-D03/doc/media/tools/12.png)

- Click "next" to proceed.

  ![image-20250307095731813](../vendor/HH-D03/doc/media/tools/13.png)

- Modify the installation path. If your computer username does not contain Chinese characters, you can use the default installation. If your computer username contains Chinese characters, please install it on another disk (here, take the D drive as an example). After selecting the path, click "install" (**Note: The installation directory should not contain Chinese characters**).

  ![image-20250307095922285](../vendor/HH-D03/doc/media/tools/14.png)

- Wait for the installation to complete.

  ![image-20250307100139436](../vendor/HH-D03/doc/media/tools/15.png)

- After installation is complete, click "Close".

  ![image-20250307100526042](../vendor/HH-D03/doc/media/tools/16.png)

- Open the "Command Prompt", type "python", and if it displays 3.11.4, it is successful.

  ![image-20250306181922046](../vendor/HH-D03/doc/media/tools/17.png)

## Compilation Plugin Installation

- Download [kconfiglib download link](https://files.pythonhosted.org/packages/8a/f1/d98a89231e779b079b977590efcc31249d959c8f1d4b5858cad69695ff9c/kconfiglib-14.1.0-py2.py3-none-any.whl)

- Download plugin [cmake download link](https://files.pythonhosted.org/packages/65/7f/80cf681cd376834b442af8af48e6f17b4197d20b7255aa2f76d8d93a9e44/cmake-3.20.5-py2.py3-none-win_amd64.whl)

- Download plugin [pycparser download link](https://files.pythonhosted.org/packages/62/d5/5f610ebe421e85889f2e55e33b7f9a6795bd982198517d912eb1c76e1a53/pycparser-2.21-py2.py3-none-any.whl)

- Download plugin [windows_curses download link](https://files.pythonhosted.org/packages/18/1b/e06eb41dad1c74f0d3124218084f258f73a5e76c67112da0ba174162670f/windows_curses-2.3.3-cp311-cp311-win_amd64.whl)

- Store the kconfiglib, cmake, pycparser, windows_curses, and other files in the same directory (**any directory is fine**), then type "cmd" in the directory folder address bar.

  ![image.png](../vendor/HH-D03/doc/media/tools/18.png)
  
- Enter `pip install windows_curses-2.3.3-cp311-cp311-win_amd64.whl` in the "command line window".

  ![image-20250307163505547](../vendor/HH-D03/doc/media/tools/image-20250307163505547.png)

- Enter `pip install cmake-3.20.5-py2.py3-none-win_amd64.whl` in the "Command Prompt window".

  ![image-20250307163428170](../vendor/HH-D03/doc/media/tools/image-20250307163428170.png)
  
- Enter `pip install kconfiglib-14.1.0-py2.py3-none-any.whl` in the command line window

  ![image-20250307163648419](../vendor/HH-D03/doc/media/tools/image-20250307163648419.png)
  
- In the "command line window", enter pip install pycparser-2.21-py2.py3-none-any.whl

  ![image-20250307163706951](../vendor/HH-D03/doc/media/tools/image-20250307163706951.png)