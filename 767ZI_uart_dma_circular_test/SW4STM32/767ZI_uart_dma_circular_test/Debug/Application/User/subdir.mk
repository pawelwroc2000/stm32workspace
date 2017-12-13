################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/PM/PM/stm32workspace/767ZI_uart_dma_circular_test/Src/freertos.c \
C:/PM/PM/stm32workspace/767ZI_uart_dma_circular_test/Src/main.c \
C:/PM/PM/stm32workspace/767ZI_uart_dma_circular_test/Src/stm32f7xx_hal_msp.c \
C:/PM/PM/stm32workspace/767ZI_uart_dma_circular_test/Src/stm32f7xx_hal_timebase_TIM.c \
C:/PM/PM/stm32workspace/767ZI_uart_dma_circular_test/Src/stm32f7xx_it.c 

OBJS += \
./Application/User/freertos.o \
./Application/User/main.o \
./Application/User/stm32f7xx_hal_msp.o \
./Application/User/stm32f7xx_hal_timebase_TIM.o \
./Application/User/stm32f7xx_it.o 

C_DEPS += \
./Application/User/freertos.d \
./Application/User/main.d \
./Application/User/stm32f7xx_hal_msp.d \
./Application/User/stm32f7xx_hal_timebase_TIM.d \
./Application/User/stm32f7xx_it.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/freertos.o: C:/PM/PM/stm32workspace/767ZI_uart_dma_circular_test/Src/freertos.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F767xx -I"C:/PM/PM/stm32workspace/767ZI_uart_dma_circular_test/Inc" -I"C:/PM/PM/stm32workspace/767ZI_uart_dma_circular_test/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/PM/PM/stm32workspace/767ZI_uart_dma_circular_test/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/PM/PM/stm32workspace/767ZI_uart_dma_circular_test/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/PM/PM/stm32workspace/767ZI_uart_dma_circular_test/Drivers/CMSIS/Include" -I"C:/PM/PM/stm32workspace/767ZI_uart_dma_circular_test/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1" -I"C:/PM/PM/stm32workspace/767ZI_uart_dma_circular_test/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/PM/PM/stm32workspace/767ZI_uart_dma_circular_test/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/main.o: C:/PM/PM/stm32workspace/767ZI_uart_dma_circular_test/Src/main.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F767xx -I"C:/PM/PM/stm32workspace/767ZI_uart_dma_circular_test/Inc" -I"C:/PM/PM/stm32workspace/767ZI_uart_dma_circular_test/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/PM/PM/stm32workspace/767ZI_uart_dma_circular_test/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/PM/PM/stm32workspace/767ZI_uart_dma_circular_test/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/PM/PM/stm32workspace/767ZI_uart_dma_circular_test/Drivers/CMSIS/Include" -I"C:/PM/PM/stm32workspace/767ZI_uart_dma_circular_test/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1" -I"C:/PM/PM/stm32workspace/767ZI_uart_dma_circular_test/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/PM/PM/stm32workspace/767ZI_uart_dma_circular_test/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/stm32f7xx_hal_msp.o: C:/PM/PM/stm32workspace/767ZI_uart_dma_circular_test/Src/stm32f7xx_hal_msp.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F767xx -I"C:/PM/PM/stm32workspace/767ZI_uart_dma_circular_test/Inc" -I"C:/PM/PM/stm32workspace/767ZI_uart_dma_circular_test/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/PM/PM/stm32workspace/767ZI_uart_dma_circular_test/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/PM/PM/stm32workspace/767ZI_uart_dma_circular_test/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/PM/PM/stm32workspace/767ZI_uart_dma_circular_test/Drivers/CMSIS/Include" -I"C:/PM/PM/stm32workspace/767ZI_uart_dma_circular_test/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1" -I"C:/PM/PM/stm32workspace/767ZI_uart_dma_circular_test/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/PM/PM/stm32workspace/767ZI_uart_dma_circular_test/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/stm32f7xx_hal_timebase_TIM.o: C:/PM/PM/stm32workspace/767ZI_uart_dma_circular_test/Src/stm32f7xx_hal_timebase_TIM.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F767xx -I"C:/PM/PM/stm32workspace/767ZI_uart_dma_circular_test/Inc" -I"C:/PM/PM/stm32workspace/767ZI_uart_dma_circular_test/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/PM/PM/stm32workspace/767ZI_uart_dma_circular_test/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/PM/PM/stm32workspace/767ZI_uart_dma_circular_test/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/PM/PM/stm32workspace/767ZI_uart_dma_circular_test/Drivers/CMSIS/Include" -I"C:/PM/PM/stm32workspace/767ZI_uart_dma_circular_test/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1" -I"C:/PM/PM/stm32workspace/767ZI_uart_dma_circular_test/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/PM/PM/stm32workspace/767ZI_uart_dma_circular_test/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/stm32f7xx_it.o: C:/PM/PM/stm32workspace/767ZI_uart_dma_circular_test/Src/stm32f7xx_it.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F767xx -I"C:/PM/PM/stm32workspace/767ZI_uart_dma_circular_test/Inc" -I"C:/PM/PM/stm32workspace/767ZI_uart_dma_circular_test/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/PM/PM/stm32workspace/767ZI_uart_dma_circular_test/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/PM/PM/stm32workspace/767ZI_uart_dma_circular_test/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/PM/PM/stm32workspace/767ZI_uart_dma_circular_test/Drivers/CMSIS/Include" -I"C:/PM/PM/stm32workspace/767ZI_uart_dma_circular_test/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1" -I"C:/PM/PM/stm32workspace/767ZI_uart_dma_circular_test/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/PM/PM/stm32workspace/767ZI_uart_dma_circular_test/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


