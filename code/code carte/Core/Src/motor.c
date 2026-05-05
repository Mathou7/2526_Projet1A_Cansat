/*
 * motor.c
 *
 *  Created on: Apr 16, 2026
 *      Author: garci
 */


#include "motor.h";

void ParachuteTrigger(){
	HAL_GPIO_WritePin(GPIO,GPIO_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIO,GPIO_Pin,GPIO_PIN_RESET);
	HAL_Delay(1000);
	HAL_GPIO_WritePin(GPIO,GPIO_Pin,GPIO_PIN_RESET);

}
