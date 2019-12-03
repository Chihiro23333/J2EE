#include <stdio.h>

void swap(int* x, int* y);

int main(void){

    int x = 5;
    int y = 10;
    swap(&x, &y);
    printf("x=%d,y=%d",x,y);

    return 0;
}

void swap(int* x, int* y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp; 
}