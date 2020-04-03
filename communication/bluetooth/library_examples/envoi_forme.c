//
// Created by clement on 03/04/20.
//

#include "../library/bluetooth.c"

int main(){

    printf("Connect to arduino\n");
    int s = connectToArduino();

    printf("Draw Soleil on Arduino\n");
    drawSoleilOnArduino(s);
    printf("Fin Draw Soleil on Arduino\n");
    sleep(2);
    printf("Draw nuage on Arduino\n");
    drawNuageOnArduino(s);
    printf("Fin nuage on Arduino\n");
    sleep(2);
    printf("Draw Soleil on Arduino\n");
    drawSoleilOnArduino(s);
    printf("Fin Draw Soleil on Arduino\n");

    disconnectFromArduino(s);

    return 0;
}