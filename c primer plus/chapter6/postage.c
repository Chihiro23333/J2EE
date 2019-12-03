//for循环中使用逗号
#include <stdio.h>
int main(void)
{


    const int FIRST = 10;
    const int GAP = 10;
    int start, final;

    printf("start       final\n");
    for(start = FIRST, final = FIRST; start < 20; start++, final+= GAP)
    {
        printf("%5d     %5d\n", start, final);
    }

    return 0;
}