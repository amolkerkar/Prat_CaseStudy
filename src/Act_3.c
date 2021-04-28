
#include <avr/io.h>
#include <util/delay.h>

void Activity_3()
{
TCCR1A=(1<<COM1A1)|(1<<WGM11)|(WGM10);
TCCR1B=(1<<WGM12)|(1<<CS11)|(1<<CS10);
DDRB|=(1<<PB1);

PORTB |= (1<<PB1);

    {
        if(ADC <=200)
        {
         OCR1A=102;
        _delay_ms(200);
        }
        else if(ADC <= 500)
        {
        OCR1A=204;
        _delay_ms(200);
        }
        else if(ADC <= 700)
        {
        OCR1A=358;
        _delay_ms(200);
        }
        else if(ADC <= 1024)
        {
        OCR1A=484;
        _delay_ms(200);
        }
    }
}
