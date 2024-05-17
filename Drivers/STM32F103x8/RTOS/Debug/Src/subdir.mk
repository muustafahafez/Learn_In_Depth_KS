################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/main.o: ../Src/main.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/HAL/includes" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/CMSIS_V5" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/MY_RTOS/inc" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/Stm32_F103C6_Drivers/inc" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/main.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/syscalls.o: ../Src/syscalls.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/HAL/includes" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/CMSIS_V5" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/MY_RTOS/inc" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/Stm32_F103C6_Drivers/inc" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/syscalls.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/sysmem.o: ../Src/sysmem.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/HAL/includes" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/CMSIS_V5" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/MY_RTOS/inc" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/Stm32_F103C6_Drivers/inc" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/sysmem.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

