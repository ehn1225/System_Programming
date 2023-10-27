#include <unistd.h>
#include <fcntl.h>

int main(int argc, char * argv[]){
	int fd1, fd2, n;
	char buf[1024];
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDWR|O_CREAT, 0644);

	lseek(fd2, 0, SEEK_END);
	while((n = read(fd1, buf, 1024)) > 0)
		write(fd2, buf, n);
	return 0;
}
