//
// Created by clement on 22/03/20.
//

void enregistreSound() {
    system("/home/pi/voicezy/micro/lanceEnregistrement.sh 1 test.wav");
}

void waitForButtonAndEnregistreSound(){

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
                return;
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

    return 0;
}