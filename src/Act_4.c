/**
 * @file Act_4.c
 * @author Pratik Lodha
 * @brief Project for Heat Control of a seat
 * @version 0.4 (Act-4)
 * @date 2021-04-29
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <avr/io.h>
#include <util/delay.h>
int temperature;

/** \brief In USARTInit function, initialization of UART registers are done
 *
 * \param ubrr_value uint16_t
 * \return void
 *
 */
void USARTInit(uint16_t ubrr_value)
{
    //set baud-rate

    UBRR0L = ubrr_value;
    UBRR0H = (ubrr_value>>8)&0x00ff;
    UCSR0C =(1<<UMSEL00)|(1<<UCSZ01)|(1<<UCSZ00);

    UCSR0B=(1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0)|(1<<TXCIE0);

}

/** \brief This function writes char data in serial monitor for transmitting
 *
 * \param data char
 * \return char
 *
 */
char USARTWriteChar(char data)
{
    while(!(UCSR0A & (1<<UDRE0)))
    {
        //DO NOTHING
    }
    UDR0 = data;
    return 0;
}

/** \brief In main function of Act-4, I am just configuring the output port and writing the temp in UART(Serial monitor)
 *
 * \return void
 *
 */
void Activity_4()
{
DDRB|=(1<<PB1);
USARTInit(103);
    {
        USARTWriteChar(temperature);
        _delay_ms(100);
    }
}
