//
// Created by clement on 21/03/20.
//

#include <matrix.c>
#include <button.c>

#define LOADING_ANIMATION_SPEED 100000
#define DISMISS_ANIMATION_SPEED 50000

void initialisation(){

    wiringPiSetup();//On init WiringPi

    initMax7219();//On init le Max7219

    drawMatrix(blackScreen);

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