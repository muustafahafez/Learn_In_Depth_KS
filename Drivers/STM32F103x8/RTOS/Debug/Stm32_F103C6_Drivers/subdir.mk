################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Stm32_F103C6_Drivers/stm32f103x8_EXTI_driver.c \
../Stm32_F103C6_Drivers/stm32f103x8_I2C_Drver.c \
../Stm32_F103C6_Drivers/stm32f103x8_RCC_driver.c \
../Stm32_F103C6_Drivers/stm32f103x8_SPI_Drver.c \
../Stm32_F103C6_Drivers/stm32f103x8_USART_driver.c 

OBJS += \
./Stm32_F103C6_Drivers/stm32f103x8_EXTI_driver.o \
./Stm32_F103C6_Drivers/stm32f103x8_I2C_Drver.o \
./Stm32_F103C6_Drivers/stm32f103x8_RCC_driver.o \
./Stm32_F103C6_Drivers/stm32f103x8_SPI_Drver.o \
./Stm32_F103C6_Drivers/stm32f103x8_USART_driver.o 

C_DEPS += \
./Stm32_F103C6_Drivers/stm32f103x8_EXTI_driver.d \
./Stm32_F103C6_Drivers/stm32f103x8_I2C_Drver.d \
./Stm32_F103C6_Drivers/stm32f103x8_RCC_driver.d \
./Stm32_F103C6_Drivers/stm32f103x8_SPI_Drver.d \
./Stm32_F103C6_Drivers/stm32f103x8_USART_driver.d 


# Each subdirectory must supply rules for building sources it contributes
Stm32_F103C6_Drivers/stm32f103x8_EXTI_driver.o: ../Stm32_F103C6_Drivers/stm32f103x8_EXTI_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/HAL/includes" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/CMSIS_V5" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/MY_RTOS/inc" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/Stm32_F103C6_Drivers/inc" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32_F103C6_Drivers/stm32f103x8_EXTI_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Stm32_F103C6_Drivers/stm32f103x8_I2C_Drver.o: ../Stm32_F103C6_Drivers/stm32f103x8_I2C_Drver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/HAL/includes" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/CMSIS_V5" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/MY_RTOS/inc" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/Stm32_F103C6_Drivers/inc" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32_F103C6_Drivers/stm32f103x8_I2C_Drver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Stm32_F103C6_Drivers/stm32f103x8_RCC_driver.o: ../Stm32_F103C6_Drivers/stm32f103x8_RCC_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/HAL/includes" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/CMSIS_V5" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/MY_RTOS/inc" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/Stm32_F103C6_Drivers/inc" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32_F103C6_Drivers/stm32f103x8_RCC_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Stm32_F103C6_Drivers/stm32f103x8_SPI_Drver.o: ../Stm32_F103C6_Drivers/stm32f103x8_SPI_Drver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/HAL/includes" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/CMSIS_V5" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/MY_RTOS/inc" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/Stm32_F103C6_Drivers/inc" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32_F103C6_Drivers/stm32f103x8_SPI_Drver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Stm32_F103C6_Drivers/stm32f103x8_USART_driver.o: ../Stm32_F103C6_Drivers/stm32f103x8_USART_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/HAL/includes" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/CMSIS_V5" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/MY_RTOS/inc" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/Stm32_F103C6_Drivers/inc" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32_F103C6_Drivers/stm32f103x8_USART_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

