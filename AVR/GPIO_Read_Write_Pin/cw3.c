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



int main(void)
{
	DDRB |= (1<<PB0);
	DDRB |= (1<<PB1);
	DDRB |= (1<<PB2);
	DDRB |= (1<<PB3);
	
	PORTB |= (1<<PB0);
	PORTB |= (1<<PB1);
	PORTB |= (1<<PB2);
	PORTB |= (1<<PB3);
	
    /* Replace with your application code */
	
	_PORTD.d0=1;
	_PORTD.d1=1;
	
    while (1) 
    {


			if(_PIND.d0==0&&_PIND.d1==0)
			{
				PORTB &= ~ (1<<PB0);


				PORTB &= ~ (1<<PB1);


				PORTB &= ~ (1<<PB2);
	

				PORTB &= ~ (1<<PB3);	

			}
			else if(_PIND.d0==1&&_PIND.d1==1)
			{

				PORTB |= (1<<PB0);
				PORTB |= (1<<PB1);
				PORTB |= (1<<PB2);
				PORTB |= (1<<PB3);
			}
			else if(_PIND.d0==0)
			{
				PORTB &= ~ (1<<PB0);
				_delay_ms(1000);

				PORTB &= ~ (1<<PB1);
				_delay_ms(1000);

				PORTB &= ~ (1<<PB2);
				_delay_ms(1000);

				PORTB &= ~ (1<<PB3);
				_delay_ms(1000);

				
				PORTB |= (1<<PB0);
				_delay_ms(1000);

				PORTB |= (1<<PB1);
				_delay_ms(1000);

				PORTB |= (1<<PB2);
				_delay_ms(1000);

				PORTB |= (1<<PB3);
				_delay_ms(1000);

			}

			else if(_PIND.d1==0)
			{
				PORTB &= ~ (1<<PB3);
				_delay_ms(1000);

				PORTB &= ~ (1<<PB2);
				_delay_ms(1000);
	
				PORTB &= ~ (1<<PB1);
				_delay_ms(1000);

				PORTB &= ~ (1<<PB0);
				_delay_ms(1000);



				
				PORTB |= (1<<PB3);
				_delay_ms(1000);

				PORTB |= (1<<PB2);
				_delay_ms(1000);
	
				PORTB |= (1<<PB1);
				_delay_ms(1000);
	
				PORTB |= (1<<PB0);
				_delay_ms(1000);

			}	
		
    }
}
