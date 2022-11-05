################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Source/04-APP/subdir.mk
-include Source/02-ECUA/SSD/Src/subdir.mk
-include Source/02-ECUA/Led/Src/subdir.mk
-include Source/02-ECUA/LM35/Src/subdir.mk
-include Source/02-ECUA/LCD/Src/subdir.mk
-include Source/02-ECUA/Keypad/Src/subdir.mk
-include Source/02-ECUA/EEPROM24C16/Src/subdir.mk
-include Source/02-ECUA/DC_Motor/Src/subdir.mk
-include Source/02-ECUA/Buzzer/src/subdir.mk
-include Source/02-ECUA/Button/Src/subdir.mk
-include Source/01-MCAL/UART/Src/subdir.mk
-include Source/01-MCAL/Timer0/Src/subdir.mk
-include Source/01-MCAL/SPI/Src/subdir.mk
-include Source/01-MCAL/I2C/Src/subdir.mk
-include Source/01-MCAL/GINT/Src/subdir.mk
-include Source/01-MCAL/EXINT/Src/subdir.mk
-include Source/01-MCAL/Dio/Src/subdir.mk
-include Source/01-MCAL/ADC/Src/subdir.mk
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
session_27_8_updated.lss \

FLASH_IMAGE += \
session_27_8_updated.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: session_27_8_updated.elf secondary-outputs

# Tool invocations
session_27_8_updated.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,session_27_8_updated.map -mmcu=atmega32 -o "session_27_8_updated.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

session_27_8_updated.lss: session_27_8_updated.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S session_27_8_updated.elf  >"session_27_8_updated.lss"
	@echo 'Finished building: $@'
	@echo ' '

session_27_8_updated.hex: session_27_8_updated.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex session_27_8_updated.elf  "session_27_8_updated.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: session_27_8_updated.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 session_27_8_updated.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) session_27_8_updated.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
