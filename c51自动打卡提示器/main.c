//���������74HC164��������

#include<reg51.H>
#include "intrins.h"
#include "string.h" 
#include "74hc164.h"
#include "serial.h"
#include "timer0.h"
#include "1307_uart.h"

typedef  unsigned int uint;

typedef  unsigned char uchar;


typedef struct structPromptTime{
	uint PromptStartHM; 
	uint PromptEndHM; 
}tagPromptTime;

typedef union union2byte{
	uchar a[2];
	uint b;
}tag2byte;

tag2byte	K;
tagPromptTime PromptTime[2];
#define PROMPTTIMELEN (8)

sbit ISD1110PLAYE = P0^4;	//edge�½���ʹ�ܣ����ŵ�ֹͣ
sbit ISD1110PLAYL = P0^5;	//level �͵�ƽʹ�ܣ����ŵ�ֹͣ��ߵ�ƽֹͣ

sbit CmpPin = P0^6;
sbit In		= P0^7;

// Head	comd	data(hex)...
// Yuht 1	  	7 	sec, min , hor ,date ,day ,mon ,year
// Yuht 2     	4 	��ʼh����ʼm������h������m
// Yuht 3     	4	��ʼh����ʼm������h������m
void ProcessUartData(void)
{ 
	unsigned char *ptr;
	if(UartRecTimeoutMux5ms >20) //5*20 = 100ms
	{
		if(UartRecBuffLen>4) //�յ�����ͷ
		{
			if(memcmp(UartRecBuff,"Yuht",4) == 0)
			{
				switch(UartRecBuff[4])
				{
					case 1: // 7 sec, min , hor ,date ,day ,mon ,year
					{
						if(UartRecBuffLen>11)
						{
							memcpy(set_rtc_code,&UartRecBuff[5],7);
							Set_RTC();							
						}
						
						break;
					}
					case 2:	//PromptTime1
					case 3:	//PromptTime2
					{
						if(UartRecBuffLen>8)
						{
							ptr = (unsigned char *)&PromptTime[UartRecBuff[4]-2];
							if(memcmp(ptr,&UartRecBuff[5],4))
							{
								memcpy(ptr,&UartRecBuff[5],4);
								ptr = (unsigned char *)PromptTime; 
								Set_1307_User_Data(ptr, PROMPTTIMELEN); 
							}
						}
						break;
					}
					case 4:
					{
						COM_send(read_rtc_code, 7);
						COM_send((uchar *)&PromptTime, 8);
						break;
					}
					default :
						break;
				}
			}
		}
		UartRecBuffLen = 0 ;
		UartRecTimeoutMux5ms = 0;
	} 
}

main()
{
	unsigned char *ptr; 
// 	unsigned char abc;
	unsigned char Sec,i,j;
	bit Point;
	P0 = P1 = P2 = P3 = 0xff;
	start_Timeout5ms();
	UART_init();
// 	COM_send("uart inited\r\n",sizeof("uart inited\r\n")-1);

	ptr = (unsigned char *)PromptTime;

	Read_1307_User_Data( ptr , PROMPTTIMELEN);
	
// 	COM_send( ptr, 8);

	while (1)
	{
		Read_RTC();
		if( Sec != read_rtc_code[0])
		{
			//====================================================================
			//��ȡʱ��
			Sec = read_rtc_code[0];
			Point = !Point;
			for(i=0;i<11;i++)	//0~9,����10������
			{
				if(Point)
					tab[i-1] |= 0x01;
				else
					tab[i-1] &= 0xFE;
			}
			
			K.a[1]=read_rtc_code[1]; //min
			K.a[0]=read_rtc_code[2]; //h
			//=====================================================================
			//��ȡʱ���
			j=0;

			for(i =0 ;i<2 ;i++)
			{
				if( PromptTime[i].PromptStartHM <= PromptTime[i].PromptEndHM ) //���䣬����Խ0��
				{
					if(	( K.b >= PromptTime[i].PromptStartHM ) &&
						( K.b <= PromptTime[i].PromptEndHM ) )
					{
						j=1;	//����ʱ���
						break;
					}
				}
				else	//����,��Խ����㣬��Ϊ��ʼʱ�䡫23:59��0x173B������00:00������ʱ��
				{
					if(	((K.b <= 0x173B) && (K.b >= PromptTime[i].PromptStartHM)) ||
						((K.b <= PromptTime[i].PromptEndHM)/* && (K.b >= 0x0000)*/))
					{
						j=1;	//����ʱ���
						break;
					}
				}				
			}
			//====================================================================
		}
		ISD1110PLAYE = 1;
		if( (j) && (In == CmpPin) )//��ʱ���
		{
			ISD1110PLAYE = 0;
		}
// 		else
// 		{
// 			ISD1110PLAYE = 1;
// 		}
		ProcessUartData();
	}
}



 
