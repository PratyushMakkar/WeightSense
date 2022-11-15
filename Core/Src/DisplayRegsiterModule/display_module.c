/*
 * display_module.c
 *
 *  Created on: Nov 14, 2022
 *      Author: pratyushmakkar
 */

#include "main.h"
#include <stdint.h>

void sendSPIData(uint8_t data[], uint16_t byteSize) {
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_SET);

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);

	HAL_SPI_Transmit(&hspi1, &data[0], byteSize, 10);

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_SET);

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_RESET);

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_RESET);

}

void DisplayInteger(uint8_t display);
void _ConvertIntToChar(uint8_t display);
void _pushCharToRegister(char rep);
