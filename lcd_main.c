#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>             // not every include used

#include "lcd.h"                // optimized for 16x2 display with HD44780 controller

int main(void){
	lcd_init();                     // init lcd
	lcd_clear();                    // clear display
	lcd_setcursor(0,1);             // set cursor to (column, row)
	lcd_string("Hello world!");     // put text to cursorposition

	return 0;	
}

