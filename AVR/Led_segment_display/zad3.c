#include <avr/io.h>
#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 1000000UL

#ifndef _BV
#define _BV(bit) (1 << (bit))
#endif

static uint8_t i =0;

volatile uint8_t Tab[11];
{	
	Tab [0] = 0xc0;
	Tab [1] = 0xf9;
	Tab [2] = 0xa4;
	Tab [3] = 0xb0;
	Tab [4] = 0x99;
	Tab [5] = 0x92;
	Tab [6] = 0x82;
	Tab [7] = 0xf8;
	Tab [8] = 0x80;
	Tab [9] = 0x90;
	Tab [10] = 0xff;

}
int main(void)
{	
	DDRB = oxFF;
	DDRC|=_BV(PC0)|_BV(PC1)|_BV(PC2)|_BV(PC3);
	DDRD&=~_BV(PD0);
	PORTC|=_BV(PC0)|_BV(PC1)|_BV(PC2);
	PORTD|=_BV(PD0)
	while(1)
	{	
		if(!PIND&=~(1<<PD0))
		{	
			i--;
		}
		else
		{
			i++;
		}
		if(i == 0)
		{
			i=9;
		}
		if(i == 10)
		{
			i=0;
		}
		PORTB = Tab[i];
		_delay_ms(1000);		
		
		
	}
}