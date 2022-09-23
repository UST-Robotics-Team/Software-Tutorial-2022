# STM32 CubeIDE Setup [![HackMD Version](https://img.shields.io/badge/Made%20with-HackMD-1f425f.svg)](https://hackmd.io/EKwF2Tc8TWK7X9p48fZfXw)

---

Author: Leo Wong
Contact: lywongav@connect.ust.hk

Updated by: Wesley Leung
Contact: kcleungax@connect.ust.hk

[TOC]

## Videos on how to setup CubeIDE:
https://drive.google.com/file/d/1wEaBY-1XpNLysGSlkdC9qUE2OFOknX-9/view?usp=sharing

## Download & Install

First thing first, please download the STM32CubeIDE from Github [release](https://github.com/UST-Robotics-Team/Software-Tutorial-2022/releases/tag/Installer)

## Setup (Windows) (Mac user please refer to bottom part)

> ![](https://i.imgur.com/s3DFKCY.png)
> 
> You can choose which every directory you like to place the project files. Just make sure you can find it after.

> ![](https://i.imgur.com/huv0HIY.png)
> 
> J-Link drivers is not needed in this case
> But definitely check the ST-link drivers cuz we need then to flash(upload) the program to the mainboard.

After you have installed the IDE, please follow the steps below to properly setup your **Integrated Development Environment**

Download the code boilerplate we prepared for you from Github [release](https://github.com/HKUST-Robotics-Team/HKUST-Robotics-Team-SW-Tutorial-2021/releases/tag/code_v2.0).
_Note that we may have some library changes from time to time. So always follow what the tutorial notes say._

### Import the project files

> ![](https://i.imgur.com/eEuOorp.jpg)
>
> 1. Click Import in File tab

> ![](https://i.imgur.com/cTfTDIK.jpg)
> 
> 2. Extract the code boilerplate you have downloaded and select that as root directory. Click finish afterwards.

> ![](https://i.imgur.com/fjDdL1M.jpg)
> 3. Tada! You have successfully imported the code boilerplate.

---

### Configure ST-Linkv2 (Windows)

> ![](https://i.imgur.com/TNJrgms.png)
>
> 1. Switch build option from Debug to Release

> ![](https://i.imgur.com/8XwVtFQ.png)
>
> 2. Click the arrow besides _Run_ and click _Run Configurations..._

> ![](https://i.imgur.com/AtQTnB6.png)
> 
> 3.1 Choose STM32 Application the left and select _Debugger_ Tab.
> 
> 3.2 Change Debug probe to `ST-LINK (OpenOCD)`. :heavy_exclamation_mark: If you are running on OSX, change the line OpenOCD Command to `"${stm32cubeide_openocd_path}/openocd"`
> 
> 3.3 Click `Show generator options...` under `Configuration Scripts` to reveal more options.
> 
> 3.4 In `Mode Setup`, select `Software system reset` in `Reset Mode`.

> ![](https://i.imgur.com/Wa5m30S.png)
> 
> 4. If you see this, you are probably doing right although not exactly...

## Setup (Mac)

> ![](https://i.imgur.com/7IjBmYe.png)
> 
> Click Agree in the bottom right
> 
> ![](https://i.imgur.com/eTFKAw1.png)
> Double click the box icon on the top left.
> 
> ![](https://i.imgur.com/2a6pI0n.png)
> If you see this, this mean Apple cares about you unlike Windows
> 
> ![](https://i.imgur.com/cW9vxLR.png)
> Go to System Preferences>Security&Privacy, search near the bottom right region, click "Open Anyway" for "st-stlink-server.2.1.0-1.pkg"
> 
> ![](https://i.imgur.com/JZg4w0E.png)
> Click "Open"

You will now proceed to install st-stlink-server.2.1.0-1.pkg

> ![](https://i.imgur.com/eJkFhn6.png)
> Click, continue/ install to complete the installation process

After you have done installing the st-stlink-server.2.1.0-1.pkg, install STM32CubeIDE by dragging the Application icon to the Application folder

> ![](https://i.imgur.com/Za7b8Bk.png)
> ![](https://i.imgur.com/f4IjzMD.png)
> Same thing, Apple cares about you
> 
> ![](https://i.imgur.com/CXkEcpq.png)
> Go to System Preferences>Security&Privacy, search near the bottom right region, click "Open Anyway" for "STM32CubelDE"
>
> ![](https://i.imgur.com/Lb9cFD5.png)
> Press "Open"

After you have installed the IDE, please follow the steps below to properly setup your **Integrated Development Environment**

Download the code boilerplate we prepared for you from Github [release](https://github.com/HKUST-Robotics-Team/HKUST-Robotics-Team-SW-Tutorial-2021/releases/tag/code_v2.0).
_Note that we may have some library changes from time to time. So always follow what the tutorial notes say._

### Import the project files
>
> ![](https://i.imgur.com/238rqEI.png)
> You can choose which every directory you like to place the project files. Just make sure you can find it after.
>
> ![](https://i.imgur.com/JMpsbJJ.png)
> If the application ask for permission to accept
incoming network connections, click "Allow"
> ![](https://i.imgur.com/C2rmwU9.jpg)
>
> 1. Click Import in File tab
> 
> ![](https://i.imgur.com/2znwChr.png)
>
> Under General choose "Existing Projects into Workspace"
>
> ![](https://i.imgur.com/Vrg630D.png)
> ![](https://i.imgur.com/EwspMdM.png)
> 2. Extract the entire code boilerplate file (unzipped) you have downloaded and select that as root directory. Click finish afterwards.
> ![](https://i.imgur.com/XUTurja.jpg)
> 3. Tada! You have successfully imported the code boilerplate.

---

### Configure ST-Linkv2 (Mac)

> ![](https://i.imgur.com/Ss2oFzC.jpg)
> On the top left click the red cross to close the Information Center page
>
> ![](https://i.imgur.com/FxREOI3.png)
> You should now see this
>
> ![](https://i.imgur.com/BEYLbee.png)
>    1. Switch build option from Debug to Release
> 
> ![](https://i.imgur.com/wCJXaKf.png)
>
> 2. Click the arrow besides _Run_ and click _Run Configurations..._
> >
> ![](https://i.imgur.com/QgjX5CL.png)
> 
> 3.1 Choose STM32 Application the left and select _Debugger_ Tab.
> 
> ![](https://i.imgur.com/Xk8Z7zA.png)
> 3.2 Change Debug probe to `ST-LINK (OpenOCD)`. :heavy_exclamation_mark: change the line OpenOCD Command to `"${stm32cubeide_openocd_path}/openocd"` note '\' is changed to'/' and ".exe" is deleted.
>
>![](https://i.imgur.com/kZNp90b.png)
>  3.3 Click `Show generator options...` under `Configuration Scripts` to reveal more options.
> 
> ![](https://i.imgur.com/jIGDNqo.png)
> 3.4 In `Mode Setup`, select `Software system reset` in `Reset Mode`.

> ![](https://i.imgur.com/Wa5m30S.png)
> 
> 4. If you see this, you are probably doing right although not exactly...
>
> ![](https://i.imgur.com/S6SgtOg.png)
> If you see this and the board the led(s) in board is flashing as expected, congrats!

## Troubleshooting
> ![](https://i.imgur.com/RFDg47S.png)
>
> If somehow it says *Program file does not exist*, you can click Search Project and select the correct .elf file. In our case, `Release/SW Tutorial 2021.elf`.
### More configuration on the IDE

Since STMCubeIDE is based on Eclipse, you can configure the theme, keybindings, formatter and more.

> ![](https://i.imgur.com/jeWyQcS.png)
> What I have configured:
>
> - Dark theme
> - Clang-formatter
> - Auto-complete
> - VSCode keybindings

### Explore the IDE if you have time!
