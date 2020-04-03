//
// Created by etienne on 22/03/2020.
//

#include "parseMeteo.h"

char *substr(char *src,int pos,int len) {
    char *dest=NULL;
    if (len>0) {
        /* allocation et mise à zéro */
        dest = calloc(len+1, 1);
        /* vérification de la réussite de l'allocation*/
        if(NULL != dest) {
            strncat(dest,src+pos,len);
        }
    }
    return dest;
}

/**
*	On parse la chaine pour récuperer l'information dans le champ main
* 'm' a sa premiere ocurrence de la chaine reponse dans le mot main, donc a partir de la
*/
char* infoMeteo(char* string)
{
    char* result;
    char str[128];

    sscanf(string,"%[^m]",str);
    result = substr(string,strlen(str)+7,15);
    int lg = strlen(result);
    int maxI;
    int i;
    for (i=0;i<lg;i++){
        if(result[i] == '\"')
        {
            maxI=i;
            break;
        }
    }

    char* meteo;
    meteo = substr(result,0,maxI);
    return meteo;
}

/**
*	On cherche le premier '_' (7 caracteres avant la valeur de la temp) et en suite on extrait la valeur temperature
*/
char* infoTempEnKelvin(char * string)
{
    char* result;
    char str[256];
    sscanf(string,"%[^_]",str);

    int lg = strlen(str);
    str[lg-7] = '\0';

    char* temp;
    temp = substr(str,lg-13,6);

    return temp;
}

