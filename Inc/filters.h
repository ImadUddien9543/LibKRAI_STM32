/*
 * filters.h
 *
 *  Created on: Oct 21, 2024
 *      Author: Imaduddien
 */

#ifndef INC_FILTERS_H_
#define INC_FILTERS_H_

#include "stm32f4xx_hal.h"
#include "stdint.h"
#include "stdlib.h"
#include "stdbool.h"

#ifdef __cplusplus
extern "C" {
#endif


typedef struct {
	float alpha, beta;
	float now_output, prev_ouput;
	uint32_t start_time, last_time, delta_time, sample_time;
} Filter_t;

void init_LowPass(filter *f, float alpha, float sample_time);
float get_LowPass(filter *f, float input);

#ifdef __cplusplus
}
#endif

#endif /* INC_FILTERS_H_ */
