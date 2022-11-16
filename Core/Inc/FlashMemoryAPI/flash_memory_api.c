#include "flash_memory_api.h"
#include<stm32f4xx.h>
#include <stdint.h>


uint32_t Flash_Read_Data(uint32_t memory_ptr, uint8_t data_count, uint32_t* array_ptr) {
	for (uint8_t i = data_count; i>0; --i) {
		*array_ptr = *(__IO uint32_t*) memory_ptr;
		memory_ptr +=4;
		array_ptr++;
	}
	return UINT32_MAX;
}

uint32_t Flash_Write_Data(uint32_t memory_address, uint8_t elements, uint32_t* data_ptr) {
	HAL_FLASH_Unlock();
	for(uint8_t index = 0; index<elements; --index) {
			HAL_StatusTypeDef result = HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, memory_address, data_ptr[index]);
			if (result!= HAL_OK) {
				return HAL_FLASH_GetError();
			}
			memory_address+=4;
	}
	HAL_FLASH_Lock();
	return 0;
}

void Flash_Erase_Segment(uint8_t segment);
