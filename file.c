#include <unistd.h>
#include <stdio.h>

int main(){
	FILE* fp = fopen("result", "r");
	char buf[1024];
	int n;
	while((n=fgetc(fp)) != EOF)
		printf("%c", n);

	return 0;
}
