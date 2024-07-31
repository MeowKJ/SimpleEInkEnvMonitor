#include <Arduino.h>
#include <ArduinoJson.h>
#include <WiFi.h>
#include <time.h>
#include <esp_sleep.h>
#include <driver/rtc_io.h> // 需要引入此库来使用rtc_gpio_deinit

#include "EPaper.h"
#include "SHT4xSensor.h"
#include "Weather.h"
#include "Network.h"

#include "config.h"

#define BUTTON_PIN_A GPIO_NUM_0 // 按键连接到GPIO 0
#define BUTTON_PIN_B GPIO_NUM_9 // 按键连接到GPIO 9

// 实例化传感器、EPaper 和网络类
SHT4xSensor sensor;
EPaper epaper;

RTC_DATA_ATTR char tempText[8];
RTC_DATA_ATTR char humidityText[8];
RTC_DATA_ATTR char weatherIconText[8];
RTC_DATA_ATTR char weekText[32];
RTC_DATA_ATTR unsigned long lastWeatherUpdate = 0; // 上次天气和时间更新的时间戳（秒）

bool updateWeather()
{
  Network network(WIFI_SSID, WIFI_PASSWORD);

  if (!network.connect(WIFI_CONNECT_TIMEOUT))
  {
    Serial.println("WiFi connection failed");
    return false;
  }

  // 使用 NTP 服务器初始化时间
  struct tm timeinfo;
  configTime(GMT_OFFSET_SEC, DAYLIGHT_OFFSET_SEC, NTP_SERVER);

  if (getLocalTime(&timeinfo))
  {
    uint8_t week = timeinfo.tm_wday; // 获取星期几（0-6，0代表星期天）
    strcpy(weekText, getWeekText(week));
    Serial.println("Successfully obtained time");
  }
  else
  {
    Serial.println("Failed to obtain time");
  }
  network.disconnect();

  // 更新墨水屏天气图标
  uint16_t weatherIconId = network.getWeatherIcon(WEATHER_API_KEY, WEATHER_LOCATION);
  Serial.printf("Weather Code: %d\n", weatherIconId);
  strcpy(weatherIconText, getWeatherIconText(weatherIconId, false));

  return true;
}

void updateSensor()
{
  sensor.getTemperatureAndHumidityText(tempText, sizeof(tempText), humidityText, sizeof(humidityText), "%.1f");
  Serial.printf("Temperature: %s, Humidity: %s\n", tempText, humidityText);
  epaper.setTemperatureHumidity(tempText, humidityText);
}

void setup()
{
  // 初始化串口
  Serial.begin(115200);

  // 配置按键唤醒
  // esp_sleep_pd_config(ESP_PD_DOMAIN_RTC_PERIPH, ESP_PD_OPTION_ON);
  esp_deep_sleep_enable_gpio_wakeup(BUTTON_PIN_A, ESP_GPIO_WAKEUP_GPIO_HIGH);

  // 初始化墨水屏
  epaper.init();

  // 初始化传感器
  sensor.init();

  // 判断是否需要连接 WiFi 更新天气和时间
  unsigned long currentTime = time(nullptr);
  if (currentTime < lastWeatherUpdate || (currentTime - lastWeatherUpdate) >= WEATHER_UPDATE_INTERVAL || lastWeatherUpdate == 0)
  {
    // 更新天气和时间
    updateWeather();
    lastWeatherUpdate = time(nullptr);
  }

  // 更新传感器数据
  epaper.setWeek(weekText); // 设置墨水屏显示星期几
  epaper.setWeatherIcon(weatherIconText);
  updateSensor();

  // 刷新墨水屏显示
  epaper.refreshDisplay();

  // 配置深度睡眠
  // gpio_deep_sleep_hold_dis(); // 在深度睡眠时禁用所有数字gpio pad保持功能。
  // esp_deep_sleep_enable_gpio_wakeup(BIT(BUTTON_PIN_A), ESP_GPIO_WAKEUP_GPIO_LOW);
  // gpio_set_direction(BUTTON_PIN_A, GPIO_MODE_INPUT);  // GPIO定向，设置为输入或输出
  // gpio_set_pull_mode(BUTTON_PIN_A, GPIO_PULLUP_ONLY); // GPIO上拉模式，设置为上拉、下拉或浮空
  esp_sleep_enable_timer_wakeup(DISPLAY_UPDATE_INTERVAL);
  esp_deep_sleep_start();
}

void loop()
{
  // ESP32 进入深度睡眠后不会执行此函数
}
