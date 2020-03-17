//
// Created by clement on 17/03/20.
//

#ifndef RPI_MATRIX_H
#define RPI_MATRIX_H

#endif //RPI_MATRIX_H

#include "data_forme.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>

#include <wiringPi.h>
#include <wiringPiSPI.h>

#define	SPI_CHAN	1

char MAX7219_BRIGHTNESS = 0x0a;
char MAX7219_SCAN_LIMIT = 0x0b;
char MAX7219_DECODE_MODE = 0x09;
char MAX7219_SHUTDOWN = 0x0C;

static int myFd ;

void spiSetup (int delay);

/**
 * Sert à envoyer une info au max, data contient l'adresse ainsi que l'information : on envoit donc 2 octets
 */
void maxTransfertData_(char * data);

/**
 * Cette fonction sert à envoyé une information au MAX7219 : on envoie l'information data à l'adresse address
 */
void maxTransfertData(char address, char value);

/**
 * Allume la matrice
 */
void turnOnMatrice();

/**
 * Eteint la matrice
 */
void turnOffMatrice();

/**
 * dessine sur la matrice le dessin associé au paramètre
 * @param dessin doit être un tableau de 8 charactères
 */
void drawMatrix(char *dessin);

/**
 * Affiche un sourire sur la matrice de LEDs
 */
void sourisRaspberry();

/**
 * lance l'animation de "pleurs" sur la matrice de leds
 * @param delay : vitesse de l'animation (si delay=100000, on attendra 0.1s entre chaque "frame")
 */
void pleureRaspberry(long delay);

/**
 * @param delay : vitesse de l'animation (si delay=100000, on attendra 0.1s entre chaque "frame")
 */
void loadingAnimation(long delay);

/**
 * @param delay : vitesse de l'animation (si delay=100000, on attendra 0.1s entre chaque "frame")
 */
void validateAnimation(long delay);


/**
 * @param delay : vitesse de l'animation (si delay=100000, on attendra 0.1s entre chaque "frame")
 */
void dismissAnimation(long delay);

/**
 * Catte fonction sert à initialiser les paramètres du Max7219
 */
void initMax7219();
