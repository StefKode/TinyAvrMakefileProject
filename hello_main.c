/*######################################################################################
 #
 # Copyright by Stefan Koch <StefanKoch@gmx.org>, 2016
 #
 # Example-Project (main function)
 # This file is part of TinyAvrMakefileProject
 #
 #    omxAutomation is free software: you can redistribute it and/or modify
 #    it under the terms of the GNU General Public License as published by
 #    the Free Software Foundation, either version 3 of the License, or
 #    (at your option) any later version.
 #
 #    TinyAvrMakefileProject is distributed in the hope that it will be useful,
 #    but WITHOUT ANY WARRANTY; without even the implied warranty of
 #    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 #    GNU General Public License for more details.
 #
 #    You should have received a copy of the GNU General Public License
 #    along with TinyAvrMakefileProject. If not, see <http://www.gnu.org/licenses/>.
 #
 ######################################################################################*/
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
