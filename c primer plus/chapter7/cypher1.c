//getchar() putchar()
#include <stdio.h>
#include <ctype.h>
#define SPACE ' '
int main(void)
{

    char ch;

    ch = getchar();
    while (ch != '\n')
    {
       if(isblank(ch))
       {
           putchar(ch);
       }else
       {
           putchar(toupper(ch+1));
       }

       ch = getchar();
       
    }
    

    return 0;
}