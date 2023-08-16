################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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
LSS += \
50_CALCULATOR_2.lss \

FLASH_IMAGE += \
50_CALCULATOR_2.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: 50_CALCULATOR_2.elf secondary-outputs

# Tool invocations
50_CALCULATOR_2.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,50_CALCULATOR_2.map -mmcu=atmega32 -o "50_CALCULATOR_2.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

50_CALCULATOR_2.lss: 50_CALCULATOR_2.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 50_CALCULATOR_2.elf  >"50_CALCULATOR_2.lss"
	@echo 'Finished building: $@'
	@echo ' '

50_CALCULATOR_2.hex: 50_CALCULATOR_2.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex 50_CALCULATOR_2.elf  "50_CALCULATOR_2.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 50_CALCULATOR_2.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 50_CALCULATOR_2.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 50_CALCULATOR_2.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
