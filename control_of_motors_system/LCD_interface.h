/*********************************************************************/
/********************* Documintation section  ************************/
/*********************************************************************/
/*********************  NAME    : Ahmed Fathy  ***********************/
/*********************  DATE    : 17/9/2023    ***********************/
/*********************  SEC     : LCD _AVR        ***********************/
/*********************  Version : 1.0          ***********************/
/*********************************************************************/

#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H
#include "STD_TYPES.h"

void LCD_init(void);
void LCD_send_cmnd(uint_8 cmnd);
void LCD_write_char(uint_8 data);
void LCD_write_string(uint_8 *ptr);
void LCD_write_number(uint_16 number);
uint_8 LCD_move_address_counter_of_DDRAM(uint_8 line_num, uint_8 location_num);
uint_8 LCD_write_special_char(uint_8 char_num, uint_8 *pattern, uint_8 line_num, uint_8 loaction);


/* macros for move_address_counter_of_DDRAM */

#define LCD_LINE1 1
#define LCD_LINE2 2

/* macros for special char */

#define char0 0
#define char1 1
#define char2 2
#define char3 3
#define char4 4
#define char5 5
#define char6 6
#define char7 7

#endif
