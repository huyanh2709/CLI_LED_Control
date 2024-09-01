/*
 * led_driver.c
 *
 *  Created on: Apr 1, 2024
 *      Author: phamh
 */

#include "led_driver.h"

//Tắt bật led
void led_driver_set_led(uint8_t index, uint8_t state)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0 << index, (GPIO_PinState)state);
}

//toggle led
void led_driver_toggle_led(uint8_t index)
{
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_0 << index);
}

//Tắt bật tất cả led
void led_driver_set_all_led(uint8_t state)
{
	for(int i = 0; i<8 ;i++)
	{
		led_driver_set_led(i, state);
	}
}

void led_driver_init()
{

}
