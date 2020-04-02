//
// Created by clement on 28/03/20.
//

#ifndef RPI_TEMPERATURE_H
#define RPI_TEMPERATURE_H

#endif //RPI_TEMPERATURE_H

#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAXTIMINGS	85
#define DHTPIN		7
#define MAX_TRY 100

int dht11_dat[5] = { 0, 0, 0, 0, 0 };

/**
 *
 * @param timeOut, le temps max pour récupérer la température (en ms)
 * @param temperature : variable qui contiendra la temperature
 * @param humidite : variable qui contiendra l'humidite
 * @return 1 si OK, 0 sinon
 */
char read_temperature_(float *temperature, float *humidite);

/**
 * Réitère tant que ne récupère pas réellement la température et l'humidité (100 fois max)
 * @param timeOut, le temps max pour récupérer la température (en ms)
 * @param temperature : variable qui contiendra la temperature
 * @param humidite : variable qui contiendra l'humidite
 * @return 1 si OK, 0 sinon
 */
char read_temperature_(float *temperature, float *humidite);