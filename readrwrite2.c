#include <unistd.h>
#include <fcntl.h>

int main(){
	int fd, n;
	char buf[1024];
	fd = creat("readandwrite2_result", 0644);
	if(fd < 0) printf("can not creat file");
	while((n=read(STDIN_FILENO,buf, 1024)) > 0){
		write(fd, buf, n);
	}
	close(fd);
return 0;
} 
