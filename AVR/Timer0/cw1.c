#define F_CPU 1000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#ifndef _BV
#define _BV(bit) =(1<<(bit))
#endif



int main(void)
{
	
	#define LED1 _BV(PB0)
	#define LED2 _BV(PB1)
	#define LED3 _BV(PB2)
	#define LED4 _BV(PB3)
	
	
	
	DDRB |= LED1|LED2|LED3|LED4;
		
	PORTB |= LED1|LED2|LED3|LED4;
	
	sei();
	TIMSK|=_BV(TOIE0);
	TCCR0 |= _BV(CS02);
	TCNT0 = 0;
	
    while (1) 
    {
		
    }
}

ISR(TIMER0_OVF_vect)
{
	static uint8_t i=0,j=0;
		i++;
		j++;
		
		if(i==8){
			PORTB ^=LED1;
			i=0;
		}
		if(j==16){
				PORTB ^= LED2;
				j=0;
		}
}
