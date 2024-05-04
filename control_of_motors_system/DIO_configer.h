/*********************************************************************/
/*********************  NAME    : Ahmed Fathy  ***********************/
/*********************  DATE    : 13/9/2023    ***********************/
/*********************  SEC     :  DIO _AVR        ***********************/
/*********************  Version : 1.0          ***********************/
/*********************************************************************/

#ifndef DIO_CONFIG_H
#define DIO_CONFIG_H
#include "DIO_Private.h"
#include "STD_TYPES.h"

/*   macros for intial direction for all pins*/

/*   options :  DIO_INTI_INPUT
                DIO_INTI_OUTPUT */

/*  DDRA_REG   for  PORTA   */

#define DIO_PA0_inti_direction      DIO_INTI_OUTPUT
#define DIO_PA1_inti_direction      DIO_INTI_OUTPUT
#define DIO_PA2_inti_direction      DIO_INTI_OUTPUT
#define DIO_PA3_inti_direction      DIO_INTI_OUTPUT
#define DIO_PA4_inti_direction      DIO_INTI_OUTPUT
#define DIO_PA5_inti_direction      DIO_INTI_OUTPUT
#define DIO_PA6_inti_direction      DIO_INTI_OUTPUT
#define DIO_PA7_inti_direction      DIO_INTI_OUTPUT

/*  DDRB_REG   for  PORTB   */

#define DIO_PB0_inti_direction      DIO_INTI_OUTPUT
#define DIO_PB1_inti_direction      DIO_INTI_OUTPUT
#define DIO_PB2_inti_direction      DIO_INTI_INPUT
#define DIO_PB3_inti_direction      DIO_INTI_OUTPUT
#define DIO_PB4_inti_direction      DIO_INTI_OUTPUT
#define DIO_PB5_inti_direction      DIO_INTI_OUTPUT
#define DIO_PB6_inti_direction      DIO_INTI_OUTPUT
#define DIO_PB7_inti_direction      DIO_INTI_OUTPUT

/*  DDRC_REG   for  PORTC   */

#define DIO_PC0_inti_direction      DIO_INTI_OUTPUT
#define DIO_PC1_inti_direction      DIO_INTI_OUTPUT
#define DIO_PC2_inti_direction      DIO_INTI_OUTPUT
#define DIO_PC3_inti_direction      DIO_INTI_OUTPUT
#define DIO_PC4_inti_direction      DIO_INTI_OUTPUT
#define DIO_PC5_inti_direction      DIO_INTI_OUTPUT
#define DIO_PC6_inti_direction      DIO_INTI_OUTPUT
#define DIO_PC7_inti_direction      DIO_INTI_OUTPUT

/*  DDRD_REG   for  PORTD   */

#define DIO_PD0_inti_direction      DIO_INTI_OUTPUT
#define DIO_PD1_inti_direction      DIO_INTI_OUTPUT
#define DIO_PD2_inti_direction      DIO_INTI_OUTPUT
#define DIO_PD3_inti_direction      DIO_INTI_OUTPUT
#define DIO_PD4_inti_direction      DIO_INTI_INPUT
#define DIO_PD5_inti_direction      DIO_INTI_INPUT
#define DIO_PD6_inti_direction      DIO_INTI_INPUT
#define DIO_PD7_inti_direction      DIO_INTI_INPUT

/*macros for inti values for all pins*/

/*options :   DIO_OUTPUT_HIGH
              DIO_OUTPUT_LOW
              DIO_INPUT_PULL_UP
              DIO_INPUT_FLOATING  */

/*   PORTA    */

#define DIO_PA0_inti_value          DIO_OUTPUT_LOW
#define DIO_PA1_inti_value          DIO_OUTPUT_LOW
#define DIO_PA2_inti_value          DIO_OUTPUT_LOW
#define DIO_PA3_inti_value          DIO_OUTPUT_LOW
#define DIO_PA4_inti_value          DIO_OUTPUT_LOW
#define DIO_PA5_inti_value          DIO_OUTPUT_LOW
#define DIO_PA6_inti_value          DIO_OUTPUT_LOW
#define DIO_PA7_inti_value          DIO_OUTPUT_LOW

/*  port_REG   for  PORTB   */

#define DIO_PB0_inti_value          DIO_OUTPUT_LOW
#define DIO_PB1_inti_value          DIO_OUTPUT_LOW
#define DIO_PB2_inti_value          DIO_INPUT_PULL_UP
#define DIO_PB3_inti_value          DIO_OUTPUT_LOW
#define DIO_PB4_inti_value          DIO_OUTPUT_LOW
#define DIO_PB5_inti_value          DIO_OUTPUT_LOW
#define DIO_PB6_inti_value          DIO_OUTPUT_LOW
#define DIO_PB7_inti_value          DIO_OUTPUT_LOW

/*  port_REG   for  PORTC   */

#define DIO_PC0_inti_value          DIO_OUTPUT_LOW
#define DIO_PC1_inti_value          DIO_OUTPUT_LOW
#define DIO_PC2_inti_value          DIO_OUTPUT_LOW
#define DIO_PC3_inti_value          DIO_OUTPUT_LOW
#define DIO_PC4_inti_value          DIO_OUTPUT_LOW
#define DIO_PC5_inti_value          DIO_OUTPUT_LOW
#define DIO_PC6_inti_value          DIO_OUTPUT_LOW
#define DIO_PC7_inti_value          DIO_OUTPUT_LOW

/* port_REG   for  PORTD   */

#define DIO_PD0_inti_value          DIO_OUTPUT_HIGH
#define DIO_PD1_inti_value          DIO_OUTPUT_HIGH
#define DIO_PD2_inti_value          DIO_OUTPUT_HIGH
#define DIO_PD3_inti_value          DIO_OUTPUT_HIGH
#define DIO_PD4_inti_value          DIO_INPUT_PULL_UP
#define DIO_PD5_inti_value          DIO_INPUT_PULL_UP
#define DIO_PD6_inti_value          DIO_INPUT_PULL_UP
#define DIO_PD7_inti_value          DIO_INPUT_PULL_UP

#endif
