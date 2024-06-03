#define F_CPU 1000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#ifndef _BV
#define _BV(bit) =(1<<(bit))
#endif

volatile uint8_t k=50;
volatile uint8_t l=10;

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
	
	
	
	DDRB |= LED1|LED2;
		
	PORTB |= LED1|LED2;
	
	sei();
	TIMSK|=_BV(TOIE0);
	TCCR0 |= _BV(CS00);
	TCNT0 = 0;
	
	_PORTD.d0=1;
	_PORTD.d1=1;
	
    while (1) 
    {
		
		if(_PIND.d0==0)
		{
			_delay_ms(10);
			k=k+1;
		}
		if(_PIND.d1==0)
		{
			_delay_ms(10);
			k=k-1;
		}
		
		if(l>1)
		{
			l--;
			_delay_ms(5);
		}
		if(l<99)
		{
			l++;
			_delay_ms(5);
		}
		
		
		
    }
}

ISR(TIMER0_OVF_vect)
{
		static uint8_t i=0, j=0;
		i++;
		j++;
		
		if(i==k)
		{
			PORTB &= ~LED1;
		}
		if(i==100)
		{
			i=0;
			PORTB |=LED1;
		}
		
		if(j==l)
		{
			PORTB &= ~LED2;
		}
		if(j==100)
		{
			j=0;
			PORTB |=LED2;
		}
}
