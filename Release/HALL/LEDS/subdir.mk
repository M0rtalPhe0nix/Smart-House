################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HALL/LEDS/Leds.c 

OBJS += \
./HALL/LEDS/Leds.o 

C_DEPS += \
./HALL/LEDS/Leds.d 


# Each subdirectory must supply rules for building sources it contributes
HALL/LEDS/%.o: ../HALL/LEDS/%.c HALL/LEDS/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


