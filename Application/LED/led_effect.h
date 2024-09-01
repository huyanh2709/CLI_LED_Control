/*
 * led_effect.h
 *
 *  Created on: Apr 1, 2024
 *      Author: phamh
 */

#ifndef LED_LED_EFFECT_H_
#define LED_LED_EFFECT_H_

#include "stm32f1xx_hal.h"
#include "led_driver.h"

typedef enum{
	LED_EFFECT_IDLE,
	LED_EFFECT_BLINK,
	LED_EFECT_LIGHTUP_1BY1
}LedEffectName;

//tạo struct kết hợp union để lưu trữ các biến dùng cho các led effect
typedef struct{
//các biến dùng chung cho mọi effect
	uint32_t time_start;
	uint16_t frequency;
	LedEffectName led_effect_name;

//các biến dùng riêng cho từng effect -> dùng union để tiết kiệm bộ nhớ
//union chiếm bộ nhớ = thành phần chiếm bộ nhớ cao nhất. tuy nhiên chỉ sử dụng được 1 biến tại 1 thời điểm
	union{
		struct{
			uint8_t state;
		}blink;
		struct{
			uint8_t state;
			int8_t direction;
			int8_t idx;
		}lightup_1by1;
	}Effect;

}LedEffectState;

//thực hiện các trạng thái hiệu ứng led
void led_effect_execute();

//cách thời gian gọi hàm execute
void led_effect_handle();

//set các thông số cho trạng thái blink
void led_effect_blink(uint16_t freq);


//set các thông số cho trạng thái sáng dần
void led_effect_lightup_1by1(uint16_t freq);


void led_effect_init();

#endif /* LED_LED_EFFECT_H_ */
