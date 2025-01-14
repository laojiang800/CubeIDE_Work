#include "pid.h"

#define OUTMAX   1000
#define OUTMIN   -1000
#define ITERM_MAX  200
#define ITERM_MIN -200

typedef unsigned short int   uint16_t;

/*************************************************************************/
/*                       Output = kp*error + Iterm - kd*dInput           */
/*                       Iterm += ki*error;  dInput = Input - lastInput  */
/*************************************************************************/
float kp,ki,kd;
float Iterm = 0;
float lastInput = 0;
float temp,dInput;
float error[20];


float PID_Calc(float Input,float setpoint)
{


	float Pid_Out = 0;
	static float Bias,Last_bias;
	Bias=setpoint-Input;                                  //计算偏差
	Pid_Out=kp*(Bias-Last_bias)+ki*Bias;   //增量式PI控制器
	Last_bias=Bias;	                                     //保存上一次偏差
	return Pid_Out;                                           //增量输出
	/*
	static uint16_t left = 0;
	static uint16_t right = 0;
	static uint16_t flag = 0;
	
	error[right] = setpoint - Input;
	dInput = Input - lastInput;
	Iterm += ki*error[right];
	if(Iterm > ITERM_MAX)  Iterm = ITERM_MAX;
	else if(Iterm < ITERM_MIN)  Iterm = ITERM_MIN;

	temp = kp*error[right] + Iterm - kd*dInput;
	if(temp > OUTMAX)  temp = OUTMAX;
	else if(temp < OUTMIN)  temp = OUTMIN;
	lastInput = Input;
	
	right++;
	if(right >= 20)
	{
		flag = 1;
		right = 0;
	}
	if(flag)
	{
		Iterm -= ki*error[left++];
		if(left >= 20)
			left = 0;
	}
	
	return temp;
	*/
}

void Set_PID_Parameter(float KP,float KI,float KD)
{
    kp = KP;
    ki = KI;
    kd = KD;
}


float kp1,ki1,kd1;
float Iterm1 = 0;
float lastInput1 = 0;
float temp1,dInput1;
float error1[20];


float PID_Calc1(float Input,float setpoint)
{
	static uint16_t left1 = 0;
	static uint16_t right1 = 0;
	static uint16_t flag1 = 0;

	error1[right1] = setpoint - Input;
	dInput1 = Input - lastInput1;
	Iterm1 += ki1*error1[right1];
	if(Iterm1 > ITERM_MAX)  Iterm1 = ITERM_MAX;
	else if(Iterm1 < ITERM_MIN)  Iterm1 = ITERM_MIN;

	temp1 = kp1*error1[right1] + Iterm1 - kd1*dInput1;
	if(temp1 > OUTMAX)  temp1 = OUTMAX;
	else if(temp1 < OUTMIN)  temp1 = OUTMIN;
	lastInput1 = Input;

	right1++;
	if(right1 >= 20)
	{
		flag1 = 1;
		right1 = 0;
	}
	if(flag1)
	{
		Iterm1 -= ki1*error1[left1++];
		if(left1 >= 20)
			left1 = 0;
	}

	return temp1;
}

void Set_PID_Parameter1(float KP,float KI,float KD)
{
    kp1 = KP;
    ki1 = KI;
    kd1 = KD;
}
