#include <avr/io.h>
#include <avr/interrupt.h>

void port_def()
{
DDRB |= (1<<PB0); // set PB0=1; set bit for Led output
DDRB |= (1<<PB1); // set PB1=1; set bit for heater output

DDRD &=~(1<<PD2); // set PD2=0; clear bit for input
PORTD |= (1<<PD2);

DDRD &=~(1<<PD3); // set PD3=0; clear bit for input
PORTD |= (1<<PD3);
}
