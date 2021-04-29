/**
 * @file Act_2.c
 * @author Pratik Lodha
 * @brief Project for Heat Control of a seat
 * @version 0.2 (Act-2)
 * @date 2021-04-25
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <avr/io.h>
# define F_CPU 16000000UL
#include <util/delay.h>

/** \brief InitADC function initializes the ADC
 *
 *
 * \return void
 *
 */
void InitADC()
{
    ADMUX = (1<<REFS0);
    ADCSRA = (1<<ADEN)|(7<<ADPS0);
}

/** \brief ReadADC function reads the analog voltage at pin PC0, converts and stores binary bits in Register ADCL and ADCH
 *
 * \param ch uint8_t
 * \return uint16_t
 *
 */
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

/** \brief main function of act-2, Reading the analog temperature and converting into digital using internal ADC
 *
 * \return void
 *
 */
void Activity_2()
{
    InitADC();
 //   uint16_t temp;

    {
        ReadADC(0);
        _delay_ms(200);
    }
}
