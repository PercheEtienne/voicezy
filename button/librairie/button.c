//
// Created by clement on 22/03/20.
//
#include "button.h"

void enregistreSound() {
    system("arecord -f S16_LE -r16000 -t wav -D plughw:1,0 enregistrement.wav");
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
                exit(0);
            }

            for(;;){
                if (digitalRead(BUTTON)){
                    system("ps | grep arecord | cut -d' ' -f2 | xargs kill");
                    return;
                }
                delay(100);
            }
        }
        delay(100);
    }

    return;
}