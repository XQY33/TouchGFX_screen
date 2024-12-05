/*
 * sdram.h
 *
 *  Created on: May 30, 2024
 *      Author: YY
 */
#ifndef APPLICATION_USER_HARDWARE_SDRAM_H_
#define APPLICATION_USER_HARDWARE_SDRAM_H_

#include <stdint.h>



#define SDRAM_BASE_ADDR  0xC0000000  // SDRAM基地址


#define SCREEN_WIDTH            800         // 屏幕宽度
#define SCREEN_HEIGHT           480         // 屏幕高度
#define BLACK_COLOR             0x00000000  // 清屏颜色（黑色）



#define SDRAM_BANK_ADDR     ((uint32_t)0xC0000000) 				// FMC SDRAM 数据基地址
#define FMC_COMMAND_TARGET_BANK   FMC_SDRAM_CMD_TARGET_BANK1	//	SDRAM 的bank选择
#define SDRAM_TIMEOUT     ((uint32_t)0x1000) 						// 超时判断时间


#define SDRAM_MODEREG_BURST_LENGTH_1             ((uint16_t)0x0000)
#define SDRAM_MODEREG_BURST_LENGTH_2             ((uint16_t)0x0001)
#define SDRAM_MODEREG_BURST_LENGTH_4             ((uint16_t)0x0002)
#define SDRAM_MODEREG_BURST_LENGTH_8             ((uint16_t)0x0004)
#define SDRAM_MODEREG_BURST_TYPE_SEQUENTIAL      ((uint16_t)0x0000)
#define SDRAM_MODEREG_BURST_TYPE_INTERLEAVED     ((uint16_t)0x0008)
#define SDRAM_MODEREG_CAS_LATENCY_2              ((uint16_t)0x0020)
#define SDRAM_MODEREG_CAS_LATENCY_3              ((uint16_t)0x0030)
#define SDRAM_MODEREG_OPERATING_MODE_STANDARD    ((uint16_t)0x0000)
#define SDRAM_MODEREG_WRITEBURST_MODE_PROGRAMMED ((uint16_t)0x0000)
#define SDRAM_MODEREG_WRITEBURST_MODE_SINGLE     ((uint16_t)0x0200)


extern FMC_SDRAM_CommandTypeDef command; // 使用extern声明变量


void SDRAM_Initialization_Sequence(SDRAM_HandleTypeDef *hsdram, FMC_SDRAM_CommandTypeDef *Command);
void SDRAM_Test(void);
void Clear_Framebuffer_DMA2D(uint32_t framebuffer, uint16_t width, uint16_t height, uint32_t color);


#endif /* APPLICATION_USER_HARDWARE_SDRAM_H_ */
