# Setting Up the WSL Subsystem Development Environment

## System Requirements

| System Requirements                                           | Download Link                                                |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| Windows 10 version 2004 and higher (build 19041 and higher) or Windows 11 |                                                              |
| For x64 systems: Linux kernel update package                 | [wsl_update_x64.msi](https://wslstorestorage.blob.core.windows.net/wslblob/wsl_update_x64.msi) |

## Downloading and Importing the WSL Subsystem

- To enable the Windows Subsystem for Linux, you first need to enable the "Windows Subsystem for Linux" optional feature before you can install Linux distributions on Windows.

  Open PowerShell as **Administrator** (Start menu > "PowerShell" > right-click > "Run as administrator"), then enter the following command:

  ```
  dism.exe /online /enable-feature /featurename:Microsoft-Windows-Subsystem-Linux /all /norestart
  ```

  ![image-20250310184537535](../vendor/HH-D03/doc/media/tools/image-20250310184537535.png)

- Requires Windows 10 version 2004 and later (build 19041 and later) or Windows 11. To check your Windows version and build number, select the Windows logo key + R, then type "winver", and select "OK".

  ![image-20250310185106744](../vendor/HH-D03/doc/media/tools/image-20250310185106744.png)

- Enable the virtual machine feature. Before installing WSL 2, you must enable the "Virtual Machine Platform" optional feature. The computer needs [virtualization functionality](https://learn.microsoft.com/en-us/windows/wsl/troubleshooting#error-0x80370102-the-virtual-machine-could-not-be-started-because-a-required-feature-is-not-installed) to use this feature.

  Open PowerShell as **Administrator** and run:

  ```
  dism.exe /online /enable-feature /featurename:VirtualMachinePlatform /all /norestart
  ```

  ![image-20250310190106392](../vendor/HH-D03/doc/media/tools/image-20250310190106392.png)

- Need to install the Linux kernel update package to run WSL in the Windows operating system image.

  | System Architecture | Download Link                                               |
  | ------------------ | ----------------------------------------------------------- |
  | x64                | [wsl_update_x64.msi](https://wslstorestorage.blob.core.windows.net/wslblob/wsl_update_x64.msi) |

- Restart the computer. Be sure to restart, otherwise errors will occur later.

- Download the fbb_ws63_wsl release package. Download link: https://hispark-obs.obs.cn-east-3.myhuaweicloud.com/fbb_ws63_wsl.tar

  ![image-20250311161220485](../vendor/HH-D03/doc/media/tools/image-20250311161220485.png)

- After downloading, place the compressed package on the desktop or another directory. Here, the desktop is used as an example (path: C:/Users/Administrator/Desktop/fbb_ws63_wsl.tar). At the same time, create a new folder in a non-system drive directory. Here, a new folder named `ubuntu` is created on the F drive (path: F:/ubuntu/).

  Open PowerShell **as an administrator** and run:

  ```
  wsl --import fbb_ws63 F:/ubuntu/ C:/Users/Administrator/Desktop/fbb_ws63_wsl.tar
  ```

- After running, wait for the import to complete. Once successful, the following files will appear in the F:/ubuntu/ directory.

  ![image-20250310191219674](../vendor/HH-D03/doc/media/tools/image-20250310191219674.png)

  ![image-20250310191203544](../vendor/HH-D03/doc/media/tools/image-20250310191203544.png)

- Restart the computer, you must restart, otherwise it will be very laggy later.

- After the restart, check whether the WSL subsystem is installed successfully.

  Open PowerShell and run:

  ```
  wsl --list
  ```

  ![image-20250310194511923](../vendor/HH-D03/doc/media/tools/image-20250310194511923.png)

- Install [vscode](https://vscode.download.prss.microsoft.com/dbazure/download/stable/6609ac3d66f4eade5cf376d1cb76f13985724bcb/VSCodeUserSetup-x64-1.98.0.exe). The installation steps are not described; just install it as you like. After successful installation, as shown in the figure below, download link: https://vscode.download.prss.microsoft.com/dbazure/download/stable/6609ac3d66f4eade5cf376d1cb76f13985724bcb/VSCodeUserSetup-x64-1.98.0.exe

  ![image-20250310194000292](../vendor/HH-D03/doc/media/tools/image-20250310194000292.png)

- Open Vscode, search for "remote" in the extensions, select "Remote Development", and wait for the download to complete.

  ![image-20250310194404035](../vendor/HH-D03/doc/media/tools/image-20250310194404035.png)

- If you need Chinese display, search for "chinese" in the extensions, select "Chinese (Simplified)", wait for the installation to complete, a "Change Language and Restart" prompt will appear in the bottom right corner, click confirm.

![image-20250310194930378](../vendor/HH-D03/doc/media/tools/image-20250310194930378.png)

![image-20250310195122151](../vendor/HH-D03/doc/media/tools/image-20250310195122151.png)

- In vscode, select "Remote Explorer", choose "fbb_ws63", and select "Connect in Current Window"

  ![image-20250310200852622](../vendor/HH-D03/doc/media/tools/image-20250310200852622.png)

- Create a new "Terminal" in the VSCode interface

  ![image-20250310203406547](../vendor/HH-D03/doc/media/tools/image-20250310203406547.png)

- At the bottom of the VScode interface, "Terminal": a terminal interface will pop up.
  
  ![image-20250311113220441](../vendor/HH-D03/doc/media/tools/image-20250311113220441.png)