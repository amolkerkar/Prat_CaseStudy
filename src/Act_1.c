/**
 * @file Act_1.c
 * @author Pratik Lodha
 * @brief Project for Heat Control of a seat
 * @version 0.1 (Act-1)
 * @date 2021-04-23
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <avr/io.h>
# define F_CPU 16000000UL
#include <util/delay.h>
void Activity_2();
void Activity_3();
/** \brief main function of act-1, sensing the availability of passenger and heater button and giving output for LedActuator
 *
 * \return void
 *
 */
void Activity_1()
{
DDRB |= (1<<PB0); // set PB0=1; set bit for Led output
DDRB |= (1<<PB1); // set PB1=1; set bit for heater output

DDRD &=~(1<<PD2); // set PD2=0; clear bit for input
PORTD |= (1<<PD2);

DDRD &=~(1<<PD3); // set PD3=0; clear bit for input
PORTD |= (1<<PD3);

    {
        if(!(PIND&(1<<PD2))&&!(PIND&(1<<PD3)))
        {
        PORTB |=(1<<PB0);
        Activity_2(); // calling activity 2
        Activity_3(); // calling activity 3
        _delay_ms(200);
        }
        else
        {
        PORTB &=~(1<<PB0);
        PORTB &=~(1<<PB1);
        }
    }
}
