/*
 * cli_command.h
 *
 *  Created on: Mar 27, 2024
 *      Author: phamh
 */

#ifndef CLI_COMMAND_H_
#define CLI_COMMAND_H_

#include "stm32f1xx_hal.h"
#include "response_print_ci.h"
#include "get_temp_ci.h"
#include "set_tempt_ci.h"
#include "cli_command_table.h"

void cli_command_execute(char *uartBuff, uint8_t uart_len);

#endif /* CLI_COMMAND_H_ */
