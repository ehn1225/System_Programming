#include <unistd.h>
#include <fcntl.h>

int main(){
	int fd;
	fd = creat("dup_result", 0644);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	printf("helloworld!\n");
	return 0;
}

