#include <stdio.h>

void put1(char *string);

int main(void){
    char str[] = "hahahahahaend";
    put1(str);
    return 0;
}

void put1(char *string){
    while (*string)
    {
        putchar(*string++);
    }
}