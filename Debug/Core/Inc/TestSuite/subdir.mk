################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Inc/TestSuite/TestSuite.c 

OBJS += \
./Core/Inc/TestSuite/TestSuite.o 

C_DEPS += \
./Core/Inc/TestSuite/TestSuite.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/TestSuite/%.o Core/Inc/TestSuite/%.su: ../Core/Inc/TestSuite/%.c Core/Inc/TestSuite/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Inc-2f-TestSuite

clean-Core-2f-Inc-2f-TestSuite:
	-$(RM) ./Core/Inc/TestSuite/TestSuite.d ./Core/Inc/TestSuite/TestSuite.o ./Core/Inc/TestSuite/TestSuite.su

.PHONY: clean-Core-2f-Inc-2f-TestSuite

