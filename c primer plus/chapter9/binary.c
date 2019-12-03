#include <stdio.h>

void toBinary(unsigned long n);

int main(void){

    int num;

    while (scanf("%lu", &num) == 1)
    {
        toBinary(num);
        printf("\n");
    }

    printf("Bye\n");
    

    return 0;
}

void toBinary(unsigned long n){
    int r;

    r = n % 2;
    if(n >= 2)
        toBinary(n/2);
    printf("%d",r);
}