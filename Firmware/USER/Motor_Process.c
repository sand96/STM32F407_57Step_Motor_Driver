/*
*/
#include "stm32f4xx_gpio.h"
#include "Motor_Process.h"
#include "Motor_Init.h"
#include "STM32F407VET_Config.h"

Motor Test_Motor;
//long int Test_flag_1_second;
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
		Test_Motor.Timer_Period = 20000; //This value can be 0 or 1. It doesen't matter 
		Test_Motor.Timer_Period_Final = 1000; //This value can be 0 or 1. It doesen't matter
		Test_Motor.Channel_Pluse = 500; //This value can be 0 or 1. It doesen't matter
 //   Test_Motor.Timer_Delay = Test_Motor_Stop_Delay_MAX; //The bigger the delay is, the slower to increase the speed
 //   Test_Motor.Timer_Delay_Count = 0;
		

    Test_Motor.Motor_GPIO.Motor_Pluse_Port = GPIOA;
    Test_Motor.Motor_GPIO.Motor_Direction_Port = GPIOE;
    Test_Motor.Motor_GPIO.Motor_Input_Port = GPIOA;
    Test_Motor.Motor_GPIO.Direction_Pin = GPIO_Pin_0;
    Test_Motor.Motor_GPIO.Pluse_Pin = GPIO_Pin_1;
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
			{;} //Wait stop
				TIM2StopPwmOut();
				//now the motor want to slow down to stop 
  /*      if( (Motor.Motor_Timer% 2) == 1 )                                         
        {
        // Bar front Step Motor Pulse ---- High Level
         Pluse_Signal_Set(PLUSE_HIGH,Motor.Motor_GPIO);  		
        }
        else if( ( (Motor.Motor_Timer % 2) == 0) && ( (Motor.Motor_GPIO.Motor_Port->ODR & Test_Motor_Pluse ) == Test_Motor_Pluse ) )  
        {
            // Bar front Step Motor Pulse ---- Low Level
             Pluse_Signal_Set(PLUSE_LOW,Motor.Motor_GPIO); 
             Motor.Motor_Position++;
        }
        else
        {;}	 

        if((Motor.Motor_GPIO.Motor_Port->IDR&=Test_Motor_Input) == 0)        
        {
            Motor.Motor_Mode = MOTOR_STOP;
        }          */   
     }  
        //If backward move
 /* else if( Motor.Motor_Mode == MOTOR_BACKWARD )
    {
         // Bar front Step Motor Direction is backward 
         Direction_Signal_Set(Motor.Motor_Mode,Motor.Motor_GPIO);
        if( (Motor.Motor_Timer % 2) == 1 )                                       
        {
            Pluse_Signal_Set(PLUSE_HIGH,Motor.Motor_GPIO); 		
        }
        else if( ( (Motor.Motor_Timer % 2) == 0) && ((Motor.Motor_GPIO.Motor_Port->ODR & Test_Motor_Pluse ) == Test_Motor_Pluse ) )  
        {
            Pluse_Signal_Set(PLUSE_LOW,Motor.Motor_GPIO);        // Bar front Step Motor Pulse ---- Low Level
            if(Motor.Motor_Position > 0 )
            {
                Motor.Motor_Position --;           
            }
            else
            {
                Motor.Motor_Position = 0;
            }
        }
        else
        {;}

       if((Motor.Motor_GPIO.Motor_Port->IDR&=Test_Motor_Input) == 0)              //  Bar Motor Backward Switch, PC8, J20, PC10, J19 
        {
            Motor.Motor_Mode = MOTOR_STOP;
         }
     }
        //If nothing happen
    else
    {
			if( Motor.Motor_Mode_Old == MOTOR_FORWARD )
    {
        // Bar front Step Motor Direction is forward
        Direction_Signal_Set(Motor.Motor_Mode,Motor.Motor_GPIO);     
        if( (Motor.Motor_Timer% 2) == 1 )                                         
        {
        // Bar front Step Motor Pulse ---- High Level
         Pluse_Signal_Set(PLUSE_HIGH,Motor.Motor_GPIO);  		
        }
        else if( ( (Motor.Motor_Timer % 2) == 0) && ( (Motor.Motor_GPIO.Motor_Port->ODR & Test_Motor_Pluse ) == Test_Motor_Pluse ) )  
        {
            // Bar front Step Motor Pulse ---- Low Level
             Pluse_Signal_Set(PLUSE_LOW,Motor.Motor_GPIO); 
             Motor.Motor_Position++;
        }
        else
        {;}	 

        if((Motor.Motor_GPIO.Motor_Port->IDR&=Test_Motor_Input) == 0)        
        {
            Motor.Motor_Mode = MOTOR_STOP;
        }            
     }  
        //If backward move
   else if( Motor.Motor_Mode_Old == MOTOR_BACKWARD )
    {
         // Bar front Step Motor Direction is backward 
        Direction_Signal_Set(Motor.Motor_Mode,Motor.Motor_GPIO);
        if( (Motor.Motor_Timer % 2) == 1 )                                       
        {
            Pluse_Signal_Set(PLUSE_HIGH,Motor.Motor_GPIO); 		
        }
        else if( ( (Motor.Motor_Timer % 2) == 0) && ((Motor.Motor_GPIO.Motor_Port->ODR & Test_Motor_Pluse ) == Test_Motor_Pluse ) )  
        {
            Pluse_Signal_Set(PLUSE_LOW,Motor.Motor_GPIO);        // Bar front Step Motor Pulse ---- Low Level
            if(Motor.Motor_Position > 0 )
            {
                Motor.Motor_Position --;           
            }
            else
            {
                Motor.Motor_Position = 0;
            }
        }
		} 
		else //Now, the speed is low, the motor can stop
		{;}
	} */
}

/* brief:   TIM2 Timer, this will update Motor_Timer according to TIM2 timer
   notes:   All the set need to be finished in the NVIC interrupt mode. Commonly,
            a file called NVIC config is needed. And all the NVIC config should set
            once. Be careful with it. The following code just a set demo.
    demo:   
            void  NVIC_Configuration(void)
            {  
                TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
                NVIC_InitTypeDef NVIC_InitStructure;

                RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);  //Enable the clock for TIM2
                TIM_TimeBaseInitStructure.TIM_Period = 1000-1;    //The automatic reload value
                TIM_TimeBaseInitStructure.TIM_Prescaler=(8400-1);  //presclar of the TIM2
                TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; //Using up count mode
                TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
                
                TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStructure);//Initizlize the TIM2 timer
                
                TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE); //Enable TIM2 to refresh the interrupt
                TIM_Cmd(TIM2,ENABLE); //Enable TIM2
                               
                // Timer 2 Interrupt Configuration
                //This Interrupt is used only for the motor acceleration 
                NVIC_InitStructure.NVIC_IRQChannel=TIM2_IRQn; //TIM2 interrupt  
                NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x01; //PreemptionPriority
                NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x02; //ChannelSubPriority
                NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
                NVIC_Init(&NVIC_InitStructure);
            }
*/
/*void TIM2_IRQHandler(void)
{
    //The interrupt will happen every 500ms.
    //However, the length of interrupt isn't set here.
    //Look the above the explanation carefully. 
    if(TIM_GetITStatus(TIM2,TIM_IT_Update)==SET) //
    {
			Test_Motor.Motor_Timer = ~Test_Motor.Motor_Timer;
    }
    TIM_ClearITPendingBit(TIM2,TIM_IT_Update);  //Reset TIM2 flag
}  */

/* brief:		DMA interrupt handler. Each time will decrease the TImer_Period by 2.
*/
void DMA1_Stream5_IRQHandler(void)
{
	if(DMA_GetITStatus(DMA1_Stream5,DMA_IT_TCIF5)== SET)
	{
		if(Test_Motor.Timer_Period >Test_Motor.Timer_Period_Final)
		{
			Test_Motor.Timer_Period -= 1;
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
