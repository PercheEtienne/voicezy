//
// Created by clement on 22/03/20.
//
#include "button.h"

void enregistreSound() {
    system("/home/pi/voicezy/micro/lanceEnregistrement.sh 1 enregistrement.wav");
}

void waitForButtonAndEnregistreSound(){

    int state = NOT_PUSHED;
    int lastState;
    pthread_t th;

    pinMode (BUTTON, INPUT);

    for (;;) {
        lastState = state;

        if (!digitalRead(BUTTON)){

            int pid = fork();

            if (pid==0){
                enregistreSound();
                return;
            }

            for(;;){
                if (digitalRead(BUTTON)){
                    system("ps | grep arecord | cut -d' ' -f1 | xargs kill");
                    return;
                }
                delay(100);
            }
        }
        delay(100);
    }

    return;
}