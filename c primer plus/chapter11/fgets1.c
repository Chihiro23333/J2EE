#include <stdio.h>
#define LENGTH 10

int main(void){

    char words[LENGTH];
    fgets(words,LENGTH,stdin);
    puts("print normal fgets()");
    puts(words);
    fputs(words, stdout);

    fgets(words,LENGTH, stdin);
    puts("print more words fgets()");
    puts(words);
    fputs(words, stdout);
    puts("Done!");

    return 0;
}