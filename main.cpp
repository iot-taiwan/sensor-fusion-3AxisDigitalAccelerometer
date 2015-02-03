
#include <mbed.h>
#include "MMA7660.h"

DigitalOut myled1(LED1);
DigitalOut myled2(LED2);
DigitalOut myled3(LED3);
DigitalOut myled4(LED4);

MMA7660 accelemeter;

int main()
{
    int8_t x, y, z;
    float ax,ay,az;
    accelemeter.init();
    while(1) {
        myled4=1;
        accelemeter.getXYZ(&x,&y,&z);
        printf("X=%d, Y=%d, Z=%d, ",x,y,z);

        accelemeter.getAcceleration(&ax,&ay,&az);
        printf("Accleration of X=%2.2fg, Y=%2.2fg, Z=%2.2fg\n\r",ax,ay,az);

        if(ax<0) {
            myled1=1;
        } else {
            myled1=0;
        }
        if(ay<0) {
            myled2=1;
        } else {
            myled2=0;
        }
        if(az<0) {
            myled3=1;
        } else {
            myled3=0;
        }


        wait(.5);
    }
}