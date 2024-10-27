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
LED.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
LED.list \

OBJCOPY_HEX += \
LED.hex \

OBJCOPY_BIN += \
LED.bin \


# All Target
all: LED.elf secondary-outputs

# Tool invocations
LED.elf: $(OBJS) $(USER_OBJS) F:\EmbeddedSystemDeploma\learn-in-depth-full-progress\lern-in-depth\Embedded_C\Lecture_1\Assignment\LED\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -o "LED.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"F:\EmbeddedSystemDeploma\learn-in-depth-full-progress\lern-in-depth\Embedded_C\Lecture_1\Assignment\LED\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="LED.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

LED.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "LED.list"
	@echo 'Finished building: $@'
	@echo ' '

LED.hex: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "LED.hex"
	@echo 'Finished building: $@'
	@echo ' '

LED.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "LED.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
