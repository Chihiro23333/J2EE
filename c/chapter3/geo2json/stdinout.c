#include<stdio.h>

int main(){
	int lan;
	int lon;
	char speed[80];
	int start = 0;
	puts("data=[");
	while(scanf("%i,%i,%79[^\n]", &lan, &lon, speed) == 3){
		if(start){
			printf(",\n");
		}else{
			start = 1;
		}
		if(lan < -90 || lan > 90){
			fprintf(stderr,"Invalid lan:%i", lan);
			return 2;
		}
		printf("{latitude:%i,longtitude:%i,info:'speed=%s'}", lan, lon, speed);
	}
	puts("\n]");
	return 0;
}