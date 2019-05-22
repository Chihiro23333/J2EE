#include <stdio.h>
#include "fruit.h"


void display(fruit f){
	unit_of_measure units = f.units;
	if(units == COUNT){
		printf("name:%s,count:%hi\n", f.name, f.amount.count);
	}else if(units == POUNDS){
		printf("name:%s,weight:%.1f\n", f.name, f.amount.weight);
	}else{
		printf("name:%s,volume:%.1f\n", f.name, f.amount.volume);
	}
}

int main(){
	fruit apple = {"apple", "china", {.count=10}, COUNT};
	fruit orange = {"orange", "ameracia", {.weight = 20.3}, POUNDS};
	fruit pee = {"pee", "japan", {.volume=55.5}, PINTS};
	display(apple);
	display(orange);
	display(pee);
}