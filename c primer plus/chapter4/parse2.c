#include <stdio.h>
#include <string.h>
#define PARSE "your are a good man!"
int main()
{

    char name[40];
    printf("please enter you name:\n");
    scanf("%s", name);
    printf("ok,%s,your name sizeof=%u, letters=%u\n",name, sizeof(name), strlen(name));
    printf("PARSE sizeof=%u, letters=%u", sizeof(PARSE), strlen(PARSE));

    return 0;
}