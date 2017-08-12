################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/adaptation.c \
../Src/freertos.c \
../Src/main.c \
../Src/sin_cos.c \
../Src/stm32f4xx_hal_msp.c \
../Src/stm32f4xx_hal_timebase_TIM.c \
../Src/stm32f4xx_it.c 

OBJS += \
./Src/adaptation.o \
./Src/freertos.o \
./Src/main.o \
./Src/sin_cos.o \
./Src/stm32f4xx_hal_msp.o \
./Src/stm32f4xx_hal_timebase_TIM.o \
./Src/stm32f4xx_it.o 

C_DEPS += \
./Src/adaptation.d \
./Src/freertos.d \
./Src/main.d \
./Src/sin_cos.d \
./Src/stm32f4xx_hal_msp.d \
./Src/stm32f4xx_hal_timebase_TIM.d \
./Src/stm32f4xx_it.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F429xx -DARM_MATH_CM4 -D__FPU_PRESENT -I"D:/Beni/workspace/EntryQuad/Inc" -I"D:/Beni/workspace/EntryQuad/matlab/source" -I"D:/Beni/workspace/EntryQuad/Drivers/STM32F4xx_HAL_Driver/Inc" -I"D:/Beni/workspace/EntryQuad/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"D:/Beni/workspace/EntryQuad/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"D:/Beni/workspace/EntryQuad/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/Beni/workspace/EntryQuad/Middlewares/Third_Party/FreeRTOS/Source/include" -I"D:/Beni/workspace/EntryQuad/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"D:/Beni/workspace/EntryQuad/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


