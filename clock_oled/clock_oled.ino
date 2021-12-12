#include "ssd1306.h"

uint32_t lastMillis;
uint8_t  hours = 11;
uint8_t  minutes = 03;
uint8_t  seconds = 30;

void printSeconds()
{
    char secstr[3] = "00";
    secstr[0] = '0' + seconds / 10;
    secstr[1] = '0' + seconds % 10;
    ssd1306_printFixed(80,  8, secstr, STYLE_NORMAL);
}

void printMinutes()
{
    char minutesStr[3] = "00";
    minutesStr[0] = '0' + minutes / 10;
    minutesStr[1] = '0' + minutes % 10;
    ssd1306_printFixed(42,  8, minutesStr, STYLE_NORMAL);
}

void printHours()
{
    char hoursStr[3] = "00";
    hoursStr[0] = '0' + hours / 10;
    hoursStr[1] = '0' + hours % 10;
    ssd1306_printFixed(2,  8, hoursStr, STYLE_NORMAL);
}

void setup() {
    /* Replace the line below with ssd1306_128x32_i2c_init() if you need to use 128x32 display */
    ssd1306_128x64_i2c_init();
    ssd1306_fillScreen(0x00);
    ssd1306_setFixedFont(courier_new_font11x16_digits);
    lastMillis = millis();
    printHours();
    printMinutes();
    printSeconds();
}

void loop()
{
    if ((uint32_t)(millis() - lastMillis) >= 1000)
    {
        lastMillis += 1000;
        if (++seconds > 59)
        {
            seconds = 0;
            if (++minutes > 59)
            {
                minutes = 0;
                if (++hours > 23)
                {
                    hours = 0;
                }
                printHours();
            }
            printMinutes();
        }
        printSeconds();
    }
}
