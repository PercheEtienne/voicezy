//
// Created by clement on 21/03/20.
//

#include <stdio.h>
#include <wiringPi.h>

#define BUTTON 25

int main(){

    wiringPiSetup();

    printf ("Raspberry Pi - Quick2Wire Mainboard Button\n");

    pinMode (BUTTON, INPUT);

    for (;;)
    {
        if (!digitalRead(BUTTON)){
            printf("Button pushed!\n");
        }
        delay(100);
    }

    return 0 ;
}