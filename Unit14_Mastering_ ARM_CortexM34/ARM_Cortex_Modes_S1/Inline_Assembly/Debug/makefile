################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
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
Inline_Assembly.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Inline_Assembly.list \

OBJCOPY_BIN += \
Inline_Assembly.bin \


# All Target
all: Inline_Assembly.elf secondary-outputs

# Tool invocations
Inline_Assembly.elf: $(OBJS) $(USER_OBJS) D:\KS_ES\codes\Learn_In_Depth_KS\Drivers\STM32F103x8\Inline_Assembly\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -o "Inline_Assembly.axf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"D:\KS_ES\codes\Learn_In_Depth_KS\Drivers\STM32F103x8\Inline_Assembly\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Inline_Assembly.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	arm-none-eabi-objdump -D Inline_Assembly.axf >Inline_Assembly.s
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Inline_Assembly.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Inline_Assembly.list"
	@echo 'Finished building: $@'
	@echo ' '

Inline_Assembly.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Inline_Assembly.bin"
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
