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
#include "adc.h"
#include "dma.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "wifi.h"
#include "inputcap.h"
#include "AdcDma.h"
#include "pid.h"
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
uint8_t Up_Flag = 1;  // 1 up 0 down

float Target_V = 15;
float Target_Speed = 3;

uint16_t Pwm_CH4_CompareValue = 0;
uint16_t Pwm_Motor_CompareValue = 0;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void System_Init(void); // system init
void Set_CompareValue(uint8_t CompareValue);
void Boost_Control(void);
uint8_t StateJudgment(float Speed);

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
  MX_DMA_Init();
  MX_TIM2_Init();
  MX_USART1_UART_Init();
  MX_ADC1_Init();
  MX_TIM1_Init();
  /* USER CODE BEGIN 2 */
  System_Init();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  float Pid_Output = PID_Calc((float)2000 / Cycle, Target_Speed); //进行Pid运算
	  Pwm_Motor_CompareValue += (uint16_t) Pid_Output; //pwm比较值加上pid运算结果，实现闭环控制
	  if(Pwm_Motor_CompareValue >= 100) {//如果占空比大于1则，回调为1/2
		  Pwm_Motor_CompareValue = 100/2;
	  }
	  if(Pwm_Motor_CompareValue <= 0) { //如果占空比小于0则调为0
		  Pwm_Motor_CompareValue = 0;
	  }
	  Set_CompareValue((uint8_t)Pwm_Motor_CompareValue); //进行占空比调整



	  Boost_Control();
	  Update_Data();
	  Tcp_DataDeal();
	 // Tcp_DataAccept();
    /* USER CODE END WHILE */

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

  /** Configure the main internal regulator output voltage 
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
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
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void Set_CompareValue(uint8_t CompareValue) {
	if(Up_Flag == 1) {
		__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, 0);
		__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, CompareValue);
	} else {
		__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 0);
		__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, CompareValue);
	}
}

uint8_t BufferSize = 10;
float Speed_Buffer[BufferSize];
uint8_t StateJudgment(float Speed) {


}



void Boost_Control(void) {
	float Pid_Output = PID_Calc1(ADC_ValueAverage[0], Target_V); //进行Pid运算
	Pwm_CH4_CompareValue += (uint16_t) Pid_Output; //pwm比较值加上pid运算结果，实现闭环控制
	if(Pwm_CH4_CompareValue >= 100) {//如果占空比大于1则，回调为1/2
		Pwm_CH4_CompareValue = 100/2;
	}
	if(Pwm_CH4_CompareValue <= 0) { //如果占空比小于0则调为0
		Pwm_CH4_CompareValue = 0;
	}
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, Pwm_CH4_CompareValue); //进行占空比调整
}



void System_Init(void) {
	  /*WIFI  Init*/
	  Server_Init();
	  HAL_Delay(500);
	  HAL_UART_Receive_IT(&huart1,&Uart1_Rx_Char,1);

	  /*input cap Init*/
	  HAL_TIM_IC_Start_IT(&htim2, TIM_CHANNEL_1);	// �???????????????启输入捕获中�???????????????
	  __HAL_TIM_ENABLE_IT(&htim2,TIM_IT_UPDATE);	//使能更新中断

	  /*ADC  Dma Init*/
	  HAL_ADC_Start_DMA(&hadc1, (uint32_t*)&ADC_Value, Sample_Num * Channel_Num);

	  /*PWM Init*/
	  HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_4);
	  HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
	  HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_2);

	  /*pid partParameter Set*/
	  Set_PID_Parameter(1,1,1);
	  Set_PID_Parameter1(1,1,1);

}

void Tcp_DataDeal(void) {
	  //Server_SentTo_Client(Wifi_Command_Buffer);
	  char Str[40] = {0};
	  sprintf(Str, "Cycle:%d|Width:%d|I:%f|V:%f", (int)Cycle, (int)Width, ADC_ValueAverage[0], ADC_ValueAverage[1]);
	  Server_SentTo_Client((uint8_t *)Str);
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