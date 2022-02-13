#include "conf.h"
#include <FastLED.h>

int ledIndex = 0;
CRGB insideLeds[LED_COUNT]; 

void setupLeds(){
  FastLED.addLeds<WS2812, LED_PIN, GRB>(insideLeds, LED_COUNT);
}

void clearLeds(){
  FastLED.clear();
  FastLED.show();
}


void drawTrail(){
 for(int i = 0; i < LED_COUNT; i++){
    insideLeds[(LED_COUNT+i-ledIndex)%LED_COUNT] = CHSV(HUE,255,255-(i*5));
  }
  ledIndex++;
  if(ledIndex >= LED_COUNT){ledIndex = 0;}
  delay(50);
}

void drawRainbow(){
 for(int i = 0; i < LED_COUNT; i++){
    insideLeds[(LED_COUNT+i-ledIndex)%LED_COUNT] = CHSV(255-(i*5),255,255);
  }
  ledIndex++;
  if(ledIndex >= LED_COUNT){ledIndex = 0;}
  delay(50);
}

void drawColour(){
 for(int i = 0; i < LED_COUNT; i++){
    insideLeds[i] = CHSV(HUE,255,255);
  }
  delay(200);
}


void drawPattern(){

  switch(PATTERN){
    case 0:
      drawTrail();
    case 1:
      drawRainbow();
      break;
    case 2:
      drawColour();
      break;
  }

  FastLED.show();
}

