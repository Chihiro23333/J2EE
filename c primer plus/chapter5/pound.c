//定义一个带参数的函数
#include <stdio.h>

void pound(int n);

int main(void)
{
    int n = 10;
    char m = '!';
    float x = 6.667;

    pound(n);
     pound(m);
      pound(x);

    return 0;
}

void pound(int n)
{
    while (n-- > 0)
    {
       printf("n=%d", n);
    }
    printf("\n");
}