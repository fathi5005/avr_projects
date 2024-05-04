/*********************************************************************/
/********************* Documintation section  ************************/
/*********************************************************************/
/*********************  NAME    : Ahmed Fathy  ***********************/
/*********************  DATE    : 13/9/2023    ***********************/
/*********************  SEC     :  EXTERNAL_INTERRUPT _AVR   *********/
/*********************  Version : 1.0          ***********************/
/*********************************************************************/

#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H
#include "STD_TYPES.h"
#include "EXTI_private.h"
/*macros for interrupt number*/
#define INT0    0
#define INT1    1    
#define INT2    2


/*macros for sense control*/
#define RISING_EDGE                 1
#define FALLING_EDGE                2
#define LOW_LEVEL                   3
#define ANY_LOGICAL_CHANGE          4  


void GIE_Enable(void);
void GIE_Disable(void);
uint_8 INT_Enable(uint_8 Int_num , uint_8 Int_sensor_control); 
uint_8 set_call_fun(uint_8 INT_Num , void(*App_fun)(void));




 




#endif
