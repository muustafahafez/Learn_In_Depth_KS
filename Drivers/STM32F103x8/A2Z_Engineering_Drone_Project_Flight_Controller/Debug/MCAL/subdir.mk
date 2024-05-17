################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/GPIO.c \
../MCAL/I2C.c \
../MCAL/RCC.c \
../MCAL/TIMER.c 

OBJS += \
./MCAL/GPIO.o \
./MCAL/I2C.o \
./MCAL/RCC.o \
./MCAL/TIMER.o 

C_DEPS += \
./MCAL/GPIO.d \
./MCAL/I2C.d \
./MCAL/RCC.d \
./MCAL/TIMER.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/GPIO.o: ../MCAL/GPIO.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/A2Z_Engineering_Drone_Project_Flight_Controller/HAL/HAL_Includes" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/A2Z_Engineering_Drone_Project_Flight_Controller/Inc/LIBs" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/A2Z_Engineering_Drone_Project_Flight_Controller/MCAL/MCAL_Includes" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/A2Z_Engineering_Drone_Project_Flight_Controller/MCAL/MCAL_Includes" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/GPIO.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MCAL/I2C.o: ../MCAL/I2C.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/A2Z_Engineering_Drone_Project_Flight_Controller/HAL/HAL_Includes" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/A2Z_Engineering_Drone_Project_Flight_Controller/Inc/LIBs" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/A2Z_Engineering_Drone_Project_Flight_Controller/MCAL/MCAL_Includes" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/A2Z_Engineering_Drone_Project_Flight_Controller/MCAL/MCAL_Includes" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/I2C.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MCAL/RCC.o: ../MCAL/RCC.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/A2Z_Engineering_Drone_Project_Flight_Controller/HAL/HAL_Includes" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/A2Z_Engineering_Drone_Project_Flight_Controller/Inc/LIBs" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/A2Z_Engineering_Drone_Project_Flight_Controller/MCAL/MCAL_Includes" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/A2Z_Engineering_Drone_Project_Flight_Controller/MCAL/MCAL_Includes" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/RCC.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MCAL/TIMER.o: ../MCAL/TIMER.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/A2Z_Engineering_Drone_Project_Flight_Controller/HAL/HAL_Includes" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/A2Z_Engineering_Drone_Project_Flight_Controller/Inc/LIBs" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/A2Z_Engineering_Drone_Project_Flight_Controller/MCAL/MCAL_Includes" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/A2Z_Engineering_Drone_Project_Flight_Controller/MCAL/MCAL_Includes" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/TIMER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

