#include <stdio.h>
#include "totaler.h"

float total = 0.0;
short count = 0;
float tax_percent = 6;

int main(){
	int val;
	while(scanf("%i",&val) == 1){
		printf("total sofar =%.2f\n",add_with_tax(val));
	}
	
	printf("total=%.2f\n",total);
	printf("count=%hi\n"+count);
}

float add_with_tax(float money){
	total = total + money * (1 + tax_percent / 100);
	count = count++;
	return total;
}