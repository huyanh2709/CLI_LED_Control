/*
 * set_led_effect_ci.h
 *
 *  Created on: Apr 5, 2024
 *      Author: phamh
 */

#ifndef SET_LED_EFFECT_CI_H_
#define SET_LED_EFFECT_CI_H_

#include "stm32f1xx_hal.h"
#include "led_effect.h"
#include "response_print_ci.h"
#include "string.h"
#include "stdlib.h"

void set_led_effect(char **argv, uint8_t argv_idx);



#endif /* SET_LED_EFFECT_CI_H_ */
