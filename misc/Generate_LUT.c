#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/*
  This is a file to generate LUT points for Linear Interpolation using LUT method
*/

#define LUT_POINTS_12BIT 24
#define LUT_POINTS_16BIT 64

const uint16_t MAX_12BIT_VAL = 4095;
const uint16_t MAX_16BIT_VAL = 65535;

uint16_t LUT_12BIT[LUT_POINTS_12BIT];
uint16_t LUT_16BIT[LUT_POINTS_16BIT];

int main(int argc, char const *argv[])
{
	for(int i = 0; i < LUT_POINTS_12BIT; i++){
		LUT_12BIT[i] = (uint16_t)((i * MAX_12BIT_VAL) / (LUT_POINTS_12BIT - 1));
		// printf("LUT_12BIT[i] = %d\n", LUT_12BIT[i]);
    // printf("%d, ", LUT_12BIT[i]);
	}

	for(int j = 0; j < LUT_POINTS_16BIT; j++){
		LUT_16BIT[j] = (uint16_t)((j * MAX_16BIT_VAL) / (LUT_POINTS_16BIT - 1));
		// printf("LUT_16BIT[%d] = %d\n",j, LUT_16BIT[j]);
    // printf("%d, ", LUT_16BIT[i]);
	}
	return 0;
}
