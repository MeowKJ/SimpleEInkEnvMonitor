#include <Arduino.h>
#include <ArduinoJson.h>
#include <WiFi.h>
#include "EPaper.h"
#include "SHT4xSensor.h"

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
  char tempText[10];
  char humidityText[10];
  sensor.getTemperatureAndHumidityText(tempText, sizeof(tempText), humidityText, sizeof(humidityText), "%.1f");
  epaper.displayTemperatureHumidity(tempText, humidityText);

  delay(10000); // 每10秒更新一次
}
