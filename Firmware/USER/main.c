#include "sys.h"
#include "delay.h"
#include "GPIO.h"
#include "STM32F407VET_Config.h"
#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "Global_Variant.h"
#include "Motor_Process.h"
#include "Ultra_Bay.h"

//ALIENTEK 探索者STM32F407开发板 实验1
//跑马灯实验 -库函数版本
//技术支持：www.openedv.com
//淘宝店铺：http://eboard.taobao.com  
//广州市星翼电子科技有限公司  
//作者：正点原子 @ALIENTEK
//extern  u8 RxBuffer1[500];
/*   variables ---------------------------------------------------------*/
u8 Uart_send_counter; //Uart_send()函数发送的字节数
vu8 *Uart_send_pointer;//发送的数组指针
//u8 flag_rev_finish;
u8 flag_1; //第一次 读出 UID码成功
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
