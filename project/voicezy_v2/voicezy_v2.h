//
// Created by clement on 06/04/20.
//

#ifndef RPI_VOICEZY_V2_H
#define RPI_VOICEZY_V2_H

#endif //RPI_VOICEZY_V2_H

#include <meteo.c>
#include <bluetooth.c>
#include <matrix.c>
#include <button.c>
#include <deepspeech.c>
#include <firebase.c>
#include <lightsensor.c>
#include <temperature.c>
#include <buzzer.c>

#define LOADING_ANIMATION_SPEED 100000
#define DISMISS_ANIMATION_SPEED 50000
#define VALIDATE_ANIMATION_SPEED 50000
#define LOADING2_ANIMATION_SPEED 150000

char dest[18] = "00:12:05:11:94:92";

void initialisation();
void afficheMeteoMatrice();
void initialisation();

void* loading_anim();

void* loading_anim2();

void* dismiss_anim();

void* success_anim();

void* sendToFirebaseMeteo();

void afficheMeteoMatrice();

void luminosity();

void humidity();

void temperature();

void allumeLumiere();

void eteindLumiere();