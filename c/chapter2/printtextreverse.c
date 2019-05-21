#include<stdio.h>
#include<string.h>

void printReverse(char text[]){
	
	char *last = text + strlen(text);
	
	while(last >= text){
		printf("%c", *last);
		last = last - 1;
	}
	puts("");
}

int main(){
	char input[10];
	fgets(input, sizeof(input), stdin);
	printReverse(input);
	return 0;
}