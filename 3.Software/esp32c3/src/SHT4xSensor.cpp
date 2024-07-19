#include "SHT4xSensor.h"

SHT4xSensor::SHT4xSensor() : sht4() {}

bool SHT4xSensor::begin()
{
    if (!sht4.begin())
    {
        Serial.println("Couldn't find SHT4x");
        return false;
    }
    Serial.println("Found SHT4x sensor");

    sht4.setPrecision(SHT4X_HIGH_PRECISION);
    sht4.setHeater(SHT4X_NO_HEATER);
    return true;
}

void SHT4xSensor::getTemperatureAndHumidity(sensors_event_t *humidity, sensors_event_t *temp)
{
    sht4.getEvent(humidity, temp);
}
