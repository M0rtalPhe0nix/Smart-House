################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/USER_MODE/USER_MODE.c 

OBJS += \
./APP/USER_MODE/USER_MODE.o 

C_DEPS += \
./APP/USER_MODE/USER_MODE.d 


# Each subdirectory must supply rules for building sources it contributes
APP/USER_MODE/%.o: ../APP/USER_MODE/%.c APP/USER_MODE/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


