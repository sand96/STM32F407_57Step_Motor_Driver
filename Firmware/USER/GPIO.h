#ifndef __GPIO_H
#define __GPIO_H


void Front_Cover_Open(void);
void Front_Cover_Close(void);
void Jack_Up(void);
void Jack_Down(void);
void Solar_Panel_1_Open(void);
void Solar_Panel_1_Close(void);
void Solar_Panel_2_Open(void);
void Solar_Panel_2_Close(void);
void Solar_Panel_1_Stop(void);
void Solar_Panel_2_Stop(void);



#define GPIO_LIGHT_ON                                       GPIO_WriteBit(GPIOD, GPIO_Pin_4,Bit_SET);			//	JGP9
#define GPIO_LIGHT_OFF                                      GPIO_WriteBit(GPIOD, GPIO_Pin_4,Bit_RESET);
#define GPIO_LIGHT_RED_ON                                   GPIO_WriteBit(GPIOD, GPIO_Pin_11,Bit_SET); 		//	JGP5
#define GPIO_LIGHT_RED_OFF                                  GPIO_WriteBit(GPIOD, GPIO_Pin_11,Bit_RESET);
#define GPIO_LIGHT_GREEN_ON                                 GPIO_WriteBit(GPIOD, GPIO_Pin_15,Bit_SET);		//	JGP22
#define GPIO_LIGHT_GREEN_OFF                                GPIO_WriteBit(GPIOD, GPIO_Pin_15,Bit_RESET);
#define GPIO_LIGHT_YELLOW_ON							    GPIO_WriteBit(GPIOD, GPIO_Pin_13,Bit_SET);		//	JGP6
#define GPIO_LIGHT_YELLOW_OFF                               GPIO_WriteBit(GPIOD, GPIO_Pin_13,Bit_RESET);
#define GPIO_LIGHT_ALARM_ON                                 GPIO_WriteBit(GPIOD, GPIO_Pin_14,Bit_SET);		// 	JGP21
#define GPIO_LIGHT_ALARM_OFF                                GPIO_WriteBit(GPIOD, GPIO_Pin_14,Bit_RESET);

#define RS485_SEND_ENABLE                                   GPIO_WriteBit(GPIOC, GPIO_Pin_13,Bit_SET);
#define RS485_READ_ENABLE                                   GPIO_WriteBit(GPIOC, GPIO_Pin_13,Bit_RESET);


#define GPIO_LED_ON                                         GPIO_WriteBit(GPIOE, GPIO_Pin_13,Bit_SET);
#define GPIO_LED_OFF                                        GPIO_WriteBit(GPIOE, GPIO_Pin_13,Bit_RESET);
#define SOLAR_PANEL_1_OPEN_ON								GPIO_WriteBit(GPIOD, GPIO_Pin_0,Bit_SET);
#define SOLAR_PANEL_1_OPEN_OFF								GPIO_WriteBit(GPIOD, GPIO_Pin_0,Bit_RESET);
#define SOLAR_PANEL_1_CLOSE_ON								GPIO_WriteBit(GPIOD, GPIO_Pin_1,Bit_SET);
#define SOLAR_PANEL_1_CLOSE_OFF								GPIO_WriteBit(GPIOD, GPIO_Pin_1,Bit_RESET);
#define SOLAR_PANEL_2_OPEN_ON								GPIO_WriteBit(GPIOD, GPIO_Pin_2,Bit_SET);
#define SOLAR_PANEL_2_OPEN_OFF								GPIO_WriteBit(GPIOD, GPIO_Pin_2,Bit_RESET);
#define SOLAR_PANEL_2_CLOSE_ON								GPIO_WriteBit(GPIOD, GPIO_Pin_3,Bit_SET);
#define SOLAR_PANEL_2_CLOSE_OFF								GPIO_WriteBit(GPIOD, GPIO_Pin_3,Bit_RESET);

#define P4P_BUTTON_ON								        GPIO_WriteBit(GPIOD, GPIO_Pin_7,Bit_SET);
#define P4P_BUTTON_OFF								        GPIO_WriteBit(GPIOD, GPIO_Pin_7,Bit_RESET);
#define CHARGE_BUTTON_ON								    GPIO_WriteBit(GPIOD, GPIO_Pin_10,Bit_SET);
#define CHARGE_BUTTON_OFF								    GPIO_WriteBit(GPIOD, GPIO_Pin_10,Bit_RESET);
#define CHARGE_RELAY_ON								        GPIO_WriteBit(GPIOD, GPIO_Pin_8,Bit_SET);
#define CHARGE_RELAY_OFF								    GPIO_WriteBit(GPIOD, GPIO_Pin_8,Bit_RESET);
#define SENSE_RELAY_ON								        GPIO_WriteBit(GPIOD, GPIO_Pin_9,Bit_SET);
#define SENSE_RELAY_OFF								        GPIO_WriteBit(GPIOD, GPIO_Pin_9,Bit_RESET);



#define GPIO_BAR_FRONT_DIRECTION_FORWARD                    GPIO_WriteBit(GPIOE, GPIO_Pin_6,Bit_RESET);		// JGP13
#define GPIO_BAR_FRONT_DIRECTION_BACKWARD                   GPIO_WriteBit(GPIOE, GPIO_Pin_6,Bit_SET); 
#define GPIO_BAR_FRONT_PULSE_HIGH                           GPIO_WriteBit(GPIOE, GPIO_Pin_7,Bit_SET);		// JGP29
#define GPIO_BAR_FRONT_PULSE_LOW                            GPIO_WriteBit(GPIOE, GPIO_Pin_7,Bit_RESET);

#define GPIO_BAR_BACK_DIRECTION_FORWARD                     GPIO_WriteBit(GPIOE, GPIO_Pin_8,Bit_RESET);		//	JGP1
#define GPIO_BAR_BACK_DIRECTION_BACKWARD                    GPIO_WriteBit(GPIOE, GPIO_Pin_8,Bit_SET); 
#define GPIO_BAR_BACK_PULSE_HIGH                            GPIO_WriteBit(GPIOE, GPIO_Pin_9,Bit_SET);		// 	JGP28
#define GPIO_BAR_BACK_PULSE_LOW                             GPIO_WriteBit(GPIOE, GPIO_Pin_9,Bit_RESET); 

#define GPIO_JACK1_DIRECTION_UP                             GPIO_WriteBit(GPIOE, GPIO_Pin_0,Bit_RESET);			// JGP10
#define GPIO_JACK1_DIRECTION_DOWN                           GPIO_WriteBit(GPIOE, GPIO_Pin_0,Bit_SET);
#define GPIO_JACK1_PULSE_HIGH                               GPIO_WriteBit(GPIOE, GPIO_Pin_1,Bit_SET);	//	JGP16
#define GPIO_JACK1_PULSE_LOW                                GPIO_WriteBit(GPIOE, GPIO_Pin_1,Bit_RESET);
#define GPIO_JACK2_DIRECTION_UP                             GPIO_WriteBit(GPIOE, GPIO_Pin_2,Bit_RESET); 			//  JGP15
#define GPIO_JACK2_DIRECTION_DOWN                           GPIO_WriteBit(GPIOE, GPIO_Pin_2,Bit_SET);
#define GPIO_JACK2_PULSE_HIGH                               GPIO_WriteBit(GPIOE, GPIO_Pin_3,Bit_SET);		//JGP11
#define GPIO_JACK2_PULSE_LOW                                GPIO_WriteBit(GPIOE, GPIO_Pin_3,Bit_RESET);

#define GPIO_CLAW_DIRECTION_FORWARD                         GPIO_WriteBit(GPIOE, GPIO_Pin_4,Bit_SET);		//  JGP14
#define GPIO_CLAW_DIRECTION_BACKWARD                        GPIO_WriteBit(GPIOE, GPIO_Pin_4,Bit_RESET);
#define GPIO_CLAW_PULSE_HIGH                                GPIO_WriteBit(GPIOE, GPIO_Pin_5,Bit_SET); 	//	JGP12
#define GPIO_CLAW_PULSE_LOW                                 GPIO_WriteBit(GPIOE, GPIO_Pin_5,Bit_RESET);

#endif

