#include <U8g2lib.h>
#include <DHT.h>

// 在这里修改你接入的引脚和传感器类型
#define DHTPIN 14
#define DHTTYPE DHT11

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2 (U8G2_R0, U8X8_PIN_NONE);//前缀_显示控制器_显示名字_缓存大小_通信协议

// 初始化dht
DHT dht(DHTPIN,DHTTYPE);

void setup() {
  Serial.begin(115200);
  u8g2.begin();                   // 初始化U8g2库
  u8g2.enableUTF8Print();                   // 开启Arduino平台下支持输出UTF8字符集
  u8g2.setFont(u8g2_font_wqy12_t_gb2312b);   // 设置字体集

  // 传感器初始化
  dht.begin();

  //显示屏显示信息
  u8g2.clearBuffer();                   // 清除内存
}

void loop() {
  // 显示
  double temperatureNow = dht.readTemperature();
  delay(1000);
  double humidityNow = dht.readHumidity();
  Serial.println(temperatureNow);
  Serial.println(humidityNow);

  char temperatureNowChar[6];
  char humidityNowChar[5];
  sprintf(temperatureNowChar,"%.2f",temperatureNow);
  sprintf(humidityNowChar,"%.2f",humidityNow);
  String temperatureNowStr = temperatureNowChar;
  String humidityNowStr = humidityNowChar;

  u8g2.clearBuffer();

  u8g2.drawUTF8(5,10,"当前环境的温/湿度");
  u8g2.drawUTF8(5,25,"温度->");
  u8g2.drawUTF8(50,25,temperatureNowStr.c_str());
  u8g2.drawUTF8(80,25,"°C");
  u8g2.drawUTF8(5,45,"湿度->");
  u8g2.drawUTF8(50,45,humidityNowStr.c_str());
  u8g2.drawUTF8(80,45,"%");

  u8g2.sendBuffer();

  // 10s刷新一次
  delay(10000);
}
