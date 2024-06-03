#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>



#ifdef _BV()
#define _BV(bit) (1<<bit)
#endif

volatile uint16_t pomiar = 0; 

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
        //oblicznie jedności
PORTB = Tab[pomiar%10];
PORTD |= (_BV(0) | _BV(1) | _BV(2) | _BV(3));
PORTD &=~ (_BV(3));
_delay_ms(5);
         //obliczenie dziesiątek
PORTB = Tab[pomiar%100/10];
PORTD |= (_BV(0) | _BV(1) | _BV(2) | _BV(3));
PORTD &=~ (_BV(2));
_delay_ms(5);
         //obliczanie setek
PORTB = Tab[pomiar%1000/100];
PORTD |= (_BV(0) | _BV(1) | _BV(2) | _BV(3));
PORTD &=~ (_BV(1));
_delay_ms(5);



    }

}

ISR(TIMER1_COMPA_vect)
{
    ADCSRA|=(1<<ADSC);
}

ISR(ADC_vect)
{
    pomiar = (uint32_t)ADCH*500/256;
}
