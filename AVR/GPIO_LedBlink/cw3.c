#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>

int main(void)
{
	DDRB=0b00000011;
	while (1)
	{
		PORTB=0b00000010;
		_delay_ms(1000);
		PORTB=0b00000001;
		_delay_ms(1000);
	}
}