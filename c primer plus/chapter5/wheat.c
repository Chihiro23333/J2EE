//指数增长
#include <stdio.h>
#define ALL 64
int main()
{

    const double CROP = 2E16;
    float current, total;
    int count = 1;

    printf("count       added       total       ");
    printf("fraction of\n");
    printf("count       grains       grains       ");
    printf("world total\n");
    current = total = 1.0;
    while (count <= ALL)
    {
        printf("%d      %.2e      %.2e      %.2e\n",count, current, total, total/CROP);
        count++;
        current = 2 * current;
        total = total + current;
    }
    
    printf("Done!\n");

    return 0;
}