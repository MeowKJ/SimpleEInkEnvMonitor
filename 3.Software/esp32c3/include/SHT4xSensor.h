#ifndef SHT4X_SENSOR_H
#define SHT4X_SENSOR_H

#include <Arduino.h>
#include "Adafruit_SHT4x.h"

class SHT4xSensor
{
public:
    SHT4xSensor();
    bool begin();
    void getTemperatureAndHumidity(sensors_event_t *humidity, sensors_event_t *temp);

private:
    Adafruit_SHT4x sht4;
};

#endif // SHT4X_SENSOR_H
