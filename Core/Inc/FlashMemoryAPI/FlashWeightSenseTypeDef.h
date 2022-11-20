/*
 * FlashWeightSenseTypeDef.h
 *
 *  Created on: Nov. 20, 2022
 *      Author: pratyushmakkar
 */
#include <stdint.h>
#include "flash_memory_api.h"

#ifndef INC_FLASHMEMORYAPI_FLASHWEIGHTSENSETYPEDEF_H_
#define INC_FLASHMEMORYAPI_FLASHWEIGHTSENSETYPEDEF_H_

typedef struct FlashWeightSenseTypeDef {
	uint16_t date;       //Represented as date/month/year   0b01022004 is February 1st 2004
	uint16_t weight;
	uint32_t next_ptr;
} FlashWeightSenseTypeDef ;


uint32_t SaveWeightSenseWithinMemory(uint16_t week, uint16_t year, uint16_t weight,  uint32_t flashAddress);
uint32_t _InsertWeightSenseIntoFlash(FlashWeightSenseTypeDef* object_ptr, uint32_t flashAddress);
uint32_t FindTotalPlasticWaste(FlashWeightSenseTypeDef* object_ptr);
FlashWeightSenseTypeDef RetrieveObjectFromAddress(uint32_t address);

#endif /* INC_FLASHMEMORYAPI_FLASHWEIGHTSENSETYPEDEF_H_ */
