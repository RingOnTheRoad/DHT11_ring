# DHT11_ring

### 需求物料

ESP8266开发板

DHT11

0.96寸OLED屏幕

母对母杜邦线7条

MicroUSB数据线



### 物理连接方式

| ESP8266 | OLED | DHT11 |
| :-----: | :--: | :---: |
|    G    | GND  |       |
|   3V    | VCC  |       |
|   D1    | SCL  |       |
|   D2    | SDA  |       |
|    G    |      |  GND  |
|   3V    |      |  VCC  |
|   D5    |      | DATA  |



### 需求库文件

DHT (以.zip导入库)



### ino文件需要填写参数

```c++
// 在这里修改你接入的引脚和传感器类型

#define DHTPIN 14

#define DHTTYPE DHT11
```



### 填写参数说明

DHTPIN:DHT11的DATA数据线与ESP8266连接的引脚

| ESP8266引脚 | DHTPIN |
| :---------: | :----: |
|     D0      |   16   |
|     D1      |   5    |
|     D2      |   4    |
|     D3      |   0    |
|     D4      |   2    |
| D5（推荐）  |   14   |
|     D6      |   12   |
|     D7      |   13   |
|     D8      |   15   |
|     D9      |   3    |
|     D10     |   1    |