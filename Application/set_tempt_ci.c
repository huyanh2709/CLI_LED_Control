/*
 * set_tempt_ci.c
 *
 *  Created on: Mar 29, 2024
 *      Author: phamh
 */

#include "set_tempt_ci.h"

void setTempeartureMax(char **argv,uint8_t argv_idx)
{
	if(argv_idx < 2)
	{
		response_print("not enough arguments");
		return;
	}
	else if (argv_idx > 2)
	{
		response_print("too many arguments");
		return;
	}
	else
	{
		response_print("Max temp set to %f",atof(argv[1]));
	}
}
void setTempeartureMin(char **argv,uint8_t argv_idx)
{
	if(argv_idx < 2)
	{
		response_print("not enough arguments");
		return;
	}
	else if (argv_idx > 2)
	{
		response_print("too many arguments");
		return;
	}
	else
	{
		response_print("Min temp set to %f",atof(argv[1]));
	}
}


