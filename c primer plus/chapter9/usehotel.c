#include <stdio.h>
#include "hotel.h"

int main(void){

    int code;
    int nights;
    double rate;

    while ((code = menu()) != QUIT)
    {
        printf("code=%d\n",code);
       switch (code)
       {
        case 1:
            printf("case 1HOTEL1=%f\n",HOTEL1);
           rate = HOTEL1;
           break;
        case 2:
           rate = HOTEL2;
           break;
        case 3:
           rate = HOTEL3;
           break;
        case 4:
           rate = HOTEL4;
           break;
       default:
            rate = 0.0;
           break;
       }
       printf("rate=%f\n",rate);
        nights = getNights();
         printf("nights=%d\n",nights);
        showPrice(rate, nights);
    }

    printf("Bye！\n");
    return 0;
}