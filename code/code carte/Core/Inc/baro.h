/*
 * baro.h
 *
 *  Created on: Mar 12, 2026
 *      Author: garci
 */

#ifndef BARO_H
#define BARO_H

#define BMP580_HI2C hi2c1

#define BMP580_I2C_ADDRESS 0x8C
//#define BMP580_I2C_ADDRESS (0x8C >> 1)

#define ODR_CONFIG 0x37

#define CHIP_ID 0x01

#define DSP_IIR 0x31

#define INT_STATUS 0x27

BARO_Status_t BARO_Init();

bool IsDataReady();

float ReadPressureTemp();

void calibrage();

float altitute(P);

#endif //BARO_H
