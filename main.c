/**
 * @file main.c
 * @author Pratik Lodha
 * @brief Project for Heat Control of a seat
 * @version 0.1 (Act-1)
 * @date 2021-04-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <avr\io.h>
#include <util\delay.h>
/**
 * @brief main function where code execution
 * 
 * @return int 
 */
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
