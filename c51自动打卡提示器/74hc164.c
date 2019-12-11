//共阴数码管74HC164串行驱动

#include<reg51.H>
#include "intrins.h"
#include "flash.h"
#include "serial.h"
#include "74hc164.h"
#include "1307_uart.h"
typedef  unsigned int uint;

typedef  unsigned char uchar;

sbit DAT=P0^0;	//模拟串口数据发送端
sbit CLK=P0^1;	//模拟时钟控制端
#define Port_SEG P1

uchar tab[]={0xfc,0x60,0xda,0xf2,0x66,0xb6,0xbe,0xe0,0xff,0xf6,0x02,0x00};//0-9,-,全灭

// typedef struct structPromptTime{
// 	uchar PromptStartH;
// 	uchar PromptStartM;
// 	uchar PromptEndH;
// 	uchar PromptEndM;
// }tagPromptTime;

// tagPromptTime PromptTime[2];

//--------------------
// // uart
// extern UART_init();        //初始化串口
// extern void COM_send(unsigned char *str, unsigned char Len);
// //--------------------

// //--------------------
// // ds1307
// extern void Set_RTC(void);
// extern void Read_RTC(void);
// extern unsigned char read_rtc_code[];
// extern void send_UART_one(unsigned char i);
// extern void Uart_Send(unsigned char *p );
// extern void SendData(void);
//--------------------
//--------------------
// void start_Timeout5ms( void );
//--------------------

void sendbyte(uchar byte)
{ 
	uchar num,c;
	
	num = ~tab[byte]; 
	for (c=0;c<8;c++)
	{
		CLK=0;
		DAT=num&0x01;
		CLK=1; 
		num>>=1;
	}
}

void delay_50ms(unsigned int t)

{
	unsigned int j;

	for (;t>0;t--)
		for (j=150;j>0;j--);
}

void LED_Disp(void)
{
	Port_SEG = 0xff;			
	sendbyte(read_rtc_code[2]/10);
	Port_SEG = ~(0x01<<0) ;
	delay_50ms(1); 
	Port_SEG = 0xff;
	sendbyte(read_rtc_code[2]%10);
	Port_SEG = ~(0x01<<1) ;
	delay_50ms(1); 
	Port_SEG = 0xff;
	sendbyte(read_rtc_code[1]/10);
	Port_SEG = ~(0x01<<2) ;
	delay_50ms(1); 
	Port_SEG = 0xff;
	sendbyte(read_rtc_code[1]%10);
	Port_SEG = ~(0x01<<3) ;
	delay_50ms(1); 
	Port_SEG = 0xff;			
	
}

// main()
// {
// 	bit b;
// 	unsigned char a,c;
// 	P0 = P1 = P2 = P3 = 0xff;
// 	start_Timeout5ms();
// 	UART_init();
// 	COM_send("uart inited\r\n",sizeof("uart inited\r\n")-1);
// // 	Set_RTC();
// 	
// 	while (1)
// 	{
// 		Read_RTC();
// 		if( a != read_rtc_code[0])
// 		{
// 			a = read_rtc_code[0];
// 			b = !b;
// 			for(c=0;c<10;c++)
// 			{
// 				if(b)
// 					tab[c-1] |= 0x01;
// 				else
// 					tab[c-1] &= 0xFE;
// 			}
// 			Uart_Send("Time:[");

// 			SendData();
// 			
// 			Uart_Send("]\r\n");
// 		}	
// 	}
// }


