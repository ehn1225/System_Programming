#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#define BUFFSIZE 8192

int main(int args, char *argv[]){

	int n,fd1, fd2;
	char buf[BUFFSIZE];
	fd1 = creat(argv[2],0644); 
	fd2 = open(argv[1],O_RDONLY);

	if (fd2 < 0) {
		perror("open");
		exit(1);
	}
	while ((n=read(fd2,buf,BUFFSIZE))>0){
	if (write(fd1,buf,n)!=n)
		printf("write error\n");
	}
	if(n<0) 
		printf("read error\n");
	exit(0)	;
}
