#include <stdio.h>

void func(void);

int main(void)
{
    printf("fun before\n");
    func();
    printf("fun after\n");

    return 0;
}

void func(void){
    printf("func execute\n");
}

