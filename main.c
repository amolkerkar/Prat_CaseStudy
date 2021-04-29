/**
 * @file main.c
 * @author Pratik Lodha
 * @brief Project for Heat Control of a seat
 * @version 0.1
 * @date 2021-04-23
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <avr/io.h>
#include "Act_1.h"
#include "Act_2.h"
#include "Act_3.h"
#include "Act_4.h"

/** \brief main function where code execution
 *
 * \param void
 * \return int
 *
 */
int main(void)
{
    while(1)
    {
    Activity_1(); // calling activity 1
    }
return 0;
}
