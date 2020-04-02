//
// Created by clement on 21/03/20.
//

#include <stdio.h>
#include <wiringPi.h>
#include <stdlib.h>

#define BUTTON 25

#define PUSHED 1
#define NOT_PUSHED 0

void enregistreSound() {
    system("/home/pi/voicezy/micro/lanceEnregistrement.sh 1 test.wav");
}

int main(){

    int state = NOT_PUSHED;
    int lastState;
    pthread_t th;

    wiringPiSetup();

    pinMode (BUTTON, INPUT);

    for (;;) {
        lastState = state;

        if (!digitalRead(BUTTON)){

            int pid = fork();

            if (pid==0){
                enregistreSound();
                return 0;
            }

            for(;;){

                if (digitalRead(BUTTON)){
                    system("ps | grep arecord | cut -d' ' -f2 | xargs kill");
                    return 0;
                }

                delay(100);

            }
        }
        delay(100);
    }

    return 0;
}