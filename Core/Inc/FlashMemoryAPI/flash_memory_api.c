#include "flash_memory_api.h"

#include <stdint.h>


void read_from_flash(uint32_t address, uint8_t data_length, uint8_t* buffer) {
	for (uint8_t i = 0; i<data_length; ++i) {
		uint8_t data = *(__IO uint8_t*) address;
		buffer[i] = data;
		++address;
	}
}
//Programs a byte onto the Memory
uint32_t save_to_flash(uint8_t *data, uint8_t data_length, uint32_t flash_address) {

	  /* Unlock the Flash to enable the flash control register access *************/
	  HAL_FLASH_Unlock();

	  /* Allow Access to option bytes sector */
	  HAL_FLASH_OB_Unlock();

	  /* Fill EraseInit structure*/
	  FLASH_EraseInitTypeDef EraseInitStruct;
	  EraseInitStruct.TypeErase = FLASH_TYPEERASE_SECTORS;
	  EraseInitStruct.VoltageRange = FLASH_VOLTAGE_RANGE_3;
	  EraseInitStruct.Sector =FLASH_SECTOR_1;
	  EraseInitStruct.Banks = FLASH_BANK_1;
	  EraseInitStruct.NbSectors = 1;

	  uint32_t PageError;

	  volatile uint32_t CURRENT_ADD = flash_address, write_cnt=0;

	  volatile HAL_STATUS_TypeDEF;
	  volatile HAL_StatusTypeDef status;
	  status = HAL_FLASHEx_Erase(&EraseInitStruct, &PageError);


	  for (uint8_t i = 0; i<data_length; ++i) {

		  if (status != HAL_OK) {
		  	HAL_FLASH_OB_Lock();
		  	HAL_FLASH_Lock();
		  	return 0x0;
		  }
		  status = HAL_FLASH_Program(FLASH_TYPEPROGRAM_BYTE, CURRENT_ADD, data[i]);
		  ++CURRENT_ADD;
	  }


	  HAL_FLASH_OB_Lock();
	  HAL_FLASH_Lock();
	  return flash_address + data_length;
}

uint8_t Flash_Erase_Segment(uint32_t DATA_SECTOR) {

	HAL_FLASH_Unlock();

	HAL_FLASH_OB_Unlock();

	FLASH_EraseInitTypeDef EraseInitStruct;
	EraseInitStruct.TypeErase = FLASH_TYPEERASE_SECTORS;
	EraseInitStruct.VoltageRange = FLASH_VOLTAGE_RANGE_3;
	EraseInitStruct.Sector = DATA_SECTOR;
	EraseInitStruct.Banks = FLASH_BANK_1;
	EraseInitStruct.NbSectors = 1;

	uint32_t PageError;


	volatile HAL_StatusTypeDef status;
	status = HAL_FLASHEx_Erase(&EraseInitStruct, &PageError);

	HAL_FLASH_OB_Lock();
	HAL_FLASH_Lock();

	if (status == HAL_OK) {
		return 1;
	} return 0;



}


