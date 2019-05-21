#include<stdio.h>
#include<string.h>


char text[][80] = {
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine",
};

void findText(char searchText[]){
	
	for(int i = 0; i < 5; i++){
		if(strstr(text[i], searchText)){
			printf("%i:%s\n", i, text[i]);
		}
	}
}

int main(){
	char search[5];
	scanf("%s", search);
	findText(search);
	return 0;
}