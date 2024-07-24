![banner2.png](//image.lceda.cn/pullimage/K0EeVsrXQP3DfGwQLachQURisxiBrE7BQpEHVpgk.png)

# **1、项目总览**

| 特性     | 描述                           |
|:---:|:---:|
| 复刻难度 | ⭐️    |
| 成本     | ￥30-￥100                         |
| 主控     | ESP32C3                        |

> 这是一个简单又不缺实用的温湿度监测系统！这个系统基于ESP32-C3，还配备了一个2.13寸的墨水屏，可以实时显示环境的温湿度数据。这个项目旨在提供一种低功耗、实时更新的环境监测解决方案，特别适合家里或者办公室使用哦~

核心传感器食用的是盛思锐的SHT40传感器来采集温湿度数据，它具有高精度、低功耗和小尺寸的特点，非常适合用于各种环境监测应用。

Github上存放了本项目所有的资源。
项目Github地址：https://github.com/MeowKJ/SimpleEInkEnvMonitor

| 文件夹       | 作用                                   | 文件夹       | 作用                                       |
|--------------|----------------------------------------|--------------|--------------------------------------------|
| **1.Hardware** | 为空，请参考OSWHUB  | **4.Docs**     | 包含文档文件，如数据手册和开发者指南       |
| **2.Firmware** | 为空，请参考Release栏目 | **5.Design**   | 包含设计相关文件，如UI设计和图标等|
| **3.Software** | 包含项目源代码 | **6.Tools**    | 包含工具和实用程序的工具   |

> *水平有限，以下有任何问题请在评论区指出*

# **2、项目属性 & 开源协议**


该项目是首次公开，并且为原创项目，项目没有在其他比赛中获奖。

**GPL 3.0**  
https://www.gnu.org/licenses/gpl-3.0.html

# **3、硬件部分**

> 硬件设计基于ESP32-C3-MINI-1-N4模块，温湿度来自盛思锐的SHT40，墨水屏建议2.13寸正好配合板子。

## **硬件概述**

这几天刚赶完，功耗没测不好说，但肯定不高的，这板子不小，建议上块大容量锂电池告别续航焦虑，可以把3d模型屁股做厚一点，搞块大电池。  
优化建议：
- AD得加个NMOS做个开关，或者直接不要。
- 那个RTC芯片直接不要了
- 软件优化
- 搞点微弱能量供应，我觉得搞点室内光小太阳能板说不定可以，毕竟她生命的绝大多数时间都该去睡觉。

## **材料说明**

### Ⅰ. 墨水屏
这也是我第一次做墨水屏，不知道市场价格怎么样，好像听说挺贵的。现在用的这个墨水屏是在某鱼上面找到个3色的，捡了几个，4.7元一个，邮费比屏贵。  
还有那种电子标签成品的更便宜，可惜买了一个没拆好把屏弄碎了。  
总之，颜色无所谓，改代码就行，是24Pin的就好。  
![墨水屏](//image.lceda.cn/pullimage/1wwGr5C14zL0lejD0iQFHF30bSB36pGPB9v7Oga4.png)

### Ⅱ. 主控ESP32-MINI-1-N4
感觉不便宜，虽然不到十块钱，但不能说只要几块钱。  
焊接要注意一下，类似QFN那种铜在板子底部的封装，理论上焊接至少需要加热台或者是风枪。  
![ESP32-MINI-1-N4](//image.lceda.cn/pullimage/V0fX6jaJIQrDKFEZzghWvMBkaBz0CHfUC2gRZlho.png)

### Ⅲ. 墨水屏的24Pin排线接子
注意是上接。那个屏幕折过来以后，接触铜朝外。

## **重要电路**
### Ⅰ.墨水屏驱动
经典的墨水屏驱动电路，`BS`一般接地，需要修改`R2`和`L2`的值来面对不同型号的墨水屏。

![墨水屏驱动](//image.lceda.cn/oshwhub/564ac04054db490dbd7697d6992c9a96.png)

### 

### Ⅱ. 传感器
传感器的接线很简单，给它配了一颗电容。`SDA`和`SCL`使用`4.7KΩ`电阻上拉，满足IIC总线需求。

![传感器](//image.lceda.cn/oshwhub/1b06867451294cc39fd9de45465705f7.png)

### Ⅲ. 电源切换
非常经典的电源切换电路，P型MOS管`Q4`在没有5V电源时MOS导通，此时系统由`VBAT`也就是锂电池供电。`Q4`有5V电源的时候截止，此时系统由`+5V`也就是USB供电，此时会为电池充电。

![电源切换](//image.lceda.cn/oshwhub/8b57633bbd0744deb23051ebb93a0f56.png)

### Ⅳ. 锂电池充电和5V转3.3V
锂电池充电采用`TP4054`，TP4056的可爱版，`R15`用来配置充电电流为`500mA`。
5V转3.3V需要注意，需要使用`低压差LDO`，常规LDO如AMS1117可能无法在接入锂电池（压差<1V）的情况下工作。ME6211的数据手册强调，它可以在压差为100mV的情况下同时提供100mA的最大输出电流$(100mV@Iout=100mA)$。ME6231数据手册上指出，它可以不要`C27`和`C29`这两颗100nF旁路电容，同时兼容陶瓷电容。我这里加上了有两个用意：1.兼容其他型号的LDO。2。我忘了可以不加。
这里推荐可以换成DC-DC，也能增加效率，当然成本可能会略微高一点。

![锂电池充电和5V转3.3V](//image.lceda.cn/oshwhub/4f5d1273e0d54098b2397f113762d5ee.png)



### Ⅴ. 其他一些说明
- USB上面的`5.1KΩ`电阻用来适配PD使其输出5V
- `IO9`也就是`BOOT`引脚上拉的那颗电阻可以不要，内部弱上拉
- 模组那里供电最好还是加几个电容，虽然模组内部是有的。但是参考设计上加了。

### Ⅵ. 一些疑问
- 关于ESP32的IO8，虽然数据手册上说进入`SPI DOWNLOAD`模式需要 `IO8 = 1`，但是我看到一些设计并没有主动上拉IO8

## **PCB说明**
> 东西不是很多，简单布局拉拉线就好了，没有太多需要注意的
### PCB的整体布局

元件封装以`0603`作为主要封装，适合手焊。整体PCB大小为2.13寸墨水屏大小，以全贴合为目标设计，背面没有元件。PCB剩余空间还是很大的，可以增加更多功能。器件供电应保持先过电容，再在到器件。同时，ESP32模块天部分和SHT40传感器下面做禁止铺铜处理。

![PCB的整体布局](//image.lceda.cn/oshwhub/d619c7897b434c46bf3df4c08cbb561b.png)



# **4、软件部分**

> 软件使用了PlatformIO使用Arduino库进行开发，Board和Library已经集成好，克隆下来以后只要网络好，不需要像Arduino去配置板子等等繁琐的操作，可以直接编译成功，非常适合初学者进行二次开发。

## **软件概述**

| 使用到的库 | 版本 |
| --- | --- |
| adafruit/Adafruit SHT4x Library | ^1.0.4 |
| zinggjm/GxEPD2 | ^1.5.8 |
| olikraus/U8g2_for_Adafruit_GFX | ^1.8.0 |
| bblanchon/ArduinoJson | ^7.1.0 |

## **PART: A - 软件环境配置**

简单的PlatformIO环境配置，有经验的可以自己按照自己的喜好来

### I. 下载安装PlatformIO

准备以下工具和软件
- 电脑 (Win，Mac，Linux均可)
- VSCode
- 可以加快PlatformIO下载网络加速器(可选)[下面的方法二选一]
  - 代理走TUN模式(虚拟网卡)
  - 在VScode左下角`设置-代理`里面可以配置VSCode的代理

![下载安装PlatformIO.gif](//image.lceda.cn/oshwhub/d620ff8f2cfb448a802fcabdd8696e60.gif)

1. 打开 VSCode，点击左侧扩展图标，搜索并安装 "PlatformIO IDE" 插件。
2. 安装完成后，重启 VSCode。

### II. 下载并导入工程

工程 GitHub 地址: [SimpleEInkEnvMonitor](https://github.com/MeowKJ/SimpleEInkEnvMonitor) 喜欢别忘了点一个Star🌟!

![下载并导入工程.gif](//image.lceda.cn/oshwhub/e58afd440d37456c8529088e23624da2.gif)

1. 从 GitHub 下载工程压缩包并解压。（如果安装了git的话，更推荐先 fork 再 clone 项目，这样可以对自己的代码进行版本控制）
2. 在 VSCode 中打开 PlatformIO Home（点击左侧的蚂蚁图标）。
3. 选择 "Open Project" 并浏览到你的工程目录，点击 "Open" 导入工程。选择刚才下载的文件夹中的 `3.Software` 文件夹下的 `esp32c3` 文件夹。PlatformIO 会自动下载并安装依赖文件。
4. 将 `include` 文件夹中的 `config_example.h` 复制一份改名为 `config.h`，并修改 `config.h` 文件以完成配置参数。

### III. 编译和下载代码

![编译和下载代码](//image.lceda.cn/oshwhub/9bb458e7a95c42b3b4a85d03b717eb7f.png)

1. 如图所示，选择env Board为`env:meow_weather_board`，可能选择后又要进行下载一些资源。
2. 将板子通过USB和电脑连接，检查串口是否正确连接。
3. 点击左下角的“Build”按钮（对勾图标✅）编译代码。
4. 编译成功后，点击左下角的“Upload”按钮（箭头图标➡️）将代码上传(~~下载~~)到设备上。

完成这些步骤后，你的工程就成功安装并运行了。如果有任何问题，请参考 PlatformIO 的[官方文档](https://docs.platformio.org/)或社区资源以获得帮助。

## **PART: B - 重要的代码**
> 代码部分经验不多，有什么问题或者改进的地方请多多指出
### Ⅰ. 引脚的定义
引脚的定义代码在`boards/variants/meow_weather_board/pins_arduino.h`文件中
主要定义了 IIC（用来驱动SHT40传感器）和 SPI（用来驱动墨水屏），如果要更改线路墨水屏的话，这里修改引脚定义

![喵喵的帕斯.png](//image.lceda.cn/pullimage/coYJRcJRymuArHMEZqeEST5NiNw4yhEeEsZpo2hD.png)

### Ⅱ. 墨水屏型号选择
墨水屏驱动使用的是`GxEPD2`也是比较常见的一个墨水屏驱动库，具体的说明可以去阅读库文档。
GxEPD2的GitHub地址 https://github.com/ZinggJM/GxEPD2

型号选择的代码在`include/GxEPD2_display_selection.h`文件中
上面四个用来选择墨水屏的类别
`GxEPD2_BW`普通的双色墨水屏
`GxEPD2_3C`三色墨水屏
`GxEPD2_4C`四色墨水屏
`GxEPD2_7C`七色墨水屏
这四个只需选择一个就可，选择的方法是给这一行解除注释，其他3个增加注释。
然后在下面的条目中选择一个墨水屏的型号，我选择的是`GxEPD2_213_Z98c`也就是我这一块三色墨水屏。如果在下面选择的墨水屏具体型号和上面的类别不匹配的话，是会出现报错的。

![喵喵的帕斯-2.png](//image.lceda.cn/pullimage/AhdeGvNvMkIMjnnC8pAHagLIMRuUnBUs1Tsw5aZ3.png)

### Ⅲ. 获取天气

本项目使用`心知天气`的免费天气查询API。首先，注册一个账号，然后在心知天气控制台中获取API密钥中的私钥填入`include/config.h`文件如下位置中。

![喵喵的帕斯-4](//image.lceda.cn/pullimage/Ag28LPIKdlkb19lclzh77PpbmhJT75ERm1AeYv3r.png)

当然，其他天气服务也是可以用的。请求心知天气的代码在`src/Network.cpp`文件中，代码非常简易，仅仅只是一个HTTP-GET请求，然后在返回的JSON格式字符串中找到`code`字段，获取其后面的内容，即气象识别代码。然后，在`src/Weather.cpp`中，定义了一些气象识别码和天气图标的转换关系。
并没有用到`ArduinoJSON`库，不过，如果需要解析更多内容，使用JSON解析库可以省时省力省心。

![喵喵的帕斯-7](//image.lceda.cn/pullimage/weEGDLxy4G2Fp48dVqUpJ3VyH3CNowmZZ97FHF1S.png)

### Ⅳ. 获取传感器数据
这个世界上没有一件比在Arduino上驱动一些常用小模块更简单的事情了。SHT4x也是一种很常用的传感器了，直接下载`Adafruit SHT4x Library`库！
具体可以看库的说明，提供了3中精度模式和6种加热模式。在数据手册中为什么SHT4x下面不建议放焊盘，也许是怕加热器消耗更多能量吧。下面是一个简单的代码使用说明。

![喵喵的帕斯-8.png](//image.lceda.cn/pullimage/w1PJMgSNRDH6ETconqIe89rUmMBBTylVbTBtRT5A.png)

### Ⅴ. 墨水屏的驱动
略。
基本上就是调用`GxEPD2`库，例程和教程应该相当多，有条件的可以上LVGL库去做UI。
u8g2的自定义字体教程需要的话评论区说下后期我会补充。
# **6、大赛LOGO验证**

> 搞到张彩色丝印券，打了个彩色的


![logo验证](//image.lceda.cn/pullimage/EiKdRQkMjrjkNp5KKu1AeslDJh0xi3ZKIGC1fbbN.png)

# **7、项目总结**

首先感谢立创的这个温湿度训练营，除了领到了免费的券，还学到很多东西。盛思锐的传感器做的真的挺小的，用的SHT40其实和0603的阻容大小不相上下。

话说在做这个项目之前，我都不知道原来墨水屏断电可以保存内容，然后主要用于在电子标签，阅读器之类的。搞个大尺寸的做个日程表或者是通知表挺有意思，挂墙上去展示一些信息。这个项目的其实也没啥时间去做，代码功能也就最基础的，基本上能开源东西的都开源了，改改就行。第一次做墨水屏，好在基本上没遇到什么问题，社区里面开源的墨水屏项目也很多，照着电路图改改，打板子一次就成功了。电路设计的时候没啥雷点，一次画完就没改了，倒是那个屏幕排线比想象中的长，布局上最好排线再往内部靠靠。板子挺大的，空间听够用的，0603的封装也好焊接，除了ESP32那个模块第一次好像没焊好，然后重新小焊了一下就好了。在写代码的时候，还是尝试了其他的库，试了一些别的，最后还是用的GxEPD2，倒是一开始墨水屏刷不出来，除了型号不确认之外，发现是因为我丝印上面标的引脚号标歪了，浪费些时间。

注：我这个墨水屏刷一下要10秒。

# **8、演示视频**

**视频要求：**

请横屏拍摄，分辨率不低于1280×720，格式Mp4/Mov，单个视频大小限100M内；

视频标题：立创电赛：ESP32-C3 墨水屏温湿度检测-演示视频
