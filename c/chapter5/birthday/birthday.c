#include <stdio.h>
#include "birthday.h"

void happybirthday(person* p){
	
	p->age = p->age + 1;
	
	printf("method name=%s age=%i\n",p->name, p->age);
	
};