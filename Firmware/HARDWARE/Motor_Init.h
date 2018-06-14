#ifndef __MOTOR_INIT_H
#define __MOTOR_INIT_H

void Motor_Process(void);
void Motor_Init(void);	//Initialize the motor


	//There different mode for motor movement
#define MOTOR_STOP           0
#define MOTOR_FORWARD        1
#define MOTOR_BACKWARD       2
	//Two diferent mode for pluse signal 
	//It can only be high and low
#define PLUSE_HIGH	1
#define PLUSE_LOW	0

	//Define a structue for motor process
typedef structue Motor
{
	//variable for position information
	unsigned long int MOTOR_INIT_POSITION; 		//Initial position, it's costant
	unsigned long int MOTOR_TARGET_POSITION;	//Target position, it's constant
	unsigned long int Motor_Position;	//current position

	//Variable for mode information
	unsigned char Motor_Mode; //It can be forward, backward and stop.

	Motor_GPIO Motor_GPIO;

}

typedef structue Motor_GPIO
{
	//The input pin and output pin
	//Each motor control driver needs two control signal
	unsigned char Motor_Port;		//The port used by the Motor
	unsigned char Direction_Pin; //Output pin
	unsigned char Pluse_Pin;	//Output pin
	unsigned char Control_Pin; //Input pin to control the communication between STM32 and central processor
}
#endif 

