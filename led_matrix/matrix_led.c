//
// Created by clement on 12/03/20.
//


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>

#include <wiringPi.h>
#include <wiringPiSPI.h>

#define	TRUE	(1==1)
#define	FALSE	(!TRUE)

#define	SPI_CHAN	1

// MAX7219 SPI LED Driver
char MAX7219_TEST = 0x0f; // in real code put into a .h file
char MAX7219_BRIGHTNESS = 0x0a; // in real code put into a .h file
char MAX7219_SCAN_LIMIT = 0x0b; // in real code put into a .h file
char MAX7219_DECODE_MODE = 0x09; // in real code put into a .h file
char MAX7219_SHUTDOWN = 0x0C; // in real code put into a .h file


static int myFd ;
char p = '1';
char p2 = 'k';

void spiSetup (int speed)
{
    if ((myFd = wiringPiSPISetup (SPI_CHAN, speed)) < 0)
    {
        fprintf (stderr, "Can't open the SPI bus: %s\n", strerror (errno)) ;
        exit (EXIT_FAILURE) ;
    }
}

/**
 * Cette fonction sert à transferer une commande au MAX7219
 * Ex : allume toi, ou met ta luminosité à 10%, ...
 */
void maxTransfertCommand(char address, char value){
    wiringPiSPIDataRW(SPI_CHAN, &address, sizeof(char));
    wiringPiSPIDataRW(SPI_CHAN, &value, sizeof(char));
    wiringPiSPIDataRW(SPI_CHAN, &address, sizeof(char));
    wiringPiSPIDataRW(SPI_CHAN, &value, sizeof(char));
}

/**
 * Cette fonction sert à envoyé une information au MAX7219
 * On s'en sert pour lui dire quels LEDs il doit allumer
 */
void maxTransfertData(char address, char value, char v2){
    wiringPiSPIDataRW(SPI_CHAN, &address, sizeof(char));
    wiringPiSPIDataRW(SPI_CHAN, &value, sizeof(char));
    wiringPiSPIDataRW(SPI_CHAN, &address, sizeof(char));
    wiringPiSPIDataRW(SPI_CHAN, &v2, sizeof(char));
}

void turnOnMatrice(){
    maxTransfertCommand(MAX7219_SHUTDOWN, 1);//Turn on chip
}

void turnOffMatrice(){
    maxTransfertCommand(MAX7219_SHUTDOWN, 0);//Turn on chip
}



/**
 * Catte fonction sert à initialiser les paramètres du Max7219
 */
void initMax7219(){
    //On init la communication SPI a une vitesse de 1000000
    spiSetup(1000000);

    //Le decode mode est surtout utile lorsque le MAX7219 est utilisé avec des afficheurs 7 segments, or, ici,
    //il est utilisé avec une matrice de LEDs, on ne veut donc pas que notre information soit 'interprétée'
    //mais plutôt que l'on affiche exactement ce que l'on veut afficher
    maxTransfertCommand(MAX7219_DECODE_MODE, 0);
    maxTransfertCommand(MAX7219_BRIGHTNESS, 0);//Use lowest intensity
    maxTransfertCommand(MAX7219_SCAN_LIMIT, 15);//Scan all digit
    turnOnMatrice();
}

int main (void)
{

    char address, value, v2;

    //On init WiringPi
    wiringPiSetup();

    initMax7219();

    char row;
    int i=0,ud=2;

    for(;;){
        i+=ud;
        if(i>255){
            ud=-1;
            i=255;
        }
        else if (i<0){
            ud=1;
            i=0;
        }
        else if (row++>8)
            row=1;

        value = (char)i;

        maxTransfertData(row, value, value);
        //printf("%d\n",i);
        usleep(1000000);

        if (value>5) {
            turnOffMatrice();
            printf("Turn Off");
        }
    }

}