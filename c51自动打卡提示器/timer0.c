#include "reg52.h"
#include "intrins.h"
#include "timer0.h"
#include "74hc164.h"
#include "serial.h"

//晶振的频率
#define OSC_FREQ (11059200UL)

//每个指令的振荡周期数（4,6,12），注意，这里一定要仔细查看芯片手册
//*12 - 早期的8051、8052及当前的绝大部分51单片机
//*6 - Philips 的芯片
//*4 - Dallas
#define OSC_PER_INST (12)

typedef  unsigned int UINT16;

//TIME 为定时时间 单位MS
#define PRELOAD1MS (65536 - 1*(UINT16)(OSC_FREQ/(OSC_PER_INST*1000)))
#define PRELOAD5MS (65536 - 5*(UINT16)(OSC_FREQ/(OSC_PER_INST*1000)))

extern void LED_Disp(void);


void start_Timeout1ms( void ){
	TMOD |= 0x01;
	TH0 = PRELOAD1MS / 256;
	TL0 = PRELOAD1MS % 256;
	TF0 = 0 ;//清溢出标志位

	ET0 = 1;    //关定时器0的中断

	TR0 = 1;    //启动定时器

}

void start_Timeout5ms( void ){
	TMOD |= 0x01;

	TH0 = PRELOAD5MS / 256;
	TL0 = PRELOAD5MS % 256;
	TF0 = 0 ;//清溢出标志位

	ET0 = 1;    //关定时器0的中断

	TR0 = 1;    //启动定时器

}

void stop_Timeout(){
	TR0 = 0;
}

void Delay5ms(){
	start_Timeout5ms();
	while(!_testbit_(TF0));
	stop_Timeout();
}
 void timer0_5ms() interrupt 1
{
	static unsigned int i;
	TH0 = PRELOAD5MS / 256;
	TL0 = PRELOAD5MS % 256;
	i++;
	UartRecTimeoutMux5ms++;
	if(i>20)
	{
		i=0;
		LED_Disp();
		
	}
}
 /* 用法 
 start_Timeout1ms();
 while(!TF0);    //等待T0超时
 stop_Timeout();
 */