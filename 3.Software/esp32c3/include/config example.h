#ifndef CONFIG_H
#define CONFIG_H

// Wi-Fi credentials
#define WIFI_SSID "your_SSID"         // Your WiFi SSID
#define WIFI_PASSWORD "your_PASSWORD" // Your WiFi password

// NTP server configuration
#define NTP_SERVER "pool.ntp.org" // NTP server
#define GMT_OFFSET_SEC 8 * 3600   // Beijing Time zone offset in seconds (UTC+8)
#define DAYLIGHT_OFFSET_SEC 0     // Daylight saving time offset in seconds (no DST in Beijing)

#define USE_HEWEATHER

#ifdef USE_HEWEATHER
// HeWeather API configuration
#define HEWEATHER_API_KEY "your_heweather_api_key" // Your HeWeather API key
#define HEWEATHER_LOCATION "your_location"         // Your location (city ID or name)

#endif

#endif
