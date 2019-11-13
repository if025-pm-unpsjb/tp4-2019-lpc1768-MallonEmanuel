#include "mbed.h"

DigitalOut led1(LED1);
DigitalOut led2(LED2);

int main()
{
    while(1)
    {
        led1 = 0;
        led2 = 1;
        wait(0.5);
        led1 = 1;
        led2 = 0;
        wait(0.5);
    }
}


