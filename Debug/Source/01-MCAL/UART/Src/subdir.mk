################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Source/01-MCAL/UART/Src/UART.c 

OBJS += \
./Source/01-MCAL/UART/Src/UART.o 

C_DEPS += \
./Source/01-MCAL/UART/Src/UART.d 


# Each subdirectory must supply rules for building sources it contributes
Source/01-MCAL/UART/Src/%.o: ../Source/01-MCAL/UART/Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\updated\Oct21_Embedded-master\Source\02-ECUA\Buzzer\inc" -I"D:\updated\Oct21_Embedded-master\Source\01-MCAL\SPI\Inc" -I"D:\updated\Oct21_Embedded-master\Source\02-ECUA\EEPROM24C16\Inc" -I"D:\updated\Oct21_Embedded-master\Source\01-MCAL\I2C\Inc" -I"D:\updated\Oct21_Embedded-master\Source\01-MCAL\UART\Inc" -I"D:\updated\Oct21_Embedded-master\Source\02-ECUA\DC_Motor\Inc" -I"D:\updated\Oct21_Embedded-master\Source\01-MCAL\Timer0\Inc" -I"D:\updated\Oct21_Embedded-master\Source\02-ECUA\LM35\Inc" -I"D:\updated\Oct21_Embedded-master\Source\01-MCAL\ADC\Inc" -I"D:\updated\Oct21_Embedded-master\Source\01-MCAL\EXINT\Inc" -I"D:\updated\Oct21_Embedded-master\Source\01-MCAL\GINT\Inc" -I"D:\updated\Oct21_Embedded-master\Source\02-ECUA\Keypad\Inc" -I"D:\updated\Oct21_Embedded-master\Source\02-ECUA\LCD\Inc" -I"D:\updated\Oct21_Embedded-master\Source\02-ECUA\SSD\Inc" -I"D:\updated\Oct21_Embedded-master\Source\02-ECUA\Buzzer\inc" -I"D:\updated\Oct21_Embedded-master\Source\00-Lib" -I"D:\updated\Oct21_Embedded-master\Source\01-MCAL\Dio\Inc" -I"D:\updated\Oct21_Embedded-master\Source\02-ECUA\Button\Inc" -I"D:\updated\Oct21_Embedded-master\Source\02-ECUA\Led\Inc" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


