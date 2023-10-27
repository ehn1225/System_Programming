#include <unistd.h>
#include <fcntl.h>

int main(){
	int fd1, fd2, n;
	char buf[1024];

	fd1 = open("readandwrite2_result", O_RDONLY);
	fd2 = creat("readandwrite3_result", 0644);
	while((n=read(fd1, buf, 1024)) > 0){
		write(fd2, buf, n);
	}
	
close(fd1);
close(fd2);
return 0;
}
