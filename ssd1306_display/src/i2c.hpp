#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

/**
 * 使用 diagram-ssd_i2c.json 文件加载查看效果.
*/

class I2C_SSD1306_OLED
{
public:
    Adafruit_SSD1306 oled;
    uint8_t width;
    uint8_t height;

public:
    // 初始化列表方式
    I2C_SSD1306_OLED(uint8_t w, uint8_t h) : width(w), height(h)
    {
        // 构造oled对象,i2c协议
        // twi: IIC总线实例，默认为&wrie
        // rst_pin: 复位引脚，没有则填-1
        oled = Adafruit_SSD1306(w, h, &Wire, -1);
    }

    void show();
};

void I2C_SSD1306_OLED::show()
{

    // oled init
    // SSD1306_SWITCHCAPVCC 电压
    // SSD1306模块的默认I2C地址为0x3c
    oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);

    // Clear the buffer
    oled.clearDisplay();

    oled.drawLine(1, 1, 22, 22, SSD1306_WHITE);

    // 显示字符
    oled.setTextSize(1);
    oled.setTextColor(SSD1306_WHITE);
    oled.setCursor(2,2);
    oled.print(F("Score:"));

    // Show the display buffer on the screen. You MUST call display() after
    // drawing commands to make them visible on screen!
    oled.display();

    // testfillrect();
}