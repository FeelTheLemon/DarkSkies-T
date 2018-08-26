################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/adc.c \
../Src/crc.c \
../Src/dma.c \
../Src/gpio.c \
../Src/input.c \
../Src/main.c \
../Src/spi.c \
../Src/stm32f1xx_hal_msp.c \
../Src/stm32f1xx_it.c \
../Src/syscalls.c \
../Src/system_stm32f1xx.c \
../Src/tim.c \
../Src/usart.c 

CPP_SRCS += \
../Src/radio.cpp 

OBJS += \
./Src/adc.o \
./Src/crc.o \
./Src/dma.o \
./Src/gpio.o \
./Src/input.o \
./Src/main.o \
./Src/radio.o \
./Src/spi.o \
./Src/stm32f1xx_hal_msp.o \
./Src/stm32f1xx_it.o \
./Src/syscalls.o \
./Src/system_stm32f1xx.o \
./Src/tim.o \
./Src/usart.o 

C_DEPS += \
./Src/adc.d \
./Src/crc.d \
./Src/dma.d \
./Src/gpio.d \
./Src/input.d \
./Src/main.d \
./Src/spi.d \
./Src/stm32f1xx_hal_msp.d \
./Src/stm32f1xx_it.d \
./Src/syscalls.d \
./Src/system_stm32f1xx.d \
./Src/tim.d \
./Src/usart.d 

CPP_DEPS += \
./Src/radio.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F103xB -I"D:/Documents/STM32SW/DarkSkies-T/Inc" -I"D:/Documents/STM32SW/DarkSkies-T/Drivers/STM32F1xx_HAL_Driver/Inc" -I"D:/Documents/STM32SW/DarkSkies-T/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy" -I"D:/Documents/STM32SW/DarkSkies-T/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"D:/Documents/STM32SW/DarkSkies-T/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -fdata-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Src/%.o: ../Src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m3 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F103xB -I"D:/Documents/STM32SW/DarkSkies-T/Inc" -I"D:/Documents/STM32SW/DarkSkies-T/Drivers/STM32F1xx_HAL_Driver/Inc" -I"D:/Documents/STM32SW/DarkSkies-T/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy" -I"C:/Ac6/SystemWorkbench/plugins/fr.ac6.mcu.externaltools.arm-none.win32_1.16.0.201807130628/tools/compiler/arm-none-eabi/include" -I"D:/Documents/STM32SW/DarkSkies-T/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"D:/Documents/STM32SW/DarkSkies-T/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -fdata-sections -c -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


