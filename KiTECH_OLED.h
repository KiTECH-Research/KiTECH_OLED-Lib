#ifndef KiTECH_OLED_h
#define KiTECH_OLED_h

#include "Arduino.h"

class KiTECH_OLED
{
private:

public:
    KiTECH_OLED();
    bool setup();
    bool nastav();
    void print(String text);
    void vypis(String text);
    void print_at(int x, int y, String text);
    void vypis_na_poziciu(int x, int y, String text);
    void set_cursor(int x, int y);
    void nastav_kurzor(int x, int y);
    void clear();
    void vycisti();
    void set_text_size(int s);
    void nastav_velkost_textu(int s);
    void show_error_message(int errorLed, String message);

    String int_to_str(int n);
    String float_to_str(float n);

    // KiTECH Weather
    void draw_cloud(int x, int y);
    void draw_sun(int x, int y);
    void draw_cloudy_sun(int x, int y);
    void draw_rain(int x, int y);
    void draw_snow(int x, int y);
    void draw_error(int x, int y);
    void print_weather_icon(float t, bool rain, int clouds, int x, int y);
    void print_weather_info(float value, String description, String unit, int x, int y);
    void print_full_weather_info(float t, String tDesc, String tUnit, float h, String hDesc, String hUnit, float p, String pDesc, String pUnit, int x, int y, bool rain, int clouds, int iconX, int iconY);

    //KiTECH Lights
    void print_rgb_values(int r, int g, int b);
};

#endif
