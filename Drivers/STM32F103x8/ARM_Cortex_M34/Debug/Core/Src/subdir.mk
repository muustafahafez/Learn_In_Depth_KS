################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/main.c \
../Core/Src/stm32f103x8_EXTI_driver.c \
../Core/Src/stm32f103x8_RCC_driver.c \
../Core/Src/stm32f103x8_gpio_driver.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c 

OBJS += \
./Core/Src/main.o \
./Core/Src/stm32f103x8_EXTI_driver.o \
./Core/Src/stm32f103x8_RCC_driver.o \
./Core/Src/stm32f103x8_gpio_driver.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o 

C_DEPS += \
./Core/Src/main.d \
./Core/Src/stm32f103x8_EXTI_driver.d \
./Core/Src/stm32f103x8_RCC_driver.d \
./Core/Src/stm32f103x8_gpio_driver.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/main.o: ../Core/Src/main.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/ARM_Cortex_M34/Stm32_F103C6_Drivers" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/ARM_Cortex_M34/Stm32_F103C6_Drivers/GPIO" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/ARM_Cortex_M34/Stm32_F103C6_Drivers/inc" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/ARM_Cortex_M34/Stm32_F103C6_Drivers" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/ARM_Cortex_M34/Stm32_F103C6_Drivers/inc" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/ARM_Cortex_M34/Stm32_F103C6_Drivers" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/main.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/stm32f103x8_EXTI_driver.o: ../Core/Src/stm32f103x8_EXTI_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/ARM_Cortex_M34/Stm32_F103C6_Drivers" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/ARM_Cortex_M34/Stm32_F103C6_Drivers/GPIO" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/ARM_Cortex_M34/Stm32_F103C6_Drivers/inc" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/ARM_Cortex_M34/Stm32_F103C6_Drivers" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/ARM_Cortex_M34/Stm32_F103C6_Drivers/inc" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/ARM_Cortex_M34/Stm32_F103C6_Drivers" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/stm32f103x8_EXTI_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/stm32f103x8_RCC_driver.o: ../Core/Src/stm32f103x8_RCC_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/ARM_Cortex_M34/Stm32_F103C6_Drivers" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/ARM_Cortex_M34/Stm32_F103C6_Drivers/GPIO" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/ARM_Cortex_M34/Stm32_F103C6_Drivers/inc" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/ARM_Cortex_M34/Stm32_F103C6_Drivers" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/ARM_Cortex_M34/Stm32_F103C6_Drivers/inc" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/ARM_Cortex_M34/Stm32_F103C6_Drivers" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/stm32f103x8_RCC_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/stm32f103x8_gpio_driver.o: ../Core/Src/stm32f103x8_gpio_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/ARM_Cortex_M34/Stm32_F103C6_Drivers" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/ARM_Cortex_M34/Stm32_F103C6_Drivers/GPIO" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/ARM_Cortex_M34/Stm32_F103C6_Drivers/inc" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/ARM_Cortex_M34/Stm32_F103C6_Drivers" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/ARM_Cortex_M34/Stm32_F103C6_Drivers/inc" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/ARM_Cortex_M34/Stm32_F103C6_Drivers" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/stm32f103x8_gpio_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/syscalls.o: ../Core/Src/syscalls.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/ARM_Cortex_M34/Stm32_F103C6_Drivers" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/ARM_Cortex_M34/Stm32_F103C6_Drivers/GPIO" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/ARM_Cortex_M34/Stm32_F103C6_Drivers/inc" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/ARM_Cortex_M34/Stm32_F103C6_Drivers" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/ARM_Cortex_M34/Stm32_F103C6_Drivers/inc" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/ARM_Cortex_M34/Stm32_F103C6_Drivers" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/syscalls.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/sysmem.o: ../Core/Src/sysmem.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/ARM_Cortex_M34/Stm32_F103C6_Drivers" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/ARM_Cortex_M34/Stm32_F103C6_Drivers/GPIO" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/ARM_Cortex_M34/Stm32_F103C6_Drivers/inc" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/ARM_Cortex_M34/Stm32_F103C6_Drivers" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/ARM_Cortex_M34/Stm32_F103C6_Drivers/inc" -I"D:/KS_ES/codes/Learn_In_Depth_KS/Drivers/STM32F103x8/ARM_Cortex_M34/Stm32_F103C6_Drivers" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/sysmem.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

