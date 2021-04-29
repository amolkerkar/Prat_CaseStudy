/**
 * @file Act_3.c
 * @author Pratik Lodha
 * @brief Project for Heat Control of a seat
 * @version 0.3 (Act-3)
 * @date 2021-04-28
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <avr/io.h>
# define F_CPU 16000000UL
#include <util/delay.h>
int temperature=0;
void Activity_4();
/** \brief Generating PWM for controlling the temperature using Heater. Getting Input from ADC register and using Output Compare Match register
 *
 * \param void
 * \return int
 *
 */
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
         Activity_4(); //calling activity 4
         OCR1A=102;
         _delay_ms(200);
        }
        else if(ADC <= 500)
        {
         temperature = 25;
         Activity_4(); //calling activity 4
         OCR1A=204;
         _delay_ms(200);
        }
        else if(ADC <= 700)
        {
         temperature = 29;
         Activity_4(); //calling activity 4
         OCR1A=358;
         _delay_ms(200);
        }
        else if(ADC <= 1024)
        {
         temperature = 33;
         Activity_4(); //calling activity 4
         OCR1A=484;
         _delay_ms(200);
        }
    }
    return temperature;
}
