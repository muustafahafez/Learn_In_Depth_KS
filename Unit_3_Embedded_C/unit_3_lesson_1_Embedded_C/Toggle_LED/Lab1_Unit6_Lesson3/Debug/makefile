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
Lab1_Unit6_Lesson3.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Lab1_Unit6_Lesson3.list \

OBJCOPY_BIN += \
Lab1_Unit6_Lesson3.bin \


# All Target
all: Lab1_Unit6_Lesson3.elf secondary-outputs

# Tool invocations
Lab1_Unit6_Lesson3.elf: $(OBJS) $(USER_OBJS) D:\KS_ES\codes\Learn_In_Depth_KS\Unit_3_Embedded_C\unit_3_lesson_1_Embedded_C\Toggle_LED\Lab1_Unit6_Lesson3\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -o "Lab1_Unit6_Lesson3.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"D:\KS_ES\codes\Learn_In_Depth_KS\Unit_3_Embedded_C\unit_3_lesson_1_Embedded_C\Toggle_LED\Lab1_Unit6_Lesson3\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Lab1_Unit6_Lesson3.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Lab1_Unit6_Lesson3.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Lab1_Unit6_Lesson3.list"
	@echo 'Finished building: $@'
	@echo ' '

Lab1_Unit6_Lesson3.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Lab1_Unit6_Lesson3.bin"
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
