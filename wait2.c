#include <stdio.h>
#include <sys//wait.h>
#include <sys/types.h>

int main(){
	pid_t pid;
	int status;
	if((pid = fork()) == 0){ /*child*/
		printf("I an a child with pid = %d\n", getpid());
		sleep(10);
		printf("child terminates\n");
		exit(0);
	}
	else{
		while(1){
		waitpid(pid, &status, WUNTRACED);
		if(WIFSTOPPED(status)){
			printf("child stopped, singal(%d)\n", WSTOPSIG(status));
			continue;
		}
		else if(WIFEXITED(status))
			printf("normal termination with status(%d)\n", WEXITSTATUS(status));
		else if(WIFSIGNALED(status))
			printf("abnormal termination, status(%d)\n", WTERMSIG(status));
		exit(0);
		}
	}
}	
