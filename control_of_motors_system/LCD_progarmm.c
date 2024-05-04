/*********************************************************************/
/********************* Documintation section  ************************/
/*********************************************************************/
/*********************  NAME    : Ahmed Fathy  ***********************/
/*********************  DATE    : 17/9/2023    ***********************/
/*********************  SEC     : LCD _AVR     ***********************/
/*********************  Version : 1.0          ***********************/
/*********************************************************************/

/*LIB include*/

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#define F_CPU 8000000UL
#include <util/delay.h>

/*DIO includes*/
#include "DIO_interface.h"

/*LCD includes*/
#include "LCD_config.h"
#include "LCD_interface.h"
#include "LCD_private.h"

void LCD_init(void) {

#if LCD_MODE == LCD_8_BIT_MODE
  /*8_bit initialization for LCD */

  _delay_ms(35);

  LCD_send_cmnd(0b00111000);

  _delay_us(40);

  LCD_send_cmnd(0b00001111);

  _delay_us(40);

  LCD_send_cmnd(0b00000001);

  _delay_ms(2);

  LCD_send_cmnd(0b00000110);

#elif LCD_MODE == LCD_4_BIT_MODE

  _delay_ms(35);

  LCD_send_cmnd(0b00100000);
  LCD_send_cmnd(0b00100000);
  LCD_send_cmnd(0b10000000);

  _delay_us(40);

  LCD_send_cmnd(0b00000000);
  LCD_send_cmnd(0b11110000);

  _delay_us(40);

  LCD_send_cmnd(0b00000000);
  LCD_send_cmnd(0b00010000);

  _delay_ms(2);

  LCD_send_cmnd(0b00000000);
  LCD_send_cmnd(0b01100000);

#endif
}
void LCD_send_cmnd(uint_8 cmnd) {

  /*directons of all pins will be set from config file of DIO driver*/

#if LCD_MODE == LCD_8_BIT_MODE

  DI_set_pin_value(LCD_PORT_RS, LCD_PIN_RS,
                   Pin_low); /* RS low vlotage to recive cmnd*/

  DI_set_pin_value(LCD_PORT_Rw, LCD_PIN_RW,
                   Pin_low); /* RW low vlotage to write on LCD*/

  DI_set_port_value(LCD_PORT_DATA,
                    cmnd); /* wrire cmnd on port that is connected with LCD*/

  DI_set_pin_value(
      LCD_PORT_EN, LCD_PIN_EN,
      Pin_high); /*active enable of LCD to make LCD read the cmnd or data*/

  _delay_us(1); /*delay form En = 0 to En =1  from datasheet page 5*/

  DI_set_pin_value(LCD_PORT_EN, LCD_PIN_EN, Pin_low); /*cancel enable of LCD */

#elif LCD_MODE == LCD_4_BIT_MODE

  DI_set_pin_value(LCD_PORT_RS, LCD_PIN_RS,
                   Pin_low); /* RS low vlotage to recive cmnd*/

  DI_set_pin_value(LCD_PORT_Rw, LCD_PIN_RW,
                   Pin_low); /* RW low vlotage to write on LCD*/

  DI_set_port_value(LCD_PORT_DATA,
                    cmnd << 4); /* wrire cmnd on 4 high bit on   port that is
                                   connected with LCD*/

  DI_set_pin_value(
      LCD_PORT_EN, LCD_PIN_EN,
      Pin_high); /*active enable of LCD to make LCD read the cmnd or data*/

  _delay_us(1); /*delay form En = 0 to En =1  from datasheet page 5*/

  DI_set_pin_value(LCD_PORT_EN, LCD_PIN_EN, Pin_low); /*cancel enable of LCD */

  /*send the second half of the cmnd because LCD 4bit mode recive cmnd on only 4
   * pins D4 to D7*/

  DI_set_port_value(
      LCD_PORT_DATA,
      cmnd); /* wrire cmnd on 4 low bit on port that is connected with LCD*/

  DI_set_pin_value(
      LCD_PORT_EN, LCD_PIN_EN,
      Pin_high); /*active enable of LCD to make LCD read the cmnd or data*/

  _delay_us(1); /*delay form En = 0 to En =1  from datasheet page 5*/

  DI_set_pin_value(LCD_PORT_EN, LCD_PIN_EN, Pin_low);
      /*cancel enable of LCD */ /*cancel enable of LCD */

#endif
}
void LCD_write_char(uint_8 data) {

#if LCD_MODE == LCD_8_BIT_MODE

  DI_set_pin_value(LCD_PORT_RS, LCD_PIN_RS,
                   Pin_high); /* RS high vlotage to recive data*/

  DI_set_pin_value(LCD_PORT_Rw, LCD_PIN_RW,
                   Pin_low); /* RW low vlotage to write on LCD*/

  DI_set_port_value(LCD_PORT_DATA,
                    data); /* wrire cmnd on port that is connected with LCD*/

  DI_set_pin_value(
      LCD_PORT_EN, LCD_PIN_EN,
      Pin_high); /*active enable of LCD to make LCD read the cmnd or data*/

  _delay_us(1); /*delay form En = 0 to En =1  from datasheet page 5*/

  DI_set_pin_value(LCD_PORT_EN, LCD_PIN_EN, Pin_low); /*cancel enable of LCD */

#elif LCD_MODE == LCD_4_BIT_MODE

  DI_set_pin_value(LCD_PORT_RS, LCD_PIN_RS,
                   Pin_high); /* RS high vlotage to recive data*/

  DI_set_pin_value(LCD_PORT_Rw, LCD_PIN_RW,
                   Pin_low); /* RW low vlotage to write on LCD*/

  DI_set_port_value(LCD_PORT_DATA,
                    data); /* wrire cmnd on port that is connected with LCD*/

  DI_set_pin_value(
      LCD_PORT_EN, LCD_PIN_EN,
      Pin_high); /*active enable of LCD to make LCD read the cmnd or data*/

  _delay_us(1); /*delay form En = 0 to En =1  from datasheet page 5*/

  DI_set_pin_value(LCD_PORT_EN, LCD_PIN_EN, Pin_low); /*cancel enable of LCD */

  /*send the second half of the data because LCD 4bit mode recive cmnd on only 4
   * pins D4 to D7*/

  DI_set_port_value(
      LCD_PORT_DATA,
      data
          << 4); /* wrire cmnd on 4 low bit on port that is connected with LCD*/

  DI_set_pin_value(
      LCD_PORT_EN, LCD_PIN_EN,
      Pin_high); /*active enable of LCD to make LCD read the cmnd or data*/

  _delay_us(1); /*delay form En = 0 to En =1  from datasheet page 5*/

  DI_set_pin_value(LCD_PORT_EN, LCD_PIN_EN, Pin_low); /*cancel enable of LCD */

#endif
}

void LCD_write_string(uint_8 *ptr) {

  uint_8 counter = 0;
  if (ptr != NULL) {
    while (ptr[counter] != '\0') {

      LCD_write_char(ptr[counter]);

      counter++;
      _delay_ms(10);
    }
  }
}

uint_8 LCD_move_address_counter_of_DDRAM(uint_8 line_num, uint_8 location_num) {

  uint_8 Error_state = Return_Ok;
  if ((line_num == LCD_LINE1 || line_num == LCD_LINE2) &&
      (location_num <= 39)) {

    switch (line_num) {

    case LCD_LINE1:
      LCD_send_cmnd(0x80 + location_num);
      break;

    default:
      LCD_send_cmnd(0xc0 + location_num);
      break;
    }
  }

  else {

    Error_state = Return_NOT_Ok;
  }

  return Error_state;
}

uint_8 LCD_write_special_char(uint_8 char_num, uint_8 *pattern, uint_8 line_num, uint_8 loaction) {


  uint_8 Error_state = Return_Ok;

  if ((char_num <= 7) && (line_num == 1 || line_num == 2) && (loaction <= 39)) {
    switch (char_num) {

      /* set address counter in CGRAM*/

    case char0:
      LCD_send_cmnd(0b01000000);
      break;

    case char1:
      LCD_send_cmnd(0b01001000);
      break;

    case char2:
      LCD_send_cmnd(0b01010000);
      break;
    case char3:
      LCD_send_cmnd(0b01011000);
      break;

    case char4:
      LCD_send_cmnd(0b01100000);
      break;
    case char5:
      LCD_send_cmnd(0b01101000);
      break;

    case char6:
      LCD_send_cmnd(0b01110000);
      break;

    default:
      LCD_send_cmnd(0b01111000);
      break;
    }

    /*wtite special char in CGRAM*/

    for (int i = 0; i < 8; i++) {
      LCD_write_char(pattern[i]);
    }
    /*return address counter to DDRAM*/
    LCD_move_address_counter_of_DDRAM(line_num, loaction);

    switch (char_num) {

      /* show the required char in CGRAM */

    case char0:
      LCD_write_char(0);
      break;

    case char1:
      LCD_write_char(1);
      break;

    case char2:
      LCD_write_char(2);
      break;

    case char3:
      LCD_write_char(3);
      break;

    case char4:
      LCD_write_char(4);
      break;

    case char5:
      LCD_write_char(5);
      break;

    case char6:
      LCD_write_char(6);
      break;

    default:
      LCD_write_char(7);
      break;
    }

  }

  else {

    Error_state = Return_NOT_Ok;
  }

  return Error_state;
}
