//根据用户键入的值求和
#include <stdio.h>
int main(void)
{

    long sum = 1L;
    long num;
    int status;

    printf("enter a num:\n");
    status = scanf("%ld", &num);
    while(status = 1){
        sum = sum + num;
        printf("num=%ld, sum=%ld\n", num, sum);
        status = scanf("%ld", &num);
    }

    return 0;
}