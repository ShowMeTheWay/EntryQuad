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


/* USER CODE BEGIN  */

void EnableDisablePin(unsigned int pinV)
{
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, pinV);

}

extern TIM_HandleTypeDef htim4;

void user_pwm_setvalue(unsigned short int  value)
{
    TIM_OC_InitTypeDef sConfigOC;

    sConfigOC.OCMode = TIM_OCMODE_PWM1;
    sConfigOC.Pulse = value;
    sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
    sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
    HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_2);
}
/* USER CODE END  */


