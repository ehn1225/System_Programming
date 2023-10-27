#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main(){
	pid_t pid;
	int status;
	if((pid = fork()) == 0){ /*child Process*/
		printf("I am Child\n");
		exit(123);
	}
	/*Parent Precess*/
	pid = wait(&status);
	printf("parent : chile(pid = %d) is terminated with status (%d)\n", pid, WEXITSTATUS(status));
}
