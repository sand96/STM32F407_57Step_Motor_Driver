#ifndef __MOTOR_INIT_H
#define __MOTOR_INIT_H

#include "stm32f4xx_gpio.h"
#include "stm32f4xx.h"  
    
	//There different mode for motor movement
#define MOTOR_STOP           0
#define MOTOR_FORWARD        1
#define MOTOR_BACKWARD       2
	//Two diferent mode for pluse signal 
	//It can only be high and low
#define PLUSE_HIGH	1
#define PLUSE_LOW	0

	//This will be used by TIM2_GPIO_Config function
typedef struct
{
	//The input pin and output pin
	//Each motor control driver needs two control signal
	GPIO_TypeDef* Motor_Direction_Port;		//The port used by the direction pin
	GPIO_TypeDef* Motor_Pluse_Port;	//The port used by the pluse pin
	GPIO_TypeDef* Motor_Input_Port;	//The port used by the input pin
	unsigned char Direction_Pin; //Output pin
	unsigned char Pluse_Pin;	//Output pin
	unsigned char Control_Pin; //Input pin to control the communication between STM32 and central processor
} Motor_GPIO;

	//Define a structue for motor process
typedef struct
{
	//variable for position information
	unsigned long int MOTOR_INIT_POSITION; 		//Initial position, it's costant
	unsigned long int MOTOR_TARGET_POSITION;	//Target position, it's constant
	unsigned long int Motor_Position;	//current position

	//Variable for mode information
	unsigned char Motor_Mode; //It can be forward, backward and stop.
	unsigned char Motor_Mode_Old; //Store the odd information of Motor_Mode, you need to refresh the Old_Mode manually
	unsigned long int Timer_Period;//Motor timer control, in order to conrtrol the pluse precisely
	unsigned long int Timer_Period_Final; //The final timer_period that should achieve
	unsigned long int Channel_Pluse;//duty ration
	Motor_GPIO Motor_GPIO;
} Motor;

void Motor_GPIO_Init(Motor_GPIO Motor_GPIO);	//Initialize the port
//void Pluse_Signal_Set(unsigned char Pluse_Mode,Motor_GPIO Motor_GPIO);		//control the pluse
void Direction_Signal_Set(unsigned char Motor_Mode,Motor_GPIO Motor_GPIO); //Control the direction


#endif 

