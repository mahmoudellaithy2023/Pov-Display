################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/TIM1/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/L298N/subdir.mk
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
POV_Display_Fan.lss \

FLASH_IMAGE += \
POV_Display_Fan.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: POV_Display_Fan.elf secondary-outputs

# Tool invocations
POV_Display_Fan.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,POV_Display_Fan.map -mmcu=atmega32 -o "POV_Display_Fan.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

POV_Display_Fan.lss: POV_Display_Fan.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S POV_Display_Fan.elf  >"POV_Display_Fan.lss"
	@echo 'Finished building: $@'
	@echo ' '

POV_Display_Fan.hex: POV_Display_Fan.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex POV_Display_Fan.elf  "POV_Display_Fan.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: POV_Display_Fan.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 POV_Display_Fan.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) POV_Display_Fan.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
