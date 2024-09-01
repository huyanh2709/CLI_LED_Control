/*
 * get_temp_ci.c
 *
 *  Created on: Mar 28, 2024
 *      Author: phamh
 */

#include "get_temp_ci.h"

void get_temp(char **argv, uint8_t argv_idx)
{
	//nếu có ít hơn 2 thành phần trong lệnh nhập vào
	if(argv_idx < 2)
	{
		response_print("not enough arguments");
		return;
	}
	//nếu có nhiều hơn 2 thành phần trong lệnh nhập vào
	else if (argv_idx > 2)
	{
		response_print("too many arguments");
		return;
	}
	//đủ 2 thành phần
	else
	{
		//đổi chuỗi argv[1] (số kênh) thành int để lấy nhiệt độ
		uint8_t channel = atoi(argv[1]);
		response_print("temperature = %f", LM35_Gettemp(channel));
	}
}



