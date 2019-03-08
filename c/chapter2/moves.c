#include <stdio.h>

void go_south_east(int* lat ,int* lon){
		*lat = *lat - 1;
		*lon = *lon - 1;
	}

int main(){
	int lat = 64;
	int lon = 88;

	
	go_south_east(&lat ,&lon);
	
	printf("经纬度为=lat=%i---lon=%i",lat ,lon);
	
	return 0;
	
}