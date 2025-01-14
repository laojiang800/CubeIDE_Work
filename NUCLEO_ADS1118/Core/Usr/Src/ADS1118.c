#include "ADS1118.h"

uint8_t ADS1118_Config[2] = {0}; //config register
uint8_t ADS1118_Data[2] = {0}; //data register
float ADS1118_RangeValue[6] = {6.144, 4.096, 2.048, 1.024, 0.512, 0.256};

int ADS1118_GetData(void) {
	int AdsOverTime = 0;
	//update config
	HAL_GPIO_WritePin(SPI2_CS_GPIO_Port, SPI2_CS_Pin, GPIO_PIN_RESET);
	while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_14) == GPIO_PIN_SET && AdsOverTime < 50000) AdsOverTime++;
	HAL_SPI_TransmitReceive(&hspi2, ADS1118_Config, ADS1118_Data, 2, 0xff);
	HAL_SPI_TransmitReceive(&hspi2, ADS1118_Config, ADS1118_Data, 2, 0xff);
	HAL_GPIO_WritePin(SPI2_CS_GPIO_Port, SPI2_CS_Pin, GPIO_PIN_SET);
	HAL_Delay(1);
	//get new data
	AdsOverTime = 0;
	HAL_GPIO_WritePin(SPI2_CS_GPIO_Port, SPI2_CS_Pin, GPIO_PIN_RESET);
	while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_14) == GPIO_PIN_SET && AdsOverTime < 50000) AdsOverTime++;
	HAL_SPI_TransmitReceive(&hspi2, ADS1118_Config, ADS1118_Data, 2, 0xff);
	HAL_GPIO_WritePin(SPI2_CS_GPIO_Port, SPI2_CS_Pin, GPIO_PIN_SET);
	//data deal
	int Value = ((int)ADS1118_Data[0] << 8) + ADS1118_Data[1];
	if(Value >= 0x8000) {
		Value = Value - 0x10000;//to signed num
	   }
	return Value;
}

float ADS1118_GetVoltage(uint8_t mode, uint8_t range, uint8_t speed) {
	//config update
	ADS1118_Config[0] = (((((SS << 3) + mode) << 3) + range) << 1) + MODE;
	ADS1118_Config[1] = (((((((speed << 1) + TS_MODE) << 1) + PULLUP_EN) << 2) + NOP) << 1) + 0;

	//getdate and return voltage value
	int ADS1118_VoltageNum = ADS1118_GetData();
	return ADS1118_RangeValue[range] * ADS1118_VoltageNum / 32768;

}














