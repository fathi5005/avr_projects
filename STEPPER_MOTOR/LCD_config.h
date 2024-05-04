/*********************************************************************/
/********************* Documintation section  ************************/
/*********************************************************************/
/*********************  NAME    : Ahmed Fathy  ***********************/
/*********************  DATE    : 20/9/2023    ***********************/
/*********************  SEC     : LCD _AVR        ***********************/
/*********************  Version : 1.0          ***********************/
/*********************************************************************/

#ifndef LCD_CONFIGER_H
#define LCD_CONFIGER_H

#include "DIO_interface.h"

/*options : 1-DIO_PORTA
            2-DIO_PORTB
            3-DIO_PORTC
            4-DIO_PORTD*/

#define LCD_PORT_RS PORTC
#define LCD_PIN_RS PIN2

#define LCD_PORT_Rw PORTC
#define LCD_PIN_RW PIN5

#define LCD_PORT_EN PORTC
#define LCD_PIN_EN PIN7

#define LCD_PORT_DATA PORTD

/*options : 1-LCD_8_BIT_MODE
            2-LCD_4_BIT_MODE */

#define LCD_MODE LCD_8_BIT_MODE

#endif
