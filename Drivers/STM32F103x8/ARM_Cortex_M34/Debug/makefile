################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
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
ARM_Cortex_M34.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
ARM_Cortex_M34.list \

OBJCOPY_BIN += \
ARM_Cortex_M34.bin \


# All Target
all:
	+@make --no-print-directory main-build && make --no-print-directory post-build

# Main-build Target
main-build: ARM_Cortex_M34.elf secondary-outputs

# Tool invocations
ARM_Cortex_M34.elf: $(OBJS) $(USER_OBJS) D:\KS_ES\codes\Learn_In_Depth_KS\Drivers\STM32F103x8\ARM_Cortex_M34\STM32F103C8TX_FLASH.ld
	arm-none-eabi-gcc -o "ARM_Cortex_M34.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"D:\KS_ES\codes\Learn_In_Depth_KS\Drivers\STM32F103x8\ARM_Cortex_M34\STM32F103C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="ARM_Cortex_M34.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

ARM_Cortex_M34.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "ARM_Cortex_M34.list"
	@echo 'Finished building: $@'
	@echo ' '

ARM_Cortex_M34.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "ARM_Cortex_M34.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

post-build:
	arm-none-eabi-objcopy -O ihex ARM_Cortex_M34.elf ARM_Cortex_M34.axf
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
