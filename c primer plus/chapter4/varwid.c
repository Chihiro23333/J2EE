//使用变宽输入字段
#include <stdio.h>
int main(void)
{
    unsigned int width, precision;
    int number = 6000;
    float weight = 365.2356;

    printf("enter a width:\n");
    scanf("%d", &width);
    printf("number=%*d\n", width,number);
    scanf("%d%d",&width, &precision);
    printf("weight=%*.*f\n", width, precision, weight);

    return 0;
}