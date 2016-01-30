#include <avr/io.h>
#include <util/delay.h>

void sleep(uint8_t millisec)
{
        while(millisec) {
                _delay_ms(1);/* 1 ms delay */
                millisec--;
        }
}

int main(int argc, char *argv[])
{
        DDRB |=1<<PB3;  /* PC3 will now be the output pin */
        while(1) {
                PORTB &= ~(1<<PB3);/* PC3 LOW */
                sleep(100);/* 100 ms delay */

                PORTB |=(1<<PB3); /* PC3 HIGH */
                sleep(100);/* 100 ms delay */
        }
	return 0;
}
