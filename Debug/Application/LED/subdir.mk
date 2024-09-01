################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/LED/led_driver.c \
../Application/LED/led_effect.c 

OBJS += \
./Application/LED/led_driver.o \
./Application/LED/led_effect.o 

C_DEPS += \
./Application/LED/led_driver.d \
./Application/LED/led_effect.d 


# Each subdirectory must supply rules for building sources it contributes
Application/LED/%.o Application/LED/%.su Application/LED/%.cyclo: ../Application/LED/%.c Application/LED/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/STM32 cube/stm32f1_register/UART_CLI/Application" -I"D:/STM32 cube/stm32f1_register/UART_CLI/Application/LED" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Application-2f-LED

clean-Application-2f-LED:
	-$(RM) ./Application/LED/led_driver.cyclo ./Application/LED/led_driver.d ./Application/LED/led_driver.o ./Application/LED/led_driver.su ./Application/LED/led_effect.cyclo ./Application/LED/led_effect.d ./Application/LED/led_effect.o ./Application/LED/led_effect.su

.PHONY: clean-Application-2f-LED

