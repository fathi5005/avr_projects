#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "EXTI_interface.h"
#include "LCD_interface.h"
#include "STD_TYPES.h"
#include "keypad_interface.h"
#include "stepper_interface.h"
#include <util/delay.h>


#define F_CPU 8000000UL

uint_8 pattern[8] = {0b00000000, 0b00000100, 0b00010101, 0b00001110,
                     0b00010101, 0b00000100, 0b00000000, 0b00000000};

uint_8 dash[8] = {0b00000000, 0b00000000, 0b00000000, 0b00011111,
                  0b00000000, 0b00000000, 0b00000000, 0b00000000};

uint_8 dot[8] = {0b00000000, 0b00000000, 0b00000000, 0b00001100,
                 0b00001100, 0b00000000, 0b00000000, 0b00000000};

uint_8 key = 0;
uint_8 counter = 0;
uint_8 passwawrd[4] = {0, 0, 0, 0};
uint_8 log_out = 0;
uint_16 degree = 0;
uint_8 test = 0;
uint_8 test1 = 0;
uint_8 test2 = 0;

int main() {

  DIO_INTI();

  while (1) {

    LCD_init();

    LCD_write_string("Enter Passward");
    LCD_move_address_counter_of_DDRAM(LCD_LINE2, 0);

    while (counter < 4) /*to scan the keypad continousily*/
    {

      KeyPad_Return_key(&key);

      if (key != 0xff) /*to check if you press any key or not*/
      {
        if (key == CLAER_LCD) {

          LCD_send_cmnd(0b00000001);
          counter = 0;

          continue;
        }

        // LCD_write_char(key);

        LCD_write_special_char(char2, pattern, LCD_LINE2, counter);

        passwawrd[counter] = key;

        counter++;

        if (counter == 4) {

          if ((passwawrd[0] == '1') && (passwawrd[1] == '2') &&
              (passwawrd[2] == '3') && (passwawrd[3] == '4')) {

            //   DI_set_pin_value(PORTB, PIN0, Pin_high);

            LCD_move_address_counter_of_DDRAM(LCD_LINE1, 0);

            LCD_send_cmnd(0b00000001);

            LCD_write_string("welcome To Motor");

            LCD_move_address_counter_of_DDRAM(LCD_LINE2, 0);

            LCD_write_string("Desh Board");

            test = test + 1;
            _delay_ms(100);
          }
          /*******************************************************************************************************************************************************/
        }
      }

      if (test != 0) {
        break;
      }
    }

    if (test != 0) {
      break;
    }

    log_out++;

    if (log_out == 3) {
      DI_set_pin_value(PORTB, PIN1, Pin_high);

      LCD_send_cmnd(0b00000001);
      LCD_write_string("wrong Passward");

      LCD_send_cmnd(0b00000001);
      LCD_write_string("access failed");

      break;
    }

    counter = 0;

    LCD_send_cmnd(0b00000001);

    LCD_write_string("wrong Passward");
    LCD_send_cmnd(0b00000001);
    LCD_write_string("try again");
    LCD_send_cmnd(0b00000001);
  }

  return 0;
}
