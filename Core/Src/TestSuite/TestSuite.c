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
		DisplayInteger(index);
	}

	uint32_t tickend = HAL_GetTick();
	return (tickend - tickstart);
}

//Uses the HAL ADC to create a digital filter that reads the value each 5 ms
//and checks at which point the reistor is within 10% range of final.
uint32_t DigitalFilterForResistor() {
	return UINT32_MAX;
}

uint8_t PersistDataInFlash() {
	return 0;
}
