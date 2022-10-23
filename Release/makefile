################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/UART/subdir.mk
-include MCAL/TIMERS/subdir.mk
-include MCAL/I2C/subdir.mk
-include MCAL/EXT_INTERRUPT/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include HALL/LEDS/subdir.mk
-include HALL/LCD/subdir.mk
-include HALL/KEYPAD/subdir.mk
-include HALL/EEPROM/subdir.mk
-include HALL/DOOR/subdir.mk
-include HALL/BUZZER/subdir.mk
-include HALL/BUTTON/subdir.mk
-include HALL/AIR_COND/subdir.mk
-include APP/USER_MODE/subdir.mk
-include APP/ADMIN_MODE/subdir.mk
-include APP/subdir.mk
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

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := SMART_HOME
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
SMART_HOME.lss \

FLASH_IMAGE += \
SMART_HOME.hex \

EEPROM_IMAGE += \
SMART_HOME.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: main-build

# Main-build Target
main-build: SMART_HOME.elf secondary-outputs

# Tool invocations
SMART_HOME.elf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,SMART_HOME.map -mmcu=atmega32 -o "SMART_HOME.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

SMART_HOME.lss: SMART_HOME.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S SMART_HOME.elf  >"SMART_HOME.lss"
	@echo 'Finished building: $@'
	@echo ' '

SMART_HOME.hex: SMART_HOME.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex SMART_HOME.elf  "SMART_HOME.hex"
	@echo 'Finished building: $@'
	@echo ' '

SMART_HOME.eep: SMART_HOME.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex SMART_HOME.elf  "SMART_HOME.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: SMART_HOME.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 SMART_HOME.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) SMART_HOME.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents main-build

-include ../makefile.targets
