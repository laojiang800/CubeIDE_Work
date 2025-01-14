/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdio.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
uint32_t Cycle = 0, Width = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_TIM2_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_IC_Start_IT(&htim2, TIM_CHANNEL_1);	// 开启输入捕获中断
  __HAL_TIM_ENABLE_IT(&htim2,TIM_IT_UPDATE);	//使能更新中断
 // long long temp = 0;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

	  HAL_Delay(10);
	  printf("Cycle = %d  Width = %d\r\n", Cycle, Width);
	    // 信号发生器输入信号 串口打印高电平时长  ms
	   /* if (TIM5CH1_CAPTURE_STA & 0x80)   // 如果捕获完成
	    {
	        temp = TIM5CH1_CAPTURE_STA & 0x3f;
	        temp *= 0xffff;				// Total Overflow Time(总的溢出时间)
	        temp += TIM5CH1_CAPTURE_VAL;    // Get Total High Level Time(获取总的高电平时长)
	      //  printf("HIGH: %f ms\r\n", (float)temp/1000); // Print Total High Level Time(打印总的高电平时长)
	        TIM5CH1_CAPTURE_STA = 0;			    // Clear Capture State , Open The Next Capture(清除捕获状态，打开下一次捕获)
	    } */
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI_DIV2;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL16;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

//看此教程https://blog.csdn.net/Kevin_8_Lee/article/details/104350954

/*	bit7 捕获完成标识	bit6 捕获到高电平标识	bit5~0 捕获高电平后定时器溢出的次数 */
uint8_t		TIM5CH1_CAPTURE_STA = 0;	// 输入捕获状态
uint32_t	TIM5CH1_CAPTURE_VAL;		// 输入捕获值(TIM2/TIM5是32位的定时器所以这里定义为uint32_t)

// 中断服务函数里面会自动调用这个回调函数  这个是定时器更新中断中处理的函数
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  if (htim->Instance == TIM2)	// 判断是定时器5发生中断
  {
    if ((TIM5CH1_CAPTURE_STA & 0x80) == 0) // 还未成功捕获
    {
      if (TIM5CH1_CAPTURE_STA & 0x40)		   // 捕获到高电平
      {
        if ( (TIM5CH1_CAPTURE_STA & 0x3f) == 0x3f )		// 如果高电平太长  做溢出处理
        {
          TIM5CH1_CAPTURE_STA |= 0x80;				// 标记成功捕获了一次
          TIM5CH1_CAPTURE_VAL = 0xffffffff;
        }
        else
        {
          TIM5CH1_CAPTURE_STA++;		// 若没有溢出, 就只让TIM5CH1_CAPTURE_STA自加就ok
        }
      }
    }
  }
}

// 定时器输入捕获中断处理回调函数，该函数在 HAL_TIM_IRQHandler(TIM_HandleTypeDef *htim) 中会被调用

uint8_t  DownEdgeFlag = 0;
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
  if ( (TIM5CH1_CAPTURE_STA & 0x80) == 0 )	// 还未成功捕获
  {
    if (TIM5CH1_CAPTURE_STA & 0x40)			// 捕获到一个下降沿
    {
      //TIM5CH1_CAPTURE_STA |= 0x80;		// 标记成功捕获到一次高电平脉宽
      TIM5CH1_CAPTURE_VAL = HAL_TIM_ReadCapturedValue(&htim2, TIM_CHANNEL_1);	// 获取当前的捕获值. 即CCRx2

     // if (TIM5CH1_CAPTURE_STA & 0x80)   // 如果捕获完成
      	   // {
      Width = TIM5CH1_CAPTURE_STA & 0x3f;
      Width *= 0xffff;				// Total Overflow Time(总的溢出时间)
      Width += TIM5CH1_CAPTURE_VAL;    // Get Total High Level Time(获取总的高电平时长)
      	      //  printf("HIGH: %f ms\r\n", (float)temp/1000); // Print Total High Level Time(打印总的高电平时长)
      //TIM5CH1_CAPTURE_STA = 0;			    // Clear Capture State , Open The Next Capture(清除捕获状态，打开下一次捕获)
      	   //}
      TIM5CH1_CAPTURE_STA &= 0xbf;
      DownEdgeFlag = 1;


      TIM_RESET_CAPTUREPOLARITY(&htim2, TIM_CHANNEL_1);						// 清除原来的设置
      TIM_SET_CAPTUREPOLARITY(&htim2, TIM_CHANNEL_1, TIM_ICPOLARITY_RISING);	// 配置TIM5通道1上升沿捕获

    }
    else
    {

    	if(DownEdgeFlag == 1) {
    		TIM5CH1_CAPTURE_VAL = HAL_TIM_ReadCapturedValue(&htim2, TIM_CHANNEL_1);
    		Cycle = TIM5CH1_CAPTURE_STA & 0x3f;
    		Cycle *= 0xffff;				// Total Overflow Time(总的溢出时间)
    		Cycle += TIM5CH1_CAPTURE_VAL;    // Get Total High Level Time(获取总的高电平时长)

    		TIM5CH1_CAPTURE_STA = 0;
    		TIM5CH1_CAPTURE_VAL = 0;

    		DownEdgeFlag = 0;
    	} else {


      TIM5CH1_CAPTURE_STA = 0;	// 清空自定义的状态寄存器
      TIM5CH1_CAPTURE_VAL = 0;	// 清空捕获值
      TIM5CH1_CAPTURE_STA |= 0x40;// 标记捕获到了上升沿
      __HAL_TIM_DISABLE(&htim2);	//关闭定时器5
      __HAL_TIM_SET_COUNTER(&htim2,0);
      TIM_RESET_CAPTUREPOLARITY(&htim2,TIM_CHANNEL_1);   //一定要先清除原来的设置！！
      TIM_SET_CAPTUREPOLARITY(&htim2,TIM_CHANNEL_1,TIM_ICPOLARITY_FALLING);//定时器5通道1设置为下降沿捕获
      __HAL_TIM_ENABLE(&htim2);//使能定时器5
    	}


    }
  }
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
