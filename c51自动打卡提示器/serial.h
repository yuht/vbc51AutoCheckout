#ifndef __SERIAL_H__
#define __SERIAL_H__

#define UARTRECBUFFLEN 50
extern unsigned char UartRecBuff[];
extern unsigned char UartRecBuffLen;
extern unsigned char UartRecTimeoutMux5ms;

extern void send_UART_one(unsigned char i);

extern void Uart_Send(unsigned char *p );

//-------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
// 函数名称： UART_init()串口初始化函数
// 函数功能： 在系统时钟为11.059MHZ时，设定串口波特率为9600bit/s
//             串口接收中断允许，发送中断禁止
//--------------------------------------------------------------------------------------------------
extern void UART_init();
//------------------------------------------------------------
extern void COM_send(unsigned char *str, unsigned char Len);

#endif