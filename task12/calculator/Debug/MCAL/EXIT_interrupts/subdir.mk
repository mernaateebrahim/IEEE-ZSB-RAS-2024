################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/EXIT_interrupts/EXIT_interrupts.c 

OBJS += \
./MCAL/EXIT_interrupts/EXIT_interrupts.o 

C_DEPS += \
./MCAL/EXIT_interrupts/EXIT_interrupts.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/EXIT_interrupts/%.o: ../MCAL/EXIT_interrupts/%.c MCAL/EXIT_interrupts/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


