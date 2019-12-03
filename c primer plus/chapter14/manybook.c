#include <stdio.h>
#include <string.h>

#define MAXTITLE 20
#define MAXAUTH 20
#define MAXBOOK 10

char * s_gets(char *str, int n);

struct book
{
    char title[MAXTITLE];
    char auth[MAXAUTH];
    float value;
};


int main(void){

    struct book library[MAXBOOK];
    int count = 0;
    int index;

    puts("please enter book title:");
    puts("Press [enter] to exit:");

    while(count < MAXBOOK && s_gets(library[count].title, MAXTITLE) != NULL && library[count].title[0] != '\0'){
        puts("please enter book auth:");
        s_gets(library[count].auth, MAXAUTH);
        puts("please enter book value:");
        scanf("%f", &library[count++].value);
        while (getchar() != '\n')
        {
            continue;
        }
        if(count < MAXBOOK)
            puts("enter next title:");
    }
    
    puts("Done!");
    
    for(index = 0; index < count; index ++)
        printf("title:%s, auth:%s, value:%.2f\n", library[index].title, library[index].auth, library[index].value);

    return 0;
}

char * s_gets(char *str, int n){

    char *end;
    char *find;

    end = fgets(str, n ,stdin);
    if(end){
        find = strchr(str, '\n');
        if(find){
            *find = '\0';
        }else{
            while (getchar() != '\n')
                continue; 
        }
    }

    return end;
}