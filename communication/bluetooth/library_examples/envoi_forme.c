//
// Created by clement on 03/04/20.
//

#include "../library/bluetooth.c"

int main(){

    printf("Connect to arduino\n");
    int s = connectToArduino();

    printf("Draw neige\n");
    drawNeigeOnArduino(s);

    printf("Disconnect from Arduino\n");
    disconnectFromArduino(s);

    return 0;
}