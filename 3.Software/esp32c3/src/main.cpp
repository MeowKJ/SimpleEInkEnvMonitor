#include <Arduino.h>

#include "EPaper.h"
#include "SHT4xSensor.h"

SHT4xSensor sensor;
EPaper epaper;
void setup()
{
  Serial.begin(115200);
  while (!Serial)
    delay(10);

  epaper.init();

  if (!sensor.begin())
  {
    while (1)
    {
      Serial.println("Sensor initialization failed!");
      delay(1);
    }
  }
}

void loop()
{
  sensors_event_t humidity, temp;
  sensor.getTemperatureAndHumidity(&humidity, &temp);

  char tempText[10];
  char humidityText[10];

  snprintf(tempText, sizeof(tempText), "%.1f", temp.temperature);
  snprintf(humidityText, sizeof(humidityText), "%.1f%", humidity.relative_humidity);

  epaper.displayTemperatureHumidity(tempText, humidityText);

  delay(10000); // 每10秒更新一次
}
