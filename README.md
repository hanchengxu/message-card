项目简介
-------
#### 中文 | [日本語](https://github.com/hanchengxu/message-card/blob/main/README.ja.md) 

esp8266和一块0.96寸OLED单色显示屏(I2C)组合成的一个信息显示模块。用arduino nano或者其他板子  
也可以,仅仅因为手头没有其他板子😬。虽然是esp8266但没有使用Wifi和Bluetooth这些功能。  
仅仅是通过esp8266来显示数据而已。

稍微有那么点特色的话就是支持纵向滚动显示数据了。  

并没有独立供电，需要micro usb 连接移动电源或者电脑USB端口来供电。  
正因如此，也不需要焊接，组装起来也非常简单。


## 材料
1. esp8266一块
2. 0.96 OLED一块(I2C协议)
3. 一些面包板跳线
4. 35X47mm面包板两块

## 开发环境🛠️
1. [arduino 官方IDE ](https://www.arduino.cc/en/software)
2. [配置esp8266开发环境](https://www.jianshu.com/p/cb0274d612b5)

## 显示文本📃
您需要在代码里的`c_str[]`数组中写入显示内容。  
⚠️每行中文最多设定8个文字，并且需要配置换行符⚠️。  
```
const char c_str[] = 
    "こんにちは\n\n"
    "Hello world\n"
    "请注意每行结尾的\n"
    "换行符。\n"
    "每行最多8个文字\n";
```
## 语言🌎
使用了u8g2库显示文字,您可以在setup函数中指定语言文字。
```
u8g2.setFont(u8g2_font_b12_t_japanese3);
```

## 纵向滚动
参考了u8g2库的[Shennong](https://github.com/olikraus/u8g2/blob/master/sys/arduino/u8g2_full_buffer/Shennong/Shennong.ino)例程。

您可以控制下面两个参数来调整滚动的速度
```
#define SCROLL_DELTA 2
#define SCROLL_DELAY 350
```
## 接线图

| esp8266 | OLED |
----|---- 
| 3v3 | VCC |
| GNU | GND |
| D1 | SCL |
| D2 | SDA |  
<img src="https://github.com/hanchengxu/message-card/blob/main/3c10c88870aa0de9324506aeea43fad.jpg" width="500px" alt="" align=center />  

