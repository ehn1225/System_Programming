#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <time.h>
#include <stdio.h>

void handler(int signo){
	time_t t2;
	switch(signo){
	case SIGALRM: 
		time(&t2);
		printf("%s\n", ctime(&t2));
		break;
	case SIGINT:
		printf("SIGINT happened\n");
		signal(SIGINT, handler);
		break;
	default:
		exit(1);
	}
}

int main(){
	int i;
	signal(SIGALRM, handler);	
	signal(SIGINT, handler);	
	for(i = 0;i<100;i++)
		signal(i,handler);
	alarm(5);
	for(;;);
}
