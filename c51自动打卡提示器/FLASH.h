
#ifndef __FLASH_H__
#define __FLASH_H__
 
 
typedef unsigned char INT8U;  // 8 bit 无符号整型  
typedef unsigned int  INT16U;     // 16 bit 无符号整型  

// 打开 ISP,IAP 功能 
extern void ISP_IAP_enable(void);
// 关闭 ISP,IAP 功能 
extern void ISP_IAP_disable(void);

//扇区擦除 
//INT8U
extern void  sector_erase(INT16U sector_addr);

// 字节读 
extern INT8U  byte_read(INT16U byte_addr);
 
// 字节编程 
//INT8U 
extern void byte_program(INT16U byte_addr, INT8U original_data);

#endif