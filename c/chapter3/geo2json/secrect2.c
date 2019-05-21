#include<stdio.h>
int main(){
	
	char text[5];
	int i= 0;
	while(scanf("%4s", text) == 1){
		i+=1;
		if(i%3){
			fprintf(stdout, "%s\n", text);
		}else{
			fprintf(stderr, "%s\n", text);
		}
	}
	
	return 0;
}