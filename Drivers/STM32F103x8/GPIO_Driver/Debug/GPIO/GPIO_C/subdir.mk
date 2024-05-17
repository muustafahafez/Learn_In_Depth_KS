################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../GPIO/GPIO_C/GPIO.c 

OBJS += \
./GPIO/GPIO_C/GPIO.o 

C_DEPS += \
./GPIO/GPIO_C/GPIO.d 


# Each subdirectory must supply rules for building sources it contributes
GPIO/GPIO_C/GPIO.o: ../GPIO/GPIO_C/GPIO.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/GPIO_Driver/Stm32_F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"GPIO/GPIO_C/GPIO.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

