#include "sys.h"
#include "delay.h"
#include "GPIO.h"
#include "STM32F407VET_Config.h"
#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "Global_Variant.h"
#include "Motor_Process.h"
#include "Ultra_Bay.h"

//ALIENTEK ̽����STM32F407������ ʵ��1
//�����ʵ�� -�⺯���汾
//����֧�֣�www.openedv.com
//�Ա����̣�http://eboard.taobao.com  
//������������ӿƼ����޹�˾  
//���ߣ�����ԭ�� @ALIENTEK
//extern  u8 RxBuffer1[500];
/*   variables ---------------------------------------------------------*/
u8 Uart_send_counter; //Uart_send()�������͵��ֽ���
vu8 *Uart_send_pointer;//���͵�����ָ��
//u8 flag_rev_finish;
u8 flag_1; //��һ�� ���� UID��ɹ�
u8 flag_2; 
u8 flag_3; 

int main(void)
{
  /*  CPU_Initialization();
	  GPIO_InitTypeDef  GPIO_InitStructure;

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);//??GPIOF??

  //GPIOF9,F10?????
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;//LED0?LED1??IO?
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//??????
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//????
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//??
  GPIO_Init(GPIOD, &GPIO_InitStructure);//???GPIO
	
	GPIO_ResetBits(GPIOD,GPIO_Pin_0 | GPIO_Pin_1);//GPIOF9,F10???,??
	while(1)
	{;
    } */
	
	  CPU_Initialization();
    Ultra_Bay_Initialization();
    RS485_Init(115200);		//???RS485??2
    delay_init(168);		  //???????//????
		
	while(1)
	{
        //delay_ms(180);
        //    GPIO_LED_ON;
    //    ADC_temperature=ADC_Process();
    //    Jack_Motor_Process();
       Bar_Front_Motor_Process();
   //     Bar_Back_Motor_Process();
   //     Claw_Motor_Process();
   //     Solar_Panel_Process();
        UART_Process();
   //     Indicating_Process();
  //      Charge_Button_Press();
   //     P4P_Button_Process();
    }
}
