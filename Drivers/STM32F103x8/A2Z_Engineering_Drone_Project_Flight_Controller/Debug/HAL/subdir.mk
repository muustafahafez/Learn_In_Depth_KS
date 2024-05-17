################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/A2Z_Engineering_Drone_ESC.c 

OBJS += \
./HAL/A2Z_Engineering_Drone_ESC.o 

C_DEPS += \
./HAL/A2Z_Engineering_Drone_ESC.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/A2Z_Engineering_Drone_ESC.o: ../HAL/A2Z_Engineering_Drone_ESC.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/A2Z_Engineering_Drone_Project_Flight_Controller/HAL/HAL_Includes" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/A2Z_Engineering_Drone_Project_Flight_Controller/Inc/LIBs" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/A2Z_Engineering_Drone_Project_Flight_Controller/MCAL/MCAL_Includes" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/A2Z_Engineering_Drone_Project_Flight_Controller/MCAL/MCAL_Includes" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/A2Z_Engineering_Drone_ESC.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

