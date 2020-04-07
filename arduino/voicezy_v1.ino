#include <FastLED.h>

#define LED_PIN     10
#define NUM_LEDS    88

//code capteur bluetooth pour associer : 1234

char data[264];            //Variable for storing received data (bluetooth)
int i,p;
CRGB leds[NUM_LEDS];

void setup(){
    Serial.begin(9600);   //Sets the baud for serial data transmission                               
    pinMode(13, OUTPUT);  //Sets digital pin 13 as output pin
    for(int i=0;i<192;i++){
      data[i] = 0;
    }
    afficheDessin();
    i=0;
    FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
    FastLED.setBrightness(10);
}

void loop(){
   if(Serial.available() > 0)      // Send data only when you receive data:
   {
      data[i] = Serial.read();        //Read the incoming data & store into data
      incrementeI();
      Serial.println(1);
   }
}

void incrementeI(){
  i++;
  if (i>=264){
    i=0;
    afficheDessin();
  }
}

void afficheDessin(){
  for(int p=0;p<88;p++){
    allumeLed(p);
  }
  FastLED.show();
}

void allumeLed(int num){
  leds[num] = CRGB(data[num*3],data[num*3+1],data[num*3+2]);
}
