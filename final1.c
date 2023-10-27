#include <stdio.h>
#include <sys/types.h>
int global = 10;
void func1(void), func2(void);
void main(){
	func1();
	func2();
}
void func1(void){
	int i_local = 20;
	static int s_local = 30;
	if(fork() > 0){
		wait((char*)0);
		printf("i_local = %d[%d]\n", i_local, getpid());
		printf("s_local = %d[%d]\n", s_local, getpid());
		return;
	}
	else{
		sleep(2);
		global++;
		i_local++;
		s_local++;
	}
}
void func2(void){
	printf("global = %d[%d]\n", global, getpid());
}	
