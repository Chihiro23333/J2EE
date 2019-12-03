#include <stdio.h>
#include <string.h>
#define DENSITY 62.4

int main(void)
{
    float weight, volume;
    int size, letters;
    char name[40];

    printf("hi, please enter you name\n");
    scanf("%s", name);
    printf("%s hi! well, please enter you weight\n", name);
    scanf("%f", &weight);
    size = sizeof(name);
    letters = strlen(name);
    volume = weight/DENSITY;

    printf("haha,your weight is %.2f, volume=%2.2f\n", weight, volume);
    printf("size=%d, letters=%d", size, letters);

    return 0;
}