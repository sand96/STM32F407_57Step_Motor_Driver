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

//ALIENTEK 探索者STM32F407开发板 实验1
//跑马灯实验 -库函数版本
//技术支持：www.openedv.com
//淘宝店铺：http://eboard.taobao.com  
//广州市星翼电子科技有限公司  
//作者：正点原子 @ALIENTEK
//extern  u8 RxBuffer1[500];
/*   variables ---------------------------------------------------------*/
//u8 means unsigned 8 bits int, in my mind, it looks like char
u8 Uart_send_counter; //Uart_send()函数发送的字节数
vu8 *Uart_send_pointer;//发送的数组指针, also this pointer can't be optimized by the compiler
//u8 flag_rev_finish;
u8 flag_1; //第一次 读出 UID码成功
u8 flag_2; 
u8 flag_3; 

int main(void)
{
    CPU_Initialization();
    Ultra_Bay_Initialization();
 //   IIC_Init();
    RS485_Init(115200);		//初始化RS485串口2
//    uart_Init(115200);	//初始化串口波特率为115200
 //   nfc_WakeUp();
    delay_init(168);		  //初始化延时函数//不能屏蔽// 168 means this MCU frequency is 168MHz, but i haven't understand
	
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
        //nfc_InListPassiveTarget(); //寻找 nfc标签（Mifare 卡），获取UID    
        //nfc_PsdVerifyKeyA();	
    }
}
