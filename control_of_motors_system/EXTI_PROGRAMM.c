
#include "EXTI_interface.h"
#include "EXTI_private.h"


void (*INT_array[3])(void) = {NULL,NULL,NULL};


void GIE_Enable(void){

    SET_BIT(SREG_GIE_REG,7);

}

void GIE_Disable(void){

    CLR_BIT(SREG_GIE_REG,7);

}





uint_8 set_call_fun(uint_8 INT_Num , void(*App_fun)(void)){

    uint_8 Error_state = Return_Ok;

    if( (INT_Num<=INT2) &&  (App_fun!=NULL)){
        INT_array[INT_Num]=App_fun;

    }
    else{
    Error_state=Return_NOT_Ok;
    }

return Error_state;


}

uint_8 INT_Enable(uint_8 Int_num , uint_8 Int_sensor_control){

    uint_8 Error_state=Return_Ok;

    if(  (Int_num==INT0||Int_num==INT1||Int_num==INT2)    &&   
      (Int_sensor_control==RISING_EDGE||  Int_sensor_control==FALLING_EDGE  ||
       Int_sensor_control==LOW_LEVEL ||Int_sensor_control==ANY_LOGICAL_CHANGE)  )
    {

switch (Int_num)
{

 /********************************************************************************************/
case (INT0): //1


switch (Int_sensor_control)
{
    case (RISING_EDGE):
        SET_BIT(MCUCR_SENSE_CONTROL_REG,0);
        SET_BIT(MCUCR_SENSE_CONTROL_REG,1);
        SET_BIT(GICR_PIE_REG,6);
    break;

    case  (FALLING_EDGE):
        CLR_BIT(MCUCR_SENSE_CONTROL_REG,0);
        SET_BIT(MCUCR_SENSE_CONTROL_REG,1);
        SET_BIT(GICR_PIE_REG,6);
    break;

    case  (LOW_LEVEL) :
        CLR_BIT(MCUCR_SENSE_CONTROL_REG,0);
        CLR_BIT(MCUCR_SENSE_CONTROL_REG,1);
        SET_BIT(GICR_PIE_REG,6);
    break;

default: /*ANY_LOGICAL_CHANGE*/

        SET_BIT(MCUCR_SENSE_CONTROL_REG,0);
        CLR_BIT(MCUCR_SENSE_CONTROL_REG,1);
        SET_BIT(GICR_PIE_REG,6);

    break;
}



    break;//1


 /********************************************************************************************/
    case( INT1)://2


switch (Int_sensor_control)
{
    case (RISING_EDGE):
        SET_BIT(MCUCR_SENSE_CONTROL_REG,2);
        SET_BIT(MCUCR_SENSE_CONTROL_REG,3);
        SET_BIT(GICR_PIE_REG,7);
    break;

    case  (FALLING_EDGE):
        CLR_BIT(MCUCR_SENSE_CONTROL_REG,2);
        SET_BIT(MCUCR_SENSE_CONTROL_REG,3);
        SET_BIT(GICR_PIE_REG,7);
    break;

    case  (LOW_LEVEL) :
        CLR_BIT(MCUCR_SENSE_CONTROL_REG,2);
        CLR_BIT(MCUCR_SENSE_CONTROL_REG,3);
        SET_BIT(GICR_PIE_REG,7);
    break;

default: /*ANY_LOGICAL_CHANGE*/

        SET_BIT(MCUCR_SENSE_CONTROL_REG,2);
        CLR_BIT(MCUCR_SENSE_CONTROL_REG,3);
        SET_BIT(GICR_PIE_REG,7);

    break;
}


    break;//2
 /********************************************************************************************/
default://3  /*INT2*/

switch (Int_sensor_control)
{
    case (RISING_EDGE):

    SET_BIT(MCUCSR_SENSE_CONTROL_REG,6);
    SET_BIT(GICR_PIE_REG,5);
    break;

    case  (FALLING_EDGE):

    CLR_BIT(MCUCSR_SENSE_CONTROL_REG,6);
    SET_BIT(GICR_PIE_REG,5);
    break;

    default:

     Error_state=Return_NOT_Ok;

    break;
}



    break;//3


 /********************************************************************************************/

}


    }
    else{
        Error_state=Return_NOT_Ok;

    }

return  Error_state;
}


void __vector_1 (void)      __attribute__((signal));
void __vector_1 (void) {
    
    if(INT_array[INT0]!=NULL){
    INT_array[INT0]();
    }



}
void __vector_2 (void)      __attribute__((signal));
void __vector_2 (void) {

if(INT_array[INT1]!=NULL){
    INT_array[INT1]();
    }


    
}
void __vector_3 (void)      __attribute__((signal));
void __vector_3 (void) {

if(INT_array[INT2]!=NULL){
    INT_array[INT2]();
    }


    
}
