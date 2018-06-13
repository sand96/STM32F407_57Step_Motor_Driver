#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "GPIO.h"
#include "UART_Process.h"
#include "ADC_Process.h"
#include "STM32F407VET_Config.h"
#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "Global_Variant.h"
#include "Serial.h"
#include "Motor_Process.h"
#include "Indicating_Process.h"
#include "Charging_Process.h"
#include "PN532.h"
#include "Ultra_Bay.h"
#include "rs485.h"
#include "wwdg.h"
#include "myiic.h"
#include "P4P_Process.h"

//ALIENTEK ̽����STM32F407������ ʵ��1
//�����ʵ�� -�⺯���汾
//����֧�֣�www.openedv.com
//�Ա����̣�http://eboard.taobao.com  
//������������ӿƼ����޹�˾  
//���ߣ�����ԭ�� @ALIENTEK
//extern  u8 RxBuffer1[500];
/*   variables ---------------------------------------------------------*/
//u8 means unsigned 8 bits int, in my mind, it looks like char
u8 Uart_send_counter; //Uart_send()�������͵��ֽ���
vu8 *Uart_send_pointer;//���͵�����ָ��, also this pointer can't be optimized by the compiler
//u8 flag_rev_finish;
u8 flag_1; //��һ�� ���� UID��ɹ�
u8 flag_2; 
u8 flag_3; 

int main(void)
{
    CPU_Initialization();
    Ultra_Bay_Initialization();
 //   IIC_Init();
    RS485_Init(115200);		//��ʼ��RS485����2
//    uart_Init(115200);	//��ʼ�����ڲ�����Ϊ115200
 //   nfc_WakeUp();
    delay_init(168);		  //��ʼ����ʱ����//��������// 168 means this MCU frequency is 168MHz, but i haven't understand
	
	while(1)
	{
        //delay_ms(180);
        //    GPIO_LED_ON;
        ADC_temperature=ADC_Process();
        Jack_Motor_Process();
        Bar_Front_Motor_Process();
        Bar_Back_Motor_Process();
        Claw_Motor_Process();
        Solar_Panel_Process();
        UART_Process();
        Indicating_Process();
        Charge_Button_Press();
        P4P_Button_Process();
        //NFC_WriteLenByte(0,(u32*)RxBuffer1,24);
        //nfc_InListPassiveTarget(); //Ѱ�� nfc��ǩ��Mifare ��������ȡUID    
        //nfc_PsdVerifyKeyA();	
    }
}
