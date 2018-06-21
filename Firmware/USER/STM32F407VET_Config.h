#ifndef STM32F407VET_CONFIG_H
#define STM32F407VET_CONFIG_H

#include "stdint.h"

void CPU_Initialization(void);

uint16_t SRC_Buffer[10] = {2000};
#define TIM_PRESCALER 21 	//The prescaler for TIM4
#define SYS_CLOCK 168000000;

void CPU_Initialization(void);		//Configure all the setting for the CPU
void NVIC_Configuration(void);		//Configure the setting for the NVIC, interrupt

#endif
