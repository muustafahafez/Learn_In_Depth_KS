################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MY_RTOS/CortexMX_OS_porting.c \
../MY_RTOS/MYRTOS_FIFO.c \
../MY_RTOS/Scheduler.c 

OBJS += \
./MY_RTOS/CortexMX_OS_porting.o \
./MY_RTOS/MYRTOS_FIFO.o \
./MY_RTOS/Scheduler.o 

C_DEPS += \
./MY_RTOS/CortexMX_OS_porting.d \
./MY_RTOS/MYRTOS_FIFO.d \
./MY_RTOS/Scheduler.d 


# Each subdirectory must supply rules for building sources it contributes
MY_RTOS/CortexMX_OS_porting.o: ../MY_RTOS/CortexMX_OS_porting.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/HAL/includes" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/CMSIS_V5" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/MY_RTOS/inc" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/Stm32_F103C6_Drivers/inc" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MY_RTOS/CortexMX_OS_porting.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MY_RTOS/MYRTOS_FIFO.o: ../MY_RTOS/MYRTOS_FIFO.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/HAL/includes" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/CMSIS_V5" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/MY_RTOS/inc" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/Stm32_F103C6_Drivers/inc" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MY_RTOS/MYRTOS_FIFO.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MY_RTOS/Scheduler.o: ../MY_RTOS/Scheduler.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/HAL/includes" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/CMSIS_V5" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/MY_RTOS/inc" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/Stm32_F103C6_Drivers/inc" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MY_RTOS/Scheduler.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

