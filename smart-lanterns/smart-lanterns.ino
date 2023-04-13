/*
* CREATED BY: ETIENNE NAUDE - eti@naude.dev
* LINK FILES AND RUN AS MAIN
*
*
* the main file to edit is conf.h this is only for extra editing outside teh scope of the workshop
*/


#ifdef ENABLE_DEBUG
       #define DEBUG_ESP_PORT Serial
       #define NODEBUG_WEBSOCKETS
       #define NDEBUG
#endif

#include <ESP8266WiFi.h>
#include "SinricPro.h"
#include "SinricProLight.h"
#include "conf.h"
#include "patterns.h"


SinricProLight& Light = SinricPro[LIGHT_ID];
bool powerState = true;

void setup() {
  setupLeds();

  setupWiFi();
  setupSinricPro();
}

void loop()
{
  if(powerState){
    drawPattern();
  } else {
    clearLeds();
  }
  SinricPro.handle();
}


bool onPowerState(const String &deviceId, bool &state) {
  powerState = state;
  return true;
}

bool onBrightness(const String& deviceId, int& brightness) {
    FastLED.setBrightness(brightness);
    return true;
}

bool onAdjustBrightness(const String& deviceId, int& brightnessDelta) {
    FastLED.setBrightness(FastLED.getBrightness() + brightnessDelta);
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
    Light.onBrightness(onBrightness);
    Light.onAdjustBrightness(onAdjustBrightness);
    SinricPro.begin(APP_KEY, APP_SECRET);
}
