#include "Global_Variant.h"


//This variable used to increase the speed of the motor
unsigned long int delay_count_motor; 
unsigned char delay_count_motor_flag;

unsigned long int gul_motor_timer_1;
unsigned long int gul_jack_motor_timer;
unsigned long int gul_indicating_timer;
unsigned long int gul_jack_motor_slow_down_timer;
unsigned long int gul_solar_panel_1_timer;
unsigned long int gul_solar_panel_2_timer;

unsigned long int gul_jack_motor_switch_counter;
unsigned long int gul_bar_1_motor_switch_counter;
unsigned long int gul_bar_2_motor_switch_counter;

unsigned long int gul_UART_command;
unsigned char guc_jack_motor_mode;
unsigned char guc_bar_front_motor_mode;

