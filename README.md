# :computer: Embedded Weight Measuring Device

**Weight Sense** is an embedded device developed using the STM32 platform and C/C++ that measures the  weight of an object and outputs it into a LCD display using a Bit Shift register. 

The source code for drivers is available in <kbd>Core/inc</kbd>. The flash memory driver contains the driver for the flash memory. For example, here is some sample code,

## :inbox_tray: Installtion
The project follows the STM32 platform folder organization.The following batch file can be used to run the project, 

```batch
@setlocal
@set CUR_DIR=%CD%
start /B Connect_JLinkGDBServerCL.bat
start /B Start_GDB.bat %CUR_DIR%\SUITE_Objs\RTLSTagTest.elf
@endlocal
```
Courtesy of the following [source,](https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet#links) 
## :pushpin: Documentation
```C
FlashWeightSenseTypeDef RetrieveObjectFromAddress(uint32_t address) {

	uint8_t buffer[9] = {};
	read_from_flash(address, 9, &buffer[0]);

	FlashWeightSenseTypeDef weightSense = {};

	uint16_t date = ((uint16_t) buffer[0]<<8) | ((uint16_t) buffer[1]);
	weightSense.date = date;

	uint16_t object_weight = ((uint16_t) buffer[2]<<8) |((uint16_t) buffer[3]);
	weightSense.weight = object_weight;
```
The macros are defined throughout header files such as,

```C

#define _ZERO 0x7D
#define _ONE 0x11
#define _TWO 0x3E
#define _THREE 0x37
#define _FOUR 0x53
#define _FIVE 0x67
#define _SIX 0xEF
```

## License
This project is licensed under the [Mozilla Public License 2.0](LICENSE)
