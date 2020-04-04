//
// Created by clement on 05/04/20.
//

#include <temperature.c>
#include <firebase.c>

void recupereTemperatureEtEnvoi(){
    float temp;
    float humidite;
    if (read_temperature(&temp,&humidite)) {
        sendTemperatureToFirebase(temp);
    }
}

int main(){

    wiringPiSetup();

    recupereTemperatureEtEnvoi();

    return;
}
