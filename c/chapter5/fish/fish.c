#include <stdio.h>

typedef struct {
	const char* name;
	const char* type;
	int teeth;
	int age;
}fish;

void catlog(fish f){
	printf("name=%s\ntype=%s\nteeth=%i\nage=%i\n",f.name,f.type,f.teeth,f.age);
}

void label(fish f){
	printf("name=%s\ntype=%s\nteeth=%i\nage=%i\n",f.name,f.type,f.teeth,f.age);
}

int main(){
	
	fish f = {"hezhixin","fish",16, 9};
	catlog(f);
	label(f);
	
	return 0;
}