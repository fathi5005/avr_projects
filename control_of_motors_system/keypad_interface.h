/*********************************************************************/
/********************* Documintation section  ************************/
/*********************************************************************/
/*********************  NAME    : Ahmed Fathy  ***********************/
/*********************  DATE    : 21/9/2023    ***********************/
/*********************  SEC     :  KEYPAD _AVR        ***********************/
/*********************  Version : 1.0          ***********************/
/*********************************************************************/

#ifndef KEYPAD_INTERFACE_H
#define KEYPAD_INTERFACE_H
#include "keypad_configer.h"
#include "keypad_private.h"
#include "STD_TYPES.h"


#define CLAER_LCD   'D'
uint_8 KeyPad_Return_key (uint_8 * returned_key);


#endif
