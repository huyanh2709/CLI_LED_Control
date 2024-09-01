/*
 * uart.h
 *
 *  Created on: Mar 27, 2024
 *      Author: phamh
 */

#ifndef UART_H_
#define UART_H_

#include "stm32f1xx_hal.h"
#include "cli_command.h"

void uart_Rxdata_receive(uint8_t data_rx);

void uart_Rxdata_handle();


#endif /* UART_H_ */
