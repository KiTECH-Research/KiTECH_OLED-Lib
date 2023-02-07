#ifndef KiTECH_OLED_h
#define KiTECH_OLED_h

#include "Arduino.h"

/*
bool d_setup();
bool d_nastav();
void d_print(String text);
void d_vypis(String text);
void d_print_at(int x, int y, String text);
void d_vypis_na_poziciu(int x, int y, String text);
void d_set_cursor(int x, int y);
void d_nastav_kurzor(int x, int y);
void d_clear();
void d_vycisti();

*/
class KiTECH_OLED
{
private:

public:
    KiTECH_OLED();
    //KiTECH_OLED(int textSize);
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

    void draw_cloud();
    void draw_sun();
    void draw_cloudy_sun();
    void draw_rain();
    void draw_snow();
};

#endif
