/*
* GccApplication1.c
*
* Created: 2023-10-11 13:55:07
* Author : user
*/
#include <avr/io.h>
int main(void)
{
DDRB=0b00000001; //(1)
PORTB=0b00000000;//(2)
while (1) //(3)
{
}
}