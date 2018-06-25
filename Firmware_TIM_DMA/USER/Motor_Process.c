/*
*/
#include "stm32f4xx_gpio.h"
#include "Motor_Process.h"
#include "Motor_Init.h"
#include "STM32F407VET_Config.h"
#include "delay.h"
Motor Test_Motor;

/*  brief:  This will initialze a motor including all the variabl 
            and port
    notes:  This is just a demo. Anyone wants to use it, you need to
            initilize the motor according to your requirement.
*/
void Motor_Init(void)
{
    /* This is demo
    Motor Test_Motor; //This is just a variable for test.
                      //And needs to decleartion in  the header file 

    Test_Motor.MOTOR_INIT_POSITION = ;
    Test_Motor.MOTOR_TARGET_POSITION = ;
    Test_Motor.Motor_Postion = ;

    Test_Motor.Motor_Mode = ; 

    Test_Motor.Motor_GPIO.Motor_Port =;
    Test_Motor.Motor_GPIO.Motor_Port =;
    Test_Motor.Motor_GPIO.Motor_Port =;
    Test_Motor.Motor_GPIO.Motor_Port =;
    */

    Test_Motor.MOTOR_INIT_POSITION = 0x00000080;
    Test_Motor.MOTOR_TARGET_POSITION = 0x00003B00;
    Test_Motor.Motor_Position = 0;

    Test_Motor.Motor_Mode = MOTOR_STOP; //When you want to test the motor, change here directly
    Test_Motor.Motor_Mode_Old = MOTOR_STOP; //When initialzie, the old mode is also zero 
		Test_Motor.Timer_Period = 40000; 
		Test_Motor.Timer_Period_Final = 3000; 
		Test_Motor.Timer_Period_Init = 40000; 
		Test_Motor.Channel_Pluse = 1500; //This value can be 0 or 1. It doesen't matter
 //   Test_Motor.Timer_Delay = Test_Motor_Stop_Delay_MAX; //The bigger the delay is, the slower to increase the speed
 //   Test_Motor.Timer_Delay_Count = 0;
		

    Test_Motor.Motor_GPIO.Motor_Pluse_Port = GPIOA;
    Test_Motor.Motor_GPIO.Motor_Direction_Port = GPIOE;
    Test_Motor.Motor_GPIO.Motor_Input_Port = GPIOA;
    Test_Motor.Motor_GPIO.Direction_Pin = GPIO_Pin_0;
    Test_Motor.Motor_GPIO.Pluse_Pin = GPIO_Pin_0;
    Test_Motor.Motor_GPIO.Control_Pin = GPIO_Pin_2;

    //Initilize the GPIO port
    Motor_GPIO_Init(Test_Motor.Motor_GPIO);  
}

void  Motor_Process(Motor  Motor)
{
   if( Motor.Motor_Mode == MOTOR_FORWARD )
    {
        // Bar front Step Motor Direction is forward
        Direction_Signal_Set(Motor.Motor_Mode,Motor.Motor_GPIO);     
				TIM2StartPwmOut();
				while(Test_Motor.Motor_Mode != MOTOR_STOP)
				{ 
						//Disable the interrupt if achieve the highest frequency
					if(Test_Motor.Timer_Period == Test_Motor.Timer_Period_Final)
					{	DMA_ITConfig(DMA1_Stream5,DMA_IT_TC,DISABLE);;} 
				;} //Wait stop
				
					//Just for test
		/*		delay_ms(100000);
				Test_Motor.Motor_Mode = MOTOR_STOP;
					//Now stop
				if(Test_Motor.Motor_Mode == MOTOR_STOP)
				{
							//Wait speed decrease
					while(Test_Motor.Timer_Period < Test_Period_Init)
						{;};
				} */ 
     }  
        //If backward move
	else if( Motor.Motor_Mode == MOTOR_BACKWARD )
    {
				//Disable the interrupt if achieve the highest frequency
        Direction_Signal_Set(Motor.Motor_Mode,Motor.Motor_GPIO);     
				TIM2StartPwmOut();
				while(Test_Motor.Motor_Mode != MOTOR_STOP)
				{ 
				if(Test_Motor.Timer_Period == Test_Motor.Timer_Period_Final)
					{	DMA_ITConfig(DMA1_Stream5,DMA_IT_TC,DISABLE);} 
				;} //Wait stop
     }
	else if(Motor.Motor_Mode == MOTOR_STOP)
		{
				//Wait speed decrease
			while(Test_Motor.Timer_Period < Test_Motor.Timer_Period_Init)
			{;}
			TIM2StopPwmOut();
		}
}


/* brief:		DMA interrupt handler. The behavior depends on the Motor_Mode
*/
void DMA1_Stream5_IRQHandler(void)
{
	if(DMA_GetITStatus(DMA1_Stream5,DMA_IT_TCIF5)== SET)
	{
			//It Motor_Mode isn't stop, it will always increase the speed
		if(Test_Motor.Motor_Mode != MOTOR_STOP)
		{
			if(Test_Motor.Timer_Period >Test_Motor.Timer_Period_Final)
			{
				Test_Motor.Timer_Period -= 1;
			}
			DMA_ClearITPendingBit(DMA1_Stream5,DMA_IT_TCIF5); //Clear interrupt flag
		}
			//If the Motor_Mode stop, it will always decrease the speed 
		else if(Test_Motor.Motor_Mode == MOTOR_STOP)
		{
			if(Test_Motor.Timer_Period < Test_Motor.Timer_Period_Init)
			{
				Test_Motor.Timer_Period += 1;
			}
			DMA_ClearITPendingBit(DMA1_Stream5,DMA_IT_TCIF5); //Clear interrupt flag
		}
	}
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
