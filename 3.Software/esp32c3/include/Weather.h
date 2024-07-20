#ifndef WEATHER_H
#define WEATHER_H

#include <Arduino.h>
#include <stdint.h>

const char *getWeatherIconText(uint16_t id, bool fill);
const char *getWeekText(uint8_t week);

#endif