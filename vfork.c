#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int g = 6;

int main(){
	int var;
	pid_t pid;

	var = 88;
	printf("before vfork, pid = %d\n", getpid());

if((pid = vfork()) < 0)
//	if((pid = fork()) < 0)
	printf("vfork error");
	else if(pid == 0){
		g++;
		var++;
		_exit(0);
	}
	/*parent*/
	printf("pid = %d, glob = %d, var = %d\n", getpid(), g, var);
	exit(0);
}
	

