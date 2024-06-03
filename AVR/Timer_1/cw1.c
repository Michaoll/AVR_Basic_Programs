#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#ifndef _BV
#define_BV(bit)(1 << (bit))
#endif

int main(void)
{
   sei();
   TCCR1B |= (1 << WGM12);
   TCCR1B |= (1 << CS12);
   TCCR1B |= (1 << CS10);
   TIMSK|=_BV(OCIE1A);
   DDRB|=_BV(PB1);
   OCR1A = 121;
    while(1)
    {
       
    }

}

ISR (TIMER1_COMPA_vect)
{
    PORTB^=_BV(PB1);
}
