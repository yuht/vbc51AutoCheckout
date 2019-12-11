#ifndef __1307_UART_H__
#define __1307_UART_H__
extern void Set_RTC(void);
extern void Read_RTC(void);
extern unsigned char read_rtc_code[];
extern void send_UART_one(unsigned char i);
extern void Uart_Send(unsigned char *p );
extern void SendData(void);

void Set_1307_User_Data(unsigned char * userdata, unsigned char len);
 
void Read_1307_User_Data(unsigned char * userdata, unsigned char len);
extern unsigned char read_rtc_code[];
extern unsigned char set_rtc_code[];



#endif