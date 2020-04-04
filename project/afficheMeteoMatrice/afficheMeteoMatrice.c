//
// Created by clement on 04/04/20.
//

#include <meteo.c>
#include <bluetooth.c>

int main(){
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