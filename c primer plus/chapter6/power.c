//计算数的整数幂
#include <stdio.h>

double power(double x, int exp);

int main(void)
{

    double x;
    int exp;


    printf("enter two num:\n");
    while (scanf("%lf%d", &x, &exp) == 2)
    {
        printf("result=%g\n", power(x, exp));
    }
    

    return 0;
}

double power(double x, int exp)
{
    double pow = 1;
    int i;

    for(i = 0 ; i < exp ; i++)
    {
        pow *= x;
    }
    return pow;
}
