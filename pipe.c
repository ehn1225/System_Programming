#include <stdio.h>

#define READ 0
#define WRITE 1

char* phrase = "Stuff this in your pipe and smoke it";

int main(){
	int fd[2], bytesRead;
	char message[100];
	pipe(fd);
	if(fork() == 0){  //child
		close(fd[READ]);
		write(fd[WRITE], phrase, strlen(phrase)+1);
		fprintf(stdout, "[%d, child] write completed.\n", getpid());
	}
	else{  //parent
		close(fd[WRITE]);
		bytesRead = read(fd[READ], message, 100);
		fprintf(stdout, "[%d, parent] read completed.\n", getpid());
		printf("Read %d bytes : %s\n", bytesRead, message);
		close(fd[READ]);
	}
}
		
