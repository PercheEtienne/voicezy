//
// Created by clement on 05/04/20.
//

#include "../library/firebase.c"

int main(){
    char ss[10] = "182.6";
    printf("Float value : %4.8f\n",strtod(ss,NULL));
    float temp_float = strtod(ss,NULL);
    temp_float -= 273.15;
    sendTemperatureToFirebase(temp_float);
}