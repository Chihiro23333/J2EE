
#include <stdio.h>
#include <hfcal.h>

void discaluli(float weight, float distance, float coeff){
	printf("you weight:%3.2fUS\n", weight);
	printf("you distance:%3.2fUS\n", distance);
	printf("you caluli:%4.2fUS\n", weight*distance*coeff);
}