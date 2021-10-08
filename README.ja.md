項目紹介
-------
#### [中文](https://github.com/hanchengxu/message-card)  | 日本語

esp8266と0.96OLED(I2C)組立のモジュールです。arduino nanoやほかの開発ボードで運用もできます。  
項目はWifi、Bluetoothなの機能を使っていません。esp8266で文章を表示のことです。

ちょっと面白いのところは表示の文章が縦スクロール可能です。  
モジュールは電源付けないので、micro usbよりモバイルバッテリーやパソコンのUSBと連接必要です。

シンプル機能ので、組立もやりやすいと思います。

## 開発環境🛠️
1. [arduino IDE ](https://www.arduino.cc/en/software)
2. [Arduino IDE に  ESP8266 ボードをインストールする方法](https://www.mgo-tec.com/esp8266-board-install01-html)


## 材料
1. esp8266開発ボード一つ
2. 0.96 OLED(I2C 通信タイプ)
3. ジャンプワイヤキット
4. 170タイポイント Miniブレッドボード2PCS

## 文章表示📃
ソースコードの`c_str[]`文字列変数に表示の文字列を用意します。  
⚠️各行目最大文字数は10、改行の`\n`も必要です。⚠️
```
const char c_str[] = 
    "こんにちは\n\n"
    "Hello world\n"
    "行末の改行忘れない\n"
    "10文字数は最大の\n";
```
## 言語🌎
u8g2ライブラリ使ってOLEDで文字表示します。  
`setup`メソッドに表示の言語を設定できます。
```
u8g2.setFont(u8g2_font_b12_t_japanese3);
```

## 縦スクロール
u8g2ライブラリの[Shennong](https://github.com/olikraus/u8g2/blob/master/sys/arduino/u8g2_full_buffer/Shennong/Shennong.ino)を参照しています。

スクロール速度の設定は下記二つパラメータです。
```
#define SCROLL_DELTA 2
#define SCROLL_DELAY 350
```
## 回路図

| esp8266 | OLED |
----|---- 
| 3v3 | VCC |
| GNU | GND |
| D1 | SCL |
| D2 | SDA |  
<img src="https://github.com/hanchengxu/message-card/blob/main/3c10c88870aa0de9324506aeea43fad.jpg" width="500px" alt="" align=center />  

