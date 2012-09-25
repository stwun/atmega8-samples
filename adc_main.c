#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>               // not every include used!

#include "adc.h"

int main(void){
	int result1 = getadc(0x01);  // get value from ADC0
	char s_value1[16];
	itoa(result1, s_value1, 10);   // convert int to string
	
	return 0;	
}
