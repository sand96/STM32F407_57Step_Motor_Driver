#ifndef __MOTOR_PROCESS_H
#define __MOTOR_PROCESS_H

void Jack_Motor_Process(void);
void Bar_Front_Motor_Process(void);
void Bar_Back_Motor_Process(void);
void Claw_Motor_Process(void);
void Solar_Panel_Process(void);

extern unsigned char guc_jack_motor_mode;
extern unsigned char guc_bar_front_motor_mode;
extern unsigned char guc_bar_back_motor_mode;
extern unsigned char guc_claw_motor_mode;

extern unsigned long int gul_jack_motor_position;
extern unsigned long int gul_bar_front_motor_position;
extern unsigned long int gul_bar_back_motor_position;
extern unsigned long int gul_claw_motor_position;

#define JACK_INIT_POSITION                   0x00000A00
#define JACK_TARGET_POSITION          0x00013000

#define BAR_FRONT_INIT_POSITION             0x00000080
#define BAR_FRONT_TARGET_POSITION    0x00003B00

#define BAR_BACK_INIT_POSITION             0x00000080
#define BAR_BACK_TARGET_POSITION    0x00003B00

#define CLAW_INIT_POSITION             0x00000080
#define CLAW_TARGET_POSITION    0x00001F80

#define MOTOR_STOP                   0
#define MOTOR_FORWARD         1
#define MOTOR_BACKWARD      2
#define MOTOR_INITIALIZE            3
#define MOTOR_UP         1
#define MOTOR_DOWN      2
#define MOTOR_OPEN         1
#define MOTOR_CLOSE      2

#endif 

