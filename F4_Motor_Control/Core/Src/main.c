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
float Target_Speed = 2;

uint16_t Pwm_Boost_CompareValue = 80;  //boost init compareValue
int Pwm_Motor_CompareValue = 500; //pwm motor init compareValue

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void System_Init(void); // system init
void Set_CompareValue(int CompareValue); //set motor comparevalue

void Boost_Control(void);  //boost
void Motor_Contorl(void);

void StateJudgment(float Speed);

void Direction_Control(void);  // Control the direct

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
  MX_TIM3_Init();
  MX_TIM8_Init();
  /* USER CODE BEGIN 2 */
  System_Init();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  Direction_Control();
	  Motor_Contorl();
	 StateJudgment((float)2000 / 30 / Cycle);
	 //Boost_Control();


	  Update_Data(); //update data,do fliter to change ADC_ValueAverage
	  Tcp_DataAccept(); //get tcp data and deal the wifi request
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
void Set_CompareValue(int CompareValue) {
	if(Up_Flag == 1) {
		__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, 0);
		__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, (uint16_t)CompareValue);
	} else {
		__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 0);
		__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, (uint16_t)CompareValue);
	}
}

uint8_t LastTime_Up_Flag = 1;
void Direction_Control(void) {

	if(HAL_GPIO_ReadPin(Up_Down_GPIO_Port, Up_Down_Pin) == GPIO_PIN_SET) {
		if(LastTime_Up_Flag != 1) {
			Set_CompareValue((int)0);
			Up_Flag = 1;
			LastTime_Up_Flag = 1;
		}

	 } else {
		 if(LastTime_Up_Flag != 0) {
		 	Set_CompareValue((int)0);
		 	Up_Flag = 0;
		 	LastTime_Up_Flag = 0;
		 }
	 }
}

#define BufferSize 400
float MaxRange = 1.02,MinRange = 0.98; //Speed stability range

uint16_t BufferIndex = 0;

uint8_t SystemState = 0; //system status:0init,1Uniform speed,2Lost speed after constant speed,3restore
float StableI = 0; // I at constant speed
void StateJudgment(float Speed) {
	if(SystemState == 0) { //init
		if((Speed < Target_Speed * MinRange) || (Speed > Target_Speed * MaxRange)) {
			BufferIndex = 0;
		} else {
			BufferIndex++;
		}
		if(BufferIndex == BufferSize) {
			SystemState = 1; //constant speed
			StableI = ADC_ValueAverage[1]; //Current at constant speed
			//HAL_GPIO_WritePin(BEEP_GPIO_Port, BEEP_Pin, GPIO_PIN_RESET);
			BufferIndex = 0;
			return;
		}
	}
	if(SystemState == 1) { //constant speed
		if(Speed > Target_Speed * 1.3 || Speed < Target_Speed * 0.7) {
			BufferIndex++;
		} else {
			BufferIndex = 0;
		}
		if(BufferIndex == 10) {
			SystemState = 2;
			//HAL_GPIO_WritePin(BEEP_GPIO_Port, BEEP_Pin, GPIO_PIN_RESET);
			BufferIndex = 0;
			return;
		}
	}
	if(SystemState == 2) { //Enter the speed control state
		if((Speed < Target_Speed * MinRange) || (Speed > Target_Speed * MaxRange)) {
			BufferIndex = 0;
		} else {
			BufferIndex++;
		}
		if(BufferIndex == BufferSize) {
			SystemState = 3; //constant speed
			HAL_GPIO_WritePin(BEEP_GPIO_Port, BEEP_Pin, GPIO_PIN_RESET);
			BufferIndex = 0;
			return;
		}
	}
	if(SystemState == 3) { //the speed is restored
		if(Up_Flag == 1 && (fabs(ADC_ValueAverage[1] - 1.65) > 1.5 * fabs(StableI - 1.65))) {
			HAL_GPIO_WritePin(BEEP_GPIO_Port, BEEP_Pin, GPIO_PIN_RESET);
			//Beep();  //When rising
		}
		if(Up_Flag == 0 && (fabs(ADC_ValueAverage[1] - 1.65) < 0.5 * fabs(StableI - 1.65))) {
			HAL_GPIO_WritePin(BEEP_GPIO_Port, BEEP_Pin, GPIO_PIN_RESET);
			//Beep(); //When falling
		}
		SystemState = 1; //Return to constant speed mode
	}
}

void Motor_Contorl(void) {
	 float Pid_Output = PID_Calc((float)2000 / 30 / Cycle , Target_Speed); //Perform Pid operation
	 Pwm_Motor_CompareValue += (int) Pid_Output; //Pwm+ PIdoutput
	 if(Pwm_Motor_CompareValue >= 1000) {//if compare too high
		 Pwm_Motor_CompareValue = 1000/2;
	 }
	 if(Pwm_Motor_CompareValue <= 0) { //ifcompare too low
		 Pwm_Motor_CompareValue = 0;
	 }
	 Set_CompareValue(Pwm_Motor_CompareValue); //set the compareValue
}

void Boost_Control(void) {
	float Pid_Output = PID_Calc1(ADC_ValueAverage[0], Target_V); //Perform Pid operation
	Pwm_Boost_CompareValue += (uint16_t) Pid_Output; //Pwm+ PIdoutput
	if(Pwm_Boost_CompareValue >= 1000) {//if compare too high
		Pwm_Boost_CompareValue = 1000/2;
	}
	if(Pwm_Boost_CompareValue <= 0) { //if compare too low
		Pwm_Boost_CompareValue = 0;
	}
	__HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_1, Pwm_Boost_CompareValue); //set the compareValue
}


void System_Init(void) {
	  /*WIFI  Init*/
	  Server_Init();
	  HAL_Delay(500);
	  HAL_UART_Receive_IT(&huart1,&Uart1_Rx_Char,1);

	  /*input cap Init*/
	  HAL_TIM_IC_Start_IT(&htim2, TIM_CHANNEL_1);	// Start timer input capture channel
	  __HAL_TIM_ENABLE_IT(&htim2,TIM_IT_UPDATE);	//Enable update interrupt

	  /*ADC  Dma Init*/
	  HAL_ADC_Start_DMA(&hadc1, (uint32_t*)&ADC_Value, Sample_Num * Channel_Num);

	  /*motor Init*/
	  //HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_4);
	  HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
	  HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_2);
	  Set_CompareValue(Pwm_Motor_CompareValue); //motor init

	  /*Boost Init*/
	  HAL_TIM_PWM_Start(&htim8, TIM_CHANNEL_1);
	  HAL_TIMEx_PWMN_Start(&htim8, TIM_CHANNEL_1);//boost init
	  __HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_1, Pwm_Boost_CompareValue);

	  /*pid partParameter Set*/
	  Set_PID_Parameter(20, 5, 0);
	  Set_PID_Parameter1(1, 1, 1);

	  /*tim3 init*/
	  HAL_TIM_Base_Start_IT(&htim3);  //10ms interrupt
}

uint16_t CompareValue_Buffer = 0;
void Tcp_DataDeal(void) {
	  //Server_SentTo_Client(Wifi_Command_Buffer);
	  char Str[50] = {0};
	  if(Strcmp(Wifi_Command_Buffer, (uint8_t *)"Speed\r")) {
		  sprintf(Str, "Speed: %f r/s", (float)2000 / 30 / Cycle);
		  Server_SentTo_Client((uint8_t *)Str);
	  } else if(Strcmp(Wifi_Command_Buffer, (uint8_t *)"I\r")) {
		  sprintf(Str, "Motor_I: %f A", fabs(ADC_ValueAverage[1] - 1.60) * 2);
		  Server_SentTo_Client((uint8_t *)Str);
	  } else if(Strcmp(Wifi_Command_Buffer, (uint8_t *)"V\r")) {
		  sprintf(Str, "Boost_V: %f V", ADC_ValueAverage[0]);
		  Server_SentTo_Client((uint8_t *)Str);
	  } else if(Wifi_Command_Buffer[0] == 'S' && Wifi_Command_Buffer[1] == 'E' && Wifi_Command_Buffer[2] == 'T') {
		  if(Wifi_Command_Buffer[3] == 'C') {
			  for(uint8_t i = 5; Wifi_Command_Buffer[i] != '\r'; i++) {
				  CompareValue_Buffer += Wifi_Command_Buffer[i] - '0';
				  CompareValue_Buffer *= 10;
			  }
			  CompareValue_Buffer /= 10;
			  Pwm_Motor_CompareValue = (int)CompareValue_Buffer;
			  Target_Speed = (float)CompareValue_Buffer;
			  //Set_CompareValue((uint16_t)Pwm_Motor_CompareValue);
			  CompareValue_Buffer = 0;
		  }
		  if(Wifi_Command_Buffer[3] == 'T') {
			  if(Up_Flag == 1) {
				  Up_Flag = 0;
			  } else {
				  Up_Flag = 1;
			  }
	 	  }
	  }
	  else {
		  sprintf(Str, "Cycle:%d\r\nWidth:%d\r\nI: %f A\r\nV: %f V", (int)Cycle, (int)Width, fabs(ADC_ValueAverage[1] - 1.60) * 2, ADC_ValueAverage[0]);
	  	  Server_SentTo_Client((uint8_t *)Str);
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
