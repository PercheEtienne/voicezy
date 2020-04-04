//
// Created by clement on 04/04/20.
//

#include "../library/meteo.c"

int main(){

    char temp[10];
    char state[50];
    recupereLaMeteo(temp,state);

    printf("%s | %s\n",temp,state);

}