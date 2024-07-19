#include "EPaper.h"
#include "bitmap.h"
#include "GxEPD2_display_selection.h"

// const char *getWeatherIcon(const char *id, bool fill)
// {
//     if (strcmp(id, "100") == 0)
//         return !fill ? "\uf101" : "\uf1ac";
//     if (strcmp(id, "101") == 0)
//         return !fill ? "\uf102" : "\uf1ad";
//     if (strcmp(id, "102") == 0)
//         return !fill ? "\uf103" : "\uf1ae";
//     if (strcmp(id, "103") == 0)
//         return !fill ? "\uf104" : "\uf1af";
//     if (strcmp(id, "104") == 0)
//         return !fill ? "\uf105" : "\uf1b0";
//     if (strcmp(id, "150") == 0)
//         return !fill ? "\uf106" : "\uf1b1";
//     if (strcmp(id, "151") == 0)
//         return !fill ? "\uf107" : "\uf1b2";
//     if (strcmp(id, "152") == 0)
//         return !fill ? "\uf108" : "\uf1b3";
//     if (strcmp(id, "153") == 0)
//         return !fill ? "\uf109" : "\uf1b4";
//     if (strcmp(id, "300") == 0)
//         return !fill ? "\uf10a" : "\uf1b5";
//     if (strcmp(id, "301") == 0)
//         return !fill ? "\uf10b" : "\uf1b6";
//     if (strcmp(id, "302") == 0)
//         return !fill ? "\uf10c" : "\uf1b7";
//     if (strcmp(id, "303") == 0)
//         return !fill ? "\uf10d" : "\uf1b8";
//     if (strcmp(id, "304") == 0)
//         return !fill ? "\uf10e" : "\uf1b9";
//     if (strcmp(id, "305") == 0)
//         return !fill ? "\uf10f" : "\uf1ba";
//     if (strcmp(id, "306") == 0)
//         return !fill ? "\uf110" : "\uf1bb";
//     if (strcmp(id, "307") == 0)
//         return !fill ? "\uf111" : "\uf1bc";
//     if (strcmp(id, "308") == 0)
//         return !fill ? "\uf112" : "\uf1bd";
//     if (strcmp(id, "309") == 0)
//         return !fill ? "\uf113" : "\uf1be";
//     if (strcmp(id, "310") == 0)
//         return !fill ? "\uf114" : "\uf1bf";
//     if (strcmp(id, "311") == 0)
//         return !fill ? "\uf115" : "\uf1c0";
//     if (strcmp(id, "312") == 0)
//         return !fill ? "\uf116" : "\uf1c1";
//     if (strcmp(id, "313") == 0)
//         return !fill ? "\uf117" : "\uf1c2";
//     if (strcmp(id, "314") == 0)
//         return !fill ? "\uf118" : "\uf1c3";
//     if (strcmp(id, "315") == 0)
//         return !fill ? "\uf119" : "\uf1c4";
//     if (strcmp(id, "316") == 0)
//         return !fill ? "\uf11a" : "\uf1c5";
//     if (strcmp(id, "317") == 0)
//         return !fill ? "\uf11b" : "\uf1c6";
//     if (strcmp(id, "318") == 0)
//         return !fill ? "\uf11c" : "\uf1c7";
//     if (strcmp(id, "350") == 0)
//         return !fill ? "\uf11d" : "\uf1c8";
//     if (strcmp(id, "351") == 0)
//         return !fill ? "\uf11e" : "\uf1c9";
//     if (strcmp(id, "399") == 0)
//         return !fill ? "\uf11f" : "\uf1ca";
//     if (strcmp(id, "400") == 0)
//         return !fill ? "\uf120" : "\uf1cb";
//     if (strcmp(id, "401") == 0)
//         return !fill ? "\uf121" : "\uf1cc";
//     if (strcmp(id, "402") == 0)
//         return !fill ? "\uf122" : "\uf1cd";
//     if (strcmp(id, "403") == 0)
//         return !fill ? "\uf123" : "\uf1ce";
//     if (strcmp(id, "404") == 0)
//         return !fill ? "\uf124" : "\uf1cf";
//     if (strcmp(id, "405") == 0)
//         return !fill ? "\uf125" : "\uf1d0";
//     if (strcmp(id, "406") == 0)
//         return !fill ? "\uf126" : "\uf1d1";
//     if (strcmp(id, "407") == 0)
//         return !fill ? "\uf127" : "\uf1d2";
//     if (strcmp(id, "408") == 0)
//         return !fill ? "\uf128" : "\uf1d3";
//     if (strcmp(id, "409") == 0)
//         return !fill ? "\uf129" : "\uf1d4";
//     if (strcmp(id, "410") == 0)
//         return !fill ? "\uf12a" : "\uf1d5";
//     if (strcmp(id, "456") == 0)
//         return !fill ? "\uf12b" : "\uf1d6";
//     if (strcmp(id, "457") == 0)
//         return !fill ? "\uf12c" : "\uf1d7";
//     if (strcmp(id, "499") == 0)
//         return !fill ? "\uf12d" : "\uf1d8";
//     if (strcmp(id, "500") == 0)
//         return !fill ? "\uf12e" : "\uf1d9";
//     if (strcmp(id, "501") == 0)
//         return !fill ? "\uf12f" : "\uf1da";
//     if (strcmp(id, "502") == 0)
//         return !fill ? "\uf130" : "\uf1db";
//     if (strcmp(id, "503") == 0)
//         return !fill ? "\uf131" : "\uf1dc";
//     if (strcmp(id, "504") == 0)
//         return !fill ? "\uf132" : "\uf1dd";
//     if (strcmp(id, "507") == 0)
//         return !fill ? "\uf133" : "\uf1de";
//     if (strcmp(id, "508") == 0)
//         return !fill ? "\uf134" : "\uf1df";
//     if (strcmp(id, "509") == 0)
//         return !fill ? "\uf135" : "\uf1e0";
//     if (strcmp(id, "510") == 0)
//         return !fill ? "\uf136" : "\uf1e1";
//     if (strcmp(id, "511") == 0)
//         return !fill ? "\uf137" : "\uf1e2";
//     if (strcmp(id, "512") == 0)
//         return !fill ? "\uf138" : "\uf1e3";
//     if (strcmp(id, "513") == 0)
//         return !fill ? "\uf139" : "\uf1e4";
//     if (strcmp(id, "514") == 0)
//         return !fill ? "\uf13a" : "\uf1e5";
//     if (strcmp(id, "515") == 0)
//         return !fill ? "\uf13b" : "\uf1e6";
//     if (strcmp(id, "800") == 0)
//         return "\uf13c";
//     if (strcmp(id, "801") == 0)
//         return "\uf13d";
//     if (strcmp(id, "802") == 0)
//         return "\uf13e";
//     if (strcmp(id, "803") == 0)
//         return "\uf13f";
//     if (strcmp(id, "804") == 0)
//         return "\uf140";
//     if (strcmp(id, "805") == 0)
//         return "\uf141";
//     if (strcmp(id, "806") == 0)
//         return "\uf142";
//     if (strcmp(id, "807") == 0)
//         return "\uf143";
//     if (strcmp(id, "900") == 0)
//         return !fill ? "\uf144" : "\uf1e7";
//     if (strcmp(id, "901") == 0)
//         return !fill ? "\uf145" : "\uf1e8";
//     return !fill ? "\uf146" : "\uf1e9";
// }

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

        // // Display weather icon
        // u8g2Fonts.setFont(u8g2_font_qweather_icon_30_qwicon);
        // u8g2Fonts.drawStr(0, 0, getWeatherIcon(icon, false));

    } while (display.nextPage());
}
