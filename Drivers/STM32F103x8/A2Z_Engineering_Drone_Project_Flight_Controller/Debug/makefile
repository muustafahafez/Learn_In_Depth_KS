################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include MCAL/subdir.mk
-include HAL/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
A2Z_Engineering_Drone_Project_Flight_Controller.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
A2Z_Engineering_Drone_Project_Flight_Controller.list \

OBJCOPY_BIN += \
A2Z_Engineering_Drone_Project_Flight_Controller.bin \


# All Target
all: A2Z_Engineering_Drone_Project_Flight_Controller.elf secondary-outputs

# Tool invocations
A2Z_Engineering_Drone_Project_Flight_Controller.elf: $(OBJS) $(USER_OBJS) D:\KS_ES\codes\Learn_In_Depth_KS\Drivers\STM32F103x8\A2Z_Engineering_Drone_Project_Flight_Controller\STM32F103C8TX_FLASH.ld
	arm-none-eabi-gcc -gdwarf-2 -o "A2Z_Engineering_Drone_Project_Flight_Controller.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"D:\KS_ES\codes\Learn_In_Depth_KS\Drivers\STM32F103x8\A2Z_Engineering_Drone_Project_Flight_Controller\STM32F103C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="A2Z_Engineering_Drone_Project_Flight_Controller.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

A2Z_Engineering_Drone_Project_Flight_Controller.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "A2Z_Engineering_Drone_Project_Flight_Controller.list"
	@echo 'Finished building: $@'
	@echo ' '

A2Z_Engineering_Drone_Project_Flight_Controller.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "A2Z_Engineering_Drone_Project_Flight_Controller.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
