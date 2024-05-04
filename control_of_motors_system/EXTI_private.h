/*********************************************************************/
/********************* Documintation section  ************************/
/*********************************************************************/
/*********************  NAME    : Ahmed Fathy  ***********************/
/*********************  DATE    : 13/9/2023    ***********************/
/*********************  SEC     :  EXTERNAL_INTERRUPT _AVR   *********/
/*********************  Version : 1.0          ***********************/
/*********************************************************************/

#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#define SREG_GIE_REG                    *((volatile uint_8*)0x5F)
#define GICR_PIE_REG                    *((volatile uint_8*)0x5B)
#define MCUCR_SENSE_CONTROL_REG         *((volatile uint_8*)0x55)
#define MCUCSR_SENSE_CONTROL_REG        *((volatile uint_8*)0x54)
#define GIFR_PIF_REG                    *((volatile uint_8*)0x5FA)








#endif