/*
 * cli_command_table.c
 *
 *  Created on: Mar 28, 2024
 *      Author: phamh
 */

#include "cli_command_table.h"

//tạo biến command_info cho các hàm khác nhau, bao gồm con trỏ trỏ tới hàm thực thi
//-> gọi hàm thông qua con trỏ hàm trong  struct command_info
const cli_command_info_t command_info_getTemp = {
		get_temp,
		"<gettemp> <channel>: get temperature from LM35"
};

const cli_command_info_t command_info_setTempMax = {
		setTempeartureMax,
		"<settempmax> <temperature>: set max temperature"
};

const cli_command_info_t command_info_setTempMin = {
		setTempeartureMin,
		"<settempmin> <temperature>: set min temperature"
};

const cli_command_info_t command_info_setLed = {
		set_led_effect,
		"<setled> <LedCode> <frequency>: set led effect & frequency"
};


//tạo 1 mảng các struct command_entry để lưu các thông tin của tập lệnh
//kết thúc = NULL để có điểm dừng cho vòng lặp while khi duyệt tìm lệnh
const cli_command_entry_t command_entry_table[] =
{
		{"gettemp",&command_info_getTemp},
		{"settempmax",&command_info_setTempMax},
		{"settempmin",&command_info_setTempMin},
		{"setled",&command_info_setLed},
		{NULL, NULL}
};


