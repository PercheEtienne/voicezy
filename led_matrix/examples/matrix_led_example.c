//
// Created by clement on 12/03/20.
//

#include "../librairie/matrix.c"

int main (void) {

    wiringPiSetup();//On init WiringPi

    initMax7219();//On init le Max7219

    int i;
    
    for(i=0;i<1;i++) {
        loadingAnimation(100000);
    }
    
    dismissAnimation(50000);

    return 0;
}