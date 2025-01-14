
#include "inputcap.h"


/*	bit7 捕获完成标识	bit6 捕获到高电平标识	bit5~0 捕获高电平后定时器溢出的次数 */
uint8_t		TIM5CH1_CAPTURE_STA = 0;	// 输入捕获状态
uint32_t	TIM5CH1_CAPTURE_VAL;		// 输入捕获值(TIM2/TIM5是32位的定时器所以这里定义为uint32_t)
uint8_t  DownEdgeFlag = 0;

uint32_t Cycle = 20, Width = 0;

uint32_t Times = 0, Times_Buffer = 0;

// 中断服务函数里面会自动调用这个回调函数  这个是定时器更新中断中处理的函数
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  if (htim->Instance == TIM2)	// 判断是定时器5发生中断
  {
    if ((TIM5CH1_CAPTURE_STA & 0x80) == 0) // 还未成功捕获
    {
     // if (TIM5CH1_CAPTURE_STA & 0x40)		   // 捕获到高电平
      //{
        if ( (TIM5CH1_CAPTURE_STA & 0x3f) == 0x3f )		// 如果高电平太长  做溢出处理
        {
        	Cycle = 0x3f;
        	Cycle *= 0xffff;				// Total Overflow Time(总的溢出时间)
        	TIM5CH1_CAPTURE_STA = 0;
        	DownEdgeFlag = 0;
        	__HAL_TIM_DISABLE(&htim2);
        	__HAL_TIM_ENABLE(&htim2);
          //TIM5CH1_CAPTURE_STA |= 0x80;// 标记成功捕获了一次
          //TIM5CH1_CAPTURE_VAL = 0xffffffff;
        }
        else
        {
          TIM5CH1_CAPTURE_STA++;		// 若没有溢出, 就只让TIM5CH1_CAPTURE_STA自加就ok
        }
      //}
    }
  }

  if(htim->Instance == TIM3) {
	  Motor_Contorl();

	  //Times_Buffer = Times;
	  //Times = 0;
  }
}

// 定时器输入捕获中断处理回调函数，该函数在 HAL_TIM_IRQHandler(TIM_HandleTypeDef *htim) 中会被调用


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
      Width += TIM5CH1_CAPTURE_VAL + 3;    // Get Total High Level Time(获取总的高电平时长)
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
    		Cycle += TIM5CH1_CAPTURE_VAL + 3;    // Get Total High Level Time(获取总的高电平时长)

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
