#include <stdio.h>
#include <time.h>

int main(){
	int i;
	struct timeval start, end;
	
	gettimeofday(&start, NULL);
	for(i = 0; i < 150000000; i++)
	gettimeofday(&end, NULL);
	printf("%d sec\n", end.tv_sec-start.tv_sec);
	printf("%d usec\n", end.tv_usec-start.tv_usec);
}
