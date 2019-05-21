#include <stdio.h>
#include "encrypt.h"

int main(){
	char text[80];
	scanf("%79s", text);
	encrypt(text);
	printf("%s", text);
}

