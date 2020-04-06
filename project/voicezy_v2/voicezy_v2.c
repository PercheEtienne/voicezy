//
// Created by clement on 06/04/20.
//

#include "voicezy_v2.h"

void initialisation(){

    wiringPiSetup();//On init WiringPi

    initMax7219();//On init le Max7219

    init_recognition();

    drawMatrix(blackScreen);
}


void afficheMeteoMatrice(){
    char temp[10];
    char state[50];
    recupereLaMeteo(temp,state);

    printf("temp : %s\n",temp);

    int pid = fork();

    if (pid==0) { //processus 1

        printf("Connect to arduino\n");
        int s = connectToArduino();

        printf("state : %s\n", state);

        if (strcmp("Thunderstorm", state) == 0)
            drawEclairOnArduino(s);
        else if (strcmp("Drizzle", state) == 0 || strcmp("Rain", state) == 0)
            drawPluieOnArduino(s);
        else if (strcmp("Snow", state) == 0)
            drawNeigeOnArduino(s);
        else if (strcmp("Clear", state) == 0)
            drawSoleilOnArduino(s);
        else
            drawNuageOnArduino(s);

        printf("Disconnect from Arduino\n");
        disconnectFromArduino(s);

    }else{ //processus 2
        float temp_float = strtod(temp,NULL);
        temp_float -= 273.15; //conversion kelvin en degré
        sendTemperatureToFirebase(temp_float);
    }
}

int main(){
    int i;

    initialisation();

    waitForButtonAndEnregistreSound();

    int cmd = recherche_Ordre(audio_recognition_function("enregistrement.wav"));

    printf("CMD : %d\n",cmd);

    switch (cmd){
        case 1 :
            afficheMeteoMatrice();
            break;
        case 2 :

            break;
        case 3 : break;
        case 4 : break;
        case 5 : break;
        case 6 : break;
        case 7 : break;
    }
}