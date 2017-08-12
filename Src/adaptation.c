/*
 * adaptation.c
 *
 *  Created on: Feb 22, 2017
 *      Author: Beny
 */


#include "stm32f4xx_hal.h"
#include "adaptation.h"
#include "main.h"
#include "cmsis_os.h"
#include "math.h"
#include "stdlib.h"

/* USER CODE BEGIN  */

UART_HandleTypeDef huart5;

void EnableDisablePin(unsigned int pinV)
{
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, pinV);

}

//extern TIM_HandleTypeDef htim4;
UART_HandleTypeDef huart5;
void user_pwm_setvalue(uint16_t value,TIM_HandleTypeDef htimX,uint32_t channel )
{
    TIM_OC_InitTypeDef sConfigOC;

    sConfigOC.OCMode = TIM_OCMODE_PWM1;
    sConfigOC.Pulse = value;
    sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
    sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
    HAL_TIM_PWM_ConfigChannel(&htimX, &sConfigOC, channel);
    HAL_TIM_PWM_Start(&htimX, channel);
}

void ControllerSendCommand(char buff[4])
{
	HAL_UART_Transmit(&huart5, (uint8_t *)&buff, 4, 0xFFFF);
}

char * ControllerReceiveFeedback(void)
{
	//int i;
	static char buff1[12];
	HAL_UART_Receive(&huart5,(uint8_t *)&buff1,12,0xFFFF);


return buff1;

}
/* USER CODE END  */

UART_Data_Transmit(uint16_t data_in)
{
	int idx;
	uint16_t dataLen=0;
	int data_in_= data_in;
	int cnt=0;

	if(data_in != 0)
	{
		while(data_in_)
		{
			data_in_ = data_in_/10;
			cnt++;
		}
		dataLen = cnt;
		char data_out[dataLen];
		for(idx=dataLen-1; idx >=0  ; idx--)
		{
			data_out[idx]=(data_in % 10)+48;
			data_in = data_in/10;
		}
		data_out[dataLen]=(char)'\n';

		HAL_UART_Transmit(&huart5, (uint8_t *)data_out, dataLen+1, 0xFFFF);
	}
	else
	{
		char data_z[2] = "0\n";
		HAL_UART_Transmit(&huart5, (uint8_t *)data_z, 2, 0xFFFF);
	}


}

UART_Transmit_Data(float data_in)
{
	char newL[2] = "\r\n";
	int data_in_=0;
	uint8_t buffLeng=0;
	uint8_t cnt=0;
	static float isInteger;

	/*check how many digits of the integer part of the float number are*/
	data_in_ = (int)data_in;
	while(data_in_ != 0)
	{
		data_in_ = data_in_/10;
		cnt++;
	}

	isInteger = data_in - (long)(data_in);
	/*check if input data is negative*/
	if(data_in < (float)0.0)
	{
		if(cnt == 0)
		{
			buffLeng = cnt+5;  // add 4 more digits 1-sign;1-for ".";2-digits for fractional part;1-because is a special case ex:0.123
		}else
		{
			buffLeng = cnt+4; // add 4 more digits 1-sign;1-for ".";2-digits for fractional part;
		}

		if(isInteger == 0)
		{
			buffLeng = cnt + 1;
		}

	}
	else if(data_in > (float)0.0)
	{
		if(cnt == 0)
		{
			buffLeng = cnt+4; // add 4 more digits 1-for ".";2-digits for fractional part;1-because is a special case ex:0.123
		}else
		{
			buffLeng = cnt+3; // add 3 more digits 1-for ".";2-digits for fractional part
		}

		if(isInteger == 0)
		{
			buffLeng = cnt + 1;
		}

	}
	else
	{
		buffLeng = 1; // add 1 position for sending 0
	}
	char buff[buffLeng]; // define the buffer to be send via UART
	gcvt(data_in,10,buff); // convert the float number in ASCII characters



	HAL_UART_Transmit(&huart5, (uint8_t *)buff,buffLeng, 0xFFFF); // transmit the data
	//HAL_UART_Transmit(&huart5, (uint8_t *)newL, 2, 0xFFFF); // transmit the newL character
}


