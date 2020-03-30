//
// Created by clement on 28/03/20.
//

#include "../librairie/temperature.c"

int main(){
    float temp;
    float humidite;

    wiringPiSetup();

    if (read_temperature(&temp,&humidite))
        printf("Temperature : %f\nHumidité : %f\n",temp,humidite);

    return;
}