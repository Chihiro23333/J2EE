#include <stdio.h>
#include <string.h>

char tracks[][80] = {
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
};

void find_track(char search_for[]){
	for(int i = 0 ; i< 5 ; i++){
		if(strstr(tracks[i],search_for)){
			printf("track %i:%s" ,i ,tracks[i]);
		};
	}
}

int main(){
	char char_inpunt[80];
	printf("search for:");
	fgets(char_inpunt ,80 ,stdin);
	char_inpunt[strlen(char_inpunt)-1]='\0';
	find_track(char_inpunt);
	return 0;
}