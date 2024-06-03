#include <avr/io.h>
#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 1000000UL

#ifndef _BV
#define _BV(bit) (1 << (bit))
#endif

static uint8_t i =0;

static uint8_t bit1,bit2,bit3,bit4;

volatile uint8_t Tab[11];

volatile zmienna1,zmienna2;	

int main(void)
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

	DDRB = oxFF;
	DDRC|=_BV(PC0)|_BV(PC1)|_BV(PC2)|_BV(PC3);
	DDRD&=~_BV(PD0);
	DDRD&=~_BV(PD1);
	DDRD&=~_BV(PD2);
	DDRD&=~_BV(PD3);
	PORTD|=_BV(PD0)
	while(1)
	{	
		PORTC|=_BV(PC0)|_BV(PC1)|_BV(PC2)|_BV(PC3);
		if(!PIND&=~(1<<PD0))
		{
			bit1=1 ;
		}
		else
		{
			bit1=0 ;
		}
		if(!PIND&=~(1<<PD1))
		{
			bit2=1 ;
		}
		else
		{
			bit2=0 ;
		}
		if(!PIND&=~(1<<PD2))
		{
			bit3=1 ;
		}
		else
		{
			bit3=0 ;
		}
		if(!PIND&=~(1<<PD3))
		{
			bit4=1 ;
		}
		else
		{
			bit4=0 ;
		}
		
		liczba = bit1 + 2*bit2 + 4*bit3 + 8*bit8;
		
		if(liczba<=9)
		{	
			PORTC&=~_BV(PC3);
			PORTB = Tab[Liczba];
			_delay_ms(20);
		}
		if(liczba>9)
		{
			zmienna1=liczba/10;
			zmienna2=liczba - zmienna1*10;
			PORTC&=~_BV(PC3);
			PORTB = Tab[zmienna1]
			_delay_ms(10);
			PORTC|=_BV(PC3);
			PORTC&=~_BV(PC2);
			PORTB = Tab[zmienna2]
			_delay_ms(10);
		}		
		
		
	}
}