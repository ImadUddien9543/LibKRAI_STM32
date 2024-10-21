/*
 * filters.c
 *
 *  Created on: Oct 21, 2024
 *      Author: Imaduddien
 */

#include "filters.h"

/*
 *  	@brief	: Function of low pass filter.
 *		@note	: call this function in int main() before while-loop
 *		@param	:
 * 			@arg *f				: filter_t instances
 * 			@arg alpha			: alpha constant of LPF in float
 *			@arg sample time	: sample time of LPF in uint32_t
 * */
void init_LowPass(filter *f, float alpha, uint32_t sample_time){
	f->alpha = alpha;
	f->beta = (1 - alpha);
	f->sample_time = sample_time;
}

/*
 *  	@brief	: Function of low pass filter.
 *		@note	: this function returns low pass calculation in float.
 *		@param	:
 * 			@arg *f			: filter_t instances
 * 			@arg input		: input in float
 * */

float get_LowPass (filter *f, float input){
	f->start_time = HAL_GetTick();
	f->delta_time = f->start_time - f->last_time;
	if(f->delta_time >= f->sample_time){
		f->now_output = (f->alpha * input) + (f->beta * f->prev_output);
		f->prev_output = f->now_output;
		f->last_time = f->start_time
	}
	return f->now_output;
}
