#include <stdio.h>
#include "fish.h"


void printfish(fish f){
	printf("printfish:name=%s,species=%s,teeth=%i,age=%i\n,exercise:desc=%s,duration=%.2f",
	f.name, f.species, f.teeth, f.age, f.exerc.desc, f.exerc.duration);
}
void printfishbowl(fish f){
	printf("printfishbowl:name=%s,species=%s,teeth=%i,age=%i\n",f.name, f.species, f.teeth, f.age);
}


void happybirthday(fish *f){
	f->age = f->age + 1;
	printf("%i\n", f->age);
}


void printnum(fish *f){
	printf("%i", f->num.count);
}

int main(){
	fish f = {"hzx", "shayu", 23, 18, {100, "swim"}, .num.count=10};
	printfish(f);
	printfishbowl(f);
	happybirthday(&f);
	printnum(&f);
	return 0;
	
}