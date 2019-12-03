#include <stdio.h>
#include <stdarg.h>
#include "total.h"


float price(enum drink d){
	switch(d){
		case MIJIU:
		 return 2.3;
		case DOUJIANG:
		 return 6.6;
		case CHA:
		 return 1.5;
	}
	return 0;
}

float total(int arg,...){
	float total = 0;
	va_list pa;
	va_start(pa, arg);
	
	for(int i = 0; i < arg; i++){
		total += price(va_arg(pa, enum drink));
	}
	
	va_end(pa);
	
	return total;
}

int main(){
	
	printf("total=%f",total(3, MIJIU, DOUJIANG, CHA));
	
	return 0;
}