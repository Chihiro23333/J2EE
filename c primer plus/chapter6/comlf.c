#include <stdio.h>
#include <math.h>

int main(void)
{

    const double PI = 3.1415926;
    double input;

    scanf("%lf", &input);
    while (fabs(input - PI) > 0.0000001){
        printf("nonono\n");
    }
    printf("Done!\n");
    
    return 0;
}