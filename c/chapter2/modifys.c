#include<stdio.h>

int main(){
	
	char *a[] = {"abcdef"};
	printf("%s\n" ,a[0]);
	a[0] ="ssss";
	printf("%s\n" ,a[0]);
	return 0;
}