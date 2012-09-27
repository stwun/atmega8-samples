#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>       // too many includes

int main(void){
	OCR1AH = 0;     // high byte of OCR1A (PWM output), not used in 8bit-PWM
	OCR1BH = 0;
	DDRB = (1<<PB1)|(1<<PB2);   //only PB1 and PB2 able for PWM. Marked as OC1A and OC1B. set to output.
	TCCR1A = (1<<COM1A1)|(1<<COM1B1)|(0<<WGM11)|(1<<WGM10);   // OC1A to zero, OC1B to zero, 8bit-PWM
	TCCR1B = (1<<CS10);             		 //Start PWM at clockspeed

	OCR1AL = 255;       //PB1 full (255/255)=1
	OCR1BL = 127;       //PB2 half (127/255)=1/2

	return 0;   //  never reached
}
