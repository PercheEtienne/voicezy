//
// Created by clement on 21/03/20.
//

#include <stdio.h>
#include <wiringPi.h>

#define BUTTON 25

#define PUSHED 1
#define NOT_PUSHED 0

int main(){

    int state = PUSHED;
    int lastState;

    wiringPiSetup();

    printf ("Raspberry Pi - Quick2Wire Mainboard Button\n");

    pinMode (BUTTON, INPUT);

    for (;;) {

        lastState = state;

        if (!digitalRead(BUTTON)){
            //printf("Button pushed!\n");
            state = PUSHED;
        }else{
            //printf("Not pushed!\n");
            state = NOT_PUSHED;
        }

        printf("state : %d\n",state);
        printf("last state : %d\n",lastState);

        if (lastState!=state){
            printf("Different\n");
        }else{
            printf("Same\n");
        }

        delay(100);
    }

    return 0;
}