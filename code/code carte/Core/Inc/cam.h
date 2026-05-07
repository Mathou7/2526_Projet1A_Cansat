#include "Cam.h"

void Init(UART_HandleTypeDef *huart) {
   VC0706_Reset(huart);
   HAL_Delay(500)
   uint8_t check_resp[5];
   if (HAL_UART_Receive(huart, check_resp, 5, 1000) != HAL_OK) {
        return 0;
   }
}

void Camera_StopCurrentFrame(UART_HandleTypeDef *huart) {
    uint8_t cmd[] = {VC_PROTOCOL_SIGN, 0x00, VC_CMD_FBUF_CTRL, 0x01, PARAM_STOP_CURRENT};
    uint8_t resp[5];

    HAL_UART_Transmit(huart, cmd, sizeof(cmd), 100);
    HAL_UART_Receive(huart, resp, 5, 100);
}

uint32_t Camera_GetImageLength(UART_HandleTypeDef *huart) {
    uint8_t cmd[] = {VC_PROTOCOL_SIGN, 0x00, VC_CMD_GET_FBUF_LEN, 0x01, PARAM_FBUF_CURRENT};
    uint8_t resp[9];

    HAL_UART_Transmit(huart, cmd, sizeof(cmd), 100);
    if (HAL_UART_Receive(huart, resp, 9, 200) == HAL_OK) {
        return ((uint32_t)resp[5] << 24) | ((uint32_t)resp[6] << 16) |
               ((uint32_t)resp[7] << 8) | (uint32_t)resp[8];
    }
    return 0;
}

void Camera_ReadImageData(UART_HandleTypeDef *huart, uint32_t imageLen, uint8_t *buffer) {
    uint8_t header[5];
    uint8_t footer[5];
    uint8_t cmd[] = {
        VC_PROTOCOL_SIGN, 0x00, VC_CMD_READ_FBUF, 0x0C, 0x00,0x0A,
        0x00, 0x00, 0x00, 0x00,
        (uint8_t)(imageLen >> 24), (uint8_t)(imageLen >> 16),
        (uint8_t)(imageLen >> 8), (uint8_t)imageLen, 0x0B, 0xB8
    }

    HAL_UART_Transmit(huart, cmd, sizeof(cmd), 100);


    HAL_UART_Receive(huart, header, 5, 100);
    HAL_UART_Receive(huart, buffer, imageLen, 5000);
    HAL_UART_Receive(huart, footer, 5, 100);
}

void Camera_ResumeFrame(UART_HandleTypeDef *huart) {
    uint8_t cmd[] = {VC_PROTOCOL_SIGN, 0x00, VC_CMD_FBUF_CTRL, 0x01, PARAM_RESUME_FRAME};
    uint8_t resp[5];

    HAL_UART_Transmit(huart, cmd, sizeof(cmd), 100);
    HAL_UART_Receive(huart, resp, 5, 100);
}

void Camera_Reset(UART_HandleTypeDef *huart) {
    uint8_t cmd[] = {VC_PROTOCOL_SIGN, 0x00, 0x26, 0x00};
    HAL_UART_Transmit(huart, cmd, sizeof(cmd), 100);
    HAL_Delay(500);
}
#endif 
