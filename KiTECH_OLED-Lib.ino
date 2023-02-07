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
    oled.show_error_message(errorLed, "Error pri citani teploty");
}
