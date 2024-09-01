/*
 * cli_command.c
 *
 *  Created on: Mar 27, 2024
 *      Author: phamh
 */

#include "cli_command.h"

extern const cli_command_entry_t command_entry_table[];

static uint8_t help_flag = 0;

//hàm tìm lệnh truyền vào
const cli_command_info_t *find_command_info(char *cmd)
{
//con trỏ trỏ đến mảng các struct command_entry_table
	const cli_command_entry_t *command_entry_p = command_entry_table;
//nếu lệnh truyền vào ko phải lệnh help
	if(strcmp(cmd,"help") != 0)
	{
		//nếu tìm được tên lệnh trùng với lệnh nhập vào thì trả về con trỏ trỏ tới command_info của lệnh đó
		while(command_entry_p->command_info != NULL)
		{
			if(strcmp(cmd, command_entry_p->name)==0)
				return command_entry_p->command_info;
			else
				command_entry_p++;
		}
	}
//xử lí lệnh help
	else
	{
		help_flag = 1;
		//duyệt command_entry->command_info để in ra help (cú pháp + chức năng các hàm)
		while(command_entry_p->command_info != NULL)
		{

			response_print("%s \n",command_entry_p->command_info->help);
			command_entry_p++;
		}
	}
	//nếu không tìm được lệnh hoặc gọi hàm help thì trả về NULL
	return NULL;
}



//xử lí lệnh cli
void cli_command_execute(char *uartBuff, uint8_t uart_len)
{
//tạo mảng con trỏ để tách & lưu riêng các thành phần của lệnh theo dấu cách
	char *argv[10];
	uint8_t argv_idx = 0;

//dùng strtok để tách chuỗi theo dấu cách, gán với con mảng con trỏ đã tạo
//-> argv[0] sẽ là con trỏ trỏ tới tên lệnh
	char *pch = strtok(uartBuff," ");
	while(pch != NULL)
	{
		argv[argv_idx++] = pch;
		pch = strtok(NULL," ");
	}
//	for(uint8_t i = 0; i <argv_idx;i++)
//	{
//		response_print("%s \n",argv[i]);
//	}

//tạo con trỏ, gán với hàm tìm lệnh -> nếu tìm đc con trỏ trả vè trỏ tới command_info của lệnh đó
//									-> nếu không tìm được hoặc gọi lệnh help thì con trỏ trả về = NULL
	const cli_command_info_t *command_info = find_command_info(argv[0]);
	//nếu tìm được lệnh
	if(command_info != NULL)
	{
		//gọi hàm thực hiện lệnh thông qua con trỏ hàm trong command_info
		command_info->function(argv,argv_idx);
	}
	else
	{
		//nếu hàm help ko đc gọi & ko tìm đc lệnh
		if(help_flag == 0)
			response_print("command not found");
		//gọi hàm help
		else
			help_flag = 0;


	}
}


