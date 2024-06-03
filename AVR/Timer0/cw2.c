#include <avr/interrupt.h>
#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>

#ifndef _BV
#define _BV(bit) =(1<<(bit))
#endif

typedef struct
{
	unsigned int d0:1;
	unsigned int d1:1;
	unsigned int d2:1;
	unsigned int d3:1;
	unsigned int d4:1;
	unsigned int d5:1;
	unsigned int d6:1;
	unsigned int d7:1;
} IO;

#define _PORTD (*( volatile IO*)&PORTD)
#define _PIND (*( volatile IO*)&PIND)

int main(void)
{
	
	#define LED1 _BV(PB0)
	#define LED2 _BV(PB1)
	#define LED3 _BV(PB2)
	#define LED4 _BV(PB3)
	//uint8_t i=0;
	
	
	TCCR0 |= (_BV(CS02)|_BV(CS01)|_BV(CS00));
	TCNT0 = 0;
	DDRB=0b00001111;
	PORTB=0b00000000;
	DDRD &= ~(_BV(PD4));
	PORTD |= (_BV(PD4));
	
	DDRD &= ~(_BV(PD0));
	PORTD |= (_BV(PD0));
	
	sei();
	
	while (1)
	{
		PORTB = ~TCNT0;
		if(_PIND.d0==0)
		{
			TCNT0 = 0;
		}
		
	}
}
