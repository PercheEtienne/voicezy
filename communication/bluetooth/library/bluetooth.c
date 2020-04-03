//
// Created by clement on 03/04/20.
//

#include "bluetooth.h"

int connectToArduino(){

    struct sockaddr_rc addr = {0};
    int s, status;
    char dest[18] = "00:12:05:11:94:92";
    char buf[1024] = {0};

    s = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);

    // set the connection parameters (who to connect to)
    addr.rc_family = AF_BLUETOOTH;
    addr.rc_channel = (uint8_t) 1;

    str2ba( dest, &addr.rc_bdaddr );

    // connect to server
    status = connect(s, (struct sockaddr *)&addr, sizeof(addr));

    return s;
}

void drawSoleilOnArduino(int s){

    char buf[1024] = {0};
    int bytes_read,d,c,p,status;

    // send a message
    if( status == 0 ) {
        for(p=0;p<11;p++){
            for(c=0;c<8;c++){
                for(d=0;d<3;d++) {
                    status = write(s, &soleil[c][p][d], 1);
                    bytes_read = read(s, buf, sizeof(buf));
                    if (bytes_read <= 0) {
                        printf("ERROR\n");
                        p--;
                    }
                }
            }
        }
    }
}

void drawNuageOnArduino(int s){

    char buf[1024] = {0};
    int bytes_read,d,c,p,status;

    // send a message
    if( status == 0 ) {
        for(p=0;p<11;p++){
            for(c=0;c<8;c++){
                for(d=0;d<3;d++) {
                    status = write(s, &nuage[c][p][d], 1);
                    bytes_read = read(s, buf, sizeof(buf));
                    if (bytes_read <= 0) {
                        printf("ERROR\n");
                        p--;
                    }
                }
            }
        }
    }
}



void disconnectFromArduino(int s){
    close(s);
}