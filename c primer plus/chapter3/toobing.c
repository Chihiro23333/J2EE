#include <stdio.h>

int main()
{
    int i = 2147483647;
    unsigned int j = 4294967295;

    printf("i = %d, i+1= %d, i-1 = %d", i, i+1, i-1);
     printf("j = %u, j+1= %u, j-1 = %u", j, j+1, j-1);

    return 0;
}