#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(){
	if(execl("/sbin/ipconfig","/sbin/ipconfig",NULL) == -1){
		if(execlp("ipconfig","ipconfig",NULL) == -1){
			fprintf(stderr,"no ipconfig:%s",strerror(errno));
		}
	}
	return 0;
}