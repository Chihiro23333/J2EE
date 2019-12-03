#include <stdio.h>
#define MSG "i am a msg!"

int main(void){

    char msgArr[] = "i am a msg!";
    char *msgPoint = "i am a msg!";

    printf("address of \"i am a msg!\":%p\n","i am a msg!");
    printf("address of msg[]:%p\n",msgArr);
    printf("address of *msg:%p\n",msgPoint);
    printf("address of \"i am a msg!\":%p\n","i am a msg!");

    return 0;
}