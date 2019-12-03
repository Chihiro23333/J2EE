#include <stdio.h>
#include <stdlib.h>


int sort(const void *a , const void *b){
	return *(int*)a - *(int*)b;
}

int main(){
	int arr[] = {1,5,2,9,4,6};
	
	qsort(arr,6,sizeof(int),sort);
	
	for(int i = 0; i < 6;i++){
		printf("%i",arr[i]);
	}
	
	return 0;
}