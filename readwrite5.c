#include <unistd.h>
#include <fcntl.h>
int main(int argc, char* argv[]){
	int n;
	char buf[1024];
	int fd1 = open(argv[1], O_RDONLY);
	int fd2 = creat(argv[2], 0644);	
	while((n = read(fd1, buf, 1024)) > 0 )
		write(fd2, buf, n);

	return 0;
}
