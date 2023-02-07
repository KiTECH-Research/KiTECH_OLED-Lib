#include "Arduino.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "KiTECH_OLED.h"

KiTECH_OLED::KiTECH_OLED() {}

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

bool KiTECH_OLED::setup() {
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
        Serial.println("SSD1306 allocation failed");
        for(;;);
        return false;
    }
    
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 5);
    return true;
}

bool KiTECH_OLED::nastav() {
    return setup();
}

void KiTECH_OLED::clear() {
    display.clearDisplay();
}

void KiTECH_OLED::vycisti() {
    clear();
}

void KiTECH_OLED::set_text_size(int s) {
    display.setTextSize(s);
}

void KiTECH_OLED::nastav_velkost_textu(int s) {
    set_text_size(s);
}

void KiTECH_OLED::print(String text) {
    display.print(text);
    display.display(); 
}

void KiTECH_OLED::vypis(String text) {
    print(text);
}

void KiTECH_OLED::set_cursor(int x, int y) {    
    display.setCursor(x,y);
}

void KiTECH_OLED::nastav_kurzor(int x, int y) {
    set_cursor(x, y);
}

void KiTECH_OLED::print_at(int x, int y, String text) {
    set_cursor(x, y);
    print(text);
}

void KiTECH_OLED::vypis_na_poziciu(int x, int y, String text) {
    print_at(x, y, text);
}

void KiTECH_OLED::draw_cloud(int x, int y) {
    // 'cloud', 43x25px
    const unsigned char cloud [] PROGMEM = {
        0x00, 0x00, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0x80, 
        0x00, 0x00, 0x00, 0x0f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x3f, 
        0xff, 0xe0, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0x80, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xc0, 0x00, 
        0x00, 0x3f, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xf0, 0x00, 0x00, 0xff, 0xff, 0xff, 
        0xf8, 0x00, 0x01, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x03, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x03, 0xff, 
        0xff, 0xff, 0xfc, 0x00, 0x07, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x07, 0xff, 0xff, 0xff, 0xfc, 0x00, 
        0x07, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x07, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x07, 0xff, 0xff, 0xff, 
        0xfc, 0x00, 0x07, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x03, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x03, 0xff, 
        0xff, 0xff, 0xf0, 0x00, 0x01, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0xff, 0xff, 0xff, 0xc0, 0x00, 
        0x00, 0x3f, 0xff, 0xfe, 0x00, 0x00
    };

    display.clearDisplay();
    display.drawBitmap(x, y, cloud, 43, 25, WHITE);
    
    display.display();
}

void KiTECH_OLED::draw_sun(int x, int y) {
    // 'sun', 30x30px
    const unsigned char sun [] PROGMEM = {
        0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 
        0x0c, 0x03, 0x00, 0x60, 0x0e, 0x03, 0x00, 0xc0, 0x07, 0x00, 0x01, 0x80, 0x03, 0x80, 0x03, 0x00, 
        0x01, 0x80, 0x06, 0x00, 0x00, 0x0f, 0xc0, 0x00, 0x00, 0x3f, 0xf0, 0x00, 0x00, 0x3f, 0xf0, 0x00, 
        0x00, 0x7f, 0xf8, 0x00, 0x00, 0x7f, 0xf8, 0x00, 0xfc, 0x7f, 0xf8, 0xfc, 0xfc, 0x7f, 0xf8, 0xfc, 
        0x00, 0x7f, 0xf8, 0x00, 0x00, 0x7f, 0xf8, 0x00, 0x00, 0x3f, 0xf0, 0x00, 0x00, 0x3f, 0xf0, 0x00, 
        0x00, 0x0f, 0xc0, 0x00, 0x00, 0xc0, 0x06, 0x00, 0x01, 0x80, 0x07, 0x00, 0x03, 0x00, 0x03, 0x80, 
        0x06, 0x03, 0x01, 0xc0, 0x0c, 0x03, 0x00, 0xc0, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 
        0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00
    };

    display.clearDisplay();
    display.drawBitmap(x, y, sun, 30, 30, WHITE);
    
    display.display();
}

void KiTECH_OLED::draw_cloudy_sun(int x, int y) {
    // 'cloudy-sun', 30x30px
    const unsigned char cloudy_sun [] PROGMEM = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 
        0x00, 0x00, 0x40, 0x20, 0x00, 0xc0, 0x40, 0x60, 0x00, 0x60, 0x40, 0xc0, 0x00, 0x30, 0x01, 0x80, 
        0x00, 0x18, 0x01, 0x00, 0x00, 0x03, 0xf8, 0x00, 0x00, 0x07, 0xfc, 0x00, 0x00, 0x07, 0xfc, 0x00, 
        0x00, 0x03, 0xfe, 0x00, 0x01, 0xf9, 0xfe, 0xfc, 0x03, 0xfc, 0xfe, 0x00, 0x07, 0xfc, 0x0e, 0x00, 
        0x07, 0xff, 0xc4, 0x00, 0x07, 0xff, 0xf0, 0x00, 0x07, 0xff, 0xf0, 0x00, 0x1f, 0xff, 0xf9, 0x00, 
        0x3f, 0xff, 0xf9, 0x80, 0x3f, 0xff, 0xf8, 0xc0, 0x3f, 0xff, 0xf8, 0x60, 0x3f, 0xff, 0xf8, 0x00, 
        0x3f, 0xff, 0xf8, 0x00, 0x3f, 0xff, 0xf0, 0x00, 0x0f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    display.clearDisplay();
    display.drawBitmap(x, y, cloudy_sun, 30, 30, WHITE);
    
    display.display();
}

void KiTECH_OLED::draw_rain(int x, int y) {
    // 'rain', 25x30px
    const unsigned char rain [] PROGMEM = {
        0x00, 0xf8, 0x00, 0x00, 0x03, 0xfe, 0x00, 0x00, 0x07, 0xff, 0x00, 0x00, 0x07, 0xff, 0x00, 0x00, 
        0x0f, 0xff, 0xf0, 0x00, 0x0f, 0xff, 0xfc, 0x00, 0x0f, 0xff, 0xfe, 0x00, 0x1f, 0xff, 0xfe, 0x00, 
        0x3f, 0xff, 0xff, 0x00, 0x7f, 0xff, 0xff, 0x00, 0x7f, 0xff, 0xff, 0x00, 0x7f, 0xff, 0xff, 0x00, 
        0x7f, 0xff, 0xff, 0x00, 0x7f, 0xff, 0xff, 0x00, 0x7f, 0xff, 0xfe, 0x00, 0x3f, 0xff, 0xfe, 0x00, 
        0x1f, 0xff, 0xfc, 0x00, 0x0f, 0xff, 0xf0, 0x00, 0x00, 0x08, 0x00, 0x00, 0x04, 0x08, 0x00, 0x00, 
        0x04, 0x08, 0x00, 0x00, 0x04, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x84, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x08, 0x04, 0x00, 0x00, 
        0x08, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00
    };

    display.clearDisplay();
    display.drawBitmap(x, y, rain, 30, 30, WHITE);
    
    display.display();
}

void KiTECH_OLED::draw_snow(int x, int y) {
    // 'snow', 25x30px
    const unsigned char snow [] PROGMEM = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x00, 0x00, 0x03, 0xfe, 0x00, 0x00, 0x07, 0xff, 0x00, 0x00, 
        0x0f, 0xff, 0x00, 0x00, 0x0f, 0xff, 0xf0, 0x00, 0x0f, 0xff, 0xfc, 0x00, 0x0f, 0xff, 0xfe, 0x00, 
        0x1f, 0xff, 0xff, 0x00, 0x3f, 0xff, 0xff, 0x00, 0x7f, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0x80, 
        0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0x00, 
        0x7f, 0xff, 0xff, 0x00, 0x7f, 0xff, 0xfe, 0x00, 0x3f, 0xff, 0xfc, 0x00, 0x07, 0xff, 0xc0, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x06, 0x04, 0x60, 0x00, 0x00, 0x0e, 0x60, 0x00, 
        0x00, 0xc4, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x0c, 0x01, 0x80, 0x00, 
        0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    display.clearDisplay();
    display.drawBitmap(x, y, snow, 30, 30, WHITE);
    
    display.display();
}

void KiTECH_OLED::draw_error(int x, int y) {
    // 'error', 30x30px
    const unsigned char error [] PROGMEM = {
        0x00, 0x1f, 0xe0, 0x00, 0x00, 0x7f, 0xf8, 0x00, 0x01, 0xe0, 0x1e, 0x00, 0x07, 0x80, 0x03, 0x80, 
        0x0e, 0x00, 0x01, 0xc0, 0x1c, 0x00, 0x00, 0xe0, 0x19, 0x00, 0x02, 0x60, 0x31, 0x80, 0x06, 0x30, 
        0x21, 0xc0, 0x0e, 0x10, 0x60, 0xe0, 0x1c, 0x18, 0x60, 0x70, 0x38, 0x18, 0xc0, 0x38, 0x70, 0x0c, 
        0xc0, 0x1c, 0xe0, 0x0c, 0xc0, 0x0f, 0xc0, 0x0c, 0xc0, 0x07, 0x80, 0x0c, 0xc0, 0x07, 0x80, 0x0c, 
        0xc0, 0x0f, 0xc0, 0x0c, 0xc0, 0x1c, 0xe0, 0x0c, 0xc0, 0x38, 0x70, 0x0c, 0x60, 0x70, 0x38, 0x18, 
        0x60, 0xe0, 0x1c, 0x18, 0x21, 0xc0, 0x0e, 0x10, 0x31, 0x80, 0x06, 0x30, 0x19, 0x00, 0x02, 0x60, 
        0x1c, 0x00, 0x00, 0xe0, 0x0e, 0x00, 0x01, 0xc0, 0x07, 0x00, 0x03, 0x00, 0x01, 0xe0, 0x1e, 0x00, 
        0x00, 0x7f, 0xf8, 0x00, 0x00, 0x1f, 0xe0, 0x00
    };

    display.clearDisplay();
    display.drawBitmap(x, y, error, 30, 30, WHITE);
    
    display.display();
}

void KiTECH_OLED::show_error_message(int errorLed, String message) {
    digitalWrite(errorLed, HIGH);
    delay(500);
    draw_error(49, 1);
    digitalWrite(errorLed, LOW);
    delay(500);
    clear();
    digitalWrite(errorLed, HIGH);
    delay(500);
    print_at(0, 0, message);
    digitalWrite(errorLed, LOW);
    delay(500);
    digitalWrite(errorLed, HIGH);
    delay(500);
    digitalWrite(errorLed, LOW);
    delay(500);
}
