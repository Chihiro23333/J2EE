#include <stdio.h>

int main(void){
    int guess = 0;
    int response;

    printf("i will guess\n");
    printf("is it %d?\n",guess);

    while ((response = getchar()) != 'y')
    {
 
        if(response != 'n'){
            printf("not support!\n");
        }else
        {
            printf("well, it is%d?\n",++guess);
        }
        while (getchar() != '\n')
            continue;
        
    }
    printf("yeah, i do it!!!!!it is %d\n",guess);

    return 0;
}