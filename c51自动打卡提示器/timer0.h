#ifndef __TIMER0_H__
#define __TIMER0_H__

extern void start_Timeout1ms( void );

extern void start_Timeout5ms( void );

extern void stop_Timeout();

extern void Delay5ms();
 /* �÷� 
 start_Timeout1ms();
 while(!TF0);    //�ȴ�T0��ʱ
 stop_Timeout();
 */
 
 #endif