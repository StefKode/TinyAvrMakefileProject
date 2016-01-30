#include <util/delay.h>

void sleep(uint8_t millisec)
{
        while(millisec) {
                _delay_ms(1);/* 1 ms delay */
                millisec--;
        }
}
