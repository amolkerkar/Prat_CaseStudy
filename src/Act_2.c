
#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000UL
void InitADC()
{
    ADMUX = (1<<REFS0);
    ADCSRA = (1<<ADEN)|(7<<ADPS0);
}
uint16_t ReadADC(uint8_t ch)
{
    ADMUX&=0xf8;
    ch=ch&0b00000111;
    ADMUX|=ch;
    ADCSRA|=(1<<ADSC);
    while(!(ADCSRA & (1<<ADIF)));
    ADCSRA|=(1<<ADIF);
    return(ADC);
}

void Activity_2()
{
    InitADC();
 //   uint16_t temp;

    {
        ReadADC(0);
        _delay_ms(200);
    }
}
