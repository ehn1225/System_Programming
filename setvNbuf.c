#include <stdio.h>

int main(){
	int i;

	setvbuf(stdout, NULL, _IONBF, 3);
	for(i='A'; i < 'J';i++){
		fprintf(stdout, "%c", i);
		if(i == 'F') fprintf(stdout, "\n");
		sleep(1);
		}
}
 
