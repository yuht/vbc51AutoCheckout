#ifndef __TIMER0_H__
#define __TIMER0_H__

extern void start_Timeout1ms( void );

extern void start_Timeout5ms( void );

extern void stop_Timeout();

extern void Delay5ms();
 /* 用法 
 start_Timeout1ms();
 while(!TF0);    //等待T0超时
 stop_Timeout();
 */
 
 #endif