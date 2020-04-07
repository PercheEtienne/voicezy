//
// Created by clement on 03/04/20.
//

#ifndef RPI_BLUETOOTH_H
#define RPI_BLUETOOTH_H

#endif //RPI_BLUETOOTH_H

#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>
#include "figures.h"

/**
 * Crée une socket de connection
 * @return le numéro de la socket
 */
int connectToArduino();

/**
 * dessine un soleil sur la matrice de l'arduino
 * @param s : le numéro de la socket
 */
void drawSoleilOnArduino(int s);

void drawNuageOnArduino(int s);

void drawPluieOnArduino(int s);

void drawEclairOnArduino(int s);

void drawBlackScreenOnArduino(int s);

void drawNeigeOnArduino(int s);

void drawLightOnArduino(int s);

/**
 * Se deconnecte de l'arduino
 * @param s : le numéro de la socket
 */
void disconnectFromArduino(int s);