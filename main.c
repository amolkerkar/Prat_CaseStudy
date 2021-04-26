
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
port_def();

    while(1)
    {
        if(!(PIND&(1<<PD2))&&!(PIND&(1<<PD3)))
        {
        PORTB |=(1<<PB0);
        PORTB |=(1<<PB1);
        _delay_ms(2000);

        }
        else
        {
        PORTB &=~(1<<PB0);
        PORTB &=~(1<<PB1);
        }
    }

    return 0;
}
