/*	brief:	This function can control a step motor to increase its speed from zero
						A step motor drive is needed for it work. 
*/
#include "STM32F407VET_Config.h"
#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "Global_Variant.h"
#include "Motor_Process.h"
#include "sys.h"
#include "delay.h"
#include "Ultra_Bay.h"



int main(void)
{

	  CPU_Initialization();
    Ultra_Bay_Initialization();
    delay_init(168);		  //???????//????
		
	while(1)
	{
       Bar_Front_Motor_Process();
    }
}
