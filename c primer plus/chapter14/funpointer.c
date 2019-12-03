#include <stdio.h>
#include <ctype.h>

void testFun(void (*pf)(char *), char *str);

void toLower(char *);

int main(void){
    //错,指针指向常量区,字符串不可更改
    //char *str = "ABCDEF";
     char str[] = "ABCDEF";
    testFun(toLower,str);
    return 0;
}


void testFun(void (*pf)(char *), char *str){
    (*pf)(str);
    puts(str);
};

void toLower(char * str){
    while (*str)
    {
        *str = tolower(*str);
        str++;
    }
    
}