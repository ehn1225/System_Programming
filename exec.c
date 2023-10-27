#include <sys/types.h>
#include <sys/wait.h>
int main(){
	pid_t pid;
	
	if((pid = fork()) < 0)
		printf("fork error");
	else if(pid == 0){ /*child*/
		printf("Child : %d\n", getpid());
		if(execl("/usr/bin/ls", "ls", "-aCF", 0) < 0)
			printf("execl error");
		if(execl("/bin/id", "id", "-a", 0) < 0)
			printf("execl error");
	}

	printf("Parent : %d\n", getpid());
	if(waitpid(pid, NULL, 0) < 0) /*parent*/
		printf("wait pid error");
	exit(0);
}
