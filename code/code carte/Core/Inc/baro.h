/*
 * baro.h
 *
 *  Created on: Mar 12, 2026
 *      Author: garci
 */

#ifndef BARO_H
#define BARO_H

#include "stdbool.h"
#include "stdint.h"
#include <stm32l4xx_hal.h>


extern I2C_HandleTypeDef hi2c1;

typedef enum
{
    BARO_OK = 0,
    BARO_ERROR,
    BARO_TIMEOUT,
    BARO_NOT_FOUND

} BARO_Status_t;

#define BMP580_HI2C hi2c1

#define BMP580_I2C_ADDRESS 0x8C
//#define BMP580_I2C_ADDRESS (0x8C >> 1)

#define ODR_CONFIG 0x37

#define OSR_CONFIG 0x36

#define CHIP_ID 0x01

#define DSP_IIR 0x31

#define INT_STATUS 0x27

BARO_Status_t BARO_Init();

bool IsDataReady();

float * ReadPressureTemp();

void calibrage();

float altitute(float P);

#endif //BARO_H
