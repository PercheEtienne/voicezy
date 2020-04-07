//
// Created by clement on 06/04/20.
//

#include "voicezy_v2.h"

void initialisation(){

    wiringPiSetup();//On init WiringPi

    initMax7219();//On init le Max7219

    init_recognition();

    drawMatrix(blackScreen);
}

void* loading_anim(){
    while (1) {
        loadingAnimation(LOADING_ANIMATION_SPEED);
    }
}

void* loading_anim2(){
    while (1) {
        loadingAnimation2(LOADING2_ANIMATION_SPEED);
    }
}

void* dismiss_anim(){
    dismissAnimation(DISMISS_ANIMATION_SPEED);
    sleep(1);
    drawMatrix(blackScreen);
    pthread_exit(0);
}

void* success_anim(){
    validateAnimation(VALIDATE_ANIMATION_SPEED);
    sleep(1);
    loading_anim2();
}

void afficheMeteoMatrice(){
    char state[50];
    char temp[10];

    recupereLaMeteo(temp,state);

    float temp_float = strtod(temp,NULL);
    temp_float -= 273.15; //conversion kelvin en degré
    sendTemperatureToFirebase(temp_float);

    printf("Connect to arduino\n");
    int s = connectToArduino();

    if (strcmp("Thunderstorm", state) == 0)
        drawEclairOnArduino(s);
    else if (strcmp("Drizzle", state) == 0 || strcmp("Rain", state) == 0)
        drawPluieOnArduino(s);
    else if (strcmp("Snow", state) == 0)
        drawNeigeOnArduino(s);
    else if (strcmp("Clear", state) == 0)
        drawSoleilOnArduino(s);
    else
        drawNuageOnArduino(s);

    printf("Disconnect from Arduino\n");
    disconnectFromArduino(s);
}

void luminosity(){

    int luminosity;

    luminosity=getLuminositeEnLux();

    sendLuminosityToFirebase(luminosity);
}

void humidity(){

    float humidite,temp;

    if (read_temperature(&temp,&humidite))
        sendHumidityToFirebase(humidite);
    else
        printf("ERROR HUMIDITY READ\n");
}

void temperature(){

    float temp,humidite;

    if (read_temperature(&temp,&humidite))
        sendLocalTemperatureToFirebase(temp);
    else
        printf("ERROR TEMPERATURE READ\n");
}

void allumeLumiere(){

    struct sockaddr_rc addr = {0};
    int s, status,p,bytes_read,c,d;
    char buf[1024] = {0};

    // allocate a socket
    s = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);

    // set the connection parameters (who to connect to)
    addr.rc_family = AF_BLUETOOTH;
    addr.rc_channel = (uint8_t) 1;

    str2ba( dest, &addr.rc_bdaddr );

    // connect to server
    status = connect(s, (struct sockaddr *)&addr, sizeof(addr));

    // send a message
    if( status == 0 ) {
        for(p=0;p<11;p++){
            for(c=0;c<8;c++){
                for(d=0;d<3;d++) {
                    status = write(s, &light[c][p][d], 1);
                    bytes_read = read(s, buf, sizeof(buf));
                    if (bytes_read <= 0) {
                        printf("ERROR\n");
                        p--;
                    }
                }
            }
        }
    }

    if( status < 0 )
        perror("uh oh");

    close(s);
}

void eteindLumiere(){
    struct sockaddr_rc addr = {0};
    int s, status,p,bytes_read,c,d;
    char buf[1024] = {0};

    // allocate a socket
    s = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);

    // set the connection parameters (who to connect to)
    addr.rc_family = AF_BLUETOOTH;
    addr.rc_channel = (uint8_t) 1;

    str2ba( dest, &addr.rc_bdaddr );

    // connect to server
    status = connect(s, (struct sockaddr *)&addr, sizeof(addr));

    // send a message
    if( status == 0 ) {
        for(p=0;p<11;p++){
            for(c=0;c<8;c++){
                for(d=0;d<3;d++) {
                    status = write(s, &blackScreen_[c][p][d], 1);
                    bytes_read = read(s, buf, sizeof(buf));
                    if (bytes_read <= 0) {
                        printf("ERROR\n");
                        p--;
                    }
                }
            }
        }
    }

    if( status < 0 )
        perror("uh oh");

    close(s);
}

int main() {
    int i;
    pthread_t th;

    initialisation();

    while (1){

        printf("Vous pouvez parler!\n");

        waitForButtonAndEnregistreSound();

        pthread_create(&th, NULL, loading_anim, NULL);

        int cmd = recherche_Ordre(audio_recognition_function("enregistrement.wav"));

        pthread_cancel(th);

        if (cmd != 0)
            pthread_create(&th, NULL, success_anim, NULL);
        else
            pthread_create(&th, NULL, dismiss_anim, NULL);

        switch (cmd) {
            case 1 :
                printf("Je lance la commande météo\n");
                afficheMeteoMatrice();
                break;
            case 2 :
                printf("Je lance la commande luminosity\n");
                luminosity();
                break;
            case 3 :
                printf("Je lance la commande temperature\n");
                temperature();
                break;
            case 4 :
                printf("Je lance la commande allume lumière\n");
                allumeLumiere();
                break;
            case 5 :
                printf("Je lance la commande éteind lumière\n");
                eteindLumiere();
                break;
            case 6 :
                printf("Je lance la commande humidity\n");
                humidity();
                break;
            case 7 :
                printf("Je lance la commande play Mario\n");
                playMario();
                break;
        }

        if (cmd == 0) // si c'est l'animation DISMISS, on attend qu'elle se finisse
            pthread_join(th, NULL);
        else { //Sinon on arrete l'animation de chargement 2
            pthread_cancel(th);
            drawMatrix(blackScreen);
        }

    }
}