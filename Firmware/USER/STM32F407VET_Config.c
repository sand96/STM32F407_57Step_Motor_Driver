#include "STM32F407VET_Config.h"
#include "stm32f4xx.h"                  // Device header
#include "stm32f4xx_gpio.h"
#include "misc.h" 


void NVIC_Configuration(void);

void CPU_Initialization(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//Set priority groups
    NVIC_Configuration();
	//	SysTick_Config(SystemCoreClock / 20000);
}




void  NVIC_Configuration(void)
{  
  TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;


	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);  //Enable the clock for TIM2
  TIM_TimeBaseInitStructure.TIM_Period = 10-1; 	//The automatic reload value
	TIM_TimeBaseInitStructure.TIM_Prescaler=(8);  //presclar of the TIM2
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
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);  //Enable the clock for TIM3
  TIM_TimeBaseInitStructure.TIM_Period = 50-1; 	//The automatic reload value
	TIM_TimeBaseInitStructure.TIM_Prescaler=(8);  //presclar of the TIM3
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; //Using up count mode
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStructure);//Initizlize the TIM3 timer
	
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE); //Enable TIM3 to refresh the interrupt
	TIM_Cmd(TIM3,ENABLE); //Enable TIM2
	
	// Timer 3 Interrupt Configuration
  //This Interrupt is used only for the motor acceleration 
 	NVIC_InitStructure.NVIC_IRQChannel=TIM3_IRQn; //TIM3 interrupt  
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x01; //PreemptionPriority
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x0; //ChannelSubPriority
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
    
    
}

