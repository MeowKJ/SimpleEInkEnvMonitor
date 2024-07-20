#include "Weather.h"

const char *getWeatherIconText(uint16_t id, bool fill)
{
    // 可能有误,注意辨别
    switch (id)
    {
    case 0: // 晴（白天）
        return !fill ? "\uf101" : "\uf1ac";
    case 1: // 晴（夜晚）
        return !fill ? "\uf106" : "\uf1b1";
    case 2: // 多云（白天）
        return !fill ? "\uf102" : "\uf1ad";
    case 3: // 少云（白天）
        return !fill ? "\uf103" : "\uf1ae";
    case 4: // 晴间多云（白天）
        return !fill ? "\uf104" : "\uf1af";
    case 5: // 阴
        return !fill ? "\uf105" : "\uf1b0";
    case 6: // 多云（夜晚）
        return !fill ? "\uf107" : "\uf1b2";
    case 7: // 少云（夜晚）
        return !fill ? "\uf108" : "\uf1b3";
    case 8: // 晴间多云（夜晚）
        return !fill ? "\uf109" : "\uf1b4";
    case 9: // 阵雨（白天）
        return !fill ? "\uf10a" : "\uf1b5";
    case 10: // 强阵雨（白天）
        return !fill ? "\uf10b" : "\uf1b6";
    case 11: // 雷阵雨
        return !fill ? "\uf10c" : "\uf1b7";
    case 12: // 强雷阵雨
        return !fill ? "\uf10d" : "\uf1b8";
    case 13: // 雷阵雨伴有冰雹
        return !fill ? "\uf10e" : "\uf1b9";
    case 14: // 小雨
        return !fill ? "\uf10f" : "\uf1ba";
    case 15: // 中雨
        return !fill ? "\uf110" : "\uf1bb";
    case 16: // 大雨
        return !fill ? "\uf111" : "\uf1bc";
    case 17: // 极端降雨
        return !fill ? "\uf112" : "\uf1bd";
    case 18: // 毛毛雨/细雨
        return !fill ? "\uf113" : "\uf1be";
    case 19: // 暴雨
        return !fill ? "\uf114" : "\uf1bf";
    case 20: // 大暴雨
        return !fill ? "\uf115" : "\uf1c0";
    case 21: // 特大暴雨
        return !fill ? "\uf116" : "\uf1c1";
    case 22: // 冻雨
        return !fill ? "\uf117" : "\uf1c2";
    case 23: // 小到中雨
        return !fill ? "\uf118" : "\uf1c3";
    case 24: // 中到大雨
        return !fill ? "\uf119" : "\uf1c4";
    case 25: // 大到暴雨
        return !fill ? "\uf11a" : "\uf1c5";
    case 26: // 暴雨到大暴雨
        return !fill ? "\uf11b" : "\uf1c6";
    case 27: // 大暴雨到特大暴雨
        return !fill ? "\uf11c" : "\uf1c7";
    case 28: // 阵雨（夜晚）
        return !fill ? "\uf11d" : "\uf1c8";
    case 29: // 强阵雨（夜晚）
        return !fill ? "\uf11e" : "\uf1c9";
    case 30: // 雨
        return !fill ? "\uf11f" : "\uf1ca";
    case 31: // 小雪
        return !fill ? "\uf120" : "\uf1cb";
    case 32: // 中雪
        return !fill ? "\uf121" : "\uf1cc";
    case 33: // 大雪
        return !fill ? "\uf122" : "\uf1cd";
    case 34: // 暴雪
        return !fill ? "\uf123" : "\uf1ce";
    case 35: // 雨夹雪
        return !fill ? "\uf124" : "\uf1cf";
    case 36: // 雨雪天气
        return !fill ? "\uf125" : "\uf1d0";
    case 37: // 阵雨夹雪（白天）
        return !fill ? "\uf126" : "\uf1d1";
    case 38: // 阵雪（白天）
        return !fill ? "\uf127" : "\uf1d2";
    case 39: // 小到中雪
        return !fill ? "\uf128" : "\uf1d3";
    case 40: // 中到大雪
        return !fill ? "\uf129" : "\uf1d4";
    case 41: // 大到暴雪
        return !fill ? "\uf12a" : "\uf1d5";
    case 42: // 阵雨夹雪（夜晚）
        return !fill ? "\uf12b" : "\uf1d6";
    case 43: // 阵雪（夜晚）
        return !fill ? "\uf12c" : "\uf1d7";
    case 44: // 雪
        return !fill ? "\uf12d" : "\uf1d8";
    case 45: // 薄雾
        return !fill ? "\uf12e" : "\uf1d9";
    case 46: // 雾
        return !fill ? "\uf12f" : "\uf1da";
    case 47: // 霾
        return !fill ? "\uf130" : "\uf1db";
    case 48: // 扬沙
        return !fill ? "\uf131" : "\uf1dc";
    case 49: // 浮尘
        return !fill ? "\uf132" : "\uf1dd";
    case 50: // 沙尘暴
        return !fill ? "\uf133" : "\uf1de";
    case 51: // 强沙尘暴
        return !fill ? "\uf134" : "\uf1df";
    case 52: // 浓雾
        return !fill ? "\uf135" : "\uf1e0";
    case 53: // 强浓雾
        return !fill ? "\uf136" : "\uf1e1";
    case 54: // 中度霾
        return !fill ? "\uf137" : "\uf1e2";
    case 55: // 重度霾
        return !fill ? "\uf138" : "\uf1e3";
    case 56: // 严重霾
        return !fill ? "\uf139" : "\uf1e4";
    case 57: // 大雾
        return !fill ? "\uf13a" : "\uf1e5";
    case 58: // 特强浓雾
        return !fill ? "\uf13b" : "\uf1e6";
    case 59: // 热
        return !fill ? "\uf144" : "\uf1e7";
    case 60: // 冷
        return !fill ? "\uf145" : "\uf1e8";
    default: // 未知
        return !fill ? "\uf146" : "\uf1e9";
    }
}

const char *getWeekText(uint8_t week)
{
    switch (week)
    {
    case 1:
        return "星期一";
    case 2:
        return "星期二";
    case 3:
        return "星期三";
    case 4:
        return "星期四";
    case 5:
        return "星期五";
    case 6:
        return "星期六";
    case 0:
        return "星期天";
    default:
        return "星期八";
    }
}