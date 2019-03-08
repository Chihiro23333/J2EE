#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]){
	
	char* delivery="";
	int thick = 0;
	int count = 0;
	
	char ch;
	
	while((ch = getopt(argc, argv, "d:t")) != EOF){
		switch(ch){
			case 'd':
				delivery = optarg;
			break;
			case 't':
				thick = 1;
			break;
			default:
				fprintf(stderr ,"notsupport params");
				return 1;
		}
	}
	
	argc -= optind;
	argv += optind;
	
	if(thick){
		puts("thick");
	}
	
	if(delivery[0]){
		printf("to be delivery %s\n",delivery);
	}
	
	puts("ingrdients");
	
	for(count = 0; count < argc; count++){
		puts(argv[count]);
	}
	return 0;
}