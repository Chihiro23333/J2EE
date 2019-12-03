#include <stdio.h>
#include "string.h"
#include "find.h"

int NUM_ADS = 7;
char *ADS[] = {
	"AB",
	"B",
	"CD",
	"D",
	"E",
	"F",
	"G",
};

char* find(int(*match)(char*)){
	int i;
	for(i = 0; i< NUM_ADS; i++){
		if(match(ADS[i])){
			printf("%s\n", ADS[i]);
		}
	}
}

int match(char *matchstr){
	return strstr(matchstr, "A") && strstr(matchstr,"B");
}

int matchCOrD(char *matchstr){
	return strstr(matchstr, "C") || strstr(matchstr,"D");
}

int main(){
	
	find(match);
	
	find(matchCOrD);
	
	return 0;
}