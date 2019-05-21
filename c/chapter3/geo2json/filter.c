#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
	
	FILE *in = fopen(argv[1], "r");
	FILE *out1 = fopen(argv[2], "w");
	FILE *out2 = fopen(argv[3], "w");
	FILE *out3 = fopen(argv[4], "w");
	
	char word[80];
	
	while(fscanf(in, "%79[^\n]\n", word) == 1){
		if(strstr(word, argv[5])){
			fprintf(stdout, "1+%s", word);
			fprintf(out1, "%s", word);
		}else if(strstr(word, argv[6])){
			fprintf(stdout,"2+%s", word);
			fprintf(out2, "%s", word);
		}else{
			fprintf(stdout,"3+%s", word);
			fprintf(out3, "%s", word);
		}
		puts("end");
	}
	
	fclose(out1);
	fclose(out2);
	fclose(out3);
	
	return 0;
}