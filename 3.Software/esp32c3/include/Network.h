#ifndef NETWORK_H
#define NETWORK_H

#include <WiFi.h>
#include <HTTPClient.h>

class Network
{
public:
    Network(const char *ssid, const char *password);
    bool connect(uint16_t timeout);
    void disconnect();
    String getWeatherData(const char *apiKey, const char *cityCode);
    uint16_t getWeatherIcon(const char *apiKey, const char *cityCode);

private:
    const char *_ssid;
    const char *_password;
    String httpGet(const char *url);
    String decompressGzip(const uint8_t *compressedData, size_t compressedSize);
};

#endif // NETWORK_H
