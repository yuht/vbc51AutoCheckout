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
// �������ƣ� UART_init()���ڳ�ʼ������
// �������ܣ� ��ϵͳʱ��Ϊ11.059MHZʱ���趨���ڲ�����Ϊ9600bit/s
//             ���ڽ����ж����������жϽ�ֹ
//--------------------------------------------------------------------------------------------------
extern void UART_init();
//------------------------------------------------------------
extern void COM_send(unsigned char *str, unsigned char Len);

#endif