//
// Created by clement on 21/03/20.
//

#include <matrix.c>

#define LOADING_ANIMATION_SPEED 100000
#define DISMISS_ANIMATION_SPEED 50000

int main (void) {

    wiringPiSetup();//On init WiringPi

    initMax7219();//On init le Max7219

    int i;

    for(i=0;i<1;i++) {
        loadingAnimation(LOADING_ANIMATION_SPEED);
    }

    dismissAnimation(DISMISS_ANIMATION_SPEED);

    return 0;
}