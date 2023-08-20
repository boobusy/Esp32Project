#include <Arduino.h>
#include <LiquidCrystal_I2C.h> // 直接使用PlatformIO安装, 或者库文件下载地址: https://github.com/marcoschwartz/LiquidCrystal_I2C

/**
 *  连接 led_1602, 由于管脚占用很多, 选择 i2c协议的 led_1602(它绑定了个芯片). i2c 只需要2根线就可以传输大量数据
 *  I2C: 同步半双工协议.
 *  SPI: 同步全双工协议
 *  SDA: 双向数据线, 不能乱接,看原理图
 *  SCL: 时钟线, 不能乱接
 */

#define I2C_ADDR 0x27
#define LCD_COLUMNS 16 // 16 列
#define LCD_LINES 2    // 2行

LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_LINES);

void setup()
{
    // Init
    lcd.init();
    lcd.backlight(); // 开启背光

    // Print something
    lcd.setCursor(3, 0); // 3列0行
    lcd.print("Hello, world!");
    lcd.setCursor(2, 1); // 2列1行
    lcd.print("Wokwi Online IoT");

    // 设置串口波特率,使用串口读取数据并显示
    Serial.begin(9600);
}

void loop()
{
    delay(2000);

    // 检测串口是否有输入
    if (Serial.available())
    {
        // 延时100,等待输入完成.
        delay(100);
        // 清屏
        lcd.clear();

        // 反复读取串口数据,显示到屏幕上.
        while (Serial.available())
        {
            lcd.write(Serial.read()); // read一次一个字节,所以需要反复读.
        }
    }
}
