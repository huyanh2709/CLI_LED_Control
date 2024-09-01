/*
 * uart.c
 *
 *  Created on: Mar 27, 2024
 *      Author: phamh
 */

#include "uart.h"

#define UART_BUFF_MAX_LEN 100

//tạo buffer gồm 100 byte chứa kí tự
char uartBuff[UART_BUFF_MAX_LEN];
static uint8_t uart_len = 0;
uint8_t  uartFlag = 0;

//hàm ghi dữ liệu nhận qua UART vào buffer
void uart_Rxdata_receive(uint8_t data_rx)
{
	if(data_rx == '\n')
	{
		uartBuff[uart_len] = '\0';
		uartFlag = 1;
	}
	else
	{
		uartBuff[uart_len++] = data_rx;
	}

}

//hàm xử lí dữ liệu lưu trong buffer
void uart_Rxdata_handle()
{
	if(uartFlag == 1)
	{
		cli_command_execute(uartBuff, uart_len);
		uartFlag = 0;
		uart_len = 0;
	}
}
