#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"

// For the Adafruit shield, these are the default.
#define TFT_DC 2
#define TFT_CS 15
#define TFT_MOSI 11
#define TFT_MISO 12
#define TFT_CLK 13
#define TFT_RST -1

// 软件 SPI
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

class SPI_ILI9341_TFT
{
public:
    // Adafruit_ILI9341 tft;

public:
    SPI_ILI9341_TFT()
    {
        // Use hardware SPI (on Uno, #13, #12, #11) and the above for CS/DC
        // Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
        //  If using the breakout, change pins as desired
        // tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST, TFT_MISO);
    }

    void show();
    unsigned long testFillScreen();
};

void SPI_ILI9341_TFT::show()
{

    tft.begin();

    // 旋转屏幕
    tft.setRotation(1); // 0 - 3

    // read diagnostics (optional but can help debug problems)
    uint8_t x = tft.readcommand8(ILI9341_RDMODE);
    Serial.print("Display Power Mode: 0x");
    Serial.println(x, HEX);
    x = tft.readcommand8(ILI9341_RDMADCTL);
    Serial.print("MADCTL Mode: 0x");
    Serial.println(x, HEX);
    x = tft.readcommand8(ILI9341_RDPIXFMT);
    Serial.print("Pixel Format: 0x");
    Serial.println(x, HEX);
    x = tft.readcommand8(ILI9341_RDIMGFMT);
    Serial.print("Image Format: 0x");
    Serial.println(x, HEX);
    x = tft.readcommand8(ILI9341_RDSELFDIAG);
    Serial.print("Self Diagnostic: 0x");
    Serial.println(x, HEX);

    Serial.println(F("Benchmark                Time (microseconds)"));
    delay(10);
    Serial.print(F("Screen fill              "));
    Serial.println(testFillScreen());
    delay(500);

    Serial.println(F("Done!"));

    // 显示文字
    tft.setCursor(0, 0);
    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(1);
    tft.println("Hello World!");
    tft.setTextColor(ILI9341_YELLOW);
    tft.setTextSize(2);
    tft.println(1234.56);
    tft.setTextColor(ILI9341_RED);
    tft.setTextSize(3);
    tft.println(0xDEADBEEF, HEX);
    tft.println();
    tft.setTextColor(ILI9341_GREEN);
    tft.setTextSize(5);
    tft.println("Groop");
    tft.setTextSize(2);
    tft.println("I implore thee,");
    tft.setTextSize(1);
    tft.println("my foonting turlingdromes.");
    tft.println("And hooptiously drangle me");
    tft.println("with crinkly bindlewurdles,");
    tft.println("Or I will rend thee");
    tft.println("in the gobberwarts");
    tft.println("with my blurglecruncheon,");
    tft.println("see if I don't!");
}

unsigned long SPI_ILI9341_TFT::testFillScreen()
{
    unsigned long start = micros();

    yield();
    tft.fillScreen(ILI9341_RED);
    yield();
    tft.fillScreen(ILI9341_GREEN);
    yield();
    tft.fillScreen(ILI9341_BLUE);
    yield();
    tft.fillScreen(ILI9341_BLACK);
    yield();
    return micros() - start;
}