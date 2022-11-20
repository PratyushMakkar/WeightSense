/*
 * ADCToWeightModule.h
 *
 *  Created on: Nov. 20, 2022
 *      Author: pratyushmakkar
 */
#include <stdint.h>

#ifndef INC_ADCTOWEIGHTMODULE_ADCTOWEIGHTMODULE_H_
#define INC_ADCTOWEIGHTMODULE_ADCTOWEIGHTMODULE_H_

#endif /* INC_ADCTOWEIGHTMODULE_ADCTOWEIGHTMODULE_H_ */

#define SPRING_CONSTANT 40
#define GRAVITATIONAL_CONSTANT 9.81f
#define LENGTH_OF_RESISTOR 0.15f
#define ADC_RESOLUTION 4095.0f
#define MIN_ADC 65

uint32_t ConvertADCValToMass(uint32_t ADC_VAL);
float _findLengthAlongResistor(uint32_t ADC_VAL);

