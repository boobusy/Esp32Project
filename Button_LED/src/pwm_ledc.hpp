#include <Arduino.h>

/**
 * 通过 ledc 这个库,产生 pwm 信号 
*/


#define FREQ 2000    // 频率
#define CHANNEL 0    // 通道
#define RESOLUTION 8 // 分辨率 2**8 次方


void pwm_SetUp(int pin_led)
{
    
    // pwd模式(模拟电路)实现渐变
    // 1. 设置通道
    ledcSetup(CHANNEL,FREQ, RESOLUTION);
    // 绑定通道和引脚
    ledcAttachPin(pin_led, CHANNEL);
}


void pwm_flash_led(int pin_led)
{
    // 模拟电压制造呼吸灯效果. 数电转模电.
    // 渐亮
    for (int i = 0; i < pow(2, RESOLUTION); i += 20)
    {
        ledcWrite(CHANNEL,i);
        delay(20);
        // Serial.printf("i++ %d \n", i);
    }

    // 渐灭
    for (int i = pow(2, RESOLUTION) - 1; i >= 0; i -= 20)
    {
        ledcWrite(CHANNEL,i);
        delay(20);
        // Serial.printf("i-- %d \n", i);
    }
}