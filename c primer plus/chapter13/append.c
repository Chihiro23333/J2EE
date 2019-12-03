#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILE_NAME_LENGTH 20
#define BUFFERSIZE 4096

char* s_gets(char *name, int n);

void appendToDest(FILE *src, FILE *dest);

int main(void){

    FILE *fa, *fs;
    char appended[FILE_NAME_LENGTH];
    char append[FILE_NAME_LENGTH];
    int ch;


    printf("please enter appended filename:\n");
    s_gets(appended, FILE_NAME_LENGTH);

    if((fa = fopen(appended, "a+")) == NULL){
        printf("cant open file:%s\n",appended);
        exit(EXIT_FAILURE);
    }

    if(setvbuf(fa, NULL,_IOFBF, BUFFERSIZE) != 0){
         printf("cant create buffer to file:%s\n",appended);
        exit(EXIT_FAILURE);
    }

    puts("enter name to append filename:");
    while (s_gets(append, FILE_NAME_LENGTH) != 0 && append[0] != '\0')
    {
        if(strcmp(append, appended) == 0){
            fputs("cant append itself", stderr);
        }else if((fs = fopen(append, "r")) == NULL){
            fprintf(stderr,"cant open file:%s\n",append);
        }else{

            if(setvbuf(fs, NULL,_IOFBF, BUFFERSIZE) != 0){
                fprintf(stderr,"cant create buffer to file:%s\n",append);
               continue;
            }

            appendToDest(fs, fa);

            if(ferror(fs) != 0){
                fprintf(stderr,"error in read file:%s", append);
            }

            if(ferror(fa) != 0){
                fprintf(stderr,"error in write file:%s", appended);
            }

            fclose(fs);
            printf("file %s append success",append);
        }
    }

    puts("Done!");
    rewind(fa);
    while ((ch = getc(fa)) != EOF)
    {
       putchar(ch);
    }
    fclose(fa);
    return 0;
}

void appendToDest(FILE *src, FILE *dest){
    size_t bytes;
    static char temp[BUFFERSIZE];

    while ((bytes = fread(temp, sizeof(char), BUFFERSIZE, src)) > 0)
    {
       fwrite(temp, sizeof(char), bytes, dest);
    }
    
}

char* s_gets(char *name, int n){

    char *ret_val;
    char *find;

    ret_val = fgets(name, n, stdin);
    if(ret_val){
        find = strchr(name,'\n');
        if(find){
            *find = '\0';
        }else{
            while (getchar() != '\n')
            {
                continue;
            }
            
        }
    }

    return ret_val;
}