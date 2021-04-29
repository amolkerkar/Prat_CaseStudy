
#include <avr/io.h>
#include <util/delay.h>
int temperature=0;
int Activity_3(void)
{
TCCR1A=(1<<COM1A1)|(1<<WGM11)|(WGM10);
TCCR1B=(1<<WGM12)|(1<<CS11)|(1<<CS10);
DDRB|=(1<<PB1);

PORTB |= (1<<PB1);

    {
        if(ADC <=200)
        {
         temperature = 20;
         Activity_4();
         OCR1A=102;
         _delay_ms(200);
        }
        else if(ADC <= 500)
        {
         temperature = 25;
         Activity_4();
         OCR1A=204;
         _delay_ms(200);
        }
        else if(ADC <= 700)
        {
         temperature = 29;
         Activity_4();
         OCR1A=358;
         _delay_ms(200);
        }
        else if(ADC <= 1024)
        {
         temperature = 33;
         Activity_4();
         OCR1A=484;
         _delay_ms(200);
        }
    }
    return temperature;
}
