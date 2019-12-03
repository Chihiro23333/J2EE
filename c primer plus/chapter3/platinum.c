#include <stdio.h>

int main()
{
    float weight;
    float value;

    printf("enter your weight:");

    scanf("%f", &weight);

    value = weight * 1700.0 *14.5833;

    printf("weight=%.2f, value = $%.2f", weight, value);

    return 0;
}