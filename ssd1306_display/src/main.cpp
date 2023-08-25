#include <Arduino.h>
#include "i2c.hpp"
#include "ili9341.hpp"

/**
 *  显示器(wokwi)分为 0x3c, 0x3d, 教程里面都是0x3d, 我这里试试0x3c, 只有4个引脚.
 *  4个引脚的是 I2C 协议啊.
 *
 *  SPI,分为3线和4线. 还分为软SPI和硬件SPI.
 *  电源接3.3v或者5v都行, 5v清晰一些.
 * 
 *  wokwi 上的 ssd1603 屏幕不支持SPI啊.
 *
 */

// 软件I2C
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// ssd1306_i2c
#define SSD1306_I2C_SCL 22
#define SSD1306_I2C_MOSI 21


// 使用硬件SPI控制 TLF显示屏
// Use hardware SPI (on Uno, #13, #12, #11) and the above for CS/DC
// Adafruit_ILI9341 tft = Adafruit_ILI9341(OLED_CS, OLED_DC);
// If using the breakout, change pins as desired
// Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST, TFT_MISO);

// 自定义类,i2c ssd1306
I2C_SSD1306_OLED i2cOled(SCREEN_WIDTH, SCREEN_HEIGHT);

// 自定义类,spi 
SPI_ILI9341_TFT tftq;


void setup()
{
    Serial.begin(9600);
    
    //i2cOled.show();

    tftq.show();
}

void loop()
{
}