//
// Created by clement on 17/03/20.
//

#include "matrix.h"


void spiSetup (int delay) {

    if ((myFd = wiringPiSPISetup (SPI_CHAN, delay)) < 0) {
        fprintf (stderr, "Can't open the SPI bus: %s\n", strerror (errno)) ;
        exit (EXIT_FAILURE) ;
    }

}

/**
 * Sert à envoyer une info au max, data contient l'adresse ainsi que l'information : on envoit donc 2 octets
 */
void maxTransfertData_(char * data){
    wiringPiSPIDataRW(SPI_CHAN, data, 2);
}

/**
 * Cette fonction sert à envoyé une information au MAX7219 : on envoie l'information data à l'adresse address
 */
void maxTransfertData(char address, char value){
    char infos[2];
    infos[0] = address;
    infos[1] = value;
    maxTransfertData_(infos);
}

/**
 * Allume la matrice
 */
void turnOnMatrice(){
    maxTransfertData(MAX7219_SHUTDOWN, 1);//Turn on chip
}

/**
 * Eteint la matrice
 */
void turnOffMatrice(){
    maxTransfertData(MAX7219_SHUTDOWN, 0);//Turn on chip
}

/**
 * dessine sur la matrice le dessin associé au paramètre
 * @param dessin doit être un tableau de 8 charactères
 */
void drawMatrix(char *dessin){
    int i=0;
    for(i;i<8;i++){
        maxTransfertData(i+1,dessin[i]);
    }
}

/**
 * Affiche un sourire sur la matrice de LEDs
 */
void sourisRaspberry(){
    drawMatrix(smile);
}

/**
 * lance l'animation de "pleurs" sur la matrice de leds
 * @param delay : vitesse de l'animation (si delay=100000, on attendra 0.1s entre chaque "frame")
 */
void pleureRaspberry(long delay){
    drawMatrix(cry1);
    usleep(delay);
    drawMatrix(cry2);
    usleep(delay);
    drawMatrix(cry3);
    usleep(delay);
    drawMatrix(cry4);
    usleep(delay);
    drawMatrix(cry5);
    usleep(delay);
    drawMatrix(cry6);
    usleep(delay);
}

/**
 * @param delay : vitesse de l'animation (si delay=100000, on attendra 0.1s entre chaque "frame")
 */
void loadingAnimation(long delay){
    drawMatrix(loading1);
    usleep(delay);
    drawMatrix(loading2);
    usleep(delay);
    drawMatrix(loading3);
    usleep(delay);
    drawMatrix(loading4);
    usleep(delay);
    drawMatrix(loading5);
    usleep(delay);
    drawMatrix(loading6);
    usleep(delay);
    drawMatrix(loading7);
    usleep(delay);
    drawMatrix(loading8);
    usleep(delay);
    drawMatrix(loading9);
    usleep(delay);
    drawMatrix(loading10);
    usleep(delay);
    drawMatrix(loading11);
    usleep(delay);
    drawMatrix(loading12);
    usleep(delay);
}

/**
 * @param delay : vitesse de l'animation (si delay=100000, on attendra 0.1s entre chaque "frame")
 */
void validateAnimation(long delay){
    drawMatrix(validate1);
    usleep(delay);
    drawMatrix(validate2);
    usleep(delay);
    drawMatrix(validate3);
    usleep(delay);
    drawMatrix(validate4);
    usleep(delay);
    drawMatrix(validate5);
    usleep(delay);
    drawMatrix(validate6);
}


/**
 * @param delay : vitesse de l'animation (si delay=100000, on attendra 0.1s entre chaque "frame")
 */
void dismissAnimation(long delay){
    drawMatrix(dismiss1);
    usleep(delay);
    drawMatrix(dismiss2);
    usleep(delay);
    drawMatrix(dismiss3);
    usleep(delay);
    drawMatrix(dismiss4);
    usleep(delay);
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
    maxTransfertData(MAX7219_DECODE_MODE, 0);
    maxTransfertData(MAX7219_BRIGHTNESS, 0);//Use lowest intensity
    maxTransfertData(MAX7219_SCAN_LIMIT, 7);//Scan all digit
    turnOnMatrice();
}
