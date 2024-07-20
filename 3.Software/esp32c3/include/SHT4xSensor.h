#ifndef SHT4X_SENSOR_H
#define SHT4X_SENSOR_H

#include <Arduino.h>
#include "Adafruit_SHT4x.h"

class SHT4xSensor
{
public:
    SHT4xSensor();
    bool init();
    void getTemperatureAndHumidity(sensors_event_t *humidity, sensors_event_t *temp);
    void getTemperatureAndHumidityText(char *tempText, size_t tempTextSize, char *humidityText, size_t humidityTextSize, const char *format);

private:
    Adafruit_SHT4x sht4;
};

#endif // SHT4X_SENSOR_H
