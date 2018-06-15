#ifndef __MOTOR_PROCESS_H
#define __MOTOR_PROCESS_H

#include "Motor_Init.h"

#define Test_Motor_Pluse 0x000000002 //This isn't constant and needed to be changed according to your intialization
#define Test_Motor_Input 0x000000004 //This isn't constant and needed to be changed according to your intialization 

extern Motor Test_Motor;

void Motor_Init(void);
void Motor_Process(Motor Motor);
void delay_ms(unsigned int x);
#endif 

