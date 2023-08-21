#include <Arduino.h>
#include "oneled.hpp"


int ledPinList[] = {12, 13, 14, 26, 27};

void setup()
{

    // 设置引脚为输出模式
    for (size_t i = 0; i < 5; i++)
    {
      pinMode(ledPinList[i], OUTPUT);
    }
  

  // 给D13引脚放电就点亮led.
  OnLED(13);
}

void loop()
{
  // put your main code here, to run repeatedly:
  // printf("hello wor2323d 333 \n");
  //  delay(1000);

  // 点亮一串LED
  OnLEDList(ledPinList);
  delay(2000);
  // 关闭led
  // OffLEDList(ledPinList);

  digitalWrite(12, LOW);
  printf("hello wor2323d 333 \n");
}