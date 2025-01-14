#include "AdcDma.h"

uint32_t ADC_Value[Sample_Num][Channel_Num];
uint8_t Dma_DataDeal_Flag = 0;
float ADC_Value_Buffer[Sample_Num][Channel_Num];
float ADC_ValueAverage[Channel_Num];

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc) {

	if(Dma_DataDeal_Flag == 0) {
		//Dma_DataDeal_Flag = 0;

		for(int x = 0; x < Sample_Num; x++) {
			for(int y = 0; y < Channel_Num; y++) {
				ADC_Value_Buffer[x][y] = (float)ADC_Value[x][y] / 4096 * 3.3;
			}
		}

		Dma_DataDeal_Flag = 1;
	}
}

void Update_Data(void) {
	//while(1) {
		if(Dma_DataDeal_Flag == 1) {
			//Dma_DataDeal_Flag  = 0;
			Data_Fliter();
			Dma_DataDeal_Flag = 0;
			//break;
		}
	//}
}

void Data_Fliter(void) {
	for(int l=0; l<Channel_Num; l++) {
		for(int i=0; i<Sample_Num-1; i++) { // 冒泡排序
			for(int j=0; j<Sample_Num-i; j++) {
				if(ADC_Value_Buffer[j][l] > ADC_Value_Buffer[j+1][l]) {
					float tmp = ADC_Value_Buffer[j][l];
					ADC_Value_Buffer[j][l] = ADC_Value_Buffer[j+1][l];
					ADC_Value_Buffer[j+1][l] = tmp;
				}
		  	}
		}
	}
//然后取排序后中间部分的值求和平均滤波
	for(int l=0; l<Channel_Num; l++) {
		float Sum = 0;
		for(int i=Sample_Num/2-25; i<Sample_Num/2+25; i++) {	//取中间值算平均值
			Sum += ADC_Value_Buffer[i][l];
		}
		ADC_ValueAverage[l] = Sum/50;
	}
}

