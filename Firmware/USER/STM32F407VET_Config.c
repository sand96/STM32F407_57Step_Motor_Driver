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
//	TIM2_PWMDMA_Config();
	
}

/* brief:	Start outputing the PWM.
	 notes:	Here TIM2 request mapping is using CH1 and stream 5
					This will use peripheral channel 3
*/
void TIM2StartPwmOut(void)
{
 // TIM_DMACmd(TIM2,TIM_DMA_CC1,ENABLE);
//  TIM2->CCER |= 1<<1; 									//Enable CC1 for TIM2
//  TIM_Cmd(TIM2,ENABLE);									//Enable TIM
 // DMA_Cmd(DMA1_Stream5,ENABLE);					//Enable DMA 
	//DMA_ITConfig(DMA1_Stream5,DMA_IT_TC,ENABLE);
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
	//	GPIO_InitTypeDef Motor_GPIO_Struct;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
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
	
	GPIO_InitStructure.GPIO_Pin = Test_Motor.Motor_GPIO.Pluse_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(Test_Motor.Motor_GPIO.Motor_Pluse_Port,&GPIO_InitStructure);
	
	GPIO_PinAFConfig(Test_Motor.Motor_GPIO.Motor_Pluse_Port,Test_Motor.Motor_GPIO.Pluse_Pin,GPIO_AF_TIM3);  //Remap the Motor_GPIO.Pluse_Pin
}


/* brief:	Congfigure the setting for TIM2 Channel 1
*/
void TIM2_CH1_PWM_Config(void)
{	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;		//The sturcture to define the performance of TIM2
	TIM_OCInitTypeDef	TIM_OCInitStructure;	//The structure to define the capture and the compare mode
	
//	TIM_DeInit(TIM2);								//Deinitializes the TIM2 peripheral registers to their default reset values.
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);  //Enable the clock for the TIM2
	
		//Setting for the TIM2
  TIM_TimeBaseInitStructure.TIM_Period = Test_Motor.Timer_Period; 	//The automatic reload value
	TIM_TimeBaseInitStructure.TIM_Prescaler=3;  //No prescaler the frequency is equal 168MHz / 4
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; //Using up count mode
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1; 	//Just setting for filtering
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0x0000; //No repetition counting
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStructure);//Initizlize the TIM2 timer
	
		//Setting for the compare and capture mode
		//Channel 1 configurationin PWM mode
		//It looks like we don't need to generate the output 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
//  TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable;
	TIM_OCInitStructure.TIM_Pulse = Test_Motor.Channel_Pluse; //This value is RCC
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;//This will influnence the spiral direction
//  TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
//  TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;
//  TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCIdleState_Reset;
  TIM_OC1Init(TIM3, &TIM_OCInitStructure); 
  TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);
			
			//The interrupt isn't needed
//	TIM_ClearITPendingBit(TIM2, TIM_IT_CC1 | TIM_IT_CC2 | TIM_IT_CC3 | TIM_IT_CC4|TIM_IT_Update); //Clear all the interrupt flag
//	TIM_ITConfig(TIM2, TIM_IT_CC1 | TIM_IT_CC2 | TIM_IT_CC3 | TIM_IT_CC4|TIM_IT_Update, ENABLE);	//Configure the interrupt
	
//	TIM_DMACmd(TIM2,TIM_DMA_CC1,ENABLE); //Enable the DMA request
//	TIM2 -> CCER |= (1<<1); //Disable CC1 for TIM2
TIM_ARRPreloadConfig(TIM3, ENABLE);
	TIM_Cmd(TIM3,ENABLE);
}


/*
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

