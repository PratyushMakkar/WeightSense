################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Inc/ADCToWeightModule/ADCToWeightModule.c 

OBJS += \
./Core/Inc/ADCToWeightModule/ADCToWeightModule.o 

C_DEPS += \
./Core/Inc/ADCToWeightModule/ADCToWeightModule.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/ADCToWeightModule/%.o Core/Inc/ADCToWeightModule/%.su: ../Core/Inc/ADCToWeightModule/%.c Core/Inc/ADCToWeightModule/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Inc-2f-ADCToWeightModule

clean-Core-2f-Inc-2f-ADCToWeightModule:
	-$(RM) ./Core/Inc/ADCToWeightModule/ADCToWeightModule.d ./Core/Inc/ADCToWeightModule/ADCToWeightModule.o ./Core/Inc/ADCToWeightModule/ADCToWeightModule.su

.PHONY: clean-Core-2f-Inc-2f-ADCToWeightModule

