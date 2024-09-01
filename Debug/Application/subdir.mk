################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/LM35.c \
../Application/cli_command.c \
../Application/cli_command_table.c \
../Application/cli_types.c \
../Application/get_temp_ci.c \
../Application/response_print_ci.c \
../Application/set_led_effect_ci.c \
../Application/set_tempt_ci.c \
../Application/uart.c 

OBJS += \
./Application/LM35.o \
./Application/cli_command.o \
./Application/cli_command_table.o \
./Application/cli_types.o \
./Application/get_temp_ci.o \
./Application/response_print_ci.o \
./Application/set_led_effect_ci.o \
./Application/set_tempt_ci.o \
./Application/uart.o 

C_DEPS += \
./Application/LM35.d \
./Application/cli_command.d \
./Application/cli_command_table.d \
./Application/cli_types.d \
./Application/get_temp_ci.d \
./Application/response_print_ci.d \
./Application/set_led_effect_ci.d \
./Application/set_tempt_ci.d \
./Application/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Application/%.o Application/%.su Application/%.cyclo: ../Application/%.c Application/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/STM32 cube/stm32f1_register/UART_CLI/Application" -I"D:/STM32 cube/stm32f1_register/UART_CLI/Application/LED" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Application

clean-Application:
	-$(RM) ./Application/LM35.cyclo ./Application/LM35.d ./Application/LM35.o ./Application/LM35.su ./Application/cli_command.cyclo ./Application/cli_command.d ./Application/cli_command.o ./Application/cli_command.su ./Application/cli_command_table.cyclo ./Application/cli_command_table.d ./Application/cli_command_table.o ./Application/cli_command_table.su ./Application/cli_types.cyclo ./Application/cli_types.d ./Application/cli_types.o ./Application/cli_types.su ./Application/get_temp_ci.cyclo ./Application/get_temp_ci.d ./Application/get_temp_ci.o ./Application/get_temp_ci.su ./Application/response_print_ci.cyclo ./Application/response_print_ci.d ./Application/response_print_ci.o ./Application/response_print_ci.su ./Application/set_led_effect_ci.cyclo ./Application/set_led_effect_ci.d ./Application/set_led_effect_ci.o ./Application/set_led_effect_ci.su ./Application/set_tempt_ci.cyclo ./Application/set_tempt_ci.d ./Application/set_tempt_ci.o ./Application/set_tempt_ci.su ./Application/uart.cyclo ./Application/uart.d ./Application/uart.o ./Application/uart.su

.PHONY: clean-Application

