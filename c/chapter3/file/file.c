#include <stdio.h>
#include <stdlib.h>		
#include <string.h>

//file in.txt O 1.txt W 2.txt 3.txt

int main(int argc, char* argv[]){
	char in[80];
	
	if(argc < 6){
		fprintf(stderr,"params count below 6\n");
		return 1;
	}
	
	FILE* fin = fopen(argv[1],"r");
	FILE* f1 = fopen(argv[3],"w");
	FILE* f2 = fopen(argv[5],"w");
	FILE* f3 = fopen(argv[6],"w");
	
	while(fscanf(fin,"%79[^\n]\n" ,in) == 1){
		if(strstr(in ,argv[2])){
			fprintf(f1,"%s\n",in);
		}else if(strstr(in ,argv[4])){
			fprintf(f2,"%s\n",in);
		}else{
			fprintf(f3,"%s\n",in);
		}
	}
	
	fclose(f1);
	fclose(f2);
	fclose(f3);
	
	return 0;
}