#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	printf("dinner is %s\n", argv[1]);
	printf("Juice:%s", getenv("JUICE"));
	return 0;
}