/*
 * cli_types.h
 *
 *  Created on: Mar 28, 2024
 *      Author: phamh
 */

#ifndef CLI_TYPES_H_
#define CLI_TYPES_H_

#include "stm32f1xx_hal.h"
#include "stdint.h"

//khai báo con trỏ hàm
//typedef output_type (* func_pointer_name)(variable types,...)
typedef void (* cli_command_func_t) (char **argv, uint8_t argv_idx);

//tạo struct command_info hàm bao gồm cú pháp - chức năng (help) và con trỏ hàm (command_func)
typedef struct{
	cli_command_func_t function;
	char  *help;
}cli_command_info_t;

//tạo struct command_entry gồm tên hàm (để tìm hàm) và command_info
typedef struct{
	const char  *name;
	const cli_command_info_t *command_info;
}cli_command_entry_t;

#endif /* CLI_TYPES_H_ */
