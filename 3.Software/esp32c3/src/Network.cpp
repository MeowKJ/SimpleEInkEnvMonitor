#include "Network.h"

Network::Network(const char *ssid, const char *password)
    : _ssid(ssid), _password(password) {}

bool Network::connect(uint16_t timeout)
{
    WiFi.begin(_ssid, _password);
    Serial.print("Connecting to WiFi");

    unsigned long startTime = millis();

    while (WiFi.status() != WL_CONNECTED)
    {
        if (millis() - startTime >= timeout)
        {
            Serial.println("Connection timed out");
            return false;
        }
        delay(500);
        Serial.print(".");
    }

    Serial.println("Connected!");
    return true;
}

void Network::disconnect()
{
    WiFi.disconnect();
}

String Network::httpGet(const char *url)
{
    if (WiFi.status() == WL_CONNECTED)
    {
        HTTPClient http;
        http.begin(url);
        int httpCode = http.GET();
        String payload = "";

        if (httpCode > 0)
        {
            payload = http.getString();
        }
        else
        {
            Serial.printf("HTTP GET failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();
        return payload;
    }
    else
    {
        Serial.println("WiFi not connected");
        return "";
    }
}

String Network::getWeatherData(const char *apiKey, const char *cityCode)
{
    String url = String("https://api.seniverse.com/v3/weather/now.json?key=") + apiKey + "&location=" + cityCode + "&language=zh-Hans&unit=c";
    Serial.println("Requesting weather data");
    Serial.println(url);
    return httpGet(url.c_str());
}

uint16_t Network::getWeatherIcon(const char *apiKey, const char *cityCode)
{
    String weatherData = getWeatherData(apiKey, cityCode);

    // Serial.println("Weather Data:");
    // Serial.println(weatherData);

    // 检查获取的数据是否包含 "code"
    int iconIndex = weatherData.indexOf("\"code\":\"");

    if (weatherData == "" || iconIndex == -1)
    {
        return 99;
    }
    // 解析天气数据，获取天气图标代码
    int iconStartIndex = iconIndex + 8; // "code":" 的长度是 8
    int iconEndIndex = weatherData.indexOf("\"", iconStartIndex);

    String iconCodeStr = weatherData.substring(iconStartIndex, iconEndIndex);

    uint16_t iconCode = iconCodeStr.toInt();
    return iconCode;
}
