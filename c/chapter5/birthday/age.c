#include <stdio.h>
#include "birthday.h"

int main(){
	
	person p = {"zhufeng",99};
	
	printf("outer name=%s oldage=%i\n",p.name ,p.age);
	
	happybirthday(&p);
	
	printf("outer name=%s age=%i\n",p.name ,p.age);
	
	return 0;
}