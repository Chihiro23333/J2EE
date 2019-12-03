#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_LENGTH 40

int main(int argc, char *argv[]){

    FILE *in, *out;
    char name[NAME_LENGTH];
    int c;

    if(argc < 2){
        fprintf(stderr,"argc least 2");
        exit(EXIT_FAILURE);
    }

    if((in = fopen(argv[1],"r")) == NULL){
        fprintf(stderr,"open file:%s error",argv[1]);
        exit(EXIT_FAILURE);
    }

    strncpy(name, argv[1], NAME_LENGTH -5);
    name[NAME_LENGTH -5] = '\0';
    strcat(name,".red");

    if((out = fopen(name,"w")) ==NULL){
        fprintf(stderr, "cant create file:%s", name);
        exit(EXIT_FAILURE);
    }

    while ((c = getc(in)) != EOF)
    {
        putc(c, out);
    }

    if(fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr," Error in closing files\n");

    printf("Done!");
    
    return 0;
}