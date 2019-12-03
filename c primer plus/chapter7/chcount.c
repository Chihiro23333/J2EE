#include <stdio.h>
#define POINT '.'
int main(void)
{

    int charcount = 0;
    char ch;

    printf("enter str to count:\n");
    while ((ch = getchar()) != POINT)
    {
       if(ch != '"' && ch != '\'')
       {
           charcount++;
       }
    }
    
    printf("charcount=%d", charcount);

    return 0;
}