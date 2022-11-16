################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/FlashMemoryAPI/flash_memory_api.c 

OBJS += \
./Core/Src/FlashMemoryAPI/flash_memory_api.o 

C_DEPS += \
./Core/Src/FlashMemoryAPI/flash_memory_api.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/FlashMemoryAPI/%.o Core/Src/FlashMemoryAPI/%.su: ../Core/Src/FlashMemoryAPI/%.c Core/Src/FlashMemoryAPI/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I/Users/pratyushmakkar/STM32CubeIDE/workspace_1.9.0/198FinalProject/Core/Src/DisplayRegsiterModule -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-FlashMemoryAPI

clean-Core-2f-Src-2f-FlashMemoryAPI:
	-$(RM) ./Core/Src/FlashMemoryAPI/flash_memory_api.d ./Core/Src/FlashMemoryAPI/flash_memory_api.o ./Core/Src/FlashMemoryAPI/flash_memory_api.su

.PHONY: clean-Core-2f-Src-2f-FlashMemoryAPI

