#ifndef __MOTOR_PROCESS_H
#define __MOTOR_PROCESS_H

#include "Motor_Init.h"

#define Test_Motor_Pluse 0x000000002 //This isn't constant and needed to be changed according to your intialization
#define Test_Motor_Input 0x000000004 //This isn't constant and needed to be changed according to your intialization 
#define Test_Motor_Stop_Delay_MAX 2000
#define Test_Motor_Stop_Delay_MIN 20
extern Motor Test_Motor;
extern long int Test_flag_1_second;

void Motor_Init(void);
void Motor_Process(Motor Motor);
void delay_ms(unsigned int x);
#endif 

