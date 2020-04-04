//
// Created by clement on 04/04/20.
//

#ifndef RPI_METEO_H
#define RPI_METEO_H

#endif //RPI_METEO_H

#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

struct string {
    char *ptr;
    size_t len;
};

char apiKey[] = "200587bf864d1e6503f14f9c60c864fb";
char requete[] = "https://api.openweathermap.org/data/2.5/weather?q=Lille&appid=200587bf864d1e6503f14f9c60c864fb";

void recupereLaMeteo(char *temp, char * state);
