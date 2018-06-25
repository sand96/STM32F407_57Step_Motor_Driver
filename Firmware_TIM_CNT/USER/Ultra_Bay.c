#include "Global_Variant.h"
#include "Ultra_Bay.h"
#include "Motor_Process.h"
#include "delay.h"

/* \brief 	Initialize all the paramter which are used by devices
						, which are several motors, charger and etc.
		\notes 	???Why don't initilize all the motors? for example, just 
						???there motor get initial postion
*/
void Ultra_Bay_Initialization(void)
{
		guc_bar_front_motor_mode = MOTOR_STOP;

		//This variable used to increase the speed of the motor
		delay_count_motor = DELAY_MOTOR_MAX; 
		delay_count_motor_flag = 0;
	

	
		//The initilization position is little with the initial 
		//postion in the Motor_Process.h
    gul_bar_front_motor_position = 1000000;
}

/* \brief	microsecond level delay
	 \param	int x, the input number, which will set the number 
					of delay.
*/
void delay_ms(unsigned int x)
{
	unsigned int aaa;
	unsigned int bbb;
	bbb=0;
	//gul_delay_timer = 0;
	for(aaa = 0; aaa<x; aaa++)
	{
		//The us delay
		for(bbb=0;bbb<1000;bbb++);
	}
}


