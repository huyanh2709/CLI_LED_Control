/*
 * response_print_ci.c
 *
 *  Created on: Mar 27, 2024
 *      Author: phamh
 */

#include "response_print_ci.h"


static UART_HandleTypeDef *huart_print;

//hàm printf - truyền dữ liệu qua uart lên terminal
void response_print(const char *str,...)
{
//tạo mảng để lưu dữ liệu và chèn biến
	char stringArray[100];
//tạo đối tượng va_list
	va_list args;
//va_start với đối tg va_list và đối tượng truyền xác định cuối cùng
	va_start(args,str);
	vsprintf(stringArray,str,args);
//va_end với đối tượng va_list, nếu ko thì kết quả sẽ ko đc định nghĩa
	va_end(args);

//HAL_transmit để in lên terminal
	HAL_UART_Transmit(huart_print, (uint8_t *)stringArray, strlen(stringArray), 100);
}

//hàm init để chọn uart
void response_uart_init(UART_HandleTypeDef *_huart_print)
{
	huart_print = _huart_print;
}
