#ifndef __GLOBAL_VARIANT_H
#define __GLOBAL_VARIANT_H


//extern unsigned char guc_charge_flag;
extern unsigned char guc_charge_direction_flag;
extern unsigned char guc_charge_status;
#define CHARGE_START    0x01
#define CHARGING        0x02
#define CHARGE_STOP     0x03
#define CHARGE_OFF      0x04
extern unsigned char guc_button_press_flag;
extern unsigned long int  gul_button_press_timer;
extern unsigned char guc_P4P_turn_on_flag;
extern unsigned char guc_P4P_button_flag;
extern unsigned long int gul_P4P_button_press_timer;



extern unsigned long int gul_timer_counter_1;
extern unsigned long int gul_motor_timer_1;

extern unsigned long int gul_jack_motor_timer;
extern unsigned long int gul_indicating_timer;
extern unsigned long int gul_jack_motor_slow_down_timer;
extern unsigned long int gul_solar_panel_1_timer;
extern unsigned long int gul_solar_panel_2_timer;

extern unsigned long int gul_jack_motor_switch_counter;
extern unsigned long int gul_bar_1_motor_switch_counter;
extern unsigned long int gul_bar_2_motor_switch_counter;
extern unsigned long int gul_claw_motor_switch_counter;
extern unsigned long int gul_solar_panel_1_switch_counter;
extern unsigned long int gul_solar_panel_2_switch_counter;





extern unsigned long int gul_delay_timer;


extern unsigned long int gul_ultra_bay_serial_number;
extern unsigned long int gul_ultra_bay_status;
extern unsigned long int gul_UART_feedback;

extern unsigned long int gul_UART_command;

extern unsigned int gui_Battery_Voltage;
extern unsigned char guc_ADC_channel;

/* Motor Viriant    --------------    Motor Process.h    */


extern unsigned char guc_jack_motor_mode;
extern unsigned char guc_bar_front_motor_mode;
extern unsigned char guc_bar_back_motor_mode;
extern unsigned char guc_claw_motor_mode;
extern unsigned char guc_claw_right_motor_mode;
extern unsigned char guc_solar_panel_1_mode;
extern unsigned char guc_solar_panel_2_mode;

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

extern unsigned long int gul_jack_motor_position;
extern unsigned long int gul_bar_front_motor_position;
extern unsigned long int gul_bar_back_motor_position;
extern unsigned long int gul_claw_motor_position;
extern unsigned long int gul_claw_right_motor_position;
/* ADC Viriant    --------------    ADC_Process.h    */

extern unsigned int ADC_temperature;
extern unsigned int ADC_voltlage;

#endif

