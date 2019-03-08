#include <stdio.h>

int main(){
	float lat;
	float lon;
	char info[80];
	int started = 0;
	puts("[data=");
	while(scanf("%f,%f,%79[^\n]",&lat,&lon,info) == 3){
		if(started){
			printf(",\n");
		}else{
			started = 1;
			if((lat < -90.0) || (lat > 90.0)){
				fprintf(stderr,"invalid lat= %f\n",lat);
				return 2;
			}
			
			if((lon < -180.0) || (lon > 180.0)){
				fprintf(stderr,"invalid lon= %f\n",lon);
				return 2;
			}
		}
		printf("{lat:%.2f,lon:%.2f,info:%s}",lat,lon,info);
	}
	puts("\n]");
	return 0;
}