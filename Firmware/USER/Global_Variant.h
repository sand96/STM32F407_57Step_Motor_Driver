#ifndef __GLOBAL_VARIANT_H
#define __GLOBAL_VARIANT_H


extern unsigned long int gul_timer_counter_1;
extern unsigned long int gul_motor_timer_1;

extern unsigned char guc_bar_front_motor_mode;

	//The limit for deley_count_motor_flag.This will control 
	//The acceleration ratioo 
#define DELAY_COUNT_FLAG_IMIT      0x02
	//This defines the intial value of the delay for motor
#define DELAY_MOTOR_MAX	160
	//This variable will decrease to 5 from 160, each step is 5
extern unsigned long int delay_count_motor; 
	//This variable is the flag to decided whether, the delay_c
	//ount_motor will increase
extern unsigned char delay_count_motor_flag;


extern unsigned long int gul_bar_front_motor_position;


#endif

