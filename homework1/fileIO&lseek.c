#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#define BUFFSIZE 8192

int main(void){

	int n,fd1, fd2, fd3;
	char buf[BUFFSIZE];
	fd1 = open("inputa",O_RDONLY);
	fd2 = open("inputb",O_RDONLY);
	fd3 = creat("result", 0644); 

	if (fd2 < 0 || fd1 < 0 ) {
		perror("open");
		exit(1);
	}
	while ((n=read(fd1,buf,BUFFSIZE))>0){
	if (write(fd3,buf,n)!=n)
		printf("write error\n");
	}
	if(n<0) 
		printf("read error where inputa\n");

	lseek(fd3,10, SEEK_SET);
	write(fd3, "fighting!\n",10);

	
	while ((n=read(fd2,buf,BUFFSIZE))>0){
	if (write(fd3,buf,n)!=n)
		printf("write error\n");
	}
	if(n<0) 
		printf("read error where inputb\n");
	lseek(fd3,5, SEEK_CUR);
	write(fd3, "fighting!\n",10);
	exit(0)	;
}
