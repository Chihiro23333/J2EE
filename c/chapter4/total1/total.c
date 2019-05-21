#include <stdio.h>
#include "total.h"


float total;
int count;
short percent = 6;


int main(){
	float val = 0;
	printf("Price of item:");
	while(scanf("%f", &val) == 1){
		printf("Total so far:%f\n", calc(val));
		printf("Price of item:");
	}
	printf("Last total is:%f\n", total);
	printf("Last count is:%hi\n", count);
	
	return 0;
}

float calc(float f){
	float realpercnet = 1 + percent/100.0;
	count = count +1;
	total  = total + f * realpercnet;
	return total;
}