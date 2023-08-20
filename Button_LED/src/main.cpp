#include <Arduino.h>
#include "analog_led.hpp"
#include "pwm_ledc.hpp"

#define FLASH_LED 12

int pin_btn = 13;
int pin_led = 2;
int led_logic = 0;

void setup()
{

    Serial.begin(115200);
    Serial.println("Hello, ESP32 btn!");

    // 按钮配置: 下拉电阻
    pinMode(pin_btn, INPUT_PULLDOWN);

    // analog 模式闪灯配置
    // analog_setup(FLASH_LED);

    // pwm 模式闪灯配置
    pwm_SetUp(FLASH_LED);
}

void button()
{
    // 软件消抖
    if (digitalRead(pin_btn) && 1 == 2)
    {              // 按下
        delay(10); // 延迟 10ms 再次判断是否按下.

        if (digitalRead(pin_btn) && digitalRead(pin_led))
        {
            Serial.println("Hello, ESP32 btn!");
            led_logic = !led_logic;
            digitalWrite(pin_led, LOW);
        }
        else if (digitalRead(pin_btn) && !digitalRead(pin_led))
        {
            led_logic = !led_logic;
            digitalWrite(pin_led, HIGH);
        }
    }
}

void loop()
{

    // analog 模式闪一闪LED, 渐亮渐暗
    // analog_flash_led(FLASH_LED);

    // pwm 模式闪一闪LED, 渐亮渐暗
    pwm_flash_led(FLASH_LED);
}
