/*
 * display_module.c
 *
 *  Created on: Nov 14, 2022
 *      Author: pratyushmakkar
 */

#include "main.h"
#include <stdint.h>

uint32_t GetADCValue(ADC_HandleTypeDef hadc1) {
	HAL_ADC_Start(&hadc1);

	HAL_ADC_PollForConversion(&hadc1, 100);

	uint32_t adc_val;

	adc_val = HAL_ADC_GetValue(&hadc1);

	HAL_ADC_Stop(&hadc1);

	HAL_Delay (500);
}

void UpdateADCValuesIntoFilter(ADC_HandleTypeDef* hadc1, uint16_t* ADCArray) {
	HAL_ADC_Start(&hadc1);

	uint16_t adc_val;

	for (uint8_t i = 0; i<100; ++i) {
		HAL_ADC_PollForConversion(&hadc1, 100);
		adc_val = HAL_ADC_GetValue(&hadc1);
		ADCArray[i] = adc_val;
		HAL_Delay(100);
	}

	HAL_ADC_Stop(&hadc1);

}

void sendSPIData(uint8_t data[], uint16_t byteSize, SPI_HandleTypeDef hspi1) {
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_SET);

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);

	HAL_SPI_Transmit(&hspi1, &data[0], byteSize, 10);

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_SET);

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_RESET);

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_RESET);

}

void DisplayInteger(uint16_t display);
void _ConvertIntToChar(uint8_t display);
void _pushCharToRegister(char rep);
