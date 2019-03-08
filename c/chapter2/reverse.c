#include <stdio.h>
#include <string.h>

void reverse(char reverse[]){
	int len = strlen(reverse);
	int i = len - 1;
	while(i >= 0){
		printf("%c",reverse[i]);
		i -- ;
	}
}

int main(){
	puts("请输入要反转的文字:");
	char str[80];
	fgets(str ,80,stdin);
	reverse(str);
	return 0;
}