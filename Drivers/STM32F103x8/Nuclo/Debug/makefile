################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F3xx_HAL_Driver/Src/subdir.mk
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
Nuclo.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Nuclo.list \

OBJCOPY_BIN += \
Nuclo.bin \


# All Target
all: Nuclo.elf secondary-outputs

# Tool invocations
Nuclo.elf: $(OBJS) $(USER_OBJS) D:\KS_ES\codes\Learn_In_Depth_KS\Drivers\STM32F103x8\Nuclo\STM32F303RETX_FLASH.ld
	arm-none-eabi-gcc -o "Nuclo.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"D:\KS_ES\codes\Learn_In_Depth_KS\Drivers\STM32F103x8\Nuclo\STM32F303RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Nuclo.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Nuclo.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Nuclo.list"
	@echo 'Finished building: $@'
	@echo ' '

Nuclo.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Nuclo.bin"
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
