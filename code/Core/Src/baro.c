/*
 * baro.c
 *
 *  Created on: Mar 26, 2026
 *      Author: garci
 */


#include “baro.h”

#define BARO_NOT_READY



BARO_Status_t BARO_Init(){

MX_I2C_Init();

if(HAL_I2C_IsDeviceReady() != HAL_OK OR ){

return BARO_NOT_READY ;

}

Else{

Return BARO_OK

}

}
