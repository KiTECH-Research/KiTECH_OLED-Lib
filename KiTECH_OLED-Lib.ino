#include "KiTECH_OLED.h"

KiTECH_OLED oled;

int errorLed = 4;

void setup() {
    Serial.begin(9600);

    pinMode(errorLed, OUTPUT);

    if (oled.setup()) {
        oled.print("setup OK");
    } else {
        oled.print("setup FAIL");
    }
}

void loop() {
  
  oled.draw_cloud(0, 0);
  delay(1000);
  oled.clear();
  
  oled.draw_sun(0, 0);
  delay(1000);
  oled.clear();
  
  oled.draw_cloudy_sun(0, 0);
  delay(1000);
  oled.clear();
  
  oled.draw_rain(0, 0);
  delay(1000);
  oled.clear();
  
  oled.draw_snow(0, 0);
  delay(1000);
  oled.clear();
  
  oled.draw_error(0, 0);
  delay(1000);
  oled.clear();
  
  //oled.show_error_message(errorLed, "Error pri citani teploty");
}
