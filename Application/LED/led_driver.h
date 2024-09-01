/*
 * led_driver.h
 *
 *  Created on: Apr 1, 2024
 *      Author: phamh
 */

#ifndef LED_LED_DRIVER_H_
#define LED_LED_DRIVER_H_

#include "stm32f1xx_hal.h"

//Tắt bật led
void led_driver_set_led(uint8_t index, uint8_t state);

//toggle led
void led_driver_toggle_led(uint8_t index);


//Tắt bật tất cả led
void led_driver_set_all_led(uint8_t state);

void led_driver_init();


#endif /* LED_LED_DRIVER_H_ */
