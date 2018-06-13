/*-----------------------------------------------------------------------------
 * Name:    LED_NUCLEO_F103RB.c
 * Purpose: LED interface for NUCLEO-F103RB evaluation board
 * Rev.:    1.00
 *----------------------------------------------------------------------------*/

/* Copyright (c) 2013 - 2014 ARM LIMITED

   All rights reserved.
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:
   - Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
   - Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in the
     documentation and/or other materials provided with the distribution.
   - Neither the name of ARM nor the names of its contributors may be used
     to endorse or promote products derived from this software without
     specific prior written permission.
   *
   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
   ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS AND CONTRIBUTORS BE
   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
   POSSIBILITY OF SUCH DAMAGE.
   ---------------------------------------------------------------------------*/

#include "stm32f4xx_gpio.h"
#include "GPIO.h"
#include "Global_Variant.h"
#include "Indicating_Process.h"
#include "Timer.h"
#include "motor_process.h"


void Front_Cover_Open(void)
{
    GPIO_WriteBit(GPIOB, GPIO_Pin_5,Bit_RESET);                   // Bar front Step Motor Direction is backward
    GPIO_WriteBit(GPIOB, GPIO_Pin_8,Bit_SET);                   // Bar front Step Motor Direction is backward
}

void Front_Cover_Close(void)
{
    GPIO_WriteBit(GPIOB, GPIO_Pin_8,Bit_RESET);                   // Bar front Step Motor Direction is backward
    GPIO_WriteBit(GPIOB, GPIO_Pin_5,Bit_SET);                   // Bar front Step Motor Direction is backward
}


void Jack_Up(void)
{
    if( ( (GPIOC->IDR & 0x00000C00) == 0xC00 ) && ( ( GPIOB->ODR & 0x120 ) == 0 ) )                                        //  PC.11 == 0,   bar back Motor reaches limit switch
    {
        GPIO_WriteBit(GPIOC, GPIO_Pin_4, Bit_SET);                       // 
        gul_ultra_bay_status |= UAV_READY_FLAG;    
        gul_ultra_bay_status &= (~STANDBY_FLAG);    
    }
  
}

void Jack_Down(void)
{
    if( (GPIOC->IDR & 0x00000C00) == 0xC00)                                         //  PC.11 == 0,   bar back Motor reaches limit switch
    {
        GPIO_WriteBit(GPIOC, GPIO_Pin_4, Bit_RESET);                   // 
        GPIO_WriteBit(GPIOC, GPIO_Pin_5, Bit_SET);                       // 
        gul_ultra_bay_status |= UAV_READY_FLAG;
        gul_ultra_bay_status &= (~STANDBY_FLAG);
    }
    
}

void Solar_Panel_1_Close(void)
{
    SOLAR_PANEL_1_OPEN_OFF;
		Delay(1000);	
		SOLAR_PANEL_1_CLOSE_ON;
		if( (GPIOB->IDR & 0x00001000) == 0x00000000)		//	Solar Panel 1 close switch, PB12, J30
		{
			SOLAR_PANEL_1_CLOSE_OFF;
		} 
}

void Solar_Panel_1_Open(void)
{
  
	SOLAR_PANEL_1_CLOSE_OFF;
	Delay(1000);
	SOLAR_PANEL_1_OPEN_ON;
	if( (GPIOB->IDR & 0x00002000) == 0x00000000)		//	Solar Panel open switch, PB13, J31
	{
		SOLAR_PANEL_1_OPEN_OFF;
	}	    
}

void Solar_Panel_2_Close(void)
{
	SOLAR_PANEL_2_OPEN_OFF;
	Delay(1000);
	SOLAR_PANEL_2_CLOSE_ON;
	if( (GPIOB->IDR & 0x00004000) == 0x00000000)		//	Solar Panel open switch, PB14, J32
	{
		SOLAR_PANEL_2_CLOSE_OFF;
	} 
}

void Solar_Panel_2_Open(void)
{
	SOLAR_PANEL_2_CLOSE_OFF;
    Delay(1000);
	SOLAR_PANEL_2_OPEN_ON;
	if( (GPIOB->IDR & 0x00008000) == 0x00000000)		//	Solar Panel open switch, PB15, J33
	{
		SOLAR_PANEL_2_OPEN_OFF;
	}	    
}

void Solar_Panel_1_Stop(void)
{
	SOLAR_PANEL_1_CLOSE_OFF;
	SOLAR_PANEL_1_OPEN_OFF;
}

void Solar_Panel_2_Stop(void)
{
	SOLAR_PANEL_2_CLOSE_OFF;
	SOLAR_PANEL_2_OPEN_OFF;
}
