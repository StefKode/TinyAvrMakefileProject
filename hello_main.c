#include <avr/io.h>
#include "sleep.h"

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
