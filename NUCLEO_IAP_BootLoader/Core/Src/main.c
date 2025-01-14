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
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdio.h"
#include "flash.h"
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

uint8_t Uart1_Rx_Char;		// 用来接收串口1收到的的数据
uint8_t Uart1_Rx_Buffer[150] = {0};
//uint8_t Wifi_Command_Buffer[100] = {0};
uint8_t Rx_Buffer_Size = 0;
//uint8_t Rx_Line_Flag = 0;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

void go2APP(void);

void Data_Manage(uint8_t Is_Last_Page);

void Download_App(void);
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
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
  HAL_UART_Receive_IT(&huart1,&Uart1_Rx_Char,1);
  //printf("BOOTLOADER Start\r\n");
/*
  uint8_t Flash_Test[1024] = {0};
  for(int i = 0; i < 256; i++) {
	  Flash_Test[i] = 25;
  }
  Flash_Write_Page(0x08008000, Flash_Test);
  uint32_t t =  *(uint32_t *)0x08008400;
  while(1);
*/
 // printf("C");
  //printf("C");
/*
  //printf("C\r\n");
  printf("C\n");
 // int i = 0;
  uint8_t ReceiveFile_End_Flag = 0;
  uint8_t temp[10] = {0}, i = 0;
 // uint8_t Last_Buffer_Size = 0;
  while(1) {

	  if(Rx_Buffer_Size == 133) { //一帧数据接受完成

		  if(Uart1_Rx_Buffer[1] == 0) { //为起始帧
			  printf("%c", 6);//返回ACK
			  printf("C\n");
		  } else {  //每一帧正文数据  在printf前处理

			  Data_Manage(0);

			  printf("%c\n", 6);//返回ACK
			 // printf("C\r\n");
		  }

		  //Rx_Buffer_Size = 0;
		 // printf("%c", 6);
		 // printf("C\r\n");
		//  i++;
		  Rx_Buffer_Size = 0;
	    }


 	//  if((Rx_Buffer_Size - Last_Buffer_Size) == 1 && Rx_Buffer_Size == 1) { //检查第一位
	  	  if(Rx_Buffer_Size == 1) {
 		 // temp[i] = Uart1_Rx_Buffer[0];
 		  //i++;

		  if(Uart1_Rx_Buffer[0] == 4) { //文件传送结束
				/*
			  if(ReceiveFile_End_Flag == 1) {
				  printf("%c", 6); //返回ACK
				  printf("C\r\n");
				  //ReceiveFile_End_Flag = 1;
				  Rx_Buffer_Size = 0;
			  }

			  if(ReceiveFile_End_Flag == 0) { //发送方发送的第一个EOT 此处处理收尾

				  Data_Manage(1);

				//  while(1);

				  printf("%c\n", 21); //返回NAK
				  ReceiveFile_End_Flag = 1;
				  Rx_Buffer_Size = 0;
			  }
		  }

	  }

 	// Last_Buffer_Size = Rx_Buffer_Size;
  }
*/
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  if(HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin)) { //user app
		 // printf("button is up\r\n");
		//  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin,GPIO_PIN_RESET);
		  go2APP();
	  } else { //bootloader
		 // printf("button is down\r\n");

		  //HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);

		  Download_App();
		  go2APP();
		  //printf("C");
		  //HAL_FLASH
	  }
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

#define FLASH_APP_ADDR 0x8008000
typedef void (*pFunction)(void);

void go2APP(void) {
  uint32_t JumpAddress;
  pFunction Jump_To_Application;

  //printf("BOOTLOADER Start\n");

  //Check
  if (((*(__IO uint32_t*) FLASH_APP_ADDR) & 0x2FFE0000) == 0x20000000) {
    printf("APP Start...\n");
    HAL_Delay(100);
    // Jump to user application //
    JumpAddress = *(__IO uint32_t*) (FLASH_APP_ADDR + 4);
    Jump_To_Application = (pFunction) JumpAddress;
    // Initialize user application's Stack Pointer //
    __set_MSP(*(__IO uint32_t*) FLASH_APP_ADDR);
    Jump_To_Application();
  } else {
    printf("No APP found!!!\n");
  }
}


//UART接收中断
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	if(huart->Instance == huart1.Instance) {
		//if(Rx_Line_Flag == 0) {
			/*
			if(Uart1_Rx_Char == '\n') {
				Uart1_Rx_Buffer[Rx_Buffer_Size] = '\0';
				//if(Rx_Buffer_Size >= 5) {
					Rx_Line_Flag = 1;
				//}
				if(Rx_Buffer_Size == 0){
					Rx_Line_Flag = 0;
				}
				Rx_Buffer_Size = 0;
			}else {*/ //不必要有这段
				Uart1_Rx_Buffer[Rx_Buffer_Size] = Uart1_Rx_Char;
				Rx_Buffer_Size++;
			//}

		//}
		HAL_UART_Receive_IT(&huart1,&Uart1_Rx_Char,1);
	}
}

uint8_t Flash_Data_Buffer[1024] = {0};
uint8_t Flash_Data_Frame_Num = 0;
uint32_t Flash_Page_Num = 0;
void Data_Manage(uint8_t Is_Last_Page) {

	if(Is_Last_Page == 0) {
		for(uint8_t i = 0; i < 128; i++) {
			Flash_Data_Buffer[Flash_Data_Frame_Num * 128 + i] = Uart1_Rx_Buffer[3 + i];
		}
		Flash_Data_Frame_Num++;
		if(Flash_Data_Frame_Num == 8) {
			Flash_Write_Page(0x08008000 + Flash_Page_Num * 0x400, Flash_Data_Buffer);

			uint8_t t =  *(uint8_t *)0x080083ff;

			Flash_Page_Num++;
			Flash_Data_Frame_Num = 0;
		}
	} else if(Is_Last_Page == 1) {

		if(Flash_Data_Frame_Num != 0) {
			Flash_Write_Page(0x08008000 + Flash_Page_Num * 0x400, Flash_Data_Buffer);

			uint8_t t =  *(uint8_t *)0x08008131;

		}

	}

}


void Download_App(void) {

	  //printf("C\r\n");
	  printf("C\n");
	 // int i = 0;
	  uint8_t ReceiveFile_End_Flag = 0;
	  uint8_t temp[10] = {0}, i = 0;
	 // uint8_t Last_Buffer_Size = 0;
	  while(1) {

		  if(Rx_Buffer_Size == 133) { //一帧数据接受完成

			  if(Uart1_Rx_Buffer[1] == 0) { //为起始帧
				  printf("%c", 6);//返回ACK
				  printf("C\n");
			  } else {  //每一帧正文数据  在printf前处理

				  Data_Manage(0);

				  printf("%c\n", 6);//返回ACK
				 // printf("C\r\n");
			  }

			  //Rx_Buffer_Size = 0;
			 // printf("%c", 6);
			 // printf("C\r\n");
			//  i++;
			  Rx_Buffer_Size = 0;
		    }


	 	//  if((Rx_Buffer_Size - Last_Buffer_Size) == 1 && Rx_Buffer_Size == 1) { //检查第一位
		  	  if(Rx_Buffer_Size == 1) {
	 		 // temp[i] = Uart1_Rx_Buffer[0];
	 		  //i++;

			  if(Uart1_Rx_Buffer[0] == 4) { //文件传送结束
				  /*
				  if(ReceiveFile_End_Flag == 1) {
					  printf("%c", 6); //返回ACK
					  printf("C\r\n");
					  //ReceiveFile_End_Flag = 1;
					  Rx_Buffer_Size = 0;
				  }
					*/
				  if(ReceiveFile_End_Flag == 0) { //发送方发送的第一个EOT 此处处理收尾

					  Data_Manage(1);


					  return;
					//  while(1);

					//  printf("%c\n", 21); //返回NAK
					  ReceiveFile_End_Flag = 1;
					  Rx_Buffer_Size = 0;
				  }
			  }

		  }

	 	// Last_Buffer_Size = Rx_Buffer_Size;
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
