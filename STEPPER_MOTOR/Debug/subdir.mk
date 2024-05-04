################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_programm.c \
../LCD_progarmm.c \
../keypad_programm.c \
../stepper_programm.c \
../stetpper_motor.c 

OBJS += \
./DIO_programm.o \
./LCD_progarmm.o \
./keypad_programm.o \
./stepper_programm.o \
./stetpper_motor.o 

C_DEPS += \
./DIO_programm.d \
./LCD_progarmm.d \
./keypad_programm.d \
./stepper_programm.d \
./stetpper_motor.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


