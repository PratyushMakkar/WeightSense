/*
 * display_module.c
 *
 *  Created on: Nov 14, 2022
 *      Author: pratyushmakkar
 */

#include "main.h"
#include <stdint.h>
#include "DisplayRegsiterModule/display_module.h"


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

void sendSPIData(uint8_t data[], uint16_t byteSize, SPI_HandleTypeDef* hspi1) {
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_SET);

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);

	HAL_SPI_Transmit(hspi1, &data[0], byteSize, 10);

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_SET);

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_RESET);

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_RESET);


}

void DisplayInteger(uint16_t display, SPI_HandleTypeDef* hspi1 ) {
	uint8_t digitArray[3] = {};
	_ConvertIntToChar(display, digitArray);
	for (uint8_t i =0; i<4; ++i) {
		if (i ==0) {
			uint8_t digit = digitArray[0];
			digit |= (0b1<<7);
			digitArray[0] = digit;
		}
		sendSPIData(&digitArray[i], 1, hspi1);
		HAL_Delay(1000);
	}

}

void DisplayIntegerWithDelay(uint16_t display, SPI_HandleTypeDef* hspi1, uint32_t delay) {
	uint8_t digitArray[4] = {};
	_ConvertIntToChar(display, digitArray);
	for (uint8_t i =0; i<3; ++i) {
		if (i ==0) {
			uint8_t digit = digitArray[0];
			digit |= (0b1<<7);
			digitArray[0] = digit;
		}
		sendSPIData(&digitArray[i], 1, hspi1);
		HAL_Delay(delay);
	}

}


uint8_t DigitToMacro(uint16_t digit) {
	if (digit==0) {
		return _ZERO;
	}
	if (digit==1) {
		return _ONE;
	}
	if (digit==2) {
		return _TWO;
	}
	if (digit==3) {
		return _THREE;
	}
	if (digit==4) {
		return _FOUR;
	}
	if (digit==5) {
		return _FIVE;
	}
	if (digit==6) {
		return _SIX;
	}
	if (digit==7) {
		return _SEVEN;
	}
	if (digit==8) {
		return _EIGHT;
	}
	if (digit==9) {
		return  _NINE;
	}
	return _ZERO;
}

void _ConvertIntToChar(uint16_t display, uint8_t* digitArray) {
	//We operate under the assumption that the integer is three digits

	uint16_t _digit = display%100;
	_digit = display-_digit;
	digitArray[0] = DigitToMacro(_digit/100);
	display = display - (_digit);

	 _digit = display%10;
	_digit = display-_digit;
	digitArray[1] = DigitToMacro(_digit/10);
	display = display - (_digit);

	digitArray[2] = DigitToMacro(display);
	digitArray[3] = _ZERO;

}

void _pushCharToRegister(char rep);
