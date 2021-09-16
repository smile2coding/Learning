# study of STM32

> STM32单片机是ST（意法半导体）公司使用ARM公司的Cortex-M系列为核心生产的32bit系列的单片机，追求高性能、低功耗、低成本。

<img src="https://gitee.com/xiaoshihd/MdPicture/raw/master/img/20201123193718.png" alt="image-20201123193713582"  />

## 1. MDK-keil

keil公司是一家优秀的微控制器（MCU）软件开发工具供应商，于2005年被ARM公司收购。

MDK（Microcontroller Development Kit）,可称MDK-ARM、KEIL MDK、RealView MDK、KEIL for ARM，都是同一东西。

## 2. ARM7、ARM11和Cortex M的区别

ARM公司自2004年推出ARMv7内核架构，之后便放弃了以”ARM+数字“命名处理器的方式，arm系列从arm11开始，以后的就命名为cortex。

* Cortex-A系列：面向性能密集型系统的应用处理器内核

- Cortex-R系列：面向实时应用的高性能内核
- Cortex-M系列：面向各类嵌入式应用的微控制器内核

## 3. GPIO

STM32的GPIO口有八种模式：

* GPIO_Mode_AIN 模拟输入
* GPIO_Mode_IN_FLOATING 浮空输入
* GPIO_Mode_IPD 下拉输入
* GPIO_Mode_IPU 上拉输入
* GPIO_Mode_Out_OD 开漏输出
* GPIO_Mode_Out_PP 推挽输出
* GPIO_Mode_AF_OD 复用开漏输出
* GPIO_Mode_AF_PP 复用推挽输出



