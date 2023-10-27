#include <unistd.h>
#include <fcntl.h>

int main(){
	int fd;
	fd = dup(STDOUT_FILENO);
	write(fd, "fd->helloworld!\n", 16);

	write(STDOUT_FILENO, "STDOUT->helloworld!\n", 20);
	close(fd);
	fd = open("lockfile", O_RDONLY);
	int flag = fcntl(fd, F_GETFL);
	if ((flag & O_ACCMODE) == O_RDONLY)
		printf("opened with RDONLY");
	else if ((flag & O_ACCMODE) == O_WRONLY)
		printf("opened with WRONLY");
	else
		printf("opened with RDWR");
	if (flag & O_APPEND)
		printf(" ,APPEND\n");
	else
		printf("\n");
	close(fd);

	return 0;
}
	
