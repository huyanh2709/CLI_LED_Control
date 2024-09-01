/*
 * set_tempt_ci.h
 *
 *  Created on: Mar 29, 2024
 *      Author: phamh
 */

#ifndef SET_TEMPT_CI_H_
#define SET_TEMPT_CI_H_

#include "stm32f1xx_hal.h"
#include "response_print_ci.h"
#include "string.h"
#include "stdlib.h"

void setTempeartureMax(char **argv,uint8_t arg_num);

void setTempeartureMin(char **argv,uint8_t arg_num);



#endif /* SET_TEMPT_CI_H_ */
