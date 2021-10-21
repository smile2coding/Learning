# Modbus通信协议
> MODBUS是一个请求/应答协议，位于OSI模型的第7层上的应用层报文传输协议。  

* Modbus：1979年，莫迪康，施耐德收购
* ModbusRtu/ModbusAscill/MobusTcp
* 开源免费
* 多种电气接口及通信介质
* 报文帧简单紧凑

![Modbus protocol](https://www.rfwireless-world.com/images/Modbus-protocol.jpg)

![Modbus message format,Modbus frame structure](https://www.rfwireless-world.com/images/Modbus-message-format.jpg)



## 1. Modbus protocol working

* The Modbus protocol typically follows a master and slave based architecture. Master transmits a request message to a slave and waits for a response message. This architecture provides complete control to the master for flow of information. This has great merits over the previous multidrop networks using RS422/RS485 etc
* As shown in the figure, Modbus request message is a layered set of data. Controllers can be setup to communicate on standard Modbus networks using either of two transmission modes: **ASCII or RTU**. Users select the desired mode, along with the serial port communication parameters (baud rate, parity mode, etc), during configuration of each controller. The mode and serial parameters must be the same for all devices on a Modbus network.
* The selection of ASCII or RTU(remote terminal unit) mode pertains only to standard Modbus networks. It defines the bit contents of message fields transmitted serially on those networks. It determines how information will be packed into the message fields and decoded.
*  When controllers are setup to communicate on a Modbus network using ASCII mode, each eight-bit byte in a message is sent as two ASCII characters. The main advantage of this mode is that it allows time intervals of up to one second to occur between characters without causing an error.
*  When controllers are setup to communicate on a Modbus network using RTU mode, each eight-bit byte in a message contains two four-bit hexadecimal characters. The main advantage of this mode is that its greater character density allows better data throughput than ASCII for the same baud rate. Each message must be transmitted in a continuous stream.

## 2. Modbus Functions

**function codes:**

* (0x01): read coils ---> 读取线圈
* (0x02): read discrete inputs ---> 
* (0x03): read holding registers --->
* (0x04): read input registers ---> 读取输入寄存器
* (0x05): write single coil ---> 读取单个线圈
* (0x06): write single register ---> 写单个寄存器
* (0x15): write mutiple coils ---> 写多个线圈
* (0x16): write mutiple registers ---> 写多个寄存器

## 3.**Modbus debugging tools:**

* Modbus poll 
* Modbus Slave
* VSPD

## 4. Modbus on serial (RS232、RS485)

### 4.1 frame format of sending

| slave address | funciton code | start reg | reg number |CRC|
| :-----------: | :-----------: | :-------: | :--------: |:-:|
|1byte|1byte|2bytes|2bytes|2bytes|

Tx: <font color=red>0A 03 01 11 00 01 D4 88</font>

### 4.2 frame fromat of receiving

| slave address | funciton code | byte count | data | data|...| CRC   |
| :-----------: | :-----------: | :--------: | :--------: | :-:|:-:|:----: |
|     1byte     |     1byte     |   2bytes   |   1byte   | 1byte |1byte|2bytes|

Rx: <font color=red>0A 03 02  xx xx xx xx</font>



