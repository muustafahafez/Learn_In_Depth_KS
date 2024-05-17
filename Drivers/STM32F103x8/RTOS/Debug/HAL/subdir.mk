################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/I2C_Slave_EEPROM.c \
../HAL/keypad.c \
../HAL/lcd.c 

OBJS += \
./HAL/I2C_Slave_EEPROM.o \
./HAL/keypad.o \
./HAL/lcd.o 

C_DEPS += \
./HAL/I2C_Slave_EEPROM.d \
./HAL/keypad.d \
./HAL/lcd.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/I2C_Slave_EEPROM.o: ../HAL/I2C_Slave_EEPROM.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/HAL/includes" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/CMSIS_V5" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/MY_RTOS/inc" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/Stm32_F103C6_Drivers/inc" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/I2C_Slave_EEPROM.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
HAL/keypad.o: ../HAL/keypad.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/HAL/includes" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/CMSIS_V5" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/MY_RTOS/inc" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/Stm32_F103C6_Drivers/inc" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/keypad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
HAL/lcd.o: ../HAL/lcd.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/HAL/includes" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/CMSIS_V5" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/MY_RTOS/inc" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/RTOS/Stm32_F103C6_Drivers/inc" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/lcd.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

