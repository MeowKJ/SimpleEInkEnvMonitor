#ifndef EPAPER_H
#define EPAPER_H

#include "GxEPD2_3C.h"
#include <U8g2_for_Adafruit_GFX.h>
#include <CustomFont.h>

class EPaper
{
public:
    void init();
    void displayTemperatureHumidity(const char *tempText, const char *humidityText);

private:
    U8G2_FOR_ADAFRUIT_GFX u8g2Fonts;
    void drawBitmap();
};

#endif // EPAPER_H
