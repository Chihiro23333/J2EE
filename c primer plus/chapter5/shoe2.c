//计算多个不同鞋码对应的脚长
#include <stdio.h>
#define ADJUST 7.3
int main(void)
{

    const double SCALE = 0.333;
    float shoe, foot;

    shoe = 3.0;
    while (shoe < 18.5)
    {
        foot = SCALE * shoe + ADJUST;
        printf("shoe = %-10.2ffoot=%-15.2f\n", shoe, foot);
        shoe = shoe + 1;
    }

    printf("Done!\n");
    
    return 0;
}