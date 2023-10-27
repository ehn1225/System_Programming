#include <stdio.h>
#include <unistd.h>

int main(){
	setvbuf(stdout, NULL, _IONBF, 3);
	int i = 0;		
	for( i = 'a'; i < 'f'; i++){
		fprintf(stdout, "%c", i);
		sleep(1);
	}
}

