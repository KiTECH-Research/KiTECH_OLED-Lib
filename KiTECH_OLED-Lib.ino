#include "KiTECH_OLED.h"

KiTECH_OLED oled;

int errorLed = 4;

void setup() {
    Serial.begin(9600);

    pinMode(errorLed, OUTPUT);

    if (oled.setup()) {
        oled.print("setup OK");
    }
    oled.clear();
}

void loop() {
    //oled.print_full_weather_info(-7.23, "Teplota", "*C", 25, "Vlhkost", "%", 125, "Tlak", "kPa", 40, 5, true, 2, 5, 5);
    //oled.show_error_message(errorLed, "Error pri citani teploty");
    oled.print_rgb_values(123, 234, 12);
}
