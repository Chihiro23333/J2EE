//简单使用scanf
#include <stdio.h>
int main(void)
{
    int age;
    float assets;
    char pet[30];

    printf("please input your age, assets, pet:\n");
    scanf("%d%f",&age, &assets);
    scanf("%s", pet);
    printf("age=%d, assets=%.2f,pet=%s", age, assets,pet);

    return 0;
}