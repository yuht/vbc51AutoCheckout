
#ifndef __FLASH_H__
#define __FLASH_H__
 
 
typedef unsigned char INT8U;  // 8 bit �޷�������  
typedef unsigned int  INT16U;     // 16 bit �޷�������  

// �� ISP,IAP ���� 
extern void ISP_IAP_enable(void);
// �ر� ISP,IAP ���� 
extern void ISP_IAP_disable(void);

//�������� 
//INT8U
extern void  sector_erase(INT16U sector_addr);

// �ֽڶ� 
extern INT8U  byte_read(INT16U byte_addr);
 
// �ֽڱ�� 
//INT8U 
extern void byte_program(INT16U byte_addr, INT8U original_data);

#endif