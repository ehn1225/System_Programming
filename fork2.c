#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int g = 6;
int main(void)
{
	int var;
	pid_t pid;
	var = 88;
	if ((pid = vfork()) < 0) {
		perror("fork error");
	}
	else if (pid == 0) { /* child */
		g++; /* modify variables */
		var++;
	}
	printf("pid = %d, glob = %d, var = %d\n",
	getpid(), g, var);
	exit(0);
}

