/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
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

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "app_touchgfx.h"
#include "usart.h"
#include "stdio.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
DataPacket packet;
int ECG_flag;
uint8_t rx_buffer[172];

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */


uint32_t unpack_uint32(const uint8_t *data) {
    // 确保从小端字节序数据中提取一�?32位无符号整数
    return (uint32_t)data[0] |
           (uint32_t)data[1] << 8 |
           (uint32_t)data[2] << 16 |
           (uint32_t)data[3] << 24;
}

void unpack_data(const uint8_t *data, DataPacket *packet) {
    // 复制ECG数据
    for (int i = 0; i < ECG_DATA_SIZE; i++) {
        packet->ecg_data[i] = unpack_uint32(data);
        data += 4;
    }

    // 复制心率
    packet->heart_rate = unpack_uint32(data);
    data += 4;

    // 复制体温
    packet->body_temperature = unpack_uint32(data);
    data += 4;

    // 复制�?�?
    packet->blood_oxygen = unpack_uint32(data);
}

void print_packet(const DataPacket *packet) {
    printf("ECG Data: ");
    for (int i = 0; i < ECG_DATA_SIZE; i++) {
        printf("%u ", packet->ecg_data[i]);
    }
    printf("\n");

    printf("Heart Rate: %u\n", packet->heart_rate);
    printf("Body Temperature: %u\n", packet->body_temperature);
    printf("Blood Oxygen: %u\n", packet->blood_oxygen);
}


uint8_t data[] = {
        // ecg_data[40]
        0x01, 0x00, 0x00, 0x00, // 1
        0x02, 0x00, 0x00, 0x00, // 2
        0x03, 0x00, 0x00, 0x00, // 3
        0x04, 0x00, 0x00, 0x00, // 4
        0x05, 0x00, 0x00, 0x00, // 5
        0x06, 0x00, 0x00, 0x00, // 6
        0x07, 0x00, 0x00, 0x00, // 7
        0x08, 0x00, 0x00, 0x00, // 8
        0x09, 0x00, 0x00, 0x00, // 9
        0x0A, 0x00, 0x00, 0x00, // 10
        0x0B, 0x00, 0x00, 0x00, // 11
        0x0C, 0x00, 0x00, 0x00, // 12
        0x0D, 0x00, 0x00, 0x00, // 13
        0x0E, 0x00, 0x00, 0x00, // 14
        0x0F, 0x00, 0x00, 0x00, // 15
        0x10, 0x00, 0x00, 0x00, // 16
        0x11, 0x00, 0x00, 0x00, // 17
        0x12, 0x00, 0x00, 0x00, // 18
        0x13, 0x00, 0x00, 0x00, // 19
        0x14, 0x00, 0x00, 0x00, // 20
        0x15, 0x00, 0x00, 0x00, // 21
        0x16, 0x00, 0x00, 0x00, // 22
        0x17, 0x00, 0x00, 0x00, // 23
        0x18, 0x00, 0x00, 0x00, // 24
        0x19, 0x00, 0x00, 0x00, // 25
        0x1A, 0x00, 0x00, 0x00, // 26
        0x1B, 0x00, 0x00, 0x00, // 27
        0x1C, 0x00, 0x00, 0x00, // 28
        0x1D, 0x00, 0x00, 0x00, // 29
        0x1E, 0x00, 0x00, 0x00, // 30
        0x1F, 0x00, 0x00, 0x00, // 31
        0x20, 0x00, 0x00, 0x00, // 32
        0x21, 0x00, 0x00, 0x00, // 33
        0x22, 0x00, 0x00, 0x00, // 34
        0x23, 0x00, 0x00, 0x00, // 35
        0x24, 0x00, 0x00, 0x00, // 36
        0x25, 0x00, 0x00, 0x00, // 37
        0x26, 0x00, 0x00, 0x00, // 38
        0x27, 0x00, 0x00, 0x00, // 39
        0x28, 0x00, 0x00, 0x00, // 40
        0x2C, 0x01, 0x00, 0x00, // heart_rate 300
        0x90, 0x01, 0x00, 0x00, // body_temperature 400
        0x5E, 0x01, 0x00, 0x00  // blood_oxygen 350
    };


/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
osThreadId TouchGFX_TaskHandle;
osThreadId LEDHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void Start_TouchGFX_Task(void const * argument);
void StartTaskLED(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */
//  Wifi_Init(osPriorityNormal);

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of TouchGFX_Task */
  osThreadDef(TouchGFX_Task, Start_TouchGFX_Task, osPriorityNormal, 0, 4096);
  TouchGFX_TaskHandle = osThreadCreate(osThread(TouchGFX_Task), NULL);

  /* definition and creation of LED */
  osThreadDef(LED, StartTaskLED, osPriorityLow, 0, 128);
  LEDHandle = osThreadCreate(osThread(LED), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_Start_TouchGFX_Task */
/**
  * @brief  Function implementing the TouchGFX_Task thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_Start_TouchGFX_Task */
void Start_TouchGFX_Task(void const * argument)
{
  /* USER CODE BEGIN Start_TouchGFX_Task */
	MX_TouchGFX_Process();
  /* Infinite loop */
  for(;;)
  {
    osDelay(50);
  }
  /* USER CODE END Start_TouchGFX_Task */
}

/* USER CODE BEGIN Header_StartTaskLED */
/**
* @brief Function implementing the LED thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTaskLED */
void StartTaskLED(void const * argument)
{
  /* USER CODE BEGIN StartTaskLED */

  /* Infinite loop */
  for(;;)
  {
      HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);

      HAL_UART_Receive_IT(&huart2, rx_buffer, 172);

      osDelay(50);
  /* USER CODE END StartTaskLED */
}
}
/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{

	unpack_data(rx_buffer, &packet);
	print_packet(&packet);
}
/* USER CODE END Application */
