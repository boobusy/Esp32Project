#include <Arduino.h>
#include "oneled.hpp"

void setup()
{

  // 给D13引脚放电就点亮led.
  OnLED(13);

}

void loop()
{
  // put your main code here, to run repeatedly:
  // printf("hello wor2323d 333 \n");
  //  delay(1000);

  // 点亮一串LED
  int ledPinList[] = {12, 13, 14, 26, 27};
  OnLEDList(ledPinList);
  delay(100);
  // 关闭led
  OffLEDList(ledPinList);
}