/*********************************************************************/
/********************* Documintation section  ************************/
/*********************************************************************/
/*********************  NAME    : Ahmed Fathy  ***********************/
/*********************  DATE    : 21/9/2023    ***********************/
/*********************  SEC     :  KEYPAD _AVR        ***********************/
/*********************  Version : 1.0          ***********************/
/*********************************************************************/

#include "STD_TYPES.h"
#include "keypad_interface.h"

#define F_CPU 8000000UL
#include <util/delay.h>


const uint_8 keypad_row_num[4] = {KEYPAD_R1, KEYPAD_R2, KEYPAD_R3,KEYPAD_R4};

const uint_8 keypad_colum_num[4] = {KEYPAD_C1, KEYPAD_C2, KEYPAD_C3, KEYPAD_C4};
                             
const uint_8 Keypad_shape[4][4] = KPD_FRAM;

/***************************************************************************************************/
/***************************************************************************************************/

uint_8 KeyPad_Return_key(uint_8 *returned_key) {

	*returned_key = 0xff;
  uint_8 flag = 0;

  uint_8 Error_state = Return_Ok;

  uint_8 Returned_pin_value = 0;

  //DI_set_port_value(PORTA, 0xff); /******** will set all pins from DIO configer file   *******/

  if (returned_key != NULL) {

    for (uint_8 row_num = 0; row_num < 4; row_num++) {

      DI_set_pin_value(KEYPAD_PORT, keypad_row_num[row_num], Pin_low);
     
      for (uint_8 colum_num = 0; colum_num < 4; colum_num++) {

        DIO_get_pin_value(KEYPAD_PORT, keypad_colum_num[colum_num],&Returned_pin_value);
                          
        if (Returned_pin_value == Pin_low) {

            /*there are two problems when prrssing on any key*/

            /*
            1- BOuncing and its solution is delaying function
            2-time of press on the key is greater than the excution time of processor 
            so when you pree on the key it will be displaied more than one time on LCD 
            */
            

            /*the first problem bouncing*/

          _delay_ms(20); /*delay to solve it */

            /*the second problem of displaying the key more than one time on the LCD  */

            /*After solving the Bouncing  the are two options 
            1- you still press on the key
            2- you are no longer press on the key
            */

           /*
           1- read the pins again to update its value
           2-if its value still low that mean you still press on the key
           so we using while loop to update the value of the pin until iys value chang to high
           */

         /*1-*/ DIO_get_pin_value(KEYPAD_PORT, keypad_colum_num[colum_num],&Returned_pin_value); 
                            

         /*2-*/ while (Returned_pin_value == Pin_low) /* comment*/
          {

            DIO_get_pin_value(KEYPAD_PORT, keypad_colum_num[colum_num], &Returned_pin_value); /* comment*/
                             
          }

          *returned_key = Keypad_shape[row_num][colum_num];

          flag = 1;

          break;
        }
      }

      DI_set_pin_value(KEYPAD_PORT, keypad_row_num[row_num], Pin_high);

      if (flag == 1) {

        break;
      }
    }
  }

  else {

    Error_state = Return_NOT_Ok;
  }

  return Error_state;
}
