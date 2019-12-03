#include <stdio.h>
#include <unistd.h>

int main(){
	char *env[] = {"JUICE=orange and apple",NULL};
	execle("dinner_info","dinner_info","meat",NULL,env);
	return 0;
}