/*
 * UpdateNumberOntoDisplayTest.c
 *
 *  Created on: Nov. 15, 2022
 *      Author: pratyushmakkar
 */
#include "Test_Suite.h"
#include <stdint.h>
#include <main.h>

uint32_t UpdateNumberOntoDisplay() {
	uint32_t tickstart = HAL_GetTick();

	for (uint16_t index = 1; index<1000; ++index) {
		//DisplayInteger(index);
	}

	uint32_t tickend = HAL_GetTick();
	return (tickend - tickstart);
}

//Uses the HAL ADC to create a digital filter that reads the value each 5 ms
//and checks at which point the reistor is within 10% range of final.
uint32_t DigitalFilterForResistor(ADC_HandleTypeDef* hadc1, uint32_t* ADCArray ) {
	uint32_t tickstart = HAL_GetTick();

	HAL_ADC_Start(hadc1);

	uint16_t adc_val;

	for (uint8_t i = 0; i<100; ++i) {
			HAL_ADC_PollForConversion(hadc1, 100);
			adc_val = HAL_ADC_GetValue(hadc1);
			ADCArray[i] = adc_val;
			HAL_Delay(100);
	}

		HAL_ADC_Stop(hadc1);


	uint32_t tickend = HAL_GetTick();
	return (tickend-tickstart);
}

uint8_t PersistDataInFlash() {
	return 0;
}
