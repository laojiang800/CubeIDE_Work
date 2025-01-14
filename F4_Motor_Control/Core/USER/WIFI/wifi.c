#include "wifi.h"

uint8_t Uart1_Rx_Char;		// 用来接收串口1收到的的数据
uint8_t Uart1_Rx_Buffer[100] = {0};
uint8_t Wifi_Command_Buffer[100] = {0};
uint8_t Rx_Buffer_Size = 0;
uint8_t Rx_Line_Flag = 0;
uint8_t Wifi_Get_Command_Flag = 0;



void Server_Init(void) {
	HAL_Delay(50);
	printf("AT+RST\r\n");
	HAL_Delay(300);
	printf("AT+CWMODE=2\r\n");
	HAL_Delay(100);
	printf("AT+CWSAP=\"ESP8266_HHHH\",\"12345678\",3,4\r\n");

	HAL_Delay(100);
	printf("AT+RST\r\n");
	HAL_Delay(300);
	printf("AT+CWMODE=2\r\n");
	HAL_Delay(100);
	printf("AT+CIPMUX=1\r\n");
	HAL_Delay(100);
	printf("AT+CIPSERVER=1,8080\r\n");
	HAL_Delay(100);
	printf("AT+CIPSTO=0\r\n");
	HAL_Delay(100);
}

void Server_SentTo_Client(uint8_t *Str) {
	HAL_Delay(50);
	printf("AT+CIPSEND=0,%d\r\n", Strlen(Str) + 2);
	HAL_Delay(50);
	printf("%s\r\n", Str);
	HAL_Delay(50);
}

 uint8_t Strlen(uint8_t *s) {
	 for(uint8_t i = 0; i < 256; i++) {
		 if(s[i] == '\0') {
			 return i;
		 }
	 }
 }
 void Strcpy(uint8_t *s1, uint8_t *s2) {
	 uint8_t i;
	 for(i = 0; s2[i] != '\0'; i++) {
		 s1[i] = s2[i];
	 }
	 s1[i] = '\0';
 }
uint8_t Strcmp(uint8_t *s1, uint8_t *s2) {
	uint8_t i;
		 for(i = 0; s2[i] != '\0'; i++) {
			 if(s1[i] != s2[i]) {
				 return 0;
			 }
		 }
		 if(s1[i] == '\0') {
			 return 1;
		 }
		 return 0;
}

//UART接收中断
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	if(huart->Instance == huart1.Instance) {
		if(Rx_Line_Flag == 0) {
			if(Uart1_Rx_Char == '\n') {
				Uart1_Rx_Buffer[Rx_Buffer_Size] = '\0';
				//if(Rx_Buffer_Size >= 5) {
					Rx_Line_Flag = 1;
				//}

				if(Rx_Buffer_Size == 1) {
					Rx_Line_Flag = 0;
				}

				if(Rx_Buffer_Size == 0){
					Rx_Line_Flag = 0;
				}
				Rx_Buffer_Size = 0;
			}else {
				Uart1_Rx_Buffer[Rx_Buffer_Size] = Uart1_Rx_Char;
				Rx_Buffer_Size++;
			}
		}
		HAL_UART_Receive_IT(&huart1,&Uart1_Rx_Char,1);
	}
}

void Tcp_DataAccept(void) {

	if(Wifi_Get_Command_Flag == 1) {
			Tcp_DataDeal();
			Wifi_Get_Command_Flag = 0;
		  }
		  if(Rx_Line_Flag == 1) {
			  if(Wifi_Get_Command_Flag == 0) {
				  //Server_SentTo_Client(Uart1_Rx_Buffer);
				  Wifi_Command_Buffer[0] = Uart1_Rx_Buffer[0];
		  		  Wifi_Command_Buffer[1] = Uart1_Rx_Buffer[1];
		  		  Wifi_Command_Buffer[2] = Uart1_Rx_Buffer[2];
		  		  Wifi_Command_Buffer[3] = Uart1_Rx_Buffer[3];
		  		  Wifi_Command_Buffer[4] = '\0';
		  		  if(Strcmp(Wifi_Command_Buffer, "+IPD") == 1) {
		  			  //Strcpy(Wifi_Command_Buffer, Uart1_Rx_Buffer);
		  			  Wifi_Get_Command_Flag = 1;
		  			  for(uint8_t i = 0; ; i++) {
		  				  if(Uart1_Rx_Buffer[i] == ':') {
		  					  Strcpy(Wifi_Command_Buffer, Uart1_Rx_Buffer + i + 1);
		  					  break;
		  				  }
		  			  }
		  		  }
			  }
			  Rx_Line_Flag = 0;
		  }
}

__weak void Tcp_DataDeal(void) {

	 /*收到数据会调用此函数，在此写业务代码 Wifi_Command_Buffer中为收到的数据*/
			  		  //此时Wifi_Command_Buffer的尾部为\r\0   指令匹配时需要注意
	//weak修饰 在main中重写
		//do nothing

}

void IntToStr(uint32_t num, uint8_t *s) {
	uint32_t TempNum = num;

	if(num == 0) {
		s[0] = '0';
		return;
	}

	for(uint8_t i = 0; ; i++) {
		if(TempNum == 0) {
			for(uint8_t j = 0; j < i / 2; j++) {
				uint8_t temp = s[j];
				s[j] = s[i - j - 1];
				s[i - j - 1] = temp;
			}
			s[i] = 0;
			break;
		}
		s[i] = '0' + TempNum % 10;
		TempNum /= 10;
	}

}
