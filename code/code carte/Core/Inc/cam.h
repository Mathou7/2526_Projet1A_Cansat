#ifndef __Cam_H
#define __Cam_H

#include "stm32g431kbt_hal.h"

#define VC_PROTOCOL_SIGN        0x56
#define VC_PROTOCOL_RESP        0x76
#define VC_CMD_FBUF_CTRL        0x36
#define VC_CMD_GET_FBUF_LEN     0x34
#define VC_CMD_READ_FBUF        0x32

#define PARAM_STOP_CURRENT      0x00
#define PARAM_RESUME_FRAME      0x02
#define PARAM_FBUF_CURRENT      0x00
#define CTRL_MODE_UART          0x0A

void Camera_Reset(UART_HandleTypeDef *huart);
void Camera_StopCurrentFrame(UART_HandleTypeDef *huart);
uint32_t Camera_GetImageLength(UART_HandleTypeDef *huart);
void Camera_ReadImageData(UART_HandleTypeDef *huart, uint32_t imageLen, uint8_t *buffer);
void Camera_ResumeFrame(UART_HandleTypeDef *huart);

#endif
