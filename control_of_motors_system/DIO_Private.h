/*********************************************************************/
/********************* Documintation section  ************************/
/*********************************************************************/
/*********************  NAME    : Ahmed Fathy  ***********************/
/*********************  DATE    : 13/9/2023    ***********************/
/*********************  SEC     :  DIO _AVR        ***********************/
/*********************  Version : 1.0          ***********************/
/*********************************************************************/
#include "STD_TYPES.h"
#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

#define PORTA_REG *((volatile uint_8 *)0x3B)
#define DDRA_REG *((volatile uint_8 *)0x3A)
#define PINA_REG *((volatile uint_8 *)0x39)

#define PORTB_REG *((volatile uint_8 *)0x38)
#define DDRB_REG *((volatile uint_8 *)0x37)
#define PINB_REG *((volatile uint_8 *)0x36)

#define PORTC_REG *((volatile uint_8 *)0x35)
#define DDRC_REG *((volatile uint_8 *)0x34)
#define PINC_REG *((volatile uint_8 *)0x33)

#define PORTD_REG *((volatile uint_8 *)0x32)
#define DDRD_REG *((volatile uint_8 *)0x31)
#define PIND_REG *((volatile uint_8 *)0x30)

/*macros for inti dirction for all pins*/
#define DIO_INTI_INPUT 0
#define DIO_INTI_OUTPUT 1

/*macros for inti value for  all pins*/
#define DIO_OUTPUT_HIGH 1
#define DIO_OUTPUT_LOW 0
#define DIO_INPUT_PULL_UP 1
#define DIO_INPUT_FLOATING 0

#define conc(b7, b6, b5, b4, b3, b2, b1, b0)          conc_Help(b7, b6, b5, b4, b3, b2, b1, b0)
#define conc_Help(b7, b6, b5, b4, b3, b2, b1, b0)        0b##b7##b6##b5##b4##b3##b2##b1##b0



#endif
