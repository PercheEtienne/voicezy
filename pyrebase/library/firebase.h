//
// Created by clement on 04/04/20.
//

#ifndef RPI_FIREBASE_H
#define RPI_FIREBASE_H

#endif //RPI_FIREBASE_H

#include <stdio.h>
#include <string.h>

void sendTemperatureToFirebase(float temperature);
void sendHumidityToFirebase(float humidity);
void sendLocalTemperatureToFirebase(float temperature);
void sendLuminosityToFirebase(int luminosity);
