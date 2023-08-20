#include <Arduino.h>


void analog_setup(int pin_led)
{
    pinMode(pin_led, OUTPUT);
    digitalWrite(pin_led, LOW);
}


void analog_flash_led(int pin_led)
{
    // 模拟电压制造呼吸灯效果. 数电转模电.
    // 渐亮
    for (int i = 0; i < 256; i += 20)
    {
        analogWrite(pin_led, i);
        delay(20);
        // Serial.printf("i++ %d \n", i);
    }

    // 渐灭
    for (int i = 255; i >= 0; i -= 20)
    {
        analogWrite(pin_led, i);
        delay(20);
        // Serial.printf("i-- %d \n", i);
    }
}