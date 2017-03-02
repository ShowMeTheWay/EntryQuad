################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/heap_4.c 

OBJS += \
./Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/heap_4.o 

C_DEPS += \
./Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/heap_4.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/%.o: ../Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D__weak=__attribute__((weak)) -D__packed=__attribute__((__packed__)) -DUSE_HAL_DRIVER -DSTM32F429xx -I"D:/workspace/SSworkspace/EntryQuad/Inc" -I"D:/workspace/SSworkspace/EntryQuad/Drivers/STM32F4xx_HAL_Driver/Inc" -I"D:/workspace/SSworkspace/EntryQuad/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"D:/workspace/SSworkspace/EntryQuad/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"D:/workspace/SSworkspace/EntryQuad/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/workspace/SSworkspace/EntryQuad/Middlewares/Third_Party/FreeRTOS/Source/include" -I"D:/workspace/SSworkspace/EntryQuad/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"D:/workspace/SSworkspace/EntryQuad/Drivers/CMSIS/Include"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


