
/*
 * flash_memory_api.h
 *
 *  Created on: Nov 3, 2022
 *      Author: pmakkar
 */
#include <stdint.h>




#ifndef SRC_FLASHMEMORYAPI_FLASH_MEMORY_API_H_
#define SRC_FLASHMEMORYAPI_FLASH_MEMORY_API_H_

#endif /* SRC_FLASHMEMORYAPI_FLASH_MEMORY_API_H_ */

uint32_t Flash_Write_Data(uint32_t memory_address, uint8_t elements, uint32_t* data_ptr);
uint32_t Flash_Read_Data(uint32_t memory_ptr, uint8_t data_count, uint32_t* array_ptr);
void Flash_Erase_Segment(uint8_t segment);
