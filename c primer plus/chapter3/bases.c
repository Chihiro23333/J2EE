#include <stdio.h>

int main()
{
    int x = 100; 

    printf("十进制=%d, 八进制=%o, 十六进制=%x\n", x, x, x);
     printf("十进制=%#d, 八进制=%#o, 十六进制=%#x", x, x, x);

     return 0;
}