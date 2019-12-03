#include <stdio.h>
#define PARISE "your are a nice man!"
int main(void)
{

    char name[40];
    
    printf("please you name:\n");
    scanf("%s", name);
    printf("haha, %s ,%s", name, PARISE);

    return 0;
}