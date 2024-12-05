/*
 * sdram.c
 *
 *  Created on: May 30, 2024
 *      Author: YY
 */
#include "fmc.h"
#include "sdram.h"
#include "stdio.h"
FMC_SDRAM_CommandTypeDef command;	// 控制指令


/******************************************************************************************************
*	函 数 名: SDRAM_Initialization_Sequence
*	入口参数: hsdram - SDRAM_HandleTypeDef定义的变量，即表示定义的sdram
*				 Command	- 控制指令
*	返 回 值: 无
*	函数功能: SDRAM 参数配置
*	说    明: 配置SDRAM相关时序和控制方式
*******************************************************************************************************/

void SDRAM_Initialization_Sequence(SDRAM_HandleTypeDef *hsdram, FMC_SDRAM_CommandTypeDef *Command)
{
	__IO uint32_t tmpmrd = 0;

	/* Configure a clock configuration enable command */
	Command->CommandMode 				= FMC_SDRAM_CMD_CLK_ENABLE;	// 开启SDRAM时钟
	Command->CommandTarget 				= FMC_COMMAND_TARGET_BANK; 	// 选择要控制的区域
	Command->AutoRefreshNumber 		= 1;
	Command->ModeRegisterDefinition 	= 0;

	HAL_SDRAM_SendCommand(hsdram, Command, SDRAM_TIMEOUT);	// 发送控制指令
	HAL_Delay(1);		// 延时等待

	/* Configure a PALL (precharge all) command */
	Command->CommandMode 				= FMC_SDRAM_CMD_PALL;		// 预充电命令
	Command->CommandTarget 				= FMC_COMMAND_TARGET_BANK;	// 选择要控制的区域
	Command->AutoRefreshNumber 		= 1;
	Command->ModeRegisterDefinition 	= 0;

	HAL_SDRAM_SendCommand(hsdram, Command, SDRAM_TIMEOUT);  // 发送控制指令

	/* Configure a Auto-Refresh command */
	Command->CommandMode 				= FMC_SDRAM_CMD_AUTOREFRESH_MODE;	// 使用自动刷新
	Command->CommandTarget 				= FMC_COMMAND_TARGET_BANK;          // 选择要控制的区域
	Command->AutoRefreshNumber			= 8;                                // 自动刷新次数
	Command->ModeRegisterDefinition 	= 0;

	HAL_SDRAM_SendCommand(hsdram, Command, SDRAM_TIMEOUT);	// 发送控制指令

	/* Program the external memory mode register */
	tmpmrd = (uint32_t)SDRAM_MODEREG_BURST_LENGTH_2         |
							SDRAM_MODEREG_BURST_TYPE_SEQUENTIAL   |
							SDRAM_MODEREG_CAS_LATENCY_3           |
							SDRAM_MODEREG_OPERATING_MODE_STANDARD |
							SDRAM_MODEREG_WRITEBURST_MODE_SINGLE;

	Command->CommandMode					= FMC_SDRAM_CMD_LOAD_MODE;	// 加载模式寄存器命令
	Command->CommandTarget 				= FMC_COMMAND_TARGET_BANK;	// 选择要控制的区域
	Command->AutoRefreshNumber 		= 1;
	Command->ModeRegisterDefinition 	= tmpmrd;

	HAL_SDRAM_SendCommand(hsdram, Command, SDRAM_TIMEOUT);	// 发送控制指令

	HAL_SDRAM_ProgramRefreshRate(hsdram, 918);  // 配置刷新率

}





void SDRAM_Test(void)
{
  uint32_t *sdram_address = (uint32_t *)0xC0000000; // SDRAM 基地�?
  uint32_t write_data = 0x12345678;
  uint32_t read_data;

  //  写入数据 SDRAM
  *sdram_address = write_data;

  // SDRAM 读取数据
  read_data = *sdram_address;

  // 查读取的数据是否正确
  if (read_data == write_data)
  {	HAL_Delay(1);
  	printf("sdram_test_past\n");

  }
  else
  {
  	HAL_Delay(1);
  	printf("sdram_test_error\n");
  }
}




extern DMA2D_HandleTypeDef hdma2d;  // 确保这是您在CubeMX中生成的DMA2D句柄变量





extern DMA2D_HandleTypeDef hdma2d;  // 确保这是您在CubeMX中生成的DMA2D句柄变量

/**
  * @brief  使用DMA2D快速清空显存
  * @param  framebuffer 地址指针
  * @param  width 显存的宽度，单位是像素
  * @param  height 显存的高度，单位是像素
  * @param  color 要填充的颜色，通常为黑色0x00000000
  * @retval None
  */
void Clear_Framebuffer_DMA2D(uint32_t framebuffer, uint16_t width, uint16_t height, uint32_t color)
{
    /* 配置DMA2D传输参数 */
    hdma2d.Init.Mode = DMA2D_R2M;                       // 设置为寄存器到内存模式
    hdma2d.Init.ColorMode = DMA2D_OUTPUT_ARGB8888;      // 设置颜色模式为ARGB8888
    hdma2d.Init.OutputOffset = 0;                       // 输出偏移设为0

    /* 配置层参数，这一步通常不必改动，除非有特殊需求 */
    hdma2d.LayerCfg[1].InputOffset = 0;                 // 输入偏移设为0
    hdma2d.LayerCfg[1].InputColorMode = DMA2D_INPUT_ARGB8888; // 输入颜色模式
    hdma2d.LayerCfg[1].AlphaMode = DMA2D_NO_MODIF_ALPHA; // Alpha模式不修改
    hdma2d.LayerCfg[1].InputAlpha = 0xFF;               // 输入Alpha值设为255

    /* 重新初始化配置，如果在应用中多次改变配置，需要调用此函数 */
    HAL_DMA2D_Init(&hdma2d);
    HAL_DMA2D_ConfigLayer(&hdma2d, 1);

    /* 启动DMA2D传输 */
    HAL_DMA2D_Start(&hdma2d, color, framebuffer, width, height);
    /* 轮询等待传输完成 */
    HAL_DMA2D_PollForTransfer(&hdma2d, 10);  // 10毫秒超时
}



