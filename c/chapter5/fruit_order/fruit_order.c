#include <stdio.h>

typedef enum{
	COUNT, WEIGHT, VOLUME
} unit_of_measure;

typedef union{
	int count;
	float weight;
	int volume;
} quantity;

typedef struct{
	char* name;
	quantity amount;
	unit_of_measure type;
} fruit_order;

void display(fruit_order order){
	printf("order contains:\n");
	
	if(order.type == COUNT){
		printf("count=%i\n", order.amount.count);
	}else if(order.type == WEIGHT){
		printf("weight=%.2f\n", order.amount.weight);
	}else {
		printf("volume=%i\n", order.amount.volume);
	}
	
}

int main(){
	fruit_order apples = {"apple",.amount.count=10,COUNT};
	fruit_order oranges = {"oranges",.amount.weight=1.555,WEIGHT};
	display(apples);
	display(oranges);
	
	return 0;
}