#include <stdio.h>
#define ROW 3
#define COLS 4

void sumRows(int arr[][COLS], int rows);

int sumClos(int arr[][COLS], int clos);

int sumAll(int arr[][COLS]);


int main(void){

    int arr[ROW][COLS] = {
        {1,2,3,-1},
        {4,5,6,0},
        {7,8,9,0}
    };

    sumRows(arr,ROW);
    sumClos(arr, COLS);
    sumAll(arr);

    return 0;
}


void sumRows(int arr[][COLS], int rows){
    int r;
    int c;
    int tot;

    for(r = 0; r< rows; r++){
        tot = 0;
        for(c = 0; c< COLS; c++)
            tot += arr[r][c];
        printf("row%dsum=%d\n",r,tot);
    }
}

int sumClos(int arr[][COLS], int clos){
    int r;
    int c;
    int tot;

    for(r = 0; r< clos; r++){
        tot = 0;
        for(c = 0; c< ROW; c++)
            tot += arr[c][r];
        printf("clos%dsum=%d\n",r,tot);
    }
}

int sumAll(int arr[][COLS]){
    int r;
    int c;
    int tot = 0;

    for(r = 0; r< ROW; r++){
        for(c = 0; c< COLS; c++)
            tot += arr[r][c];
    }
     printf("allsum=%d\n",tot);
}