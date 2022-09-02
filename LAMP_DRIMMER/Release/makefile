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
LAMP_DRIMMER.lss \

FLASH_IMAGE += \
LAMP_DRIMMER.hex \

EEPROM_IMAGE += \
LAMP_DRIMMER.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: LAMP_DRIMMER.elf secondary-outputs

# Tool invocations
LAMP_DRIMMER.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,LAMP_DRIMMER.map -mmcu=atmega16 -o "LAMP_DRIMMER.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

LAMP_DRIMMER.lss: LAMP_DRIMMER.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S LAMP_DRIMMER.elf  >"LAMP_DRIMMER.lss"
	@echo 'Finished building: $@'
	@echo ' '

LAMP_DRIMMER.hex: LAMP_DRIMMER.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex LAMP_DRIMMER.elf  "LAMP_DRIMMER.hex"
	@echo 'Finished building: $@'
	@echo ' '

LAMP_DRIMMER.eep: LAMP_DRIMMER.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex LAMP_DRIMMER.elf  "LAMP_DRIMMER.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: LAMP_DRIMMER.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 LAMP_DRIMMER.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) LAMP_DRIMMER.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
