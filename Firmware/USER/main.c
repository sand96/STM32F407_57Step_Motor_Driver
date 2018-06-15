/*	brief:	This function can control a step motor to increase its speed from zero
						A step motor drive is needed for it work. 
*/
#include "STM32F407VET_Config.h"
#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "Motor_Process.h"
#include "sys.h"
#include "delay.h"

extern Motor Test_Motor;
int main(void)
{
	  CPU_Initialization();
    delay_init(168);		  //???????//????
	
			//The Test Motor is needed to be set in the Motor_Process.c//
		Motor_Init(Test_Motor); 
		
		Test_Motor.Motor_Mode = MOTOR_FORWARD;
	
	///Test
	GPIO_InitTypeDef Motor_GPIO_Struct;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
		
		//Initialize the output port 
		Motor_GPIO_Struct.GPIO_Pin = GPIO_Pin_4; //
    Motor_GPIO_Struct.GPIO_Mode = GPIO_Mode_OUT; //output mode 
    Motor_GPIO_Struct.GPIO_OType = GPIO_OType_PP;//push-pull output
    Motor_GPIO_Struct.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
    Motor_GPIO_Struct.GPIO_PuPd = GPIO_PuPd_UP;//Enable pull up resistor
    GPIO_Init(GPIOA, &Motor_GPIO_Struct);
	
	GPIO_WriteBit(GPIOA, GPIO_Pin_4,Bit_SET); 
	
	while(1)
	{
			Motor_Process(Test_Motor);
		
  }
}
