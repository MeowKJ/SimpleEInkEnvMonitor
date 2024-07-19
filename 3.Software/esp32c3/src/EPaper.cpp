#include "EPaper.h"
#include "bitmap.h"
#include "GxEPD2_display_selection.h"

void EPaper::init()
{
    display.init(115200, true, 2, false); // Waveshare boards
    u8g2Fonts.begin(display);             // 连接 u8g2 到 Adafruit GFX
    display.setRotation(1);
    display.setTextColor(GxEPD_BLACK);
}

void EPaper::displayTemperatureHumidity(const char *tempText, const char *humidityText)
{
    uint16_t bg = GxEPD_WHITE;
    uint16_t fg = GxEPD_BLACK;
    uint16_t red = GxEPD_RED;

    u8g2Fonts.setFontMode(1);         // 使用 u8g2 透明模式（默认）
    u8g2Fonts.setFontDirection(0);    // 从左到右（默认）
    u8g2Fonts.setForegroundColor(fg); // 设置前景色
    u8g2Fonts.setBackgroundColor(bg); // 设置背景色

    // 设置并显示温度
    uint16_t tempX = 60;
    uint16_t tempY = 50;

    // 设置并显示湿度
    uint16_t humidityX = tempX;
    uint16_t humidityY = tempY + 60;

    uint8_t tempSignX = 220;
    uint8_t tempSignY = tempY - 30;

    uint8_t humiditySignX = 220;
    uint8_t humiditySignY = humidityY - 30;

    display.setFullWindow();
    display.firstPage();
    do
    {
        u8g2Fonts.setFont(font_number_40); // 设置字体
        display.fillScreen(bg);
        u8g2Fonts.setCursor(tempX, tempY);
        u8g2Fonts.print(tempText);
        u8g2Fonts.setCursor(humidityX, humidityY);
        u8g2Fonts.print(humidityText);
        display.drawBitmap(tempSignX, tempSignY, gImage_a, 30, 30, fg);
        display.drawBitmap(humiditySignX, humiditySignY, gImage_b, 30, 30, fg);

        display.fillRect(50, 0, 4, 122, red);
        display.fillRect(54, tempY + 8, 250, 4, red);
    } while (display.nextPage());
}
