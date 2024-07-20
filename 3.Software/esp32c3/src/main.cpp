#include <Arduino.h>
#include <ArduinoJson.h>
#include <WiFi.h>
#include "EPaper.h"
#include "SHT4xSensor.h"
#include "Weather.h"

SHT4xSensor sensor;
EPaper epaper;
void setup()
{
  Serial.begin(115200);

  epaper.init();

  if (!sensor.begin())
  {
    Serial.println("Sensor initialization failed!");
  }

  Serial.println("---Start---");
}

void loop()
{

  for (int i = 100; i < 106; i++)
  {
    char tempText[5];
    char humidityText[5];
    char weatherIconText[5];

    sensor.getTemperatureAndHumidityText(tempText, sizeof(tempText), humidityText, sizeof(humidityText), "%.1f");
    Serial.printf("Temperature: %s, Humidity: %s\n", tempText, humidityText);

    epaper.setTemperatureHumidity(tempText, humidityText);

    epaper.setWeatherIcon(getWeatherIcon(i, true));
    epaper.refreshDisplay();

    delay(10000); // 每10秒更新一次
  }
}
