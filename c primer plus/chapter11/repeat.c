#include <stdio.h>

int main(int argc, char *argv[]){

    int i;

    printf("has %d argc:\n", argc-1);
    for(i = 1; i < argc; i++){
        printf("count:%d, argv:%s\n",i,argv[i]);
    }

    return 0;
}