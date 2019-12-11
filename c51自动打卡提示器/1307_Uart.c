
//#include <60s2.h>
#include <reg52.h>
#include <intrins.h>
#include "1307_uart.h"
#include "serial.h"


#define TURE 1
#define FALSE 0

// unsigned char code systemset_tab[]={0x30,0x87,0x07,0x27,0x3a,0xef,0x28,0x00};
// unsigned char code scroll_tab[]={0x00,0x00,0xf0,0xb0,0x04,0xf0,0x30,0x2a,0xb0,0x4f};

///***********************DS1307开始**************************/

#define Wait2us {_nop_();_nop_();}
#define Wait4us {Wait2us;Wait2us;}
#define Wait8us {Wait4us;Wait4us;}

#define WRITEDS1307 0xD0
#define READDS1307  0xD1

sbit SDA=P0^2; //DS1307 Serial-Data  Input pin 5
sbit SCL=P0^3; //DS1307 Serial-Clock Input pin 6
///************************************************************/
void I2C_start(void);//I2C start function
void I2C_stop(void); //I2C stop  function
//void I2C_send_ack(void);//I2C send responsion function
void I2C_send_noack(void);
unsigned char I2C_write_byte(unsigned char IIC_data);//I2C bus write byte function
unsigned char I2C_read_byte(void);//I2C bus read byte function
///*********************************************************/
// void Write1307(unsigned char add,unsigned char dat);//write information to ds1307
// unsigned char Read1307(unsigned char add);//read information from ds1307
// void Read_RTC(void);//read RTC
// void Set_RTC(void);//set RTC
///*********************************************************/
unsigned char set_rtc_code[8]=	  {00,53,06,05,03,10,14,0x12};
//                                  |  |  |  |  |  |  |  └SQWE(SQWE = 0x12 闪烁频率为1Hz)
//                                  |  |  |  |  |  |  └ YEAR
//                                  |  |  |  |  |  └ Month
//                                  |  |  |  |  └ Date
//                                  |  |  |  └ Day
//                                  |  |  └ Hour
//                                  |  └ Minute
//                                  └ Second
//
//
//
//
//
unsigned char read_rtc_code[7];

///***********************************************************/
//
// void serial_port_one_initial() //9600bps@22.1184MHz
// {
// //     PCON &= 0x7f;        //波特率不倍速
// //     SCON = 0x50;        //8位数据,可变波特率
// //     BRT = 0xB8;        //设定独立波特率发生器重装值
// //     AUXR |= 0x04;        //独立波特率发生器时钟为Fosc,即1T
// //     AUXR |= 0x01;        //串口1选择独立波特率发生器为波特率发生器
// //     AUXR |= 0x10;        //启动独立波特率发生器
// // //    ES      =   1;    //允许串口中断
// // //    EA      =   1;    //开总中断
// }
 
//
void SendData(void)
{

    send_UART_one(2|0x30);
    send_UART_one(0|0x30);

    send_UART_one((read_rtc_code[6]/10)|0x30);
    send_UART_one((read_rtc_code[6]%10)|0x30);
    send_UART_one('/');
    send_UART_one((read_rtc_code[5]/10)|0x30);
    send_UART_one((read_rtc_code[5]%10)|0x30);
    send_UART_one('/');
    send_UART_one((read_rtc_code[4]/10)|0x30);
    send_UART_one((read_rtc_code[4]%10)|0x30);

    send_UART_one(' ');
    send_UART_one((read_rtc_code[3]/10)|0x30);
    send_UART_one((read_rtc_code[3]%10)|0x30);

    send_UART_one(' ');

    send_UART_one((read_rtc_code[2]/10)|0x30);
    send_UART_one((read_rtc_code[2]%10)|0x30);
    send_UART_one(':');
    send_UART_one((read_rtc_code[1]/10)|0x30);
    send_UART_one((read_rtc_code[1]%10)|0x30);
    send_UART_one(':');
    send_UART_one((read_rtc_code[0]/10)|0x30);
    send_UART_one((read_rtc_code[0]%10)|0x30);

}


// void mainJ(void)
// {
//     unsigned char a;

//     serial_port_one_initial();
//     Set_RTC();


//     while(1)
//     {
//         Read_RTC();
//         if( a != read_rtc_code[0])
//         {
//             Uart_Send("Time:[");

//             SendData();
//             a = read_rtc_code[0];
//             Uart_Send("]\r\n");
//         }
//     }
// }


///***********************************************************************/
//  以下为1307及IIC总线
//

void I2C_start(void)
{
    SDA=1;
    SCL=1;
    Wait8us;
    SDA=0;
    Wait8us;
    SCL=0;

}
///***********************************************************************/
void I2C_stop(void)
{
    SDA=0;
    SCL=1;
    Wait8us;
    SDA=1;
    Wait4us;
    SCL=0;
}
///***********************************************************************/
//void I2C_send_ack(void)
//{
// SDA=0;
// SCL=1;
// Wait4us;
// SCL=0;
//}
///*************************************************************************/
void I2C_send_noack(void)
{
    SDA=1;
    SCL=1;
    Wait4us;
    SCL=0;
}
///***********************************************************************/
unsigned char I2C_write_byte(unsigned char IIC_data)
{
    unsigned char i;
    for(i=0;i<8;i++)
    {
        IIC_data=IIC_data<<1;
        F0=SDA=CY;
        SCL=1;
        if(F0!=SDA)
        {
            SCL=0;
            return FALSE;
        }
        Wait2us;
        SCL=0;
    }
    SDA=1;
    Wait2us;
    SCL=1;
    Wait2us;
    if(SDA==1)
    {
        SCL=0;
        return FALSE;
    }
    else
    {
        SCL=0;
        return TURE;
    }
}
///***********************************************************************/
unsigned char I2C_read_byte(void)
{
    unsigned char i,dat;
    dat=0;
    SDA=1;
    for (i=0;i<8;i++)
    {
        dat=dat<<1;
        SCL=1;
        Wait2us;
        if(SDA==1)
        {
            dat++;
        }

        SCL=0;
    }
    return (dat);
}
///***********************************************************************/
///******************************** DS1307 PART START ****************/
void Write1307(unsigned char add,unsigned char dat)
{
//     unsigned char temp;
//     temp=dat/10;		//hex转bcd
//     temp<<=4;
//     temp=dat%10+temp;

	
    I2C_start();
    I2C_write_byte(WRITEDS1307);
    I2C_write_byte(add);
    //I2C_write_byte(temp);
	I2C_write_byte(dat);
	
    I2C_stop();
}
///***********************************************************************/
unsigned char Read1307(unsigned char add)
{

    unsigned char /*temp,*/dat;
    I2C_start();
    I2C_write_byte(WRITEDS1307);
    I2C_write_byte(add);
    I2C_start();
    I2C_write_byte(READDS1307);
    dat=I2C_read_byte();
    I2C_send_noack();
    I2C_stop();
//     temp=dat/16;	//bcd转hex
//     dat=dat%16;
//     dat=dat+temp*10;
    return (dat);
}
///****************************读DS1307的寄存器*******************************************/
void Read_RTC(void)
{
    unsigned char i,temp;
	
    for(i=0;i<7;i++)
    {
        temp = Read1307(i);
		read_rtc_code[i] = (temp>>4)*10 + (temp & 0x0f); //bcd =>hex
    }
	read_rtc_code[7] = Read1307(7);// Control register
}
///***************************DS1307的初始化********************************************/
void Set_RTC(void)
{
    unsigned char i,temp;

    for(i=0;i<7;i++)
    {
		temp = ((set_rtc_code[i]/10)<<4) + (set_rtc_code[i]%10);	//hex => bcd
        Write1307(i,temp);
    }
	Write1307(i,set_rtc_code[7]); // Control register
}

void Set_1307_User_Data(unsigned char * userdata, unsigned char len)
{
	unsigned  char i;
	if(len <56)
	{
		for(i = 0;i<len;i++)
		{
			Write1307(8+i,*(userdata+i));
		}
	}
}
 
void Read_1307_User_Data(unsigned char * userdata, unsigned char len)
{
	unsigned  char i;
	if(len <56)
	{
		for(i = 0;i<len;i++)
		{
			*(userdata+i) = Read1307(i+8);
		}
	}
}