#include "STM32F407VET_Config.h"
#include "stm32f4xx.h"                  // Device header
#include "stm32f4xx_gpio.h"							//GPIO header
#include "misc.h" 
#include "stm32f4xx_dma.h"							//header for dma
#include "Motor_Process.h"							//Hearder for Motor_Process

extern Motor Test_Motor;

	//Only visited by the TIM2_Config()
static void TIM2_GPIO_Config(void);  //GPIO configure
static void TIM2_CH1_PWM_Config(void);//TIMER capture and compare configure
static void TIM2_PWMDMA_Config(void); //DMA and interrupt configure 

void CPU_Initialization(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//Set priority groups
}

/* breif:		This function is used to calculate the period 
	 param:		period 
						num 
*/
void TIM2_Config(void)
{
	TIM2_GPIO_Config();
	TIM2_CH1_PWM_Config();
	TIM2_PWMDMA_Config();
	
}

/* brief:	Start outputing the PWM.
	 notes:	Here TIM2 request mapping is using CH1 and stream 5
					This will use peripheral channel 3
*/
void TIM2StartPwmOut(void)
{
  TIM_DMACmd(TIM2,TIM_DMA_CC1,ENABLE);
  TIM2->CCER |= 1<<1; 									//Enable CC1 for TIM2
  TIM_Cmd(TIM2,ENABLE);									//Enable TIM
  DMA_Cmd(DMA1_Stream5,ENABLE);					//Enable DMA 
	DMA_ITConfig(DMA1_Stream5,DMA_IT_TC,ENABLE);
}

/* brief:	Stop the PWM output
	 notes:	Here TIM2 request mapping is using CH1 and stream 5
					This will use peripheral channel 3
*/
void TIM2StopPwmOut(void)
{
  TIM_DMACmd(TIM2,TIM_DMA_CC1,DISABLE);
	TIM2 -> CCER &= ~(1<<1); 								//Disable CC1 for TIM2
	TIM_Cmd(TIM2,DISABLE); 									//Disable TIM
  DMA_Cmd(DMA1_Stream5,DISABLE);					//Disable DMA
	DMA_ITConfig(DMA1_Stream5,DMA_IT_TC,DISABLE);
}

/* brief:		The GPIO configuration for TIM2
	 notes:		The formal paramter comes from the structure of Test_Motor
						The TIM2_CH1 can remap to PA0. PA5 and PA15. Here TIM2_CH1
						has been remapped to PA0.
	 notes:	  Motor_GPIO.Pluse_Pin is PA0
*/
void TIM2_GPIO_Config(void)
{
	GPIO_InitTypeDef      GPIO_InitStructure;
		//Initialize the clock for Motor_GPIO
	if(Test_Motor.Motor_GPIO.Motor_Pluse_Port == GPIOA) 
	{
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
	}
	else if(Test_Motor.Motor_GPIO.Motor_Pluse_Port == GPIOB)
	{
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB,ENABLE);
	}
	else if(Test_Motor.Motor_GPIO.Motor_Pluse_Port == GPIOC)
	{
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC,ENABLE);
	}	
	else if(Test_Motor.Motor_GPIO.Motor_Pluse_Port == GPIOD)
	{
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD,ENABLE);
	}
	else if(Test_Motor.Motor_GPIO.Motor_Pluse_Port == GPIOE)
	{
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE,ENABLE);
	}
	else if(Test_Motor.Motor_GPIO.Motor_Pluse_Port == GPIOF)
	{
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE);
	}	
	else if(Test_Motor.Motor_GPIO.Motor_Pluse_Port == GPIOG)
	{
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG,ENABLE);
	}
	else if(Test_Motor.Motor_GPIO.Motor_Pluse_Port == GPIOH)
	{
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOH,ENABLE);
	}
	else if(Test_Motor.Motor_GPIO.Motor_Pluse_Port == GPIOI)
	{
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOI,ENABLE);
	}
	else if(Test_Motor.Motor_GPIO.Motor_Pluse_Port == GPIOJ)
	{
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOJ,ENABLE);
	}
	else if(Test_Motor.Motor_GPIO.Motor_Pluse_Port == GPIOK)
	{
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOK,ENABLE);
	}
	 
  // GPIOC Configuration: TIM2 CH1 (PA0)
  GPIO_InitStructure.GPIO_Pin = Test_Motor.Motor_GPIO.Pluse_Pin;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP ;
  GPIO_Init(Test_Motor.Motor_GPIO.Motor_Pluse_Port, &GPIO_InitStructure); 

  /* Connect TIM2 pins to AF3 */  
	if(Test_Motor.Motor_GPIO.Pluse_Pin == GPIO_Pin_0)
		GPIO_PinAFConfig(Test_Motor.Motor_GPIO.Motor_Pluse_Port,GPIO_PinSource0, GPIO_AF_TIM2);
	else if(Test_Motor.Motor_GPIO.Pluse_Pin == GPIO_Pin_1)
		GPIO_PinAFConfig(Test_Motor.Motor_GPIO.Motor_Pluse_Port,GPIO_PinSource1, GPIO_AF_TIM2);
	else if(Test_Motor.Motor_GPIO.Pluse_Pin == GPIO_Pin_2)
		GPIO_PinAFConfig(Test_Motor.Motor_GPIO.Motor_Pluse_Port,GPIO_PinSource2, GPIO_AF_TIM2);
	else if(Test_Motor.Motor_GPIO.Pluse_Pin == GPIO_Pin_3)
		GPIO_PinAFConfig(Test_Motor.Motor_GPIO.Motor_Pluse_Port,GPIO_PinSource3, GPIO_AF_TIM2);
	else if(Test_Motor.Motor_GPIO.Pluse_Pin == GPIO_Pin_4)
		GPIO_PinAFConfig(Test_Motor.Motor_GPIO.Motor_Pluse_Port,GPIO_PinSource4, GPIO_AF_TIM2);
	else if(Test_Motor.Motor_GPIO.Pluse_Pin == GPIO_Pin_5)
		GPIO_PinAFConfig(Test_Motor.Motor_GPIO.Motor_Pluse_Port,GPIO_PinSource5, GPIO_AF_TIM2);
	else if(Test_Motor.Motor_GPIO.Pluse_Pin == GPIO_Pin_6)
		GPIO_PinAFConfig(Test_Motor.Motor_GPIO.Motor_Pluse_Port,GPIO_PinSource6, GPIO_AF_TIM2);
	else if(Test_Motor.Motor_GPIO.Pluse_Pin == GPIO_Pin_7)
		GPIO_PinAFConfig(Test_Motor.Motor_GPIO.Motor_Pluse_Port,GPIO_PinSource7, GPIO_AF_TIM2);
	else if(Test_Motor.Motor_GPIO.Pluse_Pin == GPIO_Pin_8)
		GPIO_PinAFConfig(Test_Motor.Motor_GPIO.Motor_Pluse_Port,GPIO_PinSource8, GPIO_AF_TIM2);
	else if(Test_Motor.Motor_GPIO.Pluse_Pin == GPIO_Pin_9)
		GPIO_PinAFConfig(Test_Motor.Motor_GPIO.Motor_Pluse_Port,GPIO_PinSource9, GPIO_AF_TIM2);
	else if(Test_Motor.Motor_GPIO.Pluse_Pin == GPIO_Pin_10)
		GPIO_PinAFConfig(Test_Motor.Motor_GPIO.Motor_Pluse_Port,GPIO_PinSource10, GPIO_AF_TIM2);
	else if(Test_Motor.Motor_GPIO.Pluse_Pin == GPIO_Pin_11)
		GPIO_PinAFConfig(Test_Motor.Motor_GPIO.Motor_Pluse_Port,GPIO_PinSource11, GPIO_AF_TIM2);
	else if(Test_Motor.Motor_GPIO.Pluse_Pin == GPIO_Pin_12)
		GPIO_PinAFConfig(Test_Motor.Motor_GPIO.Motor_Pluse_Port,GPIO_PinSource12, GPIO_AF_TIM2);
	else if(Test_Motor.Motor_GPIO.Pluse_Pin == GPIO_Pin_13)
		GPIO_PinAFConfig(Test_Motor.Motor_GPIO.Motor_Pluse_Port,GPIO_PinSource13, GPIO_AF_TIM2);
	else if(Test_Motor.Motor_GPIO.Pluse_Pin == GPIO_Pin_14)
		GPIO_PinAFConfig(Test_Motor.Motor_GPIO.Motor_Pluse_Port,GPIO_PinSource14, GPIO_AF_TIM2);
	else if(Test_Motor.Motor_GPIO.Pluse_Pin == GPIO_Pin_15)
		GPIO_PinAFConfig(Test_Motor.Motor_GPIO.Motor_Pluse_Port,GPIO_PinSource15, GPIO_AF_TIM2);
}


/* brief:	Congfigure the setting for TIM2 Channel 1
*/
void TIM2_CH1_PWM_Config(void)
{		
	TIM_DeInit(TIM2);								//Deinitializes the TIM2 peripheral registers to their default reset values.

	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
  /* Time base configuration */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
  TIM_TimeBaseStructure.TIM_Period = Test_Motor.Timer_Period;
  TIM_TimeBaseStructure.TIM_Prescaler = 0;
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

  /* PWM1 Mode configuration: Channel1 */
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = Test_Motor.Channel_Pluse;
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

  TIM_OC1Init(TIM2, &TIM_OCInitStructure);
  TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Enable);
  TIM_ARRPreloadConfig(TIM2, DISABLE);

  /* TIM3 enable counter */
  //TIM_Cmd(TIM2, ENABLE);
	TIM2 -> CCER |= (1<<1); //Disable CC1 for TIM2
  TIM_Cmd(TIM2,DISABLE);
}


/* brief:		This function has set the paramter for DMA
	 notes:		All the setting should be changed according to the data sheet. 
						In this demo, the function use TIM2_CH1. Here, DMA1_stream5 and channel
						2 has been used.
*/
void TIM2_PWMDMA_Config(void)
{
		//The value will be written into TIM2
	
	DMA_InitTypeDef  DMA_InitStructure;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA1, ENABLE);
  DMA_DeInit(DMA1_Stream5);  //Deintilize the setting 
  while (DMA_GetCmdStatus(DMA1_Stream5) != DISABLE);
  
	DMA_InitStructure.DMA_Channel = DMA_Channel_3;
	DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)&TIM2->ARR;
  DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)&(Test_Motor.Timer_Period); //This value should be changed 
	DMA_InitStructure.DMA_BufferSize = 1;
  DMA_InitStructure.DMA_DIR = DMA_DIR_MemoryToPeripheral;
  DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
  DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Word;
  DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
  DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
  DMA_InitStructure.DMA_Priority = DMA_Priority_High;
  DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable;
	DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_HalfFull;
	DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;
	DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;
	DMA_Init(DMA1_Stream5,&DMA_InitStructure);
	
		//generate the interrupt for DMA
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = DMA1_Stream5_IRQn;   //Setting interrupt stream
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; //Setting preemption priority
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;        //Setting subpriority
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;           //enable interrupt
	NVIC_Init(&NVIC_InitStructure); 
	DMA_ITConfig(DMA1_Stream5,DMA_IT_TC,DISABLE);    					//enable DMA interrupt
}

