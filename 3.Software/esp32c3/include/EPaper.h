#ifndef EPAPER_H
#define EPAPER_H

#include "U8g2_for_Adafruit_GFX.h"
#include "CustomFonts.h"
class EPaper
{
public:
    void init();
    void setTemperatureHumidity(const char *tempText, const char *humidityText);
    void setWeatherIcon(const char *iconText);
    void setWeek(const char *week);
    void refreshDisplay();

private:
    U8G2_FOR_ADAFRUIT_GFX u8g2Fonts;
    const char *temperatureText;
    const char *humidityText;
    const char *weatherIconText;
    const char *weekText;
};

#endif // EPAPER_H
