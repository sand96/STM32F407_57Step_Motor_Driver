#include "Global_Variant.h"
#include "Ultra_Bay.h"
#include "Motor_Process.h"
#include "GPIO.h" 
#include "delay.h"

/* \brief 	Initialize all the paramter which are used by devices
						, which are several motors, charger and etc.
		\notes 	???Why don't initilize all the motors? for example, just 
						???there motor get initial postion
*/
void Ultra_Bay_Initialization(void)
{
	guc_claw_motor_mode = MOTOR_STOP;
	guc_jack_motor_mode = MOTOR_STOP;
	guc_bar_front_motor_mode = MOTOR_STOP;
  guc_bar_back_motor_mode = MOTOR_STOP;
	SOLAR_PANEL_1_CLOSE_OFF;
	SOLAR_PANEL_1_OPEN_OFF;
	SOLAR_PANEL_2_CLOSE_OFF;
	SOLAR_PANEL_2_OPEN_OFF;
	guc_solar_panel_2_mode = MOTOR_STOP;
	guc_solar_panel_1_mode = MOTOR_STOP;
    P4P_BUTTON_OFF;

//This variable used to increase the speed of the motor
delay_count_motor = DELAY_MOTOR_MAX; 
delay_count_motor_flag = 0;
	
gul_jack_motor_switch_counter = 0;
gul_bar_1_motor_switch_counter = 0;
gul_bar_2_motor_switch_counter = 0;
gul_claw_motor_switch_counter = 0;
gul_solar_panel_1_switch_counter = 0;
gul_solar_panel_2_switch_counter = 0;
//    guc_charge_relay_flag = 0;
	
    guc_charge_status = CHARGE_OFF;
    guc_button_press_flag = 0;
    gul_button_press_timer = 0;
    gul_P4P_button_press_timer = 0;
    gul_ultra_bay_serial_number = 0x10;
    gul_ultra_bay_status = 0x00;
		
		//The initilization position is little with the initial 
		//postion in the Motor_Process.h
    gul_bar_front_motor_position = 1000000;
    gul_bar_back_motor_position = 1000000;
    gul_claw_motor_position = 10000; 
}

/* \brief	microsecond level delay
	 \param	int x, the input number, which will set the number 
					of delay.
*/
void delay_ms( unsigned int x)
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

//定时器3中断服务函数
void TIM3_IRQHandler(void)
{
	//The intrrupt will happen every 500ms.
	if(TIM_GetITStatus(TIM3,TIM_IT_Update)==SET) //溢出中断
	{
	//	gul_delay_timer++; 
		gul_jack_motor_timer ++;
	//	gul_motor_timer_1 ++;
		if(delay_count_motor_flag < 2)
		{	
			delay_count_motor_flag += 1;
		}
		
			if(gul_timer_counter_1 >= 3)
			{
					msTicks++;
				 // gul_motor_timer_1 ++;
					gul_indicating_timer ++; //It's possible to used in the indicating_Process.c
					gul_timer_counter_1 = 0;
					gul_button_press_timer ++;
					// gul_jack_motor_timer ++;   
			}
			else
			{
					gul_timer_counter_1 ++;
			}
        
        if(gul_indicating_timer >= 1000)
        {
            gul_indicating_timer = 0;
        }
        else
        {
          ;      
        }
        
        if(gul_button_press_timer >= 3000)
        {
            gul_button_press_timer = 0;
        }
        else
        {
          ;   
        }
	}
	TIM_ClearITPendingBit(TIM3,TIM_IT_Update);  //清除中断标志位
}

//The TIM2 interrupt sevice
/* \brief Generating a time flag for Systick to manage delay 
					used by motor drive pluse signal
	\param
	\notes
*/
void TIM2_IRQHandler(void)
{
	
}