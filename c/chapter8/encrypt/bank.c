#include <stdio.h>
#include <encrypt.h>
#include <checksum.h>

int main(){
	
	char str[] = "i love you baby!";
	
	encrypt(str);
	printf("encrypted:%s\n", str);
	printf("checksum:%i\n", checksum(str));
	
	encrypt(str);
	printf("discrypted:%s\n", str);
	printf("checksum:%i\n", checksum(str));
	
	return 0;
}