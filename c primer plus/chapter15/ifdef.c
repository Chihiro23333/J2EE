#include <stdio.h>
#define JUST_CHECKING
#undef JUST_CHECKING
#define LIMIT 4

int main(void){

    int i;

    for(i = 0; i< 5; i++){

        #ifdef JUST_CHECKING
        printf("i=%d\n",i);
        #endif

    }

    return 0;
}