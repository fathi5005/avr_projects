/*********************************************************************/
/********************* Documintation section  ************************/
/*********************************************************************/
/*********************  NAME    : Ahmed Fathy  ***********************/
/*********************  DATE    : 30/9/2023    ***********************/
/*********************  SEC     : STEPPER_MOTOR _AVR        ***********************/
/*********************  Version : 1.0          ***********************/
/*********************************************************************/

#ifndef STEPPER_MOTOR_INTERFACE_H
#define STEPPER_MOTOR_INTERFACE_H
#include "BIT_MATH.h"
#include "DIO_Private.h"
#include "DIO_configer.h"
#include "DIO_interface.h"
#include "STD_TYPES.h"
#include "stepper_configer.h"

#include  <util/delay.h>
#define  F_CPU  8000000UL



#define CW		 1
#define CCW		-1


uint_8 MOVE_STEPPER_MOTOR(sint_8 direction , uint_16 angle);

#endif
