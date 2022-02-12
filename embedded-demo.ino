/*
* CREATED BY: ETIENNE NAUDE - eti@naude.dev
* LINK FILES AND RUN AS MAIN
*
*/


#ifdef ENABLE_DEBUG
       #define DEBUG_ESP_PORT Serial
       #define NODEBUG_WEBSOCKETS
       #define NDEBUG
#endif 

#include <ESP8266WiFi.h>
#include <FastLED.h>
#include "SinricPro.h"
#include "SinricProLight.h"
#include "conf.h"

SinricProLight& Light = SinricPro[LIGHT_ID]; 

CRGB insideLeds[INNER_COUNT];                 
CRGB outerLeds[OUTER_NUM];              
int innerIndex = 0;             
int outerIndex = 0;             
bool powerState = true;         

void setup() {
  FastLED.addLeds<WS2812, INNER_PIN, GRB>(insideLeds, INNER_COUNT);
  FastLED.addLeds<WS2812, OUTER_PIN, GRB>(outerLeds, OUTER_NUM);

  setupWiFi();
  setupSinricPro(); 
}


void loop()
{

  if(powerState){
    // DRAW OUTSIDE TAIL
    for(int i = 0; i < OUTER_NUM; i++){
      outerLeds[(OUTER_NUM+i-outerIndex)%OUTER_NUM] = CHSV(200,255,255-(i*12));
    }
    outerIndex++;
    if(outerIndex > OUTER_NUM){outerIndex = 0;}

    // DRAW INSIDE TAIL
    for(int i = 0; i < INNER_COUNT; i++){
      insideLeds[(INNER_COUNT+i-innerIndex)%INNER_COUNT] = CHSV(170,255,255-(i*15));
    }
    innerIndex++;
    if(innerIndex > INNER_COUNT){innerIndex = 0;}


    FastLED.show();
    delay(50);
  } else {
    FastLED.clear();
    FastLED.show();
  }
  SinricPro.handle(); 
}


bool onPowerState(const String &deviceId, bool &state) {
  powerState = state;
  return true;
}

void setupWiFi() {
    WiFi.begin(WIFI_SSID, WIFI_PASS);
    while (WiFi.status() != WL_CONNECTED) {
        delay(250);
    }
}

void setupSinricPro() {
    Light.onPowerState(onPowerState);
    SinricPro.begin(APP_KEY, APP_SECRET);
}
