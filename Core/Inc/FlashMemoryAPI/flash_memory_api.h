
/*
 * flash_memory_api.h
 *
 *  Created on: Nov 3, 2022
 *      Author: pmakkar
 */
#include <stdint.h>
#include <main.h>



#ifndef SRC_FLASHMEMORYAPI_FLASH_MEMORY_API_H_
#define SRC_FLASHMEMORYAPI_FLASH_MEMORY_API_H_

#endif /* SRC_FLASHMEMORYAPI_FLASH_MEMORY_API_H_ */

#define page_size 0x800
#define PAGE_ADDRESS 0x08005000
#define FLASH_SECTOR FLASH_SECTOR_1

uint32_t save_to_flash(uint8_t *data, uint8_t data_length, uint32_t flash_addres);
void read_from_flash(uint32_t address, uint8_t data_length, uint8_t* buffer);
uint8_t Flash_Erase_Segment(uint32_t data_segment);
