#include "EPaper.h"
#include "bitmap.h"
#include "GxEPD2_display_selection.h"

void printUnicodeCodes(const char *str)
{
    Serial.print("Unicode Codes: ");
    for (const char *p = str; *p != '\0'; ++p)
    {
        Serial.printf("\\u%04X", (unsigned char)*p);
    }
    Serial.println();
}

void EPaper::init()
{
    display.init(115200);
    u8g2Fonts.begin(display); // 连接 u8g2 到 Adafruit GFX
    display.setRotation(1);
    display.setTextColor(GxEPD_BLACK);

    // 初始化内容为空
    temperatureText = nullptr;
    humidityText = nullptr;
    weatherIconText = nullptr;
}

void EPaper::setTemperatureHumidity(const char *tempText, const char *humText)
{
    temperatureText = tempText;
    humidityText = humText;
}

void EPaper::setWeatherIcon(const char *iconText)
{
    weatherIconText = iconText;
}

void EPaper::refreshDisplay()
{
    uint16_t bg = GxEPD_WHITE;
    uint16_t fg = GxEPD_BLACK;
    uint16_t red = GxEPD_RED;

    uint8_t tempX = 60;
    uint8_t tempY = 50;
    uint8_t humidityX = tempX;
    uint8_t humidityY = tempY + 60;
    uint8_t tempSignX = 220;
    uint8_t tempSignY = tempY - 30;
    uint8_t humiditySignX = 220;
    uint8_t humiditySignY = humidityY - 30;

    // 显示温度和湿度
    u8g2Fonts.setFontMode(1);
    u8g2Fonts.setFontDirection(0);
    u8g2Fonts.setForegroundColor(fg);
    u8g2Fonts.setBackgroundColor(bg);

    display.setFullWindow();
    display.firstPage();
    do
    {
        display.fillScreen(bg);

        if (temperatureText != nullptr && humidityText != nullptr)
        {
            Serial.printf("Temperature: %s, Humidity: %s\n", temperatureText, humidityText);

            u8g2Fonts.setFont(font_number_40); // 设置字体

            u8g2Fonts.setCursor(tempX, tempY);
            u8g2Fonts.print(temperatureText);
            u8g2Fonts.setCursor(humidityX, humidityY);
            u8g2Fonts.print(humidityText);
        }

        if (weatherIconText != nullptr)
        {
            printUnicodeCodes(weatherIconText);
            // 显示天气图标
            u8g2Fonts.setForegroundColor(red);
            u8g2Fonts.setFont(u8g2_font_qweather_icon_30);
            u8g2Fonts.drawUTF8(3, 50, weatherIconText);
        }
        u8g2Fonts.setFont(u8g2_font_cangemin);
        u8g2Fonts.setCursor(3, 100);
        u8g2Fonts.print("星期一");

        display.drawBitmap(tempSignX, tempSignY, gImage_a, 30, 30, fg);
        display.drawBitmap(humiditySignX, humiditySignY, gImage_b, 30, 30, fg);
        display.fillRect(50, 0, 4, 122, red);
        display.fillRect(54, tempY + 8, 250, 4, red);

    } while (display.nextPage());
}
