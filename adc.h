int getadc(int channel){
	int result,i=0;
	int div = 32;         // convert div-times and build average
	ADMUX = channel;     // choose Channel (ADCx)
	ADMUX |= (0<<REFS1) | (0<<REFS0);    // choose reference (intern, extern, 5V, 2.6V ...)
	ADCSRA = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);     // prescale options
	ADCSRA |= (1<<ADSC);   // dummyconvertion for adjusting the adc
	while(ADCSRA &(1<<ADSC)){}
   result=ADCW;
   result=0;
	for( i=0; i<div; i++ ){    //fetch value div-times
		ADCSRA |= (1<<ADSC);
		while ( ADCSRA & (1<<ADSC) ) {}     //wait for value
			result += ADCW;
	}
	ADCSRA &= ~(1<<ADEN);
	result /= div;                           //calculate average
	return result;
}
