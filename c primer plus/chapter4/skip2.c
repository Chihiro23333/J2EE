//跳过输入中的两个整数
#include <stdio.h>
int main(void)
{
    int n;

    scanf("%*d %*d %d", &n);
    printf("\"n=%d\"\n", n);

    return 0;
}