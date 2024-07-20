#ifndef WEATHER_H
#define WEATHER_H

#include <Arduino.h>
#include <stdint.h>

const char *getWeatherIcon(uint16_t id, bool fill);

#endif