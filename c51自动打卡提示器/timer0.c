#include "reg52.h"
#include "intrins.h"
#include "timer0.h"
#include "74hc164.h"
#include "serial.h"

//�����Ƶ��
#define OSC_FREQ (11059200UL)

//ÿ��ָ�������������4,6,12����ע�⣬����һ��Ҫ��ϸ�鿴оƬ�ֲ�
//*12 - ���ڵ�8051��8052����ǰ�ľ��󲿷�51��Ƭ��
//*6 - Philips ��оƬ
//*4 - Dallas
#define OSC_PER_INST (12)

typedef  unsigned int UINT16;

//TIME Ϊ��ʱʱ�� ��λMS
#define PRELOAD1MS (65536 - 1*(UINT16)(OSC_FREQ/(OSC_PER_INST*1000)))
#define PRELOAD5MS (65536 - 5*(UINT16)(OSC_FREQ/(OSC_PER_INST*1000)))

extern void LED_Disp(void);


void start_Timeout1ms( void ){
	TMOD |= 0x01;
	TH0 = PRELOAD1MS / 256;
	TL0 = PRELOAD1MS % 256;
	TF0 = 0 ;//�������־λ

	ET0 = 1;    //�ض�ʱ��0���ж�

	TR0 = 1;    //������ʱ��

}

void start_Timeout5ms( void ){
	TMOD |= 0x01;

	TH0 = PRELOAD5MS / 256;
	TL0 = PRELOAD5MS % 256;
	TF0 = 0 ;//�������־λ

	ET0 = 1;    //�ض�ʱ��0���ж�

	TR0 = 1;    //������ʱ��

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
 /* �÷� 
 start_Timeout1ms();
 while(!TF0);    //�ȴ�T0��ʱ
 stop_Timeout();
 */