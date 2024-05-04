


#include "stepper_interface.h"

uint_8 MOVE_STEPPER_MOTOR(sint_8 direction , uint_16 angle){

	uint_8 error_state = Return_Ok;
	uint_8 counter = (((angle)*2048UL)/360)/4;

	if(  (angle>0)  &&   (angle<=360)  ){

		switch (direction) {
			case  CW :

				/*power to the motor*/



				/*#define STEPPER_MOTOR_FIRST_PIN			PIN0
#define STEPPER_MOTOR_SECOND_PIN		PIN1
#define STEPPER_MOTOR_THIRD_PIN			PIN2
#define STEPPER_MOTOR_FOURTH_PIN*/

				DI_set_pin_value(STEPPER_MOTOR_PORT, STEPPER_MOTOR_FIRST_PIN , Pin_low);
				DI_set_pin_value(STEPPER_MOTOR_PORT , STEPPER_MOTOR_SECOND_PIN , Pin_high);
				DI_set_pin_value(STEPPER_MOTOR_PORT , STEPPER_MOTOR_THIRD_PIN , Pin_high);
				DI_set_pin_value(STEPPER_MOTOR_PORT , STEPPER_MOTOR_FOURTH_PIN , Pin_high);
				_delay_ms(10);


			for(int i = 1 ; i <=counter ; i++){


						DI_set_pin_value(STEPPER_MOTOR_PORT , STEPPER_MOTOR_FIRST_PIN , Pin_high);
						DI_set_pin_value(STEPPER_MOTOR_PORT , STEPPER_MOTOR_SECOND_PIN , Pin_high);
						DI_set_pin_value(STEPPER_MOTOR_PORT , STEPPER_MOTOR_THIRD_PIN , Pin_high);
						DI_set_pin_value(STEPPER_MOTOR_PORT , STEPPER_MOTOR_FOURTH_PIN , Pin_low);
						_delay_ms(10);

						DI_set_pin_value(STEPPER_MOTOR_PORT , STEPPER_MOTOR_FIRST_PIN , Pin_high);
						DI_set_pin_value(STEPPER_MOTOR_PORT , STEPPER_MOTOR_SECOND_PIN , Pin_high);
						DI_set_pin_value(STEPPER_MOTOR_PORT , STEPPER_MOTOR_THIRD_PIN , Pin_low);
						DI_set_pin_value(STEPPER_MOTOR_PORT , STEPPER_MOTOR_FOURTH_PIN , Pin_high);
						_delay_ms(10);

						DI_set_pin_value(STEPPER_MOTOR_PORT , STEPPER_MOTOR_FIRST_PIN , Pin_high);
						DI_set_pin_value(STEPPER_MOTOR_PORT , STEPPER_MOTOR_SECOND_PIN , Pin_low);
						DI_set_pin_value(STEPPER_MOTOR_PORT , STEPPER_MOTOR_THIRD_PIN , Pin_high);
						DI_set_pin_value(STEPPER_MOTOR_PORT , STEPPER_MOTOR_FOURTH_PIN , Pin_high);
						_delay_ms(10);



						DI_set_pin_value(STEPPER_MOTOR_PORT , STEPPER_MOTOR_FIRST_PIN , Pin_low);
						DI_set_pin_value(STEPPER_MOTOR_PORT , STEPPER_MOTOR_SECOND_PIN , Pin_high);
						DI_set_pin_value(STEPPER_MOTOR_PORT , STEPPER_MOTOR_THIRD_PIN , Pin_high);
						DI_set_pin_value(STEPPER_MOTOR_PORT , STEPPER_MOTOR_FOURTH_PIN , Pin_high);
						_delay_ms(10);





			}

				break;



			default:



				/*power to the motor*/
				DI_set_pin_value(STEPPER_MOTOR_PORT, STEPPER_MOTOR_FIRST_PIN , Pin_high);
				DI_set_pin_value(STEPPER_MOTOR_PORT , STEPPER_MOTOR_SECOND_PIN , Pin_high);
				DI_set_pin_value(STEPPER_MOTOR_PORT , STEPPER_MOTOR_THIRD_PIN , Pin_high);
				DI_set_pin_value(STEPPER_MOTOR_PORT , STEPPER_MOTOR_FOURTH_PIN , Pin_low);
				_delay_ms(10);


				for(int i = 1 ; i <=counter ; i++){


					DI_set_pin_value(STEPPER_MOTOR_PORT , STEPPER_MOTOR_FIRST_PIN , Pin_low);
					DI_set_pin_value(STEPPER_MOTOR_PORT , STEPPER_MOTOR_SECOND_PIN , Pin_high);
					DI_set_pin_value(STEPPER_MOTOR_PORT , STEPPER_MOTOR_THIRD_PIN , Pin_high);
					DI_set_pin_value(STEPPER_MOTOR_PORT , STEPPER_MOTOR_FOURTH_PIN , Pin_high);
					_delay_ms(10);

					DI_set_pin_value(STEPPER_MOTOR_PORT , STEPPER_MOTOR_FIRST_PIN , Pin_high);
					DI_set_pin_value(STEPPER_MOTOR_PORT , STEPPER_MOTOR_SECOND_PIN , Pin_low);
					DI_set_pin_value(STEPPER_MOTOR_PORT , STEPPER_MOTOR_THIRD_PIN , Pin_high);
					DI_set_pin_value(STEPPER_MOTOR_PORT , STEPPER_MOTOR_FOURTH_PIN , Pin_high);
					_delay_ms(10);

					DI_set_pin_value(STEPPER_MOTOR_PORT , STEPPER_MOTOR_FIRST_PIN , Pin_high);
					DI_set_pin_value(STEPPER_MOTOR_PORT , STEPPER_MOTOR_SECOND_PIN , Pin_high);
					DI_set_pin_value(STEPPER_MOTOR_PORT , STEPPER_MOTOR_THIRD_PIN , Pin_low);
					DI_set_pin_value(STEPPER_MOTOR_PORT , STEPPER_MOTOR_FOURTH_PIN , Pin_high);
					_delay_ms(10);



					DI_set_pin_value(STEPPER_MOTOR_PORT , STEPPER_MOTOR_FIRST_PIN , Pin_high);
					DI_set_pin_value(STEPPER_MOTOR_PORT , STEPPER_MOTOR_SECOND_PIN , Pin_high);
					DI_set_pin_value(STEPPER_MOTOR_PORT , STEPPER_MOTOR_THIRD_PIN , Pin_high);
					DI_set_pin_value(STEPPER_MOTOR_PORT , STEPPER_MOTOR_FOURTH_PIN , Pin_low);
					_delay_ms(10);



			}
				break;
		}






	}

	else{

		error_state=Return_NOT_Ok;

	}


	return error_state;


}
