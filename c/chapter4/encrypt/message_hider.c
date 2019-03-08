#include <stdio.h>
#include "encrypt.h"

int main(){
	char message[80];
	while(scanf("%s" ,message) == 1){
		encrypt(message);
		printf("%s\n",message);
	}
}