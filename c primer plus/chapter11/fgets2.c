#include <stdio.h>
#define LENGTH 10

int main(void){

    char words[LENGTH];
    char* input;

    while ((input = fgets(words, LENGTH,stdin)) != NULL && words[0] != '\n')
    {

        int i = 0;

        while (words[i] != '\n' && words[i] != '\0')
           i++;

        if(words[i] == '\n')
            words[i] = '\0';
        else
            while (getchar() != '\n')
                continue;         
        fputs(words, stdout);
    }

    printf("%s --  %s",input, words);

    puts("Done!");
    

    return 0;
}