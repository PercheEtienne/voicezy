//
// Created by clement on 28/03/20.
//

#include "temperature.h"

/**
 *
 * @param temperature : variable qui contiendra la temperature
 * @param humidite : variable qui contiendra l'humidite
 * @return 1 si OK, 0 sinon
 */
char read_temperature_(float *temperature, float *humidite){

    uint8_t laststate	= HIGH;
    uint8_t counter		= 0;
    uint8_t j		= 0, i;
    int try_count = 0;
    float	f;

    dht11_dat[0] = dht11_dat[1] = dht11_dat[2] = dht11_dat[3] = dht11_dat[4] = 0;

    pinMode( DHTPIN, OUTPUT );
    digitalWrite( DHTPIN, LOW );
    delay( 18 );
    digitalWrite( DHTPIN, HIGH );
    delayMicroseconds( 40 );
    pinMode( DHTPIN, INPUT );

    for ( i = 0; i < MAXTIMINGS; i++ )
    {
        counter = 0;
        while ( digitalRead( DHTPIN ) == laststate )
        {
            counter++;
            delayMicroseconds( 1 );
            if ( counter == 255 )
            {
                break;
            }
        }
        laststate = digitalRead( DHTPIN );

        if ( counter == 255 )
            break;

        if ( (i >= 4) && (i % 2 == 0) )
        {
            dht11_dat[j / 8] <<= 1;
            if ( counter > 50 )
                dht11_dat[j / 8] |= 1;
            j++;
        }
    }

    if ( (j >= 40) && (dht11_dat[4] == ( (dht11_dat[0] + dht11_dat[1] + dht11_dat[2] + dht11_dat[3]) & 0xFF) ) ) {
        f = dht11_dat[2] * 9. / 5. + 32;
        printf( "Humidity = %d.%d %% Temperature = %d.%d C (%.1f F)\n", dht11_dat[0], dht11_dat[1], dht11_dat[2], dht11_dat[3], f );
        *temperature = dht11_dat[2] + ((float)dht11_dat[3])/10;
        *humidite = dht11_dat[0] + ((float)dht11_dat[1])/10;
        return 1;
    }else  {
        return 0;
    }
}

/**
 *
 * @param temperature : variable qui contiendra la temperature
 * @param humidite : variable qui contiendra l'humidite
 * @return 1 si OK, 0 sinon
 */
char read_temperature(float *temperature, float *humidite){
    int i=0;

    while (i<MAX_TRY){
        i++;
        if (read_temperature_(temperature,humidite))
            return 1;
        delay(100);
        i++;
    }

    return 0;

}