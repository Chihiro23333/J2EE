#include<stdio.h>

int main(){
	float lat;
	float lon;
	char info[80];
	while(scanf("%f,%f,%79[^\n]",&lat ,&lon ,info) == 3){
		if((lat > -40) && (lat < 40) && (lon >-120) && (lon < 120)){
			printf("%.2f,%.2f,%s\n",lat ,lon ,info);
		}
	}
	return 0;
}