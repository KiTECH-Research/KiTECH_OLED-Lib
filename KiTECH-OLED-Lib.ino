#include "KiTECH_OLED.h"

KiTECH_OLED oled;

void setup() {
    Serial.begin(9600);

    if (oled.setup()) {
        oled.print("setup OK");
    } else {
        oled.print("setup FAIL");
    }

    oled.draw_snow();
}

void loop() {
    
}
