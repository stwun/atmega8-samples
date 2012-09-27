#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>       // too many includes

int main(void){
	OCR1AH = 0;     // high byte of OCR1A/B (PWM output), not used in 8bit-PWM
	OCR1BH = 0;
	DDRB = (1<<PB1)|(1<<PB2)|(1<<PB3);   //PB1-3 able for PWM. Marked as OC1A, OC1B and OC2. set to output.
	TCCR1A = (1<<COM1A1)|(1<<COM1B1)|(0<<WGM11)|(1<<WGM10);   // OC1A to zero, OC1B to zero, 8bit-PWM
	TCCR1B = (1<<CS10);             		 //Start PWM at clockspeed
	TCCR2 = (1<<CS20)|(1<<COM21)|(0<<WGM21)|(1<<WGM20);     // Timer2 is 8bit (unchangeable), clockspeed

	OCR1AL = 255;       //PB1 full (255/255)=1 -> 5V
	OCR1BL = 127;       //PB2 half (127/255)=1/2 -> 2.5V
	OCR2 = 63;			  //PB3 quarter (63/255)=1/4 -> 1.25V

	return 0;
}