/*
 * display_module.h
 *
 *  Created on: Nov 14, 2022
 *      Author: pratyushmakkar
 */

#include<stdint.h>

#ifndef SRC_DISPLAYREGSITERMODULE_DISPLAY_MODULE_H_
#define SRC_DISPLAYREGSITERMODULE_DISPLAY_MODULE_H_



#endif /* SRC_DISPLAYREGSITERMODULE_DISPLAY_MODULE_H_ */

void sendSPIData(uint8_t data[], uint16_t byteSize);
void DisplayInteger(uint16_t display);
void _ConvertIntToChar(uint8_t display);
void _pushCharToRegister(char rep);
