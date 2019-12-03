#include <stdio.h>
int main(void)
{

    float length, width;

     printf("enter length:\n");
    while (scanf("%f", &length) == 1)
    {
        printf("length = %f\n", length);
          printf("enter width\n");
        if(scanf("%f", &width) != 1) break;
        printf("width=%f\n", width);
        printf("area=%f\n",width * length);
    }
     printf("Done!\n");

    return 0;
}