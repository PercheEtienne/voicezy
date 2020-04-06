//
// Created by clement on 21/03/20.
//

#include "voicezy.h"

void initialisation(){

    wiringPiSetup();//On init WiringPi

    initMax7219();//On init le Max7219

    drawMatrix(blackScreen);

}

void afficheMeteoMatrice(){
    char temp[10];
    char state[50];
    recupereLaMeteo(temp,state);

    printf("Connect to arduino\n");
    int s = connectToArduino();

    printf("state : %s\n",state);

    if (strcmp("Thunderstorm",state) == 0)
        drawEclairOnArduino(s);
    else if (strcmp("Drizzle",state) == 0 || strcmp("Rain",state) == 0)
        drawPluieOnArduino(s);
    else if (strcmp("Snow",state) == 0)
        drawNeigeOnArduino(s);
    else if (strcmp("Clear",state) == 0)
        drawSoleilOnArduino(s);
    else
        drawNuageOnArduino(s);

    printf("Disconnect from Arduino\n");
    disconnectFromArduino(s);
}

int main (void) {

    int i;

    initialisation();

    waitForButtonAndEnregistreSound();

    for(i=0;i<5;i++) {
        loadingAnimation(LOADING_ANIMATION_SPEED);
    }

    dismissAnimation(DISMISS_ANIMATION_SPEED);

    return 0;
}