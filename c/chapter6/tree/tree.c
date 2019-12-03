#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct node{
	char *question;
	struct node *yes;
	struct node *no;
} node;


int yes_no(char *question){
	printf("%s?y/n", question);
	char answer[3];
	fgets(answer, 3, stdin);
	return answer[0] == 'y';
}

node* create(char *question){
	node *newNode = malloc(sizeof(node));
	newNode->question = question;
	newNode->yes = NULL;
	newNode->no = NULL;
	return newNode;
}

void release(node *start){
	if(start){
		if(start->yes){
			release(start->yes);
		}
		if(start->no){
			release(start->no);
		}
		if(start->question){
			free(start->question);
		}
		free(start);
	}
}

void check(node *start){
	
	char question[80];
	char name[20];

	do{
		node *current =start;
		while(1){
			if(yes_no(current->question)){
				if(current->yes){
					current = current->yes;
				}else{
					printf("i find it:name=%s",current->question);
					break;
				}
			}else if(current->no){
				current = current->no;
			}else{
				printf("who is the man?");
				fgets(name, 20 ,stdin);
				current->yes = create(name);
				
				current->no = create(current->question);
				
				printf("Give a desc for %s", name);
				fgets(question, 80 ,stdin);
				free(current->question);
				current->question = strdup(question);
				break;
			}
		}
	}while(yes_no("run again"));
	release(start);
}

int main(){
	
	node *start = create("has a scar");
	start->yes = create("hzx");
	start->no = create("xiaolai");
	
	check(start);
	
	return 0;
}