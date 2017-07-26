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
	}
	else
	{
		/*do nothing yet..to send 0 data over uart */
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


