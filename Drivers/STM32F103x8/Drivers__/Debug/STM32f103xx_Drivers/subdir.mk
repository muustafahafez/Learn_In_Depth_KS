################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32f103xx_Drivers/EXTI.c \
../STM32f103xx_Drivers/GPIO.c 

OBJS += \
./STM32f103xx_Drivers/EXTI.o \
./STM32f103xx_Drivers/GPIO.o 

C_DEPS += \
./STM32f103xx_Drivers/EXTI.d \
./STM32f103xx_Drivers/GPIO.d 


# Each subdirectory must supply rules for building sources it contributes
STM32f103xx_Drivers/EXTI.o: ../STM32f103xx_Drivers/EXTI.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/Drivers__/STM32f103xx_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32f103xx_Drivers/EXTI.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32f103xx_Drivers/GPIO.o: ../STM32f103xx_Drivers/GPIO.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/Drivers__/STM32f103xx_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32f103xx_Drivers/GPIO.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

