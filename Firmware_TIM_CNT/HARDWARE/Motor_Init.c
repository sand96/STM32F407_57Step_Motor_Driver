
/*	brief:	This function will initialze the port used by the motor including
			two output port and one input port
	param:	Motor_GPIO 		Name of the structure
			Motor_Port 		The used port range from GPIOA TO GPIOK
			Direction_Pin	The direction signal for motor control
			Pluse_Pin 		The pluse signal for the motor control
			Input_Pin 		The control signal to control stm32
	notes: 	The motor control here is DM542.
*/

#include "Motor_Init.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx.h"  

void Motor_GPIO_Init(Motor_GPIO Motor_GPIO)
{
	GPIO_InitTypeDef Motor_GPIO_Struct;

		//Initialize the clock for Motor_GPIO
	if(Motor_GPIO.Motor_Direction_Port == GPIOA) 
	{
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
	}
	else if(Motor_GPIO.Motor_Direction_Port == GPIOB)
	{
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB,ENABLE);
	}
	else if(Motor_GPIO.Motor_Direction_Port == GPIOC)
	{
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC,ENABLE);
	}	
	else if(Motor_GPIO.Motor_Direction_Port == GPIOD)
	{
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD,ENABLE);
	}
	else if(Motor_GPIO.Motor_Direction_Port == GPIOE)
	{
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE,ENABLE);
	}
	else if(Motor_GPIO.Motor_Direction_Port == GPIOF)
	{
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE);
	}	
	else if(Motor_GPIO.Motor_Direction_Port == GPIOG)
	{
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG,ENABLE);
	}
	else if(Motor_GPIO.Motor_Direction_Port == GPIOH)
	{
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOH,ENABLE);
	}
	else if(Motor_GPIO.Motor_Direction_Port == GPIOI)
	{
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOI,ENABLE);
	}
	else if(Motor_GPIO.Motor_Direction_Port == GPIOJ)
	{
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOJ,ENABLE);
	}
	else if(Motor_GPIO.Motor_Direction_Port == GPIOK)
	{
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOK,ENABLE);
	}
		
		//Initialize the output port 
		Motor_GPIO_Struct.GPIO_Pin = Motor_GPIO.Direction_Pin ; //
    Motor_GPIO_Struct.GPIO_Mode = GPIO_Mode_OUT; //output mode 
    Motor_GPIO_Struct.GPIO_OType = GPIO_OType_PP;//push-pull output
    Motor_GPIO_Struct.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
    Motor_GPIO_Struct.GPIO_PuPd = GPIO_PuPd_UP;//Enable pull up resistor
    GPIO_Init(Motor_GPIO.Motor_Direction_Port, &Motor_GPIO_Struct);

	//Test to observe whether the port can be set rightly
//	GPIO_WriteBit(Motor_GPIO.Motor_Port, Motor_GPIO.Pluse_Pin,Bit_SET);
//	GPIO_WriteBit(Motor_GPIO.Motor_Port, Motor_GPIO.Direction_Pin,Bit_SET);
  
	//Initialzie the input pin 	    
    Motor_GPIO_Struct.GPIO_Speed = GPIO_Speed_50MHz; //This isn't necessary
    Motor_GPIO_Struct.GPIO_Pin = Motor_GPIO.Control_Pin;
    Motor_GPIO_Struct.GPIO_Mode = GPIO_Mode_IN; //input mode
    GPIO_Init(Motor_GPIO.Motor_Input_Port, &Motor_GPIO_Struct); 
		
}

/*	brief:	Set the Pluse signal here
*/
/*void Pluse_Signal_Set(unsigned char Pluse_Mode,Motor_GPIO Motor_GPIO)
{
	if(Pluse_Mode == PLUSE_HIGH)//It Pluse is high 
	{
		GPIO_WriteBit(Motor_GPIO.Motor_Port, Motor_GPIO.Pluse_Pin,Bit_SET);
	}
	else if(Pluse_Mode == PLUSE_LOW)//Pluse is low now
	{
		GPIO_WriteBit(Motor_GPIO.Motor_Port, Motor_GPIO.Pluse_Pin,Bit_RESET);
	}
} */

/*	brief:	Set the direction signal here
	notes:  The direction mode is the same to Motor_Mode.
			It's uncessary to define it again
*/
void Direction_Signal_Set(unsigned char Motor_Mode,Motor_GPIO Motor_GPIO)
{
	if(Motor_Mode == MOTOR_FORWARD) //If you want to forward move the motor
	{
		GPIO_WriteBit(Motor_GPIO.Motor_Direction_Port, Motor_GPIO.Direction_Pin,Bit_RESET);	
	}
	else if(Motor_Mode == MOTOR_BACKWARD)
	{
		GPIO_WriteBit(Motor_GPIO.Motor_Direction_Port, Motor_GPIO.Direction_Pin,Bit_SET); 
	}
	else	//If stop, do nothing
	{
		;
	}
}
