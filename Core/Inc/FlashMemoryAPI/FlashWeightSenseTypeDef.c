/*
 * FlashWeightSenseTypeDef.c
 *
 *  Created on: Nov. 20, 2022
 *      Author: pratyushmakkar
 */

#include "FlashWeightSenseTypeDef.h"

uint32_t FindTotalPlasticWaste(FlashWeightSenseTypeDef* object_ptr) {
	return 0x0;
}

FlashWeightSenseTypeDef RetrieveObjectFromAddress(uint32_t address) {

	uint8_t buffer[9] = {};
	read_from_flash(address, 9, &buffer[0]);

	FlashWeightSenseTypeDef weightSense = {};

	uint16_t date = ((uint16_t) buffer[0]<<8) | ((uint16_t) buffer[1]);
	weightSense.date = date;

	uint16_t object_weight = ((uint16_t) buffer[2]<<8) |((uint16_t) buffer[3]);
	weightSense.weight = object_weight;

	uint32_t next_ptr = 0;
	uint32_t FirstEightBits = (((uint32_t) buffer[4])<<24);
	uint32_t SecondEightBits = (((uint32_t) buffer[5])<<16);
	uint32_t ThirdEightBits = (((uint32_t) buffer[6])<<8);
	uint32_t FourthEightBits = ((uint32_t) buffer[7]);
	next_ptr = (((FirstEightBits | SecondEightBits) | ThirdEightBits) | FourthEightBits);
	weightSense.next_ptr = next_ptr;

	return weightSense;

}

uint32_t SaveWeightSenseWithinMemory(uint16_t week, uint16_t year, uint16_t weight,  uint32_t flashAddress) {

	if (flashAddress == 0) {
			flashAddress = PAGE_ADDRESS;
	}
	FlashWeightSenseTypeDef weightSense = {};
	weightSense.weight = weight;

	uint16_t date = 0;
	week &= (0x00FF);
	year &= (0x00FF);
	date = (week<<8) | year;
	weightSense.date = date;

	weightSense.next_ptr = flashAddress+9;;
	uint32_t address = _InsertWeightSenseIntoFlash(&weightSense, flashAddress);
	return address;
}

uint32_t _InsertWeightSenseIntoFlash(FlashWeightSenseTypeDef* object_ptr, uint32_t flashAddress) {

	uint8_t data[9] = {};

	uint16_t date = object_ptr->date;
	data[0] = (uint8_t) ((date & 0xFF00)>>8);
	data[1] = (uint8_t) (date & 0x00FF);

	uint16_t object_weight = object_ptr->weight;
	data[2] = (uint8_t) ((object_weight & (0xFF00))>>8);
	data[3] = (uint8_t) (object_weight & (0x00FF));

	uint32_t next_ptr = object_ptr ->next_ptr;
	data[4] =  ((next_ptr>>24)& 0x000000FF);
	data[5] = (uint8_t) ((next_ptr>>16) & 0x000000FF);
	data[6] = (uint8_t) ((next_ptr>>8) & 0x000000FF);
	data[7] = (uint8_t) ((next_ptr) & 0x000000FF);

	data[8] = 0x00;

	uint32_t address = save_to_flash(&data[0],9, flashAddress);

	if (address == 0x0) {
		Flash_Erase_Segment(FLASH_SECTOR);
		return 0x0;
	}
	return address;

}


