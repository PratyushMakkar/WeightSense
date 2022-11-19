/*
 * UpdateNumberOntoDisplayTest.h
 *
 *  Created on: Nov. 15, 2022
 *      Author: pratyushmakkar
 */
#include "DisplayRegsiterModule/display_module.h"
#include "FlashMemoryAPI/flash_memory_api.h"
#include <stdbool.h>
#include <stdint.h>

#define TEST_VAL_COUNT 100

#ifndef SRC_TESTSUITE_UPDATENUMBERONTODISPLAYTEST_H_
#define SRC_TESTSUITE_UPDATENUMBERONTODISPLAYTEST_H_


#endif /* SRC_TESTSUITE_UPDATENUMBERONTODISPLAYTEST_H_ */

uint32_t UpdateNumberOntoDisplayTest();
uint32_t DigitalFilterForResistor(ADC_HandleTypeDef* hadc1, uint32_t* ADCArray);
uint8_t PersistDataInFlash();
