#include <reg51.h>
#include "serial.h"
#include "intrins.h"

//-----------------------------------------------------------------

typedef unsigned char uchar;

uchar UartRecBuff[UARTRECBUFFLEN];
uchar UartRecBuffLen=0;
uchar UartRecTimeoutMux5ms=0;

//-------------------------------------------------------------------
// void mainK(void)
// {
// 	unsigned char i;
// 	UART_init();        //初始化串口
// 	for(i = 0;i < 10 ;i++)
// 	{
// 	   COM_send();        //首先发送一次数据作为测试用
// 	
// 	}

// while(1);
// }
//
 void send_UART_one(unsigned char i)
{
    ES     =   0;  //关串口中断
    TI     =   0;  //清零串口发送完成中断请求标志
    SBUF   =   i;
    while(TI ==0); //等待发送完成
    TI     =   0;  //清零串口发送完成中断请求标志
    ES     =   1;  //允许串口中断
}

void Uart_Send(unsigned char *p )
{
    while(*p !=0 )
        send_UART_one(*p++);
}


//-------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
// 函数名称： UART_init()串口初始化函数
// 函数功能： 在系统时钟为11.059MHZ时，设定串口波特率为9600bit/s
//             串口接收中断允许，发送中断禁止
//--------------------------------------------------------------------------------------------------
void UART_init()
{
						  //初始化串行口和波特率发生器
	SCON =0x50;           //选择串口工作方式1，打开接收允许
	TMOD =0x20;           //定时器1工作在方式2，定时器0工作在方式1
	TH1 =0xfA;            //0xfa 实现波特率9600（系统时钟11.0592MHZ）
	PCON = 0x80;
	TR1 =1;               //启动定时器T1
	ET1 =0;
	ES=1;                 //允许串行口中断
	PS=1;                 //设计串行口中断优先级
	EA =1;                //单片机中断允许
}
//------------------------------------------------------------
void COM_send(unsigned char *str, unsigned char Len)
{
	unsigned char point = 0;
	while(Len--)		//连续发送二十位数据   
						//把缓存区的数据都发送到串口
	{
		send_UART_one(*str++);
	}
}




//--------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
// 函数名称： com_interrup()串口接收中断处理函数
//--------------------------------------------------------------------------------------------------
void com_interrupt(void) interrupt 4
{

	if(_testbit_(RI))		//处理接收中断
	{
		UartRecTimeoutMux5ms = 0 ;
						
		if(UartRecBuffLen < UARTRECBUFFLEN)
		{
			UartRecBuff[UartRecBuffLen++]=SBUF;             //接收串口数据
		} 
	}
}
