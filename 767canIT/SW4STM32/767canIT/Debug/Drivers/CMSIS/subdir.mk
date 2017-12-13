################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/PM/PM/stm32workspace/767canIT/Src/system_stm32f7xx.c 

OBJS += \
./Drivers/CMSIS/system_stm32f7xx.o 

C_DEPS += \
./Drivers/CMSIS/system_stm32f7xx.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/system_stm32f7xx.o: C:/PM/PM/stm32workspace/767canIT/Src/system_stm32f7xx.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F767xx -I"C:/PM/PM/stm32workspace/767canIT/Inc" -I"C:/PM/PM/stm32workspace/767canIT/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/PM/PM/stm32workspace/767canIT/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/PM/PM/stm32workspace/767canIT/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/PM/PM/stm32workspace/767canIT/Drivers/CMSIS/Include" -I"C:/PM/PM/stm32workspace/767canIT/Inc"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


