#include <stdio.h>
#include "hotel.h"

int menu(void){

    int code,status;

    printf("\n%s%s\n", STAR, STAR);
    printf("enter your choice:\n");
    printf("1) one           2)two\n");
    printf("3)three          4)four\n");
    printf("5)Quit!\n");
    printf("\n%s%s\n", STAR, STAR);


    while ((status = scanf("%d",&code)) != 1 || (code < 1 || code > 5))
    {
        if(status != 1)
            scanf("%*s");
        printf("enter 1-5, ok?status = %d, code=%d\n",status);
    }

    printf("code=%d\n",code);

    return code;
}

int getNights(void){

    int nights;

    printf("\n%s%s\n", STAR, STAR);
    printf("how many nights you want:\n");
    printf("\n%s%s\n", STAR, STAR);
    while (scanf("%d", &nights) != 1)
    {
        scanf("%*s");
        printf("enter integer, ok?\n");
    }

    printf("nights=%d",nights);
    return nights;
}

void showPrice(double rate, int nights){
    int i;
    double total=0.0;
    double factor = 1.0;

    printf("rate=%f, nights=%d\n",rate,nights);

    for(i = 1; i <= nights; i++, factor *= DISCOUNT){
        total += rate * factor;
    }

    printf("\n%s%s\n", STAR, STAR); 
    printf("showPrice=%f",total);
    printf("\n%s%s\n", STAR, STAR);
}
