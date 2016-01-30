/*######################################################################################
 #
 # Copyright by Stefan Koch <StefanKoch@gmx.org>, 2016
 #
 # Example-Project (sleep function)
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

#include <util/delay.h>

void sleep(uint8_t millisec)
{
        while(millisec) {
                _delay_ms(1);/* 1 ms delay */
                millisec--;
        }
}
