//
// Created by clement on 04/04/20.
//

#include "firebase.h"

void sendTemperatureToFirebase(float temperature){
    char cmd[70] = "python /home/pi/voicezy/sendToFirebase.py Température";
    sprintf(cmd,"%s %.2f",cmd,temperature);
    printf("%s\n",cmd);
    system(cmd);
}

void sendHumidityToFirebase(float humidity){
    char cmd[70] = "python /home/pi/voicezy/sendToFirebase.py Humidité";
    sprintf(cmd,"%s %.2f",cmd,humidity);
    system(cmd);
}

void sendLuminosityToFirebase(int luminosity){
    char cmd[70] = "python /home/pi/voicezy/sendToFirebase.py Luminosité";
    sprintf(cmd,"%s %d",cmd,luminosity);
    system(cmd);
}

void sendLocalTemperatureToFirebase(float temperature){
    char cmd[70] = "python /home/pi/voicezy/sendToFirebase.py LocalTemperature";
    sprintf(cmd,"%s %.2f",cmd,temperature);
    system(cmd);
}