#include <stdio.h>
#define MSG "i am  define string."
#define MAX_LENGHT 18

int main(void){

    char str[MAX_LENGHT] = "i am a str!";
    const char *ptr = "i am a ptr str";

    puts(MSG);
    puts(str);
    puts(ptr);
    str[5] = 'A';
    puts(str);


    return 0;
}