//
// Created by clement on 04/04/20.
//

#include "meteo.h"
#include "../parseMeteo/librairie/parseMeteo.c"

void init_string(struct string *s) {
    s->len = 0;
    s->ptr = malloc(s->len+1);
    if (s->ptr == NULL) {
        fprintf(stderr, "malloc() failed\n");
        exit(EXIT_FAILURE);
    }
    s->ptr[0] = '\0';
}

/**
 * Sert à récupérer la réponse de la requête en char * plutôt qu'en CURLcode
 * @param ptr
 * @param size
 * @param nmemb
 * @param s
 * @return
 */
size_t writefunc(void *ptr, size_t size, size_t nmemb, struct string *s)
{
    size_t new_len = s->len + size*nmemb;
    s->ptr = realloc(s->ptr, new_len+1);

    if (s->ptr == NULL) {
        fprintf(stderr, "realloc() failed\n");
        exit(EXIT_FAILURE);
    }

    memcpy(s->ptr+s->len, ptr, size*nmemb);
    s->ptr[new_len] = '\0';
    s->len = new_len;

    return size*nmemb;
}

/**
 * Recupere la météo avec l'API à Lille
 * @param temp, l'adresse de la variable qui comprendra la température en kelvin
 * @param state, l'adresse de la variable qui comprendra le "state" de la météo (ex : sun)
*/
void recupereLaMeteo(char *temp, char *state){

    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();

    if(curl) {
        struct string s;
        init_string(&s);

        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &s);
        curl_easy_setopt(curl, CURLOPT_URL, requete);

#ifdef SKIP_HOSTNAME_VERIFICATION
        /*
             * If the site you're connecting to uses a different host name that what
             * they have mentioned in their server certificate's commonName (or
             * subjectAltName) fields, libcurl will refuse to connect. You can skip
             * this check, but this will make the connection less secure.
             */
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
#endif

        /* Perform the request, res will get the return code */
        res = curl_easy_perform(curl);
        /* Check for errors */
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));

        char *state_ = infoMeteo(s.ptr);
        char *temp_ = infoTempEnKelvin(s.ptr);

        strcpy(temp,temp_);
        strcpy(state,state_);

        /* always cleanup */
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
}