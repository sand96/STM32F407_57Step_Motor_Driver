#include "Motor_Process.h"
#include "Global_Variant.h"
#include "stm32f4xx_gpio.h"
#include "GPIO.h"
#include "Indicating_Process.h"
#include "delay.h"
#include "UART_Process.h"


void Bar_Front_Motor_Process(void)
{
  //  if( guc_bar_front_motor_mode == MOTOR_FORWARD )
  //  {
  /*                      // Bar front Step Motor Direction is forward
        GPIO_BAR_FRONT_DIRECTION_FORWARD;       
        if( (gul_motor_timer_1 % 2) == 1 )                                         // 
        {
                      // Bar front Step Motor Pulse ---- High Level
            GPIO_BAR_FRONT_PULSE_HIGH;  		
        }
        else if( ( (gul_motor_timer_1 % 2) == 0) && ( ( GPIOE->ODR & 0x00000080 ) == 0x00000080 ) )  
        {
                   // Bar front Step Motor Pulse ---- Low Level
            GPIO_BAR_FRONT_PULSE_LOW;    
            gul_bar_front_motor_position ++;
        }
        else
        {
                ;
        }	 */
    /*    if( (GPIOC->IDR&=0x00000080) == 0)        //  Bar Motor Forward Switch, PC7, J22 
        {
            guc_bar_front_motor_mode = MOTOR_STOP;
            if((GPIOC->IDR&=0x00000200) == 0)    
            {
                gul_UART_feedback = BAR_CLOSE_FLAG;
                RS485_SEND_ENABLE;   
                USART_ClearFlag(USART2, USART_FLAG_TC);   
                USART_SendData(USART2, gul_UART_feedback);
                delay_ms(100);
                while(USART_GetFlagStatus(USART2,USART_FLAG_TXE) == RESET )
                {
                    ;
                }
                RS485_READ_ENABLE;
            }            
        } */
  //  }
  /*  else if( guc_bar_front_motor_mode == MOTOR_BACKWARD )
    {
                        // Bar front Step Motor Direction is backward */
        GPIO_BAR_FRONT_DIRECTION_BACKWARD; 
        if( (gul_motor_timer_1 % 2) == 1 )                                        // 
        {
                          // Bar front Step Motor Pulse ---- High Level
						delay_us(delay_count_motor);
            GPIO_BAR_FRONT_PULSE_HIGH;		
        }
        else if( ( (gul_motor_timer_1 % 2) == 0) && ( ( GPIOE->ODR & 0x00000080 ) == 0x00000080 )  )  
        {
						delay_us(delay_count_motor);
            GPIO_BAR_FRONT_PULSE_LOW;         // Bar front Step Motor Pulse ---- Low Level
            if(gul_bar_front_motor_position > 0 )
            {
                gul_bar_front_motor_position --;           
            }
            else
            {
                gul_bar_front_motor_position = 0;
            }
        }
        else
        {
            ;
        }
  /*      if( (GPIOC->IDR&=0x00000100) == 0)              //  Bar Motor Backward Switch, PC8, J20, PC10, J19 
        {
            guc_bar_front_motor_mode = MOTOR_STOP;
            if((GPIOC->IDR&=0x00000400) == 0)
            {
                gul_UART_feedback = BAR_OPEN_FLAG;
                RS485_SEND_ENABLE;   
                
                USART_ClearFlag(USART2, USART_FLAG_TC);   
                USART_SendData(USART2, gul_UART_feedback);
                delay_ms(100);
                while(USART_GetFlagStatus(USART2,USART_FLAG_TXE) == RESET )
                {
                    ;
                }
                RS485_READ_ENABLE; 
            }
        }
    }
    else
    {
        ;
    } */
}

