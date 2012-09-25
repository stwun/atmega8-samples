#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>       // too many includes

int main(void){
	DDRC = (0<<PC5) | (1<<PC4);       // PC5 input, PC4 output
	PORTC = (1<<PC5) | (1<<PC4);      // activate PC4 and PC5
	
	while(1){
		if( PINC & (1<<PC5) ){              // if PINC5 is high (1): turn PC4 on, else turn off
			PORTC = (1<<PC5) | (1<<PC4);
		}
		else if(!( PINC & (1<<PC5))){     // useless else if but for the negation sample
			PORTC = (1<<PC5) | (0<<PC4);   // ... | (0<<PC4) also useless
		}
	}

	return 0;	
}
