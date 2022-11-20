/*
 * UpdateNumberOntoDisplayTest.c
 *
 *  Created on: Nov. 15, 2022
 *      Author: pratyushmakkar
 */
#include "Test_Suite.h"
#include <stdint.h>
#include <main.h>


uint32_t UpdateNumberOntoDisplayTest( SPI_HandleTypeDef* hspi1_ptr) {
	uint32_t tickstart = HAL_GetTick();

	for (uint16_t index = 1; index< TEST_VAL_COUNT; ++index) {
		DisplayIntegerWithDelay(index, hspi1_ptr, 100);
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

	Flash_Erase_Segment(FLASH_SECTOR);

	uint32_t address = SaveWeightSenseWithinMemory(22, 07, 450, PAGE_ADDRESS);
	uint32_t address2 = SaveWeightSenseWithinMemory(15, 12, 115, address);

	FlashWeightSenseTypeDef weightSense = RetrieveObjectFromAddress(PAGE_ADDRESS);
	FlashWeightSenseTypeDef weightSense2 = RetrieveObjectFromAddress(address);

	uint16_t weight = weightSense.weight;
	uint16_t weight2 = weightSense2.weight;

	Flash_Erase_Segment(FLASH_SECTOR);
}
