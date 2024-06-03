#include <avr/io.h>
#include <avr/interrupt.h>
#ifdef _BV()
#define _BV(bit) (1<<bit)
#endif

volatile uint8_t pomiar = 0; 

int main(void) 
{
    DDRC=0xFF;
    DDRC &=~(1<<PC1);
    DDRB=0xFF;
    PORTB=0xFF;
    PORTC&=~(1<<PC1);

    TCCR1B |=(1<<CS11) | (1<<WGM12);
    OCR1A = 1249;
    TIMSK |= (1<<OCIE1A);
    sei();
    ADMUX|=(1<<REFS0);
    ADMUX|=(1<<MUX0);
    ADMUX|=(1<<ADLAR);
    ADCSRA |= (1<<ADEN);
    ADCSRA |= (1<<ADPS0);
    ADCSRA |= (1<<ADPS2);
    ADCSRA |= (1<<ADIE);
    while(1)
    {
        PORTB = pomiar;
    }

}

ISR(TIMER1_COMPA_vect)
{
    ADCSRA|=(1<<ADSC);
}

ISR(ADC_vect)
{
    pomiar = ~ADCH;
}
