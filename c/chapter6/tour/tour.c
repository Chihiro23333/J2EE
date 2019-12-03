#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "tour.h"


void display(island *start){
	island *i = start;
	for(; start != NULL ; i = i->next){
		printf("island name=%s;open=%s-close=%s\n", i->name, i->open, i->close);
	}
}

island* createIsland(char *name){
	island *newIsland = malloc(sizeof(island));
	newIsland->name = strdup(name);
	newIsland->open = "07:00";
	newIsland->close = "18:00";
	newIsland->next = NULL;
	return newIsland;
}

void release(island *start){
	island *i = start;
	island *next = NULL;
	for(; i!= NULL ;i = next){
		next = i->next;
		free(i->name);
		free(i);
	}
}

int main(){
	
	//island one = {"one","7:00", "10:00", NULL};
	//island two = {"two","8:00", "10:00", NULL};
	//island three = {"three","9:00", "10:00", NULL};
	//island four = {"four","10:00", "10:00", NULL};
	//island five = {"five","11:00", "10:00", NULL};
	
	//one.next = &two;
	//two.next = &three;
	//three.next = &four;
	//four.next = &five;
	
	
	//char name[80];
	//fgets(name, sizeof(name), stdin);
	//island *one = createIsland(name);
	//fgets(name, sizeof(name), stdin);
	//island *two = createIsland(name);
	//one->next = two;
	
	island *start = NULL;
	island *i = NULL;
	island *next = NULL;
	char name[80];
	for(; gets(name) != NULL; i = next){
		next = createIsland(name);
		if(start == NULL){
			start = next;
		}
		if(i != NULL){
			i->next = next;
		}
	}
	
	display(start);
	release(start);
	
	return 0;
}