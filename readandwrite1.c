#include <unistd.h>
#define BUFFSIZE 8192

int main(void){

	int n, fd;
	char buf[BUFFSIZE];
	fd = creat("outfile",0644);
	while ((n=read(STDIN_FILENO,buf,BUFFSIZE))>0){
	if (write(fd,buf,n)!=n)
		printf("write error\n");
	}
	if(n<0) 
		printf("read error\n");
	exit(0)	;
}
