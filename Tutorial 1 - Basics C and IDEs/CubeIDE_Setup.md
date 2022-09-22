# STM32 CubeIDE Setup [![HackMD Version](https://img.shields.io/badge/Made%20with-HackMD-1f425f.svg)](https://hackmd.io/EKwF2Tc8TWK7X9p48fZfXw)

---

Author: Leo Wong
Contact: lywongav@connect.ust.hk

## Videos on how to setup CubeIDE:
https://drive.google.com/file/d/1wEaBY-1XpNLysGSlkdC9qUE2OFOknX-9/view?usp=sharing

## Download & Install

First thing first, please download the STM32CubeIDE from Github [release](https://github.com/UST-Robotics-Team/Software-Tutorial-2022/releases/tag/Installer)

> ![](https://i.imgur.com/s3DFKCY.png)
> 
> You can choose which every directory you like to place the project files. Just make sure you can find it after.

> ![](https://i.imgur.com/huv0HIY.png)
> 
> J-Link drivers is not needed in this case
> But definitely check the ST-link drivers cuz we need then to flash(upload) the program to the mainboard.

## Setup

After you have installed the IDE, please follow the steps below to properly setup your **Integrated Development Environment**

Download the code boilerplate we prepared for you from Github Releases.
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

### Configure ST-Linkv2

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
