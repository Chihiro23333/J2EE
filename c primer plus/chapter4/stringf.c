//字符串格式化
#include <stdio.h>
#define BLURD "Authentic imitation!"
int main(void)
{
    printf("[%s]\n", BLURD);
    printf("[%20s]\n",BLURD);
    printf("[%24.5s]\n", BLURD);
    printf("[%-24.5s]\n", BLURD);
    return 0;
}