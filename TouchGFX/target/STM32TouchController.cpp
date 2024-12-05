/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : STM32TouchController.cpp
  ******************************************************************************
  * This file was created by TouchGFX Generator 4.23.2. This file is only
  * generated once! Delete this file from your project and re-generate code
  * using STM32CubeMX or change this file manually to update it.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* USER CODE BEGIN STM32TouchController */

#include <STM32TouchController.hpp>

extern "C"
{
	#include "touch_800x480.h"
}

void STM32TouchController::init()
{

	Touch_Init();
	HAL_GPIO_WritePin(BL_GPIO_Port, BL_Pin, GPIO_PIN_SET);

}

bool STM32TouchController::sampleTouch(int32_t& x, int32_t& y)
{
	Touch_Scan();	// 调用触摸扫描

	if(touchInfo.flag == 1)		// 如果�?????测到触摸
	{
		x = touchInfo.x[0];		// 赋予坐标�?????
		y = touchInfo.y[0];
		return true;
	}
	else
	{
		return false;
	}


}

/* USER CODE END STM32TouchController */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
