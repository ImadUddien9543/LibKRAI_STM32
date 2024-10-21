/*
 * math_formula.c
 *
 *  Created on: Oct 18, 2024
 *      Author: Imaduddien
 */

#include "math_formula.h"

const uint16_t Max_10_bitVal = 1023;
const uint16_t Max_12_bitVal = 4095;
const uint16_t Max_16_bitVal = 65535;

static uint16_t LinearInterp(uint16_t x, uint16_t inMin, uint16_t inMax, uint16_t outMin, uint16_t outMax);
/*
 *  @brief	: Function to help generate LUT points.
 * 	@note	: Call this function in int main() before while-loop.
 * 	@param	:
 * 			@arg *arr		: Blank array to be generated with LUT
 * 			@arg lut_points	: Amount of points in LUT (pass the macro of POINTS for this arg)
 * 			@arg max_val	: maximum value of LUT (pass the const value of
 * */

void Generate_LUT(uint16_t *lut, uint16_t lut_points, uint16_t max_val){
	for(int i = 0; i < lut_points; i++){
		lut[i] = (uint16_t)((i * max_val) / (lut_points - 1));
	}
}

/*
 *  @brief	: Linear interpolation static function.
 * 	@note	: To help interpolate values when LinearInterpLUT() is called.
 * 	@param	:
 * 			@arg x		: input value
 * 			@arg inMin	: minimum input value
 * 			@arg inMax	: maximum input value
 * 			@arg outMin	: minimum output value
 * 			@arg outMax	: maximum output value
 * */
static uint16_t LinearInterp(uint16_t x, uint16_t inMin, uint16_t inMax, uint16_t outMin, uint16_t outMax){
	return (uint16_t) (outMax + ((x - inMin) * (outMax - outMin) / (inMax - inMin)));
}

/*
 *  @brief	: A linear interpolation using LUT for better processing speed
 * 	@note	: make sure the arguments are in uint16_t. Mostly used in peripherals
 * 	@param	:
 * 			@arg inputVal		: input value
 * 			@arg *arr_1			: 1st LUT as input
 * 			@arg arr_size_1		: 1st LUT len (use ARRAY_LEN() macro for this arg)
 * 			@arg *arr_2			: 2nd LUT as output
 * 			@arg arr_size_2		: 2nd LUT len (use ARRAY_LEN() macro for this arg)
 * */

uint16_t LinearInterp_LUT(uint16_t inputVal, uint16_t *arr_1, uint16_t arr_size_1, uint16_t *arr_2, uint16_t arr_size_2){
	if(inputVal <= arr_1[0]) return arr_2[0];
	else if(inputVal >= arr_1[arr_size_1 - 1]) return arr_2[arr_size_2 - 1];  //array starts with 0
	else {
		for (int point = 0; point < arr_size_1; point++){
			if(inputVal >= arr_1[point] && inputVal <= arr_1[point+1]){
				return LinearInterp(inputVal, arr_1[point], arr_1[point+1], arr_2[point], arr_2[point+1]);
			}
		}
	}
	return 0;
}
