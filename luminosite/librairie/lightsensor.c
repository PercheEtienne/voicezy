//
// Created by etienne on 03/04/2020.
//

#include "lightsensor.h"


int getLuminositeEnLux()
{
    int handle = wiringPiI2CSetup(0x5C);
    //wiringPiI2CWrite(handle, 0x10); // Continously measurement at 1 lx resolution. Measurement Time is typically 120ms.
    wiringPiI2CWrite(handle, 0x21);   // One-time measurement at 0.5 lx resolution. Measurement Time is typically 120ms. It is automatically set to Power Down mode after measurement.
    sleep(1);
    int word = wiringPiI2CReadReg16(handle, 0x00);
    int lux = ((word & 0xff00)>>8) | ((word & 0x00ff)<<8);
    return lux;
}
