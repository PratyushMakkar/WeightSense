/*
 * ADCToWeightModule.c
 *
 *  Created on: Nov. 20, 2022
 *      Author: pratyushmakkar
 */

#include "ADCToWeightModule.h"

uint32_t ConvertADCValToMass(uint32_t ADC_VAL) {
	float stretch = _findLengthAlongResistor(ADC_VAL);
	uint32_t mass = (SPRING_CONSTANT*stretch)/GRAVITATIONAL_CONSTANT*1000; //Converting weight to grams
	return mass;
}

float _findLengthAlongResistor(uint32_t ADC_VAL) {
	float stretch =(1 -(ADC_VAL/ADC_RESOLUTION)) * LENGTH_OF_RESISTOR;
	return stretch;
}
