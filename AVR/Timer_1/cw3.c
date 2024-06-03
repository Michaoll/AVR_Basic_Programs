#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#ifndef _BV
#define_BV(bit)(1 << (bit))
#endif


int main(void)
{
   sei();
   TIMSK|=_BV(TOIE1);
   TCCR1A |= (1 << WGM10);
   TCCR1A |= (1 << COM1A1);
   TCCR1A |= (1 << COM1B1);
   TCCR1B |= (1 << CS10);
   TCCR1B |= (1 << CS11);
   TCCR1B |= (1 << WGM12);
   DDRB|=_BV(PB1);
   DDRB|=_BV(PB2);
   DDRB|=_BV(PB3);
   DDRD&=~_BV(PD2);
   DDRD&=~_BV(PD3);
   PORTD|=_BV(PD2);
   PORTD|=_BV(PD3);
   GICR|=_BV(INT0);
   GICR|=_BV(INT1);
   MCUCR|=_BV(ISC01);
   MCUCR|=_BV(ISC11);
    while(1)
    {
       
    }

}

ISR(INT0_vect) 
{
    
    if (OCR1A > 0) 
    {
        OCR1A=OCR1A-10;
    }
}

ISR(INT1_vect) 
{
    
    if (OCR1A < 255) 
    {
        OCR1A=OCR1A+10;
    }
}

ISR(TIMER1_OVF_vect)
{
    static bool zmiana;

    if(OCR1B == 0 || OCR1B == 255)
    {
        zmiana = !zmiana;
    }
    if(zmiana)
    {
        OCR1B = OCR1B + 5;
    }
    if(!zmiana)
    {
        OCR1B = OCR1B - 5;
    }
}
