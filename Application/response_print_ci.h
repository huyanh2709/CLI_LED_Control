/*
 * response_print_ci.h
 *
 *  Created on: Mar 27, 2024
 *      Author: phamh
 */

#ifndef RESPONSE_PRINT_CI_H_
#define RESPONSE_PRINT_CI_H_

#include "stm32f1xx_hal.h"
#include "string.h"
#include "stdio.h"
#include "stdarg.h"

void response_print(const char *str,...);

void response_uart_init(UART_HandleTypeDef *huart);

#endif /* RESPONSE_PRINT_CI_H_ */
