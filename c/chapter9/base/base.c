
#include <string.h>
#include <base.h>

char* delespace(char *line){
	if (line[strlen(line)-1] == '\n')
	line[strlen(line)-1] = '\0'; 
	return line;
}
