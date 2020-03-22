//
// Created by clement on 22/03/20.
//

#ifndef RPI_BUTTON_H
#define RPI_BUTTON_H

#endif //RPI_BUTTON_H

#include <stdio.h>
#include <wiringPi.h>
#include <stdlib.h>

#define BUTTON 25

#define PUSHED 1
#define NOT_PUSHED 0

void enregistreSound();
void waitForButtonAndEnregistreSound();