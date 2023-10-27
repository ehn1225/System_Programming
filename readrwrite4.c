#include <unistd.h>
#include <fcntl.h>

int main(int argc, char * argv[]){
	int fd1, fd2, n;
	char buf[1024];

	fd1 = open(argv[1], O_RDONLY);
	fd2 = creat(argv[2], 0644);
	while((n=read(fd1, buf, 1024)) > 0){
		write(fd2, buf, n);
	}
	
close(fd1);
close(fd2);
return 0;
}
