#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include  "keypad_interface.h"
#include "stepper_interface.h"

#include  <util/delay.h>
#define  F_CPU  8000000UL

int main()
{

	DIO_INTI();

	MOVE_STEPPER_MOTOR(CCW,9);


	return 0 ;
}



