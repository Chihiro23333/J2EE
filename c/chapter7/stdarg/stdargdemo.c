#include <stdio.h>
#include <stdarg.h>
#include "stdargdemo.h"


void print_ints(int arg,...){
	va_list ap;
	va_start(ap, arg);
	
	for(int i =0; i < arg; i++){
		printf("arguements:%i\n", va_arg(ap, int));
	}
	
	va_end(ap);
}

int main(){
	
	print_ints(3, 123, 456 ,789);
	
	return 0;
}