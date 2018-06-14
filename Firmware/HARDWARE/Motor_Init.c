
/*	brief:	This function will initialze the port used by the motor including
			two output port and one input port
	param:	Motor_GPIO 		Name of the structure
			Motor_Port 		The used port range from GPIOA TO GPIOK
			Direction_Pin	The direction signal for motor control
			Pluse_Pin 		The pluse signal for the motor control
			Input_Pin 		The control signal to control stm32
	notes: 	The motor control here is DM542.
*/
#include "stm32f4xx_gpio.h"
#include "Motor_Init.h"
void Motor_GPIO_Init(Motor_GPIO Motor_GPIO)
{
	GPIO_InitTypeDef Motor_GPIO_Struct;

		//Initialize the clock for Motor_GPIO
	switch(Motor_GPIO.Motor_Port) 
	{
		case GPIOA : RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA)); break;
		case GPIOB : RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB)); break;
		case GPIOC : RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC)); break;
		case GPIOD : RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD)); break;
		case GPIOE : RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE)); break;
		case GPIOF : RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF)); break;
		case GPIOG : RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG)); break;
		case GPIOH : RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOH)); break;
		case GPIOI : RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOI)); break;
		case GPIOJ : RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOJ)); break;
		case GPIOK : RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOK)); break;
		default : break;			
	}

		//Initialize the output port 
	Motor_GPIO_Struct.GPIO_Pin = Motor_GPIO.Direction_Pin | Motor_GPIO.Direction_Pin; //
    Motor_GPIO_Struct.GPIO_Mode = GPIO_Mode_OUT; //output mode 
    Motor_GPIO_Struct.GPIO_OType = GPIO_OType_PP;//push-pull output
    Motor_GPIO_Struct.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
    Motor_GPIO_Struct.GPIO_PuPd = GPIO_PuPd_UP;//Enable pull up resistor
    GPIO_Init(Motor_GPIO.Motor_Port, &Motor_GPIO_Struct);

    	//Initialzie the input pin 	    
    Motor_GPIO_Struct.GPIO_Speed = GPIO_Speed_50MHz; //This isn't necessary
    Motor_GPIO_Struct.GPIO_Pin = Motor_GPIO.Control_Pin;
    Motor_GPIO_Struct.GPIO_Mode = GPIO_Mode_IN; //input mode
    GPIO_Init(Motor_GPIO.Motor_Port, &Motor_GPIO_Struct);        
}

/*	brief:	Set the Pluse signal here
*/
void Pluse_Signal_Set(unsigned char Pluse_Mode, Motor_GPIO Motor_GPIO)
{
	if(Pluse_Mode == PLUSE_HIGH)//It Pluse is high 
	{
		GPIO_WriteBit(Motor_GPIO.Motor_Port, Motor_GPIO.Pluse_Pin,Bit_SET);
	}
	else if(Pluse_Mode == PLUSE_LOW)//Pluse is low now
	{
		GPIO_WriteBit(Motor_GPIO.Motor_Port, Motor_GPIO.Pluse_Pin,Bit_RESET);
	}
}

/*	brief:	Set the direction signal here
	notes:  The direction mode is the same to Motor_Mode.
			It's uncessary to define it again
*/
void Direction_Signal_Set(unsigned char Motor_Mode, Motor_GPIO Motor_GPIO)
{
	if(Motor_Mode == MOTOR_FORWARD) //If you want to forward move the motor
	{
		GPIO_WriteBit(GPIOE, GPIO_Pin_6,Bit_RESET);	
	}
	else if(Motor_Mode == MOTOR_BACKWARD)
	{
		GPIO_WriteBit(GPIOE, GPIO_Pin_6,Bit_SET); 
	}
	else	//If stop, do nothing
	{;}
}