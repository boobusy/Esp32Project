#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


/**
 *  显示器分为 0x3c, 0x3d, 教程里面都是0x3d, 我这里试试0x3c, 只有4个引脚.
 *  SPI,分为3线和4线, 我这里是用的 0X3C, 是三线. 输入输出合并了一根线.
 * 
*/

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_ACL 22
#define OLED_MOSISO 21


// 0X3C+SA0 - 0x3C or 0x3D
#define I2C_ADDRESS 0x3C

// Define proper RST_PIN if required.
#define RST_PIN -1

Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT,&Wire, 3);

#define LOGO_HEIGHT 16
#define LOGO_WIDTH 16
static const unsigned char PROGMEM logo_bmp[] =
    {B00000000, B11000000,
     B00000001, B11000000,
     B00000001, B11000000,
     B00000011, B11100000,
     B11110011, B11100000,
     B11111110, B11111000,
     B01111110, B11111111,
     B00110011, B10011111,
     B00011111, B11111100,
     B00001101, B01110000,
     B00011011, B10100000,
     B00111111, B11100000,
     B00111111, B11110000,
     B01111100, B11110000,
     B01110000, B01110000,
     B00000000, B00110000};



void testfillrect()
{
    oled.clearDisplay();

    for (int16_t i = 0; i < oled.height() / 2; i += 3)
    {
        // The INVERSE color is used so rectangles alternate white/black
        oled.fillRect(i, i, oled.width() - i * 2, oled.height() - i * 2, SSD1306_INVERSE);
        oled.display(); // Update screen with each newly-drawn rectangle
        delay(1);
    }

    delay(2000);
}


void setup()
{
    Serial.begin(9600);

    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
    if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3D))
    { // Address 0x3D for 128x64
        Serial.println(F("SSD1306 allocation failed"));
        for (;;)
            ; // Don't proceed, loop forever
    }

    // Show initial display buffer contents on the screen --
    // the library initializes this with an Adafruit splash screen.
    oled.display();
    delay(2000); // Pause for 2 seconds

    // Clear the buffer
    oled.clearDisplay();

    // Draw a single pixel in white
    oled.drawPixel(10, 10, SSD1306_WHITE);

    // Show the display buffer on the screen. You MUST call display() after
    // drawing commands to make them visible on screen!
    oled.display();

    testfillrect();


}

void loop()
{
}