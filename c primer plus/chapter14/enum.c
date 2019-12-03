#include <stdio.h>
#include <string.h>
#define COLOR_LENGTH 20

char * s_gets(char *str, int n);

enum color {
    red, orange, yellow, green ,blue
};
char *colors[] = {"red", "orange", "yellow", "green", "blue"};

int main(void){

    char color[COLOR_LENGTH];
    enum color colorEnum;

    puts("enter color name:");
    while (s_gets(color, COLOR_LENGTH) != NULL && color[0] != '\0'){
        for(colorEnum = red; colorEnum <= blue; colorEnum++){
            if(strcmp(color, colors[colorEnum]) == 0){
                break;
            }
        }
        switch (colorEnum)
        {
        case red:
            puts("is red");
            break;
            case orange:
            puts("is orange");
            break;
            case yellow:
            puts("is yellow");
            break;
            case green:
            puts("is green");
            break;
            case blue:
            puts("is blue");
            break;
        default:
            break;
        }
    }
    puts("Done!");
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