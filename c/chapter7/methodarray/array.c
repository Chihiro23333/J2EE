#include <stdio.h>
#include "array.h"

void sayDump(response r){
	printf("dump:%s\n",r.name);
}
void saySecondChange(response r){
	printf("SecondChange:%s\n",r.name);
}
void sayMarried(response r){
	printf("Married:%s\n",r.name);
}

int main(){
	
	response dump = {"one",DUMP};
	response second_change = {"two",SECOND_CHANGE};
	response married = {"three", MARRIED};
	
	response response_array[] = {dump, second_change, married};
	void(*response_word_array[])(response) = {sayDump, saySecondChange ,sayMarried};
	
	for(int i = 0; i < 3; i++){
		response_word_array[response_array[i].type](response_array[i]);
	}
	
	return 0;
}