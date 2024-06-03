#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>

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


int zmienna=0;

int poprzednia=1;
int aktualna = 1;

void przerwanie()
{
	aktualna =_PIND.d0;
	if(aktualna==0)
	{
		zmienna=0;
	}
}


int main(void)
{
	DDRB |= (1<<PB0);
	DDRB |= (1<<PB1);
	DDRB |= (1<<PB2);
	DDRB |= (1<<PB3);
	
	
	
    /* Replace with your application code */
	
	_PORTD.d0=1;
	_PORTD.d1=1;
	PORTB |= (1<<PB0);
	PORTB |= (1<<PB1);
	PORTB |= (1<<PB2);
	PORTB |= (1<<PB3);
    while (1) 
    {
		

			
			poprzednia=aktualna;
			
			aktualna =_PIND.d0;
			
			if(poprzednia==1&&aktualna==0)
			{
				zmienna = 1;
			}
			while (zmienna==1)
			{
				PORTB &= ~ (1<<PB0);
				_delay_ms(1000);
				przerwanie();
				PORTB &= ~ (1<<PB1);
				_delay_ms(1000);
				przerwanie();
				PORTB &= ~ (1<<PB2);
				_delay_ms(1000);
				przerwanie();
				PORTB &= ~ (1<<PB3);
				_delay_ms(1000);
				przerwanie();
				
				PORTB |= (1<<PB0);
				_delay_ms(1000);
				przerwanie();
				PORTB |= (1<<PB1);
				_delay_ms(1000);
				przerwanie();
				PORTB |= (1<<PB2);
				_delay_ms(1000);
				przerwanie();
				PORTB |= (1<<PB3);
				_delay_ms(1000);
				przerwanie();
		
			}
			
		
    }
}
