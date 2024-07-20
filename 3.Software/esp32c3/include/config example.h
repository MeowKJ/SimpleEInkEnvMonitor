#ifndef CONFIG_H
#define CONFIG_H

// Wi-Fi 配置信息
#define WIFI_SSID "SSID"         // 你的 WiFi SSID
#define WIFI_PASSWORD "PASSWORD" // 你的 WiFi 密码

// NTP 服务器配置
#define NTP_SERVER "ntp.aliyun.com" // NTP 服务器地址
#define GMT_OFFSET_SEC 8 * 3600     // 北京时间的时区偏移量（以秒为单位，UTC+8）
#define DAYLIGHT_OFFSET_SEC 0       // 夏令时的时区偏移量（以秒为单位，北京不使用夏令时）

#define USE_WEATHER

// 心知天气 API 配置
#define WEATHER_API_KEY "KEY-APIKEY" // 你的心知天气 API 密钥
#define WEATHER_LOCATION "ip"        // 使用 IP 地址定位（填入ip）或城市代码

// 睡眠和更新间隔时间
#define DISPLAY_UPDATE_INTERVAL_MINUTES 10 // 墨水屏更新间隔时间（分钟）
#define WEATHER_UPDATE_INTERVAL_HOURS 1    // 天气和时间更新间隔时间（小时）

// 将更新间隔时间转换为相应单位
#define DISPLAY_UPDATE_INTERVAL (DISPLAY_UPDATE_INTERVAL_MINUTES * 60 * 1000000) // 墨水屏更新间隔时间，单位为微秒
#define WEATHER_UPDATE_INTERVAL (WEATHER_UPDATE_INTERVAL_HOURS * 60 * 60)        // 天气和时间更新间隔时间，单位为秒

// WIFI连接超时
#define WIFI_CONNECT_TIMEOUT 10000 // WIFI连接超时时间（毫秒）

#endif
