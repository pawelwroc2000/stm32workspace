################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
C:/PM/PM/stm32workspace/767ZI_uart_dma_circular_test/SW4STM32/startup_stm32f767xx.s 

OBJS += \
./Application/SW4STM32/startup_stm32f767xx.o 


# Each subdirectory must supply rules for building sources it contributes
Application/SW4STM32/startup_stm32f767xx.o: C:/PM/PM/stm32workspace/767ZI_uart_dma_circular_test/SW4STM32/startup_stm32f767xx.s
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Assembler'
	@echo $(PWD)
	arm-none-eabi-as -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-d16 -g -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


