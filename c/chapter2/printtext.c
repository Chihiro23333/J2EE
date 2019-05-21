#include<stdio.h>

void printText(char* msg){
	puts(msg+6);
}

int main(){
	char msg[] = "i want to fuck you!";
	printText(msg);
	return 0;
}