/*
 * math_formula.h
 *
 *  Created on: Oct 18, 2024
 *      Author: Imaduddien
 */

#ifndef INC_MATH_FORMULA_H_
#define INC_MATH_FORMULA_H_

#include "stm32f4xx_hal.h"
#include "stdint.h"
#include "math.h"
#include "stdlib.h"
#include "stdbool.h"

#ifdef __cplusplus
extern "C" {
#endif

#define ARRAY_LEN(ARR)			(sizeof(ARR) / sizeof(ARR[0]))
#define ARRAY_LAST_VAL(ARR)		ARR[sizeof(ARR) / sizeof(ARR[0]) - 1]

#define LUT_POINTS 512

/* Linear Interpolation with LUT variables*/
extern uint16_t LUT_10_BIT[LUT_POINTS];
extern uint16_t LUT_12_BIT[LUT_POINTS];
extern uint16_t LUT_16_BIT[LUT_POINTS];

extern const uint16_t Max_10_bitVal;
extern const uint16_t Max_12_bitVal;
extern const uint16_t Max_16_bitVal;

void Generate_LUT(uint16_t *lut, uint16_t lut_points, uint16_t max_val);
uint16_t LinearInterp_LUT(uint16_t inputVal, uint16_t *arr_1, uint16_t arr_size_1, uint16_t *arr_2, uint16_t arr_size_2);

#ifdef __cplusplus
}
#endif

#endif /* INC_MATH_FORMULA_H_ */
