#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>

int main(void)
{
	DDRB |= (1<<PB0);
	DDRB |= (1<<PB1);
	DDRB |= (1<<PB2);
	DDRB |= (1<<PB3);

	while (1)
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
}