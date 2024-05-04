


#include "stepper_interface.h"

uint_8 MOVE_STEPPER_MOTOR(sint_8 direction , uint_16 angle){

	uint_8 error_state = Return_Ok;
	uint_8 counter2 = (((angle-48)*2048UL)/360)/4;

	if(  ((angle-48)>0)  &&   ((angle-48)<=360)  ){

		switch (direction) {
			case  CW :

				DI_set_pin_value(STEPPER_MOTOR_PORT , STEPPER_MOTOR_FIRST_PIN , Pin_low);
										DI_set_pin_value(STEPPER_MOTOR_PORT , STEPPER_MOTOR_SECOND_PIN , Pin_high);
										DI_set_pin_value(STEPPER_MOTOR_PORT , STEPPER_MOTOR_THIRD_PIN , Pin_high);
										DI_set_pin_value(STEPPER_MOTOR_PORT , STEPPER_MOTOR_FOURTH_PIN , Pin_high);
										_delay_ms(10);

			for(int i = 1 ; i <=counter2 ; i++){


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

			DI_set_pin_value(STEPPER_MOTOR_PORT , STEPPER_MOTOR_FIRST_PIN , Pin_high);
									DI_set_pin_value(STEPPER_MOTOR_PORT , STEPPER_MOTOR_SECOND_PIN , Pin_high);
									DI_set_pin_value(STEPPER_MOTOR_PORT , STEPPER_MOTOR_THIRD_PIN , Pin_high);
									DI_set_pin_value(STEPPER_MOTOR_PORT , STEPPER_MOTOR_FOURTH_PIN , Pin_low);
									_delay_ms(10);




				break;



			default:


				DI_set_pin_value(STEPPER_MOTOR_PORT , STEPPER_MOTOR_FIRST_PIN , Pin_high);
									DI_set_pin_value(STEPPER_MOTOR_PORT , STEPPER_MOTOR_SECOND_PIN , Pin_high);
									DI_set_pin_value(STEPPER_MOTOR_PORT , STEPPER_MOTOR_THIRD_PIN , Pin_high);
									DI_set_pin_value(STEPPER_MOTOR_PORT , STEPPER_MOTOR_FOURTH_PIN , Pin_low);
									_delay_ms(10);


				for(int i = 1 ; i <=(counter2+1) ; i++){


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
