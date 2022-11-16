################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Inc/DisplayRegsiterModule/display_module.c 

OBJS += \
./Core/Inc/DisplayRegsiterModule/display_module.o 

C_DEPS += \
./Core/Inc/DisplayRegsiterModule/display_module.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/DisplayRegsiterModule/%.o Core/Inc/DisplayRegsiterModule/%.su: ../Core/Inc/DisplayRegsiterModule/%.c Core/Inc/DisplayRegsiterModule/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Inc-2f-DisplayRegsiterModule

clean-Core-2f-Inc-2f-DisplayRegsiterModule:
	-$(RM) ./Core/Inc/DisplayRegsiterModule/display_module.d ./Core/Inc/DisplayRegsiterModule/display_module.o ./Core/Inc/DisplayRegsiterModule/display_module.su

.PHONY: clean-Core-2f-Inc-2f-DisplayRegsiterModule

