/*
 * LM35.c
 *
 *  Created on: Mar 28, 2024
 *      Author: phamh
 */

#include "lm35.h"
float LM35_Gettemp(uint8_t channel)
{

//fake dữ liệu
	float temp =10;
	if(channel ==0) temp =20.5;
	if(channel ==1) temp =50.7;
	return temp;
}


