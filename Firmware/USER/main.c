/*	brief:	This function can control a step motor to increase its speed from zero
						A step motor drive is needed for it work. 
*/
#include "STM32F407VET_Config.h"
#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "Motor_Process.h"
#include "sys.h"
#include "delay.h"

//extern Motor Test_Motor;

int main(void)
{
	  CPU_Initialization();
    delay_init(168);		  //???????//????
	
			//Here, you initialize the Test Motor
			//The Test Motor is needed to be set in the Motor_Process.c
			//However, you don't need to pass the value into the function call
			Motor_Init(); 
	
			Test_Motor.Motor_Mode = MOTOR_BACKWARD;
			Test_Motor.Motor_Mode_Old = MOTOR_BACKWARD;
			Test_flag_1_second = 0;
	
	
	while(1)
	{
			Motor_Process(Test_Motor);
			if(Test_Motor.Timer_Delay == Test_Motor_Stop_Delay_MIN)
			{
				if(Test_flag_1_second == 100 )
				{Test_Motor.Motor_Mode = MOTOR_STOP;}
			}
  }
}
