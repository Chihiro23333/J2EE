#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	
	char *divery = "";
	int thick = 0;
	int count = 0;
	
	char ch;
	while((ch = getopt(argc, argv, "d:t")) != EOF){
		switch(ch){
			case 'd':
				divery = optarg;
			break;
			
			case 't':
				thick = 1;
			break;
			
			default:
				fprintf(stderr, "Invalid command %s \n", optarg);
			return 2;
		}
	}
	
	argc -= optind;
	argv += optind;
	
	if(thick)
		puts("is Thick");
	
	if(divery[0]){
		printf("to Be divery %s\n", divery);
	}
	
	for(count = 0; count < argc; count++){
		printf("rest param:%s",  argv[count]);
	}
	
	return 0;
}