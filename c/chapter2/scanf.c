#include<stdio.h>
int main(){
	
	char first_name[20];
	char last_name[20];
	printf("please input name:");
	scanf("%19s %19s", first_name, last_name);
	//fgets(first_name, sizeof(first_name), stdin);
	//fgets(last_name, sizeof(last_name), stdin);
	printf("first name:%s,last name:%s", first_name, last_name);
	
	return 0;
}