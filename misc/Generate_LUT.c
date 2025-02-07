#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/*
  This is a file to generate LUT points for Linear Interpolation using LUT method
*/

#define LUT_POINTS 2048 //values of LUT points

const uint16_t MAX_12BIT_VAL = 4095;
const uint16_t MAX_16BIT_VAL = 65535;

uint16_t LUT_12BIT[LUT_POINTS];
uint16_t LUT_16BIT[LUT_POINTS];

int main(int argc, char const *argv[])
{
	for(int i = 0; i < LUT_POINTS; i++){
		LUT_12BIT[i] = (uint16_t)((i * MAX_12BIT_VAL) / (LUT_POINTS - 1));
		// printf("LUT_12BIT[i] = %d\n", LUT_12BIT[i]);
    // printf("%d, ", LUT_12BIT[i]);
	}

	for(int j = 0; j < LUT_POINTS; j++){
		LUT_16BIT[j] = (uint16_t)((j * MAX_16BIT_VAL) / (LUT_POINTS - 1));
		// printf("LUT_16BIT[%d] = %d\n",j, LUT_16BIT[j]);
    // printf("%d, ", LUT_16BIT[i]);
	}
	return 0;
}
