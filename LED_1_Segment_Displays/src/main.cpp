#include <Arduino.h>

// 定义所有引脚
int pin_a = 4;
int pin_b = 5;
int pin_c = 19;
int pin_d = 21;
int pin_e = 22;
int pin_f = 2;
int pin_g = 15;
int pin_dp = 18;

// 所有引脚
int pinList[] = {pin_a, pin_b, pin_c, pin_d, pin_e, pin_f, pin_g, pin_dp};

int numList[][8] = {
	// a, b, c, d, e, f, g, dp
	{  0, 0, 0, 0, 0, 0, 1, 1 }, // 数字0
	{  1, 0, 0, 1, 1, 1, 1, 1 }, // 数字1
	{  0, 0, 1, 0, 0, 1, 0, 1 }, // 数字2
	{  0, 0, 0, 0, 1, 1, 0, 1 }, // 数字3
	{  1, 0, 0, 1, 1, 0, 0, 1 }, // 数字4
	{  0, 1, 0, 0, 1, 0, 0, 1 }, // 数字5
	{  0, 1, 0, 0, 0, 0, 0, 1 }, // 数字6
	{  0, 0, 0, 1, 1, 1, 1, 1 }, // 数字7
	{  0, 0, 0, 0, 0, 0, 0, 1 }, // 数字8
	{  0, 0, 0, 0, 1, 0, 0, 1 }, // 数字9
	{  1, 1, 1, 1, 1, 1, 1, 0 }, // 点
};

// 共阴数码管接GND, 接地
// 共阳数码管接VCC, 接电源


void setup()
{
	Serial.begin(115200);
	Serial.println("Hello, ESP32!");

	// 复位:设置所有引脚为输出引脚, 并初始化引脚为高电平(HIGH 熄灭). (LOW 点亮)
	for (size_t i = 0; i < 8; i++)
	{
		pinMode(pinList[i], OUTPUT);
		digitalWrite(pinList[i], HIGH);
	}
}

void showNum(int n)
{

	// 循环所有引脚
	for (size_t i = 0; i < 8; i++)
	{
		digitalWrite(pinList[i], numList[n][i]);
	}
}

void loop()
{
	// put your main code here, to run repeatedly:

	// 延时1秒
	delay(1000);

	// 显示1-8
	for (size_t i = 0; i <= 10; i++)
	{
		showNum(i);
		delay(300);
	}
}