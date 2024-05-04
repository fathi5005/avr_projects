/*********************************************************************/
/********************* Documintation section  ************************/
/*********************************************************************/
/*********************  NAME    : Ahmed Fathy  ***********************/
/*********************  DATE    : 21/9/2023    ***********************/
/*********************  SEC     :  KEYPAD _AVR        ***********************/
/*********************  Version : 1.0          ***********************/
/*********************************************************************/

#ifndef KEYPAD_CONFIGER_H
#define KEYPAD_CONFIGER_H
#include "DIO_interface.h"



#define KEYPAD_PORT    PORTD

#define KEYPAD_R1      PIN0
#define KEYPAD_R2      PIN1
#define KEYPAD_R3      PIN2
#define KEYPAD_R4      PIN3


#define KEYPAD_C1      PIN4
#define KEYPAD_C2      PIN5
#define KEYPAD_C3      PIN6
#define KEYPAD_C4      PIN7


#define KPD_FRAM     {{'7','8','9','/'},  \
                      {'4','5','6','*'},  \
                      {'1','2','3','-'},  \
                      {CLAER_LCD,'0','=','+'}}
                       









#endif
