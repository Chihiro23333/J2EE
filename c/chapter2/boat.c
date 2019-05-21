#include<stdio.h>

void go_north_east(int* lat, int* lon){
	*lat = *lat + 1;
	*lon = *lon + 1;
}

int main(){
	
	int lat = 30;
	int lon = 30;
	
	go_north_east(&lat, &lon);
	
	printf("位置是[%i,%i]",lat, lon);
	
	return 0;
}

