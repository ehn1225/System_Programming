#include <unistd.h>
#include <fcntl.h>

int main(){
	int n;
	char buf[1024];
	while((n = read(STDIN_FILENO, buf, 1024)) > 0)
		write(STDOUT_FILENO, buf, n);
	return 0;
} 
