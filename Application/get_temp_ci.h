/*
 * get_temp_ci.h
 *
 *  Created on: Mar 28, 2024
 *      Author: phamh
 */

#ifndef GET_TEMP_CI_H_
#define GET_TEMP_CI_H_

#include "stm32f1xx_hal.h"
#include "response_print_ci.h"
#include  "LM35.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"

void get_temp(char **argv, uint8_t argv_idx);

#endif /* GET_TEMP_CI_H_ */
