/*
 * display_module.h
 *
 *  Created on: Nov 14, 2022
 *      Author: pratyushmakkar
 */

#include <stdint.h>
#include <main.h>
#ifndef SRC_DISPLAYREGSITERMODULE_DISPLAY_MODULE_H_
#define SRC_DISPLAYREGSITERMODULE_DISPLAY_MODULE_H_

#define _ZERO 0x7D
#define _ONE 0x11
#define _TWO 0x3E
#define _THREE 0x37
#define _FOUR 0x53
#define _FIVE 0x67
#define _SIX 0xEF
#define _SEVEN  0x31
#define _EIGHT 0xFF
#define _NINE 0x73

#endif /* SRC_DISPLAYREGSITERMODULE_DISPLAY_MODULE_H_ */

void UpdateADCValuesIntoFilter(ADC_HandleTypeDef* hadc1, uint16_t* ADCArray);
uint8_t DigitToMacro(uint16_t digit);
void sendSPIData(uint8_t data[], uint16_t byteSize, SPI_HandleTypeDef* hspi1);
void DisplayInteger(uint16_t display, SPI_HandleTypeDef* hspi1 );
void _ConvertIntToChar(uint16_t display, uint8_t* digitArray);
void _pushCharToRegister(char rep);
