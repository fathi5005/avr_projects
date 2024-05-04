/*********************************************************************/
/********************* Documintation section  ************************/
/*********************************************************************/
/*********************  NAME    : Ahmed Fathy  ***********************/
/*********************  DATE    : 13/9/2023    ***********************/
/*********************  SEC     :  DIO _AVR        ***********************/
/*********************  Version : 1.0          ***********************/
/*********************************************************************/

#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#include "STD_TYPES.h"
/* Macros For PORT */
#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3

/* Macros For Pins */

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

/* Macros For Direction */

#define Output 1
#define INput 0

/*Macros for pin value*/

#define Pin_high 1
#define Pin_low 0

uint_8 DIO_set_pin_direction(uint_8 port_id, uint_8 pin_id, uint_8 pin_direction); // return of all functions is error state
  
uint_8 DI_set_pin_value(uint_8 port_id, uint_8 pin_id, uint_8 pin_value);

uint_8 DIO_get_pin_value(uint_8 port_id, uint_8 pin_id,uint_8 *return_pin_value);
                    
uint_8 DIO_set_port_direction(uint_8 port_id, uint_8 pin_direction);

uint_8 DI_set_port_value(uint_8 port_id, uint_8 pin_value);

uint_8 DIO_get_port_value(uint_8 port_id, uint_8 *return_port_value);

void DIO_INTI(void);

#endif