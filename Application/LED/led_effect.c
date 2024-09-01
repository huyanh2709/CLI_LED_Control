/*
 * led_effect.c
 *
 *  Created on: Apr 1, 2024
 *      Author: phamh
 */

#include "led_effect.h"

static LedEffectState led_effect_state;

//thực hiện các trạng thái hiệu ứng led
void led_effect_execute()
{
	switch(led_effect_state.led_effect_name)
	{
		case LED_EFFECT_BLINK:
			led_effect_state.Effect.blink.state = !led_effect_state.Effect.blink.state;
			led_driver_set_all_led(led_effect_state.Effect.blink.state);
			break;
		case LED_EFECT_LIGHTUP_1BY1:
			led_driver_set_led(led_effect_state.Effect.lightup_1by1.idx,led_effect_state.Effect.lightup_1by1.state);
			led_effect_state.Effect.lightup_1by1.idx += led_effect_state.Effect.lightup_1by1.direction;
			if(led_effect_state.Effect.lightup_1by1.idx > 7)
			{
				led_effect_state.Effect.lightup_1by1.direction = -1;
				led_effect_state.Effect.lightup_1by1.state =0;
				led_effect_state.Effect.lightup_1by1.idx += led_effect_state.Effect.lightup_1by1.direction;
			}
			else if(led_effect_state.Effect.lightup_1by1.idx < 0)
			{
				led_effect_state.Effect.lightup_1by1.direction = 1;
				led_effect_state.Effect.lightup_1by1.state = 1;
				led_effect_state.Effect.lightup_1by1.idx += led_effect_state.Effect.lightup_1by1.direction;
			}

			break;
		default: break;
	}
}

//cách thời gian gọi hàm execute
void led_effect_handle()
{
//Check for effect name
	if(led_effect_state.led_effect_name != LED_EFFECT_IDLE)
	{
		//nếu != idle thì cứ cách tgian = frequency thì gọi hàm execute để sáng/tắt led
		if(HAL_GetTick() - led_effect_state.time_start >= led_effect_state.frequency)
		{
			led_effect_execute();
			led_effect_state.time_start = HAL_GetTick();
		}
	}
}

//set các thông số cho trạng thái blink
void led_effect_blink(uint16_t freq)
{
	led_effect_state.led_effect_name = LED_EFFECT_BLINK;
	led_effect_state.frequency = freq;
	led_effect_state.Effect.blink.state = 0;
}

//set các thông số cho trạng thái sáng dần
void led_effect_lightup_1by1(uint16_t freq)
{
	led_effect_state.led_effect_name = LED_EFECT_LIGHTUP_1BY1;
	led_effect_state.frequency = freq;
	led_effect_state.Effect.lightup_1by1.idx = 0;
//bật theo chiều 0->7 thì direction = 1; tắt từ 7-> 0 thì direction = -1
	led_effect_state.Effect.lightup_1by1.direction = 1;
	led_effect_state.Effect.lightup_1by1.state = 1;
}

void led_effect_init()
{
	led_driver_init();
	led_effect_state.led_effect_name = LED_EFFECT_IDLE;
}
