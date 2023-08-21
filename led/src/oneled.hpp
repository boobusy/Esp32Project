#include <Arduino.h>

/**
 * 教程: https://www.bilibili.com/video/BV1RM4y1a7J5
 * ESP32 中, 高电平是 > 2.5v, 低电平 < 0.5v
 * LED发光二极管, 3mA - 20mA 就会发光, 亮度不同. 限制电流不要太大,串联一个电阻(限流电阻)
 * 电阻可以放到阳极也可以放到阴极.
 * 电流从阳极流(A)向阴极(C): 比如: 阳极接 D13, 阴极接 GND.
 *
 */

void OnLED(int n)
{

    int led_pin = n;

    // 设置引脚为输出模式
    pinMode(led_pin, OUTPUT);
    // 设置 引脚高电平, 就点亮了.
    digitalWrite(led_pin, HIGH);
}


void OffLED(int n)
{
    // 设置 引脚低电平,关了.
    digitalWrite(n, LOW);
}


/**
 * 数组传递问题: https://www.cnblogs.com/sunsky303/p/7711388.html
 */

// 使用非类型模板参数
template <typename T, int n>
void OnLEDList(T (&arr)[n])
{
    // std::cout << "element num : " << sizeof(arr) / sizeof(arr[0]) << std::endl; //
    // int len = sizeof(arr) / sizeof(T);
    // printf("%d", len);

    for (int i = 0; i < n; i++)
    {
        OnLED(arr[i]);
    }
}

template <typename T, int n>
void OffLEDList(T (&arr)[n])
{
    // std::cout << "element num : " << sizeof(arr) / sizeof(arr[0]) << std::endl; //
    // int len = sizeof(arr) / sizeof(T);
    // printf("%d", len);

    for (int i = 0; i < n; i++)
    {
        OffLED(arr[i]);
    }
}