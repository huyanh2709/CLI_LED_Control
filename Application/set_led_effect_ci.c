/*
 * set_led_effect_ci.c
 *
 *  Created on: Apr 5, 2024
 *      Author: phamh
 */


#include "set_led_effect_ci.h"

void set_led_effect(char **argv, uint8_t argv_idx)
{
	//nếu có ít hơn 3 thành phần trong lệnh nhập vào
	if(argv_idx < 3)
	{
		response_print("not enough arguments");
		return;
	}
	//nếu có nhiều hơn 2 thành phần trong lệnh nhập vào
	else if (argv_idx > 3)
	{
		response_print("too many arguments");
		return;
	}
	//đủ 2 thành phần
	else
	{
		//đổi chuỗi argv[1] (số chỉ hiệu ứng led) thành int để set led effect
		uint8_t led_effect_code = atoi(argv[1]);
		uint16_t freq = atoi(argv[2]);
		switch(led_effect_code)
		{
			case 1: // blink
				led_effect_blink(freq);
				break;
			case 2: //light up
				led_effect_lightup_1by1(freq);
				break;
			default:
				response_print("LED code not defined yet");
				break;

		}
	}

}

