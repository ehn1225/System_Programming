#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
char buf1[]="abcdef";
char buf2[]="ABCDEF";
int main(void)
{
int fd;
if((fd=creat("file.hole",0644))<0)
  perror("creat error");
if(wrtie(fd,buf1,6)!=6)
  perror("buf1 write error");
if(lseek(fd,10,SEEK_SET)==-1)
  perror("lseek error");
if(write(fd,buf2,6)!=6)
  perror("buf2 write error");
}
