#include <Arduino.h>

// 定义所有段选线引脚
int pin_a = 32;
int pin_b = 25;
int pin_c = 27;
int pin_d = 12;
int pin_e = 13;
int pin_f = 33;
int pin_g = 26;
int pin_dp = 14;

// 定义所有位选线引脚
int seg_1 = 5;
int seg_2 = 18;
int seg_3 = 19;
int seg_4 = 21;

// 位引脚数组
int segList[] = {seg_1, seg_2, seg_3, seg_4};

// 段引脚数组
int pinList[] = {pin_a, pin_b, pin_c, pin_d, pin_e, pin_f, pin_g, pin_dp};

int numList[][8] = {
	// a, b, c, d, e, f, g, dp
	{0, 0, 0, 0, 0, 0, 1, 1}, // 数字0
	{1, 0, 0, 1, 1, 1, 1, 1}, // 数字1
	{0, 0, 1, 0, 0, 1, 0, 1}, // 数字2
	{0, 0, 0, 0, 1, 1, 0, 1}, // 数字3
	{1, 0, 0, 1, 1, 0, 0, 1}, // 数字4
	{0, 1, 0, 0, 1, 0, 0, 1}, // 数字5
	{0, 1, 0, 0, 0, 0, 0, 1}, // 数字6
	{0, 0, 0, 1, 1, 1, 1, 1}, // 数字7
	{0, 0, 0, 0, 0, 0, 0, 1}, // 数字8
	{0, 0, 0, 0, 1, 0, 0, 1}, // 数字9
	{1, 1, 1, 1, 1, 1, 1, 0}, // 点
};

// 共阴数码管接GND, 接地
// 共阳数码管接VCC, 接电源

void clear()
{
	// 复位:设置所有引脚为输出引脚, 并初始化引脚为高电平(HIGH 熄灭). (LOW 点亮)
	for (size_t i = 0; i < 8; i++)
	{
		pinMode(pinList[i], OUTPUT);
		digitalWrite(pinList[i], HIGH);
	}

	// 初始化位选线
	for (size_t i = 0; i < 4; i++)
	{
		pinMode(segList[i], OUTPUT);
		digitalWrite(segList[i], LOW);
	}
}

void setup()
{
	Serial.begin(115200);
	Serial.println("Hello, ESP32 4!");

	clear();
}

void showNum4(int n4)
{

	// 转换数组到数组
	int showNumList[4];
	for (int i = 3; i >= 0; i--)
	{
		showNumList[i] = n4 % 10;
		n4 /= 10;
	}




	// 显示数组数字
	for (size_t i = 0; i < 4; i++)
	{	
		// 清屏函数
		clear();

		// 设置位选线
		digitalWrite(segList[i], HIGH);
		// 循环所有段引脚
		for (size_t k = 0; k < 8; k++)
		{
			int a = showNumList[i];
			digitalWrite(pinList[k], numList[a][k]);
		}
		delay(10);
	}
}

void loop()
{
	// put your main code here, to run repeatedly:

	// 延时1秒
	// delay(1000);

	// 测试显示4位数
	showNum4(987);
}