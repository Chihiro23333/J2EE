#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <base.h>

char* now(){
	time_t t;
	time(&t);
	return asctime(localtime(&t));
}

int main(){
	char comment[80];
	char cmd[180];
	fgets(comment, 80, stdin);
	sprintf(cmd, "echo %s%s>>a.log", delespace(comment), delespace(now()));
	printf(cmd);
	system(cmd);
	return 0;
}