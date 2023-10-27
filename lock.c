#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(void){
	int fd;

	while((fd = open("lockfile", O_RDONLY|O_CREAT|O_EXCL))< 0){}

	printf("Helloworld!");
	close(fd);
	unlink("lockfile");
	return 0;
}
 


