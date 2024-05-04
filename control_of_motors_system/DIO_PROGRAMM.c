#include "BIT_MATH.h"
#include "DIO_Private.h"
#include "DIO_configer.h"
#include "DIO_interface.h"
#include "STD_TYPES.h"

/**************************************************************************************************************/
/**************************************************************************************************************/
/**************************************************************************************************************/

void DIO_INTI(void) {

  DDRA_REG = conc(DIO_PA7_inti_direction, DIO_PA6_inti_direction,
                  DIO_PA5_inti_direction, DIO_PA4_inti_direction,
                  DIO_PA3_inti_direction, DIO_PA2_inti_direction,
                  DIO_PA1_inti_direction, DIO_PA0_inti_direction);

  DDRB_REG = conc(DIO_PB7_inti_direction, DIO_PB6_inti_direction,
                  DIO_PB5_inti_direction, DIO_PB4_inti_direction,
                  DIO_PB3_inti_direction, DIO_PB2_inti_direction,
                  DIO_PB1_inti_direction, DIO_PB0_inti_direction);

  DDRC_REG = conc(DIO_PC7_inti_direction, DIO_PC6_inti_direction,
                  DIO_PC5_inti_direction, DIO_PC4_inti_direction,
                  DIO_PC3_inti_direction, DIO_PC2_inti_direction,
                  DIO_PC1_inti_direction, DIO_PC0_inti_direction);

  DDRD_REG = conc(DIO_PD7_inti_direction, DIO_PD6_inti_direction,
                  DIO_PD5_inti_direction, DIO_PD4_inti_direction,
                  DIO_PD3_inti_direction, DIO_PD2_inti_direction,
                  DIO_PD1_inti_direction, DIO_PD0_inti_direction);

  PORTA_REG = conc(DIO_PA7_inti_value, DIO_PA6_inti_value, DIO_PA5_inti_value,
                   DIO_PA4_inti_value, DIO_PA3_inti_value, DIO_PA2_inti_value,
                   DIO_PA1_inti_value, DIO_PA0_inti_value);

  PORTB_REG = conc(DIO_PB7_inti_value, DIO_PB6_inti_value, DIO_PB5_inti_value,
                   DIO_PB4_inti_value, DIO_PB3_inti_value, DIO_PB2_inti_value,
                   DIO_PB1_inti_value, DIO_PB0_inti_value);

  PORTC_REG = conc(DIO_PC7_inti_value, DIO_PC6_inti_value, DIO_PC5_inti_value,
                   DIO_PC4_inti_value, DIO_PC3_inti_value, DIO_PC2_inti_value,
                   DIO_PC1_inti_value, DIO_PC0_inti_value);

  PORTD_REG = conc(DIO_PD7_inti_value, DIO_PD6_inti_value, DIO_PD5_inti_value,
                   DIO_PD4_inti_value, DIO_PD3_inti_value, DIO_PD2_inti_value,
                   DIO_PD1_inti_value, DIO_PD0_inti_value);
}


/**************************************************************************************************************/
/**************************************************************************************************************/
/**************************************************************************************************************/

uint_8 DIO_set_pin_direction(uint_8 port_id, uint_8 pin_id,
                             uint_8 pin_direction) {
  uint_8 Error_state = Return_Ok;
  if ((port_id <= PORTD) && (pin_id <= PIN7) &&
      (pin_direction == Output || pin_direction == INput)) {

    switch (port_id) {
    /***********  PORTA  *************/
    case (PORTA):
      switch (pin_direction) {
      case (Output):
        SET_BIT(DDRA_REG, pin_id);
        break;

      default:
        CLR_BIT(DDRA_REG, pin_id);
        break;
      }
      break;
    /********************************/

    /***********  PORTB *************/
    case (PORTB):
      switch (pin_direction) {
      case (Output):
        SET_BIT(DDRB_REG, pin_id);
        break;

      default:
        CLR_BIT(DDRB_REG, pin_id);
        break;
      }
      break;
    /********************************/

    /***********  PORTC  ************/
    case (PORTC):
      switch (pin_direction) {
      case (Output):
        SET_BIT(DDRC_REG, pin_id);
        break;

      default:
        CLR_BIT(DDRC_REG, pin_id);
        break;
      }
      break;
      /********************************/

    default:

      switch (pin_direction) {
      case (Output):
        SET_BIT(DDRD_REG, pin_id);
        break;

      default:
        CLR_BIT(DDRD_REG, pin_id);
        break;
      }
      break;
    }

  } else {
    Error_state = Return_NOT_Ok;
  }

  return Error_state;
}

/**************************************************************************************************************/
/**************************************************************************************************************/
/**************************************************************************************************************/

uint_8 DI_set_pin_value(uint_8 port_id, uint_8 pin_id, uint_8 pin_value) {

  uint_8 Error_state = Return_Ok;
  if ((port_id <= PORTD) &&
      (pin_id <= PIN7 && (pin_value == Pin_low || pin_value == Pin_high))) {

    switch (port_id) {
    /********************  Port A  ****************************/
    case (PORTA):

      switch (pin_value) {
      case (Pin_high):
        SET_BIT(PORTA_REG, pin_id);
        break;

      default:
        CLR_BIT(PORTA_REG, pin_id);
        break;
      }

      break;
    /***********************************************************/

    /********************  Port B  ****************************/
    case (PORTB):

      switch (pin_value) {
      case (Pin_high):
        SET_BIT(PORTB_REG, pin_id);
        break;

      default:
        CLR_BIT(PORTB_REG, pin_id);

        break;
      }

      break;

    /***********************************************************/

    /********************  Port C ****************************/
    case (PORTC):

      switch (pin_value) {
      case (Pin_high):
        SET_BIT(PORTC_REG, pin_id);
        break;

      default:
        CLR_BIT(PORTC_REG, pin_id);

        break;
      }

      break;

      /***********************************************************/

      /********************  Port D ****************************/

    default:
      switch (pin_value) {
      case (Pin_high):
        SET_BIT(PORTD_REG, pin_id);
        break;

      default:
        CLR_BIT(PORTD_REG, pin_id);

        break;
      }
      break;
    }

    /***********************************************************/

  } else {

    Error_state = Return_NOT_Ok;
  }

  return Error_state;
}

/**************************************************************************************************************/
/**************************************************************************************************************/
/**************************************************************************************************************/

uint_8 DIO_get_pin_value(uint_8 port_id, uint_8 pin_id,
                         uint_8 *return_pin_value) {

  uint_8 Error_state = Return_Ok;
  if ((port_id <= PORTD) && (pin_id <= PIN7) && (return_pin_value != NULL)) {

    switch (port_id) {
    case (PORTA):
      *return_pin_value = GET_BIT(PINA_REG, pin_id);
      break;
    case (PORTB):
      *return_pin_value = GET_BIT(PINB_REG, pin_id);
      break;
    case (PORTC):
      *return_pin_value = GET_BIT(PINC_REG, pin_id);
      break;
    default:
      *return_pin_value = GET_BIT(PIND_REG, pin_id);
      break;
    }

  } else {

    Error_state = Return_NOT_Ok;
  }

  return Error_state;
}

/**************************************************************************************************************/
/**************************************************************************************************************/
/**************************************************************************************************************/

uint_8 DIO_set_port_direction(uint_8 port_id, uint_8 pin_direction) {

  uint_8 Error_state = Return_Ok;

  if ((port_id <= PORTD) &&
      (pin_direction == Output || pin_direction == INput)) {

    switch (port_id) {

      /******************  PORT A ********************/

    case (PORTA):

      switch (pin_direction) {
      case (Output):
        DDRA_REG = 0xff;
        break;

      default:
        DDRA_REG = 0x00;
        break;
      }

      break;

      /***********************************************/

      /*******************PORT B***********************/
    case (PORTB):

      switch (pin_direction) {
      case (Output):
        DDRB_REG = 0xff;
        break;

      default:
        DDRB_REG = 0x00;
        break;
      }

      break;

      /***************************************************/

      /******************PORT C***************************/
    case (PORTC):

      switch (pin_direction) {
      case (Output):
        DDRC_REG = 0xff;
        break;

      default:
        DDRC_REG = 0x00;
        break;
      }

      break;

      /****************************************************/

      /********************PORT D*************************/
    default:

      switch (pin_direction) {
      case (Output):
        DDRC_REG = 0xff;
        break;

      default:
        DDRC_REG = 0x00;
        break;
      }
      break;
    }

  }
  /****************************************************/
  else {

    Error_state = Return_NOT_Ok;
  }

  return Error_state;
}

/**************************************************************************************************************/
/**************************************************************************************************************/
/**************************************************************************************************************/

uint_8 DI_set_port_value(uint_8 port_id, uint_8 pin_value) {

  uint_8 Error_state = Return_Ok;
  if ((port_id <= PORTD)) {

    switch (port_id) {
    case (PORTA):
      PORTA_REG = pin_value;
      break;

    case (PORTB):
      PORTB_REG = pin_value;
      break;

    case (PORTC):
      PORTC_REG = pin_value;
      break;

    default:
      PORTD_REG = pin_value;
      break;
    }
  }

  else {

    Error_state = Return_NOT_Ok;
  }

  return Error_state;
}
uint_8 DIO_get_port_value(uint_8 port_id, uint_8 *return_port_value) {

  uint_8 Error_state = Return_Ok;
  if ((port_id <= PORTD) && (return_port_value != NULL)) {

    switch (port_id) {
    case (PORTA):
      *return_port_value = PINA_REG;
      break;

    case (PORTB):
      *return_port_value = PINB_REG;
      break;

    case (PORTC):
      *return_port_value = PINC_REG;
      break;

    default:
      *return_port_value = PIND_REG;
      break;
    }
  }

  else {

    Error_state = Return_NOT_Ok;
  }

  return Error_state;
}
