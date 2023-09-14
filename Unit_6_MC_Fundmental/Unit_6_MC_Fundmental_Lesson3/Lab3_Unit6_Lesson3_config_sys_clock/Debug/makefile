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
Lab3_Unit6_Lesson3_config_sys_clock.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Lab3_Unit6_Lesson3_config_sys_clock.list \

OBJCOPY_BIN += \
Lab3_Unit6_Lesson3_config_sys_clock.bin \


# All Target
all: Lab3_Unit6_Lesson3_config_sys_clock.elf secondary-outputs

# Tool invocations
Lab3_Unit6_Lesson3_config_sys_clock.elf: $(OBJS) $(USER_OBJS) D:\KS_ES\codes\Learn_In_Depth_KS\Unit_6_MC_Fundmental\Unit_6_MC_Fundmental_Lesson3\Lab3_Unit6_Lesson3_config_sys_clock\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -o "Lab3_Unit6_Lesson3_config_sys_clock.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"D:\KS_ES\codes\Learn_In_Depth_KS\Unit_6_MC_Fundmental\Unit_6_MC_Fundmental_Lesson3\Lab3_Unit6_Lesson3_config_sys_clock\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Lab3_Unit6_Lesson3_config_sys_clock.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Lab3_Unit6_Lesson3_config_sys_clock.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Lab3_Unit6_Lesson3_config_sys_clock.list"
	@echo 'Finished building: $@'
	@echo ' '

Lab3_Unit6_Lesson3_config_sys_clock.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Lab3_Unit6_Lesson3_config_sys_clock.bin"
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
