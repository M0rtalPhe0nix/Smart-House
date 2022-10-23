################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/ADMIN_MODE/ADMIN_MODE.c 

OBJS += \
./APP/ADMIN_MODE/ADMIN_MODE.o 

C_DEPS += \
./APP/ADMIN_MODE/ADMIN_MODE.d 


# Each subdirectory must supply rules for building sources it contributes
APP/ADMIN_MODE/%.o: ../APP/ADMIN_MODE/%.c APP/ADMIN_MODE/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


